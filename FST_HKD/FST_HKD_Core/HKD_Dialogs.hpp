class HKD_Drop_Dialog
{
    idd = 9876;
    movingEnable = 1;
    
    class ControlsBackground
    {
        class Background: RscText
        {
            x = 0.29375 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.4125 * safezoneW;
            h = 0.55 * safezoneH;
            colorBackground[] = {0.1, 0.1, 0.1, 0.9};
        };
        class Title: RscText
        {
            text = "HKD Orbital Drop Interface";
            x = 0.29375 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.4125 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0, 0.2, 0.6, 1}; // CIS Blue
            sizeEx = 0.06;
        };
    };
    
    class Controls
    {
        class ObjectList: RscListbox
        {
            idc = 1500;
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.195937 * safezoneW;
            h = 0.42 * safezoneH;
            colorBackground[] = {0,0,0,0.5};
        };
        
        class SelectedList: RscListbox
        {
            idc = 1501;
            x = 0.5 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.195937 * safezoneW;
            h = 0.42 * safezoneH;
            colorBackground[] = {0,0,0,0.5};
        };
        
        class ButtonAdd: RscButton
        {
            text = ">> Add >>";
            x = 0.43 * safezoneW + safezoneX;
            y = 0.71 * safezoneH + safezoneY;
            w = 0.06 * safezoneW;
            h = 0.04 * safezoneH;
            action = "['ADD'] call HKD_fnc_dialogHandler";
        };
        
        class ButtonDrop: RscButton
        {
            text = "INITIATE DROP";
            x = 0.639062 * safezoneW + safezoneX;
            y = 0.71 * safezoneH + safezoneY;
            w = 0.06 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0.6, 0, 0, 1};
            action = "['DROP'] call HKD_fnc_dialogHandler";
        };
        
        class HelpText: RscText
        {
            text = "Select object > Click Add > Click Drop. Multiple selections allowed.";
            x = 0.304062 * safezoneW + safezoneX;
            y = 0.71 * safezoneH + safezoneY;
            w = 0.3 * safezoneW;
            h = 0.04 * safezoneH;
        };
    };
};