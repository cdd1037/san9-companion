// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401120; original name: sub_401120
void __thiscall sub_401120(unsigned int *this, struct CDataExchange *a2)
{
  unsigned int *v2; // edi

  v2 = this;
  DDX_Control(a2, 1149, (struct CWnd *)(this + 24));
  DDX_Text(a2, 1152, v2 + 40);
  DDV_MinMaxUInt(a2, v2[40], 1u, 5u);
  DDX_Text(a2, 1146, v2 + 41);
  DDV_MinMaxUInt(a2, v2[41], 5u, 0x1Eu);
  DDX_Text(a2, 1148, v2 + 42);
  DDV_MinMaxUInt(a2, v2[42], 0, 0x2710u);
  DDX_Text(a2, 1147, v2 + 43);
  DDV_MinMaxUInt(a2, v2[43], 5u, 0x32u);
  DDX_Text(a2, 1145, v2 + 44);
  DDV_MinMaxUInt(a2, v2[44], 5u, 0x3Cu);
  DDX_Text(a2, 1144, v2 + 45);
  DDV_MinMaxUInt(a2, v2[45], 5u, 0x32u);
  DDX_Text(a2, 1143, v2 + 46);
  DDV_MinMaxUInt(a2, v2[46], 5u, 0x32u);
  DDX_Text(a2, 1151, v2 + 47);
  DDV_MinMaxUInt(a2, v2[47], 1u, 8u);
  v2 += 48;
  DDX_Text(a2, 1150, v2);
  DDV_MinMaxUInt(a2, *v2, 0, 0xAu);
}
