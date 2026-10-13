// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A618; original name: ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ
// attributes: thunk
struct AFX_MODULE_STATE *__stdcall AfxGetModuleState()
{
  return __imp_?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ();
}
