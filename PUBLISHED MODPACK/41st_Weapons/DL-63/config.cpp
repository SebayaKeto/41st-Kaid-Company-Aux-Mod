//Inspired by Indecisive Armoury Team
class CfgPatches
{
	class FST_DL63
	{
		author="Gold";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]=
		{
			"FST_DL63",
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{	
	class WeaponSlotsInfo;
	class IDA_DL63;
	class FST_DL63: IDA_DL63
	{
		author="Gold";
		displayName="[41st] DL-63 Blaster rifle";
		baseWeapon="FST_DL63";
		descriptionShort="Long range, high power.";
		picture="Indecisive_Armoury_Weapons_IMPERIAL\Data\DL63\DL63_ui.paa";
		model="\Indecisive_Armoury_Weapons_IMPERIAL\Data\DL63\Model\IDA_DL63.p3d";
		scope=2;
        scopeArsenal = 2;
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red",
		};
		magazineWell[]={};
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_1.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15a";
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Single",
			"Auto"
		};
		fireLightDiffuse[]={1,0,0};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.15;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class Auto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\Imperial\E11.ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.15;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
				iconPicture="";
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
            {
                compatibleItems[]=
                {
                    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White",
                };
            };
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
};