// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404720; original name: sub_404720
int __thiscall sub_404720(int this, struct CWnd *a2)
{
  CDialog::CDialog((CDialog *)this, 0x84u, a2);
  CWnd::CWnd((CWnd *)(this + 96));
  *(_DWORD *)(this + 96) = &off_41C498;
  CWnd::CWnd((CWnd *)(this + 160));
  *(_DWORD *)(this + 160) = &off_41CBD4;
  CString::CString((CString *)(this + 224));
  CString::CString((CString *)(this + 332));
  *(_DWORD *)(this + 31556) = 0;
  *(_DWORD *)(this + 31552) = &off_41CBC0;
  CString::CString((CString *)(this + 31560));
  *(_DWORD *)this = &off_41CAE8;
  CString::operator=(this + 224, &Str2);
  *(_BYTE *)(this + 264) = 0;
  *(_DWORD *)(this + 228) = -1;
  *(_DWORD *)(this + 232) = -1;
  *(_DWORD *)(this + 236) = -1;
  *(_DWORD *)(this + 240) = -1;
  *(_DWORD *)(this + 244) = -1;
  *(_DWORD *)(this + 248) = -1;
  *(_DWORD *)(this + 252) = -1;
  *(_DWORD *)(this + 256) = -1;
  *(_DWORD *)(this + 260) = -1;
  *(_BYTE *)(this + 265) = 0;
  *(_BYTE *)(this + 266) = 0;
  *(_BYTE *)(this + 267) = 0;
  *(_DWORD *)(this + 268) = 0;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 0;
  *(_DWORD *)(this + 288) = 0;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  *(_DWORD *)(this + 300) = 0;
  *(_WORD *)(this + 304) = 0;
  *(_WORD *)(this + 306) = 0;
  *(_WORD *)(this + 308) = 0;
  *(_WORD *)(this + 310) = 0;
  *(_WORD *)(this + 312) = 0;
  *(_WORD *)(this + 314) = 0;
  *(_WORD *)(this + 316) = 0;
  *(_WORD *)(this + 318) = 0;
  *(_WORD *)(this + 320) = 0;
  *(_WORD *)(this + 322) = 0;
  *(_WORD *)(this + 324) = 0;
  *(_WORD *)(this + 326) = 0;
  *(_DWORD *)(this + 328) = 0;
  CString::operator=(this + 332, &Str2);
  *(_DWORD *)(this + 336) = 0;
  return this;
}
