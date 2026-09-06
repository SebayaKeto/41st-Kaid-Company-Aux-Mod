// ============================================================
//  FST_RscControls.hpp
//  Base GUI control classes for the Aircraft Spawn GUI.
//  Prefixed FST_ to avoid colliding with vanilla RscText/RscButton/etc,
//  which is safe to redefine in a mission's description.ext but not
//  in an addon config.cpp (that would apply engine-wide).
// ============================================================

class FST_RscText
{
    type = 0;
    idc = -1;
    style = 0;
    x = 0; y = 0; w = 0; h = 0;
    font = "RobotoCondensed";
    sizeEx = 0.04;
    text = "";
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0};
};

class FST_RscEdit
{
    type = 2;
    idc = -1;
    style = 0;
    x = 0; y = 0; w = 0; h = 0;
    font = "RobotoCondensed";
    sizeEx = 0.030;
    text = "";
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0.05, 0.05, 0.05, 1};
    colorDisabled[] = {0.5, 0.5, 0.5, 1};
    colorSelection[] = {0.20, 0.60, 0.20, 1};
    autocomplete = "";
    canModify = 1;
    size = 1;
    maxChars = 64;
};

class FST_RscButton
{
    type = 1;
    idc = -1;
    style = 2;
    x = 0; y = 0; w = 0; h = 0;
    font = "RobotoCondensed";
    sizeEx = 0.04;
    text = "";
    action = "";
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0.2, 0.2, 0.2, 1};
    colorBackgroundActive[] = {0.4, 0.4, 0.4, 1};
    colorBackgroundDisabled[] = {0.1, 0.1, 0.1, 1};
    colorFocused[] = {0.4, 0.4, 0.4, 1};
    colorDisabled[] = {0.5, 0.5, 0.5, 1};
    colorBorder[] = {0, 0, 0, 0};
    colorShadow[] = {0, 0, 0, 0};
    colorSelect[] = {1, 1, 1, 1};
    offsetX = 0;
    offsetY = 0;
    offsetPressedX = 0;
    offsetPressedY = 0;
    borderSize = 0;
    soundEnter[] = {"", 0, 1};
    soundPush[] = {"", 0, 1};
    soundClick[] = {"", 0, 1};
    soundEscape[] = {"", 0, 1};
};

class FST_RscListBox
{
    type = 5;
    idc = -1;
    style = 0;
    x = 0; y = 0; w = 0; h = 0;
    font = "RobotoCondensed";
    sizeEx = 0.04;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0.5};
    colorSelect[] = {1, 1, 1, 1};
    colorSelectBackground[] = {0.2, 0.4, 0.6, 1};
    colorDisabled[] = {0.5, 0.5, 0.5, 1};
    colorScrollbar[] = {1, 1, 1, 1};
    soundSelect[] = {"", 0, 1};
    rowHeight = 0;
    maxHistoryDelay = 1;

    class ListScrollBar
    {
        width = 0.012;
        height = 0.025;
        autoScrollEnabled = 0;
        autoScrollSpeed = -1;
        autoScrollDelay = 5;
        autoScrollRewind = 0;
        scrollSpeed = 0.06;
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        thumb = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\thumb_ca.paa";
        arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\border_ca.paa";
    };
};

class FST_RscCombo
{
    type = 4;
    idc = -1;
    style = 0;
    x = 0; y = 0; w = 0; h = 0;
    font = "RobotoCondensed";
    sizeEx = 0.032;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0.1, 0.1, 0.12, 1};
    colorDisabled[] = {0.5, 0.5, 0.5, 1};
    colorSelect[] = {1, 1, 1, 1};
    colorSelectBackground[] = {0.2, 0.4, 0.6, 1};
    soundSelect[] = {"", 0, 1};
    soundExpand[] = {"", 0, 1};
    soundCollapse[] = {"", 0, 1};
    maxHistoryDelay = 1;
    wholeHeight = 0.45;
    arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\RscCombo\arrow_combo_ca.paa";
    arrowFull  = "\A3\ui_f\data\GUI\RscCommon\RscCombo\arrow_combo_ca.paa";

    class ComboScrollBar
    {
        width = 0.012;
        height = 0.025;
        autoScrollEnabled = 0;
        autoScrollSpeed = -1;
        autoScrollDelay = 5;
        autoScrollRewind = 0;
        scrollSpeed = 0.06;
        color[] = {1, 1, 1, 0.6};
        colorActive[] = {1, 1, 1, 1};
        colorDisabled[] = {1, 1, 1, 0.3};
        thumb = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\thumb_ca.paa";
        arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\GUI\RscCommon\rscscrollbar\border_ca.paa";
    };
};

class FST_RscPicture
{
    type = 0;
    idc = -1;
    style = 48;
    x = 0; y = 0; w = 0; h = 0;
    text = "";
    font = "RobotoCondensed";
    sizeEx = 0;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0};
};
