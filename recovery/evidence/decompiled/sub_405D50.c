// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405D50; original name: sub_405D50
CWinApp *__thiscall sub_405D50(CWinApp *this, char a2)
{
  CWinApp::~CWinApp(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
