#define _ARMA_
class WBK_RscActiveText
{
    access = 0;
    type = 11;
    style = 48 + 2;
    color[] = {1,1,1,1}; 
    colorActive[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,1};
    font = "TahomaB";
    sizeEx = 0.04;
    soundEnter[] = {"",0.09,1};
    soundPush[] = {"",0.09,1};
    soundClick[] = {"",0.09,1};
    soundEscape[] = {"",0.09,1};
    default = 0;
    text = "";
    shadow = 0;
};
class CfgPatches
{
	class WBK_KitArsenal
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class WBK_RscListBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 5;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorScrollbar[] = {1,0,0,0};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,0.3};
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0,1};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {0,0,0,1};
	colorSelect2Right[] = {0,0,0,1};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class ListScrollBar
	{
		color[] = {1,1,1,1};
		autoScrollEnabled = 1;
	};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	style = 16;
	font = "TahomaB";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	colorShadow[] = {0,0,0,0.5};
	period = 1.2;
	maxHistoryDelay = 1;
};
class WBK_Box
{
	type = 0;
	idc = -1;
	style = 2;
	shadow = 2;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,0.9};
	font = "PuristaLight";
	sizeEx = 0.03;
	text = "";
};
class WBK_RscButton
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 1;
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {0,0,0,0.5};
	colorBackgroundDisabled[] = {0,0,0,0.5};
	colorBackgroundActive[] = {0,0,0,1};
	colorFocused[] = {0,0,0,1};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	idc = -1;
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_MEDIUM";
	url = "";
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	borderSize = 0;
};
class WBK_KITArsenalAlike
{
	idd = 2000;
	movingenable = "false";
	onLoad = "[] spawn {execVM '\41st_KitMenu\41st_Kit_System.sqf';};";
	class controls
	{
		class frame_1: WBK_Box
		{
			idc = 1800;
			x = "-0.325 * safezoneW + safezoneX";
			y = "-0.00599999 * safezoneH + safezoneY";
			w = "1.52109 * safezoneW";
			h = "0.066 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
			font = "PuristaMedium";
			onLBSelChanged = "";
			onLBDblClick = "";
		};
		class frame_2: WBK_Box
		{
			idc = 1801;
			x = "-0.227031 * safezoneW + safezoneX";
			y = "0.94 * safezoneH + safezoneY";
			w = "1.52109 * safezoneW";
			h = "0.066 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
			font = "PuristaMedium";
			onLBSelChanged = "";
			onLBDblClick = "";
		};
		class SwitchButtonPic: WBK_RscActiveText
		{
			idc = 1603;
			style = 48;
			text = "\41st_KitMenu\data\P2_base_helmet.paa";
			x = "0.0101562 * safezoneW + safezoneX + (0.159844 * safezoneW) / 2 - (0.062 * safezoneH) / 2";
			y = "0.065 * safezoneH + safezoneY";
			w = "0.062 * safezoneH";
			h = "0.080 * safezoneH";
			tooltip = "Switch Kit Category";
			action = "call FST_ToggleKitCategory;";
			onMouseEnter = "(_this select 0) ctrlSetPosition [ctrlPosition (_this select 0) select 0, ctrlPosition (_this select 0) select 1, 0.072 * safezoneH, 0.093 * safezoneH]; (_this select 0) ctrlCommit 0.07;";
			onMouseExit = "(_this select 0) ctrlSetPosition [ctrlPosition (_this select 0) select 0, ctrlPosition (_this select 0) select 1, 0.062 * safezoneH, 0.080 * safezoneH]; (_this select 0) ctrlCommit 0.07;";
			onButtonDown = "(_this select 0) ctrlSetPosition [ctrlPosition (_this select 0) select 0, ctrlPosition (_this select 0) select 1, 0.055 * safezoneH, 0.070 * safezoneH]; (_this select 0) ctrlCommit 0.03;";
			onButtonUp = "(_this select 0) ctrlSetPosition [ctrlPosition (_this select 0) select 0, ctrlPosition (_this select 0) select 1, 0.072 * safezoneH, 0.093 * safezoneH]; (_this select 0) ctrlCommit 0.07;";
		};
		class RscListbox_1500: WBK_RscListBox
		{
			idc = 1732;
			x = "0.0101562 * safezoneW + safezoneX";
			y = "0.160 * safezoneH + safezoneY";
			w = "0.159844 * safezoneW";
			h = "0.750 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			font = "PuristaMedium";
			onLBSelChanged = "_this call Wbk_AssignKit";
			onLBDblClick = "";
		};
		class RscListbox_1501: WBK_RscListBox
		{
			idc = 1731;
			x = "0.185469 * safezoneW + safezoneX";
			y = "0.148 * safezoneH + safezoneY";
			w = "0.159844 * safezoneW";
			h = "0.781 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			font = "PuristaMedium";
			onLBSelChanged = "_this call Wbk_AssignAditionalGear";
			onLBDblClick = "";
		};
		class variations_of_a_kit: WBK_Box
		{
			idc = 1000;
			text = "Aditional weapons and equipment";
			x = "0.180312 * safezoneW + safezoneX";
			y = "0.093 * safezoneH + safezoneY";
			w = "0.170156 * safezoneW";
			h = "0.044 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			font = "PuristaMedium";
			sizeEx = "0.023 / (getResolution select 5)";
		};
		class insideofa_of_a_kit: WBK_Box
		{
			idc = 1300;
			text = "Current loadout and traits";
			x = "0.649532 * safezoneW + safezoneX";
			y = "0.181 * safezoneH + safezoneY";
			w = "0.257813 * safezoneW";
			h = "0.044 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			font = "PuristaMedium";
			sizeEx = "0.023 / (getResolution select 5)";
		};
		class Listbox_StuffOfAPlayer: WBK_RscListBox
		{
			idc = 1733;
			x = "0.654688 * safezoneW + safezoneX";
			y = "0.236 * safezoneH + safezoneY";
			w = "0.2475 * safezoneW";
			h = "0.627 * safezoneH";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			font = "PuristaMedium";
			onLBSelChanged = "";
			onLBDblClick = "";
		};
		class CustomsMenuButton
		{
			idc = 1600;
			type = 1;
			style = 2;
			text = "Customs";
			font = "PuristaMedium";
			sizeEx = "0.023 / (getResolution select 5)";
			x = "0.454 * safezoneW + safezoneX";
			y = "0.85 * safezoneH + safezoneY";
			w = "0.15 * safezoneW";
			h = "0.04 * safezoneH";
			action = "createDialog 'FST_CustomsOverlay';";
			colorText[] = {1, 1, 1, 1};
			colorDisabled[] = {0.5, 0.5, 0.5, 1};
			colorBackground[]        = {0, 0, 0, 1};
			colorBackgroundActive[]  = {0.15, 0.15, 0.2, 1};
			colorBackgroundDisabled[]= {0, 0, 0, 0.5};
			colorFocused[]           = {0.15, 0.15, 0.2, 1};
			colorShadow[]            = {0, 0, 0, 0};
			colorBorder[]            = {0, 0, 0, 1};
			soundEnter[]  = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1};
			soundPush[]   = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1};
			soundClick[]  = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
			offsetX = 0;
			offsetY = 0;
			offsetPressedX = 0;
			offsetPressedY = 0;
			borderSize = 0;
		};
	};
};
class FST_CustomsOverlay
{
	idd = 4100;
	movingEnable = false;
	enableSimulation = true;
	onLoad = "[] spawn { uiSleep 0.1; call compile preprocessFileLineNumbers '\41st_KitMenu\helmet_overlay_onLoad.sqf'; };";

