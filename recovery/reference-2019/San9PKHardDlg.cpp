// San9PKHardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "San9PKHard.h"
#include "San9PKHardDlg.h"

#include "InsertAsm.h"
#include "ReadWriteError.h"
#include "InitData.h"
#include "ParaSettingDlg.h"

#define CHECK_ERROR(error_id)\
		if (bSuccess == FALSE)\
		{\
			dwWrData = error_id;\
			goto end_of_operation;\
		}\
		//str.Format("%d : error=%d", error_id, ::GetLastError());

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSan9PKHardDlg dialog

CSan9PKHardDlg::CSan9PKHardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSan9PKHardDlg::IDD, pParent),
	m_dwPageSize(0x1000), m_dwAllocPageNum(8),
	m_iOfficialNum(OFFICIAL_NUM),
	m_dwTrainNumAddr(0x40CAEF), m_dwTrainNumAddr2(0x40BF25), m_dwOldTrainNum(50),
	m_dwCultivateMinPoliticsAddr(0x4B6787), m_dwCultivateMinPolitics(0x23), m_dwOldCultivateMinPolitics(0x2D),
	m_dwHarborKillerAddr(0x501F74), m_dwHarborKillerFunction(0x501B49), m_dwHarborKillerOldFunction(0x501F57),
	m_dwTownKillerAddr(0x501F88), m_dwTownKillerFunction(0x501B7A), m_dwTownKillerOldFunction(0x501B49),
	m_dwBattleExperienceAddr(0x50B0B0), m_dwBattleExperienceCode(0x54), m_dwBattleExperienceOldCode(0x50),
	m_dwWaterExperienceAddr(0x50B040), m_dwWaterExperienceCode(0xFF), m_dwWaterExperienceOldCode(4),
	m_dwBurnExperienceAddr(0x496A63), m_dwBurnExperienceCode(0x076A14EB), m_dwBurnExperienceOldCode(0x076A026A),
	m_dwRobExperienceAddr(0x48DFF7), m_dwRobExperienceCode(0x076A14EB), m_dwRobExperienceOldCode(0x076A026A),
	m_dwReinforceExperienceAddr(0x492E29), m_dwReinforceExperienceCode(0x076A14EB),
	m_dwReinforceExperienceOldCode(0x076A026A),
	m_dwTrainExperienceAddr(0x48A2B8), m_dwTrainExperienceCode(0x006A35EB), m_dwTrainExperienceOldCode(0x006A016A),
	m_dwRepairExperienceAddr(0x4895C8), m_dwRepairExperienceCode(0x066A14EB), m_dwRepairExperienceOldCode(0x066A016A),
	m_dwBuildExperienceAddr(0x49C3F2), m_dwBuildExperienceCode(0xFF), m_dwBuildExperienceOldCode(6),
	m_dwAlienateIntelligenceAddr(0x493791), m_dwAlienateIntelligenceCode(6), m_dwAlienateIntelligenceOldCode(7),
	m_dwGossipIntelligenceAddr(0x493E4F), m_dwGossipIntelligenceCode(6), m_dwGossipIntelligenceOldCode(7),
	m_dwInspireIntelligenceAddr(0x48E981), m_dwInspireIntelligenceCode(6), m_dwInspireIntelligenceOldCode(7),
	m_dwCheatIntelligenceAddr(0x48EFD5), m_dwCheatIntelligenceCode(6), m_dwCheatIntelligenceOldCode(8),
	m_dwDisorderIntelligenceAddr(0x490EF5), m_dwDisorderIntelligenceCode(6), m_dwDisorderIntelligenceOldCode(8),
	m_dwSaveBaseAddr(0x492A3D), m_dwSaveBase(0x32), m_dwOldSaveBase(0x1E),
	m_dwCommonDataPageAddr(0x43F000), m_dwCaptionPageAddr(0x61C000), m_dwFriendshipPageAddr(0x610000),
	m_dwSearchSelectPageAddr(0x4EC000), m_dwSearchPerformPageAddr(0x485000),
	m_dwGoFastFlagAddr(0x43F227), m_dwGoFastCounterAddr(0x43F22B), m_dwDecisionReadyFlagAddr(0x43F4CA),
	m_dwInfoFastFlagAddr(0x43FFD6), m_dwInfoFastCounterAddr(0x43FFDA),
	m_dwAwardFastFlagAddr(0x43F7C4), m_dwAwardFastCounterAddr(0x43F7C8), m_dwAwardablePersonNumberAddr(0x43F7CC),
	m_dwResourceInfoAddr(0x1B44000), m_dwFixedFileInfoOffset(0x18C8),
	m_dwDispatchArrayAddr(0x4B9B8F), m_dwDispatchArray(0xE), m_dwOldDispatchArray(6),
	m_dwDispatchShipAddr(0x4B9BB6), m_dwDispatchShip(0x19), m_dwOldDispatchShip(0x14),
	m_dwChaosDayAddr(0x504F8A), m_dwChaosDayCoef(0xDA740DA), m_dwOldChaosDayCoef(0x10624DD3),
	m_dwWisdomResistTrickAddr(0x4FEBC0), m_dwWisdomResistTrickCoef(0xC0), m_dwOldWisdomResistTrickCoef(0xC3),
	m_dwLowerTrickAddr(0x4FECFA), m_dwLowerTrapAddr(0x4FEE0E), m_dwLowerTrickCoef(5), m_dwOldLowerTrickCoef(0x3),
	m_dwAntiAttackMinSoldierdAddr(0x4A33D7), m_dwAntiAttackMinSoldier(0x3000), m_dwOldAntiAttackMinSoldier(0x4E20),
	m_dwAntiMinTroopSoldierAddr(0x4A3DF1), m_dwAntiMinTroopSoldier(0x1770), m_dwOldAntiMinTroopSoldier(0x1F40),
	m_dwAntiAttackBarbarismAddr(0x4B06B1), m_dwAntiAttackBarbarism(0x00), m_dwOldAntiAttackBarbarism(0xE4),
	m_dwAntiAttackAssistantAddr(0x4A3D00), m_dwAntiAttackAssistant(0x01EB5858), m_dwOldAntiAttackAssistant(0xFCB27BE8),
	m_dwAlienateForceNameAddr(0x4935EA), m_dwAlienateForceName(0xEB), m_dwOldAlienateForceName(0x74),
	m_dwOfficerBasicCommandAddr(0x4B2D49), m_dwOfficerBasicCommand(0x64), m_dwOldOfficerBasicCommand(0x68),
	m_dwOfficerBasicIntAddr(0x4B2E37), m_dwOfficerBasicInt(0x5C4E8B54), m_dwOldOfficerBasicInt(0x604E8B58),
	m_dwCheckLeagueProbabilityAddr(0x57B419), m_dwOldCheckLeagueProbability(4),
	m_dwAllPersonLiveAddr(0x481B76), m_dwAllPersonLive(0x33), m_dwOldAllPersonLive(0x85),
	m_dwSearchRangePageAddr(0x4B0000), m_dwPerformPersonAddr(0x43F177)/*search_person_pointer*/,
	m_dwSearchMinPoliticsAddr(0x4B6787), m_dwSearchMinPolitics(60), m_dwOldSearchMinPolitics(0x23),
	m_dwNpcSearchTreasureAddr(0x589E14), m_dwNpcSearchTreasure(0x00), m_dwOldNpcSearchTreasure(0x14),
	m_dwNpcDisplayTreasureAddr(0x49492A), m_dwNpcDisplayTreasure(0), m_dwOldNpcDisplayTreasure(0x26),
	m_dwFootAntiElephantAddr(0x4FEB30), m_dwFootAntiElephant(0x197F013C), m_dwOldFootAntiElephant(0x1975FF85),
	m_dwInspireMaxVigourAddr(0x4A492E), m_dwInspireMaxVigour(70), m_dwOldInspireMaxVigour(80),
	m_dwAllPersonDead1Addr(0x502664), m_dwAllPersonDead2Addr(0x452466), m_dwAllPersonDead3Addr(0x452594),
	m_dwAllPersonDead(121), m_dwOldAllPersonDead(80),
	m_dwGeneralDead1Addr(0x502658), m_dwGeneralDead2Addr(0x452449), m_dwGeneralDead3Addr(0x452584),
	m_dwGeneralDead(0), m_dwOldGeneralDead(4),
	m_dwMaxBasicAbilityAddr(0x44D1AB), m_dwMaxBasicAbility(125), m_dwOldMaxBasicAbility(100),
	m_dwMaxSearchAbilityAddr(0x588FB1),
	m_dwLoadMaxFoodAddr(0x43DA06), m_dwLoadMaxFood(0x2DC6C0), m_dwOldLoadMaxFood(0xF4240),
	m_dwDonateMaxFoodAddr(0x5090AD),m_dwForecastMaxFoodAddr(0x43EFE9),m_dwDialogMaxFoodAddr(0x47F473),
	m_dwTroopWoundAddr(0x467130), m_dwTroopWound(13), m_dwOldTroopWound(10),
	m_dwBuildingWoundAddr(0x439B34), m_dwBuildingWound(12), m_dwOldBuildingWound(10),
	m_dwGossipNoAlienateAddr(0x493CED), m_dwGossipNoAlienate(0xEB), m_dwOldGossipNoAlienate(0x74),
	m_dwGossipSubLoyaltyAddr(0x493DBC), m_dwGossipSubLoyalty(0xEB), m_dwOldGossipSubLoyalty(0x74),
	m_dwGoalNullCityAddr(0x4B6224), m_dwGoalNullCity(0xFFFFFE98), m_dwOldGoalNullCity(0xFFFFD978),
	m_dwNullBulidingDangerAddr(0x4B5839), m_dwNullBulidingDanger(0xEB), m_dwOldNullBulidingDanger(0x75),
	m_dwAvoidNearCityAddr(0x4B520B), m_dwAvoidNearCity(0x18EB), m_dwOldAvoidNearCity(0x016A),
	m_dwRetreatMinVigourAddr(0x464F20), m_dwRetreatMinVigour(30), m_dwOldRetreatMinVigour(25),
	m_dwOfficialLoyaltyAddr(0xA31B0),//official_loyalty
	m_dwSelectCleverKillerAddr(0x4B8295), m_dwSelectCleverKiller(0), m_dwOldSelectCleverKiller(0x25),
	m_dwNoneOfficialSalaryAddr(0x44D6F8), m_dwOldNoneOfficialSalary(1),
	m_dwNeglectChongCheAddr(0x4B87EB), m_dwNeglectChongChe(0x33), m_dwOldNeglectChongChe(0x85),
	m_dwSameForceTroopAddr(0x4B4826), m_dwSameForceTroopAddr2(0x4B4295),
	m_dwSameForceTroop(0xB0), m_dwOldSameForceTroop(0x60),
	m_dwDisableNpcPlotForceAddr(0x4AAA20), m_dwDisableNpcPlotForce(0x33), m_dwOldDisableNpcPlotForce(0x85),
	m_dwAttackIgnoreAntitrapAddr(0x4B801D), m_dwAttackIgnoreAntitrap(0xEB), m_dwOldAttackIgnoreAntitrap(0x74),
	m_dwMunicipalForceDraftAddr(0x657724+4*5), m_dwMunicipalForceDraft(4), m_dwOldMunicipalForceDraft(5),
	m_dwBurnFoodProbabilityAddr(0x496883), m_dwBurnFoodProbability(60), m_dwOldBurnFoodProbability(3),
	m_dwBurnFoodEffectAddr(0x4968BE), m_dwBurnFoodEffect(0x28), m_dwOldBurnFoodEffect(0x10),
	m_dwBurnBuildingEffectAddr(0x4967EE), m_dwBurnBuildingEffect(3), m_dwOldBurnBuildingEffect(2),
	m_dwHomeForceDoorAddr(0x4A79A3), m_dwHomeForceDoor(25), m_dwOldHomeForceDoor(50),
	m_dwAvoidInduceMaxDayAddr(0x49F323), m_dwAvoidInduceMaxDay(25), m_dwOldAvoidInduceMaxDay(10),
	m_dwBuildingDefenseCoefAddr(0x49A446), m_dwBuildingDefenseCoef(3), m_dwOldBuildingDefenseCoef(2),
	m_dwGetTroopGoalBugAddr(0x4AFD96), m_dwGetTroopGoalBug(0xFFFA3526), m_dwOldGetTroopGoalBug(0xFFFA3596),
	m_dwArrayCenterImageAddr(0x454AC4),
	m_dwGoalToSourceDamageAddr(0x49BA6D), m_dwGoalToSourceDamage(0x9C), m_dwOldGoalToSourceDamage(0x98),
	m_dwBadBrothersArrayEndAddr(0x4FF803), m_dwBadBrothersArrayEnd(0x610740), m_dwOldBadBrothersArrayEnd(0x6108F8),
	m_dwTroopFromBuildingAddr(0x4BC038), m_dwTroopFromBuilding(0x0E), m_dwOldTroopFromBuilding(0x04),
	m_dwFalseAntiTroopAddr(0x4A5759), m_dwDisorderAntiTroopAddr(0x4AC72A),
	m_dwInternalAntiTroop(0x4A5280), m_dwExternalAntiTroop(0x4AC4B0),
	m_dwDeclareAttackTroopAddr(0x50AA2F), m_dwDeclareAttackTroop(0), m_dwOldDeclareAttackTroop(0x44),
	m_dwNotAttackOnlyBuildingAddr(0x4B6272), m_dwNotAttackOnlyBuilding(0x9002EB59), m_dwOldNotAttackOnlyBuilding(0xFFF8E9E8),
	m_dwInviteSubLoyatyAddr(0x495F2F), m_dwInviteSubLoyaty(0x53), m_dwOldInviteSubLoyaty(0x55),
	m_dwCommandOfficerEndFlagAddr(0x4B2D10), m_dwCommandOfficerEndFlag(8), m_dwOldCommandOfficerEndFlag(0x3C),
	m_dwIntelligenceOfficerEndFlagAddr(0x4B2DF4), m_dwIntelligenceOfficerEndFlag(8), m_dwOldIntelligenceOfficerEndFlag(0x34),
	m_dwMaxExperienceAddr(0x43FFDE),
	m_dwShowCelueKillerAddr(0x4368DA), m_dwShowCelueKiller(0), m_dwOldShowCelueKiller(0x10101),
	m_dwSlashDeadCoefAddr(0x50266D), m_dwOldSlashDeadCoef(80),
	m_dwShowSexMapAddr(0x4520CC+0x19), m_dwShowSexMap(0), m_dwOldShowSexMap(0xE),
	m_dwLvbuAttackDoorAddr(0x4B5AC4), m_dwLvbuAttackDoor(4), m_dwOldLvbuAttackDoor(0x3C),
	m_dwEnableSecondKillerAddr(0x50233C), m_dwEnableSecondKiller(0), m_dwOldEnableSecondKiller(0xF6),
	m_dwTroopGoalBuildingAddr(0x4B40CF), m_dwTroopGoalBuilding(0x49EB20), m_dwOldTroopGoalBuilding(0x4B0770),
	m_dwInviteAddLoyatyAddr(0x495EBC), m_dwInviteAddLoyaty(45), m_dwOldInviteAddLoyaty(75),
	m_dwNotGetPersonQuotaAddr(0x4BDBDB), m_dwNotGetPersonQuota(0xC3), m_dwOldNotGetPersonQuota(0xE9),
	m_dwEventMeetHuaTuoAddr(0x582A81), m_dwEventMeetHuaTuo(0x33), m_dwOldEventMeetHuaTuo(0x85),
	m_dwYearTableInvalidFlagAddr(0x430153), m_dwYearTableInvalidFlag(0x8C), m_dwOldYearTableInvalidFlag(0x84),
	m_dwTransportGoalInfoAddr(0x45FC3E), m_dwTransportGoalInfo(0xB11E), m_dwOldTransportGoalInfo(0xC7DE),
	m_dwCounselorMinCandidateAddr(0x4A5B10), m_dwCounselorMinCandidate(1), m_dwOldCounselorMinCandidate(5),
	m_dwNoarrayToBuildingAddr(0x50553E), m_dwNoarrayToBuildingAddr2(0x46406C),
	m_dwNoarrayToBuilding(0x00), m_dwOldNoarrayToBuilding(0x01),
	m_dwDisableBurnExplorerAddr(0x4FCE7F), m_dwDisableBurnExplorer(0), m_dwOldDisableBurnExplorer(0xE5),
	m_dwDisableAttackExplorerAddr(0x4F59A5), m_dwDisableAttackExplorer(0xC0), m_dwOldDisableAttackExplorer(0xC3),
	m_dwMaskPersonWhereAddr(0x451C11), m_dwMaskPersonWhere(0), m_dwOldMaskPersonWhere(7),
	m_dwSearchNoResultAddr(0x494420), m_dwSearchNoResult(0x33), m_dwOldSearchNoResult(0x85),
	m_dwPersonNumKillerPropAddr(0x4FEA7B),
	m_dwAttackBuildForceAddr(0x4A2F25), m_dwAttackBuildForce(0xF0), m_dwOldAttackBuildForce(0x50),
	m_dwBuildMaxArriveDayAddr(0x4A2EC0), m_dwBuildMaxArriveDay(0x19), m_dwOldBuildMaxArriveDay(0x14),
	m_dwGameEndYearAddr(0x4803C8), m_dwGameEndYear(0x7FFFFFFF), m_dwOldGameEndYear(350),
	m_dwBuildMinBuildingAddr(0x43D0C7), m_dwBuildMinBuilding(7), m_dwOldBuildMinBuilding(6),
	m_dwUpdateGoalForceAddr(0x4A811B), m_dwUpdateGoalForce(0xEB), m_dwOldUpdateGoalForce(0x7E),
	m_dwUpdateGoalPropAddr(0x4A82E9), m_dwUpdateGoalProp(12), m_dwOldUpdateGoalProp(8),
	m_dwLeagueTimeAddr(0x57C06F), m_dwOldLeagueTime(36),
	//m_dwKillPersonPropAddr(0x4A6DE5), m_dwKillPersonProp(5), m_dwOldKillPersonProp(0x13),
	m_dwKillPersonPropAddr(0x4A6E01), m_dwKillPersonProp(0x33), m_dwOldKillPersonProp(0x85),	
	m_dwSexCoefAddr(0x408C7D), m_dwOldSexCoef(0x23),
	m_dwEnableGoMenuAddr(0x4C0F93), m_dwEnableGoMenu(0x33), m_dwOldEnableGoMenu(0x85),
	m_dwEnableComeMenuAddr(0x4C7EFC),
//////////////2019年增加///////////////////////////////////////////////
    m_dwBlockArrayNumAddr(0x5030EA), m_dwBlockArrayNum(4), m_dwOldBlockArrayNum(5),	
	m_dwBarbarianNotDisappearAddr1(0x438E36),m_dwBarbarianNotDisappear1(4),m_dwOldBarbarianNotDisappear1(8),
	m_dwBarbarianNotDisappearAddr2(0x442261),m_dwBarbarianNotDisappear2(5),
	m_dwBarbarianNotDisappearAddr3(0x442273),m_dwBarbarianNotDisappear3(0),m_dwOldBarbarianNotDisappear3(9),
    m_dwNotDisplaySlashAddr(0x504389), m_dwNotDisplaySlash(0x0AEB), m_dwOldNotDisplaySlash(0x5055),
    m_dwNotDisplayExchangeAddr1(0x48FE30), m_dwNotDisplayExchangeAddr2(0x48FE43), m_dwNotDisplayExchange(0x33), m_dwOldNotDisplayExchange(0x85),
	m_dwSubforceTroopControlAddr(0x51D6D1), m_dwSubforceBuildingControlAddr(0x51D737),
	m_dwSubforceControl(0x30), m_dwOldSubforceControl(0x34)	
{
	//{{AFX_DATA_INIT(CSan9PKHardDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSan9PKHardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSan9PKHardDlg)
	DDX_Control(pDX, IDC_STATUS, m_ctrlStatus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSan9PKHardDlg, CDialog)
	//{{AFX_MSG_MAP(CSan9PKHardDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_PARA_SETTING, OnParaSetting)
	ON_BN_CLICKED(IDC_START_SAN9, OnStartSan9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSan9PKHardDlg message handlers

BOOL CSan9PKHardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

__asm{
}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	int i = 0;

	//resource
	m_hSan9PKWnd = NULL;
	m_hSan9PKProcess = NULL;
	m_dwProcessId = 0;

	//state and flag
	m_eState = STATE_FREE;

	//hwnd and message
	m_sWndMsg.hWnd = m_hWnd;
	m_sWndMsg.uMsg = ::RegisterWindowMessage("San9PKHard");
	m_sWndMsg.uNum = 0xC3C3C3C3;//ret

	//count
	m_iDelayCount = 0;
	m_iErrCount = 0;
	m_iDisplayCount= 0;

	//难度选项
	m_bEnableTrain = m_bNpcAllieAttack = m_bSubCounsellorJudge = FALSE;
	m_bAddNpcMoneyFood = m_bEnableRelayDispatch = m_bDispatchSoldierToPlayer = m_bDisableSearchEvent = FALSE;
	m_bEnableBaramArray = m_bSearchMaxAbility = m_bSubRobFood = m_bWarFog = m_bNotSureCaptive = FALSE;
	m_bNullCitySubMunicipal = m_bNpcSearchTreasure = m_bNpcAutoDraft = m_bDisableMovePerson = FALSE;
		
	//新增选项
	m_bBarbarianNotDisappear = m_bAddKillerJianyu = m_bDisableKillerJianlan = m_bNotDisplaySlash = FALSE;	
    m_bNotDisplayExchange = m_bEnableCityPopulationCoef = FALSE;
	
	//系统选项
	m_bAllPersonLive = m_bGeneralDead = m_bAllPersonDead = m_bDisableAlienate = m_bSoldierCommandKiller = FALSE;
	m_bSecondKiller = m_bFriendToAlienate = m_bSubWoundSoldier = m_bDisableNpcPlotForce = m_bBurnFood = FALSE;
	m_bDisableBurn = m_bMunicipalDraft = m_bDoubleBuildingDefense = m_bNotAddDraft = m_bAlikeKillerLinkage = FALSE;
	m_bDynamicAddProficiency = m_bDynamicAddAbility = m_bChangeTroopCommand = m_bWeakenLongRangeKiller = FALSE;
	m_bMunicipalForceDraft = m_bUpdateWaterKillerProp = m_bMinDurabilityZero = m_bUpdateZoneCity = FALSE;
	m_bFightKillerProp = m_bGooseKillerLinkage = m_bSoldierSubKiller = m_bPlayerAutoProcess = FALSE;
	m_bLowDurabilityChaos = m_bLeaderInspire = m_bDisableKillPerson = m_bKillAddProficiency = FALSE;
	m_bAbilityKillerProp = FALSE;


	//资金分隔点
	m_uMoneyCut_1 = 12;
	m_uMoneyCut_2 = 24;
	m_uMoneyCut_3 = 49;
	//兵粮分隔点
	m_uFoodCut_1 = 24;
	m_uFoodCut_2 = 49;
	m_uFoodCut_3 = 98;
	//兵役分隔点
	m_uDraftCut_1 = 9;
	m_uDraftCut_2 = 24;
	m_uDraftCut_3 = 49;

	//系统参数
	m_iYearDifference = 0;
	m_uKillerPowerCoef = 10;
	m_uSlashDeadCoef = 0;
	m_uNoOfficialSalary = 1;
	m_uBlockPropCoef = 5;
	m_uNpcAttackDisorder = 0;
	m_uNatureAttractCoef = 0;
	m_uOnePersonKillerProp = 20;//部队武将数兵法概率系数
	m_uTwoPersonKillerProp = 14;
	m_uThreePersonKillerProp = 10;
	m_uFourPersonKillerProp = 9;
	m_uFivePersonKillerProp = 8;
	m_uAntiPlayerLeagueCoef = 0;
	m_uLeagueTime = 36;
	m_uFightSubIncomeCoef = 0;
	m_uMaxCaptiveCoef = 10;

	//战争迷雾
	m_uCityViewRange = 80;
	m_uBuildingViewRange = 60;
	m_uTroopViewRange = 40;
	m_uSoldierDisplayError = 50;
	m_uCounselorReportCoef = 5;

	//武将配置信息
	m_dwAddrPersonConfigInfo = 0xA4000;//person_config_info
	for (i=0; i<CONFIG_PERSON_NUM; i++)
	{
		m_dwPersonConfigInfo[i] = 0x3FEAA;
	}

	//精进最大熟练度
	m_wMaxExperience = 1500;

	//武将亲密度表
	m_dwAddrPersonFriendship = 0x610740;
	for (i=0; i<PERSON_FRIENDSHIP_NUM/2; i++)
	{
		m_wPersonFriendship[i][0] = m_wOldPersonFriendship[i][0];
		m_wPersonFriendship[i][1] = m_wOldPersonFriendship[i][1];
		m_wPersonFriendship[i][2] = m_wOldPersonFriendship[i][2];
	}
	for (; i<PERSON_FRIENDSHIP_NUM; i++)
	{
		m_wPersonFriendship[i][0]=m_wPersonFriendship[i][1]=m_wPersonFriendship[i][2]=0;
		m_wOldPersonFriendship[i][0]=m_wOldPersonFriendship[i][1]=m_wOldPersonFriendship[i][2]=0;
	}

	//都市配置信息
	m_bCityConfigAuto = FALSE;//都市配置自动标志=0
	m_bCityConfigRead = FALSE;//都市配置读取标志=0
	m_dwCityMaxSoldierAddr = 0xA5662;//city_max_soldier
	m_dwCityMaxPeopleHeartAddr = 0xA5630;//city_max_people_heart
	for (i=0; i<CITY_NUM; i++)//init city max soldier and people
	{
		m_btInitCityMaxSoldier[i] = 50;
		m_btInitCityMaxPeopleHeart[i] = 10;
	}

	//都市攻防关系
	m_dwCityRelationAddr = 0xA6E00;//city_relation_table[]
	m_dwAttackCityMaxDayAddr = 0xA3CC0;//attack_max_arrive_day[]
	//attack max arrive day
	for (i = 0; i < CITY_NUM; i++)
		m_btAttackCityMaxDay[i] += 2;//最大到达天数的容差范围=2

	//兵法配置信息
	m_btKillerConfigRead = 0;//兵法配置标志=0
	
	//阵型配置信息
	m_btArrayConfigRead = 0;//阵型配置标志=0
	m_dwAddrArrayAttackRange = 0xA1AE0;//array_attack_range

	//小兵培养配置
	m_uBasicAbilityCoef = 0;
	m_uSexCoef = 35;

	//create timer
	m_uTimerID = SetTimer(39, 1000, NULL);//1-second timer
	if (m_uTimerID == 0)
	{
		AfxMessageBox("创建定时器失败!!!");
	}

	LoadConfig();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

bool CSan9PKHardDlg::CheckGameVersion()
{
	const DWORD dwSignature = 0xFEEF04BD;
	const DWORD dwVersion_0 = 0;
	const DWORD dwVersion_1 = 0x00010000;
	
	DWORD dwRdData;
	BOOL bSuccess = FALSE;
	bool rv = false;
	int i;

//signature
	bSuccess = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwResourceInfoAddr + m_dwFixedFileInfoOffset),\
										(LPVOID)&dwRdData, DWORD_SIZE, NULL);
	if (bSuccess == FALSE || dwRdData != dwSignature)
	{	goto end;	}
//MS version
	bSuccess = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwResourceInfoAddr + m_dwFixedFileInfoOffset + 8),\
										(LPVOID)&dwRdData, DWORD_SIZE, NULL);
	if (bSuccess == FALSE || dwRdData != dwVersion_1)
	{	goto end;	}
//LS verison
	bSuccess = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwResourceInfoAddr + m_dwFixedFileInfoOffset + 0xC),\
										(LPVOID)&dwRdData, DWORD_SIZE, NULL);
	if (bSuccess == FALSE)
	{	goto end;	}

	if (dwRdData == dwVersion_0)
	{//version=1.0.0.0
		goto end;
	}
	else if (dwRdData == dwVersion_1)
	{//version=1.0.1.0
		rv =  true;//success

		//shared data
		m_dwCityAddr[0] = CITY_ADDR;
		for (i=1; i<CITY_NUM; i++)
		{	m_dwCityAddr[i] = m_dwCityAddr[i-1] + CITY_SIZE;	}
		m_dwZoneAddr[0] = ZONE_ADDR;
		for (i=1; i<ZONE_NUM; i++)
		{	m_dwZoneAddr[i] = m_dwZoneAddr[i-1] + ZONE_SIZE;	}
//patch
		//not alienate garbage
		for (i = 0; i < PATCH_NOT_ALIENATE_GARBAGE_NUM; i++)
		{
			patchNotAlienateGarbage[i].dwAddr = dwAddrNotAlienateGarbage[i];
			patchNotAlienateGarbage[i].dwSize = dwSizeNotAlienateGarbage[i];
			patchNotAlienateGarbage[i].pCode = codeNotAlienateGarbage[i];
		}
		//wisdom effective flag
		for (i = 0; i < PATCH_WISDOM_EFFECTIVE_FLAG_NUM; i++)
		{
			patchWisdomEffectivFlag[i].dwAddr = dwAddrWisdomEffectivFlag[i];
			patchWisdomEffectivFlag[i].dwSize = dwSizeWisdomEffectivFlag[i];
			patchWisdomEffectivFlag[i].pCode = codeWisdomEffectivFlag[i];
		}
		//min durability
		for (i = 0; i < PATCH_MIN_DURABILITY_NUM; i++)
		{
			patchMinDurability[i].dwAddr = dwAddrMinDurability[i];
			patchMinDurability[i].dwSize = dwSizeMinDurability[i];
			patchMinDurability[i].pCode = codeMinDurability[i];
		}
		//battle disable gossip
		for (i = 0; i < PATCH_BATTLE_DISABLE_GOSSIP_NUM; i++)
		{
			patchBattleDisableGossip[i].dwAddr = dwAddrBattleDisableGossip[i];
			patchBattleDisableGossip[i].dwSize = dwSizeBattleDisableGossip[i];
			patchBattleDisableGossip[i].pCode = codeBattleDisableGossip[i];
		}
		//building killer
		for (i = 0; i < PATCH_BUILDING_KILLER_NUM; i++)
		{
			patchBuildingKiller[i].dwAddr = dwAddrBuildingKiller[i];
			patchBuildingKiller[i].dwSize = dwSizeBuildingKiller[i];
			patchBuildingKiller[i].pCode = codeBuildingKiller[i];
		}
		//siege experience
		for (i = 0; i < PATCH_SIEGE_EXPERIENCE_NUM; i++)
		{
			patchSiegeExperience[i].dwAddr = dwAddrSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM-1 - i];
			patchSiegeExperience[i].dwSize = dwSizeSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM-1 - i];
			patchSiegeExperience[i].pCode = codeSiegeExperience[PATCH_SIEGE_EXPERIENCE_NUM-1 - i];
		}
		//garbage person
		for (i = 0; i < PATCH_GARBAGE_PERSON_NUM; i++)
		{
			patchGarbagePerson[i].dwAddr = dwAddrGarbagePerson[i];
			patchGarbagePerson[i].dwSize = dwSizeGarbagePerson[i];
			patchGarbagePerson[i].pCode = codeGarbagePerson[i];
		}
		//filter ready person
		for (i = 0; i < PATCH_FILTER_READY_PERSON_NUM; i++)
		{
			patchFilterReadyPerson[i].dwAddr = dwAddrFilterReadyPerson[i];
			patchFilterReadyPerson[i].dwSize = dwSizeFilterReadyPerson[i];
			patchFilterReadyPerson[i].pCode = codeFilterReadyPerson[i];
		}
		//sub journey expense
		for (i = 0; i < PATCH_SUB_JOURNEY_EXPENSE_NUM; i++)
		{
			patchSubJourneyExpense[i].dwAddr = dwAddrSubJourneyExpense[i];
			patchSubJourneyExpense[i].dwSize = dwSizeSubJourneyExpense[i];
			patchSubJourneyExpense[i].pCode = codeSubJourneyExpense[i];
		}
		//troop siege power
		for (i = 0; i < PATCH_TROOP_SIEGE_POWER_NUM; i++)
		{
			patchTroopSiegePower[i].dwAddr = dwAddrTroopSiegePower[i];
			patchTroopSiegePower[i].dwSize = dwSizeTroopSiegePower[i];
			patchTroopSiegePower[i].pCode = codeTroopSiegePower[i];
		}
		//alienate experience
		for (i = 0; i < PATCH_ALIENATE_EXPERIENCE_NUM; i++)
		{
			patchAlienateExperience[i].dwAddr = dwAddrAlienateExperience[i];
			patchAlienateExperience[i].dwSize = dwSizeAlienateExperience[i];
			patchAlienateExperience[i].pCode = codeAlienateExperience[i];
		}
		//dispatch troop
		for (i = 0; i < PATCH_DISPATCH_TROOP_NUM; i++)
		{
			patchDispatchTroop[i].dwAddr = dwAddrDispatchTroop[i];
			patchDispatchTroop[i].dwSize = dwSizeDispatchTroop[i];
			patchDispatchTroop[i].pCode = codeDispatchTroop[i];
		}
		//cheat experience
		for (i = 0; i < PATCH_CHEAT_EXPERIENCE_NUM; i++)
		{
			patchCheatExperience[i].dwAddr = dwAddrCheatExperience[i];
			patchCheatExperience[i].dwSize = dwSizeCheatExperience[i];
			patchCheatExperience[i].pCode = codeCheatExperience[i];
		}
		//full prize
		for (i = 0; i < PATCH_FULL_PRIZE_NUM; i++)
		{
			patchFullPrize[i].dwAddr = dwAddrFullPrize[i];
			patchFullPrize[i].dwSize = dwSizeFullPrize[i];
			patchFullPrize[i].pCode = codeFullPrize[i];
		}
		//enable draft
		for (i = 0; i < PATCH_ENABLE_DRAFT_NUM; i++)
		{
			patchEnableDraft[i].dwAddr = dwAddrEnableDraft[i];
			patchEnableDraft[i].dwSize = dwSizeEnableDraft[i];
			patchEnableDraft[i].pCode = codeEnableDraft[i];
		}
		//min dispatch soldier
		for (i = 0; i < PATCH_MIN_DISPATCH_SOLDIER_NUM; i++)
		{
			patchMinDispatchSoldier[i].dwAddr = dwAddrMinDispatchSoldier[i];
			patchMinDispatchSoldier[i].dwSize = dwSizeMinDispatchSoldier[i];
			patchMinDispatchSoldier[i].pCode = codeMinDispatchSoldier[i];
		}
		//same force dispatch
		for (i = 0; i < PATCH_SAME_FORCE_DISPATCH_NUM; i++)
		{
			patchSameForceDispatch[i].dwAddr = dwAddrSameForceDispatch[i];
			patchSameForceDispatch[i].dwSize = dwSizeSameForceDispatch[i];
			patchSameForceDispatch[i].pCode = codeSameForceDispatch[i];
		}
		//disorder experience
		for (i = 0; i < PATCH_DISORDER_EXPERIENCE_NUM; i++)
		{
			patchDisorderExperience[i].dwAddr = dwAddrDisorderExperience[i];
			patchDisorderExperience[i].dwSize = dwSizeDisorderExperience[i];
			patchDisorderExperience[i].pCode = codeDisorderExperience[i];
		}
		//inspire experience
		for (i = 0; i < PATCH_INSPIRE_EXPERIENCE_NUM; i++)
		{
			patchInspireExperience[i].dwAddr = dwAddrInspireExperience[i];
			patchInspireExperience[i].dwSize = dwSizeInspireExperience[i];
			patchInspireExperience[i].pCode = codeInspireExperience[i];
		}
		//rob money
		for (i = 0; i < PATCH_ROB_MONEY_NUM; i++)
		{
			patchRobMoney[i].dwAddr = dwAddrRobMoney[i];
			patchRobMoney[i].dwSize = dwSizeRobMoney[i];
			patchRobMoney[i].pCode = codeRobMoney[i];
		}
		//move again
		for (i = 0; i < PATCH_MOVE_AGAIN_NUM; i++)
		{
			patchMoveAgain[i].dwAddr = dwAddrMoveAgain[i];
			patchMoveAgain[i].dwSize = dwSizeMoveAgain[i];
			patchMoveAgain[i].pCode = codeMoveAgain[i];
		}
		//journey expense
		for (i = 0; i < PATCH_JOURNEY_EXPENSE_NUM; i++)
		{
			patchJourneyExpense[i].dwAddr = dwAddrJourneyExpense[i];
			patchJourneyExpense[i].dwSize = dwSizeJourneyExpense[i];
			patchJourneyExpense[i].pCode = codeJourneyExpense[i];
		}
		//harbor killer
		for (i = 0; i < PATCH_HARBOR_KILLER_NUM; i++)
		{
			patchHarborKiller[i].dwAddr = dwAddrHarborKiller[i];
			patchHarborKiller[i].dwSize = dwSizeHarborKiller[i];
			patchHarborKiller[i].pCode = codeHarborKiller[i];
		}
		//person judgement
		for (i = 0; i < PATCH_PERSON_JUDGEMENT_NUM; i++)
		{
			patchPersonJudgement[i].dwAddr = dwAddrPersonJudgement[i];
			patchPersonJudgement[i].dwSize = dwSizePersonJudgement[i];
			patchPersonJudgement[i].pCode = codePersonJudgement[i];
		}
		//min building person
		for (i = 0; i < PATCH_MIN_BUILDING_PERSON_NUM; i++)
		{
			patchMinBuildingPerson[i].dwAddr = dwAddrMinBuildingPerson[i];
			patchMinBuildingPerson[i].dwSize = dwSizeMinBuildingPerson[i];
			patchMinBuildingPerson[i].pCode = codeMinBuildingPerson[i];
		}
	//multi search
		//search select
		for (i = 0; i < PATCH_SEARCH_SELECT_NUM; i++)
		{
			patchSearchSelect[i].dwAddr = dwAddrSearchSelect[i];
			patchSearchSelect[i].dwSize = dwSizeSearchSelect[i];
			patchSearchSelect[i].pCode = codeSearchSelect[i];
		}
		//search stop
		for (i = 0; i < PATCH_SEARCH_STOP_NUM; i++)
		{
			patchSearchStop[i].dwAddr = dwAddrSearchStop[i];
			patchSearchStop[i].dwSize = dwSizeSearchStop[i];
			patchSearchStop[i].pCode = codeSearchStop[i];
		}
		//search perform
		for (i = 0; i < PATCH_SEARCH_PERFORM_NUM; i++)
		{
			patchSearchPerform[i].dwAddr = dwAddrSearchPerform[PATCH_SEARCH_PERFORM_NUM-1 - i];
			patchSearchPerform[i].dwSize = dwSizeSearchPerform[PATCH_SEARCH_PERFORM_NUM-1 - i];
			patchSearchPerform[i].pCode = codeSearchPerform[PATCH_SEARCH_PERFORM_NUM-1 - i];
		}
	//hwnd and message
		//send message
		for (i = 0; i < PATCH_SEND_MESSAGE_NUM; i++)
		{
			patchSendMessage[i].dwAddr = dwAddrSendMessage[i];
			patchSendMessage[i].dwSize = dwSizeSendMessage[i];
			patchSendMessage[i].pCode = codeSendMessage[i];
		}
	//key process
		//key search
		for (i = 0; i < PATCH_KEY_SEARCH_NUM; i++)
		{
			patchKeySearch[i].dwAddr = dwAddrKeySearch[i];
			patchKeySearch[i].dwSize = dwSizeKeySearch[i];
			patchKeySearch[i].pCode = codeKeySearch[i];
		}
		//flag_counter process
		for (i = 0; i < PATCH_FLAG_COUNTER_PROCESS_NUM; i++)
		{
			patchFlagCounterProcess[i].dwAddr = dwAddrFlagCounterProcess[i];
			patchFlagCounterProcess[i].dwSize = dwSizeFlagCounterProcess[i];
			patchFlagCounterProcess[i].pCode = codeFlagCounterProcess[i];
		}
		//go nodisplay
		for (i = 0; i < PATCH_GO_NODISPLAY_NUM; i++)
		{
			patchGoNodisplay[i].dwAddr = dwAddrGoNodisplay[i];
			patchGoNodisplay[i].dwSize = dwSizeGoNodisplay[i];
			patchGoNodisplay[i].pCode = codeGoNodisplay[i];
		}
		//key big
		for (i = 0; i < PATCH_KEY_BIG_NUM; i++)
		{
			patchKeyBig[i].dwAddr = dwAddrKeyBig[i];
			patchKeyBig[i].dwSize = dwSizeKeyBig[i];
			patchKeyBig[i].pCode = codeKeyBig[i];
		}
		//key go
		for (i = 0; i < PATCH_KEY_GO_NUM; i++)
		{
			patchKeyGo[i].dwAddr = dwAddrKeyGo[i];
			patchKeyGo[i].dwSize = dwSizeKeyGo[i];
			patchKeyGo[i].pCode = codeKeyGo[i];
		}
		//message entry
		for (i = 0; i < PATCH_MESSAGE_ENTRY_NUM; i++)
		{
			patchMessageEntry[i].dwAddr = dwAddrMessageEntry[PATCH_MESSAGE_ENTRY_NUM-1 - i];
			patchMessageEntry[i].dwSize = dwSizeMessageEntry[PATCH_MESSAGE_ENTRY_NUM-1 - i];
			patchMessageEntry[i].pCode = codeMessageEntry[PATCH_MESSAGE_ENTRY_NUM-1 - i];
		}
		//key small
		for (i = 0; i < PATCH_KEY_SMALL_NUM; i++)
		{
			patchKeySmall[i].dwAddr = dwAddrKeySmall[i];
			patchKeySmall[i].dwSize = dwSizeKeySmall[i];
			patchKeySmall[i].pCode = codeKeySmall[i];
		}
		//key info
		for (i = 0; i < PATCH_KEY_INFO_NUM; i++)
		{
			patchKeyInfo[i].dwAddr = dwAddrKeyInfo[i];
			patchKeyInfo[i].dwSize = dwSizeKeyInfo[i];
			patchKeyInfo[i].pCode = codeKeyInfo[i];
		}
		//mouse click
		for (i = 0; i < PATCH_MOUSE_CLICK_NUM; i++)
		{
			patchMouseClick[i].dwAddr = dwAddrMouseClick[PATCH_MOUSE_CLICK_NUM-1 - i];
			patchMouseClick[i].dwSize = dwSizeMouseClick[PATCH_MOUSE_CLICK_NUM-1 - i];
			patchMouseClick[i].pCode = codeMouseClick[PATCH_MOUSE_CLICK_NUM-1 - i];
		}
		//timer process
		for (i = 0; i < PATCH_TIMER_PROCESS_NUM; i++)
		{
			patchTimerProcess[i].dwAddr = dwAddrTimerProcess[PATCH_TIMER_PROCESS_NUM-1 - i];
			patchTimerProcess[i].dwSize = dwSizeTimerProcess[PATCH_TIMER_PROCESS_NUM-1 - i];
			patchTimerProcess[i].pCode = codeTimerProcess[PATCH_TIMER_PROCESS_NUM-1 - i];
		}
		//go fast
		for (i = 0; i < PATCH_GO_FAST_NUM; i++)
		{
			patchGoFast[i].dwAddr = dwAddrGoFast[PATCH_GO_FAST_NUM-1 - i];
			patchGoFast[i].dwSize = dwSizeGoFast[PATCH_GO_FAST_NUM-1 - i];
			patchGoFast[i].pCode = codeGoFast[PATCH_GO_FAST_NUM-1 - i];
		}
		//key award
		for (i = 0; i < PATCH_KEY_AWARD_NUM; i++)
		{
			patchKeyAward[i].dwAddr = dwAddrKeyAward[i];
			patchKeyAward[i].dwSize = dwSizeKeyAward[i];
			patchKeyAward[i].pCode = codeKeyAward[i];
		}
	}

end:
	return rv;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSan9PKHardDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSan9PKHardDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSan9PKHardDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == m_uTimerID)
	{
		ModifySan9PK(MODIFY_ROUTINE);
	}

	CDialog::OnTimer(nIDEvent);
}

void CSan9PKHardDlg::ModifySan9PK(UINT modifyFlag)
{
	int i = 0;
	const int zero = 0, one = 1, negtive = -1;
	CString str;
	//read, write and operation
	HWND hWnd = NULL;
	BOOL bSuccess = FALSE;
	DWORD dwRdData = 0, dwWrData = 0;
	DWORD dwAddr = 0;

	//open San9PK
	hWnd = ::FindWindow("KOEI_SAN9WINDOW", NULL);
	if (hWnd == NULL)
	{
		m_hSan9PKProcess = NULL;
		m_hSan9PKWnd = NULL;
		m_iDelayCount = 0;
		m_ctrlStatus.SetWindowText("找不到游戏窗口!");
		return;
	}
	if (m_hSan9PKWnd != hWnd)
	{//start or restart game
		if (++m_iDelayCount <= 5)//延时插入：等待5秒
		{	return;	}
		m_iDelayCount = 0;
		m_iDisplayCount = 0;
		m_hSan9PKWnd = hWnd;
		GetWindowThreadProcessId(m_hSan9PKWnd, &m_dwProcessId);
		m_hSan9PKProcess = ::OpenProcess(0x38, FALSE, m_dwProcessId);//read, write and operation
		if (m_hSan9PKProcess == NULL)
		{
			m_hSan9PKWnd = NULL;
			m_ctrlStatus.SetWindowText("找不到游戏进程!");
			return;
		}
		if (CheckGameVersion() == false)
		{
			m_hSan9PKWnd = NULL;
			CloseHandle(m_hSan9PKProcess);
			m_hSan9PKProcess = NULL;
			m_ctrlStatus.SetWindowText("不支持游戏的当前版本!");
			return;
		}
	//game common data
		bSuccess = ::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwCommonDataPageAddr, m_dwPageSize,
																	PAGE_EXECUTE_READWRITE, &dwWrData);
		CHECK_ERROR(ERR_PAGE_COMMON_DATA);
	//multi-search
		//caption data
		bSuccess = ::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwCaptionPageAddr, m_dwPageSize,
																			PAGE_READWRITE, &dwWrData);
		CHECK_ERROR(ERR_PAGE_CAPTION);
		//person friendship data
		bSuccess = ::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwFriendshipPageAddr, m_dwPageSize,
																			PAGE_READWRITE, &dwWrData);
		CHECK_ERROR(ERR_PAGE_FRIENDSHIP);
	//npc search range
		bSuccess = ::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwSearchRangePageAddr, m_dwPageSize,
																	PAGE_EXECUTE_READWRITE, &dwWrData);
		CHECK_ERROR(ERR_PAGE_SEARCH_RANGE);
	//alloc page on stack bottom
		bSuccess = (NULL != ::VirtualAllocEx(m_hSan9PKProcess, (DWORD *)dwAddrStackBottom, m_dwAllocPageNum*m_dwPageSize,
																	MEM_COMMIT, PAGE_EXECUTE_READWRITE));
		CHECK_ERROR(ERR_ALLOC_STACK_BOTTOM);

		m_eState = STATE_FREE;
		goto modify_patch;
	}
	else if (modifyFlag == MODIFY_SETTING)
	{	goto modify_setting;	}
	else if (modifyFlag == MODIFY_LOAD_SCENE || modifyFlag == MODIFY_NEW_SCENE)
	{	goto modify_data;	}
	else if (modifyFlag == MODIFY_ROUTINE)
	{	goto modify_routine;	}
	return;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
modify_patch:
	//rob money
	for (i = 0; i < PATCH_ROB_MONEY_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobMoney[i].dwAddr),\
									(LPVOID)(patchRobMoney[i].pCode), patchRobMoney[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_ROB_MONEY);
	}
	//min dispatch soldier
	for (i = 0; i < PATCH_MIN_DISPATCH_SOLDIER_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDispatchSoldier[i].dwAddr),\
									(LPVOID)(patchMinDispatchSoldier[i].pCode), patchMinDispatchSoldier[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MIN_DISPATCH_SOLDIER);
	}
	//enable draft
	for (i = 0; i < PATCH_ENABLE_DRAFT_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableDraft[i].dwAddr),\
										(LPVOID)(patchEnableDraft[i].pCode), patchEnableDraft[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_ENABLE_DRAFT);
	}
	//min building person
	for (i = 0; i < PATCH_MIN_BUILDING_PERSON_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinBuildingPerson[i].dwAddr),\
										(LPVOID)(patchMinBuildingPerson[i].pCode), patchMinBuildingPerson[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MIN_BUILDING_PERSON);
	}
	//defence horse wimble
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDefenceHorseWimble),\
									(LPVOID)(codeDefenceHorseWimble), sizeof(codeDefenceHorseWimble), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_DEFENCE_HORSE_WIMBLE);
	//dispatch troop
	for (i = 0; i < PATCH_DISPATCH_TROOP_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDispatchTroop[i].dwAddr),\
										(LPVOID)(patchDispatchTroop[i].pCode), patchDispatchTroop[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_DISPATCH_TROOP);
	}
	//move again
	for (i = 0; i < PATCH_MOVE_AGAIN_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveAgain[i].dwAddr),\
									(LPVOID)(patchMoveAgain[i].pCode), patchMoveAgain[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MOVE_AGAIN);
	}
	//min durability
	for (i = 0; i < PATCH_MIN_DURABILITY_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDurability[i].dwAddr),\
									(LPVOID)(patchMinDurability[i].pCode), patchMinDurability[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MIN_DURABILITY);
	}
	//garbage person
	for (i = 0; i < PATCH_GARBAGE_PERSON_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGarbagePerson[i].dwAddr),\
									(LPVOID)(patchGarbagePerson[i].pCode), patchGarbagePerson[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_GARBAGE_PERSON);
	}
	//inspire experience
	for (i = 0; i < PATCH_INSPIRE_EXPERIENCE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireExperience[i].dwAddr),\
									(LPVOID)(patchInspireExperience[i].pCode), patchInspireExperience[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_INSPIRE_EXPERIENCE);
	}
	//full prize
	for (i = 0; i < PATCH_FULL_PRIZE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFullPrize[i].dwAddr),\
									(LPVOID)(patchFullPrize[i].pCode), patchFullPrize[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_FULL_PRIZE);
	}
	//same force dispatch
	for (i = 0; i < PATCH_SAME_FORCE_DISPATCH_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSameForceDispatch[i].dwAddr),\
									(LPVOID)(patchSameForceDispatch[i].pCode), patchSameForceDispatch[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SAME_FORCE_DISPATCH);
	}
	//harbor killer
	for (i = 0; i < PATCH_HARBOR_KILLER_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHarborKiller[i].dwAddr),\
									(LPVOID)(patchHarborKiller[i].pCode), patchHarborKiller[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_HARBOR_KILLER);
	}
	//wisdom effective flag
	for (i = 0; i < PATCH_WISDOM_EFFECTIVE_FLAG_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomEffectivFlag[i].dwAddr),\
										(LPVOID)(patchWisdomEffectivFlag[i].pCode), patchWisdomEffectivFlag[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_WISDOM_EFFECTIVE_FLAG);
	}
	//wisdom anti black art
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrWisdomAntiBlackArt),
										(LPVOID)(codeWisdomAntiBlackArt), sizeof(codeWisdomAntiBlackArt), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_WISDOM_ANTI_BLACK_ART);
	//building killer
	for (i = 0; i < PATCH_BUILDING_KILLER_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingKiller[i].dwAddr),\
									(LPVOID)(patchBuildingKiller[i].pCode), patchBuildingKiller[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_BUILDING_KILLER);
	}
	//siege experience
	for (i = 0; i < PATCH_SIEGE_EXPERIENCE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSiegeExperience[i].dwAddr),\
									(LPVOID)(patchSiegeExperience[i].pCode), patchSiegeExperience[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SIEGE_EXPERIENCE);
	}
	//lower build expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLowerBuildExpense),\
								(LPVOID)(codeLowerBuildExpense), sizeof(codeLowerBuildExpense), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_LOWER_BUILD_EXPENSE);
	//journey expense
	for (i = 0; i < PATCH_JOURNEY_EXPENSE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyExpense[i].dwAddr),\
									(LPVOID)(patchJourneyExpense[i].pCode), patchJourneyExpense[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_JOURNEY_EXPENSE);
	}
	//battle disable gossip
	for (i = 0; i < PATCH_BATTLE_DISABLE_GOSSIP_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBattleDisableGossip[i].dwAddr),\
									(LPVOID)(patchBattleDisableGossip[i].pCode), patchBattleDisableGossip[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_BATTLE_DISABLE_GOSSIP);
	}
	//alienate experience
	for (i = 0; i < PATCH_ALIENATE_EXPERIENCE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateExperience[i].dwAddr),\
									(LPVOID)(patchAlienateExperience[i].pCode), patchAlienateExperience[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_ALIENATE_EXPERIENCE);
	}
	//not alienate garbage
	for (i = 0; i < PATCH_NOT_ALIENATE_GARBAGE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotAlienateGarbage[i].dwAddr),\
										(LPVOID)(patchNotAlienateGarbage[i].pCode), patchNotAlienateGarbage[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_NOT_ALIENATE_GARBAGE);
	}
	//cheat experience
	for (i = 0; i < PATCH_CHEAT_EXPERIENCE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheatExperience[i].dwAddr),\
									(LPVOID)(patchCheatExperience[i].pCode), patchCheatExperience[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_CHEAT_EXPERIENCE);
	}
	//troop siege power
	for (i = 0; i < PATCH_TROOP_SIEGE_POWER_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopSiegePower[i].dwAddr),\
									(LPVOID)(patchTroopSiegePower[i].pCode), patchTroopSiegePower[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_TROOP_SIEGE_POWER);
	}
	//disorder experience
	for (i = 0; i < PATCH_DISORDER_EXPERIENCE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderExperience[i].dwAddr),\
									(LPVOID)(patchDisorderExperience[i].pCode), patchDisorderExperience[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_DISORDER_EXPERIENCE);
	}
	//filter ready person
	for (i = 0; i < PATCH_FILTER_READY_PERSON_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFilterReadyPerson[i].dwAddr),\
										(LPVOID)(patchFilterReadyPerson[i].pCode), patchFilterReadyPerson[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_FILTER_READY_PERSON);
	}
	//sub journey expense
	for (i = 0; i < PATCH_SUB_JOURNEY_EXPENSE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubJourneyExpense[i].dwAddr),\
									(LPVOID)(patchSubJourneyExpense[i].pCode), patchSubJourneyExpense[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SUB_JOURNEY_EXPENSE);
	}
	//person judgement
	for (i = 0; i < PATCH_PERSON_JUDGEMENT_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonJudgement[i].dwAddr),\
									(LPVOID)(patchPersonJudgement[i].pCode), patchPersonJudgement[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_PERSON_JUDGEMENT);
	}
	//intelligence killer coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrIntelligenceKillerCoef),
										(LPVOID)(codeIntelligenceKillerCoef), sizeof(codeIntelligenceKillerCoef), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_INTELLIGENCE_KILLER_COEF);
	//intelligence killer coef 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrIntelligenceKillerCoef2),
										(LPVOID)(codeIntelligenceKillerCoef2), sizeof(codeIntelligenceKillerCoef2), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_INTELLIGENCE_KILLER_COEF2);
	//treasure value
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTreasureValue),
										(LPVOID)(codeTreasureValue), sizeof(codeTreasureValue), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_TREASURE_VALUE);
	//max force food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxForceFood),
										(LPVOID)(codeMaxForceFood), sizeof(codeMaxForceFood), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_MAX_FORCE_FOOD);
	//official loyaty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrOfficialLoyaty),
										(LPVOID)(codeOfficialLoyaty), sizeof(codeOfficialLoyaty), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_OFFICIAL_LOYATY);
	//not approach near troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotApproachNearTroop),
										(LPVOID)(codeNotApproachNearTroop), sizeof(codeNotApproachNearTroop), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_NOT_APPROACH_NEAR_TROOP);
	//build real goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildRealGoal),
										(LPVOID)(codeBuildRealGoal), sizeof(codeBuildRealGoal), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_BUILD_REAL_GOAL);
	//save attack source building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveAttackSourceBuilding),
										(LPVOID)(codeSaveAttackSourceBuilding), sizeof(codeSaveAttackSourceBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_SAVE_ATTACK_SOURCE_BUILDING);
	//set force goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSetForceGoal),\
									(LPVOID)(codeSetForceGoal), sizeof(codeSetForceGoal), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_SET_FORCE_GOAL);
	//get city max people heart
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetCityMaxPeopleHeart),\
									(LPVOID)(codeGetCityMaxPeopleHeart), sizeof(codeGetCityMaxPeopleHeart), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_GET_CITY_MAX_PEOPLE_HEART);
	//learn to phase
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLearnToPhase),\
									(LPVOID)(codeLearnToPhase), sizeof(codeLearnToPhase), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_LEARN_TO_PHASE);
	//read scene index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrReadSceneIndex),\
									(LPVOID)(codeReadSceneIndex), sizeof(codeReadSceneIndex), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_READ_SCENE_INDEX);
	//test dark flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestDarkFlag),\
									(LPVOID)(codeTestDarkFlag), sizeof(codeTestDarkFlag), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_TEST_DARK_FLAG);

//data(on stack/in code)
	//multi search person list
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchPersonList),
										(LPVOID)(dwDataSearchPersonList), sizeof(dwDataSearchPersonList), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_PERSON_LIST);
	//attack troop list
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackTroopList),
										(LPVOID)(dwDataAttackTroopList), sizeof(dwDataAttackTroopList), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_TROOP_LIST);
	//killer transfer table
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerTransferTable),
										(LPVOID)(dwDataKillerTransferTable), sizeof(dwDataKillerTransferTable), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_TRANSFER_TABLE);
	//official loyalty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwOfficialLoyaltyAddr),\
									(LPVOID)(m_dwOfficialLoyalty), sizeof(m_dwOfficialLoyalty), NULL);
	CHECK_ERROR(ERR_WRITE_OFFICIAL_LOYALTY);
	//array center image
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwArrayCenterImageAddr),\
									(LPVOID)(m_btArrayCenterImage), sizeof(m_btArrayCenterImage), NULL);
	CHECK_ERROR(ERR_WRITE_ARRAY_CENTER_IMAGE);
	//map killer power
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwMapKillerPowerAddr),\
									(LPVOID)(btMapKillerPower), sizeof(btMapKillerPower), NULL);
	CHECK_ERROR(ERR_WRITE_MAP_KILLER_POWER);
	////////////////////////////////////
	//chase flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrChaseFlag), (LPVOID)(codeChaseFlag),
																					sizeof(codeChaseFlag), NULL);
	CHECK_ERROR(ERR_WRITE_CHASE_FLAG);
	//dispatch person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDispatchPerson),
										(LPVOID)(codeDispatchPerson), sizeof(codeDispatchPerson), NULL);
	CHECK_ERROR(ERR_WRITE_DISPATCH_PERSON);
	//check menace troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckMenaceTroop),
										(LPVOID)(codeCheckMenaceTroop), sizeof(codeCheckMenaceTroop), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_MENACE_TROOP);
	//building total soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingTotalSoldier),
										(LPVOID)(codeBuildingTotalSoldier), sizeof(codeBuildingTotalSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_TOTAL_SOLDIER);
	//before go
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBeforeGo),
										(LPVOID)(codeBeforeGo), sizeof(codeBeforeGo), NULL);
	CHECK_ERROR(ERR_WRITE_BEFORE_GO);
	//enable commerce
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrEnableCommerce),
										(LPVOID)(codeEnableCommerce), sizeof(codeEnableCommerce), NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_COMMERCE);
	//check abuse
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckAbuse),
										(LPVOID)(codeCheckAbuse), sizeof(codeCheckAbuse), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_ABUSE);
	//save troop expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveTroopExpense),
										(LPVOID)(codeSaveTroopExpense), sizeof(codeSaveTroopExpense), NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_TROOP_EXPENSE);
	//enable cultivate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrEnableCultivate),
										(LPVOID)(codeEnableCultivate), sizeof(codeEnableCultivate), NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_CULTIVATE);
	//command ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCommandAbility),
										(LPVOID)(codeCommandAbility), sizeof(codeCommandAbility), NULL);
	CHECK_ERROR(ERR_WRITE_COMMAND_ABILITY);
	//jia xu back
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJiaXuBack),
										(LPVOID)(codeJiaXuBack), sizeof(codeJiaXuBack), NULL);
	CHECK_ERROR(ERR_WRITE_JIA_XU_BACK);
	//move idle person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMoveIdlePerson),
										(LPVOID)(codeMoveIdlePerson), sizeof(codeMoveIdlePerson), NULL);
	CHECK_ERROR(ERR_WRITE_MOVE_IDLE_PERSON);
	//command intelligence ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCommandIntAbility),
										(LPVOID)(codeCommandIntAbility), sizeof(codeCommandIntAbility), NULL);
	CHECK_ERROR(ERR_WRITE_COMMAND_INT_ABILITY);
	//captive money2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCaptiveMoney2),
										(LPVOID)(codeCaptiveMoney2), sizeof(codeCaptiveMoney2), NULL);
	CHECK_ERROR(ERR_WRITE_CAPTIVE_MONEY_2);		
	//captive money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCaptiveMoney),
										(LPVOID)(codeCaptiveMoney), sizeof(codeCaptiveMoney), NULL);
	CHECK_ERROR(ERR_WRITE_CAPTIVE_MONEY);
	//invite new person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInviteNewPerson),
										(LPVOID)(codeInviteNewPerson), sizeof(codeInviteNewPerson), NULL);
	CHECK_ERROR(ERR_WRITE_INVITE_NEW_PERSON);
	//soldier command killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUpdateKillerDamage),
										(LPVOID)(codeUpdateKillerDamage), sizeof(codeUpdateKillerDamage), NULL);
	CHECK_ERROR(ERR_WRITE_UPDATE_KILLER_DAMAGE);
	//save harbor
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveHarbor),
										(LPVOID)(codeSaveHarbor), sizeof(codeSaveHarbor), NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_HARBOR);
	//goto npc city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGotoNpcCity),
										(LPVOID)(codeGotoNpcCity), sizeof(codeGotoNpcCity), NULL);
	CHECK_ERROR(ERR_WRITE_GOTO_NPC_CITY);
	//fight to killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFightToKiller),
										(LPVOID)(codeFightToKiller), sizeof(codeFightToKiller), NULL);
	CHECK_ERROR(ERR_WRITE_FIGHT_TO_KILLER);
	//pre building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPreBuildingSoldier),\
								(LPVOID)(codePreBuildingSoldier), sizeof(codePreBuildingSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_PRE_BUILDING_SOLDIER);
	//near null city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNearNullCity),
										(LPVOID)(codeNearNullCity), sizeof(codeNearNullCity), NULL);
	CHECK_ERROR(ERR_WRITE_NEAR_NULL_CITY);
	//allie attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAllieAttack),\
								(LPVOID)(codeAllieAttack), sizeof(codeAllieAttack), NULL);
	CHECK_ERROR(ERR_WRITE_ALLIE_ATTACK);
	//attack min person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackMinPerson),
										(LPVOID)(codeAttackMinPerson), sizeof(codeAttackMinPerson), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_MIN_PERSON);
	//decide attack ok
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDecideAttackOk),\
								(LPVOID)(codeDecideAttackOk), sizeof(codeDecideAttackOk), NULL);
	CHECK_ERROR(ERR_WRITE_DECIDE_ATTACK_OK);
	//building on the way
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingOnTheWay),\
								(LPVOID)(codeBuildingOnTheWay), sizeof(codeBuildingOnTheWay), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_ON_THE_WAY);
	//operation per day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrOperationPerDay),\
								(LPVOID)(codeOperationPerDay), sizeof(codeOperationPerDay), NULL);
	CHECK_ERROR(ERR_WRITE_OPERATION_PER_DAY);
	//league succeed
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLeagueSucceed),
										(LPVOID)(codeLeagueSucceed), sizeof(codeLeagueSucceed), NULL);
	CHECK_ERROR(ERR_WRITE_LEAGUE_SUCCEED);
	//select build area
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectBuildArea),
										(LPVOID)(codeSelectBuildArea), sizeof(codeSelectBuildArea), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_BUILD_AREA);
	//go through near building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGoThroughNearBuilding),
										(LPVOID)(codeGoThroughNearBuilding), sizeof(codeGoThroughNearBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_GO_THROUGH_NEAR_BUILDING);
	//select water wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectWaterWisdom),
										(LPVOID)(codeSelectWaterWisdom), sizeof(codeSelectWaterWisdom), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_WATER_WISDOM);
	//degrade snake troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDegradeSnakeTroop),
										(LPVOID)(codeDegradeSnakeTroop), sizeof(codeDegradeSnakeTroop), NULL);
	CHECK_ERROR(ERR_WRITE_DEGRADE_SNAKE_TROOP);
	//correct building attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCorrectBuildingAttackSoldier),
										(LPVOID)(codeCorrectBuildingAttackSoldier), sizeof(codeCorrectBuildingAttackSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_CORRECT_BUILDING_ATTACK_SOLDIER);
	//load near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLoadNearMaxSoldier),
										(LPVOID)(codeLoadNearMaxSoldier), sizeof(codeLoadNearMaxSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_LOAD_NEAR_MAX_SOLDIER);
	//load near max soldier 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLoadNearMaxSoldier2),
										(LPVOID)(codeLoadNearMaxSoldier2), sizeof(codeLoadNearMaxSoldier2), NULL);
	CHECK_ERROR(ERR_WRITE_LOAD_NEAR_MAX_SOLDIER);
	//test regarded building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestRegardedBuilding),
										(LPVOID)(codeTestRegardedBuilding), sizeof(codeTestRegardedBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_TEST_REGARDED_BUILDING);
	//killer power to damage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerPowerToDamage),
										(LPVOID)(codeKillerPowerToDamage), sizeof(codeKillerPowerToDamage), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_POWER_TO_DAMAGE);
	//get building prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetBuildingProp),
										(LPVOID)(codeGetBuildingProp), sizeof(codeGetBuildingProp), NULL);
	CHECK_ERROR(ERR_WRITE_GET_BUILDING_PROP);
	//sort transport source
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSortTransportSource),
										(LPVOID)(codeSortTransportSource), sizeof(codeSortTransportSource), NULL);
	CHECK_ERROR(ERR_WRITE_SORT_TRANSPORT_SOURCE);
	//get tranasport soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetTransportSoldier),\
									(LPVOID)(codeGetTransportSoldier), sizeof(codeGetTransportSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_GET_TRANSPORT_SOLDIER);
	//phase error alienate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPhaseErrorAlienate),\
									(LPVOID)(codePhaseErrorAlienate), sizeof(codePhaseErrorAlienate), NULL);
	CHECK_ERROR(ERR_WRITE_PHASE_ERROR_ALIENATE);
	//max people heart push
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxPeopleHeartPush),\
								(LPVOID)(codeMaxPeopleHeartPush), sizeof(codeMaxPeopleHeartPush), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_PEOPLE_HEART_PUSH);
	//max people heart mov
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxPeopleHeartMov),\
								(LPVOID)(codeMaxPeopleHeartMov), sizeof(codeMaxPeopleHeartMov), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_PEOPLE_HEART_MOV);
	//player subforce control
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPlayerSubforceControl),\
								(LPVOID)(codePlayerSubforceControl), sizeof(codePlayerSubforceControl), NULL);
	CHECK_ERROR(ERR_WRITE_PLAYER_SUBFORCE_CONTROL);
	//attack troop soldier 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackTroopSoldier2),\
									(LPVOID)(codeAttackTroopSoldier2), sizeof(codeAttackTroopSoldier2), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_TROOP_SOLDIER2);
	//pre building soldier 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPreBuildingSoldier2),\
									(LPVOID)(codePreBuildingSoldier2), sizeof(codePreBuildingSoldier2), NULL);
	CHECK_ERROR(ERR_WRITE_PRE_BUILDING_SOLDIER2);
	//second killer interval
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSecondKillerInterval),\
									(LPVOID)(codeSecondKillerInterval), sizeof(codeSecondKillerInterval), NULL);
	CHECK_ERROR(ERR_WRITE_SECOND_KILLER_INTERVAL);
	//killer array coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerArrayCoef),\
									(LPVOID)(codeKillerArrayCoef), sizeof(codeKillerArrayCoef), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_ARRAY_COEF);
	//display troop condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisplayTroopCondition),\
									(LPVOID)(codeDisplayTroopCondition), sizeof(codeDisplayTroopCondition), NULL);
	CHECK_ERROR(ERR_WRITE_DISPLAY_TROOP_CONDITION);
	//troop at small map
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopAtSmallMap),\
									(LPVOID)(codeTroopAtSmallMap), sizeof(codeTroopAtSmallMap), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_AT_SMALL_MAP);
	//adjust troop go date
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAdjustTroopGoDate),\
									(LPVOID)(codeAdjustTroopGoDate), sizeof(codeAdjustTroopGoDate), NULL);
	CHECK_ERROR(ERR_WRITE_ADJUST_TROOP_GO_DATE);
	//all strong force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAllStrongForce),\
									(LPVOID)(codeAllStrongForce), sizeof(codeAllStrongForce), NULL);
	CHECK_ERROR(ERR_WRITE_ALL_STRONG_FORCE);
	//killer drive prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerDriveProp),\
									(LPVOID)(codeKillerDriveProp), sizeof(codeKillerDriveProp), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_DIRVE_PROP);
	//direct big animation
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDirectBigAnimation),\
									(LPVOID)(codeDirectBigAnimation), sizeof(codeDirectBigAnimation), NULL);
	CHECK_ERROR(ERR_WRITE_DIRECT_BIG_ANIMATION);
	//update captive prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUpdateCaptiveProp),\
									(LPVOID)(codeUpdateCaptiveProp), sizeof(codeUpdateCaptiveProp), NULL);
	CHECK_ERROR(ERR_WRITE_UPDATE_CAPTIVE_PROP);
	//rob food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRobFood),\
									(LPVOID)(codeRobFood), sizeof(codeRobFood), NULL);
	CHECK_ERROR(ERR_WRITE_ROB_FOOD);
	//get troop view state
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetTroopViewState),\
									(LPVOID)(codeGetTroopViewState), sizeof(codeGetTroopViewState), NULL);
	CHECK_ERROR(ERR_WRITE_GET_TROOP_VIEW_STATE);
	//hide duty person num
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideDutyPersonNum),\
									(LPVOID)(codeHideDutyPersonNum), sizeof(codeHideDutyPersonNum), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_DUTY_PERSON_NUM);
	//hide city morale
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideCityMorale),\
									(LPVOID)(codeHideCityMorale), sizeof(codeHideCityMorale), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_CITY_MORALE);
	//counselor report prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCounselorReportProp),\
									(LPVOID)(codeCounselorReportProp), sizeof(codeCounselorReportProp), NULL);
	CHECK_ERROR(ERR_WRITE_COUNSELOR_REPORT_PROP);
	//build arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildArriveDay),\
									(LPVOID)(codeBuildArriveDay), sizeof(codeBuildArriveDay), NULL);
	CHECK_ERROR(ERR_WRITE_BUILD_ARRIVE_DAY);
	//retreat_soldier_troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRetreatSoldierTroop),\
									(LPVOID)(codeRetreatSoldierTroop), sizeof(codeRetreatSoldierTroop), NULL);
	CHECK_ERROR(ERR_WRITE_RETREAT_SOLDIER_TROOP);
	//harvest
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHarvest),\
								(LPVOID)(codeHarvest), sizeof(codeHarvest), NULL);
	CHECK_ERROR(ERR_WRITE_HARVEST);
	//goal force para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGoalForcePara),\
								(LPVOID)(codeGoalForcePara), sizeof(codeGoalForcePara), NULL);
	CHECK_ERROR(ERR_WRITE_GOAL_FORCE_PARA);
	//auto process task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAutoProcessTask),\
								(LPVOID)(codeAutoProcessTask), sizeof(codeAutoProcessTask), NULL);
	CHECK_ERROR(ERR_WRITE_AUTO_PROCESS_TASK);
	//kill sub prestige
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillSubPrestige),\
								(LPVOID)(codeKillSubPrestige), sizeof(codeKillSubPrestige), NULL);
	CHECK_ERROR(ERR_WRITE_KILL_SUB_PRESTIGE);
	//ability killer prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAbilityKillerProp),\
								(LPVOID)(codeAbilityKillerProp), sizeof(codeAbilityKillerProp), NULL);
	CHECK_ERROR(ERR_WRITE_ABILITY_KILLER_PROP);
	//add water killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAddWaterKiller),\
								(LPVOID)(codeAddWaterKiller), sizeof(codeAddWaterKiller), NULL);
	CHECK_ERROR(ERR_WRITE_ADD_WATER_KILLER);	
	//enable water killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrEnableWaterKiller),\
								(LPVOID)(codeEnableWaterKiller), sizeof(codeEnableWaterKiller), NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_WATER_KILLER);	
	//auto adjust killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAutoAdjustKiller),\
								(LPVOID)(codeAutoAdjustKiller), sizeof(codeAutoAdjustKiller), NULL);
	CHECK_ERROR(ERR_WRITE_AUTO_ADJUST_KILLER);		
	//investment
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInvestment),\
								(LPVOID)(codeInvestment), sizeof(codeInvestment), NULL);
	CHECK_ERROR(ERR_WRITE_INVESTMENT);
	//heart attack damage 1
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHeartAttackDamage1),\
								(LPVOID)(codeHeartAttackDamage1), sizeof(codeHeartAttackDamage1), NULL);
	CHECK_ERROR(ERR_WRITE_HEART_ATTACK_DAMAGE_1);	
	//heart attack damage 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHeartAttackDamage2),\
								(LPVOID)(codeHeartAttackDamage2), sizeof(codeHeartAttackDamage2), NULL);
	CHECK_ERROR(ERR_WRITE_HEART_ATTACK_DAMAGE_2);	
	//damage record
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDamageRecord),\
								(LPVOID)(codeDamageRecord), sizeof(codeDamageRecord), NULL);
	CHECK_ERROR(ERR_WRITE_DAMAGE_RECORD);
	//set troop index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSetTroopIndex),
										(LPVOID)(codeSetTroopIndex), sizeof(codeSetTroopIndex), NULL);
	CHECK_ERROR(ERR_WRITE_SET_TROOP_INDEX);
	//troop index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopIndex),
										(LPVOID)(codeTroopIndex), sizeof(codeTroopIndex), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_INDEX);	
	//troop advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopAdvise),
										(LPVOID)(codeTroopAdvise), sizeof(codeTroopAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_ADVISE);
	//get troop index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetTroopIndex),
										(LPVOID)(codeGetTroopIndex), sizeof(codeGetTroopIndex), NULL);
	CHECK_ERROR(ERR_WRITE_GET_TROOP_INDEX);		
//multi search
	//clear perform person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPerformPersonAddr),\
										(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERFORM_PERSON);
	//search stop
	for (i = 0; i < PATCH_SEARCH_STOP_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchStop[i].dwAddr),\
									(LPVOID)(patchSearchStop[i].pCode), patchSearchStop[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SEARCH_STOP);
	}
	//search perform
	for (i = 0; i < PATCH_SEARCH_PERFORM_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchPerform[i].dwAddr),\
									(LPVOID)(patchSearchPerform[i].pCode), patchSearchPerform[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SEARCH_PERFORM);
	}
	//search select
	for (i = 0; i < PATCH_SEARCH_SELECT_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchSelect[i].dwAddr),\
									(LPVOID)(patchSearchSelect[i].pCode), patchSearchSelect[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SEARCH_SELECT);
	}
	//multi select window
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMultiSelectWindow),
										(LPVOID)(codeMultiSelectWindow), sizeof(codeMultiSelectWindow), NULL);
	CHECK_ERROR(ERR_WRITE_MULTI_SELECT_WINDOW);
	//invite multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInviteMultiSelect),
										(LPVOID)(codeInviteMultiSelect), sizeof(codeInviteMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_INVITE_MULTI_SELECT);
	//save multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveMultiSelect),
										(LPVOID)(codeSaveMultiSelect), sizeof(codeSaveMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_MULTI_SELECT);
	//rob multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRobMultiSelect),
										(LPVOID)(codeRobMultiSelect), sizeof(codeRobMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_ROB_MULTI_SELECT);
	//burn multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBurnMultiSelect),
										(LPVOID)(codeBurnMultiSelect), sizeof(codeBurnMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_BURN_MULTI_SELECT);
	//alienate multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAlienateMultiSelect),
										(LPVOID)(codeAlienateMultiSelect), sizeof(codeAlienateMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_ALIENATE_MULTI_SELECT);
	//false multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFalseMultiSelect),
										(LPVOID)(codeFalseMultiSelect), sizeof(codeFalseMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_FALSE_MULTI_SELECT);
	//disorder multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisorderMultiSelect),
										(LPVOID)(codeDisorderMultiSelect), sizeof(codeDisorderMultiSelect), NULL);
	CHECK_ERROR(ERR_WRITE_DISORDER_MULTI_SELECT);
	/////////////////counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCounselorAdvise),
										(LPVOID)(codeCounselorAdvise), sizeof(codeCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_COUNSELOR_ADVISE);
	//search counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchCounselorAdvise),
										(LPVOID)(codeSearchCounselorAdvise), sizeof(codeSearchCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_COUNSELOR_ADVISE);
	//invite counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInviteCounselorAdvise),
										(LPVOID)(codeInviteCounselorAdvise), sizeof(codeInviteCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_INVITE_COUNSELOR_ADVISE);
	//false counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFalseCounselorAdvise),
										(LPVOID)(codeFalseCounselorAdvise), sizeof(codeFalseCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_FALSE_COUNSELOR_ADVISE);
	//disorder counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisorderCounselorAdvise),
										(LPVOID)(codeDisorderCounselorAdvise), sizeof(codeDisorderCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_DISORDER_COUNSELOR_ADVISE);
	//save counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveCounselorAdvise),
										(LPVOID)(codeSaveCounselorAdvise), sizeof(codeSaveCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_COUNSELOR_ADVISE);
	//inspire counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInspireCounselorAdvise),
										(LPVOID)(codeInspireCounselorAdvise), sizeof(codeInspireCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_INSPIRE_COUNSELOR_ADVISE);
	//rob counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRobCounselorAdvise),
										(LPVOID)(codeRobCounselorAdvise), sizeof(codeRobCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_ROB_COUNSELOR_ADVISE);
	//burn counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBurnCounselorAdvise),
										(LPVOID)(codeBurnCounselorAdvise), sizeof(codeBurnCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_BURN_COUNSELOR_ADVISE);
	//alienate counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAlienateCounselorAdvise),
										(LPVOID)(codeAlienateCounselorAdvise), sizeof(codeAlienateCounselorAdvise), NULL);
	CHECK_ERROR(ERR_WRITE_ALIENATE_COUNSELOR_ADVISE);
	///////////////////////////////////
	//wisdom person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrWisdomPerson),
										(LPVOID)(codeWisdomPerson), sizeof(codeWisdomPerson), NULL);
	CHECK_ERROR(ERR_WRITE_WISDOM_PERSON);
	//alienate min day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAlienateMinDay),
										(LPVOID)(codeAlienateMinDay), sizeof(codeAlienateMinDay), NULL);
	CHECK_ERROR(ERR_WRITE_ALIENATE_MIN_DAY);
	//force troop list
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrForceTroopList),
										(LPVOID)(codeForceTroopList), sizeof(codeForceTroopList), NULL);
	CHECK_ERROR(ERR_WRITE_FORCE_TROOP_LIST);
	//relay dispatch success
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRelayDispatchOk),
										(LPVOID)(codeRelayDispatchOk), sizeof(codeRelayDispatchOk), NULL);
	CHECK_ERROR(ERR_WRITE_RELAY_DISPATCH_OK);
	//battle disable task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBattleDisableTask),
										(LPVOID)(codeBattleDisableTask), sizeof(codeBattleDisableTask), NULL);
	CHECK_ERROR(ERR_WRITE_BATTLE_DISABLE_TASK);
	//simple award
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSimpleAward),
										(LPVOID)(codeSimpleAward), sizeof(codeSimpleAward), NULL);
	CHECK_ERROR(ERR_WRITE_SIMPLE_AWARD);
	//building backup
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingBackup),
										(LPVOID)(codeBuildingBackup), sizeof(codeBuildingBackup), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_BACKUP);
	//min danger dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMinDangerDispatch),
										(LPVOID)(codeMinDangerDispatch), sizeof(codeMinDangerDispatch), NULL);
	CHECK_ERROR(ERR_WRITE_MIN_DANGER_DISPATCH);
	//check officer money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckOfficerMoney),
										(LPVOID)(codeCheckOfficerMoney), sizeof(codeCheckOfficerMoney), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_OFFICER_MONEY);
	//degrade person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDegradePerson),
										(LPVOID)(codeDegradePerson), sizeof(codeDegradePerson), NULL);
	CHECK_ERROR(ERR_WRITE_DEGRADE_PERSON);
	//search range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchRange),
										(LPVOID)(codeSearchRange), sizeof(codeSearchRange), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_RANGE);
	//building killer person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingKillerPerson),
										(LPVOID)(codeBuildingKillerPerson), sizeof(codeBuildingKillerPerson), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_KILLER_PERSON);
	//draft min money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDraftMinMoney),
										(LPVOID)(codeDraftMinMoney), sizeof(codeDraftMinMoney), NULL);
	CHECK_ERROR(ERR_WRITE_DRAFT_MIN_MONEY);
	//go on attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGoOnAttack),\
								(LPVOID)(codeGoOnAttack), sizeof(codeGoOnAttack), NULL);
	CHECK_ERROR(ERR_WRITE_GO_ON_ATTACK);
	//get player city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPlayerCity),\
								(LPVOID)(codeGetPlayerCity), sizeof(codeGetPlayerCity), NULL);
	CHECK_ERROR(ERR_WRITE_GET_PLAYER_CITY);
	//attack source city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackSourceCity),\
								(LPVOID)(codeAttackSourceCity), sizeof(codeAttackSourceCity), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_SOURCE_CITY);
	//add city relation
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAddCityRelation),\
								(LPVOID)(codeAddCityRelation), sizeof(codeAddCityRelation), NULL);
	CHECK_ERROR(ERR_WRITE_ADD_CITY_RELATION);
	//retry attacked building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRetryAttackedBuilding),\
								(LPVOID)(codeRetryAttackedBuilding), sizeof(codeRetryAttackedBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_RETRY_ATTACKED_BUILDING);
	//left clever killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLeftCleverKiller),\
								(LPVOID)(codeLeftCleverKiller), sizeof(codeLeftCleverKiller), NULL);
	CHECK_ERROR(ERR_WRITE_LEFT_CLEVER_KILLER);
	//select attack array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectAttackArray),\
								(LPVOID)(codeSelectAttackArray), sizeof(codeSelectAttackArray), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_ATTACK_ARRAY);
	//set near attack flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSetNearAttackFlag),\
								(LPVOID)(codeSetNearAttackFlag), sizeof(codeSetNearAttackFlag), NULL);
	CHECK_ERROR(ERR_WRITE_SET_NEAR_ATTACK_FLAG);
	//decide build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDecideBuild),\
								(LPVOID)(codeDecideBuild), sizeof(codeDecideBuild), NULL);
	CHECK_ERROR(ERR_WRITE_DECIDE_BUILD);
	//adjust attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAdjustAttackSoldier),\
								(LPVOID)(codeAdjustAttackSoldier), sizeof(codeAdjustAttackSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_ADJUST_ATTACK_SOLDIER);
	//anti attack antitrap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAntiAttackAntitrap),\
								(LPVOID)(codeAntiAttackAntitrap), sizeof(codeAntiAttackAntitrap), NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_ANTITRAP);
	//select train person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectTrainPerson),\
								(LPVOID)(codeSelectTrainPerson), sizeof(codeSelectTrainPerson), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_TRAIN_PERSON);
	//refuse change
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRefuseChange),\
								(LPVOID)(codeRefuseChange), sizeof(codeRefuseChange), NULL);
	CHECK_ERROR(ERR_WRITE_REFUSE_CHANGE);
	//correct goal building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCorrectGoalBuildingSoldier),\
								(LPVOID)(codeCorrectGoalBuildingSoldier), sizeof(codeCorrectGoalBuildingSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_CORRECT_GOAL_BUILDING_SOLDIER);
	//test attack goal force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestAttackGoalForce),\
								(LPVOID)(codeTestAttackGoalForce), sizeof(codeTestAttackGoalForce), NULL);
	CHECK_ERROR(ERR_WRITE_TEST_ATTACK_GOAL_FORCE);
	//regarded building on attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRegardedBuildingOnAttack),\
								(LPVOID)(codeRegardedBuildingOnAttack), sizeof(codeRegardedBuildingOnAttack), NULL);
	CHECK_ERROR(ERR_WRITE_REGARDED_BUILDING_ON_ATTACK);
	//linkage killer to record
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLinkageKillerToRecord),\
								(LPVOID)(codeLinkageKillerToRecord), sizeof(codeLinkageKillerToRecord), NULL);
	CHECK_ERROR(ERR_WRITE_LINKAGE_KILLER_TO_RECORD);
	//update seige power
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUpdateSeigePower),\
								(LPVOID)(codeUpdateSeigePower), sizeof(codeUpdateSeigePower), NULL);
	CHECK_ERROR(ERR_WRITE_UPDATE_SEIGE_POWER);
	//force fight troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrForceFightTroop),
										(LPVOID)(codeForceFightTroop), sizeof(codeForceFightTroop), NULL);
	CHECK_ERROR(ERR_WRITE_FORCE_FIGHT_TROOP);
	//get force danger coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetForceDangerCoef),
										(LPVOID)(codeGetForceDangerCoef), sizeof(codeGetForceDangerCoef), NULL);
	CHECK_ERROR(ERR_WRITE_GET_FORCE_DANGER_COEF);
	//stop task bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrStopTaskBug),
										(LPVOID)(codeStopTaskBug), sizeof(codeStopTaskBug), NULL);
	CHECK_ERROR(ERR_WRITE_STOP_TASK_BUG);
	//auto save docname
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAutoSaveDocname),
										(LPVOID)(codeAutoSaveDocname), sizeof(codeAutoSaveDocname), NULL);
	CHECK_ERROR(ERR_WRITE_AUTO_SAVE_DOCNAME);
	//person experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPersonExperience),
										(LPVOID)(codePersonExperience), sizeof(codePersonExperience), NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_EXPERIENCE);
	//intelligence officer para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrIntelligenceOfficerPara),
										(LPVOID)(codeIntelligenceOfficerPara), sizeof(codeIntelligenceOfficerPara), NULL);
	CHECK_ERROR(ERR_WRITE_INTELLIGENCE_OFFICER_PARA);
	//max people heart basic
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxPeopleHeartBasic),
										(LPVOID)(codeMaxPeopleHeartBasic), sizeof(codeMaxPeopleHeartBasic), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_PEOPLE_HEART_BASIC);
	//dynamic add proficiency
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDynamicAddProficiency),
										(LPVOID)(codeDynamicAddProficiency), sizeof(codeDynamicAddProficiency), NULL);
	CHECK_ERROR(ERR_WRITE_DYNAMIC_ADD_PROFICIENCY);
	//person char num
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPersonCharNum),
										(LPVOID)(codePersonCharNum), sizeof(codePersonCharNum), NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_CHAR_NUM);
	//attack troop retreat
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackTroopRetreat),
										(LPVOID)(codeAttackTroopRetreat), sizeof(codeAttackTroopRetreat), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_TROOP_RETREAT);
	//get person quota
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPersonQuota),
										(LPVOID)(codeGetPersonQuota), sizeof(codeGetPersonQuota), NULL);
	CHECK_ERROR(ERR_WRITE_GET_PERSON_QUOTA);
	//delete big person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDeleteBigPerson),
										(LPVOID)(codeDeleteBigPerson), sizeof(codeDeleteBigPerson), NULL);
	CHECK_ERROR(ERR_WRITE_DELETE_BIG_PERSON);
	//compare person name
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrComparePersonName),
										(LPVOID)(codeComparePersonName), sizeof(codeComparePersonName), NULL);
	CHECK_ERROR(ERR_WRITE_COMPARE_PERSON_NAME);
	//block prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBlcokProp),
										(LPVOID)(codeBlcokProp), sizeof(codeBlcokProp), NULL);
	CHECK_ERROR(ERR_WRITE_BLOCK_PROP);
	//multi select person state
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMultiSelectPersonState),
										(LPVOID)(codeMultiSelectPersonState), sizeof(codeMultiSelectPersonState), NULL);
	CHECK_ERROR(ERR_WRITE_MULTI_SELECT_PERSON_STATE);
	//clear troop cur goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrClearTroopCurGoal),
										(LPVOID)(codeClearTroopCurGoal), sizeof(codeClearTroopCurGoal), NULL);
	CHECK_ERROR(ERR_WRITE_CLEAR_TROOP_CUR_GOAL);
	//strength killer big animaiton
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrStrengthKillerBigAnimaiton),
										(LPVOID)(codeStrengthKillerBigAnimaiton), sizeof(codeStrengthKillerBigAnimaiton), NULL);
	CHECK_ERROR(ERR_WRITE_STRENGTH_KILLER_BIG_ANIMATION);
	//control march troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrControlMarchTroop),
										(LPVOID)(codeControlMarchTroop), sizeof(codeControlMarchTroop), NULL);
	CHECK_ERROR(ERR_WRITE_CONTROL_MARCH_TROOP);
	//killer to building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerToBuilding),
										(LPVOID)(codeKillerToBuilding), sizeof(codeKillerToBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_TO_BUILDING);
	//journey goal troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJourneyGoalTroop),
										(LPVOID)(codeJourneyGoalTroop), sizeof(codeJourneyGoalTroop), NULL);
	CHECK_ERROR(ERR_WRITE_JOURNEY_GOAL_TROOP);
	//hide info menu
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideInfoMenu),
										(LPVOID)(codeHideInfoMenu), sizeof(codeHideInfoMenu), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_INFO_MENU);
	//hide down stone
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideDownStone),
										(LPVOID)(codeHideDownStone), sizeof(codeHideDownStone), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_DOWN_STONE);
	//hide city income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideCityIncome),
										(LPVOID)(codeHideCityIncome), sizeof(codeHideCityIncome), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_CITY_INCOME);
	//killer check bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrKillerCheckBug),
										(LPVOID)(codeKillerCheckBug), sizeof(codeKillerCheckBug), NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_CHECK_BUG);
	//chaos power coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrChaosPowerCoef),
										(LPVOID)(codeChaosPowerCoef), sizeof(codeChaosPowerCoef), NULL);
	CHECK_ERROR(ERR_WRITE_CHAOS_POWER_COEF);
	//attack build date
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackBuildDate),
										(LPVOID)(codeAttackBuildDate), sizeof(codeAttackBuildDate), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_BUILD_DATE);
	//attack_player_build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackPlayerBuild),
										(LPVOID)(codeAttackPlayerBuild), sizeof(codeAttackPlayerBuild), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_PLAYER_BUILD);
	//city population coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCityPopulationCoef),
										(LPVOID)(codeCityPopulationCoef), sizeof(codeCityPopulationCoef), NULL);
	CHECK_ERROR(ERR_WRITE_CITY_POPULATION_COEF);
	//show city draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrShowCityDraft),
										(LPVOID)(codeShowCityDraft), sizeof(codeShowCityDraft), NULL);
	CHECK_ERROR(ERR_WRITE_SHOW_CITY_DRAFT);
	//add city draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAddCityDraft),
										(LPVOID)(codeAddCityDraft), sizeof(codeAddCityDraft), NULL);
	CHECK_ERROR(ERR_WRITE_ADD_CITY_DRAFT);
	//get league goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetLeagueGoal),
										(LPVOID)(codeGetLeagueGoal), sizeof(codeGetLeagueGoal), NULL);
	CHECK_ERROR(ERR_WRITE_GET_LEAGUE_GOAL);
	//train basic ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTrainBasicAbility),
										(LPVOID)(codeTrainBasicAbility), sizeof(codeTrainBasicAbility), NULL);
	CHECK_ERROR(ERR_WRITE_TRAIN_BASIC_ABILITY);
	//set max captive
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSetMaxCaptive),
										(LPVOID)(codeSetMaxCaptive), sizeof(codeSetMaxCaptive), NULL);
	CHECK_ERROR(ERR_WRITE_SET_MAX_CAPTIVE);

//message
	if (m_sWndMsg.uMsg == 0)
	{
		m_sWndMsg.uMsg = ::RegisterWindowMessage("San9PKHard");
		if (m_sWndMsg.uMsg == 0)
		{
			str.Format("CreateMessage()错误，error=%d", ::GetLastError());
			goto end_of_operation;
		}
	}
	//hwnd and message
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(HWND_MSG_ADDRESS),\
									(LPVOID)(&m_sWndMsg), sizeof(m_sWndMsg), NULL);
	CHECK_ERROR(ERR_WRITE_HWND_MESSAGE);
	//change_interface
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrChangeInterface),\
									(LPVOID)(codeChangeInterface), sizeof(codeChangeInterface), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_CHANGE_INTERFACE);
	//send message
	for (i = 0; i < PATCH_SEND_MESSAGE_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSendMessage[i].dwAddr),\
										(LPVOID)(patchSendMessage[i].pCode), patchSendMessage[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_SEND_MESSAGE);
	}
	//update end
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUpdateEnd),\
									(LPVOID)(codeUpdateEnd), sizeof(codeUpdateEnd), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_UPDATE_END);
	/////////////////////////////////////
	//check troop pos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckTroopPos),
										(LPVOID)(codeCheckTroopPos), sizeof(codeCheckTroopPos), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_TROOP_POS);
	//multi search person clear
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchPersonClear),
										(LPVOID)(codeSearchPersonClear), sizeof(codeSearchPersonClear), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_PERSON_CLEAR);
	//fast relay
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFastRelay),
										(LPVOID)(codeFastRelay), sizeof(codeFastRelay), NULL);
	CHECK_ERROR(ERR_WRITE_FAST_RELAY);
	//anti attack min defence
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAntiAttackMinDefence),\
								(LPVOID)(codeAntiAttackMinDefence), sizeof(codeAntiAttackMinDefence), NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_MIN_DEFENCE);
	//anti attack min defence 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAntiAttackMinDefence2),\
								(LPVOID)(codeAntiAttackMinDefence2), sizeof(codeAntiAttackMinDefence2), NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_MIN_DEFENCE);
	//menu no display
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMenuNoDisplay),
										(LPVOID)(codeMenuNoDisplay), sizeof(codeMenuNoDisplay), NULL);
	CHECK_ERROR(ERR_WRITE_MENU_NO_DISPLAY);
	//switch foot horse
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSwitchFootHorse),
										(LPVOID)(codeSwitchFootHorse), sizeof(codeSwitchFootHorse), NULL);
	CHECK_ERROR(ERR_WRITE_SWITCH_FOOT_HORSE);
	//max anti troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxAntiTroop),
										(LPVOID)(codeMaxAntiTroop), sizeof(codeMaxAntiTroop), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_ANTI_TROOP);
	//undel command person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUndelCommandPerson),
										(LPVOID)(codeUndelCommandPerson), sizeof(codeUndelCommandPerson), NULL);
	CHECK_ERROR(ERR_WRITE_UNDEL_COMMAND_PERSON);
	//array image
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrArrayImage),
										(LPVOID)(codeArrayImage), sizeof(codeArrayImage), NULL);
	CHECK_ERROR(ERR_WRITE_ARRAY_IMAGE);
	//troop experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopExperience),\
								(LPVOID)(codeTroopExperience), sizeof(codeTroopExperience), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_EXPERIENCE);
	//search condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchCondition),\
								(LPVOID)(codeSearchCondition), sizeof(codeSearchCondition), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_CONDITION);
	//not sure captive
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotSureCaptive),\
								(LPVOID)(codeNotSureCaptive), sizeof(codeNotSureCaptive), NULL);
	CHECK_ERROR(ERR_WRITE_NOT_SURE_CAPTIVE);
	//new force soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNewForceSoldier),\
								(LPVOID)(codeNewForceSoldier), sizeof(codeNewForceSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_NEW_FORCE_SOLDIER);
	//safe arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSafeArriveDay),\
								(LPVOID)(codeSafeArriveDay), sizeof(codeSafeArriveDay), NULL);
	CHECK_ERROR(ERR_WRITE_SAFE_ARRIVE_DAY);
	//attack min money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackMinMoney),
										(LPVOID)(codeAttackMinMoney), sizeof(codeAttackMinMoney), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_MIN_MONEY);
	//attack null building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackNullBuilding),\
								(LPVOID)(codeAttackNullBuilding), sizeof(codeAttackNullBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_NULL_BUILDING);
	//circle attack building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCircleAttackBuilding),\
								(LPVOID)(codeCircleAttackBuilding), sizeof(codeCircleAttackBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_CIRCLE_ATTACK_BUILDING);
	//check go on attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckGoOnAttack),\
								(LPVOID)(codeCheckGoOnAttack), sizeof(codeCheckGoOnAttack), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_GO_ON_ATTACK);
	//select attack person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectAttackPerson),\
								(LPVOID)(codeSelectAttackPerson), sizeof(codeSelectAttackPerson), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_ATTACK_PERSON);
	//add official loyaty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAddOfficialLoyaty),\
								(LPVOID)(codeAddOfficialLoyaty), sizeof(codeAddOfficialLoyaty), NULL);
	CHECK_ERROR(ERR_WRITE_ADD_OFFICIAL_LOYATY);
	//adjust killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAdjustKiller),\
								(LPVOID)(codeAdjustKiller), sizeof(codeAdjustKiller), NULL);
	CHECK_ERROR(ERR_WRITE_ADJUST_KILLER);
	//not attack near troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotAttackNearTroop),\
								(LPVOID)(codeNotAttackNearTroop), sizeof(codeNotAttackNearTroop), NULL);
	CHECK_ERROR(ERR_WRITE_NOT_ATTACK_NEAR_TROOP);
	//being build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBeingBuild),\
								(LPVOID)(codeBeingBuild), sizeof(codeBeingBuild), NULL);
	CHECK_ERROR(ERR_WRITE_BEING_BUILD);
	//anti attack wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAntiAttackWisdom),\
								(LPVOID)(codeAntiAttackWisdom), sizeof(codeAntiAttackWisdom), NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_WISDOM);
	//select attack wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectAttackWisdom),\
								(LPVOID)(codeSelectAttackWisdom), sizeof(codeSelectAttackWisdom), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_ATTACK_WISDOM);
	//draft fail bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDraftFailBug),\
								(LPVOID)(codeDraftFailBug), sizeof(codeDraftFailBug), NULL);
	CHECK_ERROR(ERR_WRITE_DRAFT_FAIL_BUG);
	//baram not build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBaramNotBuild),\
								(LPVOID)(codeBaramNotBuild), sizeof(codeBaramNotBuild), NULL);
	CHECK_ERROR(ERR_WRITE_BARAM_NOT_BUILD);
	//check min defence
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckMinDefence),\
								(LPVOID)(codeCheckMinDefence), sizeof(codeCheckMinDefence), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_MIN_DEFENCE);
	//regarded building on attack 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRegardedBuildingOnAttack2),\
								(LPVOID)(codeRegardedBuildingOnAttack2), sizeof(codeRegardedBuildingOnAttack2), NULL);
	CHECK_ERROR(ERR_WRITE_REGARDED_BUILDING_ON_ATTACK2);
	//check person killer level
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckPersonKillerLevel),\
								(LPVOID)(codeCheckPersonKillerLevel), sizeof(codeCheckPersonKillerLevel), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_PERSON_KILLER_LEVEL);
	//linkage killer to dialog
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLinkageKillerToDialog),\
								(LPVOID)(codeLinkageKillerToDialog), sizeof(codeLinkageKillerToDialog), NULL);
	CHECK_ERROR(ERR_WRITE_LINKAGE_KILLER_TO_DIALOG);
	//get array to wall
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetArrayToWall),\
								(LPVOID)(codeGetArrayToWall), sizeof(codeGetArrayToWall), NULL);
	CHECK_ERROR(ERR_WRITE_GET_ARRAY_TO_WALL);
	//check transport task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckTransportTask),\
								(LPVOID)(codeCheckTransportTask), sizeof(codeCheckTransportTask), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_TRANSPORT_TASK);
	//init transport building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrInitTransportBuilding),\
								(LPVOID)(codeInitTransportBuilding), sizeof(codeInitTransportBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_INIT_TRANSPORT_BUILDING);
	//max building wound
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxBuildingWound),\
								(LPVOID)(codeMaxBuildingWound), sizeof(codeMaxBuildingWound), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BUILDING_WOUND);
	//multi alienate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMultiAlienate),\
								(LPVOID)(codeMultiAlienate), sizeof(codeMultiAlienate), NULL);
	CHECK_ERROR(ERR_WRITE_MULTI_ALIENATE);
	//get officer type
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetOfficerType),\
								(LPVOID)(codeGetOfficerType), sizeof(codeGetOfficerType), NULL);
	CHECK_ERROR(ERR_WRITE_GET_OFFICER_TYPE);
	//building max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingMaxSoldier),\
								(LPVOID)(codeBuildingMaxSoldier), sizeof(codeBuildingMaxSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_MAX_SOLDIER);
	//max soldier push
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxSoldierPush),\
								(LPVOID)(codeMaxSoldierPush), sizeof(codeMaxSoldierPush), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_SOLDIER_PUSH);
	//learn to phase 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLearnToPhase2),\
								(LPVOID)(codeLearnToPhase2), sizeof(codeLearnToPhase2), NULL);
	CHECK_ERROR(ERR_WRITE_LEARN_TO_PHASE2);
	//attack ratio door
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackRatioDoor),\
								(LPVOID)(codeAttackRatioDoor), sizeof(codeAttackRatioDoor), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_RATIO_DOOR);
	//troop retreat
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopRetreat),\
								(LPVOID)(codeTroopRetreat), sizeof(codeTroopRetreat), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_RETREAT);
	//coordinate request
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCoordinateRequest),\
								(LPVOID)(codeCoordinateRequest), sizeof(codeCoordinateRequest), NULL);
	CHECK_ERROR(ERR_WRITE_COORDINATE_REQUEST);
	//get array attack range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetArrayAttackRange),\
								(LPVOID)(codeGetArrayAttackRange), sizeof(codeGetArrayAttackRange), NULL);
	CHECK_ERROR(ERR_WRITE_GET_ARRAY_ATTACK_RANGE);
	//check_player_view_range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckPlayerViewRange),\
								(LPVOID)(codeCheckPlayerViewRange), sizeof(codeCheckPlayerViewRange), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_PLAYER_VIEW_RANGE);
	//adjust attack array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAdjustAttackArray),\
								(LPVOID)(codeAdjustAttackArray), sizeof(codeAdjustAttackArray), NULL);
	CHECK_ERROR(ERR_WRITE_ADJUST_ATTACK_ARRAY);
	//sort multi select person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSortMultiSelectPerson),\
								(LPVOID)(codeSortMultiSelectPerson), sizeof(codeSortMultiSelectPerson), NULL);
	CHECK_ERROR(ERR_WRITE_SORT_MULTI_SELECT_PERSON);
	//check long range array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckLongRangeArray),\
								(LPVOID)(codeCheckLongRangeArray), sizeof(codeCheckLongRangeArray), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_LONG_RANGE_ARRAY);
	//move guard troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMoveGuardTroop),\
								(LPVOID)(codeMoveGuardTroop), sizeof(codeMoveGuardTroop), NULL);
	CHECK_ERROR(ERR_WRITE_MOVE_GUARD_TROOP);
	//soldier command killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSoldierCommandKiller),\
								(LPVOID)(codeSoldierCommandKiller), sizeof(codeSoldierCommandKiller), NULL);
	CHECK_ERROR(ERR_WRITE_SOLDIER_COMMAND_KILLER);
	//year table info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrYearTableInfo),\
								(LPVOID)(codeYearTableInfo), sizeof(codeYearTableInfo), NULL);
	CHECK_ERROR(ERR_WRITE_YEAR_TABLE_INFO);
	//water killer prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrWaterKillerProp),\
								(LPVOID)(codeWaterKillerProp), sizeof(codeWaterKillerProp), NULL);
	CHECK_ERROR(ERR_WRITE_WATER_KILLER_PROP);
	//false goal troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFalseGoalTroop),\
								(LPVOID)(codeFalseGoalTroop), sizeof(codeFalseGoalTroop), NULL);
	CHECK_ERROR(ERR_WRITE_FALSE_GOAL_TROOP);
	//damage number down
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDamageNumberDown),\
								(LPVOID)(codeDamageNumberDown), sizeof(codeDamageNumberDown), NULL);
	CHECK_ERROR(ERR_WRITE_DAMAGE_NUMBER_DOWN);
	//hide special state
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrHideSpecialState),\
								(LPVOID)(codeHideSpecialState), sizeof(codeHideSpecialState), NULL);
	CHECK_ERROR(ERR_WRITE_HIDE_SPECIAL_STATE);
	//retreat building condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRetreatBuildingCondition),\
									(LPVOID)(codeRetreatBuildingCondition), sizeof(codeRetreatBuildingCondition), NULL);
	CHECK_ERROR(ERR_WRITE_RETREAT_BUILDING_CONDITION);
	//test player view range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestPlayerViewRange),\
									(LPVOID)(codeTestPlayerViewRange), sizeof(codeTestPlayerViewRange), NULL);
	CHECK_ERROR(ERR_WRITE_TEST_PLAYER_VIEW_RANGE);
	//clear second killer person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrClearSecondKillerPerson),\
									(LPVOID)(codeClearSecondKillerPerson), sizeof(codeClearSecondKillerPerson), NULL);
	CHECK_ERROR(ERR_WRITE_CLEAR_SECOND_KILLER_PERSON);
	//judge attack build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJudgeAttackBuild),\
									(LPVOID)(codeJudgeAttackBuild), sizeof(codeJudgeAttackBuild), NULL);
	CHECK_ERROR(ERR_WRITE_JUDGE_ATTACK_BUILD);
	//max business
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxBusiness),\
									(LPVOID)(codeMaxBusiness), sizeof(codeMaxBusiness), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BUSINESS);
	//get force military pop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetForceMilitaryPop),\
									(LPVOID)(codeGetForceMilitaryPop), sizeof(codeGetForceMilitaryPop), NULL);
	CHECK_ERROR(ERR_WRITE_GET_FORCE_MILITARY_POP);
	//phase error invite
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPhaseErrorInvite),\
									(LPVOID)(codePhaseErrorInvite), sizeof(codePhaseErrorInvite), NULL);
	CHECK_ERROR(ERR_WRITE_PHASE_ERROR_INVITE);
	//fight sub income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFightSubIncome),\
									(LPVOID)(codeFightSubIncome), sizeof(codeFightSubIncome), NULL);
	CHECK_ERROR(ERR_WRITE_FIGHT_SUB_INCOME);
	//check draft food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckDraftFood),\
									(LPVOID)(codeCheckDraftFood), sizeof(codeCheckDraftFood), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_DRAFT_FOOD);
	//get max captive---------------------------
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetMaxCaptive),\
									(LPVOID)(codeGetMaxCaptive), sizeof(codeGetMaxCaptive), NULL);
	CHECK_ERROR(ERR_WRITE_GET_MAX_CAPTIVE);
	

//key process
	//key small
	for (i = 0; i < PATCH_KEY_SMALL_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeySmall[i].dwAddr),\
									(LPVOID)(patchKeySmall[i].pCode), patchKeySmall[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_KEY_SMALL);
	}
	//message entry
	for (i = 0; i < PATCH_MESSAGE_ENTRY_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMessageEntry[i].dwAddr),\
										(LPVOID)(patchMessageEntry[i].pCode), patchMessageEntry[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MESSAGE_ENTRY);
	}
	//key go
	for (i = 0; i < PATCH_KEY_GO_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeyGo[i].dwAddr),\
									(LPVOID)(patchKeyGo[i].pCode), patchKeyGo[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_KEY_GO);
	}
	//key search
	for (i = 0; i < PATCH_KEY_SEARCH_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeySearch[i].dwAddr),\
										(LPVOID)(patchKeySearch[i].pCode), patchKeySearch[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_KEY_SEARCH);
	}
	//go fast
	for (i = 0; i < PATCH_GO_FAST_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoFast[i].dwAddr),\
										(LPVOID)(patchGoFast[i].pCode), patchGoFast[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_GO_FAST);
	}
	//key info
	for (i = 0; i < PATCH_KEY_INFO_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeyInfo[i].dwAddr),\
									(LPVOID)(patchKeyInfo[i].pCode), patchKeyInfo[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_KEY_INFO);
	}
	//timer process
	for (i = 0; i < PATCH_TIMER_PROCESS_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTimerProcess[i].dwAddr),\
									(LPVOID)(patchTimerProcess[i].pCode), patchTimerProcess[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_TIMER_PROCESS);
	}
	//mouse click
	for (i = 0; i < PATCH_MOUSE_CLICK_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMouseClick[i].dwAddr),\
										(LPVOID)(patchMouseClick[i].pCode), patchMouseClick[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_MOUSE_CLICK);
	}
	//go nodisplay
	for (i = 0; i < PATCH_GO_NODISPLAY_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoNodisplay[i].dwAddr),\
										(LPVOID)(patchGoNodisplay[i].pCode), patchGoNodisplay[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_GO_NODISPLAY);
	}
	//key big
	for (i = 0; i < PATCH_KEY_BIG_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeyBig[i].dwAddr),\
									(LPVOID)(patchKeyBig[i].pCode), patchKeyBig[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_KEY_BIG);
	}
	//flag counter
	for (i = 0; i < PATCH_FLAG_COUNTER_PROCESS_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFlagCounterProcess[i].dwAddr),\
									(LPVOID)(patchFlagCounterProcess[i].pCode), patchFlagCounterProcess[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_PATCH_FLAG_COUNTER_PROCESS);
	}
	//key award
	for (i = 0; i < PATCH_KEY_AWARD_NUM; i++)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeyAward[i].dwAddr),\
									(LPVOID)(patchKeyAward[i].pCode), patchKeyAward[i].dwSize, NULL);
		CHECK_ERROR(ERR_WRITE_KEY_AWARD);
	}
	/////////////////////////////////
	//do award
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDoAward),
										(LPVOID)(codeDoAward), sizeof(codeDoAward), NULL);
	CHECK_ERROR(ERR_WRITE_DO_AWARD);
	//attack troop condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackTroopCondition),
										(LPVOID)(codeAttackTroopCondition),	sizeof(codeAttackTroopCondition), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_TROOP_CONDITION);
	//check no soldier building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckNoSoldierBuilding),
										(LPVOID)(codeCheckNoSoldierBuilding), sizeof(codeCheckNoSoldierBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_NO_SOLDIER_BUILDING);
	//relay failed dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRelayFailedDispatch),
										(LPVOID)(codeRelayFailedDispatch), sizeof(codeRelayFailedDispatch), NULL);
	CHECK_ERROR(ERR_WRITE_RELAY_FAILED_DISPATCH);
	//get distance
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetDistance),
										(LPVOID)(codeGetDistance), sizeof(codeGetDistance), NULL);
	CHECK_ERROR(ERR_WRITE_GET_DISTANCE);
	//check attack troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckAttackTroop),
										(LPVOID)(codeCheckAttackTroop), sizeof(codeCheckAttackTroop), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_ATTACK_TROOP);
	//adjust person pos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAdjustPersonPos),
										(LPVOID)(codeAdjustPersonPos), sizeof(codeAdjustPersonPos), NULL);
	CHECK_ERROR(ERR_WRITE_ADJUST_PERSON_POS);
	//building anti attack troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBuildingAntiAttackTroop),
										(LPVOID)(codeBuildingAntiAttackTroop), sizeof(codeBuildingAntiAttackTroop), NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_ANTI_ATTACK_TROOP);
	//test intelligence person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestIntelligencePerson),
										(LPVOID)(codeTestIntelligencePerson), sizeof(codeTestIntelligencePerson), NULL);
	CHECK_ERROR(ERR_WRITE_PATCH_TEST_INTELLIGENCE_PERSON);
	//jia xu officer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJiaXuOfficer),
										(LPVOID)(codeJiaXuOfficer), sizeof(codeJiaXuOfficer), NULL);
	CHECK_ERROR(ERR_WRITE_JIA_XU_OFFICER);
	//intelligence ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrIntelligenceAbility),
										(LPVOID)(codeIntelligenceAbility), sizeof(codeIntelligenceAbility), NULL);
	CHECK_ERROR(ERR_WRITE_INTELLIGENCE_ABILITY);
	//stone stop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrStoneStop),
										(LPVOID)(codeStoneStop), sizeof(codeStoneStop), NULL);
	CHECK_ERROR(ERR_WRITE_STONE_STOP);
	//search invite
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSearchInvite),
										(LPVOID)(codeSearchInvite), sizeof(codeSearchInvite), NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_INVITE);
	//sub anti trick
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSubAntiTrick),
										(LPVOID)(codeSubAntiTrick), sizeof(codeSubAntiTrick), NULL);
	CHECK_ERROR(ERR_WRITE_SUB_ANTI_TRICK);
	//gossip to player
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGossipToPlayer),
										(LPVOID)(codeGossipToPlayer), sizeof(codeGossipToPlayer), NULL);
	CHECK_ERROR(ERR_WRITE_GOSSIP_TO_PLAYER);
	//filter building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrFilterBuildingSoldier),\
								(LPVOID)(codeFilterBuildingSoldier), sizeof(codeFilterBuildingSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_FILTER_BUILDING_SOLDIER);
	//null building array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNullBuildingArray),
										(LPVOID)(codeNullBuildingArray), sizeof(codeNullBuildingArray), NULL);
	CHECK_ERROR(ERR_WRITE_NULL_BUILDING_ARRAY);
	//select attack building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectAttackBuilding),\
								(LPVOID)(codeSelectAttackBuilding), sizeof(codeSelectAttackBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_ATTACK_BUILDING);
	//reserve attacked building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrReserveAttackedBuilding),\
								(LPVOID)(codeReserveAttackedBuilding), sizeof(codeReserveAttackedBuilding), NULL);
	CHECK_ERROR(ERR_WRITE_RESERVE_ATTACKED_BUILDING);
	//max attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxAttackSoldier),\
								(LPVOID)(codeMaxAttackSoldier), sizeof(codeMaxAttackSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_ATTACK_SOLDIER);
	//correct near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCorrectNearMaxSoldier),\
								(LPVOID)(codeCorrectNearMaxSoldier), sizeof(codeCorrectNearMaxSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_CORRECT_NEAR_MAX_SOLDIER);
	//transfer killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTransferKiller),\
								(LPVOID)(codeTransferKiller), sizeof(codeTransferKiller), NULL);
	CHECK_ERROR(ERR_WRITE_TRANSFER_KILLER);
	//league fail
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLeagueFail),\
								(LPVOID)(codeLeagueFail), sizeof(codeLeagueFail), NULL);
	CHECK_ERROR(ERR_WRITE_LEAGUE_FAIL);
	//max build money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxBuildMoney),\
								(LPVOID)(codeMaxBuildMoney), sizeof(codeMaxBuildMoney), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BUILD_MONEY);
	//check wisdom antitrap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckWisdomAntitrap),\
								(LPVOID)(codeCheckWisdomAntitrap), sizeof(codeCheckWisdomAntitrap), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_WISDOM_ANTITRAP);
	//display year
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisplayYear),
										(LPVOID)(codeDisplayYear), sizeof(codeDisplayYear), NULL);
	CHECK_ERROR(ERR_WRITE_DISPLAY_YEAR);
	//draft min food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDraftMinFood),
										(LPVOID)(codeDraftMinFood), sizeof(codeDraftMinFood), NULL);
	CHECK_ERROR(ERR_WRITE_DRAFT_MIN_FOOD);
	//save near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSaveNearMaxSoldier),
										(LPVOID)(codeSaveNearMaxSoldier), sizeof(codeSaveNearMaxSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_NEAR_MAX_SOLDIER);
	//pre building soldier 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPreBuildingSoldier3),
										(LPVOID)(codePreBuildingSoldier3), sizeof(codePreBuildingSoldier3), NULL);
	CHECK_ERROR(ERR_WRITE_PRE_BUILDING_SOLDIER3);
	//test not null city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTestNotNullCity),
										(LPVOID)(codeTestNotNullCity), sizeof(codeTestNotNullCity), NULL);
	CHECK_ERROR(ERR_WRITE_TEST_NOT_NULL_CIYT);
	//regarded building on attack 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRegardedBuildingOnAttack3),\
								(LPVOID)(codeRegardedBuildingOnAttack3), sizeof(codeRegardedBuildingOnAttack3), NULL);
	CHECK_ERROR(ERR_WRITE_REGARDED_BUILDING_ON_ATTACK3);
	//judge killer linkage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJudgeKillerLinkage),\
								(LPVOID)(codeJudgeKillerLinkage), sizeof(codeJudgeKillerLinkage), NULL);
	CHECK_ERROR(ERR_WRITE_JUDGE_KILLER_LINKAGE);
	//main force dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMainForceDispatch),\
								(LPVOID)(codeMainForceDispatch), sizeof(codeMainForceDispatch), NULL);
	CHECK_ERROR(ERR_WRITE_MAIN_FORCE_DISPATCH);
	//get array to garrison
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetArrayToGarrison),\
								(LPVOID)(codeGetArrayToGarrison), sizeof(codeGetArrayToGarrison), NULL);
	CHECK_ERROR(ERR_WRITE_GET_ARRAY_TO_GARRISON);
	//set building soldier remains
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSetBuildingSoldierRemains),\
								(LPVOID)(codeSetBuildingSoldierRemains), sizeof(codeSetBuildingSoldierRemains), NULL);
	CHECK_ERROR(ERR_WRITE_SET_BUILDING_SOLDIER_REMAINS);
	//select transport source
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSelectTransportSource),\
								(LPVOID)(codeSelectTransportSource), sizeof(codeSelectTransportSource), NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_TRANSPORT_SOURCE);
	//check transport block
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCheckTransportBlock),\
								(LPVOID)(codeCheckTransportBlock), sizeof(codeCheckTransportBlock), NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_TRANSPORT_BLOCK);
	//try invite captive
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTryInviteCaptive),\
								(LPVOID)(codeTryInviteCaptive), sizeof(codeTryInviteCaptive), NULL);
	CHECK_ERROR(ERR_WRITE_TRY_INVITE_CAPTIVE);
	//command officer para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCommandOfficerPara),\
								(LPVOID)(codeCommandOfficerPara), sizeof(codeCommandOfficerPara), NULL);
	CHECK_ERROR(ERR_WRITE_COMMAND_OFFICER_PARA);
	//max people heart cmp
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxPeopleHeartCmp),\
								(LPVOID)(codeMaxPeopleHeartCmp), sizeof(codeMaxPeopleHeartCmp), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_PEOPLE_HEART_CMP);
	//delete max officer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDeleteMaxOfficer),\
									(LPVOID)(codeDeleteMaxOfficer), sizeof(codeDeleteMaxOfficer), NULL);
	CHECK_ERROR(ERR_WRITE_DELETE_MAX_OFFICER);
	//max soldier cmp
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMaxSoldierCmp),\
									(LPVOID)(codeMaxSoldierCmp), sizeof(codeMaxSoldierCmp), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_SOLDIER_CMP);
	//attack troop soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAttackTroopSoldier),\
									(LPVOID)(codeAttackTroopSoldier), sizeof(codeAttackTroopSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_TROOP_SOLDIER);
	//troop at good place
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrTroopAtGoodPlace),\
									(LPVOID)(codeTroopAtGoodPlace), sizeof(codeTroopAtGoodPlace), NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_AT_GOOD_PLACE);
	//second killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSecondKiller),\
									(LPVOID)(codeSecondKiller), sizeof(codeSecondKiller), NULL);
	CHECK_ERROR(ERR_WRITE_SECOND_KILLER);
	//get anti attack garrison
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetAntiAttackGarrison),\
									(LPVOID)(codeGetAntiAttackGarrison), sizeof(codeGetAntiAttackGarrison), NULL);
	CHECK_ERROR(ERR_WRITE_GET_ANTI_ATTACK_GARRISON);
	//get near building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetNearBuildingSoldier),\
									(LPVOID)(codeGetNearBuildingSoldier), sizeof(codeGetNearBuildingSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_GET_NEAR_BUILDING_SOLDIER);
	//person small dialog
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPersonSmallDialog),\
									(LPVOID)(codePersonSmallDialog), sizeof(codePersonSmallDialog), NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_SMALL_DIALOG);
	//get array killer power
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetArrayKillerPower),\
									(LPVOID)(codeGetArrayKillerPower), sizeof(codeGetArrayKillerPower), NULL);
	CHECK_ERROR(ERR_WRITE_GET_ARRAY_KILLER_POWER);
	//chaos linkage flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrChaosLinkageFlag),\
									(LPVOID)(codeChaosLinkageFlag), sizeof(codeChaosLinkageFlag), NULL);
	CHECK_ERROR(ERR_WRITE_CHAOS_LINKAGE_FLAG);
	//change troop command
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrChangeTroopCommand),\
									(LPVOID)(codeChangeTroopCommand), sizeof(codeChangeTroopCommand), NULL);
	CHECK_ERROR(ERR_WRITE_CHANGE_TROOP_COMMAND);
	//use baram array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUseBaramArray),\
								(LPVOID)(codeUseBaramArray), sizeof(codeUseBaramArray), NULL);
	CHECK_ERROR(ERR_WRITE_USE_BARAM_ARRAY);
	//weaken long range killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrWeakenLongRangeKiller),\
								(LPVOID)(codeWeakenLongRangeKiller), sizeof(codeWeakenLongRangeKiller), NULL);
	CHECK_ERROR(ERR_WRITE_WEAKEN_LONG_RANGE_KILLER);
	//month table info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMonthTableInfo),\
								(LPVOID)(codeMonthTableInfo), sizeof(codeMonthTableInfo), NULL);
	CHECK_ERROR(ERR_WRITE_MONTH_TABLE_INFO);
	//get info distance
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetInfoDistance),\
								(LPVOID)(codeGetInfoDistance), sizeof(codeGetInfoDistance), NULL);
	CHECK_ERROR(ERR_WRITE_GET_INFO_DISTANCE);
	//display building condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisplayBuildingCondition),\
								(LPVOID)(codeDisplayBuildingCondition), sizeof(codeDisplayBuildingCondition), NULL);
	CHECK_ERROR(ERR_WRITE_DISPLAY_BUILDING_CONDITION);
	//get player force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPlayerForce),\
								(LPVOID)(codeGetPlayerForce), sizeof(codeGetPlayerForce), NULL);
	CHECK_ERROR(ERR_WRITE_GET_PLAYER_FORCE);
	//get building view state
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetBuildingViewState),\
								(LPVOID)(codeGetBuildingViewState), sizeof(codeGetBuildingViewState), NULL);
	CHECK_ERROR(ERR_WRITE_GET_BUILDING_VIEW_STATE);
	//alloc free troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAllocFreeTroop),\
								(LPVOID)(codeAllocFreeTroop), sizeof(codeAllocFreeTroop), NULL);
	CHECK_ERROR(ERR_WRITE_ALLOC_FREE_TROOP);
	//skip arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSkipArriveDay),\
								(LPVOID)(codeSkipArriveDay), sizeof(codeSkipArriveDay), NULL);
	CHECK_ERROR(ERR_WRITE_SKIP_ARRIVE_DAY);
	//get_build_soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetBuildSoldier),\
								(LPVOID)(codeGetBuildSoldier), sizeof(codeGetBuildSoldier), NULL);
	CHECK_ERROR(ERR_WRITE_GET_BUILD_SOLDIER);
	//income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrIncome),\
								(LPVOID)(codeIncome), sizeof(codeIncome), NULL);
	CHECK_ERROR(ERR_WRITE_INCOME);
	//get force strength
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetForceStrength),\
								(LPVOID)(codeGetForceStrength), sizeof(codeGetForceStrength), NULL);
	CHECK_ERROR(ERR_WRITE_GET_FORCE_STRENGTH);
	//player auto process
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPlayerAutoProcess),\
								(LPVOID)(codePlayerAutoProcess), sizeof(codePlayerAutoProcess), NULL);
	CHECK_ERROR(ERR_WRITE_PLAYER_AUTO_PROCESS);
	//leader inspire
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrLeaderInspire),\
								(LPVOID)(codeLeaderInspire), sizeof(codeLeaderInspire), NULL);
	CHECK_ERROR(ERR_WRITE_LEADER_INSPIRE);
	//retreat change array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRetreatChangeArray),\
								(LPVOID)(codeRetreatChangeArray), sizeof(codeRetreatChangeArray), NULL);
	CHECK_ERROR(ERR_WRITE_RETREAT_CHANGE_ARRAY);

//thunk
	//harbor killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHarborKillerThunk[0].dwAddr),\
							(LPVOID)(patchHarborKillerThunk[0].pCode), patchHarborKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HARBOR_KILLER);
	//building killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingKillerThunk[0].dwAddr),\
							(LPVOID)(patchBuildingKillerThunk[0].pCode), patchBuildingKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILDING_KILLER);
	//siege experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSiegeExperienceThunk[0].dwAddr),\
							(LPVOID)(patchSiegeExperienceThunk[0].pCode), patchSiegeExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SIEGE_EXPERIENCE);
	//water killer experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWaterKillerExperienceThunk[0].dwAddr),\
					(LPVOID)(patchWaterKillerExperienceThunk[0].pCode), patchWaterKillerExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WATER_KILLER_EXPERIENCE);
	//killer experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerExperienceThunk[0].dwAddr),\
					(LPVOID)(patchKillerExperienceThunk[0].pCode), patchKillerExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_KILLER_EXPERIENCE);
	//alienate experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateExperienceThunk[0].dwAddr),\
					(LPVOID)(patchAlienateExperienceThunk[0].pCode), patchAlienateExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALIENATE_EXPERIENCE);
	//gossip experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGossipExperienceThunk[0].dwAddr),\
					(LPVOID)(patchGossipExperienceThunk[0].pCode), patchGossipExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GOSSIP_EXPERIENCE);
	//cheat experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheatExperienceThunk[0].dwAddr),\
					(LPVOID)(patchCheatExperienceThunk[0].pCode), patchCheatExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHEAT_EXPERIENCE);
	//disorder experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderExperienceThunk[0].dwAddr),\
					(LPVOID)(patchDisorderExperienceThunk[0].pCode), patchDisorderExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISORDER_EXPERIENCE);
	//inspire experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireExperienceThunk[0].dwAddr),\
					(LPVOID)(patchInspireExperienceThunk[0].pCode), patchInspireExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INSPIRE_EXPERIENCE);
	//rob money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobMoneyThunk[0].dwAddr),\
					(LPVOID)(patchRobMoneyThunk[0].pCode), patchRobMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ROB_MONEY);
	//person judgement
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonJudgementThunk[0].dwAddr),\
					(LPVOID)(patchPersonJudgementThunk[0].pCode), patchPersonJudgementThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PERSON_JUDGEMENT);
	//journey expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyExpenseThunk[0].dwAddr),\
					(LPVOID)(patchJourneyExpenseThunk[0].pCode), patchJourneyExpenseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JOURNEY_EXPENSE);
	//sub journey expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubJourneyExpenseThunk[0].dwAddr),\
					(LPVOID)(patchSubJourneyExpenseThunk[0].pCode), patchSubJourneyExpenseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SUB_JOURNEY_EXPENSE);
	//enable draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableDraftThunk[0].dwAddr),\
					(LPVOID)(patchEnableDraftThunk[0].pCode), patchEnableDraftThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ENABLE_DRAFT);
	//before go
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBeforeGoThunk[0].dwAddr),\
					(LPVOID)(patchBeforeGoThunk[0].pCode), patchBeforeGoThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BEFORE_GO);
	//enable commerce
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableCommerceThunk[0].dwAddr),\
					(LPVOID)(patchEnableCommerceThunk[0].pCode), patchEnableCommerceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ENABLE_COMMERCE);
	//enable cultivate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableCultivateThunk[0].dwAddr),\
					(LPVOID)(patchEnableCultivateThunk[0].pCode), patchEnableCultivateThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ENABLE_CULTIVATE);
	//not alienate garbage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotAlienateGarbageThunk[0].dwAddr),\
					(LPVOID)(patchNotAlienateGarbageThunk[0].pCode), patchNotAlienateGarbageThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NOT_ALIENATE_GARBAGE);
	//dispatch troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDispatchTroopThunk[0].dwAddr),\
					(LPVOID)(patchDispatchTroopThunk[0].pCode), patchDispatchTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISPATCH_TROOP);
	//chase flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaseFlagThunk[0].dwAddr),\
					(LPVOID)(patchChaseFlagThunk[0].pCode), patchChaseFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHASE_FLAG);
	//keep attack flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeepAttackFlagThunk[0].dwAddr),\
					(LPVOID)(patchKeepAttackFlagThunk[0].pCode), patchKeepAttackFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KEEP_ATTACK_FLAG);
	//check min defence
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMinDefenceThunk[0].dwAddr),\
					(LPVOID)(patchCheckMinDefenceThunk[0].pCode), patchCheckMinDefenceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_MIN_DEFENCE);
	//check troop pos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTroopPosThunk[0].dwAddr),\
					(LPVOID)(patchCheckTroopPosThunk[0].pCode), patchCheckTroopPosThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_TROOP_POS);
	//wisdom effective flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomEffectivFlagThunk[0].dwAddr),\
					(LPVOID)(patchWisdomEffectivFlagThunk[0].pCode), patchWisdomEffectivFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_EFFECTIVE_FLAG);
	//wisdom person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonThunk[0].dwAddr),\
					(LPVOID)(patchWisdomPersonThunk[0].pCode), patchWisdomPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_PERSON);
	//wisdom person abuse
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonAbuseThunk[0].dwAddr),\
					(LPVOID)(patchWisdomPersonAbuseThunk[0].pCode), patchWisdomPersonAbuseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_PERSON_ABUSE);
	//wisdom person attack heart
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonAttackHeartThunk[0].dwAddr),\
					(LPVOID)(patchWisdomPersonAttackHeartThunk[0].pCode), patchWisdomPersonAttackHeartThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_PERSON_ATTACK_HEART);
	//wisdom person magic
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonMagicThunk[0].dwAddr),\
					(LPVOID)(patchWisdomPersonMagicThunk[0].pCode), patchWisdomPersonMagicThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_PERSON_MAGIC);
	//wisdom person black art
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonBlackArtThunk[0].dwAddr),\
					(LPVOID)(patchWisdomPersonBlackArtThunk[0].pCode), patchWisdomPersonBlackArtThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_PERSON_BLACK_ART);
	//dispatch person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDispatchPersonThunk[0].dwAddr),\
					(LPVOID)(patchDispatchPersonThunk[0].pCode), patchDispatchPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISPATCH_PERSON);
	//min dispatch soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDispatchSoldierThunk[0].dwAddr),\
					(LPVOID)(patchMinDispatchSoldierThunk[0].pCode), patchMinDispatchSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MIN_DISPATCH_SOLDIER);
	//full prize
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFullPrizeThunk[0].dwAddr),\
					(LPVOID)(patchFullPrizeThunk[0].pCode), patchFullPrizeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FULL_PRIZE);
	//lower build expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLowerBuildExpenseThunk[0].dwAddr),\
					(LPVOID)(patchLowerBuildExpenseThunk[0].pCode), patchLowerBuildExpenseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LOWER_BUILD_EXPENSE);
	//attack troop condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopConditionThunk[0].dwAddr),\
					(LPVOID)(patchAttackTroopConditionThunk[0].pCode), patchAttackTroopConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_TROOP_CONDITION);
	//check no soldier building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckNoSoldierBuildingThunk[0].dwAddr),\
					(LPVOID)(patchCheckNoSoldierBuildingThunk[0].pCode), patchCheckNoSoldierBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_NO_SOLDIER_BUILDING);
	//anti attack min defence
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackMinDefenceThunk[0].dwAddr),\
					(LPVOID)(patchAntiAttackMinDefenceThunk[0].pCode), patchAntiAttackMinDefenceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ANTI_ATTACK_MIN_DEFENCE);
	//alienate min day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateMinDayThunk[0].dwAddr),\
					(LPVOID)(patchAlienateMinDayThunk[0].pCode), patchAlienateMinDayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALIENATE_MIN_DAY);
	//min building person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinBuildingPersonThunk[0].dwAddr),\
					(LPVOID)(patchMinBuildingPersonThunk[0].pCode), patchMinBuildingPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MIN_BUILDING_PERSON);
	//force troop list
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchForceTroopListThunk[0].dwAddr),\
					(LPVOID)(patchForceTroopListThunk[0].pCode), patchForceTroopListThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FORCE_TROOP_LIST);
	//building total soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingTotalSoldierThunk[0].dwAddr),\
					(LPVOID)(patchBuildingTotalSoldierThunk[0].pCode), patchBuildingTotalSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILDING_TOTAL_SOLDIER);
	//main force dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMainForceDispatchThunk[0].dwAddr),\
					(LPVOID)(patchMainForceDispatchThunk[0].pCode), patchMainForceDispatchThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAIN_FORCE_DISPATCH);
	//same force dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSameForceDispatchThunk[0].dwAddr),\
					(LPVOID)(patchSameForceDispatchThunk[0].pCode), patchSameForceDispatchThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAME_FORCE_DISPATCH);
	//relay failed dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRelayFailedDispatchThunk[0].dwAddr),\
					(LPVOID)(patchRelayFailedDispatchThunk[0].pCode), patchRelayFailedDispatchThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RELAY_FAILED_DISPATCH);
	//relay dispatch success
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRelayDispatchOkThunk[0].dwAddr),\
					(LPVOID)(patchRelayDispatchOkThunk[0].pCode), patchRelayDispatchOkThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RELAY_DISPATCH_OK);
	//fast relay
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFastRelayThunk[0].dwAddr),\
					(LPVOID)(patchFastRelayThunk[0].pCode), patchFastRelayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FAST_RELAY);
	//troop siege power
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopSiegePowerThunk[0].dwAddr),\
					(LPVOID)(patchTroopSiegePowerThunk[0].pCode), patchTroopSiegePowerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_SIEGE_POWER);
	//battle disable gossip
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBattleDisableGossipThunk[0].dwAddr),\
					(LPVOID)(patchBattleDisableGossipThunk[0].pCode), patchBattleDisableGossipThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BATTLE_DISABLE_GOSSIP);
	//check attack troop save
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAttackTroopSaveThunk[0].dwAddr),\
					(LPVOID)(patchCheckAttackTroopSaveThunk[0].pCode), patchCheckAttackTroopSaveThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_ATTACK_TROOP_SAVE);
	//check attack troop anti
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAttackTroopAntiThunk[0].dwAddr),\
					(LPVOID)(patchCheckAttackTroopAntiThunk[0].pCode), patchCheckAttackTroopAntiThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_ATTACK_TROOP_ANTI);
	//battle disable task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBattleDisableTaskThunk[0].dwAddr),\
					(LPVOID)(patchBattleDisableTaskThunk[0].pCode), patchBattleDisableTaskThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BATTLE_DISABLE_TASK);
	//simple award
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSimpleAwardThunk[0].dwAddr),\
					(LPVOID)(patchSimpleAwardThunk[0].pCode), patchSimpleAwardThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SIMPLE_AWARD);
	//menu no display
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMenuNoDisplayThunk[0].dwAddr),\
					(LPVOID)(patchMenuNoDisplayThunk[0].pCode), patchMenuNoDisplayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MENU_NO_DISPLAY);
	//intelligence killer coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceKillerCoefThunk[0].dwAddr),\
					(LPVOID)(patchIntelligenceKillerCoefThunk[0].pCode), patchIntelligenceKillerCoefThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INTELLIGENCE_KILLER_COEF);
	//intelligence killer coef 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceKillerCoef2Thunk[0].dwAddr),\
					(LPVOID)(patchIntelligenceKillerCoef2Thunk[0].pCode), patchIntelligenceKillerCoef2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INTELLIGENCE_KILLER_COEF2);
	//wisdom anti black art
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomAntiBlackArtThunk[0].dwAddr),\
					(LPVOID)(patchWisdomAntiBlackArtThunk[0].pCode), patchWisdomAntiBlackArtThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WISDOM_ANTI_BLACK_ART);
	//defence horse wimble
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceHorseWimbleThunk[0].dwAddr),\
					(LPVOID)(patchDefenceHorseWimbleThunk[0].pCode), patchDefenceHorseWimbleThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEFENCE_HORSE_WIMBLE);
	//check abuse
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAbuseThunk[0].dwAddr),\
					(LPVOID)(patchCheckAbuseThunk[0].pCode), patchCheckAbuseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_ABUSE);
	//check chaos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckChaosThunk[0].dwAddr),\
					(LPVOID)(patchCheckChaosThunk[0].pCode), patchCheckChaosThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_CHAOS);
	//switch foot horse
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSwitchFootHorseThunk[0].dwAddr),\
					(LPVOID)(patchSwitchFootHorseThunk[0].pCode), patchSwitchFootHorseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SWITCH_FOOT_HORSE);
	//adjust person pos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAdjustPersonPosThunk[0].dwAddr),\
					(LPVOID)(patchAdjustPersonPosThunk[0].pCode), patchAdjustPersonPosThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADJUST_PERSON_POS);
	//save troop expense
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveTroopExpenseThunk[0].dwAddr),\
					(LPVOID)(patchSaveTroopExpenseThunk[0].pCode), patchSaveTroopExpenseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_TROOP_EXPENSE);
	//min danger dispatch
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDangerDispatchThunk[0].dwAddr),\
					(LPVOID)(patchMinDangerDispatchThunk[0].pCode), patchMinDangerDispatchThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MIN_DANGER_DISPATCH);
	//max anti troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxAntiTroopThunk[0].dwAddr),\
					(LPVOID)(patchMaxAntiTroopThunk[0].pCode), patchMaxAntiTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_ANTI_TROOP);
	//pre building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPreBuildingSoldierThunk[0].dwAddr),\
					(LPVOID)(patchPreBuildingSoldierThunk[0].pCode), patchPreBuildingSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PRE_BUILDING_SOLDIER);
	//check officer money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckOfficerMoneyThunk[0].dwAddr),\
					(LPVOID)(patchCheckOfficerMoneyThunk[0].pCode), patchCheckOfficerMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_OFFICER_MONEY);
	//filter ready person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFilterReadyPersonThunk[0].dwAddr),\
					(LPVOID)(patchFilterReadyPersonThunk[0].pCode), patchFilterReadyPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FILTER_READY_PERSON);
	//command ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandAbilityThunk[0].dwAddr),\
					(LPVOID)(patchCommandAbilityThunk[0].pCode), patchCommandAbilityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_COMMAND_ABILITY);
	//jia xu officer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJiaXuOfficerThunk[0].dwAddr),\
					(LPVOID)(patchJiaXuOfficerThunk[0].pCode), patchJiaXuOfficerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JIA_XU_OFFICER);
	//undel command person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUndelCommandPersonThunk[0].dwAddr),\
					(LPVOID)(patchUndelCommandPersonThunk[0].pCode), patchUndelCommandPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UNDEL_COMMAND_PERSON);
	//del command person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDelCommandPersonThunk[0].dwAddr),\
					(LPVOID)(patchDelCommandPersonThunk[0].pCode), patchDelCommandPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEL_COMMAND_PERSON);
	//jia xu back
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJiaXuBackThunk[0].dwAddr),\
					(LPVOID)(patchJiaXuBackThunk[0].pCode), patchJiaXuBackThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JIA_XU_BACK);
	//undel intelligence person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUndelIntelligencePersonThunk[0].dwAddr),\
					(LPVOID)(patchUndelIntelligencePersonThunk[0].pCode), patchUndelIntelligencePersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UNDEL_INTELLIGENCE_PERSON);
	//del intelligence person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDelIntelligencePersonThunk[0].dwAddr),\
					(LPVOID)(patchDelIntelligencePersonThunk[0].pCode), patchDelIntelligencePersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEL_INTELLIGENCE_PERSON);
	//intelligence ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceAbilityThunk[0].dwAddr),\
					(LPVOID)(patchIntelligenceAbilityThunk[0].pCode), patchIntelligenceAbilityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INTELLIGENCE_ABILITY);
	//degrade person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDegradePersonThunk[0].dwAddr),\
					(LPVOID)(patchDegradePersonThunk[0].pCode), patchDegradePersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEGRADE_PERSON);
	//move idle person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveIdlePersonThunk[0].dwAddr),\
					(LPVOID)(patchMoveIdlePersonThunk[0].pCode), patchMoveIdlePersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MOVE_IDLE_PERSON);
	//move again
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveAgainThunk[0].dwAddr),\
					(LPVOID)(patchMoveAgainThunk[0].pCode), patchMoveAgainThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MOVE_AGAIN);
	//array image
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchArrayImageThunk[0].dwAddr),\
					(LPVOID)(patchArrayImageThunk[0].pCode), patchArrayImageThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ARRAY_IMAGE);
	//stone stop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStoneStopThunk[0].dwAddr),\
					(LPVOID)(patchStoneStopThunk[0].pCode), patchStoneStopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STONE_STOP);
	//command int ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandIntAbilityThunk[0].dwAddr),\
					(LPVOID)(patchCommandIntAbilityThunk[0].pCode), patchCommandIntAbilityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_COMMAND_INT_ABILITY);
	//captive money2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCaptiveMoney2Thunk[0].dwAddr),\
					(LPVOID)(patchCaptiveMoney2Thunk[0].pCode), patchCaptiveMoney2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CAPTIVE_MONEY_2);	
	//captive money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCaptiveMoneyThunk[0].dwAddr),\
					(LPVOID)(patchCaptiveMoneyThunk[0].pCode), patchCaptiveMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CAPTIVE_MONEY);
	//search range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchRangeThunk[0].dwAddr),\
					(LPVOID)(patchSearchRangeThunk[0].pCode), patchSearchRangeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_RANGE);
	//search condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchConditionThunk[0].dwAddr),\
					(LPVOID)(patchSearchConditionThunk[0].pCode), patchSearchConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_CONDITION);
	//search invite
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchInviteThunk[0].dwAddr),\
					(LPVOID)(patchSearchInviteThunk[0].pCode), patchSearchInviteThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_INVITE);
	//invite new person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteNewPersonThunk[0].dwAddr),\
					(LPVOID)(patchInviteNewPersonThunk[0].pCode), patchInviteNewPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INVITE_NEW_PERSON);
	//treasure value
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTreasureValueThunk[0].dwAddr),\
					(LPVOID)(patchTreasureValueThunk[0].pCode), patchTreasureValueThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TREASURE_VALUE);
	//update killer damage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateKillerDamageThunk[0].dwAddr),\
					(LPVOID)(patchUpdateKillerDamageThunk[0].pCode), patchUpdateKillerDamageThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UPDATE_KILLER_DAMAGE);
	//building killer person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingKillerPersonThunk[0].dwAddr),\
					(LPVOID)(patchBuildingKillerPersonThunk[0].pCode), patchBuildingKillerPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILDING_KILLER_PERSON);
	//save harbor
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveHarborThunk[0].dwAddr),\
					(LPVOID)(patchSaveHarborThunk[0].pCode), patchSaveHarborThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_HARBOR);
	//new force soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNewForceSoldierThunk[0].dwAddr),\
					(LPVOID)(patchNewForceSoldierThunk[0].pCode), patchNewForceSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NEW_FORCE_SOLDIER);
	//check troop retreat
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTroopRetreatThunk[0].dwAddr),\
					(LPVOID)(patchCheckTroopRetreatThunk[0].pCode), patchCheckTroopRetreatThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_TROOP_RETREAT);
	//check min left soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMinLeftSoldierThunk[0].dwAddr),\
					(LPVOID)(patchCheckMinLeftSoldierThunk[0].pCode), patchCheckMinLeftSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_MIN_LEFT_SOLDIER);
	//check max save soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMaxSaveSoldierThunk[0].dwAddr),\
					(LPVOID)(patchCheckMaxSaveSoldierThunk[0].pCode), patchCheckMaxSaveSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_MAX_SAVE_SOLDIER);
	//attack if check soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackIfCheckSoldierThunk[0].dwAddr),\
					(LPVOID)(patchAttackIfCheckSoldierThunk[0].pCode), patchAttackIfCheckSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_BUILDING_SOLDIER);
	//attack building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackBuildingSoldierThunk[0].dwAddr),\
					(LPVOID)(patchAttackBuildingSoldierThunk[0].pCode), patchAttackBuildingSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_BUILDING_SOLDIER);
	//attack left soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackLeftSoldierThunk[0].dwAddr),\
					(LPVOID)(patchAttackLeftSoldierThunk[0].pCode), patchAttackLeftSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_BUILDING_SOLDIER);
	//goto npc city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGotoNpcCityThunk[0].dwAddr),\
					(LPVOID)(patchGotoNpcCityThunk[0].pCode), patchGotoNpcCityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GOTO_NPC_CITY);
	//sub anti trick
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubAntiTrickThunk[0].dwAddr),\
					(LPVOID)(patchSubAntiTrickThunk[0].pCode), patchSubAntiTrickThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SUB_ANTI_TRICK);
	//sub anti trap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubAntiTrapThunk[0].dwAddr),\
					(LPVOID)(patchSubAntiTrapThunk[0].pCode), patchSubAntiTrapThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SUB_ANTI_TRAP);
	//max force food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxForceFoodThunk[0].dwAddr),\
					(LPVOID)(patchMaxForceFoodThunk[0].pCode), patchMaxForceFoodThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_FORCE_FOOD);
	//draft min money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftMinMoneyThunk[0].dwAddr),\
					(LPVOID)(patchDraftMinMoneyThunk[0].pCode), patchDraftMinMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DRAFT_MIN_MONEY);
	//attack min money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackMinMoneyThunk[0].dwAddr),\
					(LPVOID)(patchAttackMinMoneyThunk[0].pCode), patchAttackMinMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_MIN_MONEY);
	//gossip to player
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGossipToPlayerThunk[0].dwAddr),\
					(LPVOID)(patchGossipToPlayerThunk[0].pCode), patchGossipToPlayerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GOSSIP_TO_PLAYER);
	//filter building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFilterBuildingSoldierThunk[0].dwAddr),\
					(LPVOID)(patchFilterBuildingSoldierThunk[0].pCode), patchFilterBuildingSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FILTER_BUILDING_SOLDIER);
	//near null city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNearNullCityThunk[0].dwAddr),\
					(LPVOID)(patchNearNullCityThunk[0].pCode), patchNearNullCityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NEAR_NULL_CITY);
	//get player city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetPlayerCityThunk[0].dwAddr),\
					(LPVOID)(patchGetPlayerCityThunk[0].pCode), patchGetPlayerCityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_PLAYER_CITY);
	//attack null building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackNullBuildingThunk[0].dwAddr),\
					(LPVOID)(patchAttackNullBuildingThunk[0].pCode), patchAttackNullBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_NULL_BUILDING);
	//null building array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNullBuildingArrayThunk[0].dwAddr),\
					(LPVOID)(patchNullBuildingArrayThunk[0].pCode), patchNullBuildingArrayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NULL_BUILDING_ARRAY);
	//allie attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllieAttackThunk[0].dwAddr),\
					(LPVOID)(patchAllieAttackThunk[0].pCode), patchAllieAttackThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALLIE_ATTACK);
	//attack source city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackSourceCityThunk[0].dwAddr),\
					(LPVOID)(patchAttackSourceCityThunk[0].pCode), patchAttackSourceCityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_SOURCE_CITY);
	//circle attack building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCircleAttackBuildingThunk[0].dwAddr),\
					(LPVOID)(patchCircleAttackBuildingThunk[0].pCode), patchCircleAttackBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CIRCLE_ATTACK_BUILDING);
	//select attack building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackBuildingThunk[0].dwAddr),\
					(LPVOID)(patchSelectAttackBuildingThunk[0].pCode), patchSelectAttackBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_ATTACK_BUILDING);
	//attack min person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackMinPersonThunk[0].dwAddr),\
					(LPVOID)(patchAttackMinPersonThunk[0].pCode), patchAttackMinPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_MIN_PERSON);
	//add city relation
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddCityRelationThunk[0].dwAddr),\
					(LPVOID)(patchAddCityRelationThunk[0].pCode), patchAddCityRelationThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADD_CITY_RELATION);
	//reserve attacked building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchReserveAttackedBuildingThunk[0].dwAddr),\
					(LPVOID)(patchReserveAttackedBuildingThunk[0].pCode), patchReserveAttackedBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RESERVE_ATTACKED_BUILDING);
	//decide attack ok
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDecideAttackOkThunk[0].dwAddr),\
					(LPVOID)(patchDecideAttackOkThunk[0].pCode), patchDecideAttackOkThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DECIDE_ATTACK_OK);
	//retry attacked building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetryAttackedBuildingThunk[0].dwAddr),\
					(LPVOID)(patchRetryAttackedBuildingThunk[0].pCode), patchRetryAttackedBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RETRY_ATTACKED_BUILDING);
	//select attack person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackPersonThunk[0].dwAddr),\
					(LPVOID)(patchSelectAttackPersonThunk[0].pCode), patchSelectAttackPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_ATTACK_PERSON);
	//max attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxAttackSoldierThunk[0].dwAddr),\
					(LPVOID)(patchMaxAttackSoldierThunk[0].pCode), patchMaxAttackSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_ATTACK_SOLDIER);
	//building on the way
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingOnTheWayThunk[0].dwAddr),\
					(LPVOID)(patchBuildingOnTheWayThunk[0].pCode), patchBuildingOnTheWayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILDING_ON_THE_WAY);
	//left clever killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeftCleverKillerThunk[0].dwAddr),\
					(LPVOID)(patchLeftCleverKillerThunk[0].pCode), patchLeftCleverKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEFT_CLEVER_KILLER);
	//official loyaty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchOfficialLoyatyThunk[0].dwAddr),\
					(LPVOID)(patchOfficialLoyatyThunk[0].pCode), patchOfficialLoyatyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_OFFICIAL_LOYATY);
	//add official loyaty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddOfficialLoyatyThunk[0].dwAddr),\
					(LPVOID)(patchAddOfficialLoyatyThunk[0].pCode), patchAddOfficialLoyatyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADD_OFFICIAL_LOYATY);
	//correct near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectNearMaxSoldierThunk[0].dwAddr),\
					(LPVOID)(patchCorrectNearMaxSoldierThunk[0].pCode), patchCorrectNearMaxSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CORRECT_NEAR_MAX_SOLDIER);
	//select attack array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackArrayThunk[0].dwAddr),\
					(LPVOID)(patchSelectAttackArrayThunk[0].pCode), patchSelectAttackArrayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_ATTACK_ARRAY);
	//set near attack flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetNearAttackFlagThunk[0].dwAddr),\
					(LPVOID)(patchSetNearAttackFlagThunk[0].pCode), patchSetNearAttackFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SET_NEAR_ATTACK_FLAG);
	//not attack near troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotAttackNearTroopThunk[0].dwAddr),\
					(LPVOID)(patchNotAttackNearTroopThunk[0].pCode), patchNotAttackNearTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NOT_ATTACK_NEAR_TROOP);
	//league fail
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueFailThunk[0].dwAddr),\
					(LPVOID)(patchLeagueFailThunk[0].pCode), patchLeagueFailThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEAGUE_FAIL);
	//league succeed
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueSucceedThunk[0].dwAddr),\
					(LPVOID)(patchLeagueSucceedThunk[0].pCode), patchLeagueSucceedThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEAGUE_SUCCEED);
	//select build area
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectBuildAreaThunk[0].dwAddr),\
					(LPVOID)(patchSelectBuildAreaThunk[0].pCode), patchSelectBuildAreaThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_BUILD_AREA);
	//decide build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDecideBuildThunk[0].dwAddr),\
					(LPVOID)(patchDecideBuildThunk[0].pCode), patchDecideBuildThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DECIDE_BUILD);
	//being build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBeingBuildThunk[0].dwAddr),\
					(LPVOID)(patchBeingBuildThunk[0].pCode), patchBeingBuildThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BEING_BUILD);
	//not approach near troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotApproachNearTroopThunk[0].dwAddr),\
					(LPVOID)(patchNotApproachNearTroopThunk[0].pCode), patchNotApproachNearTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NOT_APPROACH_NEAR_TROOP);
	//build real goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildRealGoalThunk[0].dwAddr),\
					(LPVOID)(patchBuildRealGoalThunk[0].pCode), patchBuildRealGoalThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILD_REAL_GOAL);
	//max build money
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBuildMoneyThunk[0].dwAddr),\
					(LPVOID)(patchMaxBuildMoneyThunk[0].pCode), patchMaxBuildMoneyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_BUILD_MONEY);
	//go through near building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoThroughNearBuildingThunk[0].dwAddr),\
					(LPVOID)(patchGoThroughNearBuildingThunk[0].pCode), patchGoThroughNearBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GO_THROUGH_NEAR_BUILDING);
	//go through near barrier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoThroughNearBarrierThunk[0].dwAddr),\
					(LPVOID)(patchGoThroughNearBarrierThunk[0].pCode), patchGoThroughNearBarrierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GO_THROUGH_NEAR_BUILDING);
	//adjust attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAdjustAttackSoldierThunk[0].dwAddr),\
					(LPVOID)(patchAdjustAttackSoldierThunk[0].pCode), patchAdjustAttackSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADJUST_ATTACK_SOLDIER);
	//select water wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectWaterWisdomThunk[0].dwAddr),\
					(LPVOID)(patchSelectWaterWisdomThunk[0].pCode), patchSelectWaterWisdomThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_WATER_WISDOM);
	//anti attack antitrap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackAntitrapThunk[0].dwAddr),\
					(LPVOID)(patchAntiAttackAntitrapThunk[0].pCode), patchAntiAttackAntitrapThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ANTI_ATTACK_ANTITRAP);
	//anti attack wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackWisdomThunk[0].dwAddr),\
					(LPVOID)(patchAntiAttackWisdomThunk[0].pCode), patchAntiAttackWisdomThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ANTI_ATTACK_WISDOM);
	//select train person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectTrainPersonThunk[0].dwAddr),\
					(LPVOID)(patchSelectTrainPersonThunk[0].pCode), patchSelectTrainPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_TRAIN_PERSON);
	//select attack wisdom
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackWisdomThunk[0].dwAddr),\
					(LPVOID)(patchSelectAttackWisdomThunk[0].pCode), patchSelectAttackWisdomThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_ATTACK_WISDOM);
	//display year
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayYearThunk[0].dwAddr),\
					(LPVOID)(patchDisplayYearThunk[0].pCode), patchDisplayYearThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISPLAY_YEAR);
	//refuse change
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRefuseChangeThunk[0].dwAddr),\
					(LPVOID)(patchRefuseChangeThunk[0].pCode), patchRefuseChangeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_REFUSE_CHANGE);
	//draft fail bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftFailBugThunk[0].dwAddr),\
					(LPVOID)(patchDraftFailBugThunk[0].pCode), patchDraftFailBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DRAFT_FAIL_BUG);
	//draft min food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftMinFoodThunk[0].dwAddr),\
									(LPVOID)(patchDraftMinFoodThunk[0].pCode), patchDraftMinFoodThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DRAFT_MIN_FOOD);
	//save attack source building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveAttackSourceBuildingThunk[0].dwAddr),\
									(LPVOID)(patchSaveAttackSourceBuildingThunk[0].pCode), patchSaveAttackSourceBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_ATTACK_SOURCE_BUILDING);
	//correct building attack soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectBuildingAttackSoldierThunk[0].dwAddr),\
									(LPVOID)(patchCorrectBuildingAttackSoldierThunk[0].pCode), patchCorrectBuildingAttackSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CORRECT_BUILDING_ATTACK_SOLDIER);
	//correct goal building soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectGoalBuildingSoldierThunk[0].dwAddr),\
									(LPVOID)(patchCorrectGoalBuildingSoldierThunk[0].pCode), patchCorrectGoalBuildingSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CORRECT_GOAL_BUILDING_SOLDIER);
	//baram not build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBaramNotBuildThunk[0].dwAddr),\
									(LPVOID)(patchBaramNotBuildThunk[0].pCode), patchBaramNotBuildThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BARAM_NOT_BUILD);
	//save near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveNearMaxSoldierThunk[0].dwAddr),\
									(LPVOID)(patchSaveNearMaxSoldierThunk[0].pCode), patchSaveNearMaxSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_NEAR_MAX_SOLDIER);
	//load near max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLoadNearMaxSoldierThunk[0].dwAddr),\
									(LPVOID)(patchLoadNearMaxSoldierThunk[0].pCode), patchLoadNearMaxSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LOAD_NEAR_MAX_SOLDIER);
	//load near max soldier 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLoadNearMaxSoldier2Thunk[0].dwAddr),\
									(LPVOID)(patchLoadNearMaxSoldier2Thunk[0].pCode), patchLoadNearMaxSoldier2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LOAD_NEAR_MAX_SOLDIER);
	//set force goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetForceGoalThunk[0].dwAddr),\
									(LPVOID)(patchSetForceGoalThunk[0].pCode), patchSetForceGoalThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SET_FORCE_GOAL);
	//test not null city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTestNotNullCityThunk[0].dwAddr),\
									(LPVOID)(patchTestNotNullCityThunk[0].pCode), patchTestNotNullCityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TEST_NOT_NULL_CIYT);
	//regarded building on attack
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttackThunk[0].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttackThunk[0].pCode), patchRegardedBuildingOnAttackThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_REGARDED_BUILDING_ON_ATTACK);
	//regarded building on attack 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttack2Thunk[0].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttack2Thunk[0].pCode), patchRegardedBuildingOnAttack2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_REGARDED_BUILDING_ON_ATTACK2);
	//regarded building on attack 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttack3Thunk[0].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttack3Thunk[0].pCode), patchRegardedBuildingOnAttack3Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_REGARDED_BUILDING_ON_ATTACK3);
	//check person killer level
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckPersonKillerLevelThunk[0].dwAddr),\
									(LPVOID)(patchCheckPersonKillerLevelThunk[0].pCode), patchCheckPersonKillerLevelThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_PERSON_KILLER_LEVEL);
	//judge killer linkage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJudgeKillerLinkageThunk[0].dwAddr),\
									(LPVOID)(patchJudgeKillerLinkageThunk[0].pCode), patchJudgeKillerLinkageThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JUDGE_KILLER_LINKAGE);
	//killer power to damage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerPowerToDamageThunk[0].dwAddr),\
									(LPVOID)(patchKillerPowerToDamageThunk[0].pCode), patchKillerPowerToDamageThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILLER_POWER_TO_DAMAGE);
	//linkage killer to record
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLinkageKillerToRecordThunk[0].dwAddr),\
									(LPVOID)(patchLinkageKillerToRecordThunk[0].pCode), patchLinkageKillerToRecordThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LINKAGE_KILLER_TO_RECORD);
	//linkage killer to dialog
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLinkageKillerToDialogThunk[0].dwAddr),\
									(LPVOID)(patchLinkageKillerToDialogThunk[0].pCode), patchLinkageKillerToDialogThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LINKAGE_KILLER_TO_DIALOG);
	//get array to wall
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayToWallThunk[0].dwAddr),\
									(LPVOID)(patchGetArrayToWallThunk[0].pCode), patchGetArrayToWallThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_ARRAY_TO_WALL);
	//get array to garrison
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayToGarrisonThunk[0].dwAddr),\
									(LPVOID)(patchGetArrayToGarrisonThunk[0].pCode), patchGetArrayToGarrisonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_ARRAY_TO_GARRISON);
	//direct big animation
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDirectBigAnimationThunk[0].dwAddr),\
									(LPVOID)(patchDirectBigAnimationThunk[0].pCode), patchDirectBigAnimationThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DIRECT_BIG_ANIMATION);
	//force fight troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchForceFightTroopThunk[0].dwAddr),\
									(LPVOID)(patchForceFightTroopThunk[0].pCode), patchForceFightTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FORCE_FIGHT_TROOP);
	//get tranasport soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetTransportSoldierThunk[0].dwAddr),\
									(LPVOID)(patchGetTransportSoldierThunk[0].pCode), patchGetTransportSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_TRANSPORT_SOLDIER);
	//check transport task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTransportTaskThunk[0].dwAddr),\
									(LPVOID)(patchCheckTransportTaskThunk[0].pCode), patchCheckTransportTaskThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_TRANSPORT_TASK);
	//set building soldier remains
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetBuildingSoldierRemainsThunk[0].dwAddr),\
									(LPVOID)(patchSetBuildingSoldierRemainsThunk[0].pCode), patchSetBuildingSoldierRemainsThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SET_BUILDING_SOLDIER_REMAINS);
	//init transport building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInitTransportBuildingThunk[0].dwAddr),\
									(LPVOID)(patchInitTransportBuildingThunk[0].pCode), patchInitTransportBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INIT_TRANSPORT_BUILDING);
	//select transport source
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectTransportSourceThunk[0].dwAddr),\
									(LPVOID)(patchSelectTransportSourceThunk[0].pCode), patchSelectTransportSourceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_TRANSPORT_SOURCE);
	//sort transport source
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSortTransportSourceThunk[0].dwAddr),\
									(LPVOID)(patchSortTransportSourceThunk[0].pCode), patchSortTransportSourceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SORT_TRANSPORT_SOURCE);
	//stop train bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopTrainBugThunk[0].dwAddr),\
									(LPVOID)(patchStopTrainBugThunk[0].pCode), patchStopTrainBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STOP_TRAIN_BUG);
	//stop commerce bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopCommerceBugThunk[0].dwAddr),\
									(LPVOID)(patchStopCommerceBugThunk[0].pCode), patchStopCommerceBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STOP_COMMERCE_BUG);
	//stop cultivate bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopCultivateBugThunk[0].dwAddr),\
									(LPVOID)(patchStopCultivateBugThunk[0].pCode), patchStopCultivateBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STOP_CULTIVATE_BUG);
	//stop visit bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopVisitBugThunk[0].dwAddr),\
									(LPVOID)(patchStopVisitBugThunk[0].pCode), patchStopVisitBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STOP_VISIT_BUG);
	//stop repair bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopRepairBugThunk[0].dwAddr),\
									(LPVOID)(patchStopRepairBugThunk[0].pCode), patchStopRepairBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STOP_REPAIR_BUG);
	//max building wound
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBuildingWoundThunk[0].dwAddr),\
									(LPVOID)(patchMaxBuildingWoundThunk[0].pCode), patchMaxBuildingWoundThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_BUILDING_WOUND);
	//check transport block
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTransportBlockThunk[0].dwAddr),\
									(LPVOID)(patchCheckTransportBlockThunk[0].pCode), patchCheckTransportBlockThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHECK_TRANSPORT_BLOCK);
	//auto save docname
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoSaveDocnameThunk[0].dwAddr),\
									(LPVOID)(patchAutoSaveDocnameThunk[0].pCode), patchAutoSaveDocnameThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_AUTO_SAVE_DOCNAME);
	//multi alienate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMultiAlienateThunk[0].dwAddr),\
									(LPVOID)(patchMultiAlienateThunk[0].pCode), patchMultiAlienateThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MULTI_ALIENATE);
	//person experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonExperienceThunk[0].dwAddr),\
									(LPVOID)(patchPersonExperienceThunk[0].pCode), patchPersonExperienceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PERSON_EXPERIENCE);
	//command officer para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandOfficerParaThunk[0].dwAddr),\
									(LPVOID)(patchCommandOfficerParaThunk[0].pCode), patchCommandOfficerParaThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_COMMAND_OFFICER_PARA);
	//delete max officer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDeleteMaxOfficerThunk[0].dwAddr),\
									(LPVOID)(patchDeleteMaxOfficerThunk[0].pCode), patchDeleteMaxOfficerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DELETE_MAX_OFFICER);
	//intelligence officer para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceOfficerParaThunk[0].dwAddr),\
									(LPVOID)(patchIntelligenceOfficerParaThunk[0].pCode), patchIntelligenceOfficerParaThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INTELLIGENCE_OFFICER_PARA);
	//building max soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingMaxSoldierThunk[0].dwAddr),\
									(LPVOID)(patchBuildingMaxSoldierThunk[0].pCode), patchBuildingMaxSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILDING_MAX_SOLDIER);
	//max people heart cmp
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmpThunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmpThunk[0].pCode), patchMaxPeopleHeartCmpThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_CMP);
	//max people heart cmp 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp2Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp2Thunk[0].pCode), patchMaxPeopleHeartCmp2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_CMP);
	//max people heart cmp 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp3Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp3Thunk[0].pCode), patchMaxPeopleHeartCmp3Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_CMP);
	//max people heart cmp 4
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp4Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp4Thunk[0].pCode), patchMaxPeopleHeartCmp4Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_CMP);
	//get city max people heart
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetCityMaxPeopleHeartThunk[0].dwAddr),\
									(LPVOID)(patchGetCityMaxPeopleHeartThunk[0].pCode), patchGetCityMaxPeopleHeartThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_CITY_MAX_PEOPLE_HEART);
	//max people heart push
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPushThunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPushThunk[0].pCode), patchMaxPeopleHeartPushThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_PUSH);
	//max people heart push 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush2Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush2Thunk[0].pCode), patchMaxPeopleHeartPush2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_PUSH);
	//max people heart push 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush3Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush3Thunk[0].pCode), patchMaxPeopleHeartPush3Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_PUSH);
	//max people heart push 4
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush4Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush4Thunk[0].pCode), patchMaxPeopleHeartPush4Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_PUSH);
	//max people heart mov
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartMovThunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartMovThunk[0].pCode), patchMaxPeopleHeartMovThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_MOV);
	//max people heart mov 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartMov2Thunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartMov2Thunk[0].pCode), patchMaxPeopleHeartMov2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_MOV);
	//max people heart basic
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartBasicThunk[0].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartBasicThunk[0].pCode), patchMaxPeopleHeartBasicThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_PEOPLE_HEART_BASIC);
	//max soldier push
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierPushThunk[0].dwAddr),\
									(LPVOID)(patchMaxSoldierPushThunk[0].pCode), patchMaxSoldierPushThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_SOLDIER_PUSH);
	//max soldier push 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierPush2Thunk[0].dwAddr),\
									(LPVOID)(patchMaxSoldierPush2Thunk[0].pCode), patchMaxSoldierPush2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_SOLDIER_PUSH);
	//max soldier cmp
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierCmpThunk[0].dwAddr),\
									(LPVOID)(patchMaxSoldierCmpThunk[0].pCode), patchMaxSoldierCmpThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_SOLDIER_CMP);
	//dynamic add proficiency
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDynamicAddProficiencyThunk[0].dwAddr),\
									(LPVOID)(patchDynamicAddProficiencyThunk[0].pCode), patchDynamicAddProficiencyThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DYNAMIC_ADD_PROFICIENCY);
	//learn to phase
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLearnToPhaseThunk[0].dwAddr),\
									(LPVOID)(patchLearnToPhaseThunk[0].pCode), patchLearnToPhaseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEARN_TO_PHASE);
	//learn to phase 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLearnToPhase2Thunk[0].dwAddr),\
									(LPVOID)(patchLearnToPhase2Thunk[0].pCode), patchLearnToPhase2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEARN_TO_PHASE2);
	//attack troop soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopSoldierThunk[0].dwAddr),\
									(LPVOID)(patchAttackTroopSoldierThunk[0].pCode), patchAttackTroopSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_TROOP_SOLDIER);
	//attack troop soldier 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopSoldier2Thunk[0].dwAddr),\
									(LPVOID)(patchAttackTroopSoldier2Thunk[0].pCode), patchAttackTroopSoldier2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_TROOP_SOLDIER2);
	//person char num
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonCharNumThunk[0].dwAddr),\
									(LPVOID)(patchPersonCharNumThunk[0].pCode), patchPersonCharNumThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PERSON_CHAR_NUM);
	//attack ratio door
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackRatioDoorThunk[0].dwAddr),\
									(LPVOID)(patchAttackRatioDoorThunk[0].pCode), patchAttackRatioDoorThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_RATIO_DOOR);
	//troop at good place
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAtGoodPlaceThunk[0].dwAddr),\
									(LPVOID)(patchTroopAtGoodPlaceThunk[0].pCode), patchTroopAtGoodPlaceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_AT_GOOD_PLACE);
	//troop retreat
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopRetreatThunk[0].dwAddr),\
									(LPVOID)(patchTroopRetreatThunk[0].pCode), patchTroopRetreatThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_RETREAT);
	//second killer interval
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSecondKillerIntervalThunk[0].dwAddr),\
									(LPVOID)(patchSecondKillerIntervalThunk[0].pCode), patchSecondKillerIntervalThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SECOND_KILLER_INTERVAL);
	//get person quota
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetPersonQuotaThunk[0].dwAddr),\
									(LPVOID)(patchGetPersonQuotaThunk[0].pCode), patchGetPersonQuotaThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_PERSON_QUOTA);
	//coordinate request
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCoordinateRequestThunk[0].dwAddr),\
									(LPVOID)(patchCoordinateRequestThunk[0].pCode), patchCoordinateRequestThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_COORDINATE_REQUEST);
	//get array attack range
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayAttackRangeThunk[0].dwAddr),\
									(LPVOID)(patchGetArrayAttackRangeThunk[0].pCode), patchGetArrayAttackRangeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_ARRAY_ATTACK_RANGE);
	//display troop condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayTroopConditionThunk[0].dwAddr),\
									(LPVOID)(patchDisplayTroopConditionThunk[0].pCode), patchDisplayTroopConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISPLAY_TROOP_CONDITION);
	//person small dialog
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonSmallDialogThunk[0].dwAddr),\
									(LPVOID)(patchPersonSmallDialogThunk[0].pCode), patchPersonSmallDialogThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PERSON_SMALL_DIALOG);
	//troop at small map
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAtSmallMapThunk[0].dwAddr),\
									(LPVOID)(patchTroopAtSmallMapThunk[0].pCode), patchTroopAtSmallMapThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_AT_SMALL_MAP);
	//disorder goal troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderGoalTroopThunk[0].dwAddr),\
									(LPVOID)(patchDisorderGoalTroopThunk[0].pCode), patchDisorderGoalTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISORDER_GOAL_TROOP);
	//block prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBlcokPropThunk[0].dwAddr),\
									(LPVOID)(patchBlcokPropThunk[0].pCode), patchBlcokPropThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BLOCK_PROP);
	//chaos linkage flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaosLinkageFlagThunk[0].dwAddr),\
									(LPVOID)(patchChaosLinkageFlagThunk[0].pCode), patchChaosLinkageFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHAOS_LINKAGE_FLAG);
	//trap linkage flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTrapLinkageFlagThunk[0].dwAddr),\
									(LPVOID)(patchTrapLinkageFlagThunk[0].pCode), patchTrapLinkageFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TRAP_LINKAGE_FLAG);
	//attack heart linkage flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackHeartLinkageFlagThunk[0].dwAddr),\
									(LPVOID)(patchAttackHeartLinkageFlagThunk[0].pCode), patchAttackHeartLinkageFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ATTACK_HEART_LINKAGE_FLAG);
	//all strong force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllStrongForceThunk[0].dwAddr),\
									(LPVOID)(patchAllStrongForceThunk[0].pCode), patchAllStrongForceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALL_STRONG_FORCE);
	//read scene index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchReadSceneIndexThunk[0].dwAddr),\
									(LPVOID)(patchReadSceneIndexThunk[0].pCode), patchReadSceneIndexThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_READ_SCENE_INDEX);
	//killer drive prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerDrivePropThunk[0].dwAddr),\
									(LPVOID)(patchKillerDrivePropThunk[0].pCode), patchKillerDrivePropThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILLER_DIRVE_PROP);
	//killer drive prop 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerDriveProp2Thunk[0].dwAddr),\
									(LPVOID)(patchKillerDriveProp2Thunk[0].pCode), patchKillerDriveProp2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILLER_DIRVE_PROP);
	//clear troop cur goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchClearTroopCurGoalThunk[0].dwAddr),\
									(LPVOID)(patchClearTroopCurGoalThunk[0].pCode), patchClearTroopCurGoalThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CLEAR_TROOP_CUR_GOAL);
	//move guard troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveGuardTroopThunk[0].dwAddr),\
									(LPVOID)(patchMoveGuardTroopThunk[0].pCode), patchMoveGuardTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MOVE_GUARD_TROOP);
	//strength killer big animaiton
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStrengthKillerBigAnimaitonThunk[0].dwAddr),\
									(LPVOID)(patchStrengthKillerBigAnimaitonThunk[0].pCode), patchStrengthKillerBigAnimaitonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STRENGTH_KILLER_BIG_ANIMATION);
	//update captive prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateCaptivePropThunk[0].dwAddr),\
									(LPVOID)(patchUpdateCaptivePropThunk[0].pCode), patchUpdateCaptivePropThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UPDATE_CAPTIVE_PROP);
	//control march troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchControlMarchTroopThunk[0].dwAddr),\
									(LPVOID)(patchControlMarchTroopThunk[0].pCode), patchControlMarchTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CONTROL_MARCH_TROOP);
	//year table info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchYearTableInfoThunk[0].dwAddr),\
									(LPVOID)(patchYearTableInfoThunk[0].pCode), patchYearTableInfoThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_YEAR_TABLE_INFO);
	//month table info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMonthTableInfoThunk[0].dwAddr),\
									(LPVOID)(patchMonthTableInfoThunk[0].pCode), patchMonthTableInfoThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MONTH_TABLE_INFO);
	//rob food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobFoodThunk[0].dwAddr),\
									(LPVOID)(patchRobFoodThunk[0].pCode), patchRobFoodThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ROB_FOOD);
	//killer to building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerToBuildingThunk[0].dwAddr),\
									(LPVOID)(patchKillerToBuildingThunk[0].pCode), patchKillerToBuildingThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILLER_TO_BUILDING);
	//journey goal troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyGoalTroopThunk[0].dwAddr),\
									(LPVOID)(patchJourneyGoalTroopThunk[0].pCode), patchJourneyGoalTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JOURNEY_GOAL_TROOP);
	//false goal troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseGoalTroopThunk[0].dwAddr),\
									(LPVOID)(patchFalseGoalTroopThunk[0].pCode), patchFalseGoalTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FALSE_GOAL_TROOP);
	//display building condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayBuildingConditionThunk[0].dwAddr),\
									(LPVOID)(patchDisplayBuildingConditionThunk[0].pCode), patchDisplayBuildingConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISPLAY_BUILDING_CONDITION);
	//hide duty person num
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDutyPersonNumThunk[0].dwAddr),\
									(LPVOID)(patchHideDutyPersonNumThunk[0].pCode), patchHideDutyPersonNumThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_DUTY_PERSON_NUM);
	//hide duty person num 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDutyPersonNum2Thunk[0].dwAddr),\
									(LPVOID)(patchHideDutyPersonNum2Thunk[0].pCode), patchHideDutyPersonNum2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_DUTY_PERSON_NUM2);
	//test dark flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTestDarkFlagThunk[0].dwAddr),\
									(LPVOID)(patchTestDarkFlagThunk[0].pCode), patchTestDarkFlagThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TEST_DARK_FLAG);
	//journey goal troop 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyGoalTroop2Thunk[0].dwAddr),\
									(LPVOID)(patchJourneyGoalTroop2Thunk[0].pCode), patchJourneyGoalTroop2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JOURNEY_GOAL_TROOP);
	//hide info menu
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideInfoMenuThunk[0].dwAddr),\
									(LPVOID)(patchHideInfoMenuThunk[0].pCode), patchHideInfoMenuThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_INFO_MENU);
	//damage number down
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDamageNumberDownThunk[0].dwAddr),\
									(LPVOID)(patchDamageNumberDownThunk[0].pCode), patchDamageNumberDownThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DAMAGE_NUMBER_DOWN);
	//hide down stone
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDownStoneThunk[0].dwAddr),\
									(LPVOID)(patchHideDownStoneThunk[0].pCode), patchHideDownStoneThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_DOWN_STONE);
	//hide special state
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideSpecialStateThunk[0].dwAddr),\
									(LPVOID)(patchHideSpecialStateThunk[0].pCode), patchHideSpecialStateThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_SPECIAL_STATE);
	//retreat building condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetreatBuildingConditionThunk[0].dwAddr),\
									(LPVOID)(patchRetreatBuildingConditionThunk[0].pCode), patchRetreatBuildingConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RETREAT_BUILDING_CONDITION);
	//hide city morale
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityMoraleThunk[0].dwAddr),\
									(LPVOID)(patchHideCityMoraleThunk[0].pCode), patchHideCityMoraleThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_CITY_MORALE);
	//hide city income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityIncomeThunk[0].dwAddr),\
									(LPVOID)(patchHideCityIncomeThunk[0].pCode), patchHideCityIncomeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_CITY_INCOME);
	//hide city harvest
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityHarvestThunk[0].dwAddr),\
									(LPVOID)(patchHideCityHarvestThunk[0].pCode), patchHideCityHarvestThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HIDE_CITY_HARVEST);
	//alloc free troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllocFreeTroopThunk[0].dwAddr),\
									(LPVOID)(patchAllocFreeTroopThunk[0].pCode), patchAllocFreeTroopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALLOC_FREE_TROOP);
	//counselor report prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCounselorReportPropThunk[0].dwAddr),\
									(LPVOID)(patchCounselorReportPropThunk[0].pCode), patchCounselorReportPropThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_COUNSELOR_REPORT_PROP);
	//killer check bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerCheckBugThunk[0].dwAddr),\
									(LPVOID)(patchKillerCheckBugThunk[0].pCode), patchKillerCheckBugThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILLER_CHECK_BUG);
	//chaos power coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaosPowerCoefThunk[0].dwAddr),\
									(LPVOID)(patchChaosPowerCoefThunk[0].pCode), patchChaosPowerCoefThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHAOS_POWER_COEF);
	//clear second killer person
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchClearSecondKillerPersonThunk[0].dwAddr),\
									(LPVOID)(patchClearSecondKillerPersonThunk[0].pCode), patchClearSecondKillerPersonThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CLEAR_SECOND_KILLER_PERSON);
	//skip arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSkipArriveDayThunk[0].dwAddr),\
									(LPVOID)(patchSkipArriveDayThunk[0].pCode), patchSkipArriveDayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SKIP_ARRIVE_DAY);
	//build arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildArriveDayThunk[0].dwAddr),\
									(LPVOID)(patchBuildArriveDayThunk[0].pCode), patchBuildArriveDayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILD_ARRIVE_DAY);
	//judge attack build
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJudgeAttackBuildThunk[0].dwAddr),\
									(LPVOID)(patchJudgeAttackBuildThunk[0].pCode), patchJudgeAttackBuildThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_JUDGE_ATTACK_BUILD);
	//max business
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBusinessThunk[0].dwAddr),\
									(LPVOID)(patchMaxBusinessThunk[0].pCode), patchMaxBusinessThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_BUSINESS);
	//max business 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBusiness2Thunk[0].dwAddr),\
									(LPVOID)(patchMaxBusiness2Thunk[0].pCode), patchMaxBusiness2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MAX_BUSINESS);
	//income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIncomeThunk[0].dwAddr),\
									(LPVOID)(patchIncomeThunk[0].pCode), patchIncomeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INCOME);
	//harvest
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHarvestThunk[0].dwAddr),\
									(LPVOID)(patchHarvestThunk[0].pCode), patchHarvestThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HARVEST);
	//city population coef 1
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef1Thunk[0].dwAddr),\
									(LPVOID)(patchCityPopulationCoef1Thunk[0].pCode), patchCityPopulationCoef1Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CITY_POPULATION_COEF);
	//city population coef 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef2Thunk[0].dwAddr),\
									(LPVOID)(patchCityPopulationCoef2Thunk[0].pCode), patchCityPopulationCoef2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CITY_POPULATION_COEF);
	//city population coef 3
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef3Thunk[0].dwAddr),\
									(LPVOID)(patchCityPopulationCoef3Thunk[0].pCode), patchCityPopulationCoef3Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CITY_POPULATION_COEF);
	//city population coef 4
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef4Thunk[0].dwAddr),\
									(LPVOID)(patchCityPopulationCoef4Thunk[0].pCode), patchCityPopulationCoef4Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CITY_POPULATION_COEF);
	//goal force para
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoalForceParaThunk[0].dwAddr),\
									(LPVOID)(patchGoalForceParaThunk[0].pCode), patchGoalForceParaThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GOAL_FORCE_PARA);
	//show city draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchShowCityDraftThunk[0].dwAddr),\
									(LPVOID)(patchShowCityDraftThunk[0].pCode), patchShowCityDraftThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SHOW_CITY_DRAFT);	
	//add city draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddCityDraftThunk[0].dwAddr),\
									(LPVOID)(patchAddCityDraftThunk[0].pCode), patchAddCityDraftThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADD_CITY_DRAFT);
	//get league goal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetLeagueGoalThunk[0].dwAddr),\
									(LPVOID)(patchGetLeagueGoalThunk[0].pCode), patchGetLeagueGoalThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_LEAGUE_GOAL);
	//fight sub income
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncomeThunk[0].dwAddr),\
									(LPVOID)(patchFightSubIncomeThunk[0].pCode), patchFightSubIncomeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FIGHT_SUB_INCOME);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncome2Thunk[0].dwAddr),\
									(LPVOID)(patchFightSubIncome2Thunk[0].pCode), patchFightSubIncome2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FIGHT_SUB_INCOME);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncome3Thunk[0].dwAddr),\
									(LPVOID)(patchFightSubIncome3Thunk[0].pCode), patchFightSubIncome3Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FIGHT_SUB_INCOME);
	//operation per day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchOperationPerDayThunk[0].dwAddr),\
									(LPVOID)(patchOperationPerDayThunk[0].pCode), patchOperationPerDayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_OPERATION_PER_DAY);
	//kill sub prestige
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillSubPrestigeThunk[0].dwAddr),\
									(LPVOID)(patchKillSubPrestigeThunk[0].pCode), patchKillSubPrestigeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_KILL_SUB_PRESTIGE);
	//auto process task
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoProcessTaskThunk[0].dwAddr),\
									(LPVOID)(patchAutoProcessTaskThunk[0].pCode), patchAutoProcessTaskThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_AUTO_PROCESS_TASK);
	//train basic ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTrainBasicAbilityThunk[0].dwAddr),\
									(LPVOID)(patchTrainBasicAbilityThunk[0].pCode), patchTrainBasicAbilityThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TRAIN_BASIC_ABILITY);
	//retreat change array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetreatChangeArrayThunk[0].dwAddr),\
									(LPVOID)(patchRetreatChangeArrayThunk[0].pCode), patchRetreatChangeArrayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_RETREAT_CHANGE_ARRAY);
	//set max captive
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetMaxCaptiveThunk[0].dwAddr),\
									(LPVOID)(patchSetMaxCaptiveThunk[0].pCode), patchSetMaxCaptiveThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SET_MAX_CAPTIVE);
	//get max captive
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetMaxCaptiveThunk[0].dwAddr),\
									(LPVOID)(patchGetMaxCaptiveThunk[0].pCode), patchGetMaxCaptiveThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_MAX_CAPTIVE);
	
	//enable water killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableWaterKillerThunk[0].dwAddr),\
									(LPVOID)(patchEnableWaterKillerThunk[0].pCode), patchEnableWaterKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ENABLE_WATER_KILLER);
	//auto adjust killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoAdjustKillerThunk[0].dwAddr),\
									(LPVOID)(patchAutoAdjustKillerThunk[0].pCode), patchAutoAdjustKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_AUTO_ADJUST_KILLER)	
	//investment
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInvestmentThunk[0].dwAddr),\
									(LPVOID)(patchInvestmentThunk[0].pCode), patchInvestmentThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INVESTMENT);	
	//heart attack damage 1
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHeartAttackDamage1Thunk[0].dwAddr),\
									(LPVOID)(patchHeartAttackDamage1Thunk[0].pCode), patchHeartAttackDamage1Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HEART_ATTACK_DAMAGE_1);
	//heart attack damage 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHeartAttackDamage2Thunk[0].dwAddr),\
									(LPVOID)(patchHeartAttackDamage2Thunk[0].pCode), patchHeartAttackDamage2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_HEART_ATTACK_DAMAGE_2);		
	//intelligence damage record
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceDamageRecordThunk[0].dwAddr),\
									(LPVOID)(patchIntelligenceDamageRecordThunk[0].pCode), patchIntelligenceDamageRecordThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INTELLIGENCE_DAMAGE_RECORD);
	//strength damage record
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStrengthDamageRecordThunk[0].dwAddr),\
									(LPVOID)(patchStrengthDamageRecordThunk[0].pCode), patchStrengthDamageRecordThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_STRENGTH_DAMAGE_RECORD);
	//skip contained dialog
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSkipContainedDialogThunk[0].dwAddr),\
									(LPVOID)(patchSkipContainedDialogThunk[0].pCode), patchSkipContainedDialogThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SKIP_CONTAINED_DIALOG);
	//set troop index  
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetTroopIndexThunk[0].dwAddr),\
									(LPVOID)(patchSetTroopIndexThunk[0].pCode), patchSetTroopIndexThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SET_TROOP_INDEX);
	//troop index  
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopIndexThunk[0].dwAddr),\
									(LPVOID)(patchTroopIndexThunk[0].pCode), patchTroopIndexThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_INDEX);	
	//troop advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAdviseThunk[0].dwAddr),\
									(LPVOID)(patchTroopAdviseThunk[0].pCode), patchTroopAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TROOP_ADVISE);
	//get troop index
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetTroopIndexThunk[0].dwAddr),\
									(LPVOID)(patchGetTroopIndexThunk[0].pCode), patchGetTroopIndexThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_TROOP_INDEX);		
//multi search
	//search stop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchStopThunk[0].dwAddr),\
					(LPVOID)(patchSearchStopThunk[0].pCode), patchSearchStopThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_STOP);
	//search select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchSelectThunk[0].dwAddr),\
					(LPVOID)(patchSearchSelectThunk[0].pCode), patchSearchSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_SELECT);
	//search perform
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchPerformThunk[0].dwAddr),\
					(LPVOID)(patchSearchPerformThunk[0].pCode), patchSearchPerformThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_PERFORM);
	//invite perform
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInvitePerformThunk[0].dwAddr),\
					(LPVOID)(patchInvitePerformThunk[0].pCode), patchInvitePerformThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INVITE_PERFORM);
	//invite multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchInviteMultiSelectThunk[0].pCode), patchInviteMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INVITE_MULTI_SELECT);
	//save multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchSaveMultiSelectThunk[0].pCode), patchSaveMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_MULTI_SELECT);
	//rob multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchRobMultiSelectThunk[0].pCode), patchRobMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ROB_MULTI_SELECT);
	//burn multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchBurnMultiSelectThunk[0].pCode), patchBurnMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BURN_MULTI_SELECT);
	//alienate multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchAlienateMultiSelectThunk[0].pCode), patchAlienateMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALIENATE_MULTI_SELECT);
	//false multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchFalseMultiSelectThunk[0].pCode), patchFalseMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FALSE_MULTI_SELECT);
	//disorder multi select
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderMultiSelectThunk[0].dwAddr),\
					(LPVOID)(patchDisorderMultiSelectThunk[0].pCode), patchDisorderMultiSelectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISORDER_MULTI_SELECT);
	///////////////////////////////////////////////////////////
	//search counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchSearchCounselorAdviseThunk[0].pCode), patchSearchCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SEARCH_COUNSELOR_ADVISE);
	//invite counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchInviteCounselorAdviseThunk[0].pCode), patchInviteCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INVITE_COUNSELOR_ADVISE);
	//false counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchFalseCounselorAdviseThunk[0].pCode), patchFalseCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FALSE_COUNSELOR_ADVISE);
	//false counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchFalseCounselorAdvise2Thunk[0].pCode), patchFalseCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FALSE_COUNSELOR_ADVISE);
	//disorder counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchDisorderCounselorAdviseThunk[0].pCode), patchDisorderCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISORDER_COUNSELOR_ADVISE);
	//disorder counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchDisorderCounselorAdvise2Thunk[0].pCode), patchDisorderCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DISORDER_COUNSELOR_ADVISE);
	//save counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchSaveCounselorAdviseThunk[0].pCode), patchSaveCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_COUNSELOR_ADVISE);
	//save counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchSaveCounselorAdvise2Thunk[0].pCode), patchSaveCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_COUNSELOR_ADVISE);
	//inspire counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchInspireCounselorAdviseThunk[0].pCode), patchInspireCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INSPIRE_COUNSELOR_ADVISE);
	//inspire counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchInspireCounselorAdvise2Thunk[0].pCode), patchInspireCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INSPIRE_COUNSELOR_ADVISE);
	//rob counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchRobCounselorAdviseThunk[0].pCode), patchRobCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ROB_COUNSELOR_ADVISE);
	//rob counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchRobCounselorAdvise2Thunk[0].pCode), patchRobCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ROB_COUNSELOR_ADVISE);
	//burn counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchBurnCounselorAdviseThunk[0].pCode), patchBurnCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BURN_COUNSELOR_ADVISE);
	//burn counselor advise 2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnCounselorAdvise2Thunk[0].dwAddr),\
					(LPVOID)(patchBurnCounselorAdvise2Thunk[0].pCode), patchBurnCounselorAdvise2Thunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BURN_COUNSELOR_ADVISE);
	//alienate counselor advise
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateCounselorAdviseThunk[0].dwAddr),\
					(LPVOID)(patchAlienateCounselorAdviseThunk[0].pCode), patchAlienateCounselorAdviseThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ALIENATE_COUNSELOR_ADVISE);
//message
	//update end play
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateEndPlayThunk[0].dwAddr),\
									(LPVOID)(patchUpdateEndPlayThunk[0].pCode), patchUpdateEndPlayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UPDATE_END_PLAY);
	//update end main
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateEndMainThunk[0].dwAddr),\
									(LPVOID)(patchUpdateEndMainThunk[0].pCode), patchUpdateEndMainThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_UPDATE_END_MAIN);
	//change interface
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChangeInterfaceThunk[0].dwAddr),\
								(LPVOID)(patchChangeInterfaceThunk[0].pCode), patchChangeInterfaceThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHANGE_INTERFACE);
//key process
	//reset decision ready flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDecisionReadyFlagAddr),\
													(LPVOID)(&one), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BEFORE_GO_FLAG);
	//reset go fast flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoFastFlagAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GO_FAST_FLAG);
	//reset go fast counter
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoFastCounterAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GO_FAST_COUNTER);
	//reset info fast flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInfoFastFlagAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INFO_FAST_FLAG);
	//reset info fast counter
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInfoFastCounterAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INFO_FAST_COUNTER);
	//reset award fast flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAwardFastFlagAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_AWARD_FAST_FLAG);
	//reset award fast counter
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAwardFastCounterAddr),\
													(LPVOID)(&zero), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_AWARD_FAST_COUNTER);
	//reset awardable person number
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAwardablePersonNumberAddr),\
													(LPVOID)(&negtive), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_AWARDABLE_PERSON_NUMBER);
	//go fast
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoFastThunk[0].dwAddr),\
					(LPVOID)(patchGoFastThunk[0].pCode), patchGoFastThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GO_FAST);
	//go no_display
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoNodisplayThunk[0].dwAddr),\
					(LPVOID)(patchGoNodisplayThunk[0].pCode), patchGoNodisplayThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GO_NODISPLAY);
	//message entry
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMessageEntryThunk[0].dwAddr),\
					(LPVOID)(patchMessageEntryThunk[0].pCode), patchMessageEntryThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MESSAGE_ENTRY);
//null thunk
	//league low prestige
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueLowPrestigeThunk[0].dwAddr),\
									(LPVOID)(patchLeagueLowPrestigeThunk[0].pCode), patchLeagueLowPrestigeThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEAGUE_LOW_PRESTIGE);
	//defence array arrow
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayArrowThunk[0].dwAddr),\
									(LPVOID)(patchDefenceArrayArrowThunk[0].pCode), patchDefenceArrayArrowThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEFENCE_ARRAY_ARROW);
	//defence array wimble
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayWimbleThunk[0].dwAddr),\
									(LPVOID)(patchDefenceArrayWimbleThunk[0].pCode), patchDefenceArrayWimbleThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEFENCE_ARRAY_WIMBLE);
	//defence array scale
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayScaleThunk[0].dwAddr),\
									(LPVOID)(patchDefenceArrayScaleThunk[0].pCode), patchDefenceArrayScaleThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_DEFENCE_ARRAY_SCALE);
	//elephant anti killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchElephantAntiKillerThunk[0].dwAddr),\
									(LPVOID)(patchElephantAntiKillerThunk[0].pCode), patchElephantAntiKillerThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ELEPHANT_ANTI_KILLER);
	//build min soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildMinSoldierThunk[0].dwAddr),\
									(LPVOID)(patchBuildMinSoldierThunk[0].pCode), patchBuildMinSoldierThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_BUILD_MIN_SOLDIER);
	//transport goal condition
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTransportGoalConditionThunk[0].dwAddr),\
									(LPVOID)(patchTransportGoalConditionThunk[0].pCode), patchTransportGoalConditionThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TRANSPORT_GOAL_CONDITION);
	//init match step
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInitMatchStepThunk[0].dwAddr),\
									(LPVOID)(patchInitMatchStepThunk[0].pCode), patchInitMatchStepThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_INIT_MATCH_STEP);
	//transport match
	bSuccess = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTransportMatchThunk[1].dwAddr),\
									(LPVOID)(patchTransportMatchThunk[1].pCode), patchTransportMatchThunk[1].dwSize, NULL);
	CHECK_ERROR(ERR_READ_THUNK_TRANSPORT_MATCH);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTransportMatchThunk[0].dwAddr),\
									(LPVOID)(patchTransportMatchThunk[0].pCode), patchTransportMatchThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TRANSPORT_MATCH);
	//get person friendship
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPersonFriendship),\
									(LPVOID)(codeGetPersonFriendship), sizeof(codeGetPersonFriendship), NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GET_PERSON_FRIENDSHIP);
	//save troop display object
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveTroopDisplayObjectThunk[0].dwAddr),\
									(LPVOID)(patchSaveTroopDisplayObjectThunk[0].pCode), patchSaveTroopDisplayObjectThunk[0].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SAVE_TROOP_DISPLAY_OBJECT);

//code
	//harbor killer function
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwHarborKillerAddr),\
									(LPVOID)(&m_dwHarborKillerFunction), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_HARBOR_KILLER_FUNCTION);
	//town killer function
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTownKillerAddr),\
									(LPVOID)(&m_dwTownKillerFunction), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TOWN_KILLER_FUNCTION);
	//burn experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnExperienceAddr),\
									(LPVOID)(&m_dwBurnExperienceCode), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BURN_EXPERIENCE);
	//rob experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRobExperienceAddr),\
									(LPVOID)(&m_dwRobExperienceCode), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ROB_EXPERIENCE);
	//reinforce experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwReinforceExperienceAddr),\
									(LPVOID)(&m_dwReinforceExperienceCode), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_REINFORCE_EXPERIENCE);
	//train experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainExperienceAddr),\
									(LPVOID)(&m_dwTrainExperienceCode), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TRAIN_EXPERIENCE);
	//repair experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRepairExperienceAddr),\
									(LPVOID)(&m_dwRepairExperienceCode), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_REPAIR_EXPERIENCE);
	//cultivate min politics
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCultivateMinPoliticsAddr),\
									(LPVOID)(&m_dwCultivateMinPolitics), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_CULTIVATE_MIN_POLITICS);
	//dispatch array
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDispatchArrayAddr),\
									(LPVOID)(&m_dwDispatchArray), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISPATCH_ARRAY);
	//dispatch ship
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDispatchShipAddr),\
									(LPVOID)(&m_dwDispatchShip), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISPATCH_SHIP);
	//chaos day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwChaosDayAddr),\
									(LPVOID)(&m_dwChaosDayCoef), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_CHAOS_DAY);
	//lower trick
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLowerTrickAddr),\
									(LPVOID)(&m_dwLowerTrickCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LOWER_TRICK);
	//wisdom resist trick
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwWisdomResistTrickAddr),\
									(LPVOID)(&m_dwWisdomResistTrickCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_WISDOM_RESIST_TRICK);
	//lower trap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLowerTrapAddr),\
									(LPVOID)(&m_dwLowerTrickCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LOWER_TRAP);
	//alienate intelligenc experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAlienateIntelligenceAddr),\
									(LPVOID)(&m_dwAlienateIntelligenceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALIENATE_INTELLIGENCE);
	//gossip intelligence experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipIntelligenceAddr),\
									(LPVOID)(&m_dwGossipIntelligenceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GOSSIP_INTELLIGENCE);
	//inspire intelligenc experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInspireIntelligenceAddr),\
									(LPVOID)(&m_dwInspireIntelligenceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INSPIRE_INTELLIGENCE);
	//cheat intelligenc experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCheatIntelligenceAddr),\
									(LPVOID)(&m_dwCheatIntelligenceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_CHEAT_INTELLIGENCE);
	//disorder intelligenc experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisorderIntelligenceAddr),\
									(LPVOID)(&m_dwDisorderIntelligenceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISORDER_INTELLIGENCE);
	//build experience
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildExperienceAddr),\
									(LPVOID)(&m_dwBuildExperienceCode), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BUILD_EXPERIENCE);
	//antiattack min soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackMinSoldierdAddr),\
									(LPVOID)(&m_dwAntiAttackMinSoldier), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_MIN_SOLDIER);
	//antiattack barbarism
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackBarbarismAddr),\
									(LPVOID)(&m_dwAntiAttackBarbarism), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_BARBARISM);
	//antiattack assistant
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackAssistantAddr),\
									(LPVOID)(&m_dwAntiAttackAssistant), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_ATTACK_ASSISTANT);
	//alienate force name
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAlienateForceNameAddr),\
									(LPVOID)(&m_dwAlienateForceName), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALIENATE_FORCE_NAME);
	//anti min troop soldier
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiMinTroopSoldierAddr),\
									(LPVOID)(&m_dwAntiMinTroopSoldier), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_MIN_TROOP_SOLDIER);
	//save base
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSaveBaseAddr),\
									(LPVOID)(&m_dwSaveBase), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SAVE_BASE);
	//officer basic command
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwOfficerBasicCommandAddr),\
									(LPVOID)(&m_dwOfficerBasicCommand), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_OFFICER_BASIC_COMMAND);
	//officer basic intelligence and politics
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwOfficerBasicIntAddr),\
									(LPVOID)(&m_dwOfficerBasicInt), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_OFFICER_BASIC_INT);
	//search min politics
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSearchMinPoliticsAddr),\
									(LPVOID)(&m_dwSearchMinPolitics), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_MIN_POLITICS);
	//foot anti elephant
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwFootAntiElephantAddr),\
									(LPVOID)(&m_dwFootAntiElephant), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_FOOT_ANTI_ELEPHANT);
	//inspire max vigour
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInspireMaxVigourAddr),\
									(LPVOID)(&m_dwInspireMaxVigour), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INSPIRE_MAX_VIGOUR);
	//load max food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLoadMaxFoodAddr),\
									(LPVOID)(&m_dwLoadMaxFood), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LOAD_MAX_FOOD);
	//gossip sub loyalty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipSubLoyaltyAddr),\
									(LPVOID)(&m_dwGossipSubLoyalty), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GOSSIP_SUB_LOYALTY);
	//gossip no alienate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipNoAlienateAddr),\
									(LPVOID)(&m_dwGossipNoAlienate), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GOSSIP_NO_ALIENATE);
	//goal null city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoalNullCityAddr),\
									(LPVOID)(&m_dwGoalNullCity), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GOAL_NULL_CITY);
	//null buliding danger
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNullBulidingDangerAddr),\
									(LPVOID)(&m_dwNullBulidingDanger), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NULL_BUILDING_DANGER);
	//avoid near city
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAvoidNearCityAddr),\
									(LPVOID)(&m_dwAvoidNearCity), WORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_AVOID_NEAR_CITY);
	//retreat min vigour
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRetreatMinVigourAddr),\
									(LPVOID)(&m_dwRetreatMinVigour), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_RETREAT_MIN_VIGOUR);
	//select clever killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSelectCleverKillerAddr),\
									(LPVOID)(&m_dwSelectCleverKiller), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SELECT_CLEVER_KILLER);
	//neglect chong che
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNeglectChongCheAddr),\
									(LPVOID)(&m_dwNeglectChongChe), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NEGLECT_CHONG_CHE);
	//same force troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSameForceTroopAddr),\
									(LPVOID)(&m_dwSameForceTroop), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SAME_FORCE_TROOP);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSameForceTroopAddr2),\
									(LPVOID)(&m_dwSameForceTroop), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SAME_FORCE_TROOP);
	//attack ignore antitrap
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAttackIgnoreAntitrapAddr),\
									(LPVOID)(&m_dwAttackIgnoreAntitrap), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_IGNORE_ANTITRAP);
	//donate max food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDonateMaxFoodAddr),\
									(LPVOID)(&m_dwLoadMaxFood), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DONATE_MAX_FOOD);
	//forecast max food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwForecastMaxFoodAddr),\
									(LPVOID)(&m_dwLoadMaxFood), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_FORECAST_MAX_FOOD);
	//dialog max food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDialogMaxFoodAddr),\
									(LPVOID)(&m_dwLoadMaxFood), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DIALOG_MAX_FOOD);	
	//home force door
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwHomeForceDoorAddr),\
									(LPVOID)(&m_dwHomeForceDoor), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_HOME_FORCE_DOOR);
	//avoid induce max day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAvoidInduceMaxDayAddr),\
									(LPVOID)(&m_dwAvoidInduceMaxDay), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_AVOID_INDUCE_MAX_DAY);
	//get troop goal bug
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGetTroopGoalBugAddr),\
									(LPVOID)(&m_dwGetTroopGoalBug), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GET_TROOP_GOAL_BUG);
	//goal to source damage
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoalToSourceDamageAddr),\
									(LPVOID)(&m_dwGoalToSourceDamage), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GOAL_TO_SOURCE_DAMAGE);
	//bad brothers array end
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBadBrothersArrayEndAddr),\
									(LPVOID)(&m_dwBadBrothersArrayEnd), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BAD_BROTHERS_ARRAY_END);
	//troop from building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopFromBuildingAddr),\
									(LPVOID)(&m_dwTroopFromBuilding), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_FROM_BUILDING);
	//false anti troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwFalseAntiTroopAddr),\
									(LPVOID)(&m_dwExternalAntiTroop), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_FALSE_ANTI_TROOP);
	//disorder anti troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisorderAntiTroopAddr),\
									(LPVOID)(&m_dwInternalAntiTroop), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISORDER_ANTI_TROOP);
	//declare attack troop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDeclareAttackTroopAddr),\
									(LPVOID)(&m_dwDeclareAttackTroop), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DECLARE_ATTACK_TROOP);
	//not attack only building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotAttackOnlyBuildingAddr),\
									(LPVOID)(&m_dwNotAttackOnlyBuilding), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_ATTACK_ONLY_BUILDING);
	//invite sub loyaty
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInviteSubLoyatyAddr),\
									(LPVOID)(&m_dwInviteSubLoyaty), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INVITE_SUB_LOYATY);
	//command officer end flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCommandOfficerEndFlagAddr),\
									(LPVOID)(&m_dwCommandOfficerEndFlag), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_COMMAND_OFFICER_END_FLAG);
	//intelligence officer end flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwIntelligenceOfficerEndFlagAddr),\
									(LPVOID)(&m_dwIntelligenceOfficerEndFlag), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INTELLIGENCE_OFFICER_END_FLAG);
	//show celue killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwShowCelueKillerAddr),\
									(LPVOID)(&m_dwShowCelueKiller), sizeof(m_dwShowCelueKiller), NULL);
	CHECK_ERROR(ERR_WRITE_SHOW_CELUE_KILLER);
	//show sex map
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwShowSexMapAddr),\
									(LPVOID)(&m_dwShowSexMap), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SHOW_SEX_MAP);
	//lvbu attack door
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLvbuAttackDoorAddr),\
									(LPVOID)(&m_dwLvbuAttackDoor), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LVBU_ATTACK_DOOR);
	//enable second killer
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableSecondKillerAddr),\
									(LPVOID)(&m_dwEnableSecondKiller), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_SECOND_KILLER);
	//troop goal building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopGoalBuildingAddr),\
									(LPVOID)(&m_dwTroopGoalBuilding), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_GOAL_BUILDING);
	//not get person quota
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotGetPersonQuotaAddr),\
									(LPVOID)(&m_dwNotGetPersonQuota), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_GET_PERSON_QUOTA);
	//year table invalid flag
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwYearTableInvalidFlagAddr),\
									(LPVOID)(&m_dwYearTableInvalidFlag), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_YEAR_TABLE_INVALID_FLAG);
	//transport goal info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTransportGoalInfoAddr),\
									(LPVOID)(&m_dwTransportGoalInfo), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TRANSPORT_GOAL_INFO);
	//counselor min candidate
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCounselorMinCandidateAddr),\
									(LPVOID)(&m_dwCounselorMinCandidate), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_COUNSELOR_MIN_CANDIDATE);
	//noarray to building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoarrayToBuildingAddr),\
									(LPVOID)(&m_dwNoarrayToBuilding), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOARRAY_TO_BUILDING);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoarrayToBuildingAddr2),\
									(LPVOID)(&m_dwNoarrayToBuilding), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOARRAY_TO_BUILDING);
	//search no result
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSearchNoResultAddr),\
									(LPVOID)(&m_dwSearchNoResult), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SEARCH_NO_RESULT);
	//attack build force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAttackBuildForceAddr),\
									(LPVOID)(&m_dwAttackBuildForce), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_BUILD_FORCE);
	//build max arrive day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildMaxArriveDayAddr),\
									(LPVOID)(&m_dwBuildMaxArriveDay), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BUILD_MAX_ARRIVE_DAY);
	//game end year
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGameEndYearAddr),\
									(LPVOID)(&m_dwGameEndYear), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_GAME_END_YEAR);
	//build min building
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildMinBuildingAddr),\
									(LPVOID)(&m_dwBuildMinBuilding), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BUILD_MIN_BUILDING);
	//update goal force
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwUpdateGoalForceAddr),\
									(LPVOID)(&m_dwUpdateGoalForce), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_UPDATE_GOAL_FORCE);
	//update goal prop
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwUpdateGoalPropAddr),\
									(LPVOID)(&m_dwUpdateGoalProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_UPDATE_GOAL_PROP);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
modify_setting:

//精进熟练度上限
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxExperienceAddr),\
									(LPVOID)(&m_wMaxExperience), sizeof(m_wMaxExperience), NULL);
	CHECK_ERROR(ERR_WRITE_MAX_EXPERIENCE);

//武将配置信息
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAddrPersonConfigInfo),\
									(LPVOID)(m_dwPersonConfigInfo), sizeof(m_dwPersonConfigInfo), NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_CONFIG_INFO);

//武将亲密度
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAddrPersonFriendship),\
									(LPVOID)(m_wPersonFriendship), sizeof(m_wPersonFriendship), NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_FRIENDSHIP);

//参数
	//保存9个分隔点到全局数组
	codeCutPoint[0] = m_uMoneyCut_1;
	codeCutPoint[1] = m_uMoneyCut_2;
	codeCutPoint[2] = m_uMoneyCut_3;
	codeCutPoint[3] = m_uFoodCut_1;
	codeCutPoint[4] = m_uFoodCut_2;
	codeCutPoint[5] = m_uFoodCut_3;
	codeCutPoint[6] = m_uDraftCut_1;
	codeCutPoint[7] = m_uDraftCut_2;
	codeCutPoint[8] = m_uDraftCut_3;

	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(addrCutPoint),\
									(LPVOID)(codeCutPoint), sizeof(codeCutPoint), NULL);
	CHECK_ERROR(ERR_WRITE_CUT_POINT);

	//year difference
	dwWrData = m_iYearDifference;
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDisplayYear+2),\
														(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_YEAR_DIFFERENCE);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrYearTableInfo+0x0C),\
														(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_YEAR_DIFFERENCE);

	//killer power coef
	dwWrData = m_uKillerPowerCoef;
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUpdateKillerDamage+0x1D),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_KILLER_POWER_COEF);

	//slash dead coef
	dwWrData = m_dwOldSlashDeadCoef + 4*m_uSlashDeadCoef;
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSlashDeadCoefAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SLASH_DEAD_COEF);

	//second killer coef
	dwWrData = (m_bSecondKiller==FALSE ? 1 : 0);//关闭/开启第二兵法
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSecondKillerThunk[dwWrData].dwAddr),\
									(LPVOID)(patchSecondKillerThunk[dwWrData].pCode), patchSecondKillerThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SECOND_KILLER);

	//官爵“无”的薪水
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoneOfficialSalaryAddr),
									(LPVOID)(&m_uNoOfficialSalary), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NULL_OFFICIAL_SALARY);

	//阻击概率系数
	dwWrData = 40 - m_uBlockPropCoef * 2;
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrBlcokProp + 8),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BLOCK_PROP_COEF);

	//电脑乱战系数
	dwWrData = m_uNpcAttackDisorder;
	if (dwWrData != 0)
		dwWrData = 10 - dwWrData;//专攻系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F4CC),//npc_attack_intensive
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_ATTACK_INTENSIVE);

	//相性同化系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F4CF),//nature_attract_coef
									(LPVOID)(&m_uNatureAttractCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NATURE_ATTRACT_COEF);

	//部队武将数兵法概率系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr),
									(LPVOID)(&m_uOnePersonKillerProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_NUM_KILLER_PROP);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+8),
									(LPVOID)(&m_uTwoPersonKillerProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_NUM_KILLER_PROP);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+16),
									(LPVOID)(&m_uThreePersonKillerProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_NUM_KILLER_PROP);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+24),
									(LPVOID)(&m_uFourPersonKillerProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_NUM_KILLER_PROP);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+32),
									(LPVOID)(&m_uFivePersonKillerProp), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_PERSON_NUM_KILLER_PROP);

	//反玩家联盟系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF19),//anti_player_league_coef
									(LPVOID)(&m_uAntiPlayerLeagueCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ANTI_PLAYER_LEAGUE_COEF);

	//检查联盟的概率
	dwWrData = 4 - m_uAntiPlayerLeagueCoef/4;//0~3=>P=1/4, 4~7=>P=1/3, 8~10=>P=1/2
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCheckLeagueProbabilityAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_CHECK_LEAGUE_PROBABILITY);

	//联盟时间
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLeagueTimeAddr),\
									(LPVOID)(&m_uLeagueTime), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LEAGUE_TIME);

	//交战减少内政系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF1A),//fight_sub_income_coef
									(LPVOID)(&m_uFightSubIncomeCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_FIGHT_SUB_INCOME_COEF);

	//最大俘虏系数
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF1D),//max_captive_coef
									(LPVOID)(&m_uMaxCaptiveCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_CAPTIVE_COEF);

//小兵培养
	//basic ability coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F3D1),\
									(LPVOID)(&m_uBasicAbilityCoef), BYTE_SIZE, NULL);//basic_ability_coef 
	CHECK_ERROR(ERR_WRITE_BASIC_ABLILITY_COEF);

	//sex coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSexCoefAddr),\
									(LPVOID)(&m_uSexCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SEX_COEF);

//战争迷雾
	//fog_view_range[3]+fog_soldier_error
	dwWrData = (m_uTroopViewRange&0xFF) + ((m_uBuildingViewRange&0xFF)<<8) + ((m_uCityViewRange&0xFF)<<16)\
					+ ((m_uSoldierDisplayError&0x7F)<<24);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F887), (LPVOID)(&dwWrData), DWORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_FOG_VIEW_RANGE);

	//counselor report coef
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F88F),//counselor_report_coef
										(LPVOID)(&m_uCounselorReportCoef), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_COUNSELOR_REPORT_COEF);

//都市攻防关系
	//city relation info
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCityRelationAddr),
										(LPVOID)(m_dwCityRelationInfo), sizeof(m_dwCityRelationInfo), NULL);
	CHECK_ERROR(ERR_WRITE_CITY_RELATION_INFO);
	//attack city max day
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAttackCityMaxDayAddr),
										(LPVOID)(m_btAttackCityMaxDay), sizeof(m_btAttackCityMaxDay), NULL);
	CHECK_ERROR(ERR_WRITE_ATTACK_CITY_MAX_DAY);

//选项
	//enable train
	dwWrData = (m_bEnableTrain == FALSE ? 0 : 50);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainNumAddr),\
										(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TRAIN_NUM);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainNumAddr2),\
										(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TRAIN_NUM);

	//all person live
	dwWrData = (m_bAllPersonLive == FALSE ? m_dwOldAllPersonLive : m_dwAllPersonLive);//test ebp, ebp/xor ebp,ebp
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonLiveAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_LIVE);

	//add killer proficiency
	dwWrData = (m_bDynamicAddProficiency == FALSE ? 0x27EB : 0xB999);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPersonExperience),\
														(LPVOID)(&dwWrData), WORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ADD_KILLER_PROFICIENCY);

	//disable alienate
	dwWrData = (m_bDisableAlienate == FALSE ? 0x85 : 0x33);//test eax, eax/xor eax,eax
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotAlienateGarbage[1]+5),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_ALIENATE);

	//soldier command killer
	dwWrData = (m_bSoldierCommandKiller == FALSE ? 0xCC : 0xCA);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSoldierCommandKiller+0x58),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SOLDIER_COMMAND_KILLER_FLAG);

	//all person dead
	dwWrData = (m_bAllPersonDead == FALSE ? m_dwOldAllPersonDead : m_dwAllPersonDead);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead1Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead2Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead3Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);

	//friend to alienate
	//phase error alienate
	dwWrData = (m_bFriendToAlienate == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPhaseErrorAlienateThunk[dwWrData].dwAddr),\
									(LPVOID)(patchPhaseErrorAlienateThunk[dwWrData].pCode), patchPhaseErrorAlienateThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PHASE_ERROR_ALIENATE);
	//invite add loyaty
	dwWrData = (m_bFriendToAlienate == FALSE ? m_dwOldInviteAddLoyaty : m_dwInviteAddLoyaty);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInviteAddLoyatyAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_INVITE_ADD_LOYATY);
	//try invite captive
	dwWrData = (m_bFriendToAlienate == FALSE ? 0 : 1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTryInviteCaptiveThunk[dwWrData].dwAddr),\
									(LPVOID)(patchTryInviteCaptiveThunk[dwWrData].pCode), patchTryInviteCaptiveThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_TRY_INVITE_CAPTIVE);
	//phase error invite
	dwWrData = (m_bFriendToAlienate == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPhaseErrorInviteThunk[dwWrData].dwAddr),\
									(LPVOID)(patchPhaseErrorInviteThunk[dwWrData].pCode), patchPhaseErrorInviteThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PHASE_ERROR_INVITE);

	//update water killer prop
	dwWrData = (m_bUpdateWaterKillerProp == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWaterKillerPropThunk[dwWrData].dwAddr),\
									(LPVOID)(patchWaterKillerPropThunk[dwWrData].pCode), patchWaterKillerPropThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_WATER_KILLER_PROP);

	//ability killer prop
	dwWrData = (m_bAbilityKillerProp  == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAbilityKillerPropThunk[dwWrData].dwAddr),\
									(LPVOID)(patchAbilityKillerPropThunk[dwWrData].pCode), patchAbilityKillerPropThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ABILITY_KILLER_PROP);

	//troop/building wound
	dwWrData = (m_bSubWoundSoldier == FALSE ? m_dwOldTroopWound : m_dwTroopWound);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopWoundAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_WOUND);
	dwWrData = (m_bSubWoundSoldier == FALSE ? m_dwOldBuildingWound : m_dwBuildingWound);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildingWoundAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_TROOP_WOUND);

	//change troop command
	dwWrData = (m_bChangeTroopCommand == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChangeTroopCommandThunk[dwWrData].dwAddr),\
									(LPVOID)(patchChangeTroopCommandThunk[dwWrData].pCode), patchChangeTroopCommandThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_CHANGE_TROOP_COMMAND);

	//npc allie attack
	dwWrData = (m_bNpcAllieAttack == FALSE ? 0 : 5);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPlayerCity+0x1A),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_ALLIE_ATTACK);
	dwWrData = (m_bNpcAllieAttack == FALSE ? 0 : 1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrAllieAttack+9),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_ALLIE_ATTACK);
	dwWrData = (m_bNpcAllieAttack == FALSE ? 0xEB : 0x75);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotAttackNearTroop+4),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_ALLIE_ATTACK);

	//disable npc plot force
	//dwWrData = (m_bDisableNpcPlotForce == FALSE ? m_dwOldDisableNpcPlotForce : m_dwDisableNpcPlotForce);
	dwWrData = m_dwDisableNpcPlotForce;
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableNpcPlotForceAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_NPC_PLOT_FORCE);

	//burn food
	dwWrData = (m_bBurnFood==FALSE ? m_dwOldBurnFoodProbability : m_dwBurnFoodProbability);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnFoodProbabilityAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BURN_BUILDING_FOOD);

	dwWrData = (m_bBurnFood==FALSE ? m_dwOldBurnFoodEffect : m_dwBurnFoodEffect);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnFoodEffectAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BURN_BUILDING_FOOD);

	dwWrData = (m_bBurnFood==FALSE ? m_dwOldBurnBuildingEffect : m_dwBurnBuildingEffect);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnBuildingEffectAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BURN_BUILDING_FOOD);

	//disable burn
	dwWrData = (m_bDisableBurn == FALSE ? 0x7F : 0x1E);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrNotAlienateGarbage[0]+0x0B),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_BURN);

	//disable subforce transport
	dwWrData = (m_bMunicipalDraft == FALSE ? 3 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrMainForceDispatch+0x29),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_SUBFORCE_TRANSPORT);

	//double building defense
	dwWrData = (m_bDoubleBuildingDefense == FALSE ? m_dwOldBuildingDefenseCoef : m_dwBuildingDefenseCoef);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildingDefenseCoefAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BUILDING_DEFENSE_COEF);

	//disable search event
	dwWrData = (m_bDisableSearchEvent==FALSE ? m_dwOldEventMeetHuaTuo : m_dwEventMeetHuaTuo);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEventMeetHuaTuoAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_SEARCH_EVENT);

	//sub rob food
	dwWrData = (m_bSubRobFood == FALSE ? 0 : 1);//sub_rob_food
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF1C),\
														(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SUB_ROB_FOOD);

	//dynamic add ability
	dwWrData = (m_bDynamicAddAbility == FALSE ? 0 : 6);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrDynamicAddProficiency+1),\
														(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DYNAMIC_ADD_ABILITY_FLAG);

	//dispatch soldier to player
	dwWrData = (m_bDispatchSoldierToPlayer == FALSE ? 0xEB : 0x74);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetForceDangerCoef+0x2D),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISPATCH_SOLDIER_TO_PLAYER);

	//sub counsellor judge
	dwWrData = (m_bSubCounsellorJudge == FALSE ? 1 : 3);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrPersonJudgement[1]+3),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SUB_COUNSELLOR_JUDGE);
	dwWrData = (m_bSubCounsellorJudge == FALSE ? 5 : 9);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonJudgementThunk[0].dwAddr + 0x1D),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SUB_COUNSELLOR_JUDGE);

	//add npc money food
	dwWrData = (m_bAddNpcMoneyFood == FALSE ? 0 : 1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF16),//add_npc_money_food
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ADD_NPC_MONEY_FOOD);

	//max ability
	dwWrData = (m_bSearchMaxAbility == FALSE ? m_dwOldMaxBasicAbility : m_dwMaxBasicAbility);
	//max search ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxSearchAbilityAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_SEARCh_ABILITY);
	//max basic ability
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BASIC_ABILITY);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x30),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BASIC_ABILITY);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x60),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BASIC_ABILITY);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x90),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MAX_BASIC_ABILITY);

	//not add draft
	dwWrData = (m_bNotAddDraft == FALSE ? 0 : 1);//not_add_draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF17),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_ADD_DRAFT);

	//alike killer linkage
	dwWrData = (m_bAlikeKillerLinkage == FALSE ? 0 : 0xE);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrJudgeKillerLinkage+1),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALIKE_KILLER_LINKAGE);

	//enable baram array
	dwWrData = (m_bEnableBaramArray == FALSE ? 0xC3 : 0x56);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrUseBaramArray),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_BARAM_ARRAY);

	//enable relay dispatch
	dwWrData = (m_bEnableRelayDispatch == FALSE ? 0xEB : 0x75);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrRelayFailedDispatch+0x14),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_RELAY_DISPATCH);

	//merge subforce
	dwWrData = (m_bDisableNpcPlotForce == FALSE ? 0 : 1);//merge_subforce
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F4CD),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_NPC_PLOT_FORCE);

	//weaken long range liller
	dwWrData = (m_bWeakenLongRangeKiller == FALSE ? 0xC3 : 0x56);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrWeakenLongRangeKiller),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_WEAKEN_LONG_RANGE_KILLER_FLAG);

	//municipal force draft
	dwWrData = (m_bMunicipalForceDraft == FALSE ? m_dwOldMunicipalForceDraft : m_dwMunicipalForceDraft);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMunicipalForceDraftAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MUNICIPAL_FORCE_DRAFT);
	//subforce troop/building control
	dwWrData = (m_bMunicipalForceDraft == FALSE ? m_dwOldSubforceControl : m_dwSubforceControl);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSubforceTroopControlAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SUBFORCE_CONTROL);	
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSubforceBuildingControlAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SUBFORCE_CONTROL);

	//min durability zero
	dwWrData = (m_bMinDurabilityZero==FALSE ? 0 : 1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDurabilityThunk[dwWrData].dwAddr),\
							(LPVOID)(patchMinDurabilityThunk[dwWrData].pCode), patchMinDurabilityThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_MIN_DURABILITY);

	//fight killer prop
	dwWrData = (m_bFightKillerProp == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightToKillerThunk[dwWrData].dwAddr),\
					(LPVOID)(patchFightToKillerThunk[dwWrData].pCode), patchFightToKillerThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_FIGHT_TO_KILLER);

	//not sure captive
	dwWrData = (m_bNotSureCaptive == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotSureCaptiveThunk[dwWrData].dwAddr),\
					(LPVOID)(patchNotSureCaptiveThunk[dwWrData].pCode), patchNotSureCaptiveThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_NOT_SURE_CAPTIVE);

	//goose killer linkage
	dwWrData = (m_bGooseKillerLinkage == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGooseKillerLinkageThunk[dwWrData].dwAddr),\
					(LPVOID)(patchGooseKillerLinkageThunk[dwWrData].pCode), patchGooseKillerLinkageThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_GOOSE_KILLER_LINKAGE);
	//block array num
	dwWrData = (m_bGooseKillerLinkage == FALSE ? m_dwOldBlockArrayNum : m_dwBlockArrayNum);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBlockArrayNumAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BLOCK_ARRAY_NUM);
	//null city sub municipal
	dwWrData = (m_bNullCitySubMunicipal == FALSE ? 0 : 1);//null_city_sub_municipal
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43F4CE),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NULL_CITY_SUB_MUNICIPAL);

	//npc search treasure
	dwWrData = (m_bNpcSearchTreasure == FALSE ? m_dwOldNpcSearchTreasure : m_dwNpcSearchTreasure);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNpcSearchTreasureAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_SEARCH_TREASURE);
	dwWrData = (m_bNpcSearchTreasure == FALSE ? m_dwOldNpcDisplayTreasure : m_dwNpcDisplayTreasure);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNpcDisplayTreasureAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_SEARCH_TREASURE);

	//soldier sub killer
	dwWrData = (m_bSoldierSubKiller == FALSE ? 0x02EB : 0xF1F7);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrSoldierCommandKiller+0x21),\
									(LPVOID)(&dwWrData), WORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_SOLDIER_COMMAND_KILLER_FLAG);

	//npc auto draft
	dwWrData = (m_bNpcAutoDraft == FALSE ? 0 : 1);//npc_auto_draft
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF18),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NPC_AUTO_DRAFT);

	//player auto process
	dwWrData = (m_bPlayerAutoProcess == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPlayerAutoProcessThunk[dwWrData].dwAddr),\
									(LPVOID)(patchPlayerAutoProcessThunk[dwWrData].pCode), patchPlayerAutoProcessThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_PLAYER_AUTO_PROCESS);

	//low durability chaos
	dwWrData = (m_bLowDurabilityChaos == FALSE ? 0 : 1);//low_durability_chaos
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(0x43FF1B),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_LOW_DURABILITY_CHAOS);

	//leader inspire
	dwWrData = (m_bLeaderInspire == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeaderInspireThunk[dwWrData].dwAddr),\
									(LPVOID)(patchLeaderInspireThunk[dwWrData].pCode), patchLeaderInspireThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_LEADER_INSPIRE);

	//disable kill person
	dwWrData = (m_bDisableKillPerson == FALSE ? m_dwOldKillPersonProp : m_dwKillPersonProp);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwKillPersonPropAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_KILL_PERSON);

	//kill add proficiency
	//battle experience
	dwWrData = (m_bKillAddProficiency == FALSE ? m_dwBattleExperienceOldCode : m_dwBattleExperienceCode);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBattleExperienceAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BATTLE_EXPERIENCE);
	//water experience
	dwWrData = (m_bKillAddProficiency == FALSE ? m_dwWaterExperienceOldCode : m_dwWaterExperienceCode);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwWaterExperienceAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_WATER_EXPERIENCE);

	//disable move person
	dwWrData = (m_bDisableMovePerson == FALSE ? m_dwOldEnableGoMenu : m_dwEnableGoMenu);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableGoMenuAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_GO_MENU);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableComeMenuAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_GO_MENU);

	//general dead
	dwWrData = (m_bGeneralDead == FALSE ? m_dwOldGeneralDead : m_dwGeneralDead);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead1Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead2Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead3Addr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ALL_PERSON_DEAD);

	//barbarian not disappear
	dwWrData = (m_bBarbarianNotDisappear == FALSE ? m_dwOldBarbarianNotDisappear1 : m_dwBarbarianNotDisappear1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr1),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BARBARIAN_NOT_DISAPPEAR);
	dwWrData = (m_bBarbarianNotDisappear == FALSE ? m_dwOldBarbarianNotDisappear1 : m_dwBarbarianNotDisappear2);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr2),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BARBARIAN_NOT_DISAPPEAR);	
	dwWrData = (m_bBarbarianNotDisappear == FALSE ? m_dwOldBarbarianNotDisappear3 : m_dwBarbarianNotDisappear3);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr3),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_BARBARIAN_NOT_DISAPPEAR);	
	
	//add killer jianyu
	dwWrData = (m_bAddKillerJianyu == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddWaterKillerThunk[dwWrData].dwAddr),\
									(LPVOID)(patchAddWaterKillerThunk[dwWrData].pCode), patchAddWaterKillerThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_ADD_WATER_KILLER);	
	dwWrData = (m_bAddKillerJianyu == FALSE ? 5 : 1);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrEnableWaterKiller+9),\
														(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ADD_KILLER_JIANYU);	

	//disable killer jianlan
	dwWrData = (m_bDisableKillerJianlan == FALSE ? 6 : 5);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrEnableWaterKiller+4),\
														(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_KILLER_JIANLAN);
	dwWrData = (m_bDisableKillerJianlan == FALSE ? 1 : 0);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackShipThunk[dwWrData].dwAddr),\
									(LPVOID)(patchSelectAttackShipThunk[dwWrData].pCode), patchSelectAttackShipThunk[dwWrData].dwSize, NULL);
	CHECK_ERROR(ERR_WRITE_THUNK_SELECT_ATTACK_SHIP);

    //not display slash	
	dwWrData = (m_bNotDisplaySlash == FALSE ? m_dwOldNotDisplaySlash : m_dwNotDisplaySlash);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplaySlashAddr),\
									(LPVOID)(&dwWrData), WORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_DISPLAY_SLASH);

	//not display exchange dialog
	dwWrData = (m_bNotDisplayExchange == FALSE ? m_dwOldNotDisplayExchange : m_dwNotDisplayExchange);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplayExchangeAddr1),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_DISPLAY_EXCHANGE);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplayExchangeAddr2),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_NOT_DISPLAY_EXCHANGE)	

	//enable city population coef
	dwWrData = (m_bEnableCityPopulationCoef == FALSE ? 0xC3 : 0x0F);	
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrCityPopulationCoef+6),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_ENABLE_CITY_POPULATION_COEF);	
//war fog
	//war fog door
	dwWrData = (m_bWarFog == 0 ? 0x16EB : 0xD233);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddrGetPlayerForce),\
									(LPVOID)(&dwWrData), WORD_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_WAR_FOG_DOOR);
	//disable burn explorer
	dwWrData = (m_bWarFog == 0 ? m_dwOldDisableBurnExplorer : m_dwDisableBurnExplorer);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableBurnExplorerAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_BURN_EXPLORER);
	//disable attack explorer
	dwWrData = (m_bWarFog == 0 ? m_dwOldDisableAttackExplorer : m_dwDisableAttackExplorer);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableAttackExplorerAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_DISABLE_ATTACK_EXPLORER);
	//mask person where
	dwWrData = (m_bWarFog == 0 ? m_dwOldMaskPersonWhere : m_dwMaskPersonWhere);
	bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaskPersonWhereAddr),\
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	CHECK_ERROR(ERR_WRITE_MASK_PERSON_WHERE);

///////////////////////////////////////////////////////////////////////////////
// modify_setting 和 modify_data 的共享部分
modify_data:

//都市配置信息
	if (m_bCityConfigAuto != FALSE || m_bCityConfigRead != FALSE)//配置信息已读取
	{
		m_bCityConfigRead = FALSE;//都市配置读取标志=0
		for (i=0; i<CITY_NUM; i++)
		{
			//都市最大士兵数
			dwWrData = m_CityConfigInfo[i].btMaxSoldier;
			if (dwWrData>50) dwWrData = 50;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCityMaxSoldierAddr+i),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			//都市最大民心
			dwWrData = m_CityConfigInfo[i].btMaxPeopleHeart;
			if (dwWrData>10) dwWrData = 10;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCityMaxPeopleHeartAddr+i),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			dwAddr = CITY_ADDR + i*CITY_SIZE;//都市起始地址
			//都市兵法
			dwRdData = m_CityConfigInfo[i].btFlag&0xF;//都市兵法序号
			dwWrData = (dwRdData<=2 ? (1<<(dwRdData+1)) : 0);//齐射
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x51),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			if (dwRdData<=2) goto write_city_stone;
			dwWrData = (dwRdData==3 ? 0x80 : 0);//混乱
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x52),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			if (dwRdData==3)  goto write_city_stone;
			dwWrData = 1<<(dwRdData-4);//陷阱~妖术
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x53),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
		write_city_stone:
			dwWrData = ((m_CityConfigInfo[i].btFlag>>4)&1)<<7;//都市落石
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x54),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			dwWrData = (m_CityConfigInfo[i].btFlag>>5)&1;//都市射台
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x55),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			//都市商人常驻
			bSuccess = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x1E0),\
											(LPVOID)(&dwRdData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_READ_CITY_CONFIG_INFO);
			dwWrData = dwRdData | ((m_CityConfigInfo[i].btFlag>>7)&1);
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x1E0),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			dwWrData = m_CityConfigInfo[i].btMaxIncome;//都市最大收益
			if (dwWrData>10) dwWrData = 10;
			dwWrData *= 100;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x1D4),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			dwWrData = m_CityConfigInfo[i].btMaxHarvest;//都市最大收获
			if (dwWrData>10) dwWrData = 10;
			dwWrData *= 100;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x1D8),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
			dwWrData = m_CityConfigInfo[i].btMaxDurability;//都市最大耐久
			if (dwWrData>15) dwWrData = 15;
			dwWrData *= 100;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x1C8),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
		}
	}
	else if (modifyFlag == MODIFY_ROUTINE)
	{
		//reset city max soldier and people heart in buffer
		for (i=0; i<CITY_NUM; i++)
		{
			m_CityConfigInfo[i].btMaxSoldier = m_btInitCityMaxSoldier[i];
			m_CityConfigInfo[i].btMaxPeopleHeart = m_btInitCityMaxPeopleHeart[i];
		}
		//reset city max soldier in game
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCityMaxSoldierAddr),\
								(LPVOID)(m_btInitCityMaxSoldier), sizeof(m_btInitCityMaxSoldier), NULL);
		CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
		//reset city max people heart in game
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCityMaxPeopleHeartAddr),\
								(LPVOID)(m_btInitCityMaxPeopleHeart), sizeof(m_btInitCityMaxPeopleHeart), NULL);
		CHECK_ERROR(ERR_WRITE_CITY_CONFIG_INFO);
	}

//兵法配置信息
	if ((m_btKillerConfigRead&3) != 0)//兵法配置已读取
	{
		m_btKillerConfigRead &= ~2;//兵法配置读取标志=0
		for (i=0; i<KILLER_NUM; i++)
		{
			dwAddr = KILLER_ADDR + i*KILLER_SIZE;//兵法起始地址
			//威力
			dwWrData = m_KillerConfigInfo[i].btPower;
			if (dwWrData>30) dwWrData = 30;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x64),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_KILLER_CONFIG_INFO);
			//间隔
			dwWrData = m_KillerConfigInfo[i].btInterval;
			if (dwWrData>30) dwWrData = 30;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x7C),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_KILLER_CONFIG_INFO);
			//习得熟练度
			dwWrData = m_KillerConfigInfo[i].wrLearnProficiency;
			if (dwWrData>1500) dwWrData = 1500;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x58),\
											(LPVOID)(&dwWrData), DWORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_KILLER_CONFIG_INFO);
		}
	}

//阵型配置信息
	if ((m_btArrayConfigRead&3) != 0)//阵型配置已读取
	{
		m_btArrayConfigRead &= ~2;//阵型配置读取标志=0
		for (i=0; i<ARRAY_NUM; i++)
		{
			dwAddr = ARRAY_ADDR + i*ARRAY_SIZE;//阵型起始地址
			//对部队
			dwWrData = m_ArrayConfigInfo[i].dwAttackDefence&0x3F;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x60),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//对守兵
			dwWrData = (m_ArrayConfigInfo[i].dwAttackDefence>>6)&0x3F;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x64),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//对城壁
			dwWrData = (m_ArrayConfigInfo[i].dwAttackDefence>>12)&0x3F;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x68),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//守备力
			dwWrData = (m_ArrayConfigInfo[i].dwAttackDefence>>18)&0x3F;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x6C),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//机动力
			dwWrData = (m_ArrayConfigInfo[i].dwAttackDefence>>24)&0x3F;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x5C),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//射程
			dwWrData = m_ArrayConfigInfo[i].wrView&0xF;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAddrArrayAttackRange+i),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//视距
			dwWrData = (m_ArrayConfigInfo[i].wrView>>4)&0xF;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x70),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//视角
			dwWrData = (m_ArrayConfigInfo[i].wrView>>8)&0xF;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x74),\
											(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
			//费用
			dwWrData = m_ArrayConfigInfo[i].wrExpense;
			bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(dwAddr+0x78),\
											(LPVOID)(&dwWrData), WORD_SIZE, NULL);
			CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
		}
	}
	else if (modifyFlag == MODIFY_ROUTINE)
	{
		//复位阵型射程
		for (i=0; i<ARRAY_NUM; i++)
		{
			m_ArrayConfigInfo[i].wrView = m_btInitArrayAttackRange[i];
		}
		//写阵型射程到游戏内存
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAddrArrayAttackRange),\
										(LPVOID)(&m_btInitArrayAttackRange), sizeof(m_btInitArrayAttackRange), NULL);
		CHECK_ERROR(ERR_WRITE_ARRAY_CONFIG_INFO);
	}

//地域所属都市
	if (m_bUpdateZoneCity != FALSE)
	{
		bSuccess = UpdateZoneCity(m_bUpdateZoneCity);
		CHECK_ERROR(ERR_WRITE_ZONE_FROM_CITY);
	}

//////////////////////////////////////////////////////////////////////////////////////
modify_routine:

	m_iDisplayCount++;

	if (m_iDisplayCount<1)//等待错误显示完成
		return;

	str.Format("正在监控游戏(%d)", m_iErrCount);
	for (i = m_iDisplayCount; i>1; i--)
	{
		str += "·";
	}
	if (m_iDisplayCount == 6)
	{
		m_iDisplayCount = 0;//回到初始状态
	}
	
	goto display_info;

end_of_operation:
	str.Format("%d : error=%d", dwWrData, ::GetLastError());
	++m_iErrCount;
	m_iDisplayCount = -8;//错误显示停留9秒

display_info:
	m_ctrlStatus.SetWindowText(str);
}

void CSan9PKHardDlg::UndoModify()
{
	DWORD dwAddr = 0, dwWrData = 0;
	HWND hWnd = NULL;

	//check San9PK
	hWnd = ::FindWindow("KOEI_SAN9WINDOW", NULL);
	if (hWnd == NULL || m_hSan9PKWnd != hWnd)
	{//game not start or restart
		m_hSan9PKWnd = NULL;
		m_hSan9PKProcess = NULL;
		return;
	}

//data
	//地域所属都市
	if (m_bUpdateZoneCity != FALSE)
	{
		UpdateZoneCity(FALSE);
	}

	//武将亲密度表
	WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAddrPersonFriendship),\
									(LPVOID)(m_wOldPersonFriendship), sizeof(m_wOldPersonFriendship), NULL);

	//官爵“无”的薪水
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoneOfficialSalaryAddr),
									(LPVOID)(&m_dwOldNoneOfficialSalary), BYTE_SIZE, NULL);

//code
	//not display exchange
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplayExchangeAddr1),\
									(LPVOID)(&m_dwOldNotDisplayExchange), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplayExchangeAddr2),\
									(LPVOID)(&m_dwOldNotDisplayExchange), BYTE_SIZE, NULL);
									
    //not display slash
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotDisplaySlashAddr),\
									(LPVOID)(&m_dwOldNotDisplaySlash), WORD_SIZE, NULL);	
	//barbarian not disappear
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr3),\
									(LPVOID)(&m_dwOldBarbarianNotDisappear3), BYTE_SIZE, NULL);	
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr2),\
									(LPVOID)(&m_dwOldBarbarianNotDisappear1), BYTE_SIZE, NULL);	
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBarbarianNotDisappearAddr1),\
									(LPVOID)(&m_dwOldBarbarianNotDisappear1), BYTE_SIZE, NULL);										

    //block array num
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBlockArrayNumAddr),\
									(LPVOID)(&m_dwOldBlockArrayNum), BYTE_SIZE, NULL);	
	//general dead
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead1Addr),\
									(LPVOID)(&m_dwOldGeneralDead), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead2Addr),\
									(LPVOID)(&m_dwOldGeneralDead), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGeneralDead3Addr),\
									(LPVOID)(&m_dwOldGeneralDead), BYTE_SIZE, NULL);
	//disable move person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableComeMenuAddr),\
									(LPVOID)(&m_dwOldEnableGoMenu), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableGoMenuAddr),\
									(LPVOID)(&m_dwOldEnableGoMenu), BYTE_SIZE, NULL);
	//sex coef
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSexCoefAddr),\
									(LPVOID)(&m_dwOldSexCoef), BYTE_SIZE, NULL);
	//disable kill person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwKillPersonPropAddr),\
									(LPVOID)(&m_dwOldKillPersonProp), BYTE_SIZE, NULL);
	//league time
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLeagueTimeAddr),\
									(LPVOID)(&m_dwOldLeagueTime), BYTE_SIZE, NULL);
	//update goal prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwUpdateGoalPropAddr),\
									(LPVOID)(&m_dwOldUpdateGoalProp), BYTE_SIZE, NULL);
	//update goal force
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwUpdateGoalForceAddr),\
									(LPVOID)(&m_dwOldUpdateGoalForce), BYTE_SIZE, NULL);
	//build min building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildMinBuildingAddr),\
									(LPVOID)(&m_dwOldBuildMinBuilding), BYTE_SIZE, NULL);
	//game end year
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGameEndYearAddr),\
									(LPVOID)(&m_dwOldGameEndYear), DWORD_SIZE, NULL);
	//build max arrive day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildMaxArriveDayAddr),\
									(LPVOID)(&m_dwOldBuildMaxArriveDay), BYTE_SIZE, NULL);
	//attack build force
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAttackBuildForceAddr),\
									(LPVOID)(&m_dwOldAttackBuildForce), BYTE_SIZE, NULL);
	//部队武将数兵法概率系数
	dwWrData = 20;
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	dwWrData = 14;
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+8),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	dwWrData = 10;
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+16),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	dwWrData = 9;
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+24),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	dwWrData = 8;
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwPersonNumKillerPropAddr+32),
									(LPVOID)(&dwWrData), BYTE_SIZE, NULL);
	//search no result
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSearchNoResultAddr),\
									(LPVOID)(&m_dwOldSearchNoResult), BYTE_SIZE, NULL);
	//mask person where
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaskPersonWhereAddr),\
									(LPVOID)(&m_dwOldMaskPersonWhere), BYTE_SIZE, NULL);
	//disable attack explorer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableAttackExplorerAddr),\
									(LPVOID)(&m_dwOldDisableAttackExplorer), BYTE_SIZE, NULL);
	//disable burn explorer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableBurnExplorerAddr),\
									(LPVOID)(&m_dwOldDisableBurnExplorer), BYTE_SIZE, NULL);
	//noarray to building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoarrayToBuildingAddr2),\
									(LPVOID)(&m_dwOldNoarrayToBuilding), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNoarrayToBuildingAddr),\
									(LPVOID)(&m_dwOldNoarrayToBuilding), BYTE_SIZE, NULL);
	//counselor min candidate
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCounselorMinCandidateAddr),\
									(LPVOID)(&m_dwOldCounselorMinCandidate), BYTE_SIZE, NULL);
	//transport goal info
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTransportGoalInfoAddr),\
									(LPVOID)(&m_dwOldTransportGoalInfo), DWORD_SIZE, NULL);
	//year table invalid flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwYearTableInvalidFlagAddr),\
									(LPVOID)(&m_dwOldYearTableInvalidFlag), BYTE_SIZE, NULL);
	//event meet hua tuo
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEventMeetHuaTuoAddr),\
									(LPVOID)(&m_dwOldEventMeetHuaTuo), BYTE_SIZE, NULL);
	//not get person quota
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotGetPersonQuotaAddr),\
									(LPVOID)(&m_dwOldNotGetPersonQuota), BYTE_SIZE, NULL);
	//invite add loyaty
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInviteAddLoyatyAddr),\
									(LPVOID)(&m_dwOldInviteAddLoyaty), BYTE_SIZE, NULL);
	//troop goal building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopGoalBuildingAddr),\
									(LPVOID)(&m_dwOldTroopGoalBuilding), DWORD_SIZE, NULL);
	//enable second killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwEnableSecondKillerAddr),\
									(LPVOID)(&m_dwOldEnableSecondKiller), BYTE_SIZE, NULL);
	//lvbu attack door
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLvbuAttackDoorAddr),\
									(LPVOID)(&m_dwOldLvbuAttackDoor), BYTE_SIZE, NULL);
	//show sex map
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwShowSexMapAddr),\
									(LPVOID)(&m_dwOldShowSexMap), BYTE_SIZE, NULL);
	//slash dead coef
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSlashDeadCoefAddr),\
									(LPVOID)(&m_dwOldSlashDeadCoef), BYTE_SIZE, NULL);
	//show celue killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwShowCelueKillerAddr),\
									(LPVOID)(&m_dwOldShowCelueKiller), sizeof(m_dwOldShowCelueKiller), NULL);
	//intelligence officer end flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwIntelligenceOfficerEndFlagAddr),\
									(LPVOID)(&m_dwOldIntelligenceOfficerEndFlag), BYTE_SIZE, NULL);
	//command officer end flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCommandOfficerEndFlagAddr),\
									(LPVOID)(&m_dwOldCommandOfficerEndFlag), BYTE_SIZE, NULL);
	//invite sub loyaty
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInviteSubLoyatyAddr),\
									(LPVOID)(&m_dwOldInviteSubLoyaty), BYTE_SIZE, NULL);
	//not attack only building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNotAttackOnlyBuildingAddr),\
									(LPVOID)(&m_dwOldNotAttackOnlyBuilding), DWORD_SIZE, NULL);
	//declare attack troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDeclareAttackTroopAddr),\
									(LPVOID)(&m_dwOldDeclareAttackTroop), BYTE_SIZE, NULL);
	//disorder anti troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisorderAntiTroopAddr),\
									(LPVOID)(&m_dwExternalAntiTroop), DWORD_SIZE, NULL);
	//false anti troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwFalseAntiTroopAddr),\
									(LPVOID)(&m_dwInternalAntiTroop), DWORD_SIZE, NULL);
	//troop from building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopFromBuildingAddr),\
									(LPVOID)(&m_dwOldTroopFromBuilding), BYTE_SIZE, NULL);
	//bad brothers array end
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBadBrothersArrayEndAddr),\
									(LPVOID)(&m_dwOldBadBrothersArrayEnd), DWORD_SIZE, NULL);
	//goal to source damage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoalToSourceDamageAddr),\
									(LPVOID)(&m_dwOldGoalToSourceDamage), BYTE_SIZE, NULL);
	//get troop goal bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGetTroopGoalBugAddr),\
									(LPVOID)(&m_dwOldGetTroopGoalBug), DWORD_SIZE, NULL);
	//double building defense
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildingDefenseCoefAddr),\
									(LPVOID)(&m_dwOldBuildingDefenseCoef), BYTE_SIZE, NULL);
	//avoid induce max day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAvoidInduceMaxDayAddr),\
									(LPVOID)(&m_dwOldAvoidInduceMaxDay), BYTE_SIZE, NULL);
	//home force door
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwHomeForceDoorAddr),\
									(LPVOID)(&m_dwOldHomeForceDoor), BYTE_SIZE, NULL);
	//dialog max food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDialogMaxFoodAddr),\
									(LPVOID)(&m_dwOldLoadMaxFood), DWORD_SIZE, NULL);									
	//forecast max food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwForecastMaxFoodAddr),\
									(LPVOID)(&m_dwOldLoadMaxFood), DWORD_SIZE, NULL);									
	//donate max food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDonateMaxFoodAddr),\
									(LPVOID)(&m_dwOldLoadMaxFood), DWORD_SIZE, NULL);
	//burn building effect
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnBuildingEffectAddr),\
									(LPVOID)(&m_dwOldBurnBuildingEffect), BYTE_SIZE, NULL);
	//burn food effect
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnFoodEffectAddr),\
									(LPVOID)(&m_dwOldBurnFoodEffect), BYTE_SIZE, NULL);
	//burn food probability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnFoodProbabilityAddr),\
									(LPVOID)(&m_dwOldBurnFoodProbability), BYTE_SIZE, NULL);
	//subforce troop/building control
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSubforceTroopControlAddr),\
									(LPVOID)(&m_dwOldSubforceControl), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSubforceBuildingControlAddr),\
									(LPVOID)(&m_dwOldSubforceControl), BYTE_SIZE, NULL);								
	//municipal force draft
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMunicipalForceDraftAddr),\
									(LPVOID)(&m_dwOldMunicipalForceDraft), BYTE_SIZE, NULL);
	//attack ignore antitrap
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAttackIgnoreAntitrapAddr),\
									(LPVOID)(&m_dwOldAttackIgnoreAntitrap), BYTE_SIZE, NULL);
	//disable npc plot force
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisableNpcPlotForceAddr),\
									(LPVOID)(&m_dwOldDisableNpcPlotForce), BYTE_SIZE, NULL);
	//same force troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSameForceTroopAddr),\
									(LPVOID)(&m_dwOldSameForceTroop), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSameForceTroopAddr2),\
									(LPVOID)(&m_dwOldSameForceTroop), BYTE_SIZE, NULL);
	//neglect chong che
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNeglectChongCheAddr),\
									(LPVOID)(&m_dwOldNeglectChongChe), BYTE_SIZE, NULL);
	//select clever killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSelectCleverKillerAddr),\
									(LPVOID)(&m_dwOldSelectCleverKiller), BYTE_SIZE, NULL);
	//retreat min vigour
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRetreatMinVigourAddr),\
									(LPVOID)(&m_dwOldRetreatMinVigour), BYTE_SIZE, NULL);
	//avoid near city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAvoidNearCityAddr),\
									(LPVOID)(&m_dwOldAvoidNearCity), WORD_SIZE, NULL);
	//null buliding danger
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNullBulidingDangerAddr),\
									(LPVOID)(&m_dwOldNullBulidingDanger), BYTE_SIZE, NULL);
	//goal null city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGoalNullCityAddr),\
									(LPVOID)(&m_dwOldGoalNullCity), DWORD_SIZE, NULL);
	//gossip no alienate
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipNoAlienateAddr),\
									(LPVOID)(&m_dwOldGossipNoAlienate), BYTE_SIZE, NULL);
	//gossip sub loyalty
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipSubLoyaltyAddr),\
									(LPVOID)(&m_dwOldGossipSubLoyalty), BYTE_SIZE, NULL);
	//troop/building wound
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildingWoundAddr),\
									(LPVOID)(&m_dwOldBuildingWound), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTroopWoundAddr),\
									(LPVOID)(&m_dwOldTroopWound), BYTE_SIZE, NULL);
	//load max food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLoadMaxFoodAddr),\
									(LPVOID)(&m_dwOldLoadMaxFood), DWORD_SIZE, NULL);
	//max search ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxSearchAbilityAddr),\
									(LPVOID)(&m_dwOldMaxBasicAbility), BYTE_SIZE, NULL);
	//max basic ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr),\
									(LPVOID)(&m_dwOldMaxBasicAbility), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x30),\
									(LPVOID)(&m_dwOldMaxBasicAbility), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x60),\
									(LPVOID)(&m_dwOldMaxBasicAbility), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwMaxBasicAbilityAddr+0x90),\
									(LPVOID)(&m_dwOldMaxBasicAbility), BYTE_SIZE, NULL);
	//all person dead
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead1Addr),\
									(LPVOID)(&m_dwOldAllPersonDead), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead2Addr),\
									(LPVOID)(&m_dwOldAllPersonDead), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonDead3Addr),\
									(LPVOID)(&m_dwOldAllPersonDead), BYTE_SIZE, NULL);
	//inspire max vigour
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInspireMaxVigourAddr),\
									(LPVOID)(&m_dwOldInspireMaxVigour), BYTE_SIZE, NULL);
	//foot anti elephant
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwFootAntiElephantAddr),\
									(LPVOID)(&m_dwOldFootAntiElephant), DWORD_SIZE, NULL);
	//npc search treasure
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNpcDisplayTreasureAddr),\
									(LPVOID)(&m_dwOldNpcDisplayTreasure), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwNpcSearchTreasureAddr),\
									(LPVOID)(&m_dwOldNpcSearchTreasure), BYTE_SIZE, NULL);
	//search min politics
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSearchMinPoliticsAddr),\
									(LPVOID)(&m_dwOldSearchMinPolitics), BYTE_SIZE, NULL);
	//all person live
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAllPersonLiveAddr),\
									(LPVOID)(&m_dwOldAllPersonLive), BYTE_SIZE, NULL);
	//check league probability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCheckLeagueProbabilityAddr),\
									(LPVOID)(&m_dwOldCheckLeagueProbability), BYTE_SIZE, NULL);
	//officer basic intelligence and politics
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwOfficerBasicIntAddr),\
									(LPVOID)(&m_dwOldOfficerBasicInt), DWORD_SIZE, NULL);
	//officer basic command
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwOfficerBasicCommandAddr),\
									(LPVOID)(&m_dwOldOfficerBasicCommand), BYTE_SIZE, NULL);
	//save base
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwSaveBaseAddr),\
									(LPVOID)(&m_dwOldSaveBase), BYTE_SIZE, NULL);
	//anti min troop soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiMinTroopSoldierAddr),\
									(LPVOID)(&m_dwOldAntiMinTroopSoldier), DWORD_SIZE, NULL);
	//alienate force name
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAlienateForceNameAddr),\
									(LPVOID)(&m_dwOldAlienateForceName), BYTE_SIZE, NULL);
	//antiattack assistant
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackAssistantAddr),\
									(LPVOID)(&m_dwOldAntiAttackAssistant), DWORD_SIZE, NULL);
	//antiattack barbarism
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackBarbarismAddr),\
									(LPVOID)(&m_dwOldAntiAttackBarbarism), BYTE_SIZE, NULL);
	//antiattack min soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAntiAttackMinSoldierdAddr),\
									(LPVOID)(&m_dwOldAntiAttackMinSoldier), DWORD_SIZE, NULL);
	//build experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBuildExperienceAddr),\
									(LPVOID)(&m_dwBuildExperienceOldCode), BYTE_SIZE, NULL);
	//disorder intelligenc experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDisorderIntelligenceAddr),\
									(LPVOID)(&m_dwDisorderIntelligenceOldCode), BYTE_SIZE, NULL);
	//cheat intelligenc experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCheatIntelligenceAddr),\
									(LPVOID)(&m_dwCheatIntelligenceOldCode), BYTE_SIZE, NULL);
	//inspire intelligenc experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwInspireIntelligenceAddr),\
									(LPVOID)(&m_dwInspireIntelligenceOldCode), BYTE_SIZE, NULL);
	//gossip intelligenc experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwGossipIntelligenceAddr),\
									(LPVOID)(&m_dwGossipIntelligenceOldCode), BYTE_SIZE, NULL);
	//alienate intelligenc experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwAlienateIntelligenceAddr),\
									(LPVOID)(&m_dwAlienateIntelligenceOldCode), BYTE_SIZE, NULL);
	//lower trap
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLowerTrapAddr), (LPVOID)(&m_dwOldLowerTrickCoef), BYTE_SIZE, NULL);
	//wisdom resist trick
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwWisdomResistTrickAddr),\
									(LPVOID)(&m_dwOldWisdomResistTrickCoef), BYTE_SIZE, NULL);
	//lower trick
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwLowerTrickAddr), (LPVOID)(&m_dwOldLowerTrickCoef), BYTE_SIZE, NULL);
	//chaos day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwChaosDayAddr),\
									(LPVOID)(&m_dwOldChaosDayCoef), DWORD_SIZE, NULL);
	//dispatch ship
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDispatchShipAddr),\
									(LPVOID)(&m_dwOldDispatchShip), BYTE_SIZE, NULL);
	//dispatch array
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwDispatchArrayAddr),\
									(LPVOID)(&m_dwOldDispatchArray), BYTE_SIZE, NULL);
	//cultivate min politics
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwCultivateMinPoliticsAddr),\
									(LPVOID)(&m_dwOldCultivateMinPolitics), BYTE_SIZE, NULL);
	//repair experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRepairExperienceAddr),\
									(LPVOID)(&m_dwRepairExperienceOldCode), DWORD_SIZE, NULL);
	//train experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainExperienceAddr),\
									(LPVOID)(&m_dwTrainExperienceOldCode), DWORD_SIZE, NULL);
	//reinforce experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwReinforceExperienceAddr),\
									(LPVOID)(&m_dwReinforceExperienceOldCode), DWORD_SIZE, NULL);
	//rob experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwRobExperienceAddr),\
									(LPVOID)(&m_dwRobExperienceOldCode), DWORD_SIZE, NULL);
	//burn experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBurnExperienceAddr),\
									(LPVOID)(&m_dwBurnExperienceOldCode), DWORD_SIZE, NULL);
	//water experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwWaterExperienceAddr),\
									(LPVOID)(&m_dwWaterExperienceOldCode), BYTE_SIZE, NULL);
	//battle experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwBattleExperienceAddr),\
									(LPVOID)(&m_dwBattleExperienceOldCode), BYTE_SIZE, NULL);
	//town killer function
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTownKillerAddr),
							(LPVOID)(&m_dwTownKillerOldFunction), DWORD_SIZE, NULL);
	//harbor killer function
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwHarborKillerAddr),
							(LPVOID)(&m_dwHarborKillerOldFunction), DWORD_SIZE, NULL);
	//train num
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainNumAddr), (LPVOID)(&m_dwOldTrainNum), BYTE_SIZE, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwTrainNumAddr2), (LPVOID)(&m_dwOldTrainNum), BYTE_SIZE, NULL);
//null thunk
	//goose killer linkage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGooseKillerLinkageThunk[1].dwAddr),\
									(LPVOID)(patchGooseKillerLinkageThunk[1].pCode), patchGooseKillerLinkageThunk[1].dwSize, NULL);
	//save troop display object
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveTroopDisplayObjectThunk[1].dwAddr),\
									(LPVOID)(patchSaveTroopDisplayObjectThunk[1].pCode), patchSaveTroopDisplayObjectThunk[1].dwSize, NULL);
	//transport match
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTransportMatchThunk[1].dwAddr),\
									(LPVOID)(patchTransportMatchThunk[1].pCode), patchTransportMatchThunk[1].dwSize, NULL);
	//init match step
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInitMatchStepThunk[1].dwAddr),\
									(LPVOID)(patchInitMatchStepThunk[1].pCode), patchInitMatchStepThunk[1].dwSize, NULL);
	//transport goal condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTransportGoalConditionThunk[1].dwAddr),\
									(LPVOID)(patchTransportGoalConditionThunk[1].pCode), patchTransportGoalConditionThunk[1].dwSize, NULL);
	//build min soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildMinSoldierThunk[1].dwAddr),\
									(LPVOID)(patchBuildMinSoldierThunk[1].pCode), patchBuildMinSoldierThunk[1].dwSize, NULL);
	//elephant anti killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchElephantAntiKillerThunk[1].dwAddr),\
									(LPVOID)(patchElephantAntiKillerThunk[1].pCode), patchElephantAntiKillerThunk[1].dwSize, NULL);
	//defence array scale
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayScaleThunk[1].dwAddr),\
									(LPVOID)(patchDefenceArrayScaleThunk[1].pCode), patchDefenceArrayScaleThunk[1].dwSize, NULL);
	//defence array wimble
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayWimbleThunk[1].dwAddr),\
									(LPVOID)(patchDefenceArrayWimbleThunk[1].pCode), patchDefenceArrayWimbleThunk[1].dwSize, NULL);
	//defence array arrow
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceArrayArrowThunk[1].dwAddr),\
									(LPVOID)(patchDefenceArrayArrowThunk[1].pCode), patchDefenceArrayArrowThunk[1].dwSize, NULL);
	//league low prestige
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueLowPrestigeThunk[1].dwAddr),\
							(LPVOID)(patchLeagueLowPrestigeThunk[1].pCode), patchLeagueLowPrestigeThunk[1].dwSize, NULL);
//message
	//unthunk change_interface
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChangeInterfaceThunk[1].dwAddr),\
							(LPVOID)(patchChangeInterfaceThunk[1].pCode), patchChangeInterfaceThunk[1].dwSize, NULL);
	//unthunk update end main
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateEndMainThunk[1].dwAddr),\
							(LPVOID)(patchUpdateEndMainThunk[1].pCode), patchUpdateEndMainThunk[1].dwSize, NULL);
	//unthunk update end play
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateEndPlayThunk[1].dwAddr),\
							(LPVOID)(patchUpdateEndPlayThunk[1].pCode), patchUpdateEndPlayThunk[1].dwSize, NULL);
//key process
	//unthunk go nodisplay
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoNodisplayThunk[1].dwAddr),\
					(LPVOID)(patchGoNodisplayThunk[1].pCode), patchGoNodisplayThunk[1].dwSize, NULL);
	//unthunk go fast
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoFastThunk[1].dwAddr),\
					(LPVOID)(patchGoFastThunk[1].pCode), patchGoFastThunk[1].dwSize, NULL);
	//unthunk message entry
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMessageEntryThunk[1].dwAddr),\
					(LPVOID)(patchMessageEntryThunk[1].pCode), patchMessageEntryThunk[1].dwSize, NULL);
//multi search
	//alienate counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchAlienateCounselorAdviseThunk[1].pCode), patchAlienateCounselorAdviseThunk[1].dwSize, NULL);
	//burn counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchBurnCounselorAdvise2Thunk[1].pCode), patchBurnCounselorAdvise2Thunk[1].dwSize, NULL);
	//burn counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchBurnCounselorAdviseThunk[1].pCode), patchBurnCounselorAdviseThunk[1].dwSize, NULL);
	//rob counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchRobCounselorAdvise2Thunk[1].pCode), patchRobCounselorAdvise2Thunk[1].dwSize, NULL);
	//rob counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchRobCounselorAdviseThunk[1].pCode), patchRobCounselorAdviseThunk[1].dwSize, NULL);
	//inspire counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchInspireCounselorAdvise2Thunk[1].pCode), patchInspireCounselorAdvise2Thunk[1].dwSize, NULL);
	//inspire counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchInspireCounselorAdviseThunk[1].pCode), patchInspireCounselorAdviseThunk[1].dwSize, NULL);
	//save counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchSaveCounselorAdvise2Thunk[1].pCode), patchSaveCounselorAdvise2Thunk[1].dwSize, NULL);
	//save counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchSaveCounselorAdviseThunk[1].pCode), patchSaveCounselorAdviseThunk[1].dwSize, NULL);
	//disorder counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchDisorderCounselorAdvise2Thunk[1].pCode), patchDisorderCounselorAdvise2Thunk[1].dwSize, NULL);
	//disorder counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchDisorderCounselorAdviseThunk[1].pCode), patchDisorderCounselorAdviseThunk[1].dwSize, NULL);
	//false counselor advise 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseCounselorAdvise2Thunk[1].dwAddr),\
					(LPVOID)(patchFalseCounselorAdvise2Thunk[1].pCode), patchFalseCounselorAdvise2Thunk[1].dwSize, NULL);
	//false counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchFalseCounselorAdviseThunk[1].pCode), patchFalseCounselorAdviseThunk[1].dwSize, NULL);
	//invite counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchInviteCounselorAdviseThunk[1].pCode), patchInviteCounselorAdviseThunk[1].dwSize, NULL);
	//search counselor advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchCounselorAdviseThunk[1].dwAddr),\
					(LPVOID)(patchSearchCounselorAdviseThunk[1].pCode), patchSearchCounselorAdviseThunk[1].dwSize, NULL);
	///////////////////////////////////////////////////
	//disorder multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchDisorderMultiSelectThunk[1].pCode), patchDisorderMultiSelectThunk[1].dwSize, NULL);
	//false multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchFalseMultiSelectThunk[1].pCode), patchFalseMultiSelectThunk[1].dwSize, NULL);
	//alienate multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchAlienateMultiSelectThunk[1].pCode), patchAlienateMultiSelectThunk[1].dwSize, NULL);
	//burn multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBurnMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchBurnMultiSelectThunk[1].pCode), patchBurnMultiSelectThunk[1].dwSize, NULL);
	//rob multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchRobMultiSelectThunk[1].pCode), patchRobMultiSelectThunk[1].dwSize, NULL);
	//save multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchSaveMultiSelectThunk[1].pCode), patchSaveMultiSelectThunk[1].dwSize, NULL);
	//invite multi select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteMultiSelectThunk[1].dwAddr),\
					(LPVOID)(patchInviteMultiSelectThunk[1].pCode), patchInviteMultiSelectThunk[1].dwSize, NULL);
	//invite perform
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInvitePerformThunk[1].dwAddr),\
					(LPVOID)(patchInvitePerformThunk[1].pCode), patchInvitePerformThunk[1].dwSize, NULL);
	//search perform
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchPerformThunk[1].dwAddr),\
					(LPVOID)(patchSearchPerformThunk[1].pCode), patchSearchPerformThunk[1].dwSize, NULL);
	//search select
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchSelectThunk[1].dwAddr),\
					(LPVOID)(patchSearchSelectThunk[1].pCode), patchSearchSelectThunk[1].dwSize, NULL);
	//search stop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchStopThunk[1].dwAddr),\
					(LPVOID)(patchSearchStopThunk[1].pCode), patchSearchStopThunk[1].dwSize, NULL);
//thunk
	//get troop index
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetTroopIndexThunk[1].dwAddr),\
									(LPVOID)(patchGetTroopIndexThunk[1].pCode), patchGetTroopIndexThunk[1].dwSize, NULL);
	//troop advise
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAdviseThunk[1].dwAddr),\
									(LPVOID)(patchTroopAdviseThunk[1].pCode), patchTroopAdviseThunk[1].dwSize, NULL);
	//troop index  
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopIndexThunk[1].dwAddr),\
									(LPVOID)(patchTroopIndexThunk[1].pCode), patchTroopIndexThunk[1].dwSize, NULL);
	//set troop index  
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetTroopIndexThunk[1].dwAddr),\
									(LPVOID)(patchSetTroopIndexThunk[1].pCode), patchSetTroopIndexThunk[1].dwSize, NULL);
	//skip contained dialog
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSkipContainedDialogThunk[1].dwAddr),\
									(LPVOID)(patchSkipContainedDialogThunk[1].pCode), patchSkipContainedDialogThunk[1].dwSize, NULL);
	//strength damage record
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStrengthDamageRecordThunk[1].dwAddr),\
									(LPVOID)(patchStrengthDamageRecordThunk[1].pCode), patchStrengthDamageRecordThunk[1].dwSize, NULL);
	//intelligence damage record
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceDamageRecordThunk[1].dwAddr),\
									(LPVOID)(patchIntelligenceDamageRecordThunk[1].pCode), patchIntelligenceDamageRecordThunk[1].dwSize, NULL);
	//heart attack damage 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHeartAttackDamage2Thunk[1].dwAddr),\
									(LPVOID)(patchHeartAttackDamage2Thunk[1].pCode), patchHeartAttackDamage2Thunk[1].dwSize, NULL);
	//heart attack damage 1
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHeartAttackDamage1Thunk[1].dwAddr),\
									(LPVOID)(patchHeartAttackDamage1Thunk[1].pCode), patchHeartAttackDamage1Thunk[1].dwSize, NULL);
	//investment
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInvestmentThunk[1].dwAddr),\
									(LPVOID)(patchInvestmentThunk[1].pCode), patchInvestmentThunk[1].dwSize, NULL);
	//auto adjust killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoAdjustKillerThunk[1].dwAddr),\
									(LPVOID)(patchAutoAdjustKillerThunk[1].pCode), patchAutoAdjustKillerThunk[1].dwSize, NULL);
	//select attack ship
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackShipThunk[1].dwAddr),\
									(LPVOID)(patchSelectAttackShipThunk[1].pCode), patchSelectAttackShipThunk[1].dwSize, NULL);
	//enable water killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableWaterKillerThunk[1].dwAddr),\
									(LPVOID)(patchEnableWaterKillerThunk[1].pCode), patchEnableWaterKillerThunk[1].dwSize, NULL);
	//add water killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddWaterKillerThunk[1].dwAddr),\
									(LPVOID)(patchAddWaterKillerThunk[1].pCode), patchAddWaterKillerThunk[1].dwSize, NULL);
	//get max captive
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetMaxCaptiveThunk[1].dwAddr),\
									(LPVOID)(patchGetMaxCaptiveThunk[1].pCode), patchGetMaxCaptiveThunk[1].dwSize, NULL);
	//set max captive
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetMaxCaptiveThunk[1].dwAddr),\
									(LPVOID)(patchSetMaxCaptiveThunk[1].pCode), patchSetMaxCaptiveThunk[1].dwSize, NULL);
	//ability killer prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAbilityKillerPropThunk[1].dwAddr),\
									(LPVOID)(patchAbilityKillerPropThunk[1].pCode), patchAbilityKillerPropThunk[1].dwSize, NULL);
	//retreat change array
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetreatChangeArrayThunk[1].dwAddr),\
									(LPVOID)(patchRetreatChangeArrayThunk[1].pCode), patchRetreatChangeArrayThunk[1].dwSize, NULL);
	//train basic ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTrainBasicAbilityThunk[1].dwAddr),\
									(LPVOID)(patchTrainBasicAbilityThunk[1].pCode), patchTrainBasicAbilityThunk[1].dwSize, NULL);
	//auto process task
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoProcessTaskThunk[1].dwAddr),\
									(LPVOID)(patchAutoProcessTaskThunk[1].pCode), patchAutoProcessTaskThunk[1].dwSize, NULL);
	//kill sub prestige
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillSubPrestigeThunk[1].dwAddr),\
									(LPVOID)(patchKillSubPrestigeThunk[1].pCode), patchKillSubPrestigeThunk[1].dwSize, NULL);
	//leader inspire
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeaderInspireThunk[1].dwAddr),\
									(LPVOID)(patchLeaderInspireThunk[1].pCode), patchLeaderInspireThunk[1].dwSize, NULL);
	//operation per day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchOperationPerDayThunk[1].dwAddr),\
									(LPVOID)(patchOperationPerDayThunk[1].pCode), patchOperationPerDayThunk[1].dwSize, NULL);
	//fight sub income
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncome3Thunk[1].dwAddr),\
									(LPVOID)(patchFightSubIncome3Thunk[1].pCode), patchFightSubIncome3Thunk[1].dwSize, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncome2Thunk[1].dwAddr),\
									(LPVOID)(patchFightSubIncome2Thunk[1].pCode), patchFightSubIncome2Thunk[1].dwSize, NULL);
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightSubIncomeThunk[1].dwAddr),\
									(LPVOID)(patchFightSubIncomeThunk[1].pCode), patchFightSubIncomeThunk[1].dwSize, NULL);
	//get league goal
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetLeagueGoalThunk[1].dwAddr),\
									(LPVOID)(patchGetLeagueGoalThunk[1].pCode), patchGetLeagueGoalThunk[1].dwSize, NULL);
	//player auto process
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPlayerAutoProcessThunk[1].dwAddr),\
									(LPVOID)(patchPlayerAutoProcessThunk[1].pCode), patchPlayerAutoProcessThunk[1].dwSize, NULL);
	//phase error invite
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPhaseErrorInviteThunk[1].dwAddr),\
									(LPVOID)(patchPhaseErrorInviteThunk[1].pCode), patchPhaseErrorInviteThunk[1].dwSize, NULL);
	//add city draft
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddCityDraftThunk[1].dwAddr),\
									(LPVOID)(patchAddCityDraftThunk[1].pCode), patchAddCityDraftThunk[1].dwSize, NULL);
	//show city draft
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchShowCityDraftThunk[1].dwAddr),\
									(LPVOID)(patchShowCityDraftThunk[1].pCode), patchShowCityDraftThunk[1].dwSize, NULL);
	//goal force para
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoalForceParaThunk[1].dwAddr),\
									(LPVOID)(patchGoalForceParaThunk[1].pCode), patchGoalForceParaThunk[1].dwSize, NULL);
	//city population coef 4
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef4Thunk[1].dwAddr),\
									(LPVOID)(patchCityPopulationCoef4Thunk[1].pCode), patchCityPopulationCoef4Thunk[1].dwSize, NULL);
	//city population coef 3
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef3Thunk[1].dwAddr),\
									(LPVOID)(patchCityPopulationCoef3Thunk[1].pCode), patchCityPopulationCoef3Thunk[1].dwSize, NULL);
	//city population coef 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef2Thunk[1].dwAddr),\
									(LPVOID)(patchCityPopulationCoef2Thunk[1].pCode), patchCityPopulationCoef2Thunk[1].dwSize, NULL);
	//city population coef 1
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCityPopulationCoef1Thunk[1].dwAddr),\
									(LPVOID)(patchCityPopulationCoef1Thunk[1].pCode), patchCityPopulationCoef1Thunk[1].dwSize, NULL);
	//harvest
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHarvestThunk[1].dwAddr),\
									(LPVOID)(patchHarvestThunk[1].pCode), patchHarvestThunk[1].dwSize, NULL);
	//income
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIncomeThunk[1].dwAddr),\
									(LPVOID)(patchIncomeThunk[1].pCode), patchIncomeThunk[1].dwSize, NULL);
	//max business 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBusiness2Thunk[1].dwAddr),\
									(LPVOID)(patchMaxBusiness2Thunk[1].pCode), patchMaxBusiness2Thunk[1].dwSize, NULL);
	//max business
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBusinessThunk[1].dwAddr),\
									(LPVOID)(patchMaxBusinessThunk[1].pCode), patchMaxBusinessThunk[1].dwSize, NULL);
	//judge attack build
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJudgeAttackBuildThunk[1].dwAddr),\
									(LPVOID)(patchJudgeAttackBuildThunk[1].pCode), patchJudgeAttackBuildThunk[1].dwSize, NULL);
	//build arrive day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildArriveDayThunk[1].dwAddr),\
									(LPVOID)(patchBuildArriveDayThunk[1].pCode), patchBuildArriveDayThunk[1].dwSize, NULL);
	//skip arrive day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSkipArriveDayThunk[1].dwAddr),\
									(LPVOID)(patchSkipArriveDayThunk[1].pCode), patchSkipArriveDayThunk[1].dwSize, NULL);
	//clear second killer person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchClearSecondKillerPersonThunk[1].dwAddr),\
									(LPVOID)(patchClearSecondKillerPersonThunk[1].pCode), patchClearSecondKillerPersonThunk[1].dwSize, NULL);
	//chaos power coef
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaosPowerCoefThunk[1].dwAddr),\
									(LPVOID)(patchChaosPowerCoefThunk[1].pCode), patchChaosPowerCoefThunk[1].dwSize, NULL);
	//killer check bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerCheckBugThunk[1].dwAddr),\
									(LPVOID)(patchKillerCheckBugThunk[1].pCode), patchKillerCheckBugThunk[1].dwSize, NULL);
	//counselor report prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCounselorReportPropThunk[1].dwAddr),\
									(LPVOID)(patchCounselorReportPropThunk[1].pCode), patchCounselorReportPropThunk[1].dwSize, NULL);
	//alloc free troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllocFreeTroopThunk[1].dwAddr),\
									(LPVOID)(patchAllocFreeTroopThunk[1].pCode), patchAllocFreeTroopThunk[1].dwSize, NULL);
	//hide city harvest
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityHarvestThunk[1].dwAddr),\
									(LPVOID)(patchHideCityHarvestThunk[1].pCode), patchHideCityHarvestThunk[1].dwSize, NULL);
	//hide city income
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityIncomeThunk[1].dwAddr),\
									(LPVOID)(patchHideCityIncomeThunk[1].pCode), patchHideCityIncomeThunk[1].dwSize, NULL);
	//hide city morale
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideCityMoraleThunk[1].dwAddr),\
									(LPVOID)(patchHideCityMoraleThunk[1].pCode), patchHideCityMoraleThunk[1].dwSize, NULL);
	//retreat building condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetreatBuildingConditionThunk[1].dwAddr),\
									(LPVOID)(patchRetreatBuildingConditionThunk[1].pCode), patchRetreatBuildingConditionThunk[1].dwSize, NULL);
	//hide special state
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideSpecialStateThunk[1].dwAddr),\
									(LPVOID)(patchHideSpecialStateThunk[1].pCode), patchHideSpecialStateThunk[1].dwSize, NULL);
	//hide down stone
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDownStoneThunk[1].dwAddr),\
									(LPVOID)(patchHideDownStoneThunk[1].pCode), patchHideDownStoneThunk[1].dwSize, NULL);
	//damage number down
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDamageNumberDownThunk[1].dwAddr),\
									(LPVOID)(patchDamageNumberDownThunk[1].pCode), patchDamageNumberDownThunk[1].dwSize, NULL);
	//hide info menu
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideInfoMenuThunk[1].dwAddr),\
									(LPVOID)(patchHideInfoMenuThunk[1].pCode), patchHideInfoMenuThunk[1].dwSize, NULL);
	//journey goal troop 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyGoalTroop2Thunk[1].dwAddr),\
									(LPVOID)(patchJourneyGoalTroop2Thunk[1].pCode), patchJourneyGoalTroop2Thunk[1].dwSize, NULL);
	//test dark flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTestDarkFlagThunk[1].dwAddr),\
									(LPVOID)(patchTestDarkFlagThunk[1].pCode), patchTestDarkFlagThunk[1].dwSize, NULL);
	//hide duty person num 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDutyPersonNum2Thunk[1].dwAddr),\
									(LPVOID)(patchHideDutyPersonNum2Thunk[1].pCode), patchHideDutyPersonNum2Thunk[1].dwSize, NULL);
	//hide duty person num
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHideDutyPersonNumThunk[1].dwAddr),\
									(LPVOID)(patchHideDutyPersonNumThunk[1].pCode), patchHideDutyPersonNumThunk[1].dwSize, NULL);
	//display building condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayBuildingConditionThunk[1].dwAddr),\
									(LPVOID)(patchDisplayBuildingConditionThunk[1].pCode), patchDisplayBuildingConditionThunk[1].dwSize, NULL);
	//false goal troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFalseGoalTroopThunk[1].dwAddr),\
									(LPVOID)(patchFalseGoalTroopThunk[1].pCode), patchFalseGoalTroopThunk[1].dwSize, NULL);
	//journey goal troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyGoalTroopThunk[1].dwAddr),\
									(LPVOID)(patchJourneyGoalTroopThunk[1].pCode), patchJourneyGoalTroopThunk[1].dwSize, NULL);
	//water killer prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWaterKillerPropThunk[1].dwAddr),\
									(LPVOID)(patchWaterKillerPropThunk[1].pCode), patchWaterKillerPropThunk[1].dwSize, NULL);
	//killer to building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerToBuildingThunk[1].dwAddr),\
									(LPVOID)(patchKillerToBuildingThunk[1].pCode), patchKillerToBuildingThunk[1].dwSize, NULL);
	//rob food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobFoodThunk[1].dwAddr),\
									(LPVOID)(patchRobFoodThunk[1].pCode), patchRobFoodThunk[1].dwSize, NULL);
	//month table info
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMonthTableInfoThunk[1].dwAddr),\
									(LPVOID)(patchMonthTableInfoThunk[1].pCode), patchMonthTableInfoThunk[1].dwSize, NULL);
	//year table info
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchYearTableInfoThunk[1].dwAddr),\
									(LPVOID)(patchYearTableInfoThunk[1].pCode), patchYearTableInfoThunk[1].dwSize, NULL);
	//control march troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchControlMarchTroopThunk[1].dwAddr),\
									(LPVOID)(patchControlMarchTroopThunk[1].pCode), patchControlMarchTroopThunk[1].dwSize, NULL);
	//update captive prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateCaptivePropThunk[1].dwAddr),\
									(LPVOID)(patchUpdateCaptivePropThunk[1].pCode), patchUpdateCaptivePropThunk[1].dwSize, NULL);
	//strength killer big animaiton
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStrengthKillerBigAnimaitonThunk[1].dwAddr),\
									(LPVOID)(patchStrengthKillerBigAnimaitonThunk[1].pCode), patchStrengthKillerBigAnimaitonThunk[1].dwSize, NULL);
	//move guard troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveGuardTroopThunk[1].dwAddr),\
									(LPVOID)(patchMoveGuardTroopThunk[1].pCode), patchMoveGuardTroopThunk[1].dwSize, NULL);
	//clear troop cur goal
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchClearTroopCurGoalThunk[1].dwAddr),\
									(LPVOID)(patchClearTroopCurGoalThunk[1].pCode), patchClearTroopCurGoalThunk[1].dwSize, NULL);
	//killer drive prop 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerDriveProp2Thunk[1].dwAddr),\
									(LPVOID)(patchKillerDriveProp2Thunk[1].pCode), patchKillerDriveProp2Thunk[1].dwSize, NULL);
	//killer drive prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerDrivePropThunk[1].dwAddr),\
									(LPVOID)(patchKillerDrivePropThunk[1].pCode), patchKillerDrivePropThunk[1].dwSize, NULL);
	//change troop command
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChangeTroopCommandThunk[1].dwAddr),\
									(LPVOID)(patchChangeTroopCommandThunk[1].pCode), patchChangeTroopCommandThunk[1].dwSize, NULL);
	//read scene index
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchReadSceneIndexThunk[1].dwAddr),\
									(LPVOID)(patchReadSceneIndexThunk[1].pCode), patchReadSceneIndexThunk[1].dwSize, NULL);
	//all strong force
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllStrongForceThunk[1].dwAddr),\
									(LPVOID)(patchAllStrongForceThunk[1].pCode), patchAllStrongForceThunk[1].dwSize, NULL);
	//attack heart linkage flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackHeartLinkageFlagThunk[1].dwAddr),\
									(LPVOID)(patchAttackHeartLinkageFlagThunk[1].pCode), patchAttackHeartLinkageFlagThunk[1].dwSize, NULL);
	//trap linkage flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTrapLinkageFlagThunk[1].dwAddr),\
									(LPVOID)(patchTrapLinkageFlagThunk[1].pCode), patchTrapLinkageFlagThunk[1].dwSize, NULL);
	//chaos linkage flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaosLinkageFlagThunk[1].dwAddr),\
									(LPVOID)(patchChaosLinkageFlagThunk[1].pCode), patchChaosLinkageFlagThunk[1].dwSize, NULL);
	//block prop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBlcokPropThunk[1].dwAddr),\
									(LPVOID)(patchBlcokPropThunk[1].pCode), patchBlcokPropThunk[1].dwSize, NULL);
	//disorder goal troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderGoalTroopThunk[1].dwAddr),\
									(LPVOID)(patchDisorderGoalTroopThunk[1].pCode), patchDisorderGoalTroopThunk[1].dwSize, NULL);
	//troop at small map
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAtSmallMapThunk[1].dwAddr),\
									(LPVOID)(patchTroopAtSmallMapThunk[1].pCode), patchTroopAtSmallMapThunk[1].dwSize, NULL);
	//person small dialog
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonSmallDialogThunk[1].dwAddr),\
									(LPVOID)(patchPersonSmallDialogThunk[1].pCode), patchPersonSmallDialogThunk[1].dwSize, NULL);
	//display troop condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayTroopConditionThunk[1].dwAddr),\
									(LPVOID)(patchDisplayTroopConditionThunk[1].pCode), patchDisplayTroopConditionThunk[1].dwSize, NULL);
	//get array attack range
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayAttackRangeThunk[1].dwAddr),\
									(LPVOID)(patchGetArrayAttackRangeThunk[1].pCode), patchGetArrayAttackRangeThunk[1].dwSize, NULL);
	//coordinate request
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCoordinateRequestThunk[1].dwAddr),\
									(LPVOID)(patchCoordinateRequestThunk[1].pCode), patchCoordinateRequestThunk[1].dwSize, NULL);
	//get person quota
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetPersonQuotaThunk[1].dwAddr),\
									(LPVOID)(patchGetPersonQuotaThunk[1].pCode), patchGetPersonQuotaThunk[1].dwSize, NULL);
	//second killer interval
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSecondKillerIntervalThunk[1].dwAddr),\
									(LPVOID)(patchSecondKillerIntervalThunk[1].pCode), patchSecondKillerIntervalThunk[1].dwSize, NULL);
	//second killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSecondKillerThunk[1].dwAddr),\
									(LPVOID)(patchSecondKillerThunk[1].pCode), patchSecondKillerThunk[1].dwSize, NULL);
	//troop retreat
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopRetreatThunk[1].dwAddr),\
									(LPVOID)(patchTroopRetreatThunk[1].pCode), patchTroopRetreatThunk[1].dwSize, NULL);
	//troop at good place
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopAtGoodPlaceThunk[1].dwAddr),\
									(LPVOID)(patchTroopAtGoodPlaceThunk[1].pCode), patchTroopAtGoodPlaceThunk[1].dwSize, NULL);
	//attack ratio door
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackRatioDoorThunk[1].dwAddr),\
									(LPVOID)(patchAttackRatioDoorThunk[1].pCode), patchAttackRatioDoorThunk[1].dwSize, NULL);
	//person char num
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonCharNumThunk[1].dwAddr),\
									(LPVOID)(patchPersonCharNumThunk[1].pCode), patchPersonCharNumThunk[1].dwSize, NULL);
	//attack troop soldier 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopSoldier2Thunk[1].dwAddr),\
									(LPVOID)(patchAttackTroopSoldier2Thunk[1].pCode), patchAttackTroopSoldier2Thunk[1].dwSize, NULL);
	//attack troop soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopSoldierThunk[1].dwAddr),\
									(LPVOID)(patchAttackTroopSoldierThunk[1].pCode), patchAttackTroopSoldierThunk[1].dwSize, NULL);
	//learn to phase 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLearnToPhase2Thunk[1].dwAddr),\
									(LPVOID)(patchLearnToPhase2Thunk[1].pCode), patchLearnToPhase2Thunk[1].dwSize, NULL);
	//learn to phase
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLearnToPhaseThunk[1].dwAddr),\
									(LPVOID)(patchLearnToPhaseThunk[1].pCode), patchLearnToPhaseThunk[1].dwSize, NULL);
	//dynamic add proficiency
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDynamicAddProficiencyThunk[1].dwAddr),\
									(LPVOID)(patchDynamicAddProficiencyThunk[1].pCode), patchDynamicAddProficiencyThunk[1].dwSize, NULL);
	//max soldier cmp
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierCmpThunk[1].dwAddr),\
									(LPVOID)(patchMaxSoldierCmpThunk[1].pCode), patchMaxSoldierCmpThunk[1].dwSize, NULL);
	//max soldier push 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierPush2Thunk[1].dwAddr),\
									(LPVOID)(patchMaxSoldierPush2Thunk[1].pCode), patchMaxSoldierPush2Thunk[1].dwSize, NULL);
	//max soldier push
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxSoldierPushThunk[1].dwAddr),\
									(LPVOID)(patchMaxSoldierPushThunk[1].pCode), patchMaxSoldierPushThunk[1].dwSize, NULL);
	//max people heart basic
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartBasicThunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartBasicThunk[1].pCode), patchMaxPeopleHeartBasicThunk[1].dwSize, NULL);
	//max people heart mov 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartMov2Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartMov2Thunk[1].pCode), patchMaxPeopleHeartMov2Thunk[1].dwSize, NULL);
	//max people heart mov
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartMovThunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartMovThunk[1].pCode), patchMaxPeopleHeartMovThunk[1].dwSize, NULL);
	//max people heart push 4
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush4Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush4Thunk[1].pCode), patchMaxPeopleHeartPush4Thunk[1].dwSize, NULL);
	//max people heart push 3
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush3Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush3Thunk[1].pCode), patchMaxPeopleHeartPush3Thunk[1].dwSize, NULL);
	//max people heart push 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPush2Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPush2Thunk[1].pCode), patchMaxPeopleHeartPush2Thunk[1].dwSize, NULL);
	//max people heart push
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartPushThunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartPushThunk[1].pCode), patchMaxPeopleHeartPushThunk[1].dwSize, NULL);
	//get city max people heart
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetCityMaxPeopleHeartThunk[1].dwAddr),\
									(LPVOID)(patchGetCityMaxPeopleHeartThunk[1].pCode), patchGetCityMaxPeopleHeartThunk[1].dwSize, NULL);
	//max people heart cmp 4
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp4Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp4Thunk[1].pCode), patchMaxPeopleHeartCmp4Thunk[1].dwSize, NULL);
	//max people heart cmp 3
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp3Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp3Thunk[1].pCode), patchMaxPeopleHeartCmp3Thunk[1].dwSize, NULL);
	//max people heart cmp 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmp2Thunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmp2Thunk[1].pCode), patchMaxPeopleHeartCmp2Thunk[1].dwSize, NULL);
	//max people heart cmp
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxPeopleHeartCmpThunk[1].dwAddr),\
									(LPVOID)(patchMaxPeopleHeartCmpThunk[1].pCode), patchMaxPeopleHeartCmpThunk[1].dwSize, NULL);
	//building max soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingMaxSoldierThunk[1].dwAddr),\
									(LPVOID)(patchBuildingMaxSoldierThunk[1].pCode), patchBuildingMaxSoldierThunk[1].dwSize, NULL);
	//intelligence officer para
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceOfficerParaThunk[1].dwAddr),\
						(LPVOID)(patchIntelligenceOfficerParaThunk[1].pCode), patchIntelligenceOfficerParaThunk[1].dwSize, NULL);
	//delete max officer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDeleteMaxOfficerThunk[1].dwAddr),\
									(LPVOID)(patchDeleteMaxOfficerThunk[1].pCode), patchDeleteMaxOfficerThunk[1].dwSize, NULL);
	//command officer para
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandOfficerParaThunk[1].dwAddr),\
									(LPVOID)(patchCommandOfficerParaThunk[1].pCode), patchCommandOfficerParaThunk[1].dwSize, NULL);
	//person experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonExperienceThunk[1].dwAddr),\
									(LPVOID)(patchPersonExperienceThunk[1].pCode), patchPersonExperienceThunk[1].dwSize, NULL);
	//phase error alienate
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPhaseErrorAlienateThunk[1].dwAddr),\
									(LPVOID)(patchPhaseErrorAlienateThunk[1].pCode), patchPhaseErrorAlienateThunk[1].dwSize, NULL);
	//try invite captive
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTryInviteCaptiveThunk[1].dwAddr),\
									(LPVOID)(patchTryInviteCaptiveThunk[1].pCode), patchTryInviteCaptiveThunk[1].dwSize, NULL);
	//multi alienate
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMultiAlienateThunk[1].dwAddr),\
									(LPVOID)(patchMultiAlienateThunk[1].pCode), patchMultiAlienateThunk[1].dwSize, NULL);
	//auto save docname
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAutoSaveDocnameThunk[1].dwAddr),\
									(LPVOID)(patchAutoSaveDocnameThunk[1].pCode), patchAutoSaveDocnameThunk[1].dwSize, NULL);
	//check transport block
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTransportBlockThunk[1].dwAddr),\
									(LPVOID)(patchCheckTransportBlockThunk[1].pCode), patchCheckTransportBlockThunk[1].dwSize, NULL);
	//max building wound
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBuildingWoundThunk[1].dwAddr),\
									(LPVOID)(patchMaxBuildingWoundThunk[1].pCode), patchMaxBuildingWoundThunk[1].dwSize, NULL);
	//stop repair bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopRepairBugThunk[1].dwAddr),\
									(LPVOID)(patchStopRepairBugThunk[1].pCode), patchStopRepairBugThunk[1].dwSize, NULL);
	//stop Visit bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopVisitBugThunk[1].dwAddr),\
									(LPVOID)(patchStopVisitBugThunk[1].pCode), patchStopVisitBugThunk[1].dwSize, NULL);
	//stop cultivate bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopCultivateBugThunk[1].dwAddr),\
									(LPVOID)(patchStopCultivateBugThunk[1].pCode), patchStopCultivateBugThunk[1].dwSize, NULL);
	//stop commerce bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopCommerceBugThunk[1].dwAddr),\
									(LPVOID)(patchStopCommerceBugThunk[1].pCode), patchStopCommerceBugThunk[1].dwSize, NULL);
	//stop train bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStopTrainBugThunk[1].dwAddr),\
									(LPVOID)(patchStopTrainBugThunk[1].pCode), patchStopTrainBugThunk[1].dwSize, NULL);
	//sort transport source
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSortTransportSourceThunk[1].dwAddr),\
									(LPVOID)(patchSortTransportSourceThunk[1].pCode), patchSortTransportSourceThunk[1].dwSize, NULL);
	//select transport source
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectTransportSourceThunk[1].dwAddr),\
									(LPVOID)(patchSelectTransportSourceThunk[1].pCode), patchSelectTransportSourceThunk[1].dwSize, NULL);
	//init transport building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInitTransportBuildingThunk[1].dwAddr),\
									(LPVOID)(patchInitTransportBuildingThunk[1].pCode), patchInitTransportBuildingThunk[1].dwSize, NULL);
	//set building soldier remains
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetBuildingSoldierRemainsThunk[1].dwAddr),\
									(LPVOID)(patchSetBuildingSoldierRemainsThunk[1].pCode), patchSetBuildingSoldierRemainsThunk[1].dwSize, NULL);
	//check transport task
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTransportTaskThunk[1].dwAddr),\
									(LPVOID)(patchCheckTransportTaskThunk[1].pCode), patchCheckTransportTaskThunk[1].dwSize, NULL);
	//get tranasport soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetTransportSoldierThunk[1].dwAddr),\
									(LPVOID)(patchGetTransportSoldierThunk[1].pCode), patchGetTransportSoldierThunk[1].dwSize, NULL);
	//force fight troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchForceFightTroopThunk[1].dwAddr),\
									(LPVOID)(patchForceFightTroopThunk[1].pCode), patchForceFightTroopThunk[1].dwSize, NULL);
	//direct big animation
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDirectBigAnimationThunk[1].dwAddr),\
									(LPVOID)(patchDirectBigAnimationThunk[1].pCode), patchDirectBigAnimationThunk[1].dwSize, NULL);
	//get array to garrison
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayToGarrisonThunk[1].dwAddr),\
									(LPVOID)(patchGetArrayToGarrisonThunk[1].pCode), patchGetArrayToGarrisonThunk[1].dwSize, NULL);
	//get array to wall
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetArrayToWallThunk[1].dwAddr),\
									(LPVOID)(patchGetArrayToWallThunk[1].pCode), patchGetArrayToWallThunk[1].dwSize, NULL);
	//linkage killer to dialog
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLinkageKillerToDialogThunk[1].dwAddr),\
									(LPVOID)(patchLinkageKillerToDialogThunk[1].pCode), patchLinkageKillerToDialogThunk[1].dwSize, NULL);
	//linkage killer to record
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLinkageKillerToRecordThunk[1].dwAddr),\
									(LPVOID)(patchLinkageKillerToRecordThunk[1].pCode), patchLinkageKillerToRecordThunk[1].dwSize, NULL);
	//killer power to damage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerPowerToDamageThunk[1].dwAddr),\
									(LPVOID)(patchKillerPowerToDamageThunk[1].pCode), patchKillerPowerToDamageThunk[1].dwSize, NULL);
	//judge killer linkage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJudgeKillerLinkageThunk[1].dwAddr),\
									(LPVOID)(patchJudgeKillerLinkageThunk[1].pCode), patchJudgeKillerLinkageThunk[1].dwSize, NULL);
	//check person killer level
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckPersonKillerLevelThunk[1].dwAddr),\
									(LPVOID)(patchCheckPersonKillerLevelThunk[1].pCode), patchCheckPersonKillerLevelThunk[1].dwSize, NULL);
	//regarded building on attack 3
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttack3Thunk[1].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttack3Thunk[1].pCode), patchRegardedBuildingOnAttack3Thunk[1].dwSize, NULL);
	//regarded building on attack 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttack2Thunk[1].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttack2Thunk[1].pCode), patchRegardedBuildingOnAttack2Thunk[1].dwSize, NULL);
	//regarded building on attack
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRegardedBuildingOnAttackThunk[1].dwAddr),\
									(LPVOID)(patchRegardedBuildingOnAttackThunk[1].pCode), patchRegardedBuildingOnAttackThunk[1].dwSize, NULL);
	//test not null city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTestNotNullCityThunk[1].dwAddr),\
									(LPVOID)(patchTestNotNullCityThunk[1].pCode), patchTestNotNullCityThunk[1].dwSize, NULL);
	//set force foal
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetForceGoalThunk[1].dwAddr),\
									(LPVOID)(patchSetForceGoalThunk[1].pCode), patchSetForceGoalThunk[1].dwSize, NULL);
	//load near max soldier 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLoadNearMaxSoldier2Thunk[1].dwAddr),\
									(LPVOID)(patchLoadNearMaxSoldier2Thunk[1].pCode), patchLoadNearMaxSoldier2Thunk[1].dwSize, NULL);
	//load near max soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLoadNearMaxSoldierThunk[1].dwAddr),\
									(LPVOID)(patchLoadNearMaxSoldierThunk[1].pCode), patchLoadNearMaxSoldierThunk[1].dwSize, NULL);
	//save near max soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveNearMaxSoldierThunk[1].dwAddr),\
									(LPVOID)(patchSaveNearMaxSoldierThunk[1].pCode), patchSaveNearMaxSoldierThunk[1].dwSize, NULL);
	//baram not build
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBaramNotBuildThunk[1].dwAddr),\
									(LPVOID)(patchBaramNotBuildThunk[1].pCode), patchBaramNotBuildThunk[1].dwSize, NULL);
	//correct goal building soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectGoalBuildingSoldierThunk[1].dwAddr),\
									(LPVOID)(patchCorrectGoalBuildingSoldierThunk[1].pCode), patchCorrectGoalBuildingSoldierThunk[1].dwSize, NULL);
	//correct building attack soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectBuildingAttackSoldierThunk[1].dwAddr),\
									(LPVOID)(patchCorrectBuildingAttackSoldierThunk[1].pCode), patchCorrectBuildingAttackSoldierThunk[1].dwSize, NULL);
	//save attack source building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveAttackSourceBuildingThunk[1].dwAddr),\
		(LPVOID)(patchSaveAttackSourceBuildingThunk[1].pCode), patchSaveAttackSourceBuildingThunk[1].dwSize, NULL);
	//draft min food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftMinFoodThunk[1].dwAddr),\
					(LPVOID)(patchDraftMinFoodThunk[1].pCode), patchDraftMinFoodThunk[1].dwSize, NULL);
	//draft fail bug
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftFailBugThunk[1].dwAddr),\
					(LPVOID)(patchDraftFailBugThunk[1].pCode), patchDraftFailBugThunk[1].dwSize, NULL);
	//refuse change
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRefuseChangeThunk[1].dwAddr),\
					(LPVOID)(patchRefuseChangeThunk[1].pCode), patchRefuseChangeThunk[1].dwSize, NULL);
	//display year
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisplayYearThunk[1].dwAddr),\
					(LPVOID)(patchDisplayYearThunk[1].pCode), patchDisplayYearThunk[1].dwSize, NULL);
	//select attack wisdom
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackWisdomThunk[1].dwAddr),\
					(LPVOID)(patchSelectAttackWisdomThunk[1].pCode), patchSelectAttackWisdomThunk[1].dwSize, NULL);
	//select train person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectTrainPersonThunk[1].dwAddr),\
					(LPVOID)(patchSelectTrainPersonThunk[1].pCode), patchSelectTrainPersonThunk[1].dwSize, NULL);
	//anti attack wisdom
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackWisdomThunk[1].dwAddr),\
					(LPVOID)(patchAntiAttackWisdomThunk[1].pCode), patchAntiAttackWisdomThunk[1].dwSize, NULL);
	//anti attack antitrap
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackAntitrapThunk[1].dwAddr),\
					(LPVOID)(patchAntiAttackAntitrapThunk[1].pCode), patchAntiAttackAntitrapThunk[1].dwSize, NULL);
	//select water wisdom
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectWaterWisdomThunk[1].dwAddr),\
					(LPVOID)(patchSelectWaterWisdomThunk[1].pCode), patchSelectWaterWisdomThunk[1].dwSize, NULL);
	//adjust attack soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAdjustAttackSoldierThunk[1].dwAddr),\
					(LPVOID)(patchAdjustAttackSoldierThunk[1].pCode), patchAdjustAttackSoldierThunk[1].dwSize, NULL);
	//go through near barrier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoThroughNearBarrierThunk[1].dwAddr),\
					(LPVOID)(patchGoThroughNearBarrierThunk[1].pCode), patchGoThroughNearBarrierThunk[1].dwSize, NULL);
	//go through near building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGoThroughNearBuildingThunk[1].dwAddr),\
					(LPVOID)(patchGoThroughNearBuildingThunk[1].pCode), patchGoThroughNearBuildingThunk[1].dwSize, NULL);
	//max build money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxBuildMoneyThunk[1].dwAddr),\
					(LPVOID)(patchMaxBuildMoneyThunk[1].pCode), patchMaxBuildMoneyThunk[1].dwSize, NULL);
	//build real goal
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildRealGoalThunk[1].dwAddr),\
					(LPVOID)(patchBuildRealGoalThunk[1].pCode), patchBuildRealGoalThunk[1].dwSize, NULL);
	//not approach near troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotApproachNearTroopThunk[1].dwAddr),\
					(LPVOID)(patchNotApproachNearTroopThunk[1].pCode), patchNotApproachNearTroopThunk[1].dwSize, NULL);
	//being build
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBeingBuildThunk[1].dwAddr),\
					(LPVOID)(patchBeingBuildThunk[1].pCode), patchBeingBuildThunk[1].dwSize, NULL);
	//decide build
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDecideBuildThunk[1].dwAddr),\
					(LPVOID)(patchDecideBuildThunk[1].pCode), patchDecideBuildThunk[1].dwSize, NULL);
	//select build area
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectBuildAreaThunk[1].dwAddr),\
					(LPVOID)(patchSelectBuildAreaThunk[1].pCode), patchSelectBuildAreaThunk[1].dwSize, NULL);
	//league succeed
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueSucceedThunk[1].dwAddr),\
					(LPVOID)(patchLeagueSucceedThunk[1].pCode), patchLeagueSucceedThunk[1].dwSize, NULL);
	//league fail
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeagueFailThunk[1].dwAddr),\
					(LPVOID)(patchLeagueFailThunk[1].pCode), patchLeagueFailThunk[1].dwSize, NULL);
	//not attack near troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotAttackNearTroopThunk[1].dwAddr),\
					(LPVOID)(patchNotAttackNearTroopThunk[1].pCode), patchNotAttackNearTroopThunk[1].dwSize, NULL);
	//set near attack flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSetNearAttackFlagThunk[1].dwAddr),\
					(LPVOID)(patchSetNearAttackFlagThunk[1].pCode), patchSetNearAttackFlagThunk[1].dwSize, NULL);
	//select attack array
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackArrayThunk[1].dwAddr),\
					(LPVOID)(patchSelectAttackArrayThunk[1].pCode), patchSelectAttackArrayThunk[1].dwSize, NULL);
	//correct near max soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCorrectNearMaxSoldierThunk[1].dwAddr),\
					(LPVOID)(patchCorrectNearMaxSoldierThunk[1].pCode), patchCorrectNearMaxSoldierThunk[1].dwSize, NULL);
	//add official loyaty
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddOfficialLoyatyThunk[1].dwAddr),\
					(LPVOID)(patchAddOfficialLoyatyThunk[1].pCode), patchAddOfficialLoyatyThunk[1].dwSize, NULL);
	//official loyaty
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchOfficialLoyatyThunk[1].dwAddr),\
					(LPVOID)(patchOfficialLoyatyThunk[1].pCode), patchOfficialLoyatyThunk[1].dwSize, NULL);
	//left clever killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLeftCleverKillerThunk[1].dwAddr),\
					(LPVOID)(patchLeftCleverKillerThunk[1].pCode), patchLeftCleverKillerThunk[1].dwSize, NULL);
	//building on the way
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingOnTheWayThunk[1].dwAddr),\
					(LPVOID)(patchBuildingOnTheWayThunk[1].pCode), patchBuildingOnTheWayThunk[1].dwSize, NULL);
	//max attack soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxAttackSoldierThunk[1].dwAddr),\
					(LPVOID)(patchMaxAttackSoldierThunk[1].pCode), patchMaxAttackSoldierThunk[1].dwSize, NULL);
	//select attack person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackPersonThunk[1].dwAddr),\
					(LPVOID)(patchSelectAttackPersonThunk[1].pCode), patchSelectAttackPersonThunk[1].dwSize, NULL);
	//retry attacked building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRetryAttackedBuildingThunk[1].dwAddr),\
					(LPVOID)(patchRetryAttackedBuildingThunk[1].pCode), patchRetryAttackedBuildingThunk[1].dwSize, NULL);
	//decide attack ok
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDecideAttackOkThunk[1].dwAddr),\
					(LPVOID)(patchDecideAttackOkThunk[1].pCode), patchDecideAttackOkThunk[1].dwSize, NULL);
	//reserve attacked building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchReserveAttackedBuildingThunk[1].dwAddr),\
					(LPVOID)(patchReserveAttackedBuildingThunk[1].pCode), patchReserveAttackedBuildingThunk[1].dwSize, NULL);
	//add city relation
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAddCityRelationThunk[1].dwAddr),\
					(LPVOID)(patchAddCityRelationThunk[1].pCode), patchAddCityRelationThunk[1].dwSize, NULL);
	//attack min person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackMinPersonThunk[1].dwAddr),\
					(LPVOID)(patchAttackMinPersonThunk[1].pCode), patchAttackMinPersonThunk[1].dwSize, NULL);
	//select attack building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSelectAttackBuildingThunk[1].dwAddr),\
					(LPVOID)(patchSelectAttackBuildingThunk[1].pCode), patchSelectAttackBuildingThunk[1].dwSize, NULL);
	//circle attack building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCircleAttackBuildingThunk[1].dwAddr),\
					(LPVOID)(patchCircleAttackBuildingThunk[1].pCode), patchCircleAttackBuildingThunk[1].dwSize, NULL);
	//attack source city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackSourceCityThunk[1].dwAddr),\
					(LPVOID)(patchAttackSourceCityThunk[1].pCode), patchAttackSourceCityThunk[1].dwSize, NULL);
	//allie attack
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAllieAttackThunk[1].dwAddr),\
					(LPVOID)(patchAllieAttackThunk[1].pCode), patchAllieAttackThunk[1].dwSize, NULL);
	//null building array
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNullBuildingArrayThunk[1].dwAddr),\
					(LPVOID)(patchNullBuildingArrayThunk[1].pCode), patchNullBuildingArrayThunk[1].dwSize, NULL);
	//attack null building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackNullBuildingThunk[1].dwAddr),\
					(LPVOID)(patchAttackNullBuildingThunk[1].pCode), patchAttackNullBuildingThunk[1].dwSize, NULL);
	//get player city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGetPlayerCityThunk[1].dwAddr),\
					(LPVOID)(patchGetPlayerCityThunk[1].pCode), patchGetPlayerCityThunk[1].dwSize, NULL);
	//near null city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNearNullCityThunk[1].dwAddr),\
					(LPVOID)(patchNearNullCityThunk[1].pCode), patchNearNullCityThunk[1].dwSize, NULL);
	//filter building soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFilterBuildingSoldierThunk[1].dwAddr),\
					(LPVOID)(patchFilterBuildingSoldierThunk[1].pCode), patchFilterBuildingSoldierThunk[1].dwSize, NULL);
	//gossip to player
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGossipToPlayerThunk[1].dwAddr),\
					(LPVOID)(patchGossipToPlayerThunk[1].pCode), patchGossipToPlayerThunk[1].dwSize, NULL);
	//attack min money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackMinMoneyThunk[1].dwAddr),\
					(LPVOID)(patchAttackMinMoneyThunk[1].pCode), patchAttackMinMoneyThunk[1].dwSize, NULL);
	//draft min money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDraftMinMoneyThunk[1].dwAddr),\
					(LPVOID)(patchDraftMinMoneyThunk[1].pCode), patchDraftMinMoneyThunk[1].dwSize, NULL);
	//fight to killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFightToKillerThunk[1].dwAddr),\
					(LPVOID)(patchFightToKillerThunk[1].pCode), patchFightToKillerThunk[1].dwSize, NULL);
	//max force food
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxForceFoodThunk[1].dwAddr),\
					(LPVOID)(patchMaxForceFoodThunk[1].pCode), patchMaxForceFoodThunk[1].dwSize, NULL);
	//sub anti trap
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubAntiTrapThunk[1].dwAddr),\
					(LPVOID)(patchSubAntiTrapThunk[1].pCode), patchSubAntiTrapThunk[1].dwSize, NULL);
	//sub anti trick
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubAntiTrickThunk[1].dwAddr),\
					(LPVOID)(patchSubAntiTrickThunk[1].pCode), patchSubAntiTrickThunk[1].dwSize, NULL);
	//goto npc city
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGotoNpcCityThunk[1].dwAddr),\
					(LPVOID)(patchGotoNpcCityThunk[1].pCode), patchGotoNpcCityThunk[1].dwSize, NULL);
	//attack left soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackLeftSoldierThunk[1].dwAddr),\
					(LPVOID)(patchAttackLeftSoldierThunk[1].pCode), patchAttackLeftSoldierThunk[1].dwSize, NULL);
	//attack building soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackBuildingSoldierThunk[1].dwAddr),\
					(LPVOID)(patchAttackBuildingSoldierThunk[1].pCode), patchAttackBuildingSoldierThunk[1].dwSize, NULL);
	//attack if check soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackIfCheckSoldierThunk[1].dwAddr),\
					(LPVOID)(patchAttackIfCheckSoldierThunk[1].pCode), patchAttackIfCheckSoldierThunk[1].dwSize, NULL);
	//check max save soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMaxSaveSoldierThunk[1].dwAddr),\
					(LPVOID)(patchCheckMaxSaveSoldierThunk[1].pCode), patchCheckMaxSaveSoldierThunk[1].dwSize, NULL);
	//check min left soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMinLeftSoldierThunk[1].dwAddr),\
					(LPVOID)(patchCheckMinLeftSoldierThunk[1].pCode), patchCheckMinLeftSoldierThunk[1].dwSize, NULL);
	//check troop retreat
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTroopRetreatThunk[1].dwAddr),\
					(LPVOID)(patchCheckTroopRetreatThunk[1].pCode), patchCheckTroopRetreatThunk[1].dwSize, NULL);
	//new force soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNewForceSoldierThunk[1].dwAddr),\
					(LPVOID)(patchNewForceSoldierThunk[1].pCode), patchNewForceSoldierThunk[1].dwSize, NULL);
	//save harbor
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveHarborThunk[1].dwAddr),\
					(LPVOID)(patchSaveHarborThunk[1].pCode), patchSaveHarborThunk[1].dwSize, NULL);
	//not sure captive
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotSureCaptiveThunk[1].dwAddr),\
					(LPVOID)(patchNotSureCaptiveThunk[1].pCode), patchNotSureCaptiveThunk[1].dwSize, NULL);
	//building killer person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingKillerPersonThunk[1].dwAddr),\
					(LPVOID)(patchBuildingKillerPersonThunk[1].pCode), patchBuildingKillerPersonThunk[1].dwSize, NULL);
	//update killer damage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUpdateKillerDamageThunk[1].dwAddr),\
					(LPVOID)(patchUpdateKillerDamageThunk[1].pCode), patchUpdateKillerDamageThunk[1].dwSize, NULL);
	//treasure value
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTreasureValueThunk[1].dwAddr),\
					(LPVOID)(patchTreasureValueThunk[1].pCode), patchTreasureValueThunk[1].dwSize, NULL);
	//invite new person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInviteNewPersonThunk[1].dwAddr),\
					(LPVOID)(patchInviteNewPersonThunk[1].pCode), patchInviteNewPersonThunk[1].dwSize, NULL);
	//search invite
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchInviteThunk[1].dwAddr),\
					(LPVOID)(patchSearchInviteThunk[1].pCode), patchSearchInviteThunk[1].dwSize, NULL);
	//search condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchConditionThunk[1].dwAddr),\
					(LPVOID)(patchSearchConditionThunk[1].pCode), patchSearchConditionThunk[1].dwSize, NULL);
	//search range
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSearchRangeThunk[1].dwAddr),\
					(LPVOID)(patchSearchRangeThunk[1].pCode), patchSearchRangeThunk[1].dwSize, NULL);
	//captive money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCaptiveMoneyThunk[1].dwAddr),\
					(LPVOID)(patchCaptiveMoneyThunk[1].pCode), patchCaptiveMoneyThunk[1].dwSize, NULL);
	//captive money2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCaptiveMoney2Thunk[1].dwAddr),\
					(LPVOID)(patchCaptiveMoney2Thunk[1].pCode), patchCaptiveMoney2Thunk[1].dwSize, NULL);					
	//command int ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandIntAbilityThunk[1].dwAddr),\
					(LPVOID)(patchCommandIntAbilityThunk[1].pCode), patchCommandIntAbilityThunk[1].dwSize, NULL);
	//stone stop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchStoneStopThunk[1].dwAddr),\
					(LPVOID)(patchStoneStopThunk[1].pCode), patchStoneStopThunk[1].dwSize, NULL);
	//array image
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchArrayImageThunk[1].dwAddr),\
					(LPVOID)(patchArrayImageThunk[1].pCode), patchArrayImageThunk[1].dwSize, NULL);
	//move again
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveAgainThunk[1].dwAddr),\
					(LPVOID)(patchMoveAgainThunk[1].pCode), patchMoveAgainThunk[1].dwSize, NULL);
	//move idle person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMoveIdlePersonThunk[1].dwAddr),\
					(LPVOID)(patchMoveIdlePersonThunk[1].pCode), patchMoveIdlePersonThunk[1].dwSize, NULL);
	//degrade person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDegradePersonThunk[1].dwAddr),\
					(LPVOID)(patchDegradePersonThunk[1].pCode), patchDegradePersonThunk[1].dwSize, NULL);
	//intelligence ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceAbilityThunk[1].dwAddr),\
					(LPVOID)(patchIntelligenceAbilityThunk[1].pCode), patchIntelligenceAbilityThunk[1].dwSize, NULL);
	//del intelligence person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDelIntelligencePersonThunk[1].dwAddr),\
					(LPVOID)(patchDelIntelligencePersonThunk[1].pCode), patchDelIntelligencePersonThunk[1].dwSize, NULL);
	//undel intelligence person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUndelIntelligencePersonThunk[1].dwAddr),\
					(LPVOID)(patchUndelIntelligencePersonThunk[1].pCode), patchUndelIntelligencePersonThunk[1].dwSize, NULL);
	//jia xu back
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJiaXuBackThunk[1].dwAddr),\
					(LPVOID)(patchJiaXuBackThunk[1].pCode), patchJiaXuBackThunk[1].dwSize, NULL);
	//del command person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDelCommandPersonThunk[1].dwAddr),\
					(LPVOID)(patchDelCommandPersonThunk[1].pCode), patchDelCommandPersonThunk[1].dwSize, NULL);
	//undel command person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchUndelCommandPersonThunk[1].dwAddr),\
					(LPVOID)(patchUndelCommandPersonThunk[1].pCode), patchUndelCommandPersonThunk[1].dwSize, NULL);
	//jia xu officer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJiaXuOfficerThunk[1].dwAddr),\
					(LPVOID)(patchJiaXuOfficerThunk[1].pCode), patchJiaXuOfficerThunk[1].dwSize, NULL);
	//command ability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCommandAbilityThunk[1].dwAddr),\
					(LPVOID)(patchCommandAbilityThunk[1].pCode), patchCommandAbilityThunk[1].dwSize, NULL);
	//filter ready person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFilterReadyPersonThunk[1].dwAddr),\
					(LPVOID)(patchFilterReadyPersonThunk[1].pCode), patchFilterReadyPersonThunk[1].dwSize, NULL);
	//check officer money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckOfficerMoneyThunk[1].dwAddr),\
					(LPVOID)(patchCheckOfficerMoneyThunk[1].pCode), patchCheckOfficerMoneyThunk[1].dwSize, NULL);
	//pre building soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPreBuildingSoldierThunk[1].dwAddr),\
					(LPVOID)(patchPreBuildingSoldierThunk[1].pCode), patchPreBuildingSoldierThunk[1].dwSize, NULL);
	//max anti troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMaxAntiTroopThunk[1].dwAddr),\
					(LPVOID)(patchMaxAntiTroopThunk[1].pCode), patchMaxAntiTroopThunk[1].dwSize, NULL);
	//min danger dispatch
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDangerDispatchThunk[1].dwAddr),\
					(LPVOID)(patchMinDangerDispatchThunk[1].pCode), patchMinDangerDispatchThunk[1].dwSize, NULL);
	//save troop expense
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSaveTroopExpenseThunk[1].dwAddr),\
					(LPVOID)(patchSaveTroopExpenseThunk[1].pCode), patchSaveTroopExpenseThunk[1].dwSize, NULL);
	//switch foot horse
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSwitchFootHorseThunk[1].dwAddr),\
					(LPVOID)(patchSwitchFootHorseThunk[1].pCode), patchSwitchFootHorseThunk[1].dwSize, NULL);
	//adjust person pos
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAdjustPersonPosThunk[1].dwAddr),\
					(LPVOID)(patchAdjustPersonPosThunk[1].pCode), patchAdjustPersonPosThunk[1].dwSize, NULL);
	//check chaos
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckChaosThunk[1].dwAddr),\
					(LPVOID)(patchCheckChaosThunk[1].pCode), patchCheckChaosThunk[1].dwSize, NULL);
	//check abuse
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAbuseThunk[1].dwAddr),\
					(LPVOID)(patchCheckAbuseThunk[1].pCode), patchCheckAbuseThunk[1].dwSize, NULL);
	//defence horse wimble
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDefenceHorseWimbleThunk[1].dwAddr),\
					(LPVOID)(patchDefenceHorseWimbleThunk[1].pCode), patchDefenceHorseWimbleThunk[1].dwSize, NULL);
	//wisdom anti black art
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomAntiBlackArtThunk[1].dwAddr),\
					(LPVOID)(patchWisdomAntiBlackArtThunk[1].pCode), patchWisdomAntiBlackArtThunk[1].dwSize, NULL);
	//intelligence killer coef 2
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceKillerCoef2Thunk[1].dwAddr),\
					(LPVOID)(patchIntelligenceKillerCoef2Thunk[1].pCode), patchIntelligenceKillerCoef2Thunk[1].dwSize, NULL);
	//intelligence killer coef
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchIntelligenceKillerCoefThunk[1].dwAddr),\
					(LPVOID)(patchIntelligenceKillerCoefThunk[1].pCode), patchIntelligenceKillerCoefThunk[1].dwSize, NULL);
	//menu no display
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMenuNoDisplayThunk[1].dwAddr),\
					(LPVOID)(patchMenuNoDisplayThunk[1].pCode), patchMenuNoDisplayThunk[1].dwSize, NULL);
	//simple award
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSimpleAwardThunk[1].dwAddr),\
					(LPVOID)(patchSimpleAwardThunk[1].pCode), patchSimpleAwardThunk[1].dwSize, NULL);
	//battle disable task
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBattleDisableTaskThunk[1].dwAddr),\
					(LPVOID)(patchBattleDisableTaskThunk[1].pCode), patchBattleDisableTaskThunk[1].dwSize, NULL);
	//check attack troop anti
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAttackTroopAntiThunk[1].dwAddr),\
					(LPVOID)(patchCheckAttackTroopAntiThunk[1].pCode), patchCheckAttackTroopAntiThunk[1].dwSize, NULL);
	//check attack troop save
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckAttackTroopSaveThunk[1].dwAddr),\
					(LPVOID)(patchCheckAttackTroopSaveThunk[1].pCode), patchCheckAttackTroopSaveThunk[1].dwSize, NULL);
	//battle disable gossip
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBattleDisableGossipThunk[1].dwAddr),\
					(LPVOID)(patchBattleDisableGossipThunk[1].pCode), patchBattleDisableGossipThunk[1].dwSize, NULL);
	//troop siege power
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchTroopSiegePowerThunk[1].dwAddr),\
					(LPVOID)(patchTroopSiegePowerThunk[1].pCode), patchTroopSiegePowerThunk[1].dwSize, NULL);
	//fast relay
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFastRelayThunk[1].dwAddr),\
					(LPVOID)(patchFastRelayThunk[1].pCode), patchFastRelayThunk[1].dwSize, NULL);
	//relay dispatch success
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRelayDispatchOkThunk[1].dwAddr),\
					(LPVOID)(patchRelayDispatchOkThunk[1].pCode), patchRelayDispatchOkThunk[1].dwSize, NULL);
	//relay failed dispatch
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRelayFailedDispatchThunk[1].dwAddr),\
					(LPVOID)(patchRelayFailedDispatchThunk[1].pCode), patchRelayFailedDispatchThunk[1].dwSize, NULL);
	//same force dispatch
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSameForceDispatchThunk[1].dwAddr),\
					(LPVOID)(patchSameForceDispatchThunk[1].pCode), patchSameForceDispatchThunk[1].dwSize, NULL);
	//main force dispatch
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMainForceDispatchThunk[1].dwAddr),\
					(LPVOID)(patchMainForceDispatchThunk[1].pCode), patchMainForceDispatchThunk[1].dwSize, NULL);
	//building total soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingTotalSoldierThunk[1].dwAddr),\
					(LPVOID)(patchBuildingTotalSoldierThunk[1].pCode), patchBuildingTotalSoldierThunk[1].dwSize, NULL);
	//force troop list
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchForceTroopListThunk[1].dwAddr),\
					(LPVOID)(patchForceTroopListThunk[1].pCode), patchForceTroopListThunk[1].dwSize, NULL);
	//min building person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinBuildingPersonThunk[1].dwAddr),\
					(LPVOID)(patchMinBuildingPersonThunk[1].pCode), patchMinBuildingPersonThunk[1].dwSize, NULL);
	//alienate min day
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateMinDayThunk[1].dwAddr),\
					(LPVOID)(patchAlienateMinDayThunk[1].pCode), patchAlienateMinDayThunk[1].dwSize, NULL);
	//anti attack min defence
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAntiAttackMinDefenceThunk[1].dwAddr),\
					(LPVOID)(patchAntiAttackMinDefenceThunk[1].pCode), patchAntiAttackMinDefenceThunk[1].dwSize, NULL);
	//check no soldier building
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckNoSoldierBuildingThunk[1].dwAddr),\
					(LPVOID)(patchCheckNoSoldierBuildingThunk[1].pCode), patchCheckNoSoldierBuildingThunk[1].dwSize, NULL);
	//attack troop condition
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAttackTroopConditionThunk[1].dwAddr),\
					(LPVOID)(patchAttackTroopConditionThunk[1].pCode), patchAttackTroopConditionThunk[1].dwSize, NULL);
	//lower build expense
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchLowerBuildExpenseThunk[1].dwAddr),\
					(LPVOID)(patchLowerBuildExpenseThunk[1].pCode), patchLowerBuildExpenseThunk[1].dwSize, NULL);
	//full prize
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchFullPrizeThunk[1].dwAddr),\
					(LPVOID)(patchFullPrizeThunk[1].pCode), patchFullPrizeThunk[1].dwSize, NULL);
	//min dispatch soldier
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDispatchSoldierThunk[1].dwAddr),\
					(LPVOID)(patchMinDispatchSoldierThunk[1].pCode), patchMinDispatchSoldierThunk[1].dwSize, NULL);
	//dispatch person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDispatchPersonThunk[1].dwAddr),\
					(LPVOID)(patchDispatchPersonThunk[1].pCode), patchDispatchPersonThunk[1].dwSize, NULL);
	//wisdom person black art
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonBlackArtThunk[1].dwAddr),\
					(LPVOID)(patchWisdomPersonBlackArtThunk[1].pCode), patchWisdomPersonBlackArtThunk[1].dwSize, NULL);
	//wisdom person magic
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonMagicThunk[1].dwAddr),\
					(LPVOID)(patchWisdomPersonMagicThunk[1].pCode), patchWisdomPersonMagicThunk[1].dwSize, NULL);
	//wisdom person attack heart
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonAttackHeartThunk[1].dwAddr),\
					(LPVOID)(patchWisdomPersonAttackHeartThunk[1].pCode), patchWisdomPersonAttackHeartThunk[1].dwSize, NULL);
	//wisdom person abuse
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonAbuseThunk[1].dwAddr),\
					(LPVOID)(patchWisdomPersonAbuseThunk[1].pCode), patchWisdomPersonAbuseThunk[1].dwSize, NULL);
	//wisdom person
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomPersonThunk[1].dwAddr),\
					(LPVOID)(patchWisdomPersonThunk[1].pCode), patchWisdomPersonThunk[1].dwSize, NULL);
	//wisdom effective flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWisdomEffectivFlagThunk[1].dwAddr),\
					(LPVOID)(patchWisdomEffectivFlagThunk[1].pCode), patchWisdomEffectivFlagThunk[1].dwSize, NULL);
	//check troop pos
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckTroopPosThunk[1].dwAddr),\
					(LPVOID)(patchCheckTroopPosThunk[1].pCode), patchCheckTroopPosThunk[1].dwSize, NULL);
	//check min defence
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheckMinDefenceThunk[1].dwAddr),\
					(LPVOID)(patchCheckMinDefenceThunk[1].pCode), patchCheckMinDefenceThunk[1].dwSize, NULL);
	//keep attack flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKeepAttackFlagThunk[1].dwAddr),\
					(LPVOID)(patchKeepAttackFlagThunk[1].pCode), patchKeepAttackFlagThunk[1].dwSize, NULL);
	//chase flag
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchChaseFlagThunk[1].dwAddr),\
					(LPVOID)(patchChaseFlagThunk[1].pCode), patchChaseFlagThunk[1].dwSize, NULL);
	//dispatch troop
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDispatchTroopThunk[1].dwAddr),\
					(LPVOID)(patchDispatchTroopThunk[1].pCode), patchDispatchTroopThunk[1].dwSize, NULL);
	//not alienate garbage
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchNotAlienateGarbageThunk[1].dwAddr),\
					(LPVOID)(patchNotAlienateGarbageThunk[1].pCode), patchNotAlienateGarbageThunk[1].dwSize, NULL);
	//enable cultivate
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableCultivateThunk[1].dwAddr),\
					(LPVOID)(patchEnableCultivateThunk[1].pCode), patchEnableCultivateThunk[1].dwSize, NULL);
	//enable commerce
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableCommerceThunk[1].dwAddr),\
					(LPVOID)(patchEnableCommerceThunk[1].pCode), patchEnableCommerceThunk[1].dwSize, NULL);
	//before go
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBeforeGoThunk[1].dwAddr),\
					(LPVOID)(patchBeforeGoThunk[1].pCode), patchBeforeGoThunk[1].dwSize, NULL);
	//enable draft
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchEnableDraftThunk[1].dwAddr),\
					(LPVOID)(patchEnableDraftThunk[1].pCode), patchEnableDraftThunk[1].dwSize, NULL);
	//sub journey expense
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSubJourneyExpenseThunk[1].dwAddr),\
					(LPVOID)(patchSubJourneyExpenseThunk[1].pCode), patchSubJourneyExpenseThunk[1].dwSize, NULL);
	//journey expense
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchJourneyExpenseThunk[1].dwAddr),\
					(LPVOID)(patchJourneyExpenseThunk[1].pCode), patchJourneyExpenseThunk[1].dwSize, NULL);
	//person judgement
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchPersonJudgementThunk[1].dwAddr),\
					(LPVOID)(patchPersonJudgementThunk[1].pCode), patchPersonJudgementThunk[1].dwSize, NULL);
	//rob money
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchRobMoneyThunk[1].dwAddr),\
					(LPVOID)(patchRobMoneyThunk[1].pCode), patchRobMoneyThunk[1].dwSize, NULL);
	//inspire experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchInspireExperienceThunk[1].dwAddr),\
					(LPVOID)(patchInspireExperienceThunk[1].pCode), patchInspireExperienceThunk[1].dwSize, NULL);
	//disorder experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchDisorderExperienceThunk[1].dwAddr),\
					(LPVOID)(patchDisorderExperienceThunk[1].pCode), patchDisorderExperienceThunk[1].dwSize, NULL);
	//cheat experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchCheatExperienceThunk[1].dwAddr),\
					(LPVOID)(patchCheatExperienceThunk[1].pCode), patchCheatExperienceThunk[1].dwSize, NULL);
	//gossip experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchGossipExperienceThunk[1].dwAddr),\
					(LPVOID)(patchGossipExperienceThunk[1].pCode), patchGossipExperienceThunk[1].dwSize, NULL);
	//alienate experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchAlienateExperienceThunk[1].dwAddr),\
					(LPVOID)(patchAlienateExperienceThunk[1].pCode), patchAlienateExperienceThunk[1].dwSize, NULL);
	//killer experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchKillerExperienceThunk[1].dwAddr),\
					(LPVOID)(patchKillerExperienceThunk[1].pCode), patchKillerExperienceThunk[1].dwSize, NULL);
	//water killer experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchWaterKillerExperienceThunk[1].dwAddr),\
					(LPVOID)(patchWaterKillerExperienceThunk[1].pCode), patchWaterKillerExperienceThunk[1].dwSize, NULL);
	//siege experience
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchSiegeExperienceThunk[1].dwAddr),\
							(LPVOID)(patchSiegeExperienceThunk[1].pCode), patchSiegeExperienceThunk[1].dwSize, NULL);
	//building killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchBuildingKillerThunk[1].dwAddr),\
							(LPVOID)(patchBuildingKillerThunk[1].pCode), patchBuildingKillerThunk[1].dwSize, NULL);
	//harbor killer
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchHarborKillerThunk[1].dwAddr),\
							(LPVOID)(patchHarborKillerThunk[1].pCode), patchHarborKillerThunk[1].dwSize, NULL);
	//min durability
	::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(patchMinDurabilityThunk[1].dwAddr),\
							(LPVOID)(patchMinDurabilityThunk[1].pCode), patchMinDurabilityThunk[1].dwSize, NULL);

//page property
	::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwSearchRangePageAddr, m_dwPageSize,
																PAGE_EXECUTE_READ, &m_dwProcessId);
	::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwFriendshipPageAddr, m_dwPageSize, PAGE_READONLY, &m_dwProcessId);
	::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwCaptionPageAddr, m_dwPageSize, PAGE_READONLY, &m_dwProcessId);
	::VirtualProtectEx(m_hSan9PKProcess, (DWORD *)m_dwCommonDataPageAddr, m_dwPageSize,
																PAGE_EXECUTE_READ, &m_dwProcessId);
//de-commit page on stack bottom
	::VirtualFreeEx(m_hSan9PKProcess, (DWORD *)dwAddrStackBottom, m_dwAllocPageNum*m_dwPageSize, MEM_DECOMMIT);
/*
	FILE *file = fopen("data.txt", "wt");
	int data[58*3];
	BOOL bS = ::ReadProcessMemory(m_hSan9PKProcess, (LPVOID)0x610740, data, 58*3*4, 0);
	for (i=0; i<58*3; i++)
	{
	    if (i%3==0) fprintf(file, "\n");
		fprintf(file, "%d\t", data[i]);
	}
	fclose(file);
*/
//close process
	::CloseHandle(m_hSan9PKProcess);
	m_hSan9PKProcess = NULL;
	m_hSan9PKWnd = NULL;
}

void CSan9PKHardDlg::OnCancel()
{
	//unmodify and release game
	UndoModify();

	//release system resources
	if (m_uTimerID != 0)
	{
		KillTimer(m_uTimerID);
	}

	CDialog::OnCancel();
}

void CSan9PKHardDlg::WriteCodeOnStack(UINT message, UINT address)
{
	BOOL bSuccess = FALSE;
	CString str;

	if (message == MSG_SEARCH_SELECT)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(address), (LPVOID)(codeSearchSelectOnStack),
																		sizeof(codeSearchSelectOnStack), NULL);
		if (bSuccess == FALSE)
		{
			str.Format("%d : error=%d", ERR_WRITE_STACK_SEARCH_SELECT, ::GetLastError());
			goto end_write_code_on_stack;
		}
	}
	else if (message == MSG_SEARCH_PERFORM)
	{
		bSuccess = ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(address), (LPVOID)(codeSearchPerformOnStack),
																		sizeof(codeSearchPerformOnStack), NULL);
		if (bSuccess == FALSE)
		{
			str.Format("%d : error=%d", ERR_WRITE_STACK_SEARCH_PERFORM, ::GetLastError());
			goto end_write_code_on_stack;
		}
	}
	return;

end_write_code_on_stack:
	++m_iErrCount;
	m_ctrlStatus.SetWindowText(str);
}

LRESULT CSan9PKHardDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	int msg, arg;
	CString str;

	if (message == m_sWndMsg.uMsg)
	{
		msg = wParam;
		arg = lParam;
		if (m_eState == STATE_FREE)//空闲状态
		{
			switch(msg)
			{
			case MSG_UPDATE_END :
				if (arg != 0)//arg=加载存档成功标志
				{
					ModifySan9PK(MODIFY_LOAD_SCENE);
				}
			break;

			case MSG_CHANGE_INTERFACE :
				if (arg == INTERFACE_SCENE)//进入设置新游戏
				{
					m_eState = STATE_WAIT_SCENE;
				}
			break;

			case MSG_SEARCH_SELECT ://多人探索
			case MSG_SEARCH_PERFORM :
					WriteCodeOnStack(msg, arg);
			break;

			default:
			break;
			}
		}
		else if (m_eState == STATE_WAIT_SCENE)//设置新游戏的状态
		{
			if (msg == MSG_CHANGE_INTERFACE)
			{
				if (arg == INTERFACE_MAIN)//返回主界面
				{
					m_eState = STATE_FREE;
				}
				else if (arg == INTERFACE_GAME)//开始新游戏
				{
					ModifySan9PK(MODIFY_NEW_SCENE);
					m_eState = STATE_FREE;
				}
			}
		}
	}

	return CDialog::WindowProc(message, wParam, lParam);
}

void CSan9PKHardDlg::OnParaSetting() 
{
	CParaSettingDlg dlg;
	int i = 0;

	//资金分隔点
	dlg.m_uMoneyCut_1 = m_uMoneyCut_1;
	dlg.m_uMoneyCut_2 = m_uMoneyCut_2;
	dlg.m_uMoneyCut_3 = m_uMoneyCut_3;
	//兵粮分隔点
	dlg.m_uFoodCut_1 = m_uFoodCut_1;
	dlg.m_uFoodCut_2 = m_uFoodCut_2;
	dlg.m_uFoodCut_3 = m_uFoodCut_3;
	//兵役分隔点
	dlg.m_uDraftCut_1 = m_uDraftCut_1;
	dlg.m_uDraftCut_2 = m_uDraftCut_2;
	dlg.m_uDraftCut_3 = m_uDraftCut_3;

	//难度选项
	dlg.m_bEnableTrain = m_bEnableTrain;
	dlg.m_bDisableKillPerson = m_bDisableKillPerson;
	dlg.m_bNpcAllieAttack = m_bNpcAllieAttack;
	dlg.m_bSubCounsellorJudge = m_bSubCounsellorJudge;
	dlg.m_bAddNpcMoneyFood = m_bAddNpcMoneyFood;
	dlg.m_bEnableRelayDispatch = m_bEnableRelayDispatch;
	dlg.m_bDispatchSoldierToPlayer = m_bDispatchSoldierToPlayer;
	dlg.m_bDisableSearchEvent = m_bDisableSearchEvent;
	dlg.m_bEnableBaramArray = m_bEnableBaramArray;
	dlg.m_bSearchMaxAbility = m_bSearchMaxAbility;
	dlg.m_bSubRobFood = m_bSubRobFood;
	dlg.m_bWarFog = m_bWarFog;
	dlg.m_bNotSureCaptive = m_bNotSureCaptive;
	dlg.m_bNullCitySubMunicipal = m_bNullCitySubMunicipal;
	dlg.m_bNpcSearchTreasure = m_bNpcSearchTreasure;
	dlg.m_bNpcAutoDraft = m_bNpcAutoDraft;
	dlg.m_bDisableMovePerson = m_bDisableMovePerson;
		
	//新增选项
	dlg.m_bBarbarianNotDisappear = m_bBarbarianNotDisappear;	
	dlg.m_bAddKillerJianyu = m_bAddKillerJianyu;
	dlg.m_bDisableKillerJianlan =  m_bDisableKillerJianlan;
	dlg.m_bNotDisplaySlash =  m_bNotDisplaySlash;
	dlg.m_bNotDisplayExchange =  m_bNotDisplayExchange;	
	dlg.m_bEnableCityPopulationCoef =  m_bEnableCityPopulationCoef;		

	//系统选项
	dlg.m_bAllPersonLive = m_bAllPersonLive;
	dlg.m_bAllPersonDead = m_bAllPersonDead;
	dlg.m_bGeneralDead = m_bGeneralDead;
	dlg.m_bDisableAlienate = m_bDisableAlienate;
	dlg.m_bSoldierCommandKiller = m_bSoldierCommandKiller;
	dlg.m_bSecondKiller = m_bSecondKiller;
	dlg.m_bFriendToAlienate = m_bFriendToAlienate;
	dlg.m_bSubWoundSoldier = m_bSubWoundSoldier;
	dlg.m_bDisableNpcPlotForce = m_bDisableNpcPlotForce;
	dlg.m_bBurnFood = m_bBurnFood;
	dlg.m_bDisableBurn = m_bDisableBurn;
	dlg.m_bMunicipalDraft = m_bMunicipalDraft;
	dlg.m_bDoubleBuildingDefense = m_bDoubleBuildingDefense;
	dlg.m_bNotAddDraft = m_bNotAddDraft;
	dlg.m_bAlikeKillerLinkage = m_bAlikeKillerLinkage;
	dlg.m_bDynamicAddProficiency = m_bDynamicAddProficiency;
	dlg.m_bDynamicAddAbility =  m_bDynamicAddAbility;
	dlg.m_bChangeTroopCommand = m_bChangeTroopCommand;
	dlg.m_bWeakenLongRangeKiller = m_bWeakenLongRangeKiller;
	dlg.m_bMunicipalForceDraft = m_bMunicipalForceDraft;
	dlg.m_bUpdateWaterKillerProp = m_bUpdateWaterKillerProp;
	dlg.m_bMinDurabilityZero = m_bMinDurabilityZero;
	dlg.m_bUpdateZoneCity = m_bUpdateZoneCity;
	dlg.m_bFightKillerProp = m_bFightKillerProp;
	dlg.m_bGooseKillerLinkage = m_bGooseKillerLinkage;
	dlg.m_bSoldierSubKiller = m_bSoldierSubKiller;
	dlg.m_bPlayerAutoProcess = m_bPlayerAutoProcess;
	dlg.m_bLowDurabilityChaos = m_bLowDurabilityChaos;
	dlg.m_bLeaderInspire = m_bLeaderInspire;
	dlg.m_bKillAddProficiency = m_bKillAddProficiency;
	dlg.m_bAbilityKillerProp = m_bAbilityKillerProp;

	//系统参数
	dlg.m_iYearDifference = m_iYearDifference;
	dlg.m_uKillerPowerCoef = m_uKillerPowerCoef;
	dlg.m_uSlashDeadCoef = m_uSlashDeadCoef;
	dlg.m_uNoOfficialSalary = m_uNoOfficialSalary;
	dlg.m_uBlockPropCoef = m_uBlockPropCoef;
	dlg.m_uNpcAttackDisorder = m_uNpcAttackDisorder;
	dlg.m_uNatureAttractCoef = m_uNatureAttractCoef;
	dlg.m_uOnePersonKillerProp = m_uOnePersonKillerProp;//部队武将数兵法概率系数
	dlg.m_uTwoPersonKillerProp = m_uTwoPersonKillerProp;
	dlg.m_uThreePersonKillerProp = m_uThreePersonKillerProp;
	dlg.m_uFourPersonKillerProp = m_uFourPersonKillerProp;
	dlg.m_uFivePersonKillerProp = m_uFivePersonKillerProp;
	dlg.m_uAntiPlayerLeagueCoef = m_uAntiPlayerLeagueCoef;
	dlg.m_uLeagueTime = m_uLeagueTime;
	dlg.m_uFightSubIncomeCoef = m_uFightSubIncomeCoef;
	dlg.m_uBasicAbilityCoef = m_uBasicAbilityCoef;
	dlg.m_uSexCoef = m_uSexCoef;
	dlg.m_uMaxCaptiveCoef = m_uMaxCaptiveCoef;

	//战争迷雾
	dlg.m_uCityViewRange = m_uCityViewRange;
	dlg.m_uBuildingViewRange = m_uBuildingViewRange;
	dlg.m_uTroopViewRange = m_uTroopViewRange;
	dlg.m_uSoldierDisplayError = m_uSoldierDisplayError;
	dlg.m_uCounselorReportCoef = m_uCounselorReportCoef;

	if (dlg.DoModal() == IDOK)
	{
		//资金分隔点
		m_uMoneyCut_1 = dlg.m_uMoneyCut_1;
		m_uMoneyCut_2 = dlg.m_uMoneyCut_2;
		m_uMoneyCut_3 = dlg.m_uMoneyCut_3;
		//兵粮分隔点
		m_uFoodCut_1 = dlg.m_uFoodCut_1;
		m_uFoodCut_2 = dlg.m_uFoodCut_2;
		m_uFoodCut_3 = dlg.m_uFoodCut_3;
		//兵役分隔点
		m_uDraftCut_1 = dlg.m_uDraftCut_1;
		m_uDraftCut_2 = dlg.m_uDraftCut_2;
		m_uDraftCut_3 = dlg.m_uDraftCut_3;

		//难度选项
		m_bEnableTrain = dlg.m_bEnableTrain;
		m_bDisableKillPerson = dlg.m_bDisableKillPerson;
		m_bNpcAllieAttack = dlg.m_bNpcAllieAttack;
		m_bSubCounsellorJudge = dlg.m_bSubCounsellorJudge;
		m_bAddNpcMoneyFood = dlg.m_bAddNpcMoneyFood;
		m_bEnableRelayDispatch = dlg.m_bEnableRelayDispatch;
		m_bDispatchSoldierToPlayer = dlg.m_bDispatchSoldierToPlayer;
		m_bDisableSearchEvent = dlg.m_bDisableSearchEvent;
		m_bEnableBaramArray = dlg.m_bEnableBaramArray;
		m_bSearchMaxAbility = dlg.m_bSearchMaxAbility;
		m_bSubRobFood = dlg.m_bSubRobFood;
		m_bWarFog = dlg.m_bWarFog;
		m_bNotSureCaptive = dlg.m_bNotSureCaptive;
		m_bNullCitySubMunicipal = dlg.m_bNullCitySubMunicipal;
		m_bNpcSearchTreasure = dlg.m_bNpcSearchTreasure;
		m_bNpcAutoDraft = dlg.m_bNpcAutoDraft;
		m_bDisableMovePerson = dlg.m_bDisableMovePerson;
		
		//新增选项
	    m_bBarbarianNotDisappear = dlg.m_bBarbarianNotDisappear;		
		m_bAddKillerJianyu = dlg.m_bAddKillerJianyu;
		m_bDisableKillerJianlan = dlg.m_bDisableKillerJianlan;
	    m_bNotDisplaySlash = dlg.m_bNotDisplaySlash;
	    m_bNotDisplayExchange = dlg.m_bNotDisplayExchange;	
	    m_bEnableCityPopulationCoef = dlg.m_bEnableCityPopulationCoef;		
		
		//系统选项
		m_bAllPersonLive = dlg.m_bAllPersonLive;
		m_bAllPersonDead = dlg.m_bAllPersonDead;
		m_bGeneralDead = dlg.m_bGeneralDead;
		m_bDisableAlienate = dlg.m_bDisableAlienate;
		m_bSoldierCommandKiller = dlg.m_bSoldierCommandKiller;
		m_bSecondKiller = dlg.m_bSecondKiller;
		m_bFriendToAlienate = dlg.m_bFriendToAlienate;
		m_bSubWoundSoldier = dlg.m_bSubWoundSoldier;
		m_bDisableNpcPlotForce = dlg.m_bDisableNpcPlotForce;
		m_bBurnFood = dlg.m_bBurnFood;
		m_bDisableBurn = dlg.m_bDisableBurn;
		m_bMunicipalDraft = dlg.m_bMunicipalDraft;
		m_bDoubleBuildingDefense = dlg.m_bDoubleBuildingDefense;
		m_bNotAddDraft = dlg.m_bNotAddDraft;
		m_bAlikeKillerLinkage = dlg.m_bAlikeKillerLinkage;
		m_bDynamicAddProficiency = dlg.m_bDynamicAddProficiency;
		m_bDynamicAddAbility = dlg.m_bDynamicAddAbility;
		m_bChangeTroopCommand = dlg.m_bChangeTroopCommand;
		m_bWeakenLongRangeKiller = dlg.m_bWeakenLongRangeKiller;
		m_bMunicipalForceDraft = dlg.m_bMunicipalForceDraft;
		m_bUpdateWaterKillerProp = dlg.m_bUpdateWaterKillerProp;
		m_bMinDurabilityZero = dlg.m_bMinDurabilityZero;
		m_bUpdateZoneCity = dlg.m_bUpdateZoneCity;
		m_bFightKillerProp = dlg.m_bFightKillerProp;
		m_bGooseKillerLinkage = dlg.m_bGooseKillerLinkage;
		m_bSoldierSubKiller = dlg.m_bSoldierSubKiller;
		m_bPlayerAutoProcess = dlg.m_bPlayerAutoProcess;
		m_bLowDurabilityChaos = dlg.m_bLowDurabilityChaos;
		m_bLeaderInspire = dlg.m_bLeaderInspire;
		m_bKillAddProficiency = dlg.m_bKillAddProficiency;
		m_bAbilityKillerProp = dlg.m_bAbilityKillerProp;


		//系统参数
		m_iYearDifference = dlg.m_iYearDifference;
		m_uKillerPowerCoef = dlg.m_uKillerPowerCoef;
		m_uSlashDeadCoef = dlg.m_uSlashDeadCoef;
		m_uNoOfficialSalary = dlg.m_uNoOfficialSalary;
		m_uBlockPropCoef = dlg.m_uBlockPropCoef;
		m_uNpcAttackDisorder = dlg.m_uNpcAttackDisorder;
		m_uNatureAttractCoef = dlg.m_uNatureAttractCoef;
		m_uOnePersonKillerProp = dlg.m_uOnePersonKillerProp;//部队武将数兵法概率系数
		m_uTwoPersonKillerProp = dlg.m_uTwoPersonKillerProp;
		m_uThreePersonKillerProp = dlg.m_uThreePersonKillerProp;
		m_uFourPersonKillerProp = dlg.m_uFourPersonKillerProp;
		m_uFivePersonKillerProp = dlg.m_uFivePersonKillerProp;
		m_uAntiPlayerLeagueCoef = dlg.m_uAntiPlayerLeagueCoef;
		m_uLeagueTime = dlg.m_uLeagueTime;
		m_uFightSubIncomeCoef = dlg.m_uFightSubIncomeCoef;
		m_uBasicAbilityCoef = dlg.m_uBasicAbilityCoef;
		m_uSexCoef = dlg.m_uSexCoef;
		m_uMaxCaptiveCoef = dlg.m_uMaxCaptiveCoef;

		//战争迷雾
		m_uCityViewRange = dlg.m_uCityViewRange;
		m_uBuildingViewRange = dlg.m_uBuildingViewRange;
		m_uTroopViewRange = dlg.m_uTroopViewRange;
		m_uSoldierDisplayError = dlg.m_uSoldierDisplayError;
		m_uCounselorReportCoef = dlg.m_uCounselorReportCoef;

		//应用设置参数
		ModifySan9PK(MODIFY_SETTING);
	}
	else
	{
		//清除所有配置读取标志
		m_bCityConfigRead = FALSE;
		m_btKillerConfigRead &= ~2;
		m_btArrayConfigRead &= ~2;
	}
}

void CSan9PKHardDlg::LoadConfig()
{
	CStdioFile file;
	CString str;
	DWORD m_dwComboData = 0;
	int i = 0;

//读参数设置文件

	if (file.Open("San9PKHardPara.txt", CFile::modeRead | CFile::shareDenyWrite | CFile::typeText) == FALSE)
	{
		goto read_person_config_file;
	}

	try
	{
		//分隔点
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uMoneyCut_1 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uMoneyCut_2 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uMoneyCut_3 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFoodCut_1 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFoodCut_2 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFoodCut_3 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uDraftCut_1 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uDraftCut_2 = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uDraftCut_3 = atoi(LPCTSTR(str));
		//战争迷雾
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uCityViewRange = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uBuildingViewRange = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uTroopViewRange = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uSoldierDisplayError = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uCounselorReportCoef = atoi(LPCTSTR(str));
		//难度选项
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_dwComboData = atoi(LPCTSTR(str));
		m_bEnableTrain = m_dwComboData & 1;
		m_bDisableKillPerson = (m_dwComboData>>1) & 1;
		m_bNpcAllieAttack = (m_dwComboData>>2) & 1;
		m_bSubCounsellorJudge = (m_dwComboData>>3) & 1;
		m_bAddNpcMoneyFood =  (m_dwComboData>>4) & 1;
		m_bEnableRelayDispatch = (m_dwComboData>>5) & 1;
		m_bDispatchSoldierToPlayer = (m_dwComboData>>6) & 1;
		m_bDisableSearchEvent = (m_dwComboData>>7) & 1;
		m_bEnableBaramArray = (m_dwComboData>>8) & 1;
		m_bSearchMaxAbility = (m_dwComboData>>9) & 1;
		m_bSubRobFood = (m_dwComboData>>10) & 1;
		m_bWarFog = (m_dwComboData>>11) & 1;
		m_bNotSureCaptive = (m_dwComboData>>12) & 1;
		m_bNullCitySubMunicipal = (m_dwComboData>>13) & 1;
		m_bNpcSearchTreasure = (m_dwComboData>>14) & 1;
		m_bNpcAutoDraft = (m_dwComboData>>15) & 1;
		m_bDisableMovePerson = (m_dwComboData>>16) & 1;
		//新增选项
		m_bBarbarianNotDisappear = (m_dwComboData>>17) & 1;
		m_bAddKillerJianyu = (m_dwComboData>>18) & 1;
		m_bDisableKillerJianlan = (m_dwComboData>>19) & 1;	
		m_bNotDisplaySlash = (m_dwComboData>>20) & 1;	
		m_bNotDisplayExchange = (m_dwComboData>>21) & 1;	
		m_bEnableCityPopulationCoef = (m_dwComboData>>22) & 1;			
		//系统选项
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_dwComboData = atoi(LPCTSTR(str));
		m_bSoldierSubKiller = m_dwComboData & 1;
		m_bAllPersonLive = (m_dwComboData>>1) & 1;
		m_bAllPersonDead = (m_dwComboData>>2) & 1;
		m_bDisableAlienate = (m_dwComboData>>3) & 1;
		m_bSoldierCommandKiller = (m_dwComboData>>4) & 1;
		m_bSecondKiller = (m_dwComboData>>5) & 1;
		m_bFriendToAlienate = (m_dwComboData>>6) & 1;
		m_bSubWoundSoldier = (m_dwComboData>>7) & 1;
		m_bDisableNpcPlotForce = (m_dwComboData>>8) & 1;
		m_bBurnFood = (m_dwComboData>>9) & 1;
		m_bDisableBurn = (m_dwComboData>>10) & 1;
		m_bMunicipalDraft = (m_dwComboData>>11) & 1;
		m_bDoubleBuildingDefense = (m_dwComboData>>12) & 1;
		m_bNotAddDraft = (m_dwComboData>>13) & 1;
		m_bAlikeKillerLinkage = (m_dwComboData>>14) & 1;
		m_bDynamicAddProficiency = (m_dwComboData>>15) & 1;
		m_bDynamicAddAbility = (m_dwComboData>>16) & 1;
		m_bChangeTroopCommand = (m_dwComboData>>17) & 1;
		m_bWeakenLongRangeKiller = (m_dwComboData>>18) & 1;
		m_bMunicipalForceDraft = (m_dwComboData>>19) & 1;
		m_bUpdateWaterKillerProp = (m_dwComboData>>20) & 1;
		m_bMinDurabilityZero =  (m_dwComboData>>21) & 1;
		m_bUpdateZoneCity = (m_dwComboData>>22) & 1;
		m_bFightKillerProp = (m_dwComboData>>23) & 1;
		m_bGooseKillerLinkage = (m_dwComboData>>24) & 1;
		m_bPlayerAutoProcess = (m_dwComboData>>25) & 1;
		m_bLowDurabilityChaos = (m_dwComboData>>26) & 1;
		m_bLeaderInspire = (m_dwComboData>>27) & 1;
		m_bKillAddProficiency = (m_dwComboData>>28) & 1;
		m_bGeneralDead = (m_dwComboData>>29) & 1;
		m_bAbilityKillerProp = (m_dwComboData>>30) & 1;
		//系统参数
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_iYearDifference = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uKillerPowerCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uSlashDeadCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uNoOfficialSalary = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uBlockPropCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uNpcAttackDisorder = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uNatureAttractCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;//部队武将数兵法概率系数
		m_uOnePersonKillerProp = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uTwoPersonKillerProp = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uThreePersonKillerProp = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFourPersonKillerProp = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFivePersonKillerProp = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uAntiPlayerLeagueCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uLeagueTime = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uFightSubIncomeCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uBasicAbilityCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uSexCoef = atoi(LPCTSTR(str));
		if (file.ReadString(str) == FALSE) goto read_error_para;
		m_uMaxCaptiveCoef = atoi(LPCTSTR(str));
	}
	catch(CFileException e)
	{
		str.Format("读设置参数文件失败!(%d, %d)", e.m_cause, e.m_lOsError);
		AfxMessageBox(str);
		goto end_read_para;
	}

	goto end_read_para;

read_error_para:
	AfxMessageBox("设置参数不完整!");

end_read_para:
	file.Close();

//读武将配置文件
read_person_config_file:

	if (file.Open("San9PKHardPerson.txt", CFile::modeRead | CFile::shareDenyWrite | CFile::typeText) == FALSE)
	{
		goto read_city_config_file;
	}

	try
	{
		for (i=0; i<CONFIG_PERSON_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_person;
			m_dwPersonConfigInfo[i] = atoi(LPCTSTR(str));
		}
		for (i=0; i<PERSON_FRIENDSHIP_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_person;
			int iFriendship = atoi(LPCTSTR(str));
			m_wPersonFriendship[i][0] = (iFriendship&0x3FF);
			m_wPersonFriendship[i][1] = ((iFriendship>>10)&0x3FF);
			m_wPersonFriendship[i][2] = ((iFriendship>>20)&0x3F);
		}
		if (file.ReadString(str) == FALSE) goto read_error_person;
		m_wMaxExperience = atoi(LPCTSTR(str));
	}
	catch(CFileException e)
	{
		str.Format("读武将配置文件失败!(%d, %d)", e.m_cause, e.m_lOsError);
		AfxMessageBox(str);
		goto end_read_person;
	}

	goto end_read_person;

read_error_person:
	AfxMessageBox("武将配置参数不完整!");

end_read_person:
	file.Close();

//读都市配置文件
read_city_config_file:

	LoadCityConfig();

//读兵法配置文件
	LoadKillerConfig();

//读阵型配置文件
	LoadArrayConfig();
}

void CSan9PKHardDlg::LoadCityConfig(bool bSelectFileFlag)
{
	CStdioFile file;
	CString str = "San9PKHardCity.txt";//默认都市配置文件
	int i = 0;
	char szFilter[] = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, str, OFN_HIDEREADONLY, szFilter, this);

	if (bSelectFileFlag != false)
	{
		if (dlg.DoModal() != IDOK)
			return;
		str = dlg.GetPathName();//读取配置文件路径名
	}

	//读都市配置文件
	if (file.Open(str, CFile::modeRead | CFile::shareDenyWrite | CFile::typeText) == FALSE)
	{
		if (bSelectFileFlag != false)
		{
			AfxMessageBox("打开都市配置文件失败!");
		}
		return;
	}

	try
	{
		for (i=0; i<CITY_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_city;
			*((int*)(&m_CityConfigInfo[i])) = atoi(LPCTSTR(str));
			if (file.ReadString(str) == FALSE) goto read_error_city;
			*(((short*)(&m_CityConfigInfo[i]))+2) = atoi(LPCTSTR(str));
		}
		m_bCityConfigAuto = TRUE;//都市配置自动标志=1
		//都市攻防关系
		for (i=0; i<CITY_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_city;
			m_dwCityRelationInfo[i*2] = atoi(LPCTSTR(str));//都市攻防关系1
			if (file.ReadString(str) == FALSE) goto read_error_city;
			m_dwCityRelationInfo[i*2+1] = atoi(LPCTSTR(str));//都市攻防关系2
			if (file.ReadString(str) == FALSE) goto read_error_city;
			m_btAttackCityMaxDay[i] = atoi(LPCTSTR(str));
		}
	}
	catch(CFileException e)
	{
		str.Format("读都市配置文件失败!(%d, %d)", e.m_cause, e.m_lOsError);
		AfxMessageBox(str);
		goto end_read_city;
	}

	goto end_read_city;

read_error_city:
	AfxMessageBox("都市配置参数不完整!");

end_read_city:
	file.Close();
}

void CSan9PKHardDlg::LoadKillerConfig()
{
	CStdioFile file;
	int i = 0;
	CString str;

	//读兵法配置文件
	if (file.Open("San9PKHardSkill.txt", CFile::modeRead | CFile::shareDenyWrite | CFile::typeText) == FALSE)
	{
		return;
	}

	try
	{
		for (i=0; i<KILLER_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_killer;
			*((int*)&m_KillerConfigInfo[i]) = atoi(LPCTSTR(str));
		}
		m_btKillerConfigRead |= 1;//配置文件读取标志=1
	}
	catch(CFileException e)
	{
		str.Format("读兵法配置文件失败!(%d, %d)", e.m_cause, e.m_lOsError);
		AfxMessageBox(str);
		goto end_read_killer;
	}

	goto end_read_killer;

read_error_killer:
	AfxMessageBox("兵法配置参数不完整!");

end_read_killer:
	file.Close();

}

void CSan9PKHardDlg::LoadArrayConfig()
{
	CStdioFile file;
	int i = 0;
	CString str;

	//读阵型配置文件
	if (file.Open("San9PKHardArray.txt", CFile::modeRead | CFile::shareDenyWrite | CFile::typeText) == FALSE)
	{
		return;
	}

	try
	{
		for (i=0; i<ARRAY_NUM; i++)
		{
			if (file.ReadString(str) == FALSE) goto read_error_array;
			m_ArrayConfigInfo[i].dwAttackDefence = atoi(LPCTSTR(str));
			if (file.ReadString(str) == FALSE) goto read_error_array;
			 *((int*)&m_ArrayConfigInfo[i].wrView) = atoi(LPCTSTR(str));
		}
		m_btArrayConfigRead |= 1;//配置文件读取标志=1
	}
	catch(CFileException e)
	{
		str.Format("读阵型配置文件失败!(%d, %d)", e.m_cause, e.m_lOsError);
		AfxMessageBox(str);
		goto end_read_array;
	}

	goto end_read_array;

read_error_array:
	AfxMessageBox("阵型配置参数不完整!");

end_read_array:
	file.Close();
}

void CSan9PKHardDlg::Big2Gb(char *sBig)
{
	char* pszBig5=NULL; //Big5编码的字符
	wchar_t* wszUnicode=NULL; //Unicode编码的字符
	char* pszGbt=NULL; //Gb编码的繁体字符
	char* pszGbs=NULL; //Gb编码的简体字符
	int iLen=0; //需要转换的字符数

	pszBig5 = sBig; //读入需要转换的字符参数

	//计算转换的字符数
	iLen=MultiByteToWideChar (950, 0, pszBig5, -1, NULL,0) ;
	//给wszUnicode分配内存
	wszUnicode=new wchar_t[iLen+1];
	//转换Big5码到Unicode码，使用了API函数MultiByteToWideChar
	MultiByteToWideChar (950, 0, pszBig5, -1, wszUnicode,iLen);

	//计算转换的字符数
	iLen=WideCharToMultiByte (936, 0, (PWSTR) wszUnicode, -1, NULL,0, NULL, NULL) ;
	//给pszGbt分配内存
	pszGbt=new char[iLen+1];
	//给pszGbs分配内存
	pszGbs=new char[iLen+1];
	//转换Unicode码到Gb码繁体，使用API函数WideCharToMultiByte
	WideCharToMultiByte (936, 0, (PWSTR) wszUnicode, -1, pszGbt,iLen, NULL, NULL) ;

	//转换Gb码繁体到Gb码简体，使用API函数LCMapString
	LCMapString(0x0804,LCMAP_SIMPLIFIED_CHINESE, pszGbt, -1, pszGbs, iLen);

	//返回Gb码简体字符
	strcpy(sBig,pszGbs);

	//释放内存
	delete [] wszUnicode;
	delete [] pszGbt;
	delete [] pszGbs;
} 

BOOL CSan9PKHardDlg::UpdateZoneCity(BOOL bUpdate)
{
	DWORD cityIndex;

	//官渡:洛阳=>濮阳
	cityIndex = (bUpdate==FALSE ? 15 : 9);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[48]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//东平:濮阳=>陈留
	cityIndex = (bUpdate==FALSE ? 9 : 10);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[31]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//泰山:濮阳=>小沛
	cityIndex = (bUpdate==FALSE ? 9 : 12);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[32]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//平阳:洛阳=>上党
	cityIndex = (bUpdate==FALSE ? 15 : 7);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[46]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//陈仓:安定=>天水
	cityIndex = (bUpdate==FALSE ? 17 : 18);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[59]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//南海:交趾=>桂阳
	cityIndex = (bUpdate==FALSE ? 44 : 34);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[131]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	//汨罗:长沙=>桂阳
	cityIndex = (bUpdate==FALSE ? 32 : 34);
	if (FALSE == ::WriteProcessMemory(m_hSan9PKProcess, (LPVOID)(m_dwZoneAddr[100]+0x44),\
									(LPVOID)(&m_dwCityAddr[cityIndex]), DWORD_SIZE, NULL))
	{	return FALSE;	}

	return TRUE;
}

void CSan9PKHardDlg::OnStartSan9() 
{
	UINT rv = 0;
	CString str;

	if (::FindWindow("KOEI_SAN9WINDOW", NULL) != NULL)
	{
		AfxMessageBox("39已运行!");
		return;
	}

	rv = ::WinExec("San9PK.exe", SW_SHOW);
	if (rv <= 31)
	{
		str.Format("启动39失败(%d)! 请确认高难度优化伴侣放在39的根目录下", rv);
		AfxMessageBox(str);
	}
}
