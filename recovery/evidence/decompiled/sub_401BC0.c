// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401BC0; original name: sub_401BC0
void __thiscall sub_401BC0(int this, struct CDataExchange *a2)
{
  int v2; // edi

  v2 = this;
  DDX_Control(a2, 1121, (struct CWnd *)(this + 96));
  DDX_CBIndex(a2, 1122, (int *)(v2 + 160));
  DDX_Check(a2, 1124, (int *)(v2 + 164));
  DDX_Check(a2, 1123, (int *)(v2 + 168));
  DDX_Check(a2, 1130, (int *)(v2 + 172));
  DDX_Text(a2, 1126, (unsigned int *)(v2 + 176));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 176), 6u, 0x14u);
  DDX_Text(a2, 1128, (unsigned int *)(v2 + 180));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 180), 4u, 0xFu);
  DDX_Text(a2, 1127, (unsigned int *)(v2 + 184));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 184), 4u, 0xFu);
  DDX_Text(a2, 1129, (unsigned int *)(v2 + 188));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 188), 4u, 0xAu);
  DDX_Text(a2, 1125, (unsigned int *)(v2 + 192));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 192), 0xAu, 0x32u);
  DDX_Check(a2, 1133, (int *)(v2 + 196));
  DDX_Text(a2, 1134, (unsigned int *)(v2 + 200));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 200), 0, 0x32u);
  DDX_Text(a2, 1135, (unsigned int *)(v2 + 204));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 204), 0, 0x32u);
  DDX_Text(a2, 1136, (unsigned int *)(v2 + 208));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 208), 0, 0x32u);
  DDX_Text(a2, 1137, (unsigned int *)(v2 + 212));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 212), 0, 0x32u);
  DDX_Text(a2, 1138, (unsigned int *)(v2 + 216));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 216), 0, 0x32u);
  DDX_Text(a2, 1139, (unsigned int *)(v2 + 220));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 220), 0, 0x32u);
  DDX_Text(a2, 1140, (unsigned int *)(v2 + 224));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 224), 0, 0x32u);
  DDX_Text(a2, 1141, (unsigned int *)(v2 + 228));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 228), 0, 0x32u);
  v2 += 232;
  DDX_Text(a2, 1142, (unsigned int *)v2);
  DDV_MinMaxUInt(a2, *(_DWORD *)v2, 0x14u, 0x64u);
}
