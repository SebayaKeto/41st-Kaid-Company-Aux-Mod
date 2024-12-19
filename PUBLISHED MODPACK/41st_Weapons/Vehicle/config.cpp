class CfgPatches
{
	class 41st_Weapons_Vehicle
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"41st_Addon",
		};
		author="Daara";
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgAmmo
{
	class BulletBase;
	class FST_127x99_red: BulletBase
	{
		hit=30;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="";
		visibleFire=8;
		audibleFire=120;
		dangerRadiusBulletClose=12;
		dangerRadiusHit=16;
		suppressionRadiusBulletClose=8;
		suppressionRadiusHit=12;
		cost=5;
		airLock=1;
		caliber=2.5999999;
		typicalSpeed=880;
		timeToLive=10;
		model="ls_weapons_core\Effects\laser_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Red_Fly";
		tracerScale=1.2;
		tracerStartTime=9.9999997e-006;
		tracerEndTime=10;
		airFriction=-0.00085999997;
		JLTS_isStunAmmo=0;
		JLTS_isEMPAmmo=0;
		ACE_damageType="plasma";
		coefGravity=1;
		ACE_caliber=12.954;
        ACE_bulletLength=58.674;
        ACE_bulletMass=41.9256;
        ACE_muzzleVelocityVariationSD=0.35;
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55, -25.47, -22.85, -20.12, -16.98, -12.80, -7.64, -1.53, 5.96, 15.17, 26.19};
        ACE_ballisticCoefficients[]={0.670};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={900};
        ACE_barrelLengths[]={736.6};
		class CamShakeExplode
		{
			power=3.6055501;
			duration=0.80000001;
			frequency=20;
			distance=10.8167;
		};
		class CamShakeHit
		{
			power=13;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
	};
	class IDA_thermal_shell;
	class IDA_blasterbolt;
	class FST_thermal_shell: IDA_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Green_Fly";
		ACE_damageType="plasmashell";
		hit=75;
		indirectHit=50;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_blue: IDA_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		ACE_damageType="plasmashell";
		hit=75;
		indirectHit=50;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_red: IDA_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
		ACE_damageType="plasmashell";
		hit=75;
		indirectHit=50;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
	};
	class FST_thermal_shell_HP_Blue: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=6;
		caliber=2;
	};
	class FST_thermal_shell_HP: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
	};
	class FST_thermal_shell_HP_Green: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Green_Fly";
		hit=900;
		indirectHit=150;
		explosive=1;
		indirectHitRange=6;
		caliber=2;
	};
	class FST_thermal_shell_LP_Red: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
		hit=400;
		indirectHit=75;
		explosive=1;
		indirectHitRange=4;
		caliber=2;
	};
	class FST_thermal_shell_OP_Red: IDA_thermal_shell
	{
		model="Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Red_Fly";
		hit=1200;
		indirectHit=300;
		explosive=1;
		indirectHitRange=8;
		caliber=2;
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class 1Rnd_HE_Grenade_shell;
	class FST_500Rnd_127x99_mag_red: VehicleMagazine
	{
		displayname="12.7x99mm 500Rnd plasma cell (Red)";
		displaynameshort="12.7x99mm";
		scope=2;
		count=500;
		ammo="FST_127x99_red";
		initSpeed=910;
		maxLeadSpeed=36.111099;
		tracersEvery=1;
		nameSound="mgun";
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
	class FST_thermal_coil: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Green)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_blue: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Blue)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell_blue";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_red: 1Rnd_HE_Grenade_shell
	{
		author="Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=150;
		displayName="[41st] 150 Rnd Thermal Coil (Red)";
		displayNameShort="Thermal Coil";
		descriptionShort="Fires Thermal Shells.";
		ammo="FST_thermal_shell_red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_HP_Blue: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] High-Power Thermal coil (Blue)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires High-Power Thermal Shells.";
		ammo="FST_thermal_shell_HP_Blue";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_LP_Red: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] Low-Power Thermal coil (Red)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires Low-Power Thermal Shells.";
		ammo="FST_thermal_shell_LP_Red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_OP_Red: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] Overpowered Thermal coil (Red)";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires OP Thermal Shells.";
		ammo="FST_thermal_shell_OP_Red";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
	class FST_thermal_coil_HP: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=1;
		displayName="[41st] High-Power Thermal coil";
		displayNameShort="HP Thermal Coil";
		descriptionShort="Fires High-Power Thermal Shells.";
		ammo="FST_thermal_shell_HP";
		tracersEvery=1;
		initSpeed=800;
		mass=20;
	};
};
class CfgWeapons
{
	class MGun;
	class LMG_coax;
	class autocannon_Base_F;
	class player;
	class OPTRE_M247T_Coax;
	class ls_laat_gun;
	
	//AAT------------------------------------------------
	
