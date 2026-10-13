// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041AA34; original name: __setdefaultprecision
unsigned int _setdefaultprecision()
{
  return controlfp(0x10000u, 0x30000u);
}
