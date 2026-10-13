// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00429958; original name: sub_429958
int __cdecl sub_429958(
        _DWORD *a1,
        int a2,
        void (__thiscall *a3)(int, _DWORD, _DWORD, int),
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v7; // ecx
  int v8; // ebx
  _DWORD *v9; // esi
  int result; // eax
  int v11; // eax
  void *retaddr; // [esp+10h] [ebp+4h]

  v8 = v7;
  v9 = *(_DWORD **)(a2 + 4);
  MEMORY[0xA8290](656640);
  do
  {
    a3(v8, 0, v9[2], a7);
    result = MEMORY[0x486480](v8);
    if ( (_BYTE)result != 3 )
      result = MEMORY[0x46EF70](656640, v9[2]);
    v9 = (_DWORD *)*v9;
  }
  while ( v9 != nullptr );
  if ( MEMORY[0xA050C] != 0 )
  {
    v11 = MEMORY[0xA0504];
    if ( (unsigned int)(*(_DWORD *)(v8 + 52) - 25) <= 2 )
      v11 = MEMORY[0xA0508];
    *a1 = *(_DWORD *)(v11 + 8);
    return (*(int (__thiscall **)(void *, int))(*(_DWORD *)retaddr + 236))(retaddr, 1);
  }
  return result;
}
