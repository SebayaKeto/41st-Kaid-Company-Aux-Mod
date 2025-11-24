// Base Rsc Classes
class RscText
{
    type = 0;
    idc = -1;
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    style = 0;
    shadow = 0;
    colorBackground[] = {0, 0, 0, 0};
    colorShadow[] = {0, 0, 0, 0.5};
    colorText[] = {1, 1, 1, 1};
    font = "RobotoCondensed";
    sizeEx = 0.04;
};

class RscButton: RscText
{
    type = 1;
    style = 2;
    colorBackground[] = {0.75, 0.75, 0.75, 1};
    colorBackgroundActive[] = {1, 1, 1, 1};
    colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 0.5};
    colorFocused[] = {0, 0, 0, 1};
    colorShadow[] = {0, 0, 0, 0};
    colorBorder[] = {0.1, 0.1, 0.1, 1};
    soundEnter[] = {"\A3\sounds_f\sfx\blip1.wss", 0.09, 1};
    soundPush[] = {"\A3\sounds_f\sfx\hint-1.wss", 0.09, 1};
    soundClick[] = {"\A3\sounds_f\sfx\beep_target.wss", 0.09, 1};
    soundEscape[] = {"\A3\sounds_f\sfx\zoomout.wss", 0.09, 1};
};

class RscListbox: RscText
{
    type = 5;
    style = 0;
    colorBackground[] = {0, 0, 0, 0.5};
    colorSelect[] = {0.2, 0.6, 1, 1};
    colorText[] = {1, 1, 1, 1};
    colorDisabled[] = {0.5, 0.5, 0.5, 0.7};
    font = "RobotoCondensed";
    sizeEx = 0.04;
};

class HKD_Drop_Dialog
{
    idd = 9876;
    movingEnable = 1;
    
    class ControlsBackground
    {
        // Datapad background
        class Background: RscText
        {
            x = 0.28 * safezoneW + safezoneX;
            y = 0.21 * safezoneH + safezoneY;
            w = 0.44 * safezoneW;
            h = 0.58 * safezoneH;
            colorBackground[] = {0.02, 0.03, 0.04, 0.95};
        };
        // Top title bar (accent)
        class TitleBar: RscText
        {
            text = "HKD Orbital Drop";
            x = 0.28 * safezoneW + safezoneX;
            y = 0.21 * safezoneH + safezoneY;
            w = 0.44 * safezoneW;
            h = 0.05 * safezoneH;
            colorBackground[] = {0.06, 0.09, 0.12, 1};
            sizeEx = 0.065;
            colorText[] = {0.9, 0.9, 0.8, 1};
        };
        // Sub-title / datapad header
        class SubTitle: RscText
        {
            text = "Orbital Logistics - Drop Console";
            x = 0.282 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.44 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.036;
            colorText[] = {0.7,0.8,1,0.9};
        };
    };
    
    class Controls
    {
        class ObjectList: RscListbox
        {
            idc = 1500;
            x = 0.292 * safezoneW + safezoneX;
            y = 0.295 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.39 * safezoneH;
            colorBackground[] = {0,0,0,0.5};
        };
        
        class SelectedList: RscListbox
        {
            idc = 1501;
            x = 0.548 * safezoneW + safezoneX;
            y = 0.295 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.39 * safezoneH;
            colorBackground[] = {0,0,0,0.5};
        };
        
        class ButtonAdd: RscButton
        {
            text = ">> Add >>";
            x = 0.46 * safezoneW + safezoneX;
            y = 0.62 * safezoneH + safezoneY;
            w = 0.06 * safezoneW;
            h = 0.035 * safezoneH;
            action = "['ADD'] call HKD_fnc_dialogHandler";
        };
        
        class ButtonDrop: RscButton
        {
            text = "INITIATE DROP";
            x = 0.639062 * safezoneW + safezoneX;
            y = 0.62 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.035 * safezoneH;
            colorBackground[] = {0.6, 0, 0, 1};
            action = "['DROP'] call HKD_fnc_dialogHandler";
        };
        
        class HelpText: RscText
        {
            text = "Select object > Click Add > Click Drop. Multiple selections allowed.";
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.675 * safezoneH + safezoneY;
            w = 0.3 * safezoneW;
            h = 0.03 * safezoneH;
        };
        class ProgressText: RscText
        {
            idc = 1520;
            text = "";
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.71 * safezoneH + safezoneY;
            w = 0.39 * safezoneW;
            h = 0.03 * safezoneH;
            sizeEx = 0.035;
            colorText[] = {1,1,0.6,1};
        };
        class ProgressBarBG: RscText
        {
            idc = 1521;
            text = "";
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.745 * safezoneH + safezoneY;
            w = 0.39 * safezoneW;
            h = 0.01 * safezoneH;
            colorBackground[] = {0.05,0.05,0.05,0.9};
        };
        class ProgressBarFill: RscText
        {
            idc = 1522;
            text = "";
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.745 * safezoneH + safezoneY;
            w = 0; // will be set dynamically
            h = 0.01 * safezoneH;
            colorBackground[] = {0.2,0.6,1,0.9};
        };
        class ButtonCancel: RscButton
        {
            text = "CANCEL";
            x = 0.544 * safezoneW + safezoneX;
            y = 0.62 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.035 * safezoneH;
            colorBackground[] = {0.3,0.1,0.1,1};
            action = "private _logic = missionNamespace getVariable ['HKD_Current_Drop_Module', objNull]; if (!isNull _logic) then { [_logic] remoteExecCall ['HKD_fnc_serverSetCancel', 2]; }; ((findDisplay 9876) displayCtrl 1520) ctrlSetText 'Cancelling...';";
        };
    };
};