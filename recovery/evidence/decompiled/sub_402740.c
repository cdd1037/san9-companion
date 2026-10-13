// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402740; original name: sub_402740
void __thiscall sub_402740(unsigned int *this, struct CDataExchange *a2)
{
  unsigned int *v2; // edi

  v2 = this;
  DDX_Control(a2, 1138, (struct CWnd *)(this + 24));
  DDX_Text(a2, 1140, v2 + 40);
  DDV_MinMaxUInt(a2, v2[40], 0, 0x1Eu);
  DDX_Text(a2, 1141, v2 + 41);
  DDV_MinMaxUInt(a2, v2[41], 0, 0x9C4u);
  v2 += 42;
  DDX_Text(a2, 1139, v2);
  DDV_MinMaxUInt(a2, *v2, 0, 0x64u);
}
