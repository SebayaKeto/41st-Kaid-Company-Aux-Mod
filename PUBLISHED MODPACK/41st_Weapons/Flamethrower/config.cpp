class CfgPatches
{
	class FST_Pyro
	{
		author="Daara";
		name="THE FLAMETHROWER";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies",
			"JLTS_weapons_Grenades",
			"JLTS_weapons_Core",
			"JLTS_weapons_Reloads"
		};
		units[]={};
		weapons[]=
		{
			"FST_BTX42",
		};
		magazines[]=
		{
		};
	};
};
class SmallFire;
class FST_FireEffect: SmallFire
{
	class Light1
	{
		simulation="light";
		type="IDA_FireEffectLight";
	};
	class sound
	{
		simulation="sound";
		type="Fire";
	};
	class Fire1
	{
		simulation="particles";
		type="SmallFireF";
	};
	class Refract1
	{
		simulation="particles";
		type="SmallFireFRefract";
	};
	class Smoke1
	{
		simulation="particles";
		type="ImpactSmoke";
		lifeTime=0.2;
	};
};
class CfgLights
{
	class FST_FireEffectLight
	{
		name="FireEffectLight";
		diffuse[]={255,137,0};
		color[]={255,137,0};
		ambient[]={0,0,0,0.5};
		intensity=2500;
		blinking=0;
		drawLight=0;
		dayLight=1;
		class Attenuation
		{
			start=0;
			constant=3;
			linear=0;
			quadratic=32;
		};
		position[]={0,0.5,0};
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_BTX42: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
        ace_overheating_slowdownFactor=0;
        ace_overheating_allowSwapBarrel=0;
        ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
        ace_overheating_barrelMass=1;
		author="Daara";
		inertia=0;
		scope=2;
		autoReload=true;
		baseWeapon="FST_BTX42";
		displayName="[41st] BT X-42 Flamethrower";
		displayNameShort="BT X-42 Flamethrower";
		descriptionShort="For Freezer, Merry Christmas";
		picture="3AS\3AS_Weapons\X42\Data\BTX42_ui_ca.paa";
		model="3AS\3AS_Weapons\X42\BX42.p3d";
/* 		WBK_BurnEm_IsFlamethrower="True";
		WBK_BurnEm_RequiredBackpack="DBA_JLTS_Breathmask_Backpack";
		WBK_BurnEm_FlamethrowerSoundArray="['flamethrower_start','flamethrower_looping',4.8,'flamethrower_end']";
		WBK_BurnEm_FlamethrowerParticlePos="[[-0.32,0.3,-0.3],'leftHand']";
		WBK_BurnEm_FlamethrowerDistance=32.5; */
		magazines[]=
		{
			"m2_Fuel_Tank",
			"FST_FuelTank"
		};
		recoil="";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3AS\3AS_Weapons\Data\Anim\BX42.rtm"
		};
		reloadAction="";
		ace_clearJamAction=""; 
		magazineWell[]={};
		fireLightDiffuse[]={1,1,0};
		drySound[]=
		{
			"MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
			5,
			1,
			10
		};
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_SW\Sounds\blaster_reload_4.ogg",
			1.5,
			1,
			100
		};
		muzzles[]=
		{
			"this",
		};
		modes[]=
		{
			"FullAuto",
		};
		class FullAuto: Mode_FullAuto
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
					"3AS\3AS_Weapons\X42\SFX\flamer.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"3AS\3AS_Weapons\X42\SFX\flamer.ogg",
					1,
					1,
					1800
				};
				begin3[]=
				{
					"3AS\3AS_Weapons\X42\SFX\flamer.ogg",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
			};
			soundContinuous=1;
			reloadTime=0.08;
			recoil="recoil_auto_mx";
			recoilProne="recoil_auto_prone_mx";
			dispersion=0.00073000003;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
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
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
};