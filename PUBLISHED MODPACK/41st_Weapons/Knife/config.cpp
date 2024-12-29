class CfgPatches
{
	class FST_Stab
	{
		units[]={};
		weapons[]=
		{
			"FST_Knife"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"WBK_MeleeMechanics"
		};
	};
};
class CfgWeapons
{
	class InventoryMuzzleItem_Base_F;
	class muzzle_snds_H;
	class FST_Knife: muzzle_snds_H
	{
		displayName="[41st] Knife";
		scope=2;
		author="Daara";
		model="41st_Weapons\Knife\Data\41st_Knife.p3d";
		picture="41st_Weapons\Knife\Data\switchblade.paa";
		IMS_Bayonet_Item="true";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=2;
			class MagazineCoef
			{
				initSpeed=1.01;
			};
			class AmmoCoef
			{
				hit=1;
				visibleFire=0.2;
				audibleFire=0.40000001;
				visibleFireTime=0.5;
				audibleFireTime=1;
				cost=1;
				typicalSpeed=1;
				airFriction=1;
			};
			class MuzzleCoef
			{
				dispersionCoef="0.8f";
				artilleryDispersionCoef="1.0f";
				fireLightCoef="0.1f";
				recoilCoef="1.0f";
				recoilProneCoef="1.0f";
				minRangeCoef="1.0f";
				minRangeProbabCoef="1.0f";
				midRangeCoef="1.0f";
				midRangeProbabCoef="1.0f";
				maxRangeCoef="1.0f";
				maxRangeProbabCoef="1.0f";
			};
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
			soundTypeIndex=0;
			inertia=0.2;
		};
	};
};
