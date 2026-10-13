// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A8BD; original name: start
void __noreturn start()
{
  char *v0; // esi
  int wShowWindow; // eax
  HMODULE ModuleHandleA; // eax
  int v3; // [esp-4h] [ebp-88h]
  _BYTE v4[4]; // [esp+14h] [ebp-70h] BYREF
  int v5; // [esp+18h] [ebp-6Ch] BYREF
  int v6; // [esp+1Ch] [ebp-68h]
  _BYTE v7[4]; // [esp+20h] [ebp-64h] BYREF
  _BYTE v8[4]; // [esp+24h] [ebp-60h] BYREF
  struct _STARTUPINFOA StartupInfo; // [esp+28h] [ebp-5Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+6Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  _set_app_type(_crt_gui_app);
  dword_42F820 = -1;
  dword_42F824 = -1;
  *_p__fmode() = dword_42F814;
  *_p__commode() = dword_42F810;
  dword_42F81C = adjust_fdiv;
  nullsub_1();
  if ( dword_42EF40 == 0 )
    _setusermatherr(UserMathErrorFunction);
  _setdefaultprecision();
  initterm(&First, &Last);
  v5 = dword_42F80C;
  _getmainargs(v8, v4, v7, dword_42F808, &v5);
  initterm(&dword_41F000, &dword_41F500);
  v0 = acmdln;
  if ( *acmdln != 34 )
  {
    while ( (unsigned __int8)*v0 > 0x20u )
      ++v0;
    goto LABEL_8;
  }
  do
    ++v0;
  while ( *v0 != 0 && *v0 != 34 );
  if ( *v0 != 34 )
    goto LABEL_8;
  while ( 1 )
  {
    ++v0;
LABEL_8:
    if ( *v0 == 0 || (unsigned __int8)*v0 > 0x20u )
    {
      StartupInfo.dwFlags = 0;
      GetStartupInfoA(&StartupInfo);
      if ( (StartupInfo.dwFlags & 1) != 0 )
        wShowWindow = StartupInfo.wShowWindow;
      else
        wShowWindow = 10;
      v3 = wShowWindow;
      ModuleHandleA = GetModuleHandleA(nullptr);
      v6 = WinMain(ModuleHandleA, nullptr, v0, v3);
      exit(v6);
    }
  }
}
