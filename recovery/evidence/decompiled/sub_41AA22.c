// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041AA22; original name: __dllonexit
// attributes: thunk
_onexit_t __cdecl _dllonexit(int a1, int a2, int a3)
{
  return __dllonexit(a1, a2, a3);
}
