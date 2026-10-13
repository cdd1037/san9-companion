// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A816; original name: ??2@YAPAXI@Z
// attributes: thunk
void *__cdecl operator new(unsigned int a1)
{
  return __imp_??2@YAPAXI@Z(a1);
}
