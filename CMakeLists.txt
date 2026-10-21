cmake_minimum_required(VERSION 3.25)
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "")
project(San9Companion LANGUAGES CXX)
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build configuration" FORCE)
endif()
if(MSVC)
  add_link_options(/DEBUG:NONE)
endif()
add_library(san9-recovered STATIC src/model/PatchImage.cpp src/model/ParameterConfig.cpp src/model/CityConfig.cpp src/model/SkillConfig.cpp src/model/FormationConfig.cpp src/model/PersonConfig.cpp src/model/PersonSnapshot.cpp src/model/PackedConfigIO.cpp)
target_compile_features(san9-recovered PUBLIC cxx_std_17)
target_include_directories(san9-recovered PUBLIC src/model PRIVATE src/generated)
add_executable(san9-static src/model/main.cpp)
target_link_libraries(san9-static PRIVATE san9-recovered)
if(MSVC)
  target_compile_options(san9-recovered PRIVATE /W4 /utf-8)
  target_compile_options(san9-static PRIVATE /W4 /utf-8)
else()
  target_compile_options(san9-recovered PRIVATE -Wall -Wextra -Wpedantic)
endif()
enable_testing()
add_executable(san9-model-test tests/model_test.cpp)
target_link_libraries(san9-model-test PRIVATE san9-recovered)
add_test(NAME model-rebase COMMAND san9-model-test)
add_executable(san9-parameter-test tests/parameter_test.cpp)
target_link_libraries(san9-parameter-test PRIVATE san9-recovered)
add_test(NAME parameter-config COMMAND san9-parameter-test)

# The recovered injection ABI is x86. This path builds core/tests with only the
# Windows SDK and C++ runtime; the MFC frontend is deliberately not a dependency.
if(WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 4)
  enable_language(ASM_MASM)
  add_library(san9-runtime STATIC
    src/runtime/Runtime2026.cpp src/runtime/RuntimeVersion2026.cpp
    src/runtime/PresentationSpeed2026.cpp src/runtime/RuntimePresentation2026.cpp src/runtime/ThreadBarrier2026.cpp
    src/runtime/PresentationPayload2026.asm
    src/runtime/ProcessSession2026.cpp src/runtime/ChangeJournal2026.cpp
    src/runtime/RuntimeInjection2026.cpp src/runtime/RuntimeConfiguration2026.cpp
    src/runtime/RuntimeZone2026.cpp src/runtime/GameText.cpp src/runtime/GameSnapshots2026.cpp)
  target_link_libraries(san9-runtime PUBLIC san9-recovered user32)
  target_include_directories(san9-runtime PUBLIC src/runtime)
  add_executable(san9-runtime-test tests/runtime_test.cpp tests/config_files_test.cpp tests/preferences_test.cpp tests/presentation_speed_test.cpp
    src/app/platform/Preferences.cpp
    tests/presentation_speed_fixture.asm
    src/app/application/ConfigFiles.cpp src/app/application/Controller.cpp
    src/app/ui/RuntimeStatusText.cpp)
  target_link_libraries(san9-runtime-test PRIVATE san9-runtime)
  if(MSVC)
    foreach(target san9-runtime san9-runtime-test)
      target_compile_options(${target} PRIVATE /W3 /source-charset:utf-8 /execution-charset:.936)
      target_compile_options(${target} PRIVATE "$<$<COMPILE_LANGUAGE:ASM_MASM>:/safeseh>")
      target_compile_definitions(${target} PRIVATE _WIN32_WINNT=0x0A00)
    endforeach()
  endif()
  add_test(NAME runtime-session COMMAND san9-runtime-test --all "${CMAKE_CURRENT_SOURCE_DIR}/assets/config")
endif()

if(WIN32)
  add_executable(san9-preferences-test tests/preferences_test.cpp src/app/platform/Preferences.cpp)
  target_compile_features(san9-preferences-test PRIVATE cxx_std_17)
  target_compile_definitions(san9-preferences-test PRIVATE SAN9_PREFERENCES_TEST_STANDALONE)
  add_test(NAME preferences-atomic-save COMMAND san9-preferences-test)
endif()
