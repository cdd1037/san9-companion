# 配置

| 模型 | 默认文件 | 内容 |
| --- | --- | --- |
| `ParameterConfig` | `San9PKHardPara.txt` | 88 项参数，34 行 |
| `PersonConfig` | `San9PKHardPerson.txt` | 800 个武将、116 个亲密度记录及经验上限，917 行 |
| `CityConfig` | `San9PKHardCity.txt` | 50 个都市、关系和攻城天数，250 行 |
| `SkillConfig` | `San9PKHardSkill.txt` | 39 项兵法，39 行 |
| `FormationConfig` | `San9PKHardArray.txt` | 27 项阵型，54 行 |

文件格式、范围和字节编码以 `src/model/` 为准。读取完整文件并校验成功后才提交；缺行、额外内容、整数溢出或字段越界都保留原配置。默认文件位于 `assets/config/`，构建复制到 EXE 目录。偏好文件 `San9PKHardSettings.ini` 也按 EXE 目录定位，不依赖启动工作目录。

INI 的 `[City] AutoApply` 控制自动应用都市配置；`[Extensions] SkipDurabilitySiegeSelection` 控制跳过耐久驱动的攻城阵型优先选择。缺省时两者开启。确认时保存偏好，失败则保留编辑窗口，不提交该次编辑；取消不写入。参数导出只保存传统 TXT，不代替扩展选项确认。

读取游戏配置由核心快照接口完成。已有文件、待应用设置或自动应用状态决定是否导入游戏值；任一行无效时整份草稿保留已有配置。游戏名称采用受限的编码转换；读取失败或无连接时仍可按编号编辑已有配置。
