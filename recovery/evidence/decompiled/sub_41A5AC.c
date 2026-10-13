// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5AC; original name: ?GetTypeLibCache@CCmdTarget@@UAEPAVCTypeLibCache@@XZ
// attributes: thunk
struct CTypeLibCache *__thiscall CCmdTarget::GetTypeLibCache(CCmdTarget *this)
{
  return __imp_?GetTypeLibCache@CCmdTarget@@UAEPAVCTypeLibCache@@XZ(this);
}
