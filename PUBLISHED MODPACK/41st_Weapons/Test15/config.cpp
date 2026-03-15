class FST_Test15: IDA_T15
{
	author="Daara";
	displayName="[41st] T-15 Heavy Blaster (Test)";
	descriptionShort="Heavy blaster with a three-round anti-armor burst.";
	picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_ui_ca.paa";
	model="\MRC\JLTS\weapons\EPL2\EPL2.p3d";

	hiddenSelections[]=
	{
		"camo1",
		"camo2"
	};
	hiddenSelectionsTextures[]=
	{
		"\MRC\JLTS\weapons\EPL2\data\EPL2_co.paa",
		"\MRC\JLTS\weapons\EPL2\data\EPL2_mag_co.paa"
	};

	reloadAction="GestureReloadSPARUGL";
	reloadMagazineSound[]=
	{
		"\41st_Weapons\DC-15AS\Data\reload.ogg",
		1.5,
		1,
		100
	};

	recoil="FST_recoil_T15";

	// Switch to light rounds as the base
	magazines[]=
	{
		"FST_thermal_coil_LP_Blue",
	};
	magazineWell[]={};

	muzzles[]=
	{
		"this"
	};

	modes[]=
	{
		"Single",
		"Burst"
	};

	class Single: Mode_SemiAuto
	{
		displayName="Single";
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
			begin1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,1800};
			begin2[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.015,1800};
			begin3[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.98500001,1800};
			begin4[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.01,1800};
			begin5[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.995,1800};
			soundBegin[]=
			{
				"begin1",0.2,
				"begin2",0.2,
				"begin3",0.2,
				"begin4",0.2,
				"begin5",0.2
			};
			beginwater1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,400};
			soundBeginWater[]={"beginwater1",1};
		};

		reloadTime=0.33333334;
		dispersion=0.00145;

		minRange=60;
		minRangeProbab=1;
		midRange=300;
		midRangeProbab=0.85;
		maxRange=10000;
		maxRangeProbab=0.05;

		aiRateOfFire=4;
		aiRateOfFireDistance=1;
		aiRateOfFireDispersion=3;
	};

	class Burst: Mode_Burst
	{
		displayName="Burst";
		burst=3;
		soundBurst=0;

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
			begin1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,1800};
			begin2[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.015,1800};
			begin3[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.98500001,1800};
			begin4[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,1.01,1800};
			begin5[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1.25,0.995,1800};
			soundBegin[]=
			{
				"begin1",0.2,
				"begin2",0.2,
				"begin3",0.2,
				"begin4",0.2,
				"begin5",0.2
			};
			beginwater1[]={"\41st_Weapons\T15\Data\t15v1 2-177.ogg",1,1,400};
			soundBeginWater[]={"beginwater1",1};
		};

		reloadTime=0.1;
		dispersion=0.0018;

		minRange=60;
		minRangeProbab=1;
		midRange=300;
		midRangeProbab=0.85;
		maxRange=10000;
		maxRangeProbab=0.05;

		aiRateOfFire=1.0;
		aiRateOfFireDistance=1;
		aiRateOfFireDispersion=3;
	};
};