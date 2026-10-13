"""Intentional UI customizations; original resource evidence stays untouched."""

def control_title(dialog_id, control_id, original):
    if dialog_id == 102 and control_id in (1202, 0xFFFF, 0xFFFFFFFF):
        assert original == "2026年2月9日更新"
        return "提交时间"
    if (dialog_id, control_id) == (133, 1133):
        assert original == "自动同步配置信息"
        return "自动应用都市配置"
    return original


def customize_control_layout(dialog_id, control):
    if dialog_id == 102 and control["id"] in (0xFFFF, 0xFFFFFFFF):
        control["id"] = 1202
        control["rect"] = [15, 82, 120, 8]
        control["style"] = (control["style"] & ~0x1F) | 0x01  # SS_CENTER


def dialog_title(dialog_id, original):
    return "三国志9优化伴侣" if dialog_id == 102 else original
