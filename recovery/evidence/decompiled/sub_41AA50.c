// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041AA50; original name: _controlfp
// attributes: thunk
unsigned int __cdecl controlfp(unsigned int NewValue, unsigned int Mask)
{
  return _controlfp(NewValue, Mask);
}
