// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00409D20; original name: sub_409D20
void __thiscall sub_409D20(struct CWnd *this)
{
  int SystemMetrics; // ebx
  int v3; // edi
  struct tagRECT Rect; // [esp+4h] [ebp-64h] BYREF
  _BYTE v5[4]; // [esp+14h] [ebp-54h] BYREF
  HDC hDC; // [esp+18h] [ebp-50h]

  if ( IsIconic(*((HWND *)this + 8)) )
  {
    CPaintDC::CPaintDC((CPaintDC *)v5, this);
    SendMessageA(*((HWND *)this + 8), 0x27u, v5 != nullptr ? (unsigned int)hDC : 0, 0);
    SystemMetrics = GetSystemMetrics(11);
    v3 = GetSystemMetrics(12);
    GetClientRect(*((HWND *)this + 8), &Rect);
    DrawIcon(
      hDC,
      (Rect.right - Rect.left - SystemMetrics + 1) / 2,
      (Rect.bottom - Rect.top - v3 + 1) / 2,
      *((HICON *)this + 1922));
    CPaintDC::~CPaintDC((CPaintDC *)v5);
  }
  else
  {
    CWnd::Default(this);
  }
}
