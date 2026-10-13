
typedef struct
{
	DWORD dwAddr;
	DWORD dwSize;
	BYTE *pCode;
}ASM_PATCH;

#define PATCH_SIZE 16

/////////////////////////////////////////
#define PATCH_SEND_MESSAGE_NUM 3
#define HWND_MSG_ADDRESS 0x43F7E4
#define SEND_MSG_ADDRESS 0x43F824

DWORD dwAddrSendMessage[PATCH_SEND_MESSAGE_NUM] = {SEND_MSG_ADDRESS, 0x43F843, 0x43F9B3};
DWORD dwSizeSendMessage[PATCH_SEND_MESSAGE_NUM] = {0xB, 0xC, 0xC};
BYTE codeSendMessage[PATCH_SEND_MESSAGE_NUM][PATCH_SIZE] = {
	{0xB8, 0xE4, 0xF7, 0x43, 0x00,       //mov         eax,HWND_MSG_ADDRESS
	0xFF, 0x74, 0x24, 0x08,              //push        dword ptr [esp+8]
	0xEB, 0x14},
	//1:9+2
	{0xFF, 0x74, 0x24, 0x08,             //push        dword ptr [esp+8]
	0xFF, 0x70, 0x04,                    //push        dword ptr [eax+4]
	0xE9, 0x64, 0x01, 0x00, 0x00},
	//2:7+5
	{0xFF, 0x30,                         //push        dword ptr [eax]
	0xA1, 0xCC, 0xF3, 0x5F, 0x00,        //mov         eax,[5FF3CCh]=User32::SendMessage()
	0xFF, 0xD0,                          //call        eax
	0xC2, 0x08, 0x00                     //ret         8
	}//3:C
};
ASM_PATCH patchSendMessage[PATCH_SEND_MESSAGE_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////////////
BYTE codeLeagueLowPrestigeThunk[] = {
	0x8B, 0xD0,
	0x81, 0xFF, 0x20, 0xBF, 0x02, 0x00};//cmp edi, 2BF20h
BYTE codeLeagueLowPrestigeOldThunk[] = {
	0x03, 0xF8,//add edi, eax
	0x81, 0xFF, 0x40, 0x0D, 0x03, 0x00};//cmp edi, 30D40h
ASM_PATCH patchLeagueLowPrestigeThunk[] = {
	{0x57B2C0, sizeof(codeLeagueLowPrestigeThunk), codeLeagueLowPrestigeThunk},
	{0x57B2C0, sizeof(codeLeagueLowPrestigeOldThunk), codeLeagueLowPrestigeOldThunk}};

/////////////////////////////////////////
#define PATCH_MIN_DURABILITY_NUM 2

DWORD dwAddrMinDurability[PATCH_MIN_DURABILITY_NUM] = {0x4B2112, 0x4B23D2};
DWORD dwSizeMinDurability[PATCH_MIN_DURABILITY_NUM] = {0xE, 0xE};
BYTE codeMinDurability[PATCH_MIN_DURABILITY_NUM][PATCH_SIZE] = {
	{0x8B, 0xCF,                              //mov         ecx,edi
	0xB8, 0x40, 0x54, 0x43, 0x00,             //mov         eax,435440h
	0xFF, 0xD0,                               //call        eax
	0xE9, 0xB2, 0x02, 0x00, 0x00},
	//1:9+5
	{0x85, 0xC0,                              //test        eax,eax
	0x75, 0x04,                               //jnz         end
	0xFE, 0x4C, 0x24, 0x04,                   //dec         [esp+4]
	                                          //end:
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00}       //jmp         [5FF308h]
	//2:E
};
ASM_PATCH patchMinDurability[PATCH_MIN_DURABILITY_NUM] = {{0, 0, 0}};

BYTE codeMinDurabilityThunk[] = {0xE8, 0x30, 0x80, 0x01, 0x00, 0x42};//4B2112h - 49A0DDh - 5
BYTE codeMinDurabilityOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};
ASM_PATCH patchMinDurabilityThunk[] = {
	{0x49A0DD, sizeof(codeMinDurabilityThunk), codeMinDurabilityThunk},
	{0x49A0DD, sizeof(codeMinDurabilityOldThunk), codeMinDurabilityOldThunk}};

/////////////////////////////////////////
#define PATCH_HARBOR_KILLER_NUM 1

DWORD dwAddrHarborKiller[PATCH_HARBOR_KILLER_NUM] = {0x49A532};
DWORD dwSizeHarborKiller[PATCH_HARBOR_KILLER_NUM] = {0xD};
BYTE codeHarborKiller[PATCH_HARBOR_KILLER_NUM][PATCH_SIZE] = {
	{0x83, 0xF8, 0x02,         //cmp         eax,2
	0x74, 0x05,                //je          end
	0x83, 0xF8, 0x01,          //cmp         eax,1
	0x75, 0x02,                //jne         end2
	                           //end:
	0xB0, 0x06,                //mov         al,6
	                           //end2:
	0xC3                       //ret
	}
};
ASM_PATCH patchHarborKiller[PATCH_HARBOR_KILLER_NUM] = {{0, 0, 0}};

BYTE codeHarborKillerThunk[] = {0xE8, 0x7D, 0xF4, 0xFF, 0xFF};//49A532h - 49B0B0h - 5
BYTE codeHarborKillerOldThunk[] = {0x83, 0xF8, 0x02, 0x74, 0x0A};
ASM_PATCH patchHarborKillerThunk[] = {
	{0x49B0B0, sizeof(codeHarborKillerThunk), codeHarborKillerThunk},
	{0x49B0B0, sizeof(codeHarborKillerOldThunk), codeHarborKillerOldThunk}};

/////////////////////////////////////////
#define PATCH_BUILDING_KILLER_NUM 3

DWORD dwAddrBuildingKiller[PATCH_BUILDING_KILLER_NUM] = {0x43D216, 0x43DB15, 0x43DBF4};
DWORD dwSizeBuildingKiller[PATCH_BUILDING_KILLER_NUM] = {0xA, 8, 0xC};
BYTE codeBuildingKiller[PATCH_BUILDING_KILLER_NUM][PATCH_SIZE] = {
	{0xE8, 0xC5, 0x95, 0x00, 0x00,              //call        4467E0h
	0xE9, 0xF5, 0x08, 0x00, 0x00},
	//1:5+5
	{0x83, 0xF8, 0x01,                          //cmp         eax,1
	0xE9, 0xD7, 0x00, 0x00, 0x00},
	//2:3+5
	{0x75, 0x02,                                //jne         town
	0xB0, 0x07,                                 //mov         al,7
	                                            //town:
	0x83, 0xF8, 0x09,                           //cmp         eax,9
	0x75, 0x02,                                 //jne         end
	0xB0, 0x08,                                 //mov         al,8
	                                            //end:
	0xC3}                                       //ret
	//3:C
};
ASM_PATCH patchBuildingKiller[PATCH_BUILDING_KILLER_NUM] = {{0, 0, 0}};

BYTE codeBuildingKillerThunk[] = {0xE8, 0xD1, 0x00, 0x00, 0x00};//43D216h - 43D140h - 5
BYTE codeBuildingKillerOldThunk[] = {0xE8, 0x9B, 0x96, 0x00, 0x00};
ASM_PATCH patchBuildingKillerThunk[] = {
	{0x43D140, sizeof(codeBuildingKillerThunk), codeBuildingKillerThunk},
	{0x43D140, sizeof(codeBuildingKillerOldThunk), codeBuildingKillerOldThunk}};

/////////////////////////////////////////
#define PATCH_SIEGE_EXPERIENCE_NUM 5

DWORD dwAddrSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM] = {0x499272, 0x499362, 0x494972, 0x49A662, 0x49AFE1};
DWORD dwSizeSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM] = {0xE, 0xD, 0xE, 0xC, 0xF};
BYTE codeSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM][PATCH_SIZE] = {
	{0x8B, 0x51, 0x6C,                        //mov         edx,dword ptr [ecx+6Ch]
	0x8A, 0x42, 0x04,                         //mov         al,byte ptr [edx+4]
	0xC0, 0xE8, 0x02,                         //shr         al,2
	0xE9, 0xE2, 0x00, 0x00, 0x00},
	//1:9+5
	{0x3C, 0x02,                              //cmp         al,2
	0x0F, 0x84, 0xFF, 0x12, 0x00, 0x00,       //je          siege
	0xE9, 0x03, 0xB6, 0xFF, 0xFF},
	//2:8+5
	{0x51,                                    //push        ecx
	0xB8, 0xE1, 0xAF, 0x49, 0x00,             //mov         eax,siege_random
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0xE9, 0xE2, 0x5C, 0x00, 0x00},
	//3:5+5
	{0xA8, 0x03,                              //test        al,03h
	0x74, 0x03,                               //je          siege
	0xC2, 0x08, 0x00,                         //ret         8
                                              //siege:
	0xE9, 0x52, 0x67, 0xFC, 0xFF},            //jmp         460DC0h
	//4:C
	                                          //siege_random:
	{0x6A, 0x01,                              //push        1
	0x6A, 0x0B,                               //push        0Bh
	0x6A, 0x04,                               //push        4
	0xE8, 0x74, 0x22, 0xF8, 0xFF,             //call        41D260h;jmp[5FF318h]
	0x83, 0xC4, 0x0C,                         //add         esp,0Ch
	0xC3}                                     //ret
	//5:10h
};
ASM_PATCH patchSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM] = {{0, 0, 0}};

BYTE codeSiegeExperienceThunk[] = {0xE8, 0x3D, 0xF1, 0xFF, 0xFF};//499272h - 49A130h - 5
BYTE codeSiegeExperienceOldThunk[] = {0xE8, 0x8B, 0x6C, 0xFC, 0xFF};
ASM_PATCH patchSiegeExperienceThunk[] = {
	{0x49A130, sizeof(codeSiegeExperienceThunk), codeSiegeExperienceThunk},
	{0x49A130, sizeof(codeSiegeExperienceOldThunk), codeSiegeExperienceOldThunk}};

/////////////////////////////////////////////
#define PATCH_ALIENATE_EXPERIENCE_NUM 1

DWORD dwAddrAlienateExperience[PATCH_ALIENATE_EXPERIENCE_NUM] = {0x4942A2};
DWORD dwSizeAlienateExperience[PATCH_ALIENATE_EXPERIENCE_NUM] = {0xE};
BYTE codeAlienateExperience[PATCH_ALIENATE_EXPERIENCE_NUM][PATCH_SIZE] = {
	{0x8B, 0x74, 0x24, 0x28,           //mov         esi,dword ptr [esp+28h]
                                       //shared_alienate:
	0x58,                              //pop         eax
	0x83, 0xC0, 0x1A,                  //add         eax,1Ah
	0x50,                              //push        eax
	0xE9, 0xE0, 0x1C, 0xFB, 0xFF,      //jmp         445F90h
	}
};
ASM_PATCH patchAlienateExperience[PATCH_ALIENATE_EXPERIENCE_NUM] = {{0, 0, 0}};
//离间
BYTE codeAlienateExperienceThunk[] = {0xE8, 0x18, 0x0B, 0x00, 0x00};//4942A2h - 493785h - 5
BYTE codeAlienateExperienceOldThunk[] = {0xE8, 0x06, 0x28, 0xFB, 0xFF};
ASM_PATCH patchAlienateExperienceThunk[] = {
	{0x493785, sizeof(codeAlienateExperienceThunk), codeAlienateExperienceThunk},
	{0x493785, sizeof(codeAlienateExperienceOldThunk), codeAlienateExperienceOldThunk}};
//流言
BYTE codeGossipExperienceThunk[] = {0xE8, 0x5A, 0x04, 0x00, 0x00};//4942A2h - 493E43h - 5
BYTE codeGossipExperienceOldThunk[] = {0xE8, 0x48, 0x21, 0xFB, 0xFF};
ASM_PATCH patchGossipExperienceThunk[] = {
	{0x493E43, sizeof(codeGossipExperienceThunk), codeGossipExperienceThunk},
	{0x493E43, sizeof(codeGossipExperienceOldThunk), codeGossipExperienceOldThunk}};

/////////////////////////////////////////////
#define PATCH_CHEAT_EXPERIENCE_NUM 1

DWORD dwAddrCheatExperience[PATCH_CHEAT_EXPERIENCE_NUM] = {0x487AF6};
DWORD dwSizeCheatExperience[PATCH_CHEAT_EXPERIENCE_NUM] = {0x9};
BYTE codeCheatExperience[PATCH_CHEAT_EXPERIENCE_NUM][PATCH_SIZE] = {
	{0x8B, 0x7C, 0x24, 0x2C,           //mov         edi,dword ptr [esp+2Ch]
	0xE9, 0xA7, 0xC7, 0x00, 0x00       //jmp         shared_alienate
	}//1:9
};
ASM_PATCH patchCheatExperience[PATCH_CHEAT_EXPERIENCE_NUM] = {{0, 0, 0}};
//伪报
BYTE codeCheatExperienceThunk[] = {0xE8, 0x33, 0x8B, 0xFF, 0xFF};//487AF6h - 48EFBEh - 5
BYTE codeCheatExperienceOldThunk[] = {0xE8, 0xCD, 0x6F, 0xFB, 0xFF};
ASM_PATCH patchCheatExperienceThunk[] = {
	{0x48EFBE, sizeof(codeCheatExperienceThunk), codeCheatExperienceThunk},
	{0x48EFBE, sizeof(codeCheatExperienceOldThunk), codeCheatExperienceOldThunk}};

/////////////////////////////////////////////
#define PATCH_DISORDER_EXPERIENCE_NUM 1

DWORD dwAddrDisorderExperience[PATCH_DISORDER_EXPERIENCE_NUM] = {0x492826};
DWORD dwSizeDisorderExperience[PATCH_DISORDER_EXPERIENCE_NUM] = {0x9};
BYTE codeDisorderExperience[PATCH_DISORDER_EXPERIENCE_NUM][PATCH_SIZE] = {
	{0x8B, 0x5C, 0x24, 0x30,           //mov         ebx,dword ptr [esp+30h]
	0xE9, 0x77, 0x1A, 0x00, 0x00       //jmp         shared_alienate
	}//1:9
};
ASM_PATCH patchDisorderExperience[PATCH_DISORDER_EXPERIENCE_NUM] = {{0, 0, 0}};
//扰乱
BYTE codeDisorderExperienceThunk[] = {0xE8, 0x43, 0x19, 0x00, 0x00};//492826h - 490EDEh - 5
BYTE codeDisorderExperienceOldThunk[] = {0xE8, 0xAD, 0x50, 0xFB, 0xFF};
ASM_PATCH patchDisorderExperienceThunk[] = {
	{0x490EDE, sizeof(codeDisorderExperienceThunk), codeDisorderExperienceThunk},
	{0x490EDE, sizeof(codeDisorderExperienceOldThunk), codeDisorderExperienceOldThunk}};

/////////////////////////////////////////////
#define PATCH_INSPIRE_EXPERIENCE_NUM 1

DWORD dwAddrInspireExperience[PATCH_INSPIRE_EXPERIENCE_NUM] = {0x48E351};
DWORD dwSizeInspireExperience[PATCH_INSPIRE_EXPERIENCE_NUM] = {0xE};
BYTE codeInspireExperience[PATCH_INSPIRE_EXPERIENCE_NUM][PATCH_SIZE] = {
	{0x8B, 0x6C, 0x24, 0x30,           //mov         ebp,dword ptr [esp+30h]
	0x58,                              //pop         eax
	0x83, 0xC0, 0x1A,                  //add         eax,1Ah
	0x50,                              //push        eax
	0xE9, 0xD1, 0x9C, 0x07, 0x00       //jmp         508030h
	}//1:E
};
ASM_PATCH patchInspireExperience[PATCH_INSPIRE_EXPERIENCE_NUM] = {{0, 0, 0}};
//激励
BYTE codeInspireExperienceThunk[] = {0xE8, 0xD7, 0xF9, 0xFF, 0xFF};//48E351h - 48E975h - 5
BYTE codeInspireExperienceOldThunk[] = {0xE8, 0xB6, 0x96, 0x07, 0x00};
ASM_PATCH patchInspireExperienceThunk[] = {
	{0x48E975, sizeof(codeInspireExperienceThunk), codeInspireExperienceThunk},
	{0x48E975, sizeof(codeInspireExperienceOldThunk), codeInspireExperienceOldThunk}};

/////////////////////////////////////////////
#define PATCH_ROB_MONEY_NUM 4

DWORD dwAddrRobMoney[PATCH_ROB_MONEY_NUM] = {0x461A24, 0x461A42, 0x494802, 0x494485};
DWORD dwSizeRobMoney[PATCH_ROB_MONEY_NUM] = {0xB, 0xC, 0xE, 0xB};
BYTE codeRobMoney[PATCH_ROB_MONEY_NUM][PATCH_SIZE] = {
	{0x8B, 0xCF,                                //mov         ecx, edi  
	0x8B, 0x01,                                 //mov         eax, dword ptr [ecx]
	0xFF, 0x50, 0x3C,                           //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                                 //test        eax, eax
	0xEB, 0x13},                                
	{0x0F, 0x84, 0xBA, 0x2D, 0x03, 0x00,        //je          npc
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00},	    //jmp         [5FF308h]  
	                                            //npc:	
	{0x8B, 0x44, 0x24, 0x04,                    //mov         eax,dword ptr [esp+4]
	0x0F, 0xAF, 0x44, 0x24, 0x08,               //imul        eax,dword ptr [esp+8]
	0xE9, 0x75, 0xFC, 0xFF, 0xFF},
	//1:9+5
	{0x51,                                      //push        ecx
	0x99,                                       //cdq
	0xB9, 0x00, 0xC8, 0x00, 0x00,               //mov         ecx,0C800h
	0xF7, 0xF1,                                 //div         eax,ecx
	0x59,                                       //pop         ecx
	0xC3}                                       //ret
	//2:B
};
ASM_PATCH patchRobMoney[PATCH_ROB_MONEY_NUM] = {{0, 0, 0}};

BYTE codeRobMoneyThunk[] = {0xE8, 0xDC, 0x38, 0xFD, 0xFF, 0x90};//461A24h - 48E143h - 5
BYTE codeRobMoneyOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};
ASM_PATCH patchRobMoneyThunk[] = {
	{0x48E143, sizeof(codeRobMoneyThunk), codeRobMoneyThunk},
	{0x48E143, sizeof(codeRobMoneyOldThunk), codeRobMoneyOldThunk}};

/////////////////////////////////////////////////////
#define PATCH_PERSON_JUDGEMENT_NUM 2

DWORD dwAddrPersonJudgement[PATCH_PERSON_JUDGEMENT_NUM] = {0x508024, 0x508192};
DWORD dwSizePersonJudgement[PATCH_PERSON_JUDGEMENT_NUM] = {0xC, 0xD};
BYTE codePersonJudgement[PATCH_PERSON_JUDGEMENT_NUM][PATCH_SIZE] = {
	               //basic:
	{0x3C, 0x50,   //cmp         al,50h
	0x7F, 0x03,    //jg          advanced
	0x2C, 0x0A,    //sub         al,0Ah
	0xC3,          //ret
	               //advanced:
	0xD0, 0xE0,    //shl         al,1
	0x2C, 0x5A,    //sub         al,5Ah
	0xC3},         //ret
	//1:C
	                             //high_intelligence:
	{0x2C, 0x5F,                 //sub         al,5Fh
	0xB9, 0x03, 0x00, 0x00, 0x00,//mov         ecx,3
	0x99,                        //cdq
	0xF7, 0xF1,                  //div         eax,ecx
	0x04, 0x5F,                  //add         al,5Fh
	0xC3}                        //ret
};
ASM_PATCH patchPersonJudgement[PATCH_PERSON_JUDGEMENT_NUM] = {{0, 0, 0}};

BYTE codePersonJudgementThunk[] = {
	0x8B, 0x54, 0x24, 0x04,                   //mov         edx,dword ptr [esp+4]
	0x8B, 0x8A, 0xF4, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edx+0F4h]
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0x8B, 0x88, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0B8h]
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr [ecx+34h],1
	0x8B, 0x42, 0x58,                         //mov         eax,dword ptr [edx+58h]
	0x75, 0x02,                               //jne         get_judgement
	0x04, 0x08,                               //add         al,08h
	                                          //get_judgement:
	0x3C, 0x5A,                               //cmp         al,5Ah
	0x0F, 0x8E, 0x7E, 0xF3, 0xFF, 0xFF,       //jle         basic//508024h - 508C80h - 26h
	0x3C, 0x5F,                               //cmp         al,5Fh
	0x0F, 0x8F, 0xE4, 0xF4, 0xFF, 0xFF,       //jg          high_intelligence
	0xC3                                      //ret
};
BYTE codePersonJudgementOldThunk[] = {
	0x8B, 0x44, 0x24, 0x04, 0x53, 0x56, 0x8B, 0x70, 0x58, 0x57, 0x8B, 0x3D, 0x30, 0xF3, 0x5F,
	0x00, 0x8D, 0x4E, 0xA6, 0x51, 0x6A, 0x00, 0xFF, 0xD7, 0x83, 0xC6, 0xBA, 0x56, 0x6A, 0x00,
	0x8B, 0xD8, 0xFF, 0xD7, 0x83, 0xC4, 0x10, 0x5F, 0x5E, 0x8D, 0x44, 0x03, 0x3C, 0x5B, 0xC3};
ASM_PATCH patchPersonJudgementThunk[] = {
	{0x508C80, sizeof(codePersonJudgementThunk), codePersonJudgementThunk},
	{0x508C80, sizeof(codePersonJudgementOldThunk), codePersonJudgementOldThunk}};

/////////////////////////////////////////////
#define PATCH_JOURNEY_EXPENSE_NUM 2

DWORD dwAddrJourneyExpense[PATCH_JOURNEY_EXPENSE_NUM] = {0x508724, 0x5087D4};
DWORD dwSizeJourneyExpense[PATCH_JOURNEY_EXPENSE_NUM] = {0xC, 0xC};
BYTE codeJourneyExpense[PATCH_JOURNEY_EXPENSE_NUM][PATCH_SIZE] = {
	{0xB8, 0x90, 0x79, 0x4E, 0x00,            //mov         eax,4E7990h
	0xFF, 0xD0,                               //call        eax
	0xE9, 0xA4, 0x00, 0x00, 0x00},
	//1:7+5
	{0x8B, 0x96, 0x94, 0x07, 0x00, 0x00,      //mov         edx,dword ptr [esi+794h]
	0xF7, 0xEA,                               //imul        edx
	0xC1, 0xE8, 0x0E,                         //shr         eax,0Eh
	0xC3}                                     //ret
	//2:C
};
ASM_PATCH patchJourneyExpense[PATCH_JOURNEY_EXPENSE_NUM] = {{0, 0, 0}};

BYTE codeJourneyExpenseThunk[] = {0xE8, 0xFA, 0xE8, 0x01, 0x00};//508724h - 4E9E25h - 5
BYTE codeJourneyExpenseOldThunk[] = {0xE8, 0x66, 0xDB, 0xFF, 0xFF};
ASM_PATCH patchJourneyExpenseThunk[] = {
	{0x4E9E25, sizeof(codeJourneyExpenseThunk), codeJourneyExpenseThunk},
	{0x4E9E25, sizeof(codeJourneyExpenseOldThunk), codeJourneyExpenseOldThunk}};

/////////////////////////////////////////////
#define PATCH_SUB_JOURNEY_EXPENSE_NUM 2

DWORD dwAddrSubJourneyExpense[PATCH_SUB_JOURNEY_EXPENSE_NUM] = {0x47F304, 0x47F117};
DWORD dwSizeSubJourneyExpense[PATCH_SUB_JOURNEY_EXPENSE_NUM] = {0xC, 0x9};
BYTE codeSubJourneyExpense[PATCH_SUB_JOURNEY_EXPENSE_NUM][PATCH_SIZE] = {
	{0xB8, 0x80, 0xE0, 0x45, 0x00,            //mov         eax,45E080h
	0xFF, 0xD0,                               //call        eax
	0xE9, 0x07, 0xFE, 0xFF, 0xFF},
	//1:7+5
	{0x8B, 0x56, 0x30,                        //mov         edx,dword ptr [esi+30h]
	0xF7, 0xEA,                               //imul        edx
	0xC1, 0xE8, 0x0E,                         //shr         eax,0Eh
	0xC3}                                     //ret
	//2:9
};
ASM_PATCH patchSubJourneyExpense[PATCH_SUB_JOURNEY_EXPENSE_NUM] = {{0, 0, 0}};

BYTE codeSubJourneyExpenseThunk[] = {0xE8, 0x45, 0xE8, 0x01, 0x00};//47F304h - 460ABAh - 5
BYTE codeSubJourneyExpenseOldThunk[] = {0xE8, 0xC1, 0xD5, 0xFF, 0xFF};
ASM_PATCH patchSubJourneyExpenseThunk[] = {
	{0x460ABA, sizeof(codeSubJourneyExpenseThunk), codeSubJourneyExpenseThunk},
	{0x460ABA, sizeof(codeSubJourneyExpenseOldThunk), codeSubJourneyExpenseOldThunk}};

/////////////////////////////////////////////
#define PATCH_ENABLE_DRAFT_NUM 4

DWORD dwAddrEnableDraft[PATCH_ENABLE_DRAFT_NUM] = {0x461E25, 0x46A841, 0x46A855, 0x46A815};
DWORD dwSizeEnableDraft[PATCH_ENABLE_DRAFT_NUM] = {0xB, 0xF, 0xA, 0xB};
BYTE codeEnableDraft[PATCH_ENABLE_DRAFT_NUM][PATCH_SIZE] = {
	{0x8B, 0x86, 0xC0, 0x01, 0x00, 0x00,      //mov         eax,[esi+1C0h]
	0xE9, 0x11, 0x8A, 0x00, 0x00},
	//1:6+5
	{0x3D, 0x70, 0x17, 0x00, 0x00,            //cmp         eax,1770h
	0xB2, 0x5E,                               //mov         dl,5Eh
	0x8B, 0x86, 0x90, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+90h]
	0xEB, 0x05},
	//2:D+2
	{0x7C, 0xC8,                              //jl          end
	0x8B, 0x8E, 0x88, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [esi+88h]
	0xEB, 0xB6},
	//3:8+2
	{0x81, 0xF9, 0x6C, 0x6B, 0x00, 0x00,      //cmp         ecx,6B6Ch
	0x7D, 0x02,                               //jge         end
	0xB2, 0x4B,                               //mov         dl,4Bh
	                                          //end:
	0xC3}                                     //ret
	//4:B
};
ASM_PATCH patchEnableDraft[PATCH_ENABLE_DRAFT_NUM] = {{0, 0, 0}};

BYTE codeEnableDraftThunk[] = {0x33, 0xD2, 0xE8, 0x38, 0x24, 0xFC, 0xFF, 0x3B, 0xC2};//461E25h - 49F9E6h - 7
BYTE codeEnableDraftOldThunk[] = {0xFF, 0x90, 0x84, 0x00, 0x00, 0x00, 0x83, 0xF8, 0x5A};
ASM_PATCH patchEnableDraftThunk[] = {
	{0x49F9E6, sizeof(codeEnableDraftThunk), codeEnableDraftThunk},
	{0x49F9E6, sizeof(codeEnableDraftOldThunk), codeEnableDraftOldThunk}};

/////////////////////////////////////////////
#define PATCH_GARBAGE_PERSON_NUM 3

DWORD dwAddrGarbagePerson[PATCH_GARBAGE_PERSON_NUM] = {0x46EFB2, 0x46EF75, 0x46EF25};
DWORD dwSizeGarbagePerson[PATCH_GARBAGE_PERSON_NUM] = {0xD, 0xA, 0x9};
BYTE codeGarbagePerson[PATCH_GARBAGE_PERSON_NUM][PATCH_SIZE] = {
	                                          //garbage_person:
	{0x83, 0x78, 0x50, 0x3C,                  //cmp         dword ptr [eax+50h],3Ch
	0x7C, 0x01,                               //jl          check_garbage
	                                          //end1:
	0xC3,                                     //ret
	                                          //check_garbage:
	0x83, 0x78, 0x58, 0x41,                   //cmp         dword ptr [eax+58h],41h
	0xEB, 0xB6},
	//1:B+2
	{0x7D, 0x41,                              //jge         end1
	0x83, 0x78, 0x60, 0x3C,                   //cmp         dword ptr [eax+60h],3Ch
	0x7D, 0x3B,                               //jge         end1
	0xEB, 0xA6},
	//2:8+2
	{0x83, 0x78, 0x68, 0x41,                  //cmp         dword ptr [eax+68h],41h
	0x7D, 0x02,                               //jge         end2
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end2:
	0xC3}                                     //ret
	//3:9
};
ASM_PATCH patchGarbagePerson[PATCH_GARBAGE_PERSON_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_NOT_ALIENATE_GARBAGE_NUM 3

DWORD dwAddrNotAlienateGarbage[PATCH_NOT_ALIENATE_GARBAGE_NUM] = {0x46AC92, 0x46ACA4, 0x4687A4};
DWORD dwSizeNotAlienateGarbage[PATCH_NOT_ALIENATE_GARBAGE_NUM] = {0xE, 0xC, 0xB};
BYTE codeNotAlienateGarbage[PATCH_NOT_ALIENATE_GARBAGE_NUM][PATCH_SIZE] = {
	{0x83, 0x7F, 0x34, 0x1D,                  //cmp         dword ptr [edi+34h],1Dh
	0x74, 0x0C,                               //je          alienate
	0x33, 0xC0,                               //xor         eax, eax
	0x83, 0x7F, 0x34, 0x1E,                   //cmp         dword ptr [edi+34h],1Eh
	0xEB, 0x0B},
	//1:C+2
	                                          //alienate:
	{0xE8, 0x09, 0x43, 0x00, 0x00,            //call        garbage_person
	0x85, 0xC0,                               //test        eax,eax
	0xE9, 0xF4, 0xDA, 0xFF, 0xFF},
	//2:7+5
	{0x75, 0x03,                              //jne         normal
	0xC2, 0x14, 0x00,                         //ret         14h
                                              //normal:
	0x68, 0x80, 0xF4, 0x4A, 0x00,             //push        4AF480h
	0xC3}                                     //ret
	//3:B
};
ASM_PATCH patchNotAlienateGarbage[PATCH_NOT_ALIENATE_GARBAGE_NUM] = {{0, 0, 0}};

BYTE codeNotAlienateGarbageThunk[] = {0xE8, 0xF7, 0xA8, 0xFB, 0xFF};//46AC92h - 4B0396h - 5
BYTE codeNotAlienateGarbageOldThunk[] = {0xE8, 0xE5, 0xF0, 0xFF, 0xFF};//call 4AF480h
ASM_PATCH patchNotAlienateGarbageThunk[] = {
	{0x4B0396, sizeof(codeNotAlienateGarbageThunk), codeNotAlienateGarbageThunk},
	{0x4B0396, sizeof(codeNotAlienateGarbageOldThunk), codeNotAlienateGarbageOldThunk}};

/////////////////////////////////////////////
#define PATCH_FULL_PRIZE_NUM 2

DWORD dwAddrFullPrize[PATCH_FULL_PRIZE_NUM] = {0x46F6C1, 0x46F422};
DWORD dwSizeFullPrize[PATCH_FULL_PRIZE_NUM] = {0xF, 0xE};
BYTE codeFullPrize[PATCH_FULL_PRIZE_NUM][PATCH_SIZE] = {
	{0x83, 0x7E, 0x34, 0x0F,                  //cmp         dword ptr[esi+34h],0Fh
	0x0F, 0x85, 0x45, 0xF7, 0x00, 0x00,       //jne         47EE10h
	0xE9, 0x52, 0xFD, 0xFF, 0xFF},
	//1:A+5
	{0x51,                                    //push        ecx
	0xB8, 0xE1, 0xAF, 0x49, 0x00,             //mov         eax,siege_random
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x24, 0x03,                               //and         al,3
	0xC2, 0x0C, 0x00}                         //ret         0Ch
	//2:E
};
ASM_PATCH patchFullPrize[PATCH_FULL_PRIZE_NUM] = {{0, 0, 0}};

BYTE codeFullPrizeThunk[] = {0xE8, 0xE9, 0x02, 0xFC, 0xFF};//46F6C1h - 4AF3D3h - 5
BYTE codeFullPrizeOldThunk[] = {0xE8, 0x38, 0xFA, 0xFC, 0xFF};
ASM_PATCH patchFullPrizeThunk[] = {
	{0x4AF3D3, sizeof(codeFullPrizeThunk), codeFullPrizeThunk},
	{0x4AF3D3, sizeof(codeFullPrizeOldThunk), codeFullPrizeOldThunk}};

/////////////////////////////////////////////
#define PATCH_DISPATCH_TROOP_NUM 2

DWORD dwAddrDispatchTroop[PATCH_DISPATCH_TROOP_NUM] = {0x46D255, 0x46D212};
DWORD dwSizeDispatchTroop[PATCH_DISPATCH_TROOP_NUM] = {0xB, 0xE};
BYTE codeDispatchTroop[PATCH_DISPATCH_TROOP_NUM][PATCH_SIZE] = {
	{0x81, 0x79, 0x6C, 0xE0, 0x12, 0x50, 0x01,//cmp         dword ptr [ecx+6Ch],15012E0h
	0x75, 0xBC,                               //jne         end
	0xEB, 0xB2},
	//1:9+2
	{0x80, 0x49, 0x22, 0x20,                  //or          byte ptr [ecx+22h],20h
	0xC6, 0x42, 0x0C, 0x33,                   //mov         byte ptr [edx+0Ch],33h
	                                          //end:
	0x68, 0x40, 0x1E, 0x46, 0x00,             //push        461E40h
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchDispatchTroop[PATCH_DISPATCH_TROOP_NUM] = {{0, 0, 0}};

BYTE codeDispatchTroopThunk[] = {0xE8, 0x98, 0x13, 0xFE, 0xFF};//46D255h - 48BEB8h - 5
BYTE codeDispatchTroopOldThunk[] = {0xE8, 0x83, 0x5F, 0xFD, 0xFF};
ASM_PATCH patchDispatchTroopThunk[] = {
	{0x48BEB8, sizeof(codeDispatchTroopThunk), codeDispatchTroopThunk},
	{0x48BEB8, sizeof(codeDispatchTroopOldThunk), codeDispatchTroopOldThunk}};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                   multi_search
/////////////////////////////////////////////////////////////////////////////////////////////////
#define PATCH_SEARCH_SELECT_NUM 2

DWORD dwAddrSearchSelect[PATCH_SEARCH_SELECT_NUM] = {0x4FDE82, 0x4EC4D6};
DWORD dwSizeSearchSelect[PATCH_SEARCH_SELECT_NUM] = {0xE, 0xA};
BYTE codeSearchSelect[PATCH_SEARCH_SELECT_NUM][PATCH_SIZE] = {
	{0x55,                                    //push        ebp
	0x8B, 0xEC,                               //mov         ebp,esp
	0x81, 0xEC, 0x00, 0x01, 0x00, 0x00,       //sub         esp, code_length
	0xE9, 0x46, 0xE6, 0xFE, 0xFF},
	//1:9+5
	{0x54,                                    //push        esp
	0x6A, 0x0A,                               //push        MSG_SEARCH_SELECT
	0xE8, 0x46, 0x33, 0xF5, 0xFF,             //call        SEND_MSG_ADDRESS
	0xFF, 0xE4}                               //jmp         esp
	//2:A
};
ASM_PATCH patchSearchSelect[PATCH_SEARCH_SELECT_NUM] = {{0, 0, 0}};

BYTE codeSearchSelectThunk[] = {0xE8, 0x69, 0x1A, 0x01, 0x00};//4FDE82h - 4EC414h - 5
BYTE codeSearchSelectOldThunk[] = {0xE8, 0x67, 0x3F, 0x08, 0x00};
ASM_PATCH patchSearchSelectThunk[] = {
	{0x4EC414, sizeof(codeSearchSelectThunk), codeSearchSelectThunk},
	{0x4EC414, sizeof(codeSearchSelectOldThunk), codeSearchSelectOldThunk}};

/////////////////////////////////////////////
BYTE codeSearchSelectOnStack[] = {//code_length = 5Bh
	0x57,                                     //push        edi
	0xC7, 0x05, 0x10, 0xC6, 0x61, 0x00, 0xB1, 0xB4, 0xAF, 0xC1,//mov [61C610h], C1AFB4B1h
	0xBF, 0x00, 0x05, 0x0A, 0x00,             //mov         edi,multi_search_person_list
	0x6A, 0x00,                               //push        0
	0x6A, 0x01,                               //push        1
	0x68, 0x28, 0xC6, 0x66, 0x00,             //push        66C628h
	0x68, 0x65, 0x1F, 0x00, 0x00,             //push        1F65h
	0xFF, 0x73, 0x0C,                         //push        dword ptr [ebx+0Ch]
	0x53,                                     //push        ebx
	0x57,                                     //push        edi
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0xD8, 0x23, 0x0A, 0x00,             //mov         eax,sort_multi_select_person
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x1C,                         //add         esp,1Ch
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x11,                               //je          end
	0x8B, 0x47, 0x04,                         //mov         eax,dword ptr [edi+4]
	0x8B, 0x50, 0x08,                         //mov         edx,dword ptr [eax+8]
	0x89, 0x96, 0xD4, 0x0E, 0x00, 0x00,       //mov         dword ptr [esi+0ED4h],edx
	0xA3, 0x77, 0xF1, 0x43, 0x00,             //mov         [search_person_pointer],eax
	                                          //end:
	0xC7, 0x05, 0x10, 0xC6, 0x61, 0x00, 0xB0, 0xD3, 0xB7, 0x7E,//mov [61C610h], 7EB7D3B0h
	0x5F,                                     //pop         edi
	0x8B, 0xE5,                               //mov         esp,ebp
	0x5D,                                     //pop         ebp
	0xC3                                      //ret
};

/////////////////////////////////////////////
#define PATCH_SEARCH_STOP_NUM 2

DWORD dwAddrSearchStop[PATCH_SEARCH_STOP_NUM] = {0x4E7C73, 0x4E7DA3};
DWORD dwSizeSearchStop[PATCH_SEARCH_STOP_NUM] = {0xD, 0xD};
BYTE codeSearchStop[PATCH_SEARCH_STOP_NUM][PATCH_SIZE] = {
	{0xB8, 0x40, 0x05, 0x0A, 0x00,       //mov         eax,search_person_clear
	0xFF, 0xD0,                          //call        eax
	0x68, 0xA0, 0xB4, 0x4C, 0x00,        //push        4CB4A0h
	0xC3},                               //ret
	//1:D
	                                     //normal_perform:
	{0xB8, 0x40, 0x05, 0x0A, 0x00,       //mov         eax,search_person_clear
	0xFF, 0xD0,                          //call        eax
	0x68, 0x00, 0x5A, 0x48, 0x00,        //push        485A00h
	0xC3}                                //ret
	//2:D
};
ASM_PATCH patchSearchStop[PATCH_SEARCH_STOP_NUM] = {{0, 0, 0}};

BYTE codeSearchStopThunk[] = {0xE9, 0xFE, 0x19, 0x00, 0x00};//4E7C73h - 4E6270h - 5
BYTE codeSearchStopOldThunk[] = {0xE9, 0x2B, 0x52, 0xFE, 0xFF};
ASM_PATCH patchSearchStopThunk[] = {
	{0x4E6270, sizeof(codeSearchStopThunk), codeSearchStopThunk},
	{0x4E6270, sizeof(codeSearchStopOldThunk), codeSearchStopOldThunk}};

/////////////////////////////////////////////
#define PATCH_SEARCH_PERFORM_NUM 4

DWORD dwAddrSearchPerform[PATCH_SEARCH_PERFORM_NUM] = {0x458094, 0x458D61, 0x458B03, 0x458796};
DWORD dwSizeSearchPerform[PATCH_SEARCH_PERFORM_NUM] = {0xC, 0xE, 0xD, 0xA};
BYTE codeSearchPerform[PATCH_SEARCH_PERFORM_NUM][PATCH_SIZE] = {
	{0xA1, 0x77, 0xF1, 0x43, 0x00,            //mov         eax,[search_person_pointer]
	0x85, 0xC0,                               //test        eax,eax
	0xE9, 0xC1, 0x0C, 0x00, 0x00},
	//1:7+5
	{0x75, 0x06,                              //jnz         perform_caller
	0x68, 0xA3, 0x7D, 0x4E, 0x00,             //push        normal_perform
	0xC3,                                     //ret
	                                          //perform_caller:
	0x55,                                     //push        ebp
	0xE9, 0x94, 0xFD, 0xFF, 0xFF},
	//2:9+5
	{0x8B, 0xEC,                              //mov         ebp,esp
	0x81, 0xEC, 0x00, 0x01, 0x00, 0x00,       //sub         esp,code_length
	0xE9, 0x86, 0xFC, 0xFF, 0xFF},
	//3:8+5
	{0x54,                                    //push        esp
	0x6A, 0x0B,                               //push        MSG_SEARCH_PERFORM
	0xE8, 0x86, 0x70, 0xFE, 0xFF,             //call        SEND_MSG_ADDRESS
	0xFF, 0xE4}                               //jmp         esp
	//4:A
};
ASM_PATCH patchSearchPerform[PATCH_SEARCH_PERFORM_NUM] = {{0, 0, 0}};

BYTE codeSearchPerformThunk[] = {0xE8, 0xD9, 0x22, 0xFD, 0xFF};//458094h - 485DB6h - 5
BYTE codeSearchPerformOldThunk[] = {0xE8, 0x45, 0xFC, 0xFF, 0xFF};//call 485A00h()
ASM_PATCH patchSearchPerformThunk[] = {
	{0x485DB6, sizeof(codeSearchPerformThunk), codeSearchPerformThunk},
	{0x485DB6, sizeof(codeSearchPerformOldThunk), codeSearchPerformOldThunk}};

BYTE codeInvitePerformThunk[] = {0xE8, 0x32, 0x29, 0xFC, 0xFF};//458094h - 49575Dh - 5
BYTE codeInvitePerformOldThunk[] = {0xE8, 0x9E, 0x02, 0xFF, 0xFF};
ASM_PATCH patchInvitePerformThunk[] = {
	{0x49575D, sizeof(codeInvitePerformThunk), codeInvitePerformThunk},
	{0x49575D, sizeof(codeInvitePerformOldThunk), codeInvitePerformOldThunk}};

/////////////////////////////////////////////
BYTE codeSearchPerformOnStack[] = {//code_length = 72h
	0x55,                                     //push        ebp
	0x57,                                     //push        edi
	0xBD, 0xAC, 0x55, 0x54, 0x01,             //mov         ebp,15455ACh
	0x8B, 0x3D, 0x77, 0xF1, 0x43, 0x00,       //mov         edi,[search_person_pointer]
	                                          //start:
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x57, 0x08,                         //mov         edx,dword ptr [edi+8]
	0x52,                                     //push        edx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0x3D, 0x77, 0xF1, 0x43, 0x00,       //cmp         edi,dword ptr[search_person_pointer]
	0x74, 0x0C,								  //je          perform_search
	0x8B, 0x4F, 0x08,						  //mov         ecx,dword ptr [edi+8]
	0x8B, 0x01,								  //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x34,						  //call        dword ptr [eax+34h]
	0x80, 0x60, 0x34, 0xFE,					  //and         byte ptr [eax+34h],0FEh
											  //perform_search:
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x5A, 0x48, 0x00,             //mov         eax,485A00h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0x3D, 0x77, 0xF1, 0x43, 0x00,       //cmp         edi,dword ptr[search_person_pointer]
	0x74, 0x0C,								  //je          next_person
	0x8B, 0x4F, 0x08,						  //mov         ecx,dword ptr [edi+8]
	0x8B, 0x01,								  //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x34,						  //call        dword ptr [eax+34h]
	0x80, 0x48, 0x34, 0x01,					  //or          byte ptr [eax+34h],1
											  //next_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xB3,                               //jnz         start

	0x89, 0x3D, 0x77, 0xF1, 0x43, 0x00,       //mov         [search_person_pointer],edi
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x5F,                                     //pop         edi
	0x5D,                                     //pop         ebp
	0x8B, 0xE5,                               //mov         esp,ebp
	0x5D,                                     //pop         ebp
	0xC3                                      //ret
};

//智力兵法映射成武力兵法的威力
DWORD dwMapKillerPowerAddr = 0x45D8E7;//map_killer_power
BYTE btMapKillerPower[8] = {7,12,10,15,5,5,12,15};//混乱7,陷阱12,攻心10,幻术15,辱骂5,鼓舞5,治疗12,妖术15


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                           key process
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PATCH_MESSAGE_ENTRY_NUM 0x12

DWORD dwAddrMessageEntry[PATCH_MESSAGE_ENTRY_NUM] =
{0x5CA801, 0x5CA7E4, 0x5CA7C5, 0x5CACF6, 0x5CAD26, 0x5CCE03, 0x5C96C3, 0x5C9953,
0x5C9A63, 0x5CAAE6, 0x5CAE72, 0x5CBC16, 0x5CD392, 0x5C92E6, 0x5C92F6, 0x5CD251,
0x5BE094, 0x5BEF14};
DWORD dwSizeMessageEntry[PATCH_MESSAGE_ENTRY_NUM] = 
{0xF, 0xC, 0x7, 0x8, 0x7, 0xD, 0xD, 0xD,     0xD, 7, 0xE, 7, 0xE, 9, 8, 0xF,
0xC, 0xC};
BYTE codeMessageEntry[PATCH_MESSAGE_ENTRY_NUM][PATCH_SIZE] = {
	{0x81, 0x7A, 0x04, 0x01, 0x01, 0x00, 0x00,//cmp         dword ptr[edx+4],101h
	0x74, 0xDA,                               //je          key_up
	0x68, 0x94, 0xE0, 0x5B, 0x00,             //push        check_timer
	0xC3},                                    //ret
	//1:F                                     //key_up:
	{0x8B, 0x42, 0x08,                        //mov         eax,dword ptr [edx+8]
	0x3C, 0x54,                               //cmp         al,54h
	0x75, 0xDA,                               //jne         next
	0xE9, 0x14, 0x15, 0xF2, 0xFF},            //jmp         key_search
	//2:C
	{0x3C, 0x20,                              //cmp         al,20h
	0xE9, 0x2A, 0x05, 0x00, 0x00},
	//3:2+5
	{0x75, 0x2E,                              //jne         next
	0x68, 0x06, 0x86, 0x5B, 0x00,             //push        key_go
	0xC3},                                    //ret
	//4:8
	{0x3C, 0xC0,                              //cmp         al,C0h
	0xE9, 0xD6, 0x20, 0x00, 0x00},
	//5:2+5
	{0x0F, 0x84, 0xAD, 0x9B, 0xF1, 0xFF,      //je          key_big
	0x3C, 0x31,                               //cmp         al,31h
	0xE9, 0xB3, 0xC8, 0xFF, 0xFF},
	//6:8+5
	{0x0F, 0x84, 0x7D, 0x3D, 0xFB, 0xFF,      //je          key_small
	0x3C, 0x51,                               //cmp         al,51h
	0xE9, 0x83, 0x02, 0x00, 0x00},
	//7:8+5
	{0x0F, 0x84, 0x5D, 0xB5, 0xEE, 0xFF,      //je          key_award
	0x3C, 0x32,                               //cmp         al,32h
	0xE9, 0x03, 0x01, 0x00, 0x00},
	//8:8+5
	{0x0F, 0x85, 0x7D, 0x10, 0x00, 0x00,      //jne         next
	0xB0, 0x14,                               //mov         al,14h
	0xE9, 0x61, 0xE3, 0xFE, 0xFF},            //jmp         key_info
	//9:8+5
	{0x3C, 0x70,                              //cmp         al,70h
	0xE9, 0x85, 0x03, 0x00, 0x00},
	//A:6
	{0x0F, 0x85, 0x9E, 0x0D, 0x00, 0x00,      //jne         next
	0xB0, 0x0F,                               //mov         al,0Fh
	0x68, 0xD1, 0x7D, 0x5B, 0x00,             //push        key_info
	0xC3},                                    //ret
	//B:E
	{0x3C, 0x71,                              //cmp         al,71h
	0xE9, 0x75, 0x17, 0x00, 0x00},
	//C:7
	{0x0F, 0x85, 0x4E, 0xBF, 0xFF, 0xFF,      //jne         next
	0xB0, 0x0E,                               //mov         al,0Eh
	0x68, 0xD1, 0x7D, 0x5B, 0x00,             //push        key_info
	0xC3},                                    //ret
	//D:E
	{0x3C, 0x72,                              //cmp         al,72h
	0x74, 0x0C,                               //je          key_F3
	0xE9, 0x62, 0x3F, 0x00, 0x00},
	//E:9
	                                          //key_F3:
	{0xB0, 0x13,                              //mov         al,13h
	0x68, 0xD1, 0x7D, 0x5B, 0x00,             //push        key_info
	0xC3},                                    //ret
	//F:8
	{0x3C, 0x73,                              //cmp         al,73h
	0x0F, 0x85, 0xC1, 0x1C, 0xFF, 0xFF,       //jne			TranslateMessageThunk
	0xB0, 0x0D,                               //mov         al,0Dh
	0xE9, 0x71, 0xAB, 0xFE, 0xFF},            //jmp         key_info
	//10:F

	                                          //check_timer:
	{0x81, 0x7A, 0x04, 0x13, 0x01, 0x00, 0x00,//cmp         dword ptr[edx+4],113h
	0xE9, 0x74, 0x0E, 0x00, 0x00},
	//11:7+5
	{0x0F, 0x84, 0xF9, 0xAA, 0xFF, 0xFF,      //je          timer_process
	                                          //TranslateMessageThunk(5BEF1Ah):
	0xFF, 0x25, 0x70, 0xF4, 0x5F, 0x00}       //jmp         [5FF470h]=User32::TranslateMessage()
	//12:C
};
ASM_PATCH patchMessageEntry[PATCH_MESSAGE_ENTRY_NUM] = {{0, 0, 0}};

BYTE codeMessageEntryThunk[] = {0xE8, 0xEE, 0xF9, 0xFF, 0xFF};//5CA801h - 5CAE0Eh - 5
BYTE codeMessageEntryOldThunk[] = {0xE8, 0xDD, 0xFE, 0xFF, 0xFF};
ASM_PATCH patchMessageEntryThunk[] = {
	{0x5CAE0E, sizeof(codeMessageEntryThunk), codeMessageEntryThunk},
	{0x5CAE0E, sizeof(codeMessageEntryOldThunk), codeMessageEntryOldThunk}};

/////////////////////////////////////////////
#define PATCH_KEY_SEARCH_NUM 1

DWORD dwAddrKeySearch[PATCH_KEY_SEARCH_NUM] = {0x4EBD04};
DWORD dwSizeKeySearch[PATCH_KEY_SEARCH_NUM] = {0xC};
BYTE codeKeySearch[PATCH_KEY_SEARCH_NUM][PATCH_SIZE] = {
                                              //key_search:
	{0x68, 0x1A, 0xEF, 0x5B, 0x00,            //push        TranslateMessageThunk
	0xC3}                                     //ret
};
ASM_PATCH patchKeySearch[PATCH_KEY_SEARCH_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_KEY_GO_NUM 3

DWORD dwAddrKeyGo[PATCH_KEY_GO_NUM] = {0x5B8606, 0x5B8666, 0x5B8052};
DWORD dwSizeKeyGo[PATCH_KEY_GO_NUM] = {0x9, 0xA, 0xD};
BYTE codeKeyGo[PATCH_KEY_GO_NUM][PATCH_SIZE] = {
                                              //key_go:
	{0xC6, 0x05, 0x27, 0xF2, 0x43, 0x00, 0x01,//mov         byte ptr [go_fast_flag],1
	0xEB, 0x57},
	//1:7+2
	{0x68, 0xDD, 0x03, 0xA0, 0x02,            //push        2A003DDh
	0xE9, 0xE2, 0xF9, 0xFF, 0xFF},
	//2:5+5
	{0xB8, 0x81, 0xB6, 0x5B, 0x00,            //mov         eax,mouse_click
	0xFF, 0xD0,                               //call        eax
	0x68, 0x1A, 0xEF, 0x5B, 0x00,             //push        TranslateMessageThunk
	0xC3                                      //ret
	}//3:D
};
ASM_PATCH patchKeyGo[PATCH_KEY_GO_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_KEY_AWARD_NUM 3

DWORD dwAddrKeyAward[PATCH_KEY_AWARD_NUM] = {0x4B4EB6, 0x4B50A4, 0x4B54E3};
DWORD dwSizeKeyAward[PATCH_KEY_AWARD_NUM] = {0xA, 0xC, 0xD};
BYTE codeKeyAward[PATCH_KEY_AWARD_NUM][PATCH_SIZE] = {
                                              //key_award:
	{0x68, 0x00, 0x02, 0x80, 0x01,            //push        01800200h
	0xE9, 0xE4, 0x01, 0x00, 0x00},
	//1:5+5
	{0xC6, 0x05, 0xC4, 0xF7, 0x43, 0x00, 0x01,//mov         byte ptr[key_award_flag],1
	0xE9, 0x33, 0x04, 0x00, 0x00},
	//2:7+5
	{0xB8, 0x81, 0xB6, 0x5B, 0x00,            //mov         eax,mouse_click
	0xFF, 0xD0,                               //call        eax
	0x68, 0x1A, 0xEF, 0x5B, 0x00,             //push        TranslateMessageThunk
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchKeyAward[PATCH_KEY_AWARD_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_MOUSE_CLICK_NUM 4

DWORD dwAddrMouseClick[PATCH_MOUSE_CLICK_NUM] = {0x5BB681, 0x5BBBC2, 0x5BBC46, 0x5BBCA6};
DWORD dwSizeMouseClick[PATCH_MOUSE_CLICK_NUM] = {0xF, 0xB, 0xA, 0xA};
BYTE codeMouseClick[PATCH_MOUSE_CLICK_NUM][PATCH_SIZE] = {
	                                          //mouse_click:
	{0x58,                                    //pop         eax
	0x59,                                     //pop         ecx
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0xA1, 0x60, 0xF4, 0x5F, 0x00,             //mov         eax,[5FF460h]=User32::PostMessage()
	0x52,                                     //push        edx
	0xE9, 0x32, 0x05, 0x00, 0x00},
	//1:A+5
	{0x50,                                    //push        eax
	0x51,                                     //push        ecx
	0x6A, 0x01,                               //push        1
	0x68, 0x01, 0x02, 0x00, 0x00,             //push        201h
	0xEB, 0x79},
	//2:8+2
	{0xFF, 0x32,                              //push        dword ptr [edx]
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	0x5A,                                     //pop         edx
	0x6A, 0x01,                               //push        1
	0xEB, 0x56},
	//3:8+2
	{0x68, 0x02, 0x02, 0x00, 0x00,            //push        202h
	0xFF, 0x32,                               //push        dword ptr [edx]
	0xFF, 0xD0,                               //call        eax
	0xC3}                                     //ret
	//4:9
};
ASM_PATCH patchMouseClick[PATCH_MOUSE_CLICK_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_GO_FAST_NUM 7

DWORD dwAddrGoFast[PATCH_GO_FAST_NUM] = {0x508942, 0x508962, 0x508982, 0x5089C2, 0x5089E2, 0x508D24, 0x5089A2};
DWORD dwSizeGoFast[PATCH_GO_FAST_NUM] = {0xE, 0xD, 0xD, 0xD, 0xE, 0xC, 0xE};
BYTE codeGoFast[PATCH_GO_FAST_NUM][PATCH_SIZE] = {
	{0x8B, 0x84, 0x24, 0x7C, 0x09, 0x00, 0x00,//mov         eax,[esp+97Ch]
	0x3D, 0x50, 0x04, 0x51, 0x00,             //cmp         eax,510450h
	0xEB, 0x12},
	//1:C+2
	{0x75, 0x5E,                              //jne         check_info_flag
	0xA1, 0x27, 0xF2, 0x43, 0x00,             //mov         eax,[go_fast_flag]
	0xA8, 0x01,                               //test        al,1
	0x74, 0x3D,                               //jz          end
	0xEB, 0x13},
	//2:B+2
	{0xB0, 0x06,                              //mov         al,6
	0x89, 0x41, 0x14,                         //mov         [ecx+14h],eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x27, 0xF2, 0x43, 0x00,             //mov         [go_fast_flag],eax
	0xC3},                                    //ret
	//3:D
	                                          //check_info_flag:
	{0x8B, 0x44, 0x24, 0x5C,	              //mov         eax,[esp+5Ch]
	0x3D, 0x7E, 0x05, 0x51, 0x00,             //cmp         eax,51057Eh
	0x75, 0xDD,                               //jne         end
	0xEB, 0x13},
	//4:B+2
	{0xA1, 0xD6, 0xFF, 0x43, 0x00,            //mov         eax,[info_fast_flag]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xBF,                               //jz          end
	0xE9, 0x34, 0x03, 0x00, 0x00},
	//5:9+5
	{0x66, 0x0D, 0x00, 0x2B,                  //or          ax,2B00h
	0x89, 0x41, 0x14,                         //mov         [ecx+14h],eax
	0xE9, 0x72, 0xFC, 0xFF, 0xFF},
	//6:7+5
	{0x33, 0xC0,                              //xor         eax,eax
	0xA3, 0xD6, 0xFF, 0x43, 0x00,             //mov         [info_fast_flag],eax
	0xC3,                                     //ret
	                                          //end:
	0x68, 0x00, 0x15, 0x0A, 0x00,             //push        do_award
	0xC3}                                     //ret
	//7:D
};
ASM_PATCH patchGoFast[PATCH_GO_FAST_NUM] = {{0, 0, 0}};

BYTE codeGoFastThunk[] = {0xE8, 0x78, 0x21, 0xF5, 0xFF};//508942h - 5B67C5h - 5
BYTE codeGoFastOldThunk[] = {0xE8, 0xD6, 0x6B, 0x01, 0x00};
ASM_PATCH patchGoFastThunk[] = {
	{0x5B67C5, sizeof(codeGoFastThunk), codeGoFastThunk},
	{0x5B67C5, sizeof(codeGoFastOldThunk), codeGoFastOldThunk}};

/////////////////////////////////////////////
#define PATCH_GO_NODISPLAY_NUM 4

DWORD dwAddrGoNodisplay[PATCH_GO_NODISPLAY_NUM] = {0x4934F3, 0x493513, 0x57D232, 0x57D2A2};
DWORD dwSizeGoNodisplay[PATCH_GO_NODISPLAY_NUM] = {0xD, 0xC, 0xD, 0xE};
BYTE codeGoNodisplay[PATCH_GO_NODISPLAY_NUM][PATCH_SIZE] = {
	{0x81, 0xBC, 0x24, 0x50, 0x09, 0x00, 0x00, 0x50, 0x04, 0x51, 0x00,//cmp dword ptr[esp+950h],510450h
	0xEB, 0x13},
	//1:B+2
	{0x0F, 0x85, 0x91, 0x9D, 0x0E, 0x00,      //jne         end
	0x68, 0x32, 0xD2, 0x57, 0x00,
	0xC3},
	//2:6+6
	{0xF6, 0x05, 0x27, 0xF2, 0x43, 0x00, 0x01,//test        byte ptr[go_fast_flag],1
	0x74, 0x6F,                               //jz          end
	0xB0, 0x83,                               //mov         al,83h
	0xEB, 0x63},
	//3:D	
	{0xA3, 0x2B, 0xF2, 0x43, 0x00,            //mov         [go_fast_counter],eax
	0xC2, 0x0C, 0x00,                         //ret         0Ch
	                                          //end:
	0x68, 0x30, 0x83, 0x5B, 0x00,             //push        5B8330h
	0xC3}                                     //ret
	//4:E
};
ASM_PATCH patchGoNodisplay[PATCH_GO_NODISPLAY_NUM] = {{0, 0, 0}};

BYTE codeGoNodisplayThunk[] = {0xE8, 0x9D, 0xAF, 0xED, 0xFF};//4934F3h - 5B8551h - 5
BYTE codeGoNodisplayOldThunk[] = {0xE8, 0xDA, 0xFD, 0xFF, 0xFF};//call 5B8330
ASM_PATCH patchGoNodisplayThunk[] = {
	{0x5B8551, sizeof(codeGoNodisplayThunk), codeGoNodisplayThunk},
	{0x5B8551, sizeof(codeGoNodisplayOldThunk), codeGoNodisplayOldThunk}};

/////////////////////////////////////////////
#define PATCH_KEY_BIG_NUM 2

DWORD dwAddrKeyBig[PATCH_KEY_BIG_NUM] = {0x4E69B6, 0x4E6752};
DWORD dwSizeKeyBig[PATCH_KEY_BIG_NUM] = {0xA, 0xD};
BYTE codeKeyBig[PATCH_KEY_BIG_NUM][PATCH_SIZE] = {
                                              //key_big:
	{0x68, 0xA0, 0x03, 0x9C, 0x02,            //push        29C03A0h
	0xE9, 0x92, 0xFD, 0xFF, 0xFF},
	//1:5+5
	{0xB8, 0x81, 0xB6, 0x5B, 0x00,            //mov         eax,mouse_click
	0xFF, 0xD0,                               //call        eax
	0x68, 0x1A, 0xEF, 0x5B, 0x00,             //push        TranslateMessageThunk
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchKeyBig[PATCH_KEY_BIG_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_KEY_SMALL_NUM 2

DWORD dwAddrKeySmall[PATCH_KEY_SMALL_NUM] = {0x57D446, 0x5B6743};
DWORD dwSizeKeySmall[PATCH_KEY_SMALL_NUM] = {0xA, 0xD};
BYTE codeKeySmall[PATCH_KEY_SMALL_NUM][PATCH_SIZE] = {
                                              //key_small:
	{0x68, 0xE8, 0x03, 0x70, 0x02,            //push        27003E8h
	0xE9, 0xF3, 0x92, 0x03, 0x00},
	//1:5+5
	{0xB8, 0x81, 0xB6, 0x5B, 0x00,            //mov         eax,mouse_click
	0xFF, 0xD0,                               //call        eax
	0x68, 0x1A, 0xEF, 0x5B, 0x00,             //push        TranslateMessageThunk
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchKeySmall[PATCH_KEY_SMALL_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_KEY_INFO_NUM 2

DWORD dwAddrKeyInfo[PATCH_KEY_INFO_NUM] = {0x5B7DD1, 0x5B7502};
DWORD dwSizeKeyInfo[PATCH_KEY_INFO_NUM] = {0xF, 0xD};
BYTE codeKeyInfo[PATCH_KEY_INFO_NUM][PATCH_SIZE] = {
                                              //key_info:
	{0xA2, 0xD6, 0xFF, 0x43, 0x00,            //mov         byte ptr[info_fast_flag],al
	0xB8, 0x81, 0xB6, 0x5B, 0x00,             //mov         eax,mouse_click
	0xE9, 0x22, 0xF7, 0xFF, 0xFF},
	//1:A+5
	{0x68, 0x80, 0x03, 0x20, 0x00,            //push        200380h
	0xFF, 0xD0,                               //call        eax
	0x68, 0x1A, 0xEF, 0x5B, 0x00,             //push        TranslateMessageThunk
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchKeyInfo[PATCH_KEY_INFO_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_TIMER_PROCESS_NUM 4

DWORD dwAddrTimerProcess[PATCH_TIMER_PROCESS_NUM] = {0x5B9A13, 0x5B9A26, 0x5B9A83, 0x5B8785};
DWORD dwSizeTimerProcess[PATCH_TIMER_PROCESS_NUM] = {0xC, 0xA, 0xA, 0xA};
BYTE codeTimerProcess[PATCH_TIMER_PROCESS_NUM][PATCH_SIZE] = {
	                                          //timer_process:
	{0xB8, 0x34, 0xE3, 0x45, 0x00,            //mov         eax,flag_counter_process
	0xB9, 0x27, 0xF2, 0x43, 0x00,             //mov         ecx,go_fast_flag
	0xEB, 0x07},
	//1:A+2
	{0x50,                                    //push        eax
	0xFF, 0xD0,                               //call        eax
	0xB9, 0xD6, 0xFF, 0x43, 0x00,             //mov         ecx,info_fast_flag
	0xEB, 0x53},
	//2:8+2
	{0x58,                                    //pop         eax
	0x50,                                     //push        eax
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	0xE9, 0xF8, 0xEC, 0xFF, 0xFF},
	//3:5+5
	{0xB9, 0xC4, 0xF7, 0x43, 0x00,            //mov         ecx,key_award_flag
	0xFF, 0xD0,                               //call        eax
	0xC2, 0x04, 0x00}                         //ret         4
	//4:A
};
ASM_PATCH patchTimerProcess[PATCH_TIMER_PROCESS_NUM] = {{0, 0, 0}};

/////////////////////////////////////////////
#define PATCH_FLAG_COUNTER_PROCESS_NUM 2

DWORD dwAddrFlagCounterProcess[PATCH_FLAG_COUNTER_PROCESS_NUM] = {0x45E334, 0x45E344};
DWORD dwSizeFlagCounterProcess[PATCH_FLAG_COUNTER_PROCESS_NUM] = {0xC, 0xC};
BYTE codeFlagCounterProcess[PATCH_FLAG_COUNTER_PROCESS_NUM][PATCH_SIZE] = {
	                                          //flag_counter_process:
	{0x8B, 0x01,                              //mov         eax,dword ptr [ecx]
	0xA8, 0xFF,                               //test        al,0FFh
	0x74, 0x12,                               //je          end
	0x8B, 0x41, 0x04,                         //mov         eax,dword ptr [ecx+4]
	0x40,                                     //inc         eax
	0xEB, 0x04},
	//1:A+2
	{0x3C, 0x03,                              //cmp         al,3
	0x7C, 0x04,                               //jl          end
	0x33, 0xC0,                               //xor         eax,eax
	0x89, 0x01,                               //mov         dword ptr [ecx],eax
	                                          //end:
	0x89, 0x41, 0x04,                         //mov         dword ptr [ecx+4],eax
	0xC3}                                     //ret
	//2:C
};
ASM_PATCH patchFlagCounterProcess[PATCH_FLAG_COUNTER_PROCESS_NUM] = {{0, 0, 0}};

//read scene index
DWORD dwAddrReadSceneIndex = 0x43E916;
BYTE codeReadSceneIndex[] = {
	0x85, 0xC9,                               //test        ecx, ecx
	0x74, 0x04,                               //jz          end
	0x33, 0xC9,                               //xor         ecx, ecx
	0xB0, 0x13,                               //mov         al,13h
	                                          //end:
	0xC3                                      //ret
};

BYTE codeReadSceneIndexThunk[] = {0xE8, 0x24, 0x75, 0xFE, 0xFF, 0x90};//dwAddrReadSceneIndex - 4573EDh - 5
BYTE codeReadSceneIndexOldThunk[] = {0x81, 0xE1, 0xB0, 0x12, 0x1C, 0x02};//and ecx,21C12B0h
ASM_PATCH patchReadSceneIndexThunk[] = {
	{0x4573ED, sizeof(codeReadSceneIndexThunk), codeReadSceneIndexThunk},
	{0x4573ED, sizeof(codeReadSceneIndexOldThunk), codeReadSceneIndexOldThunk}};

//test dark flag
DWORD dwAddrTestDarkFlag = 0x450923;
BYTE codeTestDarkFlag[] = {
	0xF6, 0x41, 0x20, 0x80,                   //test        byte ptr [ecx+20h],80h
	0x75, 0x04,                               //jne         end
	0x80, 0x61, 0x20, 0xF7,                   //and         byte ptr [ecx+20h],0F7h
	                                          //end:
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeTestDarkFlagThunk[] = {0xE8, 0x6C, 0x14, 0xF2, 0xFF};//dwAddrTestDarkFlag - 52F4B2h - 5
BYTE codeTestDarkFlagOldThunk[] = {0xE8, 0xA9, 0xF8, 0xFF, 0xFF};//call 52ED60h()
ASM_PATCH patchTestDarkFlagThunk[] = {
	{0x52F4B2, sizeof(codeTestDarkFlagThunk), codeTestDarkFlagThunk},
	{0x52F4B2, sizeof(codeTestDarkFlagOldThunk), codeTestDarkFlagOldThunk}};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                battle
///////////////////////////////////////////////////////////////////////////////////////////////

//shared code on stack bottom
DWORD dwAddrStackBottom = 0xA0000;//stack : 30000h~130000h

//chase/keep_attack flag
DWORD dwAddrChaseFlag = dwAddrStackBottom + 0x3AC0;
BYTE codeChaseFlag[] = {
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0xF6, 0x40, 0x34, 0x05,                   //test        byte ptr [eax+34h],5
	0x75, 0x1A,                               //jne         normal
	0x80, 0x79, 0x52, 0x03,                   //cmp         byte ptr[ecx+52h],3
	0x75, 0x14,                               //jne         normal
	0x8B, 0x41, 0x64,                         //mov         eax,[ecx+64h]
	0x81, 0xB8, 0x88, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00,//cmp dword ptr[eax+88h],2710h
	0x7D, 0x02,                               //jge         end
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //normal:
	0x81, 0x3C, 0x24, 0x34, 0x52, 0x46, 0x00, //cmp         dword ptr [esp],465234h
	0x75, 0x07,                               //jne         keep_attack
	0x68, 0x90, 0x0E, 0x46, 0x00,             //push        460E90h
	0xEB, 0x05,                               //jmp         go_back
	                                          //keep_attack:
	0x68, 0xB0, 0x0E, 0x46, 0x00,             //push        460EB0h
	                                          //go_back
	0xC3                                      //ret
};

BYTE codeChaseFlagThunk[] = {0xE8, 0x8C, 0xE8, 0xC3, 0xFF};//dwAddrChaseFlag - 46522Fh - 5
BYTE codeChaseFlagOldThunk[] = {0xE8, 0x5C, 0xBC, 0xFF, 0xFF};
ASM_PATCH patchChaseFlagThunk[] = {
	{0x46522F, sizeof(codeChaseFlagThunk), codeChaseFlagThunk},
	{0x46522F, sizeof(codeChaseFlagOldThunk), codeChaseFlagOldThunk}};

BYTE codeKeepAttackFlagThunk[] = {0xE8, 0x2E, 0xBF, 0xC3, 0xFF};//dwAddrChaseFlag - 467B8Dh - 5
BYTE codeKeepAttackFlagOldThunk[] = {0xE8, 0x1E, 0x93, 0xFF, 0xFF};
ASM_PATCH patchKeepAttackFlagThunk[] = {
	{0x467B8D, sizeof(codeKeepAttackFlagThunk), codeKeepAttackFlagThunk},
	{0x467B8D, sizeof(codeKeepAttackFlagOldThunk), codeKeepAttackFlagOldThunk}};

//check troop pos
DWORD dwAddrCheckTroopPos = dwAddrStackBottom + 0x0030;
BYTE codeCheckTroopPos[] = {
	0x57,										//push        edi
	0x8B, 0x41, 0x74,							//mov         eax,dword ptr [ecx+74h]
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x75, 0x06,									//jne         normal
	0x80, 0x79, 0x52, 0x03,						//cmp         byte ptr [ecx+52h],3
	0x74, 0x09,									//je          goal_troop
												//normal:
	0x5F,										//pop         edi
	0x8B, 0xCE,									//mov         ecx,esi
	0x68, 0x70, 0x0E, 0x46, 0x00,				//push        460E70h
	0xC3,										//ret
												//goal_troop:
	0x8A, 0x41, 0x56,							//mov         al,byte ptr [ecx+56h]
	0x3C, 0xFF,									//cmp         al,0FFh
	0x74, 0x11,									//je          test_goal_build_troop
	0x3C, 0x03,									//cmp         al,3
	0x74, 0x0D,									//je          test_goal_build_troop
												//retreat_troop:
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xD0, 0x00, 0x0A, 0x00,				//mov         eax,retreat_soldier_troop
	0xFF, 0xD0,									//call        eax
	0x5F,										//pop         edi
	0xC2, 0x04, 0x00,							//ret         4
												//test_goal_build_troop:
	0xFF, 0x71, 0x50,							//push        dword ptr [ecx+50h]
	0xB8, 0xC0, 0x37, 0x45, 0x00,				//mov         eax,4537C0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x8B, 0xF8,									//mov         edi,eax
	0x8A, 0x47, 0x58,							//mov         al,byte ptr [edi+58h]
	0x3C, 0x28,									//cmp         al,28h
	0x7C, 0x04,									//jl          check_build_troop
	0x3C, 0x32,									//cmp         al,32h
	0x7E, 0x3A,									//jle         goal_build_troop
												//check_build_troop:
	0x8B, 0x47, 0x6C,							//mov         eax,dword ptr [edi+6Ch]
	0x80, 0x78, 0x04, 0x0D,						//cmp         byte ptr [eax+4],0Dh
	0x74, 0xD2,									//je          retreat_troop
	0x8B, 0x7E, 0x64,							//mov         edi,dword ptr [esi+64h]
	0x57,										//push        edi
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,				//mov         eax,get_distance
	0xFF, 0xD0,									//call        eax
	0x83, 0xF8, 0x1E,							//cmp         eax,1Eh
												//skip_normal:
	0x7E, 0xAC,									//jle         normal
	0x83, 0xF8, 0x3C,							//cmp         eax,3Ch
	0x7F, 0xBB,									//jg          retreat_troop
	0x57,										//push        edi
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x70, 0x88, 0x46, 0x00,				//mov         eax,468870h
	0xFF, 0xD0,									//call        eax
	0x6A, 0x06,									//push        6
	0x5A,										//pop         edx
	0x80, 0x7F, 0x06, 0x05,						//cmp         byte ptr [edi+6],5
	0x74, 0x01,									//je          check_arrive_day
	0x4A,										//dec         edx
												//check_arrive_day:
	0x3B, 0xC2,									//cmp         eax,edx
												//skip_normal2:
	0x7E, 0xE1,									//jle         skip_normal
	0xEB, 0xA1,									//jmp         retreat_troop
												//goal_build_troop:
	0x8B, 0x47, 0x74,							//mov         eax,dword ptr [edi+74h]
												//skip_normal3:
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x74, 0xF3,									//je          skip_normal2
	0x8B, 0x46, 0x74,							//mov         eax,dword ptr [esi+74h]
	0xF6, 0x40, 0x0D, 0x01,						//test        byte ptr [eax+0Dh],1
	0x75, 0xF1,									//jne         skip_normal3
	0x68, 0x00, 0x76, 0x0A, 0x00,				//push        attack_player_build
	0xC3										//ret
};

BYTE codeCheckTroopPosThunk[] = {0xE8, 0x1B, 0xB1, 0xC3, 0xFF};//dwAddrCheckTroopPos - 464F10h - 5
BYTE codeCheckTroopPosOldThunk[] = {0xE8, 0x5B, 0xBF, 0xFF, 0xFF};
ASM_PATCH patchCheckTroopPosThunk[] = {
	{0x464F10, sizeof(codeCheckTroopPosThunk), codeCheckTroopPosThunk},
	{0x464F10, sizeof(codeCheckTroopPosOldThunk), codeCheckTroopPosOldThunk}};

//retreat_soldier_troop
DWORD dwAddrRetreatSoldierTroop = dwAddrStackBottom + 0x00D0;
BYTE codeRetreatSoldierTroop[] = {
												//retreat_soldier_troop:
	0x33, 0xC0,									//xor         eax,eax
	0x89, 0x41, 0x7C,							//mov         [ecx+7Ch],eax
	0xB0, 0x34,									//mov         al,34h
	0x89, 0x41, 0x58,							//mov         [ecx+58h],eax
	0x8B, 0x41, 0x64,							//mov         eax,[ecx_64h]
	0x8B, 0x50, 0x04,							//mov         edx,[eax+4]
	0x89, 0x51, 0x50,							//mov         [ecx+50h],edx
	0xC3										//ret
};

//multi search person list
DWORD dwAddrSearchPersonList = dwAddrStackBottom + 0x500;//multi_search_person_list
DWORD dwDataSearchPersonList[] = {0x606C8C, 0, 0, 0, 0, 0, 0xA, 0x6060E8};//size=20h

//attack troop list
DWORD dwAddrAttackTroopList = dwAddrStackBottom + 0x520;//attack_troop_list
DWORD dwDataAttackTroopList[] = {0x606D70, 0, 0, 0, 0, 0, 0xA, 0x60646C};//size=20h

//clear multi-search person list
DWORD dwAddrSearchPersonClear = dwAddrStackBottom + 0x540;
BYTE codeSearchPersonClear[] = {//length=18h
	                                          //search_person_clear:
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x77, 0xF1, 0x43, 0x00,             //mov         [search_person_pointer],eax
	0x59,                                     //pop         ecx
	0x58,                                     //pop         eax
	0xC3                                      //ret
};

//dispatch person
DWORD dwAddrDispatchPerson = dwAddrSearchPersonClear + 0x20;
BYTE codeDispatchPerson[] = {
	0x80, 0x79, 0x0C, 0x05,                   //cmp         byte ptr [ecx+0Ch],5
	0x7C, 0x2C,                               //jl          low_able_person
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x33, 0xF6,                               //xor         esi,esi
	0x8B, 0x51, 0x08,                         //mov         edx,dword ptr [ecx+8]
	                                          //loop_person2:
	0x8B, 0x4A, 0x08,                         //mov         ecx,dword ptr [edx+8]
	0x8B, 0x41, 0x58,                         //mov         eax,dword ptr [ecx+58h]
	0x3C, 0x40,                               //cmp         al,40h
	0x7D, 0x0F,                               //jge         loop_end2
	0x3B, 0xC6,                               //cmp         eax,esi
	0x7E, 0x04,                               //jle         next_person2
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0xFA,                               //mov         edi,edx
	                                          //next_person2:
	0x8B, 0x52, 0x04,                         //mov         edx,dword ptr [edx+4]
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0xE7,                               //jne         loop_person2
	                                          //loop_end2:
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x02,                               //jne         get_int_person
	0x8B, 0xD7,                               //mov         edx,edi
	                                          //get_int_person:
	0x8B, 0x42, 0x08,                         //mov         eax,dword ptr [edx+8]
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //low_able_person:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x8B, 0x71, 0x04,                         //mov         esi,dword ptr [ecx+4]
	0xBF, 0x00, 0x01, 0x00, 0x00,             //mov         edi,100h
	                                          //loop_person:
	0x8B, 0x46, 0x08,                         //mov         eax,dword ptr [esi+8]
	0xBA, 0xB2, 0xEF, 0x46, 0x00,             //mov         edx,garbage_person
	0xFF, 0xD2,                               //call        edx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x2E,                               //je          loop_end
	0x33, 0xC0,                               //xor         eax,eax
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x51, 0x50,                         //mov         edx,dword ptr [ecx+50h]
	0x3B, 0xD0,                               //cmp         edx,eax
	0x7E, 0x02,                               //jle         get_int
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //get_int:
	0x8B, 0x51, 0x58,                         //mov         edx,dword ptr [ecx+58h]
	0x3B, 0xD0,                               //cmp         edx,eax
	0x7E, 0x02,                               //jle         get_lead
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //get_lead:
	0x8B, 0x51, 0x68,                         //mov         edx,dword ptr [ecx+68h]
	0x3B, 0xD0,                               //cmp         edx,eax
	0x7E, 0x02,                               //jle         got_max_able
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //got_max_able:
	0x3B, 0xC7,                               //cmp         eax,edi
	0x7D, 0x04,                               //jge         next_person
	0x8B, 0xF8,                               //mov         edi,eax
	0x8B, 0xDE,                               //mov         ebx,esi
	                                          //next_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xC4,                               //jne         loop_person
	                                          //loop_end:
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0x02,                               //jne         get_worst_person
	0x8B, 0xF3,                               //mov         esi,ebx
	                                          //get_worst_person:
	0x8B, 0x46, 0x08,                         //mov         eax,dword ptr [esi+8]
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeDispatchPersonThunk[] = {0xE8, 0x53, 0xC6, 0xBF, 0xFF};//dwAddrDispatchPerson - 4A3F08h - 5
BYTE codeDispatchPersonOldThunk[] = {0xE8, 0x03, 0x43, 0x07, 0x00};
ASM_PATCH patchDispatchPersonThunk[] = {
	{0x4A3F08, sizeof(codeDispatchPersonThunk), codeDispatchPersonThunk},
	{0x4A3F08, sizeof(codeDispatchPersonOldThunk), codeDispatchPersonOldThunk}};

//check menace troop
DWORD dwAddrCheckMenaceTroop = dwAddrStackBottom + 0x600;
BYTE codeCheckMenaceTroop[] = {
	                                          //check_menace_troop:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x8B, 0xF2,                               //mov         esi,edx
	0x8B, 0xF9,                               //mov         edi,ecx
	0xB8, 0x20, 0x54, 0x43, 0x00,             //mov         eax,435420h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x3B,                               //je          no_menace_troop
	0x8B, 0x4E, 0x74,                         //mov         ecx,dword ptr [esi+74h]
	0xF6, 0x41, 0x34, 0x01,                   //test        dword ptr [ecx+34h],1
	0x74, 0x32,                               //je          no_menace_troop
	0x8B, 0x97, 0xCC, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [edi+0CCh]
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x28,                               //jz          no_menace_troop
	0x51,                                     //push        ecx
	0x52,                                     //push        edx
	0xB8, 0x70, 0x06, 0x4B, 0x00,             //mov         eax,4B0670h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x18,                               //je          no_menace_troop
	0x56,                                     //push        esi
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x1E,                         //cmp         eax,1Eh
	0x7F, 0x04,                               //jg          test_max_distance,
	0xB0, 0x01,                               //mov         al,1
	0xEB, 0x67,                               //jmp         end_check_menace_troop
	                                          //test_max_distance:
	0x83, 0xF8, 0x3C,                         //cmp         eax,3Ch
	0x7E, 0x04,                               //jle         check_building_soldier
	                                          //no_menace_troop:
	0x33, 0xC0,                               //xor         eax,eax
	0xEB, 0x5E,                               //jmp         end_check_menace_troop
	                                          //check_building_soldier:
	0x81, 0xBF, 0x88, 0x00, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00,//cmp dword ptr[esi+88],2710h
	0x7D, 0x07,                               //jge         check_troop_array
	0xBA, 0x0C, 0x00, 0x00, 0x00,             //mov         edx,0Ch
	0xEB, 0x36,                               //jmp         get_arrive_day
	                                          //check_troop_array:
	0x8B, 0x4E, 0x6C,                         //mov         ecx,dword ptr [esi+6Ch]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x0D,                               //cmp         al,0Dh
	0x74, 0xDF,                               //je          no_menace_troop
	0x3C, 0x0E,                               //cmp         al,0Eh
	0x74, 0x00,                               //je          $
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0xE3, 0x45, 0x00,             //mov         eax,45E390h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0xBA, 0x08, 0x00, 0x00, 0x00,             //mov         edx,8
	0x74, 0x2C,                               //je          troop_on_land
	0xB2, 0x0A,                               //mov         dl,0Ah
	0x8B, 0x4E, 0x70,                         //mov         ecx,dword ptr [esi+70h]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x16,                               //cmp         al,16h
	0x75, 0x02,                               //jne         test_fight_ship
	0xB2, 0x0D,                               //mov         dl,0Dh
	                                          //test_fight_ship:
	0x3C, 0x17,                               //cmp         al,17h
	0x75, 0x02,                               //jne         get_arrive_day
	0xB2, 0x0C,                               //mov         dl,0Ch
	                                          //get_arrive_day:
	0x52,                                     //push        edx
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x28, 0x24, 0x0A, 0x00,             //mov         eax,safe_arrive_day
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x33, 0xC9,                               //xor         ecx,ecx
	0x3B, 0xC2,                               //cmp         eax,edx
	0x0F, 0x9E, 0xC1,                         //setle       cl
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //end_check_menace_troop:
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //troop_on_land:
	0x3C, 0x08,                               //cmp         al,8
	0x75, 0x02,                               //jne         test_stone
	0xB2, 0x0F,                               //mov         dl,0Fh
	                                          //test_stone:
	0x3C, 0x0A,                               //cmp         al,0Ah
	0x75, 0x02,                               //jne         test_goose
	0xB2, 0x0C,                               //mov         dl,0Ch
	                                          //test_goose:
	0x3C, 0x04,                               //cmp         al,4
	0x74, 0x04,                               //je          basic_seige
	0x3C, 0x05,                               //cmp         al,5
	0x75, 0x02,                               //jne         test_wimble
	                                          //basic_seige:
	0xB2, 0x0A,                               //mov         dl,0Ah
	                                          //test_wimble:
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0xCE,                               //jne         get_arrive_day
	0x8B, 0x8E, 0x88, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [esi+88h]
	                                          //loop_person:
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0x8B, 0x80, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0F8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0E,                               //je          next_person
	0x80, 0x78, 0x04, 0x06,                   //cmp         byte ptr [eax+4],6
	0x7C, 0x08,                               //jl          next_person
	0x80, 0x78, 0x04, 0x08,                   //cmp         byte ptr [eax+4],8
	0x7F, 0x02,                               //jg          next_person
	0x42,                                     //inc         edx
	0x90,//0x42,                                     //inc         edx
	                                          //next_person:
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0xDF,                               //jne         loop_person
	0xEB, 0xA5                                //jmp         get_arrive_day
};

//wisdom person
DWORD dwAddrWisdomPerson = dwAddrStackBottom + 0x2B0;
BYTE codeWisdomPerson[] = {
	0xF6, 0x05, 0xC7, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[wisdom_effective_flag], 1
	0x74, 0x38,                               //je          end
	0x81, 0x3C, 0x24, 0x79, 0xE1, 0x4F, 0x00, //cmp         dword ptr[esp], 4FE179h
	0x75, 0x07,                               //jne         get_wisdom_person
	0xC6, 0x05, 0xC7, 0xF4, 0x43, 0x00, 0x00, //mov         byte ptr[wisdom_effective_flag], 0
	                                          //get_wisdom_person:
	0x33, 0xC0,                               //xor         eax,eax
	0x51,                                     //push        ecx
	0x8B, 0x91, 0x88, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [ecx+88h]
	                                          //loop_troop:
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x13,                               //je          end_troop
	0x8B, 0x4A, 0x08,                         //mov         ecx,dword ptr [edx+8]
	0x8B, 0x12,                               //mov         edx,dword ptr [edx]
	0x81, 0xB9, 0xF8, 0x00, 0x00, 0x00, 0xD8, 0xE6, 0x4F, 0x01,//cmp dword ptr [ecx+0F8h],14FE6D8h
	0x75, 0xEB,                               //jne         loop_troop
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //end_troop:
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x03,                               //je          end
	0xC2, 0x0C, 0x00,                         //ret         0Ch
	                                          //end:
	0x8B, 0x11,                               //mov         edx,[ecx]
	0xFF, 0xA2, 0xC4, 0x00, 0x00, 0x00        //jmp         dword ptr [edx+0C4h]
};
//进行记录
BYTE codeWisdomPersonThunk[] = {0xE8, 0x37, 0x21, 0xBA, 0xFF, 0x41};//dwAddrWisdomPerson - 4FE174h - 5
BYTE codeWisdomPersonOldThunk[] = {0xFF, 0x92, 0xC4, 0x00, 0x00, 0x00};
ASM_PATCH patchWisdomPersonThunk[] = {
	{0x4FE174, sizeof(codeWisdomPersonThunk), codeWisdomPersonThunk},
	{0x4FE174, sizeof(codeWisdomPersonOldThunk), codeWisdomPersonOldThunk}};
//辱骂小对白
BYTE codeWisdomPersonAbuseThunk[] = {0xE8, 0xB6, 0xF7, 0xB9, 0xFF, 0x41};//dwAddrWisdomPerson - 500AF5h - 5
BYTE codeWisdomPersonAbuseOldThunk[] = {0xFF, 0x90, 0xC4, 0x00, 0x00, 0x00};
ASM_PATCH patchWisdomPersonAbuseThunk[] = {
	{0x500AF5, sizeof(codeWisdomPersonAbuseThunk), codeWisdomPersonAbuseThunk},
	{0x500AF5, sizeof(codeWisdomPersonAbuseOldThunk), codeWisdomPersonAbuseOldThunk}};
//攻心小对白
BYTE codeWisdomPersonAttackHeartThunk[] = {0xE8, 0x6B, 0xB0, 0xB9, 0xFF, 0x41};//dwAddrWisdomPerson - 505240h - 5
BYTE codeWisdomPersonAttackHeartOldThunk[] = {0xFF, 0x92, 0xC4, 0x00, 0x00, 0x00};
ASM_PATCH patchWisdomPersonAttackHeartThunk[] = {
	{0x505240, sizeof(codeWisdomPersonAttackHeartThunk), codeWisdomPersonAttackHeartThunk},
	{0x505240, sizeof(codeWisdomPersonAttackHeartOldThunk), codeWisdomPersonAttackHeartOldThunk}};
//幻术小对白
BYTE codeWisdomPersonMagicThunk[] = {0xE8, 0xD5, 0x95, 0xB9, 0xFF, 0x41};//dwAddrWisdomPerson - 506CD6h - 5
BYTE codeWisdomPersonMagicOldThunk[] = {0xFF, 0x92, 0xC4, 0x00, 0x00, 0x00};
ASM_PATCH patchWisdomPersonMagicThunk[] = {
	{0x506CD6, sizeof(codeWisdomPersonMagicThunk), codeWisdomPersonMagicThunk},
	{0x506CD6, sizeof(codeWisdomPersonMagicOldThunk), codeWisdomPersonMagicOldThunk}};
//妖术小对白
BYTE codeWisdomPersonBlackArtThunk[] = {0xE8, 0x87, 0x89, 0xB9, 0xFF, 0x41};//dwAddrWisdomPerson - 507924h - 5
BYTE codeWisdomPersonBlackArtOldThunk[] = {0xFF, 0x90, 0xC4, 0x00, 0x00, 0x00};
ASM_PATCH patchWisdomPersonBlackArtThunk[] = {
	{0x507924, sizeof(codeWisdomPersonBlackArtThunk), codeWisdomPersonBlackArtThunk},
	{0x507924, sizeof(codeWisdomPersonBlackArtOldThunk), codeWisdomPersonBlackArtOldThunk}};

/////////////////////////////////////////////
#define PATCH_WISDOM_EFFECTIVE_FLAG_NUM 2

DWORD dwAddrWisdomEffectivFlag[PATCH_WISDOM_EFFECTIVE_FLAG_NUM] = {0x4B3574, 0x4B3785};
DWORD dwSizeWisdomEffectivFlag[PATCH_WISDOM_EFFECTIVE_FLAG_NUM] = {0xC, 0xA};
BYTE codeWisdomEffectivFlag[PATCH_WISDOM_EFFECTIVE_FLAG_NUM][PATCH_SIZE] = {
	{0xE8, 0x87, 0x54, 0xF9, 0xFF,            //call        448A00h
	0x85, 0xC0,                               //test        eax,eax
	0xE9, 0x05, 0x02, 0x00, 0x00},
	//1:7+5
	{0x75, 0x07,                              //jne         end
	0xC6, 0x05, 0xC7, 0xF4, 0x43, 0x00, 0x01, //mov         byte ptr[wisdom_effective_flag],1
	                                          //end:
	0xC3}                                     //ret
	//2:A
};
ASM_PATCH patchWisdomEffectivFlag[PATCH_WISDOM_EFFECTIVE_FLAG_NUM] = {{0, 0, 0}};

BYTE codeWisdomEffectivFlagThunk[] = {0xE8, 0x91, 0x49, 0xFB, 0xFF};//4B3574h - 4FEBDEh - 5
BYTE codeWisdomEffectivFlagOldThunk[] = {0xE8, 0x1D, 0x9E, 0xF4, 0xFF};
ASM_PATCH patchWisdomEffectivFlagThunk[] = {
	{0x4FEBDE, sizeof(codeWisdomEffectivFlagThunk), codeWisdomEffectivFlagThunk},
	{0x4FEBDE, sizeof(codeWisdomEffectivFlagOldThunk), codeWisdomEffectivFlagOldThunk}};

/////////////////////////////////////////////
DWORD dwAddrLowerBuildExpense = 0x44F093;
BYTE codeLowerBuildExpense[] = {
	0x8D, 0x48, 0x04,                         //lea         ecx,[eax+4]
	0x8B, 0xC6,                               //mov         eax,esi
	0x6B, 0xC0, 0x04,						  //imul        eax,4
	0xC3                                      //ret
};

BYTE codeLowerBuildExpenseThunk[] = {0xE8, 0xD1, 0x58, 0xFC, 0xFF, 0x42};//44F093h - 4897BDh - 5
BYTE codeLowerBuildExpenseOldThunk[] = {0x8D, 0x48, 0x02, 0x8D, 0x04, 0x36};
ASM_PATCH patchLowerBuildExpenseThunk[] = {
	{0x4897BD, sizeof(codeLowerBuildExpenseThunk), codeLowerBuildExpenseThunk},
	{0x4897BD, sizeof(codeLowerBuildExpenseOldThunk), codeLowerBuildExpenseOldThunk}};

/////////////////////////////////////////////
#define PATCH_MIN_DISPATCH_SOLDIER_NUM 3

DWORD dwAddrMinDispatchSoldier[PATCH_MIN_DISPATCH_SOLDIER_NUM] = {0x57A2C3, 0x57A341, 0x510191};
DWORD dwSizeMinDispatchSoldier[PATCH_MIN_DISPATCH_SOLDIER_NUM] = {0xC, 0xF, 0xF};
BYTE codeMinDispatchSoldier[PATCH_MIN_DISPATCH_SOLDIER_NUM][PATCH_SIZE] = {
	{0x81, 0x7C, 0x24, 0x04, 0xB8, 0x0B, 0x00, 0x00,//cmp   dword ptr [esp+4],0BB8h
	0x7C, 0x7A,                               //jl          min_soldier
	0xEB, 0x72},

	{0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00,      //jmp         [5FF308h]
	                                          //min_soldier:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x11,                               //mov         edx,dword ptr [ecx]
	0xE9, 0x41, 0x5E, 0xF9, 0xFF},

	{0xFF, 0x52, 0x0C,                        //call        dword ptr [edx+0Ch]
	0x8B, 0xD0,                               //mov         edx,eax
	0x33, 0xC0,                               //xor         eax,eax

	0x89, 0x84, 0x95, 0x3C, 0x27, 0x00, 0x00, //mov         dword ptr [ebp+edx*4+273Ch],eax
	0xC3}                                     //ret
	//3:F
};
ASM_PATCH patchMinDispatchSoldier[PATCH_MIN_DISPATCH_SOLDIER_NUM] = {{0, 0, 0}};

BYTE codeMinDispatchSoldierThunk[] = {0xE8, 0x13, 0x63, 0x0D, 0x00, 0x42};//57A2C3h - 4A3FABh - 5
BYTE codeMinDispatchSoldierOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};
ASM_PATCH patchMinDispatchSoldierThunk[] = {
	{0x4A3FAB, sizeof(codeMinDispatchSoldierThunk), codeMinDispatchSoldierThunk},
	{0x4A3FAB, sizeof(codeMinDispatchSoldierOldThunk), codeMinDispatchSoldierOldThunk}};

//attack troop condition
DWORD dwAddrAttackTroopCondition = dwAddrStackBottom + 0x770;
BYTE codeAttackTroopCondition[] = {
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0xE3, 0x45, 0x00,             //mov         eax,45E390h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0xBA, 0x11, 0x00, 0x00, 0x00,             //mov         edx,11h
	0x75, 0x1A,                               //jne         test_soldier
	0x8B, 0x4E, 0x6C,                         //mov         ecx,dword ptr [esi+6Ch]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x0A,                               //cmp         al,0Ah
	0x74, 0x29,                               //je          test_arrive_day
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x2E,                               //je          test_wimble_killer
	0x3C, 0x06,                               //cmp         al,6
	0x75, 0x04,                               //jne         test_field_array
	                                          //near_attack:
	0xB2, 0x08,                               //mov         dl,8
	0xEB, 0x1D,                               //jmp         test_arrive_day
	                                          //test_field_array:
	0x3C, 0x03,                               //cmp         al,3
	0x7E, 0xF8,                               //jle         near_attack
	                                          //test_soldier:
	0x8B, 0x46, 0x30,                         //mov         eax,[esi+30h]
	0x3D, 0x00, 0x20, 0x00, 0x00,             //cmp         eax,2000h
	0x7D, 0x0F,                               //jge         test_arrive_day
	0x81, 0x7E, 0x34, 0x00, 0x10, 0x00, 0x00, //cmp         dword ptr [esi+34h],1000h
	0x7D, 0x06,                               //jge         test_arrive_day
	0x0F, 0xAF, 0xD0,                         //imul        edx,eax
	0xC1, 0xEA, 0x0D,                         //shr         edx,0Dh
	                                          //test_arrive_day:
	0x3B, 0xFA,                               //cmp         edi,edx
	0x7E, 0x04,                               //jle         end
	                                          //fail:
	0xC6, 0x04, 0x24, 0x6D,                   //mov         byte ptr [esp],6Dh
	                                          //end:
	0xC3,                                     //ret
	                                          //test_wimble_killer:
	0xB2, 0x08,                               //mov         dl,8
	0x8B, 0x8E, 0x88, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [esi+88h]
	                                          //loop_person:
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0x8B, 0x80, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0F8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0D,                               //je          next_person
	0x8A, 0x40, 0x04,                         //mov         al,byte ptr [eax+4]
	0x3C, 0x06,                               //cmp         al,6
	0x7C, 0x06,                               //jl          next_person
	0x3C, 0x08,                               //cmp         al,8
	0x7F, 0x02,                               //jg          next_person
	0x42,                                     //inc         edx
	0x42,                                     //inc         edx
	                                          //next_person:
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0xE0,                               //jne         loop_person
	0xEB, 0xB4                                //jmp         test_soldier
};

BYTE codeAttackTroopConditionThunk[] = {0xE8, 0x55, 0xE2, 0xBF, 0xFF, 0x40};//addrAttackTroopCondition - 4A2516h - 5
BYTE codeAttackTroopConditionOldThunk[] = {0x39, 0x7C, 0x24, 0x1C, 0x7E, 0x51};
ASM_PATCH patchAttackTroopConditionThunk[] = {
	{0x4A2516, sizeof(codeAttackTroopConditionThunk), codeAttackTroopConditionThunk},
	{0x4A2516, sizeof(codeAttackTroopConditionOldThunk), codeAttackTroopConditionOldThunk}};

/////////////////////////////////////////////
DWORD dwAddrCheckMinDefence = dwAddrStackBottom + 0x000;
BYTE codeCheckMinDefence[] = {
	0x8B, 0x8C, 0x24, 0x9C, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+9Ch]
	0x8D, 0x44, 0x24, 0x0C,                   //lea         eax,[esp+0Ch]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x60, 0x0A, 0x00,             //mov         eax,get_anti_attack_garrison
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF0,                               //mov         esi,eax
	0x81, 0xEE, 0x70, 0x17, 0x00, 0x00,       //sub         esi,1770h
	0x68, 0xC2, 0xE5, 0x49, 0x00,             //push        49E5C2h
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCheckMinDefenceThunk[] = {0xE8, 0x50, 0x1A, 0xC0, 0xFF, 0x42};//dwAddrCheckMinDefence - 49E5ABh - 5
BYTE codeCheckMinDefenceOldThunk[] = {0x69, 0xC0, 0xA0, 0x0F, 0x00, 0x00};//imul eax, 0FA0h
ASM_PATCH patchCheckMinDefenceThunk[] = {
	{0x49E5AB, sizeof(codeCheckMinDefenceThunk), codeCheckMinDefenceThunk},
	{0x49E5AB, sizeof(codeCheckMinDefenceOldThunk), codeCheckMinDefenceOldThunk}};

//anti attack min defence
DWORD dwAddrAntiAttackMinDefence = dwAddrStackBottom + 0x800;
BYTE codeAntiAttackMinDefence[] = {
	0x8B, 0xCB,                               //mov         ecx,ebx
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x0C,                         //call        [eax+0Ch]
	0xB9, 0x8B, 0xF8, 0x43, 0x00,             //mov         ecx,anti_attack_building_id
	0x66, 0x3B, 0x01,                         //cmp         ax,[ecx]
	0x74, 0x19,                               //je          load_anti_attack_garrison
	0x66, 0x89, 0x01,                         //mov         [ecx],ax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0x8D, 0x44, 0x24, 0x54,                   //lea         eax,[esp+54h]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x60, 0x0A, 0x00,             //mov         eax,get_anti_attack_garrison
	0xFF, 0xD0,                               //call eax
	0x66, 0xA3, 0x8D, 0xF8, 0x43, 0x00,       //mov         [anti_attack_building_id+2],ax
	0xEB, 0x04,                               //jmp         get_max_anti_attack_soldier
	                                          //load_anti_attack_garrison:
	0x0F, 0xB7, 0x41, 0x02,                   //movzx       eax,word ptr[ecx+2]
											  //get_max_anti_attack_soldier:
	0x2B, 0x83, 0x88, 0x00, 0x00, 0x00,       //sub         eax,[ebx+88h]
	0xF7, 0xD8,                               //neg         eax
	0x3D, 0x70, 0x17, 0x00, 0x00,             //cmp         eax,1770h
	0x7D, 0x08,                               //jge         process_journey
	0x68, 0xD8, 0x3D, 0x4A, 0x00,             //push        4A3DD8h
	0xC2, 0x04, 0x00,                         //ret         4

	                                          //process_journey:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x3D, 0x80, 0x3E, 0x00, 0x00,             //cmp         eax,3E80h
	0x7D, 0x3A,                               //jge         much_soldier
	0x8B, 0xF8,                               //mov         edi,eax
	0x3D, 0xE0, 0x2E, 0x00, 0x00,             //cmp         eax,2EE0h
	0x7C, 0x1D,                               //jl          test_soldier_much2
	0x83, 0x7C, 0x24, 0x50, 0x01,             //cmp         dword ptr[esp+50h],1
	0x74, 0x09,                               //je          test_soldier_much
	0xD1, 0xEF,                               //shr         edi,1
	0xBE, 0x02, 0x00, 0x00, 0x00,             //mov         esi,2
	0xEB, 0x4E,                               //jmp         get_journey_person
	                                          //test_soldier_much:
	0x3D, 0xC8, 0x32, 0x00, 0x00,             //cmp         eax,32C8h
	0x7C, 0x06,                               //jl          test_soldier_much2
	0x81, 0xEF, 0xE8, 0x03, 0x00, 0x00,       //sub         edi,3E8h
	                                          //test_soldier_much2:
	0x3D, 0x10, 0x27, 0x00, 0x00,             //cmp         eax,2710h
	0x7C, 0x06,                               //jl          got_protect_building
	0x81, 0xEF, 0xE8, 0x03, 0x00, 0x00,       //sub         edi,3E8h
	                                          //got_protect_building:
	0xBE, 0x01, 0x00, 0x00, 0x00,             //mov         esi,1
	0xEB, 0x2D,                               //jmp         get_journey_person

	                                          //much_soldier:
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0x7C, 0x24, 0x50,                   //mov         edi,dword ptr [esp+50h]
	0xB9, 0x40, 0x1F, 0x00, 0x00,             //mov         ecx,1F40h
	                                          //loop_journey_soldier:
	0x8B, 0xC6,                               //mov         eax,esi
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x3B, 0xF8,                               //cmp         edi,eax
	0x7D, 0x0E,                               //jge         get_journey_soldier
	0x81, 0xC1, 0xD0, 0x07, 0x00, 0x00,       //add         ecx,7D0h
	0x81, 0xF9, 0x20, 0x4E, 0x00, 0x00,       //cmp         ecx,4E20h
	0x7E, 0xE9,                               //jle         loop_journey_soldier
	                                          //get_journey_soldier:
	0x8B, 0xC8,                               //mov         ecx,eax
	0x8B, 0xC6,                               //mov         eax,esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xF8,                               //mov         edi,eax

	                                          //get_journey_person:
	0x89, 0x35, 0x04, 0xFC, 0x43, 0x00,       //mov         [anti_troop_num],esi
	0x57,                                     //push        edi
	0x8B, 0x44, 0x24, 0x54,                   //mov         eax,dword ptr [esp+54h]
	0x99,                                     //cdq
	0xF7, 0xF6,                               //div         eax,esi
	0x52,                                     //push        edx
	0x83, 0xF8, 0x04,                         //cmp         eax,4
	0x7E, 0x07,                               //jle         test_zero_person
	0xB8, 0x04, 0x00, 0x00, 0x00,             //mov         eax,4
	0xEB, 0x09,                               //jmp         get_person_num
	                                          //test_zero_person:
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x05,                               //jne         get_person_num
	0xB0, 0x01,                               //mov         al,1
	0x5A,                                     //pop         edx
	0x6A, 0x00,                               //push        0
	                                          //get_person_num:
	0x48,                                     //dec         eax
	0x75, 0x06,                               //jne         get_sum_intelligence_person
	0x68, 0x78, 0x1A, 0x0A, 0x00,             //push        check_person_remains
	0xC3,                                     //ret

	                                          //get_sum_intelligence_person:
	0x50,                                     //push        eax
	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0x5C, 0x24, 0x54,                   //mov         ebx,dword ptr [esp+54h]
	                                          //loop_sum_intelligence_person:
	0x8B, 0x4B, 0x08,                         //mov         ecx,dword ptr [ebx+8]
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          next_sum_intelligence_person
	0x47,                                     //inc         edi
	                                          //next_sum_intelligence_person:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0xEB,                               //jne         loop_sum_intelligence_person
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          get_troop_intelligence_person
	0x47,                                     //inc         edi
	                                          //get_troop_intelligence_person:
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0xC7,                               //mov         eax,edi
	0x99,                                     //cdq
	0xF7, 0xF6,                               //div         eax,esi
	0x8B, 0x7C, 0x24, 0x10,                   //mov         edi,dword ptr [esp+10h]
	0x3B, 0x7F, 0x44,                         //cmp         edi,dword ptr [edi+44h]
	0x75, 0x13,                               //jne         add_person_remains
	0xF6, 0x47, 0x51, 0xFF,                   //test        byte ptr [edi+51h],0FFh
	0x75, 0x0D,                               //jne         add_person_remains
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x14,                               //je          sub_leader
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x05,                               //jne         add_person_remains
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x0C,                               //jne         sub_leader
	0x48,                                     //dec         eax
	                                          //add_person_remains:
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x01,                               //je          test_max_intelligence_person
	0x40,                                     //inc         eax
	                                          //test_max_intelligence_person:
	0x3C, 0x02,                               //cmp         al,2
	0x7E, 0x02,                               //jle         sub_leader
	0xB0, 0x02,                               //mov         al,2
	                                          //sub_leader:
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x01,                               //je          test_max_intelligence_person
	0x48,                                     //dec         eax
	                                          //test_max_intelligence_person:
	0x5E,                                     //pop         esi
	0x3B, 0xC6,                               //cmp         eax,esi
	0x7E, 0x02,                               //jle         delete_troop_intelligence_person
	0x8B, 0xC6,                               //mov         eax,esi
	                                          //delete_troop_intelligence_person:
	0x8B, 0xD8,                               //mov         ebx,eax
	0x2B, 0xF3,                               //sub         esi,ebx
	0xB8, 0xA8, 0x09, 0x0A, 0x00,             //mov         eax,delete_big_person
	0xFF, 0xD0,                               //call        eax

	0x8B, 0x7C, 0x24, 0x50,                   //mov         edi,dword ptr [esp+50h]
	                                          //loop_delete_intelligence_person:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x26,                               //je          next_delete_intelligence_person
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x12,                               //je          delete_intelligence_person
	0x4B,                                     //dec         ebx
	0x8D, 0x8C, 0x24, 0x10, 0x01, 0x00, 0x00, //lea         ecx,[esp+110h]
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //delete_intelligence_person:
	0x8D, 0x4C, 0x24, 0x4C,                   //lea         ecx,[esp+4Ch]
	0x57,                                     //push        edi
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,                               //jmp         test_end_of_person_list
	                                          //next_delete_intelligence_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	                                          //test_end_of_person_list:
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xC6,                               //jne         loop_delete_intelligence_person
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0x06,                               //jnz         add_person_list
	0x68, 0x78, 0x1A, 0x0A, 0x00,             //push        check_person_remains
	0xC3,                                     //ret
	                                          //add_person_list:
	0x68, 0x00, 0x1A, 0x0A, 0x00,             //push        anti_attack_min_defence2
	0xC3                                      //ret
};

BYTE codeAntiAttackMinDefenceThunk[] = {0xE8, 0x4E, 0xCA, 0xBF, 0xFF, 0x40};//dwAddrAntiAttackMinDefence - 4A3DADh - 5
BYTE codeAntiAttackMinDefenceOldThunk[] = {0x69, 0xC9, 0xA0, 0x0F, 0x00, 0x00};//imul ecx, 0FA0h
ASM_PATCH patchAntiAttackMinDefenceThunk[] = {
	{0x4A3DAD, sizeof(codeAntiAttackMinDefenceThunk), codeAntiAttackMinDefenceThunk},
	{0x4A3DAD, sizeof(codeAntiAttackMinDefenceOldThunk), codeAntiAttackMinDefenceOldThunk}};

//delete big person
DWORD dwAddrDeleteBigPerson = dwAddrStackBottom + 0x9A8;
BYTE codeDeleteBigPerson[] = {
	                                          //delete_big_person:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x8B, 0x1D, 0x04, 0xFC, 0x43, 0x00,       //mov         ebx,[anti_troop_num]
	0x85, 0xDB,                               //text        ebx,ebx
	0x74, 0x40,                               //je          end
	0xFF, 0x74, 0x24, 0x18,                   //push        dword ptr [esp+18h]
	0x68, 0x00, 0x05, 0x0A, 0x00,             //push        multi_search_person_list
	0xB8, 0x00, 0x16, 0x4A, 0x00,             //mov         eax,4A1600h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x3D, 0x04, 0x05, 0x0A, 0x00,       //mov         edi,[multi_search_person_list+4]
	                                          //loop_delete_big_person:
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8D, 0x4C, 0x24, 0x5C,                   //lea         ecx,[esp+5Ch]
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0x4B,                                     //dec         ebx
	0x74, 0x06,                               //je          end_delete_big_person
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xE9,                               //jne         loop_delete_big_person
	                                          //end_delete_big_person:
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x04, 0xFC, 0x43, 0x00,             //mov         [anti_troop_num],eax
	                                          //end:
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//anti attack min defence 2
DWORD dwAddrAntiAttackMinDefence2 = dwAddrStackBottom + 0x1A00;
BYTE codeAntiAttackMinDefence2[] = {
	                                          //anti_attack_min_defence2:
	0x33, 0xDB,                               //xor         ebx,ebx
	                                          //loop_add_person_list:
	0xB3, 0x01,                               //mov         bl,1
	0x8B, 0x7C, 0x24, 0x50,                   //mov         edi,dword ptr [esp+50h]
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x6C,                               //jz          check_person_remains
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x03,                         //cmp         eax,3
	0x7F, 0x2E,                               //jg          compare_next_person
	                                          //add_person:
	0x8B, 0x6F, 0x08,                         //mov         ebp,dword ptr[edi+8]
	0x2B, 0xF3,                               //sub         esi,ebx
	                                          //loop_add_person:
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8D, 0x8C, 0x24, 0x14, 0x01, 0x00, 0x00, //lea         ecx,[esp+114h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x57,                                     //push        edi
	0x8B, 0x7F, 0x04,                         //mov         edi,dword ptr[edi+4]
	0x8D, 0x4C, 0x24, 0x50,                   //lea         ecx,[esp+50h]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0x4B,                                     //dec         ebx
	0x75, 0xDD,                               //jnz         loop_add_person
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xB9,                               //jne         loop_add_person_list
	0xEB, 0x2D,                               //jmp         check_person_remains
	                                          //compare_next_person:
	0x8B, 0x07,                               //mov         eax,dword ptr [edi]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x17,                               //je          check_class_counter
	0xFF, 0x70, 0x08,                         //push        dword ptr [eax+8]
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x03,                         //cmp         eax,3
	0x7F, 0x05,                               //jg          check_class_counter
	0x43,                                     //inc         ebx
	                                          //next_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xEB, 0xE3,                               //jmp         compare_next_person
	                                          //check_class_counter:
	0x3B, 0xDE,                               //cmp         ebx,esi
	0x7E, 0xB1,                               //jle         add_person
	0xB3, 0x01,                               //mov         bl,1
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0xF2,                               //jnz         next_person
	0x8B, 0x7C, 0x24, 0x50,                   //mov         edi,dword ptr [esp+50h]
	0xEB, 0xA5,                               //jmp         add_person

	                                          //check_person_remains:
	0x5A,                                     //pop         edx
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x3D,                               //je          end
	0x83, 0xBC, 0x24, 0x18, 0x01, 0x00, 0x00, 0x04,//cmp    dword ptr [esp+118h],4
	0x7D, 0x33,                               //jge         end
	0x52,                                     //push        edx
	0xB8, 0xA8, 0x09, 0x0A, 0x00,             //mov         eax,delete_big_person
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0x7C, 0x24, 0x4C,                   //mov         edi,dword ptr [esp+4Ch]
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x22,                               //jz          end
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x03,                         //cmp         eax,3
	0x7F, 0x11,                               //jg          end
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8D, 0x8C, 0x24, 0x10, 0x01, 0x00, 0x00, //lea         ecx,[esp+110h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //end:
	0x58,                                     //pop         eax

	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0x68, 0xD8, 0x3D, 0x4A, 0x00,             //push        4A3DD8h
	0xC2, 0x04, 0x00                          //ret         4
};

//test intelligence person
DWORD dwAddrTestIntelligencePerson = 0x4861A1;
BYTE codeTestIntelligencePerson[] = {
	                                          //test_intelligence_person:
	0x8B, 0x51, 0x54,                         //mov         edx,dword ptr [ecx+54h]
	0x2B, 0x51, 0x4C,                         //sub         edx,dword ptr [ecx+4Ch]
	0x33, 0xC0,                               //xor         eax,eax
	0x83, 0xFA, 0x08,                         //cmp         edx,8
	0x7C, 0x01,                               //jl          end
	0x40,                                     //inc         eax
	                                          //end:
	0xC3                                      //ret
};

//alienate min day
DWORD dwAddrAlienateMinDay = dwAddrStackBottom + 0xA00;
BYTE codeAlienateMinDay[] = {
	0x58,                                     //pop         eax
	0xB8, 0x70, 0xF7, 0x46, 0x00,             //mov         eax,46F770h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x06,                               //jne         filter_person_list
	                                          //normal:
	0x68, 0xB1, 0x13, 0x4B, 0x00,             //push        4B13B1h
	0xC3,                                     //ret
	                                          //filter_person_list:
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x8B, 0x7E, 0x04,                         //mov         edi,dword ptr [esi+4]
	0x8B, 0xAB, 0xF4, 0x00, 0x00, 0x00,       //mov         ebp,dword ptr [ebx+0F4h]
	0xF7, 0x45, 0x20, 0x01, 0x00, 0x00, 0x00, //test        dword ptr [ebp+20h],1
	0x74, 0x03,                               //je          loop_person
	0x8B, 0x6D, 0x64,                         //mov         ebp,dword ptr [ebp+64h]
	                                          //loop_person:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x89, 0xF4, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0F4h]
	0xFF, 0x71, 0x64,                         //push        dword ptr [ecx+64h]
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC0, 0x1D,                         //add         eax,1Dh
	0x99,                                     //cdq
	0xB9, 0x1E, 0x00, 0x00, 0x00,             //mov         ecx,1Eh
	0xF7, 0xF1,                               //div         eax,ecx
	0x83, 0xF8, 0x0F,                         //cmp         eax,0Fh
	0x7E, 0x0F,                               //jle         end_person
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xCC,                               //jne         loop_person
	                                          //end_person:
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0xEB, 0xAB                                //jmp         normal
};

BYTE codeAlienateMinDayThunk[] = {0xE8, 0x4F, 0xF6, 0xBE, 0xFF};//dwAddrAlienateMinDay - 4B13ACh - 5
BYTE codeAlienateMinDayOldThunk[] = {0xE8, 0xBF, 0xE3, 0xFB, 0xFF};//call 46F770h
ASM_PATCH patchAlienateMinDayThunk[] = {
	{0x4B13AC, sizeof(codeAlienateMinDayThunk), codeAlienateMinDayThunk},
	{0x4B13AC, sizeof(codeAlienateMinDayOldThunk), codeAlienateMinDayOldThunk}};

//get distance
DWORD dwAddrGetDistance = dwAddrStackBottom + 0xA80;
BYTE codeGetDistance[] = {
	                                          //get_distance:
	0x8B, 0x54, 0x24, 0x04,                   //mov         edx,dword ptr [esp+4]
	0x8B, 0x42, 0x10,                         //mov         eax,dword ptr [edx+10h]
	0x03, 0x42, 0x18,                         //add         eax,dword ptr [edx+18h]
	0x2B, 0x41, 0x10,                         //sub         eax,dword ptr [ecx+10h]
	0x2B, 0x41, 0x18,                         //sub         eax,dword ptr [ecx+18h]
	0xD1, 0xF8,                               //sar         eax,1
	0x0F, 0xAF, 0xC0,                         //imul        eax,eax
	0x50,                                     //push        eax
	0x8B, 0x42, 0x14,                         //mov         eax,dword ptr [edx+14h]
	0x03, 0x42, 0x1C,                         //add         eax,dword ptr [edx+1Ch]
	0x2B, 0x41, 0x14,                         //sub         eax,dword ptr [ecx+14h]
	0x2B, 0x41, 0x1C,                         //sub         eax,dword ptr [ecx+1Ch]
	0xD1, 0xF8,                               //sar         eax,1
	0x0F, 0xAF, 0xC0,                         //imul        eax,eax
	0x5A,                                     //pop         edx
	0x03, 0xC2,                               //add         eax,edx
	0x50,                                     //push        eax
	0xFF, 0x15, 0x1C, 0xF3, 0x5F, 0x00,       //call        [5FF31Ch]
	0x83, 0xC4, 0x04,                         //add         esp,4
	0xC2, 0x04, 0x00                          //ret         4
};

//check no soldier building
DWORD dwAddrCheckNoSoldierBuilding = dwAddrStackBottom + 0xB00;
BYTE codeCheckNoSoldierBuilding[] = {
	0x51,                                     //push        ecx
	0x80, 0x7E, 0x06, 0x04,                   //cmp         byte ptr [esi+6],4
	0x75, 0x4C,                               //jne         end
	0x8B, 0x86, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+88h]
	0x8B, 0x96, 0x8C, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [esi+8Ch]
	0x03, 0xC2,                               //add         eax,edx
	0x3D, 0xA0, 0x0F, 0x00, 0x00,             //cmp         eax,0FA0h
	0x7D, 0x37,                               //jge         end
	0x80, 0xBE, 0xE8, 0x00, 0x00, 0x00, 0x00, //cmp         byte ptr [esi+0E8h],0
	0x74, 0x2E,                               //je          end
	0x8B, 0x86, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0CCh]
	0x39, 0x05, 0x64, 0xFA, 0x43, 0x00,       //cmp         [no_soldier_building_force],eax
	0x74, 0x20,                               //je          end
	0xA3, 0x64, 0xFA, 0x43, 0x00,             //mov         [no_soldier_building_force],eax
	0x89, 0x35, 0x68, 0xFA, 0x43, 0x00,       //mov         [no_soldier_building],esi
	0x33, 0xD2,                               //xor         edx,edx
	0x89, 0x54, 0x24, 0x08,                   //mov         dword ptr [esp+8],edx
	0x8B, 0x4E, 0x44,                         //mov         ecx,dword ptr [esi+44h]
	0x39, 0x81, 0xCC, 0x00, 0x00, 0x00,       //cmp         [ecx+0CCh],eax
	0x75, 0x0B,                               //jne         get_near_city
	                                          //update_city_person:
	0xC6, 0x41, 0x0C, 0xC8,                   //mov         byte ptr[ecx+0Ch],0C8h
	                                          //end:
	0x59,                                     //pop         ecx
	0x68, 0x30, 0xDA, 0x4F, 0x00,             //push        4FDA30h
	0xC3,                                     //ret
	                                          //get_near_city:
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0xBF, 0x58, 0xDB, 0x24, 0x01,             //mov         edi,124DB58h
	0xBB, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         ebx,7FFFFFFFh
	                                          //loop_city:
	0x8B, 0x87, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edi+0CCh]
	0x39, 0x86, 0xCC, 0x00, 0x00, 0x00,       //cmp         dword ptr [esi+0CCh],eax
	0x75, 0x12,                               //jne         next_city
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7D, 0x04,                               //jge         next_city
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0xEF,                               //mov         ebp,edi
	                                          //next_city:
	0x81, 0xC7, 0xF0, 0x01, 0x00, 0x00,       //add         edi,1F0h
	0x81, 0xFF, 0x38, 0x3C, 0x25, 0x01,       //cmp         edi, 1253C38h
	0x7C, 0xD2,                               //jl          loop_city
	0x8B, 0xCD,                               //mov         ecx,ebp
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0xEB, 0xB3                                //jmp         update_city_person
};

BYTE codeCheckNoSoldierBuildingThunk[] = {0xE8, 0xCE, 0x6E, 0xBF, 0xFF};//dwAddrCheckNoSoldierBuilding - 4A9C2Dh - 5
BYTE codeCheckNoSoldierBuildingOldThunk[] = {0xE8, 0xFE, 0x3D, 0x05, 0x00};//call 4FDA30h
ASM_PATCH patchCheckNoSoldierBuildingThunk[] = {
	{0x4A9C2D, sizeof(codeCheckNoSoldierBuildingThunk), codeCheckNoSoldierBuildingThunk},
	{0x4A9C2D, sizeof(codeCheckNoSoldierBuildingOldThunk), codeCheckNoSoldierBuildingOldThunk}};

/////////////////////////////////////////////
#define PATCH_MIN_BUILDING_PERSON_NUM 3

DWORD dwAddrMinBuildingPerson[PATCH_MIN_BUILDING_PERSON_NUM] = {0x4B0725, 0x4B0CD3, 0x4B0DC3};
DWORD dwSizeMinBuildingPerson[PATCH_MIN_BUILDING_PERSON_NUM] = {0xB, 0xD, 0xD};
BYTE codeMinBuildingPerson[PATCH_MIN_BUILDING_PERSON_NUM][PATCH_SIZE] = {
	{0x8B, 0x96, 0x88, 0x00, 0x00, 0x00,      //mov         edx,dword ptr [esi+88h]
	0xE9, 0xA3, 0x05, 0x00, 0x00},
	//1:6+5
	{0x8B, 0x8E, 0x8C, 0x00, 0x00, 0x00,      //mov         ecx,dword ptr [esi+8Ch]
	0x03, 0xD1,                               //add         edx,ecx
	0xE9, 0xE3, 0x00, 0x00, 0x00},
	//2:8+5
	{0x81, 0xFA, 0x88, 0x13, 0x00, 0x00,      //cmp         edx,1388h
	0x0F, 0x8D, 0x01, 0xE5, 0xFF, 0xFF,       //jge         4AF2D0h
	0xC3}                                     //ret
	//3:D
};
ASM_PATCH patchMinBuildingPerson[PATCH_MIN_BUILDING_PERSON_NUM] = {{0, 0, 0}};

BYTE codeMinBuildingPersonThunk[] = {0xE8, 0x6F, 0x6B, 0x00, 0x00};//4B0725h - 4A9BB1h - 5
BYTE codeMinBuildingPersonOldThunk[] = {0xE8, 0x1A, 0x57, 0x00, 0x00};//call 4AF2D0h
ASM_PATCH patchMinBuildingPersonThunk[] = {
	{0x4A9BB1, sizeof(codeMinBuildingPersonThunk), codeMinBuildingPersonThunk},
	{0x4A9BB1, sizeof(codeMinBuildingPersonOldThunk), codeMinBuildingPersonOldThunk}};

//force troop list
DWORD dwAddrForceTroopList = dwAddrStackBottom + 0xC00;
BYTE codeForceTroopList[] = {
	0xB8, 0x80, 0xF1, 0x43, 0x00,             //mov         eax,43F180h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x54, 0x24, 0x38,                   //mov         edx,dword ptr [esp+38h]
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x01,                               //jne         create_troop_list
	0xC3,                                     //ret
	                                          //create_troop_list:
	0x50,                                     //push        eax
	0x55,                                     //push        ebp
	0xBD, 0xB0, 0x93, 0x4B, 0x01,             //mov         ebp,14B93B0h
	                                          //loop_troop:
	0xF6, 0x45, 0x20, 0x02,                   //test        byte ptr [ebp+20h],2
	0x75, 0x12,                               //jne         next_troop
	0x39, 0x75, 0x74,                         //cmp         dword ptr [ebp+74h],esi
	0x75, 0x0D,                               //jne         next_troop
	0x55,                                     //push        ebp
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_troop:
	0x81, 0xC5, 0x04, 0x01, 0x00, 0x00,       //add         ebp,104h
	0x66, 0x81, 0x7D, 0x04, 0x51, 0x03,       //cmp         word ptr[ebp+4],351h
	0x7C, 0xDA,                               //jl          loop_troop
	0x5D,                                     //pop         ebp
	0x58,                                     //pop         eax
	0xC3                                      //ret
};

BYTE codeForceTroopListThunk[] = {0xE8, 0xD3, 0x70, 0xBF, 0xFF};//dwAddrForceTroopList - 4A9B28h - 5
BYTE codeForceTroopListOldThunk[] = {0xE8, 0x53, 0x56, 0xF9, 0xFF};//call 43F180h
ASM_PATCH patchForceTroopListThunk[] = {
	{0x4A9B28, sizeof(codeForceTroopListThunk), codeForceTroopListThunk},
	{0x4A9B28, sizeof(codeForceTroopListOldThunk), codeForceTroopListOldThunk}};

//building total soldier
DWORD dwAddrBuildingTotalSoldier = dwAddrStackBottom + 0x1E00;
BYTE codeBuildingTotalSoldier[] = {
	0x57,                                     //push        edi
	0x8B, 0x3D, 0x24, 0x05, 0x0A, 0x00,       //mov         edi,[attack_troop+4]
	                                          //loop_troop:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x2A,                               //je          end_troop
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x80, 0x79, 0x58, 0x33,                   //cmp         byte ptr [ecx+58h],33h
	0x75, 0x10,                               //jne         check_owner_building
	0xF6, 0x41, 0x22, 0x40,                   //test        byte ptr [ecx+22h],40h
	0x75, 0x0A,                               //jne         check_owner_building
	0x8B, 0x46, 0x04,                         //mov         eax,dword ptr [esi+4]
	0x3B, 0x41, 0x50,                         //cmp         eax,dword ptr [ecx+50h]
	0x75, 0xE3,                               //jne         loop_troop
	0xEB, 0x05,                               //jmp         add_troop_soldier
	                                          //check_owner_building:
	0x39, 0x71, 0x64,                         //cmp         dword ptr [ecx+64h],esi
	0x75, 0xDC,                               //jne         loop_troop
	                                          //add_troop_soldier:
	0x8B, 0x41, 0x30,                         //mov         eax,dword ptr [ecx+30h]
	0x03, 0x41, 0x34,                         //add         eax,dword ptr [ecx+34h]
	0x03, 0xE8,                               //add         ebp,eax
	0xEB, 0xD2,                               //jmp         loop_troop
	                                          //end_troop:
	0x0F, 0xAF, 0x6C, 0x24, 0x20,             //imul        ebp,dword ptr [esp+20h]
	0x83, 0x7C, 0x24, 0x40, 0x00,             //cmp         dword ptr [esp+40h],0
	0x75, 0x0C,                               //jne         test_attacked
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	                                          //test_attacked:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x0F, 0xB6, 0x88, 0x00, 0x0D, 0x0A, 0x00, //movzx       ecx,byte ptr [eax+building_attacked_coef]
	0xC1, 0xE1, 0x0B,                         //shl         ecx,0Bh
	0x3B, 0x8E, 0x88, 0x00, 0x00, 0x00,       //cmp         ecx,dword ptr [esi+88h]
	0x7E, 0x27,                               //jle         end
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x19, 0x0A, 0x00,             //mov         eax,get_building_backup
	0xFF, 0xD0,                               //call        eax
	0x03, 0x86, 0x88, 0x00, 0x00, 0x00,       //add         eax,dword ptr [esi+88h]
	0x3D, 0x50, 0x46, 0x00, 0x00,             //cmp         eax,4650h
	0x7C, 0x11,                               //jl          end
	0x8B, 0xC3,								  //mov         eax,ebx
	0x99,                                     //cdq
	0xB9, 0x0A, 0x00, 0x00, 0x00,             //mov         ecx,0Ah
	0xF7, 0xF1,                               //div         eax,ecx
	0x0F, 0xAF, 0x44, 0x24, 0x20,			  //imul        eax,[esp+20h]
	0x03, 0xE8,                               //add         ebp,eax
	                                          //end:
	0x5F,                                     //pop         edi
	0xC3                                      //ret
};

BYTE codeBuildingTotalSoldierThunk[] = {0xE8, 0x13, 0x82, 0xBF, 0xFF};//dwAddrBuildingTotalSoldier - 4A9BE8h - 5
BYTE codeBuildingTotalSoldierOldThunk[] = {0x0F, 0xAF, 0x6C, 0x24, 0x18};//imul ebp,[esp+18h]
ASM_PATCH patchBuildingTotalSoldierThunk[] = {
	{0x4A9BE8, sizeof(codeBuildingTotalSoldierThunk), codeBuildingTotalSoldierThunk},
	{0x4A9BE8, sizeof(codeBuildingTotalSoldierOldThunk), codeBuildingTotalSoldierOldThunk}};

/////////////////////////////////////////////
#define PATCH_SAME_FORCE_DISPATCH_NUM 3

DWORD dwAddrSameForceDispatch[PATCH_SAME_FORCE_DISPATCH_NUM] = {0x4B7C52, 0x4B7713, 0x4B76A2};
DWORD dwSizeSameForceDispatch[PATCH_SAME_FORCE_DISPATCH_NUM] = {0xD, 0xD, 0xE};
BYTE codeSameForceDispatch[PATCH_SAME_FORCE_DISPATCH_NUM][PATCH_SIZE] = {
	{0x8B, 0x91, 0xCC, 0x00, 0x00, 0x00,      //mov         edx,dword ptr [ecx+0CCh]
	0x85, 0xD2,                               //test        edx,edx
	0xE9, 0xB4, 0xFA, 0xFF, 0xFF},
	//1:8+5
	{0x74, 0x96,                              //je          differ_force
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr[edx+34h],1
	0x75, 0x90,                               //jne         differ_force
	0x50,                                     //push        eax
	0x8B, 0xCA,                               //mov         ecx,edx
	0xEB, 0x82},
	//2:B+2
	{0xB8, 0x10, 0x18, 0x44, 0x00,            //mov         eax,441810h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,                               //jmp         end
	                                          //differ_force:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC2, 0x04, 0x00}                         //ret         4
	//3:E
};
ASM_PATCH patchSameForceDispatch[PATCH_SAME_FORCE_DISPATCH_NUM] = {{0, 0, 0}};

BYTE codeSameForceDispatchThunk[] = {0xE8, 0x9E, 0x44, 0x01, 0x00};//4B7C52h - 4A37AFh - 5
BYTE codeSameForceDispatchOldThunk[] = {0xE8, 0x5C, 0xAA, 0xFB, 0xFF};//call 45E210h
ASM_PATCH patchSameForceDispatchThunk[] = {
	{0x4A37AF, sizeof(codeSameForceDispatchThunk), codeSameForceDispatchThunk},
	{0x4A37AF, sizeof(codeSameForceDispatchOldThunk), codeSameForceDispatchOldThunk}};

//relay failed dispatch
DWORD dwAddrRelayFailedDispatch = dwAddrStackBottom + 0x300;
BYTE codeRelayFailedDispatch[] = {
	0xB8, 0x90, 0xC9, 0x46, 0x00,             //mov         eax,46C990h
	0xFF, 0xD0,                               //call        eax
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0xA1, 0xE4, 0xFB, 0x43, 0x00,             //mov         eax,[relay_city]
	0x3B, 0xD8,                               //cmp         ebx,eax
	0x74, 0x17,                               //je          search_relay_city_again
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x10,                               //jne         end
	0x8B, 0xCB,                               //mov         ecx,ebx
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x80, 0xB8, 0x00, 0x0E, 0x0A, 0x00, 0x00, //cmp         byte ptr [eax+relay_wait_time],0
	0x74, 0x0B,                               //je          search_relay_city
	                                          //end:
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //search_relay_city_again:
	0x8B, 0x1D, 0xE8, 0xFB, 0x43, 0x00,       //mov         ebx,[relay_building]
	0xEB, 0x32,                               //jmp         ready_near_city
	                                          //search_relay_city:
	0x53,                                     //push        ebx
	0x54,                                     //push        esp
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x90, 0x11, 0x4A, 0x00,             //mov         eax,4A1190h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF0,                               //mov         esi,eax
	0xB8, 0xA0, 0x12, 0x4A, 0x00,             //mov         eax,4A12A0h
	0xFF, 0xD0,                               //call        eax
	0x2B, 0xF0,                               //sub         esi,eax

	0x3D, 0x20, 0x4E, 0x00, 0x00,             //cmp         eax,4E20h
	0x7D, 0x05,                               //jge         get_max_soldier_margin
	0xB8, 0x20, 0x4E, 0x00, 0x00,             //mov         eax,4E20h
	                                          //get_max_soldier_margin:
	0x6B, 0xC0, 0x0B,						  //imul        eax,0Bh
	0xC1, 0xE8, 0x04,						  //shr         eax,4
	0x3B, 0xF0,                               //cmp         esi,eax
	0x7F, 0xC9,                               //jg          end

	0x89, 0x35, 0xEC, 0xFB, 0x43, 0x00,       //mov         [building_soldier_margin],esi
	                                          //ready_near_city:
	0x8B, 0x4B, 0x44,                         //mov         ecx,dword ptr [ebx+44h]
	0x0F, 0xB6, 0x41, 0x04,                   //movzx       eax,byte ptr [ecx+4]
	0xC1, 0xE0, 0x03,                         //shl         eax,3
	0x05, 0x00, 0x6E, 0x0A, 0x00,             //add         eax,city_relation_table
	0x8B, 0xF0,                               //mov         esi,eax
	0xBF, 0x08, 0x00, 0x00, 0x00,             //mov         edi,8
	0xA1, 0xE4, 0xFB, 0x43, 0x00,             //mov         eax,[relay_city]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x11,                               //je          loop_near_city
	0x8A, 0x50, 0x04,                         //mov         dl,[eax+4]
	                                          //loop_skip_relay_city:
	0x38, 0x16,                               //cmp         byte ptr [esi],dl
	0x74, 0x06,                               //je          end_skip_relay_city
	0x46,                                     //inc         esi
	0x4F,                                     //dec         edi
	0x75, 0xF8,                               //jne         loop_skip_relay_city
	0xEB, 0x66,                               //jmp         search_fail:
	                                          //end_skip_relay_city:
	0x46,                                     //inc         esi
	0x4F,                                     //dec         edi
	0x74, 0x62,                               //je          search_fail:
	                                          //loop_near_city:
	0x0F, 0xB6, 0x06,                         //movzx       eax,byte ptr[esi]
	0x50,                                     //push        eax
	0xB8, 0x70, 0x2F, 0x45, 0x00,             //mov         eax,452F70h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x4C,                               //je          next_near_city
	0x8B, 0x90, 0xCC, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [eax+0CCh]
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x42,                               //je          next_near_city
	0x8B, 0x8A, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edx+0B8h]
	0x3B, 0x4D, 0x38,                         //cmp         ecx,dword ptr [ebp+38h]
	0x75, 0x37,                               //jne         next_near_city
	0x83, 0xB8, 0xE8, 0x00, 0x00, 0x00, 0x00, //cmp         dword ptr [eax+0E8h],0
	0x7E, 0x2E,                               //jle         next_near_city
	0x50,                                     //push        eax
	0x54,                                     //push        esp
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x70, 0x12, 0x4A, 0x00,             //mov         eax,4A1270h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x1E,                               //jg          next_near_city
	0x56,                                     //push        esi
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x54,                                     //push        esp
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x90, 0x11, 0x4A, 0x00,             //mov         eax,4A1190h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF0,                               //mov         esi,eax
	0xB8, 0xA0, 0x12, 0x4A, 0x00,             //mov         eax,4A12A0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0xD6,                               //mov         edx,esi
	0x3B, 0xF0,                               //cmp         esi,eax
	0x5E,                                     //pop         esi
	0x7E, 0x0A,                               //jle         got_relay_city
	                                          //next_near_city:
	0x83, 0xC6, 0x01,                         //add         esi,1
	0x4F,                                     //dec         edi
	0x75, 0x9E,                               //jne         loop_near_city
	                                          //search_fail:
	0x33, 0xF6,                               //xor         esi,esi
	0xEB, 0x3E,                               //jmp         end2
	                                          //got_relay_city:
	0x8B, 0xF1,                               //mov         esi,ecx
	0x81, 0xC2, 0x40, 0x1F, 0x00, 0x00,       //add         edx,1F40h
	0x3B, 0xD0,                               //cmp         edx,eax
	0xEB, 0x02,                               //jmp         check_min
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //check_min:
	0x3D, 0x10, 0x27, 0x00, 0x00,             //cmp         eax,2710h
	0x7D, 0x05,                               //jge         get_new_soldier
	0xB8, 0x10, 0x27, 0x00, 0x00,             //mov         eax,2710h
	                                          //get_new_soldier:
	0x03, 0x05, 0xEC, 0xFB, 0x43, 0x00,       //add         eax,[building_soldier_margin]
	0x05, 0x88, 0x13, 0x00, 0x00,             //add         eax,1388h
	0x51,                                     //push        ecx
	0x8B, 0xD4,                               //mov         edx,esp
	0x50,                                     //push        eax
	0x52,                                     //push        edx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x60, 0x11, 0x4A, 0x00,             //mov         eax,4A1160h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x30,                   //lea         ecx,[esp+30h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //end2:
	0x89, 0x35, 0xE4, 0xFB, 0x43, 0x00,       //mov         [relay_city],esi
	0x89, 0x1D, 0xE8, 0xFB, 0x43, 0x00,       //mov         [relay_building],ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeRelayFailedDispatchThunk[] = {0xE8, 0x5D, 0xC8, 0xBF, 0xFF};//dwAddrRelayFailedDispatch - 4A3A9Eh - 5
BYTE codeRelayFailedDispatchOldThunk[] = {0xE8, 0xED, 0x8E, 0xFC, 0xFF};//call 46C990h
ASM_PATCH patchRelayFailedDispatchThunk[] = {
	{0x4A3A9E, sizeof(codeRelayFailedDispatchThunk), codeRelayFailedDispatchThunk},
	{0x4A3A9E, sizeof(codeRelayFailedDispatchOldThunk), codeRelayFailedDispatchOldThunk}};

//relay wait time[0C0h]
DWORD dwAddrRelayWaitTime = dwAddrStackBottom + 0xE00;

//relay dispatch success
DWORD dwAddrRelayDispatchOk = dwAddrRelayWaitTime + 0xC0;
BYTE codeRelayDispatchOk[] = {
	0xB8, 0xE0, 0x11, 0x4A, 0x00,             //mov         eax,4A11E0h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0x1D, 0xE4, 0xFB, 0x43, 0x00,       //cmp         ebx,[relay_city]
	0x75, 0x17,                               //jne         end
	0xA1, 0xE8, 0xFB, 0x43, 0x00,             //mov         eax,[relay_building]
	0x0F, 0xB6, 0x50, 0x04,                   //movzx       edx,byte ptr [eax+4]
	0xC6, 0x82, 0x00, 0x0E, 0x0A, 0x00, 0x02, //mov         byte ptr [edx+relay_wait_time],2
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0xE4, 0xFB, 0x43, 0x00,             //mov         [relay_city],eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeRelayDispatchOkThunk[] = {0xE8, 0xA9, 0xD7, 0xBF, 0xFF};//dwAddrRelayDispatchOkh - 4A3712h - 5
BYTE codeRelayDispatchOkOldThunk[] = {0xE8, 0xC9, 0xDA, 0xFF, 0xFF};//call 4A11E0h
ASM_PATCH patchRelayDispatchOkThunk[] = {
	{0x4A3712, sizeof(codeRelayDispatchOkThunk), codeRelayDispatchOkThunk},
	{0x4A3712, sizeof(codeRelayDispatchOkOldThunk), codeRelayDispatchOkOldThunk}};

//fast relay
DWORD dwAddrFastRelay = dwAddrStackBottom + 0x450;
BYTE codeFastRelay[] = {
	0x80, 0x7E, 0x06, 0x05,                   //cmp         byte ptr [esi+6],5
	0x74, 0x4D,                               //je          get_city_remain_soldier
	0x8B, 0x4C, 0x24, 0x18,                   //mov         ecx,dword ptr [esp+18h]
	0x8B, 0x49, 0x38,                         //mov         ecx,dword ptr [ecx+38h]
	0x8D, 0x49, 0x78,                         //lea         ecx,[ecx+78h]
	0x83, 0x79, 0x0C, 0x01,                   //cmp         dword ptr [ecx+0Ch],1
	0x75, 0x0F,                               //jne         normal
	0x8B, 0x41, 0x04,                         //mov         eax,dword ptr [ecx+4]
	0x3B, 0x58, 0x08,                         //cmp         ebx,dword ptr [eax+8]
	0x75, 0x07,                               //jne         normal
	0xBD, 0x01, 0x00, 0x00, 0x00,             //mov         ebp,1
	0xEB, 0x21,                               //jmp         check_building_soldier
	                                          //normal:
	0x81, 0xFD, 0x87, 0x13, 0x00, 0x00,       //cmp         ebp,1387h
	0x7D, 0x19,                               //jge         check_building_soldier
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x3D, 0x0A, 0x00,             //mov         eax,test_regarded_building
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x7C, 0x07,                               //jl          building_one_soldier
	0xBD, 0x87, 0x13, 0x00, 0x00,             //mov         ebp,1387h
	0xEB, 0x05,                               //jmp         check_building_soldier
	                                          //building_one_soldier:
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0x01,                               //jne         check_building_soldier
	0x45,                                     //inc         ebp
	                                          //check_building_soldier:
	0x8B, 0x86, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+88h]
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7D, 0x02,                               //jge         got_building_soldier
	0x8B, 0xC5,                               //mov         eax,ebp
	                                          //got_building_soldier:
	0xC3,                                     //ret
	                                          //get_city_remain_soldier:
	0x33, 0xED,                               //xor         ebp,ebp
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x19, 0x0A, 0x00,             //mov         eax,get_building_backup
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xBE, 0x88, 0x00, 0x00, 0x00,       //mov         edi,dword ptr [esi+88h]
	0x03, 0xC7,                               //add         eax,edi
	0x2D, 0x10, 0x27, 0x00, 0x00,             //sub         eax,2710h
	0x50,                                     //push        eax
	0x4F,                                     //dec         edi
	0x8B, 0x4C, 0x24, 0x1C,                   //mov         ecx,dword ptr [esp+1Ch]
	0x56,                                     //push        esi
	0x54,                                     //push        esp
	0xB8, 0x90, 0x11, 0x4A, 0x00,             //mov         eax,4A1190h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x2B, 0xF8,                               //sub         edi,eax
	0x58,                                     //pop         eax
	0x3B, 0xC7,                               //cmp         eax,edi
	0x7E, 0x02,                               //jle         check_negtive
	0x8B, 0xC7,                               //mov         eax,edi
	                                          //check_negtive:
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         end
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeFastRelayThunk[] = {0xE8, 0xE8, 0xCB, 0xBF, 0xFF, 0x42};//dwAddrFastRelay - 4A3863h - 5
BYTE codeFastRelayOldThunk[] = {0xFF, 0x92, 0x80, 0x00, 0x00, 0x00};//call [edx+80h]
ASM_PATCH patchFastRelayThunk[] = {
	{0x4A3863, sizeof(codeFastRelayThunk), codeFastRelayThunk},
	{0x4A3863, sizeof(codeFastRelayOldThunk), codeFastRelayOldThunk}};

/////////////////////////////////////////////
#define PATCH_TROOP_SIEGE_POWER_NUM 3

DWORD dwAddrTroopSiegePower[PATCH_TROOP_SIEGE_POWER_NUM] = {0x46C4F4, 0x46C575, 0x46C4D2};
DWORD dwSizeTroopSiegePower[PATCH_TROOP_SIEGE_POWER_NUM] = {0xB, 0xB, 0xE};
BYTE codeTroopSiegePower[PATCH_TROOP_SIEGE_POWER_NUM][PATCH_SIZE] = {
	{0x51,                                    //push        ecx
	0x8B, 0x51, 0x04,                         //mov         edx,dword ptr [ecx+4]
	                                          //loop_troop:
	0x8B, 0x4A, 0x08,                         //mov         ecx,dword ptr [edx+8]
	0x8B, 0x12,                               //mov         edx,dword ptr [edx]
	0xEB, 0x76},
	//1:9+2
	{0x8B, 0x41, 0x08,                        //mov         eax,dword ptr [ecx+8]
	0x6B, 0xC0, 0x19,                         //imul        eax,eax,19h
	0xE9, 0x52, 0xFF, 0xFF, 0xFF},
	//2:6+5
	{0x89, 0x41, 0x08,                        //mov         dword ptr [ecx+8],eax
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x1F,                               //jne         loop_troop
	0x59,                                     //pop         ecx
	0x68, 0x10, 0xF6, 0x46, 0x00,             //push        46F610h
	0xC3}                                     //ret
	//3:E
};
ASM_PATCH patchTroopSiegePower[PATCH_TROOP_SIEGE_POWER_NUM] = {{0, 0, 0}};

BYTE codeTroopSiegePowerThunk[] = {0xE8, 0x20, 0x9E, 0xFC, 0xFF};//46C4F4h - 4A26CFh - 5
BYTE codeTroopSiegePowerOldThunk[] = {0xE8, 0x3C, 0xCF, 0xFC, 0xFF};//call 46F610h()
ASM_PATCH patchTroopSiegePowerThunk[] = {
	{0x4A26CF, sizeof(codeTroopSiegePowerThunk), codeTroopSiegePowerThunk},
	{0x4A26CF, sizeof(codeTroopSiegePowerOldThunk), codeTroopSiegePowerOldThunk}};

//battle disable task
DWORD dwAddrBattleDisableTask = dwAddrStackBottom + 0xF00;
BYTE codeBattleDisableTask[] = {
	0x8B, 0x47, 0x34,                         //mov         eax,dword ptr [edi+34h]
	0x3C, 0x17,                               //cmp         al,17h
	0x74, 0x0C,                               //je          test_attacked
	0x3C, 0x18,                               //cmp         al,18h
	0x74, 0x08,                               //je          test_attacked
	0x3C, 0x1D,                               //cmp         al,1Dh
	0x7C, 0x09,                               //jl          end
	0x3C, 0x1F,                               //cmp         al,1Fh
	0x7F, 0x05,                               //jg          end
	                                          //test_attacked:
	0xE8, 0x01, 0x00, 0x00, 0x00,             //call        test_building_attacked
	                                          //end:
	0xC3,                                     //ret
	                                          //test_building_attacked:
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x6F, 0x48,                         //mov         ebp,[edi+48h]
	0x85, 0xED,                               //test        ebp,ebp
	0x74, 0x2C,                               //je          end_person_list
	                                          //loop_person_list:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0x39, 0x99, 0xF4, 0x00, 0x00, 0x00,       //cmp         dword ptr [ecx+0F4h],ebx
	0x74, 0x1A,                               //je          next_person
	                                          //new_building_person:
	0x8B, 0x99, 0xF4, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [ecx+0F4h]
	0x8B, 0x4B, 0x64,                         //mov         ecx,dword ptr [ebx+64h]
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x0F, 0xB6, 0x90, 0x00, 0x0D, 0x0A, 0x00, //movzx       edx,byte ptr [eax+building_attacked_coef]
	0x83, 0xFA, 0x0A,                         //cmp         edx,0Ah
	0x7D, 0x0A,                               //jge         delete_building_person
	                                          //next_person:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xD4,                               //jne         loop_person_list
	                                          //end_person_list:
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0xC3,                                     //ret
	                                          //delete_building_person:
	0x55,                                     //push        ebp
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x8D, 0x4F, 0x44,                         //lea         ecx,[edi+44h]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xED,                               //test        ebp,ebp
	0x74, 0xEB,                               //je          end_person_list
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0x39, 0x99, 0xF4, 0x00, 0x00, 0x00,       //cmp         dword ptr [ecx+0F4h],ebx
	0x74, 0xE3,                               //je          delete_building_person
	0xEB, 0xBD                                //jmp         new_building_person
};

BYTE codeBattleDisableTaskThunk[] = {0xE8, 0x82, 0x0B, 0xBF, 0xFF, 0x42, 0x42};//dwAddrBattleDisableTask - 4B0379h - 5
BYTE codeBattleDisableTaskOldThunk[] = {0x8D, 0xA4, 0x24, 0x00, 0x00, 0x00, 0x00};//lea esp,[esp]
ASM_PATCH patchBattleDisableTaskThunk[] = {
	{0x4B0379, sizeof(codeBattleDisableTaskThunk), codeBattleDisableTaskThunk},
	{0x4B0379, sizeof(codeBattleDisableTaskOldThunk), codeBattleDisableTaskOldThunk}};

/////////////////////////////////////////////
#define PATCH_BATTLE_DISABLE_GOSSIP_NUM 2

DWORD dwAddrBattleDisableGossip[PATCH_BATTLE_DISABLE_GOSSIP_NUM] = {0x4922E5, 0x4922F5};
DWORD dwSizeBattleDisableGossip[PATCH_BATTLE_DISABLE_GOSSIP_NUM] = {0xA, 0xB};
BYTE codeBattleDisableGossip[PATCH_BATTLE_DISABLE_GOSSIP_NUM][PATCH_SIZE] = {
	{0x57,                                    //push        edi
	0x8B, 0xFE,                               //mov         edi,esi
	0xB8, 0x19, 0x0F, 0x0A, 0x00,             //mov         eax,test_building_attacked
	0xEB, 0x06},
	//1:8+2
	{0xFF, 0xD0,                              //call        eax
	0x5F,                                     //pop         edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0x68, 0x80, 0xF4, 0x4A, 0x00,             //push        4AF480h
	0xC3}                                     //ret
	//2:B
};
ASM_PATCH patchBattleDisableGossip[PATCH_BATTLE_DISABLE_GOSSIP_NUM] = {{0, 0, 0}};

BYTE codeBattleDisableGossipThunk[] = {0xE8, 0x49, 0x05, 0xFE, 0xFF};//4922E5h - 4B1D97h - 5
BYTE codeBattleDisableGossipOldThunk[] = {0xE8, 0xE4, 0xD6, 0xFF, 0xFF};//call 4AF480h()
ASM_PATCH patchBattleDisableGossipThunk[] = {
	{0x4B1D97, sizeof(codeBattleDisableGossipThunk), codeBattleDisableGossipThunk},
	{0x4B1D97, sizeof(codeBattleDisableGossipOldThunk), codeBattleDisableGossipOldThunk}};

//check attack troop
DWORD dwAddrCheckAttackTroop = dwAddrStackBottom + 0xF80;
BYTE codeCheckAttackTroop[] = {
	                                          //check_attack_troop:
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x8B, 0x11,                               //mov         edx,dword ptr [ecx]
	0x83, 0x7A, 0x24, 0x00,                   //cmp         dword ptr[edx+24h],0
	0x74, 0x5C,                               //je          not_attack_troop
	0xF6, 0x42, 0x20, 0x03,                   //test        byte ptr [edx+20h],3
	0x75, 0x56,                               //jne         not_attack_troop
	0x8B, 0x49, 0x0C,                         //mov         ecx,dword ptr [ecx+0Ch]
	0x8B, 0x41, 0x04,                         //mov         eax,dword ptr [ecx+4]
	0x83, 0x7A, 0x54, 0xFF,                   //cmp         dword ptr [edx+54h],-1
	0x75, 0x12,                               //jne         check_current_goal
	0x39, 0x42, 0x50,                         //cmp         dword ptr [edx+50h],eax
	0x0F, 0x85, 0x59, 0xF6, 0xFF, 0xFF,       //jne         check_menace_troop
	0x80, 0x7A, 0x58, 0x26,                   //cmp         byte ptr [edx+58h],26h
	0x75, 0x3B,                               //jne         not_attack_troop
	                                          //attack_troop:
	0xB0, 0x01,                               //mov         al,1
	0xC3,                                     //ret
	                                          //check_current_goal:
	0x39, 0x42, 0x54,                         //cmp         dword ptr [edx+54h],eax
	0x74, 0xF8,                               //je          attack_troop
	0x39, 0x42, 0x50,                         //cmp         dword ptr [edx+50h],eax
	0x75, 0x2E,                               //jne         not_attack_troop
	0x8A, 0x42, 0x56,                         //mov         al,byte ptr [edx+56h]
	0x3C, 0x03,                               //cmp         al,3
	0x75, 0x27,                               //jne         not_attack_troop
	0x0F, 0xB7, 0x42, 0x54,                   //movzx       eax,word ptr [edx+54h]
	0x69, 0xC0, 0x04, 0x01, 0x00, 0x00,       //imul        eax,eax,104h
	0x05, 0xB0, 0x93, 0x4B, 0x01,             //add         eax,14B93B0h
	0x8B, 0x40, 0x74,                         //mov         eax,dword ptr [eax+74h]
	0x39, 0x81, 0xCC, 0x00, 0x00, 0x00,       //cmp         dword ptr [ecx+CCh],eax
	0x75, 0x0D,                               //jne         not_attack_troop
	0x52,                                     //push        edx
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x28,                         //cmp         eax,28h
	0x7C, 0x02,                               //jl          end
	                                          //not_attack_troop:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeCheckAttackTroopThunk[] = {0x80, 0x0F, 0x0A, 0x00};//30F80h, arg as function 46F280h()

BYTE codeCheckAttackTroopOldThunk[] = {0xC0, 0x28, 0x4A, 0x00};//4A28C0h
ASM_PATCH patchCheckAttackTroopSaveThunk[] = {
	{0x4A3125, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4A3125, sizeof(codeCheckAttackTroopOldThunk), codeCheckAttackTroopOldThunk}};
ASM_PATCH patchCheckAttackTroopAntiThunk[] = {
	{0x4A3403, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4A3403, sizeof(codeCheckAttackTroopOldThunk), codeCheckAttackTroopOldThunk}};

BYTE codeCheckAttackTroop2OldThunk[] = {0x70, 0x07, 0x4B, 0x00};//4B0770h
ASM_PATCH patchCheckTroopRetreatThunk[] = {//49F1BEh
	{0x49F1BE, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x49F1BE, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};
ASM_PATCH patchCheckMinLeftSoldierThunk[] = {//4A3D36h
	{0x4A3D36, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4A3D36, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};
ASM_PATCH patchCheckMaxSaveSoldierThunk[] = {//4A380Ch
	{0x4A380C, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4A380C, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};
//attack
ASM_PATCH patchAttackIfCheckSoldierThunk[] = {//4B405Ch
	{0x4B405C, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4B405C, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};
ASM_PATCH patchAttackBuildingSoldierThunk[] = {//4B58E3h
	{0x4B58E3, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4B58E3, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};
ASM_PATCH patchAttackLeftSoldierThunk[] = {//4B785Dh
	{0x4B785D, sizeof(codeCheckAttackTroopThunk), codeCheckAttackTroopThunk},
	{0x4B785D, sizeof(codeCheckAttackTroop2OldThunk), codeCheckAttackTroop2OldThunk}};

//before go
DWORD dwAddrBeforeGo = dwAddrStackBottom + 0x1000;
BYTE codeBeforeGo[] = {
	0xB8, 0x10, 0xEC, 0x50, 0x00,             //mov         eax,50EC10h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0D,                               //jnz         test_player_force
	0xC6, 0x05, 0xCA, 0xF4, 0x43, 0x00, 0x01, //mov         byte ptr[decision_ready_flag],1
	0x68, 0x00, 0x2B, 0x0A, 0x00,             //push        check_go_on_attack
	0xC3,                                     //ret
	                                          //test_player_force:
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr[eax+34h],1
	0x74, 0x06,                               //jz          npc
	0x68, 0x60, 0x57, 0x0A, 0x00,             //push        player_subforce_control
	0xC3,                                     //ret
	                                          //npc:
	0x3B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //cmp         eax,[eax+0B8h]
	0x74, 0x01,                               //je          test_decision_ready_flag
	0xC3,                                     //ret
	                                          //test_decision_ready_flag:
	0xF6, 0x05, 0xCA, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[decision_ready_flag],1
	0x75, 0x01,                               //jne         ready_for_all_npc
	0xC3,                                     //ret
	                                          //ready_for_all_npc:
	////////////////////////////////////////////////////////////////////////////////////
	0x57,                                     //push        edi
	////////////////////////////////////////////////////////////////////////////////
	0xFF, 0x35, 0x9C, 0x26, 0x23, 0x01,       //push        [123269Ch]
	0xB8, 0x50, 0xAA, 0x46, 0x00,             //mov         eax,46AA50h
	0xFF, 0xD0,                               //call        eax
	0xA2, 0x14, 0xFF, 0x43, 0x00,             //mov         [quarter], al
	///////////////////////////////////////////////////////////////////////////////////////
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x64, 0xFA, 0x43, 0x00,             //mov         [no_soldier_building_force],eax
	0xA3, 0xE4, 0xFB, 0x43, 0x00,             //mov         [relay_city],eax
	0xA3, 0x08, 0xFC, 0x43, 0x00,             //mov         [reserved_attacked_building],eax
	0xA2, 0xCA, 0xF4, 0x43, 0x00,             //mov         [decision_ready_flag],al
	////////////////////////////////////////////////////////////////////////////////////////
	0xB9, 0x30, 0x00, 0x00, 0x00,             //mov         ecx,30h
	0xBF, 0x00, 0x0D, 0x0A, 0x00,             //mov         edi,building_attacked_coef
	0xF3,                                     //rep
	0xAB,                                     //stos        dword ptr [edi]
	0x56,                                     //push        esi
	0x33, 0xFF,                               //xor         edi,edi
	                                          //loop_building:
	0x57,                                     //push        edi
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x56,                               //je          next_building
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x20, 0x54, 0x43, 0x00,             //mov         eax,435420h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x47,                               //jle         next_building
	0x56,                                     //push        esi
	0x6A, 0x7F,                               //push        7Fh
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xC4,                               //mov         eax,esp
	0x6A, 0x00,                               //push        0
	0x50,                                     //push        eax
	0x68, 0x80, 0x0F, 0x0A, 0x00,             //push        check_attack_troop
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x80, 0xF2, 0x46, 0x00,             //mov         eax,46F280h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x68, 0x60, 0x45, 0x47, 0x00,             //push        474560h
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x30, 0xE8, 0x46, 0x00,             //mov         eax,46E830h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x12,                               //jle         next_building
	0xC1, 0xE8, 0x0A,                         //shr         eax,0Ah
	0x3D, 0xFF, 0x00, 0x00, 0x00,             //cmp         eax,0FFh
	0x7E, 0x02,                               //jle         save_building_attacked_coef
	0xB0, 0xFF,                               //mov         al,0FFh
	                                          //save_building_attacked_coef:
	0x88, 0x87, 0x00, 0x0D, 0x0A, 0x00,       //mov         byte ptr [edi+building_attacked_coef],al
	                                          //next_building:
	0x47,                                     //inc         edi
	0x81, 0xFF, 0xFA, 0x00, 0x00, 0x00,       //cmp         edi,0FAh
	0x7C, 0x95,                               //jl          loop_building
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x5E,                                     //pop         esi
	///////////////////////////////////////////////////////////////////////////////////////
	0xC6, 0x05, 0x15, 0xFF, 0x43, 0x00, 0x0A, //mov         byte ptr[left_day],10
	0xC6, 0x05, 0x8C, 0xF8, 0x43, 0x00, 0x70, //mov         byte ptr[anti_attack_building_id+1],70h
	//////////////////////////////////////////////////////////////////////////////////////
	0xB9, 0x00, 0x0E, 0x0A, 0x00,             //mov         ecx,[relay_wait_time]
	0xBA, 0xC0, 0x00, 0x00, 0x00,             //mov         edx,0C0h
	                                          //loop_relay_wait:
	0x8A, 0x01,                               //mov         al,[ecx]
	0x84, 0xC0,                               //test        al,al
	0x74, 0x04,                               //je          next_relay_wait
	0xFE, 0xC8,                               //dec         al
	0x88, 0x01,                               //mov         [ecx],al
	                                          //next_relay_wait:
	0x41,                                     //inc         ecx
	0x4A,                                     //dec         edx
	0x75, 0xF2,                               //jne         loop_relay_wait
	//////////////////////////////////////////////////////////////////////////////////////
	0xF6, 0x05, 0xCE, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[null_city_sub_municipal],1
	0x74, 0x78,                               //je          end_sub_municipal
	0xB9, 0x58, 0xDB, 0x24, 0x01,             //mov         ecx,124DB58h
	0xBF, 0xC8, 0x00, 0x00, 0x00,             //mov         edi,0C8h
	                                          //loop_city:
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x56,                               //jle         next_city
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr [eax+34h],4
	0x75, 0x50,                               //jne         next_city
	0xF6, 0x41, 0x7A, 0x40,                   //test        byte ptr [ecx+7Ah],40h
	0x75, 0x4A,                               //jne         next_city
	0x51,                                     //push        ecx
	0x68, 0x00, 0x05, 0x0A, 0x00,             //push        multi_search_person_list
	0xB8, 0x20, 0x6C, 0x43, 0x00,             //mov         eax,436C20h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x38,                               //jnz         next_city
	0x8B, 0xD1,								  //mov         edx,ecx
	0x81, 0xC2, 0xBC, 0x01,	0x00, 0x00,		  //add         edx,1BCh
	0x8B, 0x42, 0x08,						  //mov         eax,dword ptr [edx+8]
	0x3B, 0xC7,                               //cmp         eax,edi
	0x7C, 0x09,                               //jl          test_income
	0x6B, 0xC0, 0x7E,                         //imul        eax,eax,7Eh
	0xC1, 0xE8, 0x07,                         //shr         eax,7
	0x89, 0x42, 0x08,						  //mov         dword ptr [edx+8],eax
	                                          //test_income:
	0x8B, 0x42, 0x10,						  //mov         eax,dword ptr [edx+10h]
	0x3B, 0xC7,                               //cmp         eax,edi
	0x7C, 0x09,                               //jl          test_harvest
	0x6B, 0xC0, 0x7E,                         //imul        eax,eax,7Eh
	0xC1, 0xE8, 0x07,                         //shr         eax,7
	0x89, 0x42, 0x10,						  //mov         dword ptr [edx+10h],eax
	                                          //test_harvest:
	0x8B, 0x42, 0x14,						  //mov         eax,dword ptr [edx+14h]
	0x3B, 0xC7,                               //cmp         eax,edi
	0x7C, 0x09,                               //jl          next_city
	0x6B, 0xC0, 0x7E,                         //imul        eax,eax,7Eh
	0xC1, 0xE8, 0x07,                         //shr         eax,7
	0x89, 0x42, 0x14,						  //mov         dword ptr [edx+14h],eax
	                                          //next_city:
	0x81, 0xC1, 0xF0, 0x01, 0x00, 0x00,       //add         ecx,1F0h
	0x81, 0xF9, 0x38, 0x3C, 0x25, 0x01,       //cmp         ecx,1253C38h
	0x7C, 0x92,                               //jl          loop_city
											  //end_sub_municipal:
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	//////////////////////////////////////////////////////////////////////////////////////
	0x80, 0x3D, 0xCF, 0xF4, 0x43, 0x00,	0x00,	//cmp         byte ptr [nature_attract_coef],0
	0x0F, 0x84, 0x93, 0x00, 0x00, 0x00,			//je          end_nature_attract
	0x56,										//push        esi
	0x53,										//push        ebx
	0x55,										//push        ebp
	0xBD, 0x96, 0x00, 0x00, 0x00,				//mov         ebp,96h
	0x0F, 0xB6, 0x1D, 0xCF, 0xF4, 0x43,	0x00,	//movzx       ebx,byte ptr [nature_attract_coef]
	0x6B, 0xDB, 0x0A,							//imul        ebx,ebx,0Ah
	0xBE, 0x64, 0x8F, 0x25, 0x01,				//mov         esi,1258F64h
												//loop_person:
	0x83, 0x3E, 0x03,							//cmp         dword ptr[esi],3
	0x7F, 0x66,									//jg          next_person
	0x83, 0x3E, 0x01,							//cmp         dword ptr[esi],1
	0x7C, 0x61,									//jl          next_person
	0x8B, 0x46, 0x70,							//mov         eax,dword ptr [esi+70h]
	0x8B, 0x48, 0x74,							//mov         ecx,dword ptr [eax+74h]
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,			//mov         ecx,dword ptr [ecx+0B8h]
	0x8B, 0xB9, 0xBC, 0x00, 0x00, 0x00,			//mov         edi,dword ptr [ecx+0BCh]
	0x3B, 0x87, 0xF4, 0x00, 0x00, 0x00,			//cmp         eax,[edi+0F4h]
	0x75, 0x47,									//jne         next_person
	0x83, 0xFB, 0x64,							//cmp         ebx,64h
	0x7D, 0x17,									//jge         attract_nature
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,			//call        [5FF2DCh]
	0x0F, 0xAF, 0x46, 0xE8,						//imul        eax,dword ptr [esi-18h]
	0x33, 0xD2,									//xor         edx,edx
	0xB9, 0x64, 0x00, 0x00, 0x00,				//mov         ecx,64h
	0xF7, 0xF9,									//idiv        eax,ecx
	0x3B, 0xD3,									//cmp         edx,ebx
	0x7D, 0x2B,									//jge         next_person
												//attract_nature:
	0x8B, 0x47, 0x6C,							//mov         eax,dword ptr [edi+6Ch]
	0x8B, 0x56, 0xE8,							//mov         edx,dword ptr [esi-18h]
	0x2B, 0xC2,									//sub         eax,edx
	0x85, 0xC0,									//test        eax,eax
	0x7C, 0x10,									//jl          negtive_nature_error
	0x74, 0x1D,									//je          next_person
	0x83, 0xF8, 0x4B,							//cmp         eax,4Bh
	0x7E, 0x0E,									//jle         add_person_nature
												//sub_person_nature:
	0x4A,										//dec         edx
	0x85, 0xD2,									//test        edx,edx
	0x7D, 0x02,									//jge         skip_save_person_nature
	0x03, 0xD5,									//add         edx,ebp
												//skip_save_person_nature:
	0xEB, 0x0C,									//jmp         save_person_nature
												//negtive_nature_error:
	0x83, 0xF8, 0xB5,							//cmp         eax,0B5h
	0x7D, 0xF2,									//jge         sub_person_nature
												//add_person_nature:
	0x42,										//inc         edx
	0x3B, 0xD5,									//cmp         edx,ebp
	0x7C, 0x02,									//jl          save_person_nature
	0x2B, 0xD5,									//sub         edx,ebp
												//save_person_nature:
	0x89, 0x56, 0xE8,							//mov         dword ptr [esi-18h],edx
												//next_person:
	0x81, 0xC6, 0x28, 0x01, 0x00, 0x00,			//add         esi,128h
	0x81, 0xFE, 0xB0, 0x65, 0x29, 0x01,			//cmp         esi,12965B0h
	0x7C, 0x87,									//jl          loop_person
	0x5D,										//pop         ebp
	0x5B,										//pop         ebx
	0x5E,										//pop         esi
												//end_nature_attract:
	//////////////////////////////////////////////////////////////////////////////////////
	0xBF, 0xB0, 0x93, 0x4B, 0x01,             //mov         edi,14B93B0h
	                                          //loop_build_troop:
	0xF6, 0x47, 0x20, 0x08,                   //test        byte ptr [edi+20h],8
	0x74, 0x29,                               //je          next_build_troop
	0xF6, 0x47, 0x22, 0x10,                   //test        byte ptr [edi+22h],10h
	0x74, 0x23,                               //je          next_build_troop
	0xF6, 0x47, 0x22, 0x40,                   //test        byte ptr [edi+22h],40h
	0x74, 0x1D,                               //je          next_build_troop
	0x8B, 0x47, 0x74,                         //mov         eax,dword ptr [edi+74h]
	0xF6, 0x40, 0x34, 0x05,                   //test        byte ptr [eax+34h],5
	0x75, 0x14,                               //jne         next_build_troop
	0x8B, 0x47, 0x34,                         //mov         eax,dword ptr [edi+34h]
	0x6B, 0xC0, 0x05,                         //imul        eax,eax,5
	0x3B, 0x47, 0x30,                         //cmp         eax,dword ptr [edi+30h]
	0x7C, 0x09,                               //jl          next_build_troop
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xB0, 0x42, 0x46, 0x00,             //mov         eax,4642B0
	0xFF, 0xD0,                               //call        eax
	                                          //next_build_troop:
	0x81, 0xC7, 0x04, 0x01, 0x00, 0x00,       //add         edi,104h
	0x66, 0x81, 0x7F, 0x04, 0x51, 0x03,       //cmp         word ptr [edi+4],351h
	0x7C, 0xC3,                               //jl          loop_build_troop
	//////////////////////////////////////////////////////////////////////////////////////
	0xF6, 0x05, 0xCD, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[merge_subforce],1
	0x74, 0x4D,                               //je          end_merge_subforce
	0x33, 0xFF,                               //xor         edi,edi
	0xB9, 0x38, 0x3C, 0x25, 0x01,             //mov         ecx,1253C38h
	                                          //loop_merage_subforce:
	0x8D, 0x81, 0xB8, 0x00, 0x00, 0x00,       //lea         eax,[ecx+0B8h]
	0x83, 0x78, 0x04, 0x00,                   //cmp         dword ptr [eax+4],0
	0x74, 0x2E,                               //je          next_force
	0x8B, 0x00,                               //mov         eax,[eax]
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x74, 0x28,                               //je          next_force
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr[eax+34h],1
	0x75, 0x22,                               //jne         next_force
	0xF6, 0x40, 0x72, 0x08,                   //test        byte ptr[eax+72h],8
	0x75, 0x1C,                               //jne         next_force
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x6A, 0x01,                               //push        1
	0xB8, 0x70, 0x24, 0x44, 0x00,             //mov         eax,442470h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0xC0, 0x26, 0x23, 0x01,             //mov         ecx,12326C0h
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	                                          //next_force:
	0x81, 0xC1, 0xD4, 0x00, 0x00, 0x00,       //add         ecx,0D4h
	0x47,                                     //inc         edi
	0x83, 0xFF, 0x32,                         //cmp         edi,32h
	0x7C, 0xBA,                               //jl          loop_merage_subforce
	                                          //end_merge_subforce:
	//////////////////////////////////////////////////////////////////////////////////////
	0x5F,                                     //pop         edi
	//////////////////////////////////////////////////////////////////////////////////////
	0x68, 0x10, 0xEC, 0x50, 0x00,             //push        50EC10h
	0xC3                                      //ret
};

BYTE codeBeforeGoThunk[] = {0xE8, 0x8D, 0x1E, 0xB9, 0xFF};//dwAddrBeforeGo - 50F16Eh - 5
BYTE codeBeforeGoOldThunk[] = {0xE8, 0x9D, 0xFA, 0xFF, 0xFF};//call 50EC10h
ASM_PATCH patchBeforeGoThunk[] = {
	{0x50F16E, sizeof(codeBeforeGoThunk), codeBeforeGoThunk},
	{0x50F16E, sizeof(codeBeforeGoOldThunk), codeBeforeGoOldThunk}};

//check go on attack
DWORD dwAddrCheckGoOnAttack = dwAddrStackBottom + 0x2B00;
BYTE codeCheckGoOnAttack[] = {
	                                          //check_go_on_attack:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x33, 0xFF,                               //xor         edi,edi
	                                          //loop_building:
	0x57,                                     //push        edi
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x71,                               //je          next_building
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x20, 0x54, 0x43, 0x00,             //mov         eax,435420h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x62,                               //jle         next_building
	0x56,                                     //push        esi
	0x6A, 0x7F,                               //push        7Fh
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xC4,                               //mov         eax,esp
	0x6A, 0x00,                               //push        0
	0x50,                                     //push        eax
	0x68, 0x80, 0x0F, 0x0A, 0x00,             //push        check_attack_troop
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x80, 0xF2, 0x46, 0x00,             //mov         eax,46F280h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x68, 0x60, 0x45, 0x47, 0x00,             //push        474560h
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x30, 0xE8, 0x46, 0x00,             //mov         eax,46E830h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x2D,                               //jle         next_building
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xF0, 0x00, 0x0A, 0x00,             //mov         eax,go_on_attack
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x1F,                               //jg          next_building
	0x8B, 0x35, 0x24, 0x05, 0x0A, 0x00,       //mov         esi,[attack_troop_list+4]
	                                          //loop_attack_troop:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0xF6, 0x40, 0x34, 0x05,                   //test        byte ptr [eax+34h],5
	0x75, 0x07,                               //jne         next_attack_troop
	0xB8, 0x60, 0x5B, 0x0A, 0x00,             //mov         eax,attack_troop_retreat
	0xFF, 0xD0,                               //call        eax
	                                          //next_attack_troop:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xE7,                               //jne         loop_attack_troop
	                                          //next_building:
	0x47,                                     //inc         edi
	0x81, 0xFF, 0xFA, 0x00, 0x00, 0x00,       //cmp         edi,0FAh
	0x0F, 0x8C, 0x76, 0xFF, 0xFF, 0xFF,       //jl          loop_building
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0x68, 0x10, 0xEC, 0x50, 0x00,             //push        50EC10h
	0xC3                                      //ret
};

//do award
DWORD dwAddrDoAward = dwAddrStackBottom + 0x1500;
BYTE codeDoAward[] = {
	                                          //do_award:
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x06,                               //jnz         check_building_menu
	                                          //end:
	0x68, 0xA0, 0xD3, 0x5C, 0x00,             //push        5CD3A0h
	0xC3,                                     //ret
	                                          //check_building_menu:
	0x3D, 0x21, 0x3A, 0x51, 0x00,             //cmp         eax,513A21h
	0x75, 0xF3,                               //jne         end
	0xF6, 0x05, 0xC4, 0xF7, 0x43, 0x00, 0x01, //test        byte ptr[key_award_flag],1
	0x74, 0xEA,                               //je          end
	0xA1, 0xCC, 0xF7, 0x43, 0x00,             //mov         eax,[awardable_person_numer]
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x10,                               //jne         test_awardable
	                                          //abandon_award:
	0xB8, 0x02, 0x00, 0x00, 0x00,             //mov         eax,2
	                                          //fast_end:
	0x89, 0x41, 0x14,                         //mov         [ecx+14h],eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0xC4, 0xF7, 0x43, 0x00,             //mov         [key_award_flag],eax
	0xC3,                                     //ret
	                                          //test_awardable:
	0x7C, 0x0E,                               //jl          get_awardable_person_number
	0xB0, 0x01,                               //mov         al,1
	0xA2, 0xCB, 0xF4, 0x43, 0x00,             //mov         [simple_award_flag],al
	0xB8, 0x1F, 0x27, 0x00, 0x00,             //mov         eax,271Fh
	0xEB, 0xE5,                               //jmp         fast_end
	                                          //get_awardable_person_number:
	0x8B, 0x15, 0xC4, 0x26, 0x23, 0x01,       //mov         edx,[12326C4h]
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0xD6,                               //je          abandon_award
	0x8B, 0x42, 0x08,                         //mov         eax,dword ptr [edx+8]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x74, 0xCD,                               //je          abandon_award
	0x55,                                     //push        ebp
	0x56,                                     //push        esi
	0x8B, 0xE8,                               //mov         ebp,eax
	0xBE, 0xE0, 0x8E, 0x25, 0x01,             //mov         esi,1258EE0h
	0xBA, 0x52, 0x03, 0x00, 0x00,             //mov         edx,352h
	                                          //loop_person_list:
	0x8B, 0x86, 0x84, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+84h]
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x39,                               //jle         next_person
	0x83, 0xF8, 0x03,                         //cmp         eax,3
	0x7F, 0x34,                               //jg          next_person
	0x8B, 0x8E, 0xF4, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [esi+0F4h]
	0xF6, 0x41, 0x20, 0x01,                   //test        byte ptr [ecx+20h],1
	0x74, 0x28,                               //je          next_person
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0x39, 0xA8, 0xB8, 0x00, 0x00, 0x00,       //cmp         dword ptr [eax+0B8h],ebp
	0x75, 0x1D,                               //jne         next_person
	0x0F, 0xB6, 0x45, 0x04,                   //movzx       eax,byte ptr [ebp+4]
	0x05, 0xB6, 0x00, 0x00, 0x00,             //add         eax,0B6h
	0x0F, 0xB6, 0x04, 0x06,                   //movzx       eax,byte ptr [esi+eax]
	0x83, 0xF8, 0x64,                         //cmp         eax,64h
	0x7D, 0x0B,                               //jge         next_person
	0x66, 0xF7, 0x86, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x40,//test word ptr [esi+0E8h],4000h
	0x74, 0x09,                               //je          got_award_person
	                                          //next_person:
	0x81, 0xC6, 0x28, 0x01, 0x00, 0x00,       //add         esi,128h
	0x4A,                                     //dec         edx
	0x75, 0xB4,                               //jne         loop_person_list
	                                          //got_award_person:
	0x5E,                                     //pop         esi
	0x5D,                                     //pop         ebp
	0x33, 0xC0,                               //xor         eax,eax
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x12,                               //je          abandon_award2
	0xB0, 0x01,                               //mov         al,1
	0xA3, 0xCC, 0xF7, 0x43, 0x00,             //mov         [awardable_person_number],eax
	0xA2, 0xCB, 0xF4, 0x43, 0x00,             //mov         [simple_award_flag],al
	0x66, 0xB8, 0x1F, 0x27,                   //mov         ax,271Fh
	0xEB, 0x07,                               //jmp         fast_end2
	                                          //abandon_award2:
	0xA3, 0xCC, 0xF7, 0x43, 0x00,             //mov         [awardable_person_number],eax
	0xB0, 0x02,                               //mov         al,2
	                                          ////fast_end2:
	0x89, 0x46, 0x14,                         //mov         dword ptr [esi+14h],eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0xC4, 0xF7, 0x43, 0x00,             //mov         [key_award_flag],eax
	0xC3                                      //ret
};

//simple award
DWORD dwAddrSimpleAward = dwAddrStackBottom + 0x1800;
BYTE codeSimpleAward[] = {
	0xF6, 0x05, 0xCB, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[simple_award_flag],1
	0x75, 0x09,                               //jne         simple_award
	0xB8, 0x00, 0xFB, 0x41, 0x00,             //mov         eax,41FB00h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x49,                               //jmp         update_awardable_person_number
	                                          //simple_award:
	0x33, 0xC0,                               //xor         eax,eax
	0xA2, 0xCB, 0xF4, 0x43, 0x00,             //mov         [simple_award_flag],al
	0x51,                                     //push        ecx
	0x6A, 0x01,                               //push        1
	0x68, 0xD0, 0x1B, 0x47, 0x00,             //push        471BD0h
	0x81, 0xC1, 0xA0, 0x0E, 0x00, 0x00,       //add         ecx,0EA0h
	0xB8, 0x10, 0xF6, 0x46, 0x00,             //mov         eax,46F610h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x68, 0x80, 0x3E, 0x4D, 0x00,             //push        4D3E80h
	0x6A, 0x01,                               //push        1
	0x68, 0xEC, 0xC5, 0x66, 0x00,             //push        66C5ECh
	0x68, 0x66, 0x1F, 0x00, 0x00,             //push        1F66h
	0xFF, 0x76, 0x4C,                         //push        dword ptr [esi+4Ch]
	0x8D, 0x81, 0xA0, 0x0E, 0x00, 0x00,       //lea         eax,[ecx+0EA0h]
	0x50,                                     //push        eax
	0x8D, 0x81, 0xAC, 0x06, 0x00, 0x00,       //lea         eax,[ecx+6ACh]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x05, 0x57, 0x00,             //mov         eax,570500h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x1C,                         //add         esp,1Ch
	                                          //update_awardable_person_number:
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x10,                               //je          end
	0x8B, 0x56, 0x4C,                         //mov         edx,[esi+4Ch]
	0x2B, 0x94, 0x24, 0xC4, 0x06, 0x00, 0x00, //sub         edx,[esp+6C4h]
	0x89, 0x15, 0xCC, 0xF7, 0x43, 0x00,       //mov         [awardable_person_number],edx
	                                          //end:
	0xC3                                      //ret
};

BYTE codeSimpleAwardThunk[] = {0xE8, 0x81, 0x0E, 0xBE, 0xFF};//dwAddrSimpleAward - 4C097Ah - 5
BYTE codeSimpleAwardOldThunk[] = {0xE8, 0x81, 0xF1, 0xF5, 0xFF};//call 41FB00h()
ASM_PATCH patchSimpleAwardThunk[] = {
	{0x4C097A, sizeof(codeSimpleAwardThunk), codeSimpleAwardThunk},
	{0x4C097A, sizeof(codeSimpleAwardOldThunk), codeSimpleAwardOldThunk}};

//menu no display
DWORD dwAddrMenuNoDisplay = dwAddrStackBottom + 0xDC0;
BYTE codeMenuNoDisplay[] = {
	0x8B, 0x44, 0x24, 0x4C,                   //mov         eax,dword ptr [esp+4Ch]
	0x3D, 0x21, 0x3A, 0x51, 0x00,             //cmp         eax,513A21h
	0x75, 0x11,                               //jne         check_info_ret_addr
	0xF6, 0x05, 0xC4, 0xF7, 0x43, 0x00, 0x01, //test        byte ptr[key_award_flag],1
	0x74, 0x20,                               //je          normal
	0xB0, 0x83,                               //mov         al,83
	0xA3, 0xC8, 0xF7, 0x43, 0x00,             //mov         [key_award_counter],eax
	0xC3,                                     //ret
	                                          //check_info_ret_addr:
	0x3D, 0x7E, 0x05, 0x51, 0x00,             //cmp         eax,51057Eh
	0x75, 0x11,                               //jne         normal
	0xF6, 0x05, 0xD6, 0xFF, 0x43, 0x00, 0xFF, //test        byte ptr[info_fast_flag],0FFh
	0x74, 0x08,                               //je          normal
	0xB0, 0x83,                               //mov         al,83
	0xA3, 0xDA, 0xFF, 0x43, 0x00,             //mov         [info_fast_counter],eax
	0xC3,                                     //ret
	                                          //normal:
	0x68, 0x80, 0x7B, 0x5B, 0x00,             //push        5B7B80h
	0xC3                                      //ret
};

BYTE codeMenuNoDisplayThunk[] = {0xE8, 0x4D, 0x89, 0xAE, 0xFF};//dwAddrMenuNoDisplay - 5B846Eh - 5
BYTE codeMenuNoDisplayOldThunk[] = {0xE8, 0x0D, 0xF7, 0xFF, 0xFF};//call 5B7B80h()
ASM_PATCH patchMenuNoDisplayThunk[] = {
	{0x5B846E, sizeof(codeMenuNoDisplayThunk), codeMenuNoDisplayThunk},
	{0x5B846E, sizeof(codeMenuNoDisplayOldThunk), codeMenuNoDisplayOldThunk}};

//intelligence killer coef
DWORD dwAddrIntelligenceKillerCoef = 0x453911;
BYTE codeIntelligenceKillerCoef[] = {//8
	0xC1, 0xE0, 0x03,                         //shl         eax,3
	0x89, 0x44, 0x24, 0x40,                   //mov         dword ptr [esp+40h],eax
	0xC3                                      //ret
};

BYTE codeIntelligenceKillerCoefThunk[] = {0xE8, 0x53, 0x1D, 0xFB, 0xFF, 0x40};//453911h - 4A1BB9h - 5
BYTE codeIntelligenceKillerCoefOldThunk[] = {0xD1, 0xE0, 0x89, 0x44, 0x24, 0x3C};//shl eax,1; mov [esp+3Ch],eax
ASM_PATCH patchIntelligenceKillerCoefThunk[] = {
	{0x4A1BB9, sizeof(codeIntelligenceKillerCoefThunk), codeIntelligenceKillerCoefThunk},
	{0x4A1BB9, sizeof(codeIntelligenceKillerCoefOldThunk), codeIntelligenceKillerCoefOldThunk}};

//intelligence killer coef 2 on attack
DWORD dwAddrIntelligenceKillerCoef2 = 0x4538B6;
BYTE codeIntelligenceKillerCoef2[] = {//9
	0x59,                                     //pop         ecx
	0xC1, 0xE0, 0x03,                         //shl         eax,3
	0x6A, 0x0B,                               //push        0Bh
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0xC3                                      //ret
};

BYTE codeIntelligenceKillerCoef2Thunk[] = {0xE8, 0x0C, 0xB6, 0xF9, 0xFF};//4538B6h - 4B82A5h - 5
BYTE codeIntelligenceKillerCoef2OldThunk[] = {0xD1, 0xE0, 0x6A, 0x0B, 0x50};//shl eax,1;push 0Bh;push eax
ASM_PATCH patchIntelligenceKillerCoef2Thunk[] = {
	{0x4B82A5, sizeof(codeIntelligenceKillerCoef2Thunk), codeIntelligenceKillerCoef2Thunk},
	{0x4B82A5, sizeof(codeIntelligenceKillerCoef2OldThunk), codeIntelligenceKillerCoef2OldThunk}};

//wisdom anti black art
DWORD dwAddrWisdomAntiBlackArt = 0x487D12;
BYTE codeWisdomAntiBlackArt[] = {//E
	0xC7, 0x44, 0x24, 0x04, 0x38, 0xEB, 0x4F, 0x01,//mov         dowrd ptr [esp+4],14FEB38h
	0x68, 0x00, 0x0D, 0x46, 0x00,                  //push        460D00h
	0xC3                                           //ret
};

BYTE codeWisdomAntiBlackArtThunk[] = {0xE8, 0x11, 0x60, 0xFE, 0xFF};//487D12h - 4A1CFCh - 5
BYTE codeWisdomAntiBlackArtOldThunk[] = {0xE8, 0xFF, 0xEF, 0xFB, 0xFF};//call 460D00h
ASM_PATCH patchWisdomAntiBlackArtThunk[] = {
	{0x4A1CFC, sizeof(codeWisdomAntiBlackArtThunk), codeWisdomAntiBlackArtThunk},
	{0x4A1CFC, sizeof(codeWisdomAntiBlackArtOldThunk), codeWisdomAntiBlackArtOldThunk}};

//enable commerce
DWORD dwAddrEnableCommerce = dwAddrStackBottom + 0x2700;
BYTE codeEnableCommerce[] = {
	0x33, 0xC0,                               //xor         eax,eax
	0x80, 0x3D, 0x14, 0xFF, 0x43, 0x00, 0x01, //cmp         byte ptr[quarter], 1
	0x75, 0x01,                               //jne         update_max_income
	0xC3,                                     //ret
	                                          //update_max_income:
	0x57,                                     //push        edi
	0x8B, 0xBE, 0xCC, 0x00, 0x00, 0x00,       //mov         edi,dword ptr [esi+0CCh]
	0x83, 0x7F, 0x24, 0x01,                   //cmp         dword ptr[edi+24h],1
	0x75, 0x04,                               //jne         not_home_force
	0x33, 0xD2,                               //xor         edx,edx
	0xEB, 0x2D,                               //jmp         do_commerce
	                                          //not_home_force:
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xB0, 0xD9, 0x43, 0x00,             //mov         eax,43D9B0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x57, 0x14,                         //mov         edx,dword ptr [edi+14h]
	0x2B, 0xD0,                               //sub         edx,eax
	0x85, 0xD2,                               //test        edx,edx
	0x7E, 0x1B,                               //jle         do_commerce
	0x8B, 0x87, 0x84, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edi+84h]
	0x3C, 0x14,                               //cmp         al,14h
	0x7E, 0x02,                               //jle         get_money_coef
	0xB0, 0x14,                               //mov         al,14h
	                                          //get_money_coef:
	0x69, 0xC0, 0xDC, 0x05, 0x00, 0x00,       //imul        eax,eax,5DCh
	0x8B, 0xC8,                               //mov         ecx,eax
	0x8B, 0xC2,                               //mov         eax,edx
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xD0,                               //mov         edx,eax
	                                          //do_commerce:
	0x8B, 0x86, 0xD4, 0x01, 0x00, 0x00,       //mov         eax,dword ptr [esi+1D4h]
	0x85, 0xD2,                               //test        edx,edx
	0x7E, 0x14,                               //jle         end
	0x66, 0x83, 0xFA, 0x08,                   //cmp         dx,8
	0x7E, 0x04,                               //jle         get_random_number
	0x66, 0xBA, 0x08, 0x00,                   //mov         dx,8
	                                          //get_random_number:
	0xF7, 0xDA,                               //neg         edx
	0x83, 0xC2, 0x09,                         //add         edx,9
	0xF7, 0xEA,                               //imul        edx
	0xC1, 0xE8, 0x03,                         //shr         eax,3
	                                          //end:
	0x5F,                                     //pop         edi
	0xC3                                      //ret
};

BYTE codeEnableCommerceThunk[] = {0xE8, 0xA5, 0xF2, 0xBE, 0xFF, 0x42};//dwAddrEnableCommerce - 4B3456h - 5
BYTE codeEnableCommerceOldThunk[] = {0xFF, 0x92, 0xF4, 0x00, 0x00, 0x00};//call [edx+0F4h]
ASM_PATCH patchEnableCommerceThunk[] = {
	{0x4B3456, sizeof(codeEnableCommerceThunk), codeEnableCommerceThunk},
	{0x4B3456, sizeof(codeEnableCommerceOldThunk), codeEnableCommerceOldThunk}};

//defence horse wimble
DWORD dwAddrDefenceHorseWimble = 0x4B4CC1;
BYTE codeDefenceHorseWimble[] = {//F
	0xB8, 0x10, 0x0E, 0x47, 0x00,             //mov         eax,470E10h
	0xFF, 0xD0,                               //call        eax
	0x68, 0xB3, 0x22, 0x4A, 0x00,             //push        4A22B3h
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeDefenceHorseWimbleThunk[] = {0xE8, 0x61, 0x2A, 0x01, 0x00};//4B4CC1h - 4A225Bh - 5
BYTE codeDefenceHorseWimbleOldThunk[] = {0xE8, 0xB0, 0xEB, 0xFC, 0xFF};//call 470E10h()
ASM_PATCH patchDefenceHorseWimbleThunk[] = {
	{0x4A225B, sizeof(codeDefenceHorseWimbleThunk), codeDefenceHorseWimbleThunk},
	{0x4A225B, sizeof(codeDefenceHorseWimbleOldThunk), codeDefenceHorseWimbleOldThunk}};

//defence array
//锋矢
BYTE codeDefenceArrayArrowThunk[] = {
	0x0F, 0x8C, 0x51, 0x01, 0x00, 0x00,	0x3B, 0xD9, 
	0x0F, 0x8C, 0x49, 0x01, 0x00, 0x00,	0x3B, 0xD8, 
	0x0F, 0x8C, 0x41, 0x01, 0x00, 0x00};
BYTE codeDefenceArrayArrowOldThunk[] = {
	0x0F, 0x8C, 0xF5, 0x00, 0x00, 0x00, 0x3B, 0xD9, 
	0x0F, 0x8C, 0xED, 0x00, 0x00, 0x00,	0x3B, 0xD8, 
	0x0F, 0x8C, 0xE5, 0x00, 0x00, 0x00};
ASM_PATCH patchDefenceArrayArrowThunk[] = {
	{0x4A216D, sizeof(codeDefenceArrayArrowThunk), codeDefenceArrayArrowThunk},
	{0x4A216D, sizeof(codeDefenceArrayArrowOldThunk), codeDefenceArrayArrowOldThunk}};
//锥行
BYTE codeDefenceArrayWimbleThunk[] =    {0x7C, 0xC9, 0x3B, 0xCB, 0x7C, 0xC5, 0x3B, 0xC8, 0x7C, 0xC1};
BYTE codeDefenceArrayWimbleOldThunk[] = {0x7C, 0x19, 0x3B, 0xCB, 0x7C, 0x15, 0x3B, 0xC8, 0x7C, 0x11};
ASM_PATCH patchDefenceArrayWimbleThunk[] = {
	{0x4A22A9, sizeof(codeDefenceArrayWimbleThunk), codeDefenceArrayWimbleThunk},
	{0x4A22A9, sizeof(codeDefenceArrayWimbleOldThunk), codeDefenceArrayWimbleOldThunk}};
//鱼鳞/鹤翼
BYTE codeDefenceArrayScaleThunk[] =    {0x7C, 0xDF, 0x3B, 0xE9, 0x7C, 0xDB, 0x3B, 0xE8, 0x7C, 0xD7};
BYTE codeDefenceArrayScaleOldThunk[] = {0x7C, 0x2A, 0x3B, 0xE9, 0x7C, 0x26, 0x3B, 0xE8, 0x7C, 0x22};
ASM_PATCH patchDefenceArrayScaleThunk[] = {
	{0x4A22C6, sizeof(codeDefenceArrayScaleThunk), codeDefenceArrayScaleThunk},
	{0x4A22C6, sizeof(codeDefenceArrayScaleOldThunk), codeDefenceArrayScaleOldThunk}};

//change interface
DWORD dwAddrChangeInterface = dwAddrStackBottom + 0xBA0;
BYTE codeChangeInterface[] = {
	0x8B, 0xF1,                               //mov         esi,ecx
	0xFF, 0x76, 0x2C,                         //push        dword ptr[esi+2Ch]
	0x6A, 0x02,                               //push        MSG_CHANGE_INTERFACE
	0xB8, 0x24, 0xF8, 0x43, 0x00,             //mov         eax,SEND_MSG_ADDRESS
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x46, 0x2C,                         //mov         eax,dword ptr[esi+2Ch]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xC3                                      //ret
};

BYTE codeChangeInterfaceThunk[] = {0xE8, 0x9A, 0xF5, 0xB3, 0xFF};//dwAddrChangeInterface - 561601h - 5
BYTE codeChangeInterfaceOldThunk[] = {0x8B, 0xF1, 0x8B, 0x46, 0x2C};//mov esi,ecx; mov eax,[esi+2Ch]
ASM_PATCH patchChangeInterfaceThunk[] = {
	{0x561601, sizeof(codeChangeInterfaceThunk), codeChangeInterfaceThunk},
	{0x561601, sizeof(codeChangeInterfaceOldThunk), codeChangeInterfaceOldThunk}};

//update end
DWORD dwAddrUpdateEnd = dwAddrStackBottom + 0x15E0;
BYTE codeUpdateEnd[] = {
	0xFF, 0x74, 0x24, 0x04,               //push        dword ptr[esp+4]
	0xB8, 0xC0, 0xB1, 0x45, 0x00,         //mov         eax,45B1C0h
	0xFF, 0xD0,                           //call        eax
	0x83, 0xC4, 0x04,                     //add         esp,4
	0x50,                                 //push        eax
	0x50,                                 //push        eax
	0x6A, 0x01,                           //push        MSG_UPDATE_END
	0xB8, 0x24, 0xF8, 0x43, 0x00,         //mov         eax,SEND_MSG_ADDRESS
	0xFF, 0xD0,                           //call        eax
	0x58,                                 //pop         eax
	0xC3                                  //ret
};

BYTE codeUpdateEndPlayThunk[] = {0xE8, 0x0E, 0x0F, 0xB9, 0xFF};//dwAddrUpdateEnd - 5106CDh - 5
BYTE codeUpdateEndPlayOldThunk[] = {0xE8, 0xEE, 0xAA, 0xF4, 0xFF};//call 45B1C0h()
ASM_PATCH patchUpdateEndPlayThunk[] = {
	{0x5106CD, sizeof(codeUpdateEndPlayThunk), codeUpdateEndPlayThunk},
	{0x5106CD, sizeof(codeUpdateEndPlayOldThunk), codeUpdateEndPlayOldThunk}};

BYTE codeUpdateEndMainThunk[] = {0xE8, 0x6D, 0x12, 0xB4, 0xFF};//dwAddrUpdateEnd - 56036Eh - 5
BYTE codeUpdateEndMainOldThunk[] = {0xE8, 0x4D, 0xAE, 0xEF, 0xFF};//call 45B1C0h()
ASM_PATCH patchUpdateEndMainThunk[] = {
	{0x56036E, sizeof(codeUpdateEndMainThunk), codeUpdateEndMainThunk},
	{0x56036E, sizeof(codeUpdateEndMainOldThunk), codeUpdateEndMainOldThunk}};

//check abuse
DWORD dwAddrCheckAbuse = dwAddrStackBottom + 0x27A0;
BYTE codeCheckAbuse[] = {
	0xFF, 0x74, 0x24, 0x04,                   //push        dword ptr [esp+4]
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x40,                               //je          end
	0x33, 0xD2,                               //xor         edx,edx
	0x8B, 0x4C, 0x24, 0x20,                   //mov         ecx,dword ptr [esp+20h]
	                                          //loop,killer:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x1B,                               //je          end_killer
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0x83, 0x78, 0x54, 0x07,                   //cmp         dword ptr[eax+54h],7
	0x74, 0xF1,                               //je          loop_killer
	0x83, 0x78, 0x54, 0x08,                   //cmp         dword ptr[eax+54h],8
	0x74, 0xEB,                               //je          loop_killer
	0x39, 0x50, 0x64,                         //cmp         dword ptr [eax+64h],edx
	0x7E, 0xE6,                               //jle         loop_killer
	0x8B, 0x50, 0x64,                         //mov         edx,dword ptr [eax+64h]
	0xEB, 0xE1,                               //jmp         loop_killer
	                                          //end_killer:
	0x8B, 0x8C, 0x24, 0xE0, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+0E0h]
	0x8B, 0x41, 0x58,                         //mov         eax,dword ptr [ecx+58h]
	0x2B, 0x41, 0x50,                         //sub         eax,dword ptr [ecx+50h]
	0x33, 0xC9,                               //xor         ecx,ecx
	0x85, 0xD2,                               //test        edx,edx
	0x0F, 0x94, 0xC1,                         //setz        cl
	0x3B, 0xC2,                               //cmp         eax,edx
	0x0F, 0x9F, 0xC1,                         //setg        cl
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCheckAbuseThunk[] = {0xE8, 0x0F, 0x0C, 0xC0, 0xFF};//dwAddrCheckAbuse - 4A1B8Ch - 5
BYTE codeCheckAbuseOldThunk[] = {0xE8, 0xBF, 0xD2, 0xFC, 0xFF};//call 46EE50()
ASM_PATCH patchCheckAbuseThunk[] = {
	{0x4A1B8C, sizeof(codeCheckAbuseThunk), codeCheckAbuseThunk},
	{0x4A1B8C, sizeof(codeCheckAbuseOldThunk), codeCheckAbuseOldThunk}};

BYTE codeCheckChaosThunk[] = {0xE8, 0x3D, 0x0C, 0xC0, 0xFF};//dwAddrCheckAbuse - 4A1B5Eh - 5
BYTE codeCheckChaosOldThunk[] = {0xE8, 0xED, 0xD2, 0xFC, 0xFF};//call 46EE50()
ASM_PATCH patchCheckChaosThunk[] = {
	{0x4A1B5E, sizeof(codeCheckChaosThunk), codeCheckChaosThunk},
	{0x4A1B5E, sizeof(codeCheckChaosOldThunk), codeCheckChaosOldThunk}};

//get building backup
DWORD dwAddrBuildingBackup = dwAddrStackBottom + 0x1990;
BYTE codeBuildingBackup[] = {
	                                          //get_building_backup:
	0x55,                                     //push        ebp
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x33, 0xFF,                               //xor         edi,edi
	0xBD, 0xB0, 0x93, 0x4B, 0x01,             //mov         ebp,14B93B0h
	0x8B, 0xF1,                               //mov         esi,ecx
	                                          //loop_troop:
	0x8B, 0x45, 0x58,                         //mov         eax,[ebp+58h]
	0x3C, 0x34,                               //cmp         al,34h
	0x74, 0x08,                               //je          check_troop_goal
	0x3C, 0x33,                               //cmp         al,33h
	0x74, 0x04,                               //je          check_troop_goal
	0x3C, 0x27,                               //cmp         al,27h
	0x75, 0x3B,                               //jne         next_troop
	                                          //check_troop_goal:
	0x8B, 0x46, 0x04,                         //mov         eax,dword ptr [esi+4]
	0x39, 0x45, 0x50,                         //cmp         dword ptr [ebp+50h],eax
	0x75, 0x33,                               //jne         next_troop
	0x83, 0x7D, 0x54, 0xFF,                   //cmp         dword ptr [ebp+54h],0FFh
	0x75, 0x2D,                               //jne         next_troop
	0x83, 0x7D, 0x24, 0x06,                   //cmp         dword ptr [ebp+24h],6
	0x74, 0x27,                               //je          next_troop
	0x83, 0x7D, 0x24, 0x04,                   //cmp         dword ptr [ebp+24h],4
	0x74, 0x21,                               //je          next_troop
	0x56,                                     //push        esi
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x1E,                         //cmp         eax,1Eh
	                                          //test_distance:
	0x7E, 0x0F,                               //jle         add_troop_soldier
	0x56,                                     //push        esi
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x70, 0x88, 0x46, 0x00,             //mov         eax,468870h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x09,                         //cmp         eax,9
	0x7F, 0x03,                               //jg          next_troop
	                                          //add_troop_soldier:
	0x03, 0x7D, 0x30,                         //add         edi,dword ptr [ebp+30h]
	                                          //next_troop:
	0x81, 0xC5, 0x04, 0x01, 0x00, 0x00,       //add         ebp,104h
	0x66, 0x81, 0x7D, 0x04, 0x51, 0x03,       //cmp         word ptr [ebp+4],351h
	0x7C, 0xA8,                               //jl          loop_troop
	0x8B, 0xC7,                               //mov         eax,edi
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0x5D,                                     //pop         ebp
	0xC3                                      //ret
};

//switch foot horse killer
DWORD dwAddrSwitchFootHorse = dwAddrStackBottom + 0x1600;
BYTE codeSwitchFootHorse[] = {
	0xB8, 0xF0, 0x0D, 0x47, 0x00,             //mov         eax,470DF0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4F, 0x38,                         //mov         ecx,dword ptr [edi+38h]
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0B8h]
	0x8B, 0x41, 0x70,                         //mov         eax,dword ptr [ecx+70h]
	0xA3, 0xF3, 0xFA, 0x43, 0x00,             //mov         [force_killer_flag],eax
	0x8A, 0x43, 0x04,                         //mov         al,byte ptr [ebx+4]
	0x3C, 0x01,                               //cmp         al,1
	0x7F, 0x10,                               //jg          test_horse_array
	0x6A, 0x01,                               //push        1
	0x6A, 0x01,                               //push        1
	0x8D, 0x4E, 0x2C,                         //lea         ecx,[esi+2Ch]
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x62,                               //jmp         end
	                                          //test_horse_array:
	0x3C, 0x03,                               //cmp         al,3
	0x7F, 0x5E,                               //jg          end
	0x6A, 0x01,                               //push        1
	0x6A, 0x00,                               //push        0
	0x8D, 0x4E, 0x2C,                         //lea         ecx,[esi+2Ch]
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x4C,                               //jg          end
	0x6A, 0x00,                               //push        0
	0x8D, 0x4E, 0x2C,                         //lea         ecx,[esi+2Ch]
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x3C,                               //jle         end
	0x50,                                     //push        eax
	0x6A, 0x01,                               //push        1
	0x8D, 0x4E, 0x2C,                         //lea         ecx,[esi+2Ch]
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x7F, 0x2A,                               //jg          end
	0x6A, 0x01,                               //push        1
	0x6A, 0x01,                               //push        1
	0x8D, 0x4E, 0x2C,                         //lea         ecx,[esi+2Ch]
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x18,                               //jle         end
	0x33, 0xC0,                               //xor         eax,eax
	0xF6, 0x45, 0x04, 0x01,                   //test        byte ptr [ebp+4],1
	0x74, 0x02,                               //je          get_new_array
	0xB0, 0x01,                               //mov         al,1
	                                          //get_new_array:
	0x50,                                     //push        eax
	0xB8, 0x90, 0x38, 0x45, 0x00,             //mov         eax,453890h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x89, 0x46, 0x30,                         //mov         dword ptr [esi+30h],eax
	0x8B, 0xD8,                               //mov         ebx,eax
	                                          //end:
	0xB8, 0x00, 0x64, 0x0A, 0x00,             //mov         eax,attack_build_date
	0xFF, 0xD0,                               //call        eax
	0xC3                                      //ret
};

BYTE codeSwitchFootHorseThunk[] = {0xE8, 0x70, 0xEA, 0xBF, 0xFF};//dwAddrSwitchFootHorse - 4A2B8Bh - 5
BYTE codeSwitchFootHorseOldThunk[] = {0xE8, 0x60, 0xE2, 0xFC, 0xFF};//call 470DF0h()
ASM_PATCH patchSwitchFootHorseThunk[] = {
	{0x4A2B8B, sizeof(codeSwitchFootHorseThunk), codeSwitchFootHorseThunk},
	{0x4A2B8B, sizeof(codeSwitchFootHorseOldThunk), codeSwitchFootHorseOldThunk}};

//attack build date
DWORD dwAddrAttackBuildDate = dwAddrStackBottom + 0x6400;
BYTE codeAttackBuildDate[] = {
												//attack_build_date:
	0x8A, 0x45, 0x58,							//mov         al,byte ptr [ebp+58h]
	0x3C, 0x28,									//cmp         al,28h
	0x7C, 0x0A,									//jl          end
	0x3C, 0x32,									//cmp         al,32h
	0x7F, 0x06,									//jg          end
	0xF6, 0x45, 0x22, 0x08,						//test        byte ptr [ebp+22h],8
	0x74, 0x01,									//je          get_attack_build_date
												//end:
	0xC3,										//ret
												//get_attack_build_date:
	0x83, 0xEC, 0x60,							//sub         esp,60h
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,				//mov         eax,4734B0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCD,									//mov         ecx,ebp
	0xB8, 0x40, 0x1F, 0x46, 0x00,				//mov         eax,461F40h
	0xFF, 0xD0,									//call        eax
	0x89, 0x86, 0xA4, 0x00, 0x00, 0x00,			//mov         [esi+0A4h],eax
	0x8D, 0x4C, 0x24, 0x20,						//lea         ecx,[esp+20h]
	0x50,										//push        eax
	0x8B, 0x97, 0xC0, 0x08, 0x00, 0x00,			//mov         edx,dword ptr [edi+8C0h]
	0xFF, 0xB2, 0xD0, 0x00, 0x00, 0x00,			//push        dword ptr [edx+0D0h]
	0xB8, 0x70, 0xA3, 0x47, 0x00,				//mov         eax,47A370h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x20,						//lea         ecx,[esp+20h]
	0x54,										//push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0x10, 0x82, 0x51, 0x00,				//mov         eax,518210h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0x80, 0x7B, 0x43, 0x00,				//mov         eax,437B80h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0x8B, 0x46, 0x34,							//mov         eax,dword ptr [esi+34h]
	0xFF, 0x70, 0x5C,							//push        dword ptr [eax+5Ch]
	0xFF, 0x73, 0x5C,							//push        dword ptr [ebx+5Ch]
	0x51,										//push        ecx
	0xB8, 0xC0, 0xA4, 0x44, 0x00,				//mov         eax,44A4C0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x0C,							//add         esp,0Ch
	0x50,										//push        eax
	0x8B, 0xCF,									//mov         ecx,edi
	0x55,										//push        ebp
	0x54,										//push        esp
	0xB8, 0xD0, 0x16, 0x4A, 0x00,				//mov         eax,4A16D0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x5A,										//pop         edx
	0x2B, 0xC2,									//sub         eax,edx
	0x85, 0xC0,									//test        eax,eax
	0x7D, 0x02,									//jge         set_attack_build_date
	0x33, 0xC0,									//xor         eax,eax
												//set_attack_build_date:
	0x89, 0x86, 0xA0, 0x00, 0x00, 0x00,			//mov         dword ptr [esi+0A0h],eax
	0x8D, 0x4C, 0x24, 0x20,						//lea         ecx,[esp+20h]
	0xB8, 0x10, 0x9F, 0x47, 0x00,				//mov         eax,479F10h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,				//mov         eax,5180E0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x60,							//add         esp,60h
	0xC3										//ret
};

//adjust person pos
DWORD dwAddrAdjustPersonPos = dwAddrStackBottom + 0xC60;
BYTE codeAdjustPersonPos[] = {
	0x8A, 0x43, 0x04,                         //mov         al,byte ptr [ebx+4]
	0x3C, 0x07,                               //cmp         al,7
	0x74, 0x4C,                               //je          end
	0xBF, 0x03, 0x00, 0x00, 0x00,             //mov         edi,3
	0x3C, 0x00,                               //cmp         al,0
	0x75, 0x01,                               //jne         test_crane_array
	0x47,                                     //inc         edi
	                                          //test_crane_array:
	0x3C, 0x01,                               //cmp         al,1
	0x75, 0x01,                               //jne         check_person_number
	0x4F,                                     //dec         edi
	                                          //check_person_number:
	0x39, 0x7E, 0x4C,                         //cmp         dword ptr [esi+4Ch],edi
	0x7E, 0x38,                               //jle         end
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0xBD, 0x01, 0x00, 0x00, 0x00,             //mov         ebp,1
	0x8B, 0x5C, 0x24, 0x34,                   //mov         ebx,dword ptr [esp+34h]
	                                          //loop_killer:
	0x8D, 0x4E, 0x40,                         //lea         ecx,[esi+40h]
	0x51,                                     //push        ecx
	0xFF, 0x73, 0x08,                         //push        dword ptr [ebx+8]
	0xB8, 0x50, 0xB9, 0x48, 0x00,             //mov         eax,48B950h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4E, 0x74,                         //lea         ecx,[esi+74h]
	0x8B, 0x04, 0x81,                         //mov         eax,dword ptr [ecx+eax*4]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0C,                               //je          next_killer
	0x83, 0x78, 0x54, 0x07,                   //cmp         dword ptr [eax+54h],7
	0x7C, 0x06,                               //jl          next_killer
	0x3B, 0xEF,                               //cmp         ebp,edi
	0x7E, 0x09,                               //jle         end_loop_killer
	0xEB, 0x0C,                               //jmp         adjust_person_position
	                                          //next_killer:
	0x45,                                     //inc         ebp
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0xD5,                               //jne         loop_killer
	                                          //end_loop_killer:
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	                                          //end:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //adjust_person_position:
	0x4F,                                     //dec         edi
	0x8B, 0x4C, 0x24, 0x34,                   //mov         ecx,dword ptr [esp+34h]
	                                          //search_person:
	0x4F,                                     //dec         edi
	0x75, 0x02,                               //jne         test_goal_person
	0x8B, 0xD9,                               //mov         ebx,ecx
	                                          //test_goal_person:
	0x4D,                                     //dec         ebp
	0x74, 0x04,                               //je          end_search_person
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xF4,                               //jmp         search_person
	                                          //end_search_person:
	0x8B, 0x79, 0x08,                         //mov         edi,dword ptr [ecx+8]
	0x51,                                     //push        ecx
	0x8D, 0x4C, 0x24, 0x34,                   //lea         ecx,[esp+34h]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x8D, 0x4C, 0x24, 0x38,                   //lea         ecx,[esp+38h]
	0xB8, 0xA0, 0x82, 0x51, 0x00,             //mov         eax,5182A0h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xCC                                //jmp         end_loop_killer
};

BYTE codeAdjustPersonPosThunk[] = {0xE8, 0x4B, 0xE0, 0xBF, 0xFF, 0x42};//dwAddrAdjustPersonPos - 4A2C10h - 5
BYTE codeAdjustPersonPosOldThunk[] = {0xFF, 0x15, 0x10, 0xF3, 0x5F, 0x00};//call [5FF310h]
ASM_PATCH patchAdjustPersonPosThunk[] = {
	{0x4A2C10, sizeof(codeAdjustPersonPosThunk), codeAdjustPersonPosThunk},
	{0x4A2C10, sizeof(codeAdjustPersonPosOldThunk), codeAdjustPersonPosOldThunk}};

//save troop expense
DWORD dwAddrSaveTroopExpense = dwAddrStackBottom + 0x2770;
BYTE codeSaveTroopExpense[] = {
	0x50,                                     //push        eax
	0x8B, 0x4E, 0x40,                         //mov         ecx,dword ptr [esi+40h]
	0x8B, 0x51, 0x6C,                         //mov         edx,dword ptr [ecx+6Ch]
	0x8B, 0x42, 0x78,                         //mov         eax,dword ptr [edx+78h]
	0x8B, 0x51, 0x70,                         //mov         edx,dword ptr [ecx+70h]
	0x03, 0x42, 0x78,                         //add         eax,dword ptr [edx+78h]
	0x69, 0xC0, 0xB8, 0x0B, 0x00, 0x00,       //imul        eax,0BB8h
	0xC1, 0xE8, 0x0E,                         //shr         eax,0Eh
	0x59,                                     //pop         ecx
	0x8B, 0x51, 0x14,                         //mov         edx,dword ptr [ecx+14h]
	0x2B, 0xD0,                               //sub         edx,eax
	0x85, 0xD2,                               //test        edx,edx
	0x7D, 0x02,                               //jge         save_force_money
	0x33, 0xD2,                               //xor         edx,edx
	                                          //save_force_money:
	0x89, 0x51, 0x14,                         //mov         dword ptr [ecx+14h],edx
	0x8B, 0x41, 0x34,                         //mov         eax,dword ptr [ecx+34h]
	0x83, 0xE0, 0x01,                         //and         eax,1
	0xC3                                      //ret
};

BYTE codeSaveTroopExpenseThunk[] = {0xE8, 0x38, 0x00, 0xC1, 0xFF};//dwAddrSaveTroopExpense - 492733h - 5
BYTE codeSaveTroopExpenseOldThunk[] = {0x8B, 0xC8, 0xFF, 0x52, 0x40};//mov ecx,eax; call [edx+40h]
ASM_PATCH patchSaveTroopExpenseThunk[] = {
	{0x492733, sizeof(codeSaveTroopExpenseThunk), codeSaveTroopExpenseThunk},
	{0x492733, sizeof(codeSaveTroopExpenseOldThunk), codeSaveTroopExpenseOldThunk}};

//min danger dispatch
DWORD dwAddrMinDangerDispatch = dwAddrStackBottom + 0x1E0;
BYTE codeMinDangerDispatch[] = {
	0x57,                                     //push        edi
	0xB8, 0xA0, 0x12, 0x4A, 0x00,             //mov         eax,4A12A0h
	0xFF, 0xD0,                               //call        eax
	0x3D, 0x40, 0x1F, 0x00, 0x00,             //cmp         eax,1F40h
	0x7D, 0x0D,                               //jge         end
	0x81, 0xFE, 0x10, 0x27, 0x00, 0x00,       //cmp         esi,2710h
	0x7D, 0x05,                               //jge         end
	0xBE, 0x10, 0x27, 0x00, 0x00,             //mov         esi,2710h
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeMinDangerDispatchThunk[] = {0xE8, 0xD5, 0xCF, 0xBF, 0xFF};//dwAddrMinDangerDispatch - 4A3206h - 5
BYTE codeMinDangerDispatchOldThunk[] = {0xE8, 0x95, 0xE0, 0xFF, 0xFF};//call 4A12A0h
ASM_PATCH patchMinDangerDispatchThunk[] = {
	{0x4A3206, sizeof(codeMinDangerDispatchThunk), codeMinDangerDispatchThunk},
	{0x4A3206, sizeof(codeMinDangerDispatchOldThunk), codeMinDangerDispatchOldThunk}};

//max anti troop
DWORD dwAddrMaxAntiTroop = dwAddrStackBottom + 0x16B0;
BYTE codeMaxAntiTroop[] = {
	0x58,                                     //pop         eax
	0xC6, 0x44, 0x24, 0x04, 0xF0,             //mov         byte ptr[esp+4],0F0h
	0xB8, 0x30, 0xF3, 0x46, 0x00,             //mov         eax,46F330h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x2A,                               //jle         end
	0x33, 0xC0,                               //xor         eax,eax
	0x8B, 0x49, 0x04,                         //mov         ecx,dword ptr [ecx+4]
	                                          //loop_troop:
	0x8B, 0x51, 0x08,                         //mov         edx,dword ptr [ecx+8]
	0x03, 0x42, 0x30,                         //add         eax,dword ptr [edx+30h]
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0xF4,                               //jne         loop_troop
	0x3B, 0x46, 0x30,                         //cmp         eax,dword ptr [esi+30h]
	0x7C, 0x14,                               //jl          end
	0x56,                                     //push        esi
	0x8D, 0x4C, 0x24, 0x24,                   //lea         ecx,[esp+24h]
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x44, 0x24, 0x2C,                   //mov         eax,dword ptr [esp+2Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x06,                               //je          fail
	                                          //end:
	0x68, 0x56, 0x26, 0x4A, 0x00,             //push        4A2656h
	0xC3,                                     //ret
	                                          //fail:
	0x68, 0xFA, 0x26, 0x4A, 0x00,             //push        4A26FAh
	0xC3                                      //ret
};

BYTE codeMaxAntiTroopThunk[] = {0xE8, 0x5A, 0xF0, 0xBF, 0xFF};//dwAddrMaxAntiTroop - 4A2651h - 5
BYTE codeMaxAntiTroopOldThunk[] = {0xE8, 0xDA, 0xCC, 0xFC, 0xFF};//call 46F430h
ASM_PATCH patchMaxAntiTroopThunk[] = {
	{0x4A2651, sizeof(codeMaxAntiTroopThunk), codeMaxAntiTroopThunk},
	{0x4A2651, sizeof(codeMaxAntiTroopOldThunk), codeMaxAntiTroopOldThunk}};

//building anti attack troop
DWORD dwAddrBuildingAntiAttackTroop = dwAddrStackBottom + 0x1780;
BYTE codeBuildingAntiAttackTroop[] = {
	                                          //building_anti_attack_troop:
	0x55,                                     //push        ebp
	0x57,                                     //push        edi
	0x8B, 0xE9,                               //mov         ebp,ecx
	0x8B, 0x7D, 0x04,                         //mov         edi,dword ptr [ebp+4]
	                                          //loop_troop:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x1F,                               //je          end_loop_troop
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x8B, 0x41, 0x58,                         //mov         eax,dword ptr [ecx+58h]
	0x83, 0xF8, 0x26,                         //cmp         eax,26h
	0x75, 0x06,                               //jne         delete_troop
	0x80, 0x79, 0x52, 0x03,                   //cmp         byte ptr [ecx+52h],3
	0x74, 0xE9,                               //je          loop_troop
	                                          //delete_troop:
	0x51,                                     //push        ecx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xDD,                               //jmp         loop_troop
	                                          //end_loop_troop:
	0x8B, 0xCD,                               //mov         ecx,ebp
	0x5F,                                     //pop         edi
	0x5D,                                     //pop         ebp
	0x68, 0x30, 0xE8, 0x46, 0x00,             //push        46E830h
	0xC3                                      //ret
};

//enable cultivate
DWORD dwAddrEnableCultivate = dwAddrStackBottom + 0x3900;
BYTE codeEnableCultivate[] = {
	0x33, 0xC0,                               //xor         eax,eax
	0x80, 0x3D, 0x14, 0xFF, 0x43, 0x00, 0x02, //cmp         byte ptr[quarter],2
	0x75, 0x01,                               //jne         check_cultivate_condition
	0xC3,                                     //ret
	                                          //check_cultivate_condition:
	0x57,                                     //push        edi
	0x8B, 0xBE, 0xCC, 0x00, 0x00, 0x00,       //mov         edi,dword ptr [esi+0CCh]
	0xB8, 0x90, 0x4B, 0x45, 0x00,             //mov         eax,454B90h
	0xFF, 0xD0,                               //call        eax
	0x05, 0xFE, 0x01, 0x00, 0x00,             //add         eax,1FEh
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xE0, 0xED, 0x43, 0x00,             //mov         eax,43EDE0h
	0xFF, 0xD0,                               //call        eax
	0x2B, 0x47, 0x18,                         //sub         eax,dword ptr [edi+18h]
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x14,                               //jle         check_city_condition
	0x50,                                     //push        eax
	0x68, 0x68, 0x01, 0x00, 0x00,             //push        168h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0xDA, 0x43, 0x00,             //mov         eax,43DA80h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7C, 0x39,                               //jl          do_cultivate
	                                          //check_city_condition:
	0x8B, 0x86, 0xD0, 0x01, 0x00, 0x00,       //mov         eax,dword ptr [esi+1D0h]
	0x6B, 0xC0, 0x64,                         //imul        eax,eax,64h
	0x99,                                     //cdq
	0x8B, 0x8E, 0xD8, 0x01, 0x00, 0x00,       //mov         ecx,dword ptr [esi+1D8h]
	0xF7, 0xF1,                               //div         eax,ecx
	0xF7, 0xD8,                               //neg         eax
	0x83, 0xC0, 0x64,                         //add         eax,64h
	0x8B, 0x96, 0xC0, 0x01, 0x00, 0x00,       //mov         edx,dword ptr [esi+1C0h]
	0xC1, 0xEA, 0x0A,                         //shr         edx,0Ah
	0x03, 0xC2,                               //add         eax,edx
	0x50,                                     //push        eax
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0x33, 0xD2,                               //xor         edx,edx
	0xB9, 0x64, 0x00, 0x00, 0x00,             //mov         ecx,64h
	0xF7, 0xF1,                               //div         eax,ecx
	0x59,                                     //pop         ecx
	0x33, 0xC0,                               //xor         eax,eax
	0x3B, 0xD1,                               //cmp         edx,ecx
	0x7D, 0x06,                               //jge         end
	                                          //do_cultivate:
	0x8B, 0x86, 0xD8, 0x01, 0x00, 0x00,       //mov         eax,dword ptr [esi+1D8h]
	                                          //end:
	0x5F,                                     //pop         edi
	0xC3                                      //ret
};

BYTE codeEnableCultivateThunk[] = {0xE8, 0x15, 0x82, 0xBF, 0xFF, 0x42};//dwAddrEnableCultivate - 4AB6E6h - 5
BYTE codeEnableCultivateOldThunk[] = {0xFF, 0x92, 0xFC, 0x00, 0x00, 0x00};
ASM_PATCH patchEnableCultivateThunk[] = {
	{0x4AB6E6, sizeof(codeEnableCultivateThunk), codeEnableCultivateThunk},
	{0x4AB6E6, sizeof(codeEnableCultivateOldThunk), codeEnableCultivateOldThunk}};

//move idle person
DWORD dwAddrMoveIdlePerson = dwAddrStackBottom + 0x1CE0;
BYTE codeMoveIdlePerson[] = {
	0x80, 0x7F, 0x0C, 0xC8,                   //cmp         byte ptr [edi+0Ch],0C8h
	0x74, 0x06,                               //je          no_soldier_building
	0x68, 0x10, 0xF6, 0x46, 0x00,             //push        46F610h
	0xC3,                                     //ret
	                                          //no_soldier_building:
	0x8B, 0x49, 0x04,                         //mov         ecx,dword ptr [ecx+4]
	0xA1, 0x68, 0xFA, 0x43, 0x00,             //mov         eax,[no_soldier_building]
	0x89, 0x41, 0x08,                         //mov         dword ptr [ecx+8],eax
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeMoveIdlePersonThunk[] = {0xE8, 0x1F, 0x84, 0xBF, 0xFF};//dwAddrMoveIdlePerson - 4A98BCh - 5
BYTE codeMoveIdlePersonOldThunk[] = {0xE8, 0x4F, 0x5D, 0xFC, 0xFF};//call 46F610h
ASM_PATCH patchMoveIdlePersonThunk[] = {
	{0x4A98BC, sizeof(codeMoveIdlePersonThunk), codeMoveIdlePersonThunk},
	{0x4A98BC, sizeof(codeMoveIdlePersonOldThunk), codeMoveIdlePersonOldThunk}};

/////////////////////////////////////////////
#define PATCH_MOVE_AGAIN_NUM 2

DWORD dwAddrMoveAgain[PATCH_MOVE_AGAIN_NUM] = {0x468866, 0x468893};
DWORD dwSizeMoveAgain[PATCH_MOVE_AGAIN_NUM] = {0xA, 0xD};
BYTE codeMoveAgain[PATCH_MOVE_AGAIN_NUM][PATCH_SIZE] = {
	{0x5E,                                    //pop         esi
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x23},
	//1:8+2
	{0x57,                                    //push        edi
	0x8D, 0x4D, 0x64,                         //lea         ecx,[ebp+64h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x56,                                     //push        esi
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchMoveAgain[PATCH_MOVE_AGAIN_NUM] = {{0, 0, 0}};

BYTE codeMoveAgainThunk[] = {0xE8, 0x4A, 0xEF, 0xFB, 0xFF};//468866h - 4A9917h - 5
BYTE codeMoveAgainOldThunk[] = {0xE8, 0x34, 0x55, 0xFC, 0xFF};//call 46EE50h
ASM_PATCH patchMoveAgainThunk[] = {
	{0x4A9917, sizeof(codeMoveAgainThunk), codeMoveAgainThunk},
	{0x4A9917, sizeof(codeMoveAgainOldThunk), codeMoveAgainOldThunk}};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                allocate officer
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//check officer money
DWORD dwAddrCheckOfficerMoney = dwAddrStackBottom + 0x1B40;
BYTE codeCheckOfficerMoney[] = {
	0x58,                                     //pop         eax
	0xB8, 0x70, 0x34, 0x47, 0x00,             //mov         eax,473470h
	0xFF, 0xD0,                               //call        eax
	0xFF, 0x73, 0x08,                         //push        dword ptr [ebx+8]
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x10, 0x30, 0x44, 0x00,             //mov         eax,443010h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xA0, 0x30, 0x44, 0x00,             //mov         eax,4430A0h
	0xFF, 0xD0,                               //call        eax
	0x6B, 0xC0, 0x03,                         //imul        eax,eax,3
	0x5A,                                     //pop         edx
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7C, 0x0B,                               //jl          normal
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x67,                               //jmp         end
	                                          //normal:
	0x8B, 0x7C, 0x24, 0x24,                   //mov         edi,dword ptr [esp+24h]
	                                          //loop_official_person:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x91, 0x8C, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [ecx+8Ch]
	0x85, 0xD2,                               //test        edx,edx
	0x7E, 0x34,                               //jle         none_official_type
	0x52,                                     //push        edx
	0xB8, 0xA0, 0x37, 0x45, 0x00,             //mov         eax,4537A0h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0xC0, 0x55, 0x0A, 0x00,             //mov         eax,get_officer_type
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x01,                               //cmp         al,1
	0x75, 0x3A,                               //jne         next_official_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0x00, 0xDE, 0x44, 0x00,             //mov         eax,44DE00h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x50,                         //cmp         eax,50h
	0x7D, 0x2B,                               //jge         next_official_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xC7, 0x81, 0x8C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,//mov dword ptr [ecx+8Ch],-1
	0xEB, 0x0C,                               //jmp         delete_person
	                                          //none_official_type:
	0xB8, 0x00, 0xDE, 0x44, 0x00,             //mov         eax,44DE00h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x55,                         //cmp         eax,55h
	0x7D, 0x10,                               //jge         next_official_person
	                                          //delete_person:
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0x57,                                     //push        edi
	0x8B, 0x3F,                               //mov         edi,[edi]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,                               //jmp         test_next_official_person
	                                          //next_official_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	                                          //test_next_official_person:
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0x9D,                               //jne         loop_official_person
	                                          //end:
	0x68, 0xB5, 0x2F, 0x4B, 0x00,             //push        4B2FB5h
	0xC3                                      //ret
};

BYTE codeCheckOfficerMoneyThunk[] = {0xE8, 0x8B, 0xEB, 0xBE, 0xFF};//dwAddrCheckOfficerMoney - 4B2FB0h - 5
BYTE codeCheckOfficerMoneyOldThunk[] = {0xE8, 0xBB, 0x04, 0xFC, 0xFF};//call 473470h
ASM_PATCH patchCheckOfficerMoneyThunk[] = {
	{0x4B2FB0, sizeof(codeCheckOfficerMoneyThunk), codeCheckOfficerMoneyThunk},
	{0x4B2FB0, sizeof(codeCheckOfficerMoneyOldThunk), codeCheckOfficerMoneyOldThunk}};

/////////////////////////////////////////////
#define PATCH_FILTER_READY_PERSON_NUM 2

DWORD dwAddrFilterReadyPerson[PATCH_FILTER_READY_PERSON_NUM] = {0x46B462, 0x46B923};
DWORD dwSizeFilterReadyPerson[PATCH_FILTER_READY_PERSON_NUM] = {0xE, 0xD};
BYTE codeFilterReadyPerson[PATCH_FILTER_READY_PERSON_NUM][PATCH_SIZE] = {
	{0xB8, 0x10, 0xF6, 0x44, 0x00,            //mov         eax,44F610h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0xE9, 0xB3, 0x04, 0x00, 0x00},
	//1:9+5
	{0x75, 0x08,                              //jne         invalid_person
	0x8B, 0xCE,                               //mov         ecx,esi
	0x68, 0xC0, 0xD6, 0x44, 0x00,             //push        44D6C0h
	0xC3,                                     //ret
	                                          //invalid_person:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3}                                     //ret
	//2:D
};
ASM_PATCH patchFilterReadyPerson[PATCH_FILTER_READY_PERSON_NUM] = {{0, 0, 0}};

BYTE codeFilterReadyPersonThunk[] = {0xE8, 0x6D, 0x84, 0xFB, 0xFF};//46B462h - 4B2FF0h - 5
BYTE codeFilterReadyPersonOldThunk[] = {0xE8, 0xCB, 0xA6, 0xF9, 0xFF};//call 44D6C0h
ASM_PATCH patchFilterReadyPersonThunk[] = {
	{0x4B2FF0, sizeof(codeFilterReadyPersonThunk), codeFilterReadyPersonThunk},
	{0x4B2FF0, sizeof(codeFilterReadyPersonOldThunk), codeFilterReadyPersonOldThunk}};

//command intelligence ability
DWORD dwAddrCommandIntAbility = dwAddrStackBottom + 0x1DE0;
BYTE codeCommandIntAbility[] = {
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x08,                   //mov         esi,dword ptr [esp+8]
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x6A, 0x00,                               //push        0
	0xB8, 0x90, 0xD4, 0x44, 0x00,             //mov         eax,44D490h
	0xFF, 0xD0,                               //call        eax
	0x03, 0x44, 0x24, 0xEC,                   //add         eax,dword ptr [esp-14h]
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x03, 0x41, 0x64,                         //add         eax,dword ptr [ecx+64h]
	0x03, 0x41, 0x54,                         //add         eax,dword ptr [ecx+54h]
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeCommandIntAbilityThunk[] = {0xE0, 0x1D, 0x0A, 0x00};//dwAddrCommandIntAbility
BYTE codeCommandIntAbilityOldThunk[] = {0x10, 0x29, 0x4B, 0x00};//4B2910h
ASM_PATCH patchCommandIntAbilityThunk[] = {
	{0x4B2BFD, sizeof(codeCommandIntAbilityThunk), codeCommandIntAbilityThunk},
	{0x4B2BFD, sizeof(codeCommandIntAbilityOldThunk), codeCommandIntAbilityOldThunk}};

//command ability
DWORD dwAddrCommandAbility = dwAddrStackBottom + 0x0BC0;
BYTE codeCommandAbility[] = {
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x08,                   //mov         esi,dword ptr [esp+8]
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x8B, 0x81, 0xF4, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0F4h]
	0x8B, 0x48, 0x74,                         //mov         ecx,[eax+74h]
	0xB8, 0xE0, 0xFD, 0x43, 0x00,             //mov         eax,43FDE0h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x6A, 0x00,                               //push        0
	0xB8, 0x90, 0xD4, 0x44, 0x00,             //mov         eax,44D490h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x03, 0x41, 0x64,                         //add         eax,dword ptr [ecx+64h]
	0xD1, 0xE0,                               //shl         eax,1
	0x03, 0x41, 0x70,                         //add         eax,[ecx+70h]
	0x5A,                                     //pop         edx
	0xC1, 0xEA, 0x01,                         //shr         edx,1
	0x2B, 0xC2,                               //sub         eax,edx
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeCommandAbilityThunk[] = {0xC0, 0x0B, 0x0A, 0x00};//dwAddrCommandAbility
BYTE codeCommandAbilityOldThunk[] = {0x70, 0x29, 0x4B, 0x00};//4B2970h
ASM_PATCH patchCommandAbilityThunk[] = {
	{0x4B2CBE, sizeof(codeCommandAbilityThunk), codeCommandAbilityThunk},
	{0x4B2CBE, sizeof(codeCommandAbilityOldThunk), codeCommandAbilityOldThunk}};

//jia xu officer
DWORD dwAddrJiaXuOfficer = dwAddrStackBottom + 0x1C00;
BYTE codeJiaXuOfficer[] = {
	0x58,                                     //pop         eax
	0xB8, 0x10, 0xF6, 0x46, 0x00,             //mov         eax,46F610h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x56,                                     //push        esi
	0x8B, 0x73, 0x48,                         //mov         esi,dword ptr [ebx+48h]
	                                          //loop_person_list:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x41, 0x64,                         //mov         eax,dword ptr [ecx+64h]
	0x83, 0xF8, 0x3C,                         //cmp         eax,3Ch
	0x7C, 0x2A,                               //jl          end_loop_person_list
	0x2B, 0x41, 0x54,                         //sub         eax,dword ptr [ecx+54h]
	0x83, 0xF8, 0xF8,                         //cmp         eax,-8
	0x7F, 0x1C,                               //jg          next_person
	0x51,                                     //push        ecx
	0x8D, 0x4B, 0x44,                         //lea         ecx,[ebx+44h]
	0x56,                                     //push        esi
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,                               //jmp         test_end_person_list
	                                          //next_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	                                          //test_end_person_list:
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xCB,                               //jne         loop_person_list
	                                          //end_loop_person_list:
	0x5E,                                     //pop         esi
	0x68, 0xC7, 0x2C, 0x4B, 0x00,             //push        4B2CC7h
	0xC3                                      //ret
};

BYTE codeJiaXuOfficerThunk[] = {0xE8, 0x39, 0xEF, 0xBE, 0xFF};//dwAddrJiaXuOfficer - 4B2CC2h - 5
BYTE codeJiaXuOfficerOldThunk[] = {0xE8, 0x49, 0xC9, 0xFB, 0xFF};//call 46F610h
ASM_PATCH patchJiaXuOfficerThunk[] = {
	{0x4B2CC2, sizeof(codeJiaXuOfficerThunk), codeJiaXuOfficerThunk},
	{0x4B2CC2, sizeof(codeJiaXuOfficerOldThunk), codeJiaXuOfficerOldThunk}};

//undel command person
DWORD dwAddrUndelCommandPerson = dwAddrStackBottom + 0x1CA0;
BYTE codeUndelCommandPerson[] = {
	0x8B, 0x41, 0x04,                         //mov         eax,dword ptr [ecx+4]
	0x8B, 0x40, 0x08,                         //mov         eax,dword ptr [eax+8]
	0xC3,                                     //ret
	0x51,                                     //push        ecx
	0x8D, 0x4B, 0x44,                         //lea         ecx,[ebx+44h]
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x68, 0x70, 0xEF, 0x46, 0x00,             //push        46EF70h
	0xC3                                      //ret
};

BYTE codeUndelCommandPersonThunk[] = {0xE8, 0x7C, 0xEF, 0xBE, 0xFF};//dwAddrUndelCommandPerson - 4B2D1Fh - 5
BYTE codeUndelCommandPersonOldThunk[] = {0xE8, 0xEC, 0x54, 0x06, 0x00};//call 518210h()
ASM_PATCH patchUndelCommandPersonThunk[] = {
	{0x4B2D1F, sizeof(codeUndelCommandPersonThunk), codeUndelCommandPersonThunk},
	{0x4B2D1F, sizeof(codeUndelCommandPersonOldThunk), codeUndelCommandPersonOldThunk}};
BYTE codeDelCommandPersonThunk[] = {0xE8, 0x31, 0xEF, 0xBE, 0xFF};//dwAddrUndelCommandPerson + 7 - 4B2D71h - 5
BYTE codeDelCommandPersonOldThunk[] = {0xE8, 0xFA, 0xC1, 0xFB, 0xFF};//call 46EF70h()
ASM_PATCH patchDelCommandPersonThunk[] = {
	{0x4B2D71, sizeof(codeDelCommandPersonThunk), codeDelCommandPersonThunk},
	{0x4B2D71, sizeof(codeDelCommandPersonOldThunk), codeDelCommandPersonOldThunk}};

BYTE codeUndelIntelligencePersonThunk[] = {0xE8, 0x8E, 0xEE, 0xBE, 0xFF};//dwAddrUndelCommandPerson - 4B2E0Dh - 5
BYTE codeUndelIntelligencePersonOldThunk[] = {0xE8, 0xFE, 0x53, 0x06, 0x00};//call 518210h()
ASM_PATCH patchUndelIntelligencePersonThunk[] = {
	{0x4B2E0D, sizeof(codeUndelIntelligencePersonThunk), codeUndelIntelligencePersonThunk},
	{0x4B2E0D, sizeof(codeUndelIntelligencePersonOldThunk), codeUndelIntelligencePersonOldThunk}};
BYTE codeDelIntelligencePersonThunk[] = {0xE8, 0x33, 0xEE, 0xBE, 0xFF};//dwAddrUndelCommandPerson + 7 - 4B2E6Fh - 5
BYTE codeDelIntelligencePersonOldThunk[] = {0xE8, 0xFC, 0xC0, 0xFB, 0xFF};//call 46EF70h()
ASM_PATCH patchDelIntelligencePersonThunk[] = {
	{0x4B2E6F, sizeof(codeDelIntelligencePersonThunk), codeDelIntelligencePersonThunk},
	{0x4B2E6F, sizeof(codeDelIntelligencePersonOldThunk), codeDelIntelligencePersonOldThunk}};

//jia xu back
DWORD dwAddrJiaXuBack = dwAddrStackBottom + 0x1C70;
BYTE codeJiaXuBack[] = {
	0x68, 0xFF, 0x7F, 0x00, 0x00,             //push        7FFFh
	0x68, 0x00, 0x05, 0x0A, 0x00,             //push        multi_search_person_list
	0x8D, 0x4B, 0x44,                         //lea         ecx,[ebx+44h]
	0xB8, 0x80, 0xEF, 0x46, 0x00,             //mov         eax,46EF80h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0xB8, 0xFF, 0xFF, 0xFF, 0xFF,             //mov         eax,7FFFFFFFh
	0xC3                                      //ret
};

BYTE codeJiaXuBackThunk[] = {0xE8, 0xDC, 0xEE, 0xBE, 0xFF};//dwAddrJiaXuBack - 4B2D8Fh - 5
BYTE codeJiaXuBackOldThunk[] = {0xE8, 0x1C, 0xAC, 0xF8, 0xFF};//call 43D9B0h
ASM_PATCH patchJiaXuBackThunk[] = {
	{0x4B2D8F, sizeof(codeJiaXuBackThunk), codeJiaXuBackThunk},
	{0x4B2D8F, sizeof(codeJiaXuBackOldThunk), codeJiaXuBackOldThunk}};

//intelligence ability
DWORD dwAddrIntelligenceAbility = dwAddrStackBottom + 0x1CC0;
BYTE codeIntelligenceAbility[] = {
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x08,                   //mov         esi,dword ptr [esp+8]
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x6A, 0x02,                               //push        2
	0xB8, 0x90, 0xD4, 0x44, 0x00,             //mov         eax,44D490h
	0xFF, 0xD0,                               //call        eax
	0x03, 0x44, 0x24, 0xF0,                   //add         eax,dword ptr [esp-10h]
	0x8B, 0x0E,                               //mov         ecx,dword ptr [esi]
	0x03, 0x41, 0x54,                         //add         eax,dword ptr [ecx+54h]
	0x03, 0x41, 0x5C,                         //add         eax,dword ptr [ecx+5Ch]
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeIntelligenceAbilityThunk[] = {0xC0, 0x1C, 0x0A, 0x00};//dwAddrIntelligenceAbility
BYTE codeIntelligenceAbilityOldThunk[] = {0x20, 0x2A, 0x4B, 0x00};//4B2A20h
ASM_PATCH patchIntelligenceAbilityThunk[] = {
	{0x4B2DA2, sizeof(codeIntelligenceAbilityThunk), codeIntelligenceAbilityThunk},
	{0x4B2DA2, sizeof(codeIntelligenceAbilityOldThunk), codeIntelligenceAbilityOldThunk}};

//degrade person
DWORD dwAddrDegradePerson = dwAddrStackBottom + 0x1900;
BYTE codeDegradePerson[] = {
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x08,                   //mov         esi,dword ptr [esp+8]
	0x57,                                     //push        edi
	0x8B, 0x7E, 0x04,                         //mov         edi,dword ptr [esi+4]
	                                          //loop_officer_person:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x25,                               //je          end_loop_officer_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x25, 0xFF, 0x00, 0x00, 0x00,             //and         eax,0FFh
	0x3B, 0x81, 0x8C, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [ecx+8Ch]
	0x75, 0x0E,                               //jne         next_officer_person
	0x57,                                     //push        edi
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xDB,                               //jmp         loop_officer_person
	                                          //next_officer_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xEB, 0xD7,                               //jmp         loop_officer_person
	                                          //end_loop_officer_person:
	0x8B, 0x7B, 0x48,                         //mov         edi,dword ptr [ebx+48h]
	                                          //loop_person:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x41,                               //je          end_loop_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x81, 0x8C, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+8Ch]
	0x83, 0xF8, 0xFF,                         //cmp         eax,0FFh
	0x74, 0x2F,                               //je          next_person
	0x50,                                     //push        eax
	0xB8, 0xA0, 0x37, 0x45, 0x00,             //mov         eax,4537A0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x04,                         //add         esp,4
	0x50,                                     //push        eax
	0x8D, 0x4B, 0x64,                         //lea         ecx,[ebx+64h]
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x15,                               //jne         next_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	                                          //degrade_person:
	0xB8, 0x4C, 0x00, 0x10, 0x00,             //mov         eax,10004Ch
	0x89, 0x41, 0x08,                         //mov         dword ptr [ecx+8],eax
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xEB, 0xBB,                               //jmp         loop_person
	                                          //end_loop_person:
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0x8B, 0xCB,                               //mov         ecx,ebx
	0x68, 0x50, 0xEB, 0x50, 0x00,             //push        50EB50h
	0xC3                                      //ret
};

BYTE codeDegradePersonThunk[] = {0xE8, 0x26, 0xEA, 0xBE, 0xFF};//dwAddrDegradePerson - 4B2ED5h - 5
BYTE codeDegradePersonOldThunk[] = {0xE8, 0x76, 0xBC, 0x05, 0x00};//call 50EB50h()
ASM_PATCH patchDegradePersonThunk[] = {
	{0x4B2ED5, sizeof(codeDegradePersonThunk), codeDegradePersonThunk},
	{0x4B2ED5, sizeof(codeDegradePersonOldThunk), codeDegradePersonOldThunk}};

//stone stop
DWORD dwAddrStoneStop = dwAddrStackBottom + 0x2000;
BYTE codeStoneStop[] = {
	0xB8, 0x00, 0x1B, 0x0A, 0x00,             //mov         eax,check_long_range_array
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x6A,                               //je          normal
	0x83, 0x7E, 0x58, 0x26,                   //cmp         dword ptr [esi+58h],26h
	0x75, 0x64,                               //jne         normal
	0x81, 0x7E, 0x30, 0x00, 0x0C, 0x00, 0x00, //cmp         dword ptr [esi+30h],0C00h
	0x7E, 0x5B,                               //jle         normal
	0x83, 0xBE, 0x80, 0x00, 0x00, 0x00, 0x00, //cmp         dword ptr [esi+80h],0
	0x75, 0x52,                               //jne         normal
	0x8B, 0x46, 0x54,                         //mov         eax,dword ptr [esi+54h]
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x4B,                               //jle         normal
	0x50,                                     //push        eax
	0xB8, 0xE0, 0x32, 0x45, 0x00,             //mov         eax,4532E0h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0xF6, 0x40, 0x20, 0x01,                   //test        byte ptr[eax+20h],1
	0x74, 0x09,                               //je          test_in_range
	0x81, 0x78, 0x30, 0x00, 0x04, 0x00, 0x00, //cmp         dword ptr [eax+30h],400h
	0x7E, 0x33,                               //jle         normal
	                                          //test_in_range:
	0x50,                                     //push        eax
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x60, 0x58, 0x46, 0x00,             //mov         eax,465860h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x74, 0x23,                               //je          normal
	0xF6, 0x40, 0x20, 0x01,                   //test        byte ptr[eax+20h],1
	0x75, 0x06,                               //jne         compare_goal
	0xF6, 0x46, 0x21, 0x10,                   //test        byte ptr[esi+21h],10h
	0x75, 0x08,                               //jne         stop_on_attack
	                                          //compare_goal:
	0x8B, 0x46, 0x50,                         //mov         eax,dword ptr [esi+50h]
	0x3B, 0x46, 0x54,                         //cmp         eax,[esi+54h]
	0x75, 0x0F,                               //jne         normal
	                                          //stop_on_attack:
	0x8B, 0x54, 0x24, 0x04,                   //mov         edx,dword ptr [esp+4]
	0x8B, 0x42, 0x08,                         //mov         eax,dword ptr [edx+8]
	0x89, 0x02,                               //mov         dword ptr [edx],eax
	0x8B, 0x42, 0x0C,                         //mov         eax,dword ptr [edx+0Ch]
	0x89, 0x42, 0x04,                         //mov         dword ptr [edx+4],eax
	                                          //normal:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x68, 0x00, 0xAC, 0x44,  0x00,            //push        44AC00h
	0xC3                                      //ret
};

BYTE codeStoneStopThunk[] = {0xE8, 0x82, 0x4F, 0xC0, 0xFF};//dwAddrStoneStop - 49D079h - 5
BYTE codeStoneStopOldThunk[] = {0xE8, 0x82, 0xDB, 0xFA, 0xFF};//call 44AC00h
ASM_PATCH patchStoneStopThunk[] = {
	{0x49D079, sizeof(codeStoneStopThunk), codeStoneStopThunk},
	{0x49D079, sizeof(codeStoneStopOldThunk), codeStoneStopOldThunk}};

//array image
DWORD dwAddrArrayImage = dwAddrStackBottom + 0x1720;
BYTE codeArrayImage[] = {
	0x33, 0xC0,                               //xor         eax,eax
	0x83, 0xFF, 0x0B,                         //cmp         edi,0Bh
	0x7E, 0x03,                               //jle         center_display
	                                          //normal:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //center_display:
	0xB0, 0x01,                               //mov         al,1
	0x83, 0xFF, 0x08,                         //cmp         edi,8
	0x7D, 0xF6,                               //jge         normal
	0x8A, 0x87, 0xC4, 0x4A, 0x45, 0x00,       //mov         al,byte ptr [edi+array_center_image]
	0x8B, 0x74, 0x24, 0x28,                   //mov         esi,dword ptr [esp+28h]
	0x68, 0x59, 0xFA, 0x52, 0x00,             //push        52FA59h
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeArrayImageThunk[] = {0xE8, 0xD6, 0x1C, 0xB7, 0xFF};//dwAddrArrayImage - 52FA45h - 5
BYTE codeArrayImageOldThunk[] = {0xE8, 0x96, 0xE5, 0xF2, 0xFF};//call 45DFE0h
ASM_PATCH patchArrayImageThunk[] = {
	{0x52FA45, sizeof(codeArrayImageThunk), codeArrayImageThunk},
	{0x52FA45, sizeof(codeArrayImageOldThunk), codeArrayImageOldThunk}};

//troop experience
DWORD dwAddrTroopExperience = dwAddrStackBottom + 0x1D30;
BYTE codeTroopExperience[] = {
	0xB8, 0x03, 0x00, 0x00, 0x00,             //mov         eax,3
	0x8B, 0x51, 0x74,                         //mov         edx,dword ptr [ecx+74h]
	0x8B, 0x92, 0xB8, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [edx+0B8h]
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr [edx+34h],1
	0x75, 0x01,                               //jne         add_troop_proficiency
	0x40,                                     //inc         eax
	                                          //add_troop_proficiency:
	0x50,                                     //push        eax
	0x50,                                     //push        eax
	0x57,                                     //push        edi
	0xB8, 0xC0, 0x0D, 0x46, 0x00,             //mov         eax,460DC0h
	0xFF, 0xD0,                               //call        eax
	0x6A, 0x02,                               //push        2
	0x57,                                     //push        edi
	0x8D, 0x4E, 0xC8,                         //lea         ecx,[esi-38h]
	0xB8, 0xC0, 0x0D, 0x46, 0x00,             //mov         eax,460DC0h
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	0x50,                                     //push        eax
	0x57,                                     //push        edi
	0x8B, 0x4E, 0x30,                         //mov         ecx,dword ptr [esi+30h]
	0xB8, 0x80, 0xDC, 0x44, 0x00,             //mov         eax,44DC80h
	0xFF, 0xD0,                               //call        eax
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeKillerExperienceThunk[] = {0xE8, 0xD6, 0x25, 0xBA, 0xFF};//dwAddrTroopExperience - 4FF755h - 5
BYTE codeKillerExperienceOldThunk[] = {0xE8, 0x66, 0x16, 0xF6, 0xFF};//call 460DC0h
ASM_PATCH patchKillerExperienceThunk[] = {
	{0x4FF755, sizeof(codeKillerExperienceThunk), codeKillerExperienceThunk},
	{0x4FF755, sizeof(codeKillerExperienceOldThunk), codeKillerExperienceOldThunk}};
BYTE codeWaterKillerExperienceThunk[] = {0xE8, 0x84, 0x26, 0xBA, 0xFF};//dwAddrTroopExperience - 4FF6A7h - 5
BYTE codeWaterKillerExperienceOldThunk[] = {0xE8, 0x14, 0x17, 0xF6, 0xFF};//call 460DC0h
ASM_PATCH patchWaterKillerExperienceThunk[] = {
	{0x4FF6A7, sizeof(codeWaterKillerExperienceThunk), codeWaterKillerExperienceThunk},
	{0x4FF6A7, sizeof(codeWaterKillerExperienceOldThunk), codeWaterKillerExperienceOldThunk}};

//captive money
DWORD dwAddrCaptiveMoney = dwAddrStackBottom + 0x17C0;
BYTE codeCaptiveMoney[] = {
	0xC1, 0xE0, 0x02,                         //shl         eax,2
	0xBA, 0x55, 0x55, 0x55, 0x55,             //mov         edx,55555555h
	0xF7, 0xEA,                               //imul        edx
	0x8B, 0xC2,                               //mov         eax,edx
	0xC3                                      //ret
};

BYTE codeCaptiveMoneyThunk[] = {0xE8, 0xC9, 0x21, 0xC1, 0xFF};//dwAddrCaptiveMoney - 48F5F2h - 5
BYTE codeCaptiveMoneyOldThunk[] = {0x83, 0xE2, 0x03, 0x03, 0xC2};//and edx,3;add eax,edx
ASM_PATCH patchCaptiveMoneyThunk[] = {
	{0x48F5F2, sizeof(codeCaptiveMoneyThunk), codeCaptiveMoneyThunk},
	{0x48F5F2, sizeof(codeCaptiveMoneyOldThunk), codeCaptiveMoneyOldThunk}};

//search range
DWORD dwAddrSearchRange = dwAddrStackBottom + 0x1F00;
BYTE codeSearchRange[] = {
	0x58,                                     //pop         eax
	0x8B, 0x41, 0x38,                         //mov         eax,dword ptr [ecx+38h]
	0x8B, 0x90, 0xB8, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [eax+0B8h]
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr [edx+34h],1
	0x75, 0x0A,                               //jne         player_force
	0xB8, 0x32, 0x1F, 0x0A, 0x00,             //mov         eax,search_range
	0xA3, 0x05, 0x05, 0x4B, 0x00,             //mov         [4B0505h],eax
	                                          //player_force:
	0xB8, 0xB0, 0x04, 0x4B, 0x00,             //mov         eax,4B04B0h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0xF0, 0xCC, 0x46, 0x00,             //mov         ecx,46CCF0h
	0x89, 0x0D, 0x05, 0x05, 0x4B, 0x00,       //mov         [4B0505h],ecx
	0x68, 0xE6, 0x6B, 0x4B, 0x00,             //push        4B6BE6h
	0xC3,                                     //ret
	                                          //search_range:
	0x8B, 0x54, 0x24, 0x04,                   //mov         edx,dword ptr [esp+4]
	0x8B, 0x0A,                               //mov         ecx,dword ptr [edx]
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x13,                               //jz          test_owner_city
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0x8B, 0x4A, 0x0C,                         //mov         ecx,dword ptr [edx+0Ch]
	0x3B, 0x81, 0xB8, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [ecx+0B8h]
	0x74, 0x24,                               //je          end
	0xEB, 0x20,                               //jmp         fail
	                                          //test_owner_city:
	0x8B, 0x0A,                               //mov         ecx,dword ptr [edx]
	0x8B, 0x41, 0x44,                         //mov         eax,dword ptr [ecx+44h]
	0x8B, 0x80, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x13,                               //jz          end
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0x8B, 0x4A, 0x0C,                         //mov         ecx,dword ptr [edx+0Ch]
	0x3B, 0x81, 0xB8, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [ecx+0B8h]
	0x74, 0x02,                               //je          end
	                                          //fail:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeSearchRangeThunk[] = {0xE8, 0x1A, 0xB3, 0xBE, 0xFF};//dwAddrSearchRange - 4B6BE1h - 5
BYTE codeSearchRangeOldThunk[] = {0xE8, 0xCA, 0x98, 0xFF, 0xFF};//call 4B04B0h
ASM_PATCH patchSearchRangeThunk[] = {
	{0x4B6BE1, sizeof(codeSearchRangeThunk), codeSearchRangeThunk},
	{0x4B6BE1, sizeof(codeSearchRangeOldThunk), codeSearchRangeOldThunk}};

//search condition
DWORD dwAddrSearchCondition = dwAddrStackBottom + 0x1D70;
BYTE codeSearchCondition[] = {
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x8B, 0x41, 0x0C,                         //mov         eax,dword ptr [ecx+0Ch]
	0x8B, 0x90, 0xB8, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [eax+0B8h]
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr [edx+34h],1
	0x74, 0x06,                               //je          npc_force
	0x68, 0x10, 0x68, 0x4B, 0x00,             //push        4B6810h
	0xC3,                                     //ret
	                                          //npc_force:
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0x8B, 0x81, 0x48, 0x01, 0x00, 0x00,       //mov         eax,dword ptr [ecx+148h]
	0x85, 0xC0,                               //test        eax,eax
	//0x74, 0x01,                               //jz          test_treasure
	0x74, 0x00,                               //jz          test_treasure
	0xC3,                                     //ret
	                                          //test_treasure:
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x6A, 0x00,                               //push        0
	0x51,                                     //push        ecx
	0x8D, 0x4C, 0x24, 0x08,                   //lea         ecx,[esp+8]
	0xB8, 0x00, 0xFC, 0x46, 0x00,             //mov         eax,46FC00h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0xB8, 0x50, 0x2F, 0x45, 0x00,             //mov         eax,452F50h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x0C,                         //add         esp,0Ch
	0x8B, 0xCC,                               //mov         ecx,esp
	0x50,                                     //push        eax
	0xB8, 0x20, 0xFC, 0x46, 0x00,             //mov         eax,46FC20h
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0xC3                                      //ret
};

BYTE codeSearchConditionThunk[] = {0x70, 0x1D, 0x0A, 0x00};//dwAddrSearchCondition
BYTE codeSearchConditionOldThunk[] = {0x10, 0x68, 0x4B, 0x00};//4B6810h
ASM_PATCH patchSearchConditionThunk[] = {
	{0x4B6C29, sizeof(codeSearchConditionThunk), codeSearchConditionThunk},
	{0x4B6C29, sizeof(codeSearchConditionOldThunk), codeSearchConditionOldThunk}};

//search invite
DWORD dwAddrSearchInvite = dwAddrStackBottom + 0x1FA0;
BYTE codeSearchInvite[] = {
	0x58,                                     //pop         eax
	0xFF, 0x15, 0xF0, 0xF2, 0x5F, 0x00,       //call        [5FF2F0h]
	0x8B, 0x4E, 0x40,                         //mov         ecx,dword ptr [esi+40h]
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0B8h]
	0xF7, 0x41, 0x34, 0x01, 0x00, 0x00, 0x00, //test        dword ptr [ecx+34h],1
	0x75, 0x0A,                               //jne         end
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x06,                               //jne         end
	0x33, 0xD2,                               //xor         edx,edx
	0x89, 0x54, 0x24, 0x1C,                   //mov         dword ptr [esp+1Ch],edx
	                                          //end:
	0x68, 0xEC, 0x46, 0x49, 0x00,             //push        4946ECh
	0xC3                                      //ret
};

BYTE codeSearchInviteThunk[] = {0xE8, 0xB5, 0xD8, 0xC0, 0xFF, 0x42};//dwAddrSearchInvite - 4946E6h - 5
BYTE codeSearchInviteOldThunk[] = {0xFF, 0x15, 0xF0, 0xF2, 0x5F, 0x00};//call [5FF2F0h]
ASM_PATCH patchSearchInviteThunk[] = {
	{0x4946E6, sizeof(codeSearchInviteThunk), codeSearchInviteThunk},
	{0x4946E6, sizeof(codeSearchInviteOldThunk), codeSearchInviteOldThunk}};

//invite new person
DWORD dwAddrInviteNewPerson = dwAddrStackBottom + 0x1F80;
BYTE codeInviteNewPerson[] = {
	0x8B, 0x81, 0xF4, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0F4h]
	0x83, 0x78, 0x58, 0x25,                   //cmp         dword ptr [eax+58h],25h
	0x74, 0x06,                               //je          test_person_number
	                                          //normal:
	0x68, 0xC0, 0xDC, 0x44, 0x00,             //push        44DCC0h
	0xC3,                                     //ret
	                                          //test_person_number:
	0x83, 0xB8, 0x90, 0x00, 0x00, 0x00, 0x02, //cmp         dword ptr [eax+90h],2
	0x75, 0xF1,                               //jne         normal
	0x33, 0xC0,                               //xor         eax,eax
	0xC2, 0x04, 0x00,                         //ret         4
};

BYTE codeInviteNewPersonThunk[] = {0xE8, 0x6D, 0xCC, 0xC0, 0xFF};//dwAddrInviteNewPerson - 49530Eh - 5
BYTE codeInviteNewPersonOldThunk[] = {0xE8, 0xAD, 0x89, 0xFB, 0xFF};//call 44DCC0h
ASM_PATCH patchInviteNewPersonThunk[] = {
	{0x49530E, sizeof(codeInviteNewPersonThunk), codeInviteNewPersonThunk},
	{0x49530E, sizeof(codeInviteNewPersonOldThunk), codeInviteNewPersonOldThunk}};

//treasure value
DWORD dwAddrTreasureValue = 0x43CF67;
BYTE codeTreasureValue[] = {
	0x83, 0xC6, 0x06,                         //add         esi,6
	0xB8, 0x1F, 0x85, 0xEB, 0x51,             //mov         eax,51EB851Fh
	0xC3                                      //ret
};

BYTE codeTreasureValueThunk[] = {0xE8, 0x82, 0xD7, 0xFA, 0xFF};//dwAddrTreasureValue - 48F7E0h - 5
BYTE codeTreasureValueOldThunk[] = {0xB8, 0x1F, 0x85, 0xEB, 0x51};//mov eax, 51EB851Fh
ASM_PATCH patchTreasureValueThunk[] = {
	{0x48F7E0, sizeof(codeTreasureValueThunk), codeTreasureValueThunk},
	{0x48F7E0, sizeof(codeTreasureValueOldThunk), codeTreasureValueOldThunk}};

//update killer damage
DWORD dwAddrUpdateKillerDamage = dwAddrStackBottom + 0x1880;
BYTE codeUpdateKillerDamage[] = {
	0x50,                                     //push        eax
	0x8D, 0x4C, 0x24, 0x0C,                   //lea         ecx,[esp+0Ch]
	0xB8, 0x30, 0x3F, 0x0A, 0x00,             //mov         eax,soldier_command_killer
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x0C,                   //lea         ecx,[esp+0Ch]
	0xB8, 0x90, 0x3F, 0x0A, 0x00,             //mov         eax,weaken_long_range_killer
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x44, 0x24, 0x0C,                   //mov         eax,[esp+0Ch]
	0x6B, 0xC0, 0x0A,                         //imul        eax,0Ah
	0x99,                                     //cdq
	0xB9, 0x0A, 0x00, 0x00, 0x00,             //mov         ecx,0Ah
	0xF7, 0xF1,                               //div         eax,ecx
	0x89, 0x44, 0x24, 0x0C,                   //mov         [esp+0Ch],eax
	0x58,                                     //pop         eax
	0x83, 0xF8, 0x06,                         //cmp         eax,6
	0xC3                                      //ret
};

BYTE codeUpdateKillerDamageThunk[] = {0xE8, 0x5F, 0x29, 0xBA, 0xFF};//dwAddrUpdateKillerDamage - 4FEF1Ch - 5
BYTE codeUpdateKillerDamageOldThunk[] = {0xB9, 0x0A, 0x00, 0x00, 0x00};//mov ecx, 0Ah
ASM_PATCH patchUpdateKillerDamageThunk[] = {
	{0x4FEF1C, sizeof(codeUpdateKillerDamageThunk), codeUpdateKillerDamageThunk},
	{0x4FEF1C, sizeof(codeUpdateKillerDamageOldThunk), codeUpdateKillerDamageOldThunk}};

//soldier command killer
DWORD dwAddrSoldierCommandKiller = dwAddrStackBottom + 0x3F30;
BYTE codeSoldierCommandKiller[] = {
	                                          //soldier_command_killer:
	0x56,                                     //push        esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0x8B, 0x4D, 0x3C,                         //mov         ecx,dword ptr [ebp+3Ch]
	0x8B, 0x41, 0x30,                         //mov         eax,dword ptr [ecx+30h]
	0x3D, 0x10, 0x27, 0x00, 0x00,             //cmp         eax,2710h
	0x7D, 0x17,                               //jge         many_soldier
	0x50,                                     //push        eax
	0xFF, 0x15, 0x1C, 0xF3, 0x5F, 0x00,       //call        [5FF31Ch]
	0x5A,                                     //pop         edx
	0x0F, 0xAF, 0x06,                         //imul        eax,dword ptr [esi]
	0x99,                                     //cdq
	0xB9, 0x64, 0x00, 0x00, 0x00,             //mov         ecx,64h
	0xF7, 0xF1,                               //div         eax,ecx
	                                          //end:
	0x89, 0x06,                               //mov         dword ptr [esi],eax
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //many_soldier:
	0x50,                                     //push        eax
	0x8B, 0x4D, 0x30,                         //mov         ecx,dword ptr [ebp+30h]
	0x8B, 0x41, 0x68,                         //mov         eax,dword ptr [ecx+68h]
	0x83, 0xE8, 0x3C,                         //sub         eax,3Ch
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,								  //jge         max_command_soldier
	0x33, 0xC0,                               //xor         eax,eax
	                                          //max_command_soldier:
	0x69, 0xC0, 0xE8, 0x03, 0x00, 0x00,       //imul        eax,3E8h
	0x59,                                     //pop         ecx
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x7E, 0x02,                               //jle         add_killer_damage
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //add_killer_damage:
	0x05, 0xA0, 0x86, 0x01, 0x00,             //add         eax,186A0h
	0xC1, 0xE8, 0x04,                         //shr         eax,4
	0x0F, 0xAF, 0x06,                         //imul        eax,dword ptr [esi]
	0xB9, 0x6A, 0x18, 0x00, 0x00,             //mov         ecx,186Ah
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0xEB, 0xCA                                //jmp         end
};

//building killer person
DWORD dwAddrBuildingKillerPerson = dwAddrStackBottom + 0x2100;
BYTE codeBuildingKillerPerson[] = {
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x52,                                     //push        edx
	0x8B, 0x71, 0x64,                         //mov         esi,dword ptr [ecx+64h]
	0xBA, 0x03, 0x00, 0x00, 0x00,             //mov         edx,3
	0xB9, 0x50, 0x00, 0x00, 0x00,             //mov         ecx,50h
	0xBF, 0x19, 0x00, 0x00, 0x00,             //mov         edi,19h
	0x3B, 0x76, 0x44,                         //cmp         esi,dword ptr [esi+44h]
	0x75, 0x14,                               //jne         got_building_type
	0xF6, 0x46, 0x51, 0xFF,                   //test        byte ptr [esi+51h],0FFh
	0x75, 0x0E,                               //jne         got_building_type
	0xB2, 0x07,                               //mov         dl,7
	0xB1, 0x58,                               //mov         cl,58h
	0xD1, 0xEF,                               //shr         edi,1
	0xF6, 0x46, 0x53, 0x40,                   //test        byte ptr [esi+53h],40h
	0x74, 0x02,                               //je          got_building_type
	0xB2, 0x08,                               //mov         dl,8
	                                          //got_building_type:
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0xB6, 0xE0, 0x00, 0x00, 0x00,       //mov         esi,dword ptr [esi+0E0h]
	                                          //loop_building_person:
	0x8B, 0x6E, 0x08,                         //mov         ebp,dword ptr [esi+8]
	0x83, 0xBD, 0x80, 0x00, 0x00, 0x00, 0x00, //cmp         dword ptr [ebp+80h],0
	0x7F, 0x18,                               //jg          next_person
	0x8B, 0x44, 0x0D, 0x00,                   //mov         eax,dword ptr [ebp+ecx]
	0x0F, 0xAF, 0xC7,                         //imul        eax,edi
	0x66, 0x03, 0x84, 0x55, 0xA4, 0x00, 0x00, 0x00,//add    ax,word ptr [ebp+edx*2+0A4h]
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7E, 0x05,                               //jle         next_person
	0x8B, 0xD8,                               //mov         ebx,eax
	0x89, 0x2C, 0x24,                         //mov         dword ptr [esp],ebp
	                                          //next_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xD6,                               //jne         loop_building_person
	0x58,                                     //pop         eax
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0x02,                               //jne         end
	0x8B, 0xC5,                               //mov         eax,ebp
	                                          //end:
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeBuildingKillerPersonThunk[] = {0xE8, 0xAD, 0xC0, 0xB9, 0xFF, 0x42};//dwAddrBuildingKillerPerson - 50604Eh - 5
BYTE codeBuildingKillerPersonOldThunk[] = {0xFF, 0x92, 0xBC, 0x00, 0x00, 0x00};//call [edx+BCh]
ASM_PATCH patchBuildingKillerPersonThunk[] = {
	{0x50604E, sizeof(codeBuildingKillerPersonThunk), codeBuildingKillerPersonThunk},
	{0x50604E, sizeof(codeBuildingKillerPersonOldThunk), codeBuildingKillerPersonOldThunk}};

//not sure captive
DWORD dwAddrNotSureCaptive = dwAddrStackBottom + 0x2170;
BYTE codeNotSureCaptive[] = {
	0x85, 0xF6,                               //test        esi,esi
	0x74, 0x06,                               //jz          end
	0xF6, 0x46, 0x34, 0x01,                   //test        dword ptr [esi+34h],1
	0x75, 0x06,                               //jne         player_force
	                                          //end:
	0x68, 0x40, 0x58, 0x40, 0x00,             //push        405840h
	0xC3,                                     //ret
	                                          //player_force:
	0xB0, 0x01,                               //mov         al,1
	0xC3                                      //ret
};

BYTE codeNotSureCaptiveThunk[] = {0xE8, 0x78, 0xC0, 0xC3, 0xFF};//dwAddrNotSureCaptive - 4660F3h - 5
BYTE codeNotSureCaptiveOldThunk[] = {0xE8, 0x48, 0xF7, 0xF9, 0xFF};//call 405840h()
ASM_PATCH patchNotSureCaptiveThunk[] = {
	{0x4660F3, sizeof(codeNotSureCaptiveThunk), codeNotSureCaptiveThunk},
	{0x4660F3, sizeof(codeNotSureCaptiveOldThunk), codeNotSureCaptiveOldThunk}};

//save harbor
DWORD dwAddrSaveHarbor = dwAddrStackBottom + 0x33C8;
BYTE codeSaveHarbor[] = {
	0xB8, 0x00, 0x3D, 0x0A, 0x00,             //mov         eax,test_regarded_building
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x7D, 0x1E,                               //jge         regarded_building
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          test_force_killer
	0xC3,                                     //ret
	                                          //test_force_killer:
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xF0, 0xFB, 0x43, 0x00,             //mov         eax,43FBF0h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0x44, 0x24, 0x20,                   //cmp         eax,dword ptr [esp+20h]
	0x74, 0x01,                               //je          regarded_building
	0xC3,                                     //ret
	                                          //regarded_building:
	0x68, 0x8E, 0x31, 0x4A, 0x00,             //push        4A318Eh
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeSaveHarborThunk[] = {0xE8, 0x54, 0x02, 0xC0, 0xFF};//dwAddrSaveHarbor - 4A316Fh - 5
BYTE codeSaveHarborOldThunk[] = {0xE8, 0x5C, 0x22, 0xF9, 0xFF};//call 4353D0h()
ASM_PATCH patchSaveHarborThunk[] = {
	{0x4A316F, sizeof(codeSaveHarborThunk), codeSaveHarborThunk},
	{0x4A316F, sizeof(codeSaveHarborOldThunk), codeSaveHarborOldThunk}};

//goto npc city
DWORD dwAddrGotoNpcCity = dwAddrStackBottom + 0x2260;
BYTE codeGotoNpcCity[] = {
	0x51,                                     //push        ecx
	0x6A, 0x01,                               //push        1
	0x6A, 0x0B,                               //push        0Bh
	0x6A, 0x02,                               //push        2
	0xFF, 0x15, 0x18, 0xF3, 0x5F, 0x00,       //call        [5FF318h]
	0x83, 0xC4, 0x0C,                         //add         esp,0Ch
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x07,                               //je          goto_npc_city
	                                          //normal:
	0x59,                                     //pop         ecx
	0x68, 0x00, 0xE9, 0x46, 0x00,             //push        46E900h
	0xC3,                                     //ret
	                                          //goto_npc_city:
	0x59,                                     //pop         ecx
	0x51,                                     //push        ecx
	0x8B, 0x51, 0x04,                         //mov         edx,dword ptr [ecx+4]
	                                          //loop_building:
	0x8B, 0x4A, 0x08,                         //mov         ecx,dword ptr [edx+8]
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0C,                               //je          next_building
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x74, 0x29,                               //je          got_goal_zone
	                                          //next_building:
	0x8B, 0x12,                               //mov         edx,dword ptr [edx]
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0xE1,                               //jne         loop_building
	0x8B, 0x86, 0xF4, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0F4h]
	0x8B, 0x48, 0x64,                         //mov         ecx,dword ptr [eax+64h]
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0xC8,                               //je          normal
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xBE,                               //je          normal
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x75, 0xB2,                               //jne         normal
	                                          //got_goal_zone:
	0x58,                                     //pop         eax
	0x8B, 0xC1,                               //mov         eax,ecx
	0xC3                                      //ret
};

BYTE codeGotoNpcCityThunk[] = {0xE8, 0x8A, 0xFA, 0xC4, 0xFF};//dwAddrGotoNpcCity - 4527D1h - 5
BYTE codeGotoNpcCityOldThunk[] = {0xE8, 0x2A, 0xC1, 0x01, 0x00};//call 46E900h()
ASM_PATCH patchGotoNpcCityThunk[] = {
	{0x4527D1, sizeof(codeGotoNpcCityThunk), codeGotoNpcCityThunk},
	{0x4527D1, sizeof(codeGotoNpcCityOldThunk), codeGotoNpcCityOldThunk}};

//new force soldier
DWORD dwAddrNewForceSoldier = dwAddrStackBottom + 0x5C40;
BYTE codeNewForceSoldier[] = {
	0x8B, 0x87, 0xE8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edi+0E8h]
	0x40,                                     //inc         eax
	0x40,                                     //inc         eax
	0x69, 0xC0, 0x88, 0x13, 0x00, 0x00,       //imul        eax,eax,1388h
	0x03, 0xC6,                               //add         eax,esi
	0x89, 0x44, 0x24, 0x04,                   //mov         dword ptr [esp+4],eax
	0x68, 0xA0, 0x73, 0x43, 0x00,             //push        4373A0h
	0xC3                                      //ret
};

BYTE codeNewForceSoldierThunk[] = {0xE8, 0xA8, 0x18, 0xC6, 0xFF};//dwAddrNewForceSoldier - 444393h - 5
BYTE codeNewForceSoldierOldThunk[] = {0xE8, 0x08, 0x30, 0xFF, 0xFF};//call 4373A0h()
ASM_PATCH patchNewForceSoldierThunk[] = {
	{0x444393, sizeof(codeNewForceSoldierThunk), codeNewForceSoldierThunk},
	{0x444393, sizeof(codeNewForceSoldierOldThunk), codeNewForceSoldierOldThunk}};

///////////////////////////////////////////////////////////////////////////////////
//                               军师推荐
/////////////////////////////////////////////////////////////////////////
DWORD dwAddrCounselorAdvise = dwAddrStackBottom + 0x2300;
BYTE codeCounselorAdvise[] = {
	                                          //counselor_advise:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x8B, 0xF1,                               //mov         esi,ecx
	0x8B, 0x7C, 0x24, 0x14,                   //mov         edi,dword ptr [esp+14h]
	0x8B, 0x5C, 0x24, 0x18,                   //mov         ebx,dword ptr [esp+18h]
	0x8B, 0x6C, 0x24, 0x1C,                   //mov         ebp,dword ptr [esp+1Ch]
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x56,                                     //push        esi
	0xFF, 0x37,                               //push        dword ptr [edi]
	0x33, 0xC0,                               //xor         eax,eax
	0x89, 0x07,                               //mov         [edi],eax
	0xA3, 0x77, 0xF1, 0x43, 0x00,             //mov         [search_person_pointer],eax
	0x81, 0xC6, 0xB4, 0x06, 0x00, 0x00,       //add         esi,6B4h
	0x8B, 0x76, 0x04,                         //mov         esi,dword ptr [esi+4]
	                                          //loop_person:
	0xFF, 0x77, 0x04,                         //push        dword ptr [edi+4]
	0xFF, 0x76, 0x08,                         //push        dword ptr [esi+8]
	0x6A, 0x00,                               //push        0
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xFF, 0xD3,                               //call        ebx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x80, 0x64, 0x48, 0x00,             //mov         eax,486480h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x03,                               //cmp         al,3
	0x74, 0x19,                               //je          next_person
	0x83, 0x3F, 0x00,                         //cmp         dword ptr[edi],0
	0x75, 0x05,                               //jne         save_multi_advise
	0x8B, 0x46, 0x08,                         //mov         eax,dword ptr [esi+8]
	0x89, 0x07,                               //mov         dword ptr [edi],eax
	                                          //save_multi_advise:
	0xFF, 0x76, 0x08,                         //push        dword ptr[esi+8]
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx,multi_search_person_list
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xC8,                               //jne         loop_person
	                                          //end_loop_person:
	0x58,                                     //pop         eax
	0x83, 0x3F, 0x00,                         //cmp         dword ptr[edi],0
	0x75, 0x02,                               //jne         end
	0x89, 0x07,                               //mov         dword ptr [edi],eax
	                                          //end:
	0x59,                                     //pop         ecx
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0x6A, 0x01,                               //push        1
	0xFF, 0x90, 0xEC, 0x00, 0x00, 0x00,       //call        dword ptr [eax+0ECh]
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x0C, 0x00                          //ret         0Ch
};

//search counselor advise
DWORD dwAddrSearchCounselorAdvise = dwAddrStackBottom + 0xC40;
BYTE codeSearchCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xA0, 0x3E, 0x49, 0x00,             //push        493EA0h
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x07,                               //mov         eax,[edi]
	0x89, 0x44, 0x24, 0x08,                   //mov         [esp+8],eax
	0x68, 0xA0, 0x3E, 0x49, 0x00,             //push        493EA0h
	0xC3                                      //ret
};

BYTE codeSearchCounselorAdviseThunk[] = {0xE8, 0x63, 0x48, 0xBB, 0xFF};//dwAddrSearchCounselorAdvise - 4EC3D8h - 5
BYTE codeSearchCounselorAdviseOldThunk[] = {0xE8, 0xC3, 0x7A, 0xFA, 0xFF};//call 493EA0h()
ASM_PATCH patchSearchCounselorAdviseThunk[] = {
	{0x4EC3D8, sizeof(codeSearchCounselorAdviseThunk), codeSearchCounselorAdviseThunk},
	{0x4EC3D8, sizeof(codeSearchCounselorAdviseOldThunk), codeSearchCounselorAdviseOldThunk}};

//invite counselor adivse
DWORD dwAddrInviteCounselorAdvise = dwAddrStackBottom + 0x22D0;
BYTE codeInviteCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0x10, 0x4F, 0x49, 0x00,             //push        494F10h
	0x8D, 0x8D, 0x2C, 0xF9, 0xFF, 0xFF,       //lea         ecx,[ebp-6D4h]
	0x8D, 0x81, 0xD4, 0x12, 0x00, 0x00,       //lea         eax,[ecx+12D4h]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x85, 0x00, 0x0C, 0x00, 0x00,       //mov         eax,dword ptr [ebp+0C00h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0x10, 0x4F, 0x49, 0x00,             //push        494F10h
	0xC3                                      //ret
};

BYTE codeInviteCounselorAdviseThunk[] = {0xE8, 0x56, 0x52, 0xBB, 0xFF};//dwAddrInviteCounselorAdvise - 4ED075h - 5
BYTE codeInviteCounselorAdviseOldThunk[] = {0xE8, 0x96, 0x7E, 0xFA, 0xFF};//call 494F10h()
ASM_PATCH patchInviteCounselorAdviseThunk[] = {
	{0x4ED075, sizeof(codeInviteCounselorAdviseThunk), codeInviteCounselorAdviseThunk},
	{0x4ED075, sizeof(codeInviteCounselorAdviseOldThunk), codeInviteCounselorAdviseOldThunk}};

//false counselor adivse
DWORD dwAddrFalseCounselorAdvise = dwAddrStackBottom + 0x2450;
BYTE codeFalseCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xB0, 0xE9, 0x48, 0x00,             //push        48E9B0h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0xB0, 0xE9, 0x48, 0x00,             //push        48E9B0h
	0xC3                                      //ret
};

BYTE codeFalseCounselorAdviseThunk[] = {0xE8, 0xA4, 0x05, 0xBD, 0xFF};//dwAddrFalseCounselorAdvise - 4D1EA7h - 5
BYTE codeFalseCounselorAdviseOldThunk[] = {0xE8, 0x04, 0xCB, 0xFB, 0xFF};//call 48E9B0h
ASM_PATCH patchFalseCounselorAdviseThunk[] = {
	{0x4D1EA7, sizeof(codeFalseCounselorAdviseThunk), codeFalseCounselorAdviseThunk},
	{0x4D1EA7, sizeof(codeFalseCounselorAdviseOldThunk), codeFalseCounselorAdviseOldThunk}};
BYTE codeFalseCounselorAdvise2Thunk[] = {0xE8, 0x6E, 0x0D, 0xBD, 0xFF};//dwAddrFalseCounselorAdvise - 4D16DDh - 5
BYTE codeFalseCounselorAdvise2OldThunk[] = {0xE8, 0xCE, 0xD2, 0xFB, 0xFF};//call 48E9B0h
ASM_PATCH patchFalseCounselorAdvise2Thunk[] = {
	{0x4D16DD, sizeof(codeFalseCounselorAdvise2Thunk), codeFalseCounselorAdvise2Thunk},
	{0x4D16DD, sizeof(codeFalseCounselorAdvise2OldThunk), codeFalseCounselorAdvise2OldThunk}};

//disorder counselor adivse
DWORD dwAddrDisorderCounselorAdvise = dwAddrStackBottom + 0x2600;
BYTE codeDisorderCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xF0, 0x07, 0x49, 0x00,             //push        4907F0h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0xF0, 0x07, 0x49, 0x00,             //push        4907F0h
	0xC3                                      //ret
};

BYTE codeDisorderCounselorAdviseThunk[] = {0xE8, 0x94, 0x67, 0xBC, 0xFF};//dwAddrDisorderCounselorAdvise - 4DBE67h - 5
BYTE codeDisorderCounselorAdviseOldThunk[] = {0xE8, 0x84, 0x49, 0xFB, 0xFF};//call 4907F0h
ASM_PATCH patchDisorderCounselorAdviseThunk[] = {
	{0x4DBE67, sizeof(codeDisorderCounselorAdviseThunk), codeDisorderCounselorAdviseThunk},
	{0x4DBE67, sizeof(codeDisorderCounselorAdviseOldThunk), codeDisorderCounselorAdviseOldThunk}};
BYTE codeDisorderCounselorAdvise2Thunk[] = {0xE8, 0x7E, 0x6E, 0xBC, 0xFF};//dwAddrDisorderCounselorAdvise - 4DB77Dh - 5
BYTE codeDisorderCounselorAdvise2OldThunk[] = {0xE8, 0x6E, 0x50, 0xFB, 0xFF};//call 4907F0h
ASM_PATCH patchDisorderCounselorAdvise2Thunk[] = {
	{0x4DB77D, sizeof(codeDisorderCounselorAdvise2Thunk), codeDisorderCounselorAdvise2Thunk},
	{0x4DB77D, sizeof(codeDisorderCounselorAdvise2OldThunk), codeDisorderCounselorAdvise2OldThunk}};

//save counselor adivse
DWORD dwAddrSaveCounselorAdvise = dwAddrStackBottom + 0x2520;
BYTE codeSaveCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xC0, 0x26, 0x49, 0x00,             //push        4926C0h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0xC0, 0x26, 0x49, 0x00,             //push        4926C0h
	0xC3                                      //ret
};

BYTE codeSaveCounselorAdviseThunk[] = {0xE8, 0x31, 0x1E, 0xBC, 0xFF};//dwAddrSaveCounselorAdvise - 4E06EAh - 5
BYTE codeSaveCounselorAdviseOldThunk[] = {0xE8, 0xD1, 0x1F, 0xFB, 0xFF};//call 4926C0h
ASM_PATCH patchSaveCounselorAdviseThunk[] = {
	{0x4E06EA, sizeof(codeSaveCounselorAdviseThunk), codeSaveCounselorAdviseThunk},
	{0x4E06EA, sizeof(codeSaveCounselorAdviseOldThunk), codeSaveCounselorAdviseOldThunk}};
BYTE codeSaveCounselorAdvise2Thunk[] = {0xE8, 0xDE, 0x24, 0xBC, 0xFF};//dwAddrSaveCounselorAdvise - 4E003Dh - 5
BYTE codeSaveCounselorAdvise2OldThunk[] = {0xE8, 0x7E, 0x26, 0xFB, 0xFF};//call 4926C0h
ASM_PATCH patchSaveCounselorAdvise2Thunk[] = {
	{0x4E003D, sizeof(codeSaveCounselorAdvise2Thunk), codeSaveCounselorAdvise2Thunk},
	{0x4E003D, sizeof(codeSaveCounselorAdvise2OldThunk), codeSaveCounselorAdvise2OldThunk}};

//inspire counselor adivse
DWORD dwAddrInspireCounselorAdvise = dwAddrStackBottom + 0x35D0;
BYTE codeInspireCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0x20, 0xE4, 0x48, 0x00,             //push        48E420h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0x20, 0xE4, 0x48, 0x00,             //push        48E420h
	0xC3                                      //ret
};

BYTE codeInspireCounselorAdviseThunk[] = {0xE8, 0xD1, 0x27, 0xBD, 0xFF};//dwAddrInspireCounselorAdvise - 4D0DFAh - 5
BYTE codeInspireCounselorAdviseOldThunk[] = {0xE8, 0x21, 0xD6, 0xFB, 0xFF};//call 48E420h
ASM_PATCH patchInspireCounselorAdviseThunk[] = {
	{0x4D0DFA, sizeof(codeInspireCounselorAdviseThunk), codeInspireCounselorAdviseThunk},
	{0x4D0DFA, sizeof(codeInspireCounselorAdviseOldThunk), codeInspireCounselorAdviseOldThunk}};
BYTE codeInspireCounselorAdvise2Thunk[] = {0xE8, 0x3E, 0x2F, 0xBD, 0xFF};//dwAddrInspireCounselorAdvise - 4D068Dh - 5
BYTE codeInspireCounselorAdvise2OldThunk[] = {0xE8, 0x8E, 0xDD, 0xFB, 0xFF};//call 48E420h
ASM_PATCH patchInspireCounselorAdvise2Thunk[] = {
	{0x4D068D, sizeof(codeInspireCounselorAdvise2Thunk), codeInspireCounselorAdvise2Thunk},
	{0x4D068D, sizeof(codeInspireCounselorAdvise2OldThunk), codeInspireCounselorAdvise2OldThunk}};

//rob counselor adivse
DWORD dwAddrRobCounselorAdvise = dwAddrStackBottom + 0x36C0;
BYTE codeRobCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xB0, 0xD5, 0x48, 0x00,             //push        48D5B0h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0xB0, 0xD5, 0x48, 0x00,             //push        48D5B0h
	0xC3                                      //ret
};

BYTE codeRobCounselorAdviseThunk[] = {0xE8, 0x4E, 0x35, 0xBD, 0xFF};//dwAddrRobCounselorAdvise - 4D016Dh - 5
BYTE codeRobCounselorAdviseOldThunk[] = {0xE8, 0x3E, 0xD4, 0xFB, 0xFF};//call 48D5B0h
ASM_PATCH patchRobCounselorAdviseThunk[] = {
	{0x4D016D, sizeof(codeRobCounselorAdviseThunk), codeRobCounselorAdviseThunk},
	{0x4D016D, sizeof(codeRobCounselorAdviseOldThunk), codeRobCounselorAdviseOldThunk}};
BYTE codeRobCounselorAdvise2Thunk[] = {0xE8, 0xAE, 0x3B, 0xBD, 0xFF};//dwAddrRobCounselorAdvise - 4CFB0Dh - 5
BYTE codeRobCounselorAdvise2OldThunk[] = {0xE8, 0x9E, 0xDA, 0xFB, 0xFF};//call 48D5B0h
ASM_PATCH patchRobCounselorAdvise2Thunk[] = {
	{0x4CFB0D, sizeof(codeRobCounselorAdvise2Thunk), codeRobCounselorAdvise2Thunk},
	{0x4CFB0D, sizeof(codeRobCounselorAdvise2OldThunk), codeRobCounselorAdvise2OldThunk}};

//burn counselor adivse
DWORD dwAddrBurnCounselorAdvise = dwAddrStackBottom + 0x3700;
BYTE codeBurnCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0x50, 0x62, 0x49, 0x00,             //push        496250h
	0x8D, 0x86, 0xF4, 0x06, 0x00, 0x00,       //lea         eax,[esi+6F4h]
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x86, 0xF4, 0x06, 0x00, 0x00,       //mov         eax,dword ptr [esi+6F4h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0x50, 0x62, 0x49, 0x00,             //push        496250h
	0xC3                                      //ret
};

BYTE codeBurnCounselorAdviseThunk[] = {0xE8, 0xAE, 0x4D, 0xBB, 0xFF};//dwAddrBurnCounselorAdvise - 4EE94Dh - 5
BYTE codeBurnCounselorAdviseOldThunk[] = {0xE8, 0xFE, 0x78, 0xFA, 0xFF};//call 496250h
ASM_PATCH patchBurnCounselorAdviseThunk[] = {
	{0x4EE94D, sizeof(codeBurnCounselorAdviseThunk), codeBurnCounselorAdviseThunk},
	{0x4EE94D, sizeof(codeBurnCounselorAdviseOldThunk), codeBurnCounselorAdviseOldThunk}};
BYTE codeBurnCounselorAdvise2Thunk[] = {0xE8, 0xAE, 0x53, 0xBB, 0xFF};//dwAddrBurnCounselorAdvise - 4EE34Dh - 5
BYTE codeBurnCounselorAdvise2OldThunk[] = {0xE8, 0xFE, 0x7E, 0xFA, 0xFF};//call 496250h
ASM_PATCH patchBurnCounselorAdvise2Thunk[] = {
	{0x4EE34D, sizeof(codeBurnCounselorAdvise2Thunk), codeBurnCounselorAdvise2Thunk},
	{0x4EE34D, sizeof(codeBurnCounselorAdvise2OldThunk), codeBurnCounselorAdvise2OldThunk}};

//alienate counselor adivse
DWORD dwAddrAlienateCounselorAdvise = dwAddrStackBottom + 0x1750;
BYTE codeAlienateCounselorAdvise[] = {
	0x51,                                     //push        ecx
	0x51,                                     //push        ecx
	0x68, 0xD0, 0x31, 0x49, 0x00,             //push        4931D0h
	0x8D, 0x8D, 0x2C, 0xF9, 0xFF, 0xFF,       //lea         ecx,[ebp-6D4h]
	0x8D, 0x81, 0x08, 0x14, 0x00, 0x00,       //lea         eax,[ecx+1408h]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x23, 0x0A, 0x00,             //mov         eax,counselor_advise
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x85, 0x34, 0x0D, 0x00, 0x00,       //mov         eax,dword ptr [ebp+0D34h]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0xD0, 0x31, 0x49, 0x00,             //push        4931D0h
	0xC3                                      //ret
};

BYTE codeAlienateCounselorAdviseThunk[] = {0xE8, 0x59, 0x05, 0xBC, 0xFF};//dwAddrAlienateCounselorAdvise - 4E11F2h - 5
BYTE codeAlienateCounselorAdviseOldThunk[] = {0xE8, 0xD9, 0x1F, 0xFB, 0xFF};//call 4931D0h
ASM_PATCH patchAlienateCounselorAdviseThunk[] = {
	{0x4E11F2, sizeof(codeAlienateCounselorAdviseThunk), codeAlienateCounselorAdviseThunk},
	{0x4E11F2, sizeof(codeAlienateCounselorAdviseOldThunk), codeAlienateCounselorAdviseOldThunk}};

//multi select window
DWORD dwAddrMultiSelectWindow = dwAddrStackBottom + 0x2390;
BYTE codeMultiSelectWindow[] = {
	                                          //multi_select_person_window:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x8B, 0x74, 0x24, 0x14,                   //mov         esi,dword ptr [esp+14h]
	0xBF, 0x00, 0x05, 0x0A, 0x00,             //mov         edi,multi_search_person_list
	0x8B, 0x5C, 0x24, 0x10,                   //mov         ebx,dword ptr [esp+10h]
	0x81, 0xC1, 0xB4, 0x06, 0x00, 0x00,       //add         ecx,6B4h
	0x6A, 0x00,                               //push        0
	0x6A, 0x01,                               //push        1
	0x56,                                     //push        esi
	0x68, 0x65, 0x1F, 0x00, 0x00,             //push        1F65h
	0xFF, 0x71, 0x0C,                         //push        dword ptr [ecx+0Ch]
	0x51,                                     //push        ecx
	0x57,                                     //push        edi
	0xB8, 0xD8, 0x23, 0x0A, 0x00,             //mov         eax,sort_multi_select_person
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x1C,                         //add         esp,1Ch
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0D,                               //je          end
	0x8B, 0x47, 0x04,                         //mov         eax,dword ptr [edi+4]
	0x8B, 0x50, 0x08,                         //mov         edx,dword ptr [eax+8]
	0x89, 0x13,                               //mov         dword ptr [ebx],edx
	0xA3, 0x77, 0xF1, 0x43, 0x00,             //mov         [search_person_pointer],eax
	                                          //end:
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x08, 0x00                          //ret         8
};

//invite multi select
DWORD dwAddrInviteMultiSelect = dwAddrStackBottom + 0x2400;
BYTE codeInviteMultiSelect[] = {
	0xC7, 0x05, 0x10, 0xC6, 0x61, 0x00, 0xB5, 0x6E, 0xB1, 0x65,//mov [61C610h], 65B16EB5h
	0x68, 0x28, 0xC6, 0x66, 0x00,             //push        66C628h
	0x55,                                     //push        ebp
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0x10, 0xC6, 0x61, 0x00, 0xB0, 0xD3, 0xB7, 0x7E,//mov [61C610h], 7EB7D3B0h
	0xC3                                      //ret
};

BYTE codeInviteMultiSelectThunk[] = {0xE8, 0x4D, 0x53, 0xBB, 0xFF};//dwAddrInviteMultiSelect - 4ED0AEh - 5
BYTE codeInviteMultiSelectOldThunk[] = {0xE8, 0xCD, 0x32, 0x08, 0x00};//call 570380h()
ASM_PATCH patchInviteMultiSelectThunk[] = {
	{0x4ED0AE, sizeof(codeInviteMultiSelectThunk), codeInviteMultiSelectThunk},
	{0x4ED0AE, sizeof(codeInviteMultiSelectOldThunk), codeInviteMultiSelectOldThunk}};

//save multi select
DWORD dwAddrSaveMultiSelect = dwAddrStackBottom + 0x3830;
BYTE codeSaveMultiSelect[] = {
	0x53,                                     //push        ebx
	0xC7, 0x05, 0x8C, 0xC0, 0x61, 0x00, 0xB1, 0xCF, 0xB4, 0xA9,//mov [61C08Ch], A9B4CFB1h
	0xBB, 0x00, 0x05, 0x0A, 0x00,             //mov         ebx,multi_search_person_list
	0x6A, 0x00,                               //push        0
	0x6A, 0x01,                               //push        1
	0x68, 0x4C, 0xC6, 0x66, 0x00,             //push        66C64Ch
	0x68, 0x65, 0x1F, 0x00, 0x00,             //push        1F65h
	0xFF, 0x75, 0x0C,                         //push        [ebp+0Ch]
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0xD8, 0x23, 0x0A, 0x00,             //mov         eax,sort_multi_select_person
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x1C,                         //add         esp,1Ch
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x3A,                               //je          end
	0x8B, 0x0D, 0x74, 0x24, 0x23, 0x01,       //mov         ecx,[1232474h]
	0x8B, 0x81, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+88h]
	0x99,                                     //cdq
	0xB9, 0xB8, 0x0B, 0x00, 0x00,             //mov         ecx,0BB8h
	0xF7, 0xF1,                               //div         eax,ecx
	0x2B, 0x43, 0x0C,                         //sub         eax,dword ptr [ebx+0Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x12,                               //jge         normal
	0xF7, 0xD8,                               //neg         eax
	0x56,                                     //push        esi
	0x8B, 0xF0,                               //mov         esi,eax
	                                          //loop_del_surplus_person:
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x80, 0x7B, 0x43, 0x00,             //mov         eax,437B80h
	0xFF, 0xD0,                               //call        eax
	0x4E,                                     //dec         esi
	0x75, 0xF4,                               //jne         loop_del_surplus_person
	0x5E,                                     //pop         esi
	                                          //normal:
	0x8B, 0x43, 0x04,                         //mov         eax,dword ptr [ebx+4]
	0x8B, 0x50, 0x08,                         //mov         edx,dword ptr [eax+8]
	0x89, 0x17,                               //mov         dword ptr [edi],edx
	0xA3, 0x77, 0xF1, 0x43, 0x00,             //mov         [search_person_pointer], eax
	                                          //end:
	0xC7, 0x05, 0x8C, 0xC0, 0x61, 0x00, 0xBC, 0x78, 0xA7, 0x4C,//mov [61C08Ch], 4CA778BCh
	0x5B,                                     //pop         ebx
	0xC3                                      //ret

};

BYTE codeSaveMultiSelectThunk[] = {0xE8, 0x80, 0x3B, 0xBC, 0xFF};//dwAddrSaveMultiSelect - 4DFCABh - 5
BYTE codeSaveMultiSelectOldThunk[] = {0xE8, 0xD0, 0x06, 0x09, 0x00};//call 570380h()
ASM_PATCH patchSaveMultiSelectThunk[] = {
	{0x4DFCAB, sizeof(codeSaveMultiSelectThunk), codeSaveMultiSelectThunk},
	{0x4DFCAB, sizeof(codeSaveMultiSelectOldThunk), codeSaveMultiSelectOldThunk}};

//rob multi select
DWORD dwAddrRobMultiSelect = dwAddrStackBottom + 0x3758;
BYTE codeRobMultiSelect[] = {
	0xC7, 0x05, 0xF8, 0xC5, 0x61, 0x00, 0xB9, 0xDC, 0xA8, 0xFA,//mov [61C5F8h], FAA8DCB9h
	0x68, 0x58, 0xC6, 0x66, 0x00,             //push        66C658h
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0xF8, 0xC5, 0x61, 0x00, 0xB0, 0x56, 0xBD, 0x6D,//mov [61C5F8h], 6DBD56B0h
	0xC3                                      //ret
};

BYTE codeRobMultiSelectThunk[] = {0xE8, 0x98, 0x3F, 0xBD, 0xFF};//dwAddrRobMultiSelect - 4CF7BBh - 5
BYTE codeRobMultiSelectOldThunk[] = {0xE8, 0xC0, 0x0B, 0x0A, 0x00};//call 570380h()
ASM_PATCH patchRobMultiSelectThunk[] = {
	{0x4CF7BB, sizeof(codeRobMultiSelectThunk), codeRobMultiSelectThunk},
	{0x4CF7BB, sizeof(codeRobMultiSelectOldThunk), codeRobMultiSelectOldThunk}};

//burn multi select
DWORD dwAddrBurnMultiSelect = dwAddrStackBottom + 0x3780;
BYTE codeBurnMultiSelect[] = {
	0xC7, 0x05, 0xF8, 0xC5, 0x61, 0x00, 0xBF, 0x4E, 0xA6, 0x69,//mov [61C5F8h], 69A64EBFh
	0x68, 0x58, 0xC6, 0x66, 0x00,             //push        66C658h
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0xF8, 0xC5, 0x61, 0x00, 0xB0, 0x56, 0xBD, 0x6D,//mov [61C5F8h], 6DBD56B0h
	0xC3                                      //ret
};

BYTE codeBurnMultiSelectThunk[] = {0xE8, 0xD0, 0x57, 0xBB, 0xFF};//dwAddrBurnMultiSelect - 4EDFABh - 5
BYTE codeBurnMultiSelectOldThunk[] = {0xE8, 0xD0, 0x23, 0x08, 0x00};//call 570380h()
ASM_PATCH patchBurnMultiSelectThunk[] = {
	{0x4EDFAB, sizeof(codeBurnMultiSelectThunk), codeBurnMultiSelectThunk},
	{0x4EDFAB, sizeof(codeBurnMultiSelectOldThunk), codeBurnMultiSelectOldThunk}};

//sub anti trick
DWORD dwAddrSubAntiTrick = dwAddrStackBottom + 0x2480;
BYTE codeSubAntiTrick[] = {
	0xB8, 0x15, 0x00, 0x00, 0x00,             //mov         eax,15h
	0x80, 0x3C, 0x24, 0x8D,                   //cmp         byte ptr [esp],8Dh
	0x74, 0x01,                               //je          check_troop_killer
	0x40,                                     //inc         eax
	                                          //check_troop_killer:
	0x51,                                     //push        ecx
	0x50,                                     //push        eax
	0x8B, 0x4E, 0x40,                         //mov         ecx,[esi+40h]
	0xB8, 0x90, 0x2A, 0x46, 0x00,             //mov         eax,462A90h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x03,                               //je          end
	0x83, 0xE9, 0x56,                         //sub         ecx,56h
	                                          //end:
	0xB8, 0x78, 0x77, 0x77, 0x77,             //mov         eax,77777778h
	0xC3                                      //ret
};

BYTE codeSubAntiTrickThunk[] = {0xE8, 0x36, 0x38, 0xBA, 0xFF};//dwAddrSubAntiTrick - 4FEC45h - 5
BYTE codeSubAntiTrickOldThunk[] = {0xB8, 0x67, 0x66, 0x66, 0x66};//mov eax,66666667h
ASM_PATCH patchSubAntiTrickThunk[] = {
	{0x4FEC45, sizeof(codeSubAntiTrickThunk), codeSubAntiTrickThunk},
	{0x4FEC45, sizeof(codeSubAntiTrickOldThunk), codeSubAntiTrickOldThunk}};
BYTE codeSubAntiTrapThunk[] = {0xE8, 0xF3, 0x36, 0xBA, 0xFF};//dwAddrSubAntiTrap - 4FED88h - 5
BYTE codeSubAntiTrapOldThunk[] = {0xB8, 0x67, 0x66, 0x66, 0x66};//mov eax,66666667h
ASM_PATCH patchSubAntiTrapThunk[] = {
	{0x4FED88, sizeof(codeSubAntiTrapThunk), codeSubAntiTrapThunk},
	{0x4FED88, sizeof(codeSubAntiTrapOldThunk), codeSubAntiTrapOldThunk}};

//max force food
DWORD dwAddrMaxForceFood = 0x4505C2;
BYTE codeMaxForceFood[] = {
	0xC7, 0x44, 0x24, 0x0C, 0xC0, 0xC6, 0x2D, 0x00,//mov    dword ptr [esp+0Ch],2DC6C0h
	0xFF, 0x25, 0x30, 0xF3, 0x5F, 0x00        //jmp         [5FF330h]
};

BYTE codeMaxForceFoodThunk[] = {0xE8, 0x8E, 0x2B, 0x01, 0x00, 0x41};//dwAddrMaxForceFood - 43DA2Fh - 5
BYTE codeMaxForceFoodOldThunk[] = {0xFF, 0x15, 0x30, 0xF3, 0x5F, 0x00};//call [5FF330h]
ASM_PATCH patchMaxForceFoodThunk[] = {
	{0x43DA2F, sizeof(codeMaxForceFoodThunk), codeMaxForceFoodThunk},
	{0x43DA2F, sizeof(codeMaxForceFoodOldThunk), codeMaxForceFoodOldThunk}};

//fight to killer
DWORD dwAddrFightToKiller = dwAddrStackBottom + 0x2640;
BYTE codeFightToKiller[] = {
	0x8B, 0x03,                               //mov         eax,[ebx]
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xFF, 0x50, 0x64,                         //call        [eax+64h]
	0x8B, 0x40, 0x38,                         //mov         eax,dword ptr [eax+38h]
	0x83, 0xE8, 0x50,                         //sub         eax,50h
	0x01, 0x44, 0x24, 0x04,                   //add         dword ptr [esp+4],eax
	0xFF, 0x25, 0xF0, 0xF2, 0x5F, 0x00        //jmp         [5FF2F0h]
};

BYTE codeFightToKillerThunk[] = {0xE8, 0x5D, 0x74, 0xC0, 0xFF, 0x42};//dwAddrFightToKiller - 49B1DEh - 5
BYTE codeFightToKillerOldThunk[] = {0xFF, 0x15, 0xF0, 0xF2, 0x5F, 0x00};//call [5FF2F0h]
ASM_PATCH patchFightToKillerThunk[] = {
	{0x49B1DE, sizeof(codeFightToKillerThunk), codeFightToKillerThunk},
	{0x49B1DE, sizeof(codeFightToKillerOldThunk), codeFightToKillerOldThunk}};

//draft min money
DWORD dwAddrDraftMinMoney = dwAddrStackBottom + 0x2A70;
BYTE codeDraftMinMoney[] = {
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0x8B, 0x91, 0x84, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [ecx+84h]
	0x42,                                     //inc         edx
	0xC1, 0xE2, 0x0A,                         //shl         edx,0Ah
	0x03, 0xC2,                               //add         eax,edx
	0xC3                                      //ret
};

BYTE codeDraftMinMoneyThunk[] = {0xE8, 0x7F, 0x2F, 0xC0, 0xFF};//dwAddrDraftMinMoney - 49FAECh - 5
BYTE codeDraftMinMoneyOldThunk[] = {0x05, 0xE8, 0x03, 0x00, 0x00};//add eax,3E8h
ASM_PATCH patchDraftMinMoneyThunk[] = {
	{0x49FAEC, sizeof(codeDraftMinMoneyThunk), codeDraftMinMoneyThunk},
	{0x49FAEC, sizeof(codeDraftMinMoneyOldThunk), codeDraftMinMoneyOldThunk}};

//attack min money
DWORD dwAddrAttackMinMoney = dwAddrStackBottom + 0x24A8;
BYTE codeAttackMinMoney[] = {
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr[eax+34h],4
	0x74, 0x04,                               //je          normal
	0x83, 0xF8, 0x00,                         //cmp         eax,0
	0xC3,                                     //ret
	                                          //normal:
	0x50,                                     //push        eax
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0xB0, 0xD9, 0x43, 0x00,             //mov         eax,43D9B0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x91, 0x84, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [ecx+84h]
	0x80, 0xFA, 0x02,                         //cmp         dl,2
	0x7D, 0x02,                               //jge         test_max_city
	0xB2, 0x02,                               //mov         dl,2
	                                          //test_max_city:
	0x80, 0xFA, 0x0A,                         //cmp         dl,0Ah
	0x7E, 0x02,                               //jle         get_min_force_money
	0xB2, 0x0A,                               //mov         dl,0Ah
	                                          //get_min_force_money:
	0xC1, 0xE2, 0x0B,                         //shl         edx,0Bh
	0x03, 0xC2,                               //add         eax,edx
	0x39, 0x41, 0x14,                         //cmp         dword ptr [ecx+14h],eax
	0x7D, 0x01,                               //jge         test_force_food
	0xC3,                                     //ret
	                                          //test_force_food:
	0x51,                                     //push        ecx
	0xB8, 0x90, 0x4B, 0x45, 0x00,             //mov         eax,454B90h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x83, 0xC0, 0x3C,                         //add         eax,3Ch
	0x51,                                     //push        ecx
	0x50,                                     //push        eax
	0xB8, 0xE0, 0xED, 0x43, 0x00,             //mov         eax,43EDE0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x39, 0x41, 0x18,                         //cmp         dword ptr [ecx+18h],eax
	0x7D, 0x01,                               //jge         normal
	0xC3,                                     //ret
	                                          //normal:
	0x51,                                     //push        ecx
	0xB8, 0xD0, 0xF4, 0x43, 0x00,             //mov         eax,43F4D0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0xF6, 0x41, 0x0D, 0x01,                   //test        byte ptr[ecx+0Dh],1
	0x75, 0x05,                               //jnz         weak_force
	0x6B, 0xC0, 0x0A,                         //imul        eax,eax,0Ah
	0xEB, 0x03,                               //jmp         get_pre_city_num
	                                          //weak_force:
	0x6B, 0xC0, 0x10,                         //imul        eax,eax,10h
	                                          //get_pre_city_num:
	0xC1, 0xE8, 0x05,                         //shr         eax,5
	                                          //end:
	0x3B, 0x81, 0x84, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [ecx+84h]
	0xC3                                      //ret
};

BYTE codeAttackMinMoneyThunk[] = {0xE8, 0xFC, 0xCE, 0xBE, 0xFF, 0x90, 0x90};//dwAddrAttackMinMoney - 4B55A7h - 5
BYTE codeAttackMinMoneyOldThunk[] = {0x81, 0x78, 0x14, 0xF4, 0x01, 0x00, 0x00};//cmp [eax+14],1F4h
ASM_PATCH patchAttackMinMoneyThunk[] = {
	{0x4B55A7, sizeof(codeAttackMinMoneyThunk), codeAttackMinMoneyThunk},
	{0x4B55A7, sizeof(codeAttackMinMoneyOldThunk), codeAttackMinMoneyOldThunk}};

//safe arrive day
DWORD dwAddrSafeArriveDay = dwAddrStackBottom + 0x2428;
BYTE codeSafeArriveDay[] = {
	                                          //safe_arrive_day:
	0x83, 0x79, 0x30, 0x00,                   //cmp         dword ptr[ecx+30h],0
	0x74, 0x06,                               //je          null_troop
	0x68, 0x70, 0x88, 0x46, 0x00,             //push        468870h
	0xC3,                                     //ret
	                                          //null_troop:
	0xB8, 0x64, 0x00, 0x00, 0x00,             //mov         eax,64h
	0xC2, 0x04, 0x00                          //ret         4
};

//gossip to player
DWORD dwAddrGossipToPlayer = dwAddrStackBottom + 0x2660;
BYTE codeGossipToPlayer[] = {
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          test_source_force
	0xC3,                                     //ret
	                                          //test_source_force:
	0x8B, 0x4E, 0x40,                         //mov         ecx,dword ptr [esi+40h]
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0xC3                                      //ret
};

BYTE codeGossipToPlayerThunk[] = {0xE8, 0x14, 0xE9, 0xC0, 0xFF};//dwAddrGossipToPlayer - 493D47h - 5
BYTE codeGossipToPlayerOldThunk[] = {0x8B, 0x01, 0xFF, 0x50, 0x3C};//mov eax,[ecx];call [eax+3Ch]
ASM_PATCH patchGossipToPlayerThunk[] = {
	{0x493D47, sizeof(codeGossipToPlayerThunk), codeGossipToPlayerThunk},
	{0x493D47, sizeof(codeGossipToPlayerOldThunk), codeGossipToPlayerOldThunk}};

//pre building soldier
DWORD dwAddrPreBuildingSoldier = dwAddrStackBottom + 0x2550;
BYTE codePreBuildingSoldier[] = {
	                                          //pre_building_soldier:
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x08,                   //mov         esi,[esp+8]
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xC0, 0x3C, 0x47, 0x00,             //mov         eax,473CC0h
	0xFF, 0xD0,                               //call        eax
	0x6A, 0x00,                               //push        0
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x20, 0x6A, 0x43, 0x00,             //mov         eax,436A20h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0x68, 0x60, 0x45, 0x47, 0x00,             //push        474560h
	0xB8, 0x80, 0x17, 0x0A, 0x00,             //mov         eax,building_anti_attack_troop
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0x50,                                     //push        eax
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0xC6, 0x05, 0xD2, 0x19, 0x0A, 0x00, 0xEB, //mov         byte ptr[get_building_backup+test_distance],0EBh
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x19, 0x0A, 0x00,             //mov         eax,get_building_backup
	0xFF, 0xD0,                               //call        eax
	0xC6, 0x05, 0xD2, 0x19, 0x0A, 0x00, 0x7E, //mov         byte ptr[get_building_backup+test_distance],7Eh
	0x59,                                     //pop         ecx
	0x03, 0xC1,                               //add         eax,ecx
	0x03, 0x86, 0x88, 0x00, 0x00, 0x00,       //add         eax,dword ptr [esi+88h]
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codePreBuildingSoldierThunk[] = {0x68, 0x50, 0x25, 0x0A, 0x00, 0xC3};//push pre_building_soldier;ret
BYTE codePreBuildingSoldierOldThunk[] = {0x6A, 0xFF, 0x68, 0x30, 0x78, 0x5E};//push 0FFh...
ASM_PATCH patchPreBuildingSoldierThunk[] = {
	{0x4A12A0, sizeof(codePreBuildingSoldierThunk), codePreBuildingSoldierThunk},
	{0x4A12A0, sizeof(codePreBuildingSoldierOldThunk), codePreBuildingSoldierOldThunk}};

//go on attack
DWORD dwAddrGoOnAttack = dwAddrStackBottom + 0xF0;
BYTE codeGoOnAttack[] = {
	                                          //go_on_attack:
	0x81, 0xB9, 0x88, 0x00, 0x00, 0x00, 0x40, 0x1F, 0x00, 0x00,//cmp dword ptr [ecx+88h],1F40h
	0x7F, 0x09,                               //jg          normal
	0xF6, 0x41, 0x7A, 0x40,                   //test        byte ptr[ecx+7Ah],40h
	0x74, 0x03,                               //je          normal
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //normal:
	0x51,                                     //push        ecx
	0xB8, 0x00, 0x36, 0x0A, 0x00,             //mov         eax,degrade_snake_troop
	0xFF, 0xD0,                               //call        eax
	0x29, 0x44, 0x24, 0x08,                   //sub         [esp+8],eax
	0xB8, 0x00, 0x02, 0x0A, 0x00,             //mov         eax,pre_building_soldier3
	0xFF, 0xD0,                               //call        eax
	0x33, 0xC9,                               //xor         ecx,ecx
	0x6B, 0xC0, 0x2C,                         //imul        eax,eax,2Ch
	0xC1, 0xE8, 0x06,                         //shr         eax,6
	0x3B, 0x44, 0x24, 0x04,                   //cmp         eax,[esp+4]
	0x0F, 0x9C, 0xC1,                         //setl        cl
	0x8B, 0xC1,                               //mov         eax,ecx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0D,                               //je          end
	0x8B, 0x4C, 0x24, 0xFC,                   //mov         ecx,[esp-4]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x66, 0x0A, 0x00,             //mov         eax,adjust_attack_array
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

//degrade snake troop
DWORD dwAddrDegradeSnakeTroop = dwAddrStackBottom + 0x3600;
BYTE codeDegradeSnakeTroop[] = {
	                                          //degrade_snake_troop:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x48,                                     //dec         eax
	0x8B, 0xF8,                               //mov         edi,eax
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x35, 0x24, 0x05, 0x0A, 0x00,       //mov         esi,[attack_troop_list+4]
	                                          //loop_attack_troop:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x41, 0x6C,                         //mov         eax,dword ptr [ecx+6Ch]
	0x80, 0x78, 0x04, 0x06,                   //cmp         byte ptr [eax+4],6
	0x75, 0x1C,                               //jne         next_attack_troop
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0x11,                               //jne         sub_snake_troop
	0x8B, 0x49, 0x78,                         //mov         ecx,dword ptr [ecx+78h]
	0xB8, 0x40, 0xCC, 0x45, 0x00,             //mov         eax,45CC40h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0A,                               //jne         next_attack_troop
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	                                          //sub_snake_troop:
	0x8B, 0x41, 0x30,                         //mov         eax,dword ptr [ecx+30h]
	0xD1, 0xE8,                               //shr         eax,1
	0x03, 0xD8,                               //add         ebx,eax
	                                          //next_attack_troop:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xD2,                               //jne         loop_attack_troop
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//pre building soldier 3
DWORD dwAddrPreBuildingSoldier3 = dwAddrStackBottom + 0x0200;
BYTE codePreBuildingSoldier3[] = {
	                                          //pre_building_soldier3:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x33, 0xDB,                               //xor         ebx,ebx
	0xBE, 0xB0, 0x93, 0x4B, 0x01,             //mov         esi,14B93B0h
	                                          //loop_troop:
	0x8A, 0x46, 0x56,                         //mov         al,byte ptr [esi+56h]
	0x3C, 0xFF,                               //cmp         al,0FFh
	0x74, 0x26,                               //je          test_troop_goal
	0x3C, 0x03,                               //cmp         al,3
	0x75, 0x62,                               //jne         next_troop
	0x0F, 0xB7, 0x46, 0x54,                   //movzx       eax,word ptr [esi+54h]
	0x69, 0xC0, 0x04, 0x01, 0x00, 0x00,       //imul        eax,eax,104h
	0x05, 0xB0, 0x93, 0x4B, 0x01,             //add         eax,14B93B0h
	0x50,                                     //push        eax
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x3F,                               //jne         add_attack_soldier
	0xEB, 0x40,                               //jmp         next_troop
	                                          //test_troop_goal:
	0x80, 0x7E, 0x58, 0x26,                   //cmp         byte ptr [esi+58h],26h
	0x75, 0x3A,                               //jne         next_troop
	0x80, 0x7E, 0x52, 0x03,                   //cmp         byte ptr [esi+52h],3
	0x75, 0x34,                               //jne         next_troop
	0x0F, 0xB7, 0x46, 0x50,                   //movzx       eax,word ptr [esi+50h]
	0x69, 0xC0, 0x04, 0x01, 0x00, 0x00,       //imul        eax,eax,104h
	0x05, 0xB0, 0x93, 0x4B, 0x01,             //add         eax,14B93B0h
	0x50,                                     //push        eax
	0x50,                                     //push        eax
	0xB9, 0x20, 0x05, 0x0A, 0x00,             //mov         ecx,attack_troop_list
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,                                     //pop         ecx
	0x74, 0x12,                               //je          next_troop
	0x56,                                     //push        esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x3D, 0x32, 0x00, 0x00, 0x00,             //cmp         eax,32h
	0x7F, 0x03,                               //jg          next_troop
	                                          //add_attack_soldier:
	0x03, 0x5E, 0x30,                         //add         ebx,dword ptr [esi+30h]
	                                          //next_troop:
	0x81, 0xC6, 0x04, 0x01, 0x00, 0x00,       //add         esi,104h
	0x66, 0x81, 0x7E, 0x04, 0x51, 0x03,       //cmp         word ptr [esi+4],351h
	0x7C, 0x85,                               //jl          loop_troop
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0xB8, 0x90, 0x19, 0x0A, 0x00,             //mov         eax,get_building_backup
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x5A,                                     //pop         edx
	0x03, 0xC2,                               //add         eax,edx
	0x03, 0x81, 0x88, 0x00, 0x00, 0x00,       //add         eax,dword ptr [ecx+88h]
	0xC2, 0x04, 0x00                          //ret         4
};

//filter building soldier
DWORD dwAddrFilterBuildingSoldier = dwAddrStackBottom + 0x2BA8;
BYTE codeFilterBuildingSoldier[] = {
	0x56,                                     //push        esi
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0x80, 0x57, 0x43, 0x00,             //mov         eax,435780h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x06,                               //je          discard_other_force_soldier
	0x68, 0x40, 0x5A, 0x0A, 0x00,             //push        pre_building_soldier2
	0xC3,                                     //ret
	                                          //discard_other_force_soldier:
	0x33, 0xC0,                               //xor         eax,eax
	0xC2, 0x04, 0x00,                         //ret         4
};

BYTE codeFilterBuildingSoldierThunk[] = {0xE8, 0xDD, 0xCD, 0xBE, 0xFF};//dwAddrFilterBuildingSoldier - 4B5DC6h - 5
BYTE codeFilterBuildingSoldierOldThunk[] = {0xE8, 0x25, 0xF7, 0xFF, 0xFF};//call 4B54F0h()
ASM_PATCH patchFilterBuildingSoldierThunk[] = {
	{0x4B5DC6, sizeof(codeFilterBuildingSoldierThunk), codeFilterBuildingSoldierThunk},
	{0x4B5DC6, sizeof(codeFilterBuildingSoldierOldThunk), codeFilterBuildingSoldierOldThunk}};

//near null city
DWORD dwAddrNearNullCity = dwAddrStackBottom + 0x3C60;
BYTE codeNearNullCity[] = {
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0xA8, 0x01,                               //test        al,1
	0x74, 0x05,                               //je          select_null_city
	0x33, 0xC0,                               //xor         eax,eax
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //select_null_city:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x57,                                     //push        edi
	0x8B, 0x6C, 0x24, 0x18,                   //mov         ebp,dword ptr [esp+18h]
	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0x4C, 0x24, 0x14,                   //mov         ecx,[esp+14h]
	0x8B, 0x71, 0x04,                         //mov         esi,dword ptr [ecx+4]
	0xBB, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         ebx,7FFFFFFFh
	                                          //loop_city:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0xB8, 0x40, 0x58, 0x43, 0x00,             //mov         eax,435840h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x1B,                               //je          next_city
	0x6A, 0x1A,                               //push        1Ah
	0x6A, 0x1A,                               //push        1Ah
	0xFF, 0x76, 0x08,                         //push        dword ptr [esi+8]
	0x55,                                     //push        ebp
	0xB8, 0x80, 0xA6, 0x44, 0x00,             //mov         eax,44A680h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7D, 0x05,                               //jge         next_city
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0x7E, 0x08,                         //mov         edi,dword ptr [esi+8]
	                                          //next_city:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xD1,                               //jne         loop_city
	0x8B, 0xC7,                               //mov         eax,edi
	0x5F,                                     //pop         edi
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeNearNullCityThunk[] = {0xE8, 0x53, 0xDA, 0xBE, 0xFF};//dwAddrNearNullCity - 4B6208h - 5
BYTE codeNearNullCityOldThunk[] = {0xE8, 0xB3, 0xFE, 0xFF, 0xFF};//call 4B60C0h
ASM_PATCH patchNearNullCityThunk[] = {
	{0x4B6208, sizeof(codeNearNullCityThunk), codeNearNullCityThunk},
	{0x4B6208, sizeof(codeNearNullCityOldThunk), codeNearNullCityOldThunk}};

//set force goal
DWORD dwAddrSetForceGoal = 0x45CCE5;
BYTE codeSetForceGoal[] = {
	0x8B, 0x84, 0x24, 0xC0, 0x00, 0x00, 0x00, //mov         eax,[esp+0C0h]
	0x8B, 0x40, 0x08,                         //mov         eax,[eax+8]
	0xC3                                      //ret
};

BYTE codeSetForceGoalThunk[] = {0xE8, 0x6D, 0x46, 0xFB, 0xFF};//45CCE5h - 4A8673h - 5
BYTE codeSetForceGoalOldThunk[] = {0xE8, 0x08, 0xE2, 0xF5, 0xFF};//call 406880h()
ASM_PATCH patchSetForceGoalThunk[] = {
	{0x4A8673, sizeof(codeSetForceGoalThunk), codeSetForceGoalThunk},
	{0x4A8673, sizeof(codeSetForceGoalOldThunk), codeSetForceGoalOldThunk}};

//get player city
DWORD dwAddrGetPlayerCity = dwAddrStackBottom + 0x2800;
BYTE codeGetPlayerCity[] = {
	0x8B, 0x46, 0x38,                         //mov         eax,dword ptr [esi+38h]
	0x83, 0x78, 0x24, 0x02,                   //cmp         dword ptr[eax+24h],2
	0x7C, 0x06,                               //jl          common_force
	0x68, 0x60, 0x5E, 0x4B, 0x00,             //push        4B5E60h
	0xC3,                                     //ret
	                                          //common_force:
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x74, 0x05,                               //je          allie_attack_player
	0x33, 0xC0,                               //xor         eax,eax
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //allie_attack_player:
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x53,                                     //push        ebx
	0x57,                                     //push        edi
	0x8B, 0x59, 0x04,                         //mov         ebx,dword ptr [ecx+4]
	                                          //loop_city:
	0x8B, 0x7B, 0x08,                         //mov         edi,dword ptr [ebx+8]
	0x8B, 0x97, 0xCC, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [edi+0CCh]
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x7F,                               //je          next_city
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr [edx+34h],1
	0x74, 0x79,                               //je          next_city
	0x52,                                     //push        edx
	0xFF, 0x76, 0x38,                         //push        dword ptr [esi+38h]
	0xB8, 0x70, 0x06, 0x4B, 0x00,             //mov         eax,4B0670h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x67,                               //je          next_city
	0x0F, 0xB6, 0x47, 0x04,                   //movzx       eax,byte ptr [edi+4]
	0x80, 0xB8, 0x00, 0x0D, 0x0A, 0x00, 0x09, //cmp         byte ptr [eax+building_attacked_coef],09h
	0x7D, 0x64,                               //jge         end_city_loop
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0x70, 0xC9, 0x46, 0x00,             //mov         eax,46C970h
	0xFF, 0xD0,                               //call        eax
	0x57,                                     //push        edi
	0x50,                                     //push        eax
	0xB8, 0x40, 0x5C, 0x47, 0x00,             //mov         eax,475C400h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,[esp+4]
	                                          //loop_border_area:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x2B,                               //je          end_border_area
	0x8B, 0x51, 0x08,                         //mov         edx,dword ptr [ecx+8]
	0x8B, 0x82, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edx+0CCh]
	0x3B, 0x87, 0xCC, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [edi+0CCh]
	0x75, 0x16,                               //jne         next_border_area
	0x0F, 0xB6, 0x42, 0x04,                   //movzx       eax,byte ptr [edx+4]
	0x80, 0x7A, 0x06, 0x05,                   //cmp         byte ptr [edx+6],5
	0x74, 0x0C,                               //je          next_border_area
	0x83, 0xC0, 0x32,                         //add         eax,32h
	0x80, 0xB8, 0x00, 0x0D, 0x0A, 0x00, 0x09, //cmp         byte ptr [eax+building_attacked_coef],09h
	0x7D, 0x04,                               //jge         end_border_area
	                                          //next_border_area:
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xD1,                               //jmp         loop_border_area
	                                          //end_border_area:
	0x8B, 0xF9,                               //mov         edi,ecx
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0x0A,                               //jne         end_city_loop
	                                          //next_city:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0x85, 0xDB,                               //test        ebx,ebx
	0x0F, 0x85, 0x6A, 0xFF, 0xFF, 0xFF,       //jne         loop_city
	                                          //end_city_loop:
	0x33, 0xC0,                               //xor         eax,eax
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x03,                               //je          got_player_city
	0x8B, 0x43, 0x08,                         //mov         eax,dword ptr [ebx+8]
	                                          //got_player_city:
	0x5F,                                     //pop         edi
	0x5B,                                     //pop         ebx
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeGetPlayerCityThunk[] = {0xE8, 0x0E, 0xC6, 0xBE, 0xFF};//dwAddrGetPlayerCity - 4B61EDh - 5
BYTE codeGetPlayerCityOldThunk[] = {0xE8, 0x6E, 0xFC, 0xFF, 0xFF};//call 4B5E60h
ASM_PATCH patchGetPlayerCityThunk[] = {
	{0x4B61ED, sizeof(codeGetPlayerCityThunk), codeGetPlayerCityThunk},
	{0x4B61ED, sizeof(codeGetPlayerCityOldThunk), codeGetPlayerCityOldThunk}};

//allie attack
DWORD dwAddrAllieAttack = dwAddrStackBottom + 0x28D0;
BYTE codeAllieAttack[] = {
	0x8B, 0xB7, 0xB8, 0x00, 0x00, 0x00,       //mov         esi,dword ptr [edi+0B8h]
	0x3B, 0xC6,                               //cmp         eax,esi
	0x75, 0x01,                               //jne         check_player_force
	0xC3,                                     //ret
	                                          //check_player_force:
	0x8B, 0x8C, 0x24, 0x88, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+88h]
	0x8B, 0x89, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0CCh]
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x06,                               //je          end
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr [ecx+34h],1
	0x75, 0x03,                               //jne         check_source_force
	                                          //end:
	0x3B, 0xC6,                               //cmp         eax,esi
	0xC3,                                     //ret
	                                          //check_source_force:
	0x3B, 0xC0,                               //cmp         eax,eax
	0xC3                                      //ret
};

BYTE codeAllieAttackThunk[] = {0xE8, 0x31, 0xE7, 0xBE, 0xFF, 0x90};//dwAddrAllieAttack - 4B419Ah - 5
BYTE codeAllieAttackOldThunk[] = {0x3B, 0x87, 0xB8, 0x00, 0x00, 0x00};//cmp eax,[edi+0B8h]
ASM_PATCH patchAllieAttackThunk[] = {
	{0x4B419A, sizeof(codeAllieAttackThunk), codeAllieAttackThunk},
	{0x4B419A, sizeof(codeAllieAttackOldThunk), codeAllieAttackOldThunk}};

//attack null building
DWORD dwAddrAttackNullBuilding = dwAddrStackBottom + 0x26D0;
BYTE codeAttackNullBuilding[] = {
	0xF6, 0x42, 0x34, 0x04,                   //test        byte ptr [edx+34h],4
	0x75, 0x0D,                               //jne         normal
	0x8B, 0x86, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x03,                               //jne         normal
	0xB0, 0x01,                               //mov         al,1
	0xC3,                                     //ret
	                                          //normal:
	0x68, 0x00, 0x07, 0x4B, 0x00,             //push        4B0700h
	0xC3,                                     //ret
};

BYTE codeAttackNullBuildingThunk[] = {0xE8, 0x1D, 0xE3, 0xBE, 0xFF};//dwAddrAttackNullBuilding - 4B43AEh - 5
BYTE codeAttackNullBuildingOldThunk[] = {0xE8, 0x4D, 0xC3, 0xFF, 0xFF};//call 4B0700h()
ASM_PATCH patchAttackNullBuildingThunk[] = {
	{0x4B43AE, sizeof(codeAttackNullBuildingThunk), codeAttackNullBuildingThunk},
	{0x4B43AE, sizeof(codeAttackNullBuildingOldThunk), codeAttackNullBuildingOldThunk}};

//null building array
DWORD dwAddrNullBuildingArray = dwAddrStackBottom + 0x2A80;
BYTE codeNullBuildingArray[] = {
	0x81, 0xBF, 0x88, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00,//cmp dword ptr [edi+88h],0BB8h
	0x7E, 0x06,                               //jle         use_array_snake
	0x68, 0x60, 0x77, 0x4B, 0x00,             //push        4B7760h
	0xC3,                                     //ret
	                                          //use_array_snake:
	0x68, 0x6C, 0x87, 0x4B, 0x00,             //push        4B876Ch
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeNullBuildingArrayThunk[] = {0xE8, 0x24, 0xA3, 0xBE, 0xFF};//dwAddrNullBuildingArray - 4B8757h - 5
BYTE codeNullBuildingArrayOldThunk[] = {0xE8, 0x04, 0xF0, 0xFF, 0xFF};//call 4B7760h()
ASM_PATCH patchNullBuildingArrayThunk[] = {
	{0x4B8757, sizeof(codeNullBuildingArrayThunk), codeNullBuildingArrayThunk},
	{0x4B8757, sizeof(codeNullBuildingArrayOldThunk), codeNullBuildingArrayOldThunk}};

//attack source city
DWORD dwAddrAttackSourceCity = dwAddrStackBottom + 0x3DD8;
BYTE codeAttackSourceCity[] = {
	0xC6, 0x05, 0xC8, 0xF4, 0x43, 0x00, 0x00, //mov         byte ptr[check_soldier_flag],0
	0x89, 0x3D, 0x0C, 0xFC, 0x43, 0x00,       //mov         [reserved_source_city],edi
	0x3B, 0xC7,                               //cmp         eax,edi
	0x75, 0x0D,                               //jne         normal
	0x8B, 0x80, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0CCh]
	0x3B, 0x46, 0x38,                         //cmp         eax,dword ptr [esi+38h]
	0x74, 0x02,                               //je          normal
	0x33, 0xFF,                               //xor         edi,edi
	                                          //normal:
	0x68, 0x40, 0x58, 0x40, 0x00,             //push        405840h
	0xC3                                      //ret
};

BYTE codeAttackSourceCityThunk[] = {0xE8, 0x48, 0xD9, 0xBE, 0xFF};//dwAddrAttackSourceCity - 4B648Bh - 5
BYTE codeAttackSourceCityOldThunk[] = {0xE8, 0xB0, 0xF3, 0xF4, 0xFF};//call 405840h()
ASM_PATCH patchAttackSourceCityThunk[] = {
	{0x4B648B, sizeof(codeAttackSourceCityThunk), codeAttackSourceCityThunk},
	{0x4B648B, sizeof(codeAttackSourceCityOldThunk), codeAttackSourceCityOldThunk}};

//circle attack building
DWORD dwAddrCircleAttackBuilding = 0x46B9F1;
BYTE codeCircleAttackBuilding[] = {
	0x6A, 0x01,                               //push        1
	0x6A, 0x00,                               //push        0
	0x52,                                     //push        edx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xC0, 0xB1, 0x43, 0x00,             //mov         eax,43B1C0h
	0xFF, 0xD0,                               //call        eax
	0xC3                                      //ret
};

BYTE codeCircleAttackBuildingThunk[] = {0xE8, 0x76, 0x68, 0xFB, 0xFF};//dwAddrCircleAttackBuilding - 4B5176h - 5
BYTE codeCircleAttackBuildingOldThunk[] = {0xE8, 0xA5, 0xA7, 0xFF, 0xFF};//call 4AF920h()
ASM_PATCH patchCircleAttackBuildingThunk[] = {
	{0x4B5176, sizeof(codeCircleAttackBuildingThunk), codeCircleAttackBuildingThunk},
	{0x4B5176, sizeof(codeCircleAttackBuildingOldThunk), codeCircleAttackBuildingOldThunk}};

//select attack building
DWORD dwAddrSelectAttackBuilding = dwAddrStackBottom + 0x2900;
BYTE codeSelectAttackBuilding[] = {
	0x56,                                     //push        esi
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x03,                               //je          test_baram_force
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_baram_force:
	0x8B, 0x4C, 0x24, 0x24,                   //mov         ecx,[esp+24h]
	0xF6, 0x41, 0x34, 0x04,                   //test        byte ptr[ecx+34h],4
	0x75, 0xF3,                               //jne         end
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0xBA, 0x10, 0x27, 0x00, 0x00,             //mov         edx,2710h
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x06,                               //jg          got_building_min_soldier
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x02,                               //je          got_building_min_soldier
	0xD1, 0xE2,                               //shl         edx,1
	                                          //got_building_min_soldier:
	0xB0, 0x01,                               //mov         al,1
	0x39, 0x96, 0x88, 0x00, 0x00, 0x00,       //cmp         dword ptr [esi+88h],edx
	0x7C, 0xD1,                               //jl          end
	0x8B, 0x4C, 0x24, 0x20,                   //mov         ecx,dword ptr [esp+20h]
	0xB8, 0xA0, 0xC8, 0x45, 0x00,             //mov         eax,45C8A0h
	0xFF, 0xD0,                               //call        eax
	0x6A, 0x0C,                               //push        0Ch
	0x81, 0xB8, 0x88, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00,//cmp dword ptr [eax+88h],0BB8h
	0x7F, 0x09,                               //jg          normal
	0x6A, 0x14,                               //push        14h
	0xBF, 0x1E, 0x00, 0x00, 0x00,             //mov         edi,1Eh
	0xEB, 0x10,                               //jmp         get_arrive_day
	                                          //normal:
	0x6A, 0x0B,                               //push        0Bh
	0x8B, 0x48, 0x44,                         //mov         ecx,dword ptr [eax+44h]
	0x0F, 0xB6, 0x51, 0x04,                   //movzx       edx,byte ptr [ecx+4]
	0x0F, 0xB6, 0xBA, 0xC0, 0x3C, 0x0A, 0x00, //movzx       edi,byte ptr [edx+attack_max_arrive_day]
	                                          //get_arrive_day:
	0x50,                                     //push        eax
	0x56,                                     //push        esi
	0xB8, 0x80, 0xA6, 0x44, 0x00,             //mov         eax,44A680h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x33, 0xC9,                               //xor         ecx,ecx
	0x3B, 0xC7,                               //cmp         eax,edi
	0x0F, 0x9F, 0xC1,                         //setg        cl
	0x8B, 0xC1,                               //mov         eax,ecx
	0xC2, 0x04, 0x00,                         //ret         4
};

BYTE codeSelectAttackBuildingThunk[] = {0xE8, 0xDB, 0xD5, 0xBE, 0xFF};//dwAddrSelectAttackBuilding - 4B5320h - 5
BYTE codeSelectAttackBuildingOldThunk[] = {0xE8, 0x3B, 0x98, 0xFB, 0xFF};//call 46EB60h
ASM_PATCH patchSelectAttackBuildingThunk[] = {
	{0x4B5320, sizeof(codeSelectAttackBuildingThunk), codeSelectAttackBuildingThunk},
	{0x4B5320, sizeof(codeSelectAttackBuildingOldThunk), codeSelectAttackBuildingOldThunk}};

//attack min person
DWORD dwAddrAttackMinPerson = dwAddrStackBottom + 0x2990;
BYTE codeAttackMinPerson[] = {
	0x52,                                     //push        edx
	0x8B, 0x4C, 0x24, 0x5C,                   //mov         ecx,dword ptr [esp+5Ch]
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0x74, 0x24, 0x5C,                   //mov         esi,dword ptr [esp+5Ch]
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x05,                               //jg          end
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          end
	0x4A,                                     //dec         edx
	                                          //end:
	0xC3                                      //ret
};

BYTE codeAttackMinPersonThunk[] = {0xE8, 0xE8, 0xAD, 0xBE, 0xFF};//dwAddrAttackMinPerson - 4B7BA3h - 5
BYTE codeAttackMinPersonOldThunk[] = {0x8B, 0x74, 0x24, 0x58, 0x4A};//mov esi,[esp+58h];dec edx
ASM_PATCH patchAttackMinPersonThunk[] = {
	{0x4B7BA3, sizeof(codeAttackMinPersonThunk), codeAttackMinPersonThunk},
	{0x4B7BA3, sizeof(codeAttackMinPersonOldThunk), codeAttackMinPersonOldThunk}};

//add city relation
DWORD dwAddrAddCityRelation = dwAddrStackBottom + 0x2A00;
BYTE codeAddCityRelation[] = {
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8B, 0xF8,                               //mov         edi,eax
	0x0F, 0xB7, 0x6E, 0x04,                   //movzx       ebp,word ptr [esi+4]
	0xC1, 0xE5, 0x03,                         //shl         ebp,3
	0x81, 0xC5, 0x00, 0x6E, 0x0A, 0x00,       //add         ebp,city_relation_table
	0x33, 0xDB,                               //xor         ebx,ebx
	                                          //loop_city_table:
	0x0F, 0xB6, 0x45, 0x00,                   //movzx       eax,byte ptr [ebp]
	0x50,                                     //push        eax
	0xB8, 0xB0, 0xD7, 0x46, 0x00,             //mov         eax,46D7B0h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC6,                               //cmp         eax,esi
	0x74, 0x27,                               //je          next_city_relation
	0x50,                                     //push        eax
	0xB8, 0x40, 0x58, 0x40, 0x00,             //mov         eax,405840h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x74, 0x1A,                               //je          next_city_relation
	0x50,                                     //push        eax
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x75, 0x0A,                               //jne         next_city_relation
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_city_relation:
	0x45,                                     //inc         ebp
	0x43,                                     //inc         ebx
	0x80, 0xFB, 0x08,                         //cmp         bl,8
	0x7C, 0xC2,                               //jl          loop_city_table
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x58,                                     //pop         eax
	0x68, 0x0B, 0xB0, 0x43, 0x00,             //push        43B00Bh
	0xC3                                      //ret
};

BYTE codeAddCityRelationThunk[] = {0xE8, 0x2B, 0x7A, 0xC6, 0xFF};//dwAddrAddCityRelation - 43AFD0h - 5
BYTE codeAddCityRelationOldThunk[] = {0xE8, 0x0B, 0xB8, 0x00, 0x00};//call 4467E0h()
ASM_PATCH patchAddCityRelationThunk[] = {
	{0x43AFD0, sizeof(codeAddCityRelationThunk), codeAddCityRelationThunk},
	{0x43AFD0, sizeof(codeAddCityRelationOldThunk), codeAddCityRelationOldThunk}};

//test not null city
DWORD dwAddrTestNotNullCity = dwAddrStackBottom + 0x39B0;
BYTE codeTestNotNullCity[] = {
	0x8B, 0x4B, 0x38,                         //mov         ecx,dword ptr [ebx+38h]
	0x83, 0x79, 0x24, 0x04,                   //cmp         dword ptr [ecx+24h],4
	0x7C, 0x03,                               //jl          common_force
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //common_force:
	0x56,                                     //push        esi
	0x55,                                     //push        ebp
	0xB8, 0x00, 0x07, 0x4B, 0x00,             //mov         eax,4B0700h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         test_goal_city_more
	0xC3,                                     //ret
	                                          //test_goal_city_more:
	0x8B, 0x4B, 0x38,                         //mov         ecx,dword ptr [ebx+38h]
	0x56,                                     //push        esi
	0xB8, 0x80, 0x20, 0x0A, 0x00,             //mov         eax,test_attack_goal_force
	0xFF, 0xD0,                               //call        eax
	0xC3                                      //ret
};

BYTE codeTestNotNullCityThunk[] = {0xE8, 0x72, 0xD8, 0xBE, 0xFF};//dwAddrTestNotNullCity - 4B6139h - 5
BYTE codeTestNotNullCityOldThunk[] = {0xE8, 0xC2, 0xA5, 0xFF, 0xFF};//call 4B0700h()
ASM_PATCH patchTestNotNullCityThunk[] = {
	{0x4B6139, sizeof(codeTestNotNullCityThunk), codeTestNotNullCityThunk},
	{0x4B6139, sizeof(codeTestNotNullCityOldThunk), codeTestNotNullCityOldThunk}};

//test attack goal force
DWORD dwAddrTestAttackGoalForce = dwAddrStackBottom + 0x2080;
BYTE codeTestAttackGoalForce[] = {
	                                          //test_attack_goal_force:
	0x56,                                     //push        esi
	0x8B, 0x54, 0x24, 0x08,                   //mov         edx,dword ptr [esp+8]
	0x8B, 0x82, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edx+0CCh]
	0x8B, 0xB0, 0xB8, 0x00, 0x00, 0x00,       //mov         esi,dword ptr [eax+0B8h]
	0xF6, 0x46, 0x34, 0x01,                   //test        byte ptr [esi+34h],1
	0x74, 0x04,                               //je          get_force_goal
											  //end:
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00,                         //ret         4
											  //get_force_goal:
	0x8B, 0x51, 0x0C,                         //mov         edx,dword ptr [ecx+0Ch]
	0xC1, 0xEA, 0x0C,                         //shr         edx,0Ch
	0x8B, 0xC2,                               //mov         eax,edx
	0x24, 0x0F,                               //and         al,0Fh
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x09,                               //jne         test_force_diploma
	0xC1, 0xEA, 0x04,                         //shr         edx,4
	0x4A,                                     //dec         edx
	0x3A, 0x56, 0x04,                         //cmp         dl,byte ptr [esi+4]
	0x74, 0xE5,                               //je          end
	                                          //test_force_diploma:
	0x8B, 0x81, 0xBC, 0x00, 0x00, 0x00,       //mov         eax,[ecx+0BCh]
	0xFF, 0x70, 0x74,                         //push        dword ptr[eax+74h]
	0x56,                                     //push        esi
	0xB8, 0x60, 0x14, 0x44, 0x00,             //mov         eax,441460h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xE8, 0x3C,                         //sub         eax,3Ch
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,								  //test        eax,eax
	0x5A,									  //pop         edx
	0x7E, 0x2C,								  //jle         fail
	0x8A, 0x0D, 0xCC, 0xF4, 0x43, 0x00,		  //mov         cl,[npc_attack_intensive]
	0x84, 0xC9,								  //test        cl,cl
	0x74, 0x07,								  //je          get_leader_ambition
	0xC1, 0xE0, 0x04,						  //shl         eax,4
	0xD3, 0xE8,								  //shr         eax,cl
	0xEB, 0x11,								  //jmp         judge_if_attack
											  //get_leader_ambition:
	0xC1, 0xE8, 0x01,                         //shr         eax,1
	0x83, 0xEA, 0x05,                         //sub         edx,5
	0x85, 0xD2,                               //test        edx,edx
	0x7D, 0x02,                               //jge         get_chaos_fight_p
	0x33, 0xD2,                               //xor         edx,edx
	                                          //get_chaos_fight_p:
	0x6B, 0xD2, 0x07,                         //imul        edx,7
	0x03, 0xC2,                               //add         eax,edx
											  //judge_if_attack:
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,								  //jmp         end2
											  //fail:
	0x33, 0xC0,								  //xor         eax,eax
	                                          //end2:
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

//reserve attacked building
DWORD dwAddrReserveAttackedBuilding = dwAddrStackBottom + 0x3990;
BYTE codeReserveAttackedBuilding[] = {
	0x8B, 0x70, 0x08,                         //mov         esi,dword ptr [eax+8]
	0x8B, 0x38,                               //mov         edi,dword ptr [eax]
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x10,                               //je          end
	0x8B, 0x7F, 0x08,                         //mov         edi,dword ptr [edi+8]
	0x89, 0x3D, 0x08, 0xFC, 0x43, 0x00,       //mov         [reserved_attacked_building],edi
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x0C, 0xFC, 0x43, 0x00,             //mov         [reserved_source_city],eax
	                                          //end:
	0x85, 0xF6,                               //test        esi,esi
	0xC3                                      //ret
};

BYTE codeReserveAttackedBuildingThunk[] = {0xE8, 0x83, 0xDB, 0xBE, 0xFF};//dwAddrReserveAttackedBuilding - 4B5E08h - 5
BYTE codeReserveAttackedBuildingOldThunk[] = {0x8B, 0x70, 0x08, 0x85, 0xF6};//mov esi,[eax+8];test esi,esi
ASM_PATCH patchReserveAttackedBuildingThunk[] = {
	{0x4B5E08, sizeof(codeReserveAttackedBuildingThunk), codeReserveAttackedBuildingThunk},
	{0x4B5E08, sizeof(codeReserveAttackedBuildingOldThunk), codeReserveAttackedBuildingOldThunk}};

//retry attack building
DWORD dwAddrRetryAttackedBuilding = dwAddrStackBottom + 0x1D00;
BYTE codeRetryAttackedBuilding[] = {
	0xA1, 0x08, 0xFC, 0x43, 0x00,             //mov         eax,[reserved_attacked_building]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x1B,                               //je          normal
	0x8B, 0xD8,                               //mov         ebx,eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x08, 0xFC, 0x43, 0x00,             //mov         [reserved_attacked_building],eax
	0xA1, 0x0C, 0xFC, 0x43, 0x00,             //mov         eax,[reserved_source_city]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x09,                               //je          normal
	0x8B, 0xF8,                               //mov         edi,eax
	0x58,                                     //pop         eax
	0x68, 0xCB, 0x63, 0x4B, 0x00,             //push        4B63CBh
	0xC3,                                     //ret
	                                          //normal:
	0x8B, 0x86, 0x24, 0x08, 0x00, 0x00,       //mov         eax,dword ptr [esi+824h]
	0xC3                                      //ret
};

BYTE codeRetryAttackedBuildingThunk[] = {0xE8, 0x47, 0xB7, 0xBE, 0xFF, 0x90};//dwAddrRetryAttackedBuilding - 4B65B4h - 5
BYTE codeRetryAttackedBuildingOldThunk[] = {0x8B, 0x86, 0x24, 0x08, 0x00, 0x00};//mov eax,[esi+824h]
ASM_PATCH patchRetryAttackedBuildingThunk[] = {
	{0x4B65B4, sizeof(codeRetryAttackedBuildingThunk), codeRetryAttackedBuildingThunk},
	{0x4B65B4, sizeof(codeRetryAttackedBuildingOldThunk), codeRetryAttackedBuildingOldThunk}};

//test regarded building
DWORD dwAddrTestRegardedBuilding = dwAddrStackBottom + 0x3D00;
BYTE codeTestRegardedBuilding[] = {
                                              //test_regarded_building:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x8B, 0xF1,                               //mov         esi,ecx
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0x70, 0xC9, 0x46, 0x00,             //mov         eax,46C970h
	0xFF, 0xD0,                               //call        eax
	0x56,                                     //push        esi
	0x50,                                     //push        eax
	0xB8, 0x40, 0x5C, 0x47, 0x00,             //mov         eax,475C40h
	0xFF, 0xD0,                               //call        eax
	0xBB, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         ebx,7FFFFFFFh
	0x8B, 0xEB,                               //mov         ebp,ebx
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_near_zone_list:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x34,                               //je          end_loop_near_zone_list
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x80, 0x79, 0x06, 0x05,                   //cmp         byte ptr [ecx+6],5
	0x75, 0x27,                               //jne         next_near_zone
	0x56,                                     //push        esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0x56,                                     //push        esi
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0x80, 0x57, 0x43, 0x00,             //mov         eax,435780h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x74, 0x08,                               //je          none_self_city
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7D, 0x02,                               //jge         skip_next_near_zone
	0x8B, 0xD8,                               //mov         ebx,eax
	                                          //skip_next_near_zone:
	0xEB, 0x06,                               //jmp         next_near_zone											  
	                                          //none_self_city:
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7D, 0x02,                               //jge         next_near_zone
	0x8B, 0xE8,                               //mov         ebp,eax
	                                          //next_near_zone:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xEB, 0xC8,                               //jmp         loop_near_zone_list
	                                          //end_loop_near_zone_list:
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0x33, 0xC0,                               //xor         eax,eax
	0x83, 0xFB, 0x50,                         //cmp         ebx,50h
	0x7F, 0x04,                               //jg          test_none_self_city
	0xB0, 0x02,                               //mov         al,2
	0xEB, 0x07,                               //jmp         end
	                                          //test_none_self_city:
	0x83, 0xFB, 0x50,                         //cmp         ebx,50h
	0x7F, 0x02,                               //jg          end
	0xB0, 0x01,                               //mov         al,1
	                                          //end:
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//regarded building on attack
DWORD dwAddrRegardedBuildingOnAttack = dwAddrStackBottom + 0x3D90;
BYTE codeRegardedBuildingOnAttack[] = {
	0xC6, 0x05, 0xC8, 0xF4, 0x43, 0x00, 0x01, //mov         byte ptr[check_soldier_flag],1
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x04,                               //je          city_or_door
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x03,                               //jne         other_building
	                                          //city_or_door:
	0xB0, 0x01,                               //mov         al,1
	0xC3,                                     //ret
	                                          //other_building:
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x3D, 0x0A, 0x00,             //mov         eax,test_regarded_building
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x01,                               //cmp         al,1
	0xEB, 0x01,//jmp regarded_building
	//0x7D, 0x01,                               //jge         regarded_building
	0xC3,                                     //ret
	                                          //regarded_building:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x80, 0x4C, 0x85, 0x44, 0x80,             //or          byte ptr [ebp+eax*4+44h],80h
	0xC7, 0x44, 0x24, 0x20, 0x00, 0x10, 0x00, 0x00,//mov    dword ptr[esp+20h],1000h
	0x33, 0xC0,                               //xor         eax,eax
	0xC3                                      //ret
};

BYTE codeRegardedBuildingOnAttackThunk[] = {0xE8, 0xDA, 0xE4, 0xBE, 0xFF};//dwAddrRegardedBuildingOnAttack - 4B58B1h - 5
BYTE codeRegardedBuildingOnAttackOldThunk[] = {0xE8, 0xAA, 0x51, 0xF9, 0xFF};//call 44AA60h()
ASM_PATCH patchRegardedBuildingOnAttackThunk[] = {
	{0x4B58B1, sizeof(codeRegardedBuildingOnAttackThunk), codeRegardedBuildingOnAttackThunk},
	{0x4B58B1, sizeof(codeRegardedBuildingOnAttackOldThunk), codeRegardedBuildingOnAttackOldThunk}};

//regarded building on attack 2
DWORD dwAddrRegardedBuildingOnAttack2 = dwAddrStackBottom + 0x140;
BYTE codeRegardedBuildingOnAttack2[] = {
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x04,                               //je          city_or_door
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x03,                               //jne         other_building
	                                          //city_or_door:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //other_building:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0xF6, 0x05, 0xC8, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[check_soldier_flag],1
	0x74, 0x15,                               //je          do_test_regarded_building
	0xF6, 0x44, 0x83, 0x44, 0x80,             //test        byte ptr [ebx+eax*4+44h],80h
	0x75, 0x01,                               //jne         regarded_building
	0xC3,                                     //ret
	                                          //regarded_building:
	0xBB, 0x00, 0x10, 0x00, 0x00,             //mov         ebx,1000h
	0x68, 0xE6, 0x4B, 0x4B, 0x00,             //push        4B4BE6h
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //do_test_regarded_building:
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x3D, 0x0A, 0x00,             //mov         eax,test_regarded_building
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x01,                               //cmp         al,1
	0x58,                                     //pop         eax
	0xEB, 0x01,//jmp regarded_building2
	//0x7D, 0x01,                               //jge         regarded_building2
	0xC3,                                     //ret
	                                          //regarded_building2:
	0x80, 0x4C, 0x83, 0x44, 0x80,             //or          byte ptr [ebx+eax*4+44h],80h
	0xEB, 0xDC                                //jmp         regarded_building
};

BYTE codeRegardedBuildingOnAttack2Thunk[] = {0xE8, 0x73, 0xB5, 0xBE, 0xFF};//dwAddrRegardedBuildingOnAttack2 - 4B4BC8h - 5
BYTE codeRegardedBuildingOnAttack2OldThunk[] = {0xE8, 0x03, 0x08, 0xF8, 0xFF};//call 4353D0h()
ASM_PATCH patchRegardedBuildingOnAttack2Thunk[] = {
	{0x4B4BC8, sizeof(codeRegardedBuildingOnAttack2Thunk), codeRegardedBuildingOnAttack2Thunk},
	{0x4B4BC8, sizeof(codeRegardedBuildingOnAttack2OldThunk), codeRegardedBuildingOnAttack2OldThunk}};

//regarded building on attack 3
DWORD dwAddrRegardedBuildingOnAttack3 = dwAddrStackBottom + 0x29B0;
BYTE codeRegardedBuildingOnAttack3[] = {
	0x8B, 0xD8,                               //mov         ebx,eax
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x04,                               //je          city_or_door
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x05,                               //jne         other_building
	                                          //city_or_door:
	0x8B, 0xEB,                               //mov         ebp,ebx
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //other_building:
	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0xF6, 0x44, 0x85, 0x44, 0x80,             //test        byte ptr [ebp+eax*4+44h],80h
	0x8B, 0xEB,                               //mov         ebp,ebx
	0x75, 0x01,                               //jne         regarded_building
	0xC3,                                     //ret
	                                          //regarded_building:
	0xBB, 0x00, 0x10, 0x00, 0x00,             //mov         ebx,1000h
	0x68, 0x12, 0x4E, 0x4B, 0x00,             //push        4B4E12h
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeRegardedBuildingOnAttack3Thunk[] = {0x90, 0x90, 0xE8, 0xB7, 0xDB, 0xBE, 0xFF};//dwAddrRegardedBuildingOnAttack3 - 4B4DF2h - 5
BYTE codeRegardedBuildingOnAttack3OldThunk[] = {0x8B, 0xE8, 0xE8, 0xD7, 0x05, 0xF8, 0xFF};//mov ebp,eax;call 4353D0h()
ASM_PATCH patchRegardedBuildingOnAttack3Thunk[] = {
	{0x4B4DF2, sizeof(codeRegardedBuildingOnAttack3Thunk), codeRegardedBuildingOnAttack3Thunk},
	{0x4B4DF2, sizeof(codeRegardedBuildingOnAttack3OldThunk), codeRegardedBuildingOnAttack3OldThunk}};

//select attack person
DWORD dwAddrSelectAttackPerson = dwAddrStackBottom + 0x2C00;
BYTE codeSelectAttackPerson[] = {
	0x8B, 0x45, 0x38,                         //mov         eax,dword ptr [ebp+38h]
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr [eax+34h],4
	0x74, 0x06,                               //je          normal
	0x68, 0x90, 0x31, 0x47, 0x00,             //push        473190h
	0xC3,                                     //ret
	                                          //normal:
	0x33, 0xD2,                               //xor         edx,edx
	0x8B, 0x8D, 0x3C, 0x08, 0x00, 0x00,       //mov         ecx,dword ptr [ebp+83Ch]
	                                          //loop_source_building:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x0A,                               //je          end_source_building
	0x3B, 0x79, 0x08,                         //cmp         edi,dword ptr [ecx+8]
	0x75, 0x01,                               //jne         next_source_building
	0x42,                                     //inc         edx
	                                          //next_source_building:
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xF2,                               //jmp         loop_source_building
	                                          //end_source_building:
	0x42,                                     //inc         edx
	0x52,                                     //push        edx
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4C, 0x24, 0x08,                   //mov         ecx,dword ptr [esp+8]
	0x8B, 0x51, 0x0C,                         //mov         edx,dword ptr [ecx+0Ch]
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x05,                               //je          got_max_attack_person
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x01,                               //je          got_max_attack_person
	0x42,                                     //inc         edx
	                                          //got_max_attack_person:
	0x8B, 0xC2,                               //mov         eax,edx
	0x99,                                     //cdq
	0x59,                                     //pop         ecx
	0xF7, 0xF1,                               //div         eax,ecx
	0x83, 0x7E, 0xC4, 0x0A,                   //cmp         dword ptr[esi-3Ch],0Ah
	0x75, 0x0C,                               //jne         test_troop_person_num
	0x83, 0xF8, 0x02,                         //cmp         eax,2
	0x7E, 0x05,                               //jle         skip_got_troop_person_num
	0xB8, 0x02, 0x00, 0x00, 0x00,             //mov         eax,2
	                                          //skip_got_troop_person_num:
	0xEB, 0x27,                               //jmp         got_troop_person_num
	                                          //test_troop_person_num:
	0x83, 0xF8, 0x05,                         //cmp         eax,5
	0x7E, 0x07,                               //jle         test_normal_person_num
	0xB8, 0x04, 0x00, 0x00, 0x00,             //mov         eax,4
	0xEB, 0x1B,                               //jmp         got_troop_person_num
	                                          //test_normal_person_num:
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x07,                               //jg          test_border_person_num
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x01,                               //je          skip_got_max_troop_person
	0x40,                                     //inc         eax
	                                          //skip_got_max_troop_person:
	0xEB, 0x10,                               //jmp         got_troop_person_num
	                                          //test_border_person_num:
	0x3C, 0x03,                               //cmp         al,3
	0x74, 0x0C,                               //je          got_troop_person_num
	0x3C, 0x04,                               //cmp         al,4
	0x74, 0x07,                               //je          dec_troop_person_num
	0xD1, 0xE2,                               //shl         edx,1
	0x3B, 0xD1,                               //cmp         edx,ecx
	0x7F, 0x01,                               //jg          dec_troop_person_num
	0x48,                                     //dec         eax
	                                          //dec_troop_person_num:
	0x48,                                     //dec         eax
	                                          //got_troop_person_num:
	0x55,                                     //push        ebp
	0x57,                                     //push        edi
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x8B, 0xE8,                               //mov         ebp,eax
	0x8B, 0xF9,                               //mov         edi,ecx
	0x8B, 0x4C, 0x24, 0x14,                   //mov         ecx,dword ptr [esp+14h]
	0x8B, 0x59, 0x04,                         //mov         ebx,dword ptr [ecx+4]
	0x33, 0xF6,                               //xor         esi,esi
	                                          //loop_int_person:
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x13,                               //je          end_get_int_person
	0x8B, 0x4B, 0x08,                         //mov         ecx,dword ptr [ebx+8]
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          next_int_person
	0x46,                                     //inc         esi
	                                          //next_int_person:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0xEB, 0xE9,                               //jmp         loop_int_person
	                                          //end_get_int_person:
	0x5B,                                     //pop         ebx
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x33, 0xC9,                               //xor         ecx,ecx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x02,                               //je          got_int_person
	0x46,                                     //inc         esi
	0x41,                                     //inc         ecx
	                                          //got_int_person:
	0x8B, 0xC6,                               //mov         eax,esi
	0x5E,                                     //pop         esi
	0x99,                                     //cdq
	0xF7, 0xF7,                               //div         eax,edi
	0x85, 0xD2,                               //test        edx,edx
	0x74, 0x01,                               //je          get_troop_int_person
	0x40,                                     //inc         eax
	                                          //get_troop_int_person:
	0x83, 0xF8, 0x01,                         //cmp         eax,1
	0x7E, 0x05,                               //jle         got_troop_int_person
	0xB8, 0x01, 0x00, 0x00, 0x00,             //mov         eax,1
	                                          //got_troop_int_person:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x01,                               //je          got_left_troop_int_person
	0x48,                                     //dec         eax
	                                          //got_left_troop_int_person:
	0xA3, 0xFB, 0xFA, 0x43, 0x00,             //mov         [left_troop_int_person],eax
	                                          //loop_skip_other_leader:
	0x4F,                                     //dec         edi
	0x74, 0x0D,                               //je          end_skip_other_leader
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xF0,                               //jmp         loop_skip_other_leader
	                                          //end_skip_other_leader:
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0x8B, 0x79, 0x04,                         //mov         edi,dword ptr [ecx+4]
	0x85, 0xFF,                               //test        edi,edi
	0x0F, 0x84, 0x9F, 0x00, 0x00, 0x00,       //je          end
	0x83, 0xBB, 0x84, 0x00, 0x00, 0x00, 0x00, //cmp         dword ptr [ebx+84h],0
	0x75, 0x3A,                               //jne         test_left_person
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x43, 0x68,                         //mov         eax,dword ptr [ebx+68h]
	0x04, 0x0A,                               //add         al,0Ah
	0x3B, 0x41, 0x68,                         //cmp         eax,dword ptr [ecx+68h]
	0x7D, 0x2D,                               //jge         test_left_person
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xD8,                               //mov         ebx,eax
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4C, 0x24, 0x14,                   //mov         ecx,dword ptr [esp+14h]
	0x89, 0x59, 0x0C,                         //mov         dword ptr [ecx+0Ch],ebx
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x5C,                               //je          end
	                                          //test_left_person:
	0x4D,                                     //dec         ebp
	0x74, 0x59,                               //je          end
	0x8B, 0x7C, 0x24, 0x0C,                   //mov         edi,dword ptr [esp+0Ch]
	0x6A, 0x01,                               //push        1
	0xFF, 0x74, 0x24, 0x18,                   //push        dword ptr [esp+18h]
	0x68, 0x50, 0x1C, 0x47, 0x00,             //push        471C50h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x30, 0xF4, 0x46, 0x00,             //mov         eax,46F430h
	0xFF, 0xD0,                               //call        eax
	0x53,                                     //push        ebx
	0x8B, 0x1D, 0xFB, 0xFA, 0x43, 0x00,       //mov         ebx,dword ptr [left_troop_int_person]
	0x2B, 0xEB,                               //sub         ebp,ebx
	0x8B, 0x7F, 0x04,                         //mov         edi,dword ptr [edi+4]
	                                          //loop_select_left_person:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0xA1, 0x61, 0x48, 0x00,             //mov         eax,test_intelligence_person
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x07,                               //je          check_non_int_person
	0x85, 0xDB,                               //test        ebx,ebx
	0x7E, 0x14,                               //jle         test_left_person
	0x4B,                                     //dec         ebx
	0xEB, 0x05,                               //jmp         select_person
	                                          //check_non_int_person:
	0x85, 0xED,                               //test        ebp,ebp
	0x7E, 0x0D,                               //jle         test_left_person
	0x4D,                                     //dec         ebp
	                                          //select_person:
	0xFF, 0x77, 0x08,                         //push        dword ptr [edi+8]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //test_left_person:
	0x85, 0xDB,                               //test        ebx,ebx
	0x7F, 0x04,                               //jg          next_left_person
	0x85, 0xED,                               //test        ebp,ebp
	0x7E, 0x06,                               //jle         end_left_person
	                                          //next_left_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xCC,                               //jne         loop_select_left_person
	                                          //end_left_person:
	0x5B,                                     //pop         ebx
	                                          //end:
	0x5F,                                     //pop         edi
	0x5D,                                     //pop         ebp
	0xC2, 0x18, 0x00                          //ret         18h
};

BYTE codeSelectAttackPersonThunk[] = {0xE8, 0x56, 0xDE, 0xBE, 0xFF};//dwAddrSelectAttackPersong - 4B4DA5h - 5
BYTE codeSelectAttackPersonOldThunk[] = {0xE8, 0xE6, 0xE3, 0xFB, 0xFF};//call 473190h
ASM_PATCH patchSelectAttackPersonThunk[] = {
	{0x4B4DA5, sizeof(codeSelectAttackPersonThunk), codeSelectAttackPersonThunk},
	{0x4B4DA5, sizeof(codeSelectAttackPersonOldThunk), codeSelectAttackPersonOldThunk}};

//max attack soldier
DWORD dwAddrMaxAttackSoldier = dwAddrStackBottom + 0x3F00;
BYTE codeMaxAttackSoldier[] = {
	0x50,                                     //push        eax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x5A,                                     //pop         edx
	0x74, 0x18,                               //je          normal
	0xF6, 0x05, 0xC8, 0xF4, 0x43, 0x00, 0x01, //test        byte ptr[check_soldier_flag],1
	0x74, 0x0A,                               //je          player_max_attack_soldier
	0x8B, 0x4C, 0x24, 0x1C,                   //mov         ecx,dword ptr [esp+1Ch]
	0x8B, 0x91, 0x28, 0x04, 0x00, 0x00,       //mov         edx,dword ptr [ecx+428h]
	                                          //player_max_attack_soldier:
	0x6B, 0xD2, 0x03,                         //imul        edx,edx,3
	0xEB, 0x02,                               //jmp         end
	                                          //normal:
	0xD1, 0xE2,                               //shl         edx,1
	                                          //end:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3                                      //ret
};

BYTE codeMaxAttackSoldierThunk[] = {0xE8, 0x09, 0xF4, 0xBE, 0xFF};//dwAddrMaxAttackSoldier - 4B4AF2h - 5
BYTE codeMaxAttackSoldierOldThunk[] = {0x8D, 0x14, 0x00, 0x33, 0xC0};//lea edx,[eax+eax];xor eax,eax
ASM_PATCH patchMaxAttackSoldierThunk[] = {
	{0x4B4AF2, sizeof(codeMaxAttackSoldierThunk), codeMaxAttackSoldierThunk},
	{0x4B4AF2, sizeof(codeMaxAttackSoldierOldThunk), codeMaxAttackSoldierOldThunk}};

//building on the way
DWORD dwAddrBuildingOnTheWay = dwAddrStackBottom + 0x5CA0;
BYTE codeBuildingOnTheWay[] = {
	0x33, 0xC0,                               //xor         eax,eax
	0x83, 0x7E, 0x48, 0x00,                   //cmp         dword ptr [esi+48h],0
	0x74, 0x02,                               //je          end
	0x8B, 0xC6,                               //mov         eax,esi
	                                          //end:
	0xC3                                      //ret
};

BYTE codeBuildingOnTheWayThunk[] = {0xE8, 0x70, 0x19, 0xBF, 0xFF};//dwAddrBuildingOnTheWay - 4B432Bh - 5
BYTE codeBuildingOnTheWayOldThunk[] = {0xE8, 0x40, 0x8D, 0xFA, 0xFF};//call 45D070h()
ASM_PATCH patchBuildingOnTheWayThunk[] = {
	{0x4B432B, sizeof(codeBuildingOnTheWayThunk), codeBuildingOnTheWayThunk},
	{0x4B432B, sizeof(codeBuildingOnTheWayOldThunk), codeBuildingOnTheWayOldThunk}};

//being build
DWORD dwAddrBeingBuild = dwAddrStackBottom + 0x3270;
BYTE codeBeingBuild[] = {
	0x56,                                     //push        esi
	0xB8, 0x80, 0x57, 0x43, 0x00,             //mov         eax,435780h
	0xFF, 0xD0,                               //call        eax
	0xF6, 0x46, 0x3D, 0x80,                   //test        byte ptr [esi+3Dh],80h
	0x74, 0x02,                               //je          end
	0x34, 0x01,                               //xor         al,1
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeBeingBuildThunk[] = {0xE8, 0x05, 0xEF, 0xBE, 0xFF};//dwAddrBeingBuild - 4B4366h - 5
BYTE codeBeingBuildOldThunk[] = {0xE8, 0x15, 0x14, 0xF8, 0xFF};//call 435780h()
ASM_PATCH patchBeingBuildThunk[] = {
	{0x4B4366, sizeof(codeBeingBuildThunk), codeBeingBuildThunk},
	{0x4B4366, sizeof(codeBeingBuildOldThunk), codeBeingBuildOldThunk}};

//left clever killer
DWORD dwAddrLeftCleverKiller = dwAddrStackBottom + 0x2AC0;
BYTE codeLeftCleverKiller[] = {
	0x51,                                     //push        ecx
	0xB8, 0xB0, 0xFA, 0x46, 0x00,             //mov         eax,46FAB0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x83, 0x7C, 0x24, 0x18, 0x00,             //cmp         dword ptr [esp+18h],0
	0x74, 0x10,                               //je          test_chaos_killer
	0xFF, 0x74, 0x24, 0x40,                   //push        dword ptr [esp+40h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x83, 0x04, 0x24, 0x36,                   //add         dword ptr [esp],36h
	0xC3,                                     //ret
	                                          //test_chaos_killer:
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0x01,                               //jne         add_chao_killer
	0xC3,                                     //ret
	                                          //add_chao_killer:
	0xFF, 0x74, 0x24, 0x58,                   //push        dword ptr [esp+58h]
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x83, 0x04, 0x24, 0x1D,                   //add         dword ptr [esp],1Dh
	0xC3                                      //ret
};

BYTE codeLeftCleverKillerThunk[] = {0xE8, 0x44, 0xA7, 0xBE, 0xFF};//dwAddrLeftCleverKiller - 4B8377h - 5
BYTE codeLeftCleverKillerOldThunk[] = {0xE8, 0x34, 0x77, 0xFB, 0xFF};//call 46FAB0h()
ASM_PATCH patchLeftCleverKillerThunk[] = {
	{0x4B8377, sizeof(codeLeftCleverKillerThunk), codeLeftCleverKillerThunk},
	{0x4B8377, sizeof(codeLeftCleverKillerOldThunk), codeLeftCleverKillerOldThunk}};

//official loyaty
DWORD dwAddrOfficialLoyaty = 0x45BFB5;
BYTE codeOfficialLoyaty[] = {//B
	0x0F, 0xB6, 0x46, 0x04,                   //movzx       eax,byte ptr [esi+4]
	0x8A, 0x80, 0xB0, 0x31, 0x0A, 0x00,       //mov         al,[eax+official_loyalty]
	0xC3                                      //ret
};

BYTE codeOfficialLoyatyThunk[] = {0xE8, 0xCD, 0xF9, 0xFF, 0xFF};//dwAddrOfficialLoyaty- 45C5E3h - 5
BYTE codeOfficialLoyatyOldThunk[] = {0x99, 0x2B, 0xC2, 0xD1, 0xF8};//cdq;sub eax,edx;sar eax,1
ASM_PATCH patchOfficialLoyatyThunk[] = {
	{0x45C5E3, sizeof(codeOfficialLoyatyThunk), codeOfficialLoyatyThunk},
	{0x45C5E3, sizeof(codeOfficialLoyatyOldThunk), codeOfficialLoyatyOldThunk}};

//add official loyaty
DWORD dwAddrAddOfficialLoyaty = dwAddrStackBottom + 0x3BD0;
BYTE codeAddOfficialLoyaty[] = {
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x09,                               //je          test_new_official
	0x8A, 0x5F, 0x04,                         //mov         bl,[edi+4]
	0x8A, 0x9B, 0xB0, 0x31, 0x0A, 0x00,       //mov         bl,[ebx+official_loyalty]
	                                          //test_new_official:
	0x33, 0xC0,                               //xor         eax,eax
	0x85, 0xED,                               //test        ebp,ebp
	0x74, 0x09,                               //je          end
	0x8A, 0x45, 0x04,                         //mov         al,[ebp+4]
	0x8A, 0x80, 0xB0, 0x31, 0x0A, 0x00,       //mov         al,[eax+official_loyalty]
	                                          //end:
	0x8B, 0xF8,                               //mov         edi,eax
	0x68, 0x20, 0xAF, 0x48, 0x00,             //push        48AF20h
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeAddOfficialLoyatyThunk[] = {0xE8, 0xDA, 0x8C, 0xC1, 0xFF};//dwAddrAddOfficialLoyaty - 48AEF1h - 5
BYTE codeAddOfficialLoyatyOldThunk[] = {0xE8, 0x4A, 0xA9, 0xF7, 0xFF};//call 405840h()
ASM_PATCH patchAddOfficialLoyatyThunk[] = {
	{0x48AEF1, sizeof(codeAddOfficialLoyatyThunk), codeAddOfficialLoyatyThunk},
	{0x48AEF1, sizeof(codeAddOfficialLoyatyOldThunk), codeAddOfficialLoyatyOldThunk}};

//correct near max soldier
DWORD dwAddrCorrectNearMaxSoldier = dwAddrStackBottom + 0x3C00;
BYTE codeCorrectNearMaxSoldier[] = {
	0x8B, 0x86, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         test_baram_force
	0xC3,                                     //ret
	                                          //test_baram_force:
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr [eax+34h],4
	0x74, 0x03,                               //je          not_baram_force
	                                          //not_defense:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //not_baram_force:
	0x81, 0xFD, 0x20, 0x4E, 0x00, 0x00,       //cmp         ebp,4E20h
	0x7C, 0xF5,                               //jl          not_defense
	0x56,                                     //push        esi
	0x51,                                     //push        ecx
	0xB8, 0x00, 0x07, 0x4B, 0x00,             //mov         eax,4B0700h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         update_building_soldier
	0xC3,                                     //ret
	                                          //update_building_soldier:
	0x8B, 0x0D, 0x6C, 0xFA, 0x43, 0x00,       //mov         ecx,[attack_source_building]
	0x6A, 0x0C,                               //push        0Ch
	0x6A, 0x0B,                               //push        0Bh
	0x51,                                     //push        ecx
	0x56,                                     //push        esi
	0xB8, 0x80, 0xA6, 0x44, 0x00,             //mov         eax,44A680h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x66, 0x3D, 0x32, 0x00,                   //cmp         ax,32h
	0x7E, 0x04,                               //jle         got_arrive_day
	0x66, 0xB8, 0x32, 0x00,                   //mov         ax,32h
	                                          //got_arrive_day:
	0x83, 0xE8, 0x46,                         //sub         eax,46h
	0xF7, 0xD8,                               //neg         eax
	0xF7, 0xED,                               //imul        ebp
	0xB9, 0x32, 0x00, 0x00, 0x00,             //mov         ecx,32h
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xE8,                               //mov         ebp,eax
	0xC3                                      //ret
};

BYTE codeCorrectNearMaxSoldierThunk[] = {0xE8, 0x37, 0xE2, 0xBE, 0xFF};//dwAddrCorrectNearMaxSoldier - 4B59C4h - 5
BYTE codeCorrectNearMaxSoldierOldThunk[] = {0xE8, 0x37, 0xAD, 0xFF, 0xFF};//call 4B0700h()
ASM_PATCH patchCorrectNearMaxSoldierThunk[] = {
	{0x4B59C4, sizeof(codeCorrectNearMaxSoldierThunk), codeCorrectNearMaxSoldierThunk},
	{0x4B59C4, sizeof(codeCorrectNearMaxSoldierOldThunk), codeCorrectNearMaxSoldierOldThunk}};

//save near max soldier
DWORD dwAddrSaveNearMaxSoldier = dwAddrStackBottom + 0x2FE8;
BYTE codeSaveNearMaxSoldier[] = {
	0x8B, 0x0D, 0x6C, 0xFA, 0x43, 0x00,       //mov         ecx,[attack_source_building]
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x8B, 0xD3,                               //mov         edx,ebx
	0xC1, 0xEA, 0x04,                         //shr         edx,4
	0x66, 0x89, 0x54, 0x85, 0x46,             //mov         word ptr [ebp+eax*4+46h],dx
	0x8B, 0xC3,                               //mov         eax,ebx
	0xC3                                      //ret
};

BYTE codeSaveNearMaxSoldierThunk[] = {0xE8, 0xFC, 0xD5, 0xBE, 0xFF};//dwAddrSaveNearMaxSoldier - 4B59E7h - 5
BYTE codeSaveNearMaxSoldierOldThunk[] = {0x8B, 0xC3, 0x99, 0x2B, 0xC2};//mov eax,ebx;cdq;sub eax,edx
ASM_PATCH patchSaveNearMaxSoldierThunk[] = {
	{0x4B59E7, sizeof(codeSaveNearMaxSoldierThunk), codeSaveNearMaxSoldierThunk},
	{0x4B59E7, sizeof(codeSaveNearMaxSoldierOldThunk), codeSaveNearMaxSoldierOldThunk}};

//load near max soldier
DWORD dwAddrLoadNearMaxSoldier = dwAddrStackBottom + 0x04E0;
BYTE codeLoadNearMaxSoldier[] = {
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x0F, 0xB7, 0x44, 0x83, 0x46,             //movzx       eax,word ptr [ebx+eax*4+46h]
	0xC1, 0xE0, 0x04,                         //shl         eax,4
	0xC3                                      //ret
};

BYTE codeLoadNearMaxSoldierThunk[] = {0xE8, 0x22, 0xB9, 0xBE, 0xFF, 0x41};//dwAddrLoadNearMaxSoldier - 4B4BB9h - 5
BYTE codeLoadNearMaxSoldierOldThunk[] = {0x8B, 0x83, 0x14, 0x08, 0x00, 0x00};//mov eax,[ebx+814h]
ASM_PATCH patchLoadNearMaxSoldierThunk[] = {
	{0x4B4BB9, sizeof(codeLoadNearMaxSoldierThunk), codeLoadNearMaxSoldierThunk},
	{0x4B4BB9, sizeof(codeLoadNearMaxSoldierOldThunk), codeLoadNearMaxSoldierOldThunk}};
//load near max soldier 2
DWORD dwAddrLoadNearMaxSoldier2 = dwAddrStackBottom + 0x04F0;
BYTE codeLoadNearMaxSoldier2[] = {
	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x0F, 0xB7, 0x44, 0x85, 0x46,             //movzx       eax,word ptr [ebp+eax*4+46h]
	0xC1, 0xE0, 0x04,                         //shl         eax,4
	0xC3                                      //ret
};

BYTE codeLoadNearMaxSoldier2Thunk[] = {0xE8, 0x10, 0xB7, 0xBE, 0xFF, 0x41};//dwAddrLoadNearMaxSoldier2 - 4B4DDBh - 5
BYTE codeLoadNearMaxSoldier2OldThunk[] = {0x8B, 0x85, 0x14, 0x08, 0x00, 0x00};//mov eax,[ebp+814h]
ASM_PATCH patchLoadNearMaxSoldier2Thunk[] = {
	{0x4B4DDB, sizeof(codeLoadNearMaxSoldier2Thunk), codeLoadNearMaxSoldier2Thunk},
	{0x4B4DDB, sizeof(codeLoadNearMaxSoldier2OldThunk), codeLoadNearMaxSoldier2OldThunk}};

//operation per day
DWORD dwAddrOperationPerDay = dwAddrStackBottom + 0x3400;
BYTE codeOperationPerDay[] = {
	0x57,                                     //push        edi
	0x56,                                     //push        esi
	0xFE, 0x0D, 0x15, 0xFF, 0x43, 0x00,       //dec         byte ptr[left_day]
	0x33, 0xC0,								  //xor         eax,eax
	0xB9, 0x32, 0x00, 0x00, 0x00,			  //mov         ecx,32h
	0xBF, 0x00, 0x79, 0x0A, 0x00,			  //mov         edi,city_fight_count
	0xF3, 0xAA,								  //rep         stosb
	0x80, 0x3D, 0x1B, 0xFF, 0x43, 0x00, 0x00, //cmp         byte ptr[low_durability_chaos], 0
	0x74, 0x7E,								  //je          end
	0x33, 0xFF,                               //xor         edi,edi
	                                          //loop_building:
	0x57,                                     //push        edi
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x67,                               //je          next_building
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0x20, 0x54, 0x43, 0x00,             //mov         eax,435420h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x58,                               //je          next_building
	0xF6, 0x46, 0x7A, 0x40,                   //test        byte ptr [esi+7Ah],40h
	0x74, 0x52,                               //je          next_building
	0x80, 0x7E, 0x7C, 0x01,                   //cmp         byte ptr [esi+7Ch],1
	0x75, 0x4C,                               //jne         next_building
	0x0F, 0xB7, 0x46, 0x3C,					  //movzx       eax,word ptr[esi+3Ch]
	0x6B, 0xC0, 0x05,						  //imul        eax,eax,5
	0x8B, 0x4E, 0x48,                         //mov         ecx,dword ptr [esi+48h]
	0x3B, 0x41, 0x24,						  //cmp         eax,[ecx+24h]
	0x7D, 0x3D,                               //jge         next_building
	0x8B, 0x86, 0xE0, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0E0h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x06,                               //je          got_leader_command
	0x8B, 0x48, 0x08,                         //mov         ecx,dword ptr [eax+8]
	0x8B, 0x41, 0x68,                         //mov         eax,dword ptr [ecx+68h]
	                                          //got_leader_command:
	0xC1, 0xE8, 0x01,                         //shr         eax,1
	0x83, 0xE8, 0x3C,                         //sub         eax,3Ch
	0xF7, 0xD8,                               //neg         eax
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x19,                               //je          next_building
	0x6A, 0x78,								  //push        78h
	0x58,									  //pop         eax
	0x2B, 0x86, 0x90, 0x00, 0x00, 0x00,       //sub         eax,dword ptr [esi+90h]
	0x99,                                     //cdq
	0x6A, 0x14,								  //push        14h
	0x59,									  //pop         ecx
	0xF7, 0xF1,                               //div         eax,ecx
	0x88, 0x86, 0x80, 0x00, 0x00, 0x00,       //mov         byte ptr [esi+80h],al
	0xC6, 0x46, 0x7C, 0x06,                   //mov         byte ptr [esi+7Ch],6
	                                          //next_building:
	0x47,                                     //inc         edi
	0x81, 0xFF, 0xFA, 0x00, 0x00, 0x00,       //cmp         edi,0FAh
	0x7C, 0x84,								  //jl          loop_building
											  //end:
	0x5E,                                     //pop         esi
	0x5F,                                     //pop         edi
	0x68, 0x50, 0x2E, 0x45, 0x00,             //push        452E50h
	0xC3                                      //ret
};

BYTE codeOperationPerDayThunk[] = {0xE8, 0xB1, 0x90, 0xB9, 0xFF};//dwAddrOperationPerDay - 50A34Ah - 5
BYTE codeOperationPerDayOldThunk[] = {0xE8, 0x01, 0x8B, 0xF4, 0xFF};//call 452E50h()
ASM_PATCH patchOperationPerDayThunk[] = {
	{0x50A34A, sizeof(codeOperationPerDayThunk), codeOperationPerDayThunk},
	{0x50A34A, sizeof(codeOperationPerDayOldThunk), codeOperationPerDayOldThunk}};

//selec attack array
DWORD dwAddrSelectAttackArray = dwAddrStackBottom + 0x2E00;
BYTE codeSelectAttackArray[] = {
	0x58,                                     //pop         eax
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xD8,                               //mov         ebx,eax
	0x6A, 0x01,                               //push        1
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xE8,                               //mov         ebp,eax
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x54,                               //je          get_foot_killer
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x4C,                               //je          test_horse_killer
	                                          //bow_to_horsebow:
	0x6A, 0x00,                               //push        0
	0x6A, 0x03,                               //push        3
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x75, 0x13,                               //jne         horsebow_to_bow
	0x6A, 0x01,                               //push        1
	0x6A, 0x03,                               //push        3
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x03, 0xFB,                               //add         edi,ebx
	0x33, 0xDB,                               //xor         ebx,ebx
	0xEB, 0x2C,                               //jmp         get_foot_killer
	                                          //horsebow_to_bow:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x28,                               //je          get_foot_killer
	0x6A, 0x00,                               //push        0
	0x6A, 0x02,                               //push        2
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC7,                               //cmp         eax,edi
	0x75, 0x11,                               //jne         skip_foot_killer
	0x6A, 0x01,                               //push        1
	0x6A, 0x02,                               //push        2
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x03, 0xDF,                               //add         ebx,edi
	0x33, 0xFF,                               //xor         edi,edi
	                                          //skip_foot_killer:
	0xEB, 0x04,                               //jmp         get_foot_killer
	                                          //test_horse_killer:
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xB0,                               //jne         bow_to_horsebow
	                                          //get_foot_killer:
	0x6A, 0x00,                               //push        0
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x7D,                               //je          select_array
	0x53,                                     //push        ebx
	0x8B, 0xD8,                               //mov         ebx,eax
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x1D,                               //je          foot_to_horse
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x36,                               //je          horse_to_foot
	0xD1, 0xE0,                               //shl         eax,1
	0x03, 0xC7,                               //add         eax,edi
	0x03, 0xC5,                               //add         eax,ebp
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7C, 0x2C,                               //jl          horse_to_foot
	0xEB, 0x17,                               //jmp         do_foot_to_horse
	                                          //foot_to_horse:
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x19,                               //je          horse_to_foot
	0x03, 0xC5,                               //add         eax,ebp
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7E, 0x13,                               //jle         horse_to_foot
	                                          //do_foot_to_horse:
	0x6A, 0x01,                               //push        1
	0x6A, 0x00,                               //push        0
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x03, 0xE8,                               //add         ebp,eax
	0x2B, 0xD8,                               //sub         ebx,eax
	0xEB, 0x2C,                               //jmp         end_foot_horse
	                                          //horse_to_foot:
	0x85, 0xED,                               //test        ebp,ebp
	0x74, 0x28,                               //je          end_foot_horse
	0x6A, 0x00,                               //push        0
	0x6A, 0x01,                               //push        1
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x17,                               //je          end_foot_horse
	0x03, 0xC3,                               //add         eax,ebx
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7E, 0x11,                               //jle         end_foot_horse
	0x6A, 0x01,                               //push        1
	0x6A, 0x01,                               //push        1
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0x03, 0xD8,                               //add         ebx,eax
	0x2B, 0xE8,                               //sub         ebp,eax
	                                          //end_foot_horse:
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5B,                                     //pop         ebx
	                                          //select_array:
	0xF6, 0x44, 0x24, 0x34, 0x01,             //test        byte ptr [esp+34h],1
	0x75, 0x51,                               //jne         array_elephant
	0x03, 0xEF,                               //add         ebp,edi
	0x8B, 0xD3,                               //mov         edx,ebx
	0x03, 0xD7,                               //add         edx,edi
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7D, 0x02,                               //jge         cmp_bow_horsebow
	0x8B, 0xC5,                               //mov         eax,ebp
	                                          //cmp_bow_horsebow:
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7D, 0x02,                               //jge         got_max_killer_num
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //got_max_killer_num:
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x16,                               //jne         killer_to_array
	0xF6, 0x44, 0x24, 0x24, 0x01,             //test        byte ptr [esp+24h],1
	0x74, 0x04,                               //je          test_stone
	                                          //array_well:
	0x6A, 0x08,                               //push        8
	0xEB, 0x32,                               //jmp         end
	                                          //test_stone:
	0xF6, 0x44, 0x24, 0x1C, 0x01,             //test        byte ptr [esp+1Ch],1
	0x74, 0x25,                               //je          array_goose
	0x6A, 0x0A,                               //push        0Ah
	0xEB, 0x27,                               //jmp         end
	                                          //killer_to_array:
	0x3B, 0xD0,                               //cmp         edx,eax
	0x7C, 0x35,                               //jl          test_horse_horsebow
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0x04,                               //jne         test_horsebow
	                                          //array_wimble:
	0x6A, 0x02,                               //push        2
	0xEB, 0x48,                               //jmp         adjust_wimble_killer
	                                          //test_horsebow:
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x04,                               //je          pure_bow
	                                          //array_dustpan:
	0x6A, 0x05,                               //push        5
	0xEB, 0x13,                               //jmp         end
	                                          //pure_bow:
	0xF6, 0x44, 0x24, 0x24, 0x01,             //test        byte ptr [esp+24h],1
	0x75, 0xD6,                               //jne         array_well
	0xF6, 0x46, 0x19, 0x01,                   //test        byte ptr [esi+19h],01h
	0x75, 0xEF,                               //jne         array_dustpan
	                                          //array_goose:
	0x6A, 0x04,                               //push        4
	0xEB, 0x02,                               //jmp         end
	                                          //array_elephant:
	0x6A, 0x0B,                               //push        0Bh
	                                          //end:
	0xB8, 0x90, 0x38, 0x45, 0x00,             //mov         eax,453890h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x04,                         //add         esp,4
	0x8B, 0xD8,                               //mov         ebx,eax
	0x68, 0x93, 0x88, 0x4B, 0x00,             //push        4B8893h
	0xC3,                                     //ret
	                                          //test_horse_horsebow:
	0x3B, 0xE8,                               //cmp         ebp,eax
	0x7D, 0xCB,                               //jge         array_wimble
	0x6A, 0x00,                               //push        0
	0x2B, 0xEF,                               //sub         ebp,edi
	0x85, 0xED,                               //test        ebp,ebp
	0x74, 0xE2,                               //je          end
	0x6A, 0x01,                               //push        1
	0x6A, 0x01,                               //push        1
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xD3,                               //jmp         end
	                                          //adjust_wimble_killer:
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x0D,                               //je          adjust_wimble_foot
	0x6A, 0x01,                               //push        1
	0x6A, 0x03,                               //push        3
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	                                          //adjust_wimble_foot:
	0x6A, 0x01,                               //push        1
	0x6A, 0x00,                               //push        0
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x30, 0x0A, 0x00,             //mov         eax,adjust_killer
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xB3                                //jmp         end
};

BYTE codeSelectAttackArrayThunk[] = {0xE8, 0x3F, 0xA4, 0xBE, 0xFF};//dwAddrSelectAttackArray - 4B89BCh - 5
BYTE codeSelectAttackArrayOldThunk[] = {0xE8, 0x9F, 0x31, 0xFD, 0xFF};//call 48BB60h()
ASM_PATCH patchSelectAttackArrayThunk[] = {
	{0x4B89BC, sizeof(codeSelectAttackArrayThunk), codeSelectAttackArrayThunk},
	{0x4B89BC, sizeof(codeSelectAttackArrayOldThunk), codeSelectAttackArrayOldThunk}};

//adjust killer
DWORD dwAddrAdjustKiller = dwAddrStackBottom + 0x3000;
BYTE codeAdjustKiller[] = {
	                                          //adjust_killer:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8D, 0x71, 0x48,                         //lea         esi,[ecx+48h]
	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0x69, 0x18,                         //mov         ebp,dword ptr [ecx+18h]
	0x8B, 0x5C, 0x24, 0x14,                   //mov         ebx,dword ptr [esp+14h]
	                                          //loop_config_killer:
	0x8B, 0x06,                               //mov         eax,dword ptr [esi]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x2C,                               //je          next_killer
	0x39, 0x58, 0x54,                         //cmp         dword ptr [eax+54h],ebx
	0x75, 0x27,                               //jne         next_killer
	0x0F, 0xB6, 0x40, 0x04,                   //movzx       eax,byte ptr [eax+4]
	0x50,                                     //push        eax
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xB8, 0x60, 0x30, 0x0A, 0x00,             //mov         eax,transfer_killer
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x74, 0x13,                               //je          next_killer
	0x47,                                     //inc         edi
	0xF6, 0x44, 0x24, 0x18, 0x01,             //test        byte ptr [esp+18h],1
	0x74, 0x0B,                               //je          next_killer
	0x50,                                     //push        eax
	0xB8, 0x20, 0x37, 0x45, 0x00,             //mov         eax,453720h
	0xFF, 0xD0,                               //call        eax
	0x89, 0x06,                               //mov         dword ptr [esi],eax
	0x58,                                     //pop         eax
	                                          //next_killer:
	0x83, 0xC6, 0x04,                         //add         esi,4
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xC4,                               //jne         loop_config_killer
	0x8B, 0xC7,                               //mov         eax,edi
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x08, 0x00                          //ret         8
};

//transfer killer
DWORD dwAddrTransferKiller = dwAddrStackBottom + 0x3060;
BYTE codeTransferKiller[] = {
	                                          //transfer_killer:
	0x8B, 0x89, 0x00, 0x01, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+100h]
	0x0B, 0x0D, 0xF3, 0xFA, 0x43, 0x00,       //or          ecx,[force_killer_flag]
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,dword ptr [esp+4]
	0x0F, 0xB7, 0x14, 0x45, 0xE8, 0x32, 0x0A, 0x00,//movzx  edx,word ptr [eax*2+killer_transfer_table]
	0x23, 0xCA,                               //and         ecx,edx
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0x01,                               //jne         get_transfered_killer
	0xC3,                                     //ret
	                                          //get_transfered_killer:
	0x33, 0xC0,                               //xor         eax,eax
	0x48,                                     //dec         eax
	                                          //loop_transfer_killer:
	0x40,                                     //inc         eax
	0xD1, 0xE9,                               //shr         ecx,1
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0xF9,                               //jne         loop_transfer_killer
	0xC3                                      //ret
};

//killer_transfer_table[]
DWORD dwAddrKillerTransferTable = dwAddrStackBottom + 0x32E8;
DWORD dwDataKillerTransferTable[6] = {
	0x080000, 0x010010, 0x060003, 0x4000200, 0x00800, 0x800040};

//decide attack ok
DWORD dwAddrDecideAttackOk = dwAddrStackBottom + 0x5D00;
BYTE codeDecideAttackOk[] = {
	0xB8, 0x90, 0xC9, 0x46, 0x00,             //mov         eax,46C990h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xC0,                               //xor         eax,eax
	0xA3, 0x08, 0xFC, 0x43, 0x00,             //mov         [reserved_attacked_building],eax
	0x8B, 0x46, 0x38,                         //mov         eax,dword ptr [esi+38h]
	0x8B, 0x88, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0B8h]
	0x8B, 0x41, 0x70,                         //mov         eax,dword ptr [ecx+70h]
	0xA3, 0xF3, 0xFA, 0x43, 0x00,             //mov         [force_killer_flag],eax
	0xC3                                      //ret
};

BYTE codeDecideAttackOkThunk[] = {0xE8, 0xE1, 0xF6, 0xBE, 0xFF};//dwAddrDecideAttackOk - 4B661Ah - 5
BYTE codeDecideAttackOkOldThunk[] = {0xE8, 0x71, 0x63, 0xFB, 0xFF};//call 46C990h()
ASM_PATCH patchDecideAttackOkThunk[] = {
	{0x4B661A, sizeof(codeDecideAttackOkThunk), codeDecideAttackOkThunk},
	{0x4B661A, sizeof(codeDecideAttackOkOldThunk), codeDecideAttackOkOldThunk}};

//set near attack flag
DWORD dwAddrSetNearAttackFlag = dwAddrStackBottom + 0x3090;
BYTE codeSetNearAttackFlag[] = {
	0x51,                                     //push        ecx
	0xB8, 0xD0, 0x95, 0x4B, 0x00,             //mov         eax,4B95D0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x09,                               //je          end2
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0xF6, 0x41, 0x34, 0x04,                   //test        byte ptr [ecx+34h],4
	0x74, 0x02,                               //je          normal
	                                          //end2:
	0x59,                                     //pop         ecx
	0xC3,                                     //ret
	                                          //normal:
	0x59,                                     //pop         ecx
	0x8B, 0x43, 0x44,                         //mov         eax,dword ptr [ebx+44h]
	0x8A, 0x40, 0x04,                         //mov         al,byte ptr [eax+4]
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x29,                               //je          attack_near_troop
	0x3C, 0x0B,                               //cmp         al,0Bh
	0x74, 0x25,                               //je          attack_near_troop
	0x3C, 0x0F,                               //cmp         al,0Fh
	0x7D, 0x21,                               //jge         attack_near_troop
	0x3C, 0x02,                               //cmp         al,02h
	0x75, 0x25,                               //jne         end
	0x83, 0xC1, 0x2C,                         //add         ecx,2Ch
	0x51,                                     //push        ecx
	0x6A, 0x01,                               //push        1
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF8,                               //mov         edi,eax
	0x59,                                     //pop         ecx
	0x6A, 0x02,                               //push        2
	0xB8, 0x60, 0xBB, 0x48, 0x00,             //mov         eax,48BB60h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xF8,                               //cmp         edi,eax
	0x7C, 0x08,                               //jl          end
	                                          //attack_near_troop:
	0xB0, 0x01,                               //mov         al,1
	0x88, 0x83, 0xA4, 0x00, 0x00, 0x00,       //mov         byte ptr [ebx+0A4h],al
	                                          //end:
	0xC3                                      //ret
};

BYTE codeSetNearAttackFlagThunk[] = {0xE8, 0x05, 0xD9, 0xBE, 0xFF};//dwAddrSetNearAttackFlag - 4B5786h - 5
BYTE codeSetNearAttackFlagOldThunk[] = {0xE8, 0x45, 0x3E, 0x00, 0x00};//call 4B95D0h()
ASM_PATCH patchSetNearAttackFlagThunk[] = {
	{0x4B5786, sizeof(codeSetNearAttackFlagThunk), codeSetNearAttackFlagThunk},
	{0x4B5786, sizeof(codeSetNearAttackFlagOldThunk), codeSetNearAttackFlagOldThunk}};

//adjust attack soldier
DWORD dwAddrAdjustAttackSoldier = dwAddrStackBottom + 0x3500;
BYTE codeAdjustAttackSoldier[] = {
	0x3B, 0xB7, 0x88, 0x00, 0x00, 0x00,       //cmp         esi,dword ptr [edi+88h]
	0x75, 0x01,                               //jne         end
	0x4E,                                     //dec         esi
	                                          //end:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3                                      //ret
};

BYTE codeAdjustAttackSoldierThunk[] = {0xE8, 0xB0, 0xE6, 0xBE, 0xFF};//dwAddrAdjustAttackSoldier - 4B4E4Bh - 5
BYTE codeAdjustAttackSoldierOldThunk[] = {0xE8, 0x10, 0x5C, 0xF9, 0xFF};//call 44AA60h()
ASM_PATCH patchAdjustAttackSoldierThunk[] = {
	{0x4B4E4B, sizeof(codeAdjustAttackSoldierThunk), codeAdjustAttackSoldierThunk},
	{0x4B4E4B, sizeof(codeAdjustAttackSoldierOldThunk), codeAdjustAttackSoldierOldThunk}};

//check wisdom anti trap
DWORD dwAddrCheckWisdomAntitrap = dwAddrStackBottom + 0x2DE0;
BYTE codeCheckWisdomAntitrap[] = {
	                                          //check_wisdom_antitrap:
	0x8B, 0x51, 0x4C,                         //mov         edx,dword ptr [ecx+4Ch]
	0x8B, 0x41, 0x54,                         //mov         eax,dword ptr [ecx+54h]
	0x2B, 0xD0,                               //sub         edx,eax
	0x83, 0xFA, 0xF8,                         //cmp         edx,0F8h
	0x7E, 0x03,                               //jle         test_intelligence
	                                          //unuse_wisdom_antitrap:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //test_intelligence:
	0x3C, 0x5A,                               //cmp         al,5Ah
	0x7D, 0xF9,                               //jge         unuse_wisdom_antitrap
	0x3C, 0x50,                               //cmp         al,50h
	0x7C, 0x03,                               //jl          use_wisdom_antitrap
	0xB0, 0x02,                               //mov         al,2
	0xC3,                                     //ret
	                                          //use_wisdom_antitrap:
	0xB0, 0x01,                               //mov         al,1
	0xC3                                      //ret
};

//select water wisdom
DWORD dwAddrSelectWaterWisdom = dwAddrStackBottom + 0x2200;
BYTE codeSelectWaterWisdom[] = {
	0x50,                                     //push        eax
	0xB8, 0xD0, 0xB8, 0x48, 0x00,             //mov         eax,48B8D0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x14,                               //jne         end
	0x8B, 0x8C, 0x24, 0x2C, 0x01, 0x00, 0x00, //mov         ecx,dword ptr [esp+12Ch]
	0xB8, 0xE0, 0x2D, 0x0A, 0x00,             //mov         eax,check_wisdom_antitrap
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x05,                               //je          random_use_wisdom
	0x34, 0x01,                               //xor         al,1
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //random_use_wisdom:
	0x6A, 0x32,                               //push        32h
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeSelectWaterWisdomThunk[] = {0xE8, 0x69, 0xA1, 0xBE, 0xFF};//dwAddrSelectWaterWisdom - 4B8092h - 5
BYTE codeSelectWaterWisdomOldThunk[] = {0xE8, 0x39, 0x38, 0xFD, 0xFF};//call 48B8D0h()
ASM_PATCH patchSelectWaterWisdomThunk[] = {
	{0x4B8092, sizeof(codeSelectWaterWisdomThunk), codeSelectWaterWisdomThunk},
	{0x4B8092, sizeof(codeSelectWaterWisdomOldThunk), codeSelectWaterWisdomOldThunk}};

//select attack wisdom
DWORD dwAddrSelectAttackWisdom = dwAddrStackBottom + 0x37CC;
BYTE codeSelectAttackWisdom[] = {
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xE0, 0x2D, 0x0A, 0x00,             //mov         eax,check_wisdom_antitrap
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x1C,                               //je          normal
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x0F,                               //je          use_wisdom
	0x80, 0x79, 0x0C, 0x00,                   //cmp         byte ptr [ecx+0Ch],0
	0x75, 0x06,                               //jne         not_use_wisdom
	0x58,                                     //pop         eax
	0x68, 0x3C, 0x83, 0x4B, 0x00,             //push        4B833Ch
	                                          //not_use_wisdom:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //use_wisdom:
	0x51,                                     //push        ecx
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	                                          //normal:
	0x68, 0x70, 0xEF, 0x46, 0x00,             //push        46EF70h
	0xC3                                      //ret
};

BYTE codeSelectAttackWisdomThunk[] = {0xE8, 0xBA, 0xB4, 0xBE, 0xFF};//dwAddrSelectAttackWisdom - 4B830Dh - 5
BYTE codeSelectAttackWisdomOldThunk[] = {0xE8, 0x5E, 0x6C, 0xFB, 0xFF};//call 46EF70h()
ASM_PATCH patchSelectAttackWisdomThunk[] = {
	{0x4B830D, sizeof(codeSelectAttackWisdomThunk), codeSelectAttackWisdomThunk},
	{0x4B830D, sizeof(codeSelectAttackWisdomOldThunk), codeSelectAttackWisdomOldThunk}};

//anti attack antitrap
DWORD dwAddrAntiAttackAntitrap = dwAddrStackBottom + 0x2230;
BYTE codeAntiAttackAntitrap[] = {
	0x8B, 0x8C, 0x24, 0xE0, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+0E0h]
	0xB8, 0xE0, 0x2D, 0x0A, 0x00,             //mov         eax,check_wisdom_antitrap
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x0D,                               //je          test_person_trap
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x06,                               //je          end
	                                          //skip_anti_trap:
	0x58,                                     //pop         eax
	0x68, 0x67, 0x1C, 0x4A, 0x00,             //push        4A1C67h
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_person_trap:
	0xF6, 0x44, 0x24, 0x58, 0x01,             //test        byte ptr [esp+58h],1
	0x75, 0xF0,                               //jne         skip_anti_trap
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeAntiAttackAntitrapThunk[] = {0xE8, 0x2B, 0x06, 0xC0, 0xFF};//dwAddrAntiAttackAntitrap - 4A1C00h - 5
BYTE codeAntiAttackAntitrapOldThunk[] = {0xE8, 0x6B, 0xFA, 0xFF, 0xFF};//call 4A1670h()
ASM_PATCH patchAntiAttackAntitrapThunk[] = {
	{0x4A1C00, sizeof(codeAntiAttackAntitrapThunk), codeAntiAttackAntitrapThunk},
	{0x4A1C00, sizeof(codeAntiAttackAntitrapOldThunk), codeAntiAttackAntitrapOldThunk}};

//anti attack wisdom
DWORD dwAddrAntiAttackWisdom = dwAddrStackBottom + 0x3550;
BYTE codeAntiAttackWisdom[] = {
	0x8B, 0x8C, 0x24, 0xE0, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+0E0h]
	0xB8, 0xE0, 0x2D, 0x0A, 0x00,             //mov         eax,check_wisdom_antitrap
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x0D,                               //je          test_killer
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x06,                               //je          end
	                                          //skip_anti_trap:
	0x58,                                     //pop         eax
	0x68, 0x78, 0x1D, 0x4A, 0x00,             //push        4A1D78h
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_killer:
	0x8B, 0x8C, 0x24, 0xE4, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+0E4h]
	0x68, 0x38, 0xEB, 0x4F, 0x01,             //push        14FEB38h
	0xB8, 0x00, 0x0D, 0x46, 0x00,             //mov         eax,460D00h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0xE6,                               //jne         end
	0x8B, 0x8C, 0x24, 0xE4, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+0E4h]
	0x68, 0x08, 0xE9, 0x4F, 0x01,             //push        14FE908h
	0xB8, 0x00, 0x0D, 0x46, 0x00,             //mov         eax,460D00h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0xCF,                               //jne         end
	0xF6, 0x44, 0x24, 0x58, 0x01,             //test        byte ptr [esp+58h],1
	0x75, 0xC2,                               //jne         skip_anti_trap
	0xF6, 0x44, 0x24, 0x60, 0x01,             //test        byte ptr [esp+60h],1
	0x75, 0xBB,                               //jne         skip_anti_trap
	0xB0, 0x01,                               //mov         al,1
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeAntiAttackWisdomThunk[] = {0xE8, 0x3A, 0x18, 0xC0, 0xFF};//dwAddrAntiAttackWisdom - 4A1D11h - 5
BYTE codeAntiAttackWisdomOldThunk[] = {0xE8, 0x5A, 0xF9, 0xFF, 0xFF};//call 4A1670h()
ASM_PATCH patchAntiAttackWisdomThunk[] = {
	{0x4A1D11, sizeof(codeAntiAttackWisdomThunk), codeAntiAttackWisdomThunk},
	{0x4A1D11, sizeof(codeAntiAttackWisdomOldThunk), codeAntiAttackWisdomOldThunk}};

//not attack near troop
DWORD dwAddrNotAttackNearTroop = dwAddrStackBottom + 0x3290;
BYTE codeNotAttackNearTroop[] = {
	                                          //not_attack_near_troop:
	0x80, 0x79, 0x58, 0x26,                   //cmp         byte ptr [ecx+58h],26h
	0x75, 0x45,                               //jne         normal
	0x8A, 0x41, 0x52,                         //mov         al,byte ptr [ecx+52h]
	0x3C, 0x03,                               //cmp         al,3
	0x74, 0x3E,                               //je          normal
	0x0F, 0xB6, 0x51, 0x50,                   //movzx       edx,byte ptr [ecx+50h]
	0xB9, 0x70, 0x2F, 0x45, 0x00,             //mov         ecx,452F70h
	0x3C, 0x05,                               //cmp         al,5
	0x74, 0x02,                               //je          get_goal
	0xB1, 0x10,                               //mov         cl,10h
	                                          //get_goal:
	0x52,                                     //push        edx
	0xFF, 0xD1,                               //call        ecx
	0x5A,                                     //pop         edx
	0x8B, 0x88, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0CCh]
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x21,                               //je          normal
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr [ecx+34h],1
	0x74, 0x1B,                               //je          normal
	0x57,                                     //push        edi
	0xB8, 0x50, 0x18, 0x44, 0x00,             //mov         eax,441850h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0F,                               //jne         normal
	0x80, 0x3C, 0x24, 0x83,                   //cmp         byte ptr[esp],83h
	0x74, 0x06,                               //je          end
	0x5A,                                     //pop         edx
	0x68, 0x0D, 0x4C, 0x46, 0x00,             //push        464C0Dh
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //normal:
	0x8B, 0xCE,                               //mov         ecx,esi
	0x68, 0x50, 0x0E, 0x46, 0x00,             //push        460E50h
	0xC3                                      //ret
};

BYTE codeNotAttackNearTroopThunk[] = {0xE8, 0x17, 0xE7, 0xC3, 0xFF};//dwAddrNotAttackNearTroop - 464B74h - 5
BYTE codeNotAttackNearTroopOldThunk[] = {0xE8, 0xD7, 0xC2, 0xFF, 0xFF};//call 460E50h()
ASM_PATCH patchNotAttackNearTroopThunk[] = {
	{0x464B74, sizeof(codeNotAttackNearTroopThunk), codeNotAttackNearTroopThunk},
	{0x464B74, sizeof(codeNotAttackNearTroopOldThunk), codeNotAttackNearTroopOldThunk}};

//not approach near troop
DWORD dwAddrNotApproachNearTroop = 0x492591;
BYTE codeNotApproachNearTroop[] = {
	0x58,                                     //pop         eax
	0x5A,                                     //pop         edx
	0x6A, 0x01,                               //push        1
	0x50,                                     //push        eax
	0x8B, 0xFE,                               //mov         edi,esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0x68, 0x90, 0x32, 0x0A, 0x00,             //push        not_attack_near_troop
	0xC3                                      //ret
};

BYTE codeNotApproachNearTroopThunk[] = {0xE8, 0x0E, 0x92, 0x01, 0x00};//dwAddrNotApproachNearTroop - 47937Eh - 5
BYTE codeNotApproachNearTroopOldThunk[] = {0xE8, 0x7D, 0x55, 0xFE, 0xFF};//call 45E900h(1000h)
ASM_PATCH patchNotApproachNearTroopThunk[] = {
	{0x47937E, sizeof(codeNotApproachNearTroopThunk), codeNotApproachNearTroopThunk},
	{0x47937E, sizeof(codeNotApproachNearTroopOldThunk), codeNotApproachNearTroopOldThunk}};

//go through near building
DWORD dwAddrGoThroughNearBuilding = dwAddrStackBottom + 0x3300;
BYTE codeGoThroughNearBuilding[] = {
	0xF6, 0x46, 0x3D, 0x80,                   //test        byte ptr[esi+3Dh],80h
	0x74, 0x03,                               //je          normal
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //normal:
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0x8B, 0x49, 0x78,                         //mov         ecx,dword ptr [ecx+78h]
	0xB8, 0x40, 0xCC, 0x45, 0x00,             //mov         eax,45CC40h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          on_the_earth
	0xC3,                                     //ret
	                                          //on_the_earth:
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x74, 0x01,                               //je          npc_troop
	0xC3,                                     //ret
	                                          //npc_troop:
	0x8B, 0x51, 0x6C,                         //mov         edx,dword ptr [ecx+6Ch]
	0x8B, 0x42, 0x04,                         //mov         eax,dword ptr [edx+4]
	0x3C, 0x0E,                               //cmp         al,0Eh
	0x74, 0x05,                               //je          check_goal
	0x3C, 0x06,                               //cmp         al,6
	0x74, 0x01,                               //je          check_goal
	0xC3,                                     //ret
	                                          //check_goal:
	0x8B, 0x41, 0x50,                         //mov         eax,dword ptr [ecx+50h]
	0x3B, 0x46, 0x04,                         //cmp         eax,dword ptr [esi+4]
	0x75, 0x01,                               //jne         check_go_through
	0xC3,                                     //ret
	                                          //check_go_through:
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x83, 0xEC, 0x60,                         //sub         esp,60h
	0x8B, 0xF9,                               //mov         edi,ecx
	0x0F, 0xB7, 0xD0,                         //movzx       edx,ax
	0xC1, 0xE8, 0x10,                         //shr         eax,10h
	0x3C, 0x05,                               //cmp         al,5
	0x74, 0x03,                               //je          got_goal_index
	0x83, 0xC2, 0x32,                         //add         edx,32h
	                                          //got_goal_index:
	0x52,                                     //push        edx
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xFF, 0xB0, 0xD0, 0x00, 0x00, 0x00,       //push        dword ptr [eax+0D0h]
	0x57,                                     //push        edi
	0xB8, 0x30, 0xA3, 0x47, 0x00,             //mov         eax,47A330h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,             //mov         eax,4734B0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0x54,                                     //push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,             //mov         eax,478290h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_map_block:
	0x43,                                     //inc         ebx
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0x70, 0xD0, 0x45, 0x00,             //mov         eax,45D070h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC6,                               //cmp         eax,esi
	0x74, 0x0D,                               //je          end
	0x80, 0xFB, 0x09,                         //cmp         bl,9
	0x7D, 0x06,                               //jge         end_map_block
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xE6,                               //jne         loop_map_block
	                                          //end_map_block:
	0x33, 0xDB,                               //xor         ebx,ebx
	                                          //end:
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xB8, 0x10, 0x9F, 0x47, 0x00,             //mov         eax,479F10h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x60,                         //add         esp,60h
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0xC3                                      //ret
};
//都设
BYTE codeGoThroughNearBuildingThunk[] = {0xE8, 0x8B, 0x9F, 0xC2, 0xFF};//dwAddrGoThroughNearBuilding - 479370h - 5
BYTE codeGoThroughNearBuildingOldThunk[] = {0xB8, 0x01, 0x00, 0x00, 0x00};//mov eax,1
ASM_PATCH patchGoThroughNearBuildingThunk[] = {
	{0x479370, sizeof(codeGoThroughNearBuildingThunk), codeGoThroughNearBuildingThunk},
	{0x479370, sizeof(codeGoThroughNearBuildingOldThunk), codeGoThroughNearBuildingOldThunk}};
//障碍物
BYTE codeGoThroughNearBarrierThunk[] = {0xE8, 0xBB, 0x9F, 0xC2, 0xFF};//dwAddrGoThroughNearBuilding - 479340h - 5
ASM_PATCH patchGoThroughNearBarrierThunk[] = {
	{0x479340, sizeof(codeGoThroughNearBarrierThunk), codeGoThroughNearBarrierThunk},
	{0x479340, sizeof(codeGoThroughNearBuildingOldThunk), codeGoThroughNearBuildingOldThunk}};

/////////////////////////////////////////////////////////////////////////////////////////
BYTE codeElephantAntiKillerThunk[] = {0x2C, 0x04, 0x2B, 0xC7, 0x42, 0x5F};//sub al,4;sub eax,edi;inc edx;pop edi
BYTE codeElephantAntiKillerOldThunk[] = {0x5F, 0xB8, 0x0F, 0x00, 0x00, 0x00};//pop edi;mov eax,0Fh
ASM_PATCH patchElephantAntiKillerThunk[] = {
	{0x4FEB44, sizeof(codeElephantAntiKillerThunk), codeElephantAntiKillerThunk},
	{0x4FEB44, sizeof(codeElephantAntiKillerOldThunk), codeElephantAntiKillerOldThunk}};

//league fail
DWORD dwAddrLeagueFail = dwAddrStackBottom + 0x35B0;
BYTE codeLeagueFail[] = {
	0x50,                                     //push        eax
	0x33, 0xC0,                               //xor         eax,eax
	0x89, 0x44, 0x24, 0x24,                   //mov         dword ptr [esp+24h],eax
	0x6A, 0x14,                               //push        14h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xD0, 0xDA, 0x43, 0x00,             //mov         eax,43DAD0h
	0xFF, 0xD0,                               //call        eax
	0x58,                                     //pop         eax
	0x83, 0xF8, 0x05,                         //cmp         eax,5
	0xC3                                      //ret
};

BYTE codeLeagueFailThunk[] = {0xE8, 0xAB, 0xAD, 0xC4, 0xFF, 0x90, 0x90, 0x90};//dwAddrLeagueFail - 458800h - 5
BYTE codeLeagueFailOldThunk[] = {0xC7, 0x44, 0x24, 0x1C, 0x00, 0x00, 0x00, 0x00};//mov [esp+1Ch],0
ASM_PATCH patchLeagueFailThunk[] = {
	{0x458800, sizeof(codeLeagueFailThunk), codeLeagueFailThunk},
	{0x458800, sizeof(codeLeagueFailOldThunk), codeLeagueFailOldThunk}};

//league succeed
DWORD dwAddrLeagueSucceed = dwAddrStackBottom + 0x3200;
BYTE codeLeagueSucceed[] = {
	0x6A, 0x23,                               //push        23h
	0xB8, 0xB0, 0xF7, 0x43, 0x00,             //mov         eax,43F7B0h
	0xFF, 0xD0,                               //call        eax
	0xB9, 0x38, 0x3C, 0x25, 0x01,             //mov         ecx,1253C38h
	0x33, 0xD2,                               //xor         edx,edx
	                                          //loop_force:
	0xF6, 0x41, 0x34, 0x30,                   //test        byte ptr [ecx+34h],30h
	0x74, 0x2A,                               //je          next_force
	0x3B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //cmp         ecx,[ecx+0B8h]
	0x75, 0x22,                               //jne         next_force
	0x3B, 0xCE,                               //cmp         ecx,esi
	0x74, 0x1E,                               //je          next_force
	0x0F, 0xB6, 0x41, 0x14,                   //movzx       eax,byte ptr [ecx+14h]
	0x24, 0x0F,                               //and         al,0Fh
	0x3C, 0x05,                               //cmp         al,5
	0x7D, 0x02,                               //jge         add_basic_prestige
	0x04, 0x08,                               //add         al,8
	                                          //add_basic_prestige:
	0x03, 0x41, 0x1C,                         //add         eax,dword ptr [ecx+1Ch]
	0x3D, 0xE8, 0x03, 0x00, 0x00,             //cmp         eax,3E8h
	0x7E, 0x05,                               //jle         save_basic_prestige
	0xB8, 0xE8, 0x03, 0x00, 0x00,             //mov         eax,3E8h
	                                          //save_basic_prestige:
	0x89, 0x41, 0x1C,                         //mov         dword ptr [ecx+1Ch],eax
	                                          //next_force:
	0x81, 0xC1, 0xD4, 0x00, 0x00, 0x00,       //add         ecx,0D4h
	0x42,                                     //inc         edx
	0x80, 0xFA, 0x32,                         //cmp         dl,32h
	0x7C, 0xC4,                               //jl          loop_force
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeLeagueSucceedThunk[] = {0xE8, 0xE7, 0xA4, 0xC4, 0xFF};//dwAddrLeagueSucceed - 458D14h - 5
BYTE codeLeagueSucceedOldThunk[] = {0xE8, 0x97, 0x6A, 0xFE, 0xFF};//call 43F7B0h()
ASM_PATCH patchLeagueSucceedThunk[] = {
	{0x458D14, sizeof(codeLeagueSucceedThunk), codeLeagueSucceedThunk},
	{0x458D14, sizeof(codeLeagueSucceedOldThunk), codeLeagueSucceedOldThunk}};

//baram not build
DWORD dwAddrBaramNotBuild = dwAddrStackBottom + 0x36EC;
BYTE codeBaramNotBuild[] = {
	0x8B, 0x85, 0x68, 0x08, 0x00, 0x00,       //mov         eax,[ebp+868h]
	0x8B, 0x4D, 0x38,                         //mov         ecx,[ebp+38h]
	0xF6, 0x41, 0x34, 0x04,                   //test        byte ptr[ecx+34h],4
	0x74, 0x02,                               //je          end
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeBaramNotBuildThunk[] = {0xE8, 0xD0, 0xEF, 0xBE, 0xFF, 0x41};//dwAddrBaramNotBuild - 4B4717h - 5
BYTE codeBaramNotBuildOldThunk[] = {0x8B, 0x85, 0x68, 0x08, 0x00, 0x00};//mov eax,[ebp+868h]
ASM_PATCH patchBaramNotBuildThunk[] = {
	{0x4B4717, sizeof(codeBaramNotBuildThunk), codeBaramNotBuildThunk},
	{0x4B4717, sizeof(codeBaramNotBuildOldThunk), codeBaramNotBuildOldThunk}};

//build min soldier
BYTE codeBuildMinSoldierThunk[] = {0xBE, 0x70, 0x17, 0x00, 0x00};//mov esi,1770h
BYTE codeBuildMinSoldierOldThunk[] = {0x99, 0x2B, 0xC2, 0x8B, 0xF0};//cdq;sub eax,edx;mov esi,eax
ASM_PATCH patchBuildMinSoldierThunk[] = {
	{0x4B4953, sizeof(codeBuildMinSoldierThunk), codeBuildMinSoldierThunk},
	{0x4B4953, sizeof(codeBuildMinSoldierOldThunk), codeBuildMinSoldierOldThunk}};

//transport goal condition
BYTE codeTransportGoalConditionThunk[] = {
	0x33, 0xC0,                               //xor         eax,eax
	0x81, 0x79, 0x08, 0x78, 0xEC, 0xFF, 0xFF, //cmp         dword ptr [ecx+8],0FFFFEC78h
	0x0F, 0x9C, 0xC0,                         //setl        al
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};
BYTE codeTransportGoalConditionOldThunk[] = {
	0xE8, 0xA4, 0xEE, 0xF8, 0xFF, 0x85, 0xC0, 0x75, 0x0E, 0x8B, 0x86, 0xE8, 0x00, 0x00};
ASM_PATCH patchTransportGoalConditionThunk[] = {
	{0x4BBBB7, sizeof(codeTransportGoalConditionThunk), codeTransportGoalConditionThunk},
	{0x4BBBB7, sizeof(codeTransportGoalConditionOldThunk), codeTransportGoalConditionOldThunk}};

//init match step
BYTE codeInitMatchStepThunk[] = {
	0xC6, 0x05, 0xC9, 0xF4, 0x43, 0x00, 0x00  //mov         byte ptr [transport_match_step],0
};
BYTE codeInitMatchStepOldThunk[] = {
	0xFF, 0x52, 0x10, 0x85, 0xC0, 0x74, 0x14};
ASM_PATCH patchInitMatchStepThunk[] = {
	{0x4BC361, sizeof(codeInitMatchStepThunk), codeInitMatchStepThunk},
	{0x4BC361, sizeof(codeInitMatchStepOldThunk), codeInitMatchStepOldThunk}};

//select build area
DWORD dwAddrSelectBuildArea = dwAddrStackBottom + 0x3250;
BYTE codeSelectBuildArea[] = {
	0x8B, 0x8D, 0x64, 0x08, 0x00, 0x00,       //mov         ecx,dword ptr [ebp+864h]
	0x8A, 0x85, 0x68, 0x08, 0x00, 0x00,       //mov         al, [ebp+868h]
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x0C,                               //je          end
	0x3C, 0x03,                               //cmp         al,3
	0x7D, 0x05,                               //jge         get_second_area
	0xF6, 0xC1, 0x10,                         //test        cl,10h
	0x75, 0x03,                               //jne         end
	                                          //get_second_area:
	0x8B, 0x49, 0x04,                         //mov         ecx,dword ptr [ecx+4]
	                                          //end:
	0xC3                                      //ret
};

BYTE codeSelectBuildAreaThunk[] = {0xE8, 0xB3, 0xEA, 0xBE, 0xFF, 0x40};//dwAddrSelectBuildArea - 4B4798h - 5
BYTE codeSelectBuildAreaOldThunk[] = {0x8B, 0x8D, 0x64, 0x08, 0x00, 0x00};//mov ecx,[ebp+864h]
ASM_PATCH patchSelectBuildAreaThunk[] = {
	{0x4B4798, sizeof(codeSelectBuildAreaThunk), codeSelectBuildAreaThunk},
	{0x4B4798, sizeof(codeSelectBuildAreaOldThunk), codeSelectBuildAreaOldThunk}};

//decide build
DWORD dwAddrDecideBuild = dwAddrStackBottom + 0x17D0;
BYTE codeDecideBuild[] = {
	0x8B, 0x44, 0x24, 0x18,                   //mov         eax,dword ptr [esp+18h]
	0x8B, 0x4C, 0x24, 0x1C,                   //mov         ecx,dword ptr [esp+1Ch]
	0x89, 0x0D, 0xF7, 0xFA, 0x43, 0x00,       //mov         dword ptr [build_real_goal],ecx
	0x6A, 0x0C,                               //push        0Ch
	0x6A, 0x0B,                               //push        0Bh
	0x51,                                     //push        ecx
	0x50,                                     //push        eax
	0xB8, 0x80, 0xA6, 0x44, 0x00,             //mov         eax,44A680h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x83, 0xE8, 0x14,                         //sub         eax,14h
	0x6B, 0xC0, 0x02,                         //imul        eax,eax,02h
	0x83, 0x04, 0x24, 0x04,                   //add         dword ptr [esp],4
	0xC3                                      //ret
};

BYTE codeDecideBuildThunk[] = {0xE8, 0x13, 0xCE, 0xBE, 0xFF, 0x41};//dwAddrDecideBuild - 4B49B8h - 5
BYTE codeDecideBuildOldThunk[] = {0x8B, 0x85, 0x68, 0x08, 0x00, 0x00};//mov eax,[ebp+868h]
ASM_PATCH patchDecideBuildThunk[] = {
	{0x4B49B8, sizeof(codeDecideBuildThunk), codeDecideBuildThunk},
	{0x4B49B8, sizeof(codeDecideBuildOldThunk), codeDecideBuildOldThunk}};

//build real goal
DWORD dwAddrBuildRealGoal = 0x453D61;
BYTE codeBuildRealGoal[] = {
	0xA1, 0xF7, 0xFA, 0x43, 0x00,             //mov         eax,[build_real_goal]
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x68, 0x90, 0x30, 0x47, 0x00,             //push        473090h
	0xC3                                      //ret
};

BYTE codeBuildRealGoalThunk[] = {0xE8, 0xA9, 0xF7, 0xF9, 0xFF};//dwAddrBuildRealGoal - 4B45B3h - 5
BYTE codeBuildRealGoalOldThunk[] = {0xE8, 0xD8, 0xEA, 0xFB, 0xFF};//call 473090h()
ASM_PATCH patchBuildRealGoalThunk[] = {
	{0x4B45B3, sizeof(codeBuildRealGoalThunk), codeBuildRealGoalThunk},
	{0x4B45B3, sizeof(codeBuildRealGoalOldThunk), codeBuildRealGoalOldThunk}};

//max build money
DWORD dwAddrMaxBuildMoney = dwAddrStackBottom + 0x2BC8;
BYTE codeMaxBuildMoney[] = {
	0x51,                                     //push        ecx
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0x51,                                     //push        ecx
	0xB8, 0xB0, 0xD9, 0x43, 0x00,             //mov         eax,43D9B0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x8B, 0x17,                               //mov         edx,dword ptr [edi]
	0x2B, 0xD0,                               //sub         edx,eax
	0x8B, 0x81, 0x84, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+84h]
	0xC1, 0xE0, 0x0B,                         //shl         eax,0Bh
	0x2B, 0xD0,                               //sub         edx,eax
	0x59,                                     //pop         ecx
	0x83, 0xFA, 0x64,                         //cmp         edx,64h
	0x7C, 0x0C,                               //jl          fail
	0x89, 0x17,                               //mov         [edi],edx
	0x89, 0x54, 0x24, 0x08,                   //mov         [esp+8],edx
	0x68, 0xD0, 0xDE, 0x46, 0x00,             //push        46DED0h
	0xC3,                                     //ret
											  //fail:
	0xC2, 0x08, 0x00                          //ret          8
};

BYTE codeMaxBuildMoneyThunk[] = {0xE8, 0x86, 0xEE, 0xBE, 0xFF};//dwAddrMaxBuildMoney - 4B3D3Dh - 5
BYTE codeMaxBuildMoneyOldThunk[] = {0xE8, 0x8E, 0xA1, 0xFB, 0xFF};//call 46DED0h()
ASM_PATCH patchMaxBuildMoneyThunk[] = {
	{0x4B3D3D, sizeof(codeMaxBuildMoneyThunk), codeMaxBuildMoneyThunk},
	{0x4B3D3D, sizeof(codeMaxBuildMoneyOldThunk), codeMaxBuildMoneyOldThunk}};

//select train person
DWORD dwAddrSelectTrainPerson = dwAddrStackBottom + 0x37A8;
BYTE codeSelectTrainPerson[] = {
	0x80, 0x7F, 0x06, 0x05,                   //cmp         byte ptr [edi+6],5
	0x74, 0x11,                               //je          normal
	0x80, 0xBF, 0x90, 0x00, 0x00, 0x00, 0x5C, //cmp         [edi+90h],5Ch
	0x7D, 0x08,                               //jge         normal
	0xC7, 0x44, 0x24, 0x08, 0xC5, 0x37, 0x0A, 0x00,//mov    dword ptr [esp+8],return_max_ability
	                                          //normal:
	0x68, 0x80, 0x32, 0x47, 0x00,             //push        473280h
	0xC3,                                     //ret
	                                          //return_max_ability:
	0xB8, 0x64, 0x00, 0x00, 0x00,             //mov         eax,64h
	0xC3                                      //ret
};

BYTE codeSelectTrainPersonThunk[] = {0xE8, 0xA3, 0x55, 0xBF, 0xFF};//dwAddrSelectTrainPerson - 4AE200h - 5
BYTE codeSelectTrainPersonOldThunk[] = {0xE8, 0x7B, 0x50, 0xFC, 0xFF};//call 473280h()
ASM_PATCH patchSelectTrainPersonThunk[] = {
	{0x4AE200, sizeof(codeSelectTrainPersonThunk), codeSelectTrainPersonThunk},
	{0x4AE200, sizeof(codeSelectTrainPersonOldThunk), codeSelectTrainPersonOldThunk}};

//display year
DWORD dwAddrDisplayYear = dwAddrStackBottom + 0x3800;
BYTE codeDisplayYear[] = {
	0x81, 0xC1, 0x00, 0x00, 0x00, 0x00,       //add         ecx,0
	0x85, 0xC9,                               //test        ecx,ecx
	0x7C, 0x0A,                               //jl          display_negtive_year
	                                          //update_year:
	0x89, 0x4C, 0x24, 0x0C,                   //mov         dword ptr [esp+0Ch],ecx
	0x68, 0xC7, 0x3A, 0x5D, 0x00,             //push        5D3AC7h
	0xC3,                                     //ret
	                                          //display_negtive_year:
	0x66, 0xC7, 0x02, 0xAB, 0x65,             //mov         word ptr [edx],065ABh
	0x83, 0x44, 0x24, 0x04, 0x02,             //add         dword ptr [esp+4],2
	0xF7, 0xD9,                               //neg         ecx
	0xEB, 0xE8                                //jmp         update_year
};

BYTE codeDisplayYearThunk[] = {0xE8, 0x1E, 0xDC, 0xB7, 0xFF};//dwAddrDisplayYear - 525BDDh - 5
BYTE codeDisplayYearOldThunk[] = {0xE8, 0xE5, 0xDE, 0x0A, 0x00};//call 5D3AC7h
ASM_PATCH patchDisplayYearThunk[] = {
	{0x525BDD, sizeof(codeDisplayYearThunk), codeDisplayYearThunk},
	{0x525BDD, sizeof(codeDisplayYearOldThunk), codeDisplayYearOldThunk}};

//refuse change
DWORD dwAddrRefuseChange = dwAddrStackBottom + 0x372C;
BYTE codeRefuseChange[] = {
	0x50,                                     //push        eax
	0x3B, 0xC8,                               //cmp         ecx,eax
	0x7E, 0x20,                               //jle         normal
	0x8B, 0x8B, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,[ebx+0B8h]
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr[ecx+34h],1
	0x74, 0x12,                               //je          check_change_flag
	0x99,                                     //cdq
	0xB9, 0x19, 0x00, 0x00, 0x00,             //mov         ecx,19h
	0xF7, 0xF1,                               //div         eax,ecx
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x34, 0x01,                               //xor         al,1
	                                          //check_change_flag:
	0x85, 0xC0,                               //test        eax,eax
	                                          //normal:
	0x58,                                     //pop         eax
	0xC2, 0x0C, 0x00                          //ret         0Ch
};

BYTE codeRefuseChangeThunk[] = {0xE8, 0xB7, 0x40, 0xC1, 0xFF};//dwAddrRefuseChange - 48F670h - 5
BYTE codeRefuseChangeOldThunk[] = {0x83, 0xC4, 0x0C, 0x3B, 0xC8};//add esp,0Ch;cmp ecx,eax
ASM_PATCH patchRefuseChangeThunk[] = {
	{0x48F670, sizeof(codeRefuseChangeThunk), codeRefuseChangeThunk},
	{0x48F670, sizeof(codeRefuseChangeOldThunk), codeRefuseChangeOldThunk}};

//killer power to damage
DWORD dwAddrKillerPowerToDamage = dwAddrStackBottom + 0x39DC;
BYTE codeKillerPowerToDamage[] = {
	0x80, 0x79, 0x54, 0x04,                   //cmp         byte ptr [ecx+54h],4
	0x74, 0x18,                               //je          normal
	0x8B, 0x45, 0x3C,                         //mov         eax,dword ptr [ebp+3Ch]
	0xF6, 0x40, 0x20, 0x01,                   //test        byte ptr [eax+20h],1
	0x75, 0x0F,                               //jne         normal
	0x8B, 0x8F, 0xF8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edi+0F8h]
	0x83, 0x79, 0x54, 0x06,                   //cmp         dword ptr[ecx+54h],6
	0x7D, 0x03,                               //jge         normal
	0x8B, 0x59, 0x64,                         //mov         ebx,dword ptr [ecx+64h]
	                                          //normal:
	0x68, 0x00, 0xD3, 0x41, 0x00,             //push        41D300h
	0xC3,                                     //ret
};

BYTE codeKillerPowerToDamageThunk[] = {0xE8, 0x41, 0x4B, 0xBA, 0xFF};//dwAddrKillerPowerToDamage - 4FEE96h - 5
BYTE codeKillerPowerToDamageOldThunk[] = {0xE8, 0x65, 0xE4, 0xF1, 0xFF};//call 41D300h()
ASM_PATCH patchKillerPowerToDamageThunk[] = {
	{0x4FEE96, sizeof(codeKillerPowerToDamageThunk), codeKillerPowerToDamageThunk},
	{0x4FEE96, sizeof(codeKillerPowerToDamageOldThunk), codeKillerPowerToDamageOldThunk}};

//linkage killer to dialog
DWORD dwAddrLinkageKillerToDialog = dwAddrStackBottom + 0x3510;
BYTE codeLinkageKillerToDialog[] = {
	0x3B, 0x7B, 0x30,                         //cmp         edi,dword ptr [ebx+30h]
	0x75, 0x06,                               //jne         test_water_killer
	                                          //normal:
	0x68, 0xD0, 0x6E, 0x56, 0x00,             //push        566ED0h
	0xC3,                                     //ret
	                                          //test_water_killer:
	0x80, 0x7A, 0x54, 0x04,                   //cmp         byte ptr [edx+54h],4
	0x74, 0xF4,                               //je          normal
	0x8B, 0x87, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edi+0F8h]
	0x89, 0x44, 0x24, 0x14,                   //mov         dword ptr [esp+14h],eax
	0xEB, 0xE8                                //jmp         normal
};

BYTE codeLinkageKillerToDialogThunk[] = {0xE8, 0xE6, 0xFF, 0xB9, 0xFF};//dwAddrLinkageKillerToDialog - 503525h - 5
BYTE codeLinkageKillerToDialogOldThunk[] = {0xE8, 0xA6, 0x39, 0x06, 0x00};//call 566ED0h()
ASM_PATCH patchLinkageKillerToDialogThunk[] = {
	{0x503525, sizeof(codeLinkageKillerToDialogThunk), codeLinkageKillerToDialogThunk},
	{0x503525, sizeof(codeLinkageKillerToDialogOldThunk), codeLinkageKillerToDialogOldThunk}};

//draft fail bug
DWORD dwAddrDraftFailBug = dwAddrStackBottom + 0x4E00;
BYTE codeDraftFailBug[] = {
	0x83, 0x7C, 0x24, 0x20, 0x00,             //cmp         dword ptr [esp+20h],0
	0x74, 0x25,                               //je          check_next_city
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0x80, 0x79, 0x24, 0x01,                   //cmp         byte ptr [ecx+24h],1
	0x74, 0x01,                               //je          municipal_force
	0xC3,                                     //ret
	                                          //municipal_force:
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0x02, 0x43, 0x04,                         //add         al,[ebx+4]
	0xA8, 0x05,                               //test        al,5
	0x75, 0x03,                               //jne         clear_draft_person_list
	0x85, 0xC0,                               //test        eax,eax
	0xC3,                                     //ret
	                                          //clear_draft_person_list:
	0x8D, 0x4C, 0x24, 0x14,                   //lea         ecx,[esp+14h]
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	                                          //check_next_city:
	0x83, 0x7E, 0x50, 0x00,                   //cmp         dword ptr [esi+50h],0
	0x75, 0x01,                               //jne         skip_next_city
	0xC3,                                     //ret
	                                          //skip_next_city:
	0x68, 0x37, 0xFA, 0x49, 0x00,             //push        49FA37h
	0xC2, 0x04, 0x00                          //ret         
};

BYTE codeDraftFailBugThunk[] = {0xE8, 0x64, 0x53, 0xC0, 0xFF, 0x90};//dwAddrDraftFailBug - 49FA97h - 5
BYTE codeDraftFailBugOldThunk[] = {0x8B, 0x44, 0x24, 0x1C, 0x85, 0xC0};//mov eax,[esp+1Ch];test eax,eax
ASM_PATCH patchDraftFailBugThunk[] = {
	{0x49FA97, sizeof(codeDraftFailBugThunk), codeDraftFailBugThunk},
	{0x49FA97, sizeof(codeDraftFailBugOldThunk), codeDraftFailBugOldThunk}};

//stop task bug
DWORD dwAddrStopTaskBug = dwAddrStackBottom + 0x6CE0;
BYTE codeStopTaskBug[] = {
	                                          //stop_task_bug:
	0xB8, 0x10, 0x0E, 0x47, 0x00,             //mov         eax,470E10h
	0xFF, 0xD0,                               //call        eax
	0x83, 0x7E, 0x50, 0x00,                   //cmp         dword ptr [esi+50h],0
	0x75, 0x01,                               //jne         skip_next_building
	0xC3,                                     //ret
	                                          //skip_next_building:
	0x58,                                     //pop         eax
	0x05, 0x91, 0xFF, 0xFF, 0xFF,             //add         eax,0FFFFFF91h
	0x50,                                     //push        eax
	0xC3                                      //ret
};

BYTE codeStopTrainBugThunk[] = {0xE8, 0x1A, 0x8B, 0xBF, 0xFF};//dwAddrStopTrainBug - 4AE1C1h - 5
BYTE codeStopTrainBugOldThunk[] = {0xE8, 0x4A, 0x2C, 0xFC, 0xFF};//call 470E10h()
ASM_PATCH patchStopTrainBugThunk[] = {
	{0x4AE1C1, sizeof(codeStopTrainBugThunk), codeStopTrainBugThunk},
	{0x4AE1C1, sizeof(codeStopTrainBugOldThunk), codeStopTrainBugOldThunk}};

BYTE codeStopCommerceBugThunk[] = {0xE8, 0xDA, 0x37, 0xBF, 0xFF};//dwAddrStopCommerceBug - 4B3501h - 5
BYTE codeStopCommerceBugOldThunk[] = {0xE8, 0x0A, 0xD9, 0xFB, 0xFF};//call 470E10h()
ASM_PATCH patchStopCommerceBugThunk[] = {
	{0x4B3501, sizeof(codeStopCommerceBugThunk), codeStopCommerceBugThunk},
	{0x4B3501, sizeof(codeStopCommerceBugOldThunk), codeStopCommerceBugOldThunk}};

BYTE codeStopCultivateBugThunk[] = {0xE8, 0x4A, 0xB5, 0xBF, 0xFF};//dwAddrStopCultivateBug - 4AB791h - 5
BYTE codeStopCultivateBugOldThunk[] = {0xE8, 0x7A, 0x56, 0xFC, 0xFF};//call 470E10h()
ASM_PATCH patchStopCultivateBugThunk[] = {
	{0x4AB791, sizeof(codeStopCultivateBugThunk), codeStopCultivateBugThunk},
	{0x4AB791, sizeof(codeStopCultivateBugOldThunk), codeStopCultivateBugOldThunk}};

BYTE codeStopVisitBugThunk[] = {0xE8, 0x1A, 0xBE, 0xBF, 0xFF};//dwAddrStopVisitBug - 4AAEC1h - 5
BYTE codeStopVisitBugOldThunk[] = {0xE8, 0x4A, 0x5F, 0xFC, 0xFF};//call 470E10h()
ASM_PATCH patchStopVisitBugThunk[] = {
	{0x4AAEC1, sizeof(codeStopVisitBugThunk), codeStopVisitBugThunk},
	{0x4AAEC1, sizeof(codeStopVisitBugOldThunk), codeStopVisitBugOldThunk}};

BYTE codeStopRepairBugThunk[] = {0xE8, 0x0A, 0xB0, 0xBF, 0xFF};//dwAddrStopRepairBug - 4ABCD1h - 5
BYTE codeStopRepairBugOldThunk[] = {0xE8, 0x3A, 0x51, 0xFC, 0xFF};//call 470E10h()
ASM_PATCH patchStopRepairBugThunk[] = {
	{0x4ABCD1, sizeof(codeStopRepairBugThunk), codeStopRepairBugThunk},
	{0x4ABCD1, sizeof(codeStopRepairBugOldThunk), codeStopRepairBugOldThunk}};

//draft min food
DWORD dwAddrDraftMinFood = dwAddrStackBottom + 0x5E8;
BYTE codeDraftMinFood[] = {
	0xB8, 0x90, 0x01, 0x0A, 0x00,			  //mov         eax,check_draft_food
	0xFF, 0xD0,								  //call        eax
	0x85, 0xC0,								  //test        eax,eax
	0x8B, 0xC6,								  //mov         eax,esi
	0x75, 0x01,								  //jne         end
	0x40,									  //inc         eax
	                                          //end:
	0xC6, 0x04, 0x24, 0x32,                   //mov         byte ptr [esp],32h
	0xC3                                      //ret
};

BYTE codeDraftMinFoodThunk[] = {0xE8, 0xC3, 0x0A, 0xC0, 0xFF};//dwAddrDraftMinFood - 49FB20h - 5
BYTE codeDraftMinFoodOldThunk[] = {0xE8, 0x7B, 0xF4, 0xF9, 0xFF};//call 43EFA0h()
ASM_PATCH patchDraftMinFoodThunk[] = {
	{0x49FB20, sizeof(codeDraftMinFoodThunk), codeDraftMinFoodThunk},
	{0x49FB20, sizeof(codeDraftMinFoodOldThunk), codeDraftMinFoodOldThunk}};

//save attack source building
DWORD dwAddrSaveAttackSourceBuilding = 0x459B94;
BYTE codeSaveAttackSourceBuilding[] = {
	0x89, 0x35, 0x6C, 0xFA, 0x43, 0x00,       //mov         [attack_source_building],esi
	0x68, 0xA0, 0xF5, 0x4A, 0x00,             //push        4AF5A0h
	0xC3                                      //ret
};

BYTE codeSaveAttackSourceBuildingThunk[] = {0xE8, 0x73, 0x42, 0xFA, 0xFF};//dwAddrSaveAttackSourceBuilding - 4B591Ch - 5
BYTE codeSaveAttackSourceBuildingOldThunk[] = {0xE8, 0x7F, 0x9C, 0xFF, 0xFF};//call 4AF5A0h()
ASM_PATCH patchSaveAttackSourceBuildingThunk[] = {
	{0x4B591C, sizeof(codeSaveAttackSourceBuildingThunk), codeSaveAttackSourceBuildingThunk},
	{0x4B591C, sizeof(codeSaveAttackSourceBuildingOldThunk), codeSaveAttackSourceBuildingOldThunk}};

//correct building attack soldier
DWORD dwAddrCorrectBuildingAttackSoldier = dwAddrStackBottom + 0x3A00;
BYTE codeCorrectBuildingAttackSoldier[] = {
	0x3B, 0xCA,                               //cmp         ecx,edx
	0x7D, 0x02,                               //jge         got_left_soldier
	0x8B, 0xCA,                               //mov         ecx,edx
	                                          //got_left_soldier:
	0x8B, 0x35, 0x6C, 0xFA, 0x43, 0x00,       //mov         esi,[attack_source_building]
	0x8B, 0x9E, 0x88, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [esi+88h]
	0x2B, 0xD9,                               //sub         ebx,ecx
	0x81, 0xFB, 0x88, 0x13, 0x00, 0x00,       //cmp         ebx,1388h
	0x7D, 0x15,                               //jge         test_baram_force
	                                          //delete_attack_building:
	0x56,                                     //push        esi
	0x8D, 0x8D, 0x38, 0x08, 0x00, 0x00,       //lea         ecx,[ebp+838h]
	0xB8, 0x50, 0xEE, 0x46, 0x00,             //mov         eax,46EE50h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x86, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+88h]
	0xC3,                                     //ret
	                                          //test_baram_force:
	0x8B, 0x45, 0x38,                         //mov         eax,[ebp+38h]
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr[eax+34h],4
	0x74, 0x03,                               //je          normal
	0x8B, 0xC1,                               //mov         eax,ecx
	0xC3,                                     //ret
	                                          //normal
	0x8B, 0x86, 0xE8, 0x00, 0x00, 0x00,       //mov         eax,[esi+0E8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xD5,                               //je          delete_attack_building
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x05,                               //jg          got_attack_person
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          got_attack_person
	0x49,                                     //dec         ecx
	                                          //got_attack_person:
	0x51,                                     //push        ecx
	0x8B, 0xC3,                               //mov         eax,ebx
	0x99,                                     //cdq
	0xB9, 0x10, 0x27, 0x00, 0x00,             //mov         ecx,2710h
	0xF7, 0xF1,                               //div         eax,ecx
	0x81, 0xFA, 0x88, 0x13, 0x00, 0x00,       //cmp         edx,1388h
	0x7C, 0x01,                               //jl          got_min_attack_person
	0x40,                                     //inc         eax
	                                          //got_min_attack_person:
	0x8B, 0xD0,                               //mov         edx,eax
	0x58,                                     //pop         eax
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7F, 0x11,                               //jg          add_attack_soldier
	0x74, 0x06,                               //je          end
	0x69, 0xD8, 0x10, 0x27, 0x00, 0x00,       //imul        ebx,eax,2710h
	                                          //end:
	0x8B, 0x86, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+88h]
	0x2B, 0xC3,                               //sub         eax,ebx
	0xC3,                                     //ret
	                                          //add_attack_soldier:
	0x2B, 0xC2,                               //sub         eax,edx
	0x8B, 0xCA,                               //mov         ecx,edx
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x66, 0x3D, 0x03, 0x00,                   //cmp         ax,3
	0x7C, 0x06,                               //jl          got_add_base
	0x66, 0xB8, 0x03, 0x00,                   //mov         ax,3
	0x33, 0xD2,                               //xor         edx,edx
	                                          //got_add_base:
	0x50,                                     //push        eax
	0x52,                                     //push        edx
	0xB8, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         eax,7FFFFFFFh
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x5A,                                     //pop         edx
	0xF7, 0xEA,                               //imul        edx
	0xB9, 0x33, 0x33, 0x33, 0x33,             //mov         ecx,33333333h
	0xF7, 0xE9,                               //imul        ecx
	0xD1, 0xE9,                               //shr         ecx,1
	0x58,                                     //pop         eax
	0x0F, 0xAF, 0xC1,                         //imul        eax,ecx
	0x03, 0xC2,                               //add         eax,edx
	0xF7, 0xEB,                               //imul        ebx
	0x03, 0xDA,                               //add         ebx,edx
	0xEB, 0xC2                                //jmp         end
};

BYTE codeCorrectBuildingAttackSoldierThunk[] = {0xE8, 0xD4, 0xDF, 0xBE, 0xFF, 0x90};
//dwAddrCorrectBuildingAttackSoldier - 4B5A27h - 5
BYTE codeCorrectBuildingAttackSoldierOldThunk[] = {0xFF, 0x15, 0x30, 0xF3, 0x5F, 0x00};//call [5FF330h]
ASM_PATCH patchCorrectBuildingAttackSoldierThunk[] = {
	{0x4B5A27, sizeof(codeCorrectBuildingAttackSoldierThunk), codeCorrectBuildingAttackSoldierThunk},
	{0x4B5A27, sizeof(codeCorrectBuildingAttackSoldierOldThunk), codeCorrectBuildingAttackSoldierOldThunk}};

//correct goal building soldier
DWORD dwAddrCorrectGoalBuildingSoldier = dwAddrStackBottom + 0x3B00;
BYTE codeCorrectGoalBuildingSoldier[] = {
	0x53,                                     //push        ebx
	0xB8, 0x40, 0x5A, 0x0A, 0x00,             //mov         eax,pre_building_soldier2
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x8B, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ebx+0CCh]
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0x03,                               //jne         test_player_force
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_player_force:
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0B8h]
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr [ecx+34h],1
	0x74, 0xF1,                               //je          end
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0xE9,                               //mov         ebp,ecx
	0xBF, 0xB0, 0x93, 0x4B, 0x01,             //mov         edi,14B93B0h
	                                          //loop_incure_troop:
	0x39, 0x6F, 0x74,                         //cmp         dword ptr [edi+74h],ebp
	0x75, 0x32,                               //jne         jmp_next_incure_troop
	0x8B, 0x47, 0x20,                         //mov         eax,dword ptr [edi+20h]
	0xA9, 0x06, 0x00, 0x70, 0x00,             //test        eax,700006h
	0x75, 0x28,                               //jne         jmp_next_incure_troop
	0xA8, 0x08,                               //test        al,8
	0x75, 0x05,                               //jne         test_troop_array
	0x39, 0x5F, 0x64,                         //cmp         dword ptr [edi+64h],ebx
	0x74, 0x1F,                               //je          jmp_next_incure_troop
	                                          //test_troop_array:
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x90, 0xE3, 0x45, 0x00,             //mov         eax,45E390h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x14,                               //jne         test_troop_goal
	0x8B, 0x4F, 0x6C,                         //mov         ecx,dword ptr [edi+6Ch]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x0B,                               //cmp         al,0Bh
	0x74, 0x0A,                               //je          test_troop_goal 
	0x3C, 0x05,                               //cmp         al,5
	0x7F, 0x04,                               //jg          jmp_next_incure_troop
	0x3C, 0x04,                               //cmp         al,4
	0x75, 0x02,                               //jne         test_troop_goal
	                                          //jmp_next_incure_troop:
	0xEB, 0x43,                               //jmp         next_incure_troop 
	                                          //test_troop_goal:
	0x80, 0x7F, 0x52, 0x03,                   //cmp         byte ptr [edi+52h],3
	0x75, 0x1C,                               //jne         test_troop_distance
	0x0F, 0xB7, 0x47, 0x50,                   //movzx       eax,word ptr [edi+50h]
	0x50,                                     //push        eax
	0xB8, 0xC0, 0x32, 0x45, 0x00,             //mov         eax,4532C0h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x32,                         //cmp         eax,32h
	0x7C, 0x21,                               //jl          next_incure_troop
	                                          //test_troop_distance:
	0x53,                                     //push        ebx
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x64,                         //cmp         eax,64h
	0x7D, 0x12,                               //jge         next_incure_troop
	0x53,                                     //push        ebx
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x70, 0x88, 0x46, 0x00,             //mov         eax,468870h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x14,                         //cmp         eax,14h
	0x7D, 0x03,                               //jge         next_incure_troop
	0x03, 0x77, 0x30,                         //add         esi,dword ptr [edi+30h]
	                                          //next_incure_troop:
	0x81, 0xC7, 0x04, 0x01, 0x00, 0x00,       //add         edi,104h
	0x66, 0x81, 0x7F, 0x04, 0x51, 0x03,       //cmp         word ptr [edi+4],351h
	0x0F, 0x8C, 0x72, 0xFF, 0xFF, 0xFF,       //jl          loop_incure_troop
	0xB8, 0x8C, 0x69, 0x0A, 0x00,             //mov         eax,get_near_building_soldier
	0xFF, 0xD0,                               //call        eax
	0x03, 0xC6,                               //add         eax,esi
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x89, 0x85, 0x28, 0x04, 0x00, 0x00,       //mov         dword ptr [ebp+428h],eax
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCorrectGoalBuildingSoldierThunk[] = {0xE8, 0x95, 0xE0, 0xBE, 0xFF};
//dwAddrCorrectGoalBuildingSoldier - 4B5A66h - 5
BYTE codeCorrectGoalBuildingSoldierOldThunk[] = {0xE8, 0x85, 0xFA, 0xFF, 0xFF};//call 4B54F0h()
ASM_PATCH patchCorrectGoalBuildingSoldierThunk[] = {
	{0x4B5A66, sizeof(codeCorrectGoalBuildingSoldierThunk), codeCorrectGoalBuildingSoldierThunk},
	{0x4B5A66, sizeof(codeCorrectGoalBuildingSoldierOldThunk), codeCorrectGoalBuildingSoldierOldThunk}};

//check person killer level
DWORD dwAddrCheckPersonKillerLevel= dwAddrStackBottom + 0x2680;
BYTE codeCheckPersonKillerLevel[] = {
	0x0F, 0xB7, 0x51, 0x04,                   //movzx       edx,word ptr [ecx+4]
	0x81, 0xFA, 0x20, 0x03, 0x00, 0x00,       //cmp         edx,320h
	0x7C, 0x06,                               //jl          get_max_killer_level
	                                          //normal:
	0x68, 0x40, 0xC9, 0x44, 0x00,             //push        44C940h
	0xC3,                                     //ret
	                                          //get_max_killer_level:
	0x8B, 0x14, 0x95, 0x00, 0x40, 0x0A, 0x00, //mov         edx,dword ptr [edx*4+person_config_info]
	0x8B, 0xC8,                               //mov         ecx,eax
	0xD1, 0xE1,                               //shl         ecx,1
	0xD3, 0xEA,                               //shr         edx,cl
	0x83, 0xE2, 0x03,                         //and         edx,3
	0x52,                                     //push        edx
	0x0F, 0xB6, 0x46, 0x04,                   //movzx       eax,byte ptr [esi+4]
	0x3C, 0x0F,                               //cmp         al,0Fh
	0x7D, 0x04,                               //jge         intelligence_killer
	0xB1, 0x03,                               //mov         cl,3
	0xEB, 0x04,                               //jmp         get_killer_level
	                                          //intelligence_killer:
	0x2C, 0x0F,                               //sub         al,0Fh
	0xB1, 0x04,                               //mov         cl,4
	                                          //get_killer_level:
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x58,                                     //pop         eax
	0x3A, 0xD0,                               //cmp         dl,al
	0x8B, 0xCF,                               //mov         ecx,edi
	0x7E, 0xCF,                               //jle         normal
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCheckPersonKillerLevelThunk[] = {0xE8, 0x24, 0x46, 0xC5, 0xFF};//dwAddrCheckPersonKillerLevel - 44E057h - 5
BYTE codeCheckPersonKillerLevelOldThunk[] = {0xE8, 0xE4, 0xE8, 0xFF, 0xFF};//call 44C940h()
ASM_PATCH patchCheckPersonKillerLevelThunk[] = {
	{0x44E057, sizeof(codeCheckPersonKillerLevelThunk), codeCheckPersonKillerLevelThunk},
	{0x44E057, sizeof(codeCheckPersonKillerLevelOldThunk), codeCheckPersonKillerLevelOldThunk}};

//judge killer linkage
DWORD dwAddrJudgeKillerLinkage = dwAddrStackBottom + 0x68D0;
BYTE codeJudgeKillerLinkage[] = {
	0xEB, 0x0E,                               //jmp         alike_killer_linkage
	0x39, 0x44, 0x24, 0x20,                   //cmp         dword ptr [esp+20h],eax
	0x74, 0x14,                               //je          test_second_killer
	                                          //non_killer_linkage:
	0x68, 0x57, 0x24, 0x50, 0x00,             //push        502457h
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //alike_killer_linkage:
	0x8B, 0x50, 0x54,                         //mov         edx,dword ptr [eax+54h]
	0x8B, 0x4C, 0x24, 0x20,                   //mov         ecx,dword ptr [esp+20h]
	0x39, 0x51, 0x54,                         //cmp         dword ptr [ecx+54h],edx
	0x75, 0xEC,                               //jne         non_killer_linkage
	                                          //test_second_killer:
	0x3B, 0x85, 0xF8, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [ebp+0F8h]
	0x75, 0xE4,                               //jne         non_killer_linkage
	0xC3                                      //ret
};

BYTE codeJudgeKillerLinkageThunk[] = {0xE8, 0xF6, 0x44, 0xBA, 0xFF, 0x40};//dwAddrJudgeKillerLinkage - 5023D5h - 5
BYTE codeJudgeKillerLinkageOldThunk[] = {0x39, 0x44, 0x24, 0x1C, 0x75, 0x7C};//cmp [esp+1Ch],eax;jnz 502457h
ASM_PATCH patchJudgeKillerLinkageThunk[] = {
	{0x5023D5, sizeof(codeJudgeKillerLinkageThunk), codeJudgeKillerLinkageThunk},
	{0x5023D5, sizeof(codeJudgeKillerLinkageOldThunk), codeJudgeKillerLinkageOldThunk}};

//linkage killer to record
DWORD dwAddrLinkageKillerToRecord = dwAddrStackBottom + 0x29E8;
BYTE codeLinkageKillerToRecord[] = {
	0x80, 0x7F, 0x54, 0x04,                   //cmp         byte ptr [edi+54h],4
	0x74, 0x0A,                               //je          end
	0x8B, 0x80, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0F8h]
	0x89, 0x44, 0x24, 0x10,                   //mov         dword ptr [esp+10h],eax
	                                          //end:
	0x68, 0xD0, 0x6E, 0x56, 0x00,             //push        566ED0h
	0xC3                                      //ret
};

BYTE codeLinkageKillerToRecordThunk[] = {0xE8, 0x46, 0x2F, 0xBA, 0xFF};//dwAddrLinkageKillerToRecord - 4FFA9Dh - 5
BYTE codeLinkageKillerToRecordOldThunk[] = {0xE8, 0x2E, 0x74, 0x06, 0x00};//call 566ED0h()
ASM_PATCH patchLinkageKillerToRecordThunk[] = {
	{0x4FFA9D, sizeof(codeLinkageKillerToRecordThunk), codeLinkageKillerToRecordThunk},
	{0x4FFA9D, sizeof(codeLinkageKillerToRecordOldThunk), codeLinkageKillerToRecordOldThunk}};

//main force dispatch
DWORD dwAddrMainForceDispatch = dwAddrStackBottom + 0x4CAA;
BYTE codeMainForceDispatch[] = {
	0x51,                                     //push        ecx
	0x8B, 0x4D, 0x38,                         //mov         ecx,dword ptr [ebp+38h]
	0xB8, 0xC3, 0x4C, 0x0A, 0x00,             //mov         eax,test_npc_first_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,                                     //pop         ecx
	0x74, 0x06,                               //je          fail
	0x68, 0x50, 0xF7, 0x46, 0x00,             //push        46F750h
	0xC3,                                     //ret
	                                          //fail:
	0xC2, 0x08, 0x00,                         //ret         8
	                                          //test_npc_first_force:
	0x8B, 0x81, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0B8h]
	0x3B, 0xC8,                               //cmp         ecx,eax
	0x75, 0x01,                               //jne         test_player_force
	0xC3,                                     //ret
	                                          //test_player_force:
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x75, 0x03,                               //jne         test_player_sub_force
	                                          //fail:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //test_player_sub_force:
	0xBA, 0x38, 0x3C, 0x25, 0x01,             //mov         edx,1253C38h
	                                          //loop_force:
	0x3B, 0xD0,                               //cmp         edx,eax
	0x74, 0x0C,                               //je          next_force
	0x3B, 0xD1,                               //cmp         edx,ecx
	0x74, 0x16,                               //je          end_loop_force
	0x39, 0x82, 0xB8, 0x00, 0x00, 0x00,       //cmp         dword ptr [edx+0B8h],eax
	0x74, 0x0E,                               //je          end_loop_force
	                                          //next_force:
	0x81, 0xC2, 0xD4, 0x00, 0x00, 0x00,       //add         edx,0D4h
	0x81, 0xFA, 0xCC, 0x64, 0x25, 0x01,       //cmp         edx,12564CCh
	0x7E, 0xE2,                               //jle         loop_force
	                                          //end_loop_force:
	0x3B, 0xD1,                               //cmp         edx,ecx
	0x75, 0xD6,                               //jne         fail
	0xC3                                      //ret
};

BYTE codeMainForceDispatchThunk[] = {0xE8, 0x03, 0x16, 0xC0, 0xFF};//dwAddrMainForceDispatch - 4A36A2h - 5
BYTE codeMainForceDispatchOldThunk[] = {0xE8, 0xA9, 0xC0, 0xFC, 0xFF};//call 46F750h
ASM_PATCH patchMainForceDispatchThunk[] = {
	{0x4A36A2, sizeof(codeMainForceDispatchThunk), codeMainForceDispatchThunk},
	{0x4A36A2, sizeof(codeMainForceDispatchOldThunk), codeMainForceDispatchOldThunk}};

//update seige power
DWORD dwAddrUpdateSeigePower = dwAddrStackBottom + 0x2DB0;
BYTE codeUpdateSeigePower[] = {
	                                          //update_seige_power:
	0x53,                                     //push        ebx
	0x8B, 0x5C, 0x24, 0x08,                   //mov         ebx,dword ptr [esp+8]
	0x8D, 0x44, 0x24, 0x08,                   //lea         eax,[esp+8]
	0x6A, 0x01,                               //push        1
	0x6A, 0x05,                               //push        5
	0x50,                                     //push        eax
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x90, 0xC8, 0x00, 0x00, 0x00,       //call        dword ptr [eax+0C8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          got_max_experience
	0x8B, 0x44, 0x24, 0x08,                   //mov         eax,dword ptr [esp+8]
	                                          //got_max_experience:
	0x2D, 0x58, 0x02, 0x00, 0x00,             //sub         eax,258h
	0xC1, 0xE0, 0x15,                         //shl         eax,15h
	0xF7, 0xEB,                               //imul        ebx
	0x03, 0xDA,                               //add         ebx,edx
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5B,                                     //pop         ebx
	0xC2, 0x04, 0x00                          //ret         4
};

//get array to wall
DWORD dwAddrGetArrayToWall = dwAddrStackBottom + 0x352F;
BYTE codeGetArrayToWall[] = {
	0x8A, 0x50, 0x04,                         //mov         dl,byte ptr [eax+4]
	0x8B, 0x40, 0x68,                         //mov         eax,dword ptr [eax+68h]
	0x80, 0xFA, 0x08,                         //cmp         dl,8
	0x7C, 0x05,                               //jl          end
	0x80, 0xFA, 0x0B,                         //cmp         dl,0Bh
	0x7E, 0x05,                               //jle         seige_array
	                                          //end:
	0x8B, 0x4C, 0x24, 0x2C,                   //mov         ecx,dword ptr [esp+2Ch]
	0xC3,                                     //ret
	                                          //seige_array:
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xB0, 0x2D, 0x0A, 0x00,             //mov         eax,update_seige_power
	0xFF, 0xD0,                               //call        eax
	0xEB, 0xEF                                //jmp         end
};

BYTE codeGetArrayToWallThunk[] = {0xE8, 0xC2, 0x94, 0xC0, 0xFF, 0x90, 0x90};//dwAddrGetArrayToWall - 49A068h - 5
BYTE codeGetArrayToWallOldThunk[] = {0x8B, 0x4C, 0x24, 0x28, 0x8B, 0x40, 0x68};//mov ecx,[esp+28h];mov eax,[eax+68h]
ASM_PATCH patchGetArrayToWallThunk[] = {
	{0x49A068, sizeof(codeGetArrayToWallThunk), codeGetArrayToWallThunk},
	{0x49A068, sizeof(codeGetArrayToWallOldThunk), codeGetArrayToWallOldThunk}};

//get array to garrison
DWORD dwAddrGetArrayToGarrison = dwAddrStackBottom + 0x6BB0;
BYTE codeGetArrayToGarrison[] = {
	0x8A, 0x45, 0x04,                         //mov         al,byte ptr [ebp+4]
	0x8B, 0x55, 0x64,                         //mov         edx,dword ptr [ebp+64h]
	0x3C, 0x08,                               //cmp         al,8
	0x7C, 0x04,                               //jl          end
	0x3C, 0x0B,                               //cmp         al,0Bh
	0x7E, 0x03,                               //jle         seige_array
	                                          //end:
	0xD1, 0xE2,                               //shl         edx,1
	0xC3,                                     //ret
	                                          //seige_array:
	0x8B, 0x4C, 0x24, 0x1C,                   //mov         ecx,dword ptr [esp+1Ch]
	0x52,                                     //push        edx
	0xB8, 0xB0, 0x2D, 0x0A, 0x00,             //mov         eax,update_seige_power
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xD0,                               //mov         edx,eax
	0xEB, 0xED                                //jmp         end
};

BYTE codeGetArrayToGarrisonThunk[] = {0xE8, 0x24, 0xC7, 0xC0, 0xFF, 0x40};//dwAddrGetArrayToGarrison - 49A487h - 5
BYTE codeGetArrayToGarrisonOldThunk[] = {0x8B, 0x45, 0x64, 0x8D, 0x14, 0x00};//mov eax,[ebp+64h];lea edx,[eax+eax]
ASM_PATCH patchGetArrayToGarrisonThunk[] = {
	{0x49A487, sizeof(codeGetArrayToGarrisonThunk), codeGetArrayToGarrisonThunk},
	{0x49A487, sizeof(codeGetArrayToGarrisonOldThunk), codeGetArrayToGarrisonOldThunk}};

//direct big animation
DWORD dwAddrDirectBigAnimation = dwAddrStackBottom + 0x30E8;
BYTE codeDirectBigAnimation[] = {
	0x83, 0xFA, 0x0B,                         //cmp         edx,0Bh
	0x7E, 0x0E,                               //jle         end
	0x83, 0xFA, 0x1F,                         //cmp         edx,1Fh
	0x7D, 0x06,                               //jge         killer_on_water
	0x83, 0xC0, 0x11,                         //add         eax,11h
	0x8B, 0xF0,                               //mov         esi,eax
	0xC3,                                     //ret
	                                          //killer_on_water:
	0x83, 0xEA, 0x13,                         //sub         edx,13h
	                                          //end:
	0x8B, 0xF2,                               //mov         esi,edx
	0xC3                                      //ret
};

BYTE codeDirectBigAnimationThunk[] = {0xE8, 0x5F, 0x9D, 0xB6, 0xFF};//dwAddrDirectBigAnimation - 539384h - 5
BYTE codeDirectBigAnimationOldThunk[] = {0x83, 0xC0, 0x11, 0x8B, 0xF0};//add eax,11h;mov esi,eax
ASM_PATCH patchDirectBigAnimationThunk[] = {
	{0x539384, sizeof(codeDirectBigAnimationThunk), codeDirectBigAnimationThunk},
	{0x539384, sizeof(codeDirectBigAnimationOldThunk), codeDirectBigAnimationOldThunk}};

//phase error alienate
DWORD dwAddrPhaseErrorAlienate = dwAddrStackBottom + 0x3680;
BYTE codePhaseErrorAlienate[] = {
	0x8B, 0xF0,                               //mov         esi,eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x26,                               //jle         save_alienate_prop
	0x8B, 0x4C, 0x24, 0x10,                   //mov         ecx,dword ptr [esp+10h]
	0x51,                                     //push        ecx
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x30,                         //call        dword ptr [eax+30h]
	0x59,                                     //pop         ecx
	0xFF, 0xB0, 0xBC, 0x00, 0x00, 0x00,       //push        dword ptr [eax+0BCh]
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x0A,                               //cmp         al,0Ah
	0x7D, 0x0A,                               //jge         save_alienate_prop
	0x83, 0xE8, 0x0A,                         //sub         eax,0Ah
	0xF7, 0xD8,                               //neg         eax
	0x6B, 0xC0, 0x04,                         //imul        eax,eax,4
	0x2B, 0xF0,                               //sub         esi,eax
	                                          //save_alienate_prop:
	0x89, 0x74, 0x24, 0x10,                   //mov         dword ptr [esp+10h],esi
	0x58,                                     //pop         eax
	0x5E,                                     //pop         esi
	0x50,                                     //push        eax
	0xC3                                      //ret
};

BYTE codePhaseErrorAlienateThunk[] = {0xE8, 0x9B, 0x01, 0xC1, 0xFF};//dwAddrPhaseErrorAlienate - 4934E0h - 5
BYTE codePhaseErrorAlienateOldThunk[] = {0x5E, 0x89, 0x44, 0x24, 0x08};//pop esi;mov [esp+8],eax
ASM_PATCH patchPhaseErrorAlienateThunk[] = {
	{0x4934E0, sizeof(codePhaseErrorAlienateThunk), codePhaseErrorAlienateThunk},
	{0x4934E0, sizeof(codePhaseErrorAlienateOldThunk), codePhaseErrorAlienateOldThunk}};

//force fight troop
DWORD dwAddrForceFightTroop = dwAddrStackBottom + 0x4C80;
BYTE codeForceFightTroop[] = {
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,dword ptr [esp+4]
	0x8B, 0x08,                               //mov         ecx,dword ptr [eax]
	0x83, 0x79, 0x24, 0x00,                   //cmp         dword ptr [ecx+24h],0
	0x74, 0x06,                               //je          fail
	0xF6, 0x41, 0x20, 0x03,                   //test        byte ptr [ecx+20h],3
	0x74, 0x03,                               //je          test_source_force
	                                          //fail:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //test_source_force:
	0x8B, 0x50, 0x0C,                         //mov         edx,dword ptr [eax+0Ch]
	0x8B, 0x41, 0x74,                         //mov         eax,dword ptr [ecx+74h]
	0x8B, 0x80, 0xB8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [eax+0B8h]
	0x3B, 0x82, 0xB8, 0x00, 0x00, 0x00,       //cmp         eax,dword ptr [edx+0B8h]
	0x75, 0xE9,                               //jne         fail
	0xC3                                      //ret
};

BYTE codeForceFightTroopThunk[] = {0x80, 0x4C, 0x0A, 0x00};//dwAddrForceFightTroop
BYTE codeForceFightTroopOldThunk[] = {0x50, 0x52, 0x47, 0x00};//475250h()
ASM_PATCH patchForceFightTroopThunk[] = {
	{0x4BBF98, sizeof(codeForceFightTroopThunk), codeForceFightTroopThunk},
	{0x4BBF98, sizeof(codeForceFightTroopOldThunk), codeForceFightTroopOldThunk}};

//check transport task
DWORD dwAddrCheckTransportTask = dwAddrStackBottom + 0x4D00;
BYTE codeCheckTransportTask[] = {
	0xB8, 0x10, 0x76, 0x4B, 0x00,             //mov         eax,4B7610h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         check_transport_force
	0xC3,                                     //ret
	                                          //check_transport_force:
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0xB8, 0xC3, 0x4C, 0x0A, 0x00,             //mov         eax,test_npc_first_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         transport_init
	0xC3,                                     //ret
	                                          //transport_init:
	0x53,                                     //push        ebx
	0x33, 0xDB,                               //xor         ebx,ebx
	                                          //loop_building:
	0x53,                                     //push        ebx
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          next_building
	0x80, 0x60, 0x0F, 0x01,                   //and         byte ptr [eax+0Fh],1
	                                          //next_building:
	0x43,                                     //inc         ebx
	0x81, 0xFB, 0xFA, 0x00, 0x00, 0x00,       //cmp         ebx,0FAh
	0x7C, 0xE7,                               //jl          loop_building
	0x5B,                                     //pop         ebx
	0xC6, 0x46, 0x3C, 0x19,                   //mov         byte ptr[esi+3Ch],19h
	0xB0, 0x01,                               //mov         al,1
	0xC3                                      //ret
};

BYTE codeCheckTransportTaskThunk[] = {0xE8, 0x08, 0x8B, 0xBE, 0xFF};//dwAddrCheckTransportTask-4BC1F3h
BYTE codeCheckTransportTaskOldThunk[] = {0xE8, 0x18, 0xB4, 0xFF, 0xFF};//call 4B7610h()
ASM_PATCH patchCheckTransportTaskThunk[] = {
	{0x4BC1F3, sizeof(codeCheckTransportTaskThunk), codeCheckTransportTaskThunk},
	{0x4BC1F3, sizeof(codeCheckTransportTaskOldThunk), codeCheckTransportTaskOldThunk}};

//set building soldier remains
DWORD dwAddrSetBuildingSoldierRemains = dwAddrStackBottom + 0x5000;
BYTE codeSetBuildingSoldierRemains[] = {
	0x56,                                     //push        esi
	0xB8, 0x00, 0x71, 0x47, 0x00,             //mov         eax,477100h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF8,                               //mov         edi,eax
	0x80, 0x4F, 0x0F, 0x80,                   //or          byte ptr [edi+0Fh],80h
	0x57,                                     //push        edi
	0x8B, 0x8F, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edi+0CCh]
	0xB8, 0x50, 0x36, 0x0A, 0x00,             //mov         eax,get_building_prop
	0xFF, 0xD0,                               //call        eax
	0xA8, 0x12,                               //test        al,12h
	0x75, 0x20,                               //jne         border_building
	0x33, 0xED,                               //xor         ebp,ebp
	0x45,                                     //inc         ebp
	0x80, 0x7F, 0x06, 0x05,                   //cmp         byte ptr [edi+6],5
	0x75, 0x12,                               //jne         got_inside_building_soldier_quota
	0xBD, 0x10, 0x27, 0x00, 0x00,             //mov         ebp,2710h
	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x3C,                         //call        [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x02,                               //je          got_inside_building_soldier_quota
	0xD1, 0xED,                               //shr         ebp,1
	                                          //got_inside_building_soldier_quota:
	0xE9, 0x7B, 0x02, 0x00, 0x00,             //jmp         get_building_soldier_remains
	                                          //border_building:
	0x80, 0x4F, 0x0F, 0x40,                   //or          byte ptr [edi+0Fh],40h
	0x8B, 0x6F, 0x44,                         //mov         ebp,dword ptr [edi+44h]
	0x83, 0xEC, 0x40,                         //sub         esp,40h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0x70, 0xD7, 0x46, 0x00,             //mov         eax,46D770h
	0xFF, 0xD0,                               //call        eax
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x50,                                     //push        eax
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x60, 0xB0, 0x43, 0x00,             //mov         eax,43B060h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0x55,                                     //push        ebp
	0xB8, 0x20, 0xEF, 0x46, 0x00,             //mov         eax,46EF20h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xB8, 0x70, 0xC9, 0x46, 0x00,             //mov         eax,46C970h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x6C, 0x24, 0x04,                   //mov         ebp,dword ptr [esp+4]
	0x56,                                     //push        esi
	0x33, 0xF6,                               //xor         esi,esi
	                                          //loop_near_city:
	0x8B, 0x45, 0x08,                         //mov         eax,dword ptr [ebp+8]
	0xFF, 0xB0, 0xCC, 0x00, 0x00, 0x00,       //push        dword ptr [eax+0CCh]
	0x8B, 0x8F, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx, [edi+0CCh]
	0xB8, 0x10, 0x18, 0x44, 0x00,             //mov         eax,441810h
	0xFF, 0xD0,                               //call        eax
	0x03, 0xF0,                               //add         esi,eax
	0x8D, 0x44, 0x24, 0x24,                   //lea         eax,[esp+24h]
	0x6A, 0x01,                               //push        1
	0x6A, 0x00,                               //push        0
	0x50,                                     //push        eax
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xB8, 0x20, 0xA8, 0x43, 0x00,             //mov         eax,43A820h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xCE,                               //jne         loop_near_city
	0x45,                                     //inc         ebp
	0x85, 0xF6,                               //test        esi,esi
	0x5E,                                     //pop         esi
	0x0F, 0x84, 0xCD, 0x01, 0x00, 0x00,       //je          border_building_release_resource
	0x66, 0xBD, 0x88, 0x13,                   //mov         bp,1388h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x06,                               //jg          got_border_building_soldier_quota
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x02,                               //je          got_border_building_soldier_quota
	0xD1, 0xE5,                               //shl         ebp,1
	                                          //got_border_building_soldier_quota:
	0x56,                                     //push        esi
	0x8B, 0x74, 0x24, 0x28,                   //mov         esi,dword ptr [esp+28h]
	0x83, 0xEC, 0x60,                         //sub         esp,60h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,             //mov         eax,4734B0h
	0xFF, 0xD0,                               //call        eax
	                                          //loop_near_building:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x3B, 0xCF,                               //cmp         ecx,edi
	0x74, 0x46,                               //je          skip_next_near_building
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax, [ecx+0CCh]
	0x50,                                     //push        eax
	0x8B, 0x8F, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edi+0CCh]
	0xB8, 0x00, 0x4F, 0x0A, 0x00,             //mov         eax,get_force_danger_coef
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x2E,                               //je          skip_next_near_building
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x17,                               //jne         test_null_force
	0xF6, 0x47, 0x0F, 0x30,                   //test        byte ptr [edi+0Fh],30h
	0x75, 0x24,                               //jne         skip_next_near_building
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x81, 0xB9, 0x88, 0x00, 0x00, 0x00, 0x88, 0x13, 0x00, 0x00,//cmp dword ptr [ecx+88h],1388h
	0x7D, 0x1A,                               //jge         create_map_block_list
	0xEB, 0x13,                               //jmp         skip_next_near_building
	                                          //test_null_force:
	0x3C, 0x04,                               //cmp         al,4
	0x75, 0x14,                               //jne         create_map_block_list
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x80, 0x79, 0x06, 0x05,                   //cmp         byte ptr[ecx+6],5
	0x75, 0x06,                               //jne         skip_next_near_building
	0xF6, 0x47, 0x0F, 0x36,                   //test        byte ptr [edi+0Fh],36h
	0x74, 0x05,                               //je          create_map_block_list
	                                          //skip_next_near_building:
	0xE9, 0x3C, 0x01, 0x00, 0x00,             //jmp         next_near_building
	                                          //create_map_block_list:
	0x50,                                     //push        eax
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x6A, 0x00,                               //push        0
	0x8D, 0x58, 0x00,                         //lea         ebx,[eax+0]
	0x8D, 0x4C, 0x24, 0x30,                   //lea         ecx,[esp+30h]
	0x8B, 0x46, 0x08,                         //mov         eax,dword ptr [esi+8]
	0xFF, 0xB0, 0xD0, 0x00, 0x00, 0x00,       //push        dword ptr [eax+0D0h]
	0x57,                                     //push        edi
	0xB8, 0x30, 0xA3, 0x47, 0x00,             //mov         eax,47A330h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x30,                   //lea         ecx,[esp+30h]
	0x8D, 0x44, 0x24, 0x10,                   //lea         eax,[esp+10h]
	0x50,                                     //push        eax
	0xB8, 0x90, 0x82, 0x47, 0x00,             //mov         eax,478290h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x6C, 0x24, 0x14,                   //mov         ebp,dword ptr [esp+14h]
	                                          //loop_map_block_list:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xB8, 0x70, 0xD0, 0x45, 0x00,             //mov         eax,45D070h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0A,                               //je          skip_next_map_block
	0x3B, 0x04, 0x24,                         //cmp         eax,dword ptr [esp]
	0x74, 0x05,                               //je          skip_next_map_block
	0x89, 0x04, 0x24,                         //mov         dword ptr [esp],eax
	0x3B, 0xC7,                               //cmp         eax,edi
	                                          //skip_next_map_block:
	0x74, 0x7E,                               //je          next_map_block
	0x3B, 0x46, 0x08,                         //cmp         eax,dword ptr [esi+8]
	0x74, 0x32,                               //je          skip_end_loop_map_block_list
	0xF6, 0x40, 0x3D, 0x80,                   //test        byte ptr [eax+3Dh],80h
	0x75, 0x73,                               //jne         next_map_block
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0x40, 0x54, 0x43, 0x00,             //mov         eax,435440h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x03,                               //je          test_through_building_force
	0x4B,                                     //dec         ebx
	0xEB, 0x5F,                               //jmp         check_danger_coef
	                                          //test_through_building_force:
	0x8B, 0x0C, 0x24,                         //mov         ecx,dword ptr [esp]
	0xFF, 0xB1, 0xCC, 0x00, 0x00, 0x00,       //push        dword ptr [ecx+0CCh]
	0x8B, 0x8F, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edi+0CCh]
	0xB8, 0x10, 0x18, 0x44, 0x00,             //mov         eax,441810h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          test_map_block_num
	0x33, 0xDB,                               //xor         ebx,ebx
	                                          //skip_end_loop_map_block_list:
	0xEB, 0x50,                               //jmp         end_loop_map_block_list
	                                          //test_map_block_num:
	0x8A, 0x44, 0x24, 0x0C,                   //mov         al,[esp+0Ch]
	0x3C, 0x04,                               //cmp         al,4
	0x74, 0x3D,                               //je          next_map_block
	0x3C, 0x05,                               //cmp         al,5
	0x74, 0x39,                               //je          next_map_block
	0x83, 0x7C, 0x24, 0x1C, 0x18,             //cmp         dword ptr [esp+1Ch],18h
	0x7C, 0x3D,                               //jl          end_loop_map_block_list
	0x4B,                                     //dec         ebx
	0x8B, 0x0C, 0x24,                         //mov         ecx,dword ptr [esp]
	0x81, 0xB9, 0x88, 0x00, 0x00, 0x00, 0x40, 0x1F, 0x00, 0x00,//cmp dword ptr [ecx+88h],1F40h
	0x7C, 0x1E,                               //jl          check_danger_coef
	0x8B, 0x46, 0x08,                         //mov         eax,dword ptr [esi+8]
	0xFF, 0xB0, 0xCC, 0x00, 0x00, 0x00,       //push        dword ptr [eax+0CCh]
	0xFF, 0xB1, 0xCC, 0x00, 0x00, 0x00,       //push        dword ptr [ecx+0CCh]
	0xB8, 0x70, 0x06, 0x4B, 0x00,             //mov         eax,4B0670h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x01,                               //je          check_danger_coef
	0x4B,                                     //dec         ebx
	                                          //check_danger_coef:
	0x85, 0xDB,                               //test        ebx,ebx
	0x7E, 0x0B,                               //jle         end_loop_map_block_list
	                                          //next_map_block:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x0F, 0x85, 0x5D, 0xFF, 0xFF, 0xFF,       //jne         loop_map_block_list
	                                          //end_loop_map_block_list:
	0x8D, 0x4C, 0x24, 0x30,                   //lea         ecx,[esp+30h]
	0xB8, 0x10, 0x9F, 0x47, 0x00,             //mov         eax,479F10h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xC3,                               //mov         eax,ebx
	0x5A,                                     //pop         edx
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x53,                               //jle         next_near_building
	0x80, 0xF9, 0x04,                         //cmp         cl,4
	0x75, 0x06,                               //jne         test_baram_force
	0x80, 0x4F, 0x0F, 0x04,                   //or          byte ptr [edi+0Fh],4
	0xEB, 0x48,                               //jmp         next_near_building
	                                          //test_baram_force:
	0x80, 0xF9, 0x05,                         //cmp         cl,5
	0x75, 0x06,                               //jne         test_npc_danger_force
	0x80, 0x4F, 0x0F, 0x02,                   //or          byte ptr [edi+0Fh],2
	0xEB, 0x3D,                               //jmp         next_near_building
	                                          //test_npc_danger_force:
	0x80, 0xF9, 0x02,                         //cmp         cl,2
	0x74, 0x34,                               //je          set_npc_danger_force
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x30,                               //je          set_npc_danger_force
	0x80, 0x4F, 0x0F, 0x20,                   //or          byte ptr [edi+0Fh],20h
	0x8B, 0x44, 0x24, 0x0C,                   //mov         eax,dword ptr [esp+0Ch]
	0x66, 0x3D, 0x14, 0x00,                   //cmp         ax,14h
	0x7D, 0x04,                               //jge         add_border_building_soldier_quota
	0x66, 0xB8, 0x14, 0x00,                   //mov         ax,14h
	                                          //add_border_building_soldier_quota:
	0x83, 0xE8, 0x5A,                         //sub         eax,5Ah
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x19,                               //jle         next_near_building
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0xF7, 0xA9, 0x88, 0x00, 0x00, 0x00,       //imul        dword ptr [ecx+88h]
	0x99,                                     //cdq
	0xB9, 0x3C, 0x00, 0x00, 0x00,             //mov         ecx,3Ch
	0xF7, 0xF1,                               //div         eax,ecx
	0x03, 0xE8,                               //add         ebp,eax
	0xEB, 0x04,                               //jmp         next_near_building
	                                          //set_npc_danger_force:
	0x80, 0x4F, 0x0F, 0x10,                   //or          byte ptr [edi+0Fh],10h
	                                          //next_near_building:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x0F, 0x85, 0x68, 0xFE, 0xFF, 0xFF,       //jne         loop_near_building
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x60,                         //add         esp,60h
	0x5E,                                     //pop         esi
	                                          //border_building_release_resource:
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x40,                         //add         esp,40h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xC0, 0x61, 0x43, 0x00,             //mov         eax,4361C0h
	0xFF, 0xD0,                               //call        eax
	0x6B, 0xC0, 0x0F,                         //imul        eax,eax,0Fh
	0xC1, 0xE8, 0x04,                         //shr         eax,4
	0x3B, 0xE8,                               //cmp         ebp,eax
	0x7E, 0x02,                               //jle         check_border_building_soldier_max
	0x8B, 0xE8,                               //mov         ebp,eax
	                                          //check_border_building_soldier_max:
	0x39, 0x04, 0xB3,                         //cmp         dword ptr [ebx+esi*4],eax
	0x7E, 0x04,                               //jle         get_building_soldier_remains
	0x80, 0x4F, 0x0F, 0x08,                   //or          byte ptr [edi+0Fh],8
	                                          //get_building_soldier_remains:
	0x8B, 0x04, 0xB3,                         //mov         eax,dword ptr [ebx+esi*4]
	0x2B, 0xC5,                               //sub         eax,ebp
	0xF6, 0x47, 0x0F, 0x08,                   //test        byte ptr [edi+0Fh],8
	0x75, 0x5D,                               //jne         clear_border_danger_force_building_soldier_remains
	0xF6, 0x47, 0x0F, 0x20,                   //test        byte ptr [edi+0Fh],20h
	0x74, 0x12,                               //je          test_border_npc_danger_force
	0xBA, 0x78, 0xEC, 0xFF, 0xFF,             //mov         edx,0FFFFEC78h
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7C, 0x02,                               //jl          get_border_player_building_soldier_remains
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //get_border_player_building_soldier_remains:
	0x2D, 0xFF, 0x03, 0x00, 0x00,             //sub         eax,3FFh
	0xEB, 0x4D,                               //jmp         got_border_building_soldier_remains
	                                          //test_border_npc_danger_force:
	0xF6, 0x47, 0x0F, 0x10,                   //test        byte ptr [edi+0Fh],10h
	0x74, 0x17,                               //je          test_border_baram_city
	                                          //get_border_building_random_soldier_remains:
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0xF7, 0x6F, 0x04,                         //imul        dword ptr [edi+4]
	0x25, 0xFF, 0x03, 0x00, 0x00,             //and         eax,3FFh
	0x05, 0x88, 0x13, 0x00, 0x00,             //add         eax,1388h
	0xF7, 0xD8,                               //neg         eax
	0xEB, 0x30,                               //jmp         got_border_building_soldier_remains
	                                          //test_border_baram_city:
	0xF6, 0x47, 0x0F, 0x02,                   //test        byte ptr [edi+0Fh],2
	0x74, 0x11,                               //je          test_border_null_city
	0x03, 0xC5,                               //add         eax,ebp
	0xBD, 0x50, 0xC3, 0x00, 0x00,             //mov         ebp,0C350h
	0x2B, 0xC5,                               //sub         eax,ebp
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         skip_test_building_soldier_remains2
	0x33, 0xC0,                               //xor         eax,eax
	                                          //skip_test_building_soldier_remains2:
	0xEB, 0x0F,                               //jmp         skip_test_building_soldier_remains
	                                          //test_border_null_city:
	0xF6, 0x47, 0x0F, 0x04,                   //test        byte ptr [edi+0Fh],4
	0x74, 0x09,                               //je          skip_test_building_soldier_remains
	0x03, 0xC5,                               //add         eax,ebp
	0xBD, 0x20, 0x4E, 0x00, 0x00,             //mov         ebp,4E20h
	0x2B, 0xC5,                               //sub         eax,ebp
	                                          //skip_test_building_soldier_remains:
	0xEB, 0x0A,                               //jmp         test_building_soldier_remains
	                                          //clear_border_danger_force_building_soldier_remains:
	0xF6, 0x47, 0x0F, 0x30,                   //test        byte ptr [edi+0Fh],30h
	0x74, 0x04,                               //je          test_building_soldier_remains
	0x33, 0xC0,                               //xor         eax,eax
	                                          //got_border_building_soldier_remains:
	0xEB, 0x12,                               //jmp         save_building_soldier_remains
	                                          //test_building_soldier_remains:
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x0E,                               //jle         save_building_soldier_remains
	0x8B, 0x87, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edi+88h]
	0x2B, 0xC5,                               //sub         eax,ebp
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         save_building_soldier_remains
	0x33, 0xC0,                               //xor         eax,eax
	                                          //save_building_soldier_remains:
	0x89, 0x04, 0xB3,                         //mov         dword ptr [ebx+esi*4],eax
	0x58,                                     //pop         eax
	0x04, 0x03,                               //add         al,3
	0x50,                                     //push        eax
	0xC3,                                     //ret
};

BYTE codeSetBuildingSoldierRemainsThunk[] = {0xE8, 0x2D, 0x8F, 0xBE, 0xFF};//dwAddrSetBuildingSoldierRemains-4BC0CEh
BYTE codeSetBuildingSoldierRemainsOldThunk[] = {0xE8, 0x7D, 0x19, 0x04, 0x00};//call 4FDA50h()
ASM_PATCH patchSetBuildingSoldierRemainsThunk[] = {
	{0x4BC0CE, sizeof(codeSetBuildingSoldierRemainsThunk), codeSetBuildingSoldierRemainsThunk},
	{0x4BC0CE, sizeof(codeSetBuildingSoldierRemainsOldThunk), codeSetBuildingSoldierRemainsOldThunk}};

//get building prop
DWORD dwAddrGetBuildingProp = dwAddrStackBottom + 0x3650;
BYTE codeGetBuildingProp[] = {
	                                          //get_building_prop:
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0B8h]
	0x0F, 0xB6, 0x41, 0x04,                   //movzx       eax,byte ptr [ecx+4]
	0x69, 0xC0, 0xEC, 0x03, 0x00, 0x00,       //imul        eax,eax,3ECh
	0x03, 0x05, 0x68, 0x55, 0x54, 0x01,       //add         eax,[1545568h]
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x50,                                     //push        eax
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x40,                                     //inc         eax
	0x59,                                     //pop         ecx
	0x8B, 0x04, 0x81,                         //mov         eax,dword ptr [ecx+eax*4]
	0xC2, 0x04, 0x00                          //ret         4
};

//get force danger coef
DWORD dwAddrGetForceDangerCoef = dwAddrStackBottom + 0x4F00;
BYTE codeGetForceDangerCoef[] = {
	                                          //get_force_danger_coef:
	0x33, 0xC0,                               //xor         eax,eax
	0x8B, 0x54, 0x24, 0x04,                   //mov         edx,dword ptr [esp+4]
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x05,                               //jne         get_goal_main_force
	0xB0, 0x04,                               //mov         al,4
	                                          //end:
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //get_goal_main_force:
	0x8B, 0x92, 0xB8, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [edx+0B8h]
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0B8h]
	0x3B, 0xD1,                               //cmp         edx,ecx
	0x74, 0xED,                               //je          end
	0xF6, 0x42, 0x34, 0x04,                   //test        byte ptr [edx+34h],4
	0x74, 0x04,                               //je          test_player_force
	0xB0, 0x05,                               //mov         al,5
	0xEB, 0xE3,                               //jmp         end
	                                          //test_player_force:
	0xF6, 0x42, 0x34, 0x01,                   //test        byte ptr [edx+34h],1
	0x74, 0x04,                               //je          test_diploma_relation
	0xB0, 0x03,                               //mov         al,3
	0xEB, 0xD9,                               //jmp         end
	                                          //test_diploma_relation:
	0x0F, 0xB6, 0x42, 0x04,                   //movzx       eax,byte ptr [edx+4]
	0x8A, 0x44, 0x01, 0x38,                   //mov         al,byte ptr [ecx+eax+38h]
	0x3C, 0x46,                               //cmp         al,46h
	0x7F, 0x17,                               //jg          no_danger_force
	0xB0, 0x02,                               //mov         al,2
	0xF6, 0x41, 0x34, 0x30,                   //test        byte ptr [ecx+34h],30h
	0x74, 0x11,                               //je          end
	0xF6, 0x42, 0x34, 0x30,                   //test        byte ptr [edx+34h],30h
	0x74, 0x0B,                               //je          end
	0x83, 0x3D, 0x90, 0x24, 0x23, 0x01, 0x07, //cmp         dword ptr[1232490h],7
	0x7E, 0x02,                               //jle         end
	                                          //no_danger_force:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

//init transport building
DWORD dwAddrInitTransportBuilding = dwAddrStackBottom + 0x1EA0;
BYTE codeInitTransportBuilding[] = {
	0x81, 0xFE, 0x78, 0xEC, 0xFF, 0xFF,       //cmp         esi,0FFFFEC78h
	0x7D, 0x13,                               //jge         test_source_building
	0x57,									  //push        edi
	0xB8, 0x10, 0xF2, 0x4A, 0x00,			  //mov         eax,4AF210h
	0xFF, 0xD0,								  //call        eax
	0x5A,									  //pop         edx
	0x85, 0xC0,								  //test        eax,eax
	0x74, 0x42,								  //je          end
	0x8B, 0x4C, 0x24, 0x70,                   //mov         ecx,dword ptr [esp+70h]
	0xEB, 0x34,                               //jmp         add_to_transport_building_list
	                                          //test_source_building:
	0x81, 0xFE, 0x00, 0x17, 0x00, 0x00,       //cmp         esi,1700h
	0x7E, 0x34,                               //jle         end
	0x80, 0x7F, 0x7C, 0x01,                   //cmp         byte ptr [edi+7Ch],1
	0x75, 0x2E,                               //jne         end
	0xF6, 0x47, 0x7A, 0x40,                   //test        byte ptr [edi+7Ah],40h
	0x75, 0x28,                               //jne         end
	0x8B, 0x87, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,[edi+0CCh]
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr[eax+34h],1
	0x75, 0x1C,                               //jne         end
	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x0C,                         //call        [eax+0Ch]
	0x80, 0xB8, 0x00, 0x0D, 0x0A, 0x00, 0x08, //cmp         byte ptr[eax+building_attacked_coef],8
	0x7D, 0x0C,                               //jge         end
	0x8B, 0x4C, 0x24, 0x6C,                   //mov         ecx,dword ptr [esp+6Ch]
	                                          //add_to_transport_building_list:
	0x57,                                     //push        edi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeInitTransportBuildingThunk[] = {0xE8, 0x58, 0x62, 0xBE, 0xFF, 0x33, 0xC0, 0x90};
//dwAddrInitTransportBuilding-4BBC43h,xor eax,eax,nop
BYTE codeInitTransportBuildingOldThunk[] = {0xC7, 0x44, 0x24, 0x14, 0x01, 0x00, 0x00, 0x00};//mov dword ptr[esp+14h],1
ASM_PATCH patchInitTransportBuildingThunk[] = {
	{0x4BBC43, sizeof(codeInitTransportBuildingThunk), codeInitTransportBuildingThunk},
	{0x4BBC43, sizeof(codeInitTransportBuildingOldThunk), codeInitTransportBuildingOldThunk}};

//select transport source
DWORD dwAddrSelectTransportSource = dwAddrStackBottom + 0x4F60;
BYTE codeSelectTransportSource[] = {
	0x53,                                     //push        ebx
	0x8D, 0x8F, 0x58, 0x08, 0x00, 0x00,       //lea         ecx,[edi+858h]
	0xB8, 0x60, 0xB9, 0x4B, 0x00,             //mov         eax,4BB960h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0x46, 0xE4,                         //mov         eax,dword ptr [esi-1Ch]
	0x8B, 0x48, 0x08,                         //mov         ecx,dword ptr [eax+8]
	0x81, 0x79, 0x08, 0x78, 0xE8, 0xFF, 0xFF, //cmp         dword ptr [ecx+8],0FFFFE878h
	0x7E, 0x01,                               //jle         select_transport_source_building
	0x47,                                     //inc         edi
	                                          //select_transport_source_building:
	0x8B, 0x5B, 0x04,                         //mov         ebx,dword ptr [ebx+4]
	                                          //loop_source_building:
	0x8B, 0x4B, 0x08,                         //mov         ecx,dword ptr [ebx+8]
	0x81, 0x79, 0x08, 0x00, 0x17, 0x00, 0x00, //cmp         dword ptr [ecx+8],1700h
	0x7E, 0x1D,                               //jle         next_source_building
	0x83, 0xB9, 0xE8, 0x00, 0x00, 0x00, 0x00, //cmp         dword ptr [ecx+0E8h],0
	0x7E, 0x14,                               //jle         next_source_building
	0x85, 0xFF,                               //test        edi,edi
	0x74, 0x06,                               //je          add_source_building
	0xF6, 0x41, 0x0F, 0x04,                   //test        byte ptr [ecx+0Fh],4
	0x75, 0x0A,                               //jne         next_source_building
	                                          //add_source_building:
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_source_building:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0xD1,                               //jne         loop_source_building
	0x58,                                     //pop         eax
	0x04, 0x39,                               //add         al,39h
	0x50,                                     //push        eax
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeSelectTransportSourceThunk[] = {0xE8, 0x26, 0x91, 0xBE, 0xFF};//dwAddrSelectTransportSource-4BBE35h
BYTE codeSelectTransportSourceOldThunk[] = {0xE8, 0x76, 0x46, 0xFF, 0xFF};//call 4B04B0h()
ASM_PATCH patchSelectTransportSourceThunk[] = {
	{0x4BBE35, sizeof(codeSelectTransportSourceThunk), codeSelectTransportSourceThunk},
	{0x4BBE35, sizeof(codeSelectTransportSourceOldThunk), codeSelectTransportSourceOldThunk}};

//sort transport source
DWORD dwAddrSortTransportSource = dwAddrStackBottom + 0x4FC0;
BYTE codeSortTransportSource[] = {
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,dword ptr [esp+4]
	0x8B, 0x08,                               //mov         ecx,dword ptr [eax]
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0xF6, 0x41, 0x0F, 0x40,                   //test        byte ptr [ecx+0Fh],40h
	0x75, 0x06,                               //jne         test_border_null_city
	0x05, 0x40, 0x42, 0x0F, 0x00,             //add         eax,0F4240h
	0xC3,                                     //ret
	                                          //test_border_null_city:
	0xF6, 0x41, 0x0F, 0x04,                   //test        byte ptr [ecx+0Fh],4
	0x75, 0x05,                               //jne         end
	0x05, 0x20, 0xA1, 0x07, 0x00,             //add         eax,7A120h
	                                          //end:
	0xC3                                      //ret
};

BYTE codeSortTransportSourceThunk[] = {0xC0, 0x4F, 0x0A, 0x00};//dwAddrSortTransportSource
BYTE codeSortTransportSourceOldThunk[] = {0x20, 0xB9, 0x4B, 0x00};//4BB920h
ASM_PATCH patchSortTransportSourceThunk[] = {
	{0x4BBEA4, sizeof(codeSortTransportSourceThunk), codeSortTransportSourceThunk},
	{0x4BBEA4, sizeof(codeSortTransportSourceOldThunk), codeSortTransportSourceOldThunk}};

//transport match
BYTE codeTransportMatchThunk[] = {
	0x8B, 0x7E, 0x08,                         //mov         edi,dword ptr [esi+8]
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0xA0, 0xC9, 0xF4, 0x43, 0x00,             //mov         al,[transport_match_step]
	0xA8, 0x01,                               //test        al,1
	0x75, 0x14,                               //jne         test_goal_soldier_remains
	0x8D, 0x4C, 0x24, 0x54,                   //lea         ecx,[esp+54h]
	0x50,                                     //push        eax
	0xFF, 0x77, 0x44,                         //push        dword ptr [edi+44h]
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x74, 0x25,                               //je          next_goal_building
	                                          //test_goal_soldier_remains:
	0x33, 0xC9,                               //xor         ecx,ecx
	0x81, 0x7F, 0x08, 0x78, 0xE8, 0xFF, 0xFF, //cmp         dword ptr [edi+8],0FFFFE878h
	0x0F, 0x9E, 0xC1,                         //setle       cl
	0xD0, 0xE8,                               //shr         al,1
	0x32, 0xC1,                               //xor         al,cl
	0xA8, 0x01,                               //test        al,1
	0x74, 0x11,                               //je          next_goal_building
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0xB8, 0xA0, 0xB7, 0x4B, 0x00,             //mov         eax,4BB7A0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x0F, 0x84, 0x9C, 0x00, 0x00, 0x00,       //je          match_fail
	                                          //next_goal_building:
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xB5,                               //jne         loop_goal_building
	0xA0, 0xC9, 0xF4, 0x43, 0x00,             //mov         al,[transport_match_step]
	0x40,                                     //inc         eax
	0xA2, 0xC9, 0xF4, 0x43, 0x00,             //mov         [transport_match_step],al
	0x3C, 0x04,                               //cmp         al,4
	0x7D, 0x52,                               //jge         match_fail
	0x8B, 0xB5, 0x3C, 0x08, 0x00, 0x00,       //mov         esi,dword ptr [ebp+83Ch]
	0xEB, 0x9E                                //jmp         loop_goal_building
};
BYTE codeTransportMatchOldThunk[sizeof(codeTransportMatchThunk)];

ASM_PATCH patchTransportMatchThunk[] = {
	{0x4BC3B6, sizeof(codeTransportMatchThunk), codeTransportMatchThunk},
	{0x4BC3B6, sizeof(codeTransportMatchOldThunk), codeTransportMatchOldThunk}};

//get person friendship
DWORD dwAddrGetPersonFriendship = 0x4FF790;
BYTE codeGetPersonFriendship[] = {
	0x33, 0xF6,                               //xor         esi,esi
	0xB9, 0x40, 0x07, 0x61, 0x00,             //mov         ecx,610740h
	0x66, 0x8B, 0x47, 0x04,                   //mov         ax,word ptr [edi+4]
	0x66, 0x8B, 0x53, 0x04,                   //mov         dx,word ptr [ebx+4]
	                                          //loop_person_match:
	0x66, 0x3B, 0x01,                         //cmp         ax,word ptr [ecx]
	0x75, 0x06,                               //jne         check_person2
	0x66, 0x3B, 0x51, 0x02,                   //cmp         dx,word ptr [ecx+2]
	0x74, 0x16,                               //je          person_match_ok
	                                          //check_person2:
	0x66, 0x3B, 0x11,                         //cmp         dx,word ptr [ecx]
	0x75, 0x06,                               //jne         next_person_pair
	0x66, 0x3B, 0x41, 0x02,                   //cmp         ax,word ptr [ecx+2]
	0x74, 0x0B,                               //je          person_match_ok
	                                          //next_person_pair:
	0x83, 0xC1, 0x06,                         //add         ecx,6
	0x46,                                     //inc         esi
	0x83, 0xFE, 0x74,                         //cmp         esi,74h
	0x7C, 0xE1,                               //jl          loop_person_match
	0xEB, 0x13,                               //jmp         next_person_pair+9
	                                          //person_match_ok:
	0x0F, 0xB6, 0x69, 0x04,                   //movzx       ebp,byte ptr [ecx+4]
	0x5E,                                     //pop         esi
	0x5B,                                     //pop         ebx
	0xEB, 0x59                                //jmp         person_match_ok
};

//max building wound
DWORD dwAddrMaxBuildingWound = dwAddrStackBottom + 0x5360;
BYTE codeMaxBuildingWound[] = {
	0xF6, 0x46, 0x20, 0x01,                   //test        byte ptr[esi+20h],1
	0x74, 0x10,                               //je          normal
	0x8B, 0x4E, 0x64,                         //mov         ecx,dword ptr [esi+64h]
	0xB8, 0xC0, 0x61, 0x43, 0x00,             //mov         eax,4361C0h
	0xFF, 0xD0,                               //call        eax
	0xD1, 0xE8,                               //shr         eax,1
	0x89, 0x44, 0x24, 0x0C,                   //mov         dword ptr [esp+0Ch],eax
	                                          //normal:
	0xFF, 0x25, 0x0C, 0xF3, 0x5F, 0x00        //jmp         [5FF30Ch]
};

BYTE codeMaxBuildingWoundThunk[] = {0xE8, 0xBA, 0x75, 0xC4, 0xFF, 0x41};//dwAddrMaxBuildingWound
BYTE codeMaxBuildingWoundOldThunk[] = {0xFF, 0x15, 0x0C, 0xF3, 0x5F, 0x00};//call [5FF30Ch]
ASM_PATCH patchMaxBuildingWoundThunk[] = {
	{0x45DDA1, sizeof(codeMaxBuildingWoundThunk), codeMaxBuildingWoundThunk},
	{0x45DDA1, sizeof(codeMaxBuildingWoundOldThunk), codeMaxBuildingWoundOldThunk}};

//check transport block
DWORD dwAddrCheckTransportBlock = dwAddrStackBottom + 0x5400;
BYTE codeCheckTransportBlock[] = {
	0xB8, 0xA0, 0xC8, 0x45, 0x00,             //mov         eax,45C8A0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x48, 0x48,                         //mov         ecx,dword ptr [eax+48h]
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0x08,                               //jne         test_part_building
	                                          //no_block:
	0x68, 0x86, 0xB8, 0x4B, 0x00,             //push        4BB886h
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_part_building:
	0xF6, 0x40, 0x3D, 0x80,                   //test        byte ptr [eax+3Dh],80h
	0x75, 0xF2,                               //jne         no_block
	0x80, 0x79, 0x04, 0x0A,                   //cmp         byte ptr [ecx+4],0Ah
	0x7D, 0x2D,                               //jge         check_building_range
	0x50,                                     //push        eax
	0x50,                                     //push        eax
	0x8B, 0xCD,                               //mov         ecx,ebp
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x30,                         //call        dword ptr [eax+30h]
	0x50,                                     //push        eax
	0xB8, 0x00, 0x07, 0x4B, 0x00,             //mov         eax,4B0700h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x08,                         //add         esp,8
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x74, 0xD3,                               //je          no_block
	0x8B, 0x88, 0xCC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0CCh]
	0xF6, 0x41, 0x34, 0x01,                   //test        byte ptr [ecx+34h],1
	0x74, 0x08,                               //je          check_building_range
	0x68, 0xDC, 0xB8, 0x4B, 0x00,             //push        4BB8DCh
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //check_building_range:
	0x53,                                     //push        ebx
	0x83, 0xEC, 0x18,                         //sub         esp,18h
	0x8B, 0xD8,                               //mov         ebx,eax
	0x54,                                     //push        esp
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x60, 0xCE, 0x45, 0x00,             //mov         eax,45CE60h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x44, 0x24, 0x08,                   //lea         eax,[esp+8]
	0x50,                                     //push        eax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x40, 0xA9, 0x44, 0x00,             //mov         eax,44A940h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4B, 0x48,                         //mov         ecx,dword ptr [ebx+48h]
	0xB8, 0x01, 0x00, 0x00, 0x00,             //mov         eax,1
	0x80, 0x79, 0x04, 0x0A,                   //cmp         byte ptr [ecx+4],0Ah
	0x7D, 0x02,                               //jge         got_building_range
	0xB0, 0x03,                               //mov         al,3
	                                          //got_building_range:
	0x29, 0x44, 0x24, 0x08,                   //sub         dword ptr[esp+8],eax
	0x29, 0x44, 0x24, 0x0C,                   //sub         dword ptr[esp+0Ch],eax
	0x40,                                     //inc         eax
	0x01, 0x44, 0x24, 0x10,                   //add         dword ptr[esp+10h],eax
	0x01, 0x44, 0x24, 0x14,                   //add         dword ptr[esp+14h],eax
	0x8D, 0x44, 0x24, 0x08,                   //lea         eax,[esp+8]
	0x50,                                     //push        eax
	0xFF, 0x15, 0x6C, 0xF3, 0x5F, 0x00,       //call        [5FF36Ch]
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x5B,                                     //pop         ebx
	0x85, 0xC0,                               //test        eax,eax
	0xB8, 0x86, 0xB8, 0x4B, 0x00,             //mov         eax,4BB886h
	0x74, 0x02,                               //je          got_check_result
	0xB0, 0xDC,                               //mov         al,0DCh
	                                          //got_check_result:
	0x50,                                     //push        eax
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCheckTransportBlockThunk[] = {0xE8, 0xB1, 0x9B, 0xBE, 0xFF};//dwAddrCheckTransportBlock-4BB84Ah
BYTE codeCheckTransportBlockOldThunk[] = {0xE8, 0x51, 0x10, 0xFA, 0xFF};//call 45C8A0h()
ASM_PATCH patchCheckTransportBlockThunk[] = {
	{0x4BB84A, sizeof(codeCheckTransportBlockThunk), codeCheckTransportBlockThunk},
	{0x4BB84A, sizeof(codeCheckTransportBlockOldThunk), codeCheckTransportBlockOldThunk}};

//get tranasport soldier
DWORD dwAddrGetTransportSoldier = dwAddrStackBottom + 0x5CB0;
BYTE codeGetTransportSoldier[] = {
	0x53,                                     //push        ebx
	0xBB, 0x10, 0x27, 0x00, 0x00,             //mov         ebx,2710h
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x0C,                         //call        [eax+0Ch]
	0x8B, 0xB4, 0x87, 0x58, 0x08, 0x00, 0x00, //mov         esi,dword ptr [edi+eax*4+858h]
	0x3B, 0xF3,                               //cmp         esi,ebx
	0x7E, 0x34,                               //jle         end2
	0x8B, 0x8F, 0x48, 0x0C, 0x00, 0x00,       //mov         ecx,dword ptr [edi+0C48h]
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x0C,                         //call        [eax+0Ch]
	0x8B, 0x84, 0x87, 0x58, 0x08, 0x00, 0x00, //mov         eax,dword ptr [edi+eax*4+858h]
	0xF7, 0xD8,                               //neg         eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7F, 0x04,                               //jg          compare_remains_vacancy
	0x8B, 0xC3,                               //mov         eax,ebx
	0xEB, 0x1A,                               //jmp         end
	                                          //compare_remains_vacancy:
	0x3B, 0xC6,                               //cmp         eax,esi
	0x7D, 0x02,                               //jge         get_person_soldier
	0x8B, 0xF0,                               //mov         esi,eax
	                                          //get_person_soldier:
	0x8B, 0x44, 0x24, 0x1C,                   //mov         eax,[esp+1Ch]
	0x8B, 0x48, 0x08,                         //mov         ecx,[eax+8]
	0xB8, 0x00, 0xD7, 0x44, 0x00,             //mov         eax,44D700h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC6,                               //cmp         eax,esi
	0x7E, 0x02,                               //jle         end
	                                          //end2:
	0x8B, 0xC6,                               //mov         eax,esi
	                                          //end:
	0x5B,                                     //pop         ebx
	0xC3                                      //ret
};

BYTE codeGetTransportSoldierThunk[] = {0xE8, 0xBF, 0xA5, 0xBE, 0xFF, 0x41};//dwAddrGetTransportSoldier-4BB6ECh
BYTE codeGetTransportSoldierOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};//call [5FF308h]
ASM_PATCH patchGetTransportSoldierThunk[] = {
	{0x4BB6EC, sizeof(codeGetTransportSoldierThunk), codeGetTransportSoldierThunk},
	{0x4BB6EC, sizeof(codeGetTransportSoldierOldThunk), codeGetTransportSoldierOldThunk}};

//auto save docname
DWORD dwAddrAutoSaveDocname = dwAddrStackBottom + 0x4FE8;
BYTE codeAutoSaveDocname[] = {
	0xC7, 0x46, 0x02, 0x53, 0x61, 0x76, 0x30, //mov         dword ptr [esi+2],30766153h
	0xC6, 0x46, 0x06, 0x33,                   //mov         byte ptr [esi+6],33h
	0x80, 0x46, 0x07, 0x05,                   //add         byte ptr [esi+7],5
	0x68, 0x40, 0x46, 0x45, 0x00,             //push        454640h
	0xC3                                      //ret
};

BYTE codeAutoSaveDocnameThunk[] = {0xE8, 0xD5, 0x9A, 0xC4, 0xFF};//dwAddrAutoSaveDocname-45B50Eh
BYTE codeAutoSaveDocnameOldThunk[] = {0xE8, 0x2D, 0x91, 0xFF, 0xFF};//call 454640h()
ASM_PATCH patchAutoSaveDocnameThunk[] = {
	{0x45B50E, sizeof(codeAutoSaveDocnameThunk), codeAutoSaveDocnameThunk},
	{0x45B50E, sizeof(codeAutoSaveDocnameOldThunk), codeAutoSaveDocnameOldThunk}};

//multi alienate
DWORD dwAddrMultiAlienate = dwAddrStackBottom + 0x53B0;
BYTE codeMultiAlienate[] = {
	0x8B, 0xCA,                               //mov         ecx,edx
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x03,                               //je          normal
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //normal:
	0x8B, 0xCF,                               //mov         ecx,edi
	0x68, 0x50, 0xEE, 0x46, 0x00,             //push        46EE50h
	0xC3                                      //ret
};

BYTE codeMultiAlienateThunk[] = {0xE8, 0xB9, 0x40, 0xBF, 0xFF};//dwAddrMultiAlienate-4B12F2h
BYTE codeMultiAlienateOldThunk[] = {0xE8, 0x59, 0xDB, 0xFB, 0xFF};//call 46EE50h()
ASM_PATCH patchMultiAlienateThunk[] = {
	{0x4B12F2, sizeof(codeMultiAlienateThunk), codeMultiAlienateThunk},
	{0x4B12F2, sizeof(codeMultiAlienateOldThunk), codeMultiAlienateOldThunk}};

//try invite captive
DWORD dwAddrTryInviteCaptive = dwAddrStackBottom + 0x5500;
BYTE codeTryInviteCaptive[] = {
	0x51,                                     //push        ecx
	0x55,                                     //push        ebp
	0x8B, 0x6F, 0x04,                         //mov         ebp,dword ptr [edi+4]
	                                          //loop_invite_captive:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0x80, 0xB9, 0x84, 0x00, 0x00, 0x00, 0x04, //cmp         byte ptr [ecx+84h],4
	0x75, 0x48,                               //jne         next_invite_captive
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x3F,                               //je          next_invite_captive
	0x8B, 0x45, 0x08,                         //mov         eax,dword ptr [ebp+8]
	0xB9, 0xB2, 0xEF, 0x46, 0x00,             //mov         ecx,46EFB2h
	0xFF, 0xD1,                               //call        ecx
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x31,                               //je          next_invite_captive
	0x8B, 0x4E, 0x38,                         //mov         ecx,[esi+38h]
	0xB8, 0xE0, 0xFD, 0x43, 0x00,             //mov         eax,43FDE0h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0x8B, 0x4D, 0x08,                         //mov         ecx,[ebp+8]
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x3C, 0x14,                               //cmp         al,14h
	0x7D, 0x18,                               //jge         next_invite_captive
	0x8B, 0x45, 0x08,                         //mov         eax,dword ptr [ebp+8]
	0x5D,                                     //pop         ebp
	0x59,                                     //pop         ecx
	0x89, 0x44, 0x24, 0x1C,                   //mov         dword ptr [esp+1Ch],eax
	0x8B, 0x4B, 0x04,                         //mov         ecx,dword ptr [ebx+4]
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x89, 0x44, 0x24, 0x18,                   //mov         dword ptr [esp+18h],eax
	0x83, 0x04, 0x24, 0x14,                   //add         dword ptr [esp],14h
	0xC3,                                     //ret
	                                          //next_invite_captive:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xA5,                               //jne         loop_invite_captive
	0x5D,                                     //pop         ebp
	0x59,                                     //pop         ecx
	0x68, 0xE0, 0x6F, 0x4B, 0x00,             //push        4B6FE0h
	0xC3                                      //ret
};

BYTE codeTryInviteCaptiveThunk[] = {0xE8, 0x45, 0xE0, 0xBE, 0xFF};//dwAddrTryInviteCaptive-4B74B6h
BYTE codeTryInviteCaptiveOldThunk[] = {0xE8, 0x25, 0xFB, 0xFF, 0xFF};//call 4B6FE0h()
ASM_PATCH patchTryInviteCaptiveThunk[] = {
	{0x4B74B6, sizeof(codeTryInviteCaptiveThunk), codeTryInviteCaptiveThunk},
	{0x4B74B6, sizeof(codeTryInviteCaptiveOldThunk), codeTryInviteCaptiveOldThunk}};

//person experience
DWORD dwAddrPersonExperience = dwAddrStackBottom + 0x2190;
BYTE codePersonExperience[] = {
	0x99,                                     //cdq
	0xB9, 0xFA, 0x00, 0x00, 0x00,             //mov         ecx,0FAh
	0xF7, 0xF1,                               //div         eax,ecx
	0x83, 0xE8, 0x04,                         //sub         eax,4
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x04,                               //jg          test_max_prof_coef
	0x33, 0xC0,                               //xor         eax,eax
	0xB0, 0x01,                               //mov         al,1
	                                          //test_max_prof_coef:
	0x3C, 0x04,                               //cmp         al,4
	0x7E, 0x02,                               //jle         get_added_prof
	0xB0, 0x04,                               //mov         al,4
	                                          //get_added_prof:
	0x0F, 0xAF, 0x44, 0x24, 0x08,             //imul        eax,dword ptr [esp+8]
	0x99,                                     //cdq
	0xB1, 0x03,                               //mov         cl,3
	0xF7, 0xF1,                               //div         eax,ecx
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x83, 0xFF, 0x04,                         //cmp         edi,4
	0x7F, 0x29,                               //jg          normal
	0x0F, 0xB7, 0x46, 0x04,                   //movzx       eax,word ptr [esi+4]
	0x3D, 0x20, 0x03, 0x00, 0x00,             //cmp         eax,320h
	0x7D, 0x1E,                               //jge         normal
	0x8B, 0x04, 0x85, 0x00, 0x40, 0x0A, 0x00, //mov         eax,dword ptr [eax*4+person_config_info]
	0x8B, 0xCF,                               //mov         ecx,edi
	0xD1, 0xE1,                               //shl         ecx,1
	0xD3, 0xE8,                               //shr         eax,cl
	0x24, 0x03,                               //and         al,3
	0x3C, 0x03,                               //cmp         al,3
	0x75, 0x0B,                               //jne         normal
	0x66, 0xA1, 0xDE, 0xFF, 0x43, 0x00,       //mov         ax,[max_experience]
	0x66, 0x89, 0x44, 0x24, 0x0C,             //mov         [esp+0Ch],ax
	                                          //normal:
	0xFF, 0x25, 0x0C, 0xF3, 0x5F, 0x00        //jmp         [5FF30Ch]
};

BYTE codePersonExperienceThunk[] = {0xE8, 0xE8, 0x57, 0xC5, 0xFF, 0x41};//dwAddrPersonExperience-44C9A3h
BYTE codePersonExperienceOldThunk[] = {0xFF, 0x15, 0x0C, 0xF3, 0x5F, 0x00};//call [5FF30Ch]
ASM_PATCH patchPersonExperienceThunk[] = {
	{0x44C9A3, sizeof(codePersonExperienceThunk), codePersonExperienceThunk},
	{0x44C9A3, sizeof(codePersonExperienceOldThunk), codePersonExperienceOldThunk}};

//get officer type
DWORD dwAddrGetOfficerType = dwAddrStackBottom + 0x55C0;
BYTE codeGetOfficerType[] = {
	                                          //get_officer_type:
	0x0F, 0xB6, 0x41, 0x04,                   //movzx       eax,byte ptr [ecx+4]
	0x83, 0xE8, 0x04,                         //sub         eax,4
	0x85, 0xC0,                               //test        eax,eax
	0x7C, 0x12,                               //jl          max_officer_type
	0xC1, 0xE8, 0x02,                         //shr         eax,2
	0x83, 0xF8, 0x10,                         //cmp         eax,10h
	0x7D, 0x07,                               //jge         command_officer_type
	0xA8, 0x01,                               //test        al,1
	0x74, 0x03,                               //je          command_officer_type
	0xB0, 0x02,                               //mov         al,2
	0xC3,                                     //ret
	                                          //command_officer_type:
	0xB0, 0x01,                               //mov         al,1
	0xC3,                                     //ret
	                                          //max_officer_type:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3                                      //ret
};

//command officer para
DWORD dwAddrCommandOfficerPara = dwAddrStackBottom + 0x53D0;
BYTE codeCommandOfficerPara[] = {
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,dword ptr [esp+4]
	0x56,                                     //push        esi
	0x8B, 0x30,                               //mov         esi,dword ptr [eax]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xC0, 0x55, 0x0A, 0x00,             //mov         eax,get_officer_type
	0xFF, 0xD0,                               //call        eax
	0x33, 0xD2,                               //xor         edx,edx
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          got_officer_flag
	0x42,                                     //inc         edx
	                                          //got_officer_flag:
	0x89, 0x56, 0x08,                         //mov         dword ptr [esi+8],edx
	0x33, 0xC0,                               //xor         eax,eax
	0x85, 0xD2,                               //test        edx,edx
	0x75, 0x09,                               //jne         got_officer_para
	0x0F, 0xB6, 0x46, 0x04,                   //movzx       eax,byte ptr [esi+4]
	0x83, 0xE8, 0x4D,                         //sub         eax,4Dh
	0xF7, 0xD8,                               //neg         eax
	                                          //got_officer_para:
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeCommandOfficerParaThunk[] = {0xD0, 0x53, 0x0A, 0x00};//dwAddrCommandOfficerPara
BYTE codeCommandOfficerParaOldThunk[] = {0xD0, 0x29, 0x4B, 0x00};//4B29D0h()
ASM_PATCH patchCommandOfficerParaThunk[] = {
	{0x4B2CCD, sizeof(codeCommandOfficerParaThunk), codeCommandOfficerParaThunk},
	{0x4B2CCD, sizeof(codeCommandOfficerParaOldThunk), codeCommandOfficerParaOldThunk}};

//delete max officer
DWORD dwAddrDeleteMaxOfficer = dwAddrStackBottom + 0x55E0;
BYTE codeDeleteMaxOfficer[] = {
	0x51,                                     //push        ecx
	0x8D, 0x4B, 0x64,                         //lea         ecx,[ebx+64h]
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x68, 0x70, 0xEF, 0x46, 0x00,             //push        46EF70h
	0xC3                                      //ret
};

BYTE codeDeleteMaxOfficerThunk[] = {0xE8, 0x3B, 0x29, 0xBF, 0xFF};//dwAddrDeleteMaxOfficer-4B2CA0h
BYTE codeDeleteMaxOfficerOldThunk[] = {0xE8, 0xCB, 0xC2, 0xFB, 0xFF};//46EF70h()
ASM_PATCH patchDeleteMaxOfficerThunk[] = {
	{0x4B2CA0, sizeof(codeDeleteMaxOfficerThunk), codeDeleteMaxOfficerThunk},
	{0x4B2CA0, sizeof(codeDeleteMaxOfficerOldThunk), codeDeleteMaxOfficerOldThunk}};

//intelligence officer para
DWORD dwAddrIntelligenceOfficerPara = dwAddrStackBottom + 0x5600;
BYTE codeIntelligenceOfficerPara[] = {
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,dword ptr [esp+4]
	0x56,                                     //push        esi
	0x8B, 0x30,                               //mov         esi,dword ptr [eax]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xC0, 0x55, 0x0A, 0x00,             //mov         eax,get_officer_type
	0xFF, 0xD0,                               //call        eax
	0xBA, 0x10, 0x27, 0x00, 0x00,             //mov         edx,2710h
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x01,                               //je          got_officer_flag
	0x42,                                     //inc         edx
	                                          //got_officer_flag:
	0x89, 0x56, 0x08,                         //mov         dword ptr [esi+8],edx
	0x33, 0xC0,                               //xor         eax,eax
	0xF6, 0xC2, 0x01,                         //test        dl,1
	0x75, 0x09,                               //jne         got_officer_para
	0x0F, 0xB6, 0x46, 0x04,                   //movzx       eax,byte ptr [esi+4]
	0x83, 0xE8, 0x4D,                         //sub         eax,4Dh
	0xF7, 0xD8,                               //neg         eax
	                                          //got_officer_para:
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeIntelligenceOfficerParaThunk[] = {0x00, 0x56, 0x0A, 0x00};//dwAddrIntelligenceOfficerPara
BYTE codeIntelligenceOfficerParaOldThunk[] = {0x80, 0x2A, 0x4B, 0x00};//4B2A80h()
ASM_PATCH patchIntelligenceOfficerParaThunk[] = {
	{0x4B2DB1, sizeof(codeIntelligenceOfficerParaThunk), codeIntelligenceOfficerParaThunk},
	{0x4B2DB1, sizeof(codeIntelligenceOfficerParaOldThunk), codeIntelligenceOfficerParaOldThunk}};

//building max soldier
DWORD dwAddrBuildingMaxSoldier = dwAddrStackBottom + 0x56A0;
BYTE codeBuildingMaxSoldier[] = {
	0x56,                                     //push        esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353Dh
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0A,                               //je          get_city_max_soldier
	0x3C, 0x02,                               //cmp         al,2
	0xB0, 0x19,                               //mov         al,19h
	0x74, 0x02,                               //je          got_building_max_soldier_num
	0xB0, 0x19,                               //mov         al,19h
	                                          //got_building_max_soldier_num:
	0xEB, 0x0B,                               //jmp         get_max_soldier
	                                          //get_city_max_soldier:
	0x0F, 0xB6, 0x46, 0x04,                   //movzx       eax,byte ptr [esi+4]
	0x0F, 0xB6, 0x80, 0x62, 0x56, 0x0A, 0x00, //movzx       eax,byte ptr [eax+city_max_soldier]
	                                          //get_max_soldier:
	0x69, 0xC0, 0x10, 0x27, 0x00, 0x00,       //imul        eax,eax,2710h
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

BYTE codeBuildingMaxSoldierThunk[] = {0xE9, 0xDB, 0xF4, 0xC6, 0xFF};//dwAddrBuildingMaxSoldier - 4361C0h
BYTE codeBuildingMaxSoldierOldThunk[] = {0xE8, 0x0B, 0xF2, 0xFF, 0xFF};//4353D0h()
ASM_PATCH patchBuildingMaxSoldierThunk[] = {
	{0x4361C0, sizeof(codeBuildingMaxSoldierThunk), codeBuildingMaxSoldierThunk},
	{0x4361C0, sizeof(codeBuildingMaxSoldierOldThunk), codeBuildingMaxSoldierOldThunk}};

//max people heart cmp
DWORD dwAddrMaxPeopleHeartCmp = dwAddrStackBottom + 0x1FD0;
BYTE codeMaxPeopleHeartCmp[] = {
	0x5A,                                     //pop         edx
	0x80, 0xFA, 0x28,                         //cmp         dl,28h
	0x75, 0x06,                               //jne         xuncha_enable
	0x53,                                     //push        ebx
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xEB, 0x01,                               //jmp         get_max_people_heart
	                                          //xuncha_enable:
	0x50,                                     //push        eax
	                                          //get_max_people_heart:
	0x52,                                     //push        edx
	0xB8, 0xB1, 0xDD, 0x45, 0x00,             //mov         eax,get_city_max_people_heart
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x80, 0xFA, 0x28,                         //cmp         dl,28h
	0x75, 0x01,                               //jne         cmp_people_heart
	0x59,                                     //pop         ecx
	                                          //cmp_people_heart:
	0x87, 0x14, 0x24,                         //xchg        edx,dword ptr [esp]
	0x3B, 0xD0,                               //cmp         edx,eax
	0xB8, 0x00, 0x00, 0x00, 0x00,             //mov         eax,0
	0xC3                                      //ret
};

BYTE codeMaxPeopleHeartCmpThunk[] = {0xE8, 0xC6, 0x05, 0xBE, 0xFF};//dwAddrMaxPeopleHeartCmp - 4C1A05h
BYTE codeMaxPeopleHeartCmpOldThunk[] = {0x3D, 0xE8, 0x03, 0x00, 0x00};//cmp eax,3E8h
ASM_PATCH patchMaxPeopleHeartCmpThunk[] = {
	{0x4C1A05, sizeof(codeMaxPeopleHeartCmpThunk), codeMaxPeopleHeartCmpThunk},
	{0x4C1A05, sizeof(codeMaxPeopleHeartCmpOldThunk), codeMaxPeopleHeartCmpOldThunk}};
BYTE codeMaxPeopleHeartCmp2Thunk[] = {0xE8, 0x6C, 0x99, 0xC1, 0xFF};//dwAddrMaxPeopleHeartCmp - 48865Fh
BYTE codeMaxPeopleHeartCmp2OldThunk[] = {0x3D, 0xE8, 0x03, 0x00, 0x00};//cmp eax,3E8h
ASM_PATCH patchMaxPeopleHeartCmp2Thunk[] = {
	{0x48865F, sizeof(codeMaxPeopleHeartCmp2Thunk), codeMaxPeopleHeartCmp2Thunk},
	{0x48865F, sizeof(codeMaxPeopleHeartCmp2OldThunk), codeMaxPeopleHeartCmp2OldThunk}};
BYTE codeMaxPeopleHeartCmp3Thunk[] = {0xE8, 0xA8, 0x98, 0xC1, 0xFF, 0x90};//dwAddrMaxPeopleHeartCmp - 488723h
BYTE codeMaxPeopleHeartCmp3OldThunk[] = {0x81, 0xFB, 0xE8, 0x03, 0x00, 0x00};//cmp ebx,3E8h
ASM_PATCH patchMaxPeopleHeartCmp3Thunk[] = {
	{0x488723, sizeof(codeMaxPeopleHeartCmp3Thunk), codeMaxPeopleHeartCmp3Thunk},
	{0x488723, sizeof(codeMaxPeopleHeartCmp3OldThunk), codeMaxPeopleHeartCmp3OldThunk}};
BYTE codeMaxPeopleHeartCmp4Thunk[] = {0xE8, 0xBC, 0x71, 0xBF, 0xFF};//dwAddrMaxPeopleHeartCmp - 4AAE0Fh
BYTE codeMaxPeopleHeartCmp4OldThunk[] = {0x3D, 0xE8, 0x03, 0x00, 0x00};//cmp eax,3E8h
ASM_PATCH patchMaxPeopleHeartCmp4Thunk[] = {
	{0x4AAE0F, sizeof(codeMaxPeopleHeartCmp4Thunk), codeMaxPeopleHeartCmp4Thunk},
	{0x4AAE0F, sizeof(codeMaxPeopleHeartCmp4OldThunk), codeMaxPeopleHeartCmp4OldThunk}};

//get city max people heart
DWORD dwAddrGetCityMaxPeopleHeart = 0x45DDB1;
BYTE codeGetCityMaxPeopleHeart[] = {
	                                          //get_city_max_people_heart:
	0x0F, 0xB6, 0x41, 0x04,                   //movzx       eax,byte ptr [ecx+4]
	0x0F, 0xB6, 0x80, 0x30, 0x56, 0x0A, 0x00, //movzx       eax,byte ptr [eax+city_max_people_heart]
	0x6B, 0xC0, 0x64,                         //imul        eax,eax,64h
	0xC3                                      //ret
};

BYTE codeGetCityMaxPeopleHeartThunk[] = {0xE9, 0xFC, 0x38, 0x02, 0x00};//dwAddrGetCityMaxPeopleHeart - 43A4B0h
BYTE codeGetCityMaxPeopleHeartOldThunk[] = {0xB8, 0xE8, 0x03, 0x00, 0x00};//mov eax,3E8h
ASM_PATCH patchGetCityMaxPeopleHeartThunk[] = {
	{0x43A4B0, sizeof(codeGetCityMaxPeopleHeartThunk), codeGetCityMaxPeopleHeartThunk},
	{0x43A4B0, sizeof(codeGetCityMaxPeopleHeartOldThunk), codeGetCityMaxPeopleHeartOldThunk}};

//max people heart push
DWORD dwAddrMaxPeopleHeartPush = dwAddrStackBottom + 0x56D0;
BYTE codeMaxPeopleHeartPush[] = {
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0x52,                                     //push        edx
	0x8B, 0x44, 0x24, 0x0C,                   //mov         eax,dword ptr [esp+0Ch]
	0x3C, 0x7F,                               //cmp         al,7Fh
	0x74, 0x0A,                               //je          get_max_people_heart
	0x3C, 0x36,                               //cmp         al,36h
	0x74, 0x04,                               //je          capture_city
	0x8B, 0xCE,                               //mov         ecx,esi
	0xEB, 0x02,                               //jmp         get_max_people_heart
	                                          //capture_city:
	0x8B, 0xCF,                               //mov         ecx,edi
	                                          //get_max_people_heart:
	0xB8, 0xB1, 0xDD, 0x45, 0x00,             //mov         eax,get_city_max_people_heart
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x59,                                     //pop         ecx
	0x87, 0x44, 0x24, 0x04,                   //xchg        eax,dword ptr [esp+4]
	0x87, 0x04, 0x24,                         //xchg        eax,dword ptr [esp]
	0xC3                                      //ret
};

BYTE codeMaxPeopleHeartPushThunk[] = {0xE8, 0x83, 0xB1, 0xBD, 0xFF};//dwAddrMaxPeopleHeartPush - 4CA548h
BYTE codeMaxPeopleHeartPushOldThunk[] = {0x68, 0xE8, 0x03, 0x00, 0x00};//push 3E8h
ASM_PATCH patchMaxPeopleHeartPushThunk[] = {
	{0x4CA548, sizeof(codeMaxPeopleHeartPushThunk), codeMaxPeopleHeartPushThunk},
	{0x4CA548, sizeof(codeMaxPeopleHeartPushOldThunk), codeMaxPeopleHeartPushOldThunk}};
BYTE codeMaxPeopleHeartPush2Thunk[] = {0xE8, 0x51, 0xA3, 0xB1, 0xFF};//dwAddrMaxPeopleHeartPush - 58B37Ah
BYTE codeMaxPeopleHeartPush2OldThunk[] = {0x68, 0xE8, 0x03, 0x00, 0x00};//push 3E8h
ASM_PATCH patchMaxPeopleHeartPush2Thunk[] = {
	{0x58B37A, sizeof(codeMaxPeopleHeartPush2Thunk), codeMaxPeopleHeartPush2Thunk},
	{0x58B37A, sizeof(codeMaxPeopleHeartPush2OldThunk), codeMaxPeopleHeartPush2OldThunk}};
BYTE codeMaxPeopleHeartPush3Thunk[] = {0xE8, 0x3E, 0xB2, 0xC6, 0xFF};//dwAddrMaxPeopleHeartPush - 43A48Dh
BYTE codeMaxPeopleHeartPush3OldThunk[] = {0x68, 0xE8, 0x03, 0x00, 0x00};//push 3E8h
ASM_PATCH patchMaxPeopleHeartPush3Thunk[] = {
	{0x43A48D, sizeof(codeMaxPeopleHeartPush3Thunk), codeMaxPeopleHeartPush3Thunk},
	{0x43A48D, sizeof(codeMaxPeopleHeartPush3OldThunk), codeMaxPeopleHeartPush3OldThunk}};
BYTE codeMaxPeopleHeartPush4Thunk[] = {0xE8, 0x9A, 0xC2, 0xC3, 0xFF};//dwAddrMaxPeopleHeartPush - 469431h
BYTE codeMaxPeopleHeartPush4OldThunk[] = {0x68, 0xE8, 0x03, 0x00, 0x00};//push 3E8h
ASM_PATCH patchMaxPeopleHeartPush4Thunk[] = {
	{0x469431, sizeof(codeMaxPeopleHeartPush4Thunk), codeMaxPeopleHeartPush4Thunk},
	{0x469431, sizeof(codeMaxPeopleHeartPush4OldThunk), codeMaxPeopleHeartPush4OldThunk}};

//max people heart mov
DWORD dwAddrMaxPeopleHeartMov = dwAddrStackBottom + 0x5700;
BYTE codeMaxPeopleHeartMov[] = {
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xB1, 0xDD, 0x45, 0x00,             //mov         eax,get_city_max_people_heart
	0xFF, 0xD0,                               //call        eax
	0x80, 0x3C, 0x24, 0x54,                   //cmp         byte ptr [esp],54h
	0x74, 0x02,                               //je          end
	0x8B, 0xC8,                               //mov         ecx,eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeMaxPeopleHeartMovThunk[] = {0xE8, 0xAC, 0xCF, 0xC1, 0xFF};//dwAddrMaxPeopleHeartMov - 48874Fh
BYTE codeMaxPeopleHeartMovOldThunk[] = {0xB8, 0xE8, 0x03, 0x00, 0x00};//mov eax, 3E8h
ASM_PATCH patchMaxPeopleHeartMovThunk[] = {
	{0x48874F, sizeof(codeMaxPeopleHeartMovThunk), codeMaxPeopleHeartMovThunk},
	{0x48874F, sizeof(codeMaxPeopleHeartMovOldThunk), codeMaxPeopleHeartMovOldThunk}};
BYTE codeMaxPeopleHeartMov2Thunk[] = {0xE8, 0x61, 0xCF, 0xC1, 0xFF};//dwAddrMaxPeopleHeartMov - 48879Ah
BYTE codeMaxPeopleHeartMov2OldThunk[] = {0xB9, 0xE8, 0x03, 0x00, 0x00};//mov ecx, 3E8h
ASM_PATCH patchMaxPeopleHeartMov2Thunk[] = {
	{0x48879A, sizeof(codeMaxPeopleHeartMov2Thunk), codeMaxPeopleHeartMov2Thunk},
	{0x48879A, sizeof(codeMaxPeopleHeartMov2OldThunk), codeMaxPeopleHeartMov2OldThunk}};

//max people heart basic
DWORD dwAddrMaxPeopleHeartBasic = dwAddrStackBottom + 0x5718;
BYTE codeMaxPeopleHeartBasic[] = {
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0xC0, 0x44, 0x00,             //mov         eax,44C080h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0xB1, 0xDD, 0x45, 0x00,             //mov         eax,get_city_max_people_heart
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF0,                               //mov         esi,eax
	0x58,                                     //pop         eax
	0xC3                                      //ret
};

BYTE codeMaxPeopleHeartBasicThunk[] = {0xE8, 0x0E, 0xD2, 0xC1, 0xFF};//dwAddrMaxPeopleHeartBasic - 488505h
BYTE codeMaxPeopleHeartBasicOldThunk[] = {0xBE, 0xE8, 0x03, 0x00, 0x00};//mov esi, 3E8h
ASM_PATCH patchMaxPeopleHeartBasicThunk[] = {
	{0x488505, sizeof(codeMaxPeopleHeartBasicThunk), codeMaxPeopleHeartBasicThunk},
	{0x488505, sizeof(codeMaxPeopleHeartBasicOldThunk), codeMaxPeopleHeartBasicOldThunk}};

//max soldier push
DWORD dwAddrMaxSoldierPush = dwAddrStackBottom + 0x5730;
BYTE codeMaxSoldierPush[] = {
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0x52,                                     //push        edx
	0xB8, 0xC0, 0x61, 0x43, 0x00,             //mov         eax,4361C0h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x59,                                     //pop         ecx
	0x87, 0x44, 0x24, 0x04,                   //xchg        eax,dword ptr [esp+4]
	0x87, 0x04, 0x24,                         //xchg        eax,dword ptr [esp]
	0xC3                                      //ret
};

BYTE codeMaxSoldierPushThunk[] = {0xE8, 0xF4, 0xA2, 0xB1, 0xFF};//dwAddrMaxSoldierPush - 58B437h
BYTE codeMaxSoldierPushOldThunk[] = {0x68, 0x20, 0xA1, 0x07, 0x00};//push 7A120h
ASM_PATCH patchMaxSoldierPushThunk[] = {
	{0x58B437, sizeof(codeMaxSoldierPushThunk), codeMaxSoldierPushThunk},
	{0x58B437, sizeof(codeMaxSoldierPushOldThunk), codeMaxSoldierPushOldThunk}};
BYTE codeMaxSoldierPush2Thunk[] = {0xE8, 0x33, 0xA9, 0xB1, 0xFF};//dwAddrMaxSoldierPush - 58ADF8h
BYTE codeMaxSoldierPush2OldThunk[] = {0x68, 0x90, 0xD0, 0x03, 0x00};//push 3D090h
ASM_PATCH patchMaxSoldierPush2Thunk[] = {
	{0x58ADF8, sizeof(codeMaxSoldierPush2Thunk), codeMaxSoldierPush2Thunk},
	{0x58ADF8, sizeof(codeMaxSoldierPush2OldThunk), codeMaxSoldierPush2OldThunk}};

//max soldier cmp
DWORD dwAddrMaxSoldierCmp = dwAddrStackBottom + 0x5748;
BYTE codeMaxSoldierCmp[] = {
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xC0, 0x61, 0x43, 0x00,             //mov         eax,4361C0h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xF8,                               //cmp         edi,eax
	0xB8, 0x00, 0x00, 0x00, 0x00,             //mov         eax,0
	0xC3                                      //ret
};

BYTE codeMaxSoldierCmpThunk[] = {0xE8, 0x4B, 0x5D, 0xC0, 0xFF, 0x90};//dwAddrMaxSoldierCmp - 49F9F8h
BYTE codeMaxSoldierCmpOldThunk[] = {0x81, 0xFF, 0x20, 0xA1, 0x07, 0x00};//cmp edi, 7A120h
ASM_PATCH patchMaxSoldierCmpThunk[] = {
	{0x49F9F8, sizeof(codeMaxSoldierCmpThunk), codeMaxSoldierCmpThunk},
	{0x49F9F8, sizeof(codeMaxSoldierCmpOldThunk), codeMaxSoldierCmpOldThunk}};

//player subforce control
DWORD dwAddrPlayerSubforceControl = dwAddrStackBottom + 0x5760;
BYTE codePlayerSubforceControl[] = {
	                                          //player_subforce_control:
	0xC7, 0x05, 0xCC, 0xF7, 0x43, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,//mov dword ptr[awardable_person_number],-1
	0xC3,                                     //ret
};

//dynamic add proficiency
DWORD dwAddrDynamicAddProficiency = dwAddrStackBottom + 0x5570;
BYTE codeDynamicAddProficiency[] = {
	0xEB, 0x06,                               //jmp dynamic_add_proficiency
	                                          //normal:
	0xFF, 0x25, 0xF0, 0xF2, 0x5F, 0x00,       //jmp         dword ptr [5FF2F0h]
	                                          //dynamic_add_proficiency:
	0xFF, 0x74, 0x24, 0x30,                   //push        dword ptr [esp+30h]
	0xB8, 0xA0, 0xD2, 0x44, 0x00,             //mov         eax,44D2A0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xE8, 0x23,                         //sub         eax,23h
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         get_add_ability_prop
	0x33, 0xC0,                               //xor         eax,eax
	                                          //get_add_ability_prop:
	0x99,                                     //cdq
	0xB9, 0x0F, 0x00, 0x00, 0x00,             //mov         ecx,0Fh
	0xF7, 0xF1,                               //div         eax,ecx
	0x83, 0xE8, 0x05,                         //sub         eax,5
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x05,                               //jg          get_add_ability_prop2
	0xB8, 0x01, 0x00, 0x00, 0x00,             //mov         eax,1
	                                          //get_add_ability_prop2:
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call        dword ptr [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x58,                                     //pop         eax
	0x75, 0x01,                               //jne         got_add_ability_prop
	0x40,                                     //inc         eax
	                                          //got_add_ability_prop:
	0x89, 0x44, 0x24, 0x04,                   //mov         dword ptr [esp+4],eax
	0xEB, 0xBC                                //jmp         normal

};

BYTE codeDynamicAddProficiencyThunk[] = {0xE8, 0x72, 0x4F, 0xC5, 0xFF, 0x41};//dwAddrDynamicAddProficiency - 4505F9h
BYTE codeDynamicAddProficiencyOldThunk[] = {0xFF, 0x15, 0xF0, 0xF2, 0x5F, 0x00};//call [5FF2F0h]
ASM_PATCH patchDynamicAddProficiencyThunk[] = {
	{0x4505F9, sizeof(codeDynamicAddProficiencyThunk), codeDynamicAddProficiencyThunk},
	{0x4505F9, sizeof(codeDynamicAddProficiencyOldThunk), codeDynamicAddProficiencyOldThunk}};

//learn to phase
DWORD dwAddrLearnToPhase = 0x45B7A6;
BYTE codeLearnToPhase[] = {
	0x8B, 0x41, 0x6C,                         //mov         eax,[ecx+6Ch]
	0xC3                                      //ret
};

BYTE codeLearnToPhaseThunk[] = {0xE8, 0x2F, 0xA8, 0x00, 0x00};//dwAddrLearnToPhase - 450F72h
BYTE codeLearnToPhaseOldThunk[] = {0xE8, 0x39, 0xDE, 0xFF, 0xFF};//call 44EDB0h()
ASM_PATCH patchLearnToPhaseThunk[] = {
	{0x450F72, sizeof(codeLearnToPhaseThunk), codeLearnToPhaseThunk},
	{0x450F72, sizeof(codeLearnToPhaseOldThunk), codeLearnToPhaseOldThunk}};

//learn to phase 2
DWORD dwAddrLearnToPhase2 = dwAddrStackBottom + 0x57E0;
BYTE codeLearnToPhase2[] = {
	0x57,                                     //push        edi
	0xB8, 0x40, 0xA9, 0x56, 0x00,             //mov         eax,56A940h
	0xFF, 0xD0,                               //call        eax
	0x81, 0x39, 0x50, 0xC2, 0x66, 0x00,       //cmp         dword ptr[ecx],66C250h
	0x75, 0x06,                               //jne         end
	0x3C, 0x19,                               //cmp         al,19h
	0x75, 0x02,                               //jne         end
	0xB0, 0x5C,                               //mov         al,5Ch
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeLearnToPhase2Thunk[] = {0xE8, 0x24, 0x4A, 0xB3, 0xFF};//dwAddrLearnToPhase2 - 570DB7h
BYTE codeLearnToPhase2OldThunk[] = {0xE8, 0x84, 0x9B, 0xFF, 0xFF};//call 56A940h()
ASM_PATCH patchLearnToPhase2Thunk[] = {
	{0x570DB7, sizeof(codeLearnToPhase2Thunk), codeLearnToPhase2Thunk},
	{0x570DB7, sizeof(codeLearnToPhase2OldThunk), codeLearnToPhase2OldThunk}};

//attack troop soldier
DWORD dwAddrAttackTroopSoldier = dwAddrStackBottom + 0x5800;
BYTE codeAttackTroopSoldier[] = {
	0x81, 0xFA, 0x10, 0x27, 0x00, 0x00,       //cmp         edx,2710h
	0x7E, 0x31,                               //jle         normal
	0x2B, 0x86, 0x88, 0x00, 0x00, 0x00,       //sub         eax,dword ptr [esi+88h]
	0xF7, 0xD8,                               //neg         eax
	0x3D, 0x20, 0x4E, 0x00, 0x00,             //cmp         eax,4E20h
	0x7C, 0x22,                               //jl          normal
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0xBE, 0xDC, 0x00, 0x00, 0x00,       //lea         edi,[esi+0DCh]
	0x8B, 0x57, 0x0C,                         //mov         edx,dword ptr [edi+0Ch]
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x05,                               //jg          test_attack_person_num
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          test_attack_person_num
	0x4A,                                     //dec         edx
	                                          //test_attack_person_num:
	0x83, 0xFA, 0x01,                         //cmp         edx,1
	0x7F, 0x06,                               //jg          update_attack_troop_soldier
	                                          //normal:
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00,       //call        [5FF308h]
	                                          //update_attack_troop_soldier:
	0x55,                                     //push        ebp
	0x56,                                     //push        esi
	0x52,                                     //push        edx
	0x8B, 0xC3,                               //mov         eax,ebx
	0xB9, 0x98, 0x3A, 0x00, 0x00,             //mov         ecx,3A98h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x81, 0xFA, 0x10, 0x27, 0x00, 0x00,       //cmp         edx,2710h
	0x7C, 0x01,                               //jl          get_troop_num
	0x40,                                     //inc         eax
	                                          //get_troop_num:
	0x59,                                     //pop         ecx
	0x3B, 0xC8,                               //cmp         ecx,eax
	0x7E, 0x02,                               //jle         get_ref_troop_soldier
	0x8B, 0xC8,                               //mov         ecx,eax
	                                          //get_ref_troop_soldier:
	0x8B, 0xC3,                               //mov         eax,ebx
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xE8,                               //mov         ebp,eax
	0x8B, 0xD9,                               //mov         ebx,ecx
	0x49,                                     //dec         ecx
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x8B, 0x44, 0x84, 0x68,                   //mov         eax,dword ptr [esp+eax*4+68h]
	0x2B, 0xD8,                               //sub         ebx,eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x10,                               //jne         get_cur_person
	0x6A, 0x00,                               //push        0
	0x68, 0xA0, 0x1C, 0x47, 0x00,             //push        471CA0h
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x10, 0xF6, 0x46, 0x00,             //mov         eax,46F610h
	0xFF, 0xD0,                               //call        eax
	                                          //get_cur_person:
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x80, 0xE8, 0x46, 0x00,             //mov         eax,46E880h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF8,                               //mov         edi,eax
	0x8B, 0x74, 0x24, 0x0C,                   //mov         esi,[esp+0Ch]
	0x83, 0xFB, 0x01,                         //cmp         ebx,1
	0x7F, 0x12,                               //jg          test_first_person
	                                          //test_left_soldier:
	0x3B, 0x74, 0x24, 0x10,                   //cmp         esi,[esp+10h]
	0x7D, 0x04,                               //jge         normal2
	0x89, 0x74, 0x24, 0x10,                   //mov         [esp+10h],esi
	                                          //normal2:
	0x5E,                                     //pop         esi
	0x5D,                                     //pop         ebp
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00,       //jmp         [5FF308h]
	                                          //test_first_person:
	0x3B, 0x6C, 0x24, 0x10,                   //cmp         ebp,dword ptr [esp+10h]
	0x7D, 0xF2,                               //jge         normal2
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0x00, 0xD7, 0x44, 0x00,             //mov         eax,44D700h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7C, 0x06,                               //jl          loop_tail_person
	0x89, 0x6C, 0x24, 0x10,                   //mov         dword ptr [esp+10h],ebp
	0xEB, 0xDE,                               //jmp         normal2
											  //loop_tail_person:
	0x2B, 0xF0,                               //sub         esi,eax
	0x4B,                                     //dec         ebx
	0x83, 0xFB, 0x01,                         //cmp         ebx,1
	0x74, 0xCC,                               //je          test_left_soldier
	0x8B, 0x7F, 0x04,                         //mov         edi,dword ptr [edi+4]
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0x00, 0xD7, 0x44, 0x00,             //mov         eax,44D700h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7E, 0xE7,                               //jle         loop_tail_person
	0x8B, 0xC6,                               //mov         eax,esi
	0x99,                                     //cdq
	0xF7, 0xF3,                               //div         eax,ebx
	0x8B, 0xE8,                               //mov         ebp,eax
	0xEB, 0xC4                                //jmp         test_first_person
};

BYTE codeAttackTroopSoldierThunk[] = {0xE8, 0xF8, 0x0B, 0xBF, 0xFF, 0x41};//dwAddrAttackTroopSoldier - 4B4C03h
BYTE codeAttackTroopSoldierOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};//call [5FF308h]
ASM_PATCH patchAttackTroopSoldierThunk[] = {
	{0x4B4C03, sizeof(codeAttackTroopSoldierThunk), codeAttackTroopSoldierThunk},
	{0x4B4C03, sizeof(codeAttackTroopSoldierOldThunk), codeAttackTroopSoldierOldThunk}};

//attack troop soldier 2
DWORD dwAddrAttackTroopSoldier2 = dwAddrStackBottom + 0x5900;
BYTE codeAttackTroopSoldier2[] = {
	0x3D, 0x10, 0x27, 0x00, 0x00,             //cmp         eax,2710h
	0x7E, 0x28,                               //jle         normal
	0x81, 0xFE, 0x20, 0x4E, 0x00, 0x00,       //cmp         esi,4E20h
	0x7C, 0x20,                               //jl          normal
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0xAF, 0xDC, 0x00, 0x00, 0x00,       //lea         ebp,[edi+0DCh]
	0x8B, 0x55, 0x0C,                         //mov         edx,dword ptr [ebp+0Ch]
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x05,                               //jg          test_attack_person_num
	0x3C, 0x01,                               //cmp         al,1
	0x74, 0x01,                               //je          test_attack_person_num
	0x4A,                                     //dec         edx
	                                          //test_attack_person_num:
	0x83, 0xFA, 0x01,                         //cmp         edx,1
	0x7F, 0x06,                               //jg          update_attack_troop_soldier
	                                          //normal:
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00,       //jmp         [5FF308h]
	                                          //update_attack_troop_soldier:
	0x57,                                     //push        edi
	0x52,                                     //push        edx
	0x8B, 0xC6,                               //mov         eax,esi
	0xB9, 0x98, 0x3A, 0x00, 0x00,             //mov         ecx,3A98h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x81, 0xFA, 0x10, 0x27, 0x00, 0x00,       //cmp         edx,2710h
	0x7C, 0x01,                               //jl          get_troop_num
	0x40,                                     //inc         eax
	                                          //get_troop_num:
	0x59,                                     //pop         ecx
	0x3B, 0xC8,                               //cmp         ecx,eax
	0x7E, 0x02,                               //jle         get_ref_troop_soldier
	0x8B, 0xC8,                               //mov         ecx,eax
	                                          //get_ref_troop_soldier:
	0x8B, 0xC6,                               //mov         eax,esi
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0xF1,                               //mov         esi,ecx
	0x49,                                     //dec         ecx
	0x51,                                     //push        ecx
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x80, 0xE8, 0x46, 0x00,             //mov         eax,46E880h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xE8,                               //mov         ebp,eax
	0x8B, 0x7C, 0x24, 0x08,                   //mov         edi,dword ptr [esp+8]
	0x83, 0xFE, 0x01,                         //cmp         esi,1
	0x7F, 0x11,                               //jg          test_first_person
	                                          //test_left_soldier:
	0x3B, 0x7C, 0x24, 0x0C,                   //cmp         edi,dword ptr [esp+0Ch]
	0x7D, 0x04,                               //jge         normal2
	0x89, 0x7C, 0x24, 0x0C,                   //mov         dword ptr [esp+0Ch],edi
	                                          //normal2:
	0x5F,                                     //pop         edi
	0xFF, 0x25, 0x08, 0xF3, 0x5F, 0x00,       //jmp         [5FF308h]
	                                          //test_first_person:
	0x3B, 0x5C, 0x24, 0x0C,                   //cmp         ebx,dword ptr [esp+0Ch]
	0x7D, 0xF3,                               //jge         normal2
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xB8, 0x00, 0xD7, 0x44, 0x00,             //mov         eax,44D700h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7C, 0x06,                               //jl          loop_tail_person
	0x89, 0x5C, 0x24, 0x0C,                   //mov         dword ptr [esp+0Ch],ebx
	0xEB, 0xDF,                               //jmp         normal2
	                                          //loop_tail_person:
	0x2B, 0xF8,                               //sub         edi,eax
	0x4E,                                     //dec         esi
	0x83, 0xFE, 0x01,                         //cmp         esi,1
	0x74, 0xCD,                               //je          test_left_soldier
	0x8B, 0x6D, 0x04,                         //mov         ebp,dword ptr [ebp+4]
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xB8, 0x00, 0xD7, 0x44, 0x00,             //mov         eax,44D700h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7E, 0xE7,                               //jle         loop_tail_person
	0x8B, 0xC7,                               //mov         eax,edi
	0x99,                                     //cdq
	0xF7, 0xF6,                               //div         eax,esi
	0x8B, 0xD8,                               //mov         ebx,eax
	0xEB, 0xC4                                //jmp         test_first_person
};

BYTE codeAttackTroopSoldier2Thunk[] = {0xE8, 0xBD, 0x0A, 0xBF, 0xFF, 0x41};//dwAddrAttackTroopSoldier2 - 4B4E3Eh
BYTE codeAttackTroopSoldier2OldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};//call [5FF308h]
ASM_PATCH patchAttackTroopSoldier2Thunk[] = {
	{0x4B4E3E, sizeof(codeAttackTroopSoldier2Thunk), codeAttackTroopSoldier2Thunk},
	{0x4B4E3E, sizeof(codeAttackTroopSoldier2OldThunk), codeAttackTroopSoldier2OldThunk}};

//person char num
DWORD dwAddrPersonCharNum = dwAddrStackBottom + 0x6900;
BYTE codePersonCharNum[] = {
	0x8B, 0x2F,                               //mov         ebp,dword ptr [edi]
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xF6, 0xC1, 0x01,                         //test        cl,1
	0x75, 0x7F,                               //jne         end
	0xD0, 0xE9,                               //shr         cl,1
	0x80, 0xF9, 0x31,                         //cmp         cl,31h
	0x7C, 0x78,                               //jl          end
	0x80, 0xF9, 0x39,                         //cmp         cl,39h
	0x7F, 0x73,                               //jg          end
	0x80, 0x7C, 0x24, 0x2C, 0x38,             //cmp         byte ptr[esp+2Ch],38h
	0x75, 0x6C,                               //jne         end
	0x80, 0x44, 0x24, 0x5C, 0x04,             //add         byte ptr [esp+5Ch],4
	0xBF, 0x20, 0x20, 0x20, 0x20,             //mov         edi,20202020h
	0x80, 0xE9, 0x2E,                         //sub         cl,2Eh
	0x8B, 0x86, 0xE8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+0E8h]
	0xD3, 0xE8,                               //shr         eax,cl
	0x24, 0x01,                               //and         al,1
	0x74, 0x05,                               //je          test_right_effort
	0xBF, 0xA1, 0xB8, 0x20, 0x20,             //mov         edi,2020B8A1h
	                                          //test_right_effort:
	0x80, 0xE9, 0x03,                         //sub         cl,3
	0x80, 0xF9, 0x04,                         //cmp         cl,4
	0x7F, 0x21,                               //jg          save_killer_flag
	0x0F, 0xB7, 0x46, 0x04,                   //movzx       eax,word ptr [esi+4]
	0x3D, 0x20, 0x03, 0x00, 0x00,             //cmp         eax,320h
	0x7D, 0x16,                               //jge         save_killer_flag
	0x8B, 0x04, 0x85, 0x00, 0x40, 0x0A, 0x00, //mov         eax,dword ptr [eax*4+person_config_info]
	0xD0, 0xE1,                               //shl         cl,1
	0xD3, 0xE8,                               //shr         eax,cl
	0x24, 0x03,                               //and         al,3
	0x3C, 0x03,                               //cmp         al,3
	0x75, 0x05,                               //jne         save_killer_flag
	0xBF, 0xA1, 0xB7, 0x20, 0x20,             //mov         edi,2020B7A1h
	                                          //save_killer_flag:
	0x8B, 0x45, 0x00,                         //mov         eax,dword ptr [ebp]
	0x89, 0x7D, 0x00,                         //mov         dword ptr [ebp],edi
	0x8B, 0x4D, 0xF8,                         //mov         ecx,dword ptr [ebp-8]
	0x83, 0xE9, 0x04,                         //sub         ecx,4
	0xF7, 0xD9,                               //neg         ecx
	                                          //loop_space_padding:
	0x85, 0xC9,                               //test        ecx,ecx
	0x7E, 0x08,                               //jle         save_experience
	0xC1, 0xE0, 0x08,                         //shl         eax,8
	0xB0, 0x20,                               //mov         al,20h
	0x49,                                     //dec         ecx
	0xEB, 0xF4,                               //jmp         loop_space_padding
	                                          //save_experience:
	0x89, 0x45, 0x04,                         //mov         [ebp+4],eax
	0xC6, 0x45, 0x08, 0x00,                   //mov         byte ptr[ebp+8],0
	0xC6, 0x45, 0xF8, 0x08,                   //mov         byte ptr[ebp-8],8
	                                          //end:
	0x8B, 0x45, 0xF8,                         //mov         eax,dword ptr [ebp-8]
	0xC3                                      //ret
};

BYTE codePersonCharNumThunk[] = {0xE8, 0x9F, 0x4E, 0xC5, 0xFF};//dwAddrPersonCharNum - 451A5Ch
BYTE codePersonCharNumOldThunk[] = {0x8B, 0x17, 0x8B, 0x42, 0xF8};//mov edx,[edi];mov eax,[edx-8]
ASM_PATCH patchPersonCharNumThunk[] = {
	{0x451A5C, sizeof(codePersonCharNumThunk), codePersonCharNumThunk},
	{0x451A5C, sizeof(codePersonCharNumOldThunk), codePersonCharNumOldThunk}};

//attack ratio door
DWORD dwAddrAttackRatioDoor = dwAddrStackBottom + 0x59C0;
BYTE codeAttackRatioDoor[] = {
	0x50,                                     //push        eax
	0xF7, 0xD8,                               //neg         eax
	0x1B, 0xC0,                               //sbb         eax,eax
	0x83, 0xE0, 0x19,                         //and         eax,19h
	0x83, 0xC0, 0x73,                         //add         eax,73h
	0x8B, 0x4D, 0x38,                         //mov         ecx,dword ptr [ebp+38h]
	0x8B, 0x89, 0xBC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0BCh]
	0x8B, 0x51, 0x78,                         //mov         edx,dword ptr [ecx+78h]
	0x6B, 0xD2, 0x0A,                         //imul        edx,edx,0Ah
	0x03, 0xC2,                               //add         eax,edx
	0x0F, 0xAF, 0xF0,                         //imul        esi,eax
	0x58,                                     //pop         eax
	0x85, 0xC0,                               //test        eax,eax
	0xB8, 0x1F, 0x85, 0xEB, 0x51,             //mov         eax,51EB851Fh
	0x74, 0x06,                               //je          non_strong_force
	0x68, 0xAA, 0x5A, 0x4B, 0x00,             //push        4B5AAAh
	0xC3,                                     //ret
	                                          ///non_strong_force:
	0x68, 0x06, 0x5B, 0x4B, 0x00,             //push        4B5B06h
	0xC3                                      //ret
};

BYTE codeAttackRatioDoorThunk[] = {0xE9, 0xC7, 0xFE, 0xBE, 0xFF};//dwAddrAttackRatioDoor - 4B5AF4h
BYTE codeAttackRatioDoorOldThunk[] = {0xB8, 0x1F, 0x85, 0xEB, 0x51};//mov eax,51EB851Fh
ASM_PATCH patchAttackRatioDoorThunk[] = {
	{0x4B5AF4, sizeof(codeAttackRatioDoorThunk), codeAttackRatioDoorThunk},
	{0x4B5AF4, sizeof(codeAttackRatioDoorOldThunk), codeAttackRatioDoorOldThunk}};

//troop at good place
DWORD dwAddrTroopAtGoodPlace = dwAddrStackBottom + 0x5A00;
BYTE codeTroopAtGoodPlace[] = {
	0x53,                                     //push        ebx
	0xB8, 0x40, 0x58, 0x40, 0x00,             //mov         eax,405840h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         test_from_building
	0xC3,                                     //ret
	                                          //test_from_building:
	0x8B, 0x46, 0x64,                         //mov         eax,dword ptr [esi+64h]
	0x66, 0x83, 0x78, 0x06, 0x05,             //cmp         word ptr [eax+6],5
	0x75, 0x01,                               //jne         check_in_building
	0xC3,                                     //ret
	                                          //check_in_building:
	0x83, 0xEC, 0x10,                         //sub         esp,10h
	0x8B, 0xCC,                               //mov         ecx,esp
	0x83, 0xC0, 0x10,                         //add         eax,10h
	0x50,                                     //push        eax
	0x8D, 0x46, 0x10,                         //lea         eax,[esi+10h]
	0x50,                                     //push        eax
	0x51,                                     //push        ecx
	0xFF, 0x15, 0x60, 0xF3, 0x5F, 0x00,       //call        dword ptr ds:[5FF360h]
	0x83, 0xC4, 0x10,                         //add         esp,10h
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x03,                               //jne         troop_in_building
	0xB0, 0x01,                               //mov         al,1
	0xC3,                                     //ret
	                                          //troop_in_building:
	0x68, 0x76, 0x42, 0x46, 0x00,             //push        464276h
	0xC2, 0x08, 0x00                          //ret         8
};

BYTE codeTroopAtGoodPlaceThunk[] = {0xE8, 0x3A, 0x18, 0xC4, 0xFF};//dwAddrTroopAtGoodPlace - 4641C1h
BYTE codeTroopAtGoodPlaceOldThunk[] = {0xE8, 0x7A, 0x16, 0xFA, 0xFF};//call 405840h()
ASM_PATCH patchTroopAtGoodPlaceThunk[] = {
	{0x4641C1, sizeof(codeTroopAtGoodPlaceThunk), codeTroopAtGoodPlaceThunk},
	{0x4641C1, sizeof(codeTroopAtGoodPlaceOldThunk), codeTroopAtGoodPlaceOldThunk}};

//pre building soldier 2
DWORD dwAddrPreBuildingSoldier2 = dwAddrStackBottom + 0x5A40;
BYTE codePreBuildingSoldier2[] = {
	                                          //pre_building_soldier2:
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x05,                               //jne         test_baram_force
	0x33, 0xC0,                               //xor         eax,eax
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_baram_force:
	0xF6, 0x40, 0x34, 0x04,                   //test        byte ptr [eax+34h],4
	0x74, 0x09,                               //je          get_goal_soldier
	0x8B, 0x81, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+88h]
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //get_goal_soldier:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x8B, 0xD9,                               //mov         ebx,ecx
	0xB8, 0x90, 0x19, 0x0A, 0x00,             //mov         eax,get_building_backup
	0xFF, 0xD0,                               //call        eax
	0x03, 0x83, 0x88, 0x00, 0x00, 0x00,       //add         eax,dword ptr [ebx+88h]
	0x8B, 0xF0,                               //mov         esi,eax
	0x99,                                     //cdq
	0xB9, 0x10, 0x27, 0x00, 0x00,             //mov         ecx,2710h
	0xF7, 0xF1,                               //div         eax,ecx
	0x66, 0x81, 0xFA, 0x88, 0x13,             //cmp         dx,offset get_goal_soldier+20h
	0x7C, 0x01,                               //jl          got_min_defense_person
	0x40,                                     //inc         eax
	                                          //got_min_defense_person:
	0x85, 0xC0,                               //test        eax,eax
	0x0F, 0x84, 0x9F, 0x00, 0x00, 0x00,       //je          get_wait_troop_soldier
	0x50,                                     //push        eax
	0x33, 0xC9,                               //xor         ecx,ecx
	0xBA, 0xE0, 0x8E, 0x25, 0x01,             //mov         edx,1258EE0h
	0x33, 0xFF,                               //xor         edi,edi
	                                          //loop_defense_person:
	0x8B, 0x82, 0x84, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [edx+84h]
	0x85, 0xC0,                               //test        eax,eax
	0x7C, 0x27,                               //jl          next_person
	0x3C, 0x03,                               //cmp         al,3
	0x7F, 0x23,                               //jg          next_person
	0x8B, 0xAA, 0xF4, 0x00, 0x00, 0x00,       //mov         ebp,dword ptr [edx+0F4h]
	0x39, 0x5D, 0x64,                         //cmp         dword ptr [ebp+64h],ebx
	0x75, 0x18,                               //jne         next_person
	0x8B, 0x45, 0x58,                         //mov         eax,dword ptr [ebp+58h]
	0x83, 0xF8, 0x26,                         //cmp         eax,26h
	0x7C, 0x0F,                               //jl          inc_defense_person_num
	0x83, 0xF8, 0x32,                         //cmp         eax,32h
	0x7F, 0x0A,                               //jg          inc_defense_person_num
	0x83, 0xF8, 0x27,                         //cmp         eax,27h
	0x75, 0x06,                               //jne         next_person
	0x39, 0x5D, 0x50,                         //cmp         dword ptr [ebp+50h],ebx
	0x75, 0x01,                               //jne         next_person
	                                          //inc_defense_person_num:
	0x41,                                     //inc         ecx
	                                          //next_person:
	0x81, 0xC2, 0x28, 0x01, 0x00, 0x00,       //add         edx,128h
	0x47,                                     //inc         edi
	0x66, 0x81, 0xFF, 0x52, 0x03,             //cmp         di,offset next_person+0Ah
	0x7C, 0xC1,                               //jl          loop_defense_person
	0x5D,                                     //pop         ebp
	0x3B, 0xCD,                               //cmp         ecx,ebp
	0x7F, 0x1E,                               //jg          add_defense_soldier
	0xB8, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         eax,7FFFFFFFh
	0x99,                                     //cdq
	0xF7, 0xF5,                               //div         eax,ebp
	0xF7, 0xE9,                               //imul        ecx
	0x3D, 0x99, 0x99, 0x99, 0x59,             //cmp         eax,59999999h
	0x7D, 0x05,                               //jge         got_sub_coef
	0xB8, 0x99, 0x99, 0x99, 0x59,             //mov         eax,59999999h
	                                          //got_sub_coef:
	0xF7, 0xEE,                               //imul        esi
	0x8B, 0xF2,                               //mov         esi,edx
	0xD1, 0xE6,                               //shl         esi,1
	0xEB, 0x33,                               //jmp         get_wait_troop_soldier
	                                          //add_defense_soldier:
	0x2B, 0xCD,                               //sub         ecx,ebp
	0x8B, 0xC1,                               //mov         eax,ecx
	0x99,                                     //cdq
	0xF7, 0xF5,                               //div         eax,ebp
	0x66, 0x3D, 0x03, 0x00,                   //cmp         ax,3
	0x7E, 0x06,                               //jle         got_add_base
	0x66, 0xB8, 0x03, 0x00,                   //mov         ax,3
	0x33, 0xD2,                               //xor         edx,edx
	                                          //got_add_base:
	0x50,                                     //push        eax
	0x52,                                     //push        edx
	0xB8, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         eax,7FFFFFFFh
	0x99,                                     //cdq
	0xF7, 0xF5,                               //div         eax,ebp
	0x5A,                                     //pop         edx
	0xF7, 0xEA,                               //imul        edx
	0xB9, 0x33, 0x33, 0x33, 0x33,             //mov         ecx,33333333h
	0xF7, 0xE9,                               //imul        ecx
	0x58,                                     //pop         eax
	0xD1, 0xE9,                               //shr         ecx,1
	0x0F, 0xAF, 0xC1,                         //imul        eax,ecx
	0x03, 0xC2,                               //add         eax,edx
	0xF7, 0xEE,                               //imul        esi
	0x03, 0xF2,                               //add         esi,edx
	                                          //get_wait_troop_soldier:
	0xBF, 0xB0, 0x93, 0x4B, 0x01,             //mov         edi,14B93B0h
	                                          //loop_wati_troop:
	0x39, 0x5F, 0x64,                         //cmp         dword ptr [edi+64h],ebx
	0x75, 0x09,                               //jne         next_wait_troop
	0xF6, 0x47, 0x20, 0x0B,                   //test        byte ptr [edi+20h],0Bh
	0x75, 0x03,                               //jne         next_wait_troop
	0x03, 0x77, 0x30,                         //add         esi,dword ptr [edi+30h]
	                                          //next_wait_troop:
	0x81, 0xC7, 0x04, 0x01, 0x00, 0x00,       //add         edi,104h
	0x66, 0x81, 0x7F, 0x04, 0x51, 0x03,       //cmp         word ptr [edi+4],351h
	0x7C, 0xE4,                               //jl          loop_wati_troop
	0x8B, 0xC6,                               //mov         eax,esi
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

//attack troop retreat
DWORD dwAddrAttackTroopRetreat = dwAddrStackBottom + 0x5B60;
BYTE codeAttackTroopRetreat[] = {
	                                          //attack_troop_retreat:
	0x80, 0x61, 0x21, 0xEF,                   //and         byte ptr [ecx+21h],0EFh
	0x33, 0xC0,                               //xor         eax,eax
	0x89, 0x41, 0x7C,                         //mov         dword ptr [ecx+7Ch],eax
	0xB0, 0x34,                               //mov         al,34h
	0x89, 0x41, 0x58,                         //mov         dword ptr [ecx+58h],eax
	0x8B, 0x41, 0x74,						  //mov         eax,dword ptr [ecx+74h]
	0xF6, 0x40, 0x34, 0x05,					  //test        byte ptr [eax+34h],5
	0x75, 0x16,								  //jne         set_retreat_goal
	0x8B, 0x41, 0x6C,						  //mov         eax,dword ptr [ecx+6Ch]
	0x80, 0x78, 0x04, 0x08,					  //cmp         byte ptr [eax+4],8
	0x7C, 0x0D,								  //jl          set_retreat_goal
	0x80, 0x78, 0x04, 0x0B,					  //cmp         byte ptr [eax+4],0Bh
	0x7F, 0x07,								  //jg          set_retreat_goal
	0xC7, 0x41, 0x6C, 0xA0, 0x0E, 0x50, 0x01, //mov         dword ptr [ecx+6Ch],1500EA0h
	                                          //set_retreat_goal:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8B, 0xF1,                               //mov         esi,ecx
	0x8B, 0x6E, 0x64,                         //mov         ebp,dword ptr [esi+64h]
	0x83, 0xEC, 0x60,                         //sub         esp,60h
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xFF, 0xB5, 0xD0, 0x00, 0x00, 0x00,       //push        dword ptr [ebp+0D0h]
	0x56,                                     //push        esi
	0xB8, 0x30, 0xA3, 0x47, 0x00,             //mov         eax,47A330h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,             //mov         eax,4734B0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0x54,                                     //push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,             //mov         eax,478290h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_map_block:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xB8, 0xA0, 0xC8, 0x45, 0x00,             //mov         eax,45C8A0h
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x74, 0x23,                               //je          next_map_block
	0x8B, 0xD8,                               //mov         ebx,eax
	0x3B, 0xDD,                               //cmp         ebx,ebp
	0x74, 0x23,                               //je          end_map_block
	0x53,                                     //push        ebx
	0xB8, 0x10, 0xF2, 0x4A, 0x00,             //mov         eax,4AF210h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,                                     //pop         ecx
	0x74, 0x10,                               //je          next_map_block
	0x55,                                     //push        ebp
	0xB8, 0x80, 0x57, 0x43, 0x00,             //mov         eax,435780h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          next_map_block
	0x8B, 0xEB,                               //mov         ebp,ebx
	0xEB, 0x06,                               //jmp         end_map_block
	                                          //next_map_block:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xC9,                               //jne         loop_map_block
	                                          //end_map_block:
	0x8B, 0x45, 0x04,                         //mov         eax,dword ptr [ebp+4]
	0x89, 0x46, 0x50,                         //mov         dword ptr [esi+50h],eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea         ecx,[esp+20h]
	0xB8, 0x10, 0x9F, 0x47, 0x00,             //mov         eax,479F10h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x60,                         //add         esp,60h
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//troop retreat
DWORD dwAddrTroopRetreat = dwAddrStackBottom + 0x5C20;
BYTE codeTroopRetreat[] = {
	0x80, 0x79, 0x58, 0x26,                   //cmp         byte ptr [ecx+58h],26h
	0x75, 0x0E,                               //jne         normal
	0x80, 0x79, 0x52, 0x03,                   //cmp         byte ptr [ecx+52h],3
	0x74, 0x08,                               //je          normal
	0xB8, 0x60, 0x5B, 0x0A, 0x00,             //mov         eax,attack_troop_retreat
	0xFF, 0xD0,                               //call        eax
	0xC3,                                     //ret
	                                          //normal:
	0xB8, 0xB0, 0x42, 0x46, 0x00,             //mov         eax,4642B0h
	0xFF, 0xD0,                               //call        eax
	0xC3                                      //ret
};

BYTE codeTroopRetreatThunk[] = {0xE8, 0x15, 0x0B, 0xC4, 0xFF};//dwAddrTroopRetreat - 465106h
BYTE codeTroopRetreatOldThunk[] = {0xE8, 0xA5, 0xF1, 0xFF, 0xFF};//call 4642B0h()
ASM_PATCH patchTroopRetreatThunk[] = {
	{0x465106, sizeof(codeTroopRetreatThunk), codeTroopRetreatThunk},
	{0x465106, sizeof(codeTroopRetreatOldThunk), codeTroopRetreatOldThunk}};

//second killer
DWORD dwAddrSecondKiller = dwAddrStackBottom + 0x5E00;
BYTE codeSecondKiller[] = {
	0xBF, 0xB5, 0xF4, 0x43, 0x00,             //mov         edi,second_killer_id
	                                          //get_first_person:
	0x8B, 0x4E, 0x38,                         //mov         ecx,dword ptr [esi+38h]
	0x8B, 0x49, 0x08,                         //mov         ecx,dword ptr [ecx+8]
	0x3B, 0x4F, 0xFC,                         //cmp         ecx,dword ptr [edi-4]
	0x75, 0x64,                               //jne         test_first_killer
	                                          //try_second_killer:
	0x8B, 0x1F,                               //mov         ebx,[edi]
	                                          //loop_second_killer:
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x41,                               //je          delete_first_person
	0x0F, 0xB6, 0x47, 0x04,                   //movzx       eax,byte ptr [edi+4]
	0x40,                                     //inc         eax
	0x88, 0x47, 0x04,                         //mov         byte ptr [edi+4],al
	0x83, 0xC0, 0x05,                         //add         eax,5
	0x0F, 0xB6, 0x04, 0x38,					  //movzx       eax,byte ptr[edi+eax]
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x0F, 0xB6, 0xD3,                         //movzx       edx,bl
	0xC1, 0xEB, 0x08,                         //shr         ebx,8
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xDB,                               //je          loop_second_killer
	0x4A,                                     //dec         edx
	0x52,                                     //push        edx
	0xB8, 0x20, 0x37, 0x45, 0x00,             //mov         eax,453720h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x89, 0x1F,                               //mov         [edi],ebx
	0x8B, 0x4F, 0xFC,                         //mov         ecx,dword ptr [edi-4]
	0x8B, 0x99, 0xF8, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [ecx+0F8h]
	0x89, 0x81, 0xF8, 0x00, 0x00, 0x00,       //mov         dword ptr [ecx+0F8h],eax
	0xE9, 0xE8, 0x00, 0x00, 0x00,             //jmp         try_killer
	                                          //delete_first_person:
	0x8D, 0x4E, 0x34,                         //lea         ecx,[esi+34h]
	0xB8, 0x10, 0x82, 0x51, 0x00,             //mov         eax,518210h
	0xFF, 0xD0,                               //call        eax
	0x83, 0x7E, 0x40, 0x00,                   //cmp         dword ptr [esi+40h],0
	0x75, 0x9E,                               //jne         get_first_person
	0x33, 0xC0,								  //xor         eax,eax
	0x89, 0x47, 0xFC,						  //mov         [edi-4],eax
	0x68, 0x35, 0x64, 0x50, 0x00,             //push        506435h
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_first_killer:
	0x89, 0x4F, 0xFC,                         //mov         dword ptr [edi-4],ecx
	0x33, 0xDB,                               //xor         ebx,ebx
	0x89, 0x1F,                               //mov         dword ptr [edi],eax
	0x88, 0x5F, 0x04,                         //mov         [edi+4],bl
	0x8B, 0x81, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0F8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xCF,                               //je          delete_first_person
	0x8B, 0x40, 0x54,                         //mov         eax,dword ptr [eax+54h]
	0x83, 0xF8, 0x03,                         //cmp         eax,3
	0x7E, 0x5A,                               //jle         first_strength_killer
	0x83, 0xF8, 0x08,                         //cmp         eax,8
	0x7F, 0xC2,                               //jg          delete_first_person
	0x83, 0xF8, 0x06,                         //cmp         eax,6
	0x7C, 0xBD,                               //jl          delete_first_person
	0x8B, 0x41, 0x50,                         //mov         eax,dword ptr [ecx+50h]
	0x6B, 0xC0, 0x03,                         //imul        eax,eax,3
	0xD1, 0xE8,                               //shr         eax,1
	0x3B, 0x41, 0x58,                         //cmp         eax,dword ptr [ecx+58h]
	0x7C, 0x41,                               //jl          skip_try_killer
	0x8B, 0x81, 0x00, 0x01, 0x00, 0x00,       //mov         eax,dword ptr [ecx+100h]
	0x51,                                     //push        ecx
	0x33, 0xC9,                               //xor         ecx,ecx
	0x41,                                     //inc         ecx
	0x8B, 0x96, 0x84, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [esi+84h]
	0xF6, 0x42, 0x20, 0x01,                   //test        byte ptr [edx+20h],1
	0xBA, 0x00, 0x00, 0x00, 0x00,             //mov         edx,0
	0x74, 0x06,                               //je          loop_add_strength_killer 
	0xC1, 0xE8, 0x06,                         //shr         eax,6
	0x83, 0xC1, 0x06,                         //add         ecx,6
	                                          //loop_add_strength_killer:
	0xA8, 0x01,                               //test        al,1
	0x74, 0x05,                               //je          shift_killer_flag
	0x88, 0x0C, 0x1F,                         //mov         byte ptr [edi+ebx],cl
	0xB6, 0x01,                               //mov         dh,1
	                                          //shift_killer_flag:
	0xD1, 0xE8,                               //shr         eax,1
	0x42,                                     //inc         edx
	0x80, 0xFA, 0x03,                         //cmp         dl,3
	0x7C, 0x08,                               //jl          add_killer_index
	0xF6, 0xC6, 0x01,                         //test        dh,1
	0x74, 0x01,                               //je          clear_internal_index
	0x43,                                     //inc         ebx
	                                          //clear_internal_index:
	0x33, 0xD2,                               //xor         edx,edx
	                                          //add_killer_index:
	0x41,                                     //inc         ecx
	0x80, 0xF9, 0x0C,                         //cmp         cl,0Ch
	0x7E, 0xE1,                               //jle         loop_add_strength_killer
	0x59,                                     //pop         ecx
	                                          //skip_try_killer:
	0xEB, 0x55,                               //jmp         try_killer
	                                          //first_strength_killer:
	0x8B, 0x41, 0x58,                         //mov         eax,dword ptr [ecx+58h]
	0x6B, 0xC0, 0x03,                         //imul        eax,eax,3
	0xD1, 0xE8,                               //shr         eax,1
	0x3B, 0x41, 0x50,                         //cmp         eax,dword ptr [ecx+50h]
	0x7C, 0xF1,                               //jl          skip_try_killer
	0x8B, 0x81, 0x02, 0x01, 0x00, 0x00,       //mov         eax,word ptr [ecx+102h]
	0x8B, 0x96, 0x84, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [esi+84h]
	0xF6, 0x42, 0x20, 0x01,                   //test        byte ptr [edx+20h],1
	0x75, 0x0A,                               //jne         test_attack_heart
	0xF6, 0xC4, 0x01,                         //test        ah,1
	0x74, 0x05,                               //je          test_attack_heart
	0xC6, 0x04, 0x1F, 0x19,                   //mov         byte ptr [edi+ebx],19h
	0x43,                                     //inc         ebx
	                                          //test_attack_heart:
	0xF6, 0xC4, 0x02,                         //test        ah,2
	0x74, 0x05,                               //je          test_chaos
	0xC6, 0x04, 0x1F, 0x1A,                   //mov         byte ptr [edi+ebx],1Ah
	0x43,                                     //inc         ebx
	                                          //test_chaos:
	0xA8, 0x80,                               //test        al,80h
	0x74, 0x05,                               //je          test_abuse
	0xC6, 0x04, 0x1F, 0x18,                   //mov         byte ptr [edi+ebx],18h
	0x43,                                     //inc         ebx
	                                          //test_abuse:
	0xF6, 0xC4, 0x08,                         //test        ah,8
	0x74, 0x05,                               //je          test_inspire
	0xC6, 0x04, 0x1F, 0x1C,                   //mov         byte ptr [edi+ebx],1Ch
	0x43,                                     //inc         ebx
	                                          //test_inspire:
	0x80, 0x0FB, 0x04,                        //cmp         bl,4
	0x7D, 0x0A,                               //jge         try_killer
	0xF6, 0xC4, 0x10,                         //test        ah,10h
	0x74, 0x05,                               //je          try_killer
	0xC6, 0x04, 0x1F, 0x1D,                   //mov         byte ptr [edi+ebx],1Dh
	0x43,                                     //inc         ebx
	                                          //try_killer:
	0x83, 0xFB, 0x7F,                         //cmp         ebx,7Fh
	0x7F, 0x29,                               //jg          create_killer_task
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x25,                               //je          create_killer_task
	0x51,                                     //push        ecx
	0x8B, 0x89, 0xF8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+0F8h]
	0x8B, 0x86, 0x80, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [esi+80h]
	0xFF, 0x70, 0x6C,                         //push        dword ptr [eax+6Ch]
	0xB8, 0x00, 0x31, 0x0A, 0x00,             //mov         eax,killer_array_coef
	0xFF, 0xD0,                               //call        eax
	0xC1, 0xE8, 0x1D,                         //shr         eax,1Dh
	0x88, 0x47, 0x05,                         //mov         [edi+5],al
	0x59,                                     //pop         ecx
	0xC7, 0x47, 0x06, 0x32, 0x3C, 0x4B, 0x5F, //mov         dword ptr[edi+6],5F4B3C32h
	                                          //create_killer_task:
	0x89, 0x4E, 0x54,                         //mov         dword ptr [esi+54h],ecx
	0x51,                                     //push        ecx
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xB0, 0x14, 0x50, 0x00,             //mov         eax,5014B0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xFB, 0x7F,                         //cmp         ebx,7Fh
	0x7C, 0x09,                               //jl          end
	0x8B, 0x4F, 0xFC,                         //mov         ecx,dword ptr [edi-4]
	0x89, 0x99, 0xF8, 0x00, 0x00, 0x00,       //mov         dword ptr [ecx+0F8h],ebx
	                                          //end:
	0x85, 0xC0,                               //test        eax,eax
	0x0F, 0x84, 0xC7, 0xFE, 0xFF, 0xFF,       //je          delete_first_person
	0x68, 0x70, 0x64, 0x50, 0x00,             //push        506470h
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeSecondKillerThunk[] = {0xE8, 0xAD, 0xF9, 0xB9, 0xFF};//dwAddrSecondKiller - 50644Eh
BYTE codeSecondKillerOldThunk[] = {0xE8, 0xBD, 0x1D, 0x01, 0x00};//call 518210h()
ASM_PATCH patchSecondKillerThunk[] = {
	{0x50644E, sizeof(codeSecondKillerThunk), codeSecondKillerThunk},
	{0x50644E, sizeof(codeSecondKillerOldThunk), codeSecondKillerOldThunk}};

//second killer interval
DWORD dwAddrSecondKillerInterval = dwAddrStackBottom + 0x65D0;
BYTE codeSecondKillerInterval[] = {
	0x50,                                     //push        eax
	0x8B, 0x43, 0x3C,                         //mov         eax,dword ptr [ebx+3Ch]
	0xF6, 0x40, 0x20, 0x01,                   //test        byte ptr [eax+20h],1
	0x75, 0x17,                               //jne         half_killer_interval
	0x8B, 0x96, 0xF8, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [esi+0F8h]
	0x8A, 0x43, 0x34,                         //mov         al,byte ptr [ebx+34h]
	0x3C, 0x1F,                               //cmp         al,1Fh
	0x7C, 0x0E,                               //jl          killer_on_earth
	0x3C, 0x22,                               //cmp         al,22h
	0x7E, 0x0F,                               //jle         normal
	0x80, 0x7A, 0x04, 0x18,                   //cmp         byte ptr [edx+4],18h
	0x74, 0x09,                               //je          normal
	                                          //half_killer_interval:
	0xB1, 0x02,                               //mov         cl,2
	0x58,                                     //pop         eax
	0xC3,                                     //ret
	                                          //killer_on_earth:
	0x38, 0x42, 0x04,                         //cmp         byte ptr [edx+4],al
	0x75, 0xF7,                               //jne         half_killer_interval
	                                          //normal:
	0xB1, 0x01,                               //mov         cl,1
	0x58,                                     //pop         eax
	0xC3                                      //ret
};

BYTE codeSecondKillerIntervalThunk[] = {0xE8, 0x46, 0x75, 0xBA, 0xFF};//dwAddrSecondKillerInterval - 4FF085h
BYTE codeSecondKillerIntervalOldThunk[] = {0xB9, 0x01, 0x00, 0x00, 0x00};//mov ecx,1
ASM_PATCH patchSecondKillerIntervalThunk[] = {
	{0x4FF085, sizeof(codeSecondKillerIntervalThunk), codeSecondKillerIntervalThunk},
	{0x4FF085, sizeof(codeSecondKillerIntervalOldThunk), codeSecondKillerIntervalOldThunk}};

//get person quota
DWORD dwAddrGetPersonQuota = dwAddrStackBottom + 0x25B0;
BYTE codeGetPersonQuota[] = {
	0x83, 0xC1, 0x08,                         //add         ecx,8
	0xB8, 0x40, 0xDB, 0x4B, 0x00,             //mov         4BDB40h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0x68, 0x90, 0x9C, 0x4A, 0x00,             //push        4A9C90h
	0xC3                                      //ret
};

BYTE codeGetPersonQuotaThunk[] = {0xE8, 0xF1, 0x87, 0xBF, 0xFF};//dwAddrGetPersonQuota - 4A9DBAh
BYTE codeGetPersonQuotaOldThunk[] = {0xE8, 0xD1, 0xFE, 0xFF, 0xFF};//call 4A9C90h()
ASM_PATCH patchGetPersonQuotaThunk[] = {
	{0x4A9DBA, sizeof(codeGetPersonQuotaThunk), codeGetPersonQuotaThunk},
	{0x4A9DBA, sizeof(codeGetPersonQuotaOldThunk), codeGetPersonQuotaOldThunk}};

//coordinate request
DWORD dwAddrCoordinateRequest = dwAddrStackBottom + 0x25C8;
BYTE codeCoordinateRequest[] = {
	0x3B, 0xB3, 0xB8, 0x00, 0x00, 0x00,       //cmp         esi,dword ptr [ebx+0B8h]
	0x74, 0x02,                               //je          test_request_goal
	0x40,                                     //inc         eax
	0xC3,                                     //ret
	                                          //test_request_goal:
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xE0, 0x01, 0x44, 0x00,             //mov         eax,4401E0h
	0xFF, 0xD0,                               //call        eax
	0x0F, 0xB7, 0xD0,                         //movzx       edx,ax
	0x52,                                     //push        edx
	0xC1, 0xE8, 0x10,                         //shr         eax,10h
	0x83, 0xF8, 0x05,                         //cmp         eax,5
	0x75, 0x07,                               //jne         test_goal_building
	0xB8, 0xB0, 0xD7, 0x46, 0x00,             //mov         eax,46D7B0h
	0xEB, 0x0C,                               //jmp         get_request_goal
	                                          //test_goal_building:
	0x83, 0xF8, 0x04,                         //cmp         eax,4
	0x74, 0x02,                               //je          request_goal_building
	0x59,                                     //pop         ecx
	0xC3,                                     //ret
	                                          //request_goal_building:
	0xB8, 0x60, 0xC8, 0x46, 0x00,             //mov         eax,46C860h
	                                          //get_request_goal:
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC0, 0x58,                         //add         eax,58h
	0xC3                                      //ret
};

BYTE codeCoordinateRequestThunk[] = {0xE8, 0x3C, 0xE4, 0xBE, 0xFF};//dwAddrCoordinateRequest - 4B4187h
BYTE codeCoordinateRequestOldThunk[] = {0xE8, 0x94, 0xC0, 0xF8, 0xFF};//call 440220h()
ASM_PATCH patchCoordinateRequestThunk[] = {
	{0x4B4187, sizeof(codeCoordinateRequestThunk), codeCoordinateRequestThunk},
	{0x4B4187, sizeof(codeCoordinateRequestOldThunk), codeCoordinateRequestOldThunk}};

//get anti attack garrison
DWORD dwAddrGetAntiAttackGarrison = dwAddrStackBottom + 0x6000;
BYTE codeGetAntiAttackGarrison[] = {
	                                          //get_anti_attack_garrison:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8B, 0x7C, 0x24, 0x14,                   //mov         edi,dword ptr [esp+14h]
	0xBB, 0x30, 0x75, 0x00, 0x00,             //mov         ebx,7530h
	0xBD, 0xB8, 0x0B, 0x00, 0x00,             //mov         ebp,0BB8h
	0x53,                                     //push        ebx
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x89, 0x6C, 0x24, 0x0C,                   //mov         dword ptr [esp+0Ch],ebp
	0x8B, 0x47, 0x0C,                         //mov         eax,dword ptr [edi+0Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x67,                               //je          skip_end_loop_attack_troop
	0x69, 0xC0, 0x88, 0x13, 0x00, 0x00,       //imul        eax,1388h
	0x03, 0xC5,                               //add         eax,ebp
	0x8B, 0x91, 0x88, 0x00, 0x00, 0x00,       //mov         edx,[ecx+88h]
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7E, 0x02,                               //jle         check_max_pre_garrison
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //check_max_pre_garrison:
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7E, 0x02,                               //jle         save_pre_garrison
	0x8B, 0xC3,                               //mov         eax,ebx
	                                          //save_pre_garrison:
	0x89, 0x04, 0x24,                         //mov         dword ptr [esp],eax
	0x8B, 0xF1,                               //mov         esi,ecx
	0x6A, 0x01,                               //push        1
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x90, 0x88, 0x00, 0x00, 0x00,       //call        dword ptr [eax+88h]
	0xD1, 0xE0,                               //shl         eax,1
	0x8B, 0x96, 0xC4, 0x00, 0x00, 0x00,       //mov         edx,dword ptr [esi+0C4h]
	0x0F, 0xAF, 0x42, 0x6C,                   //imul        eax,dword ptr [edx+6Ch]
	0xB9, 0x0F, 0x00, 0x00, 0x00,             //mov         ecx,0Fh
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xD8,                               //mov         ebx,eax
	0x0F, 0xB6, 0x05, 0x46, 0xA4, 0x49, 0x00, //movzx       eax,byte ptr [49A446h]
	0x66, 0xF7, 0x6E, 0x3C,                   //imul        word ptr [esi+3Ch]
	0xB1, 0x05,                               //mov         cl,5
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x03, 0xC3,                               //add         eax,ebx
	0x89, 0x44, 0x24, 0x04,                   //mov         dword ptr [esp+4],eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xD0, 0x53, 0x43, 0x00,             //mov         eax,4353D0h
	0xFF, 0xD0,                               //call        eax
	0x89, 0x44, 0x24, 0x08,                   //mov         dword ptr [esp+8],eax
	0x8B, 0x7F, 0x04,                         //mov         edi,dword ptr [edi+4]
	                                          //loop_attack_troop:
	0x85, 0xFF,                               //test        edi,edi
	                                          //skip_end_loop_attack_troop:
	0x0F, 0x84, 0x5D, 0x02, 0x00, 0x00,       //je          end_loop_attack_troop
	0x8B, 0x6F, 0x08,                         //mov         ebp,dword ptr [edi+8]
	0x8B, 0xCD,                               //mov         ecx,ebp
	0x56,                                     //push        esi
	0xB8, 0x70, 0x88, 0x46, 0x00,             //mov         eax,468870h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xE8, 0x02,                         //sub         eax,2
	0x80, 0x7E, 0x06, 0x05,                   //cmp         byte ptr [esi+6],5
	0x75, 0x01,                               //jne         get_arrive_day
	0x48,                                     //dec         eax
	                                          //get_arrive_day:
	0x33, 0xDB,                               //xor         ebx,ebx
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x03,                               //jg          test_false_state
	0x33, 0xC0,                               //xor         eax,eax
	0x43,                                     //inc         ebx
	                                          //test_false_state:
	0x8B, 0x55, 0x24,                         //mov         edx,dword ptr [ebp+24h]
	0x8B, 0x4D, 0x28,                         //mov         ecx,dword ptr [ebp+28h]
	0x80, 0xFA, 0x04,                         //cmp         dl,4
	0x75, 0x04,                               //jne         test_chaos_state
	0x03, 0xC1,                               //add         eax,ecx
	0x03, 0xC1,                               //add         eax,ecx
	                                          //test_chaos_state:
	0x80, 0xFA, 0x06,                         //cmp         dl,6
	0x75, 0x02,                               //jne         test_fighting_state
	0x03, 0xC1,                               //add         eax,ecx
	                                          //test_fighting_state:
	0x3C, 0x01,                               //cmp         al,1
	0x7E, 0x0F,                               //jle         save_arrive_day
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0x0B,                               //jne         save_arrive_day
	0xF7, 0x45, 0x20, 0x04, 0x00, 0x40, 0x00, //test        dword ptr [ebp+20h],400004h
	0x74, 0x02,                               //je          save_arrive_day
	0xD1, 0xE0,                               //shl         eax,1
	                                          //save_arrive_day:
	0x89, 0x44, 0x24, 0x14,                   //mov         dword ptr [esp+14h],eax
	0x2A, 0x05, 0x15, 0xFF, 0x43, 0x00,       //sub         al,[left_day]
	0xF6, 0xD8,                               //neg         al
	0x84, 0xC0,                               //test        al,al
	0x0F, 0x8E, 0xF9, 0x01, 0x00, 0x00,       //jle         next_attack_troop
	0x89, 0x44, 0x24, 0x10,                   //mov         dword ptr [esp+10h],eax
	0x33, 0xC0,                               //xor         eax,eax
	0x80, 0xFA, 0x05,                         //cmp         dl,5
	0x75, 0x0C,                               //jne         get_common_day
	0x8B, 0xC1,                               //mov         eax,ecx
	0x2B, 0x44, 0x24, 0x14,                   //sub         eax,dword ptr [esp+14h]
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         get_common_day
	0x33, 0xC0,                               //xor         eax,eax
	                                          //get_common_day:
	0x2B, 0x44, 0x24, 0x10,                   //sub         eax,dword ptr [esp+10h]
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x0F, 0x8E, 0xD4, 0x01, 0x00, 0x00,       //jle         next_attack_troop
	0x89, 0x44, 0x24, 0x18,                   //mov         dword ptr [esp+18h],eax
	0x6A, 0x01,                               //push        1
	0x8B, 0xCD,                               //mov         ecx,ebp
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x90, 0x88, 0x00, 0x00, 0x00,       //call        dword ptr [eax+88h]
	0x8B, 0xD8,                               //mov         ebx,eax
	0xC6, 0x44, 0x24, 0x1C, 0x00,             //mov         byte ptr [esp+1Ch],0
	0x80, 0x7C, 0x24, 0x08, 0x01,             //cmp         byte ptr [esp+8],1
	0x75, 0x17,                               //jne         troop_on_earth
	0x8B, 0xCD,                               //mov         ecx,ebp
	0xB8, 0x90, 0xE3, 0x45, 0x00,             //mov         eax,45E390h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0A,                               //je          troop_on_earth
	0x8B, 0x4D, 0x70,                         //mov         ecx,dword ptr [ebp+70h]
	0xC6, 0x44, 0x24, 0x1C, 0x01,             //mov         byte ptr [esp+1Ch],1
	0xEB, 0x03,                               //jmp         get_troop_to_garrison
	                                          //troop_on_earth:
	0x8B, 0x4D, 0x6C,                         //mov         ecx,dword ptr [ebp+6Ch]
	                                          //get_troop_to_garrison:
	0x8B, 0x41, 0x64,                         //mov         eax,dword ptr [ecx+64h]
	0x0F, 0xAF, 0xC3,                         //imul        eax,ebx
	0xD1, 0xE0,                               //shl         eax,1
	0xB9, 0x19, 0x00, 0x00, 0x00,             //mov         ecx,19h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x2B, 0x44, 0x24, 0x04,                   //sub         eax,dword ptr [esp+4]
	0x05, 0x84, 0x03, 0x00, 0x00,             //add         eax,384h
	0x0F, 0xAF, 0xC0,                         //imul        eax,eax
	0xC1, 0xE8, 0x0B,                         //shr         eax,0Bh
	0x8B, 0xD8,                               //mov         ebx,eax
	0x8B, 0x45, 0x30,                         //mov         eax,dword ptr [ebp+30h]
	0x03, 0x04, 0x24,                         //add         eax,dword ptr [esp]
	0x8B, 0x4C, 0x24, 0x18,                   //mov         ecx,[esp+18h]
	0x83, 0xE9, 0x2C,                         //sub         ecx,2Ch
	0xF7, 0xD9,                               //neg         ecx
	0x0F, 0xAF, 0xC1,                         //imul        eax,ecx
	0xB9, 0x4E, 0x0C, 0x00, 0x00,             //mov         ecx,C4Eh
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x05, 0x90, 0x01, 0x00, 0x00,             //add         eax,190h
	0x0F, 0xAF, 0xC3,                         //imul        eax,ebx
	0xB9, 0x58, 0x02, 0x00, 0x00,             //mov         ecx,258h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x0F, 0xAF, 0x44, 0x24, 0x18,             //imul        eax,[esp+18h]
	0x01, 0x44, 0x24, 0x0C,                   //add         dword ptr [esp+0Ch],eax
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xBD, 0x88, 0x00, 0x00, 0x00,       //mov         edi,dword ptr [ebp+88h]
	                                          //loop_troop_person:
	0x8B, 0x77, 0x08,                         //mov         esi,dword ptr [edi+8]
	0x80, 0x7C, 0x24, 0x2C, 0x00,             //cmp         byte ptr [esp+2Ch],0
	0x74, 0x24,                               //je          get_person_killer
	0x8B, 0x4D, 0x70,                         //mov         ecx,dword ptr [ebp+70h]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x14,                               //cmp         al,14h
	0x75, 0x04,                               //jne         test_boat_lou_chuan
	0x6A, 0x1F,                               //push        1Fh
	0xEB, 0x0A,                               //jmp         get_boat_killer
	                                          //test_boat_lou_chuan:
	0x3C, 0x16,                               //cmp         al,16h
	0x74, 0x04,                               //je          killer_jian_lan
	0x3C, 0x17,                               //cmp         al,17h
	0x75, 0x0E,                               //jne         get_person_killer
	                                          //killer_jian_lan:
	0x6A, 0x20,                               //push        20h
	                                          //get_boat_killer:
	0xB8, 0x20, 0x37, 0x45, 0x00,             //mov         eax,453720h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0xD8,                               //mov         ebx,eax
	0xEB, 0x25,                               //jmp         get_person_wound
	                                          //get_person_killer:
	0x8B, 0x9E, 0xF8, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [esi+0F8h]
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x4B,                               //je          skip_next_troop_person
	0x80, 0x7C, 0x24, 0x2C, 0x00,             //cmp         byte ptr [esp+2Ch],0
	0x74, 0x0B,                               //je          test_killer_to_building
	0x8A, 0x43, 0x54,                         //mov         al,byte ptr [ebx+54h]
	0x3C, 0x07,                               //cmp         al,7
	0x74, 0x04,                               //je          test_killer_to_building
	0x3C, 0x08,                               //cmp         al,8
	0x75, 0x39,                               //jne         skip_next_troop_person
	                                          //test_killer_to_building:
	0x80, 0xBB, 0x84, 0x00, 0x00, 0x00, 0x00, //cmp         byte ptr [ebx+84h],0
	0x74, 0x30,                               //je          skip_next_troop_person
	                                          //get_person_wound:
	0x8D, 0x8E, 0x80, 0x00, 0x00, 0x00,       //lea         ecx,[esi+80h]
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0x3B, 0x41, 0x18,                         //cmp         eax,dword ptr [ecx+18h]
	0x7D, 0x03,                               //jge         get_killer_day
	0x8B, 0x41, 0x18,                         //mov         eax,dword ptr [ecx+18h]
	                                          //get_killer_day:
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0A,                               //je          load_range_day
	0x2B, 0x44, 0x24, 0x24,                   //sub         eax,dword ptr [esp+24h]
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         load_range_day
	0x33, 0xC0,                               //xor         eax,eax
	                                          //load_range_day:
	0x2B, 0x44, 0x24, 0x20,                   //sub         eax,dword ptr [esp+20h]
	0xF7, 0xD8,                               //neg         eax
	0x8B, 0x54, 0x24, 0x28,                   //mov         edx,dword ptr [esp+28h]
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7E, 0x02,                               //jle         save_killer_day
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //save_killer_day:
	0x85, 0xC0,                               //test        eax,eax
	                                          //skip_next_troop_person:
	0x0F, 0x8E, 0x96, 0x00, 0x00, 0x00,       //jle         next_troop_person
	0x89, 0x44, 0x24, 0x04,                   //mov         dword ptr [esp+4],eax
	0x57,                                     //push        edi
	0x8B, 0x7B, 0x54,                         //mov         edi,dword ptr [ebx+54h]
	0x83, 0xFF, 0x04,                         //cmp         edi,4
	0x7E, 0x05,                               //jle         strength_killer
	0xFF, 0x76, 0x58,                         //push        dword ptr [esi+58h]
	0xEB, 0x03,                               //jmp         get_perform_ability
	                                          //strength_killer:
	0xFF, 0x76, 0x50,                         //push        dword ptr [esi+50h]
	                                          //get_perform_ability:
	0xB8, 0x00, 0xD3, 0x41, 0x00,             //mov         eax,41D300h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x83, 0xC0, 0x2D,                         //add         eax,2Dh
	0x83, 0xF8, 0x46,                         //cmp         eax,46h
	0x7D, 0x02,                               //jge         get_killer_proficiency
	0xB0, 0x46,                               //mov         al,46h
	                                          //get_killer_proficiency:
	0x50,                                     //push        eax
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x40, 0xC9, 0x44, 0x00,             //mov         eax,44C940h
	0xFF, 0xD0,                               //call        eax
	0xD1, 0xE8,                               //shr         eax,1
	0x05, 0xE8, 0x03, 0x00, 0x00,             //add         eax,3E8h
	0x5A,                                     //pop         edx
	0x0F, 0xAF, 0xC2,                         //imul        eax,edx
	0x83, 0xFF, 0x04,                         //cmp         edi,4
	0x7E, 0x10,                               //jle         get_killer_power
	0x0F, 0xB6, 0x4B, 0x04,                   //movzx       ecx,byte ptr [ebx+4]
	0x83, 0xE9, 0x17,                         //sub         ecx,17h
	0x0F, 0xB6, 0x91, 0xE7, 0xD8, 0x45, 0x00, //movzx       edx,byte ptr [ecx+map_killer_power]
	0xEB, 0x03,                               //jmp         get_killer_damage
	                                          //get_killer_power:
	0x8B, 0x53, 0x64,                         //mov         edx,dword ptr [ebx+64h]
	                                          //get_killer_damage:
	0x0F, 0xAF, 0xC2,                         //imul        eax,edx
	0xC1, 0xE8, 0x0A,                         //shr         eax,0Ah
	0x0F, 0xAF, 0x44, 0x24, 0x08,             //imul        eax,dword ptr [esp+8]
	0x83, 0xFF, 0x04,                         //cmp         edi,4
	0x74, 0x10,                               //je          get_row_coef
	0x8B, 0xF8,                               //mov         eax,edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0xCD, 0x44, 0x00,             //mov         eax,44CD00h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xE8, 0x04,                         //sub         eax,4
	0xF7, 0xD8,                               //neg         eax
	                                          //get_row_coef:
	0x0F, 0xAF, 0xC7,                         //imul        eax,edi
	0xB9, 0x28, 0x00, 0x00, 0x00,             //mov         ecx,28h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xF8,                               //mov         eax,edi
	0xFF, 0x75, 0x6C,                         //push        dword ptr [ebp+6Ch]
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x00, 0x31, 0x0A, 0x00,             //mov         eax,killer_array_coef
	0xFF, 0xD0,                               //call        eax
	0xF7, 0xEF,                               //imul        edi
	0xD1, 0xE2,                               //shl         edx,1
	0x5F,                                     //pop         edi
	0x01, 0x14, 0x24,                         //add         dword ptr [esp],edx
	                                          //next_troop_person:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x0F, 0x85, 0xD7, 0xFE, 0xFF, 0xFF,       //jne         loop_troop_person
	0x58,                                     //pop         eax
	0x59,                                     //pop         ecx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xBA, 0x40, 0x1F, 0x00, 0x00,             //mov         edx,1F40h
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7E, 0x02,                               //jle         add_killer_damage
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //add_killer_damage:
	0x01, 0x44, 0x24, 0x0C,                   //add         dword ptr [esp+0Ch],eax
	                                          //next_attack_troop:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0xE9, 0x9B, 0xFD, 0xFF, 0xFF,             //jmp         loop_attack_troop
	                                          //end_loop_attack_troop:
	0x8B, 0x44, 0x24, 0x0C,                   //mov         eax,dword ptr [esp+0Ch]
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0x5A,                                     //pop         edx
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7E, 0x02,                               //jle         test_min_door
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //test_min_door:
	0xBA, 0x70, 0x17, 0x00, 0x00,             //mov         edx,1770h
	0x3B, 0xC2,                               //cmp         eax,edx
	0x7D, 0x02,                               //jge         end
	0x8B, 0xC2,                               //mov         eax,edx
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

//killer array coef
DWORD dwAddrKillerArrayCoef = dwAddrStackBottom + 0x3100;
BYTE codeKillerArrayCoef[] = {
	                                          //killer_array_coef:
	0xB8, 0xCC, 0xCC, 0xCC, 0x0C,             //mov         eax,0CCCCCCCh
	0x8B, 0x51, 0x54,                         //mov         edx,dword ptr [ecx+54h]
	0x80, 0xFA, 0x04,                         //cmp         dl,4
	0x75, 0x06,                               //jne         test_strength_killer
	0x6B, 0xC0, 0x08,                         //imul        eax,eax,8
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_strength_killer:
	0x7C, 0x06,                               //jl          strength_killer
	                                          //no_match:
	0x6B, 0xC0, 0x05,                         //imul        eax,eax,5
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //strength_killer:
	0x8B, 0x4C, 0x24, 0x04,                   //mov         ecx,dword ptr [esp+4]
	0x80, 0xFA, 0x02,                         //cmp         dl,2
	0x75, 0x18,                               //jne         test_bow_killer
	0x8A, 0x51, 0x04,                         //mov         dl,byte ptr [ecx+4]
	0x80, 0xFA, 0x02,                         //cmp         dl,2
	0x74, 0x0A,                               //je          full_match
	0x80, 0xFA, 0x05,                         //cmp         dl,5
	0x74, 0x05,                               //je          full_match
	0x80, 0xFA, 0x10,                         //cmp         dl,10h
	0x75, 0xDF,                               //jne         no_match
	                                          //full_match:
	0x6B, 0xC0, 0x0A,                         //imul        eax,eax,0Ah
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_bow_killer:
	0x80, 0xFA, 0x03,                         //cmp         dl,3
	0x75, 0x14,                               //jne         test_horse_killer
	0x8A, 0x51, 0x04,                         //mov         dl,byte ptr [ecx+4]
	0x80, 0xFA, 0x04,                         //cmp         dl,4
	0x74, 0xED,                               //je          full_match
	0x80, 0xFA, 0x05,                         //cmp         dl,5
	0x74, 0xE8,                               //je          full_match
	0x80, 0xFA, 0x08,                         //cmp         dl,8
	0x74, 0xE3,                               //je          full_match
	0xEB, 0xC0,                               //jmp         no_match
	                                          //test_horse_killer:
	0x80, 0xFA, 0x01,                         //cmp         dl,1
	0x75, 0x19,                               //jne         foot_killer
	0x8A, 0x51, 0x04,                         //mov         dl,byte ptr [ecx+4]
	0x80, 0xFA, 0x02,                         //cmp         dl,2
	0x74, 0xD4,                               //je          full_match
	0x80, 0xFA, 0x03,                         //cmp         dl,3
	0x74, 0xCF,                               //je          full_match
	0x80, 0xFA, 0x10,                         //cmp         dl,10
	0x74, 0xCA,                               //je          full_match
	0x80, 0xFA, 0x11,                         //cmp         dl,11
	0x74, 0xC5,                               //je          full_match
	0xEB, 0xA2,                               //jmp         no_match
	                                          //foot_killer:
	0x8A, 0x51, 0x04,                         //mov         dl,byte ptr [ecx+4]
	0x80, 0xFA, 0x00,                         //cmp         dl,0
	0x74, 0xBB,                               //je          full_match
	0x80, 0xFA, 0x01,                         //cmp         dl,1
	0x74, 0xB6,                               //je          full_match
	0xEB, 0x93                                //jmp         no_match
};

//get array attack range
DWORD dwAddrGetArrayAttackRange = dwAddrStackBottom + 0x5380;
BYTE codeGetArrayAttackRange[] = {
	0x8A, 0x98, 0xE0, 0x1A, 0x0A, 0x00,       //mov         bl,byte ptr [eax+array_attack_range]
	0x83, 0xE8, 0x08,                         //sub         eax,8
	0x83, 0xF8, 0x12,                         //cmp         eax,12h
	0x77, 0x0E,                               //ja          set_terrain_flag
	0x8A, 0x80, 0x74, 0x31, 0x46, 0x00,       //mov         al,[463174h+eax]
	0x3C, 0x03,                               //cmp         al,3
	0x74, 0x0B,                               //je          set_boat_flag
	0x3C, 0x02,                               //cmp         al,2
	0x74, 0x0C,                               //je          end
	                                          //set_terrain_flag:
	0xC6, 0x44, 0x24, 0x14, 0x01,             //mov         byte ptr [esp+14h],1
	0xEB, 0x05,                               //jmp         end
	                                          //set_boat_flag:
	0xC6, 0x44, 0x24, 0x18, 0x01,             //mov         byte ptr [esp+18h],1
	                                          //end:
	0x68, 0x7C, 0x30, 0x46, 0x00,             //push        46307Ch
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeGetArrayAttackRangeThunk[] = {0xE8, 0x3B, 0x23, 0xC4, 0xFF, 0x40};//dwAddrGetArrayAttackRange - 463040h
BYTE codeGetArrayAttackRangeOldThunk[] = {0x83, 0xC0, 0xF8, 0x83, 0xF8, 0x12};//add eax,-8;cmp eax,12h
ASM_PATCH patchGetArrayAttackRangeThunk[] = {
	{0x463040, sizeof(codeGetArrayAttackRangeThunk), codeGetArrayAttackRangeThunk},
	{0x463040, sizeof(codeGetArrayAttackRangeOldThunk), codeGetArrayAttackRangeOldThunk}};

//get near building soldier
DWORD dwAddrGetNearBuildingSoldier = dwAddrStackBottom + 0x698C;
BYTE codeGetNearBuildingSoldier[] = {
	                                          //get_near_building_soldier:
	0x56,                                     //push        esi
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0x70, 0xC9, 0x46, 0x00,             //mov         eax,46C970h
	0xFF, 0xD0,                               //call        eax
	0x53,                                     //push        ebx
	0x50,                                     //push        eax
	0xB8, 0x40, 0x5C, 0x47, 0x00,             //mov         eax,475C40h
	0xFF, 0xD0,                               //call        eax
	0x33, 0xF6,                               //xor         esi,esi
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_near_building:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x81, 0xCC, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0CCh]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x32,                               //je          next_near_building
	0x39, 0xA8, 0xB8, 0x00, 0x00, 0x00,       //cmp         dword ptr [eax+0B8h],ebp
	0x75, 0x2A,                               //jne         next_near_building
	0x8B, 0x81, 0x88, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+88h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x20,                               //je          next_near_building
	0x50,                                     //push        eax
	0x53,                                     //push        ebx
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x83, 0xF8, 0x4B,                         //cmp         eax,4Bh
	0x5A,                                     //pop         edx
	0x7F, 0x11,                               //jg          next_near_building
	0x83, 0xE8, 0x50,                         //sub         eax,50h
	0xF7, 0xD8,                               //neg         eax
	0xF7, 0xEA,                               //imul        edx
	0xB9, 0x3C, 0x00, 0x00, 0x00,             //mov         ecx,3Ch
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x03, 0xF0,                               //add         esi,eax
	                                          //next_near_building:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xBB,                               //jne         loop_near_building
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x020,                        //add         esp,20h
	0x8B, 0xC6,                               //mov         eax,esi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// war fog  ////////////////////////////////////////////////

//display troop condition
DWORD dwAddrDisplayTroopCondition = dwAddrStackBottom + 0x7200;
BYTE codeDisplayTroopCondition[] = {
	0x89, 0x41, 0x50,                         //mov         dword ptr [ecx+50h],eax
	0x58,                                     //pop         eax
	0x5A,                                     //pop         edx
	0x50,                                     //push        eax
	0x53,                                     //push        ebx
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x02,                               //jne         check_player_force
	                                          //end:
	0x5B,                                     //pop         ebx
	0xC3,                                     //ret
	                                          //check_player_force:
	0x8B, 0x88, 0xBC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0BCh]
	0x8D, 0x59, 0x10,                         //lea         ebx,[ecx+10h]
	0x8D, 0x46, 0x68,                         //lea         eax,[esi+68h]
	0x50,                                     //push        eax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x20, 0x63, 0x0A, 0x00,             //mov         eax,compare_person_name
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xE4,                               //je          end
	0xFF, 0x36,                               //push        dword ptr [esi]
	0xB8, 0xC0, 0x32, 0x45, 0x00,             //mov         eax,4532C0h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x80, 0x3D, 0x15, 0xFF, 0x43, 0x00, 0x0A, //cmp         byte ptr[left_day],0Ah
	0x7C, 0x0C,                               //jl          check_troop_date
	0x8B, 0x40, 0x48,                         //mov         eax,dword ptr [eax+48h]
	0x85, 0xC0,                               //test        eax,eax
	0x7E, 0x15,                               //jle         non_player_troop
	0x88, 0x47, 0x2F,                         //mov         byte ptr [edi+2Fh],al
	0xEB, 0x0A,                               //jmp         hide_troop
	                                          //check_troop_date:
	0x8A, 0x47, 0x2F,                         //mov         al,byte ptr [edi+2Fh]
	0x84, 0xC0,                               //test        al,al
	0x7E, 0x09,                               //jle         non_player_troop
	0xFE, 0x4F, 0x2F,                         //dec         byte ptr [edi+2Fh]
	                                          //hide_troop:
	0x80, 0x66, 0x28, 0xFE,                   //and         byte ptr[esi+28h],0FEh
	0x5B,                                     //pop         ebx
	0xC3,                                     //ret
											  //non_player_troop:
	0xB8, 0x80, 0x72, 0x0A, 0x00,			  //mov         eax,test_player_view_range
	0xFF, 0xD0,								  //call        eax
	0x85, 0xC0,								  //test        eax,eax
	0x74, 0xEF,								  //je          hide_troop
	0x5B,                                     //pop         ebx
	0xC3,                                     //ret

};

BYTE codeDisplayTroopConditionThunk[] = {0xE8, 0xE3, 0x76, 0xB7, 0xFF};//dwAddrDisplayTroopCondition - 52FB18h
BYTE codeDisplayTroopConditionOldThunk[] = {0xE8, 0x03, 0x7F, 0xF1, 0xFF};//call 447A20h()
ASM_PATCH patchDisplayTroopConditionThunk[] = {
	{0x52FB18, sizeof(codeDisplayTroopConditionThunk), codeDisplayTroopConditionThunk},
	{0x52FB18, sizeof(codeDisplayTroopConditionOldThunk), codeDisplayTroopConditionOldThunk}};

//test player view range
DWORD dwAddrTestPlayerViewRange = dwAddrStackBottom + 0x7280;
BYTE codeTestPlayerViewRange[] = {
	                                          //test_player_view_range:
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0xBF, 0xE4, 0x5E, 0x54, 0x01,             //mov         edi,1545EE4h
	0x33, 0xED,                               //xor         ebp,ebp
	                                          //loop_display_info:
	0x8D, 0x47, 0x38,                         //lea         eax,[edi+38h]
	0x50,                                     //push        eax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x20, 0x63, 0x0A, 0x00,             //mov         eax,compare_person_name
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x36,                               //jne         next_display_info
	0xB4, 0x04,								  //mov         ah,4
	0xB9, 0x87, 0xF8, 0x43, 0x00,			  //mov         ecx,fog_view_range
	0x81, 0xFD, 0xFA, 0x00, 0x00, 0x00,		  //cmp         ebp,0FAh
	0x7D, 0x0B,								  //jge         check_min_soldier
	0xB4, 0x04,								  //mov         ah,4
	0x41,									  //inc         ecx
	0x83, 0xFD, 0x32,						  //cmp         ebp,32h
	0x7D, 0x03,								  //jge         check_min_soldier
	0xB4, 0x04,								  //mov         ah,4
	0x41,									  //inc         ecx
											  //check_min_soldier:
	0x39, 0x47, 0x10,		                  //cmp         dword ptr [edi+10h],eax
	0x7C, 0x17,                               //jl          next_display_info
	0x51,									  //push        ecx
	0x8D, 0x47, 0x08,                         //lea         eax,[edi+8]
	0x50,                                     //push        eax
	0x8D, 0x4E, 0x04,                         //lea         ecx,[esi+4]
	0xB8, 0x00, 0x6C, 0x0A, 0x00,             //mov         eax,get_info_distance
	0xFF, 0xD0,                               //call        eax
	0x59,									  //pop         ecx
	0x0F, 0xB6, 0x11,						  //movzx       edx,byte ptr[ecx]
	0x3B, 0xC2,								  //cmp         eax,edx
	0x7E, 0x1E,                               //jle         ok
	                                          //next_display_info:
	0x81, 0xC7, 0x80, 0x00, 0x00, 0x00,       //add         edi,80h
	0x81, 0xFD, 0xFA, 0x00, 0x00, 0x00,       //cmp         ebp,0FAh
	0x7C, 0x03,                               //jl          inc_info_count
	0x83, 0xC7, 0x10,                         //add         edi,10h
	                                          //inc_info_count:
	0x45,                                     //inc         ebp
	0x81, 0xFD, 0x4C, 0x04, 0x00, 0x00,       //cmp         ebp,44Ch
	0x7C, 0x9F,                               //jl          loop_display_info
	0x33, 0xC0,								  //xor         eax,eax
	0xEB, 0x04,								  //jmp         end
	                                          //ok:
	0x8B, 0x47, 0x04,						  //mov         eax,[edi+4]
	0x40,									  //inc         eax
											  //end:
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0xC3                                      //ret
};

//compare person name
DWORD dwAddrComparePersonName = dwAddrStackBottom + 0x6320;
BYTE codeComparePersonName[] = {
	                                          //compare_person_name:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x74, 0x24, 0x0C,                   //mov         esi,dword ptr [esp+0Ch]
	                                          //loop_compare_name:
	0x8A, 0x06,                               //mov         al,byte ptr [esi]
	                                          //get_person_name:
	0x8A, 0x11,                               //mov         dl,[ecx]
	0x80, 0xFA, 0x00,                         //cmp         dl,0
	0x75, 0x09,                               //jne         compare_byte
	0x80, 0xFB, 0x05,                         //cmp         bl,5
	0x7D, 0x04,                               //jge         compare_byte
	0x41,                                     //inc         ecx
	0x43,                                     //inc         ebx
	0xEB, 0xF0,                               //jmp         get_person_name	
	                                          //compare_byte:
	0x3A, 0xC2,                               //cmp         al,dl
	0x75, 0x10,                               //jne         fail
	0x3C, 0x00,                               //cmp         al,0
	0x74, 0x08,                               //je          success
	0x46,                                     //inc         esi
	0x41,                                     //inc         ecx
	0x43,                                     //inc         ebx
	0x80, 0xFB, 0x09,                         //cmp         bl,9
	0x7C, 0xDE,                               //jl          loop_compare_name
	                                          //success:
	0x33, 0xC0,                               //xor         eax,eax
	0xEB, 0x02,                               //jmp         end
	                                          //fail:
	0xB0, 0x01,                               //mov         al,1
	                                          //end:
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

//check_player_view_range
DWORD dwAddrCheckPlayerViewRange = dwAddrStackBottom + 0x6360;
BYTE codeCheckPlayerViewRange[] = {
	                                          //check_player_view_range:
	0x56,                                     //push        esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x04,                               //jne         check_troop_force
	                                          //inside_player_view_range:
	0xB0, 0x01,                               //mov         al,1
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //check_troop_force:
	0x8B, 0x4E, 0x74,                         //mov         ecx,dword ptr [esi+74h]
	0x85, 0xC9,                               //test        ecx,ecx
	0x75, 0x04,                               //jne         compare_troop_force
	                                          //outside_player_view_range:
	0x33, 0xC0,                               //xor         eax,eax
	0x5E,                                     //pop         esi
	0xC3,                                     //ret
	                                          //compare_troop_force:
	0x39, 0x81, 0xB8, 0x00, 0x00, 0x00,       //cmp         dword ptr [ecx+0B8h],eax
	0x74, 0xE9,                               //je          inside_player_view_range
	0x83, 0x7E, 0x48, 0x00,                   //cmp         dword ptr [esi+48h],0
	0x7F, 0xEE,                               //jg          outside_player_view_range
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0xE8,                               //mov         ebp,eax
	0xF6, 0x46, 0x20, 0x01,                   //test        byte ptr [esi+20h],1
	0x74, 0x03,                               //je          loop_full_troop
	0x8B, 0x76, 0x64,						  //mov         esi,[esi+64h]
	                                          //loop_full_troop:
	0x57,                                     //push        edi
	0xB8, 0xF0, 0x3C, 0x47, 0x00,             //mov         eax,473CF0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x48, 0x74,                         //mov         ecx,dword ptr [eax+74h]
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x3D,                               //je          next_full_troop
	0x39, 0xA9, 0xB8, 0x00, 0x00, 0x00,       //cmp         dword ptr [ecx+0B8h],ebp
	0x75, 0x35,                               //jne         next_full_troop
	0x33, 0xDB,								  //xor         ebx,ebx
	0xB7, 0x04,								  //mov         bh,4
	0xBA, 0x87, 0xF8, 0x43, 0x00,             //mov         edx,fog_view_range
	0x8B, 0xC8,								  //mov         ecx,eax
	0x81, 0xFF, 0xFA, 0x00, 0x00, 0x00,		  //cmp         edi,0FAh
	0x7D, 0x0E,								  //jge         check_min_soldier
	0x8B, 0x48, 0x64,						  //mov         ecx,[eax+64h]
	0xB7, 0x04,								  //mov         bh,4
	0x42,									  //inc         edx
	0x83, 0xFF, 0x32,						  //cmp         edi,32h
	0x7D, 0x03,								  //jge         check_min_soldier
	0xB7, 0x04,								  //mov         bh,4
	0x42,									  //inc         edx
											  //check_min_soldier:
	0x39, 0x58, 0x30,						  //cmp         dword ptr [eax+30h],ebx
	0x7C, 0x0F,                               //jl          next_full_troop
	0x0F, 0xB6, 0x1A,                         //movzx       ebx,byte ptr[edx]
	0x56,                                     //push        esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7E, 0x0D,                               //jle         normal
	                                          //next_full_troop:
	0x47,                                     //inc         edi
	0x81, 0xFF, 0x4C, 0x04, 0x00, 0x00,       //cmp         edi,44Ch
	0x7C, 0xAB,                               //jl          loop_full_troop
	0x33, 0xC0,                               //xor         eax,eax
	0xEB, 0x02,                               //jmp         end
	                                          //normal:
	0xB0, 0x01,                               //mov         al,1
	                                          //end:
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//person small dialog
DWORD dwAddrPersonSmallDialog = dwAddrStackBottom + 0x64F0;
BYTE codePersonSmallDialog[] = {
	0x50,                                     //push        eax
	0x8B, 0x4C, 0x24, 0x14,                   //mov         ecx,[esp+14h]
	0xB8, 0x60, 0x63, 0x0A, 0x00,             //mov         eax,check_player_view_range
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xC8,                               //mov         ecx,eax
	0x58,                                     //pop         eax
	0xC3,                                     //ret
};

BYTE codePersonSmallDialogThunk[] = {0xE8, 0x1F, 0x2B, 0xC7, 0xFF, 0x42};//dwAddrPersonSmallDialog - 4339CCh
BYTE codePersonSmallDialogOldThunk[] = {0x8B, 0x0D, 0x3C, 0x83, 0x22, 0x01};//mov ecx,[122833Ch]
ASM_PATCH patchPersonSmallDialogThunk[] = {
	{0x4339CC, sizeof(codePersonSmallDialogThunk), codePersonSmallDialogThunk},
	{0x4339CC, sizeof(codePersonSmallDialogOldThunk), codePersonSmallDialogOldThunk}};

//troop at small map
DWORD dwAddrTroopAtSmallMap = dwAddrStackBottom + 0x6500;
BYTE codeTroopAtSmallMap[] = {
	0xB8, 0x70, 0x3B, 0x46, 0x00,             //mov         eax,463B70h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x01,                               //jne         test_troop_view_state
	0xC3,                                     //ret
	                                          //test_troop_view_state:
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x20, 0x5D, 0x0A, 0x00,             //mov         eax,get_troop_view_state
	0xFF, 0xD0,                               //call        eax
	0xC3                                      //ret
};

BYTE codeTroopAtSmallMapThunk[] = {0xE8, 0x1C, 0x4A, 0xB1, 0xFF};//dwAddrTroopAtSmallMap - 591ADFh
BYTE codeTroopAtSmallMapOldThunk[] = {0xE8, 0x8C, 0x20, 0xED, 0xFF};//call 463B70h()
ASM_PATCH patchTroopAtSmallMapThunk[] = {
	{0x591ADF, sizeof(codeTroopAtSmallMapThunk), codeTroopAtSmallMapThunk},
	{0x591ADF, sizeof(codeTroopAtSmallMapOldThunk), codeTroopAtSmallMapOldThunk}};

//get troop view state
DWORD dwAddrGetTroopViewState = dwAddrStackBottom + 0x5D20;
BYTE codeGetTroopViewState[] = {
	                                          //get_troop_view_state:
	0x0F, 0xB7, 0x41, 0x04,                   //movzx       eax,word ptr [ecx+4]
	0x69, 0xC0, 0x90, 0x00, 0x00, 0x00,       //imul        eax,eax,90h
	0x05, 0xE4, 0xDB, 0x54, 0x01,             //add         eax,154DBE4h
	0x33, 0xC9,                               //xor         ecx,ecx
	0xF6, 0x40, 0x20, 0x01,                   //test        byte ptr [eax+20h],1
	0x0F, 0x95, 0xC1,                         //setne       cl
	0x8B, 0xC1,                               //mov         eax,ecx
	0xC3                                      //ret
};

//journey goal troop
DWORD dwAddrJourneyGoalTroop = dwAddrStackBottom + 0x6AE0;
BYTE codeJourneyGoalTroop[] = {
	0xFF, 0x74, 0x24, 0x04,                   //push        dword ptr[esp+4]
	0xB8, 0xB0, 0xE1, 0x45, 0x00,             //mov         eax,45E1B0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0B,                               //jne         end
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x20, 0x5D, 0x0A, 0x00,             //mov         eax,get_troop_view_state
	0xFF, 0xD0,                               //call        eax
	0x34, 0x01,                               //xor         al,1
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeJourneyGoalTroopThunk[] = {0xE8, 0x1D, 0x60, 0xC3, 0xFF};//dwAddrJourneyGoalTroop - 470ABEh
BYTE codeJourneyGoalTroopOldThunk[] = {0xE8, 0xED, 0xD6, 0xFE, 0xFF};//call 45E1B0h()
ASM_PATCH patchJourneyGoalTroopThunk[] = {
	{0x470ABE, sizeof(codeJourneyGoalTroopThunk), codeJourneyGoalTroopThunk},
	{0x470ABE, sizeof(codeJourneyGoalTroopOldThunk), codeJourneyGoalTroopOldThunk}};
BYTE codeJourneyGoalTroop2Thunk[] = {0xE8, 0xEC, 0x5E, 0xC3, 0xFF};//dwAddrJourneyGoalTroop - 470BEFh
BYTE codeJourneyGoalTroop2OldThunk[] = {0xE8, 0xBC, 0xD5, 0xFE, 0xFF};//call 45E1B0h()
ASM_PATCH patchJourneyGoalTroop2Thunk[] = {
	{0x470BEF, sizeof(codeJourneyGoalTroop2Thunk), codeJourneyGoalTroop2Thunk},
	{0x470BEF, sizeof(codeJourneyGoalTroop2OldThunk), codeJourneyGoalTroop2OldThunk}};

//get info distance
DWORD dwAddrGetInfoDistance = dwAddrStackBottom + 0x6C00;
BYTE codeGetInfoDistance[] = {
		                                      //get_info_distance:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x8B, 0x31,                               //mov         esi,dword ptr [ecx]
	0x81, 0xEE, 0x00, 0x19, 0x00, 0x00,       //sub         esi,1900h
	0x6B, 0xF6, 0x0A,                         //imul        esi,esi,0Ah
	0xC1, 0xFE, 0x06,                         //sar         esi,6
	0x8B, 0x79, 0x04,                         //mov         edi,dword ptr [ecx+4]
	0x6B, 0xFF, 0x0A,                         //imul        edi,edi,0Ah
	0xC1, 0xEF, 0x05,                         //shr         edi,5
	0x4F,                                     //dec         edi
	0x8B, 0xC6,                               //mov         eax,esi
	0x03, 0xC7,                               //add         eax,edi
	0xD1, 0xE8,                               //shr         eax,1
	0x2B, 0xFE,                               //sub         edi,esi
	0xD1, 0xEF,                               //shr         edi,1
	0x8B, 0xF0,                               //mov         esi,eax
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,dword ptr [esp+0Ch]
	0x8B, 0x11,                               //mov         edx,dword ptr [ecx]
	0x81, 0xEA, 0x00, 0x19, 0x00, 0x00,       //sub         edx,1900h
	0x6B, 0xD2, 0x0A,                         //imul        edx,edx,0Ah
	0xC1, 0xFA, 0x06,                         //sar         edx,6
	0x8B, 0x49, 0x04,                         //mov         ecx,dword ptr [ecx+4]
	0x6B, 0xC9, 0x0A,                         //imul        ecx,ecx,0Ah
	0xC1, 0xE9, 0x05,                         //shr         ecx,5
	0x49,                                     //dec         ecx
	0x8B, 0xC2,                               //mov         eax,edx
	0x03, 0xC1,                               //add         eax,ecx
	0xD1, 0xE8,                               //shr         eax,1
	0x2B, 0xCA,                               //sub         ecx,edx
	0xD1, 0xE9,                               //shr         ecx,1
	0x2B, 0xC6,                               //sub         eax,esi
	0x0F, 0xAF, 0xC0,                         //imul        eax,eax
	0x2B, 0xCF,                               //sub         ecx,edi
	0x0F, 0xAF, 0xC9,                         //imul        ecx,ecx
	0x03, 0xC1,                               //add         eax,ecx
	0x3D, 0x00, 0x64, 0x00, 0x00,             //cmp         eax,6400h
	0x7F, 0x08,                               //jg          end
	0x50,                                     //push        eax
	0xFF, 0x15, 0x1C, 0xF3, 0x5F, 0x00,       //call        [5FF31Ch]
	0x5A,                                     //pop         edx
	                                          //end:
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

//false goal troop
DWORD dwAddrFalseGoalTroop = dwAddrStackBottom + 0x6AC0;
BYTE codeFalseGoalTroop[] = {
	0x56,                                     //push        esi
	0xB8, 0xA0, 0x1E, 0x44, 0x00,             //mov         eax,441EA0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0B,                               //jne         end
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x20, 0x5D, 0x0A, 0x00,             //mov         eax,get_troop_view_state
	0xFF, 0xD0,                               //call        eax
	0x34, 0x01,                               //xor         al,1
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

//false goal troop
BYTE codeFalseGoalTroopThunk[] = {0xE8, 0x48, 0x1C, 0xC3, 0xFF};//dwAddrFalseGoalTroop - 474E73h
BYTE codeFalseGoalTroopOldThunk[] = {0xE8, 0x28, 0xD0, 0xFC, 0xFF};//call 441EA0h()
ASM_PATCH patchFalseGoalTroopThunk[] = {
	{0x474E73, sizeof(codeFalseGoalTroopThunk), codeFalseGoalTroopThunk},
	{0x474E73, sizeof(codeFalseGoalTroopOldThunk), codeFalseGoalTroopOldThunk}};
//disorder goal troop
BYTE codeDisorderGoalTroopThunk[] = {0xE8, 0xE2, 0x1A, 0xC3, 0xFF};//dwAddrDisorderGoalTroop - 474FD9h
BYTE codeDisorderGoalTroopOldThunk[] = {0xE8, 0xC2, 0xCE, 0xFC, 0xFF};//call 441EA0h()
ASM_PATCH patchDisorderGoalTroopThunk[] = {
	{0x474FD9, sizeof(codeDisorderGoalTroopThunk), codeDisorderGoalTroopThunk},
	{0x474FD9, sizeof(codeDisorderGoalTroopOldThunk), codeDisorderGoalTroopOldThunk}};

//display building condition
DWORD dwAddrDisplayBuildingCondition = dwAddrStackBottom + 0x6D00;
BYTE codeDisplayBuildingCondition[] = {
	0x8B, 0xF9,                               //mov         edi,ecx
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x07,                               //jne         check_player_force
	                                          //end:
	0x8B, 0x56, 0x50,                         //mov         edx,[esi+50h]
	0x8B, 0x4E, 0x54,                         //mov         ecx,[esi+54h]
	0xC3,                                     //ret
	                                          //check_player_force:
	0x53,                                     //push        ebx
	0x8B, 0x88, 0xBC, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+0BCh]
	0x8D, 0x59, 0x10,                         //lea         ebx,[ecx+10h]
	0x8D, 0x46, 0x58,                         //lea         eax,[esi+58h]
	0x50,                                     //push        eax
	0x8B, 0xCB,                               //mov         ecx,ebx
	0xB8, 0x20, 0x63, 0x0A, 0x00,             //mov         eax,compare_person_name
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x03,                               //jne         non_player_building
	                                          //end2:
	0x5B,                                     //pop         ebx
	0xEB, 0xDB,                               //jmp         end
	                                          //non_player_building:
	0xC6, 0x46, 0x54, 0x00,                   //mov         byte ptr [esi+54h],0
	0xB8, 0x80, 0x72, 0x0A, 0x00,			  //mov         eax,test_player_view_range
	0xFF, 0xD0,								  //call        eax
	0x85, 0xC0,								  //test        eax,eax
	0x75, 0x3C,								  //jne         light_building
	0x33, 0xC0,                               //xor         eax,eax
	0x89, 0x46, 0x0C,                         //mov         [esi+0Ch],eax
	0x89, 0x46, 0x74,                         //mov         [esi+74h],eax
	0x66, 0x8B, 0x46, 0x16,                   //mov         ax,[esi+16h]
	0x66, 0x89, 0x46, 0x14,                   //mov         [esi+14h],ax
	0x80, 0x4E, 0x34, 0x88,                   //or          byte ptr [esi+34h],88h
	//0x80, 0x66, 0x34, 0xFD,                   //and         byte ptr [esi+34h],0FDh
	0x80, 0x66, 0x34, 0xFF,                   //and         byte ptr [esi+34h],0FFh
	0xC6, 0x46, 0x50, 0x01,                   //mov         byte ptr [esi+50h],1
	0xF6, 0x47, 0x20, 0x08,                   //test        byte ptr[edi+20h],8
	0x75, 0x18,                               //jne         skip_jmp_end2
	                                          //update_display:
	0x80, 0x77, 0x20, 0x08,                   //xor         byte ptr[edi+20h],8
	0x8B, 0x0D, 0x41, 0xF4, 0x43, 0x00,       //mov         ecx,[troop_display_object]
	0x85, 0xC9,								  //test        ecx,ecx
	0x7C, 0x0A,                               //jl          skip_jmp_end2
	0x6A, 0x01,                               //push        1
	0x57,                                     //push        edi
	0xB8, 0xA0, 0x2C, 0x53, 0x00,             //mov         eax,532CA0h
	0xFF, 0xD0,                               //call        eax
	                                          //skip_jmp_end2:
	0xEB, 0xB2,					              //jmp         end2
	                                          //light_building:
	0x8B, 0x16,                               //mov         edx,dword ptr [esi]
	0x42,                                     //inc         edx
	0xF7, 0xEA,                               //imul        edx
	0x0F, 0xB6, 0x15, 0x14, 0xFF, 0x43, 0x00, //movzx       edx,byte ptr [quarter]
	0x42,                                     //inc         edx
	0xF7, 0xEA,                               //imul        edx
	0x8B, 0xD8,                               //mov         ebx,eax
	0x0F, 0xB6, 0x0D, 0x8A, 0xF8, 0x43, 0x00, //movzx       ecx,byte ptr [fog_soldier_error]
	0x41,                                     //inc         ecx
	0x99,                                     //cdq
	0xF7, 0xF9,                               //idiv        eax,ecx
	0x8B, 0xC2,                               //mov         eax,edx
	0xF7, 0x6E, 0x0C,                         //imul        dword ptr [esi+0Ch]
	0x99,                                     //cdq
	0xB9, 0x64, 0x00, 0x00, 0x00,             //mov         ecx,64h
	0xF7, 0xF9,                               //idiv        eax,ecx
	0xF6, 0xC3, 0x01,                         //test        bl,1
	0x74, 0x02,                               //je          get_random_soldier
	0xF7, 0xD8,                               //neg         eax
	                                          //get_random_soldier:
	0x01, 0x46, 0x0C,                         //add         dword ptr [esi+0Ch],eax
	0xF6, 0x47, 0x20, 0x08,                   //test        byte ptr[edi+20h],8
	0x75, 0xAD,                               //jne         update_display
	0xEB, 0xC3                                //jmp         skip_jmp_end2
};

BYTE codeDisplayBuildingConditionThunk[] = {0xE8, 0x92, 0x85, 0xB7, 0xFF};//dwAddrDisplayBuildingCondition - 52E769h
BYTE codeDisplayBuildingConditionOldThunk[] = {0x8B, 0xF9, 0x8B, 0x4E, 0x54};//mov edi,ecx;mov ecx,[esi+54h]
ASM_PATCH patchDisplayBuildingConditionThunk[] = {
	{0x52E769, sizeof(codeDisplayBuildingConditionThunk), codeDisplayBuildingConditionThunk},
	{0x52E769, sizeof(codeDisplayBuildingConditionOldThunk), codeDisplayBuildingConditionOldThunk}};

//get building view state
DWORD dwAddrGetBuildingViewState = dwAddrStackBottom + 0x4EE0;
BYTE codeGetBuildingViewState[] = {
	                                          //get_building_view_state:
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x69, 0xC0, 0x80, 0x00, 0x00, 0x00,       //imul        eax,eax,80h
	0x05, 0xE4, 0x5E, 0x54, 0x01,             //add         eax,1545EE4h
	0x33, 0xC9,                               //xor         ecx,ecx
	0xF6, 0x40, 0x20, 0x80,                   //test        byte ptr [eax+20h],80h
	0x0F, 0x94, 0xC1,                         //sete        cl
	0x8B, 0xC1,                               //mov         eax,ecx
	0xC3                                      //ret
};

//hide duty person num
DWORD dwAddrHideDutyPersonNum = dwAddrStackBottom + 0x6F90;
BYTE codeHideDutyPersonNum[] = {
	0x51,                                     //push        ecx
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,									  //pop         ecx
	0x74, 0x2B,                               //je          normal
	0x51,                                     //push        ecx
	0x50,                                     //push        eax
	0xB8, 0x40, 0x57, 0x43, 0x00,             //mov         eax,435740h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,									  //pop         ecx
	0x75, 0x1D,                               //jne         normal
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x50, 0x0C,                         //call        dword ptr [eax+0Ch]
	0x69, 0xC0, 0x80, 0x00, 0x00, 0x00,       //imul        eax,eax,80h
	0x05, 0xE4, 0x5E, 0x54, 0x01,             //add         eax,1545EE4h
	0x8B, 0x40, 0x7C,						  //mov         eax,[eax+7Ch]
	0x8B, 0x4C, 0x24, 0x04,					  //mov         ecx,[esp+4]
	0x89, 0x41, 0x0C,						  //mov         [ecx+0Ch],eax
	0xC2, 0x0C, 0x00,                         //ret         0Ch
	                                          //normal:
	0x68, 0x60, 0x6D, 0x43, 0x00,             //push        436D60h
	0xC3                                      //ret
};

//city float window
BYTE codeHideDutyPersonNumThunk[] = {0xE8, 0xDC, 0xE2, 0xB7, 0xFF};//dwAddrHideDutyPersonNum - 528CAFh
BYTE codeHideDutyPersonNumOldThunk[] = {0xE8, 0xAC, 0xE0, 0xF0, 0xFF};//call 436D60h()
ASM_PATCH patchHideDutyPersonNumThunk[] = {
	{0x528CAF, sizeof(codeHideDutyPersonNumThunk), codeHideDutyPersonNumThunk},
	{0x528CAF, sizeof(codeHideDutyPersonNumOldThunk), codeHideDutyPersonNumOldThunk}};
//building float window
BYTE codeHideDutyPersonNum2Thunk[] = {0xE8, 0x71, 0xDA, 0xB7, 0xFF};//dwAddrHideDutyPersonNum - 52951Ah
BYTE codeHideDutyPersonNum2OldThunk[] = {0xE8, 0x41, 0xD8, 0xF0, 0xFF};//call 436D60h()
ASM_PATCH patchHideDutyPersonNum2Thunk[] = {
	{0x52951A, sizeof(codeHideDutyPersonNum2Thunk), codeHideDutyPersonNum2Thunk},
	{0x52951A, sizeof(codeHideDutyPersonNum2OldThunk), codeHideDutyPersonNum2OldThunk}};

//save troop display object
BYTE codeSaveTroopDisplayObjectThunk[] = {0x89, 0x3D, 0x41, 0xF4, 0x43, 0x00, 0x90, 0x90};
											//mov [troop_display_object], edi
BYTE codeSaveTroopDisplayObjectOldThunk[] = {0xEB, 0x06, 0x8D, 0x9B, 0x00, 0x00, 0x00, 0x00};//jmp 533790h
ASM_PATCH patchSaveTroopDisplayObjectThunk[] = {
	{0x533788, sizeof(codeSaveTroopDisplayObjectThunk), codeSaveTroopDisplayObjectThunk},
	{0x533788, sizeof(codeSaveTroopDisplayObjectOldThunk), codeSaveTroopDisplayObjectOldThunk}};

//hide info menu
DWORD dwAddrHideInfoMenu = dwAddrStackBottom + 0x6C70;
BYTE codeHideInfoMenu[] = {
	0x50,                                     //push        eax
	0xB8, 0xA0, 0x02, 0x51, 0x00,             //mov         eax,5102A0h
	0xFF, 0xD0,                               //call        eax
	0x50,                                     //push        eax
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x15,                               //je          normal
	0xFF, 0x76, 0x38,                         //push        dword ptr[esi+38h]
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0xb0, 0xE1, 0x45, 0x00,             //mov         eax,45E1B0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x05,                               //jne         normal
	0x58,                                     //pop         eax
	0xB0, 0x0F,                               //mov         al,0Fh
	0xEB, 0x01,                               //jmp         end
	                                          //normal:
	0x58,                                     //pop         eax
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeHideInfoMenuThunk[] = {0xE8, 0x7C, 0x30, 0xB9, 0xFF};//dwAddrHideInfoMenu - 513BEFh
BYTE codeHideInfoMenuOldThunk[] = {0xE8, 0xAC, 0xC6, 0xFF, 0xFF};//call 5102A0h()
ASM_PATCH patchHideInfoMenuThunk[] = {
	{0x513BEF, sizeof(codeHideInfoMenuThunk), codeHideInfoMenuThunk},
	{0x513BEF, sizeof(codeHideInfoMenuOldThunk), codeHideInfoMenuOldThunk}};

//damage number down
DWORD dwAddrDamageNumberDown = dwAddrStackBottom + 0x6CA0;
BYTE codeDamageNumberDown[] = {
	0x51,                                     //push        ecx
	0x8B, 0x4C, 0x24, 0x0C,                   //mov         ecx,[esp+0Ch]
	0xB8, 0x60, 0x63, 0x0A, 0x00,             //mov         eax,check_player_view_range
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x03,                               //jne         normal
	0xC2, 0x20, 0x00,                         //ret         20h
	                                          //normal:
	0x68, 0x80, 0xD8, 0x52, 0x00,             //push        52D880h
	0xC3,                                     //ret
};

BYTE codeDamageNumberDownThunk[] = {0xE8, 0xD6, 0xE0, 0xB9, 0xFF};//dwAddrDamageNumberDown - 508BC5h
BYTE codeDamageNumberDownOldThunk[] = {0xE8, 0xB6, 0x4C, 0x02, 0x00};//call 52D880h()
ASM_PATCH patchDamageNumberDownThunk[] = {
	{0x508BC5, sizeof(codeDamageNumberDownThunk), codeDamageNumberDownThunk},
	{0x508BC5, sizeof(codeDamageNumberDownOldThunk), codeDamageNumberDownOldThunk}};

//get player force
DWORD dwAddrGetPlayerForce = dwAddrStackBottom + 0x64D0;
BYTE codeGetPlayerForce[] = {
	                                          //get_player_force:
	0x33, 0xD2,                               //xor         edx,edx
	0xB8, 0x38, 0x3C, 0x25, 0x01,             //mov         eax,1253C38h
	                                          //loop_force:
	0xF6, 0x40, 0x34, 0x01,                   //test        byte ptr [eax+34h],1
	0x75, 0x0D,                               //jne         end
	0x05, 0xD4, 0x00, 0x00, 0x00,             //add         eax,0D4h
	0x42,                                     //inc         edx
	0x80, 0xFA, 0x32,                         //cmp         dl,32h
	0x7C, 0xEF,                               //jl          loop_force
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC3                                      //ret
};

//hide down stone
DWORD dwAddrHideDownStone = dwAddrStackBottom + 0x6CC0;
BYTE codeHideDownStone[] = {
	0x51,                                     //push        ecx
	0x8B, 0x4C, 0x24, 0x08,                   //mov         ecx,[esp+8]
	0xB8, 0x60, 0x63, 0x0A, 0x00,             //mov         eax,check_player_view_range
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x59,                                     //pop         ecx
	0x74, 0x06,                               //je          hide_down_stone
	0x68, 0x60, 0xD0, 0x52, 0x00,             //push        52D060h
	0xC3,                                     //ret
	                                          //hide_down_stone:
	0xC2, 0x0C, 0x00                          //ret         0Ch
};

BYTE codeHideDownStoneThunk[] = {0xE8, 0xBF, 0xE7, 0xB9, 0xFF};//dwAddrHideDownStone - 5084FCh
BYTE codeHideDownStoneOldThunk[] = {0xE8, 0x5F, 0x4B, 0x02, 0x00};//call 52D060h()
ASM_PATCH patchHideDownStoneThunk[] = {
	{0x5084FC, sizeof(codeHideDownStoneThunk), codeHideDownStoneThunk},
	{0x5084FC, sizeof(codeHideDownStoneOldThunk), codeHideDownStoneOldThunk}};

//hide special state
DWORD dwAddrHideSpecialState = dwAddrStackBottom + 0x6FE0;
BYTE codeHideSpecialState[] = {
	0x8B, 0x41, 0x04,                         //mov         eax,[ecx+4]
	0x8B, 0x48, 0x08,                         //mov         ecx,[eax+8]
	0xB8, 0x60, 0x63, 0x0A, 0x00,             //mov         eax,check_player_view_range
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x05,                               //je          end
	0x68, 0xC0, 0x3E, 0x43, 0x00,             //push        433EC0h
	                                          //end:
	0xC3                                      //ret
};

BYTE codeHideSpecialStateThunk[] = {0xE8, 0xE6, 0xC5, 0xC5, 0xFF};//dwAddrHideSpecialState - 44A9F5h
BYTE codeHideSpecialStateOldThunk[] = {0xE8, 0xC6, 0x94, 0xFE, 0xFF};//call 433EC0h()
ASM_PATCH patchHideSpecialStateThunk[] = {
	{0x44A9F5, sizeof(codeHideSpecialStateThunk), codeHideSpecialStateThunk},
	{0x44A9F5, sizeof(codeHideSpecialStateOldThunk), codeHideSpecialStateOldThunk}};

//hide city morale
DWORD dwAddrHideCityMorale = dwAddrStackBottom + 0x7000;
BYTE codeHideCityMorale[] = {
	0xC6, 0x44, 0x24, 0x78, 0x0B,             //mov         byte ptr[esp+78h],0Bh
	0xB8, 0xE0, 0x4E, 0x0A, 0x00,             //mov         eax,get_building_view_state
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x05,                               //jne         end
	0xC6, 0x44, 0x24, 0x08, 0x90,             //mov         byte ptr[esp+8],90h
	                                          //end:
	0xC3                                      //ret
};

BYTE codeHideCityMoraleThunk[] = {0xE8, 0x50, 0xE8, 0xB7, 0xFF};//dwAddrHideCityMorale - 5287ABh
BYTE codeHideCityMoraleOldThunk[] = {0xC6, 0x44, 0x24, 0x74, 0x0B};//mov byte ptr[esp+74h],0Bh
ASM_PATCH patchHideCityMoraleThunk[] = {
	{0x5287AB, sizeof(codeHideCityMoraleThunk), codeHideCityMoraleThunk},
	{0x5287AB, sizeof(codeHideCityMoraleOldThunk), codeHideCityMoraleOldThunk}};

//hide city income
DWORD dwAddrHideCityIncome = dwAddrStackBottom + 0x7020;
BYTE codeHideCityIncome[] = {
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0xE0, 0x4E, 0x0A, 0x00,             //mov         eax,get_building_view_state
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x03,                               //jne         normal
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //normal:
	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,dword ptr [ecx]
	0xFF, 0x60, 0x18                          //jmp         dword ptr [eax+18h]
};
//income
BYTE codeHideCityIncomeThunk[] = {0xE8, 0xB0, 0xE7, 0xB7, 0xFF};//dwAddrHideCityIncome - 52886Bh
BYTE codeHideCityIncomeOldThunk[] = {0x8B, 0xCF, 0xFF, 0x52, 0x18};//mov ecx,edi;call [edx+18h]
ASM_PATCH patchHideCityIncomeThunk[] = {
	{0x52886B, sizeof(codeHideCityIncomeThunk), codeHideCityIncomeThunk},
	{0x52886B, sizeof(codeHideCityIncomeOldThunk), codeHideCityIncomeOldThunk}};
//harvest
BYTE codeHideCityHarvestThunk[] = {0xE8, 0xD9, 0xE6, 0xB7, 0xFF};//dwAddrHideCityHarvest - 528942h
BYTE codeHideCityHarvestOldThunk[] = {0x8B, 0xCF, 0xFF, 0x50, 0x18};//mov ecx,edi;call [eax+18h]
ASM_PATCH patchHideCityHarvestThunk[] = {
	{0x528942, sizeof(codeHideCityHarvestThunk), codeHideCityHarvestThunk},
	{0x528942, sizeof(codeHideCityHarvestOldThunk), codeHideCityHarvestOldThunk}};

//alloc free troop
DWORD dwAddrAllocFreeTroop = dwAddrStackBottom + 0x7040;
BYTE codeAllocFreeTroop[] = {
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0x33, 0xD2,                               //xor         edx,edx
	0xB9, 0x20, 0x03, 0x00, 0x00,             //mov         ecx,320h
	0xF7, 0xF9,                               //idiv        eax,ecx
	0x69, 0xD2, 0x04, 0x01, 0x00, 0x00,       //imul        edx,edx,104h
	0x03, 0xD7,                               //add         edx,edi
	                                          //loop_alloc_troop:
	0x83, 0x7A, 0x24, 0x00,                   //cmp         dword ptr [edx+24h],0
	0x74, 0x19,                               //je          end
	0x81, 0xC2, 0x04, 0x01, 0x00, 0x00,       //add         edx,104h
	0x81, 0xFA, 0x2C, 0xBF, 0x4E, 0x01,       //cmp         edx,14EBF2Ch
	0x7E, 0x02,                               //jle         inc_troop_index
	0x8B, 0xD7,								  //mov         edx,edi
	                                          //inc_troop_index:
	0x46,                                     //inc         esi
	0x81, 0xFE, 0x20, 0x03, 0x00, 0x00,       //cmp         esi,320h
	0x7C, 0xE1,                               //jl          loop_alloc_troop
	                                          //end:
	0x8B, 0xFA,								  //mov         edi,edx
	0xC3                                      //ret
};

BYTE codeAllocFreeTroopThunk[] = {0xE8, 0xB2, 0x3C, 0xC5, 0xFF, 0x40, 0x40};//dwAddrAllocFreeTroop - 453389h
BYTE codeAllocFreeTroopOldThunk[] = {0x8D, 0xA4, 0x24, 0x00, 0x00, 0x00, 0x00};//lea esp, [esp]
ASM_PATCH patchAllocFreeTroopThunk[] = {
	{0x453389, sizeof(codeAllocFreeTroopThunk), codeAllocFreeTroopThunk},
	{0x453389, sizeof(codeAllocFreeTroopOldThunk), codeAllocFreeTroopOldThunk}};

//counselor report prop
DWORD dwAddrCounselorReportProp = dwAddrStackBottom + 0x7080;
BYTE codeCounselorReportProp[] = {
	0x51,                                     //push        ecx
	0x57,                                     //push        edi
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          test_war_fog_flag
	                                          //normal:
	0x59,                                     //pop         ecx
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //test_war_fog_flag:
	0xB8, 0xD0, 0x64, 0x0A, 0x00,             //mov         eax,get_player_force
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xF1,                               //je          normal
	0x50,                                     //push        eax
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x40, 0x57, 0x43, 0x00,             //mov         eax,435740h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0xE3,                               //je          normal
	0xFF, 0x74, 0x24, 0x2C,                   //push        dword ptr [esp+2Ch]
	0xB8, 0x80, 0x8C, 0x50, 0x00,             //mov         eax,508C80h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0x0F, 0xB6, 0x15, 0x8F, 0xF8, 0x43, 0x00, //movzx       edx,byte ptr[counselor_report_coef]
	0xF7, 0xEA,                               //imul        edx
	0x99,									  //cdq
	0x6A, 0x06,								  //push        6
	0x59,									  //pop         ecx
	0xF7, 0xF9,                               //idiv        eax,ecx
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x04,                               //je          counselor_report_fail
	0x33, 0xC0,                               //xor         eax,eax
	0xEB, 0xB8,                               //jmp         normal
	                                          //counselor_report_fail:
	0x59,                                     //pop         ecx
	0x57,                                     //push        edi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0xB0, 0x01,                               //mov         al,1
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeCounselorReportPropThunk[] = {0xE8, 0x98, 0x1F, 0xB9, 0xFF};//dwAddrCounselorReportProp - 5150E3h
BYTE codeCounselorReportPropOldThunk[] = {0xE8, 0x78, 0x9A, 0xF5, 0xFF};//call 46EB60h()
ASM_PATCH patchCounselorReportPropThunk[] = {
	{0x5150E3, sizeof(codeCounselorReportPropThunk), codeCounselorReportPropThunk},
	{0x5150E3, sizeof(codeCounselorReportPropOldThunk), codeCounselorReportPropOldThunk}};

//block prop
DWORD dwAddrBlcokProp = dwAddrStackBottom + 0x6520;
BYTE codeBlcokProp[] = {
	0x85, 0xFF,                               //test        edi,edi
	0x7E, 0x03,                               //jle         get_proficiency_coef
	0x83, 0xEF, 0x05,                         //sub         edi,5
	                                          //get_proficiency_coef:
	0xB9, 0x25, 0x00, 0x00, 0x00,             //mov         ecx,25h
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x83, 0xF8, 0x32,                         //cmp         eax,32h
	0x7E, 0x02,                               //jle         end
	0xB0, 0x32,                               //mov         al,32h
	                                          //end:
	0x68, 0x18, 0x31, 0x50, 0x00,             //push        503118h
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeBlcokPropThunk[] = {0xE8, 0x1E, 0x34, 0xBA, 0xFF};//dwAddrBlcokProp - 5030FDh
BYTE codeBlcokPropOldThunk[] = {0xB8, 0x1F, 0x85, 0xEB, 0x51};//mov eax, 51EB851Fh
ASM_PATCH patchBlcokPropThunk[] = {
	{0x5030FD, sizeof(codeBlcokPropThunk), codeBlcokPropThunk},
	{0x5030FD, sizeof(codeBlcokPropOldThunk), codeBlcokPropOldThunk}};

//adjust attack array
DWORD dwAddrAdjustAttackArray = dwAddrStackBottom + 0x6600;
BYTE codeAdjustAttackArray[] = {
	                                          //adjust_attack_array:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x51,                                     //push        ecx
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xC0, 0x3C, 0x47, 0x00,             //mov         eax,473CC0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x3D, 0x24, 0x05, 0x0A, 0x00,       //mov         edi,[attack_troop_list+4]
	                                          //loop_attack_troop:
	0x8B, 0x57, 0x08,                         //mov         edx,dword ptr [edi+8]
	0xF6, 0x42, 0x20, 0x08,                   //test        byte ptr [edx+20h],8
	0x75, 0x1C,                               //jne         next_attack_troop
	0x8B, 0x42, 0x74,                         //mov         eax,dword ptr [edx+74h]
	0xF6, 0x40, 0x34, 0x05,                   //test        byte ptr [eax+34h],5
	0x75, 0x13,                               //jne         next_attack_troop
	0x8B, 0x42, 0x6C,                         //mov         eax,[edx+6Ch]
	0x80, 0x78, 0x04, 0x06,                   //cmp         byte ptr[eax+4],6
	0x74, 0x0A,                               //je          next_attack_troop
	0x8B, 0xCC,                               //mov         ecx,esp
	0x52,                                     //push        edx
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_attack_troop:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xD5,                               //jne         loop_attack_troop
	                                          //loop_source_troop:
	0x83, 0x7C, 0x24, 0x0C, 0x01,             //cmp         dword ptr [esp+0Ch],1
	0x0F, 0x8E, 0x15, 0x02, 0x00, 0x00,       //jle         end
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x69, 0x74,                         //mov         ebp,dword ptr [ecx+74h]
	0x83, 0xEC, 0x20,                         //sub         esp,20h
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xC0, 0x3C, 0x47, 0x00,             //mov         eax,473CC0h
	0xFF, 0xD0,                               //call        eax
	                                          //loop_create_force_troop_list:
	0x8B, 0x57, 0x08,                         //mov         edx,dword ptr [edi+8]
	0x39, 0x6A, 0x74,                         //cmp         dword ptr [edx+74h],ebp
	0x75, 0x1A,                               //jne         next_force_troop
	0x8B, 0xCC,                               //mov         ecx,esp
	0x52,                                     //push        edx
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	0x57,                                     //push        edi
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x8D, 0x4C, 0x24, 0x24,                   //lea         ecx,[esp+24h]
	0xB8, 0x10, 0x64, 0x41, 0x00,             //mov         eax,416410h
	0xFF, 0xD0,                               //call        eax
	0xEB, 0x02,                               //jmp         skip_next_force_troop
	                                          //next_force_troop:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	                                          //skip_next_force_troop:
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xD8,                               //jne         loop_create_force_troop_list
	0x8B, 0xAD, 0xB8, 0x00, 0x00, 0x00,       //mov         ebp,dword ptr [ebp+0B8h]
	0x8B, 0x6D, 0x70,                         //mov         ebp,dword ptr [ebp+70h]
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_force_troop:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr [ecx+21h],10h
	0x75, 0x01,                               //jne         next_force_troop2
	0x43,                                     //inc         ebx
	                                          //next_force_troop2:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x75, 0xF0,                               //jne         loop_force_troop
	0x8B, 0x44, 0x24, 0x0C,                   //mov         eax,dword ptr [esp+0Ch]
	0x83, 0xF8, 0x02,                         //cmp         eax,2
	0x7E, 0x0F,                               //jle         skip_adjust_go_date
	0x6B, 0xC0, 0x02,                         //imul        eax,eax,2
	0xB9, 0x03, 0x00, 0x00, 0x00,             //mov         ecx,3
	0x99,                                     //cdq
	0xF7, 0xF1,                               //div         eax,ecx
	0x2B, 0xD8,                               //sub         ebx,eax
	0x85, 0xDB,                               //test        ebx,ebx
	                                          //skip_adjust_go_date:
	0x0F, 0x8E, 0x7B, 0x01, 0x00, 0x00,       //jle         adjust_go_date
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_seige_troop:
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr [ecx+21h],10h
	0x74, 0x0D,                               //je          seige_troop
	0xB8, 0x00, 0x00, 0x00, 0x80,             //mov         eax,80000000h
	0x89, 0x41, 0x08,                         //mov         dword ptr [ecx+8],eax
	0xE9, 0x95, 0x00, 0x00, 0x00,             //jmp         next_seige_troop
	                                          //seige_troop:
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x6A, 0x00,                               //push        0
	0x8B, 0xB1, 0x88, 0x00, 0x00, 0x00,       //mov         esi,dword ptr [ecx+88h]
	                                          //loop_troop_person:
	0x8B, 0x56, 0x08,                         //mov         edx,dword ptr [esi+8]
	0x8B, 0x8A, 0xF8, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [edx+0F8h]
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x51,                               //je          next_troop_person
	0x83, 0x79, 0x54, 0x03,                   //cmp         dword ptr [ecx+54h],3
	0x7F, 0x4B,                               //jg          next_troop_person
	0xFF, 0x71, 0x64,                         //push        dword ptr [ecx+64h]
	0x8B, 0x47, 0x08,                         //mov         eax,dword ptr [edi+8]
	0xFF, 0x70, 0x6C,                         //push        dword ptr [eax+6Ch]
	0xB8, 0x00, 0x31, 0x0A, 0x00,             //mov         eax,killer_array_coef
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0xF7, 0xE9,                               //imul        ecx
	0xD1, 0xE2,                               //shl         edx,1
	0x01, 0x14, 0x24,                         //add         dword ptr [esp],edx
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x55,                                     //push        ebp
	0x6A, 0x00,                               //push        0
	0xB8, 0x40, 0x65, 0x0A, 0x00,             //mov         eax,get_array_killer_power
	0xFF, 0xD0,                               //call        eax
	0x01, 0x44, 0x24, 0x04,                   //add         dword ptr [esp+4],eax
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x55,                                     //push        ebp
	0x6A, 0x02,                               //push        2
	0xB8, 0x40, 0x65, 0x0A, 0x00,             //mov         eax,get_array_killer_power
	0xFF, 0xD0,                               //call        eax
	0x01, 0x44, 0x24, 0x08,                   //add         dword ptr [esp+8],eax
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x55,                                     //push        ebp
	0x6A, 0x05,                               //push        5
	0xB8, 0x40, 0x65, 0x0A, 0x00,             //mov         eax,get_array_killer_power
	0xFF, 0xD0,                               //call        eax
	0x01, 0x44, 0x24, 0x0C,                   //add         dword ptr [esp+0Ch],eax
	                                          //next_troop_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0x9C,                               //jne         loop_troop_person
	0x33, 0xD2,                               //xor         edx,edx
	0x5E,                                     //pop         esi
	0x58,                                     //pop         eax
	0x59,                                     //pop         ecx
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x7D, 0x04,                               //jge         get_max_field_power
	0xB2, 0x02,                               //mov         dl,2
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //get_max_field_power:
	0x59,                                     //pop         ecx
	0x3B, 0xC1,                               //cmp         eax,ecx
	0x7D, 0x04,                               //jge         get_adjust_array_coef
	0xB2, 0x05,                               //mov         dl,5
	0x8B, 0xC1,                               //mov         eax,ecx
	                                          //get_adjust_array_coef:
	0x2B, 0xC6,                               //sub         eax,esi
	0xC1, 0xE0, 0x10,                         //shl         eax,10h
	0x03, 0xC2,                               //add         eax,edx
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x89, 0x41, 0x08,                         //mov         dword ptr [ecx+8],eax
	                                          //next_seige_troop:
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x0F, 0x85, 0x4B, 0xFF, 0xFF, 0xFF,       //jne         loop_seige_troop
	0x8B, 0xCC,                               //mov         ecx,esp
	0x6A, 0x00,                               //push        0
	0x68, 0x60, 0xE9, 0x46, 0x00,             //push        46E960h
	0xB8, 0x10, 0xF6, 0x46, 0x00,             //mov         eax,46F610h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x7C, 0x24, 0x04,                   //mov         edi,dword ptr [esp+4]
	                                          //loop_adjust_troop:
	0x53,                                     //push        ebx
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x0F, 0xB7, 0x59, 0x08,                   //movzx       ebx,word ptr [ecx+8]
	0x8B, 0xB1, 0x88, 0x00, 0x00, 0x00,       //mov         esi,dword ptr [ecx+88h]
	                                          //loop_adjust_troop_person:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x81, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,[ecx+0F8h]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x1C,                               //je          adjust_troop_person_pos
	0x83, 0x78, 0x54, 0x03,                   //cmp         dword ptr[eax+54h],3
	0x7F, 0x16,                               //jg          adjust_troop_person_pos
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0xB8, 0x40, 0x65, 0x0A, 0x00,             //mov         eax,get_array_killer_power
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x44, 0x24, 0xF8,                   //mov         eax,dword ptr [esp-8]
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x89, 0x81, 0xF8, 0x00, 0x00, 0x00,       //mov         dword ptr [ecx+0F8h],eax
	                                          //adjust_troop_person_pos:
	0x8A, 0x81, 0xEA, 0x00, 0x00, 0x00,       //mov         al,byte ptr [ecx+0EAh]
	0x24, 0x1F,                               //and         al,1Fh
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x8B, 0x51, 0x6C,                         //mov         edx,dword ptr [ecx+6Ch]
	0x81, 0xC2, 0x80, 0x00, 0x00, 0x00,       //add         edx,80h
	0x33, 0xC9,                               //xor         ecx,ecx
	                                          //loop_get_positon_index:
	0x3A, 0x02,                               //cmp         al,byte ptr [edx]
	0x74, 0x07,                               //je          end_loop_get_positon_index
	0x42,                                     //inc         edx
	0x41,                                     //inc         ecx
	0x80, 0xF9, 0x05,                         //cmp         cl,5
	0x7C, 0xF5,                               //jl          loop_get_positon_index
	                                          //end_loop_get_positon_index:
	0x80, 0xF9, 0x04,                         //cmp         cl,4
	0x7E, 0x07,                               //jle         get_new_positon
	0xB8, 0x09, 0x00, 0x00, 0x00,             //mov         eax,9
	0xEB, 0x13,                               //jmp         set_person_new_position
	                                          //get_new_positon:
	0x53,                                     //push        ebx
	0xB8, 0x90, 0x38, 0x45, 0x00,             //mov         eax,453890h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x51,                                     //push        ecx
	0x8B, 0xC8,                               //mov         ecx,eax
	0xB8, 0xF0, 0x87, 0x44, 0x00,             //mov         eax,4487F0h
	0xFF, 0xD0,                               //call        eax
	                                          //set_person_new_position:
	0x68, 0x00, 0x00, 0x1F, 0x00,             //push        1F0000h
	0x50,                                     //push        eax
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0xB8, 0x00, 0xC9, 0x44, 0x00,             //mov         eax,44C900h
	0xFF, 0xD0,                               //call        eax
	                                          //next_adjust_troop_person:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0x81,                               //jne         loop_adjust_troop_person
	0x53,                                     //push        ebx
	0xB8, 0x90, 0x38, 0x45, 0x00,             //mov         eax,453890h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0x4F, 0x08,                         //mov         ecx,dword ptr [edi+8]
	0x89, 0x41, 0x6C,                         //mov         dword ptr [ecx+6Ch],eax
	0x80, 0x49, 0x21, 0x10,                   //or          byte ptr [ecx+21h],10h
	0x5B,                                     //pop         ebx
	0x4B,                                     //dec         ebx
	0x74, 0x0A,                               //je          adjust_go_date
	0x8B, 0x3F,                               //mov         edi,dword ptr [edi]
	0x85, 0xFF,                               //test        edi,edi
	0x0F, 0x85, 0x52, 0xFF, 0xFF, 0xFF,       //jne         loop_adjust_troop
	                                          //adjust_go_date:
	0x8B, 0x44, 0x24, 0x40,                   //mov         eax,dword ptr [esp+40h]
	0x8B, 0xCC,                               //mov         ecx,esp
	0x50,                                     //push        eax
	0xB8, 0x40, 0x5D, 0x0A, 0x00,             //mov         eax,adjust_troop_go_date
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0xE9, 0xE0, 0xFD, 0xFF, 0xFF,             //jmp         loop_source_troop
	                                          //end:
	0x8B, 0xCC,                               //mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,             //mov         eax,5180E0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xC4, 0x20,                         //add         esp,20h
	0x58,                                     //pop         eax
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//get array killer power
DWORD dwAddrGetArrayKillerPower = dwAddrStackBottom + 0x6540;
BYTE codeGetArrayKillerPower[] = {
	                                          //get_array_killer_power:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x8B, 0x5C, 0x24, 0x18,                   //mov         ebx,dword ptr [esp+18h]
	0x0B, 0x99, 0x00, 0x01, 0x00, 0x00,       //or          ebx,dword ptr [ecx+100h]
	0x8A, 0x44, 0x24, 0x14,                   //mov         al,byte ptr [esp+14h]
	0x33, 0xD2,                               //xor         edx,edx
	0x33, 0xF6,                               //xor         esi,esi
	0x33, 0xFF,                               //xor         edi,edi
	0x3C, 0x00,                               //cmp         al,0
	0x75, 0x06,                               //jne         test_wimble_array
	0x66, 0xB9, 0x00, 0x02,                   //mov         cx,200h
	0xEB, 0x12,                               //jmp         check_killer
	                                          //test_wimble_array:
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x06,                               //jne         test_dustpan_array
	0x66, 0xB9, 0x03, 0x08,                   //mov         cx,803h
	0xEB, 0x08,                               //jmp         check_killer
	                                          //test_dustpan_array:
	0x3C, 0x05,                               //cmp         al,5
	0x75, 0x2F,                               //jne         end
	0x66, 0xB9, 0x06, 0x0B,                   //mov         cx,0B06h
	                                          //check_killer:
	0xF6, 0xC3, 0x01,                         //test        bl,1
	0x74, 0x1E,                               //je          next_killer
	0x52,                                     //push        edx
	0xB8, 0x20, 0x37, 0x45, 0x00,             //mov         eax,453720h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x8B, 0x68, 0x64,                         //mov         ebp,dword ptr [eax+64h]
	0x3A, 0xD1,                               //cmp         dl,cl
	0x7C, 0x04,                               //jl          half_killer_power
	0x3A, 0xD5,                               //cmp         dl,ch
	0x7E, 0x02,                               //jle         compare_killer_power
	                                          //half_killer_power:
	0xD1, 0xED,                               //shr         ebp,1
	                                          //compare_killer_power:
	0x3B, 0xEE,                               //cmp         ebp,esi
	0x7C, 0x04,                               //jl          next_killer
	0x8B, 0xF5,                               //mov         esi,ebp
	0x8B, 0xF8,                               //mov         edi,eax
	                                          //next_killer:
	0xD1, 0xEB,                               //shr         ebx,1
	0x42,                                     //inc         edx
	0x80, 0xFA, 0x0C,                         //cmp         dl,0Ch
	0x7C, 0xD5,                               //jl          check_killer
	                                          //end:
	0x89, 0x7C, 0x24, 0x14,                   //mov         dword ptr [esp+14h],edi
	0x8B, 0xC6,                               //mov         eax,esi
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x08, 0x00                          //ret         8
};

//adjust troop go date
DWORD dwAddrAdjustTroopGoDate = dwAddrStackBottom + 0x5D40;
BYTE codeAdjustTroopGoDate[] = {
	                                          //adjust_troop_go_date:
	0x83, 0x79, 0x0C, 0x01,                   //cmp         dword ptr [ecx+0Ch],1
	0x7F, 0x03,                               //jg          start_adjust_go_date
	0xC2, 0x04, 0x00,                         //ret         4
	                                          //start_adjust_go_date:
	0x56,                                     //push        esi
	0x57,                                     //push        edi
	0x55,                                     //push        ebp
	0x53,                                     //push        ebx
	0x8B, 0xF1,                               //mov         esi,ecx
	0x8B, 0x7C, 0x24, 0x14,                   //mov         edi,dword ptr [esp+14h]

	0x8B, 0xCF,                               //mov         ecx,edi
	0x8B, 0x01,                               //mov         eax,[ecx]
	0xFF, 0x50, 0x3C,                         //call        [eax+3Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x09,                               //je          do_adjust_go_date
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xA0, 0x3E, 0x0A, 0x00,             //mov         eax,use_baram_array
	0xFF, 0xD0,                               //call        eax

	                                          //do_adjust_go_date:
	0x33, 0xDB,                               //xor         ebx,ebx
	0x8B, 0x6E, 0x04,                         //mov         ebp,dword ptr [esi+4]
	                                          //loop_add_go_date:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr[ecx+21h],10h
	0x75, 0x10,                               //jne         next_add_troop
	0x57,                                     //push        edi
	0xB8, 0x70, 0x88, 0x46, 0x00,             //mov         eax,468870h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0x89, 0x41, 0x08,                         //mov         dword ptr [ecx+8],eax
	0x03, 0xD8,                               //add         ebx,eax
	                                          //next_add_troop:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xE0,                               //jne         loop_add_go_date
	0x8B, 0xC3,                               //mov         eax,ebx
	0x99,                                     //cdq
	0xF7, 0x76, 0x0C,                         //div         eax,dword ptr [esi+0Ch]
	0x8B, 0xD8,                               //mov         ebx,eax

	0x33, 0xFF,                               //xor         edi,edi
	0x8B, 0x6E, 0x04,                         //mov         ebp,dword ptr [esi+4]
	                                          //loop_get_ave_error:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr[ecx+21h],10h
	0x75, 0x0D,                               //jne         next_error_troop
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x2B, 0xC3,                               //sub         eax,ebx
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         add_ave_error
	0xF7, 0xD8,                               //neg         eax
	                                          //add_ave_error:
	0x03, 0xF8,                               //add         edi,eax
	                                          //next_error_troop:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xE3,                               //jne         loop_get_ave_error
	0x8B, 0xC7,                               //mov         eax,edi
	0x99,                                     //cdq
	0xF7, 0x76, 0x0C,                         //div         eax,dword ptr [esi+0Ch]
	0x8B, 0xE8,                               //mov         ebp,eax
	0xD1, 0xED,                               //shr         ebp,1
	0x03, 0xDD,                               //add         ebx,ebp

	0x8B, 0x6E, 0x04,                         //mov         ebp,dword ptr [esi+4]
	                                          //loop_upate_go_date:
	0x8B, 0x4D, 0x08,                         //mov         ecx,dword ptr [ebp+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr[ecx+21h],10h
	0x75, 0x19,                               //jne         next_upate_troop
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x2B, 0xC3,                               //sub         eax,ebx
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         got_go_date
	0x33, 0xC0,                               //xor         eax,eax
	                                          //got_go_date:
	0x83, 0xF8, 0x0F,                         //cmp         eax,0Fh
	0x7E, 0x04,                               //jle         update_go_date
	0x33, 0xC0,                               //xor         eax,eax
	0xB0, 0x0F,                               //mov         al,0Fh
	                                          //update_go_date:
	0x89, 0x41, 0x48,                         //mov         dword ptr [ecx+48h],eax
	                                          //next_upate_troop:
	0x8B, 0x6D, 0x00,                         //mov         ebp,dword ptr [ebp]
	0x85, 0xED,                               //test        ebp,ebp
	0x75, 0xD7,                               //jne         loop_upate_go_date
	0x5B,                                     //pop         ebx
	0x5D,                                     //pop         ebp
	0x5F,                                     //pop         edi
	0x5E,                                     //pop         esi
	0xC2, 0x04, 0x00                          //ret         4
};

//alienate multi select
DWORD dwAddrAlienateMultiSelect = dwAddrStackBottom + 0x3188;
BYTE codeAlienateMultiSelect[] = {
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xC2, 0xF7, 0xB6, 0xA1,//mov [61C618h], A1B6F7C2h
	0x68, 0x1C, 0xC6, 0x66, 0x00,             //push        66C61Ch
	0x55,                                     //push        ebp
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xA8, 0xB5, 0xB9, 0xEE,//mov [61C618h], EEB9B5A8h
	0xC3                                      //ret
};

BYTE codeAlienateMultiSelectThunk[] = {0xE8, 0x58, 0x1F, 0xBC, 0xFF};//dwAddrAlienateMultiSelect - 4E122Bh - 5
BYTE codeAlienateMultiSelectOldThunk[] = {0xE8, 0x50, 0xF1, 0x08, 0x00};//call 570380h()
ASM_PATCH patchAlienateMultiSelectThunk[] = {
	{0x4E122B, sizeof(codeAlienateMultiSelectThunk), codeAlienateMultiSelectThunk},
	{0x4E122B, sizeof(codeAlienateMultiSelectOldThunk), codeAlienateMultiSelectOldThunk}};

//false multi select
DWORD dwAddrFalseMultiSelect = dwAddrStackBottom + 0x6880;
BYTE codeFalseMultiSelect[] = {
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xB0, 0xB0, 0xB3, 0xF8,//mov [61C618h], F8B3B0B0h
	0x68, 0x1C, 0xC6, 0x66, 0x00,             //push        66C61Ch
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xA8, 0xB5, 0xB9, 0xEE,//mov [61C618h], EEB9B5A8h
	0xC3                                      //ret
};

BYTE codeFalseMultiSelectThunk[] = {0xE8, 0x30, 0x55, 0xBD, 0xFF};//dwAddrFalseMultiSelect - 4D134Bh - 5
BYTE codeFalseMultiSelectOldThunk[] = {0xE8, 0x30, 0xF0, 0x09, 0x00};//call 570380h()
ASM_PATCH patchFalseMultiSelectThunk[] = {
	{0x4D134B, sizeof(codeFalseMultiSelectThunk), codeFalseMultiSelectThunk},
	{0x4D134B, sizeof(codeFalseMultiSelectOldThunk), codeFalseMultiSelectOldThunk}};

//disorder multi select
DWORD dwAddrDisorderMultiSelect = dwAddrStackBottom + 0x68A8;
BYTE codeDisorderMultiSelect[] = {
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xC2, 0x5A, 0xB6, 0xC3,//mov [61C618h], C3B65AC2h
	0x68, 0x1C, 0xC6, 0x66, 0x00,             //push        66C61Ch
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x90, 0x23, 0x0A, 0x00,             //mov         eax,multi_select_person_window
	0xFF, 0xD0,                               //call        eax
	0xC7, 0x05, 0x18, 0xC6, 0x61, 0x00, 0xA8, 0xB5, 0xB9, 0xEE,//mov [61C618h], EEB9B5A8h
	0xC3                                      //ret
};

BYTE codeDisorderMultiSelectThunk[] = {0xE8, 0xB8, 0xB4, 0xBC, 0xFF};//dwAddrDisorderMultiSelect - 4DB3EBh - 5
BYTE codeDisorderMultiSelectOldThunk[] = {0xE8, 0x90, 0x4F, 0x09, 0x00};//call 570380h()
ASM_PATCH patchDisorderMultiSelectThunk[] = {
	{0x4DB3EB, sizeof(codeDisorderMultiSelectThunk), codeDisorderMultiSelectThunk},
	{0x4DB3EB, sizeof(codeDisorderMultiSelectOldThunk), codeDisorderMultiSelectOldThunk}};

//sort multi select person
DWORD dwAddrSortMultiSelectPerson = dwAddrStackBottom + 0x23D8;
BYTE codeSortMultiSelectPerson[] = {
	                                          //sort_multi_select_person:
	0x6A, 0x00,                               //push        0
	0x68, 0xEC, 0x23, 0x0A, 0x00,             //push        multi_select_person_state
	0xB8, 0x10, 0xF6, 0x46, 0x00,             //mov         eax,46F610h
	0xFF, 0xD0,                               //call        eax
	0x68, 0x00, 0x05, 0x57, 0x00,             //push        570500h
	0xC3                                      //ret
};

//multi select person state
DWORD dwAddrMultiSelectPersonState = dwAddrStackBottom + 0x23EC;
BYTE codeMultiSelectPersonState[] = {
	                                          //multi_select_person_state:
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,[esp+4]
	0xB9, 0x00, 0x05, 0x0A, 0x00,             //mov         ecx, multi_search_person_list
	0xFF, 0x30,                               //push        [eax]
	0xB8, 0x60, 0xEB, 0x46, 0x00,             //mov         eax,46EB60h
	0xFF, 0xD0,                               //call eax
	0xC3                                      //ret
};

//chaos linkage flag
DWORD dwAddrChaosLinkageFlag = dwAddrStackBottom + 0x65B0;
BYTE codeChaosLinkageFlag[] = {
	0x8B, 0x4E, 0x30,                         //mov         ecx,dword ptr [esi+30h]
	0x8B, 0x81, 0xF8, 0x00, 0x00, 0x00,       //mov         eax,dword ptr [ecx+0F8h]
	0x80, 0x78, 0x54, 0x07,                   //cmp         byte ptr [eax+54h],7
	0x7C, 0x07,                               //jl          end
	0xC6, 0x86, 0xB8, 0x00, 0x00, 0x00, 0x01, //mov         byte ptr [esi+0B8h],1
	                                          //end:
	0xC3                                      //ret
};

//混乱带动
BYTE codeChaosLinkageFlagThunk[] = {0xE8, 0xA1, 0x15, 0xBA, 0xFF, 0x40, 0x40, 0x40, 0x40, 0x40};
										//dwAddrChaosLinkageFlag - 50500Ah- 5
BYTE codeChaosLinkageFlagOldThunk[] = {0xC7, 0x86, 0xB8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
										//mov dword ptr[esi+0B8h],1
ASM_PATCH patchChaosLinkageFlagThunk[] = {
	{0x50500A, sizeof(codeChaosLinkageFlagThunk), codeChaosLinkageFlagThunk},
	{0x50500A, sizeof(codeChaosLinkageFlagOldThunk), codeChaosLinkageFlagOldThunk}};
//陷阱带动
BYTE codeTrapLinkageFlagThunk[] = {0xE8, 0xC1, 0x09, 0xBA, 0xFF, 0x40};//dwAddrChaosLinkageFlag - 505BEAh- 5
BYTE codeTrapLinkageFlagOldThunk[] = {0x89, 0x9E, 0xB8, 0x00, 0x00, 0x00};//mov dword ptr[esi+0B8h],ebx
ASM_PATCH patchTrapLinkageFlagThunk[] = {
	{0x505BEA, sizeof(codeTrapLinkageFlagThunk), codeTrapLinkageFlagThunk},
	{0x505BEA, sizeof(codeTrapLinkageFlagOldThunk), codeTrapLinkageFlagOldThunk}};
//攻心带动
BYTE codeAttackHeartLinkageFlagThunk[] = {0xE8, 0x2E, 0x0E, 0xBA, 0xFF, 0x40, 0x40, 0x40, 0x40, 0x40};
										//dwAddrChaosLinkageFlag - 50577Dh- 5
ASM_PATCH patchAttackHeartLinkageFlagThunk[] = {
	{0x50577D, sizeof(codeAttackHeartLinkageFlagThunk), codeAttackHeartLinkageFlagThunk},
	{0x50577D, sizeof(codeChaosLinkageFlagOldThunk), codeChaosLinkageFlagOldThunk}};

//killer to building
DWORD dwAddrKillerToBuilding = dwAddrStackBottom + 0x5FE0;
BYTE codeKillerToBuilding[] = {
	0xFF, 0x76, 0x34,                         //push        dword ptr [esi+34h]
	0xB8, 0x20, 0x37, 0x45, 0x00,             //mov         eax,453720h
	0xFF, 0xD0,                               //call        eax
	0xF6, 0x80, 0x84, 0x00, 0x00, 0x00, 0x01, //test        byte ptr [eax+84h],1
	0x58,                                     //pop         eax
	0x75, 0x03,                               //jne         normal
	0x33, 0xC0,                               //xor         eax,eax
	0xC3,                                     //ret
	                                          //normal:
	0x68, 0x40, 0x58, 0x40, 0x00,             //push        405840h
	0xC3                                      //ret
};

BYTE codeKillerToBuildingThunk[] = {0xE8, 0xE6, 0x13, 0xBA, 0xFF};//dwAddrKillerToBuilding - 504BF5h - 5
BYTE codeKillerToBuildingOldThunk[] = {0xE8, 0x46, 0x0C, 0xF0, 0xFF};//call 405840h()
ASM_PATCH patchKillerToBuildingThunk[] = {
	{0x504BF5, sizeof(codeKillerToBuildingThunk), codeKillerToBuildingThunk},
	{0x504BF5, sizeof(codeKillerToBuildingOldThunk), codeKillerToBuildingOldThunk}};

//all strong force
DWORD dwAddrAllStrongForce = dwAddrStackBottom + 0x5C60;
BYTE codeAllStrongForce[] = {
	0xB0, 0x19,                               //mov         al,19h
	0x83, 0xF9, 0x04,                         //cmp         ecx,4
	0x7D, 0x2D,                               //jge         end
	0x8B, 0x4C, 0x24, 0x20,                   //mov         ecx,dword ptr [esp+20h]
	                                          //loop_npc_force:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x0B,                               //je          set_baram_force
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x80, 0x48, 0x0C, 0x80,                   //or          byte ptr [eax+0Ch],80h
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xF1,                               //jmp         loop_npc_force
	                                          //set_baram_force:
	0x8B, 0x8C, 0x24, 0x80, 0x00, 0x00, 0x00, //mov         ecx,dword ptr [esp+80h]
	                                          //loop_baram_force:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x0B,                               //je          end_loop_baram_force
	0x8B, 0x41, 0x08,                         //mov         eax,dword ptr [ecx+8]
	0x80, 0x48, 0x0C, 0x80,                   //or          byte ptr [eax+0Ch],80h
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xF1,                               //jmp         loop_baram_force
	                                          //end_loop_baram_force:
	0xB0, 0x0A,                               //mov         al,0Ah
	0x3C, 0x60,                               //cmp         al,60h
	                                          //end:
	0xA2, 0xC7, 0x59, 0x0A, 0x00,             //mov         [dwAddrAttackRatioDoor+7],al
	0xC3                                      //ret
};

BYTE codeAllStrongForceThunk[] = {0xE8, 0x18, 0x78, 0xBE, 0xFF};//dwAddrAllStrongForce - 4BE443h - 5
BYTE codeAllStrongForceOldThunk[] = {0x03, 0xC8, 0x83, 0xF9, 0x04};//add ecx,eax; cmp ecx,4
ASM_PATCH patchAllStrongForceThunk[] = {
	{0x4BE443, sizeof(codeAllStrongForceThunk), codeAllStrongForceThunk},
	{0x4BE443, sizeof(codeAllStrongForceOldThunk), codeAllStrongForceOldThunk}};

//check long range array
DWORD dwAddrCheckLongRangeArray = dwAddrStackBottom + 0x1B00;
BYTE codeCheckLongRangeArray[] = {
	                                          //check_long_range_array:
	0x56,                                     //push        esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0xB8, 0x90, 0xE3, 0x45, 0x00,             //mov         eax,45E390h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0C,                               //jne         boat_on_water
	0x8B, 0x4E, 0x6C,                         //mov         ecx,dword ptr [esi+6Ch]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	0x3C, 0x0A,                               //cmp         al,0Ah
	0x74, 0x0A,                               //je          end
	0xEB, 0x06,                               //jmp         short_range_array
	                                          //boat_on_water:
	0x8B, 0x4E, 0x70,                         //mov         ecx,dword ptr [esi+70h]
	0x8A, 0x41, 0x04,                         //mov         al,byte ptr [ecx+4]
	                                          //short_range_array:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//change troop command
DWORD dwAddrChangeTroopCommand = dwAddrStackBottom + 0x1700;
BYTE codeChangeTroopCommand[] = {
	0x8B, 0x89, 0x88, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [ecx+88h]
	                                          //loop_troop_person:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x0F,                               //je          end_loop_troop_person
	0x8B, 0x51, 0x08,                         //mov         edx,dword ptr [ecx+8]
	0x39, 0x7A, 0x68,                         //cmp         dword ptr [edx+68h],edi
	0x7E, 0x03,                               //jle         next_troop_person
	0x8B, 0x7A, 0x68,                         //mov         edi,dword ptr [edx+68h]
	                                          //next_troop_person:
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xED,                               //jmp         loop_troop_person
	                                          //end_loop_troop_person:
	0x33, 0xC0,                               //xor         eax,eax
	0xC3                                      //ret
};

BYTE codeChangeTroopCommandThunk[] = {0xE8, 0xC5, 0x2B, 0xC4, 0xFF, 0x90};//dwAddrChangeTroopCommand - 45EB36h - 5
BYTE codeChangeTroopCommandOldThunk[] = {0xFF, 0x90, 0xBC, 0x00, 0x00, 0x00};//call [eax+0BCh]
ASM_PATCH patchChangeTroopCommandThunk[] = {
	{0x45EB36, sizeof(codeChangeTroopCommandThunk), codeChangeTroopCommandThunk},
	{0x45EB36, sizeof(codeChangeTroopCommandOldThunk), codeChangeTroopCommandOldThunk}};

//water killer prop
DWORD dwAddrWaterKillerProp = dwAddrStackBottom + 0x6B60;
BYTE codeWaterKillerProp[] = {
	0xB8, 0x00, 0xE9, 0x46, 0x00,             //mov         eax,46E900h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF8,                               //mov         edi,eax
	0xBB, 0x70, 0xF7, 0x44, 0x00,             //mov         ebx,44F770h
	0x8B, 0x8E, 0x80, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [esi+80h]
	0x8B, 0x51, 0x70,                         //mov         edx,dword ptr [ecx+70h]
	0x0F, 0xB6, 0x42, 0x04,                   //movzx       eax,byte ptr [edx+4]
	0x83, 0xE8, 0x15,                         //sub         eax,15h
	0x85, 0xC0,                               //test        eax,eax
	0x7C, 0x29,                               //jl          normal
	0x3C, 0x02,                               //cmp         al,2
	0x7F, 0x25,                               //jg          normal
	0x74, 0x0B,                               //je          test_killer_doujian
	0x04, 0x0C,                               //add         al,0Ch
	0x50,                                     //push        eax
	0x8B, 0xCF,                               //mov         ecx,edi
	0xFF, 0xD3,                               //call        ebx
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x18,                               //jne         normal
	                                          //test_killer_doujian:
	0x6A, 0x0E,                               //push        0Eh
	0x8B, 0xCF,                               //mov         ecx,edi
	0xFF, 0xD3,                               //call        ebx
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x0E,                               //jne         normal
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,       //call        [5FF2DCh]
	0xA8, 0x01,                               //test        al,1
	0x75, 0x04,                               //jne         normal
	0xC6, 0x04, 0x24, 0x2A,                   //mov         byte ptr[esp],2Ah
	                                          //normal:
	0x8B, 0xC7,                               //mov         eax,edi
	0xC3                                      //ret
};

BYTE codeWaterKillerPropThunk[] = {0xE8, 0x57, 0x0A, 0xBA, 0xFF};//dwAddrWaterKillerProp - 506104h - 5
BYTE codeWaterKillerPropOldThunk[] = {0xE8, 0xF7, 0x87, 0xF6, 0xFF};//call 46E900h()
ASM_PATCH patchWaterKillerPropThunk[] = {
	{0x506104, sizeof(codeWaterKillerPropThunk), codeWaterKillerPropThunk},
	{0x506104, sizeof(codeWaterKillerPropOldThunk), codeWaterKillerPropOldThunk}};

//killer drive prop
DWORD dwAddrKillerDriveProp = dwAddrStackBottom + 0x3E00;
BYTE codeKillerDriveProp[] = {
	0x53,                                     //push        ebx
	0x55,                                     //push        ebp
	0x8B, 0x59, 0x04,                         //mov         ebx,dword ptr [ecx+4]
	                                          //loop_strength_person:
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x50,                               //je          end_loop_strength_person
	0x8B, 0x4E, 0x54,                         //mov         ecx,dword ptr [esi+54h]
	0x8B, 0x6B, 0x08,                         //mov         ebp,dword ptr [ebx+8]
	0x3B, 0xE9,                               //cmp         ebp,ecx
	0x74, 0x42,                               //je          next_strength_person
	0x55,                                     //push        ebp
	0xB8, 0xC0, 0xCE, 0x44, 0x00,             //mov         eax,44CEC0h
	0xFF, 0xD0,                               //call        eax
	0x83, 0xE8, 0x05,                         //sub         eax,5
	0xF7, 0xD8,                               //neg         eax
	0x85, 0xC0,                               //test        eax,eax
	0x7F, 0x04,                               //jg          get_phase_drive_coef
	0x33, 0xC0,                               //xor         eax,eax
	0xEB, 0x03,                               //jmp         get_friendship_drive_coef
	                                          //get_phase_drive_coef:
	0x6B, 0xC0, 0x05,                         //imul        eax,eax,5
	                                          //get_friendship_drive_coef:
	0x50,                                     //push        eax
	0xFF, 0x76, 0x54,                         //push        dword ptr [esi+54h]
	0x55,                                     //push        ebp
	0xB8, 0x70, 0xF7, 0x4F, 0x00,             //mov         eax,4FF770h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x5A,                                     //pop         edx
	0x5A,                                     //pop         edx
	0x03, 0xC2,                               //add         eax,edx
	0x83, 0xC0, 0x19,                         //add         eax,19h
	0x50,                                     //push        eax
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x0A,                               //je          next_strength_person
	0x55,                                     //push        ebp
	0x8B, 0xCF,                               //mov         ecx,edi
	0xB8, 0x70, 0xEF, 0x46, 0x00,             //mov         eax,46EF70h
	0xFF, 0xD0,                               //call        eax
	                                          //next_strength_person:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0xEB, 0xAC,                               //jmp         loop_strength_person
	                                          //end_loop_strength_person:
	0x5D,                                     //pop         ebp
	0x5B,                                     //pop         ebx
	0x83, 0x7F, 0x0C, 0x00,                   //cmp         dword ptr [edi+0Ch],0
	0x75, 0x08,                               //jne         success
	0x68, 0x11, 0x64, 0x50, 0x00,             //push        506411h
	0xC2, 0x08, 0x00,                         //ret         8
	                                          //success:
	0x8A, 0x04, 0x24,                         //mov         al,[esp]
	0x3C, 0x19,                               //cmp         al,19h
	0x75, 0x02,                               //jne         get_return_addr
	0x04, 0x04,                               //add         al,4
	                                          //get_return_addr:
	0x04, 0x27,                               //add         al,27h
	0x88, 0x04, 0x24,                         //mov         [esp],al
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeKillerDrivePropThunk[] = {0xE8, 0xE7, 0xDA, 0xB9, 0xFF};//dwAddrKillerDriveProp - 506314h - 5
BYTE codeKillerDrivePropOldThunk[] = {0xE8, 0x37, 0x8B, 0xF6, 0xFF};//call 46EE50h()
ASM_PATCH patchKillerDrivePropThunk[] = {
	{0x506314, sizeof(codeKillerDrivePropThunk), codeKillerDrivePropThunk},
	{0x506314, sizeof(codeKillerDrivePropOldThunk), codeKillerDrivePropOldThunk}};
BYTE codeKillerDriveProp2Thunk[] = {0xE8, 0x50, 0xDA, 0xB9, 0xFF};//dwAddrKillerDriveProp - 5063ABh - 5
BYTE codeKillerDriveProp2OldThunk[] = {0xE8, 0xA0, 0x8A, 0xF6, 0xFF};//call 46EE50h()
ASM_PATCH patchKillerDriveProp2Thunk[] = {
	{0x5063AB, sizeof(codeKillerDriveProp2Thunk), codeKillerDriveProp2Thunk},
	{0x5063AB, sizeof(codeKillerDriveProp2OldThunk), codeKillerDriveProp2OldThunk}};

//clear troop cur goal
DWORD dwAddrClearTroopCurGoal = dwAddrStackBottom + 0x3E80;
BYTE codeClearTroopCurGoal[] = {
	0x83, 0x7C, 0x24, 0x20, 0xFF,             //cmp         dword ptr [esp+20h],0FFh
	0x75, 0x01,                               //jne         do_check_long_range_array
	0xC3,                                     //ret
	                                          //do_check_long_range_array:
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x00, 0x1B, 0x0A, 0x00,             //mov         eax,check_long_range_array
	0xFF, 0xD0,                               //call        eax
	0xF7, 0xD8,                               //neg         eax
	0x1B, 0xC0,                               //sbb         eax,eax
	0x40,                                     //inc         eax
	0x85, 0xC0,                               //test        eax,eax
	0xC3                                      //ret
};

BYTE codeClearTroopCurGoalThunk[] = {0xE8, 0xEF, 0x25, 0xC0, 0xFF};//dwAddrClearTroopCurGoal - 4A188Ch - 5
BYTE codeClearTroopCurGoalOldThunk[] = {0x83, 0x7C, 0x24, 0x1C, 0xFF};//cmp dword ptr[esp+1Ch],-1
ASM_PATCH patchClearTroopCurGoalThunk[] = {
	{0x4A188C, sizeof(codeClearTroopCurGoalThunk), codeClearTroopCurGoalThunk},
	{0x4A188C, sizeof(codeClearTroopCurGoalOldThunk), codeClearTroopCurGoalOldThunk}};

//move guard troop
DWORD dwAddrMoveGuardTroop = dwAddrStackBottom + 0x6A00;
BYTE codeMoveGuardTroop[] = {
	0x51,                                     //push        ecx
	0x8B, 0x4E, 0x74,                         //mov         ecx,dword ptr [esi+74h]
	0xF6, 0x41, 0x34, 0x05,                   //test        byte ptr [ecx+34h],5
	0x75, 0x18,                               //jne         end
	0x83, 0x7F, 0x0C, 0x26,                   //cmp         dword ptr [edi+0Ch],26h
	0x75, 0x12,                               //jne         end
	0x80, 0x7F, 0x06, 0x03,                   //cmp         byte ptr [edi+6],3
	0x74, 0x0C,                               //je          end
	0xF6, 0x46, 0x21, 0x10,                   //test        byte ptr [esi+21h],10h
	0x74, 0x06,                               //je          end
	0x80, 0x7F, 0x0A, 0x03,                   //cmp         byte ptr [edi+0Ah],3
	0x75, 0x07,                               //jne         find_guarded_troop
	                                          //end:
	0x59,                                     //pop         ecx
	0x68, 0xC0, 0xCC, 0x49, 0x00,             //push        49CCC0h
	0xC3,                                     //ret
	                                          //find_guarded_troop:
	0x57,                                     //push        edi
	0xBD, 0xFF, 0xFF, 0xFF, 0x7F,             //mov         ebp,7FFFFFFFh
	0x8B, 0x99, 0x9C, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [ecx+9Ch]
	                                          //loop_force_troop:
	0x8B, 0x4B, 0x08,                         //mov         ecx,dword ptr [ebx+8]
	0xF6, 0x41, 0x20, 0x02,                   //test        byte ptr [ecx+20h],2
	0x75, 0x42,                               //jne         next_force_troop
	0x83, 0x79, 0x58, 0x26,                   //cmp         dword ptr [ecx+58h],26h
	0x75, 0x3C,                               //jne         next_force_troop
	0x8B, 0x41, 0x50,                         //mov         eax,dword ptr [ecx+50h]
	0x3B, 0x46, 0x50,                         //cmp         eax,dword ptr [esi+50h]
	0x75, 0x34,                               //jne         next_force_troop
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr [ecx+21h],10h
	0x75, 0x2E,                               //jne         next_force_troop
	0xA1, 0x14, 0xFF, 0x43, 0x00,             //mov         eax,[quarter]
	0x39, 0x41, 0x08,                         //cmp         dword ptr [ecx+8],eax
	0x74, 0x24,                               //je          next_force_troop
	0x56,                                     //push        esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,             //mov         eax,get_distance
	0xFF, 0xD0,                               //call        eax
	0x8B, 0x4B, 0x08,                         //mov         ecx,dword ptr [ebx+8]
	0x8B, 0x51, 0x64,                         //mov         edx,dword ptr [ecx+64h]
	0x3B, 0x56, 0x64,                         //cmp         edx,dword ptr [esi+64h]
	0x74, 0x09,                               //je          compare_distance
	0x83, 0xF8, 0x32,                         //cmp         eax,32h
	0x7F, 0x0C,                               //jg          next_force_troop
	0x40,                                     //inc         eax
	0xC1, 0xE0, 0x18,                         //shl         eax,18h
	                                          //compare_distance:
	0x3B, 0xC5,                               //cmp         eax,ebp
	0x7D, 0x04,                               //jge         next_force_troop
	0x8B, 0xE8,                               //mov         ebp,eax
	0x8B, 0xF9,                               //mov         edi,ecx
	                                          //next_force_troop:
	0x8B, 0x1B,                               //mov         ebx,dword ptr [ebx]
	0x85, 0xDB,                               //test        ebx,ebx
	0x75, 0xAF,                               //jne         loop_force_troop
	0x81, 0xFD, 0xFF, 0xFF, 0xFF, 0x7F,       //cmp         ebp,7FFFFFFFh
	0x74, 0x26,                               //je          end2
	0xA1, 0x14, 0xFF, 0x43, 0x00,             //mov         eax,[quarter]
	0x89, 0x47, 0x08,                         //mov         dword ptr [edi+8],eax
	0x81, 0xFD, 0x00, 0x00, 0x00, 0x01,       //cmp         ebp,1000000h
	0x7C, 0x03,                               //jl          test_min_distance
	0xC1, 0xED, 0x18,                         //shr         ebp,18h
	                                          //test_min_distance:
	0x83, 0xFD, 0x14,                         //cmp         ebp,14h
	0x7E, 0x0E,                               //jle         end2
	0xC7, 0x46, 0x7C, 0x00, 0x00, 0x00, 0x00, //mov         dword ptr[esi+7Ch],0
	0x8B, 0x47, 0x78,                         //mov         eax,dword ptr [edi+78h]
	0x89, 0x44, 0x24, 0x10,                   //mov         dword ptr [esp+10h],eax
	                                          //end2:
	0x5F,                                     //pop         edi
	0x59,                                     //pop         ecx
	0x68, 0xC0, 0xCC, 0x49, 0x00,             //push        49CCC0h
	0xC3                                      //ret
};

BYTE codeMoveGuardTroopThunk[] = {0xE8, 0x3A, 0x9A, 0xC0, 0xFF};//dwAddrMoveGuardTroop - 49CFC1h - 5
BYTE codeMoveGuardTroopOldThunk[] = {0xE8, 0xFA, 0xFC, 0xFF, 0xFF};//call 49CCC0h()
ASM_PATCH patchMoveGuardTroopThunk[] = {
	{0x49CFC1, sizeof(codeMoveGuardTroopThunk), codeMoveGuardTroopThunk},
	{0x49CFC1, sizeof(codeMoveGuardTroopOldThunk), codeMoveGuardTroopOldThunk}};

//month table info
DWORD dwAddrMonthTableInfo = dwAddrStackBottom + 0x2FC0;
BYTE codeMonthTableInfo[] = {
	0x81, 0xFF, 0xE8, 0x03, 0x00, 0x00,       //cmp         edi,3E8h
	0x7C, 0x14,                               //jl          end
	0x66, 0x3B, 0x7C, 0x24, 0x34,             //cmp         di,word ptr[esp+34h]
	0x74, 0x0D,                               //je          end
	0x80, 0xFA, 0x0A,                         //cmp         dl,0Ah
	0x7D, 0x08,                               //jge         end
	0xC7, 0x44, 0x24, 0x08, 0x24, 0x9A, 0x61, 0x00,//mov    dword ptr [esp+8],619A24h
	                                          //end:
	0x68, 0xC0, 0xF6, 0x5C, 0x00,             //push        5CF6C0h
	0xC3                                      //ret
};

BYTE codeMonthTableInfoThunk[] = {0xE8, 0x1D, 0x2E, 0xC7, 0xFF};//dwAddrMonthTableInfo - 43019Eh - 5
BYTE codeMonthTableInfoOldThunk[] = {0xE8, 0x1D, 0xF5, 0x19, 0x00};//call 5CF6C0h()
ASM_PATCH patchMonthTableInfoThunk[] = {
	{0x43019E, sizeof(codeMonthTableInfoThunk), codeMonthTableInfoThunk},
	{0x43019E, sizeof(codeMonthTableInfoOldThunk), codeMonthTableInfoOldThunk}};

//use baram array
DWORD dwAddrUseBaramArray = dwAddrStackBottom + 0x3EA0;
BYTE codeUseBaramArray[] = {
	                                          //use_baram_array:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0x8B, 0x71, 0x04,                         //mov         esi,dword ptr [ecx+4]
	                                          //loop_troop:
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0x8B, 0x51, 0x6C,                         //mov         edx,dword ptr [ecx+6Ch]
	0x8A, 0x42, 0x04,                         //mov         al,byte ptr [edx+4]
	0x3C, 0x00,                               //cmp         al,0
	0x75, 0x09,                               //jne         test_array_wimble
	0xBB, 0x12, 0x00, 0x00, 0x00,             //mov         ebx,12h
	0x6A, 0x0F,                               //push        0Fh
	0xEB, 0x0B,                               //jmp         judge_if_baram_array
	                                          //test_array_wimble:
	0x3C, 0x02,                               //cmp         al,2
	0x75, 0x30,                               //jne         next_troop
	0xBB, 0x10, 0x00, 0x00, 0x00,             //mov         ebx,10h
	0x6A, 0x0A,                               //push        0Ah
	                                          //judge_if_baram_array:
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,             //mov         eax,4AEFF0h
	0xFF, 0xD0,                               //call        eax
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x1E,                               //je          next_troop
	0x8B, 0x4E, 0x08,                         //mov         ecx,dword ptr [esi+8]
	0xF6, 0x41, 0x21, 0x10,                   //test        byte ptr [ecx+21h],10h
	0x74, 0x09,                               //je          change_to_baram_array
	0xF7, 0xC6, 0x00, 0x01, 0x00, 0x00,       //test        esi,100h
	0x74, 0x01,                               //je          change_to_baram_array
	0x40,                                     //inc         eax
	                                          //change_to_baram_array:
	0x53,                                     //push        ebx
	0xB8, 0x90, 0x38, 0x45, 0x00,             //mov         eax,453890h
	0xFF, 0xD0,                               //call        eax
	0x5B,                                     //pop         ebx
	0x89, 0x41, 0x6C,                         //mov         dword ptr [ecx+6Ch],eax
	                                          //next_troop:
	0x8B, 0x36,                               //mov         esi,dword ptr [esi]
	0x85, 0xF6,                               //test        esi,esi
	0x75, 0xB0,                               //jne         loop_troop
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//strength killer big animaiton
DWORD dwAddrStrengthKillerBigAnimaiton = dwAddrStackBottom + 0x2A9C;
BYTE codeStrengthKillerBigAnimaiton[] = {
	0xF6, 0x41, 0x4E, 0x01,                   //test        byte ptr [ecx+4Eh],1
	0x75, 0x18,                               //jne         end
	0x85, 0xDB,                               //test        ebx,ebx
	0x74, 0x12,                               //je          no_killer_show
	0xFF, 0x76, 0x34,                         //push        dword ptr [esi+34h]
	0xFF, 0x76, 0x40,                         //push        dword ptr [esi+40h]
	0xFF, 0x76, 0x3C,                         //push        dword ptr [esi+3Ch]
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x60, 0x88, 0x50, 0x00,             //mov         eax,508860h
	0xFF, 0xD0,                               //call        eax
	                                          //no_killer_show:
	0x33, 0xC0,                               //xor         eax,eax
	                                          //end:
	0xC2, 0x04, 0x00                          //ret         4
};

BYTE codeStrengthKillerBigAnimaitonThunk[] = {0xE8, 0x83, 0xC2, 0xB9, 0xFF};//dwAddrStrengthKillerBigAnimaiton - 506814h - 5
BYTE codeStrengthKillerBigAnimaitonOldThunk[] = {0xE8, 0x17, 0x5E, 0xF3, 0xFF};//call 43C630h()
ASM_PATCH patchStrengthKillerBigAnimaitonThunk[] = {
	{0x506814, sizeof(codeStrengthKillerBigAnimaitonThunk), codeStrengthKillerBigAnimaitonThunk},
	{0x506814, sizeof(codeStrengthKillerBigAnimaitonOldThunk), codeStrengthKillerBigAnimaitonOldThunk}};

//weaken long range killer
DWORD dwAddrWeakenLongRangeKiller = dwAddrStackBottom + 0x3F90;
BYTE codeWeakenLongRangeKiller[] = {
	                                          //weaken_long_range_killer:
	0x56,                                     //push        esi
	0x8B, 0xF1,                               //mov         esi,ecx
	0x8B, 0x4D, 0x40,                         //mov         ecx,dword ptr [ebp+40h]
	0xF6, 0x41, 0x20, 0x01,                   //test        byte ptr [ecx+20h],1
	0x74, 0x3A,                               //je          end
	0x8B, 0x45, 0x34,                         //mov         eax,dword ptr [ebp+34h]
	0x3C, 0x06,                               //cmp         al,6
	0x7C, 0x33,                               //jl          end
	0x3C, 0x0B,                               //cmp         al,0Bh
	0x7F, 0x2F,                               //jg          end
	0x3C, 0x08,                               //cmp         al,8
	0x7E, 0x0C,                               //jle         sub_killer_damage
	0x8B, 0x55, 0x3C,                         //mov         edx,dword ptr [ebp+3Ch]
	0x8B, 0x42, 0x6C,                         //mov         eax,dword ptr [edx+6Ch]
	0x80, 0x78, 0x04, 0x08,                   //cmp         byte ptr [eax+4],8
	0x74, 0x1F,                               //je          end
	                                          //sub_killer_damage:
	0x0F, 0xB7, 0x41, 0xE4,                   //movzx       eax,word ptr [ecx-1Ch]
	0x2D, 0x00, 0x08, 0x00, 0x00,             //sub         eax,800h
	0xF7, 0xD8,                               //neg         eax
	0x3D, 0x00, 0x04, 0x00, 0x00,             //cmp         eax,400h
	0x7D, 0x05,                               //jge         get_killer_damage
	0xB8, 0x00, 0x04, 0x00, 0x00,             //mov         eax,400h
	                                          //get_killer_damage:
	0x0F, 0xAF, 0x06,                         //imul        eax,dword ptr [esi]
	0xC1, 0xE8, 0x0B,                         //shr         eax,0Bh
	0x89, 0x06,                               //mov         dword ptr [esi],eax
	                                          //end:
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//update captive prop
DWORD dwAddrUpdateCaptiveProp = dwAddrStackBottom + 0x3FE0;
BYTE codeUpdateCaptiveProp[] = {
	0x52,                                     //push        edx
	0xB8, 0x01, 0x00, 0x00, 0x00,             //mov         eax,1
	0x8B, 0xC8,                               //mov         ecx,eax
	0x33, 0xD2,                               //xor         edx,edx
	                                          //update_fight_coef:
	0x3B, 0xC3,                               //cmp         eax,ebx
	0x7D, 0x07,                               //jge         update_captive_prop
	0x03, 0xD1,                               //add         edx,ecx
	0x41,                                     //inc         ecx
	0x03, 0xC1,                               //add         eax,ecx
	0xEB, 0xF5,                               //jmp         update_fight_coef
	                                          //update_captive_prop:
	0x58,                                     //pop         eax
	0x03, 0xD3,                               //add         edx,ebx
	0xF7, 0xEA,                               //imul        edx
	0xF7, 0xF1,                               //div         eax,ecx
	0x8B, 0xF0,                               //mov         esi,eax
	0xC3                                      //ret
};

BYTE codeUpdateCaptivePropThunk[] = {0xE8, 0xE4, 0x4B, 0xC5, 0xFF};//dwAddrUpdateCaptiveProp - 44F3F7h - 5
BYTE codeUpdateCaptivePropOldThunk[] = {0x8B, 0xF2, 0x0F, 0xAF, 0xF3};//mov esi,edx;imul esi,ebx
ASM_PATCH patchUpdateCaptivePropThunk[] = {
	{0x44F3F7, sizeof(codeUpdateCaptivePropThunk), codeUpdateCaptivePropThunk},
	{0x44F3F7, sizeof(codeUpdateCaptivePropOldThunk), codeUpdateCaptivePropOldThunk}};

//control march troop
DWORD dwAddrControlMarchTroop = dwAddrStackBottom + 0x6B00;
BYTE codeControlMarchTroop[] = {
	0x53,                                     //push        ebx
	0x57,                                     //push        edi
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0xC0, 0x61, 0x43, 0x00,             //mov         eax,4361C0h
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xF8,                               //mov         edi,eax
	0x8B, 0x9E, 0x88, 0x00, 0x00, 0x00,       //mov         ebx,dword ptr [esi+88h]
	0x03, 0x9E, 0x8C, 0x00, 0x00, 0x00,       //add         ebx,dword ptr [esi+8Ch]
	0x8B, 0x44, 0x24, 0x34,                   //mov         eax,dword ptr [esp+34h]
	0x8B, 0x88, 0x9C, 0x00, 0x00, 0x00,       //mov         ecx,dword ptr [eax+9Ch]
	                                          //loop_force_troop:
	0x85, 0xC9,                               //test        ecx,ecx
	0x74, 0x2E,                               //je          end_force_troop
	0x8B, 0x51, 0x08,                         //mov         edx,dword ptr [ecx+8]
	0xF6, 0x42, 0x20, 0x02,                   //test        byte ptr [edx+20h],2
	0x75, 0x21,                               //jne         next_force_troop
	0x80, 0x7A, 0x58, 0x27,                   //cmp         byte ptr [edx+58h],27h
	0x75, 0x1B,                               //jne         next_force_troop
	0x8B, 0x46, 0x04,                         //mov         eax,dword ptr [esi+4]
	0x39, 0x42, 0x50,                         //cmp         dword ptr [edx+50h],eax
	0x75, 0x13,                               //jne         next_force_troop
	0x03, 0x5A, 0x30,                         //add         ebx,dword ptr [edx+30h]
	0x03, 0x5A, 0x34,                         //add         ebx,dword ptr [edx+34h]
	0x3B, 0xDF,                               //cmp         ebx,edi
	0x7E, 0x09,                               //jle         next_force_troop
	0x8B, 0x42, 0x64,                         //mov         eax,dword ptr [edx+64h]
	0x8B, 0x40, 0x04,                         //mov         eax,dword ptr [eax+4]
	0x89, 0x42, 0x50,                         //mov         dword ptr [edx+50h],eax
	                                          //next_force_troop:
	0x8B, 0x09,                               //mov         ecx,dword ptr [ecx]
	0xEB, 0xCE,                               //jmp         loop_force_troop
	                                          //end_force_troop:
	0x5F,                                     //pop         edi
	0x5B,                                     //pop         ebx
	0x68, 0x40, 0x58, 0x40, 0x00,             //push        405840h
	0xC3                                      //ret
};

BYTE codeControlMarchTroopThunk[] = {0xE8, 0xB7, 0xD0, 0xC6, 0xFF};//dwAddrControlMarchTroop - 439A44h - 5
BYTE codeControlMarchTroopOldThunk[] = {0xE8, 0xF7, 0xBD, 0xFC, 0xFF};//call 405840h()
ASM_PATCH patchControlMarchTroopThunk[] = {
	{0x439A44, sizeof(codeControlMarchTroopThunk), codeControlMarchTroopThunk},
	{0x439A44, sizeof(codeControlMarchTroopOldThunk), codeControlMarchTroopOldThunk}};

//year table info
DWORD dwAddrYearTableInfo = dwAddrStackBottom + 0x7E8;
BYTE codeYearTableInfo[] = {
	0x0F, 0xB7, 0x44, 0x08, 0x0C,             //movzx       eax,[eax+ecx+0Ch]
	0x85, 0xC0,                               //test        eax,eax
	0x75, 0x02,                               //jne         adjust_year
	0x48,                                     //dec         eax
	0xC3,                                     //ret
	                                          //adjust_year:
	0x05, 0x23, 0x01, 0x00, 0x00,             //add         eax,123h
	0x85, 0xC0,                               //test        eax,eax
	0x7D, 0x02,                               //jge         end
	0xF7, 0xD8,                               //neg         eax
	                                          //end:
	0xC3                                      //ret
};

BYTE codeYearTableInfoThunk[] = {0xE8, 0xAE, 0x55, 0xC5, 0xFF};//dwAddrYearTableInfo - 44B235h - 5
BYTE codeYearTableInfoOldThunk[] = {0x66, 0x8B, 0x44, 0x08, 0x0C};//mov ax,[eax+ecx+0Ch]
ASM_PATCH patchYearTableInfoThunk[] = {
	{0x44B235, sizeof(codeYearTableInfoThunk), codeYearTableInfoThunk},
	{0x44B235, sizeof(codeYearTableInfoOldThunk), codeYearTableInfoOldThunk}};

//rob food
DWORD dwAddrRobFood = dwAddrStackBottom + 0x7B00;
BYTE codeRobFood[] = {
	0x8B, 0x73, 0x74,							//mov         esi,dword ptr [ebx+74h]
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x20, 0xF7, 0x43, 0x00,				//mov         eax,43F720h
	0xFF, 0xD0,									//call        eax
	0x85, 0xC0,									//test        eax,eax
	0x7E, 0x1E,									//jle         end
	0x80, 0x3D, 0x1C, 0xFF, 0x43, 0x00,	0x00,	//cmp         byte ptr [sub_rob_food],0
	0x74, 0x15,									//je          end
	0xF6, 0x47, 0x34, 0x01,						//test        byte ptr [edi+34h],1
	0x74, 0x0F,									//je          end
	0xF6, 0x43, 0x20, 0x01,						//test        byte ptr [ebx+20h],1
	0x74, 0x09,									//je          end
	0x8B, 0x4B, 0x64,							//mov         ecx,dword ptr [ebx+64h]
	0x80, 0x79, 0x06, 0x05,						//cmp         byte ptr [ecx+6],5
	0x74, 0x01,									//je          sub_rob_food
												//end:
	0xC3,										//ret
												//sub_rob_food:
	0x50,										//push        eax
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0xB0, 0x4E, 0x0A, 0x00,				//mov         eax,get_force_military_pop
	0xFF, 0xD0,									//call        eax
	0x59,										//pop         ecx
	0xC1, 0xE8, 0x0E,							//shr         eax,0Eh
	0x83, 0xF8, 0x7F,							//cmp         eax,7Fh
	0x7E, 0x05,									//jle         normal_military_pop
	0xC1, 0xE1, 0x02,							//shl         ecx,2
	0xEB, 0x20,									//jmp         update_military_pop
												//normal_military_pop:
	0x8B, 0xD1,									//mov         edx,ecx
	0x3A, 0x05, 0xC6, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+6]
	0x7C, 0x16,									//jl          update_military_pop
	0x03, 0xCA,									//add         ecx,edx
	0x3A, 0x05, 0xC7, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+7]
	0x7C, 0x0C,									//jl          update_military_pop
	0x03, 0xCA,									//add         ecx,edx
	0x3A, 0x05, 0xC8, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+8]
	0x7C, 0x02,									//jl          update_military_pop
	0x03, 0xCA,									//add         ecx,edx
												//update_military_pop:
	0x8B, 0xC1,									//mov         eax,ecx
												//end:
	0xC3										//ret
};

BYTE codeRobFoodThunk[] = {0xE8, 0x5F, 0xF4, 0xC4, 0xFF};//dwAddrRobFood - 45869Ch - 5
BYTE codeRobFoodOldThunk[] = {0xE8, 0x7F, 0x70, 0xFE, 0xFF};//call 43F720h()
ASM_PATCH patchRobFoodThunk[] = {
	{0x45869C, sizeof(codeRobFoodThunk), codeRobFoodThunk},
	{0x45869C, sizeof(codeRobFoodOldThunk), codeRobFoodOldThunk}};

//retreat building condition
DWORD dwAddrRetreatBuildingCondition = dwAddrStackBottom + 0x21F0;
BYTE codeRetreatBuildingCondition[] = {
	                                          //retreat_building_condition:
	0x8B, 0x44, 0x24, 0x04,                   //mov         eax,[esp+4]
	0x8B, 0x08,                               //mov         ecx,[eax]
	0x51,                                     //push        ecx
	0xB8, 0x10, 0xF2, 0x4A, 0x00,             //mov         eax,4AF210h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0xC3                                      //ret
};

BYTE codeRetreatBuildingConditionThunk[] = {0xF0, 0x21, 0x0A, 0x00};//retreat_building_condition
BYTE codeRetreatBuildingConditionOldThunk[] = {0x00, 0xE6, 0x49, 0x00};//49E600h()
ASM_PATCH patchRetreatBuildingConditionThunk[] = {
	{0x49EA1B, sizeof(codeRetreatBuildingConditionThunk), codeRetreatBuildingConditionThunk},
	{0x49EA1B, sizeof(codeRetreatBuildingConditionOldThunk), codeRetreatBuildingConditionOldThunk}};

//killer check bug
DWORD dwAddrKillerCheckBug = dwAddrStackBottom + 0x7100;
BYTE codeKillerCheckBug[] = {
	0x59,                                     //pop         ecx
	0xB8, 0x40, 0x58, 0x40, 0x00,             //mov         eax,405840h
	0xFF, 0xD0,                               //call        eax
	0x59,                                     //pop         ecx
	0xBA, 0x23, 0x2D, 0x47, 0x00,             //mov         edx,472D23h
	0x85, 0xC0,                               //test        eax,eax
	0x74, 0x12,                               //je          killer_check_fail
	0x8A, 0x46, 0x04,                         //mov         al,byte ptr [esi+4]
	0x3C, 0x0B,                               //cmp         al,0Bh
	0x7E, 0x08,                               //jle         killer_check_ok
	0x3C, 0x17,                               //cmp         al,17h
	0x7C, 0x07,                               //jl          killer_check_fail
	0x3C, 0x1E,                               //cmp         al,1Eh
	0x7F, 0x03,                               //jg          killer_check_fail
	                                          //killer_check_ok:
	0x83, 0xC2, 0x04,                         //add         edx,4
	                                          //killer_check_fail:
	0x52,                                     //push        edx
	0xC3                                      //ret
};

BYTE codeKillerCheckBugThunk[] = {0xE8, 0xF9, 0x43, 0xC3, 0xFF};//dwAddrKillerCheckBug - 472D02Ch - 5
BYTE codeKillerCheckBugOldThunk[] = {0xE8, 0x39, 0x2B, 0xF9, 0xFF};//call 405840h()
ASM_PATCH patchKillerCheckBugThunk[] = {
	{0x472D02, sizeof(codeKillerCheckBugThunk), codeKillerCheckBugThunk},
	{0x472D02, sizeof(codeKillerCheckBugOldThunk), codeKillerCheckBugOldThunk}};

//chaos power coef
DWORD dwAddrChaosPowerCoef = dwAddrStackBottom + 0x4D40;
BYTE codeChaosPowerCoef[] = {
	0x51,									  //push        ecx
	0x83, 0xFB, 0x01,						  //cmp         ebx,1
	0x7E, 0x06,								  //jle         get_chaos_killer
	0x83, 0xF9, 0x1E,						  //cmp         ecx,1Eh
	0x7C, 0x01,								  //jl          get_chaos_killer
	0x4B,									  //dec         ebx
											  //get_chaos_killer:
	0x6A, 0x17,								  //push        17h
	0xB8, 0x20, 0x37, 0x45, 0x00,			  //mov         eax,453720h
	0xFF, 0xD0,								  //call        eax
	0x5A,									  //pop         edx
    0x8B, 0x50, 0x64,                         //mov         edx, dword ptr [eax+64]  
    0x85, 0xD2,                               //test        edx, edx
    0x75, 0x08,                               //jnz         test_chaos_coef
    0x68, 0xB7, 0x4F, 0x50, 0x00,             //push        504FB7
    0xC2, 0x08, 0x00,	                      //retn        8
	                                          //test_chaos_coef: 
	0xB9, 0x28, 0x00, 0x00, 0x00,			  //mov         ecx,28h
	0x2B, 0xCA,			        			  //sub         ecx,edx
	0x83, 0xF9, 0x10,						  //cmp         ecx,10h
	0x7D, 0x02,								  //jge         get_chaos_coef
	0xB1, 0x10,								  //mov         cl,10h
											  //get_chaos_coef:
	0xB8, 0x67, 0x66, 0x66, 0x66,			  //mov         eax,66666667h
	0x99,									  //cdq
	0xF7, 0xF9,								  //idiv        eax,ecx
	0x6B, 0xC0, 0x14,						  //imul        eax,eax,14h
	0x59,									  //pop         ecx
	0xC3									  //ret
};

BYTE codeChaosPowerCoefThunk[] = {0xE8, 0x97, 0xFD, 0xB9, 0xFF};//dwAddrChaosPowerCoef - 504FA4h - 5
BYTE codeChaosPowerCoefOldThunk[] = {0xB8, 0x67, 0x66, 0x66, 0x66};//mov eax,66666667h
ASM_PATCH patchChaosPowerCoefThunk[] = {
	{0x504FA4, sizeof(codeChaosPowerCoefThunk), codeChaosPowerCoefThunk},
	{0x504FA4, sizeof(codeChaosPowerCoefOldThunk), codeChaosPowerCoefOldThunk}};

//clear second killer person
DWORD dwAddrClearSecondKillerPerson = dwAddrStackBottom + 0x58F0;
BYTE codeClearSecondKillerPerson[] = {
	0x33, 0xC0,								  //xor         eax,eax
	0xA3, 0xB1, 0xF4, 0x43, 0x00,			  //mov         [second_killer_person],eax
	0x68, 0x00, 0xDF, 0x4F, 0x00,			  //push        4FDF00h
	0xC3									  //ret
};

BYTE codeClearSecondKillerPersonThunk[] = {0xE8, 0x57, 0x6F, 0xBA, 0xFF};//dwAddrClearSecondKillerPerson - 4FE994h - 5
BYTE codeClearSecondKillerPersonOldThunk[] = {0xE8, 0x67, 0xF5, 0xFF, 0xFF};//call 4FDF00h()
ASM_PATCH patchClearSecondKillerPersonThunk[] = {
	{0x4FE994, sizeof(codeClearSecondKillerPersonThunk), codeClearSecondKillerPersonThunk},
	{0x4FE994, sizeof(codeClearSecondKillerPersonOldThunk), codeClearSecondKillerPersonOldThunk}};

//skip arrive day
DWORD dwAddrSkipArriveDay = dwAddrStackBottom + 0x7300;
BYTE codeSkipArriveDay[] = {
	0x8B, 0x51, 0x74,							//mov         edx,dword ptr [ecx+74h]
	0xF6, 0x42, 0x34, 0x01,						//test        byte ptr [edx+34h],1
	0x74, 0x16,									//je          normal
	0x83, 0x79, 0x54, 0xFF,						//cmp         dword ptr[ecx+54h],-1
	0x75, 0x10,									//jne         normal
	0x8B, 0x44, 0x24, 0x04,						//mov         eax,[esp+4]
	0x8B, 0x80, 0xCC, 0x00, 0x00, 0x00,			//mov         eax,[eax+0CCh]
	0xF6, 0x40, 0x0D, 0x01,						//test        byte ptr[eax+0Dh],1
	0x74, 0x06,									//je          get_skip_arrive_day
												//normal:
	0x68, 0x70, 0x88, 0x46, 0x00,				//push        468870h
	0xC3,										//ret
												//get_skip_arrive_day:
	0x56,										//push        esi
	0x57,										//push        edi
	0x53,										//push        ebx
	0x55,										//push        ebp
	0x8B, 0x6C, 0x24, 0x14,						//mov         ebp,[esp+14h]
	0x81, 0xEC, 0xD0, 0x00, 0x00, 0x00,			//sub         esp,0D0h
	0x8B, 0xF1,									//mov         esi,ecx
	0xFF, 0x71, 0x50,							//push        dword ptr[ecx+50h]
	0xB8, 0xC0, 0x37, 0x45, 0x00,				//mov         eax,4537C0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x85, 0xC0,									//test        eax,eax
	0xBF, 0x64, 0x00, 0x00, 0x00,				//mov         edi,64h
	0x0F, 0x84, 0x6D, 0x01, 0x00, 0x00,			//je          end
	0x8B, 0xC8,									//mov         ecx,eax
	0x8B, 0x01,									//mov         eax,[ecx]
	0xFF, 0x90,	0xB8, 0x00, 0x00, 0x00,			//call        [eax+B8h]
	0x8B, 0xF8,									//mov         edi,eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,				//mov         eax,4734B0h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x20,						//lea         ecx,[esp+20h]
	0xB8, 0xB0, 0x34, 0x47, 0x00,				//mov         eax,4734B0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0x9E, 0x80, 0x00, 0x00, 0x00,			//mov         ebx,[esi+80h]
	0x85, 0xDB,									//test        ebx,ebx
	0x75, 0x1B,									//jne         skip_point
	0x8D, 0x4C, 0x24, 0x40,						//lea         ecx,[esp+40h]
	0x57,										//push        edi
	0x56,										//push        esi
	0xB8, 0x30, 0xA3, 0x47, 0x00,				//mov         eax,47A330h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x40,						//lea         ecx,[esp+40h]
	0x54,										//push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0xEB, 0x7B,									//jmp         filter_map_block
												//skip_point:
	0x53,										//push        ebx
	0xFF, 0x76, 0x78,							//push        dword ptr [esi+78h]
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0x70, 0xD0, 0x45, 0x00,				//mov         eax,45D070h
	0xFF, 0xD0,									//call        eax
	0x50,										//push        eax
	0x56,										//push        esi
	0x8D, 0x4C, 0x24, 0x50,						//lea         ecx,[esp+50h]
	0xB8, 0xC0, 0xA3, 0x47, 0x00,				//mov         eax,47A3C0h
	0xFF, 0xD0,									//call        eax
	0x57,										//push        edi
	0x53,										//push        ebx
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0x70, 0xD0, 0x45, 0x00,				//mov         eax,45D070h
	0xFF, 0xD0,									//call        eax
	0x50,										//push        eax
	0x56,										//push        esi
	0x8D, 0x8C, 0x24, 0x90, 0x00, 0x00, 0x00,	//lea         ecx,[esp+90h]
	0xB8, 0xC0, 0xA3, 0x47, 0x00,				//mov         eax,47A3C0h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x40,						//lea         ecx,[esp+40h]
	0x54,										//push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x8C, 0x24, 0x80, 0x00, 0x00, 0x00,	//lea         ecx,[esp+80h]
	0x8D, 0x44, 0x24, 0x20,						//lea         eax,[esp+20h]
	0x50,										//push        eax
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0x80, 0x7B, 0x43, 0x00,				//mov         eax,437B80h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0x8D, 0x44, 0x24, 0x20,						//lea         eax,[esp+20h]
	0x6A, 0x30,									//push        30h
	0x50,										//push        eax
	0xB8, 0x80, 0xEF, 0x46, 0x00,				//mov         eax,46EF80h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x8C, 0x24, 0x80, 0x00, 0x00, 0x00,	//lea         ecx,[esp+80h]
	0xB8, 0x20, 0x9F, 0x47, 0x00,				//mov         eax,479F20h
	0xFF, 0xD0,									//call        eax	
												//filter_map_block:
	0x83, 0x7C, 0x24, 0x0C, 0x01,				//cmp         dword ptr[esp+0Ch],1
	0x7E, 0x09,									//jle         get_goal_building_rect
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0x10, 0x82, 0x51, 0x00,				//mov         eax,518210h
	0xFF, 0xD0,									//call        eax
												//get_goal_building_rect:
	0x8B, 0xCD,									//mov         ecx,ebp
	0x8D, 0xBC, 0x24, 0xC0, 0x00, 0x00, 0x00,	//lea         edi,[esp+0C0h]
	0x57,										//push        edi
	0xB8, 0x40, 0xA9, 0x44, 0x00,				//mov         eax,44A940h
	0xFF, 0xD0,									//call        eax
	0x6A, 0x02,									//push        2
	0x6A, 0x02,									//push        2
	0x57,										//push        edi
	0xFF, 0x15, 0x78, 0xF3, 0x5F, 0x00,			//call        dword ptr [5FF378h]
	0x33, 0xED,									//xor         ebp,ebp
	0x8B, 0x5C, 0x24, 0x04,						//mov         ebx,dword ptr [esp+4]
												//loop_map_block:
	0x45,										//inc         ebp
	0x8B, 0x4B, 0x08,							//mov         ecx,dword ptr [ebx+8]
	0x0F, 0xB7, 0x41, 0x04,						//movzx       eax,word ptr [ecx+4]
	0x99,										//cdq
	0xB9, 0xC8, 0x00, 0x00, 0x00,				//mov         ecx,0C8h
	0xF7, 0xF9,									//idiv        eax,ecx
	0x50,										//push        eax
	0x52,										//push        edx
	0x57,										//push        edi
	0xFF, 0x15, 0x6C, 0xF3, 0x5F, 0x00,			//call        dword ptr [5FF36Ch]
	0x85, 0xC0,									//test        eax,eax
	0x75, 0x12,									//jne         through_goal_building
	0x83, 0xFD, 0x20,							//cmp         ebp,20h
	0x7D, 0x06,									//jge         end_loop_map_block
	0x8B, 0x1B,									//mov         ebx,dword ptr [ebx]
	0x85, 0xDB,									//test        ebx,ebx
	0x75, 0xD8,									//jne         loop_map_block
												//end_loop_map_block:
	0xBF, 0x64, 0x00, 0x00, 0x00,				//mov         edi,64h
	0xEB, 0x2D,									//jmp         free_obj
												//through_goal_building:
	0x8B, 0xCC,									//mov         ecx,esp
	0x55,										//push        ebp
	0xB8, 0xB0, 0xEE, 0x46, 0x00,				//mov         eax,46EEB0h
	0xFF, 0xD0,									//call        eax
												//get_troop_speed:
	0x8B, 0xFC,									//mov         edi,esp
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xD0, 0x47, 0x46, 0x00,				//mov         eax,4647D0h
	0xFF, 0xD0,									//call        eax
	0x50,										//push        eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x40, 0x47, 0x46, 0x00,				//mov         eax,464740h
	0xFF, 0xD0,									//call        eax
	0x50,										//push        eax
	0x57,										//push        edi
	0xB8, 0xC0, 0xA4, 0x44, 0x00,				//mov         eax,44A4C0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x0C,							//add         esp,0Ch
	0x8B, 0xF8,									//mov         edi,eax
												//free_obj:
	0x8D, 0x4C, 0x24, 0x40,						//lea         ecx,[esp+40h]
	0xB8, 0x20, 0x9F, 0x47, 0x00,				//mov         eax,479F20h
	0xFF, 0xD0,									//call        eax

	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,				//mov         eax,5180E0h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x20,						//lea         ecx,[esp+20h]
	0xB8, 0xE0, 0x80, 0x51, 0x00,				//mov         eax,5180E0h
	0xFF, 0xD0,									//call        eax
												//end:
	0x8B, 0xC7,									//mov         eax,edi
	0x81, 0xC4, 0xD0, 0x00, 0x00, 0x00,			//add         esp,0D0h
	0x5D,										//pop         ebp
	0x5B,										//pop         ebx
	0x5F,										//pop         edi
	0x5E,										//pop         esi
	0xC2, 0x04, 0x00							//ret         4
};

BYTE codeSkipArriveDayThunk[] = {0xE8, 0xF2, 0x4D, 0xC0, 0xFF};//dwAddrSkipArriveDay - 4A2509h - 5
BYTE codeSkipArriveDayOldThunk[] = {0xE8, 0x62, 0x63, 0xFC, 0xFF};//call 468870h()
ASM_PATCH patchSkipArriveDayThunk[] = {
	{0x4A2509, sizeof(codeSkipArriveDayThunk), codeSkipArriveDayThunk},
	{0x4A2509, sizeof(codeSkipArriveDayOldThunk), codeSkipArriveDayOldThunk}};

//build arrive day
DWORD dwAddrBuildArriveDay = dwAddrStackBottom + 0x7140;
BYTE codeBuildArriveDay[] = {
	0x51,										//push        ecx
	0xFF, 0x77, 0x28,							//push        dword ptr[edi+28h]
	0xB8, 0xF0, 0x3C, 0x47, 0x00,				//mov         eax,473CF0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0x40, 0x74,							//mov         eax,[eax+74h]
	0xF6, 0x40, 0x0D, 0x01,						//test        byte ptr[eax+0Dh],1
	0x59,										//pop         ecx
	0x8B, 0x7E, 0x78,							//mov         edi,dword ptr [esi+78h]
	0x75, 0x0A,									//jne         normal
	0x8B, 0x86, 0x80, 0x00, 0x00, 0x00,			//mov         eax,dword ptr [esi+80h]
	0x85, 0xC0,									//test        eax,eax
	0x75, 0x0A,									//jne         skip_path_obj
												//normal:
	0x89, 0x7C, 0x24, 0x04,						//mov         dword ptr [esp+4],edi
	0x68, 0x70, 0xA3, 0x47, 0x00,				//push        47A370h
	0xC3,										//ret
												//skip_path_obj:
	0x53,										//push        ebx
	0x83, 0xEC, 0x20,							//sub         esp,20h
	0x8B, 0xD9,									//mov         ebx,ecx
	0x55,										//push        ebp
	0x50,										//push        eax
	0x6A, 0x00,									//push        0
	0x56,										//push        esi
	0xB8, 0xC0, 0xA3, 0x47, 0x00,				//mov         eax,47A3C0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xB0, 0x34, 0x47, 0x00,				//mov         eax,4734B0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCB,									//mov         ecx,ebx
	0x54,										//push        esp
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCB,									//mov         ecx,ebx
	0xB8, 0x20, 0x9F, 0x47, 0x00,				//mov         eax,479F20h
	0xFF, 0xD0,									//call        eax
	0xFF, 0xB6, 0x80, 0x00, 0x00, 0x00,			//push        dword ptr[esi+80h]
	0x57,										//push        edi
	0x6A, 0x00,									//push        0
	0x56,										//push        esi
	0x8B, 0xCB,									//mov         ecx,ebx
	0xB8, 0xC0, 0xA3, 0x47, 0x00,				//mov         eax,47A3C0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCB,									//mov         ecx,ebx
	0x8D, 0x44, 0x24, 0x4C,						//lea         eax,[esp+4Ch]
	0x50,										//push        eax
	0xB8, 0x90, 0x82, 0x47, 0x00,				//mov         eax,478290h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0x10, 0x82, 0x51, 0x00,				//mov         eax,518210h
	0xFF, 0xD0,									//call        eax
	0x8D, 0x4C, 0x24, 0x4C,						//lea         ecx,[esp+4Ch]
	0x8B, 0xC4,									//mov         eax,esp
	0x6A, 0x7F,									//push        7Fh
	0x50,										//push        eax
	0xB8, 0x80, 0xEF, 0x46, 0x00,				//mov         eax,46EF80h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,				//mov         eax,5180E0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x20,							//add         esp,20h
	0x5B,										//pop         ebx
	0x68, 0xBC, 0x2D, 0x4A, 0x00,				//push        4A2DBCh
	0xC2, 0x0C, 0x00							//ret         0Ch
};

BYTE codeBuildArriveDayThunk[] = {0xE8, 0x9D, 0x43, 0xC0, 0xFF};//dwAddrBuildArriveDay - 4A2D9Eh - 5
BYTE codeBuildArriveDayOldThunk[] = {0xE8, 0xCD, 0x75, 0xFD, 0xFF};//call 47A370h()
ASM_PATCH patchBuildArriveDayThunk[] = {
	{0x4A2D9E, sizeof(codeBuildArriveDayThunk), codeBuildArriveDayThunk},
	{0x4A2D9E, sizeof(codeBuildArriveDayOldThunk), codeBuildArriveDayOldThunk}};

//judge attack build
DWORD dwAddrJudgeAttackBuild = dwAddrStackBottom + 0x74D0; 
BYTE codeJudgeAttackBuild[] = {
	0x8B, 0x46, 0x74,							//mov         eax,dword ptr [esi+74h]
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x74, 0x13,									//je          normal
	0x8B, 0x84, 0x24, 0xFC, 0x00, 0x00, 0x00,	//mov         eax,dword ptr [esp+0FCh]
	0x8B, 0x80, 0xCC, 0x00, 0x00, 0x00,			//mov         eax,dword ptr [eax+0CCh]
	0xF6, 0x40, 0x0D, 0x01,						//test        byte ptr [eax+0Dh],1
	0x74, 0x04,									//je          judge_attack_build
												//normal:
	0x8B, 0x46, 0x30,							//mov         eax,dword ptr [esi+30h]
	0xC3,										//ret
												//judge_attack_build:
	0x8D, 0x44, 0x24, 0x60,						//lea         eax,[esp+60h]
	0x50,										//push        eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x00, 0x75, 0x0A, 0x00,				//mov         eax,get_build_soldier
	0xFF, 0xD0,									//call        eax
	0xC3										//ret
};

BYTE codeJudgeAttackBuildThunk[] = {0xE8, 0x7D, 0x45, 0xC0, 0xFF, 0x90};//dwAddrJudgeAttackBuild - 4A2F4Eh - 5
BYTE codeJudgeAttackBuildOldThunk[] = {0xFF, 0x90, 0x80, 0x00, 0x00, 0x00};//call [eax+80h]
ASM_PATCH patchJudgeAttackBuildThunk[] = {
	{0x4A2F4E, sizeof(codeJudgeAttackBuildThunk), codeJudgeAttackBuildThunk},
	{0x4A2F4E, sizeof(codeJudgeAttackBuildOldThunk), codeJudgeAttackBuildOldThunk}};

//get_build_soldier
DWORD dwAddrGetBuildSoldier = dwAddrStackBottom + 0x7500;
BYTE codeGetBuildSoldier[] = {
												//get_build_soldier:
	0x56,										//push        esi
	0x57,										//push        edi
	0x53,										//push        ebx
	0x55,										//push        ebp
	0x8B, 0xF1,									//mov         esi,ecx
	0x8B, 0x5E, 0x30,							//mov         ebx,dword ptr [esi+30h]
	0xBF, 0xB0, 0x93, 0x4B, 0x01,				//mov         edi,14B93B0h
	0x8B, 0x6C, 0x24, 0x14,						//mov         ebp,[esp+14h]
												//loop_player_troop:
	0x8B, 0x46, 0x74,							//mov         eax,dword ptr [esi+74h]
	0x39, 0x47, 0x74,							//cmp         dword ptr [edi+74h],eax
	0x75, 0x6F,									//jne         next_player_troop
	0xF6, 0x47, 0x20, 0x02,						//test        byte ptr [edi+20h],2
	0x75, 0x69,									//jne         next_player_troop
	0x3B, 0xFE,									//cmp         edi,esi
	0x74, 0x65,									//je          next_player_troop
	0x8B, 0x47, 0x6C,							//mov         eax,[edi+6Ch]
	0x80, 0x78, 0x04, 0x07,						//cmp         byte ptr[eax+4],7
	0x7F, 0x5C,									//jg          next_player_troop
	0x8B, 0xCF,									//mov         ecx,edi
	0x56,										//push        esi
	0xB8, 0x80, 0x0A, 0x0A, 0x00,				//mov         eax,get_distance
	0xFF, 0xD0,									//call        eax
	0x83, 0xF8, 0x28,							//cmp         eax,28h
	0x7F, 0x4D,									//jg          next_player_troop
	0xF6, 0x47, 0x21, 0x10,						//test        byte ptr[edi+21h],10h
	0x75, 0x44,									//jne         add_troop_soldier
	0xF6, 0x46, 0x22, 0x08,						//test        byte ptr[esi+22h],8
	0x74, 0x3E,									//je          add_troop_soldier
	0x80, 0x7F, 0x56, 0x03,						//cmp         byte ptr[edi+56h],3
	0x75, 0x19,									//jne         check_troop_goal
	0xFF, 0x77, 0x54,							//push        dword ptr[edi+54h]
	0xB8, 0xC0, 0x37, 0x45, 0x00,				//mov         eax,4537C0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x50,										//push        eax
	0x8B, 0xCD,									//mov         ecx,ebp
	0xB8, 0x60, 0xEB, 0x46, 0x00,				//mov         eax,46EB60h
	0xFF, 0xD0,									//call        eax
	0x85, 0xC0,									//test        eax,eax
	0x75, 0x1F,									//jne         add_troop_soldier
												//check_troop_goal:
	0x80, 0x7F, 0x52, 0x03,						//cmp         byte ptr[edi+52h],3
	0x75, 0x1C,									//jne         next_player_troop
	0xFF, 0x77, 0x50,							//push        dword ptr[edi+50h]
	0xB8, 0xC0, 0x37, 0x45, 0x00,				//mov         eax,4537C0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x50,										//push        eax
	0x8B, 0xCD,									//mov         ecx,ebp
	0xB8, 0x60, 0xEB, 0x46, 0x00,				//mov         eax,46EB60h
	0xFF, 0xD0,									//call        eax
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x03,									//je          next_player_troop
												//add_troop_soldier:
	0x03, 0x5F, 0x30,							//add         ebx,dword ptr [edi+30h]
												//next_player_troop:
	0x81, 0xC7, 0x04, 0x01, 0x00, 0x00,			//add         edi,104h
	0x81, 0xFF, 0xF8, 0xF2, 0x4E, 0x01,			//cmp         edi,14EF2F8h
	0x0F, 0x8C, 0x77, 0xFF, 0xFF, 0xFF,			//jl          loop_player_troop
	0x8B, 0xC3,									//mov         eax,ebx
	0x5D,										//pop         ebp
	0x5B,										//pop         ebx
	0x5F,										//pop         edi
	0x5E,										//pop         esi
	0xC2, 0x04, 0x00							//ret         4
};

//attack_player_build
DWORD dwAddrAttackPlayerBuild = dwAddrStackBottom + 0x7600;
BYTE codeAttackPlayerBuild[] = {
												//attack_player_build:
	0x55,										//push        ebp
	0x53,										//push        ebx
	0x83, 0xEC, 0x20,							//sub         esp,20h
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xC0, 0x3C, 0x47, 0x00,				//mov         eax,473CC0h
	0xFF, 0xD0,									//call        eax
	0x33, 0xDB,									//xor         ebx,ebx
	0xBD, 0xB0, 0x93, 0x4B, 0x01,				//mov         ebp,14B93B0h
												//loop_attack_build_troop:
	0x8B, 0x47, 0x04,							//mov         eax,dword ptr [edi+4]
	0x39, 0x45, 0x50,							//cmp         dword ptr [ebp+50h],eax
	0x75, 0x13,									//jne         next_attack_build_troop
	0xF6, 0x45, 0x20, 0x02,						//test        byte ptr [ebp+20h],2
	0x75, 0x0D,									//jne         next_attack_build_troop
	0x03, 0x5D, 0x30,							//add         ebx,dword ptr [ebp+30h]
	0x8B, 0xCC,									//mov         ecx,esp
	0x55,										//push        ebp
	0xB8, 0x70, 0xEF, 0x46, 0x00,				//mov         eax,46EF70h
	0xFF, 0xD0,									//call        eax
												//next_attack_build_troop:
	0x81, 0xC5, 0x04, 0x01, 0x00, 0x00,			//add         ebp,104h
	0x81, 0xFD, 0xF8, 0xF2, 0x4E, 0x01,			//cmp         ebp,14EF2F8h
	0x7C, 0xD7,									//jl          loop_attack_build_troop
	0x54,										//push        esp
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0x00, 0x75, 0x0A, 0x00,				//mov         eax,get_build_soldier
	0xFF, 0xD0,									//call        eax
	0x3B, 0xD8,									//cmp         ebx,eax
	0x7D, 0x24,									//jge         try_retreat_attack_troop
	0x2B, 0x47, 0x30,							//sub         eax,dword ptr [edi+30h]
	0x6B, 0xC0, 0x0A,							//imul        eax,eax,0Ah
	0xC1, 0xE8, 0x04,							//shr         eax,4
	0x3B, 0xC3,									//cmp         eax,ebx
	0x7C, 0x15,									//jl          skip_end
	0x8B, 0x6C, 0x24, 0x04,						//mov         ebp,dword ptr [esp+4]
												//loop_retreat_attack_troop:
	0x8B, 0x4D, 0x08,							//mov         ecx,dword ptr [ebp+8]
	0xB8, 0xD0, 0x00, 0x0A, 0x00,				//mov         eax,retreat_soldier_troop
	0xFF, 0xD0,									//call        eax
	0x8B, 0x6D, 0x00,							//mov         ebp,dword ptr [ebp]
	0x85, 0xED,									//test        ebp,ebp
	0x75, 0xEF,									//jne         loop_retreat_attack_troop
												//skip_end:
	0xEB, 0x1D,									//jmp         end
												//try_retreat_attack_troop:
	0x8B, 0xE8,									//mov         ebp,eax
	0x8B, 0x7C, 0x24, 0x04,						//mov         edi,dword ptr [esp+4]
												//loop_retreat_part_troop:
	0x8B, 0x4F, 0x08,							//mov         ecx,dword ptr [edi+8]
	0x2B, 0x59, 0x30,							//sub         ebx,dword ptr [ecx+30h]
	0x3B, 0xDD,									//cmp         ebx,ebp
	0x7C, 0x0D,									//jl          end
	0xB8, 0xD0, 0x00, 0x0A, 0x00,				//mov         eax,retreat_soldier_troop
	0xFF, 0xD0,									//call        eax
	0x8B, 0x3F,									//mov         edi,dword ptr [edi]
	0x85, 0xFF,									//test        edi,edi
	0x75, 0xE9,									//jne         loop_retreat_part_troop
												//end:
	0x8B, 0xCC,									//mov         ecx,esp
	0xB8, 0xE0, 0x80, 0x51, 0x00,				//mov         eax,5180E0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x20,							//add         esp,20h
	0x5B,										//pop         ebx
	0x5D,										//pop         ebp
	0x5F,										//pop         edi
	0x8B, 0xCE,									//mov         ecx,esi
	0x68, 0x70, 0x0E, 0x46, 0x00,				//push        460E70h
	0xC3										//ret
};

//goose killer linkage
BYTE codeGooseKillerLinkageThunk[] = {0x6A, 0x02, 0x5F, 0x6A, 0x05, 0x90};//push 2;pop edi;push 5;nop
BYTE codeGooseKillerLinkageOldThunk[] = {0xBF, 0x02, 0x00, 0x00, 0x00, 0x57};//mov edi,2;push edi
ASM_PATCH patchGooseKillerLinkageThunk[] = {
	{0x5023F9, sizeof(codeGooseKillerLinkageThunk), codeGooseKillerLinkageThunk},
	{0x5023F9, sizeof(codeGooseKillerLinkageOldThunk), codeGooseKillerLinkageOldThunk}};

//cut_point[3*3]
BYTE codeCutPoint[3*3];
DWORD addrCutPoint = dwAddrStackBottom + 0x64C0;

//max business
DWORD dwAddrMaxBusiness = dwAddrStackBottom + 0x75B0; 
BYTE codeMaxBusiness[] = {
	0x8B, 0xCE,									//mov         ecx,esi
	0xFF, 0x50, 0x34,							//call        dword ptr [eax+34h]
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x75, 0x01,									//jne         player_force
	0xC3,										//ret
												//player_force:
	0x80, 0x3C, 0x24, 0xAF,						//cmp         byte ptr [esp],0AFh
	0x57,										//push        edi
	0x8B, 0xF8,									//mov         edi,eax
	0x74, 0x02,									//je          get_food
	0xD1, 0xEB,									//shr         ebx,1
												//get_food:
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0x00, 0x32, 0x44, 0x00,				//mov         eax,443200h
	0xFF, 0xD0,									//call        eax
	0x50,										//push        eax
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0x70, 0x31, 0x44, 0x00,				//mov         eax,443170h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x2B, 0xC2,									//sub         eax,edx
	0x85, 0xC0,									//test        eax,eax
	0x7E, 0x12,									//jle         end
	0xC1, 0xE8, 0x0D,							//shr         eax,0Dh
	0x83, 0xF8, 0x7F,							//cmp         eax,7Fh
	0x7F, 0x08,									//jg          sub_max_business
	0x3A, 0x05, 0xC3, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+3]
	0x7C, 0x02,									//jl          end
												//sub_max_business:
	0xD1, 0xEB,									//shr         ebx,1
												//end:
	0x8B, 0xC7,									//mov         eax,edi
	0x5F,										//pop         edi
	0xC3										//ret
};

BYTE codeMaxBusinessOldThunk[] = {0x8B, 0xCE, 0xFF, 0x50, 0x34};//mov ecx,esi;call [eax+34h]

BYTE codeMaxBusinessThunk[] = {0xE8, 0x01, 0x0C, 0xC2, 0xFF};//dwAddrMaxBusiness - 4869AAh - 5
ASM_PATCH patchMaxBusinessThunk[] = {
	{0x4869AA, sizeof(codeMaxBusinessThunk), codeMaxBusinessThunk},
	{0x4869AA, sizeof(codeMaxBusinessOldThunk), codeMaxBusinessOldThunk}};

BYTE codeMaxBusiness2Thunk[] = {0xE8, 0x21, 0x0B, 0xC2, 0xFF};//dwAddrMaxBusiness - 486A8Ah - 5
ASM_PATCH patchMaxBusiness2Thunk[] = {
	{0x486A8A, sizeof(codeMaxBusiness2Thunk), codeMaxBusiness2Thunk},
	{0x486A8A, sizeof(codeMaxBusinessOldThunk), codeMaxBusinessOldThunk}};

//income
DWORD dwAddrIncome = dwAddrStackBottom + 0x5770;
BYTE codeIncome[] = {
	0x51,										//push        ecx
	0xBA, 0xD3, 0x4D, 0x62, 0x10,				//mov         edx,10624DD3h
	0x8B, 0x8E, 0xCC, 0x00, 0x00, 0x00,			//mov         ecx,dword ptr [esi+0CCh]
	0x85, 0xC9,									//test        ecx,ecx
	0x74, 0x57,									//je          end
	0x8B, 0x89, 0xB8, 0x00, 0x00, 0x00,			//mov         ecx,dword ptr [ecx+0B8h]
	0xF6, 0x41, 0x34, 0x04,						//test        byte ptr [ecx+34h],4
	0x75, 0x4B,									//jne         end
	0xF6, 0x41, 0x34, 0x01,						//test        byte ptr [ecx+34h],1
	0x75, 0x0B,									//jne         get_force_money
	0xF6, 0x05, 0x16, 0xFF, 0x43, 0x00, 0x01,	//test        byte ptr[add_npc_money_food],1
	0x74, 0x02,									//je          get_force_money
	0xD1, 0xE2,									//shl         edx,1
												//get_force_money:
	0x52,										//push        edx
	0xB8, 0x10, 0x30, 0x44, 0x00,				//mov         eax,443010h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0xC1, 0xE8, 0x0C,							//shr         eax,0Ch
	0x8B, 0xCA,									//mov         ecx,edx
	0xC1, 0xE9, 0x02,							//shr         ecx,2
	0x3D, 0x80, 0x00, 0x00, 0x00,				//cmp         eax,80h
	0x7C, 0x04,									//jl          normal
	0x8B, 0xD1,									//mov         edx,ecx
	0xEB, 0x1E,									//jmp         end
												//normal:
	0x3A, 0x05, 0xC0, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point]
	0x7C, 0x16,									//jl          end
	0x2B, 0xD1,									//sub         edx,ecx
	0x3A, 0x05, 0xC1, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+1]
	0x7C, 0x0C,									//jl          end
	0x2B, 0xD1,									//sub         edx,ecx
	0x3A, 0x05, 0xC2, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+2]
	0x7C, 0x02,									//jl          end
	0x2B, 0xD1,									//sub         edx,ecx
												//end:
	0x8B, 0xC2,									//mov         eax,edx
	0x59,										//pop         ecx
	0xC3										//ret
};

BYTE codeIncomeThunk[] = {0xE8, 0x7B, 0xB1, 0xC6, 0xFF};//dwAddrIncome - 43A5F0h - 5
BYTE codeIncomeOldThunk[] = {0xB8, 0xD3, 0x4D, 0x62, 0x10};//mov eax,10624DD3h
ASM_PATCH patchIncomeThunk[] = {
	{0x43A5F0, sizeof(codeIncomeThunk), codeIncomeThunk},
	{0x43A5F0, sizeof(codeIncomeOldThunk), codeIncomeOldThunk}};

//harvest
DWORD dwAddrHarvest = dwAddrStackBottom + 0x4D80;
BYTE codeHarvest[] = {
	0x51,										//push        ecx
	0x57,										//push        edi
	0xBF, 0xD3, 0x4D, 0x62, 0x10,				//mov         edi,10624DD3h
	0x8B, 0xCE,									//mov         ecx,esi
	0x8B, 0x01,									//mov         eax,[ecx]
	0xFF, 0x50, 0x30,							//call        [eax+30h]
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x5B,									//je          end
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x75, 0x0B,									//jne         get_force_food
	0x80, 0x3D, 0x16, 0xFF, 0x43, 0x00, 0x00,	//cmp         byte ptr[add_npc_money_food],0
	0x74, 0x02,									//je          get_force_food
	0xD1, 0xE7,									//shl         edi,1
												//get_force_food:
	0x50,										//push        eax
	0x8B, 0xC8,									//mov         ecx,eax
	0xB8, 0x00, 0x32, 0x44, 0x00,				//mov         eax,443200h
	0xFF, 0xD0,									//call        eax
	0x59,										//pop         ecx
	0x50,										//push        eax
	0xB8, 0x70, 0x31, 0x44, 0x00,				//mov         eax,443170h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x2B, 0xC2,									//sub         eax,edx
	0x85, 0xC0,									//test        eax,eax
	0x7E, 0x30,									//jle         end
	0xC1, 0xE8, 0x0D,							//shr         eax,0Dh
	0x83, 0xF8, 0x7F,							//cmp         eax,7Fh
	0x7E, 0x05,									//jle         normal
	0xC1, 0xEF, 0x02,							//shr         edi,2
	0xEB, 0x23,									//jmp         end
												//normal:
	0x8B, 0xD7,									//mov         edx,edi
	0xC1, 0xEA, 0x02,							//shr         edx,2
	0x3A, 0x05, 0xC3, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+3]
	0x7C, 0x16,									//jl          end
	0x2B, 0xFA,									//sub         edi,edx
	0x3A, 0x05, 0xC4, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+4]
	0x7C, 0x0C,									//jl          end
	0x2B, 0xFA,									//sub         edi,edx
	0x3A, 0x05, 0xC5, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+5]
	0x7C, 0x02,									//jl          end
	0x2B, 0xFA,									//sub         edi,edx
												//end:
	0x8B, 0xC7,									//mov         eax,edi
	0x5F,										//pop         edi
	0x59,										//pop         ecx
	0xC3										//ret
};

BYTE codeHarvestThunk[] = {0xE8, 0xE5, 0xA6, 0xC6, 0xFF};//dwAddrHarvest - 43A696h - 5
BYTE codeHarvestOldThunk[] = {0xB8, 0xD3, 0x4D, 0x62, 0x10};//mov eax,10624DD3h
ASM_PATCH patchHarvestThunk[] = {
	{0x43A696, sizeof(codeHarvestThunk), codeHarvestThunk},
	{0x43A696, sizeof(codeHarvestOldThunk), codeHarvestOldThunk}};

//city population coef ;原//draft population
DWORD dwAddrCityPopulationCoef = dwAddrStackBottom + 0x79A8;
BYTE codeCityPopulationCoef[] = {
	0x8B, 0x81, 0xC4, 0x01, 0x00, 0x00,        //mov     eax, dword ptr [ecx+1C4h]
	0x0F, 0xB6, 0x51, 0x04,                    //movzx   edx, byte ptr [ecx+4]
	0x0F, 0xB6, 0x92, 0xCC, 0x79, 0x0A, 0x00,  //movzx   edx, byte ptr [edx+city_population_coef]
	0xF7, 0xEA,                                //imul    edx
	0xB9, 0xAB, 0xAA, 0xAA, 0x2A,              //mov     ecx, 2AAAAAABh
	0xF7, 0xE9,                                //imul    ecx
	0xD1, 0xFA,                                //sar     edx, 1
	0x8B, 0xC2,                                //mov     eax, edx
	0xC1, 0xE8, 0x1F,                          //shr     eax, 1F
	0x03, 0xC2,                                //add     eax, edx
	0xC3,                                      //retn
	//city_population_coef:
	0x08, 0x08, 0x0C, 0x0E, 0x0C,              //襄平，北平，蓟，南皮，平原；
	0x12, 0x0C, 0x0C, 0x0E, 0x0E,              //邺，晋阳，上党，北海，濮阳；
	0x0E, 0x12, 0x0C, 0x0E, 0x0E,              //陈留，下邳，小沛，许昌，汝南；
	0x18, 0x18, 0x08, 0x08, 0x08,              //洛阳，长安，安定，天水，西平；
	0x08, 0x0E, 0x0C, 0x12, 0x0C,              //武威，寿春，庐江，建业，吴；
	0x08, 0x0E, 0x0E, 0x08, 0x12,              //会稽，柴桑，宛，新野，襄阳；
	0x0E, 0x0C, 0x0E, 0x08, 0x08,              //江陵，江夏，长沙，武陵，桂阳；
	0x08, 0x08, 0x08, 0x0E, 0x08,              //零陵，西城，永安，汉中，梓潼；
	0x12, 0x0C, 0x08, 0x08, 0x0E,              //成都，江州，建宁，云南，交趾；	
	0x0C, 0x08, 0x08, 0x08, 0x08               //倭，乌丸，羌，山越，南蛮。 
};

BYTE codeCityPopulationCoefOldThunk[] = {0xFF, 0x92, 0xE8, 0x00, 0x00, 0x00};//call [edx+0E8h]
//显示兵役1
BYTE codeCityPopulationCoef1Thunk[] = {0xE8, 0x6C, 0xC6, 0xC6, 0xFF, 0x41};//dwAddrCityPopulationCoef - 43B337h - 5
ASM_PATCH patchCityPopulationCoef1Thunk[] = {
	{0x43B337, sizeof(codeCityPopulationCoef1Thunk), codeCityPopulationCoef1Thunk},
	{0x43B337, sizeof(codeCityPopulationCoefOldThunk), codeCityPopulationCoefOldThunk}};
//显示兵役2
BYTE codeCityPopulationCoef2Thunk[] = {0xE8, 0x8A, 0xC5, 0xC6, 0xFF, 0x41};//dwAddrCityPopulationCoef - 43B419h - 5
ASM_PATCH patchCityPopulationCoef2Thunk[] = {
	{0x43B419, sizeof(codeCityPopulationCoef2Thunk), codeCityPopulationCoef2Thunk},
	{0x43B419, sizeof(codeCityPopulationCoefOldThunk), codeCityPopulationCoefOldThunk}};
//增加兵役1
BYTE codeCityPopulationCoef3Thunk[] = {0xE8, 0xC8, 0x7D, 0xC2, 0xFF, 0x41};//dwAddrCityPopulationCoef - 47FBDBh - 5
ASM_PATCH patchCityPopulationCoef3Thunk[] = {
	{0x47FBDB, sizeof(codeCityPopulationCoef3Thunk), codeCityPopulationCoef3Thunk},
	{0x47FBDB, sizeof(codeCityPopulationCoefOldThunk), codeCityPopulationCoefOldThunk}};
//增加兵役2
	BYTE codeCityPopulationCoef4Thunk[] = {0xE8, 0xA6, 0x7C, 0xC2, 0xFF, 0x41};//dwAddrCityPopulationCoef - 47FCFDh - 5
ASM_PATCH patchCityPopulationCoef4Thunk[] = {
	{0x47FCFD, sizeof(codeCityPopulationCoef4Thunk), codeCityPopulationCoef4Thunk},
	{0x47FCFD, sizeof(codeCityPopulationCoefOldThunk), codeCityPopulationCoefOldThunk}};

//get force military pop
DWORD dwAddrGetForceMilitaryPop = dwAddrStackBottom + 0x4EB0;
BYTE codeGetForceMilitaryPop[] = {
												//get_force_military_pop:
	0x56,										//push        esi
	0x57,										//push        edi
	0x8B, 0xF1,									//mov         esi,ecx
	0xB8, 0xD0, 0xF0, 0x43, 0x00,				//mov         eax,43F0D0h
	0xFF, 0xD0,									//call        eax
	0x8B, 0xF8,									//mov         edi,eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x30, 0xF2, 0x43, 0x00,				//mov         eax,43F230h
	0xFF, 0xD0,									//call        eax
	0x03, 0xF8,									//add         edi,eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x20, 0x0F, 0x44, 0x00,				//mov         eax,440F20h
	0xFF, 0xD0,									//call        eax
	0x03, 0xF8,									//add         edi,eax
	0x8B, 0xC7,									//mov         eax,edi
	0x5F,										//pop         edi
	0x5E,										//pop         esi
	0xC3										//ret
};

//get force strength
DWORD dwAddrGetForceStrength = dwAddrStackBottom + 0x7700;
BYTE codeGetForceStrength[] = {
												//get_force_strength:
	0x56,										//push        esi
	0x57,										//push        edi
	0x8B, 0xF1,									//mov         esi,ecx
	0xB8, 0xB0, 0x4E, 0x0A, 0x00,				//mov         eax,get_force_military_pop
	0xFF, 0xD0,									//call        eax
	0x8B, 0xF8,									//mov         edi,eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xE0, 0xF3, 0x43, 0x00,				//mov         eax,43F3E0h
	0xFF, 0xD0,									//call        eax
	0x69, 0xC0, 0x20, 0x4E, 0x00, 0x00,			//imul        eax,eax,4E20h
	0x03, 0xF8,									//add         edi,eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x50, 0xF4, 0x43, 0x00,				//mov         eax,43F450h
	0xFF, 0xD0,									//call        eax
	0x69, 0xC0, 0x88, 0x13, 0x00, 0x00,			//imul        eax,eax,1388h
	0x03, 0xC7,									//add         eax,edi
	0x5F,										//pop         edi
	0x5E,										//pop         esi
	0xC3										//ret
};

//goal force para
DWORD dwAddrGoalForcePara = dwAddrStackBottom + 0x7738;
BYTE codeGoalForcePara[] = {
	0x8B, 0x44, 0x24, 0x04,						//mov         eax,[esp+4]
	0x8B, 0x08,									//mov         ecx,[eax]
	0xB8, 0x00, 0x77, 0x0A, 0x00,				//mov         eax,get_force_strength
	0xFF, 0xD0,									//call        eax
	0xF7, 0xD8,									//neg         eax
	0xC3										//ret
};

BYTE codeGoalForceParaThunk[] = {0x38, 0x77, 0x0A, 0x00};//dwAddrGoalForcePara
BYTE codeGoalForceParaOldThunk[] = {0x30, 0x76, 0x4A, 0x00};//4A7630h
ASM_PATCH patchGoalForceParaThunk[] = {
	{0x4A8656, sizeof(codeGoalForceParaThunk), codeGoalForceParaThunk},
	{0x4A8656, sizeof(codeGoalForceParaOldThunk), codeGoalForceParaOldThunk}};

//show city draft
DWORD dwAddrShowCityDraft = dwAddrStackBottom + 0x4E40;
BYTE codeShowCityDraft[] = {
	0x5E,                                       //pop         esi
	0xFF, 0x15, 0x2C, 0xF3, 0x5F, 0x00,         //call        dword ptr [5FF32Ch]
	0x56,                                       //push        esi
	0x8B, 0x4C, 0x24, 0x28,                     //mov         ecx, dword ptr [esp+28h]
	0xBA, 0x54, 0x4E, 0x0A, 0x00,               //mov         edx, shared_draft
	0xFF, 0xD2,                                 //call        edx 
	0xC3,	                                    //ret
	                                            //shared_draft:
	0x57,										//push        edi
	0x8B, 0xF8,			                        //mov         edi, eax
	0x8B, 0x01,									//mov         eax,[ecx]
	0xFF, 0x50, 0x30,							//call        [eax+30h]
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x3A,									//je          half
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x74, 0x36,									//je          end
	0x8B, 0xC8,									//mov         ecx,eax
	0xB8, 0xB0, 0x4E, 0x0A, 0x00,				//mov         eax,get_force_military_pop
	0xFF, 0xD0,									//call        eax
	0xC1, 0xE8, 0x0E,							//shr         eax,0Eh
	0x83, 0xF8, 0x7F,							//cmp         eax,7Fh
	0x7E, 0x02,									//jle         normal_draft
	0xB0, 0x7F,									//mov         al, 7Fh
												//normal_draft:
	0x8B, 0xD7,									//mov         edx,edi
	0xC1, 0xEA, 0x02,							//shr         edx,2
	0x3A, 0x05, 0xC6, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+6]
	0x7C, 0x16,									//jl          end
	0x2B, 0xFA,									//sub         edi,edx
	0x3A, 0x05, 0xC7, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+7]
	0x7C, 0x0C,									//jl          end
	0x2B, 0xFA,									//sub         edi,edx
	0x3A, 0x05, 0xC8, 0x64, 0x0A, 0x00,			//cmp         al,[cut_point+8]
	0x7C, 0x02,									//jl          end
                                                //half:
	0xD1, 0xEF,									//shr         edi,1
												//end:
	0x8B, 0xC7,									//mov         eax,edi
	0x5F,										//pop         edi
	0xC3										//ret
};

BYTE codeShowCityDraftThunk[] = {0xE8, 0x15, 0x9A, 0xC6, 0xFF, 0x90};//dwAddrShowCityDraft
BYTE codeShowCityDraftOldThunk[] = {0xFF, 0x15, 0x2C, 0xF3, 0x5F, 0x00};//call dword ptr [5FF32Ch]
ASM_PATCH patchShowCityDraftThunk[] = {
	{0x43B426, sizeof(codeShowCityDraftThunk), codeShowCityDraftThunk},
	{0x43B426, sizeof(codeShowCityDraftOldThunk), codeShowCityDraftOldThunk}};
	
//add city draft
DWORD dwAddrAddCityDraft = dwAddrStackBottom + 0x7748;
BYTE codeAddCityDraft[] = {
	0x51,                                       //push        ecx 
	0xBA, 0x54, 0x4E, 0x0A, 0x00,               //mov         edx, shared_draft  
	0xFF, 0xD2,                                 //call        edx 
	0x59,                                       //pop         ecx   
	0x89, 0x44, 0x24, 0x04,                     //mov         dword ptr [esp+4], eax 
	0x57,										//push        edi
	0x8D, 0xBE, 0xC0, 0x01, 0x00, 0x00,			//lea         edi,[esi+1C0h]
	0x80, 0x3D, 0x17, 0xFF, 0x43, 0x00,	0x00,	//cmp         byte ptr [not_add_draft],0
	0x75, 0x0E,									//jne         update_city_draft
	0x03, 0x07, 								//add         eax,dword ptr [edi]
	0x3D, 0x20, 0xA1, 0x07, 0x00,				//cmp         eax,7A120h
	0x7E, 0x05,									//jle         update_city_draft
	0xB8, 0x20, 0xA1, 0x07, 0x00,				//mov         eax,7A120h
												//update_city_draft:
	0x89, 0x07,									//mov         dword ptr [edi],eax
	0x80, 0x3D, 0x18, 0xFF, 0x43, 0x00,	0x00,	//cmp         byte ptr [npc_auto_draft],0
	0x74, 0x4C,									//je          end
	0x8B, 0x89, 0xCC, 0x00, 0x00, 0x00,			//mov         ecx,[ecx+0CCh]
	0x85, 0xC9,									//test        ecx,ecx
	0x74, 0x42,									//je          end
	0x8B, 0x81,	0xB8, 0x00, 0x00, 0x00,			//mov         eax,[ecx+0B8h]
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x75, 0x36,									//jne         end
	0xB8, 0x90, 0x01, 0x0A, 0x00,				//mov         eax,check_draft_food
	0xFF, 0xD0,									//call        eax
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x2B,									//je          end
	0x8B, 0x86, 0x88, 0x00, 0x00, 0x00,			//mov         eax,dword ptr [esi+88h]
	0x03, 0x07, 								//add         eax,dword ptr [edi]
	0x50,										//push        eax
	0x33, 0xC0,									//xor         eax,eax
	0x89, 0x07,									//mov         dword ptr [edi],eax
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xC0, 0x61, 0x43, 0x00,				//mov         eax,4361C0h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x2B, 0xC2,									//sub         eax,edx
	0x85, 0xC0,									//test        eax,eax
	0x7D, 0x08,									//jge         update_city_soldier
	0x8B, 0xC8,									//mov         ecx,eax
	0xF7, 0xD8,									//neg         eax
	0x89, 0x07,									//mov         dword ptr [edi],eax
	0x03, 0xD1,									//add         edx,ecx
												//update_city_soldier:
	0x89, 0x96, 0x88, 0x00, 0x00, 0x00,			//mov         dword ptr [esi+88h],edx
												//end:
	0x5F,										//pop         edi
	0xC2, 0x04, 0x00							//ret         4
};

BYTE codeAddCityDraftThunk[] = {0xE8, 0x31, 0x7A, 0xC2, 0xFF};//dwAddrAddCityDraft
BYTE codeAddCityDraftOldThunk[] = {0xE8, 0x69, 0xA6, 0xFB, 0xFF};//call 43A380h()
ASM_PATCH patchAddCityDraftThunk[] = {
	{0x47FD12, sizeof(codeAddCityDraftThunk), codeAddCityDraftThunk},
	{0x47FD12, sizeof(codeAddCityDraftOldThunk), codeAddCityDraftOldThunk}};

//phase error invite
DWORD dwAddrPhaseErrorInvite = dwAddrStackBottom + 0x4EA0;
BYTE codePhaseErrorInvite[] = {
	0x85, 0xC9,                               //test        ecx,ecx
	0x7D, 0x03,                               //jge         end
	0xC1, 0xE1, 0x02,						  //shl         ecx,2
											  //end:
	0x33, 0xD2,								  //xor         edx,edx
	0xC3									  //ret
};

BYTE codePhaseErrorInviteThunk[] = {0xE8, 0x6C, 0xFA, 0xC0, 0xFF};//dwAddrPhaseErrorInvite - 49542Fh - 5
BYTE codePhaseErrorInviteOldThunk[] = {0x8B, 0xD1, 0xC1, 0xEA, 0x1F};//mov edx,ecx;shr edx,1Fh
ASM_PATCH patchPhaseErrorInviteThunk[] = {
	{0x49542F, sizeof(codePhaseErrorInviteThunk), codePhaseErrorInviteThunk},
	{0x49542F, sizeof(codePhaseErrorInviteOldThunk), codePhaseErrorInviteOldThunk}};

//player auto process
DWORD dwAddrPlayerAutoProcess = dwAddrStackBottom + 0x7800;
BYTE codePlayerAutoProcess[] = {
	0x8B, 0x41, 0x3C,							//mov         eax,dword ptr [ecx+3Ch]
	0x8B, 0x40, 0x08,							//mov         eax,dword ptr [eax+8]
	0xF6, 0x40, 0x72, 0x08,						//test        byte ptr [eax+72h],8
	0x74, 0x0E,									//je          test_player_force
	0x80, 0x60, 0x72, 0xF7,						//and         byte ptr [eax+72h],0F7h
	0x80, 0x48, 0x34, 0x01,						//or          byte ptr [eax+34h],1
	0xC6, 0x40, 0x24, 0x00,						//mov         byte ptr [eax+24h],0
	0xEB, 0x13,									//jmp         normal
												//test_player_force:
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x74, 0x0D,									//je          normal
	0x80, 0x48, 0x72, 0x08,						//or          byte ptr [eax+72h],8
	0x80, 0x60, 0x34, 0xFE,						//and         byte ptr [eax+34h],0FEh
	0xC6, 0x40, 0x24, 0x01,						//mov         byte ptr [eax+24h],1
	0xC3,										//ret
												//normal:
	0x68, 0x10, 0xAC, 0x46, 0x00,				//push        46AC10h
	0xC3										//ret
};

BYTE codePlayerAutoProcessThunk[] = {0xE8, 0x1F, 0x8B, 0xB9, 0xFF};//dwAddrPlayerAutoProcess - 50ECDCh - 5
BYTE codePlayerAutoProcessOldThunk[] = {0xE8, 0x2F, 0xBF, 0xF5, 0xFF};//call 46AC10h()
ASM_PATCH patchPlayerAutoProcessThunk[] = {
	{0x50ECDC, sizeof(codePlayerAutoProcessThunk), codePlayerAutoProcessThunk},
	{0x50ECDC, sizeof(codePlayerAutoProcessOldThunk), codePlayerAutoProcessOldThunk}};

//auto process task
DWORD dwAddrAutoProcessTask = dwAddrStackBottom + 0x77D0;
BYTE codeAutoProcessTask[] = {
	0xF6, 0x41, 0x72, 0x08,						//test        byte ptr [ecx+72h],8
	0x74, 0x06,									//je          normal
	0x80, 0x7E, 0x44, 0x00,						//cmp         byte ptr [esi+44h],0
	0x74, 0x06,									//je          player_auto_process
												//normal:
	0x68, 0x10, 0xE5, 0x43, 0x00,				//push        43E510h
	0xC3,										//ret
												//player_auto_process:
	0xC7, 0x46, 0x3C, 0x6C, 0x77, 0x65,	0x00,	//mov         byte ptr [esi+3Ch],65776Ch;//65773Ch=>65776Ch
	0xC6, 0x46, 0x40, 0x07,						//mov         byte ptr [esi+40h],7;//6=>7
	0xC6, 0x46, 0x44, 0x02,						//mov         byte ptr [esi+44h],2
	0xC6, 0x04,	0x24, 0xD7,						//mov         byte ptr [esp],0D7h
	0xC3										//ret
};

BYTE codeAutoProcessTaskThunk[] = {0xE8, 0x3D, 0x9A, 0xBE, 0xFF};//dwAddrAutoProcessTask - 4BDD8Eh - 5
BYTE codeAutoProcessTaskOldThunk[] = {0xE8, 0x7D, 0x07, 0xF8, 0xFF};//call 43E510h()
ASM_PATCH patchAutoProcessTaskThunk[] = {
	{0x4BDD8E, sizeof(codeAutoProcessTaskThunk), codeAutoProcessTaskThunk},
	{0x4BDD8E, sizeof(codeAutoProcessTaskOldThunk), codeAutoProcessTaskOldThunk}};

//get league goal
DWORD dwAddrGetLeagueGoal = dwAddrStackBottom + 0x7840;
BYTE codeGetLeagueGoal[] = {
	0x56,										//push        esi
	0x57,										//push        edi
	0x53,										//push        ebx
	0x55,										//push        ebp
	0x80, 0x3D, 0x19, 0xFF, 0x43, 0x00,	0x00,	//cmp         byte ptr [anti_player_league_coef],0
	0x74, 0x4B,									//je          normal
	0x33, 0xFF,									//xor         edi,edi
	0xBE, 0x38, 0x3C, 0x25, 0x01,				//mov         esi,1253C38h
												//loop_player_force:
	0xF6, 0x46, 0x34, 0x01,						//test        byte ptr [esi+34h],1
	0x74, 0x32,									//je          next_player_force
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xE0, 0xF3, 0x43, 0x00,				//mov         eax,43F3E0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xF8, 0x02,							//cmp         eax,2
	0x7C, 0x24,									//jl          next_player_force
	0x48,										//dec         eax
	0x0F, 0xB6, 0x15, 0x19, 0xFF, 0x43,	0x00,	//movzx       edx,byte ptr[anti_player_league_coef]
	0xF7, 0xEA,									//imul        edx
	0x6B, 0xD8, 0x05,							//imul        ebx,eax,5
	0xFF, 0x15, 0xDC, 0xF2, 0x5F, 0x00,			//call        dword ptr [5FF2DCh]
	0x33, 0xD2,									//xor         edx,edx
	0xB9, 0x64, 0x00, 0x00, 0x00,				//mov         ecx,64h
	0xF7, 0xF9,									//idiv        ecx
	0x3B, 0xD3,									//cmp         edx,ebx
	0x7D, 0x04,									//jge         next_player_force
	0x8B, 0xC6,									//mov         eax,esi
	0xEB, 0x6B,									//jne         end
												//next_player_force:
	0x81, 0xC6, 0xD4, 0x00, 0x00, 0x00,			//add         esi,0D4h
	0x47,										//inc         edi
	0x83, 0xFF, 0x32,							//cmp         edi,32h
	0x7C, 0xBC,									//jl          loop_player_force
												//normal:
	0x33, 0xFF,									//xor         edi,edi
	0xBE, 0x38, 0x3C, 0x25, 0x01,				//mov         esi,1253C38h
	0x33, 0xDB,									//xor         ebx,ebx
	0x33, 0xED,									//xor         ebp,ebp
												//loop_force:
	0x83, 0xBE, 0xBC, 0x00, 0x00, 0x00, 0x00,	//cmp         dword ptr [esi+0BCh],0
	0x74, 0x3D,									//je          next_force
	0x39, 0xB6, 0xB8, 0x00, 0x00, 0x00,			//cmp         dword ptr [esi+0B8h],esi
	0x75, 0x35,									//jne         next_force
	0xF6, 0x46, 0x34, 0x04,						//test        byte ptr [esi+34h],4
	0x75, 0x2F,									//jne         next_force
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xB0, 0x4E, 0x0A, 0x00,				//mov         eax,get_force_military_pop
	0xFF, 0xD0,									//call        eax
	0x3D, 0xE0, 0x93, 0x04, 0x00,				//cmp         eax,493E0h
	0x7E, 0x1F,									//jle         next_force
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xE0, 0xF3, 0x43, 0x00,				//mov         eax,43F3E0h
	0xFF, 0xD0,									//call        eax
	0x83, 0xF8, 0x09,							//cmp         eax,9
	0x7C, 0x11,									//jl          next_force
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x00, 0x77, 0x0A, 0x00,				//mov         eax,get_force_strength
	0xFF, 0xD0,									//call        eax
	0x3B, 0xC3,									//cmp         eax,ebx
	0x7E, 0x04,									//jle         next_force
	0x8B, 0xEE,									//mov         ebp,esi
	0x8B, 0xD8,									//mov         ebx,eax
												//next_force:
	0x81, 0xC6, 0xD4, 0x00, 0x00, 0x00,			//add         esi,0D4h
	0x47,										//inc         edi
	0x83, 0xFF, 0x32,							//cmp         edi,32h
	0x7C, 0xAE,									//jl          loop_force
	0x8B, 0xC5,									//mov         eax,ebp
												//end:
	0x5D,										//pop         ebp
	0x5B,										//pop         ebx
	0x5F,										//pop         edi
	0x5E,										//pop         esi
	0xC3										//ret
};

BYTE codeGetLeagueGoalThunk[] = {0xE9, 0x6B, 0xC6, 0xB2, 0xFF};//dwAddrGetLeagueGoal - 57B1D0h - 5
BYTE codeGetLeagueGoalOldThunk[] = {0x51, 0x53, 0x55, 0x33, 0xED};//push ecx;push ebx;push ebp;xor ebp,ebp
ASM_PATCH patchGetLeagueGoalThunk[] = {
	{0x57B1D0, sizeof(codeGetLeagueGoalThunk), codeGetLeagueGoalThunk},
	{0x57B1D0, sizeof(codeGetLeagueGoalOldThunk), codeGetLeagueGoalOldThunk}};

//fight sub income
DWORD dwAddrFightSubIncome = dwAddrStackBottom + 0x7940;
BYTE codeFightSubIncome[] = {
	0xB8, 0x1F, 0x85, 0xEB, 0x51,				//mov         eax,51EB851Fh
	0x80, 0x3D, 0x1A, 0xFF, 0x43, 0x00, 0x00,   //cmp         byte ptr [fight_sub_income_coef],0
	0x75, 0x01,									//jne         update_income_coef
	0xC3,										//ret
												//update_income_coef:
	0x51,										//push        ecx
	0x56,										//push        esi
	0x0F, 0xB6, 0x4F, 0x04,						//movzx       ecx,byte ptr [edi+4]
	0x81, 0xC1, 0x00, 0x79, 0x0A, 0x00,			//add         ecx,city_fight_count
	0x0F, 0xB6, 0x11,							//movzx       edx,byte ptr [ecx]
	0x80, 0x7C, 0x24, 0x08, 0x6F,				//cmp         byte ptr [esp+8],6Fh
	0x75, 0x03,									//jne         got_fight_count
	0x42,										//inc         edx
	0x88, 0x11,									//mov         byte ptr [ecx],dl
												//got_fight_count:
	0xB8, 0x81, 0x5A, 0xBF, 0x52,				//mov         eax,52BF5A81h
	0x4A,										//dec         edx
	0x74, 0x31,									//je          end
	0x50,										//push        eax
	0x0F, 0xB6, 0x35, 0x1A, 0xFF, 0x43, 0x00,   //movzx       esi,byte ptr [fight_sub_income_coef]
	0x8B, 0xC6,									//mov         eax,esi
	0x0F, 0xAF, 0xF2,							//imul        esi,edx
	0x99,										//cdq
	0x6A, 0x03,									//push        3
	0x59,										//pop         ecx
	0xF7, 0xF9,									//idiv        eax,ecx
	0x8A, 0x15, 0x15, 0xFF, 0x43, 0x00,	        //mov         dl,byte ptr [left_day]
	0x80, 0xE2, 0x03,							//and         dl,3
	0x3A, 0xD0,									//cmp         dl,al
	0x58,										//pop         eax
	0x7F, 0x10,									//jg          end
	0x83, 0xFE, 0x0A,							//cmp         esi,0Ah
	0x7E, 0x03,									//jle         get_sub_coef
	0x6A, 0x0A,									//push        0Ah
	0x5E,										//pop         esi
												//get_sub_coef:
	0x69, 0xF6, 0xF0, 0x2E, 0x15, 0x00,			//imul        esi,esi,152EF0h
	0x2B, 0xC6,									//sub         eax,esi
												//end:
	0x5E,										//pop         esi
	0x59,										//pop         ecx
	0xC3										//ret
};

BYTE codeFightSubIncomeOldThunk[] = {0xB8, 0x1F, 0x85, 0xEB, 0x51};//mov eax, 51EB851Fh

//民心
BYTE codeFightSubIncomeThunk[] = {0xE8, 0xD1, 0xBB, 0xC0, 0xFF};//dwAddrFightSubIncome - 49BD6Ah - 5
ASM_PATCH patchFightSubIncomeThunk[] = {
	{0x49BD6A, sizeof(codeFightSubIncomeThunk), codeFightSubIncomeThunk},
	{0x49BD6A, sizeof(codeFightSubIncomeOldThunk), codeFightSubIncomeOldThunk}};
//收益
BYTE codeFightSubIncome2Thunk[] = {0xE8, 0xA9, 0xBB, 0xC0, 0xFF};//dwAddrFightSubIncome - 49BD92h - 5
ASM_PATCH patchFightSubIncome2Thunk[] = {
	{0x49BD92, sizeof(codeFightSubIncome2Thunk), codeFightSubIncome2Thunk},
	{0x49BD92, sizeof(codeFightSubIncomeOldThunk), codeFightSubIncomeOldThunk}};
//收获
BYTE codeFightSubIncome3Thunk[] = {0xE8, 0x81, 0xBB, 0xC0, 0xFF};//dwAddrFightSubIncome - 49BDBAh - 5
ASM_PATCH patchFightSubIncome3Thunk[] = {
	{0x49BDBA, sizeof(codeFightSubIncome3Thunk), codeFightSubIncome3Thunk},
	{0x49BDBA, sizeof(codeFightSubIncomeOldThunk), codeFightSubIncomeOldThunk}};

//leader inspire
DWORD dwAddrLeaderInspire = dwAddrStackBottom + 0x7A00;
BYTE codeLeaderInspire[] = {
	0x57,										//push        edi
	0x55,										//push        ebp
	0x53,										//push        ebx
	0x80, 0x78, 0x06, 0x03,						//cmp         byte ptr [eax+6],3
	0x74, 0x09,									//je          test_troop_fight
	0x83, 0xC0, 0x58,							//add         eax,58h
	0xF6, 0x40, 0x22, 0x40,						//test        byte ptr [eax+22h],40h
	0x74, 0x3F,									//je          skip_end
												//test_troop_fight:
	0x83, 0x78, 0x38, 0x46,						//cmp         dword ptr [eax+38h],46h
	0x7D, 0x39,									//jge         skip_end
	0x83, 0x78, 0x24, 0x01,						//cmp         dword ptr [eax+24h],1
	0x75, 0x33,									//jne         skip_end
	0x8B, 0xE8,									//mov         ebp,eax
	0x8B, 0xDA,									//mov         ebx,edx
	0x8B, 0xC8,									//mov         ecx,eax
	0x8B, 0x01,									//mov         eax,dword ptr [ecx]
	0xFF, 0x90, 0xBC, 0x00, 0x00, 0x00,			//call        dword ptr [eax+0BCh]
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x21,									//je          skip_end
	0x83, 0xB8, 0x84, 0x00, 0x00, 0x00, 0x01,	//cmp         dword ptr [eax+84h],1
	0x7F, 0x18,									//jg          skip_end
	0x83, 0xB8, 0x80, 0x00, 0x00, 0x00, 0x00,	//cmp         dword ptr [eax+80h],0
	0x75, 0x0F,									//jne         skip_end
	0x8B, 0xF8,									//mov         edi,eax
	0x6A, 0x04,									//push        4
	0xB8, 0xF0, 0xEF, 0x4A, 0x00,				//mov         eax,4AEFF0h
	0xFF, 0xD0,									//call        eax
	0x85, 0xC0,									//test        eax,eax
	0x75, 0x02,									//jne         add_troop_morale
												//skip_end
	0xEB, 0x73,									//jmp         end
												//add_troop_morale:
	0x8B, 0xCF,									//mov         ecx,edi
	0xB8, 0xA0, 0xD3, 0x44, 0x00,				//mov         eax,44D3A0h
	0xFF, 0xD0,									//call        eax
	0x99,										//cdq
	0x6A, 0x18,									//push        18h
	0x59,										//pop         ecx
	0xF7, 0xF1,									//div         eax,ecx
	0x3C, 0x06,									//cmp         al,6
	0x7D, 0x02,									//jge         add_troop_morale
	0xB0, 0x06,									//mov         al,6
												//add_troop_morale:
	0x01, 0x45, 0x38,							//add         dword ptr [ebp+38h],eax
	0x8B, 0x45, 0x74,							//mov         eax,dword ptr [ebp+74h]
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x75, 0x16,									//jne         display_dialog
	0x80, 0x7B, 0x06, 0x03,						//cmp         byte ptr [ebx+6],3
	0x74, 0x03,									//je          get_goal_force
	0x83, 0xC3, 0x58,							//add         ebx,58h
												//get_goal_force:
	0x8B, 0x43, 0x74,							//mov         eax,dword ptr [ebx+74h]
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x35,									//je          display_movie
	0xF6, 0x40, 0x34, 0x01,						//test        byte ptr [eax+34h],1
	0x74, 0x2F,									//je          display_movie
												//display_dialog:
	0x55,										//push        ebp
	0x55,										//push        ebp
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0xE0, 0x86, 0x50, 0x00,				//mov         eax,5086E0h
	0xFF, 0xD0,									//call        eax
	0x57,										//push        edi
	0x6A, 0x01,									//push        1
	0x68, 0xB4, 0x1A, 0x00, 0x00,				//push        1AB4h
	0xB8, 0xD0, 0x6E, 0x56, 0x00,				//mov         eax,566ED0h
	0xFF, 0xD0,									//call        eax
	0x6A, 0x01,									//push        1
	0x6A, 0x00,									//push        0
	0x68, 0xAA, 0x00, 0x00, 0x00,				//push        0AAh
	0x50,										//push        eax
	0x57,										//push        edi
	0xB8, 0x70, 0xEE, 0x47, 0x00,				//mov         eax,47EE70h
	0xFF, 0xD0,									//call        eax
	0x83, 0xC4, 0x20,							//add         esp,20h
												//display_movie:
	0x6A, 0x1C,									//push        1Ch
	0x55,										//push        ebp
	0x55,										//push        ebp
	0x8B, 0xCE,									//mov         ecx,esi
	0xB8, 0x30, 0x87, 0x50, 0x00,				//mov         eax,508730h
	0xFF, 0xD0,									//call        eax
												//end:
	0x5B,										//pop         ebx
	0x5D,										//pop         ebp
	0x5F,										//pop         edi
	0x8B, 0xCE,									//mov         ecx,esi
	0x68, 0xF0, 0xAF, 0x49, 0x00,				//push        49AFF0h
	0xC3										//ret
};

BYTE codeLeaderInspireThunk[] = {0xE8, 0x14, 0xC0, 0xC0, 0xFF};//dwAddrLeaderInspire - 49B9E7h - 5
BYTE codeLeaderInspireOldThunk[] = {0xE8, 0x04, 0xF6, 0xFF, 0xFF};//call 49AFF0h()
ASM_PATCH patchLeaderInspireThunk[] = {
	{0x49B9E7, sizeof(codeLeaderInspireThunk), codeLeaderInspireThunk},
	{0x49B9E7, sizeof(codeLeaderInspireOldThunk), codeLeaderInspireOldThunk}};

//kill sub prestige
DWORD dwAddrKillSubPrestige = dwAddrStackBottom + 0x0700;
BYTE codeKillSubPrestige[] = {
	0xB8, 0x40, 0xD3, 0x44, 0x00,				//mov         eax,44D340h
	0xFF, 0xD0,									//call        eax
	0x99,										//cdq
	0x6A, 0x0C,									//push        0Ch
	0x59,										//pop         ecx
	0xF7, 0xF9,									//idiv        ecx
	0x3C, 0x02,									//cmp         al,2
	0x7D, 0x02,									//jge         sub_force_prestige
	0xB0, 0x02,									//mov         al,2
												//sub_force_prestige:
	0x50,										//push        eax
	0x8B, 0xCB,									//mov         ecx,ebx
	0xB8, 0xD0, 0xDA, 0x43, 0x00,				//mov         eax,43DAD0h
	0xFF, 0xD0,									//call        eax
	0x6A, 0x01,									//push        1
	0x8B, 0xCB,									//mov         ecx,ebx
	0xB8, 0xD0, 0x32, 0x44, 0x00,				//mov         eax,4432D0h
	0xFF, 0xD0,									//call        eax
	0x68, 0xD0, 0x6E, 0x56, 0x00,				//push        566ED0h
	0xC3										//ret
};

BYTE codeKillSubPrestigeThunk[] = {0xE8, 0x10, 0x56, 0xC1, 0xFF};//dwAddrKillSubPrestige - 48B0EBh - 5
BYTE codeKillSubPrestigeOldThunk[] = {0xE8, 0xE0, 0xBD, 0x0D, 0x00};//call 566ED0h()
ASM_PATCH patchKillSubPrestigeThunk[] = {
	{0x48B0EB, sizeof(codeKillSubPrestigeThunk), codeKillSubPrestigeThunk},
	{0x48B0EB, sizeof(codeKillSubPrestigeOldThunk), codeKillSubPrestigeOldThunk}};

//train basic ability
DWORD dwAddrTrainBasicAbility = dwAddrStackBottom + 0x0730;
BYTE codeTrainBasicAbility[] = {
	0x55,										//push        ebp
	0x56,										//push        esi
	0xB8, 0xA0, 0x86, 0x40, 0x00,				//mov         eax,4086A0h
	0xFF, 0xD0,									//call        eax
	0x0F, 0xB6, 0x05, 0xD1, 0xF3, 0x43, 0x00,	//movzx       eax,byte ptr [basic_ability_coef]
	0x85, 0xC0,									//test        eax,eax
	0x74, 0x20,									//je          end
	0x6B, 0xC0, 0x03,							//imul        eax,eax,3
	0x8D, 0x56, 0x4C,							//lea         edx,[esi+4Ch]
	0x6A, 0x04,									//push        4
	0x59,										//pop         ecx
												//loop_update_basic_ability:
	0x28, 0x02,									//sub         byte ptr [edx],al
	0x83, 0xC2, 0x08,							//add         edx,8
	0x49,										//dec         ecx
	0x75, 0xF8,									//jne         loop_update_basic_ability
	0x8D, 0x96, 0x34, 0x01, 0x00, 0x00,			//lea         edx,[esi+134h]
	0x6A, 0x08,									//push        8
	0x59,										//pop         ecx
												//loop_update_ability_range:
	0x28, 0x02,									//sub         byte ptr [edx],al
	0x42,										//inc         edx
	0x49,										//dec         ecx
	0x75, 0xFA,									//jne         loop_update_ability_range
												//end:
	0xC2, 0x08, 0x00							//ret         8
};

BYTE codeTrainBasicAbilityThunk[] = {0xE8, 0x61, 0x49, 0xC9, 0xFF};//dwAddrTrainBasicAbility - 40BDCAh - 5
BYTE codeTrainBasicAbilityOldThunk[] = {0xE8, 0xD1, 0xC8, 0xFF, 0xFF};//call 4086A0h()
ASM_PATCH patchTrainBasicAbilityThunk[] = {
	{0x40BDCA, sizeof(codeTrainBasicAbilityThunk), codeTrainBasicAbilityThunk},
	{0x40BDCA, sizeof(codeTrainBasicAbilityOldThunk), codeTrainBasicAbilityOldThunk}};

//check draft food
DWORD dwAddrCheckDraftFood = dwAddrStackBottom + 0x0190;
BYTE codeCheckDraftFood[] = {
											  //check_draft_food:
	0x56,                                     //push        esi
	0x53,                                     //push        ebx
	0xB8, 0xE0, 0xED, 0x43, 0x00,             //mov         eax,43EDE0h
	0xF6, 0x41, 0x34, 0x04,					  //test        byte ptr[ecx+34h],4
	0x75, 0x3C,								  //jne         end
	0x8B, 0xF1,                               //mov         esi,ecx
	0x6A, 0x01,                               //push        1
	0xFF, 0xD0,                               //call        eax
	0x8B, 0xD8,                               //mov         ebx,eax
	0xB8, 0x90, 0x4B, 0x45, 0x00,             //mov         eax,454B90h
	0xFF, 0xD0,                               //call        eax
	0x05, 0x96, 0x00, 0x00, 0x00,             //add         eax,96h
	0xF7, 0xEB,                               //imul        ebx
	0x39, 0x46, 0x18,                         //cmp         dword ptr[esi+18],eax
	0x7C, 0x1F,                               //jl          fail
	0x50,                                     //push        eax
	0x68, 0x68, 0x01, 0x00, 0x00,             //push        168h
	0x8B, 0xCE,                               //mov         ecx,esi
	0xB8, 0x80, 0xDA, 0x43, 0x00,             //mov         eax,43DA80h
	0xFF, 0xD0,                               //call        eax
	0x5A,                                     //pop         edx
	0x69, 0xDB, 0x68, 0x01, 0x00, 0x00,       //imul        ebx,ebx,168h
	0x03, 0xD3,                               //add         edx,ebx
	0x2B, 0xD0,                               //sub         edx,eax
	0x39, 0x56, 0x18,                         //cmp         dword ptr[esi+18],edx
	0x7D, 0x02,								  //jge         end
											  //fail:
	0x33, 0xC0,								  //xor         eax,eax
	                                          //end:
	0x5B,                                     //pop         ebx
	0x5E,                                     //pop         esi
	0xC3                                      //ret
};

//retreat change array
DWORD dwAddrRetreatChangeArray = dwAddrStackBottom + 0x5FC0;
BYTE codeRetreatChangeArray[] = {
	0xF6, 0x40, 0x6C, 0x01,						//test        byte ptr [eax+6Ch],1
	0x75, 0x0F,									//jne          end	
	0xF6, 0x40, 0x70, 0x01,						//test        byte ptr [eax+70h],1
	0x74, 0x09,									//je          end
	0x8B, 0x00,									//mov         eax,dword ptr [eax]
	0xC7, 0x40, 0x6C, 0xA0, 0x0E, 0x50, 0x01,	//mov         dword ptr [eax+6Ch],1500EA0h
												//end:
	0x68, 0x80, 0x9C, 0x48, 0x00,				//push        489C80h
	0xC3										//ret
};

BYTE codeRetreatChangeArrayThunk[] = {0xE8, 0xD8, 0x12, 0xBE, 0xFF};//dwAddrRetreatChangeArray - 4C4CE3h - 5
BYTE codeRetreatChangeArrayOldThunk[] = {0xE8, 0x98, 0x4F, 0xFC, 0xFF};//call 489C80h()
ASM_PATCH patchRetreatChangeArrayThunk[] = {
	{0x4C4CE3, sizeof(codeRetreatChangeArrayThunk), codeRetreatChangeArrayThunk},
	{0x4C4CE3, sizeof(codeRetreatChangeArrayOldThunk), codeRetreatChangeArrayOldThunk}};

//ability killer prop
DWORD dwAddrAbilityKillerProp = dwAddrStackBottom + 0x38B0;
BYTE codeAbilityKillerProp[] = {
	0x53,										//push        ebx
	0x8B, 0xD9,									//mov         ebx,ecx
	0x83, 0xFB, 0x05,							//cmp         ebx,5
	0x7E, 0x03,									//jle         get_person_killer
	0x6A, 0x05,									//push        5
	0x5B,										//pop         ebx
												//get_person_killer:
	0x8B, 0x4E, 0x30,							//mov         ecx,dword ptr [esi+30h]
	0x8B, 0x91, 0xF8, 0x00, 0x00, 0x00,			//mov         edx,dword ptr [ecx+0F8h]
	0x83, 0x7A, 0x54, 0x06,						//cmp         dword ptr [edx+54h],6
	0x7D, 0x05,									//jge         intelligence_killer
	0xFF, 0x71, 0x68,							//push        dword ptr [ecx+68h]
	0xEB, 0x03,									//jmp         get_perform_ability
												//intelligence_killer:
	0xFF, 0x71, 0x58,							//push        dword ptr [ecx+58h]
												//get_perform_ability:
	0xB8, 0x00, 0xD3, 0x41, 0x00,				//mov         eax,41D300h
	0xFF, 0xD0,									//call        eax
	0x5A,										//pop         edx
	0x83, 0xC0, 0x3C,							//add         eax,3Ch
	0x3D, 0x96, 0x00, 0x00, 0x00,				//cmp         eax,96h
	0x7E, 0x05,									//jle         get_prop_coef
	0xB8, 0x96, 0x00, 0x00, 0x00,				//mov         eax,96h
												//get_prop_coef:
	0xF7, 0x6C, 0x9C, 0x14,						//imul        dword ptr [esp+ebx*4+14h]
	0xB9, 0x64, 0x00, 0x00, 0x00,				//mov         ecx,64h
	0xF7, 0xF9,									//idiv        eax,ecx
	0x89, 0x44, 0x9C, 0x14,						//mov         dword ptr [esp+ebx*4+14h],eax
	0x8B, 0xC3,									//mov         eax,ebx
	0x5B,										//pop         ebx
	0xC3										//ret
};

BYTE codeAbilityKillerPropThunk[] = {0xE8, 0xEB, 0x4D, 0xBA, 0xFF, 0x90};//dwAddrAbilityKillerProp - 4FEAC0h - 5
BYTE codeAbilityKillerPropOldThunk[] = {0xFF, 0x15, 0x08, 0xF3, 0x5F, 0x00};//call [5FF308h]
ASM_PATCH patchAbilityKillerPropThunk[] = {
	{0x4FEAC0, sizeof(codeAbilityKillerPropThunk), codeAbilityKillerPropThunk},
	{0x4FEAC0, sizeof(codeAbilityKillerPropOldThunk), codeAbilityKillerPropOldThunk}};

//set max captive
DWORD dwAddrSetMaxCaptive = dwAddrStackBottom + 0x7B70;
BYTE codeSetMaxCaptive[] = {
	0x8B, 0x87, 0x90, 0x00, 0x00, 0x00,			//mov         eax,dword ptr [edi+90h]
	0x8B, 0xD0,									//mov         edx,eax
	0xF6, 0x47, 0x20, 0x01,						//test        byte ptr [edi+20h],1
	0x74, 0x18,									//je          save_max_captive
	0x50,										//push        eax
	0x0F, 0xB6, 0x0D, 0x1D, 0xFF, 0x43,	0x00,	//movzx       ecx,byte ptr [max_captive_coef]
	0xF7, 0xE9,									//imul        ecx
	0xB1, 0x0A,									//mov         cl,0Ah
	0xF7, 0xF9,									//idiv        eax,ecx
	0x85, 0xD2,									//test        edx,edx
	0x74, 0x01,									//je          get_max_captive
	0x40,										//inc         eax
												//get_max_captive:
	0x8B, 0xD0,									//mov         edx,eax
	0x58,										//pop         eax
	0x8B, 0xCF,									//mov         ecx,edi
												//save_max_captive:
	0x89, 0x15, 0xD2, 0xF3, 0x43, 0x00,			//mov         dword ptr [max_captive],edx
	0xC3										//ret
};

BYTE codeSetMaxCaptiveThunk[] = {0xE8, 0xB0, 0x1B, 0xC4, 0xFF, 0x90};//dwAddrSetMaxCaptive - 465FBBh - 5
BYTE codeSetMaxCaptiveOldThunk[] = {0x8B, 0x87, 0x90, 0x00, 0x00, 0x00};//mov eax,[edi+90h]
ASM_PATCH patchSetMaxCaptiveThunk[] = {
	{0x465FBB, sizeof(codeSetMaxCaptiveThunk), codeSetMaxCaptiveThunk},
	{0x465FBB, sizeof(codeSetMaxCaptiveOldThunk), codeSetMaxCaptiveOldThunk}};

//get max captive
DWORD dwAddrGetMaxCaptive = dwAddrStackBottom + 0x7AE0;
BYTE codeGetMaxCaptive[] = {
	0x8B, 0x44, 0x24, 0x5C, 					//mov         eax,dword ptr [esp+5Ch]
	0x3B, 0x05, 0xD2, 0xF3, 0x43, 0x00,			//cmp         eax,[max_captive]
	0x7D, 0x06,									//jge         zero_captive_prop
	0x68, 0xB0, 0xF3, 0x44, 0x00,				//push        44F3B0h
	0xC3,										//ret
												//zero_captive_prop:
	0x33, 0xC0,									//xor         eax,eax
	0xC2, 0x08, 0x00							//ret         8
};

BYTE codeGetMaxCaptiveThunk[] = {0xE8, 0xE0, 0x18, 0xC4, 0xFF};//dwAddrGetMaxCaptive - 4661FBh - 5
BYTE codeGetMaxCaptiveOldThunk[] = {0xE8, 0xB0, 0x91, 0xFE, 0xFF};//call 44F3B0h()
ASM_PATCH patchGetMaxCaptiveThunk[] = {
	{0x4661FB, sizeof(codeGetMaxCaptiveThunk), codeGetMaxCaptiveThunk},
	{0x4661FB, sizeof(codeGetMaxCaptiveOldThunk), codeGetMaxCaptiveOldThunk}};
	
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////2019年4月份增加代码///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//captive money2
DWORD dwAddrCaptiveMoney2 = dwAddrStackBottom + 0x7BA0;
BYTE codeCaptiveMoney2[] = {
	0xFF, 0xB1, 0xB8, 0x11, 0x00, 0x00,      //push    dword ptr [ecx+11B8h]
    0xFF, 0xB1, 0xB4, 0x11, 0x00, 0x00,      //push    dword ptr [ecx+11B4h]
    0xFF, 0xB1, 0xB0, 0x11, 0x00, 0x00,      //push    dword ptr [ecx+11B0h]
    0xB8, 0x70, 0xF5, 0x48, 0x00,            //mov     eax, 0048F570h  
    0xFF, 0xD0,                              //call    eax
    0x83, 0xC4, 0x0C,                        //add     esp, 0Ch 
    0x89, 0x44, 0x24, 0x30,                  //mov     dword ptr [esp+30h], eax  
    0x68, 0x90, 0xB7, 0x4C, 0x00,            //push    004CB790h 
    0xC3                                     //retn
};

BYTE codeCaptiveMoney2Thunk[] = {0xE8, 0xBC, 0xDD, 0xBA, 0xFF};//dwAddrCaptiveMoney - 4F9DDFh - 5
BYTE codeCaptiveMoneyOld2Thunk[] = {0xE8, 0xAC, 0x19, 0xFD, 0xFF};//call 004CB790h
ASM_PATCH patchCaptiveMoney2Thunk[] = {
	{0x4F9DDF, sizeof(codeCaptiveMoney2Thunk), codeCaptiveMoney2Thunk},
	{0x4F9DDF, sizeof(codeCaptiveMoneyOld2Thunk), codeCaptiveMoneyOld2Thunk}};	
	
//add water killer
DWORD dwAddrAddWaterKiller = dwAddrStackBottom + 0x7BD0;
BYTE codeAddWaterKiller[] = {
    0x8B, 0x8E, 0x84, 0x00, 0x00, 0x00,         //mov     ecx, dword ptr [esi+84]
    0x8B, 0x01,                                 //mov     eax, dword ptr [ecx]
    0xFF, 0x90, 0xB4, 0x00, 0x00, 0x00,         //call    dword ptr [eax+B4] 
    0x85, 0xC0,                                 //test    eax, eax
    0x74, 0x1D,                                 //je      end
    0x8B, 0x0F,                                 //mov     ecx, dword ptr [edi]
    0x8B, 0x86, 0x84, 0x00, 0x00, 0x00,         //mov     eax, dword ptr [esi+84]
    0x8B, 0x11,                                 //mov     edx, dword ptr [ecx]
    0x6A, 0x01,                                 //push    1
    0x50,                                       //push    eax
    0xFF, 0x92, 0xA8, 0x00, 0x00, 0x00,         //call    dword ptr [edx+A8]
    0x85, 0xC0,                                 //test    eax, eax
    0x74, 0x06,                                 //je      end
    0x68, 0x75, 0x20, 0x50, 0x00,               //push    502075;强袭
    0xC3,                                       //retn
	                                            //end:  
    0x68, 0x3D, 0x20, 0x50, 0x00,               //push    50203D;箭雨
    0xC3										//retn
};

BYTE codeAddWaterKillerThunk[] = {0xD0, 0x7B, 0x0A, 0x00};//dwAddrAddWaterKiller - 50217C - 4
BYTE codeAddWaterKillerOldThunk[] = {0x75, 0x20, 0x50, 0x00};//dd San9PK 00502075
ASM_PATCH patchAddWaterKillerThunk[] = {
	{0x50217C, sizeof(codeAddWaterKillerThunk), codeAddWaterKillerThunk},
	{0x50217C, sizeof(codeAddWaterKillerOldThunk), codeAddWaterKillerOldThunk}};

//enable water killer
DWORD dwAddrEnableWaterKiller = dwAddrStackBottom + 0x7C10;
BYTE codeEnableWaterKiller[] = {
    0x83, 0xF8, 0x17,                           //cmp     eax, 17h
	0x74, 0x06,                                 //je      enable
	0x83, 0xF8, 0x15,                           //cmp     eax, 15h
	0x74, 0x01,                                 //je      enable
    0xC3,                                       //retn
	                                            //enable:
	0x80, 0x04, 0x24, 0x04,                     //add     byte ptr [esp], 4
	0xC3                                        //retn
};

BYTE codeEnableWaterKillerThunk[] = {0xE8, 0x64, 0x43, 0xBA, 0xFF};//dwAddrEnableWaterKiller - 5038A7h - 5
BYTE codeEnableWaterKillerOldThunk[] = {0x83, 0xF8, 0x17, 0x74, 0x04};//cmp     eax, 17 ;je 
ASM_PATCH patchEnableWaterKillerThunk[] = {
	{0x5038A7, sizeof(codeEnableWaterKillerThunk), codeEnableWaterKillerThunk},
	{0x5038A7, sizeof(codeEnableWaterKillerOldThunk), codeEnableWaterKillerOldThunk}};	
	
//select attack ship 	
BYTE codeSelectAttackShipThunk[] =    {0xDB, 0x74, 0x07, 0xBF, 0x16, 0x00, 0x00, 0x00, 0xEB, 0x14, 0x85, 0xED, 0x74, 0x07, 0xBF, 0x17};
BYTE codeSelectAttackShipOldThunk[] = {0xED, 0x74, 0x07, 0xBF, 0x17, 0x00, 0x00, 0x00, 0xEB, 0x14, 0x85, 0xDB, 0x74, 0x07, 0xBF, 0x16};
ASM_PATCH patchSelectAttackShipThunk[] = {
	{0x4B8BF7, sizeof(codeSelectAttackShipThunk), codeSelectAttackShipThunk},
	{0x4B8BF7, sizeof(codeSelectAttackShipOldThunk), codeSelectAttackShipOldThunk}};	
	

//auto adjust killer
DWORD dwAddrAutoAdjustKiller = dwAddrStackBottom + 0x7C20;
BYTE codeAutoAdjustKiller[] = {//code_length = 8Bh + 16h = 0A1h ; killer_table_addr = AddrAutoAdjustKiller + 8Bh
    0x8B, 0x85, 0x4C, 0x07, 0x00, 0x00,          //mov     eax, dword ptr [ebp+74C]
	0x8A, 0x40, 0x04,                            //mov     al, byte ptr [eax+4]
	0x33, 0xC9,                                  //xor     ecx, ecx   
	0x3C, 0x00,                                  //cmp     al, 0
	0x74, 0x1E,                                  //jz      foot_killer
	0x3C, 0x01,                                  //cmp     al, 1
	0x74, 0x1A,                                  //jz      foot_killer
	0x3C, 0x03,                                  //cmp     al, 3
	0x74, 0x15,                                  //jz      horse_killer 
	0x3C, 0x04,                                  //cmp     al, 4
	0x74, 0x0F,                                  //jz      bow_killer
	0x3C, 0x06,                                  //cmp     al, 6  
	0x74, 0x0C,                                  //jz      horse_bow_killer 
	0x3C, 0x07,                                  //cmp     al, 7  
	0x74, 0x06,                                  //jz      intelligence_killer
	0x3C, 0x08,                                  //cmp     al, 8 
	0x74, 0x03,                                  //jz      bow_killer
	0xEB, 0x5C,                                  //jmp     end 
	                                             //intelligence_killer: 
	0x41,                                        //inc     ecx 
	                                             //bow_killer:
	0x41,                                        //inc     ecx
	                                             //horse_bow_killer:
	0x41,                                        //inc     ecx
	                                             //horse_killer:  
	0x41,                                        //inc     ecx
	                                             //foot_killer:
	0x83, 0xF9, 0x04,                            //cmp     ecx, 4
	0x74, 0x0D,                                  //jz      not_change_adjust_type
	0x8B, 0x46, 0x54,                            //mov     eax, dword ptr [esi+54]
	0x2B, 0x46, 0x4C,                            //sub     eax, dword ptr [esi+4C]
	0x83, 0xF8, 0x0F,                            //cmp     eax, 0F
	0x7E, 0x02,                                  //jle     not_change_adjust_type  
	0xB1, 0x04,                                  //mov     cl, 4
	                                             //not_change_adjust_type:
	0x53,                                        //push    ebx 
	0x55,                                        //push    ebp
	0x57,                                        //push    edi
	0xBB, 0x02, 0x00, 0x00, 0x00,                //mov     ebx, 2
	0x83, 0xF9, 0x04,                            //cmp     ecx, 4
	0x75, 0x02,                                  //jnz     strength 
	0xB3, 0x09,                                  //mov     bl, 9
                                                 //strength: 	
	0x33, 0xED,                                  //xor     ebp, ebp
	0x8D, 0xBC, 0x49, 0xAB, 0x7C, 0x0A, 0x00,    //lea     edi, dword ptr [ecx+ecx*2+killer_table_addr]
	                                             //loop_check_killer:
	0x0F, 0xB6, 0x14, 0x2F,                      //movzx   edx, byte ptr [edi+ebp] 
	0x8B, 0xCE,                                  //mov     ecx, esi
	0x52,                                        //push    edx
	0xB8, 0x70, 0xF7, 0x44, 0x00,                //mov     eax, 0044F770  
	0xFF, 0xD0,                                  //call    eax
	0x85, 0xC0,                                  //test    eax, eax
	0x75, 0x07,                                  //jnz     adjust_killer  
	0x45,                                        //inc     ebp
	0x3B, 0xEB,                                  //cmp     ebp, ebx 
	0x7E, 0xE9,                                  //jle     loop_check_killer
	0xEB, 0x12,                                  //jmp     fail
	                                             //adjust_killer:
	0x0F, 0xB6, 0x14, 0x2F,                      //movzx   edx, byte ptr [edi+ebp]   
	0x52,                                        //push    edx
	0xB8, 0x20, 0x37, 0x45, 0x00,                //mov     eax, 00453720   
	0xFF, 0xD0,                                  //call    eax
	0x83, 0xC4, 0x04,                            //add     esp, 4
	0x89, 0x46, 0x08,                            //mov     dword ptr [esi+8], eax
	                                             //fail:
	0x5F,                                        //pop     edi
	0x5D,                                        //pop     ebp
	0x5B,                                        //pop     ebx
	                                             //end:
	0x83, 0xC3, 0x08,                            //add     ebx, 8 
	0x85, 0xFF,                                  //test    edi, edi
	0xC3,                                        //retn
	//killer_table:
	0x02, 0x01, 0x00,                            //foot_killer: 奋迅，奋斗，奋战；
    0x05, 0x04, 0x03,                            //horse_killer: 突击，突进，突破； 
    0x08, 0x07, 0x06,                            //horse_bow_killer: 飞射，奔射，骑射；
    0x0B, 0x0A, 0x09,                            //bow_killer: 连弩，连射，齐射；
    0x1A, 0x1E, 0x1D, 0x19, 0x16,                //intelligence_killer: 
    0x18, 0x17, 0x15, 0x1C, 0x1B                 //幻术，妖术，治疗，攻心，教谕；陷阱，混乱，破陷，鼓舞，辱骂。
};

BYTE codeAutoAdjustKillerThunk[] = {0xE8, 0x14, 0xEA, 0xBB, 0xFF};//dwAddrAutoAdjustKiller - 4E9207 - 5
BYTE codeAutoAdjustKillerOldThunk[] = {0x83, 0xC3, 0x08, 0x85, 0xFF};//add     ebx, 8  ;  test    edi, edi 
ASM_PATCH patchAutoAdjustKillerThunk[] = {
	{0x4E9207, sizeof(codeAutoAdjustKillerThunk), codeAutoAdjustKillerThunk},
	{0x4E9207, sizeof(codeAutoAdjustKillerOldThunk), codeAutoAdjustKillerOldThunk}};	
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////2019年7月份增加代码///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//investment
DWORD dwAddrInvestment = dwAddrStackBottom + 0x7CC8;
BYTE codeInvestment[] = {
    0x57,                                     //push    edi   
    0x51,                                     //push    ecx
    0x8B, 0xCE,                               //mov     ecx, esi
    0xB8, 0xD0, 0xFD, 0x57, 0x00,             //mov     eax, <San9PK.57fdd0h;交易·地点&类>
    0xFF, 0xD0,                               //call    eax
    0x33, 0xFF,                               //xor     edi, edi
    0xBA, 0x10, 0x30, 0x44, 0x00,             //mov     edx, <San9PK.443010h;势力资金> 
    0x83, 0xF8, 0x05,                         //cmp     eax, 5
    0x7E, 0x06,                               //jle     get_force_money/food
    0x47,                                     //inc     edi
    0xBA, 0x70, 0x31, 0x44, 0x00,             //mov     edx, <San9PK.443170h;势力兵粮>
	                                          //get_force_money/food:
    0x8B, 0x8B, 0xB8, 0x00, 0x00, 0x00,       //mov     ecx, dword ptr [ebx+0B8h] 
    0xFF, 0xD2,                               //call    edx 
    0x8D, 0x4F, 0x0C,                         //lea     ecx, dword ptr [edi+0Ch]
    0xD3, 0xE8,                               //shr     eax, cl
    0x83, 0xF8, 0x7F,                         //cmp     eax, 7Fh
    0x7E, 0x02,                               //jle     get_cut_point
    0xB0, 0x7F,                               //mov     al, 7Fh
	                                          //get_cut_point:
    0x33, 0xD2,                               //xor     edx, edx 
    0x8D, 0x8C, 0x7F, 0xC0, 0x64, 0x0A, 0x00, //lea     ecx, dword ptr [edi+edi*2+cut_point]
	                                          //loop:
    0x3A, 0x04, 0x11,                         //cmp     al, byte ptr [ecx+edx]
    0x7C, 0x06,                               //jl      end_loop
    0x42,                                     //inc     edx  
    0x83, 0xFA, 0x03,                         //cmp     edx, 3
    0x7C, 0xF5,                               //jl      loop
	                                          //end_loop:
    0x83, 0xEA, 0x04,                         //sub     edx, 4
    0xF7, 0xDA,                               //neg     edx
    0x69, 0xD2, 0xA0, 0x86, 0x01, 0x00,       //imul    edx, edx, 186A0h  
    0x8B, 0xCF,                               //mov     ecx, edi
    0xD3, 0xEA,                               //shr     edx, cl
    0x59,                                     //pop     ecx 
    0x3B, 0xD1,                               //cmp     edx, ecx
    0x7D, 0x02,                               //jge     end
    0x8B, 0xCA,                               //mov     ecx, edx
                                              //end:	
    0xB8, 0x67, 0x66, 0x66, 0x66,             //mov     eax, 66666667h
    0x5F,                                     //pop     edi
    0xC3	                                  //retn
};

BYTE codeInvestmentThunk[] = {0xE8, 0x50, 0x79, 0xB2, 0xFF};//dwAddrInvestment - 580373 - 5
BYTE codeInvestmentOldThunk[] = {0xB8, 0x67, 0x66, 0x66, 0x66};//mov     eax, 66666667h
ASM_PATCH patchInvestmentThunk[] = {
	{0x580373, sizeof(codeInvestmentThunk), codeInvestmentThunk},
	{0x580373, sizeof(codeInvestmentOldThunk), codeInvestmentOldThunk}};

//heart attack damage 1
DWORD dwAddrHeartAttackDamage1 = dwAddrStackBottom + 0x7D30;
BYTE codeHeartAttackDamage1[] = {
    0xB8, 0x10, 0x0E, 0x47, 0x00,              //mov     eax, 00470E10h
    0xFF, 0xD0,                                //call    eax
    0x8B, 0x44, 0x24, 0x28,                    //mov     eax, dword ptr [esp+28h]
    0x85, 0xC0,                                //test    eax, eax
    0x74, 0x18,                                //je      fail
    0x83, 0xF8, 0x0A,                          //cmp     eax, 0Ah
    0x74, 0x0F,                                //je      success
	                                           //contain:
    0x8B, 0x4E, 0x3C,                          //mov     ecx, dword ptr [esi+3Ch]
    0x8B, 0x11,                                //mov     edx, dword ptr [ecx]
    0xFF, 0x92, 0xBC, 0x00, 0x00, 0x00,        //call    dword ptr [edx+0BCh]
    0x89, 0x44, 0x24, 0x14,                    //mov     dword ptr [esp+14h], eax 
	                                           //success:
    0x83, 0x04, 0x24, 0x07,                    //add     dword ptr [esp], 7h  
                                               //fail:	
    0xC3                                       //retn
};

BYTE codeHeartAttackDamage1Thunk[] = {0xE8, 0x98, 0x29, 0xBA, 0xFF, 0xEB, 0x33, 0xE9, 0x2E, 0x00, 0x00, 0x00};//dwAddrHeartAttackDamage1 - 505393h - 12
BYTE codeHeartAttackDamage1OldThunk[] = {0xE8, 0x78, 0xBA, 0xF6, 0xFF, 0xEB, 0x33, 0x83, 0xFF, 0x0A, 0x75, 0x2E};//call 00470E10h 
ASM_PATCH patchHeartAttackDamage1Thunk[] = {
	{0x505393, sizeof(codeHeartAttackDamage1Thunk), codeHeartAttackDamage1Thunk},
	{0x505393, sizeof(codeHeartAttackDamage1OldThunk), codeHeartAttackDamage1OldThunk}};

//heart attack damage 2
DWORD dwAddrHeartAttackDamage2 = dwAddrStackBottom + 0x7D58;
BYTE codeHeartAttackDamage2[] = {
    0xC6, 0x44, 0x24, 0x08, 0x01,              //mov     byte ptr [esp+8], 1
    0x8B, 0x54, 0x24, 0x44,                    //mov     edx, dword ptr [esp+44h]
    0x89, 0x54, 0x24, 0x10,                    //mov     dword ptr [esp+10h], edx
    0x68, 0xA0, 0xEE, 0x47, 0x00,              //push    47EEA0h
    0xC3                                       //retn
};

BYTE codeHeartAttackDamage2Thunk[] = {0xE8, 0x8E, 0x29, 0xBA, 0xFF};//dwAddrHeartAttackDamage2 - 5053C5h - 5
BYTE codeHeartAttackDamage2OldThunk[] = {0xE8, 0xD6, 0x9A, 0xF7, 0xFF};//call 0047EEA0h
ASM_PATCH patchHeartAttackDamage2Thunk[] = {
	{0x5053C5, sizeof(codeHeartAttackDamage2Thunk), codeHeartAttackDamage2Thunk},
	{0x5053C5, sizeof(codeHeartAttackDamage2OldThunk), codeHeartAttackDamage2OldThunk}};
	
//damage record
DWORD dwAddrDamageRecord = dwAddrStackBottom + 0x7D70;
BYTE codeDamageRecord[] = {
	//intelligence damage record
	0x8B, 0x44, 0x24, 0x1C,                  //mov     eax, dword ptr [esp+1Ch]  
	0x85, 0xC0,                              //test    eax, eax
	0x75, 0x08,                              //jnz     correct_damage_record
 	0x68, 0x0F, 0xE1, 0x4F, 0x00,            //push    004FE10Fh
 	0xC2, 0x04, 0x00,                        //retn    4h 
	//strength damage record
	                                         //correct_damage_record:
	0x8B, 0xCB,                              //mov     ecx, ebx
	0x8B, 0x01,                              //mov     eax, dword ptr [ecx]
	0xFF, 0x50, 0x3C,                        //call    dword ptr [eax+3Ch] 
	0x85, 0xC0,                              //test    eax, eax
	0x74, 0x2F,                              //je      normal
	0x8B, 0xCF,                              //mov     ecx, edi
	0x8B, 0x01,                              //mov     eax, dword ptr [ecx]
	0xFF, 0x50, 0x3C,                        //call    dword ptr [eax+3Ch]   
	0x85, 0xC0,                              //test    eax, eax
	0x75, 0x24,                              //jnz     normal
	0x0F, 0xB7, 0x0D, 0xFE, 0x26, 0x23, 0x01,//movzx   ecx, word ptr [12326FEh] 
	0x83, 0xC1, 0x64,                        //add     ecx, 64h
	0x0F, 0xAF, 0x4C, 0x24, 0x20,            //imul    ecx, dword ptr [esp+20h]
	0xB8, 0x1F, 0x85, 0xEB, 0x51,            //mov     eax, 51EB851Fh
	0xF7, 0xE9,                              //imul    ecx
	0xC1, 0xFA, 0x05,                        //sar     edx, 5h
	0x8B, 0xC2,                              //mov     eax, edx  
	0xC1, 0xE8, 0x1F,                        //shr     eax, 1F  
	0x03, 0xD0,                              //add     edx, eax   
	0x89, 0x54, 0x24, 0x20,                  //mov     dword ptr [esp+20h], edx
                                             //normal:
	0x80, 0x3C, 0x24, 0xD4,                  //cmp     byte ptr [esp], 0D4h
	0x75, 0x01,                              //jnz     test_goal_soldier
	0xC3,                                    //retn
	                                         //test_goal_soldier:
	0x8B, 0x4E, 0x40,                        //mov     ecx, dword ptr [esi+40h]
//	0xF6, 0x41, 0x20, 0x01,                  //test    byte ptr [ecx+20h], 1
//	0x74, 0x09,                              //je      get_goal_soldier
//	0xB8, 0x40, 0x27, 0x46, 0x00,            //mov     eax, <San9PK.462740H;部队所属都设指针>
//	0xFF, 0xD0,                              //call    eax
//	0x8B, 0xC8,                              //mov     ecx, eax 
//	                                         //get_goal_soldier:
	0x8B, 0x11,                              //mov     edx, dword ptr [ecx]
	0xFF, 0x92, 0x80, 0x00, 0x00, 0x00,      //call    dword ptr [edx+80h]
	0x3B, 0x44, 0x24, 0x20,                  //cmp     eax, dword ptr [esp+20h]
	0x7D, 0x04,                              //jge     end
	0x89, 0x44, 0x24, 0x20,                  //mov     dword ptr [esp+20h], eax	
                                             //end:	
	0xC3                                     //retn
};

//intelligence damage record
BYTE codeIntelligenceDamageRecordThunk[] = {0xB8, 0x70, 0x7D, 0x0A, 0x00, 0xFF, 0xD0};//dwAddrDamageRecord - 4FE0CDh - 7
BYTE codeIntelligenceDamageRecordOldThunk[] = {0x83, 0x7C, 0x24, 0x18, 0x0A, 0x7C, 0x3B};//cmp dword ptr [esp+18h], 0Ah ; jl short 004FE10Fh
ASM_PATCH patchIntelligenceDamageRecordThunk[] = {
	{0x4FE0CD, sizeof(codeIntelligenceDamageRecordThunk), codeIntelligenceDamageRecordThunk},
	{0x4FE0CD, sizeof(codeIntelligenceDamageRecordOldThunk), codeIntelligenceDamageRecordOldThunk}};

//strength damage record	
BYTE codeStrengthDamageRecordThunk[] = {0x56, 0xE8, 0x29, 0x80, 0xBA, 0xFF, 0x5E};//dwAddrDamageRecord+10h - 4FFD51h - 7
BYTE codeStrengthDamageRecordOldThunk[] = {0x83, 0x7C, 0x24, 0x14, 0x0A, 0x7C, 0x2B};//cmp dword ptr [esp+14h], 0Ah ; jl short 004FFD83h
ASM_PATCH patchStrengthDamageRecordThunk[] = {
	{0x4FFD51, sizeof(codeStrengthDamageRecordThunk), codeStrengthDamageRecordThunk},
	{0x4FFD51, sizeof(codeStrengthDamageRecordOldThunk), codeStrengthDamageRecordOldThunk}};

//skip contained dialog
BYTE codeSkipContainedDialogThunk[] = {0x83, 0x7C, 0x24, 0x14, 0x0A, 0x7D, 0x5E};//cmp dword ptr [esp+14h], 0Ah ; jge short 004FFDE1h
BYTE codeSkipContainedDialogOldThunk[] = {0x5F, 0x5E, 0x5D, 0x5B, 0xC2, 0x08, 0x00};//pop edi;pop esi;pop ebp;pop ebx;retn 8h
ASM_PATCH patchSkipContainedDialogThunk[] = {
	{0x4FFD7C, sizeof(codeSkipContainedDialogThunk), codeSkipContainedDialogThunk},
	{0x4FFD7C, sizeof(codeSkipContainedDialogOldThunk), codeSkipContainedDialogOldThunk}};

//set troop index	
DWORD dwAddrSetTroopIndex = dwAddrStackBottom + 0x7DE0;
BYTE codeSetTroopIndex[] = {
    0x8B, 0x44, 0x24, 0x1C,                    //mov     eax, dword ptr [esp+1Ch]
    0x85, 0xC0,                                //test    eax, eax
    0x74, 0x05,                                //je      attack_troop
    0xC6, 0x04, 0x24, 0x13,                    //mov     byte ptr [esp], 13h 	
    0xC3,                                      //retn
	                                           //attack_troop:
    0xC6, 0x04, 0x24, 0x27,                    //mov     byte ptr [esp], 27h 
    0x57,                                      //push    edi
    0x53,                                      //push    ebx
    0x8D, 0x4C, 0x24, 0x40,                    //lea     ecx, dword ptr [esp+40h]
    0x8B, 0x59, 0x0C,                          //mov     ebx, dword ptr [ecx+0Ch]
    0x83, 0xFB, 0x03,                          //cmp     ebx, 3
    0x7E, 0x26,                                //jle     end
    0x0F, 0xB7, 0x56, 0x04,                    //movzx   edx, word ptr [esi+4] 
    0xC1, 0xE2, 0x04,                          //shl     edx, 4
    0x8B, 0x79, 0x04,                          //mov     edi, dword ptr [ecx+4]
	                                           //loop:
    0x8B, 0x4F, 0x08,                          //mov     ecx, dword ptr [edi+8]  
    0x8B, 0xC3,                                //mov     eax, ebx
	0x09, 0xD0,                                //or      eax, edx
    0x66, 0x89, 0x81, 0xA2, 0x00, 0x00, 0x00,  //mov     word ptr [ecx+0A2h], ax 
    0x66, 0x89, 0x81, 0x04, 0x01, 0x00, 0x00,  //mov     word ptr [ecx+104h], ax
    0x4B,                                      //dec     ebx
    0x8B, 0x3F,                                //mov     edi, dword ptr [edi]
    0x85, 0xFF,                                //test    edi, edi
    0x75, 0xE4,                                //jnz     loop
	                                           //end: 
    0x5B,                                      //pop     ebx
    0x5F,                                      //pop     edi  
    0xC3                                       //retn
};

BYTE codeSetTroopIndexThunk[] = {0xE8, 0xD0, 0xBD, 0xC1, 0xFF, 0x90};//dwAddrSetTroopIndex - 48C00Bh - 6
BYTE codeSetTroopIndexOldThunk[] = {0x8B, 0x44, 0x24, 0x18, 0x85, 0xC0};//mov     eax, dword ptr [esp+18h] ;test    eax, eax 
ASM_PATCH patchSetTroopIndexThunk[] = {
	{0x48C00B, sizeof(codeSetTroopIndexThunk), codeSetTroopIndexThunk},
	{0x48C00B, sizeof(codeSetTroopIndexOldThunk), codeSetTroopIndexOldThunk}};

//troop index
DWORD dwAddrTroopIndex = dwAddrStackBottom + 0x7E28;
BYTE codeTroopIndex[] = {
	////////////////////////////////troop_index///////////////////////////////////////////////
	0x8B, 0x44, 0x24, 0x04,                    //mov     eax, dword ptr [esp+4]   
	0x8B, 0x08,                                //mov     ecx, dword ptr [eax] 
	0x0F, 0xB7, 0x81, 0x04, 0x01, 0x00, 0x00,  //movzx   eax, word ptr [ecx+104h]
	0xC3                                       //retn
};

BYTE codeTroopIndexThunk[] = {0x28, 0x7E, 0x0A, 0x00};//dwAddrTroopIndex - 4EA2E0h - 4
BYTE codeTroopIndexOldThunk[] = {0xA0, 0x1C, 0x47, 0x00};//471CA0h;指标=大将能力
ASM_PATCH patchTroopIndexThunk[] = {
	{0x4EA2E0, sizeof(codeTroopIndexThunk), codeTroopIndexThunk},
	{0x4EA2E0, sizeof(codeTroopIndexOldThunk), codeTroopIndexOldThunk}};
	
//troop advise
DWORD dwAddrTroopAdvise = dwAddrStackBottom + 0x7E3D;
BYTE codeTroopAdvise[] = {
	///////////////////////////////cmp_troop_index////////////////////////////////////////////
	0x57,                                      //push    edi
	0x8B, 0x7C, 0x24, 0x08,                    //mov     edi, dword ptr [esp+8]
	0x8B, 0x0F,                                //mov     ecx, dword ptr [edi]
	0x8B, 0x91, 0xF4, 0x00, 0x00, 0x00,        //mov     edx, dword ptr [ecx+0F4h]
	0x33, 0xC0,                                //xor     eax, eax
	0xF6, 0x42, 0x20, 0x08,                    //test    byte ptr [edx+20h], 8
	0x75, 0x14,                                //jnz     fail
	0x0F, 0xB7, 0x91, 0x04, 0x01, 0x00, 0x00,  //movzx   edx, word ptr [ecx+104h]
	0x85, 0xD2,                                //test    edx, edx
	0x74, 0x09,                                //je      fail
	0xC1, 0xEA, 0x04,                          //shr     edx, 4
	0x3B, 0x57, 0x04,                          //cmp     edx, dword ptr [edi+4] 
	0x0F, 0x94, 0xC0,                          //sete    al
	                                           //fail:
	0x5F,                                      //pop     edi											   
	0xC3,                                      //retn
	//////////////////////////////TroopAdvise/////////////////////////////////////////////// 
	0x8B, 0x50, 0x0C,                          //mov     edx, dword ptr [eax+0Ch]
	0x85, 0xD2,                                //test    edx, edx	
	0x75, 0x49,                                //jnz     end
	0x8B, 0x5F, 0x04,                          //mov     ebx, dword ptr [edi+4]
	                                           //loop:
	0x8B, 0x4B, 0x08,                          //mov     ecx, dword ptr [ebx+8]
	0x0F, 0xB7, 0x81, 0x04, 0x01, 0x00, 0x00,  //movzx   eax, word ptr [ecx+104h]
	0x85, 0xC0,                                //test    eax, eax
	0x74, 0x38,                                //je      end
	0xC1, 0xE8, 0x04,                          //shr     eax, 4
	0x6A, 0x00,                                //push    0
	0x50,                                      //push    eax 
	0x68, 0x3D, 0x7E, 0x0A, 0x00,              //push    cmp_troop_index
	0x57,                                      //push    edi
	0x8D, 0x8E, 0x2C, 0x07, 0x00, 0x00,        //lea     ecx, dword ptr [esi+72Ch]
	0xB8, 0xF0, 0xF3, 0x46, 0x00,              //mov     eax, 46F3F0h 
	0xFF, 0xD0,                                //call    eax
	0x83, 0xF8, 0x03,                          //cmp     eax, 3
	0x7D, 0x0F,                                //jge     normal
	0xB8, 0xE0, 0x80, 0x51, 0x00,              //mov     eax, 5180E0h
	0xFF, 0xD0,                                //call    eax
	0x8B, 0x1B,                                //mov     ebx, dword ptr [ebx]
	0x85, 0xDB,                                //test    ebx, ebx
	0x75, 0xC7,                                //jnz     loop
	0xEB, 0x0B,								   //jmp	 end		
                                               //normal:	
	0xFF, 0x74, 0x24, 0x0C,                    //push    dword ptr [esp+0Ch]
	0xB8, 0xB0, 0xEE, 0x46, 0x00,              //mov     eax, 46EEB0h
	0xFF, 0xD0,                                //call    eax
	                                           //end:
	0x68, 0x00, 0x05, 0x57, 0x00,              //push    570500h
	0xC3                                       //retn
};

BYTE codeTroopAdviseThunk[] = {0xE8, 0x5F, 0xDB, 0xBB, 0xFF};//dwAddrTroopAdvise - 4EA304h - 5
BYTE codeTroopAdviseOldThunk[] = {0xE8, 0xF7, 0x61, 0x08, 0x00};//call    00570500h 
ASM_PATCH patchTroopAdviseThunk[] = {
	{0x4EA304, sizeof(codeTroopAdviseThunk), codeTroopAdviseThunk},
	{0x4EA304, sizeof(codeTroopAdviseOldThunk), codeTroopAdviseOldThunk}};	

//get troop index	
DWORD dwAddrGetTroopIndex = dwAddrStackBottom + 0x7EC0;
BYTE codeGetTroopIndex[] = {
	0x0F, 0xB7, 0x81, 0x04, 0x01, 0x00, 0x00, //movzx   eax, word ptr [ecx+104h]
	0x85, 0xC0,                               //test    eax, eax  
	0x0F, 0x84, 0x9F, 0x00, 0x00, 0x00,       //je      end
	0x8B, 0x01,                               //mov     eax, dword ptr [ecx]
	0xFF, 0x50, 0x3C,                         //call    dword ptr [eax+3Ch]
	0x8B, 0xCE,                               //mov     ecx, esi
	0x85, 0xC0,                               //test    eax, eax 
	0x74, 0x7D,                               //je      clear_troop_index
	0x80, 0xB9, 0x84, 0x00, 0x00, 0x00, 0x04, //cmp     byte ptr [ecx+84h], 4
	0x74, 0x74,                               //je      clear_troop_index
	0x8B, 0x81, 0xF4, 0x00, 0x00, 0x00,       //mov     eax, dword ptr [ecx+0F4h]
	0xF6, 0x40, 0x20, 0x08,                   //test    byte ptr [eax+20h], 8
	0x75, 0x73,                               //jnz     add_troop_index 
	0x57,                                     //push    edi  
	0x8B, 0x78, 0x64,                         //mov     edi, dword ptr [eax+64h]
	0x83, 0xEC, 0x40,                         //sub     esp, 40h
	0x8B, 0xCC,                               //mov     ecx, esp
	0xB8, 0xF0, 0x0D, 0x47, 0x00,             //mov     eax, 470DF0h 
	0xFF, 0xD0,                               //call    eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea     ecx, dword ptr [esp+20h]
	0xB8, 0xF0, 0x0D, 0x47, 0x00,             //mov     eax, 470DF0h
	0xFF, 0xD0,                               //call    eax
	0x8B, 0xCF,                               //mov     ecx, edi
	0x54,                                     //push    esp
	0xB8, 0x20, 0x6C, 0x43, 0x00,             //mov     eax, 436C20h
	0xFF, 0xD0,                               //call    eax
	0x0F, 0xB7, 0x86, 0x04, 0x01, 0x00, 0x00, //movzx   eax, word ptr [esi+104h]
	0xC1, 0xE8, 0x04,                         //shr     eax, 4 
	0x6A, 0x00,                               //push    0
	0x50,                                     //push    eax
	0x68, 0x3D, 0x7E, 0x0A, 0x00,             //push    cmp_troop_index 
	0x8D, 0x54, 0x24, 0x0C,                   //lea     edx, dword ptr [esp+0Ch]
	0x52,                                     //push    edx
	0x8D, 0x4C, 0x24, 0x30,                   //lea     ecx, dword ptr [esp+30h]
	0xB8, 0xF0, 0xF3, 0x46, 0x00,             //mov     eax, 46F3F0h
	0xFF, 0xD0,                               //call    eax  
	0x8B, 0xF8,                               //mov     edi, eax
	0x8D, 0x4C, 0x24, 0x20,                   //lea     ecx, dword ptr [esp+20h]
	0xB8, 0x10, 0x0E, 0x47, 0x00,             //mov     eax, 470E10h
	0xFF, 0xD0,                               //call    eax 
	0x8B, 0xCC,                               //mov     ecx, esp 
	0xB8, 0x10, 0x0E, 0x47, 0x00,             //mov     eax, 470E10h
	0xFF, 0xD0,                               //call    eax 
	0x83, 0xC4, 0x40,                         //add     esp, 40h
	0x83, 0xFF, 0x03,                         //cmp     edi, 3
	0x5F,                                     //pop     edi 
	0x8B, 0xCE,                               //mov     ecx, esi 
	0x7D, 0x0B,                               //jge     add_troop_index
	                                          //clear_troop_index:
	0x33, 0xC0,                               //xor     eax, eax
	0x66, 0x89, 0x81, 0x04, 0x01, 0x00, 0x00, //mov     word ptr [ecx+104h], ax
	0xEB, 0x0C,                               //jmp     end
	                                          //add_troop_index:
	0x66, 0x8B, 0x81, 0x04, 0x01, 0x00, 0x00, //mov     ax, word ptr [ecx+104h]
	0x66, 0x01, 0x44, 0x24, 0x06,             //add     word ptr [esp+6], ax 
	                                          //end:
	0x68, 0xB0, 0xBF, 0x44, 0x00,             //push    44BFB0h
	0xC3                                      //retn
};

BYTE codeGetTroopIndexThunk[] = {0xE8, 0xC3, 0x26, 0xC5, 0xFF};//dwAddrGetTroopIndex - 4557F8h - 5
BYTE codeGetTroopIndexOldThunk[] = {0xE8, 0xB3, 0x67, 0xFF, 0xFF};//call    44BFB0h 
ASM_PATCH patchGetTroopIndexThunk[] = {
	{0x4557F8, sizeof(codeGetTroopIndexThunk), codeGetTroopIndexThunk},
	{0x4557F8, sizeof(codeGetTroopIndexOldThunk), codeGetTroopIndexOldThunk}};	
		