#include "Runtime2026.h"

// Evidence: 0x409840. Version reads must retain their short-circuit order.
bool Runtime2026::checkVersion()
{
  const HANDLE process = field<HANDLE>(san9::layout2026::ProcessHandle);
  const DWORD info = field<DWORD>(san9::injection2026::ResourceInfoAddr) +
                     field<DWORD>(san9::injection2026::FixedFileInfoOffset);
  DWORD version = 0;
  readMemory(process, info, &version, sizeof(version), nullptr);
  if (version != 0xFEEF04BDu) return false;
  readMemory(process, info + 8, &version, sizeof(version), nullptr);
  if (version != 0x10000u) return false;
  readMemory(process, info + 12, &version, sizeof(version), nullptr);
  if (version != 0x10000u) return false;
  for (DWORD index = 0; index < 50; ++index)
    field<DWORD>(san9::injection2026::CityAddresses + index * 4) = 19192664 + index * 496;
  for (DWORD index = 0; index < 200; ++index)
    field<DWORD>(san9::injection2026::ZoneAddresses + index * 4) = 19103864 + index * 444;
  initializeHookDescriptors();
  return true;
}

void Runtime2026::initializeHookDescriptors()
{
  struct Seed
  {
    DWORD destination, targets, lengths, code;
    unsigned count;
    int direction;
  };
  // Length addresses point to the first actual length, after the original index update.
  // The dispatch table traverses targets, lengths and code backwards, records forwards.
  static constexpr Seed seeds[] = {
    {0x42F700u, 0x4204B8u, 0x4204C0u, 0x4204C8u, 2, 1},
    {0x42F580u, 0x41F9A0u, 0x41F9A8u, 0x41F9B0u, 2, 1},
    {0x42F7B8u, 0x421098u, 0x4210A0u, 0x4210A8u, 2, 1},
    {0x42F598u, 0x41FAECu, 0x41FB00u, 0x41FB44u, 5, -1},
    {0x42F6C0u, 0x41FF18u, 0x41FF24u, 0x41FF30u, 3, 1},
    {0x42F7E8u, 0x421EA8u, 0x421EB0u, 0x421EB8u, 2, 1},
    {0x42F678u, 0x41FE30u, 0x41FE38u, 0x41FE40u, 2, 1},
    {0x42F790u, 0x420F88u, 0x420F94u, 0x420FA0u, 3, 1},
    {0x42F5D8u, 0x41FB80u, 0x41FB84u, 0x41FB88u, 1, 1},
    {0x42F6E8u, 0x41FFB0u, 0x41FFB8u, 0x41FFC0u, 2, 1},
    {0x42F5E8u, 0x41FBE8u, 0x41FBECu, 0x41FBF0u, 1, 1},
    {0x42F690u, 0x41FE88u, 0x41FE98u, 0x41FEA8u, 4, 1},
    {0x42F718u, 0x420548u, 0x420554u, 0x420560u, 3, 1},
    {0x42F768u, 0x420CA0u, 0x420CACu, 0x420CB8u, 3, 1},
    {0x42F5F8u, 0x41FC28u, 0x41FC2Cu, 0x41FC30u, 1, 1},
    {0x42F608u, 0x41FC68u, 0x41FC6Cu, 0x41FC70u, 1, 1},
    {0x42F618u, 0x41FCA8u, 0x41FCB8u, 0x41FCC8u, 4, 1},
    {0x42F7D0u, 0x421D80u, 0x421D88u, 0x421D90u, 2, 1},
    {0x42F660u, 0x41FDD8u, 0x41FDE0u, 0x41FDE8u, 2, 1},
    {0x42F648u, 0x41FD30u, 0x41FD38u, 0x41FD40u, 2, 1},
    {0x42F740u, 0x420B10u, 0x420B1Cu, 0x420B28u, 3, 1},
  };
  for (const auto &seed : seeds)
    for (unsigned index = 0; index < seed.count; ++index)
    {
      const int step = int(index) * seed.direction;
      const PatchDescriptor2026 descriptor{
        global<DWORD>(seed.targets + step * 4),
        global<DWORD>(seed.lengths + step * 4),
        reinterpret_cast<DWORD>(pointer<BYTE>(seed.code + step * 16))};
      dataIn(seed.destination + index * sizeof(descriptor), &descriptor, sizeof(descriptor));
    }
}
