// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A77A; original name: ?OpenDocumentFile@CWinApp@@UAEPAVCDocument@@PBD@Z
// attributes: thunk
struct CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *a2)
{
  return __imp_?OpenDocumentFile@CWinApp@@UAEPAVCDocument@@PBD@Z(this, a2);
}
