class CfgPatches
{
	class FST_DC15AS
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15A",
			"FST_DC15A_ugl",
			"FST_DC15S",
			"FST_DC15S_UGL",
			"FST_DC15C_F",
			"FST_DC15LE"
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
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class 1Rnd_HE_Grenade_shell;
	class FST_blaster_cell_High: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=40;
		displayName="[41st] High-Power Energy Cell";
		displayNameShort="HP Energy Cell";
		descriptionShort="40 round capacity.";
		ammo="FST_blasterbolt_High";
		tracersEvery=1;
		initSpeed=340;
		mass=8;
	};
	class FST_blaster_cell_LE: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=10;
		displayName="[41st] High-Power DMR Blaster Cell";
		displayNameShort="HP Energy Cell";
		descriptionShort="40 round capacity.";
		ammo="FST_blasterbolt_DMR";
		tracersEvery=1;
		initSpeed=410;
		mass=8;
	};
	class FST_HE_LauncherGrenade: 1Rnd_HE_Grenade_shell
	{
		author="Adapted from the Indecisive Armoury Team";
		count=1;
		displayName="[41st] Impact Rifle Grenade";
		descriptionShort="Impact Grenade";
		ammo="FST_HE_RifleGrenade";
		mass=8;
	};
	class FST_blaster_cell: 100Rnd_65x39_caseless_mag
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=60;
		displayName="[41st] Standard Energy Cell";
		displayNameShort="Energy Cell";
		descriptionShort="60 round capacity.";
		ammo="FST_blasterbolt";
		tracersEvery=1;
		initSpeed=250;
		mass=8;
	};
	class FST_blaster_cell_Red: FST_blaster_cell
	{
		author="Indecisive Armoury Team";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=60;
		displayName="[41st] Standard Energy Cell (Red)";
		ammo="FST_blasterbolt_Red";
		tracersEvery=1;
		initSpeed=250;
		mass=8;
	};
};
class CfgAmmo
{
	class G_40mm_HE;
	class IDA_blasterbolt;
	class FST_blasterbolt: IDA_Blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType="plasma";
		cartridge="";
		lightcolor[]={0,0.30000001,1};
		hit=28;
		indirectHit=0;
		explosive=1;
		indirectHitRange=0.5;
		caliber=1.6;
		coefGravity=0.02;
		timetolive=8;
		waterFriction=-0.0099999998;
		deflecting=0;
		airfriction=0;
		tracerstarttime=0.050000001;
		tracerendtime=10;
		nvgonly=0;
		airlock=1;
		irtarget=1;
		brightness=1000;
		flaresize=5;
		tracerscale=1;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		ExplosionEffects="IDA_ImpactEffect";
		cratereffects="";
		class HitEffects
		{
			Hit_Foliage_Green="IDA_ImpactEffect";
			Hit_Foliage_Dead="IDA_ImpactEffect";
			Hit_Foliage_Green_big="IDA_ImpactEffect";
			Hit_Foliage_Palm="IDA_ImpactEffect";
			Hit_Foliage_Pine="IDA_ImpactEffect";
			hitFoliage="IDA_ImpactEffect";
			hitGlass="IDA_ImpactEffect";
			hitGlassArmoRed="IDA_ImpactEffect";
			hitWood="IDA_ImpactEffect";
			hitMetal="IDA_ImpactEffect";
			hitMetalPlate="IDA_ImpactEffect";
			hitBuilding="IDA_ImpactEffect";
			hitPlastic="IDA_ImpactEffect";
			hitRubber="IDA_ImpactEffect";
			hitTyre="IDA_ImpactEffect";
			hitConcrete="IDA_ImpactEffect";
			hitMan="IDA_ImpactEffect";
			hitGroundSoft="IDA_ImpactEffect";
			hitGroundRed="IDA_ImpactEffect";
			hitGroundHard="IDA_ImpactEffect";
			hitWater="IDA_ImpactEffect";
			hitVirtual="IDA_ImpactEffect";
			default_mat="IDA_ImpactEffect";
		};
		soundHitBody1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_1.ogg",
			3,
			1,
			200
		};
		soundHitBody2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_2.ogg",
			3,
			1,
			200
		};
		soundHitBody3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_3.ogg",
			3,
			1,
			200
		};
		soundHitBody4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_4.ogg",
			3,
			1,
			200
		};
		soundHitBody5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_5.ogg",
			3,
			1,
			200
		};
		soundHitBody6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_1.ogg",
			3,
			1.5,
			200
		};
		soundHitBody7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_2.ogg",
			3,
			1.5,
			200
		};
		soundHitBody8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_3.ogg",
			3,
			1.5,
			200
		};
		soundHitBody9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_4.ogg",
			3,
			1.5,
			200
		};
		soundHitBody10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_5.ogg",
			3,
			1.5,
			200
		};
		hitMan[]=
		{
			"soundHitBody1",
			0.1,
			"soundHitBody2",
			0.1,
			"soundHitBody3",
			0.1,
			"soundHitBody4",
			0.1,
			"soundHitBody5",
			0.1,
			"soundHitBody6",
			0.1,
			"soundHitBody7",
			0.1,
			"soundHitBody8",
			0.1,
			"soundHitBody9",
			0.1,
			"soundHitBody10",
			0.1
		};
		soundDefault1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_1.ogg",
			2,
			1,
			165
		};
		soundDefault2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_2.ogg",
			2,
			1,
			165
		};
		soundDefault3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_3.ogg",
			2,
			1,
			165
		};
		soundDefault4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_4.ogg",
			2,
			1,
			165
		};
		soundDefault5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_5.ogg",
			2,
			1,
			165
		};
		soundDefault6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_6.ogg",
			2,
			1,
			165
		};
		soundDefault7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_7.ogg",
			2,
			1,
			165
		};
		soundDefault8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_8.ogg",
			2,
			1,
			165
		};
		soundDefault9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_9.ogg",
			2,
			1,
			165
		};
		soundDefault10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_10.ogg",
			2,
			1,
			165
		};
		soundDefault11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_11.ogg",
			2,
			1,
			165
		};
		soundDefault12[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_12.ogg",
			2,
			1,
			165
		};
		soundDefault13[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_13.ogg",
			2,
			1,
			165
		};
		soundDefault14[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_14.ogg",
			2,
			1,
			165
		};
		soundDefault15[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_15.ogg",
			2,
			1,
			165
		};
		soundDefault16[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_16.ogg",
			2,
			1,
			165
		};
		soundDefault17[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_17.ogg",
			2,
			1,
			165
		};
		soundDefault18[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_18.ogg",
			2,
			1,
			165
		};
		soundDefault19[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_19.ogg",
			2,
			1,
			165
		};
		soundDefault20[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_20.ogg",
			2,
			1,
			165
		};
		soundDefault21[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_21.ogg",
			2,
			1,
			165
		};
		soundDefault22[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_22.ogg",
			2,
			1,
			165
		};
		soundDefault23[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_23.ogg",
			2,
			1,
			165
		};
		soundDefault24[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_24.ogg",
			2,
			1,
			165
		};
		soundDefault25[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_25.ogg",
			2,
			1,
			165
		};
		soundDefault26[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_26.ogg",
			2,
			1,
			165
		};
		soundDefault27[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_27.ogg",
			2,
			1,
			165
		};
		soundDefault28[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_28.ogg",
			2,
			1,
			165
		};
		soundDefault29[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_29.ogg",
			2,
			1,
			165
		};
		soundDefault30[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_30.ogg",
			2,
			1,
			165
		};
		soundDefault31[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_31.ogg",
			2,
			1,
			165
		};
		soundDefault32[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_32.ogg",
			2,
			1,
			165
		};
		soundDefault33[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_33.ogg",
			2,
			1,
			165
		};
		soundDefault34[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_34.ogg",
			2,
			1,
			165
		};
		soundDefault35[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_35.ogg",
			2,
			1,
			165
		};
		soundDefault36[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_36.ogg",
			2,
			1,
			165
		};
		soundDefault37[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_37.ogg",
			2,
			1,
			165
		};
		hitDefault[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitFoliage[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitPlastic[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitRubber[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitTyre[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitWood[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitBuilding[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		soundHit1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_1.ogg",
			2,
			1,
			165
		};
		soundHit2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_2.ogg",
			2,
			1,
			165
		};
		soundHit3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_3.ogg",
			2,
			1,
			165
		};
		soundHit4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_4.ogg",
			2,
			1,
			165
		};
		soundHit5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_5.ogg",
			2,
			1,
			165
		};
		soundHit6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_6.ogg",
			2,
			1,
			165
		};
		soundHit7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_7.ogg",
			2,
			1,
			165
		};
		soundHit8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_8.ogg",
			2,
			1,
			165
		};
		soundHit9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_9.ogg",
			2,
			1,
			165
		};
		soundHit10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_10.ogg",
			2,
			1,
			165
		};
		soundHit11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_11.ogg",
			2,
			1,
			165
		};
		hitGround[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitGroundHard[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitGroundSoft[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitConcrete[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		soundMetal1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_1.ogg",
			2,
			1,
			165
		};
		soundMetal2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_2.ogg",
			2,
			1,
			165
		};
		soundMetal3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_3.ogg",
			2,
			1,
			165
		};
		soundMetal4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_4.ogg",
			2,
			1,
			165
		};
		soundMetal5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_5.ogg",
			2,
			1,
			165
		};
		soundMetal6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_6.ogg",
			2,
			1,
			165
		};
		soundMetal7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_7.ogg",
			2,
			1,
			165
		};
		soundMetal8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_8.ogg",
			2,
			1,
			165
		};
		soundMetal9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_9.ogg",
			2,
			1,
			165
		};
		soundMetal10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_10.ogg",
			2,
			1,
			165
		};
		soundMetal11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_11.ogg",
			2,
			1,
			165
		};
		soundMetal12[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_12.ogg",
			2,
			1,
			165
		};
		soundMetal13[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_13.ogg",
			2,
			1,
			165
		};
		soundMetal14[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_14.ogg",
			2,
			1,
			165
		};
		soundMetal15[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_15.ogg",
			2,
			1,
			165
		};
		hitMetal[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitIron[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitMetalInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitMetalPlate[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitArmor[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitArmorInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		bulletFly1[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_1.wss",
			2.2387211,
			1,
			100
		};
		bulletFly2[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_2.wss",
			2.2387211,
			1,
			100
		};
		bulletFly3[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_3.wss",
			2.2387211,
			1,
			100
		};
		bulletFly4[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_4.wss",
			2.2387211,
			1,
			100
		};
		bulletFly5[]=
		{
			"\Indecisive_Armoury_Sounds\plasma_flyby_5.wss",
			2.2387211,
			1,
			100
		};
		bulletFly[]=
		{
			"bulletFly1",
			0.2,
			"bulletFly2",
			0.2,
			"bulletFly3",
			0.2,
			"bulletFly4",
			0.2,
			"bulletFly5",
			0.2
		};
		soundSetBulletFly[]=
		{
			"IDA_plasma_bullet_flyby_soundSet"
		};
		supersoniccracknear[]={};
		supersoniccrackfar[]={};
		soundSetSonicCrack[]={};
	};
	class FST_HE_RifleGrenade: G_40mm_HE
	{
		ace_frag_enabled=1;
		indirectHitRange=7;
		indirectHit=30;
		effectflare="FlareShell";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		fuseDistance=7;
		ExplosionEffects="SWLW_plasma_he_impact";
		CraterEffects="SWLW_plasma_he_impact";
		lightcolor[]={0,0,1};
	};
	class FST_blasterbolt_DMR: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=65;
		caliber=2.2;
		coefGravity=0.02;
	};
	class FST_blasterbolt_High: IDA_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=35;
		caliber=2.2;
		coefGravity=0.02;
	};
	class FST_blasterbolt_Green: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		lightcolor[]={0,1,0};
		hit=28;
	};
	class FST_blasterbolt_Yellow: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		lightcolor[]={1,1,0};
		hit=28;
	};
	class FST_blasterbolt_Red: FST_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Red.p3d";
		effectfly="IDA_BlasterBoltGlow_Red_Fly";
		lightcolor[]={1,0,0};
		hit=28;
	};
};
class CfgWeapons
{
	class JLTS_stun_muzzle;
	class Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class UGL_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class FST_DC15A: arifle_MX_Base_F
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
		displayName="[41st] DC-15A Rifle";
		descriptionShort="Long range, slow rate of fire.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"illum"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DC15A\data\DC15A_plastic_co.paa",
			"\MRC\JLTS\weapons\DC15A\data\DC15A_ugl_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"",
			"\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\DC15A\anims\DC15A_handanim.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReload_JLTS_DC15A";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15a";
		magazines[]=
		{
			"FST_blaster_cell_High",
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this",
			"stun"
		};
		class stun: JLTS_stun_muzzle {};
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
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
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
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
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S",
				//	"3AS_Optic_Red_DC15A"
				};
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
	class FST_DC15A_ugl: FST_DC15A
	{
		displayName="[41st] DC-15A Rifle w/ UGL";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_ugl_plastic_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_ugl_plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"illum"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DC15A\data\DC15A_plastic_co.paa",
			"\MRC\JLTS\weapons\DC15A\data\DC15A_ugl_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"",
			"\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"
		};
		muzzles[]=
		{
			"this",
			"EGLM"
		};
		magazines[]=
		{
			"FST_blaster_cell_High",
		};
		class EGLM: UGL_F
		{
			displayName="[41st] UGL";
			descriptionShort="FST UGL";
			useModelOptics=0;
			useExternalOptic=0;
			cameraDir="OP_look";
			discreteDistance[]={100,200,300,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye",
				"OP_eye2",
				"OP_eye3",
				"OP_eye4"
			};
			discreteDistanceInitIndex=0;
			magazines[]=
			{
				"FST_HE_LauncherGrenade",
				"IDA_Smoke_LauncherGrenade",
				"IDA_SmokeRed_LauncherGrenade",
				"IDA_SmokeGreen_LauncherGrenade",
				"IDA_SmokeBlue_LauncherGrenade",
				"IDA_SmokePurple_LauncherGrenade",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_HuntIR_M203"
			};
			recoil="FST_recoil_DP23";
			magazineWell[]={};
			class Single: Mode_SemiAuto
			{
				sounds[] = {"StandardSound"};
				class StandardSound
				{
					weaponSoundEffect = "";
					begin1[] = {"\41st_Weapons\DC-15AS\Data\41st GL New 2-343.ogg", 4, 1, 1800};
					begin2[] = {"\41st_Weapons\DC-15AS\Data\41st GL New 2-343.ogg", 4, 1, 1800};
					soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
				};
				reloadTime=2;
				dispersion=0.001;
				minRange=2;
				minRangeProbab=0.5;
				midRange=100;
				midRangeProbab=0.7;
				maxRange=200;
				maxRangeProbab=0.3;
			};
		};
		irLaserPos="";
		irLaserEnd="";
		irDistance=0;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=82;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S"
				};
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
	class FST_DC15LE: arifle_MX_Base_F
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
		displayName="[41st] DC-15LE Designated Marksman Rifle";
		descriptionShort="Long range, slow rate of fire.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model="3AS\3AS_Weapons\DC15A\3AS_DC15A_f.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3AS\3AS_Weapons\DC15A\Data\Anim\DC15A_handanim.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReload_JLTS_DC15A";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_dc15a";
		magazines[]=
		{
			"FST_blaster_cell_LE",
		};
		magazineWell[]={};
		modes[]=
		{
			"Single"
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_SW\Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this"
		};
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.5;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.125;
				opticsZoomMax=0.125;
				opticsZoomInit=0.125;
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsFlare="true";
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
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
			reloadTime=0.13333334;
			dispersion=0.001;
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
                linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
                compatibleItems[]=
                {
                    "3AS_Optic_Red_DC15A",
                    "FST_Optic_LEScope_DC15LE", 
                };
            };
            class MuzzleSlot: MuzzleSlot
            {
                linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
                compatibleItems[]=
                {
                    "3AS_Muzzle_LE_DC15A"
                };
                iconPosition[]={0,0.44999999};
                iconScale=0.2;
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
    class 3AS_Optic_LEScope_DC15A;
    class FST_Optic_LEScope_DC15LE: 3AS_Optic_LEScope_DC15A
    {
        displayName = "[41st] DC-15LE Optic";
        class ItemInfo
        {
            allowedSlots[] = {801,701,901};
            mass = 1;
            modelOptics = "\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
            mountAction = "MountOptic";
            muzzleEnd = "konec hlavne";
            muzzlePos = "usti hlavne";
            scope = 0;
            type = 201;
            unmountAction = "DismountOptic";
            zeroingSound[] = {"A3\Sounds_F\arsenal\sfx\shared\zeroing_knob_tick_plastic",0.316228,1,5};
            class OpticsModes
            {
                class IronSights
                {
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "eye";
                    opticsDisablePeripherialVision = 0.67;
                    opticsFlare = "true";
                    opticsID = 1;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
                    opticsZoomInit = 0.75;
                    opticsZoomMax = 1.1;
                    opticsZoomMin = 0.375;
                    useModelOptics = 0;
                    visionMode[] = {};
                };
                class Scope
                {
                    cameraDir = "";
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "opticView";
                    opticsDisablePeripherialVision = 0.67;
                    opticsFlare = "true";
                    opticsID = 2;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
                    opticsZoomInit = 0.0625;
                    opticsZoomMax = 0.0625;
                    opticsZoomMin = 0.03125;
                    useModelOptics = 1;
                    visionMode[] = {"Normal","NVG"};
                };
            };
        };
    };
	class FST_DC15S: arifle_MX_Base_F
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=0;
		JLTS_repairTime=5;
		ace_overheating_mrbs=40000;
        ace_overheating_slowdownFactor=0;
        ace_overheating_allowSwapBarrel=0;
        ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
        ace_overheating_barrelMass=1;
		IDA_plasmabolt=1;
		IDA_heatpershot=1;
		IDA_maxheat=1;		
		IDA_cooldownTime=15;
		JLTS_canHaveShield=1;
		JLTS_shieldedWeapon="IDA_DC15S_shield";
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		baseWeapon="FST_DC15S";
		displayName="[41st] DC-15S carbine";
		descriptionShort="Close range, fast rate of fire.";
		picture="\MRC\JLTS\weapons\DC15S\data\ui\DC15S_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15S\DC15S.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DC15S\data\DC15S_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\DC15S\anims\DC15S_handanim.rtm"
		};
		ace_clearJamAction="";
		reloadAction="GestureReload_JLTS_DC15S";
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
			"FST_blaster_cell",
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
			5,
			1,
			10
		};
		muzzles[]=
		{
			"this",
			"stun"
		};
		class stun: JLTS_stun_muzzle {};
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
			reloadTime=0.09230769;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
			reloadTime=0.09230769;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S",
				};
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
	class FST_DC15S_UGL: FST_DC15S
	{
		baseWeapon="FST_DC15S_UGL";
		recoil="FST_recoil_dc15s";
		displayName="[41st] DC-15S Carbine w/ UGL";
		scope=2;
		picture="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\DC15S_UGL_ui.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\Model\IDA_DC15S_UGL.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_beta\Rifles\MK20\Data\Anim\mk20G.rtm"
		};
		muzzles[]=
		{
			"This",
			"EGLM"
		};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		class EGLM: UGL_F
		{
			displayName="[41st] UGL";
			descriptionShort="41st UGL";
			useModelOptics=0;
			useExternalOptic=0;
			cameraDir="OP_look";
			discreteDistance[]={50,100,150,200};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye",
				"OP_eye2",
				"OP_eye3",
				"OP_eye4"
			};
			discreteDistanceInitIndex=0;
			magazines[]=
			{
				"IDA_HE_LauncherGrenade",
				"FST_HE_LauncherGrenade",
				"IDA_Smoke_LauncherGrenade",
				"IDA_SmokeRed_LauncherGrenade",
				"IDA_SmokeGreen_LauncherGrenade",
				"IDA_SmokeBlue_LauncherGrenade",
				"IDA_SmokePurple_LauncherGrenade",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_HuntIR_M203"
			};
			recoil="FST_recoil_DP23";
			reloadAction="GestureReloadMk20UGL";
			magazineWell[]={};
			class Single: Mode_SemiAuto
			{
				sounds[] = {"StandardSound"};
				class StandardSound
				{
					weaponSoundEffect = "";
					begin1[] = {"\41st_Weapons\DC-15AS\Data\41st GL New 2-343.ogg", 4, 1, 1800};
					begin2[] = {"\41st_Weapons\DC-15AS\Data\41st GL New 2-343.ogg", 4, 1, 1800};
					soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
				};
				reloadTime=2;
				dispersion=0.001;
				minRange=2;
				minRangeProbab=0.5;
				midRange=100;
				midRangeProbab=0.7;
				maxRange=200;
				maxRangeProbab=0.3;
			};
		};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		reloadAction="GestureReload_JLTS_DC15S";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
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
	class FST_DC15C_Base_F: Rifle_Base_F
	{
		author="Daara";
		magazines[]=
		{
			"FST_blaster_cell_High",
		};
		reloadAction="GestureReloadMX";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="FST_recoil_dc15a";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		dexterity=1.6;
		initSpeed=-1;
		maxZeroing=100;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"3AS_optic_reflex_DC15C"
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
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="DC-15C Carbine";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\DC15C\Data\Anim\DC15C_handanim.rtm"
		};
		selectionFireAnim="zasleh";
		fireLightDiffuse[]={7,110,176};
		fireLightIntensity=0.02;
		flash="gunfire";
		flashSize=0.1;
		muzzles[]= ///Added this as reference
		{          ///Added this as reference
			"this",///Added this as reference
			"stun" ///Added this as reference
		};         ///Added this as reference
		class stun: JLTS_stun_muzzle {}; ///The actual mode
		modes[]=
		{
			"Single",
			"Burst"
		};
		class Burst: Mode_Burst
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
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (3).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (2).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
					1.5,
					1,
					400
				};
			};
			burst=4;
			reloadTime=0.1;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (2).ogg",
					1.5,
					1,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (3).ogg",
					1.5,
					1,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
					1.5,
					1,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (2).ogg",
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
					"\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
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
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
	};
	class FST_DC15C_F: FST_DC15C_Base_F
	{
		scope=2;
		displayName="[41st] DC-15C Carbine";
		model="3AS\3AS_Weapons\DC15C\3AS_DC15C_f";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		weaponInfoType="RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
	};
    class acc_flashlight;
    class FST_Attachment_Light_Normal_White: acc_flashlight
    {
        displayName = "[41st] Light (Normal)";
        scope=2;
        scopeArsenal = 2;
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ACE_Flashlight_Beam = "\z\ace\addons\map\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "white";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 8;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 150;
                flareSize = 1.6;
                innerAngle = 5;
                intensity = 140;
                outerAngle = 100;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1.2;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
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

    class FST_Attachment_Light_Beam_White: acc_flashlight
    {
        displayName = "[41st] Light (Beam)";
        scope=2;
        scopeArsenal = 2;
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 30;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 500;
                flareSize = 4;
                innerAngle = 8;
                intensity = 140;
                irLight = 0;
                outerAngle = 25;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
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
class FST_Attachment_Module_Light_Normal_White: acc_flashlight
    {
        displayName = "[41st] Light (Normal/Beam)";
        scope=2;
        scopeArsenal = 2;
        MRT_switchItemHintText = "White Light";
        MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Beam_White";
        MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Beam_White";
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ACE_Flashlight_Beam = "\z\ace\addons\map\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "white";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 8;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 150;
                flareSize = 1.6;
                innerAngle = 5;
                intensity = 140;
                outerAngle = 100;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1.2;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
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

    class FST_Attachment_Module_Light_Beam_White: acc_flashlight
    {
        displayName = "[41st] Light/Laser Module";
        scope=1;
        scopeArsenal = 0;
        MRT_switchItemHintText = "Beam White Light";
        MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Normal_White";
        MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Normal_White";
        class Iteminfo
        {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountSide";
            scope = 0;
            type = 301;
            unmountAction = "DismountSide";
            class Flashlight
            {
                ambient[] = {0.9,0.81,0.7};
                color[] = {180,160,130};
                coneFadeCoef = 30;
                dayLight = 0;
                direction = "flash";
                flareMaxDistance = 500;
                flareSize = 4;
                innerAngle = 8;
                intensity = 140;
                irLight = 0;
                outerAngle = 25;
                position = "flash dir";
                scale[] = {1,1,1};
                size = 1;
                useFlare = 1;
                volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
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
