// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00414E40; original name: sub_414E40
HWND __thiscall sub_414E40(int this)
{
  HWND result; // eax
  LPVOID *v3; // ebx
  LPVOID *v4; // ebx
  LPCVOID *v5; // ebx
  LPCVOID *v6; // ebx
  LPCVOID *v7; // ebx
  LPCVOID *v8; // ebx
  LPCVOID *v9; // ebx
  int i; // ebx
  int j; // ebx
  int k; // ebx
  int m; // ebx
  int n; // ebx
  int ii; // ebx
  int jj; // ebx
  LPCVOID *v17; // ebx
  int kk; // ebx
  LPCVOID *v19; // ebx
  int mm; // ebx
  void *v21; // [esp-1Ch] [ebp-28h]
  void *v22; // [esp-1Ch] [ebp-28h]
  void *v23; // [esp-1Ch] [ebp-28h]
  void *v24; // [esp-1Ch] [ebp-28h]
  void *v25; // [esp-1Ch] [ebp-28h]
  void *v26; // [esp-18h] [ebp-24h]
  void *v27; // [esp-18h] [ebp-24h]
  void *v28; // [esp-18h] [ebp-24h]
  void *v29; // [esp-18h] [ebp-24h]
  void *v30; // [esp-18h] [ebp-24h]
  int Buffer; // [esp+8h] [ebp-4h] BYREF

  Buffer = 0;
  result = FindWindowA(ClassName, nullptr);
  if ( result != nullptr && *(HWND *)(this + 108) == result )
  {
    if ( *(_DWORD *)(this + 296) != 0 )
      sub_41A1F0(this, 0);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 4400), &unk_42DB28, 0x2B8u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7592), (LPCVOID)(this + 7600), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7604), (LPCVOID)(this + 7612), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7580), (LPCVOID)(this + 7588), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7532), (LPCVOID)(this + 7540), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7544), (LPCVOID)(this + 7552), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7556), (LPCVOID)(this + 7564), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7568), (LPCVOID)(this + 7576), 2u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7520), (LPCVOID)(this + 7528), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7492), (LPCVOID)(this + 7508), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7496), (LPCVOID)(this + 7508), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7500), (LPCVOID)(this + 7516), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7480), (LPCVOID)(this + 7488), 1u, nullptr);
    v3 = (LPVOID *)&unk_42C624;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), *(v3 - 3), v3, (SIZE_T)*(v3 - 2), nullptr);
      v3 += 4;
    }
    while ( (int)v3 < (int)dword_42C7D4 );
    v4 = (LPVOID *)&unk_42C25C;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), *(v4 - 3), v4, (SIZE_T)*(v4 - 2), nullptr);
      v4 += 4;
    }
    while ( (int)v4 < (int)dword_42C4FC );
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7420), (LPCVOID)(this + 7432), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7424), (LPCVOID)(this + 7432), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7408), (LPCVOID)(this + 7416), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7404), (LPCVOID)(this + 7416), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7400), (LPCVOID)(this + 7416), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7388), (LPCVOID)(this + 7396), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6616), (LPCVOID)(this + 6632), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6620), (LPCVOID)(this + 6632), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6624), (LPCVOID)(this + 6632), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7384), (LPCVOID)(this + 7380), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7372), (LPCVOID)(this + 7380), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7364), (LPCVOID)(this + 7368), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7348), (LPCVOID)(this + 7356), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7340), (LPCVOID)(this + 7344), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7328), (LPCVOID)(this + 7336), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7316), (LPCVOID)(this + 7324), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7304), (LPCVOID)(this + 7312), 1u, nullptr);
    WriteProcessMemory(
      *(HANDLE *)(this + 112),
      (LPVOID)(*(_DWORD *)(this + 7304) - 32),
      (LPCVOID)(this + 7312),
      1u,
      nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7292), (LPCVOID)(this + 7300), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7280), (LPCVOID)(this + 7288), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7268), (LPCVOID)(this + 7276), 1u, nullptr);
    v26 = *(void **)(this + 7360);
    v21 = *(void **)(this + 112);
    Buffer = 20;
    WriteProcessMemory(v21, v26, &Buffer, 1u, nullptr);
    v27 = (void *)(*(_DWORD *)(this + 7360) + 8);
    v22 = *(void **)(this + 112);
    Buffer = 14;
    WriteProcessMemory(v22, v27, &Buffer, 1u, nullptr);
    v28 = (void *)(*(_DWORD *)(this + 7360) + 16);
    v23 = *(void **)(this + 112);
    Buffer = 10;
    WriteProcessMemory(v23, v28, &Buffer, 1u, nullptr);
    v29 = (void *)(*(_DWORD *)(this + 7360) + 24);
    v24 = *(void **)(this + 112);
    Buffer = 9;
    WriteProcessMemory(v24, v29, &Buffer, 1u, nullptr);
    v30 = (void *)(*(_DWORD *)(this + 7360) + 32);
    v25 = *(void **)(this + 112);
    Buffer = 8;
    WriteProcessMemory(v25, v30, &Buffer, 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7256), (LPCVOID)(this + 7264), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7244), (LPCVOID)(this + 7252), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7232), (LPCVOID)(this + 7240), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7220), (LPCVOID)(this + 7228), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7208), (LPCVOID)(this + 7216), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7204), (LPCVOID)(this + 7216), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7192), (LPCVOID)(this + 7200), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7180), (LPCVOID)(this + 7188), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7168), (LPCVOID)(this + 7176), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7156), (LPCVOID)(this + 7164), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7144), (LPCVOID)(this + 7152), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7052), (LPCVOID)(this + 7060), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7132), (LPCVOID)(this + 7140), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7120), (LPCVOID)(this + 7128), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7108), (LPCVOID)(this + 7116), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7100), (LPCVOID)(this + 7104), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7088), (LPCVOID)(this + 7096), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7076), (LPCVOID)(this + 7084), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7064), (LPCVOID)(this + 7072), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7040), (LPCVOID)(this + 7048), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7028), (LPCVOID)(this + 7036), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7016), (LPCVOID)(this + 7024), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7012), (LPCVOID)(this + 7020), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7000), (LPCVOID)(this + 7008), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6988), (LPCVOID)(this + 6996), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6976), (LPCVOID)(this + 6984), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6964), (LPCVOID)(this + 6972), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6952), (LPCVOID)(this + 6960), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6940), (LPCVOID)(this + 6948), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6928), (LPCVOID)(this + 6936), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6912), (LPCVOID)(this + 6920), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6900), (LPCVOID)(this + 6908), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6888), (LPCVOID)(this + 6896), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7436), (LPCVOID)(this + 7444), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6876), (LPCVOID)(this + 6884), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6864), (LPCVOID)(this + 6872), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6852), (LPCVOID)(this + 6860), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6836), (LPCVOID)(this + 6848), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6840), (LPCVOID)(this + 6848), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6824), (LPCVOID)(this + 6832), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6812), (LPCVOID)(this + 6820), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6800), (LPCVOID)(this + 6808), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6788), (LPCVOID)(this + 6796), 2u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6776), (LPCVOID)(this + 6784), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6764), (LPCVOID)(this + 6772), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6752), (LPCVOID)(this + 6760), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6740), (LPCVOID)(this + 6748), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6728), (LPCVOID)(this + 6736), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6716), (LPCVOID)(this + 6724), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6712), (LPCVOID)(this + 6708), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6700), (LPCVOID)(this + 6708), 1u, nullptr);
    WriteProcessMemory(
      *(HANDLE *)(this + 112),
      (LPVOID)(*(_DWORD *)(this + 6700) + 48),
      (LPCVOID)(this + 6708),
      1u,
      nullptr);
    WriteProcessMemory(
      *(HANDLE *)(this + 112),
      (LPVOID)(*(_DWORD *)(this + 6700) + 96),
      (LPCVOID)(this + 6708),
      1u,
      nullptr);
    WriteProcessMemory(
      *(HANDLE *)(this + 112),
      (LPVOID)(*(_DWORD *)(this + 6700) + 144),
      (LPCVOID)(this + 6708),
      1u,
      nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6596), (LPCVOID)(this + 6612), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6600), (LPCVOID)(this + 6612), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6604), (LPCVOID)(this + 6612), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6684), (LPCVOID)(this + 6692), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6672), (LPCVOID)(this + 6680), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6660), (LPCVOID)(this + 6668), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6648), (LPCVOID)(this + 6656), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6636), (LPCVOID)(this + 6644), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6584), (LPCVOID)(this + 6592), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6576), (LPCVOID)(this + 6580), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6564), (LPCVOID)(this + 6572), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6552), (LPCVOID)(this + 6560), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6404), (LPCVOID)(this + 6412), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6516), (LPCVOID)(this + 6524), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6540), (LPCVOID)(this + 6548), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6504), (LPCVOID)(this + 6512), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6528), (LPCVOID)(this + 6536), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6492), (LPCVOID)(this + 6500), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6332), (LPCVOID)(this + 6340), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6392), (LPCVOID)(this + 6400), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6380), (LPCVOID)(this + 6388), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6368), (LPCVOID)(this + 6376), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6356), (LPCVOID)(this + 6364), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6344), (LPCVOID)(this + 6352), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6468), (LPCVOID)(this + 6476), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6480), (LPCVOID)(this + 6488), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6464), (LPCVOID)(this + 6476), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6452), (LPCVOID)(this + 6460), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6428), (LPCVOID)(this + 6436), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6416), (LPCVOID)(this + 6424), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6236), (LPCVOID)(this + 6244), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6320), (LPCVOID)(this + 6328), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6308), (LPCVOID)(this + 6316), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6296), (LPCVOID)(this + 6304), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6284), (LPCVOID)(this + 6292), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6272), (LPCVOID)(this + 6280), 4u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6260), (LPCVOID)(this + 6268), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6248), (LPCVOID)(this + 6256), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6224), (LPCVOID)(this + 6232), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6228), (LPCVOID)(this + 6232), 1u, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B5BC, off_42B5C4, dword_42B5C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4285F4, off_4285FC, dword_4285F8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427194, off_42719C, dword_427198, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)dword_4253B4, off_4253BC, dword_4253B8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424414, off_42441C, dword_424418, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4243EC, off_4243F4, dword_4243F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42436C, off_424374, dword_424370, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42424C, off_424254, dword_424250, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4217F4, off_4217FC, dword_4217F8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4217C4, off_4217CC, dword_4217C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_421794, off_42179C, dword_421798, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F994, off_41F99C, dword_41F998, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F8C4, off_41F8CC, dword_41F8C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F914, off_41F91C, dword_41F918, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F8EC, off_41F8F4, dword_41F8F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42B394, off_42B39C, dword_42B398, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42B3BC, off_42B3C4, dword_42B3C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42B3E4, off_42B3EC, dword_42B3E8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42B284, off_42B28C, dword_42B288, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42B2AC, off_42B2B4, dword_42B2B0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B1BC, off_42B1C4, dword_42B1C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42AFAC, off_42AFB4, dword_42AFB0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A78C, off_42A794, dword_42A790, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A5CC, off_42A5D4, dword_42A5D0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A56C, off_42A574, dword_42A570, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429DBC, off_429DC4, dword_429DC0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429D0C, off_429D14, dword_429D10, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429CE4, off_429CEC, dword_429CE8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429CBC, off_429CC4, dword_429CC0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C94, off_429C9C, dword_429C98, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C6C, off_429C74, dword_429C70, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C44, off_429C4C, dword_429C48, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C1C, off_429C24, dword_429C20, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429BF4, off_429BFC, dword_429BF8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429BCC, off_429BD4, dword_429BD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429BA4, off_429BAC, dword_429BA8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B7C, off_429B84, dword_429B80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B54, off_429B5C, dword_429B58, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B2C, off_429B34, dword_429B30, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B04, off_429B0C, dword_429B08, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429ADC, off_429AE4, dword_429AE0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429AB4, off_429ABC, dword_429AB8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A03C, off_42A044, dword_42A040, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A014, off_42A01C, dword_42A018, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429FEC, off_429FF4, dword_429FF0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429FC4, off_429FCC, dword_429FC8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F9C, off_429FA4, dword_429FA0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F74, off_429F7C, dword_429F78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F4C, off_429F54, dword_429F50, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F24, off_429F2C, dword_429F28, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429EFC, off_429F04, dword_429F00, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429ED4, off_429EDC, dword_429ED8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429EAC, off_429EB4, dword_429EB0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429E84, off_429E8C, dword_429E88, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A1AC, off_42A1B4, dword_42A1B0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A14C, off_42A154, dword_42A150, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A124, off_42A12C, dword_42A128, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A08C, off_42A094, dword_42A090, nullptr);
    v5 = (LPCVOID *)&off_42D890;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v5 - 2), *v5, (SIZE_T)*(v5 - 1), nullptr);
      v5 += 3;
    }
    while ( (int)v5 < (int)dword_42D950 );
    v6 = (LPCVOID *)&off_42D4F8;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v6 - 2), *v6, (SIZE_T)*(v6 - 1), nullptr);
      v6 += 3;
    }
    while ( (int)v6 < (int)dword_42D570 );
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42D1D4, off_42D1DC, dword_42D1D8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42D1AC, off_42D1B4, dword_42D1B0, nullptr);
    v7 = (LPCVOID *)&off_42D0F0;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v7 - 2), *v7, (SIZE_T)*(v7 - 1), nullptr);
      v7 += 3;
    }
    while ( (int)v7 < (int)dword_42D114 );
    v8 = (LPCVOID *)&off_42CFC8;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v8 - 2), *v8, (SIZE_T)*(v8 - 1), nullptr);
      v8 += 3;
    }
    while ( (int)v8 < (int)dword_42CFF8 );
    v9 = (LPCVOID *)&off_42CD70;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v9 - 2), *v9, (SIZE_T)*(v9 - 1), nullptr);
      v9 += 3;
    }
    while ( (int)v9 < (int)dword_42CD94 );
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CC84, off_42CC8C, dword_42CC88, nullptr);
    for ( i = 0; i < 4; ++i )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42CB74[i],
        (char *)&unk_42CBDC + dword_42CB94[i],
        dword_42CB84[i],
        nullptr);
    for ( j = 0; j < 4; ++j )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42CADC[j],
        (char *)&unk_42CB40 + dword_42CAFC[j],
        dword_42CAEC[j],
        nullptr);
    for ( k = 0; k < 3; ++k )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42CA78[k],
        (char *)&unk_42CABC + dword_42CA90[k],
        dword_42CA84[k],
        nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CA6C, off_42CA74, dword_42CA70, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C93C, off_42C944, dword_42C940, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CA0C, off_42CA14, dword_42CA10, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C9C4, off_42C9CC, dword_42C9C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C60C, off_42C614, dword_42C610, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_42C5B4, off_42C5BC, dword_42C5B8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C55C, off_42C564, dword_42C560, nullptr);
    for ( m = 0; m < 6; ++m )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42C134[m],
        (char *)&unk_42C1E4 + dword_42C164[m],
        dword_42C14C[m],
        nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C064, off_42C06C, dword_42C068, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42BF9C, off_42BFA4, dword_42BFA0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42BDD4, off_42BDDC, dword_42BDD8, nullptr);
    for ( n = 0; n < 6; ++n )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42B9D0[n],
        (char *)&unk_42BA30 + dword_42BA00[n],
        dword_42B9E8[n],
        nullptr);
    for ( ii = 0; ii < 4; ++ii )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42B908[ii],
        (char *)&unk_42B954 + dword_42B928[ii],
        dword_42B918[ii],
        nullptr);
    for ( jj = 0; jj < 4; ++jj )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_42B890[jj],
        (char *)&unk_42B8E4 + dword_42B8B0[jj],
        dword_42B8A0[jj],
        nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B884, off_42B88C, dword_42B888, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B81C, off_42B824, dword_42B820, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B844, off_42B84C, dword_42B848, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B784, off_42B78C, dword_42B788, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B70C, off_42B714, dword_42B710, nullptr);
    v17 = (LPCVOID *)&off_42B6C0;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v17 - 2), *v17, (SIZE_T)*(v17 - 1), nullptr);
      v17 += 3;
    }
    while ( (int)v17 < (int)dword_42B6E4 );
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B574, off_42B57C, dword_42B578, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B54C, off_42B554, dword_42B550, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B534, off_42B53C, dword_42B538, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B50C, off_42B514, dword_42B510, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4298AC, off_4298B4, dword_4298B0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42978C, off_429794, dword_429790, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42971C, off_429724, dword_429720, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429684, off_42968C, dword_429688, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429604, off_42960C, dword_429608, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4294E4, off_4294EC, dword_4294E8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4294BC, off_4294C4, dword_4294C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429494, off_42949C, dword_429498, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429404, off_42940C, dword_429408, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4293C4, off_4293CC, dword_4293C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42936C, off_429374, dword_429370, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4292DC, off_4292E4, dword_4292E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429214, off_42921C, dword_429218, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4291BC, off_4291C4, dword_4291C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429184, off_42918C, dword_429188, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4290DC, off_4290E4, dword_4290E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42909C, off_4290A4, dword_4290A0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_429044, off_42904C, dword_429048, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428FCC, off_428FD4, dword_428FD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), off_428F3C, off_428F44, dword_428F40, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428BCC, off_428BD4, dword_428BD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428EDC, off_428EE4, dword_428EE0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428E84, off_428E8C, dword_428E88, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423B2C, off_423B34, dword_423B30, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D84, off_428D8C, dword_428D88, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D64, off_428D6C, dword_428D68, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D44, off_428D4C, dword_428D48, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428CB4, off_428CBC, dword_428CB8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428B7C, off_428B84, dword_428B80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428B1C, off_428B24, dword_428B20, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428AE4, off_428AEC, dword_428AE8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428A24, off_428A2C, dword_428A28, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4289D4, off_4289DC, dword_4289D8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4288C4, off_4288CC, dword_4288C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4288EC, off_4288F4, dword_4288F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42889C, off_4288A4, dword_4288A0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42887C, off_428884, dword_428880, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42885C, off_428864, dword_428860, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42883C, off_428844, dword_428840, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4287BC, off_4287C4, dword_4287C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42871C, off_428724, dword_428720, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428684, off_42868C, dword_428688, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428664, off_42866C, dword_428668, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428484, off_42848C, dword_428488, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42842C, off_428434, dword_428430, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428354, off_42835C, dword_428358, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42815C, off_428164, dword_428160, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_428124, off_42812C, dword_428128, nullptr);
    for ( kk = 0; kk < 5; ++kk )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_428000[kk],
        (char *)&unk_428080 + dword_428028[kk],
        dword_428014[kk],
        nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427474, off_42747C, dword_427478, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4273E4, off_4273EC, dword_4273E8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42737C, off_427384, dword_427380, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427354, off_42735C, dword_427358, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427314, off_42731C, dword_427318, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427FF4, off_427FFC, dword_427FF8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4272D4, off_4272DC, dword_4272D8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427294, off_42729C, dword_427298, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427234, off_42723C, dword_427238, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4271EC, off_4271F4, dword_4271F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426F04, off_426F0C, dword_426F08, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_420044, off_42004C, dword_420048, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42716C, off_427174, dword_427170, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427144, off_42714C, dword_427148, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4270BC, off_4270C4, dword_4270C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426FB4, off_426FBC, dword_426FB8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426EDC, off_426EE4, dword_426EE0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427A7C, off_427A84, dword_427A80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427934, off_42793C, dword_427938, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427FC4, off_427FCC, dword_427FC8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427CCC, off_427CD4, dword_427CD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427F2C, off_427F34, dword_427F30, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427EEC, off_427EF4, dword_427EF0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427E04, off_427E0C, dword_427E08, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427D74, off_427D7C, dword_427D78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427C7C, off_427C84, dword_427C80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B94, off_427B9C, dword_427B98, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B4C, off_427B54, dword_427B50, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B24, off_427B2C, dword_427B28, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_427A04, off_427A0C, dword_427A08, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42994C, off_429954, dword_429950, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42990C, off_429914, dword_429910, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42799C, off_4279A4, dword_4279A0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4278EC, off_4278F4, dword_4278F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4278C4, off_4278CC, dword_4278C8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42789C, off_4278A4, dword_4278A0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4274BC, off_4274C4, dword_4274C0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426FDC, off_426FE4, dword_426FE0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426E74, off_426E7C, dword_426E78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426E34, off_426E3C, dword_426E38, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426CAC, off_426CB4, dword_426CB0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426B34, off_426B3C, dword_426B38, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42674C, off_426754, dword_426750, nullptr);
    v19 = (LPCVOID *)&off_4266D8;
    do
    {
      WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v19 - 2), *v19, (SIZE_T)*(v19 - 1), nullptr);
      v19 += 3;
    }
    while ( (int)v19 < (int)dword_426714 );
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426534, off_42653C, dword_426538, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4264DC, off_4264E4, dword_4264E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42631C, off_426324, dword_426320, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4260FC, off_426104, dword_426100, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426094, off_42609C, dword_426098, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_426034, off_42603C, dword_426038, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425F7C, off_425F84, dword_425F80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425E94, off_425E9C, dword_425E98, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425D7C, off_425D84, dword_425D80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425D0C, off_425D14, dword_425D10, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425CCC, off_425CD4, dword_425CD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425CAC, off_425CB4, dword_425CB0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C74, off_425C7C, dword_425C78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C54, off_425C5C, dword_425C58, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C1C, off_425C24, dword_425C20, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425BF4, off_425BFC, dword_425BF8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425BB4, off_425BBC, dword_425BB8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B74, off_425B7C, dword_425B78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B4C, off_425B54, dword_425B50, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B0C, off_425B14, dword_425B10, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425AE4, off_425AEC, dword_425AE8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425ABC, off_425AC4, dword_425AC0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A94, off_425A9C, dword_425A98, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A44, off_425A4C, dword_425A48, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A04, off_425A0C, dword_425A08, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4259DC, off_4259E4, dword_4259E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4259B4, off_4259BC, dword_4259B8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42598C, off_425994, dword_425990, nullptr);
    for ( mm = 0; mm < 2; ++mm )
      WriteProcessMemory(
        *(HANDLE *)(this + 112),
        (LPVOID)dword_4258E8[mm],
        (char *)&unk_42592C + dword_4258F8[mm],
        dword_4258F0[mm],
        nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425834, off_42583C, dword_425838, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4257E4, off_4257EC, dword_4257E8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4257A4, off_4257AC, dword_4257A8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425734, off_42573C, dword_425738, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424D2C, off_424D34, dword_424D30, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4256AC, off_4256B4, dword_4256B0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42561C, off_425624, dword_425620, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4255DC, off_4255E4, dword_4255E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425524, off_42552C, dword_425528, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42544C, off_425454, dword_425450, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424824, off_42482C, dword_424828, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247FC, off_424804, dword_424800, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247D4, off_4247DC, dword_4247D8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247AC, off_4247B4, dword_4247B0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424784, off_42478C, dword_424788, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425334, off_42533C, dword_425338, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4252EC, off_4252F4, dword_4252F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425264, off_42526C, dword_425268, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_425164, off_42516C, dword_425168, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424DE4, off_424DEC, dword_424DE8, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42559C, off_4255A4, dword_4255A0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424D7C, off_424D84, dword_424D80, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424CCC, off_424CD4, dword_424CD0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424C8C, off_424C94, dword_424C90, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424C3C, off_424C44, dword_424C40, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4246DC, off_4246E4, dword_4246E0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424B3C, off_424B44, dword_424B40, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424694, off_42469C, dword_424698, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424AFC, off_424B04, dword_424B00, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424AAC, off_424AB4, dword_424AB0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423564, off_42356C, dword_423568, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423504, off_42350C, dword_423508, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42348C, off_423494, dword_423490, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42327C, off_423284, dword_423280, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_422D8C, off_422D94, dword_422D90, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423A5C, off_423A64, dword_423A60, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423A24, off_423A2C, dword_423A28, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4239EC, off_4239F4, dword_4239F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424344, off_42434C, dword_424348, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424A44, off_424A4C, dword_424A48, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_42494C, off_424954, dword_424950, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424864, off_42486C, dword_424868, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424744, off_42474C, dword_424748, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_424644, off_42464C, dword_424648, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4245EC, off_4245F4, dword_4245F0, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_423F74, off_423F7C, dword_423F78, nullptr);
    WriteProcessMemory(*(HANDLE *)(this + 112), dword_4245A4, off_4245AC, dword_4245A8, nullptr);
    JUMPOUT(0x417703);
  }
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 112) = 0;
  return result;
}
