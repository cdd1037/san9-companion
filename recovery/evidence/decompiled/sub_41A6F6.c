// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6F6; original name: ?FromHandle@CGdiObject@@SGPAV1@PAX@Z
// attributes: thunk
static struct CGdiObject *__stdcall CGdiObject::FromHandle(void *a1)
{
  return __imp_?FromHandle@CGdiObject@@SGPAV1@PAX@Z(a1);
}
