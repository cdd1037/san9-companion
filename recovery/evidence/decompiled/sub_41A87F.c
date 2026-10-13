// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A87F; original name: __onexit
_onexit_t __cdecl _onexit(_onexit_t Func)
{
  if ( dword_42F824 == -1 )
    return onexit(Func);
  else
    return _dllonexit(Func, &dword_42F824, &dword_42F820);
}
