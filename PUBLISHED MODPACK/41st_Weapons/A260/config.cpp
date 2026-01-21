class CfgPatches
{
	class FST_A260
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"JLTS_weapons_DC15S",
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_A260",
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CowsSlot;
class MuzzleSlot;
class UnderBarrelSlot;
class PointerSlot;
class WeaponSlotsInfo;
class CfgWeapons
{
	class IDA_A260;
	class FST_A260: IDA_A260
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] A260 carbine";
		descriptionShort="Close range, fast rate of fire.";
		reloadAction="GestureReloadSMG_01";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15s";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (3).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (2).ogg",
					1.5,
					1,
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
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
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
			minRange=75;
			minRangeProbab=0.6;
			midRange=200;
			midRangeProbab=0.5;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class FullAuto: Mode_FullAuto
		{
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
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (3).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177 (2).ogg",
					1.5,
					1,
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
					"\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
					1.5,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0.00145;
			minRange=1;
			minRangeProbab=0.7;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
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