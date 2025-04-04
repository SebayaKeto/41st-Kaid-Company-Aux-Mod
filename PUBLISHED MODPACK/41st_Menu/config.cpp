class CfgPatches
{
	class mainmenu
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "OPTRE_Core", "A3_Data_F_Enoch_Loadorder" };
	};
};

class CfgWorlds
{
	class CAWorld;
	class VR : CAWorld
	{
		cutscenes[] = { "OPTRE_Intro1" }; // Class names of used scenes. When more than one is present, the system will pick one randomly.
	};
	class Altis : CAWorld {
		cutscenes[] = {"OPTRE_Intro1"};
	};
	
	class Stratis : CAWorld {
		cutscenes[] = {"OPTRE_Intro1"};
	};

	class Enoch : CAWorld {
		cutscenes[] = {"OPTRE_Intro1"};
	};

	initWorld = "VR";
	demoWorld = "VR";
};

class CfgMissions
{
	class Cutscenes
	{
		class OPTRE_Intro1 // Class referenced in 'cutscenes' property in CfgWorlds
		{
			directory = "41st_Menu\mainmenu.vr"; // Path to scenario with the scene
		};
	};
};

class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenu;
class RscButtonMenuMain;
class RscText;
class RscVignette;
class RscDisplayGetReady;
class RscActiveText;
class RscListBox;
class RscListNBox;
class RscCombo;
class RscXListBox;
class RscHTML;
class RscPictureKeepAspect;
class RscActivePicture;
class RscMapControl;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscFrame;
class RscTitle;
class CA_Title;
class RscDebugConsole;
class RscTrafficLight;
class RscFeedback;
class RscMessageBox;
class RscControlsGroup;
class RscTextCheckbox;
class RscDisplayInventory_DLCTemplate;
class RscEdit;
class RscCheckBox;
class RscIGProgress;
class RscHitZones;
class RscVehicleToggles;
class RscIGUIText;
class RscIGUIValue;
class RscOpticsValue;
class RscOpticsText;
class Scrollbar;
class RscIGUIShortcutButton;
class RscActivePictureKeepAspect;
class RscTree;
class RscXSliderH;
class RscBackgroundGUI;
class RscBackgroundGUILeft;
class RscBackgroundGUIRight;
class RscBackgroundGUIBottom;
class RscBackgroundGUITop;
class RscBackgroundGUIDark;
class RscButtonMenuSteam;
class RscButtonTextOnly;
class RscStandardDisplay;
class RscPicture;
class RscButton;
class RscDisplayMain: RscStandardDisplay
{
	idd=0;
	scriptName="RscDisplayMain";
	scriptPath="GUI";
	onLoad="[""onLoad"",_this,""RscDisplayMain"",'GUI'] call  (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscDisplayMain"",'GUI'] call  (uinamespace getvariable 'BIS_fnc_initDisplay')";
	delete Spotlight;
	class ControlsBackground
	{
		class Vignette: RscVignette
		{
		};
		class MouseArea: RscText
		{
			idc=999;
			style=16;
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class BackgroundLeft: RscText
		{
			colorBackground[]={0.1,0.1,0.1,1};
			x="- 10";
			y="- 10";
			w="safezoneX +  10";
			h="2 *  10";
			text="";
		};
		class BackgroundRight: BackgroundLeft
		{
			x="safezoneX + safezoneW";
			w=10;
		};
		class Picture: RscPicture
		{
			idc=102;
			text="";
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="safezoneW * 1.1";
			h="safezoneH * 1.1";
		};
	};
	class Controls
	{
		class infomods:RscControlsgroupNoHScrollbars {
            show=0;
        };
        class infoDLCsOwned:infomods {
            show=0;
        };
        class infoDLCs:infoDLCsOwned {
            show=0;
        };
        class infoNews:infomods {
            show=0;
        };
        class infoVersion:infoNews {
            show=0;
        };
		delete ModIcons;
		delete B_Quit;
		delete B_Expansions;
		delete B_Credits;
		delete B_Player;
		delete B_Options;
		delete B_SinglePlayer;
		delete B_MultiPlayer;
		delete B_SingleMission;
		delete B_Campaign;
		delete Date;
		delete ModList;
		delete TrafficLight;
		delete Version;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete SpotlightBase;
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		class SpotlightPrev: RscActivePictureKeepAspect
		{
			idc=1060;
			text="";
			color[]={1,1,1,0};
			fade=1;
			x="0";
			y="0";
			w="0";
			h="0";
		};
		class SpotlightNext: SpotlightPrev
		{
			idc=1061;
			text="";
			y="0";
			angle=180;
		};
		class BackgroundBar: RscText
		{
			colorBackground[]={0,0,0,0.75};
			x="safezoneX";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="safezoneW";
			h="2 * (pixelH * pixelGrid * 2)";
		};
		class BackgroundCenter: BackgroundBar
		{
			colorBackground[]={0,0,0,0};
			x="0.5 - 2 *   2 *  (pixelW * pixelGrid * 2)";
			w="4 *   2 *  (pixelW * pixelGrid * 2)";
		};
		class BackgroundBarLeft: RscPicture
		{
			text="\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\gradientMods_ca.paa";
			colorText[]={0,0,0,0};
			angle=180;
			x="0.5 - 4 *   2 *  (pixelW * pixelGrid * 2)";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="2 *   2 *  (pixelW * pixelGrid * 2)";
			h="2 *  (pixelH * pixelGrid * 2)";
		};
		class BackgroundBarRight: BackgroundBarLeft
		{
			angle=0;
			x="0.5 + 2 *   2 *  (pixelW * pixelGrid * 2)";
		};
		delete LogoApex;
		class News
		{
			x="2.5";
		};
		class Logo: RscActivePicture
		{
			text="41st_Menu\mainmenu.vr\images\logo.paa";
			tooltip="";
			color[]={1,1,1,1};
			//colorActive[]={0.69999999,0.69999999,0.69999999,1};
			shadow=1;
			x="0.5 -  5 *  (pixelW * pixelGrid * 2)";
			y="safezoneY + (3 - 0.5 *  5) *  (pixelH * pixelGrid * 2)";
			w="2 *  5 *  (pixelW * pixelGrid * 2)";
			h="1 *  5 *  (pixelH * pixelGrid * 2)";
			onButtonClick = "";
			//onButtonClick="if (scriptdone (missionnamespace getvariable ['RscDisplayMain_credits',scriptnull])) then {RscDisplayMain_credits = _this spawn (uinamespace getvariable 'CRP_fnc_credits');};";
			onSetFocus="(_this select 0) ctrlsettextcolor [1,1,1,1];";
			onKillFocus="(_this select 0) ctrlsettextcolor [0.9,0.9,0.9,1];";
			onLoad="";
		};
		class TitleSingleplayer: RscButtonMenu
		{
			idc=1011;
			text="$STR_A3_RscDisplayMain_TitleSingleplayer_text";
			size="1.25 *  (pixelH * pixelGrid * 2)";
			style="0x02 + 0xC0";
			colorBackground[]={0,0,0,0};
			colorBackground2[]={1,1,1,1};
			class Attributes
			{
				align="center";
				color="#ffffff";
				font="PuristaLight";
				shadow=0;
				size=1;
			};
			class TextPos
			{
				left="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				top="0.18 *   2 *  (pixelH * pixelGrid * 2)";
				right="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				bottom="0.18 *   2 *  (pixelH * pixelGrid * 2)";
			};
			x="2.8";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="2 *  (pixelH * pixelGrid * 2)";
		};
		class GroupSingleplayer: RscControlsGroupNoScrollbars
		{
			idc=1001;
			x="2.8";
			y="safezoneY + (2 +   2) *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="(0 *  1.5) *  (pixelH * pixelGrid * 2)";
			class Controls
			{
				class Campaigns: RscButtonMenuMain
				{
					idc=101;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonCampaign";
					tooltip="$STR_TOOLTIP_MAIN_CAMPAIGN";
					x=0;
					y="(0) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
					onbuttonclick="uinamespace setvariable ['RscDisplayCampaignLoad_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONCAMPAIGN')];";
				};
				class Showcases: Campaigns
				{
					idc=150;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonShowcases";
					tooltip="$STR_TOOLTIP_MAIN_SHOWCASES";
					y="(1 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick="uinamespace setvariable ['RscDisplaySingleMission_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONSHOWCASES')];";
				};
				class Challenges: Campaigns
				{
					idc=151;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonChallenges";
					tooltip="$STR_A3_RscDisplayMain_ButtonChallenges_tooltip";
					y="(2 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick="uinamespace setvariable ['RscDisplaySingleMission_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONCHALLENGES')];";
				};
				class Scenarios: Campaigns
				{
					idc=103;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonScenarios";
					tooltip="$STR_TOOLTIP_MAIN_SCENARIOS";
					y="(3 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick="uinamespace setvariable ['RscDisplaySingleMission_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONSCENARIOS')];";
				};
				class Editor: Campaigns
				{
					idc=142;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonEditor";
					tooltip="$STR_TOOLTIP_SINGLEPLAYER_EDITOR_A3";
					y="(4 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick="";
				};
			};
		};
		class TitleMultiplayer: RscButtonMenu
		{
			idc=1012;
			text="Play";
			size="1.25 *  (pixelH * pixelGrid * 2)";
			style="0x02 + 0xC0";
			colorBackground[]={0,0,0,0};
			colorBackground2[]={1,1,1,1};
			class Attributes
			{
				align="center";
				color="#ffffff";
				font="RobotoCondensedBold";
				shadow=0;
				size=1;
			};
			class TextPos
			{
				left="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				top="0.18 *   2 *  (pixelH * pixelGrid * 2)";
				right="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				bottom="0.18 *   2 *  (pixelH * pixelGrid * 2)";
			};
			x="0.5 - ( 5 +  10) *  (pixelW * pixelGrid * 2)";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="2 *  (pixelH * pixelGrid * 2)";
		};
		class GroupMultiplayer: RscControlsGroupNoScrollbars
		{
			idc = 1002;
			x = "0.5 - ( 5 +  10) *  (pixelW * pixelGrid * 2)";
			y = "safezoneY + (2 + 2) *  (pixelH * pixelGrid * 2)";
			w = "10 *  (pixelW * pixelGrid * 2)";
			h = "(6 *  1.5) *  (pixelH * pixelGrid * 2)";
			class Controls
			{
				class QuickPlay: RscButtonMenuMain
				{
					idc = 154;
					colorBackground[] = {0,0,0,0.75};
					colorBackgroundActive[] = {1,1,1,0.5};
					text = "41st Main Server";
					tooltip = "Connect to the MAIN Server";
					onbuttonclick = "0 = connectToServer ['69.67.175.24', 2302, '41'];";
					x = 0;
					y = "(0 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w = "10 *  (pixelW * pixelGrid * 2)";
					h = "1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
				class Arsenal: QuickPlay
				{
					idc = 203;
					colorBackground[] = {0,0,0,0.75};
					colorBackgroundActive[] = {1,1,1,0.5};
					text = "41st Training Server";
					tooltip = "Connect to the TRAINING Server";
					onbuttonclick = "0 = connectToServer ['69.67.175.24', 2328, '41'];";
					y = "(1 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
				};
				class ConnectToLibServer: QuickPlay
				{
					idc = 204;
					colorBackground[] = {0,0,0,0.75};
					colorBackgroundActive[] = {1,1,1,0.5};
					text = "41st Liberation Server";
					tooltip = "Connect to the LIBERATION Server";
					onbuttonclick = "0 = connectToServer ['69.67.175.24', 2310, '41'];";
					y = "(2 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
				};
				class ace_arsenal_mission: QuickPlay
				{
					idc = -1;
					text = "ACE ARSENAL";
					tooltip = "$STR_ace_arsenal_Mission_tooltip";
					y = "(3 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick = "playMission ['', '\z\ace\addons\arsenal\missions\Arsenal.VR']";
					animTextureNormal = "\z\ace\addons\arsenal\data\buttonMissionMainMenu_ca.paa";
					animTextureDisabled = "\z\ace\addons\arsenal\data\buttonMissionMainMenu_ca.paa";
					animTextureOver = "\z\ace\addons\arsenal\data\buttonMissionMainMenuHover_ca.paa";
					animTextureFocused = "\z\ace\addons\arsenal\data\buttonMissionMainMenuHover_ca.paa";
					animTexturePressed = "\z\ace\addons\arsenal\data\buttonMissionMainMenu_ca.paa";
					animTextureDefault = "\z\ace\addons\arsenal\data\buttonMissionMainMenu_ca.paa";
				};
				class ServerBrowser: QuickPlay
				{
					idc = 105;
					text = "$STR_A3_RscDisplayMain_GroupMultiplayer_ServerBrowser_text";
					tooltip = "";
					y = "(4 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick = "";
				};
				class Editor: QuickPlay
				{
					idc = 142;
					colorBackground[] = {0,0,0,0.75};
					colorBackgroundActive[] = {1,1,1,0.5};
					text = "$STR_A3_RscDisplayMain_ButtonEditor";
					tooltip = "$STR_TOOLTIP_SINGLEPLAYER_EDITOR_A3";
					y = "(5 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick = "";
				};
			};
		};
		delete TitleTutorials;
		delete TitleIconTutorials;
		//delete GroupTutorials;
		class TitleOptions: RscButtonMenu
		{
			idc=1014;
			text="$STR_A3_RscDisplayMain_TitleOptions_text";
			size="1.25 *  (pixelH * pixelGrid * 2)";
			style="0x02 + 0xC0";
			colorBackground[]={0,0,0,0};
			colorBackground2[]={1,1,1,1};
			class Attributes
			{
				align="center";
				color="#ffffff";
				font="RobotoCondensedBold";
				shadow=0;
				size=1;
			};
			class TextPos
			{
				left="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				top="0.18 *   2 *  (pixelH * pixelGrid * 2)";
				right="0.1 *   2 *  (pixelW * pixelGrid * 2)";
				bottom="0.18 *   2 *  (pixelH * pixelGrid * 2)";
			};
			x="0.5 + ( 5) *  (pixelW * pixelGrid * 2)";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="2 *  (pixelH * pixelGrid * 2)";
		};
		class GroupOptions: RscControlsGroupNoScrollbars
		{
			idc=1004;
			x="0.5 + ( 5) *  (pixelW * pixelGrid * 2)";
			y="safezoneY + (2 +   2) *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="(4 *  1.5) *  (pixelH * pixelGrid * 2)";
			class Controls
			{
				class Video: RscButtonMenuMain
				{
					idc=301;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonVideo";
					tooltip="$STR_TOOLTIP_MAIN_VIDEO";
					onbuttonclick="";
					x=0;
					y="(0 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
				class Audio: RscButtonMenuMain
				{
					idc=302;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonAudio";
					tooltip="$STR_TOOLTIP_MAIN_AUDIO";
					onbuttonclick="";
					x=0;
					y="(1 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
				class Controls: RscButtonMenuMain
				{
					idc=303;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonControls";
					tooltip="$STR_TOOLTIP_MAIN_CONTROLS";
					onbuttonclick="";
					x=0;
					y="(2 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
				class Game: RscButtonMenuMain
				{
					idc=307;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					text="$STR_A3_RscDisplayMain_ButtonGame";
					tooltip="$STR_TOOLTIP_MAIN_GAME";
					onbuttonclick="";
					x=0;
					y="(3 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
				class Expansions: RscButtonMenuMain
				{
					idc=140;
					text="$STR_A3_RscDisplayMain_ButtonExpansions";
					tooltip="$STR_TOOLTIP_MAIN_EXPANSIONS";
					onbuttonclick="";
					x=0;
					y="(15 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					w="10 *  (pixelW * pixelGrid * 2)";
					h="1.5 *  (pixelH * pixelGrid * 2) -  (pixelH)";
				};
			};
		};
		class GroupSession: RscControlsGroupNoScrollbars
		{
			idc=1005;
			x="safezoneX + safezoneW - ( 10 +   2) *  (pixelW * pixelGrid * 2) -  (pixelW)";
			y="safezoneY + (2 +   2) *  (pixelH * pixelGrid * 2)";
			w="10 *  (pixelW * pixelGrid * 2)";
			h="(4 *  1.5) *  (pixelH * pixelGrid * 2)";
			class Controls
			{
				class Profile: RscButtonMenuMain
				{
					idc=109;
					colorBackground[]={0,0,0,0.75};
					colorBackgroundActive[]={1,1,1,0.5};
					style=0;
					tooltip="$STR_TOOLTIP_MAIN_PLAYER";
					w="10 *  (pixelW * pixelGrid * 2)";
					y="(0 *  1.5) *  (pixelH * pixelGrid * 2) +  (pixelH)";
					onbuttonclick="";
					class Attributes
					{
						align="Center";
						color="#ffffff";
						font="RobotoCondensed";
					};
				};
				delete Unit;
			};
		};
		class Exit: RscButton
		{
			idc=106;
			colorBackground[]={0,0,0,0.2};
			text="\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\exit_ca.paa";
			tooltip="$STR_TOOLTIP_MAIN_EXIT";
			style=48;
			colorText[]={1,1,1,1};
			colorBackgroundActive[]={0.78431398,0.137255,0.062745102,1};
			colorFocused[]={1,1,1,1};
			x="safezoneX + safezoneW -   2 *  (pixelW * pixelGrid * 2)";
			y="safezoneY + 2 *  (pixelH * pixelGrid * 2)";
			w="2 *  (pixelW * pixelGrid * 2)";
			h="2 *  (pixelH * pixelGrid * 2)";
			onMouseEnter="(_this select 0) ctrlsettextcolor [1,1,1,1];";
			onSetFocus="(_this select 0) ctrlsettextcolor [1,1,1,1];";
			onMouseExit="(_this select 0) ctrlsettextcolor [1,1,1,0.5];";
			onKillFocus="(_this select 0) ctrlsettextcolor [1,1,1,0.5];";
		};
		class Footer: RscText
		{
			text="Welcome to 41st Elite Corps, Kaid Co.";
			style=2;
			sizeEx="1.2 *  (pixelH * pixelGrid * 2)";
			shadow=0;
			font="RobotoCondensedBold";
			colorText[]={1,1,1,1};
			colorBackground[]={0,0,0,0.75};
			x="safezoneX";
			y="safezoneY + safezoneH - 2 *  1 *  (pixelH * pixelGrid * 2)";
			w="safezoneW";
			h="(2) *  (pixelH * pixelGrid * 2)";
		};
		delete AllMissions;
		delete ProofsOfConcept;
	};
};