// ============================================================
//  FST_VehicleSpawnerDialog.hpp — 41st Kaid Bn. Star Wars Theme
//  safeZone scaling — 0.05 border gap on all sides
//  Spawn panel:  x=0.05 to 0.27  (w=0.22)
//  Camera panel: x=0.28 to 0.95  (w=0.67)
//  Top/bottom:   y=0.05 to 0.95
// ============================================================

class AircraftSpawnGUI
{
    idd = 9900;
    movingEnable = 0;
    enableSimulation = 0;
    safeZone = 1;

    class controls
    {
        // ════════════════════════════════════════════════════════
        //  SPAWN PANEL — LEFT
        //  x=0.05 to 0.27  w=0.22
        //  y=0.05 to 0.95  h=0.90
        // ════════════════════════════════════════════════════════

        class BG: FST_RscText
        {
            idc = 9901;
            x = "safeZoneX + safeZoneW * 0.05";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.22";
            h = "safeZoneH * 0.90";
            colorBackground[] = {0.122,0.122,0.122, 0.96};
            text = "";
        };
        class BorderTop: FST_RscText
        {
            idc = 9960;
            x = "safeZoneX + safeZoneW * 0.05";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.22";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BorderBottom: FST_RscText
        {
            idc = 9961;
            x = "safeZoneX + safeZoneW * 0.05";
            y = "safeZoneY + safeZoneH * 0.948";
            w = "safeZoneW * 0.22";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BorderLeft: FST_RscText
        {
            idc = 9962;
            x = "safeZoneX + safeZoneW * 0.05";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.90";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BorderRight: FST_RscText
        {
            idc = 9963;
            x = "safeZoneX + safeZoneW * 0.268";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.90";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };

        // ════════════════════════════════════════════════════════
        //  HEADER
        // ════════════════════════════════════════════════════════
        class TitleLabel: FST_RscText
        {
            idc = 9971;
            x = "safeZoneX + safeZoneW * 0.053";
            y = "safeZoneY + safeZoneH * 0.054";
            w = "safeZoneW * 0.214";
            h = "safeZoneH * 0.022";
            text = "41ST KAID BN.";
            colorText[] = {0.20, 0.80, 0.30, 1.0};
            sizeEx = "(safeZoneH / 36)";
            style = 2;
            font = "PuristaBold";
        };
        class SubTitleLabel: FST_RscText
        {
            idc = 9972;
            x = "safeZoneX + safeZoneW * 0.053";
            y = "safeZoneY + safeZoneH * 0.076";
            w = "safeZoneW * 0.214";
            h = "safeZoneH * 0.014";
            text = "VEHICLE DEPLOYMENT SYSTEM";
            colorText[] = {0.45, 0.65, 0.45, 1.0};
            sizeEx = "(safeZoneH / 52)";
            style = 2;
            font = "PuristaLight";
        };
        class HeaderDivider: FST_RscText
        {
            idc = 9907;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.092";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };

        // ════════════════════════════════════════════════════════
        //  PAD SELECTOR
        // ════════════════════════════════════════════════════════
        class PadRowBG: FST_RscText
        {
            idc = 9975;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.094";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.026";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class PadLabel: FST_RscText
        {
            idc = 9950;
            x = "safeZoneX + safeZoneW * 0.055";
            y = "safeZoneY + safeZoneH * 0.097";
            w = "safeZoneW * 0.044";
            h = "safeZoneH * 0.018";
            text = "PAD:";
            colorText[] = {0.20, 0.80, 0.30, 1.0};
            sizeEx = "(safeZoneH / 52)";
            style = 0;
            font = "PuristaBold";
        };
        class PadCombo: FST_RscCombo
        {
            idc = 9951;
            x = "safeZoneX + safeZoneW * 0.101";
            y = "safeZoneY + safeZoneH * 0.095";
            w = "safeZoneW * 0.166";
            h = "safeZoneH * 0.024";
            colorBackground[] = {0.04, 0.10, 0.04, 1.0};
            colorText[] = {0.70, 1.0, 0.70, 1.0};
            colorSelect[] = {0.10, 0.80, 0.20, 1.0};
            colorSelectBackground[] = {0.05, 0.20, 0.07, 1.0};
            sizeEx = "(safeZoneH / 54)";
            font = "PuristaLight";
        };

        // ════════════════════════════════════════════════════════
        //  CATEGORY SELECTOR
        // ════════════════════════════════════════════════════════
        class CatRowBG: FST_RscText
        {
            idc = 9980;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.122";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.026";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class CatLabel: FST_RscText
        {
            idc = 9981;
            x = "safeZoneX + safeZoneW * 0.055";
            y = "safeZoneY + safeZoneH * 0.125";
            w = "safeZoneW * 0.044";
            h = "safeZoneH * 0.018";
            text = "CAT:";
            colorText[] = {0.20, 0.80, 0.30, 1.0};
            sizeEx = "(safeZoneH / 52)";
            style = 0;
            font = "PuristaBold";
        };
        class CatCombo: FST_RscCombo
        {
            idc = 9982;
            x = "safeZoneX + safeZoneW * 0.101";
            y = "safeZoneY + safeZoneH * 0.123";
            w = "safeZoneW * 0.166";
            h = "safeZoneH * 0.024";
            colorBackground[] = {0.04, 0.10, 0.04, 1.0};
            colorText[] = {0.70, 1.0, 0.70, 1.0};
            colorSelect[] = {0.10, 0.80, 0.20, 1.0};
            colorSelectBackground[] = {0.05, 0.20, 0.07, 1.0};
            sizeEx = "(safeZoneH / 54)";
            font = "PuristaLight";
        };

        // ════════════════════════════════════════════════════════
        //  SEARCH BAR
        // ════════════════════════════════════════════════════════
        class SearchRowBG: FST_RscText
        {
            idc = 9983;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.150";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.026";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class SearchIcon: FST_RscText
        {
            idc = 9984;
            x = "safeZoneX + safeZoneW * 0.055";
            y = "safeZoneY + safeZoneH * 0.153";
            w = "safeZoneW * 0.040";
            h = "safeZoneH * 0.018";
            text = "SRCH:";
            colorText[] = {0.20, 0.70, 0.25, 1.0};
            sizeEx = "(safeZoneH / 56)";
            style = 2;
            font = "PuristaBold";
        };
        class SearchBox: FST_RscEdit
        {
            idc = 9985;
            x = "safeZoneX + safeZoneW * 0.097";
            y = "safeZoneY + safeZoneH * 0.153";
            w = "safeZoneW * 0.169";
            h = "safeZoneH * 0.018";
            colorText[] = {0.75, 1.0, 0.75, 1.0};
            colorBackground[] = {0.03, 0.08, 0.03, 0.0};
            colorSelection[] = {0.15, 0.55, 0.20, 1.0};
            sizeEx = "(safeZoneH / 56)";
            font = "PuristaLight";
        };

        class ListDivider: FST_RscText
        {
            idc = 9986;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.178";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };

        // ════════════════════════════════════════════════════════
        //  MAIN VEHICLE LIST
        //  y=0.181 to y=0.950 = h=0.769
        // ════════════════════════════════════════════════════════
        class VehicleList: FST_RscListBox
        {
            idc = 9910;
            x = "safeZoneX + safeZoneW * 0.052";
            y = "safeZoneY + safeZoneH * 0.181";
            w = "safeZoneW * 0.216";
            h = "safeZoneH * 0.769";
            colorBackground[] = {0.122,0.122,0.122, 0.96};
            colorText[] = {0.65, 0.95, 0.65, 1.0};
            colorSelect[] = {0.05, 0.05, 0.05, 1.0};
            colorSelectBackground[] = {0.12, 0.50, 0.18, 0.95};
            sizeEx = "(safeZoneH / 56)";
            rowHeight = "(safeZoneH / 42)";
            font = "PuristaLight";
        };

        // ════════════════════════════════════════════════════════
        //  CAMERA PANEL — RIGHT
        //  x=0.28 to 0.95  w=0.67
        //  y=0.05 to 0.77  h=0.72  (leaves room for button strip)
        // ════════════════════════════════════════════════════════

        class CamBG: FST_RscText
        {
            idc = 9800;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.72";
            colorBackground[] = {0.01, 0.02, 0.01, 0.96};
            text = "";
        };
        class CamBorderTop: FST_RscText
        {
            idc = 9801;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamBorderBottom: FST_RscText
        {
            idc = 9802;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.768";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamBorderLeft: FST_RscText
        {
            idc = 9803;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.72";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamBorderRight: FST_RscText
        {
            idc = 9804;
            x = "safeZoneX + safeZoneW * 0.948";
            y = "safeZoneY + safeZoneH * 0.05";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.72";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamHeaderBG: FST_RscText
        {
            idc = 9805;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.052";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.030";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class CamHeaderLabel: FST_RscText
        {
            idc = 9806;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.054";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.024";
            text = "// PAD SURVEILLANCE FEED";
            colorText[] = {0.20, 0.90, 0.30, 1.0};
            sizeEx = "(safeZoneH / 32)";
            style = 2;
            font = "PuristaBold";
        };
        class CamHeaderDivider: FST_RscText
        {
            idc = 9807;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.082";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamFeed: FST_RscPicture
        {
            idc = 9810;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.085";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.648";
            colorBackground[] = {0.0, 0.0, 0.0, 1.0};
            text = "#(argb,512,512,1)r2t(PadCamRT,1.0)";
        };
        class CamFooterDivider: FST_RscText
        {
            idc = 9808;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.733";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class CamFooterBG: FST_RscText
        {
            idc = 9809;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.735";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.032";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class CamPadNameLabel: FST_RscText
        {
            idc = 9811;
            x = "safeZoneX + safeZoneW * 0.285";
            y = "safeZoneY + safeZoneH * 0.738";
            w = "safeZoneW * 0.440";
            h = "safeZoneH * 0.024";
            text = "NO PAD SELECTED";
            colorText[] = {0.70, 1.0, 0.70, 1.0};
            sizeEx = "(safeZoneH / 44)";
            style = 0;
            font = "PuristaBold";
        };
        class CamStatusLabel: FST_RscText
        {
            idc = 9812;
            x = "safeZoneX + safeZoneW * 0.725";
            y = "safeZoneY + safeZoneH * 0.738";
            w = "safeZoneW * 0.220";
            h = "safeZoneH * 0.024";
            text = "FEED OFFLINE";
            colorText[] = {0.55, 0.30, 0.30, 1.0};
            sizeEx = "(safeZoneH / 48)";
            style = 2;
            font = "PuristaLight";
        };

        // ════════════════════════════════════════════════════════
        //  BUTTON STRIP — below camera
        //  x=0.28 to 0.95  y=0.772 to 0.950
        // ════════════════════════════════════════════════════════

        class BtnStripBG: FST_RscText
        {
            idc = 9850;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.772";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.178";
            colorBackground[] = {0.122,0.122,0.122, 0.96};
            text = "";
        };
        class BtnStripBorderTop: FST_RscText
        {
            idc = 9851;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.772";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BtnStripBorderBottom: FST_RscText
        {
            idc = 9852;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.948";
            w = "safeZoneW * 0.67";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BtnStripBorderLeft: FST_RscText
        {
            idc = 9853;
            x = "safeZoneX + safeZoneW * 0.28";
            y = "safeZoneY + safeZoneH * 0.772";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.178";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };
        class BtnStripBorderRight: FST_RscText
        {
            idc = 9854;
            x = "safeZoneX + safeZoneW * 0.948";
            y = "safeZoneY + safeZoneH * 0.772";
            w = "safeZoneW * 0.002";
            h = "safeZoneH * 0.178";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };

        class SelectedVehicleBG: FST_RscText
        {
            idc = 9855;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.775";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.030";
            colorBackground[] = {0.03, 0.08, 0.03, 1.0};
            text = "";
        };
        class SelectedVehicleLabel: FST_RscText
        {
            idc = 9856;
            x = "safeZoneX + safeZoneW * 0.285";
            y = "safeZoneY + safeZoneH * 0.778";
            w = "safeZoneW * 0.660";
            h = "safeZoneH * 0.024";
            text = "> NO UNIT SELECTED";
            colorText[] = {0.20, 0.80, 0.28, 1.0};
            sizeEx = "(safeZoneH / 48)";
            style = 0;
            font = "PuristaLight";
        };

        class BtnDivider: FST_RscText
        {
            idc = 9906;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.808";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.002";
            colorBackground[] = {0.059,0.169,0,1};
            text = "";
        };

        class DeployBtn: FST_RscButton
        {
            idc = 9920;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.812";
            w = "safeZoneW * 0.210";
            h = "safeZoneH * 0.040";
            text = "[ DEPLOY ]";
            colorBackground[] = {0.04, 0.16, 0.06, 1.0};
            colorBackgroundActive[] = {0.08, 0.35, 0.12, 1.0};
            colorText[] = {0.25, 0.95, 0.35, 1.0};
            sizeEx = "(safeZoneH / 46)";
            font = "PuristaBold";
            action = "[] call FST_fnc_deploy;";
        };
        class GarageBtn: FST_RscButton
        {
            idc = 9922;
            x = "safeZoneX + safeZoneW * 0.500";
            y = "safeZoneY + safeZoneH * 0.812";
            w = "safeZoneW * 0.210";
            h = "safeZoneH * 0.040";
            text = "[ RECALL TO HANGAR ]";
            colorBackground[] = {0.12, 0.10, 0.02, 1.0};
            colorBackgroundActive[] = {0.28, 0.22, 0.04, 1.0};
            colorText[] = {0.95, 0.85, 0.20, 1.0};
            sizeEx = "(safeZoneH / 48)";
            font = "PuristaBold";
            action = "[] call FST_fnc_garage;";
        };
        class CloseBtn: FST_RscButton
        {
            idc = 9921;
            x = "safeZoneX + safeZoneW * 0.718";
            y = "safeZoneY + safeZoneH * 0.812";
            w = "safeZoneW * 0.230";
            h = "safeZoneH * 0.040";
            text = "[ DISMISS ]";
            colorBackground[] = {0.16, 0.03, 0.03, 1.0};
            colorBackgroundActive[] = {0.35, 0.06, 0.06, 1.0};
            colorText[] = {0.95, 0.30, 0.30, 1.0};
            sizeEx = "(safeZoneH / 48)";
            font = "PuristaBold";
            action = "call FST_fnc_destroyPadCamera; closeDialog 0;";
        };

        class BtnHintsBG: FST_RscText
        {
            idc = 9857;
            x = "safeZoneX + safeZoneW * 0.282";
            y = "safeZoneY + safeZoneH * 0.856";
            w = "safeZoneW * 0.666";
            h = "safeZoneH * 0.090";
            colorBackground[] = {0.122,0.122,0.122, 0.0};
            text = "";
        };
        class BtnHintsLabel: FST_RscText
        {
            idc = 9858;
            x = "safeZoneX + safeZoneW * 0.285";
            y = "safeZoneY + safeZoneH * 0.858";
            w = "safeZoneW * 0.660";
            h = "safeZoneH * 0.086";
            text = "Select a category and unit from the list then press DEPLOY to spawn on the selected pad. Use RECALL TO HANGAR to despawn. Engine must be off and crew clear before recall.";
            colorText[] = {0.35, 0.55, 0.35, 1.0};
            sizeEx = "(safeZoneH / 68)";
            style = 0;
            font = "PuristaLight";
        };
    };
};
