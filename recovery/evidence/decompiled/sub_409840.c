// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00409840; original name: sub_409840
char __thiscall sub_409840(int this)
{
  int v2; // eax
  int i; // ecx
  int v4; // edx
  int v5; // eax
  int j; // ecx
  int v7; // edx
  char *v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // esi
  char *v12; // edx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // esi
  char *v16; // edx
  LPCVOID *v17; // eax
  int v18; // ecx
  int v19; // esi
  _DWORD *v20; // eax
  char *v21; // edx
  int v22; // ecx
  int k; // esi
  int v24; // edi
  char *v25; // edx
  _DWORD *v26; // eax
  int v27; // ecx
  int v28; // esi
  char *v29; // edx
  _DWORD *v30; // eax
  int v31; // ecx
  int v32; // esi
  char *v33; // edx
  _DWORD *v34; // eax
  int v35; // ecx
  int v36; // esi
  char *v37; // edx
  LPCVOID *v38; // eax
  int v39; // ecx
  int v40; // esi
  char *v41; // edx
  LPCVOID *v42; // eax
  int v43; // ecx
  int v44; // esi
  char *v45; // edx
  _DWORD *v46; // eax
  int v47; // ecx
  int v48; // esi
  char *v49; // edx
  _DWORD *v50; // eax
  int v51; // ecx
  int v52; // esi
  char *v53; // edx
  LPCVOID *v54; // eax
  int v55; // ecx
  int v56; // esi
  char *v57; // edx
  LPCVOID *v58; // eax
  int v59; // ecx
  int v60; // esi
  char *v61; // edx
  _DWORD *v62; // eax
  int v63; // ecx
  int v64; // esi
  char *v65; // edx
  _DWORD *v66; // eax
  int v67; // ecx
  int v68; // esi
  char *v69; // edx
  _DWORD *v70; // eax
  int v71; // ecx
  int v72; // esi
  char *v73; // edx
  LPCVOID *v74; // eax
  int v75; // ecx
  int v76; // esi
  int Buffer; // [esp+8h] [ebp-4h] BYREF

  if ( !ReadProcessMemory(
          *(HANDLE *)(this + 112),
          (LPCVOID)(*(_DWORD *)(this + 6448) + *(_DWORD *)(this + 6444)),
          &Buffer,
          4u,
          nullptr)
    || Buffer != -17890115
    || !ReadProcessMemory(
          *(HANDLE *)(this + 112),
          (LPCVOID)(*(_DWORD *)(this + 6444) + *(_DWORD *)(this + 6448) + 8),
          &Buffer,
          4u,
          nullptr)
    || Buffer != 0x10000
    || !ReadProcessMemory(
          *(HANDLE *)(this + 112),
          (LPCVOID)(*(_DWORD *)(this + 6444) + *(_DWORD *)(this + 6448) + 12),
          &Buffer,
          4u,
          nullptr)
    || Buffer != 0x10000 )
  {
    return 0;
  }
  *(_DWORD *)(this + 5224) = 19192664;
  v2 = this + 5228;
  for ( i = 49; i != 0; --i )
  {
    v4 = *(_DWORD *)(v2 - 4);
    v2 += 4;
    *(_DWORD *)(v2 - 4) = v4 + 496;
  }
  *(_DWORD *)(this + 5424) = 19103864;
  v5 = this + 5428;
  for ( j = 199; j != 0; --j )
  {
    v7 = *(_DWORD *)(v5 - 4);
    v5 += 4;
    *(_DWORD *)(v5 - 4) = v7 + 444;
  }
  v8 = (char *)&unk_4204C8;
  v9 = &unk_42F704;
  v10 = 0;
  do
  {
    v11 = dword_4204B8[v10++];
    *(v9 - 1) = v11;
    *v9 = dword_4204BC[v10];
    v9[1] = v8;
    v8 += 16;
    v9 += 3;
  }
  while ( (int)v8 < (int)byte_4204E8 );
  v12 = (char *)&unk_41F9B0;
  v13 = &unk_42F584;
  v14 = 0;
  do
  {
    v15 = dword_41F9A0[v14++];
    *(v13 - 1) = v15;
    *v13 = dword_41F9A4[v14];
    v13[1] = v12;
    v12 += 16;
    v13 += 3;
  }
  while ( (int)v12 < (int)byte_41F9D0 );
  v16 = (char *)&unk_4210A8;
  v17 = &dword_42F7BC;
  v18 = 0;
  do
  {
    v19 = dword_421098[v18++];
    *(v17 - 1) = (LPCVOID)v19;
    *v17 = (LPCVOID)dword_42109C[v18];
    v17[1] = v16;
    v16 += 16;
    v17 += 3;
  }
  while ( (int)v16 < (int)byte_4210C8 );
  v20 = &unk_42F59C;
  v21 = (char *)&unk_41FB44;
  v22 = 0;
  for ( k = 5; k != 0; --k )
  {
    v24 = dword_41FAEC[v22--];
    *(v20 - 1) = v24;
    *v20 = dword_41FB04[v22];
    v20[1] = v21;
    v21 -= 16;
    v20 += 3;
  }
  v25 = (char *)&unk_41FF30;
  v26 = &unk_42F6C4;
  v27 = 0;
  do
  {
    v28 = dword_41FF18[v27++];
    *(v26 - 1) = v28;
    *v26 = dword_41FF20[v27];
    v26[1] = v25;
    v25 += 16;
    v26 += 3;
  }
  while ( (int)v25 < (int)byte_41FF60 );
  v29 = (char *)&unk_421EB8;
  v30 = &unk_42F7EC;
  v31 = 0;
  do
  {
    v32 = dword_421EA8[v31++];
    *(v30 - 1) = v32;
    *v30 = dword_421EAC[v31];
    v30[1] = v29;
    v29 += 16;
    v30 += 3;
  }
  while ( (int)v29 < (int)byte_421ED8 );
  v33 = (char *)&unk_41FE40;
  v34 = &unk_42F67C;
  v35 = 0;
  do
  {
    v36 = dword_41FE30[v35++];
    *(v34 - 1) = v36;
    *v34 = dword_41FE34[v35];
    v34[1] = v33;
    v33 += 16;
    v34 += 3;
  }
  while ( (int)v33 < (int)byte_41FE60 );
  v37 = (char *)&unk_420FA0;
  v38 = &dword_42F794;
  v39 = 0;
  do
  {
    v40 = dword_420F88[v39++];
    *(v38 - 1) = (LPCVOID)v40;
    *v38 = (LPCVOID)dword_420F90[v39];
    v38[1] = v37;
    v37 += 16;
    v38 += 3;
  }
  while ( (int)v37 < (int)byte_420FD0 );
  dword_42F5D8 = dword_41FB80;
  dword_42F5DC = dword_41FB84;
  dword_42F5E0 = (int)&unk_41FB88;
  v41 = (char *)&unk_41FFC0;
  v42 = &dword_42F6EC;
  v43 = 0;
  do
  {
    v44 = dword_41FFB0[v43++];
    *(v42 - 1) = (LPCVOID)v44;
    *v42 = (LPCVOID)dword_41FFB4[v43];
    v42[1] = v41;
    v41 += 16;
    v42 += 3;
  }
  while ( (int)v41 < (int)byte_41FFE0 );
  dword_42F5E8 = dword_41FBE8;
  dword_42F5EC = dword_41FBEC;
  dword_42F5F0 = (int)&unk_41FBF0;
  v45 = (char *)&unk_41FEA8;
  v46 = &unk_42F694;
  v47 = 0;
  do
  {
    v48 = dword_41FE88[v47++];
    *(v46 - 1) = v48;
    *v46 = dword_41FE94[v47];
    v46[1] = v45;
    v45 += 16;
    v46 += 3;
  }
  while ( (int)v45 < (int)byte_41FEE8 );
  v49 = (char *)&unk_420560;
  v50 = &unk_42F71C;
  v51 = 0;
  do
  {
    v52 = dword_420548[v51++];
    *(v50 - 1) = v52;
    *v50 = dword_420550[v51];
    v50[1] = v49;
    v49 += 16;
    v50 += 3;
  }
  while ( (int)v49 < (int)byte_420590 );
  v53 = (char *)&unk_420CB8;
  v54 = &dword_42F76C;
  v55 = 0;
  do
  {
    v56 = dword_420CA0[v55++];
    *(v54 - 1) = (LPCVOID)v56;
    *v54 = (LPCVOID)dword_420CA8[v55];
    v54[1] = v53;
    v53 += 16;
    v54 += 3;
  }
  while ( (int)v53 < (int)byte_420CE8 );
  dword_42F5F8 = dword_41FC28;
  dword_42F5FC = dword_41FC2C;
  dword_42F608 = dword_41FC68;
  dword_42F60C = dword_41FC6C;
  dword_42F600 = (int)&unk_41FC30;
  dword_42F610 = (int)&unk_41FC70;
  v57 = (char *)&unk_41FCC8;
  v58 = &dword_42F61C;
  v59 = 0;
  do
  {
    v60 = dword_41FCA8[v59++];
    *(v58 - 1) = (LPCVOID)v60;
    *v58 = (LPCVOID)dword_41FCB4[v59];
    v58[1] = v57;
    v57 += 16;
    v58 += 3;
  }
  while ( (int)v57 < (int)byte_41FD08 );
  v61 = (char *)&unk_421D90;
  v62 = &unk_42F7D4;
  v63 = 0;
  do
  {
    v64 = dword_421D80[v63++];
    *(v62 - 1) = v64;
    *v62 = dword_421D84[v63];
    v62[1] = v61;
    v61 += 16;
    v62 += 3;
  }
  while ( (int)v61 < (int)byte_421DB0 );
  v65 = (char *)&unk_41FDE8;
  v66 = &unk_42F664;
  v67 = 0;
  do
  {
    v68 = dword_41FDD8[v67++];
    *(v66 - 1) = v68;
    *v66 = dword_41FDDC[v67];
    v66[1] = v65;
    v65 += 16;
    v66 += 3;
  }
  while ( (int)v65 < (int)byte_41FE08 );
  v69 = (char *)&unk_41FD40;
  v70 = &unk_42F64C;
  v71 = 0;
  do
  {
    v72 = dword_41FD30[v71++];
    *(v70 - 1) = v72;
    *v70 = dword_41FD34[v71];
    v70[1] = v69;
    v69 += 16;
    v70 += 3;
  }
  while ( (int)v69 < (int)byte_41FD60 );
  v73 = (char *)&unk_420B28;
  v74 = &dword_42F744;
  v75 = 0;
  do
  {
    v76 = dword_420B10[v75++];
    *(v74 - 1) = (LPCVOID)v76;
    *v74 = (LPCVOID)dword_420B18[v75];
    v74[1] = v73;
    v73 += 16;
    v74 += 3;
  }
  while ( (int)v73 < (int)byte_420B58 );
  return 1;
}
