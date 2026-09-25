params ["_side"];

switch (_side) do
{
    case "Left": {"MEAP_SnapPoint_Left"};
    case "Right": {"MEAP_SnapPoint_Right"};
    case "Front": {"MEAP_SnapPoint_Front"};
    case "Back": {"MEAP_SnapPoint_Back"};
    case "Top": {"MEAP_SnapPoint_Top"};
    case "Bottom": {"MEAP_SnapPoint_Bottom"};
    default {""};
};
