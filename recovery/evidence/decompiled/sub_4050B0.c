// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004050B0; original name: sub_4050B0
int __thiscall sub_4050B0(CWnd *this)
{
  int result; // eax

  result = CWnd::UpdateData(this, 1);
  if ( result != 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 85) + 4 * *((_DWORD *)this + 86)) = *((_DWORD *)this + 57)
                                                                     + 4
                                                                     * (*((_DWORD *)this + 58)
                                                                      + 4
                                                                      * (*((_DWORD *)this + 59)
                                                                       + 4
                                                                       * (*((_DWORD *)this + 60)
                                                                        + 4
                                                                        * (*((_DWORD *)this + 65)
                                                                         + 4
                                                                         * (*((_DWORD *)this + 61)
                                                                          + 4
                                                                          * (*((_DWORD *)this + 62)
                                                                           + 4
                                                                           * (*((_DWORD *)this + 63)
                                                                            + 4 * *((_DWORD *)this + 64))))))));
    return 1;
  }
  return result;
}