	onUnload = "uiNamespace setVariable ['FST_HelmetOverlay_Display', displayNull];";
	class controlsBackground
	{
		class ClickCatcher
		{
			idc = 4101;
			type = 0;
			style = 0;
			x = safeZoneX;
			y = safeZoneY;
			w = safeZoneW;
			h = safeZoneH;
			colorBackground[] = {0,0,0,0.01};
			colorText[] = {0,0,0,0};
			font = "TahomaB";
			sizeEx = 0;
			text = "";
			onMouseButtonDown = "closeDialog 0;";
		};
	};

	class controls
	{
		class HelmetSearchInput
		{
			idc = 4103;
			type = 2;
			style = 0;
			x = 0.35 * safezoneW + safezoneX;
			y = 0.25 * safezoneH + safezoneY;
			w = 0.3 * safezoneW;
			h = 0.04 * safezoneH;
			font = "PuristaMedium";
			sizeEx = 0.035;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.5};
			autocomplete = "";
			onKeyUp = "[] spawn FST_fnc_filterHelmets;";
		};

		class HelmetList: WBK_RscListBox
		{
			idc = 4102;
			x = 0.35 * safezoneW + safezoneX;
			y = 0.3 * safezoneH + safezoneY;
			w = 0.3 * safezoneW;
			h = 0.4 * safezoneH;
			onLBSelChanged = "_this call FST_fnc_selectHelmet;";

		};
	};
};

class Extended_PreInit_EventHandlers
{
	class WBK_Project_KitMenu_PreInit
	{
		init = "call compile preprocessFileLineNumbers '\41st_KitMenu\XEN_PreInit.sqf'";
	};
};
class cfgMods
{
	author = "WebKnight";
	timepacked = "1723919282";
};
