// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404C70; original name: sub_404C70
void __thiscall sub_404C70(int this, struct CDataExchange *a2)
{
  int v2; // edi

  v2 = this;
  DDX_Control(a2, 1119, (struct CWnd *)(this + 96));
  DDX_Control(a2, 1115, (struct CWnd *)(v2 + 160));
  DDX_Text(a2, 1043, (struct CString *)(v2 + 224));
  DDV_MaxChars(a2, (const struct CString *)(v2 + 224), 8);
  DDX_Radio(a2, 1056, (int *)(v2 + 228));
  DDX_Radio(a2, 1060, (int *)(v2 + 232));
  DDX_Radio(a2, 1064, (int *)(v2 + 236));
  DDX_Radio(a2, 1068, (int *)(v2 + 240));
  DDX_Radio(a2, 1076, (int *)(v2 + 244));
  DDX_Radio(a2, 1080, (int *)(v2 + 248));
  DDX_Radio(a2, 1084, (int *)(v2 + 252));
  DDX_Radio(a2, 1088, (int *)(v2 + 256));
  DDX_Radio(a2, 1072, (int *)(v2 + 260));
  DDX_Text(a2, 1092, (unsigned __int8 *)(v2 + 264));
  DDV_MinMaxByte(a2, *(_BYTE *)(v2 + 264), 0, 0x73u);
  DDX_Text(a2, 1094, (unsigned __int8 *)(v2 + 265));
  DDV_MinMaxByte(a2, *(_BYTE *)(v2 + 265), 0, 0x73u);
  DDX_Text(a2, 1093, (unsigned __int8 *)(v2 + 266));
  DDV_MinMaxByte(a2, *(_BYTE *)(v2 + 266), 0, 0x73u);
  DDX_Text(a2, 1095, (unsigned __int8 *)(v2 + 267));
  DDV_MinMaxByte(a2, *(_BYTE *)(v2 + 267), 0, 0x73u);
  DDX_Check(a2, 1096, (int *)(v2 + 268));
  DDX_Check(a2, 1104, (int *)(v2 + 272));
  DDX_Check(a2, 1101, (int *)(v2 + 276));
  DDX_Check(a2, 1098, (int *)(v2 + 280));
  DDX_Check(a2, 1103, (int *)(v2 + 284));
  DDX_Check(a2, 1099, (int *)(v2 + 288));
  DDX_Check(a2, 1097, (int *)(v2 + 292));
  DDX_Check(a2, 1100, (int *)(v2 + 296));
  DDX_Check(a2, 1102, (int *)(v2 + 300));
  DDX_Text(a2, 1105, (__int16 *)(v2 + 304));
  DDX_Text(a2, 1113, (__int16 *)(v2 + 306));
  DDX_Text(a2, 1110, (__int16 *)(v2 + 308));
  DDX_Text(a2, 1107, (__int16 *)(v2 + 310));
  DDX_Text(a2, 1112, (__int16 *)(v2 + 312));
  DDX_Text(a2, 1108, (__int16 *)(v2 + 314));
  DDX_Text(a2, 1106, (__int16 *)(v2 + 316));
  DDX_Text(a2, 1109, (__int16 *)(v2 + 318));
  DDX_Text(a2, 1111, (__int16 *)(v2 + 320));
  DDX_Text(a2, 1118, (__int16 *)(v2 + 322));
  DDV_MinMaxInt(a2, *(__int16 *)(v2 + 322), 0, 60);
  DDX_Text(a2, 1116, (__int16 *)(v2 + 324));
  DDV_MinMaxInt(a2, *(__int16 *)(v2 + 324), 0, 799);
  DDX_Text(a2, 1117, (__int16 *)(v2 + 326));
  DDV_MinMaxInt(a2, *(__int16 *)(v2 + 326), 0, 799);
  DDX_Text(a2, 1045, (unsigned int *)(v2 + 328));
  DDV_MinMaxUInt(a2, *(_DWORD *)(v2 + 328), 0, 0x73u);
  DDX_Text(a2, 1135, (struct CString *)(v2 + 332));
  DDV_MaxChars(a2, (const struct CString *)(v2 + 332), 6);
  v2 += 336;
  DDX_Text(a2, 1120, (unsigned int *)v2);
  DDV_MinMaxUInt(a2, *(_DWORD *)v2, 0x4B0u, 0xBB8u);
}
