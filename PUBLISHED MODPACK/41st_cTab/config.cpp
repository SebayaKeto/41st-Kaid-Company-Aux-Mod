#include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class cTab
	{
		units[]=
		{
			"Box_cTab_items"
		};
		weapons[]=
		{
			"ItemcTab",
			"ItemAndroid",
			"ItemMicroDAGR",
			"ItemcTabHCam"
		};
		requiredVersion=1.3200001;
		requiredAddons[]=
		{
			"CBA_MAIN",
			"A3Data"
		};
		versionDesc="cTab";
		version="2.2.2.1";
		versionStr="2.2.2.1";
		versionAr[]={2,2,2,1};
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class cTab
			{
				main_addon="cTab";
				class Dependencies
				{
					CBA[]=
					{
						"cba_main",
						{1,0,0},
						"true"
					};
				};
			};
		};
	};
};
class CfgMods
{
	class cTab
	{
		dir="@cTab";
		name="cTab - Blue Force Tracking";
		picture="\cTab\img\cTab_BFT_ico.paa";
		hidePicture="True";
		hideName="True";
		actionName="Website";
		action="https://github.com/Riouken/cTab";
		overview="Commander's Tablet / FBCB2 - Blue Force Tracking\nBattlefield tablet to access real time intel and blue force tracker.";
		tooltip="Commander's Tablet / FBCB2 - Blue Force Tracking";
	};
	author="76561197962969709";
	timepacked="1433095721";
};
class CfgFunctions
{
	class cTab
	{
		class Functions
		{
			file="cTab\functions";
			class addNotification
			{
			};
			class addToPairs
			{
			};
			class addUserMarker
			{
			};
			class centerMapOnPlayerPosition
			{
			};
			class checkGear
			{
			};
			class close
			{
			};
			class createHelmetCam
			{
			};
			class createUavCam
			{
			};
			class ctrlMapCenter
			{
			};
			class currentTime
			{
			};
			class degreeToOctant
			{
			};
			class deleteHelmetCam
			{
			};
			class deleteUAVcam
			{
			};
			class deleteUserMarker
			{
			};
			class dirTo
			{
			};
			class distance2D
			{
			};
			class drawBftMarkers
			{
			};
			class drawHook
			{
			};
			class drawMarkers
			{
			};
			class drawUserMarkers
			{
			};
			class findUserMarker
			{
			};
			class getBackgroundPosition
			{
			};
			class getCopilot
			{
			};
			class getFromPairs
			{
			};
			class getInfMarkerIcon
			{
			};
			class getPlayerEncryptionKey
			{
			};
			class getPlayerSides
			{
			};
			class getSettings
			{
			};
			class getUserMarkerList
			{
			};
			class isDialog
			{
			};
			class lockUavCamTo
			{
			};
			class onIfKeyDown
			{
			};
			class onIfClose
			{
			};
			class onIfOpen
			{
			};
			class open
			{
			};
			class onPlayerInventoryChanged
			{
			};
			class processCuratorKey
			{
			};
			class processNotifications
			{
			};
			class remoteControlUav
			{
			};
			class setInterfacePosition
			{
			};
			class setSettings
			{
			};
			class setToPairs
			{
			};
			class toggleIfPosition
			{
			};
			class toggleMapTools
			{
			};
			class translateUserMarker
			{
			};
			class unitInEnabledVehicleSeat
			{
			};
			class updateLists
			{
			};
			class updateInterface
			{
			};
			class updateUserMarkerList
			{
			};
			class userMenuSelect
			{
			};
		};
	};
};
class cTab_settings
{
	cTab_vehicleClass_has_FBCB2[]=
	{
		"MRAP_01_base_F",
		"MRAP_02_base_F",
		"MRAP_03_base_F",
		"Wheeled_APC_F",
		"Tank",
		"Truck_01_base_F",
		"Truck_03_base_F"
	};
	cTab_vehicleClass_has_TAD[]=
	{
		"Helicopter",
		"Plane"
	};
	cTab_helmetClass_has_HCam[]=
	{
		"H_HelmetB_light",
		"H_Helmet_Kerry",
		"H_HelmetSpecB",
		"H_HelmetO_ocamo",
		"BWA3_OpsCore_Fleck_Camera",
		"BWA3_OpsCore_Schwarz_Camera",
		"BWA3_OpsCore_Tropen_Camera"
	};
};
class cTab_keys
{
	class if_main
	{
		key=35;
		ctrl=0;
		shift=0;
		alt=0;
	};
	class if_secondary
	{
		key=35;
		ctrl=1;
		shift=0;
		alt=0;
	};
	class if_tertiary
	{
		key=35;
		ctrl=0;
		shift=0;
		alt=1;
	};
	class zoom_in
	{
		key=201;
		ctrl=1;
		shift=1;
		alt=0;
	};
	class zoom_out
	{
		key=209;
		ctrl=1;
		shift=1;
		alt=0;
	};
};
class Extended_PostInit_EventHandlers
{
	class cTab
	{
		clientInit="call compile preProcessFileLineNumbers '\cTab\player_init.sqf'";
		serverInit="call compile preProcessFileLineNumbers '\cTab\server_init.sqf'";
	};
};
class cTab_RscText
{
	access=0;
	type=0;
	idc=-1;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	text="";
	fixedWidth=0;
	x=0;
	y=0;
	h=0.037;
	w=0.30000001;
	style=0;
	shadow=1;
	colorShadow[]={0,0,0,0.5};
	font="PuristaMedium";
	SizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing=1;
};
class cTab_RscStructuredText
{
	access=0;
	type=13;
	idc=-1;
	style=0;
	colorText[]={1,1,1,1};
	class Attributes
	{
		font="PuristaMedium";
		color="#ffffff";
		align="left";
		shadow=1;
	};
	x=0;
	y=0;
	h=0.035;
	w=0.1;
	text="";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=1;
};
class cTab_RscPicture
{
	access=0;
	type=0;
	idc=-1;
	style=48;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	font="TahomaB";
	sizeEx=0;
	lineSpacing=0;
	text="";
	fixedWidth=0;
	shadow=0;
	x=0;
	y=0;
	w=0.2;
	h=0.15000001;
};
class cTab_RscEdit
{
	access=0;
	type=2;
	x=0;
	y=0;
	h=0.039999999;
	w=0.2;
	colorBackground[]={0,0,0,1};
	colorText[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelection[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	autocomplete="";
	text="";
	size=0.2;
	style="0x00 + 0x40";
	font="PuristaMedium";
	shadow=2;
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	canModify=1;
};
class cTab_RscCombo
{
	access=0;
	type=4;
	colorSelect[]={0,0,0,1};
	colorText[]={1,1,1,1};
	colorBackground[]={0,0,0,1};
	colorScrollbar[]={1,0,0,1};
	soundSelect[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundSelect",
		0.1,
		1
	};
	soundExpand[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundExpand",
		0.1,
		1
	};
	soundCollapse[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundCollapse",
		0.1,
		1
	};
	maxHistoryDelay=1;
	class ScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	style=16;
	x=0;
	y=0;
	w=0.12;
	h=0.035;
	shadow=0;
	colorSelectBackground[]={1,1,1,0.69999999};
	arrowEmpty="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight=0.44999999;
	color[]={1,1,1,1};
	colorActive[]={1,0,0,1};
	colorDisabled[]={1,1,1,0.25};
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
};
class cTab_RscListBox
{
	access=0;
	type=5;
	w=0.40000001;
	h=0.40000001;
	rowHeight=0;
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	colorScrollbar[]={1,0,0,0};
	colorSelect[]={0,0,0,1};
	colorSelect2[]={0,0,0,1};
	colorSelectBackground[]={0.94999999,0.94999999,0.94999999,1};
	colorSelectBackground2[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.30000001};
	colorPicture[]={1,1,1,1};
	colorPictureDisabled[]={1,1,1,0.25};
	colorPictureRight[]={1,1,1,1};
	colorPictureRightDisabled[]={1,1,1,0.25};
	colorPictureRightSelected[]={1,1,1,1};
	colorPictureSelected[]={1,1,1,1};
	soundSelect[]=
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.090000004,
		1
	};
	arrowEmpty="#(argb,8,8,3)color(1,1,1,1)";
	arrowFull="#(argb,8,8,3)color(1,1,1,1)";
	class ScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	style=16;
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=0;
	colorShadow[]={0,0,0,0.5};
	color[]={1,1,1,1};
	period=1.2;
	maxHistoryDelay=1;
	autoScrollSpeed=-1;
	autoScrollDelay=5;
	autoScrollRewind=0;
	class listScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
};
class cTab_RscButton
{
	access=0;
	type=1;
	text="";
	colorText[]={1,1,1,1};
	colorDisabled[]={0.40000001,0.40000001,0.40000001,1};
	colorBackground[]={0.118,0.118,0.118,0.69999999};
	colorBackgroundDisabled[]={0.94999999,0.94999999,0.94999999,1};
	colorBackgroundActive[]={0.118,0.118,0.118,1};
	colorFocused[]={0.118,0.118,0.118,1};
	colorShadow[]={0,0,0,1};
	colorBorder[]={0,0,0,1};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	style=2;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	shadow=2;
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX=0.003;
	offsetY=0.003;
	offsetPressedX=0.0020000001;
	offsetPressedY=0.0020000001;
	borderSize=0;
};
class cTab_ActiveText
{
	access=0;
	type=11;
	style=0;
	text="";
	color[]={1,1,1,1};
	colorActive[]={1,1,1,1};
	colorText[]={1,1,1,1};
	colorDisabled[]={0.40000001,0.40000001,0.40000001,1};
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		0.69999999
	};
	colorBackgroundDisabled[]={0.94999999,0.94999999,0.94999999,1};
	colorBackgroundActive[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	colorFocused[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	colorShadow[]={0,0,0,1};
	colorBorder[]={0,0,0,1};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	shadow=2;
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX=0.003;
	offsetY=0.003;
	offsetPressedX=0.0020000001;
	offsetPressedY=0.0020000001;
	borderSize=0;
};
class cTab_HTML
{
	access=0;
	style=0;
	default=0;
	blinkingPeriod=0;
	colorBackground[]={0.2,0.2,0.2,1};
	colorText[]={1,1,1,1};
	colorBold[]={1,1,1,1};
	colorLink[]={1,1,1,1};
	colorLinkActive[]={1,0.5,0,1};
	colorPicture[]={1,1,1,1};
	colorPictureBorder[]={0,0,0,0};
	colorPictureLink[]={1,1,1,1};
	colorPictureSelected[]={1,1,1,1};
	prevPage="\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
	nextPage="\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
};
class cTab_RscButtonInv
{
	access=0;
	type=1;
	text="";
	colorText[]={0,0,0,0};
	colorDisabled[]={0.40000001,0.40000001,0.40000001,0};
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		0
	};
	colorBackgroundDisabled[]={0.94999999,0.94999999,0.94999999,0};
	colorBackgroundActive[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		0
	};
	colorFocused[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		0
	};
	colorShadow[]={0,0,0,0};
	colorBorder[]={0,0,0,0};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	style=2;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	shadow=2;
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX=0.003;
	offsetY=0.003;
	offsetPressedX=0.0020000001;
	offsetPressedY=0.0020000001;
	borderSize=0;
};
class cTab_RscShortcutButton
{
	type=16;
	x=0.1;
	y=0.1;
	class HitZone
	{
		left=0;
		top=0;
		right=0;
		bottom=0;
	};
	class ShortcutPos
	{
		left=0;
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		w="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	};
	class TextPos
	{
		left="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	shortcuts[]={};
	textureNoShortcut="#(argb,8,8,3)color(0,0,0,0)";
	color[]={1,1,1,1};
	color2[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	colorBackground2[]={1,1,1,1};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	class Attributes
	{
		font="PuristaMedium";
		color="#E5E5E5";
		align="left";
		shadow="true";
	};
	idc=-1;
	style=0;
	default=0;
	shadow=1;
	w=0.183825;
	h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
	animTextureDefault="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureNormal="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureDisabled="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureOver="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
	animTextureFocused="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
	animTexturePressed="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
	periodFocus=1.2;
	periodOver=0.80000001;
	period=0.40000001;
	font="PuristaMedium";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	text="";
	action="";
	class AttributesImage
	{
		font="PuristaMedium";
		color="#E5E5E5";
		align="left";
	};
};
class cTab_RscShortcutButtonMain
{
	idc=-1;
	style=0;
	default=0;
	w=0.31372601;
	h=0.104575;
	color[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	class HitZone
	{
		left=0;
		top=0;
		right=0;
		bottom=0;
	};
	class ShortcutPos
	{
		left=0.0145;
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		w="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2) * (3/4)";
		h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	};
	class TextPos
	{
		left="(((safezoneW / safezoneH) min 1.2) / 32) * 1.5";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)*2 - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	animTextureNormal="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	animTextureDisabled="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
	animTextureOver="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
	animTextureFocused="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
	animTexturePressed="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
	animTextureDefault="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	period=0.5;
	font="PuristaMedium";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	text="";
	action="";
	class Attributes
	{
		font="PuristaMedium";
		color="#E5E5E5";
		align="left";
		shadow="false";
	};
	class AttributesImage
	{
		font="PuristaMedium";
		color="#E5E5E5";
		align="false";
	};
};
class cTab_RscFrame
{
	type=0;
	idc=-1;
	style=64;
	shadow=2;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	font="PuristaMedium";
	sizeEx=0.02;
	text="";
};
class cTab_RscSlider
{
	access=0;
	type=3;
	style=1024;
	w=0.30000001;
	color[]={1,1,1,0.80000001};
	colorActive[]={1,1,1,1};
	shadow=0;
	h=0.025;
};
class cTab_IGUIBack
{
	type=0;
	idc=124;
	style=128;
	text="";
	colorText[]={0,0,0,0};
	font="PuristaMedium";
	sizeEx=0;
	shadow=0;
	x=0.1;
	y=0.1;
	w=0.1;
	h=0.1;
	colorbackground[]=
	{
		"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"
	};
};
class cTab_RscCheckbox
{
	idc=-1;
	type=7;
	style=0;
	x="LINE_X(XVAL)";
	y="LINE_Y";
	w="LINE_W(WVAL)";
	h=0.029412;
	colorText[]={1,0,0,1};
	color[]={0,0,0,0};
	colorBackground[]={0,0,1,1};
	colorTextSelect[]={0,0.80000001,0,1};
	colorSelectedBg[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",
		1
	};
	colorSelect[]={0,0,0,1};
	colorTextDisable[]={0.40000001,0.40000001,0.40000001,1};
	colorDisable[]={0.40000001,0.40000001,0.40000001,1};
	font="PuristaMedium";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	rows=1;
	columns=1;
	strings[]=
	{
		"UNCHECKED"
	};
	checked_strings[]=
	{
		"CHECKED"
	};
};
class cTab_RscButtonMenu
{
	idc=-1;
	type=16;
	style="0x02 + 0xC0";
	default=0;
	shadow=0;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	animTextureNormal="#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled="#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver="#(argb,8,8,3)color(1,1,1,0.5)";
	animTextureFocused="#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed="#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault="#(argb,8,8,3)color(1,1,1,1)";
	textureNoShortcut="#(argb,8,8,3)color(0,0,0,0)";
	colorBackground[]={0,0,0,0.80000001};
	colorBackground2[]={1,1,1,0.5};
	color[]={1,1,1,1};
	color2[]={1,1,1,1};
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	class HitZone
	{
		left=0.0040000002;
		top=0.028999999;
		right=0.0040000002;
		bottom=0.028999999;
	};
	period=1.2;
	periodFocus=1.2;
	periodOver=1.2;
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	class TextPos
	{
		left="0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	class Attributes
	{
		font="PuristaLight";
		color="#E5E5E5";
		align="left";
		shadow="false";
	};
	class ShortcutPos
	{
		left="(6.25 * (((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005";
		top=0.0049999999;
		w=0.022500001;
		h=0.029999999;
	};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",
		0.090000004,
		1
	};
};
class cTab_RscButtonMenuOK
{
	idc=1;
	shortcuts[]=
	{
		"0x00050000 + 0",
		28,
		57,
		156
	};
	default=1;
	text="OK";
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",
		0.090000004,
		1
	};
};
class cTab_RscButtonMenuCancel
{
	idc=2;
	shortcuts[]=
	{
		"0x00050000 + 1"
	};
	text="Cancel";
};
class cTab_RscControlsGroup
{
	class VScrollbar
	{
		color[]={1,1,1,1};
		width=0.021;
		autoScrollSpeed=-1;
		autoScrollDelay=5;
		autoScrollRewind=0;
		shadow=0;
	};
	class HScrollbar
	{
		color[]={1,1,1,1};
		height=0.028000001;
		shadow=0;
	};
	class ScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	class Controls
	{
	};
	type=15;
	idc=-1;
	x=0;
	y=0;
	w=1;
	h=1;
	shadow=0;
	style=16;
};
class cTab_RscMapControl
{
	access=0;
	idc=-1;
	type=101;
	style=48;
	x=0.1;
	y=0.1;
	w=0.80000001;
	h=0.60000002;
	moveOnEdges=1;
	shadow=0;
	ptsPerSquareSea=5;
	ptsPerSquareTxt=3;
	ptsPerSquareCLn=10;
	ptsPerSquareExp=10;
	ptsPerSquareCost=10;
	ptsPerSquareFor=9;
	ptsPerSquareForEdge=9;
	ptsPerSquareRoad=6;
	ptsPerSquareObj=9;
	showCountourInterval=0;
	scaleMin=0.001;
	scaleMax=1;
	scaleDefault=0.16;
	maxSatelliteAlpha=0.85000002;
	alphaFadeStartScale=0.34999999;
	alphaFadeEndScale=0.40000001;
	colorBackground[]={0.96899998,0.95700002,0.949,1};
	colorSea[]={0.46700001,0.63099998,0.85100001,0.5};
	colorForest[]={0.40000001,1,0.40000001,0.30000001};
	colorForestBorder[]={0,0,0,0};
	colorRocks[]={0,0,0,0.30000001};
	colorRocksBorder[]={0,0,0,0};
	colorLevels[]={0,0,0,1};
	colorMainCountlines[]={1,0,0,1};
	colorCountlines[]={1,0,0,0.5};
	colorMainCountlinesWater[]={0.491,0.57700002,0.70200002,0.60000002};
	colorCountlinesWater[]={0.491,0.57700002,0.70200002,0.30000001};
	colorPowerLines[]={0.1,0.1,0.1,1};
	colorRailWay[]={0.80000001,0.2,0,1};
	colorNames[]={0,0,0,1};
	colorInactive[]={1,1,1,0.5};
	colorOutside[]={0.5,0.5,0.5,1};
	colorTracks[]={0.83999997,0.75999999,0.64999998,1};
	colorTracksFill[]={0.83999997,0.75999999,0.64999998,1};
	colorRoads[]={1,0.80000001,0,1};
	colorRoadsFill[]={1,0.80000001,0,1};
	colorMainRoads[]={1,0.60000002,0.40000001,1};
	colorMainRoadsFill[]={1,0.60000002,0.40000001,1};
	colorGrid[]={0.1,0.1,0.1,0.60000002};
	colorGridMap[]={0.1,0.1,0.1,0.60000002};
	fontLabel="PuristaMedium";
	sizeExLabel="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontGrid="TahomaB";
	sizeExGrid=0.02;
	fontUnits="TahomaB";
	sizeExUnits="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontNames="PuristaMedium";
	sizeExNames="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8) * 2";
	fontInfo="PuristaMedium";
	sizeExInfo="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	fontLevel="TahomaB";
	sizeExLevel=0.02;
	colorText[]={1,1,1,1};
	font="PuristaMedium";
	text="#(argb,8,8,3)color(1,1,1,1)";
	SizeEx="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	widthRailWay=1;
	class LineMarker
	{
		lineWidthThin=0.0080000004;
		lineWidthThick=0.014;
		lineLengthMin=5;
		lineDistanceMin=2.9999999e-005;
		textureComboBoxColor="#(argb,8,8,3)color(1,1,1,1)";
	};
	class Legend
	{
		x="SafeZoneX +      (   ((safezoneW / safezoneH) min 1.2) / 40)";
		y="SafeZoneY + safezoneH - 4.5 *      (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		w="10 *      (   ((safezoneW / safezoneH) min 1.2) / 40)";
		h="3.5 *      (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		font="PuristaMedium";
		sizeEx="(   (   (   ((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
		colorBackground[]={1,1,1,0.5};
		color[]={0,0,0,1};
	};
	class Task
	{
		icon="\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
		iconCreated="\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
		iconCanceled="\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
		iconDone="\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
		iconFailed="\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
		color[]=
		{
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
		};
		colorCreated[]={1,1,1,1};
		colorCanceled[]={0.69999999,0.69999999,0.69999999,1};
		colorDone[]={0.69999999,1,0.30000001,1};
		colorFailed[]={1,0.30000001,0.2,1};
		size=27;
		importance=1;
		coefMin=1;
		coefMax=1;
	};
	class Waypoint
	{
		icon="\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		color[]={0,0,0,1};
		size=27;
		importance=1;
		coefMin=1;
		coefMax=1;
	};
	class WaypointCompleted
	{
		icon="\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
		color[]={0,0,0,1};
		size=27;
		importance=1;
		coefMin=1;
		coefMax=1;
	};
	class CustomMark
	{
		icon="\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
		size=24;
		importance=1;
		coefMin=1;
		coefMax=1;
		color[]={0,0,0,1};
	};
	class Command
	{
		icon="\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size=18;
		importance=1;
		coefMin=1;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class Bush
	{
		icon="\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		color[]={0.44999999,0.63999999,0.33000001,0.40000001};
		size="14/2";
		importance="0.2 * 14 * 0.05 * 0.05";
		coefMin=0.25;
		coefMax=4;
	};
	class Rock
	{
		icon="\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
		color[]={0.1,0.1,0.1,0.80000001};
		size=12;
		importance="0.5 * 12 * 0.05";
		coefMin=0.25;
		coefMax=4;
	};
	class SmallTree
	{
		icon="\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		color[]={0.44999999,0.63999999,0.33000001,0.40000001};
		size=12;
		importance="0.6 * 12 * 0.05";
		coefMin=0.25;
		coefMax=4;
	};
	class Tree
	{
		icon="\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		color[]={0.44999999,0.63999999,0.33000001,0.40000001};
		size=12;
		importance="0.9 * 16 * 0.05";
		coefMin=0.25;
		coefMax=4;
	};
	class busstop
	{
		icon="\A3\ui_f\data\map\mapcontrol\busstop_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class fuelstation
	{
		icon="\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class hospital
	{
		icon="\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class church
	{
		icon="\A3\ui_f\data\map\mapcontrol\church_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class lighthouse
	{
		icon="\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class power
	{
		icon="\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class powersolar
	{
		icon="\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class powerwave
	{
		icon="\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class powerwind
	{
		icon="\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class quay
	{
		icon="\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class shipwreck
	{
		icon="\A3\ui_f\data\map\mapcontrol\shipwreck_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class transmitter
	{
		icon="\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class watertower
	{
		icon="\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={1,1,1,1};
	};
	class Cross
	{
		icon="\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={0,0,0,1};
	};
	class Chapel
	{
		icon="\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
		size=24;
		importance=1;
		coefMin=0.85000002;
		coefMax=1;
		color[]={0,0,0,1};
	};
	class Bunker
	{
		icon="\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size=14;
		importance="1.5 * 14 * 0.05";
		coefMin=0.25;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class Fortress
	{
		icon="\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size=16;
		importance="2 * 16 * 0.05";
		coefMin=0.25;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class Fountain
	{
		icon="\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
		size=11;
		importance="1 * 12 * 0.05";
		coefMin=0.25;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class Ruin
	{
		icon="\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
		size=16;
		importance="1.2 * 16 * 0.05";
		coefMin=1;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class Stack
	{
		icon="\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
		size=20;
		importance="2 * 16 * 0.05";
		coefMin=0.89999998;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class Tourism
	{
		icon="\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
		size=16;
		importance="1 * 16 * 0.05";
		coefMin=0.69999999;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class ViewTower
	{
		icon="\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
		size=16;
		importance="2.5 * 16 * 0.05";
		coefMin=0.5;
		coefMax=4;
		color[]={0,0,0,1};
	};
	class ActiveMarker
	{
		size=24;
		importance=1;
		coefMin=1;
		coefMax=1;
		color[]={0,0,0,1};
	};
};
class cTab_MenuItem: cTab_ActiveText
{
	colorActive[]=
	{
		"255/255",
		"165/255",
		"0/255",
		1
	};
};
class cTab_MenuExit: cTab_MenuItem
{
	color[]={1,1,1,0.75};
};
class cTab_RscText_Tablet: cTab_RscText
{
	style=2;
	w="(((((1341)) - (10) * 8) / 7)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(((42) - (10))) / 2048  *  (safezoneH * 1.2)";
	font="EtelkaMonospacePro";
	colorText[]={1,1,1,1};
	sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
	colorBackground[]={0,0,0,0};
	shadow=0;
};
class cTab_RscListbox_Tablet: cTab_RscListBox
{
	sizeEx="((27) * 1.2) / 2048  *  (safezoneH * 1.2)";
};
class cTab_RscEdit_Tablet: cTab_RscEdit
{
	sizeEx="((27) * 1.2) / 2048  *  (safezoneH * 1.2)";
};
class cTab_RscButton_Tablet: cTab_RscButton
{
	font="EtelkaMonospacePro";
	sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_background: cTab_RscPicture
{
	idc=1200;
	text="";
	x="(safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="( (safezoneH * 1.2) * 3/4)";
	h="(safezoneH * 1.2)";
};
class cTab_tablet_header: cTab_RscPicture
{
	idc=1;
	text="#(argb,8,8,3)color(0,0,0,1)";
	x="((257)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((491)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="((1341)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="((42)) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_OSD_battery: cTab_RscPicture
{
	idc=2;
	text="\cTab\img\icon_battery_ca.paa";
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (1 - 1))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((491) + ((42) - (35)) / 2) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="((35)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="((35)) / 2048  *  (safezoneH * 1.2)";
	colorText[]={1,1,1,1};
};
class cTab_Tablet_OSD_time: cTab_RscText_Tablet
{
	idc=2613;
	style=2;
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (4 - 1))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((491) + ((42) - (27)) / 2) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_OSD_signalStrength: cTab_Tablet_OSD_battery
{
	idc=3;
	text="\cTab\img\icon_signalStrength_ca.paa";
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (7 - 1)) + ((((1341)) - (10) * 8) / 7) - (35) * 2) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	colorText[]={1,1,1,1};
};
class cTab_Tablet_OSD_satellite: cTab_Tablet_OSD_battery
{
	idc=4;
	text="\a3\ui_f\data\map\Diary\signal_ca.paa";
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (7 - 1)) + ((((1341)) - (10) * 8) / 7) - (35)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	colorText[]={1,1,1,1};
};
class cTab_Tablet_OSD_dirDegree: cTab_Tablet_OSD_time
{
	idc=2615;
	style=0;
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (2 - 1))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_OSD_grid: cTab_Tablet_OSD_dirDegree
{
	idc=2612;
	style=1;
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (6 - 1))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_OSD_dirOctant: cTab_Tablet_OSD_dirDegree
{
	idc=2616;
	style=1;
	x="((((10) + ((257))) + ((10) + ((((1341)) - (10) * 8) / 7)) * (1 - 1))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_window_back_TL: cTab_RscPicture
{
	text="\cTab\img\window_2.jpg";
	x="((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_window_back_BL: cTab_Tablet_window_back_TL
{
	y="((((491) + (42)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3 * 2)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_window_back_TR: cTab_Tablet_window_back_TL
{
	x="((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_window_back_BR: cTab_Tablet_window_back_TR
{
	y="((((491) + (42)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3 * 2)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_btnF1: cTab_RscButtonInv
{
	x="(506) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(1545) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(52) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(52) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_btnF2: cTab_Tablet_btnF1
{
	x="(569) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnF3: cTab_Tablet_btnF1
{
	x="(639) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnF4: cTab_Tablet_btnF1
{
	x="(703) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnF5: cTab_Tablet_btnF1
{
	x="(768) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnF6: cTab_Tablet_btnF1
{
	x="(833) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnFn: cTab_Tablet_btnF1
{
	x="(970) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnPower: cTab_Tablet_btnFn
{
	x="(1034) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnBrtDn: cTab_Tablet_btnFn
{
	x="(1100) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnBrtUp: cTab_Tablet_btnFn
{
	x="(1163) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
};
class cTab_Tablet_btnTrackpad: cTab_Tablet_btnFn
{
	x="(1262) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(1550) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(48) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(43) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_btnMouse: cTab_Tablet_btnFn
{
	x="(1401) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	w="(91) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
};
class cTab_Tablet_btnHome: cTab_Tablet_btnMouse
{
	x="(897) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(1534) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(61) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(49) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_notificationLight
{
	x="(1353) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(1557) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(28) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(28) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_OSD_hookGrid: cTab_RscText_Tablet
{
	idc=2617;
	style=2;
	x="(((-(10) + ((257)) + ((1341))) - ((((1341)) - (10) * 8) / 7))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((-(0) + (491) + (993)) - (10) - ((42) - (10)) * 4) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	colorText[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.25};
};
class cTab_Tablet_OSD_hookElevation: cTab_Tablet_OSD_hookGrid
{
	idc=2620;
	y="((-(0) + (491) + (993)) - (10) - ((42) - (10)) * 3) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_OSD_hookDst: cTab_Tablet_OSD_hookGrid
{
	idc=2619;
	y="((-(0) + (491) + (993)) - (10) - ((42) - (10)) * 2) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_OSD_hookDir: cTab_Tablet_OSD_hookGrid
{
	idc=2618;
	y="((-(0) + (491) + (993)) - (10) - ((42) - (10))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
};
class cTab_Tablet_loadingtxt: cTab_RscText_Tablet
{
	idc=1000;
	style=2;
	text="Loading";
	x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
	colorBackground[]={0.2,0.43099999,0.64700001,1};
};
class cTab_Tablet_movingHandle_T: cTab_RscText_Tablet
{
	idc=5;
	moving=1;
	colorBackground[]={0,0,0,0};
	x="(0) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(0) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(2048 ) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="((491)) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_movingHandle_B: cTab_Tablet_movingHandle_T
{
	idc=6;
	y="((491) + (993)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	h="(2048  - ((491) + (993))) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_movingHandle_L: cTab_Tablet_movingHandle_T
{
	idc=7;
	y="((491)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="((257)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="((993)) / 2048  *  (safezoneH * 1.2)";
};
class cTab_Tablet_movingHandle_R: cTab_Tablet_movingHandle_L
{
	idc=8;
	x="((257) + (1341)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	w="(2048  - ((257) + (1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
};
class cTab_Tablet_brightness: cTab_RscText_Tablet
{
	idc=1005;
	x="((257)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="((491)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="((1341)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="((993)) / 2048  *  (safezoneH * 1.2)";
	colorBackground[]={0,0,0,0};
};
class cTab_Tablet_RscMapControl: cTab_RscMapControl
{
	text="#(argb,8,8,3)color(1,1,1,1)";
	x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
	maxSatelliteAlpha=10000;
	alphaFadeStartScale=10;
	alphaFadeEndScale=10;
	ptsPerSquareSea="8 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareTxt="8 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareCLn="8 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareExp="8 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareCost="8 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareFor="3 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareForEdge="100 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareRoad="1.5 / (0.86 /  (safezoneH * 1.2))";
	ptsPerSquareObj="4 / (0.86 /  (safezoneH * 1.2))";
	widthRailWay=1;
};
class cTab_Tablet_notification: cTab_RscText_Tablet
{
	idc=1620;
	x="(((257)) + (((1341)) * 0.5) / 2) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
	y="(((491) + (42)) + ((993) - (42) - (0)) - 2 * (27)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
	w="(((1341)) * 0.5) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
	colorBackground[]={0,0,0,1};
};
class cTab_Tablet_dlg
{
	idd=1775154;
	movingEnable="true";
	onLoad="_this call cTab_fnc_onIfOpen;";
	onUnload="[] call cTab_fnc_onIfclose;";
	onKeyDown="_this call cTab_fnc_onIfKeyDown;";
	objects[]={};
	class controlsBackground
	{
		class windowsBG: cTab_RscPicture
		{
			idc=1210;
			text="\cTab\img\window_background.paa";
			x="((257)) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="((491)) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="((1341)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="((993)) / 2048  *  (safezoneH * 1.2)";
		};
		class windowsBar: cTab_RscPicture
		{
			idc=1211;
			text="\cTab\img\Desktop_bar.jpg";
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (993) - (((1341)) / (1024) * (28)))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="((((1341)) / (1024) * (28))) / 2048  *  (safezoneH * 1.2)";
		};
		class MiniMapBG: cTab_Tablet_window_back_BL
		{
			idc=1218;
		};
		class cTabUavMap: cTab_Tablet_RscMapControl
		{
			idc=1774;
			x="(((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((((491) + (42)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3 * 2) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
			onDraw="nop = _this call cTabOnDrawUAV;";
			onMouseButtonDblClick="";
		};
		class cTabHcamMap: cTabUavMap
		{
			idc=1220;
			onDraw="nop = _this call cTabOnDrawHCam;";
		};
		class screen: cTab_Tablet_RscMapControl
		{
			idc=1201;
			onDraw="nop = _this call cTabOnDrawbft;";
			onMouseButtonDblClick="_ok = [3300,_this] execVM '\cTab\shared\cTab_markerMenu_load.sqf';";
			onMouseMoving="cTabCursorOnMap = _this select 3;cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
		};
		class screenTopo: screen
		{
			idc=1202;
			maxSatelliteAlpha=0;
		};
	};
	class controls
	{
		class header: cTab_tablet_header
		{
		};
		class battery: cTab_Tablet_OSD_battery
		{
		};
		class time: cTab_Tablet_OSD_time
		{
		};
		class signalStrength: cTab_Tablet_OSD_signalStrength
		{
		};
		class satellite: cTab_Tablet_OSD_satellite
		{
		};
		class dirDegree: cTab_Tablet_OSD_dirDegree
		{
		};
		class grid: cTab_Tablet_OSD_grid
		{
		};
		class dirOctant: cTab_Tablet_OSD_dirOctant
		{
		};
		class hookGrid: cTab_Tablet_OSD_hookGrid
		{
		};
		class hookElevation: cTab_Tablet_OSD_hookElevation
		{
		};
		class hookDst: cTab_Tablet_OSD_hookDst
		{
		};
		class hookDir: cTab_Tablet_OSD_hookDir
		{
		};
		class Desktop: cTab_RscControlsGroup
		{
			idc=4610;
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class actBFTtxt: cTab_ActiveText
				{
					style=48;
					idc=1001;
					text="\cTab\img\cTab_BFT_ico.paa";
					x="(((((257)) + (25)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((491) + (42)) + (25)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((100)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((100)) / 2048  *  (safezoneH * 1.2)";
					action="['cTab_Tablet_dlg',[['mode','BFT']]] call cTab_fnc_setSettings;";
					toolTip="ATAK - Blue Force Tracker";
				};
				class actUAVtxt: actBFTtxt
				{
					idc=1002;
					text="\cTab\img\cTab_UAV_ico.paa";
					y="(((((491) + (42)) + (25) * 2 + (100)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					action="['cTab_Tablet_dlg',[['mode','UAV']]] call cTab_fnc_setSettings;";
					toolTip="ATAK - ISR Access";
				};
				class actVIDtxt: actBFTtxt
				{
					idc=1003;
					text="\cTab\img\cTab_HMC_ico.paa";
					y="(((((491) + (42)) + (25) * 3 + (100) * 2) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					action="['cTab_Tablet_dlg',[['mode','HCAM']]] call cTab_fnc_setSettings;";
					toolTip="ATAK - Helmet Camera Access";
				};
				class actMSGtxt: actBFTtxt
				{
					idc=1004;
					text="\cTab\img\Mail_Main_Icon_ico.paa";
					y="(((((491) + (42)) + (25) * 4 + (100) * 3) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					action="['cTab_Tablet_dlg',[['mode','MESSAGE']]] call cTab_fnc_setSettings;";
					toolTip="ATAK - Text Messaging System";
				};
			};
		};
		class UAV: cTab_RscControlsGroup
		{
			idc=4630;
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class UAVListBG: cTab_Tablet_window_back_TL
				{
					idc=9;
					x="((((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
				};
				class UAVVidBG1: cTab_Tablet_window_back_TR
				{
					idc=10;
					x="((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
				};
				class UAVVidBG2: cTab_Tablet_window_back_BR
				{
					idc=11;
					x="((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3 * 2)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
				};
				class cTabUAVlist: cTab_RscListbox_Tablet
				{
					idc=1776;
					x="(((((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
					onLBSelChanged="if (!cTabIfOpenStart && (_this select 1 != -1)) then {['cTab_Tablet_dlg',[['uavCam',(_this select 0) lbData (_this select 1)]]] call cTab_fnc_setSettings;};";
				};
				class cTabUAVdisplay: cTab_RscPicture
				{
					idc=1773;
					text="#(argb,512,512,1)r2t(rendertarget8,1.1896551724)";
					x="(((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
				};
				class cTabUAV2nddisplay: cTab_RscPicture
				{
					idc=1775;
					text="#(argb,512,512,1)r2t(rendertarget9,1.1896551724)";
					x="(((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3 * 2) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
				};
			};
		};
		class HCAM: cTab_RscControlsGroup
		{
			idc=4640;
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class HcamListBG: cTab_Tablet_window_back_TL
				{
					idc=12;
					x="((((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
				};
				class HcamVidBG: cTab_Tablet_window_back_TR
				{
					idc=13;
					x="((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2)) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3)) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
				};
				class cTabHcamList: cTab_RscListbox_Tablet
				{
					idc=1230;
					x="(((((((257)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
					onLBSelChanged="if (!cTabIfOpenStart && (_this select 1 != -1)) then {['cTab_Tablet_dlg',[['hCam',(_this select 0) lbData (_this select 1)]]] call cTab_fnc_setSettings;};";
				};
				class cTabHcamDisplay: cTab_RscPicture
				{
					idc=1240;
					text="#(argb,512,512,1)r2t(rendertarget12,1.1896551724)";
					x="(((((((257)) + ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) + (((1341)) - 2 * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 3 * 2) + ((9) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - 2 * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)) / 3) + ((30) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((276) / (293) * ((293) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49)))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((232) / (272) * ((((993) - (42) - (0)) - (((1341)) / (1024) * (28))) * 0.49))) / 2048  *  (safezoneH * 1.2)";
				};
			};
		};
		class MESSAGE: cTab_RscControlsGroup
		{
			idc=4650;
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class msgframe: cTab_RscFrame
				{
					idc=14;
					text="Read Message";
					x="((((((257)) + (20))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((491) + (42)) + (10))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((((1341)) - (20) * 2)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2)) / 2048  *  (safezoneH * 1.2)";
				};
				class msgListbox: cTab_RscListbox_Tablet
				{
					idc=15000;
					style=32;
					x="(((((((257)) + (20)) + (10))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (10)) + (20))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((((((1341)) - (20) * 2) - (10) * 3) / 3)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20))) / 2048  *  (safezoneH * 1.2)";
					onLBSelChanged="_this call cTab_msg_get_mailTxt;";
				};
				class msgTxt: cTab_RscEdit_Tablet
				{
					idc=18510;
					htmlControl="true";
					style=16;
					lineSpacing=0.2;
					text="No Message Selected";
					x="((((((((257)) + (20)) + (10)) + (((((1341)) - (20) * 2) - (10) * 3) / 3) + (10))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((((491) + (42)) + (10)) + (20)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((((((1341)) - (20) * 2) - (10) * 3) / 3) * 2)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20)) - (10) - (50))) / 2048  *  (safezoneH * 1.2)";
					canModify=0;
				};
				class composeFrame: cTab_RscFrame
				{
					idc=15;
					text="Compose Message";
					x="(((((((257)) + (20)))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((491) + (42)) + (10)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) + (10))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((((1341)) - (20) * 2))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2))) / 2048  *  (safezoneH * 1.2)";
				};
				class playerlistbox: cTab_RscListbox_Tablet
				{
					idc=15010;
					style=32;
					x="((((((((257)) + (20)) + (10)))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((((491) + (42)) + (10)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) + (10)) + (20))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="(((((((1341)) - (20) * 2) - (10) * 3) / 3))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="(((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20)))) / 2048  *  (safezoneH * 1.2)";
				};
				class deletebtn: cTab_RscButton_Tablet
				{
					idc=16120;
					text="Delete";
					tooltip="Delete Selected Message(s)";
					x="(((((((((257)) + (20))) + ((((1341)) - (20) * 2)) - (10) - (150)))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((((491) + (42)) + (10)) + (20))) + ((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20)) - (10) - (50)) + (10))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((150)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((50)) / 2048  *  (safezoneH * 1.2)";
					action="['cTab_Tablet_dlg'] call cTab_fnc_onMsgBtnDelete;";
				};
				class sendbtn: cTab_RscButton_Tablet
				{
					idc=16130;
					text="Send";
					x="((((((((257)) + (20))) + ((((1341)) - (20) * 2)) - (10) - (150))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="((((((((((491) + (42)) + (10)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) + (10)) + (20))) + (((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20)) - (10) - (50))) + (10))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((150)) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((50)) / 2048  *  (safezoneH * 1.2)";
					action="call cTab_msg_Send;";
				};
				class edittxtbox: cTab_RscEdit_Tablet
				{
					idc=14000;
					htmlControl="true";
					style=16;
					lineSpacing=0.2;
					text="";
					x="(((((((((257)) + (20)) + (10)) + (((((1341)) - (20) * 2) - (10) * 3) / 3) + (10)))) - ((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4))";
					y="(((((((((491) + (42)) + (10)) + ((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) + (10)) + (20)))) - ((491) + (42))) / 2048  *  (safezoneH * 1.2))";
					w="((((((((1341)) - (20) * 2) - (10) * 3) / 3) * 2))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
					h="((((((((993) - (42) - (0)) - (((1341)) / (1024) * (28)) - (10) * 3) / 2) - (10) - (20)) - (10) - (50)))) / 2048  *  (safezoneH * 1.2)";
				};
			};
		};
		class cTabHcamFull: cTab_RscPicture
		{
			idc=1245;
			text="#(argb,512,512,1)r2t(rendertarget13,1.3096153846)";
			x="(((257))) / 2048  *  ( (safezoneH * 1.2) * 3/4) +  (safezoneX + (safezoneW -  ( (safezoneH * 1.2) * 3/4)) / 2 + ( ( (safezoneH * 1.2) * 3/4) * 96.5 / 2048))";
			y="(((491) + (42))) / 2048  *  (safezoneH * 1.2) +  (safezoneY + (safezoneH -  (safezoneH * 1.2)) / 2)";
			w="(((1341))) / 2048  *  ( (safezoneH * 1.2) * 3/4)";
			h="(((993) - (42) - (0))) / 2048  *  (safezoneH * 1.2)";
		};
		class notification: cTab_Tablet_notification
		{
		};
		class loadingtxt: cTab_Tablet_loadingtxt
		{
		};
		class brightness: cTab_Tablet_brightness
		{
		};
		class MainSubmenu: cTab_RscControlsGroup
		{
			idc=3300;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(5 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class mainbg: cTab_IGUIBack
				{
					idc=2200;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(5 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class op4btn: cTab_MenuItem
				{
					idc=2000;
					text="Enemy SALUTE";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[11] call cTab_fnc_userMenuSelect;";
				};
				class medbtn: cTab_MenuItem
				{
					idc=2001;
					text="Medical";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[21] call cTab_fnc_userMenuSelect;";
				};
				class genbtn: cTab_MenuItem
				{
					idc=2002;
					text="General";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[31] call cTab_fnc_userMenuSelect;";
				};
				class lockUavCam: cTab_MenuItem
				{
					idc=-1;
					text="Lock UAV Cam";
					toolTip="Lock UAV Cam to this position, a UAV has to be previously selected";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[2] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub1: cTab_RscControlsGroup
		{
			idc=3301;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(8 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2201: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(8 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class infbtn: cTab_MenuItem
				{
					idc=2003;
					text="Infantry";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,0];[12] call cTab_fnc_userMenuSelect;";
				};
				class mecinfbtn: cTab_MenuItem
				{
					idc=2004;
					text="Mechanized Inf";
					toolTip="Equipped with APCs/IFVs";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,1];[12] call cTab_fnc_userMenuSelect;";
				};
				class motrinfbtn: cTab_MenuItem
				{
					idc=2032;
					text="Motorized Inf";
					toolTip="Equipped with un-protected vehicles";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,2];[12] call cTab_fnc_userMenuSelect;";
				};
				class amrbtn: cTab_MenuItem
				{
					idc=2005;
					text="Armor";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,3];[12] call cTab_fnc_userMenuSelect;";
				};
				class helibtn: cTab_MenuItem
				{
					idc=2006;
					text="Helicopter";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,4];[12] call cTab_fnc_userMenuSelect;";
				};
				class plnbtn: cTab_MenuItem
				{
					idc=2007;
					text="Plane";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,5];[12] call cTab_fnc_userMenuSelect;";
				};
				class uknbtn: cTab_MenuItem
				{
					idc=2008;
					text="Unknown";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,6];[12] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub2: cTab_RscControlsGroup
		{
			idc=3303;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(6 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(6 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class ftbtn: cTab_MenuItem
				{
					idc=2009;
					text="Singular";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[14] call cTab_fnc_userMenuSelect;";
				};
				class patbtn: cTab_MenuItem
				{
					idc=2010;
					text="Patrol";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [2,1];[13] call cTab_fnc_userMenuSelect;";
				};
				class sqdbtn: cTab_MenuItem
				{
					idc=2011;
					text="Squad";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [2,2];[13] call cTab_fnc_userMenuSelect;";
				};
				class sctbtn: cTab_MenuItem
				{
					idc=2012;
					text="Section";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [2,3];[13] call cTab_fnc_userMenuSelect;";
				};
				class pltnbtn: cTab_MenuItem
				{
					idc=2013;
					text="Platoon";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [2,4];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub3: cTab_RscControlsGroup
		{
			idc=3304;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(10 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2203: cTab_IGUIBack
				{
					idc=2203;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(10 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class stnbtn: cTab_MenuItem
				{
					idc=2029;
					text="Stationary";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[1] call cTab_fnc_userMenuSelect;";
				};
				class nthbtn: cTab_MenuItem
				{
					idc=2015;
					text="N";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,1];[1] call cTab_fnc_userMenuSelect;";
				};
				class nebtn: cTab_MenuItem
				{
					idc=2016;
					text="NE";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,2];[1] call cTab_fnc_userMenuSelect;";
				};
				class ebtn: cTab_MenuItem
				{
					idc=2017;
					text="E";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,3];[1] call cTab_fnc_userMenuSelect;";
				};
				class sebtn: cTab_MenuItem
				{
					idc=2018;
					text="SE";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,4];[1] call cTab_fnc_userMenuSelect;";
				};
				class sbtn: cTab_MenuItem
				{
					idc=2019;
					text="S";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,5];[1] call cTab_fnc_userMenuSelect;";
				};
				class swbtn: cTab_MenuItem
				{
					idc=2020;
					text="SW";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,6];[1] call cTab_fnc_userMenuSelect;";
				};
				class wbtn: cTab_MenuItem
				{
					idc=2021;
					text="W";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,7];[1] call cTab_fnc_userMenuSelect;";
				};
				class RscText_1022: cTab_MenuItem
				{
					idc=2022;
					text="NW";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (9 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [3,8];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (10 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub4: cTab_RscControlsGroup
		{
			idc=3307;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(8 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(8 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class rifle_btn: cTab_MenuItem
				{
					idc=-1;
					text="Rifle";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,7];[13] call cTab_fnc_userMenuSelect;";
				};
				class lmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="MG";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,8];[13] call cTab_fnc_userMenuSelect;";
				};
				class at_btn: cTab_MenuItem
				{
					idc=-1;
					text="AT";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,9];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static MG";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,10];[13] call cTab_fnc_userMenuSelect;";
				};
				class mat_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AT";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,11];[13] call cTab_fnc_userMenuSelect;";
				};
				class aa_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AA";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,13];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmortar_btn: cTab_MenuItem
				{
					idc=-1;
					text="Mortar";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,12];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class CasulSub1: cTab_RscControlsGroup
		{
			idc=3305;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(5 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2204: cTab_IGUIBack
				{
					idc=2204;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(5 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class casltybtn: cTab_MenuItem
				{
					idc=2024;
					text="Casualty";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,20];[1] call cTab_fnc_userMenuSelect;";
				};
				class ccpbtn: cTab_MenuItem
				{
					idc=2025;
					text="CCP";
					toolTip="Casualty Collection Point";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,21];[1] call cTab_fnc_userMenuSelect;";
				};
				class basbtn: cTab_MenuItem
				{
					idc=2026;
					text="BAS";
					toolTip="Battalion Aid Station";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,22];[1] call cTab_fnc_userMenuSelect;";
				};
				class mcibtn: cTab_MenuItem
				{
					idc=2031;
					text="MCI";
					toolTip="Mass Casualty Incident";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,23];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class GenSub1: cTab_RscControlsGroup
		{
			idc=3306;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
			h="(3 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
			class controls
			{
				class IGUIBack_2205: cTab_IGUIBack
				{
					idc=2205;
					x=0;
					y=0;
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="(3 + 0.5) * ((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
				};
				class hqbtn: cTab_MenuItem
				{
					idc=2027;
					text="HQ";
					toolTip="Headquaters";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,30];[1] call cTab_fnc_userMenuSelect;";
				};
				class lzbtn: cTab_MenuItem
				{
					idc=2028;
					text="LZ";
					toolTip="Landing Zone";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="cTabUserSelIcon set [1,31];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((27)) / 2048  *  (safezoneH * 1.2) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((27)) / 2048  *  (safezoneH * 1.2) * 3/4 * 0.5";
					h="((27)) / 2048  *  (safezoneH * 1.2) / 0.8";
					sizeEx="((27)) / 2048  *  (safezoneH * 1.2)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class background: cTab_Tablet_background
		{
		};
		class movingHandle_T: cTab_Tablet_movingHandle_T
		{
		};
		class movingHandle_B: cTab_Tablet_movingHandle_B
		{
		};
		class movingHandle_L: cTab_Tablet_movingHandle_L
		{
		};
		class movingHandle_R: cTab_Tablet_movingHandle_R
		{
		};
		class btnF1: cTab_Tablet_btnF1
		{
			idc=1600;
			tooltip="Blue Force Tracker - Quick Key";
			action="['cTab_Tablet_dlg',[['mode','BFT']]] call cTab_fnc_setSettings;";
		};
		class btnF2: cTab_Tablet_btnF2
		{
			idc=1601;
			tooltip="ISR Access - Quick Key";
			action="['cTab_Tablet_dlg',[['mode','UAV']]] call cTab_fnc_setSettings;";
		};
		class btnF3: cTab_Tablet_btnF3
		{
			idc=1602;
			tooltip="Helmet Camera Access - Quick Key";
			action="['cTab_Tablet_dlg',[['mode','HCAM']]] call cTab_fnc_setSettings;";
		};
		class btnF4: cTab_Tablet_btnF4
		{
			idc=1603;
			tooltip="Text Message System - Quick Key";
			action="['cTab_Tablet_dlg',[['mode','MESSAGE']]] call cTab_fnc_setSettings;";
		};
		class btnF5: cTab_Tablet_btnF5
		{
			idc=1604;
			tooltip="Toggle Map Tools (F5)";
			action="['cTab_Tablet_dlg'] call cTab_fnc_toggleMapTools;";
		};
		class btnF6: cTab_Tablet_btnF6
		{
			idc=1605;
			tooltip="Toggle Map Textures (F6)";
			action="['cTab_Tablet_dlg'] call cTab_fnc_mapType_toggle;";
		};
		class btnF7: cTab_Tablet_btnTrackpad
		{
			idc=16;
			action="['cTab_Tablet_dlg'] call cTab_fnc_centerMapOnPlayerPosition;";
			tooltip="Center Map On Current Position (F7)";
		};
		class btnMain: cTab_Tablet_btnHome
		{
			idc=1606;
			tooltip="Main Menu";
			action="['cTab_Tablet_dlg',[['mode','DESKTOP']]] call cTab_fnc_setSettings;";
		};
		class btnFN: cTab_Tablet_btnFn
		{
			idc=1607;
			action="['cTab_Tablet_dlg'] call cTab_fnc_iconText_toggle;";
			tooltip="Toggle Text on/off";
		};
		class btnOFF: cTab_Tablet_btnPower
		{
			idc=1608;
			action="closeDialog 0;";
			tooltip="Close Interface";
		};
		class btnUP: cTab_Tablet_btnBrtUp
		{
			idc=1609;
			action="call cTab_fnc_txt_size_inc;";
			tooltip="Increase Font";
		};
		class btnDWN: cTab_Tablet_btnBrtDn
		{
			idc=1610;
			action="call cTab_fnc_txt_size_dec;";
			tooltip="Decrease Font";
		};
		class btnACT: cTab_Tablet_btnMouse
		{
			idc=1611;
			action="_null = [] call cTab_Tablet_btnACT;";
			tooltip="";
		};
	};
};
class cTab_RscText_Android: cTab_RscText
{
	style=2;
	w="((((1098) - (20) * 6) / 5)) / 2048  *  (safezoneW * 0.8)";
	h="(((60) - (20))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	font="EtelkaMonospacePro";
	colorText[]={1,1,1,1};
	sizeEx="((38)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	colorBackground[]={0,0,0,0};
	shadow=0;
};
class cTab_android_RscMapControl: cTab_RscMapControl
{
	idc=1201;
	text="#(argb,8,8,3)color(1,1,1,1)";
	x="(((452))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(((1098))) / 2048  *  (safezoneW * 0.8)";
	h="(((626) - (60) - (0))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	scaleMax=1000;
	scaleDefault="(missionNamespace getVariable 'cTabMapScale') * 0.86 / safezoneH";
	maxSatelliteAlpha=10000;
	alphaFadeStartScale=10;
	alphaFadeEndScale=10;
	ptsPerSquareSea="8 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareTxt="8 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareCLn="8 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareExp="8 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareCost="8 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareFor="3 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareForEdge="100 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareRoad="1.5 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	ptsPerSquareObj="4 / (0.86 /  ( (safezoneW * 0.8) * 4/3))";
	widthRailWay=1;
};
class cTab_android_background: cTab_RscPicture
{
	idc=1200;
	text="";
	x="(safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(safezoneW * 0.8)";
	h="( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_btnBack: cTab_RscButtonInv
{
	x="(1550) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(806) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(102) / 2048  *  (safezoneW * 0.8)";
	h="(102) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_btnMenu: cTab_android_btnBack
{
	y="(1140) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_btnHome: cTab_android_btnBack
{
	x="(1550) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(972) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_btnPower: cTab_RscButtonInv
{
	x="(1583) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(1407) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(107) / 2048  *  (safezoneW * 0.8)";
	h="(48) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_notificationLight
{
	x="(360) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(834) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(35) / 2048  *  (safezoneW * 0.8)";
	h="(35) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_header: cTab_RscPicture
{
	idc=1;
	text="#(argb,8,8,3)color(0,0,0,1)";
	x="((452)) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((713)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="((1098)) / 2048  *  (safezoneW * 0.8)";
	h="((60)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_on_screen_battery: cTab_RscPicture
{
	idc=2;
	text="\cTab\img\icon_battery_ca.paa";
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((713) + ((60) - (42)) / 2) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="((42)) / 2048  *  (safezoneW * 0.8)";
	h="((42)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	colorText[]={1,1,1,1};
};
class cTab_android_on_screen_time: cTab_RscText_Android
{
	idc=2613;
	style=2;
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (3 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((713) + ((60) - (38)) / 2) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_on_screen_signalStrength: cTab_android_on_screen_battery
{
	idc=3;
	text="\cTab\img\icon_signalStrength_ca.paa";
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (5 - 1)) + (((1098) - (20) * 6) / 5) - (42) * 2) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_android_on_screen_satellite: cTab_android_on_screen_battery
{
	idc=4;
	text="\a3\ui_f\data\map\Diary\signal_ca.paa";
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (5 - 1)) + (((1098) - (20) * 6) / 5) - (42)) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_android_on_screen_dirDegree: cTab_android_on_screen_time
{
	idc=2615;
	style=0;
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (2 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
};
class cTab_android_on_screen_grid: cTab_android_on_screen_dirDegree
{
	idc=2612;
	style=1;
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (4 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
};
class cTab_android_on_screen_dirOctant: cTab_android_on_screen_dirDegree
{
	idc=2616;
	style=1;
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
};
class cTab_android_on_screen_hookGrid: cTab_RscText_Android
{
	idc=2617;
	style=2;
	x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 4) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	colorText[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.25};
};
class cTab_android_on_screen_hookElevation: cTab_android_on_screen_hookGrid
{
	idc=2620;
	y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 3) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_on_screen_hookDst: cTab_android_on_screen_hookGrid
{
	idc=2619;
	y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 2) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_on_screen_hookDir: cTab_android_on_screen_hookGrid
{
	idc=2618;
	y="((-(0) + (713) + (626)) - (20) - ((60) - (20))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
};
class cTab_android_loadingtxt: cTab_RscText_Android
{
	idc=1000;
	style=2;
	text="Loading";
	x="(((452))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(((1098))) / 2048  *  (safezoneW * 0.8)";
	h="(((626) - (60) - (0))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	colorBackground[]={0.2,0.43099999,0.64700001,1};
};
class cTab_android_windowsBG: cTab_RscPicture
{
	idc=1210;
	text="#(argb,8,8,3)color(0.2,0.431,0.647,1)";
	x="((452)) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((713)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="((1098)) / 2048  *  (safezoneW * 0.8)";
	h="((626)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_movingHandle_T: cTab_RscText_Android
{
	idc=5;
	moving=1;
	colorBackground[]={0,0,0,0};
	x="(0) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(0) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(2048 ) / 2048  *  (safezoneW * 0.8)";
	h="((713)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_movingHandle_B: cTab_android_movingHandle_T
{
	idc=6;
	y="((713) + (626)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	h="(2048  - ((713) + (626))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_movingHandle_L: cTab_android_movingHandle_T
{
	idc=7;
	y="((713)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="((452)) / 2048  *  (safezoneW * 0.8)";
	h="((626)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
};
class cTab_android_movingHandle_R: cTab_android_movingHandle_L
{
	idc=8;
	x="((452) + (1098)) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	w="(2048  - ((452) + (1098))) / 2048  *  (safezoneW * 0.8)";
};
class cTab_android_brightness: cTab_RscText_Android
{
	idc=1005;
	x="((452)) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="((713)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="((1098)) / 2048  *  (safezoneW * 0.8)";
	h="((626)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
	colorBackground[]={0,0,0,0};
};
class cTab_android_notification: cTab_RscText_Android
{
	idc=1620;
	x="(((452)) + (((1098)) * 0.2) / 2) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
	y="(((713) + (60)) + ((626) - (60) - (0)) - 2 * (38)) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
	w="(((1098)) * 0.8) / 2048  *  (safezoneW * 0.8)";
	colorBackground[]={0,0,0,1};
};
class cTab_Android_dlg
{
	idd=177382;
	movingEnable="true";
	onLoad="_this call cTab_fnc_onIfOpen;";
	onUnload="[] call cTab_fnc_onIfclose;";
	onKeyDown="_this call cTab_fnc_onIfKeyDown;";
	objects[]={};
	class controlsBackground
	{
		class windowsBG: cTab_android_windowsBG
		{
		};
		class screen: cTab_android_RscMapControl
		{
			onDraw="nop = _this call cTabOnDrawbftAndroid;";
			onMouseButtonDblClick="_ok = [3300,_this] execVM '\cTab\shared\cTab_markerMenu_load.sqf';";
			onMouseMoving="cTabCursorOnMap = _this select 3;cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
		};
		class screenTopo: screen
		{
			idc=1202;
			maxSatelliteAlpha=0;
		};
	};
	class controls
	{
		class header: cTab_android_header
		{
		};
		class battery: cTab_android_on_screen_battery
		{
		};
		class time: cTab_android_on_screen_time
		{
		};
		class signalStrength: cTab_android_on_screen_signalStrength
		{
		};
		class satellite: cTab_android_on_screen_satellite
		{
		};
		class dirDegree: cTab_android_on_screen_dirDegree
		{
		};
		class grid: cTab_android_on_screen_grid
		{
		};
		class dirOctant: cTab_android_on_screen_dirOctant
		{
		};
		class hookGrid: cTab_android_on_screen_hookGrid
		{
		};
		class hookElevation: cTab_android_on_screen_hookElevation
		{
		};
		class hookDst: cTab_android_on_screen_hookDst
		{
		};
		class hookDir: cTab_android_on_screen_hookDir
		{
		};
		class menuContainer: cTab_RscControlsGroup
		{
			idc=4660;
			x="((((452)) + ((1098)) - (((1098)) / 4))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
			y="((((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
			w="((((1098)) / 4)) / 2048  *  (safezoneW * 0.8)";
			h="((((626) - (60) - (0)))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class menuBackground: cTab_IGUIBack
				{
					idc=9;
					x=0;
					y=0;
					w="((((1098)) / 4)) / 2048  *  (safezoneW * 0.8)";
					h="((((626) - (60) - (0)))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
				};
				class btnTextonoff: cTab_RscButton
				{
					idc=10;
					text="Text On/Off";
					sizeEx="((38)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					x="(((((((452)) + ((1098)) - (((1098)) / 4)) + ((((1098)) / 4) * 0.05))) - (((452)) + ((1098)) - (((1098)) / 4))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (1 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="(((((1098)) / 4) - (((((1098)) / 4) * 0.05) * 2))) / 2048  *  (safezoneW * 0.8)";
					h="((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					tooltip="Toggle Text on/off";
					action="['cTab_Android_dlg'] call cTab_fnc_iconText_toggle;";
				};
				class btnIcnSizeup: btnTextonoff
				{
					idc=11;
					text="Icon Size +";
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (2 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					tooltip="Increase Icon/Text Size";
					action="call cTab_fnc_txt_size_inc;";
				};
				class btnIconSizedwn: btnTextonoff
				{
					idc=12;
					text="Icon Size -";
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (3 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					tooltip="Decrease Icon/Text Size";
					action="call cTab_fnc_txt_size_dec;";
				};
				class btnF5: btnTextonoff
				{
					idc=13;
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (7 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					text="Map Tools";
					tooltip="Toggle Map Tools (F5)";
					action="['cTab_Android_dlg'] call cTab_fnc_toggleMapTools;";
				};
				class btnF6: btnTextonoff
				{
					idc=14;
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (5 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					text="Map Textures";
					tooltip="Toggle Map Textures (F6)";
					action="['cTab_Android_dlg'] call cTab_fnc_mapType_toggle;";
				};
				class btnF7: btnTextonoff
				{
					idc=15;
					y="(((((((713) + (60))) + ((((626) - (60) - (0))) * 0.05) + ((((((626) - (60) - (0))) - ((((626) - (60) - (0))) * 0.05) * 8) / 7) + ((((626) - (60) - (0))) * 0.05)) * (6 - 1))) - (((713) + (60)))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					text="Center Map";
					action="['cTab_Android_dlg'] call cTab_fnc_centerMapOnPlayerPosition;";
					tooltip="Center Map On Current Position (F7)";
				};
			};
		};
		class MESSAGE: cTab_RscControlsGroup
		{
			idc=4650;
			x="(((452))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
			y="(((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
			w="(((1098))) / 2048  *  (safezoneW * 0.8)";
			h="(((626) - (60) - (0))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class msgListbox: cTab_RscListBox
				{
					idc=15000;
					style=32;
					sizeEx="((38) * 0.8) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					x="((((((452) + (20)) + (10))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="((((((713) + (60) + (10)) + (20))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="(((((1098) - (20) * 2) - (10) * 3) / 3)) / 2048  *  (safezoneW * 0.8)";
					h="((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					onLBSelChanged="_this call cTab_msg_get_mailTxt;";
				};
				class msgframe: cTab_RscFrame
				{
					idc=16;
					text="Read Message";
					x="(((((452) + (20))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((713) + (60) + (10))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="(((1098) - (20) * 2)) / 2048  *  (safezoneW * 0.8)";
					h="(((626) - (60) - (10) * 2)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
				};
				class msgTxt: cTab_RscEdit
				{
					idc=18510;
					htmlControl="true";
					style=16;
					lineSpacing=0.2;
					text="No Message Selected";
					sizeEx="((38)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					x="(((((((452) + (20)) + (10)) + ((((1098) - (20) * 2) - (10) * 3) / 3) + (10))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((713) + (60) + (10)) + (20)))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3) * 2)) / 2048  *  (safezoneW * 0.8)";
					h="((((626) - (60) - (10) * 2) - (20) -(10))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					canModify=0;
				};
				class deletebtn: cTab_RscButton
				{
					idc=16120;
					text="Delete";
					tooltip="Delete Selected Message(s)";
					x="((((((((452) + (20))) + (10)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((((713) + (60) + (10))) + (20)) + ((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2)) + (10)))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3))) / 2048  *  (safezoneW * 0.8)";
					h="((60)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="['cTab_Android_dlg'] call cTab_fnc_onMsgBtnDelete;";
				};
				class toCompose: cTab_RscButton
				{
					idc=17;
					text="Compose >>";
					tooltip="Compose Messages";
					x="((((((((452) + (20))) + (10)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((((713) + (60) + (10))) + (20)) + ((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2)) + (10)) + (10) + (60))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3))) / 2048  *  (safezoneW * 0.8)";
					h="((60)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="['cTab_Android_dlg',[['mode','COMPOSE']]] call cTab_fnc_setSettings;";
				};
			};
		};
		class COMPOSE: cTab_RscControlsGroup
		{
			idc=4655;
			x="(((452))) / 2048  *  (safezoneW * 0.8) +  (safezoneX + (safezoneW -  (safezoneW * 0.8)) / 2)";
			y="(((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW * 0.8) * 4/3)) / 2)";
			w="(((1098))) / 2048  *  (safezoneW * 0.8)";
			h="(((626) - (60) - (0))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
			class VScrollbar
			{
			};
			class HScrollbar
			{
			};
			class Scrollbar
			{
			};
			class controls
			{
				class composeFrame: cTab_RscFrame
				{
					idc=18;
					text="Compose Message";
					x="((((((452) + (20)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="((((((713) + (60) + (10)))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((1098) - (20) * 2))) / 2048  *  (safezoneW * 0.8)";
					h="((((626) - (60) - (10) * 2))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
				};
				class playerlistbox: cTab_RscListBox
				{
					idc=15010;
					style=32;
					sizeEx="((38) * 0.8) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					x="(((((((452) + (20)) + (10)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((713) + (60) + (10))) + (20))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3))) / 2048  *  (safezoneW * 0.8)";
					h="(((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
				};
				class sendbtn: cTab_RscButton
				{
					idc=16130;
					text="Send";
					x="(((((((452) + (20))) + (10))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="((((((((713) + (60) + (10))) + (20)) + ((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2)) + (10))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3))) / 2048  *  (safezoneW * 0.8)";
					h="((60)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="call cTab_msg_Send;";
				};
				class edittxtbox: cTab_RscEdit
				{
					idc=14000;
					htmlControl="true";
					style=16;
					lineSpacing=0.2;
					text="";
					sizeEx="((38)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					x="((((((((452) + (20)) + (10)) + ((((1098) - (20) * 2) - (10) * 3) / 3) + (10)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="((((((((713) + (60) + (10))) + (20)))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="(((((((1098) - (20) * 2) - (10) * 3) / 3) * 2))) / 2048  *  (safezoneW * 0.8)";
					h="(((((626) - (60) - (10) * 2) - (20) -(10)))) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
				};
				class toRead: cTab_RscButton
				{
					idc=19;
					text="Read >>";
					tooltip="Read Messages";
					x="((((((((452) + (20))) + (10)))) - ((452))) / 2048  *  (safezoneW * 0.8))";
					y="(((((((((713) + (60) + (10))) + (20)) + ((((626) - (60) - (10) * 2) - (10) * 3 - (20) - (60) * 2)) + (10)) + (10) + (60))) - ((713) + (60))) / 2048  *  ( (safezoneW * 0.8) * 4/3))";
					w="((((((1098) - (20) * 2) - (10) * 3) / 3))) / 2048  *  (safezoneW * 0.8)";
					h="((60)) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="['cTab_Android_dlg',[['mode','MESSAGE']]] call cTab_fnc_setSettings;";
				};
			};
		};
		class notification: cTab_android_notification
		{
		};
		class loadingtxt: cTab_android_loadingtxt
		{
		};
		class brightness: cTab_android_brightness
		{
		};
		class MainSubmenu: cTab_RscControlsGroup
		{
			idc=3300;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(4 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class mainbg: cTab_IGUIBack
				{
					idc=2200;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(4 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class op4btn: cTab_MenuItem
				{
					idc=2000;
					text="Enemy SALUTE";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[11] call cTab_fnc_userMenuSelect;";
				};
				class medbtn: cTab_MenuItem
				{
					idc=2001;
					text="Medical";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[21] call cTab_fnc_userMenuSelect;";
				};
				class genbtn: cTab_MenuItem
				{
					idc=2002;
					text="General";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[31] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub1: cTab_RscControlsGroup
		{
			idc=3301;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(8 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2201: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(8 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class infbtn: cTab_MenuItem
				{
					idc=2003;
					text="Infantry";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,0];[12] call cTab_fnc_userMenuSelect;";
				};
				class mecinfbtn: cTab_MenuItem
				{
					idc=2004;
					text="Mechanized Inf";
					toolTip="Equipped with APCs/IFVs";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,1];[12] call cTab_fnc_userMenuSelect;";
				};
				class motrinfbtn: cTab_MenuItem
				{
					idc=2032;
					text="Motorized Inf";
					toolTip="Equipped with un-protected vehicles";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,2];[12] call cTab_fnc_userMenuSelect;";
				};
				class amrbtn: cTab_MenuItem
				{
					idc=2005;
					text="Armor";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,3];[12] call cTab_fnc_userMenuSelect;";
				};
				class helibtn: cTab_MenuItem
				{
					idc=2006;
					text="Helicopter";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,4];[12] call cTab_fnc_userMenuSelect;";
				};
				class plnbtn: cTab_MenuItem
				{
					idc=2007;
					text="Plane";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,5];[12] call cTab_fnc_userMenuSelect;";
				};
				class uknbtn: cTab_MenuItem
				{
					idc=2008;
					text="Unknown";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,6];[12] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub2: cTab_RscControlsGroup
		{
			idc=3303;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(6 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(6 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class ftbtn: cTab_MenuItem
				{
					idc=2009;
					text="Singular";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[14] call cTab_fnc_userMenuSelect;";
				};
				class patbtn: cTab_MenuItem
				{
					idc=2010;
					text="Patrol";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [2,1];[13] call cTab_fnc_userMenuSelect;";
				};
				class sqdbtn: cTab_MenuItem
				{
					idc=2011;
					text="Squad";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [2,2];[13] call cTab_fnc_userMenuSelect;";
				};
				class sctbtn: cTab_MenuItem
				{
					idc=2012;
					text="Section";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [2,3];[13] call cTab_fnc_userMenuSelect;";
				};
				class pltnbtn: cTab_MenuItem
				{
					idc=2013;
					text="Platoon";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [2,4];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub3: cTab_RscControlsGroup
		{
			idc=3304;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(10 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2203: cTab_IGUIBack
				{
					idc=2203;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(10 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class stnbtn: cTab_MenuItem
				{
					idc=2029;
					text="Stationary";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[1] call cTab_fnc_userMenuSelect;";
				};
				class nthbtn: cTab_MenuItem
				{
					idc=2015;
					text="N";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,1];[1] call cTab_fnc_userMenuSelect;";
				};
				class nebtn: cTab_MenuItem
				{
					idc=2016;
					text="NE";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,2];[1] call cTab_fnc_userMenuSelect;";
				};
				class ebtn: cTab_MenuItem
				{
					idc=2017;
					text="E";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,3];[1] call cTab_fnc_userMenuSelect;";
				};
				class sebtn: cTab_MenuItem
				{
					idc=2018;
					text="SE";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,4];[1] call cTab_fnc_userMenuSelect;";
				};
				class sbtn: cTab_MenuItem
				{
					idc=2019;
					text="S";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,5];[1] call cTab_fnc_userMenuSelect;";
				};
				class swbtn: cTab_MenuItem
				{
					idc=2020;
					text="SW";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,6];[1] call cTab_fnc_userMenuSelect;";
				};
				class wbtn: cTab_MenuItem
				{
					idc=2021;
					text="W";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,7];[1] call cTab_fnc_userMenuSelect;";
				};
				class RscText_1022: cTab_MenuItem
				{
					idc=2022;
					text="NW";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (9 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [3,8];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (10 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub4: cTab_RscControlsGroup
		{
			idc=3307;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(8 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(8 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class rifle_btn: cTab_MenuItem
				{
					idc=-1;
					text="Rifle";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,7];[13] call cTab_fnc_userMenuSelect;";
				};
				class lmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="MG";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,8];[13] call cTab_fnc_userMenuSelect;";
				};
				class at_btn: cTab_MenuItem
				{
					idc=-1;
					text="AT";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,9];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static MG";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,10];[13] call cTab_fnc_userMenuSelect;";
				};
				class mat_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AT";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,11];[13] call cTab_fnc_userMenuSelect;";
				};
				class aa_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AA";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,13];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmortar_btn: cTab_MenuItem
				{
					idc=-1;
					text="Mortar";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,12];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class CasulSub1: cTab_RscControlsGroup
		{
			idc=3305;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(5 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2204: cTab_IGUIBack
				{
					idc=2204;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(5 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class casltybtn: cTab_MenuItem
				{
					idc=2024;
					text="Casualty";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,20];[1] call cTab_fnc_userMenuSelect;";
				};
				class ccpbtn: cTab_MenuItem
				{
					idc=2025;
					text="CCP";
					toolTip="Casualty Collection Point";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,21];[1] call cTab_fnc_userMenuSelect;";
				};
				class basbtn: cTab_MenuItem
				{
					idc=2026;
					text="BAS";
					toolTip="Battalion Aid Station";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,22];[1] call cTab_fnc_userMenuSelect;";
				};
				class mcibtn: cTab_MenuItem
				{
					idc=2031;
					text="MCI";
					toolTip="Mass Casualty Incident";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,23];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class GenSub1: cTab_RscControlsGroup
		{
			idc=3306;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
			h="(3 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2205: cTab_IGUIBack
				{
					idc=2205;
					x=0;
					y=0;
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(3 + 0.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
				};
				class hqbtn: cTab_MenuItem
				{
					idc=2027;
					text="HQ";
					toolTip="Headquaters";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,30];[1] call cTab_fnc_userMenuSelect;";
				};
				class lzbtn: cTab_MenuItem
				{
					idc=2028;
					text="LZ";
					toolTip="Landing Zone";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="cTabUserSelIcon set [1,31];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (27) / 2048  *  ( (safezoneW * 0.8) * 4/3) * 3/4 * 0.5";
					h="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3) / 0.8";
					sizeEx="(27) / 2048  *  ( (safezoneW * 0.8) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class background: cTab_android_background
		{
		};
		class movingHandle_T: cTab_android_movingHandle_T
		{
		};
		class movingHandle_B: cTab_android_movingHandle_B
		{
		};
		class movingHandle_L: cTab_android_movingHandle_L
		{
		};
		class movingHandle_R: cTab_android_movingHandle_R
		{
		};
		class btnMenu: cTab_android_btnMenu
		{
			idc=1607;
			action="['cTab_Android_dlg'] call cTab_fnc_showMenu_toggle;";
			tooltip="Map Options";
		};
		class btnPower: cTab_android_btnPower
		{
			idc=1608;
			action="closeDialog 0;";
			tooltip="Close Interface";
		};
		class btnHome: cTab_android_btnHome
		{
			idc=1600;
			action="['cTab_Android_dlg'] call cTab_fnc_mode_toggle;";
			tooltip="Toggle Map (F1) / Messages (F4)";
		};
	};
};
class cTab_RscText_FBCB2: cTab_RscText
{
	style=2;
	w="(((((810)) - (15) * 6) / 5)) / 2048  *  (safezoneW)";
	h="(((44) - (15))) / 2048  *  ( (safezoneW) * 4/3)";
	font="EtelkaMonospacePro";
	colorText[]={1,1,1,1};
	sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
	colorBackground[]={0,0,0,0};
	shadow=0;
};
class cTab_FBCB2_background: cTab_RscPicture
{
	idc=1200;
	text="\cTab\img\FBCB2.paa";
	x="(safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="(safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="(safezoneW)";
	h="( (safezoneW) * 4/3)";
};
class cTab_FBCB2_header: cTab_RscPicture
{
	idc=1;
	text="#(argb,8,8,3)color(0,0,0,1)";
	x="((685)) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="((608)) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="((810)) / 2048  *  (safezoneW)";
	h="((44)) / 2048  *  ( (safezoneW) * 4/3)";
};
class cTab_FBCB2_on_screen_battery: cTab_RscPicture
{
	idc=2;
	text="\cTab\img\icon_battery_ca.paa";
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (1 - 1))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="((608) + ((44) - (28.5)) / 2) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="((28.5)) / 2048  *  (safezoneW)";
	h="((28.5)) / 2048  *  ( (safezoneW) * 4/3)";
	colorText[]={1,1,1,1};
};
class cTab_FBCB2_on_screen_time: cTab_RscText_FBCB2
{
	idc=2613;
	style=2;
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (3 - 1))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="((608) + ((44) - (24)) / 2) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_on_screen_signalStrength: cTab_FBCB2_on_screen_battery
{
	idc=3;
	text="\cTab\img\icon_signalStrength_ca.paa";
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (5 - 1)) + ((((810)) - (15) * 6) / 5) - (28.5) * 2) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_FBCB2_on_screen_satellite: cTab_FBCB2_on_screen_battery
{
	idc=4;
	text="\a3\ui_f\data\map\Diary\signal_ca.paa";
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (5 - 1)) + ((((810)) - (15) * 6) / 5) - (28.5)) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_FBCB2_on_screen_dirDegree: cTab_FBCB2_on_screen_time
{
	idc=2615;
	style=0;
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (2 - 1))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_on_screen_grid: cTab_FBCB2_on_screen_dirDegree
{
	idc=2612;
	style=1;
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (4 - 1))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_on_screen_dirOctant: cTab_FBCB2_on_screen_dirDegree
{
	idc=2616;
	style=1;
	x="((((15) + ((685))) + ((15) + ((((810)) - (15) * 6) / 5)) * (1 - 1))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF1: cTab_RscButtonInv
{
	x="(762) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="(1452) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="(70) / 2048  *  (safezoneW)";
	h="(40) / 2048  *  ( (safezoneW) * 4/3)";
};
class cTab_FBCB2_btnF2: cTab_FBCB2_btnF1
{
	x="(846) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF3: cTab_FBCB2_btnF1
{
	x="(929) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF4: cTab_FBCB2_btnF1
{
	x="(1013) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF5: cTab_FBCB2_btnF1
{
	x="(1097) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF6: cTab_FBCB2_btnF1
{
	x="(1180) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF7: cTab_FBCB2_btnF1
{
	x="(1264) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnF8: cTab_FBCB2_btnF1
{
	x="(1349) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
};
class cTab_FBCB2_btnPWR: cTab_RscButtonInv
{
	x="(592) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="(603) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="(40) / 2048  *  (safezoneW)";
	h="(70) / 2048  *  ( (safezoneW) * 4/3)";
};
class cTab_FBCB2_btnBRTplus: cTab_FBCB2_btnPWR
{
	y="(680) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnBRTminus: cTab_FBCB2_btnPWR
{
	y="(759) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnBLKOUT: cTab_FBCB2_btnPWR
{
	y="(839) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnESC: cTab_FBCB2_btnPWR
{
	y="(918) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnRight: cTab_FBCB2_btnPWR
{
	y="(998) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnUp: cTab_FBCB2_btnPWR
{
	y="(1079) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnDown: cTab_FBCB2_btnPWR
{
	y="(1161) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnENT: cTab_FBCB2_btnPWR
{
	y="(1241) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_btnFCN: cTab_FBCB2_btnPWR
{
	y="(1322) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_on_screen_hookGrid: cTab_RscText_FBCB2
{
	idc=2617;
	style=2;
	x="(((-(15) + ((685)) + ((810))) - ((((810)) - (15) * 6) / 5))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="((-(0) + (608) + (810)) - (15) - ((44) - (15)) * 4) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	colorText[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.25};
};
class cTab_FBCB2_on_screen_hookElevation: cTab_FBCB2_on_screen_hookGrid
{
	idc=2620;
	y="((-(0) + (608) + (810)) - (15) - ((44) - (15)) * 3) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_on_screen_hookDst: cTab_FBCB2_on_screen_hookGrid
{
	idc=2619;
	y="((-(0) + (608) + (810)) - (15) - ((44) - (15)) * 2) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_on_screen_hookDir: cTab_FBCB2_on_screen_hookGrid
{
	idc=2618;
	y="((-(0) + (608) + (810)) - (15) - ((44) - (15))) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
};
class cTab_FBCB2_loadingtxt: cTab_RscText_FBCB2
{
	idc=1000;
	style=2;
	text="Loading";
	x="(((685))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="(((608) + (44))) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="(((810))) / 2048  *  (safezoneW)";
	h="(((810) - (44) - (0))) / 2048  *  ( (safezoneW) * 4/3)";
	colorBackground[]={0,0,0,1};
};
class cTab_FBCB2_notification: cTab_RscText_FBCB2
{
	idc=1620;
	x="(((685)) + (((810)) * 0.2) / 2) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
	y="(((608) + (44)) + ((810) - (44) - (0)) - 2 * (24)) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
	w="(((810)) * 0.8) / 2048  *  (safezoneW)";
	colorBackground[]={0,0,0,1};
};
class cTab_FBCB2_dlg
{
	idd=1775144;
	movingEnable="true";
	onLoad="_this call cTab_fnc_onIfOpen;";
	onUnload="[] call cTab_fnc_onIfclose;";
	onKeyDown="_this call cTab_fnc_onIfKeyDown;";
	objects[]={};
	class controlsBackground
	{
		class background: cTab_FBCB2_background
		{
			moving=1;
		};
		class screen: cTab_RscMapControl
		{
			idc=1201;
			text="#(argb,8,8,3)color(1,1,1,1)";
			x="(((685))) / 2048  *  (safezoneW) +  (safezoneX + (safezoneW -  (safezoneW)) / 2)";
			y="(((608) + (44))) / 2048  *  ( (safezoneW) * 4/3) +  (safezoneY + (safezoneH -  ( (safezoneW) * 4/3)) / 2)";
			w="(((810))) / 2048  *  (safezoneW)";
			h="(((810) - (44) - (0))) / 2048  *  ( (safezoneW) * 4/3)";
			onDraw="nop = _this call cTabOnDrawbftVeh;";
			onMouseButtonDblClick="_ok = [3300,_this] execVM '\cTab\shared\cTab_markerMenu_load.sqf';";
			onMouseMoving="cTabCursorOnMap = _this select 3;cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
			maxSatelliteAlpha=10000;
			alphaFadeStartScale=10;
			alphaFadeEndScale=10;
			ptsPerSquareSea="8 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareTxt="8 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareCLn="8 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareExp="8 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareCost="8 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareFor="3 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareForEdge="100 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareRoad="1.5 / (0.86 /  ( (safezoneW) * 4/3))";
			ptsPerSquareObj="4 / (0.86 /  ( (safezoneW) * 4/3))";
			widthRailWay=1;
		};
		class screenTopo: screen
		{
			idc=1202;
			maxSatelliteAlpha=0;
		};
	};
	class controls
	{
		class header: cTab_FBCB2_header
		{
		};
		class battery: cTab_FBCB2_on_screen_battery
		{
		};
		class time: cTab_FBCB2_on_screen_time
		{
		};
		class signalStrength: cTab_FBCB2_on_screen_signalStrength
		{
		};
		class satellite: cTab_FBCB2_on_screen_satellite
		{
		};
		class dirDegree: cTab_FBCB2_on_screen_dirDegree
		{
		};
		class grid: cTab_FBCB2_on_screen_grid
		{
		};
		class dirOctant: cTab_FBCB2_on_screen_dirOctant
		{
		};
		class pwrbtn: cTab_FBCB2_btnPWR
		{
			idc=1608;
			action="closeDialog 0;";
			tooltip="Close Interface";
		};
		class btnbrtpls: cTab_FBCB2_btnBRTplus
		{
			idc=1609;
			action="call cTab_fnc_txt_size_inc;";
			tooltip="Increase Font";
		};
		class btnbrtmns: cTab_FBCB2_btnBRTminus
		{
			idc=1610;
			action="call cTab_fnc_txt_size_dec;";
			tooltip="Decrease Font";
		};
		class btnfunction: cTab_FBCB2_btnFCN
		{
			idc=1607;
			action="['cTab_FBCB2_dlg'] call cTab_fnc_iconText_toggle;";
			tooltip="Toggle Text on/off";
		};
		class btnF5: cTab_FBCB2_btnF5
		{
			idc=1604;
			tooltip="Toggle Map Tools (F5)";
			action="['cTab_FBCB2_dlg'] call cTab_fnc_toggleMapTools;";
		};
		class btnF6: cTab_FBCB2_btnF6
		{
			idc=1605;
			tooltip="Toggle Map Textures";
			action="['cTab_FBCB2_dlg'] call cTab_fnc_mapType_toggle;";
		};
		class btnF7: cTab_FBCB2_btnF7
		{
			idc=5;
			action="['cTab_FBCB2_dlg'] call cTab_fnc_centerMapOnPlayerPosition;";
			tooltip="Center Map On Current Position (F7)";
		};
		class hookGrid: cTab_FBCB2_on_screen_hookGrid
		{
		};
		class hookElevation: cTab_FBCB2_on_screen_hookElevation
		{
		};
		class hookDst: cTab_FBCB2_on_screen_hookDst
		{
		};
		class hookDir: cTab_FBCB2_on_screen_hookDir
		{
		};
		class MainSubmenu: cTab_RscControlsGroup
		{
			idc=3300;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(4 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class mainbg: cTab_IGUIBack
				{
					idc=2200;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(4 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class op4btn: cTab_MenuItem
				{
					idc=2000;
					text="Enemy SALUTE";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[11] call cTab_fnc_userMenuSelect;";
				};
				class medbtn: cTab_MenuItem
				{
					idc=2001;
					text="Medical";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[21] call cTab_fnc_userMenuSelect;";
				};
				class genbtn: cTab_MenuItem
				{
					idc=2002;
					text="General";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[31] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub1: cTab_RscControlsGroup
		{
			idc=3301;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(8 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2201: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(8 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class infbtn: cTab_MenuItem
				{
					idc=2003;
					text="Infantry";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,0];[12] call cTab_fnc_userMenuSelect;";
				};
				class mecinfbtn: cTab_MenuItem
				{
					idc=2004;
					text="Mechanized Inf";
					toolTip="Equipped with APCs/IFVs";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,1];[12] call cTab_fnc_userMenuSelect;";
				};
				class motrinfbtn: cTab_MenuItem
				{
					idc=2032;
					text="Motorized Inf";
					toolTip="Equipped with un-protected vehicles";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,2];[12] call cTab_fnc_userMenuSelect;";
				};
				class amrbtn: cTab_MenuItem
				{
					idc=2005;
					text="Armor";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,3];[12] call cTab_fnc_userMenuSelect;";
				};
				class helibtn: cTab_MenuItem
				{
					idc=2006;
					text="Helicopter";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,4];[12] call cTab_fnc_userMenuSelect;";
				};
				class plnbtn: cTab_MenuItem
				{
					idc=2007;
					text="Plane";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,5];[12] call cTab_fnc_userMenuSelect;";
				};
				class uknbtn: cTab_MenuItem
				{
					idc=2008;
					text="Unknown";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,6];[12] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub2: cTab_RscControlsGroup
		{
			idc=3303;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(6 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(6 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class ftbtn: cTab_MenuItem
				{
					idc=2009;
					text="Singular";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[14] call cTab_fnc_userMenuSelect;";
				};
				class patbtn: cTab_MenuItem
				{
					idc=2010;
					text="Patrol";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [2,1];[13] call cTab_fnc_userMenuSelect;";
				};
				class sqdbtn: cTab_MenuItem
				{
					idc=2011;
					text="Squad";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [2,2];[13] call cTab_fnc_userMenuSelect;";
				};
				class sctbtn: cTab_MenuItem
				{
					idc=2012;
					text="Section";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [2,3];[13] call cTab_fnc_userMenuSelect;";
				};
				class pltnbtn: cTab_MenuItem
				{
					idc=2013;
					text="Platoon";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [2,4];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub3: cTab_RscControlsGroup
		{
			idc=3304;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(10 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2203: cTab_IGUIBack
				{
					idc=2203;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(10 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class stnbtn: cTab_MenuItem
				{
					idc=2029;
					text="Stationary";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[1] call cTab_fnc_userMenuSelect;";
				};
				class nthbtn: cTab_MenuItem
				{
					idc=2015;
					text="N";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,1];[1] call cTab_fnc_userMenuSelect;";
				};
				class nebtn: cTab_MenuItem
				{
					idc=2016;
					text="NE";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,2];[1] call cTab_fnc_userMenuSelect;";
				};
				class ebtn: cTab_MenuItem
				{
					idc=2017;
					text="E";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,3];[1] call cTab_fnc_userMenuSelect;";
				};
				class sebtn: cTab_MenuItem
				{
					idc=2018;
					text="SE";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,4];[1] call cTab_fnc_userMenuSelect;";
				};
				class sbtn: cTab_MenuItem
				{
					idc=2019;
					text="S";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,5];[1] call cTab_fnc_userMenuSelect;";
				};
				class swbtn: cTab_MenuItem
				{
					idc=2020;
					text="SW";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,6];[1] call cTab_fnc_userMenuSelect;";
				};
				class wbtn: cTab_MenuItem
				{
					idc=2021;
					text="W";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,7];[1] call cTab_fnc_userMenuSelect;";
				};
				class RscText_1022: cTab_MenuItem
				{
					idc=2022;
					text="NW";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (9 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [3,8];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (10 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub4: cTab_RscControlsGroup
		{
			idc=3307;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(8 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(8 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class rifle_btn: cTab_MenuItem
				{
					idc=-1;
					text="Rifle";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,7];[13] call cTab_fnc_userMenuSelect;";
				};
				class lmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="MG";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,8];[13] call cTab_fnc_userMenuSelect;";
				};
				class at_btn: cTab_MenuItem
				{
					idc=-1;
					text="AT";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,9];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static MG";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,10];[13] call cTab_fnc_userMenuSelect;";
				};
				class mat_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AT";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,11];[13] call cTab_fnc_userMenuSelect;";
				};
				class aa_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AA";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,13];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmortar_btn: cTab_MenuItem
				{
					idc=-1;
					text="Mortar";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,12];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class CasulSub1: cTab_RscControlsGroup
		{
			idc=3305;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(5 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2204: cTab_IGUIBack
				{
					idc=2204;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(5 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class casltybtn: cTab_MenuItem
				{
					idc=2024;
					text="Casualty";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,20];[1] call cTab_fnc_userMenuSelect;";
				};
				class ccpbtn: cTab_MenuItem
				{
					idc=2025;
					text="CCP";
					toolTip="Casualty Collection Point";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,21];[1] call cTab_fnc_userMenuSelect;";
				};
				class basbtn: cTab_MenuItem
				{
					idc=2026;
					text="BAS";
					toolTip="Battalion Aid Station";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,22];[1] call cTab_fnc_userMenuSelect;";
				};
				class mcibtn: cTab_MenuItem
				{
					idc=2031;
					text="MCI";
					toolTip="Mass Casualty Incident";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,23];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class GenSub1: cTab_RscControlsGroup
		{
			idc=3306;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
			h="(3 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
			class controls
			{
				class IGUIBack_2205: cTab_IGUIBack
				{
					idc=2205;
					x=0;
					y=0;
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="(3 + 0.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
				};
				class hqbtn: cTab_MenuItem
				{
					idc=2027;
					text="HQ";
					toolTip="Headquaters";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,30];[1] call cTab_fnc_userMenuSelect;";
				};
				class lzbtn: cTab_MenuItem
				{
					idc=2028;
					text="LZ";
					toolTip="Landing Zone";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="cTabUserSelIcon set [1,31];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * ((24)) / 2048  *  ( (safezoneW) * 4/3) * 3/4 * 0.5";
					h="((24)) / 2048  *  ( (safezoneW) * 4/3) / 0.8";
					sizeEx="((24)) / 2048  *  ( (safezoneW) * 4/3)";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class notification: cTab_FBCB2_notification
		{
		};
		class loadingtxt: cTab_FBCB2_loadingtxt
		{
		};
	};
};
class cTab_RscButton_TAD_OSB: cTab_RscButtonInv
{
	w="((134) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="((134) / 2048  *  (safezoneH * 0.8))";
};
class cTab_RscButton_TAD_OSB01: cTab_RscButton_TAD_OSB
{
	x="((577) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((146) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB02: cTab_RscButton_TAD_OSB01
{
	x="((767) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB03: cTab_RscButton_TAD_OSB01
{
	x="((957) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB04: cTab_RscButton_TAD_OSB01
{
	x="((1147) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB05: cTab_RscButton_TAD_OSB01
{
	x="((1337) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB06: cTab_RscButton_TAD_OSB
{
	x="((1782) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((563) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB07: cTab_RscButton_TAD_OSB06
{
	y="((760) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB08: cTab_RscButton_TAD_OSB06
{
	y="((957) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB09: cTab_RscButton_TAD_OSB06
{
	y="((1155) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB10: cTab_RscButton_TAD_OSB06
{
	y="((1352) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB11: cTab_RscButton_TAD_OSB
{
	x="((1337) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((1811) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB12: cTab_RscButton_TAD_OSB11
{
	x="((1147) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB13: cTab_RscButton_TAD_OSB11
{
	x="((957) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB14: cTab_RscButton_TAD_OSB11
{
	x="((767) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB15: cTab_RscButton_TAD_OSB11
{
	x="((577) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_OSB16: cTab_RscButton_TAD_OSB
{
	x="((132) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((1352) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB17: cTab_RscButton_TAD_OSB16
{
	y="((1155) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB18: cTab_RscButton_TAD_OSB16
{
	y="((957) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB19: cTab_RscButton_TAD_OSB16
{
	y="((760) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_OSB20: cTab_RscButton_TAD_OSB16
{
	y="((563) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_ADJ_INC: cTab_RscButtonInv
{
	x="((124) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((257) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="((142) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="((119) / 2048  *  (safezoneH * 0.8))";
};
class cTab_RscButton_TAD_ADJ_DEC: cTab_RscButton_TAD_ADJ_INC
{
	y="((376) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_DSP_INC: cTab_RscButton_TAD_ADJ_INC
{
	x="((1782) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_DSP_DEC: cTab_RscButton_TAD_DSP_INC
{
	y="((376) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_CON_INC: cTab_RscButton_TAD_ADJ_INC
{
	y="((1539) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_CON_DEC: cTab_RscButton_TAD_CON_INC
{
	y="((1658) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_BRT_INC: cTab_RscButton_TAD_CON_INC
{
	x="((1782) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_BRT_DEC: cTab_RscButton_TAD_BRT_INC
{
	y="((1658) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_RscButton_TAD_SYM_INC: cTab_RscButtonInv
{
	x="((1663) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((1811) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="((119) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="((142) / 2048  *  (safezoneH * 0.8))";
};
class cTab_RscButton_TAD_SYM_DEC: cTab_RscButton_TAD_SYM_INC
{
	x="((1544) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
};
class cTab_RscButton_TAD_DNO: cTab_RscButtonInv
{
	x="((234) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((1894) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="((142) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="((142) / 2048  *  (safezoneH * 0.8))";
};
class cTab_RscText_TAD: cTab_RscText
{
	style=2;
	w="(((26)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((53)) / 2048  *  (safezoneH * 0.8))";
	font="EtelkaMonospacePro";
	colorText[]=
	{
		"57/255",
		"255/255",
		"20/255",
		1
	};
	sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
	colorBackground[]={0,0,0,1};
	shadow=0;
};
class cTab_TAD_upDownArrow: cTab_RscPicture
{
	w="(((26)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((32)) / 2048  *  (safezoneH * 0.8))";
	colorText[]=
	{
		"57/255",
		"255/255",
		"20/255",
		1
	};
	colorBackground[]={0,0,0,1};
	text="\a3\ui_f\data\IGUI\Cfg\Actions\autohover_ca.paa";
};
class cTab_TAD_RscMapControl: cTab_RscMapControl
{
	text="#(argb,8,8,3)color(1,1,1,1)";
	x="(((359)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((371)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((1330)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((1345)) / 2048  *  (safezoneH * 0.8))";
	scaleMax=1000;
	scaleDefault="(missionNamespace getVariable 'cTabMapScale') * 0.86 / (safezoneH * 0.8)";
	maxSatelliteAlpha=10000;
	alphaFadeStartScale=10;
	alphaFadeEndScale=10;
	ptsPerSquareSea="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareTxt="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareCLn="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareExp="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareCost="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareFor="3 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareForEdge="100 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareRoad="1.5 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareObj="4 / (0.86 /  (safezoneH * 0.8))";
	widthRailWay=1;
};
class cTab_TAD_RscMapControl_BLACK: cTab_TAD_RscMapControl
{
	font="TahomaB";
	sizeEx=0;
	maxSatelliteAlpha=0;
	colorBackground[]={0,0,0,0};
	colorLevels[]={0,0,0,0};
	colorSea[]={0,0,0,0};
	colorForest[]={0,0,0,0};
	colorRocks[]={0,0,0,0};
	colorCountlines[]={0,0,0,0};
	colorMainCountlines[]={0,0,0,0};
	colorCountlinesWater[]={0,0,0,0};
	colorMainCountlinesWater[]={0,0,0,0};
	colorPowerLines[]={0,0,0,0};
	colorRailWay[]={0,0,0,0};
	colorForestBorder[]={0,0,0,0};
	colorRocksBorder[]={0,0,0,0};
	colorNames[]={0,0,0,0};
	colorInactive[]={0,0,0,0};
	colorOutside[]={0,0,0,0};
	colorText[]={0,0,0,0};
	colorGrid[]={0,0,0,0};
	colorGridMap[]={0,0,0,0};
	colorTracks[]={0,0,0,0};
	colorTracksFill[]={0,0,0,0};
	colorRoads[]={0,0,0,0};
	colorRoadsFill[]={0,0,0,0};
	colorMainRoads[]={0,0,0,0};
	colorMainRoadsFill[]={0,0,0,0};
	ShowCountourInterval=0;
	shadow=0;
	text="";
	alphaFadeStartScale=0;
	alphaFadeEndScale=0;
	fontLabel="TahomaB";
	sizeExLabel=0;
	fontGrid="TahomaB";
	sizeExGrid=0;
	fontUnits="TahomaB";
	sizeExUnits=0;
	fontNames="TahomaB";
	sizeExNames=0;
	fontInfo="TahomaB";
	sizeExInfo=0;
	fontLevel="TahomaB";
	sizeExLevel=0;
	stickX[]=
	{
		0,
		
		{
			"Gamma",
			0,
			0
		}
	};
	stickY[]=
	{
		0,
		
		{
			"Gamma",
			0,
			0
		}
	};
	ptsPerSquareSea=10000;
	ptsPerSquareTxt=10000;
	ptsPerSquareCLn=10000;
	ptsPerSquareExp=10000;
	ptsPerSquareCost=10000;
	ptsPerSquareFor=10000;
	ptsPerSquareForEdge=10000;
	ptsPerSquareRoad=10000;
	ptsPerSquareObj=10000;
	widthRailWay=1;
	class Task
	{
		icon="";
		color[]={0,0,0,0};
		iconCreated="";
		colorCreated[]={0,0,0,0};
		iconCanceled="";
		colorCanceled[]={0,0,0,0};
		iconDone="";
		colorDone[]={0,0,0,0};
		iconFailed="";
		colorFailed[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class CustomMark
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Bunker
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Bush
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class BusStop
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Command
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Cross
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Fortress
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Fuelstation
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Fountain
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Hospital
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Chapel
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Church
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Lighthouse
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Quay
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Rock
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Ruin
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class SmallTree
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Stack
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Tree
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Tourism
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Transmitter
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class ViewTower
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Watertower
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Waypoint
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class WaypointCompleted
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class ActiveMarker
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class PowerSolar
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class PowerWave
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class PowerWind
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
	class Shipwreck
	{
		icon="";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
};
class cTab_TAD_Map_Background: cTab_RscText
{
	idc=1;
	x="(((359)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((371)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((1330)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((1345)) / 2048  *  (safezoneH * 0.8))";
	colorBackground[]={0,0,0,1};
};
class cTab_TAD_background: cTab_RscPicture
{
	idc=1200;
	text="";
	x="(safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(safezoneY + 0.1 * safezoneH)";
	w="(safezoneH * 0.8 * 3/4)";
	h="(safezoneH * 0.8)";
};
class cTab_TAD_OSD_hookGrid: cTab_RscText_TAD
{
	idc=2617;
	style=2;
	x="((((1384)) - (26) * 4) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (53) * 0.5 + (53) * 1) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 6) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_hookElevation: cTab_TAD_OSD_hookGrid
{
	idc=2620;
	x="((((1384)) - (26) * 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (53) * 0.5 + (53) * 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((28) * 4) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_hookDir: cTab_TAD_OSD_hookGrid
{
	idc=2618;
	x="((((1384)) - (26) * 6) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (53) * 0.5 + (53) * 0) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((30) * 8) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_hookToggleIconBackground: cTab_RscText_TAD
{
	idc=2;
	x="((((24) + (359)) + (36) - (26)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((1023)) - (53)  / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_hookToggleIcon: cTab_TAD_upDownArrow
{
	idc=3;
	x="((((24) + (359)) + (36) - (26)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((1023)) - (32) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_hookToggleText1: cTab_RscText_TAD
{
	idc=2621;
	x="((((24) + (359)) + (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((1023)) - (53)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 4) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_hookToggleText2: cTab_TAD_OSD_hookToggleText1
{
	idc=2626;
	y="((((1023))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_currentDirection: cTab_RscText_TAD
{
	idc=2615;
	x="((((844)) - (26) * 4 / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((-(24) + (371) + (1345)) - (53) * 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 4) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_currentElevation: cTab_TAD_OSD_currentDirection
{
	idc=2623;
	x="((((1202)) - (26) * 5 / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	w="(((26) * 5) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_centerMapText: cTab_RscText_TAD
{
	idc=4;
	x="((((24) + (359)) + (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((836)) - (53) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4))";
	text="CTR";
};
class cTab_TAD_loadingtxt: cTab_RscText_TAD
{
	idc=1000;
	style=2;
	text="Loading";
	x="(((359)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((371)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((1330)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((1345)) / 2048  *  (safezoneH * 0.8))";
};
class cTab_TAD_OSD_cursor: cTab_RscPicture
{
	idc=5;
	text="\a3\ui_f\data\IGUI\Cfg\WeaponCursors\cursoraimon_gs.paa";
	x="(((359) + (1330) / 2 - 128 / 33 * (48) / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((371) + (1345) / 2 - 128 / 33 * (48) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="((128 / 33 * (48)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="((128 / 33 * (48)) / 2048  *  (safezoneH * 0.8))";
	colorText[]=
	{
		"57/255",
		"255/255",
		"20/255",
		1
	};
};
class cTab_TAD_OSD_navModeOrScale: cTab_RscText_TAD
{
	idc=2614;
	x="(((-(24) + (359) + (1330)) - (38) * 4) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((24) + (371))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((38) * 4) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((82)) / 2048  *  (safezoneH * 0.8))";
	sizeEx="(((66)) / 2048  *  (safezoneH * 0.8))";
};
class cTab_TAD_OSD_modeTAD: cTab_RscText_TAD
{
	idc=6;
	x="((((661)) - (26) * 3 / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((-(24) + (371) + (1345)) - (53)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4))";
	colorText[]={0,0,0,1};
	colorBackground[]=
	{
		"57/255",
		"255/255",
		"20/255",
		1
	};
	text="TAD";
};
class cTab_TAD_OSD_txtToggleIconBg: cTab_RscText_TAD
{
	idc=7;
	x="(((-(24) + (359) + (1330)) - (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (53) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_txtToggleIcon: cTab_TAD_upDownArrow
{
	idc=8;
	x="(((-(24) + (359) + (1330)) - (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (32) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_txtToggleText1: cTab_RscText_TAD
{
	idc=9;
	x="(((-(24) + (359) + (1330)) - (36) - (26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398) - (53)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4))";
	text="TXT";
};
class cTab_TAD_OSD_txtToggleText2: cTab_RscText_TAD
{
	idc=2610;
	x="(((-(24) + (359) + (1330)) - (36) - (26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((1398)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_time: cTab_RscText_TAD
{
	idc=2613;
	x="((((24) + (359))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((-(24) + (371) + (1345)) - (53)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 5) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_currentGrid: cTab_RscText_TAD
{
	idc=2612;
	x="((((1023)) - (26) * 6 / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((-(24) + (371) + (1345)) - (53) * 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 6) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_OSD_mapToggleIconBg: cTab_RscText_TAD
{
	idc=10;
	x="((((24) + (359)) + (36) - (26)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((647)) - (53) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_mapToggleIcon: cTab_TAD_upDownArrow
{
	idc=11;
	x="((((24) + (359)) + (36) - (26)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((647)) - (32) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
};
class cTab_TAD_OSD_mapToggleText1: cTab_RscText_TAD
{
	idc=12;
	x="((((24) + (359)) + (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((647)) - (53)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 3) / 2048  *  (safezoneH * 0.8 * 3/4))";
	text="MAP";
};
class cTab_TAD_OSD_mapToggleText2: cTab_RscText_TAD
{
	idc=2611;
	x="((((24) + (359)) + (36)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((((647))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((26) * 4) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_movingHandle_T: cTab_RscText_TAD
{
	idc=13;
	moving=1;
	colorBackground[]={0,0,0,0};
	x="((0) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="((0) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="((2048 ) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((371)) / 2048  *  (safezoneH * 0.8))";
};
class cTab_TAD_movingHandle_B: cTab_TAD_movingHandle_T
{
	idc=14;
	y="(((371) + (1345)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	h="((2048  - ((371) + (1345))) / 2048  *  (safezoneH * 0.8))";
};
class cTab_TAD_movingHandle_L: cTab_TAD_movingHandle_T
{
	idc=15;
	y="(((371)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((359)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((1345)) / 2048  *  (safezoneH * 0.8))";
};
class cTab_TAD_movingHandle_R: cTab_TAD_movingHandle_L
{
	idc=16;
	x="(((359) + (1330)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	w="((2048  - ((359) + (1330))) / 2048  *  (safezoneH * 0.8 * 3/4))";
};
class cTab_TAD_brightness: cTab_RscText_TAD
{
	idc=1005;
	x="(((359)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((371)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((1330)) / 2048  *  (safezoneH * 0.8 * 3/4))";
	h="(((1345)) / 2048  *  (safezoneH * 0.8))";
	colorBackground[]={0,0,0,0};
};
class cTab_TAD_notification: cTab_RscText_TAD
{
	idc=1620;
	x="(((359) + ((1330) * 0.2) / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2))";
	y="(((-(24) + (371) + (1345)) - (53) * 3) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH))";
	w="(((1330) * 0.8) / 2048  *  (safezoneH * 0.8 * 3/4))";
	colorText[]=
	{
		0,
		0,
		"128/255",
		1
	};
	colorBackground[]={1,1,1,1};
};
class cTab_TAD_dlg
{
	idd=1755424;
	movingEnable="true";
	onLoad="_this call cTab_fnc_onIfOpen;";
	onUnload="[] call cTab_fnc_onIfclose;";
	onKeyDown="_this call cTab_fnc_onIfKeyDown;";
	objects[]={};
	class controlsBackground
	{
		class mapBackground: cTab_TAD_Map_Background
		{
		};
		class screen: cTab_TAD_RscMapControl
		{
			idc=1201;
			onDraw="nop = _this call cTabOnDrawbftTADdialog;";
			onMouseButtonDblClick="_ok = [3300,_this] execVM '\cTab\shared\cTab_markerMenu_load.sqf';";
			onMouseMoving="cTabCursorOnMap = _this select 3;cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
		};
		class screenTopo: screen
		{
			idc=1202;
			maxSatelliteAlpha=0;
		};
		class screenBlack: cTab_TAD_RscMapControl_BLACK
		{
			idc=1203;
			onDraw="nop = _this call cTabOnDrawbftTADdialog;";
			onMouseButtonDblClick="_ok = [3300,_this] execVM '\cTab\shared\cTab_markerMenu_load.sqf';";
			onMouseMoving="cTabCursorOnMap = _this select 3;cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
		};
	};
	class controls
	{
		class navMode: cTab_TAD_OSD_navModeOrScale
		{
			text="EXT1";
		};
		class modeTAD: cTab_TAD_OSD_modeTAD
		{
		};
		class txtToggleIconBg: cTab_TAD_OSD_txtToggleIconBg
		{
		};
		class txtToggleIcon: cTab_TAD_OSD_txtToggleIcon
		{
		};
		class txtToggleText1: cTab_TAD_OSD_txtToggleText1
		{
		};
		class txtToggleText2: cTab_TAD_OSD_txtToggleText2
		{
		};
		class time: cTab_TAD_OSD_time
		{
		};
		class currentGrid: cTab_TAD_OSD_currentGrid
		{
		};
		class mapToggleIconBg: cTab_TAD_OSD_mapToggleIconBg
		{
		};
		class mapToggleIcon: cTab_TAD_OSD_mapToggleIcon
		{
		};
		class mapToggleText1: cTab_TAD_OSD_mapToggleText1
		{
		};
		class mapToggleText2: cTab_TAD_OSD_mapToggleText2
		{
		};
		class hookGrid: cTab_TAD_OSD_hookGrid
		{
		};
		class hookElevation: cTab_TAD_OSD_hookElevation
		{
		};
		class hookDir: cTab_TAD_OSD_hookDir
		{
		};
		class hookToggleIconBackground: cTab_TAD_OSD_hookToggleIconBackground
		{
		};
		class hookToggleIcon: cTab_TAD_OSD_hookToggleIcon
		{
		};
		class hookToggleText1: cTab_TAD_OSD_hookToggleText1
		{
		};
		class hookToggleText2: cTab_TAD_OSD_hookToggleText2
		{
		};
		class on_screen_currentDirection: cTab_TAD_OSD_currentDirection
		{
		};
		class on_screen_currentElevation: cTab_TAD_OSD_currentElevation
		{
		};
		class on_screen_centerMapText: cTab_TAD_OSD_centerMapText
		{
		};
		class notification: cTab_TAD_notification
		{
		};
		class loadingtxt: cTab_TAD_loadingtxt
		{
		};
		class brightness: cTab_TAD_brightness
		{
		};
		class MainSubmenu: cTab_RscControlsGroup
		{
			idc=3300;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(4 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class mainbg: cTab_IGUIBack
				{
					idc=2200;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(4 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class op4btn: cTab_MenuItem
				{
					idc=2000;
					text="Enemy SALUTE";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[11] call cTab_fnc_userMenuSelect;";
				};
				class medbtn: cTab_MenuItem
				{
					idc=2001;
					text="Medical";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[21] call cTab_fnc_userMenuSelect;";
				};
				class genbtn: cTab_MenuItem
				{
					idc=2002;
					text="General";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[31] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub1: cTab_RscControlsGroup
		{
			idc=3301;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(8 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2201: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(8 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class infbtn: cTab_MenuItem
				{
					idc=2003;
					text="Infantry";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,0];[12] call cTab_fnc_userMenuSelect;";
				};
				class mecinfbtn: cTab_MenuItem
				{
					idc=2004;
					text="Mechanized Inf";
					toolTip="Equipped with APCs/IFVs";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,1];[12] call cTab_fnc_userMenuSelect;";
				};
				class motrinfbtn: cTab_MenuItem
				{
					idc=2032;
					text="Motorized Inf";
					toolTip="Equipped with un-protected vehicles";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,2];[12] call cTab_fnc_userMenuSelect;";
				};
				class amrbtn: cTab_MenuItem
				{
					idc=2005;
					text="Armor";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,3];[12] call cTab_fnc_userMenuSelect;";
				};
				class helibtn: cTab_MenuItem
				{
					idc=2006;
					text="Helicopter";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,4];[12] call cTab_fnc_userMenuSelect;";
				};
				class plnbtn: cTab_MenuItem
				{
					idc=2007;
					text="Plane";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,5];[12] call cTab_fnc_userMenuSelect;";
				};
				class uknbtn: cTab_MenuItem
				{
					idc=2008;
					text="Unknown";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,6];[12] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub2: cTab_RscControlsGroup
		{
			idc=3303;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(6 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(6 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class ftbtn: cTab_MenuItem
				{
					idc=2009;
					text="Singular";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[14] call cTab_fnc_userMenuSelect;";
				};
				class patbtn: cTab_MenuItem
				{
					idc=2010;
					text="Patrol";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [2,1];[13] call cTab_fnc_userMenuSelect;";
				};
				class sqdbtn: cTab_MenuItem
				{
					idc=2011;
					text="Squad";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [2,2];[13] call cTab_fnc_userMenuSelect;";
				};
				class sctbtn: cTab_MenuItem
				{
					idc=2012;
					text="Section";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [2,3];[13] call cTab_fnc_userMenuSelect;";
				};
				class pltnbtn: cTab_MenuItem
				{
					idc=2013;
					text="Platoon";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [2,4];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub3: cTab_RscControlsGroup
		{
			idc=3304;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(10 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2203: cTab_IGUIBack
				{
					idc=2203;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(10 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class stnbtn: cTab_MenuItem
				{
					idc=2029;
					text="Stationary";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[1] call cTab_fnc_userMenuSelect;";
				};
				class nthbtn: cTab_MenuItem
				{
					idc=2015;
					text="N";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,1];[1] call cTab_fnc_userMenuSelect;";
				};
				class nebtn: cTab_MenuItem
				{
					idc=2016;
					text="NE";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,2];[1] call cTab_fnc_userMenuSelect;";
				};
				class ebtn: cTab_MenuItem
				{
					idc=2017;
					text="E";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,3];[1] call cTab_fnc_userMenuSelect;";
				};
				class sebtn: cTab_MenuItem
				{
					idc=2018;
					text="SE";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,4];[1] call cTab_fnc_userMenuSelect;";
				};
				class sbtn: cTab_MenuItem
				{
					idc=2019;
					text="S";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,5];[1] call cTab_fnc_userMenuSelect;";
				};
				class swbtn: cTab_MenuItem
				{
					idc=2020;
					text="SW";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,6];[1] call cTab_fnc_userMenuSelect;";
				};
				class wbtn: cTab_MenuItem
				{
					idc=2021;
					text="W";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,7];[1] call cTab_fnc_userMenuSelect;";
				};
				class RscText_1022: cTab_MenuItem
				{
					idc=2022;
					text="NW";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (9 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [3,8];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (10 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class EnemySub4: cTab_RscControlsGroup
		{
			idc=3307;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(8 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2202: cTab_IGUIBack
				{
					idc=2202;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(8 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class rifle_btn: cTab_MenuItem
				{
					idc=-1;
					text="Rifle";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,7];[13] call cTab_fnc_userMenuSelect;";
				};
				class lmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="MG";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,8];[13] call cTab_fnc_userMenuSelect;";
				};
				class at_btn: cTab_MenuItem
				{
					idc=-1;
					text="AT";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,9];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmg_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static MG";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,10];[13] call cTab_fnc_userMenuSelect;";
				};
				class mat_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AT";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,11];[13] call cTab_fnc_userMenuSelect;";
				};
				class aa_btn: cTab_MenuItem
				{
					idc=-1;
					text="Static AA";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (6 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,13];[13] call cTab_fnc_userMenuSelect;";
				};
				class mmortar_btn: cTab_MenuItem
				{
					idc=-1;
					text="Mortar";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (7 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,12];[13] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (8 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class CasulSub1: cTab_RscControlsGroup
		{
			idc=3305;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(5 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2204: cTab_IGUIBack
				{
					idc=2204;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(5 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class casltybtn: cTab_MenuItem
				{
					idc=2024;
					text="Casualty";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,20];[1] call cTab_fnc_userMenuSelect;";
				};
				class ccpbtn: cTab_MenuItem
				{
					idc=2025;
					text="CCP";
					toolTip="Casualty Collection Point";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,21];[1] call cTab_fnc_userMenuSelect;";
				};
				class basbtn: cTab_MenuItem
				{
					idc=2026;
					text="BAS";
					toolTip="Battalion Aid Station";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,22];[1] call cTab_fnc_userMenuSelect;";
				};
				class mcibtn: cTab_MenuItem
				{
					idc=2031;
					text="MCI";
					toolTip="Mass Casualty Incident";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (4 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,23];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (5 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class GenSub1: cTab_RscControlsGroup
		{
			idc=3306;
			x="safeZoneXAbs + safeZoneWAbs";
			y="safeZoneY + safeZoneH";
			w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
			h="(3 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
			class controls
			{
				class IGUIBack_2205: cTab_IGUIBack
				{
					idc=2205;
					x=0;
					y=0;
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(3 + 0.5) * (((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
				};
				class hqbtn: cTab_MenuItem
				{
					idc=2027;
					text="HQ";
					toolTip="Headquaters";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (1 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,30];[1] call cTab_fnc_userMenuSelect;";
				};
				class lzbtn: cTab_MenuItem
				{
					idc=2028;
					text="LZ";
					toolTip="Landing Zone";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (2 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="cTabUserSelIcon set [1,31];[1] call cTab_fnc_userMenuSelect;";
				};
				class exit: cTab_MenuExit
				{
					idc=-1;
					text="Exit";
					x=0;
					y="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8 * (3 - 1)";
					w="(12  + 1.5) * (((42)) / 2048  *  (safezoneH * 0.8)) * 3/4 * 0.5";
					h="(((42)) / 2048  *  (safezoneH * 0.8)) / 0.8";
					sizeEx="(((42)) / 2048  *  (safezoneH * 0.8))";
					action="[0] call cTab_fnc_userMenuSelect;";
				};
			};
		};
		class background: cTab_TAD_background
		{
		};
		class movingHandle_T: cTab_TAD_movingHandle_T
		{
		};
		class movingHandle_B: cTab_TAD_movingHandle_B
		{
		};
		class movingHandle_L: cTab_TAD_movingHandle_L
		{
		};
		class movingHandle_R: cTab_TAD_movingHandle_R
		{
		};
		class pwrbtn: cTab_RscButton_TAD_DNO
		{
			idc=1606;
			onMouseButtonUp="if (_this select 1 == 0) then {['cTab_TAD_dlg'] call cTab_fnc_toggleNightMode} else {if (_this select 1 == 1) then {[] call cTab_fnc_close};}";
			tooltip="left-click: Toggle DAY / NIGHT mode; right-click: Close interface";
		};
		class btnSymInc: cTab_RscButton_TAD_SYM_INC
		{
			idc=1609;
			action="call cTab_fnc_txt_size_inc;";
			tooltip="Increase Font";
		};
		class btnSymDec: cTab_RscButton_TAD_SYM_DEC
		{
			idc=1610;
			action="call cTab_fnc_txt_size_dec;";
			tooltip="Decrease Font";
		};
		class btnBrtInc: cTab_RscButton_TAD_BRT_INC
		{
			idc=17;
			action="['cTab_TAD_dlg'] call cTab_fnc_incBrightness;";
			tooltip="Increase Brightness";
		};
		class btnBrtDec: cTab_RscButton_TAD_BRT_DEC
		{
			idc=18;
			action="['cTab_TAD_dlg'] call cTab_fnc_decBrightness;";
			tooltip="Decrease Brightness";
		};
		class btnfunction: cTab_RscButton_TAD_OSB10
		{
			idc=1607;
			action="['cTab_TAD_dlg'] call cTab_fnc_iconText_toggle;";
			tooltip="Toggle Text on/off";
		};
		class btnMapType: cTab_RscButton_TAD_OSB20
		{
			idc=19;
			action="['cTab_TAD_dlg'] call cTab_fnc_mapType_toggle;";
			tooltip="Toggle Map Type (F6)";
		};
		class btnMapTools: cTab_RscButton_TAD_OSB18
		{
			idc=20;
			action="['cTab_TAD_dlg'] call cTab_fnc_toggleMapTools;";
			tooltip="Toggle Map Tools (F5)";
		};
		class btnF7: cTab_RscButton_TAD_OSB19
		{
			idc=21;
			action="['cTab_TAD_dlg'] call cTab_fnc_centerMapOnPlayerPosition;";
			tooltip="Center Map On Current Position (F7)";
		};
	};
};
class cTab_microDAGR_header: cTab_RscPicture
{
	idc=1;
	text="#(argb,8,8,3)color(0,0,0,1)";
	x="((573)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="((317)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="((942)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="((94)) / 2048  *  (safezoneH * 0.8)";
};
class cTab_microDAGR_footer: cTab_microDAGR_header
{
	idc=2;
	y="((317) + (1296) - ((94))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	h="(((94))) / 2048  *  (safezoneH * 0.8)";
};
class cTab_RscButton_microDAGR_LeftUp: cTab_RscButtonInv
{
	x="(373) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(400) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(26) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(171) / 2048  *  (safezoneH * 0.8)";
};
class cTab_RscButton_microDAGR_LeftDown: cTab_RscButton_microDAGR_LeftUp
{
	y="(571) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
};
class cTab_RscButton_microDAGR_LeftBtn: cTab_RscButtonInv
{
	x="(368) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(829) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(31) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(184) / 2048  *  (safezoneH * 0.8)";
};
class cTab_RscButton_microDAGR_RightUp: cTab_RscButton_microDAGR_LeftUp
{
	x="(1689) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_RscButton_microDAGR_RightDown: cTab_RscButton_microDAGR_LeftDown
{
	x="(1689) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_RscButton_microDAGR_RightBtn: cTab_RscButton_microDAGR_LeftBtn
{
	x="(1689) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_RscText_microDAGR: cTab_RscText
{
	style=2;
	w="((((942) - (24) * 4) / 3)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(((94) - (24))) / 2048  *  (safezoneH * 0.8)";
	font="EtelkaMonospacePro";
	colorText[]={1,1,1,1};
	sizeEx="((60)) / 2048  *  (safezoneH * 0.8)";
	colorBackground[]={0,0,0,0};
	shadow=0;
};
class cTab_microDAGR_RscMapControl: cTab_RscMapControl
{
	idc=1201;
	text="#(argb,8,8,3)color(1,1,1,1)";
	x="(((573))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(((317) + (94))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(((942))) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(((1296) - (94) - ((94)))) / 2048  *  (safezoneH * 0.8)";
	scaleMax=1000;
	maxSatelliteAlpha=10000;
	alphaFadeStartScale=10;
	alphaFadeEndScale=10;
	ptsPerSquareSea="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareTxt="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareCLn="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareExp="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareCost="8 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareFor="3 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareForEdge="100 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareRoad="1.5 / (0.86 /  (safezoneH * 0.8))";
	ptsPerSquareObj="4 / (0.86 /  (safezoneH * 0.8))";
	widthRailWay=1;
};
class cTab_microDAGR_background: cTab_RscPicture
{
	idc=1200;
	text="";
	x="(safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(safezoneY + 0.1 * safezoneH)";
	w="(safezoneH * 0.8 * 3/4)";
	h="(safezoneH * 0.8)";
};
class cTab_microDAGR_cursor: cTab_RscPicture
{
	idc=3;
	text="\a3\ui_f\data\IGUI\Cfg\WeaponCursors\cursoraimon_gs.paa";
	x="((573) + (942) / 2 - 128 / 33 * (38) / 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="((317) + (1296) / 2 - 128 / 33 * (38) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(128 / 33 * (38)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(128 / 33 * (38)) / 2048  *  (safezoneH * 0.8)";
	colorText[]=
	{
		"57/255",
		"255/255",
		"20/255",
		1
	};
};
class cTab_microDAGR_btnF7: cTab_RscButton_microDAGR_LeftBtn
{
	idc=4;
	tooltip="Center Map On Current Position (F7)";
};
class cTab_microDAGR_btnbrtpls: cTab_RscButton_microDAGR_RightUp
{
	idc=1609;
	action="call cTab_fnc_txt_size_inc;";
	tooltip="Increase Font";
};
class cTab_microDAGR_btnbrtmns: cTab_RscButton_microDAGR_RightDown
{
	idc=1610;
	action="call cTab_fnc_txt_size_dec;";
	tooltip="Decrease Font";
};
class cTab_microDAGR_btnfunction: cTab_RscButton_microDAGR_RightBtn
{
	idc=1607;
	tooltip="Toggle Text on/off";
};
class cTab_microDAGR_btnMapType: cTab_RscButton_microDAGR_LeftUp
{
	idc=5;
	tooltip="Toggle Map Type (F6)";
};
class cTab_microDAGR_btnMapTools: cTab_RscButton_microDAGR_LeftDown
{
	idc=6;
	tooltip="Toggle Map Tools (F5)";
};
class cTab_microDAGR_on_screen_battery: cTab_RscPicture
{
	idc=7;
	text="\cTab\img\icon_battery_ca.paa";
	x="((((24) + (573)))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(((24) + (317)) + (((94) - (24)) - (50)) / 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="((50)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="((50)) / 2048  *  (safezoneH * 0.8)";
	colorText[]={1,1,1,1};
};
class cTab_microDAGR_on_screen_time: cTab_RscText_microDAGR
{
	idc=2613;
	style=2;
	x="((((24) + (573)) + (24) + (((942) - (24) * 4) / 3))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(((24) + (317))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
};
class cTab_microDAGR_on_screen_signalStrength: cTab_microDAGR_on_screen_battery
{
	idc=8;
	text="\cTab\img\icon_signalStrength_ca.paa";
	x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3)) + (((942) - (24) * 4) / 3) - (50) * 2) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_microDAGR_on_screen_satellite: cTab_microDAGR_on_screen_battery
{
	idc=9;
	text="\a3\ui_f\data\map\Diary\signal_ca.paa";
	x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3)) + (((942) - (24) * 4) / 3) - (50)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	colorText[]={1,1,1,1};
};
class cTab_microDAGR_on_screen_dirDegree: cTab_RscText_microDAGR
{
	idc=2615;
	style=0;
	y="((-((94)) + (317) + (1296))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	x="((((24) + (573)))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_microDAGR_on_screen_grid: cTab_microDAGR_on_screen_dirDegree
{
	idc=2612;
	style=2;
	x="((((24) + (573)) + (24) + (((942) - (24) * 4) / 3))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_microDAGR_on_screen_dirOctant: cTab_microDAGR_on_screen_dirDegree
{
	idc=2616;
	style=1;
	x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
};
class cTab_microDAGR_on_screen_hookGrid: cTab_RscText_microDAGR
{
	idc=2617;
	style=2;
	x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 4) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	colorText[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.25};
};
class cTab_microDAGR_on_screen_hookElevation: cTab_microDAGR_on_screen_hookGrid
{
	idc=2620;
	y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 3) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
};
class cTab_microDAGR_on_screen_hookDst: cTab_microDAGR_on_screen_hookGrid
{
	idc=2619;
	y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 2) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
};
class cTab_microDAGR_on_screen_hookDir: cTab_microDAGR_on_screen_hookGrid
{
	idc=2618;
	y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
};
class cTab_microDAGR_loadingtxt: cTab_RscText_microDAGR
{
	idc=1000;
	style=2;
	text="Loading";
	x="(((573))) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(((317) + (94))) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(((942))) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="(((1296) - (94) - ((94)))) / 2048  *  (safezoneH * 0.8)";
	colorBackground[]={0,0,0,0};
};
class cTab_microDAGR_movingHandle_T: cTab_RscText_microDAGR
{
	idc=10;
	moving=1;
	colorBackground[]={0,0,0,0};
	x="(0) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="(0) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="(2048 ) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="((317)) / 2048  *  (safezoneH * 0.8)";
};
class cTab_microDAGR_movingHandle_B: cTab_microDAGR_movingHandle_T
{
	idc=11;
	y="((317) + (1296)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	h="(2048  - ((317) + (1296))) / 2048  *  (safezoneH * 0.8)";
};
class cTab_microDAGR_movingHandle_L: cTab_microDAGR_movingHandle_T
{
	idc=12;
	y="((317)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="((573)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="((1296)) / 2048  *  (safezoneH * 0.8)";
};
class cTab_microDAGR_movingHandle_R: cTab_microDAGR_movingHandle_L
{
	idc=13;
	x="((573) + (942)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	w="(2048  - ((573) + (942))) / 2048  *  (safezoneH * 0.8 * 3/4)";
};
class cTab_microDAGR_brightness: cTab_RscText_microDAGR
{
	idc=1005;
	x="((573)) / 2048  *  (safezoneH * 0.8 * 3/4) +  (safezoneX + (safezoneW - safezoneH * 0.8 * 3/4) / 2)";
	y="((317)) / 2048  *  (safezoneH * 0.8) +  (safezoneY + 0.1 * safezoneH)";
	w="((942)) / 2048  *  (safezoneH * 0.8 * 3/4)";
	h="((1296)) / 2048  *  (safezoneH * 0.8)";
	colorBackground[]={0,0,0,0};
};
class cTab_microDAGR_dlg
{
	idd=1776134;
	movingEnable="true";
	onLoad="_this call cTab_fnc_onIfOpen;";
	onUnload="[] call cTab_fnc_onIfclose;";
	onKeyDown="_this call cTab_fnc_onIfKeyDown;";
	objects[]={};
	class controlsBackground
	{
		class screen: cTab_microDAGR_RscMapControl
		{
			onDraw="nop = _this call cTabOnDrawbftmicroDAGRdlg;";
			onMouseMoving="cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1,_this select 2];";
			scaleDefault="(missionNamespace getVariable 'cTabMapScale') * 0.86 / (safezoneH * 0.8)";
		};
		class screenTopo: screen
		{
			idc=1202;
			maxSatelliteAlpha=0;
		};
	};
	class controls
	{
		class header: cTab_microDAGR_header
		{
		};
		class footer: cTab_microDAGR_footer
		{
		};
		class battery: cTab_microDAGR_on_screen_battery
		{
		};
		class time: cTab_microDAGR_on_screen_time
		{
		};
		class signalStrength: cTab_microDAGR_on_screen_signalStrength
		{
		};
		class satellite: cTab_microDAGR_on_screen_satellite
		{
		};
		class dirDegree: cTab_microDAGR_on_screen_dirDegree
		{
		};
		class grid: cTab_microDAGR_on_screen_grid
		{
		};
		class dirOctant: cTab_microDAGR_on_screen_dirOctant
		{
		};
		class btnbrtpls: cTab_microDAGR_btnbrtpls
		{
		};
		class btnbrtmns: cTab_microDAGR_btnbrtmns
		{
		};
		class hookGrid: cTab_microDAGR_on_screen_hookGrid
		{
		};
		class hookElevation: cTab_microDAGR_on_screen_hookElevation
		{
		};
		class hookDst: cTab_microDAGR_on_screen_hookDst
		{
		};
		class hookDir: cTab_microDAGR_on_screen_hookDir
		{
		};
		class loadingtxt: cTab_microDAGR_loadingtxt
		{
		};
		class brightness: cTab_microDAGR_brightness
		{
		};
		class background: cTab_microDAGR_background
		{
		};
		class movingHandle_T: cTab_microDAGR_movingHandle_T
		{
		};
		class movingHandle_B: cTab_microDAGR_movingHandle_B
		{
		};
		class movingHandle_L: cTab_microDAGR_movingHandle_L
		{
		};
		class movingHandle_R: cTab_microDAGR_movingHandle_R
		{
		};
		class btnMapType: cTab_microDAGR_btnMapType
		{
			action="['cTab_microDAGR_dlg'] call cTab_fnc_mapType_toggle;";
		};
		class btnMapTools: cTab_microDAGR_btnMapTools
		{
			action="['cTab_microDAGR_dlg'] call cTab_fnc_toggleMapTools;";
		};
		class btnF7: cTab_microDAGR_btnF7
		{
			action="['cTab_microDAGR_dlg'] call cTab_fnc_centerMapOnPlayerPosition;";
		};
		class btnfunction: cTab_microDAGR_btnfunction
		{
			action="['cTab_microDAGR_dlg'] call cTab_fnc_iconText_toggle;";
		};
	};
};
class CfgWeapons
{
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class ItemcTab: CBA_MiscItem
	{
		descriptionshort="Roda Panther DK10 Rugged Tablet PC";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Commander's Tablet";
		displayname="DK10 Tablet";
		picture="\cTab\img\icon_dk10.paa";
		model="\ctab\data\itemDK10.p3d";
		scope=2;
		author="Gundy-Riouken-Raspu";
		simulation="Weapon";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=12;
		};
	};
	class ItemAndroid: ItemcTab
	{
		descriptionshort="Samsung Galaxy S7, Kägwerks S7 Kit, Android Team Awareness Kit";
		descriptionuse="<t color='#9cf953'>Use: </t>Show ATAK";
		displayname="Galaxy S7 ATAK";
		picture="\cTab\img\icon_Android.paa";
		model="\A3\Structures_F\Items\Electronics\MobilePhone_smart_F.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=4;
		};
		author="Gundy-Riouken-Raspu";
	};
	class ItemMicroDAGR: ItemcTab
	{
		descriptionshort="HNV-2930 Micro Defense Advanced GPS Receiver";
		descriptionuse="<t color='#9cf953'>Use: </t>Show MicroDAGR";
		displayname="MicroDAGR";
		picture="\cTab\img\icon_MicroDAGR.paa";
		model="\ctab\data\itemMicroDAGR.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=2;
		};
		author="Gundy-Riouken-Raspu";
	};
	class ItemcTabHCam: CBA_MiscItem
	{
		descriptionshort="CountourHD 1080P Helmet Mounted Camera";
		descriptionuse="<t color='#9cf953'>Use: </t>Used to record and stream video";
		displayname="Helmet Camera";
		picture="\cTab\img\cTab_helmetCam_ico.paa";
		scope=2;
		author="Gundy-Riouken-Raspu";
		simulation="Weapon";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=2;
		};
	};
};
class CfgNotifications
{
	class cTabUavNotAval
	{
		title="cTab";
		iconPicture="\cTab\img\15th_rugged_tab_ico.paa";
		iconText="";
		color[]={1,1,1,1};
		description="%1";
		duration=5;
		priority=7;
		difficulty[]={};
	};
	class cTabNewMsg
	{
		title="cTab";
		iconPicture="\cTab\img\icoUnopenedmail.paa";
		iconText="";
		color[]={1,1,1,1};
		description="%1";
		duration=4;
		priority=7;
		difficulty[]={};
	};
	class cTabMsgSent
	{
		title="cTab";
		iconPicture="\cTab\img\icoUnopenedmail.paa";
		iconText="";
		color[]={1,1,1,1};
		description="Your message has been sent.";
		duration=4;
		priority=7;
		difficulty[]={};
	};
};
class RscTitles
{
	titles[]={};
	class cTab_mapSize_dsp
	{
		idd=13673;
		onLoad="uiNamespace setVariable ['cTab_mapSize_dsp',_this select 0]";
		fadein=0;
		fadeout=0;
		duration=9.9999998e+010;
		controlsBackground[]={};
		objects[]={};
		class controls
		{
			class mapSize: cTab_RscMapControl
			{
				idc=1110;
				type=100;
				x="safeZoneXAbs + safeZoneWAbs";
				y="safeZoneY + safeZoneH";
				w=0.0099999998;
				h=10;
				scaleMin=0.001;
				scaleDefault=0.001;
				maxSatelliteAlpha=0;
				ptsPerSquareSea=10000;
				ptsPerSquareTxt=10000;
				ptsPerSquareCLn=10000;
				ptsPerSquareExp=10000;
				ptsPerSquareCost=10000;
				ptsPerSquareFor=10000;
				ptsPerSquareForEdge=10000;
				ptsPerSquareRoad=10000;
				ptsPerSquareObj=10000;
				widthRailWay=1;
			};
		};
	};
	class cTab_Mail_ico_disp
	{
		idd=13672;
		name="__cTabMailico";
		onLoad="uiNamespace setVariable ['cTab_Mail_ico_disp', _this select 0]";
		fadein=0;
		fadeout=0;
		duration=9.9999998e+010;
		controlsBackground[]={};
		objects[]={};
		class controls
		{
			class trin_image
			{
				idc=1110;
				type=0;
				style=48;
				colorBackground[]={};
				colorText[]={};
				font="puristaLight";
				sizeEx=0.052999999;
				x="(safezoneX + safezoneW * (1 - 0.00675) -  ( (0.048) * 3/4))";
				y="(safezoneY + safezoneH * 0.25)";
				w="( (0.048) * 3/4)";
				h="(0.048)";
				text="\cTab\img\icon_mail_ca.paa";
			};
		};
	};
	class cTab_RscButton_TAD_OSB: cTab_RscButtonInv
	{
		w="((134) / 2048  *  ( (0.86) * 3/4))";
		h="((134) / 2048  *  ( (0.86)))";
	};
	class cTab_RscButton_TAD_OSB01: cTab_RscButton_TAD_OSB
	{
		x="((577) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((146) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB02: cTab_RscButton_TAD_OSB01
	{
		x="((767) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB03: cTab_RscButton_TAD_OSB01
	{
		x="((957) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB04: cTab_RscButton_TAD_OSB01
	{
		x="((1147) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB05: cTab_RscButton_TAD_OSB01
	{
		x="((1337) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB06: cTab_RscButton_TAD_OSB
	{
		x="((1782) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((563) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB07: cTab_RscButton_TAD_OSB06
	{
		y="((760) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB08: cTab_RscButton_TAD_OSB06
	{
		y="((957) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB09: cTab_RscButton_TAD_OSB06
	{
		y="((1155) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB10: cTab_RscButton_TAD_OSB06
	{
		y="((1352) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB11: cTab_RscButton_TAD_OSB
	{
		x="((1337) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((1811) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB12: cTab_RscButton_TAD_OSB11
	{
		x="((1147) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB13: cTab_RscButton_TAD_OSB11
	{
		x="((957) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB14: cTab_RscButton_TAD_OSB11
	{
		x="((767) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB15: cTab_RscButton_TAD_OSB11
	{
		x="((577) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_OSB16: cTab_RscButton_TAD_OSB
	{
		x="((132) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((1352) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB17: cTab_RscButton_TAD_OSB16
	{
		y="((1155) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB18: cTab_RscButton_TAD_OSB16
	{
		y="((957) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB19: cTab_RscButton_TAD_OSB16
	{
		y="((760) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_OSB20: cTab_RscButton_TAD_OSB16
	{
		y="((563) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_ADJ_INC: cTab_RscButtonInv
	{
		x="((124) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((257) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="((142) / 2048  *  ( (0.86) * 3/4))";
		h="((119) / 2048  *  ( (0.86)))";
	};
	class cTab_RscButton_TAD_ADJ_DEC: cTab_RscButton_TAD_ADJ_INC
	{
		y="((376) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_DSP_INC: cTab_RscButton_TAD_ADJ_INC
	{
		x="((1782) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_DSP_DEC: cTab_RscButton_TAD_DSP_INC
	{
		y="((376) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_CON_INC: cTab_RscButton_TAD_ADJ_INC
	{
		y="((1539) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_CON_DEC: cTab_RscButton_TAD_CON_INC
	{
		y="((1658) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_BRT_INC: cTab_RscButton_TAD_CON_INC
	{
		x="((1782) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_BRT_DEC: cTab_RscButton_TAD_BRT_INC
	{
		y="((1658) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_RscButton_TAD_SYM_INC: cTab_RscButtonInv
	{
		x="((1663) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((1811) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="((119) / 2048  *  ( (0.86) * 3/4))";
		h="((142) / 2048  *  ( (0.86)))";
	};
	class cTab_RscButton_TAD_SYM_DEC: cTab_RscButton_TAD_SYM_INC
	{
		x="((1544) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
	};
	class cTab_RscButton_TAD_DNO: cTab_RscButtonInv
	{
		x="((234) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((1894) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="((142) / 2048  *  ( (0.86) * 3/4))";
		h="((142) / 2048  *  ( (0.86)))";
	};
	class cTab_RscText_TAD: cTab_RscText
	{
		style=2;
		w="(((26)) / 2048  *  ( (0.86) * 3/4))";
		h="(((53)) / 2048  *  ( (0.86)))";
		font="EtelkaMonospacePro";
		colorText[]=
		{
			"57/255",
			"255/255",
			"20/255",
			1
		};
		sizeEx="(((42)) / 2048  *  ( (0.86)))";
		colorBackground[]={0,0,0,1};
		shadow=0;
	};
	class cTab_TAD_upDownArrow: cTab_RscPicture
	{
		w="(((26)) / 2048  *  ( (0.86) * 3/4))";
		h="(((32)) / 2048  *  ( (0.86)))";
		colorText[]=
		{
			"57/255",
			"255/255",
			"20/255",
			1
		};
		colorBackground[]={0,0,0,1};
		text="\a3\ui_f\data\IGUI\Cfg\Actions\autohover_ca.paa";
	};
	class cTab_TAD_RscMapControl: cTab_RscMapControl
	{
		text="#(argb,8,8,3)color(1,1,1,1)";
		x="(((359)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((371)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((1330)) / 2048  *  ( (0.86) * 3/4))";
		h="(((1345)) / 2048  *  ( (0.86)))";
		scaleMax=1000;
		scaleDefault="(missionNamespace getVariable 'cTabMapScale') * 0.86 / (safezoneH * 0.8)";
		maxSatelliteAlpha=10000;
		alphaFadeStartScale=10;
		alphaFadeEndScale=10;
		ptsPerSquareSea="8 / (1)";
		ptsPerSquareTxt="8 / (1)";
		ptsPerSquareCLn="8 / (1)";
		ptsPerSquareExp="8 / (1)";
		ptsPerSquareCost="8 / (1)";
		ptsPerSquareFor="3 / (1)";
		ptsPerSquareForEdge="100 / (1)";
		ptsPerSquareRoad="1.5 / (1)";
		ptsPerSquareObj="4 / (1)";
		widthRailWay=1;
	};
	class cTab_TAD_RscMapControl_BLACK: cTab_TAD_RscMapControl
	{
		font="TahomaB";
		sizeEx=0;
		maxSatelliteAlpha=0;
		colorBackground[]={0,0,0,0};
		colorLevels[]={0,0,0,0};
		colorSea[]={0,0,0,0};
		colorForest[]={0,0,0,0};
		colorRocks[]={0,0,0,0};
		colorCountlines[]={0,0,0,0};
		colorMainCountlines[]={0,0,0,0};
		colorCountlinesWater[]={0,0,0,0};
		colorMainCountlinesWater[]={0,0,0,0};
		colorPowerLines[]={0,0,0,0};
		colorRailWay[]={0,0,0,0};
		colorForestBorder[]={0,0,0,0};
		colorRocksBorder[]={0,0,0,0};
		colorNames[]={0,0,0,0};
		colorInactive[]={0,0,0,0};
		colorOutside[]={0,0,0,0};
		colorText[]={0,0,0,0};
		colorGrid[]={0,0,0,0};
		colorGridMap[]={0,0,0,0};
		colorTracks[]={0,0,0,0};
		colorTracksFill[]={0,0,0,0};
		colorRoads[]={0,0,0,0};
		colorRoadsFill[]={0,0,0,0};
		colorMainRoads[]={0,0,0,0};
		colorMainRoadsFill[]={0,0,0,0};
		ShowCountourInterval=0;
		shadow=0;
		text="";
		alphaFadeStartScale=0;
		alphaFadeEndScale=0;
		fontLabel="TahomaB";
		sizeExLabel=0;
		fontGrid="TahomaB";
		sizeExGrid=0;
		fontUnits="TahomaB";
		sizeExUnits=0;
		fontNames="TahomaB";
		sizeExNames=0;
		fontInfo="TahomaB";
		sizeExInfo=0;
		fontLevel="TahomaB";
		sizeExLevel=0;
		stickX[]=
		{
			0,
			
			{
				"Gamma",
				0,
				0
			}
		};
		stickY[]=
		{
			0,
			
			{
				"Gamma",
				0,
				0
			}
		};
		ptsPerSquareSea=10000;
		ptsPerSquareTxt=10000;
		ptsPerSquareCLn=10000;
		ptsPerSquareExp=10000;
		ptsPerSquareCost=10000;
		ptsPerSquareFor=10000;
		ptsPerSquareForEdge=10000;
		ptsPerSquareRoad=10000;
		ptsPerSquareObj=10000;
		widthRailWay=1;
		class Task
		{
			icon="";
			color[]={0,0,0,0};
			iconCreated="";
			colorCreated[]={0,0,0,0};
			iconCanceled="";
			colorCanceled[]={0,0,0,0};
			iconDone="";
			colorDone[]={0,0,0,0};
			iconFailed="";
			colorFailed[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class CustomMark
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Bunker
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Bush
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class BusStop
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Command
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Cross
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Fortress
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Fuelstation
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Fountain
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Hospital
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Chapel
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Church
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Lighthouse
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Quay
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Rock
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Ruin
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class SmallTree
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Stack
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Tree
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Tourism
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Transmitter
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class ViewTower
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Watertower
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Waypoint
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class WaypointCompleted
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class ActiveMarker
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class PowerSolar
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class PowerWave
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class PowerWind
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
		class Shipwreck
		{
			icon="";
			color[]={0,0,0,0};
			size=0;
			importance=0;
			coefMin=0;
			coefMax=0;
		};
	};
	class cTab_TAD_Map_Background: cTab_RscText
	{
		idc=1;
		x="(((359)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((371)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((1330)) / 2048  *  ( (0.86) * 3/4))";
		h="(((1345)) / 2048  *  ( (0.86)))";
		colorBackground[]={0,0,0,1};
	};
	class cTab_TAD_background: cTab_RscPicture
	{
		idc=1200;
		text="";
		x="(safeZoneX +  (0.05) * 3/4)";
		y="(safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="( (0.86) * 3/4)";
		h="( (0.86))";
	};
	class cTab_TAD_OSD_hookGrid: cTab_RscText_TAD
	{
		idc=2617;
		style=2;
		x="((((1384)) - (26) * 4) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (53) * 0.5 + (53) * 1) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 6) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_hookElevation: cTab_TAD_OSD_hookGrid
	{
		idc=2620;
		x="((((1384)) - (26) * 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (53) * 0.5 + (53) * 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 4) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_hookDir: cTab_TAD_OSD_hookGrid
	{
		idc=2618;
		x="((((1384)) - (26) * 6) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (53) * 0.5 + (53) * 0) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 8) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_hookToggleIconBackground: cTab_RscText_TAD
	{
		idc=2;
		x="((((24) + (359)) + (36) - (26)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((1023)) - (53)  / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_hookToggleIcon: cTab_TAD_upDownArrow
	{
		idc=3;
		x="((((24) + (359)) + (36) - (26)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((1023)) - (32) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_hookToggleText1: cTab_RscText_TAD
	{
		idc=2621;
		x="((((24) + (359)) + (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((1023)) - (53)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 4) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_hookToggleText2: cTab_TAD_OSD_hookToggleText1
	{
		idc=2626;
		y="((((1023))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_currentDirection: cTab_RscText_TAD
	{
		idc=2615;
		x="((((844)) - (26) * 4 / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((-(24) + (371) + (1345)) - (53) * 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 4) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_currentElevation: cTab_TAD_OSD_currentDirection
	{
		idc=2623;
		x="((((1202)) - (26) * 5 / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		w="(((26) * 5) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_centerMapText: cTab_RscText_TAD
	{
		idc=4;
		x="((((24) + (359)) + (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((836)) - (53) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 3) / 2048  *  ( (0.86) * 3/4))";
		text="CTR";
	};
	class cTab_TAD_loadingtxt: cTab_RscText_TAD
	{
		idc=1000;
		style=2;
		text="Loading";
		x="(((359)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((371)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((1330)) / 2048  *  ( (0.86) * 3/4))";
		h="(((1345)) / 2048  *  ( (0.86)))";
	};
	class cTab_TAD_OSD_cursor: cTab_RscPicture
	{
		idc=5;
		text="\a3\ui_f\data\IGUI\Cfg\WeaponCursors\cursoraimon_gs.paa";
		x="(((359) + (1330) / 2 - 128 / 33 * (48) / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((371) + (1345) / 2 - 128 / 33 * (48) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="((128 / 33 * (48)) / 2048  *  ( (0.86) * 3/4))";
		h="((128 / 33 * (48)) / 2048  *  ( (0.86)))";
		colorText[]=
		{
			"57/255",
			"255/255",
			"20/255",
			1
		};
	};
	class cTab_TAD_OSD_navModeOrScale: cTab_RscText_TAD
	{
		idc=2614;
		x="(((-(24) + (359) + (1330)) - (38) * 4) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((24) + (371))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((38) * 4) / 2048  *  ( (0.86) * 3/4))";
		h="(((82)) / 2048  *  ( (0.86)))";
		sizeEx="(((66)) / 2048  *  ( (0.86)))";
	};
	class cTab_TAD_OSD_modeTAD: cTab_RscText_TAD
	{
		idc=6;
		x="((((661)) - (26) * 3 / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((-(24) + (371) + (1345)) - (53)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 3) / 2048  *  ( (0.86) * 3/4))";
		colorText[]={0,0,0,1};
		colorBackground[]=
		{
			"57/255",
			"255/255",
			"20/255",
			1
		};
		text="TAD";
	};
	class cTab_TAD_OSD_txtToggleIconBg: cTab_RscText_TAD
	{
		idc=7;
		x="(((-(24) + (359) + (1330)) - (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (53) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_txtToggleIcon: cTab_TAD_upDownArrow
	{
		idc=8;
		x="(((-(24) + (359) + (1330)) - (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (32) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_txtToggleText1: cTab_RscText_TAD
	{
		idc=9;
		x="(((-(24) + (359) + (1330)) - (36) - (26) * 3) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398) - (53)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 3) / 2048  *  ( (0.86) * 3/4))";
		text="TXT";
	};
	class cTab_TAD_OSD_txtToggleText2: cTab_RscText_TAD
	{
		idc=2610;
		x="(((-(24) + (359) + (1330)) - (36) - (26) * 3) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((1398)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 3) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_time: cTab_RscText_TAD
	{
		idc=2613;
		x="((((24) + (359))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((-(24) + (371) + (1345)) - (53)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 5) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_currentGrid: cTab_RscText_TAD
	{
		idc=2612;
		x="((((1023)) - (26) * 6 / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((-(24) + (371) + (1345)) - (53) * 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 6) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_OSD_mapToggleIconBg: cTab_RscText_TAD
	{
		idc=10;
		x="((((24) + (359)) + (36) - (26)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((647)) - (53) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_mapToggleIcon: cTab_TAD_upDownArrow
	{
		idc=11;
		x="((((24) + (359)) + (36) - (26)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((647)) - (32) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
	};
	class cTab_TAD_OSD_mapToggleText1: cTab_RscText_TAD
	{
		idc=12;
		x="((((24) + (359)) + (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((647)) - (53)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 3) / 2048  *  ( (0.86) * 3/4))";
		text="MAP";
	};
	class cTab_TAD_OSD_mapToggleText2: cTab_RscText_TAD
	{
		idc=2611;
		x="((((24) + (359)) + (36)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((((647))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((26) * 4) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_movingHandle_T: cTab_RscText_TAD
	{
		idc=13;
		moving=1;
		colorBackground[]={0,0,0,0};
		x="((0) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="((0) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="((2048 ) / 2048  *  ( (0.86) * 3/4))";
		h="(((371)) / 2048  *  ( (0.86)))";
	};
	class cTab_TAD_movingHandle_B: cTab_TAD_movingHandle_T
	{
		idc=14;
		y="(((371) + (1345)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		h="((2048  - ((371) + (1345))) / 2048  *  ( (0.86)))";
	};
	class cTab_TAD_movingHandle_L: cTab_TAD_movingHandle_T
	{
		idc=15;
		y="(((371)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((359)) / 2048  *  ( (0.86) * 3/4))";
		h="(((1345)) / 2048  *  ( (0.86)))";
	};
	class cTab_TAD_movingHandle_R: cTab_TAD_movingHandle_L
	{
		idc=16;
		x="(((359) + (1330)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		w="((2048  - ((359) + (1330))) / 2048  *  ( (0.86) * 3/4))";
	};
	class cTab_TAD_brightness: cTab_RscText_TAD
	{
		idc=1005;
		x="(((359)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((371)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((1330)) / 2048  *  ( (0.86) * 3/4))";
		h="(((1345)) / 2048  *  ( (0.86)))";
		colorBackground[]={0,0,0,0};
	};
	class cTab_TAD_notification: cTab_RscText_TAD
	{
		idc=1620;
		x="(((359) + ((1330) * 0.2) / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
		y="(((-(24) + (371) + (1345)) - (53) * 3) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2)))";
		w="(((1330) * 0.8) / 2048  *  ( (0.86) * 3/4))";
		colorText[]=
		{
			0,
			0,
			"128/255",
			1
		};
		colorBackground[]={1,1,1,1};
	};
	class cTab_TAD_dsp
	{
		idd=1775134;
		movingEnable="true";
		duration=9.9999998e+010;
		fadeIn=0;
		fadeOut=0;
		onLoad="_this call cTab_fnc_onIfOpen;";
		class controlsBackground
		{
			class mapBackground: cTab_TAD_Map_Background
			{
			};
			class screen: cTab_TAD_RscMapControl
			{
				idc=1201;
				onDraw="nop = _this call cTabOnDrawbftTAD;";
				scaleDefault="missionNamespace getVariable 'cTabMapScale'";
				colorGrid[]={0.1,0.1,0.1,0};
				colorGridMap[]={0.1,0.1,0.1,0};
			};
			class screenTopo: screen
			{
				idc=1202;
				maxSatelliteAlpha=0;
			};
			class screenBlack: cTab_TAD_RscMapControl_BLACK
			{
				idc=1203;
				onDraw="nop = _this call cTabOnDrawbftTAD;";
				scaleDefault="missionNamespace getVariable 'cTabMapScale'";
				colorGrid[]={0.1,0.1,0.1,0};
				colorGridMap[]={0.1,0.1,0.1,0};
			};
		};
		class controls
		{
			class navModeOrScale: cTab_TAD_OSD_navModeOrScale
			{
				x="(((-(24) + (359) + (1330)) - (38) * 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (0.05) * 3/4))";
				w="(((38) * 2) / 2048  *  ( (0.86) * 3/4))";
			};
			class modeTAD: cTab_TAD_OSD_modeTAD
			{
			};
			class txtToggleIconBg: cTab_TAD_OSD_txtToggleIconBg
			{
			};
			class txtToggleIcon: cTab_TAD_OSD_txtToggleIcon
			{
			};
			class txtToggleText1: cTab_TAD_OSD_txtToggleText1
			{
			};
			class txtToggleText2: cTab_TAD_OSD_txtToggleText2
			{
			};
			class time: cTab_TAD_OSD_time
			{
			};
			class currentGrid: cTab_TAD_OSD_currentGrid
			{
			};
			class mapToggleIconBg: cTab_TAD_OSD_mapToggleIconBg
			{
			};
			class mapToggleIcon: cTab_TAD_OSD_mapToggleIcon
			{
			};
			class mapToggleText1: cTab_TAD_OSD_mapToggleText1
			{
			};
			class mapToggleText2: cTab_TAD_OSD_mapToggleText2
			{
			};
			class hookToggleIconBackground: cTab_TAD_OSD_hookToggleIconBackground
			{
			};
			class hookToggleIcon: cTab_TAD_OSD_hookToggleIcon
			{
			};
			class hookToggleText1: cTab_TAD_OSD_hookToggleText1
			{
			};
			class hookToggleText2: cTab_TAD_OSD_hookToggleText2
			{
			};
			class on_screen_currentDirection: cTab_TAD_OSD_currentDirection
			{
			};
			class on_screen_currentElevation: cTab_TAD_OSD_currentElevation
			{
			};
			class on_screen_centerMapText: cTab_TAD_OSD_centerMapText
			{
			};
			class notification: cTab_TAD_notification
			{
			};
			class loadingtxt: cTab_TAD_loadingtxt
			{
			};
			class brightness: cTab_TAD_brightness
			{
			};
			class background: cTab_TAD_background
			{
			};
		};
	};
	class cTab_microDAGR_header: cTab_RscPicture
	{
		idc=1;
		text="#(argb,8,8,3)color(0,0,0,1)";
		x="((573)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="((317)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="((942)) / 2048  *  ( (0.86) * 3/4)";
		h="((94)) / 2048  *  ( (0.86))";
	};
	class cTab_microDAGR_footer: cTab_microDAGR_header
	{
		idc=2;
		y="((317) + (1296) - ((94))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		h="(((94))) / 2048  *  ( (0.86))";
	};
	class cTab_RscButton_microDAGR_LeftUp: cTab_RscButtonInv
	{
		x="(373) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(400) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(26) / 2048  *  ( (0.86) * 3/4)";
		h="(171) / 2048  *  ( (0.86))";
	};
	class cTab_RscButton_microDAGR_LeftDown: cTab_RscButton_microDAGR_LeftUp
	{
		y="(571) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
	};
	class cTab_RscButton_microDAGR_LeftBtn: cTab_RscButtonInv
	{
		x="(368) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(829) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(31) / 2048  *  ( (0.86) * 3/4)";
		h="(184) / 2048  *  ( (0.86))";
	};
	class cTab_RscButton_microDAGR_RightUp: cTab_RscButton_microDAGR_LeftUp
	{
		x="(1689) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_RscButton_microDAGR_RightDown: cTab_RscButton_microDAGR_LeftDown
	{
		x="(1689) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_RscButton_microDAGR_RightBtn: cTab_RscButton_microDAGR_LeftBtn
	{
		x="(1689) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_RscText_microDAGR: cTab_RscText
	{
		style=2;
		w="((((942) - (24) * 4) / 3)) / 2048  *  ( (0.86) * 3/4)";
		h="(((94) - (24))) / 2048  *  ( (0.86))";
		font="EtelkaMonospacePro";
		colorText[]={1,1,1,1};
		sizeEx="((60)) / 2048  *  ( (0.86))";
		colorBackground[]={0,0,0,0};
		shadow=0;
	};
	class cTab_microDAGR_RscMapControl: cTab_RscMapControl
	{
		idc=1201;
		text="#(argb,8,8,3)color(1,1,1,1)";
		x="(((573))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(((317) + (94))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(((942))) / 2048  *  ( (0.86) * 3/4)";
		h="(((1296) - (94) - ((94)))) / 2048  *  ( (0.86))";
		scaleMax=1000;
		maxSatelliteAlpha=10000;
		alphaFadeStartScale=10;
		alphaFadeEndScale=10;
		ptsPerSquareSea="8 / (1)";
		ptsPerSquareTxt="8 / (1)";
		ptsPerSquareCLn="8 / (1)";
		ptsPerSquareExp="8 / (1)";
		ptsPerSquareCost="8 / (1)";
		ptsPerSquareFor="3 / (1)";
		ptsPerSquareForEdge="100 / (1)";
		ptsPerSquareRoad="1.5 / (1)";
		ptsPerSquareObj="4 / (1)";
		widthRailWay=1;
	};
	class cTab_microDAGR_background: cTab_RscPicture
	{
		idc=1200;
		text="";
		x="(safeZoneX +  (-0.05) * 3/4)";
		y="(safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="( (0.86) * 3/4)";
		h="( (0.86))";
	};
	class cTab_microDAGR_cursor: cTab_RscPicture
	{
		idc=3;
		text="\a3\ui_f\data\IGUI\Cfg\WeaponCursors\cursoraimon_gs.paa";
		x="((573) + (942) / 2 - 128 / 33 * (38) / 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="((317) + (1296) / 2 - 128 / 33 * (38) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(128 / 33 * (38)) / 2048  *  ( (0.86) * 3/4)";
		h="(128 / 33 * (38)) / 2048  *  ( (0.86))";
		colorText[]=
		{
			"57/255",
			"255/255",
			"20/255",
			1
		};
	};
	class cTab_microDAGR_btnF7: cTab_RscButton_microDAGR_LeftBtn
	{
		idc=4;
		tooltip="Center Map On Current Position (F7)";
	};
	class cTab_microDAGR_btnbrtpls: cTab_RscButton_microDAGR_RightUp
	{
		idc=1609;
		action="call cTab_fnc_txt_size_inc;";
		tooltip="Increase Font";
	};
	class cTab_microDAGR_btnbrtmns: cTab_RscButton_microDAGR_RightDown
	{
		idc=1610;
		action="call cTab_fnc_txt_size_dec;";
		tooltip="Decrease Font";
	};
	class cTab_microDAGR_btnfunction: cTab_RscButton_microDAGR_RightBtn
	{
		idc=1607;
		tooltip="Toggle Text on/off";
	};
	class cTab_microDAGR_btnMapType: cTab_RscButton_microDAGR_LeftUp
	{
		idc=5;
		tooltip="Toggle Map Type (F6)";
	};
	class cTab_microDAGR_btnMapTools: cTab_RscButton_microDAGR_LeftDown
	{
		idc=6;
		tooltip="Toggle Map Tools (F5)";
	};
	class cTab_microDAGR_on_screen_battery: cTab_RscPicture
	{
		idc=7;
		text="\cTab\img\icon_battery_ca.paa";
		x="((((24) + (573)))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(((24) + (317)) + (((94) - (24)) - (50)) / 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="((50)) / 2048  *  ( (0.86) * 3/4)";
		h="((50)) / 2048  *  ( (0.86))";
		colorText[]={1,1,1,1};
	};
	class cTab_microDAGR_on_screen_time: cTab_RscText_microDAGR
	{
		idc=2613;
		style=2;
		x="((((24) + (573)) + (24) + (((942) - (24) * 4) / 3))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(((24) + (317))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
	};
	class cTab_microDAGR_on_screen_signalStrength: cTab_microDAGR_on_screen_battery
	{
		idc=8;
		text="\cTab\img\icon_signalStrength_ca.paa";
		x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3)) + (((942) - (24) * 4) / 3) - (50) * 2) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		colorText[]={1,1,1,1};
	};
	class cTab_microDAGR_on_screen_satellite: cTab_microDAGR_on_screen_battery
	{
		idc=9;
		text="\a3\ui_f\data\map\Diary\signal_ca.paa";
		x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3)) + (((942) - (24) * 4) / 3) - (50)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		colorText[]={1,1,1,1};
	};
	class cTab_microDAGR_on_screen_dirDegree: cTab_RscText_microDAGR
	{
		idc=2615;
		style=0;
		y="((-((94)) + (317) + (1296))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		x="((((24) + (573)))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_microDAGR_on_screen_grid: cTab_microDAGR_on_screen_dirDegree
	{
		idc=2612;
		style=2;
		x="((((24) + (573)) + (24) + (((942) - (24) * 4) / 3))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_microDAGR_on_screen_dirOctant: cTab_microDAGR_on_screen_dirDegree
	{
		idc=2616;
		style=1;
		x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
	};
	class cTab_microDAGR_on_screen_hookGrid: cTab_RscText_microDAGR
	{
		idc=2617;
		style=2;
		x="(((-(24) + (573) + (942)) - (((942) - (24) * 4) / 3))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 4) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		colorText[]={1,1,1,0.5};
		colorBackground[]={0,0,0,0.25};
	};
	class cTab_microDAGR_on_screen_hookElevation: cTab_microDAGR_on_screen_hookGrid
	{
		idc=2620;
		y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 3) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
	};
	class cTab_microDAGR_on_screen_hookDst: cTab_microDAGR_on_screen_hookGrid
	{
		idc=2619;
		y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24)) * 2) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
	};
	class cTab_microDAGR_on_screen_hookDir: cTab_microDAGR_on_screen_hookGrid
	{
		idc=2618;
		y="((-((94)) + (317) + (1296)) - (24) - ((94) - (24))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
	};
	class cTab_microDAGR_loadingtxt: cTab_RscText_microDAGR
	{
		idc=1000;
		style=2;
		text="Loading";
		x="(((573))) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(((317) + (94))) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(((942))) / 2048  *  ( (0.86) * 3/4)";
		h="(((1296) - (94) - ((94)))) / 2048  *  ( (0.86))";
		colorBackground[]={0,0,0,0};
	};
	class cTab_microDAGR_movingHandle_T: cTab_RscText_microDAGR
	{
		idc=10;
		moving=1;
		colorBackground[]={0,0,0,0};
		x="(0) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="(0) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="(2048 ) / 2048  *  ( (0.86) * 3/4)";
		h="((317)) / 2048  *  ( (0.86))";
	};
	class cTab_microDAGR_movingHandle_B: cTab_microDAGR_movingHandle_T
	{
		idc=11;
		y="((317) + (1296)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		h="(2048  - ((317) + (1296))) / 2048  *  ( (0.86))";
	};
	class cTab_microDAGR_movingHandle_L: cTab_microDAGR_movingHandle_T
	{
		idc=12;
		y="((317)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="((573)) / 2048  *  ( (0.86) * 3/4)";
		h="((1296)) / 2048  *  ( (0.86))";
	};
	class cTab_microDAGR_movingHandle_R: cTab_microDAGR_movingHandle_L
	{
		idc=13;
		x="((573) + (942)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		w="(2048  - ((573) + (942))) / 2048  *  ( (0.86) * 3/4)";
	};
	class cTab_microDAGR_brightness: cTab_RscText_microDAGR
	{
		idc=1005;
		x="((573)) / 2048  *  ( (0.86) * 3/4) +  (safeZoneX +  (-0.05) * 3/4)";
		y="((317)) / 2048  *  ( (0.86)) +  (safeZoneY + safeZoneH -  (0.86) -  (0.2))";
		w="((942)) / 2048  *  ( (0.86) * 3/4)";
		h="((1296)) / 2048  *  ( (0.86))";
		colorBackground[]={0,0,0,0};
	};
	class cTab_microDAGR_dsp
	{
		idd=1776135;
		movingEnable="true";
		duration=9.9999998e+010;
		fadeIn=0;
		fadeOut=0;
		onLoad="_this call cTab_fnc_onIfOpen;";
		class controlsBackground
		{
			class screen: cTab_microDAGR_RscMapControl
			{
				onDraw="nop = _this call cTabOnDrawbftmicroDAGRdsp;";
				scaleDefault="missionNamespace getVariable 'cTabMapScale'";
			};
			class screenTopo: screen
			{
				idc=1202;
				maxSatelliteAlpha=0;
			};
		};
		class controls
		{
			class header: cTab_microDAGR_header
			{
			};
			class footer: cTab_microDAGR_footer
			{
			};
			class battery: cTab_microDAGR_on_screen_battery
			{
			};
			class time: cTab_microDAGR_on_screen_time
			{
			};
			class signalStrength: cTab_microDAGR_on_screen_signalStrength
			{
			};
			class satellite: cTab_microDAGR_on_screen_satellite
			{
			};
			class dirDegree: cTab_microDAGR_on_screen_dirDegree
			{
			};
			class grid: cTab_microDAGR_on_screen_grid
			{
			};
			class dirOctant: cTab_microDAGR_on_screen_dirOctant
			{
			};
			class loadingtxt: cTab_microDAGR_loadingtxt
			{
			};
			class brightness: cTab_microDAGR_brightness
			{
			};
			class background: cTab_microDAGR_background
			{
			};
		};
	};
	class cTab_RscText_Android: cTab_RscText
	{
		style=2;
		w="((((1098) - (20) * 6) / 5)) / 2048  *  (0.86)";
		h="(((60) - (20))) / 2048  *  ( (0.86) * 4/3)";
		font="EtelkaMonospacePro";
		colorText[]={1,1,1,1};
		sizeEx="((38)) / 2048  *  ( (0.86) * 4/3)";
		colorBackground[]={0,0,0,0};
		shadow=0;
	};
	class cTab_android_RscMapControl: cTab_RscMapControl
	{
		idc=1201;
		text="#(argb,8,8,3)color(1,1,1,1)";
		x="(((452))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(((713) + (60))) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(((1098))) / 2048  *  (0.86)";
		h="(((626) - (60) - (0))) / 2048  *  ( (0.86) * 4/3)";
		scaleMax=1000;
		scaleDefault="(missionNamespace getVariable 'cTabMapScale') * 0.86 / safezoneH";
		maxSatelliteAlpha=10000;
		alphaFadeStartScale=10;
		alphaFadeEndScale=10;
		ptsPerSquareSea="8 / (1)";
		ptsPerSquareTxt="8 / (1)";
		ptsPerSquareCLn="8 / (1)";
		ptsPerSquareExp="8 / (1)";
		ptsPerSquareCost="8 / (1)";
		ptsPerSquareFor="3 / (1)";
		ptsPerSquareForEdge="100 / (1)";
		ptsPerSquareRoad="1.5 / (1)";
		ptsPerSquareObj="4 / (1)";
		widthRailWay=1;
	};
	class cTab_android_background: cTab_RscPicture
	{
		idc=1200;
		text="";
		x="(safezoneX -  (0.86) * 0.17)";
		y="(safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(0.86)";
		h="( (0.86) * 4/3)";
	};
	class cTab_android_btnBack: cTab_RscButtonInv
	{
		x="(1550) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(806) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(102) / 2048  *  (0.86)";
		h="(102) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_btnMenu: cTab_android_btnBack
	{
		y="(1140) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_btnHome: cTab_android_btnBack
	{
		x="(1550) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(972) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_btnPower: cTab_RscButtonInv
	{
		x="(1583) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(1407) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(107) / 2048  *  (0.86)";
		h="(48) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_notificationLight
	{
		x="(360) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(834) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(35) / 2048  *  (0.86)";
		h="(35) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_header: cTab_RscPicture
	{
		idc=1;
		text="#(argb,8,8,3)color(0,0,0,1)";
		x="((452)) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((713)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="((1098)) / 2048  *  (0.86)";
		h="((60)) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_on_screen_battery: cTab_RscPicture
	{
		idc=2;
		text="\cTab\img\icon_battery_ca.paa";
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((713) + ((60) - (42)) / 2) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="((42)) / 2048  *  (0.86)";
		h="((42)) / 2048  *  ( (0.86) * 4/3)";
		colorText[]={1,1,1,1};
	};
	class cTab_android_on_screen_time: cTab_RscText_Android
	{
		idc=2613;
		style=2;
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (3 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((713) + ((60) - (38)) / 2) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_on_screen_signalStrength: cTab_android_on_screen_battery
	{
		idc=3;
		text="\cTab\img\icon_signalStrength_ca.paa";
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (5 - 1)) + (((1098) - (20) * 6) / 5) - (42) * 2) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		colorText[]={1,1,1,1};
	};
	class cTab_android_on_screen_satellite: cTab_android_on_screen_battery
	{
		idc=4;
		text="\a3\ui_f\data\map\Diary\signal_ca.paa";
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (5 - 1)) + (((1098) - (20) * 6) / 5) - (42)) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		colorText[]={1,1,1,1};
	};
	class cTab_android_on_screen_dirDegree: cTab_android_on_screen_time
	{
		idc=2615;
		style=0;
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (2 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
	};
	class cTab_android_on_screen_grid: cTab_android_on_screen_dirDegree
	{
		idc=2612;
		style=1;
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (4 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
	};
	class cTab_android_on_screen_dirOctant: cTab_android_on_screen_dirDegree
	{
		idc=2616;
		style=1;
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
	};
	class cTab_android_on_screen_hookGrid: cTab_RscText_Android
	{
		idc=2617;
		style=2;
		x="((((20) + (452)) + ((20) + (((1098) - (20) * 6) / 5)) * (1 - 1))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 4) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		colorText[]={1,1,1,0.5};
		colorBackground[]={0,0,0,0.25};
	};
	class cTab_android_on_screen_hookElevation: cTab_android_on_screen_hookGrid
	{
		idc=2620;
		y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 3) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_on_screen_hookDst: cTab_android_on_screen_hookGrid
	{
		idc=2619;
		y="((-(0) + (713) + (626)) - (20) - ((60) - (20)) * 2) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_on_screen_hookDir: cTab_android_on_screen_hookGrid
	{
		idc=2618;
		y="((-(0) + (713) + (626)) - (20) - ((60) - (20))) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
	};
	class cTab_android_loadingtxt: cTab_RscText_Android
	{
		idc=1000;
		style=2;
		text="Loading";
		x="(((452))) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(((713) + (60))) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(((1098))) / 2048  *  (0.86)";
		h="(((626) - (60) - (0))) / 2048  *  ( (0.86) * 4/3)";
		colorBackground[]={0.2,0.43099999,0.64700001,1};
	};
	class cTab_android_windowsBG: cTab_RscPicture
	{
		idc=1210;
		text="#(argb,8,8,3)color(0.2,0.431,0.647,1)";
		x="((452)) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((713)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="((1098)) / 2048  *  (0.86)";
		h="((626)) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_movingHandle_T: cTab_RscText_Android
	{
		idc=5;
		moving=1;
		colorBackground[]={0,0,0,0};
		x="(0) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(0) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(2048 ) / 2048  *  (0.86)";
		h="((713)) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_movingHandle_B: cTab_android_movingHandle_T
	{
		idc=6;
		y="((713) + (626)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		h="(2048  - ((713) + (626))) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_movingHandle_L: cTab_android_movingHandle_T
	{
		idc=7;
		y="((713)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="((452)) / 2048  *  (0.86)";
		h="((626)) / 2048  *  ( (0.86) * 4/3)";
	};
	class cTab_android_movingHandle_R: cTab_android_movingHandle_L
	{
		idc=8;
		x="((452) + (1098)) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		w="(2048  - ((452) + (1098))) / 2048  *  (0.86)";
	};
	class cTab_android_brightness: cTab_RscText_Android
	{
		idc=1005;
		x="((452)) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="((713)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="((1098)) / 2048  *  (0.86)";
		h="((626)) / 2048  *  ( (0.86) * 4/3)";
		colorBackground[]={0,0,0,0};
	};
	class cTab_android_notification: cTab_RscText_Android
	{
		idc=1620;
		x="(((452)) + (((1098)) * 0.2) / 2) / 2048  *  (0.86) +  (safezoneX -  (0.86) * 0.17)";
		y="(((713) + (60)) + ((626) - (60) - (0)) - 2 * (38)) / 2048  *  ( (0.86) * 4/3) +  (safezoneY + safezoneH * 0.88 -  ( (0.86) * 4/3) * 0.72)";
		w="(((1098)) * 0.8) / 2048  *  (0.86)";
		colorBackground[]={0,0,0,1};
	};
	class cTab_Android_dsp
	{
		idd=177383;
		duration=9.9999998e+010;
		fadeIn=0;
		fadeOut=0;
		onLoad="_this call cTab_fnc_onIfOpen;";
		objects[]={};
		class controlsBackground
		{
			class windowsBG: cTab_android_windowsBG
			{
			};
			class screen: cTab_android_RscMapControl
			{
				onDraw="nop = _this call cTabOnDrawbftAndroidDsp;";
			};
			class screenTopo: screen
			{
				idc=1202;
				maxSatelliteAlpha=0;
			};
		};
		class controls
		{
			class header: cTab_android_header
			{
			};
			class battery: cTab_android_on_screen_battery
			{
			};
			class time: cTab_android_on_screen_time
			{
			};
			class signalStrength: cTab_android_on_screen_signalStrength
			{
			};
			class satellite: cTab_android_on_screen_satellite
			{
			};
			class dirDegree: cTab_android_on_screen_dirDegree
			{
			};
			class grid: cTab_android_on_screen_grid
			{
			};
			class dirOctant: cTab_android_on_screen_dirOctant
			{
			};
			class notification: cTab_android_notification
			{
			};
			class loadingtxt: cTab_android_loadingtxt
			{
			};
			class brightness: cTab_android_brightness
			{
			};
			class background: cTab_android_background
			{
			};
		};
	};
};
class CfgVehicles
{
	class Box_NATO_WpsSpecial_F;
	class Box_cTab_items: Box_NATO_WpsSpecial_F
	{
		displayname="[cTab] Computer Gear";
		icon="iconCrateLarge";
		model="\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		scope=2;
		transportmaxmagazines=64;
		transportmaxweapons=12;
		class TransportItems
		{
			class _xx_ItemcTab
			{
				count=5;
				name="ItemcTab";
			};
			class _xx_ItemAndroid
			{
				count=15;
				name="ItemAndroid";
			};
			class _xx_ItemMicroDAGR
			{
				count=25;
				name="ItemMicroDAGR";
			};
			class _xx_ItemcTabHCam
			{
				count=25;
				name="ItemcTabHCam";
			};
		};
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
	};
};
class CfgSounds
{
	sounds[]={};
	class cTab_phoneVibrate
	{
		sound[]=
		{
			"\cTab\sounds\phoneVibrate.wss",
			1,
			1
		};
		titles[]={};
	};
	class cTab_mailSent
	{
		sound[]=
		{
			"\cTab\sounds\mailSent.wss",
			1,
			1
		};
		titles[]={};
	};
};
