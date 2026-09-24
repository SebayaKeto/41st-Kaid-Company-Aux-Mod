params ["_side"];

switch (_side) do
{
    case "Left": {"Right"};
    case "Right": {"Left"};
    case "Front": {"Back"};
    case "Back": {"Front"};
    case "Top": {"Bottom"};
    case "Bottom": {"Top"};
    default {""};
};
