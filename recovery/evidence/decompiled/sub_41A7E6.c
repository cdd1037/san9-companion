// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7E6; original name: ?AfxFindResourceHandle@@YGPAUHINSTANCE__@@PBD0@Z
// attributes: thunk
HINSTANCE __stdcall AfxFindResourceHandle(const char *a1, const char *a2)
{
  return __imp_?AfxFindResourceHandle@@YGPAUHINSTANCE__@@PBD0@Z(a1, a2);
}
