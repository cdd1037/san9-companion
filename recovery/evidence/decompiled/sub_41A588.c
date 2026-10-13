// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A588; original name: ?GetEventSinkMap@CCmdTarget@@MBEPBUAFX_EVENTSINKMAP@@XZ
// attributes: thunk
const struct AFX_EVENTSINKMAP *__thiscall CCmdTarget::GetEventSinkMap(CCmdTarget *this)
{
  return __imp_?GetEventSinkMap@CCmdTarget@@MBEPBUAFX_EVENTSINKMAP@@XZ(this);
}
