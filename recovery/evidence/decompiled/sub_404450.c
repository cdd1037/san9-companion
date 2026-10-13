// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404450; original name: sub_404450
int __thiscall sub_404450(CWnd *this, unsigned int Buffer, int a3)
{
  unsigned int v3; // ebx
  void *v5; // esi

  v3 = Buffer;
  if ( (unsigned __int16)Buffer >= 0x8003u && (unsigned __int16)Buffer <= 0x8034u )
  {
    v5 = (void *)(212 * (unsigned __int16)Buffer + 12270064);
    if ( ReadProcessMemory(*(HANDLE *)(*((_DWORD *)this + 114) + 112), v5, &Buffer, 1u, nullptr) )
    {
      LOBYTE(Buffer) = Buffer ^ 1;
      WriteProcessMemory(*(HANDLE *)(*((_DWORD *)this + 114) + 112), v5, &Buffer, 1u, nullptr);
    }
    CMenu::DestroyMenu((CWnd *)((char *)this + 448));
  }
  return CWnd::OnCommand(this, v3, a3);
}