	class FST_AAT_Cannon: autocannon_Base_F
	{
		displayName="Main Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=2;
		fireLightDiffuse[]={1,0,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HP",
		};
		class HP: autocannon_Base_F
		{
			displayName="Main Blaster cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"IDA_thermal_coil_HP",
				"FST_thermal_coil_LP_Red",
				"FST_thermal_coil_OP_Red",
				"FST_thermal_coil_HP"
			};
			magazineReloadTime=2.5;
			modes[]=
			{
				"Fire",
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="DefaultRifle";
					closure1[]={};
					closure2[]={};
					soundClosure[]=
					{
						"closure1",
						0.5,
						"closure2",
						0.5
					};
				};
				class StandardSound
				{
					begin1[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_Weapons\Vehicle\Sounds\FST_AAT_Cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.4;
				};
			};
		};
	};
	class LMG_RCWS;
	class FST_AAT_Side_base: LMG_RCWS
	{
		class GunParticles;
		class manual;
	};
	class FST_AAT_Side: FST_AAT_Side_base
	{
		displayName="12.7mm AAT Side-mounted Guns";
		scope=1;
		magazines[]=
		{
			"FST_500Rnd_127x99_mag_red"
		};
		maxZeroing=2000;
		class GunParticles
		{
			class effect1
			{
				positionName="usti_hlavne_1";
				directionName="konec_hlavne_1";
				effectName="MachineGunCloud";
			};
			class effect2: effect1
			{
				positionName="usti_hlavne_2";
				directionName="konec_hlavne_2";
			};
		};
		showAimCursorInternal=0;
		class manual: mgun
		{
			TextureType="";
			displayName="12.7mm AAT Side Gun";
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"swlb_core\data\sounds\vehicles\aat\weapon\aat_light_shot.wss",
					1.5848932,
					1,
					2100
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.1;
			dispersion=0.0012000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=16;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=1.5;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.69999999;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=200;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=16;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=150;
			minRange=100;
			minRangeProbab=0.69999999;
			midRange=400;
			midRangeProbab=0.75;
			maxRange=800;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=4;
			burstRangeMax=12;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=400;
			minRange=400;
			minRangeProbab=0.75;
			midRange=800;
			midRangeProbab=0.69999999;
			maxRange=1500;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=4;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=800;
			minRange=800;
			minRangeProbab=0.60000002;
			midRange=1500;
			midRangeProbab=0.25;
			maxRange=2000;
			maxRangeProbab=0.050000001;
		};
	};
	class FST_EWEB_RemoteTurret: OPTRE_M247T_Coax
	{
		displayName="E-Web Remote Turret";
		author="Daara";
		descriptionShort="E-Web";
		magazines[]=
		{
			"FST_blaster_battery_high",
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[]={};
				closure2[]={};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1,
					2000
				};
				begin2[]=
				{
					"\41st_Weapons\EWEB\Sounds\EWEB.ogg",
					1,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					0.34,
					"begin2",
					0.33000001
				};
			};
			reloadTime=0.1;
			dispersion=0.001;
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.050000001;
			soundBurst=0;
			burst=1;
			displayName="$STR_DN_MODE_FULLAUTO";
			textureType="fullAuto";
		};
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne3";
				directionName="Usti hlavne3";
				effectName="MachineGunCloud";
			};
		};
	};
	class FST_30mm_Autocannon: autocannon_Base_F
	{
		displayName="Medium Blaster Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=0.2;
		fireLightDiffuse[]={0,1,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HE",
		};
		class HE: autocannon_Base_F
		{
			displayName="30mm Blaster cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"FST_thermal_coil"
			};
			magazineReloadTime=10;
			class player: player
			{
				class StandardSound
				{
					begin1[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.5;
				};
			};
		};
	};
	class Cannon_30mm_Plane_CAS_02_F;
	class FST_30mm_Autocannon_LAAT: Cannon_30mm_Plane_CAS_02_F
	{
		displayName="Medium LAAT Blaster Cannon";
		author="Daara";
		cursor="EmptyCursor";
		reloadTime=0.2;
		fireLightDiffuse[]={0,1,0};
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="";
				directionName="";
			};
			class Shell
			{
				positionName="";
				directionName="";
				effectName="";
			};
		};
		muzzles[]=
		{
			"HE",
		};
		class HE: autocannon_Base_F
		{
			displayName="30mm LAAT Blaster Cannon";
			cursor="EmptyCursor";
			magazines[]=
			{
				"FST_thermal_coil"
			};
			magazineReloadTime=10;
			class player: player
			{
				class StandardSound
				{
					begin1[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1,
						1500
					};
					begin2[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.015,
						1500
					};
					begin3[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.985,
						1500
					};
					begin4[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						1.01,
						1500
					};
					begin5[]=
					{
						"\41st_weapons\Vehicle\Sounds\FST_30mm_cannon.ogg",
						2.5118864,
						0.995,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
					dispersion=0.0018;
					reloadTime=0.04;
				};
			};
		};
	};
	class CannonCore;
	class FST_Mass_Driver_Cannon: CannonCore
	{
		scope=1;
		displayName="[41st] Mass Driver Cannon";
		cursor="EmptyCursor";
		cursorAim="cannon";
		showAimCursorInternal=0;
		nameSound="cannon";
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		magazines[]=
		{
			"FST_thermal_coil_HP_Blue"
		};
		reloadTime=6;
		magazineReloadTime=6;
		autoReload=1;
		canLock=0;
		ballisticsComputer="2 + 8 + 16";
		FCSMaxLeadSpeed=250;
		FCSZeroingDelay=1;
		aiDispersionCoefY=2;
		aiDispersionCoefX=2;
		autoFire=0;
		modes[]=
		{
			"player",
			"topDown",
			"close",
			"short",
			"medium",
			"far"
		};
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="Usti hlavne";
				directionName="Konec hlavne";
			};
		};
		class player: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Maincanon_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			reloadTime=6;
			magazineReloadTime=6;
			autoReload=1;
			autoFire=0;
			dispersion=0.00056999997;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class TopDown: player
		{
			textureType="topDown";
			displayName="$STR_A3_FireMode_TopDown0";
			minRange=150;
			minRangeProbab=0.40000001;
			midRange=400;
			midRangeProbab=0.94999999;
			maxRange=8000;
			maxRangeProbab=0.94999999;
		};
		class close: player
		{
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=6;
			aiRateOfFireDispersion=0.5;
			aiRateOfFireDistance=500;
			minRange=5;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.80000001;
			maxRange=1000;
			maxRangeProbab=0.85000002;
		};
		class short: close
		{
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=6;
			aiRateOfFireDispersion=1;
			aiRateOfFireDistance=1000;
			minRange=500;
			minRangeProbab=0.30000001;
			midRange=1000;
			midRangeProbab=0.85000002;
			maxRange=1500;
			maxRangeProbab=0.85000002;
		};
		class medium: close
		{
			dispersion=0.00071250001;
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=8;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=1250;
			minRange=1000;
			minRangeProbab=0.60000002;
			midRange=1500;
			midRangeProbab=0.85000002;
			maxRange=2000;
			maxRangeProbab=0.80000001;
		};
		class far: close
		{
			dispersion=0.00071250001;
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=10;
			aiRateOfFireDispersion=8;
			aiRateOfFireDistance=1500;
			minRange=1500;
			minRangeProbab=0.75;
			midRange=2000;
			midRangeProbab=0.80000001;
			maxRange=3500;
			maxRangeProbab=0.050000001;
		};
	};
	class FST_ATTE_Turret: MGun
	{
		class GunClouds
		{
		};
		bullet1[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_01",
			0.2818383,
			1,
			10
		};
		bullet2[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_02",
			0.2818383,
			1,
			10
		};
		bullet3[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_03",
			0.2818383,
			1,
			10
		};
		bullet4[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_04",
			0.2818383,
			1,
			10
		};
		bullet5[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_01",
			0.2818383,
			1,
			10
		};
		bullet6[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_02",
			0.2818383,
			1,
			10
		};
		bullet7[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_03",
			0.2818383,
			1,
			10
		};
		bullet8[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_04",
			0.2818383,
			1,
			10
		};
		bullet9[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_01",
			0.2818383,
			1,
			10
		};
		bullet10[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_02",
			0.2818383,
			1,
			10
		};
		bullet11[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_03",
			0.2818383,
			1,
			10
		};
		bullet12[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_04",
			0.2818383,
			1,
			10
		};
		soundBullet[]=
		{
			"bullet1",
			0.079999998,
			"bullet2",
			0.083999999,
			"bullet3",
			0.083999999,
			"bullet4",
			0.083999999,
			"bullet5",
			0.093000002,
			"bullet6",
			0.093000002,
			"bullet7",
			0.074000001,
			"bullet8",
			0.074000001,
			"bullet9",
			0.083999999,
			"bullet10",
			0.085000001,
			"bullet11",
			0.082999997,
			"bullet12",
			0.082999997
		};
		class GunParticles
		{
		};
		scope=1;
		displayName="[41st] Rapid Fire Turret";
		magazines[]=
		{
			"FST_thermal_coil_Blue",
			"FST_thermal_coil_Red",		
			"FST_thermal_coil"
		};
		magazineReloadTime=20;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		canLock=0;
		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=30;
		FCSZeroingDelay=1;
		maxZeroing=1500;
		aiDispersionCoefY=3;
		aiDispersionCoefX=3;
		class manual: MGun
		{
			displayName="[41st] ATTE PD Turret";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_HeavyBlaster_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.2;
			dispersion=0.0016;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=16;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.80000001;
			midRange=20;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=12;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=150;
			minRange=20;
			minRangeProbab=0.69999999;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=300;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=250;
			minRange=150;
			minRangeProbab=0.69999999;
			midRange=600;
			midRangeProbab=0.64999998;
			maxRange=800;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=8;
			aiRateOfFire=4;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=600;
			minRange=600;
			minRangeProbab=0.64999998;
			midRange=800;
			midRangeProbab=0.40000001;
			maxRange=1200;
			maxRangeProbab=0.1;
		};
	};
};