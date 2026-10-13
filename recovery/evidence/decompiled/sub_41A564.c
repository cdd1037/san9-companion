// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A564; original name: ?Create@CWnd@@UAEHPBD0KABUtagRECT@@PAV1@IPAUCCreateContext@@@Z
// attributes: thunk
int __thiscall CWnd::Create(
        CWnd *this,
        const char *a2,
        const char *a3,
        unsigned int a4,
        const struct tagRECT *a5,
        struct CWnd *a6,
        unsigned int a7,
        struct CCreateContext *a8)
{
  return __imp_?Create@CWnd@@UAEHPBD0KABUtagRECT@@PAV1@IPAUCCreateContext@@@Z(this, a2, a3, a4, a5, a6, a7, a8);
}
