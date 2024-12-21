class CfgPatches
{
	class FST_Weapons_Valken
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15X",
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgAmmo
{
	class FST_blasterbolt;
	class FST_blasterbolt_Overcharged: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=100;
		caliber=2.2;
		coefGravity=1;
		ACE_ammoTempMuzzleVelocityShifts="[-26.55,-25.47,-22.85,-20.12,-16.98,-12.8,-7.64,-1.53,5.96,15.17,26.19]";
		ACE_ballisticCoefficients="[0.317]";
		ACE_barrelLengths="[254,406.4,508,609.6,660.4]";
		ACE_bulletLength=36.220001;
		ACE_bulletMass=9.0719995;
		ACE_caliber=6.7059999;
		ACE_dragModel=7;
		ACE_muzzleVelocities="[500]";
		ACE_muzzleVelocityVariationSD=0;
		ACE_standardAtmosphere="ICAO";
		ACE_velocityBoundaries="[]";
	};
	class FST_blasterbolt_Overcharged_red: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		hit=100;
		caliber=2;
		coefGravity=1;
		ACE_ammoTempMuzzleVelocityShifts="[-26.55,-25.47,-22.85,-20.12,-16.98,-12.8,-7.64,-1.53,5.96,15.17,26.19]";
		ACE_ballisticCoefficients="[0.317]";
		ACE_barrelLengths="[254,406.4,508,609.6,660.4]";
		ACE_bulletLength=36.220001;
		ACE_bulletMass=9.0719995;
		ACE_caliber=6.7059999;
		ACE_dragModel=7;
		ACE_muzzleVelocities="[500]";
		ACE_muzzleVelocityVariationSD=0;
		ACE_standardAtmosphere="ICAO";
		ACE_velocityBoundaries="[]";
	};
};
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class FST_blaster_cell_Overcharged: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=10;
		displayName="[41st] Overcharged High-Power Energy Cell";
		displayNameShort="O/HP Energy Cell";
		descriptionShort="10 round capacity.";
		ammo="FST_blasterbolt_Overcharged";
		tracersEvery=1;
		initSpeed=800;
		mass=10;
	};
	class FST_blaster_cell_Overcharged_Red: FST_blaster_cell_Overcharged
	{
		author="Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		displayName="[41st] Overcharged High-Power Energy Cell (Red)";
		ammo="FST_blasterbolt_Overcharged_Red";
	};
};
class CfgWeapons
{
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_DC15X: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		displayName="[41st] DC-15X Sniper Rifle";
		descriptionShort="Extreme range, high power.";
		picture="\MRC\JLTS\weapons\DC15X\data\ui\DC15X_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15X\DC15X.p3d";
		baseWeapon="FST_DC15X";
		ACE_barrelLength=730;
		ACE_barrelTwist=381;
		initSpeed=-1;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DC15X\data\DC15X_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\DC15X\anims\DC15X_handanim.rtm"
		};
		magazines[]=
		{
			"FST_blaster_cell_Overcharged",
		};
		magazineWell[]={};
		ace_clearJamAction="";
		reloadAction="GestureReload_JLTS_DC15S";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15x";
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Single"
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
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
					"\41st_Weapons\DC15X\Data\15x noecho.ogg",
					1.5,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				beginwater1[]=
				{
					"\41st_Weapons\DC15X\Data\15x noecho.ogg",
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
			reloadTime=0.12;
			dispersion=9.9999997e-005;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=120;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"JLTS_DC15x_SCOPE"
				};
				iconPicture="";
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={
					"FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White"
				};
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
	class acc_flashlight;
	class FST_Base_Flashlight: acc_flashlight
	{
		scope = 0; // Base class, not to be used directly
		class Iteminfo
		{
			allowedSlots[] = {801,701,901};
			mass = 4;
			mountAction = "MountSide";
			type = 301;
			unmountAction = "DismountSide";
			class Flashlight
			{
				ambient[] = {0.9,0.81,0.7};
				color[] = {180,160,130};
				dayLight = 0;
				direction = "flash";
				useFlare = 1;
				volumeShape = "a3\\data_f\\VolumeLightFlashlight.p3d";
			};
		};
	};
	class FST_Attachment_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
				class Attenuation
				{
					constant = 0.5;
					hardLimitEnd = 60;
					hardLimitStart = 27;
					linear = 0.1;
					quadratic = 0.2;
					start = 0;
				};
			};
		};
	};
	class FST_Attachment_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Beam)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
				class Attenuation
				{
					constant = 0.2;
					hardLimitEnd = 540;
					hardLimitStart = 27;
					linear = 0.2;
					quadratic = 0.2;
					start = 20;
				};
			};
		};
	};
	class FST_Attachment_Module_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal/Beam)";
		scope = 2;
		scopeArsenal = 2;
		MRT_switchItemHintText = "White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Beam_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Beam_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
				class Attenuation
				{
					constant = 0.5;
					hardLimitEnd = 60;
					hardLimitStart = 27;
					linear = 0.1;
					quadratic = 0.2;
					start = 0;
				};
			};
		};
	};
	class FST_Attachment_Module_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light/Laser Module";
		scope = 1;
		scopeArsenal = 0;
		MRT_switchItemHintText = "Beam White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Normal_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Normal_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
				class Attenuation
				{
					constant = 0.2;
					hardLimitEnd = 540;
					hardLimitStart = 27;
					linear = 0.2;
					quadratic = 0.2;
					start = 20;
				};
			};
		};
	};
};
