# 能力上限与关联规则

013／021及关联基础调整已接入，038～040内容编辑层仍暂缓。以下区分基础成长上限、有效能力、事件资格、公式饱和与显示标尺；基础能力还可叠加伤势、宝物和官职，不能用125替换所有100或115。

## 当前采用

| 入口 | 当前规则与边界 |
| --- | --- |
| 普通成长、强制／事件奖励、武将编辑 | 共用有效的`OfficerGrowth.MaximumBaseAbility`。剧本默认100、可定义其他正整数；宿主`OfficerAbilityCap`覆盖剧本值，默认100、至少100，无附加开关。保留已有超限值，不倒扣、不拒载。013单独改变普通成长概率，强制奖励不投骰 |
| AI探索／登用及074 | 去掉当前有效能力115上界，保留政治最低资格：探索45，本地／对外登用35／45。074仅保留所在地探索，已移除自动夺取 |
| AI军师 | 替代者有效智力至少80且严格高于现任，取消115上界与下限夹取；现任仍参与排序 |
| AI计略／外交 | 取消有效能力115上界，保留各工作下限及特殊资格。计略分别按智力、武力或统率，使者按政治；`Gift`原本不套这道门 |
| 蔡琰归还 | 取消基础智力、政治均须<115的资格，保留概率、日期、资金、兵法教学及其他结算；智力／政治奖励仍为+2并服从公共上限 |
| 祢衡辱骂 | 无视时基础智力未满公共上限则+2，达到或超过上限则基础信望+2；不按有效智力判断。替代原作固定115分流，避免100～114受旧成长封顶而两种奖励均无所得 |
| 内容契约与存读档 | 删除两个旧事件阈值字段；能力仍用非负整数，保存实际值，125不要求扩大存储类型或收紧世界合法性 |
| 雷达 | 暂保留115标尺及外圈截断，文字显示真实值和加成；是否扩大标尺独立评估，不按每人最大值缩放 |

详细采用规格见[成长与水战](../../remake/specs/behavior/BEH-COMPANION-0006-ability-growth-and-naval-presets.md)。这些是重制规则，原作阈值的设计意图未知，不据此认定为原作BUG或防作弊机制。

## 独立保留的阈值与公式

- 阵亡保护107独立配置基础四维最高值门槛，默认80、预设125，替代插件固定121，不随021变化。见[阵亡规则](../../remake/specs/behavior/BEH-COMPANION-0002-combat-rules.md#battle-death-rules)。
- 军师准确率、智力兵法等的100是概率上限；`EconomyMath.ExecutedAbility`的60／80是线性分段，均不是成长上限。
- 俘获、阵亡、抵抗概率降到0是公式结果；`BattleCaptureRules`的120是减项，无退路100%分支独立优先。
- `RecruitmentRules`中特殊人物的`max(0,100−基础政治)`是登用修正；调将评分的`容量+武力−政治+115`是平移项。修改它们须另作平衡决定。
- 基础125不限制宝物、官职叠加后的有效值；原伴侣局部有符号字节比较的机器边界不带入remake。

## 原作与伴侣依据的边界

2026本体021只把四项公共基础能力及一处探索奖励写入上限从100改到125，不联动事件115门或AI候选上界。原作蔡琰比较`58363B/583643`读取人物`+54/+5C`（基础智力／政治），概率另读有效政治`+60`；祢衡`582119/58216D`均读基础智力`+54`。见[字段回查](../../remake/research/findings/RE-SAN9PK-0130.md#2026-09-20祢衡遭遇核对)。

本次复用TC101研究并定向回查伴侣写入和remake源码，未对原EXE重新进行全程序常数／交叉引用扫描，不能视为全部能力消费者的穷举证明。

## 依据

- 原作成长入口与四项setter：[`RE-SAN9PK-0067`](../../remake/research/findings/RE-SAN9PK-0067.md)、成长生产者与旁路[`RE-SAN9PK-0131`](../../remake/research/findings/RE-SAN9PK-0131.md)。
- 蔡琰资格／奖励和祢衡分流：[`RE-SAN9PK-0130`](../../remake/research/findings/RE-SAN9PK-0130.md)，其中`5835D0`为蔡琰资格，`582020/582160`为祢衡分流，`588FD0`为探索基础能力奖励。
- 2026本体地址与默认值：[`00408670.asm`](../recovery/evidence/disassembly/00408670.asm)的`408B1D..408B3B`声明`44D1AB`、125、100及`588FB1`；[`RuntimeInjection2026.cpp`](../src/runtime/RuntimeInjection2026.cpp)的021分支写探索上限及四个相隔48字节的能力上限点。
- AI候选原作依据：[`research/ai.md`](../../remake/research/ai.md)，军师、人事、计略和外交工作各节；当前实现为[`OriginalAiPersonnel.cs`](../../remake/src/San9.Application/AI/OriginalAiPersonnel.cs)、[`OriginalAiPersonnel.Search.cs`](../../remake/src/San9.Application/AI/OriginalAiPersonnel.Search.cs)、[`OriginalAiActions.cs`](../../remake/src/San9.Application/AI/OriginalAiActions.cs)。
- 当前成长与事件实现：[`OfficerAbilityGrowth.cs`](../../remake/src/San9.Core/Simulation/Personnel/OfficerAbilityGrowth.cs)、[`ScholarReturn.cs`](../../remake/src/San9.Core/Simulation/Events/Search/ScholarReturn.cs)、[`ScholarInsult.cs`](../../remake/src/San9.Core/Simulation/Events/Search/ScholarInsult.cs)；[`EventContentCompiler.cs`](../../remake/src/San9.Importer.San9PkTc101/Scenarios/EventContentCompiler.cs)已移除两个事件115参数，原作事实保留在研究记录。
- 编辑范围与显示标尺：[`WorldEditorDraft.cs`](../../remake/src/San9.Application/Presentation/WorldEditorDraft.cs)、[`SimulationEngine.Editor.cs`](../../remake/src/San9.Core/Simulation/SimulationEngine.Editor.cs)、[`officer_ability_radar.gdshader`](../../remake/src/San9.Client.Godot/shaders/officer_ability_radar.gdshader)，原作雷达依据[`RE-SAN9PK-0162`](../../remake/research/findings/RE-SAN9PK-0162.md)。
