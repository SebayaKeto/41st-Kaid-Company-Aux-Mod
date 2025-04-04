//Inspired by Indecisive Armoury Team
class CfgPatches
{
	class FST_774CX
	{
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
			"FST_774CX",
		};
	};
};
class Mode_SemiAuto;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{	
	class optic_lrps;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class WeaponSlotsInfo;
	class FST_773Firepuncher;
	class FST_774CX: FST_773Firepuncher
	{
		author="Gold";
		displayName="[41st] 774-CX marksman rifle";
		baseWeapon="FST_774CX";
		descriptionShort="Long range, high power.";
		picture="Indecisive_Armoury_Weapons_IMPERIAL\Data\774CX\774CX_ui.paa";
		model="\Indecisive_Armoury_Weapons_IMPERIAL\Data\774CX\Model\IDA_774CX.p3d";
		reloadAction="GestureReloadTrgUGL";
		recoil="FST_recoil_dc15a";
		magazines[]=
		{
			"FST_blaster_cell_LE_Blue",
			"FST_blaster_cell_LE_Green",
			"FST_blaster_cell_LE_Yellow",
			"FST_blaster_cell_LE_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
		};
		muzzles[]=
		{
			"this",
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"FST_Muzzle_774CX"
				};
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
		class LinkedItems
		{
			class LinkedItemsMuzzle
			{
				slot="MuzzleSlot";
				item="FST_Muzzle_774CX";
			};
		};
	};
	class InventoryMuzzleItem_Base_F;
	class FST_Muzzle_774CX: ItemCore
	{
		author="Inspired by 3as Studio";
		_generalMacro="muzzle_snds_H";
		htMin=1;
		htMax=600;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		scope=2;
		displayName="[41st] 774CX Muzzle";
		picture="\a3\Weapons_F\acc\Data\UI\icon_muzzle_snds_H_ca.paa";
		model="";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=10;
			class MagazineCoef
			{
				initSpeed=1.25;
			};
			class AmmoCoef
			{
				hit=1;
				typicalSpeed=1;
				airFriction=1;
				visibleFire=1;
				audibleFire=1;
				visibleFireTime=1;
				audibleFireTime=1;
				cost=1;
			};
			soundTypeIndex=0;
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
			class MuzzleCoef
			{
				dispersionCoef=0.80000001;
				artilleryDispersionCoef=1;
				fireLightCoef=1;
				recoilCoef=1;
				recoilProneCoef=1;
				minRangeCoef=1;
				minRangeProbabCoef=1;
				midRangeCoef=1;
				midRangeProbabCoef=1;
				maxRangeCoef=1;
				maxRangeProbabCoef=1;
			};
		};
		inertia=0.2;
	};
};