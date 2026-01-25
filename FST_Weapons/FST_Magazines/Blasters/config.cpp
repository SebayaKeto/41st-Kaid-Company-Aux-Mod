class CfgPatches
{
	class FST_Weapons_Magazines_Blasters
	{
		weapons[]=
		{
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		magazines[]=
		{
			"FST_ChargePack_DX11_Standard",
			"FST_ChargePack_DX11_Ion",
			"FST_ChargePack_DC15_VeryLow",
			"FST_ChargePack_DC15_Low",
			"FST_ChargePack_DC15_Medium",
			"FST_ChargePack_DC15_High",
			"FST_ChargePack_DC15_VeryHigh",
			"FST_ChargePack_DC15_Sniper",
			"FST_ChargePack_DC17_Low",
			"FST_ChargePack_DC17_High",
			"FST_ChargePack_DC17_StunBlue",
			"FST_ShotPack_DLT18_Buckshot",
			"FST_ShotPack_DLT18_Slug",
			"FST_ShotPack_DLT18_Stun",
			"FST_ShotPack_DLT18_Incendiary",
			"FST_ShotPack_DLT18_Ion"
		};
		ammo[]=
		{
			"FST_BlasterBolt_VeryLowPowerBlue",
			"FST_BlasterBolt_LowPowerBlue",
			"FST_BlasterBolt_MediumPowerBlue",
			"FST_BlasterBolt_HighPowerBlue",
			"FST_BlasterBolt_VeryHighPowerBlue",
			"FST_BlasterBolt_MaximumPowerBlue",
			"FST_BlasterBolt_StunBlue",
			"FST_BlasterBolt_IonBlue",
			"FST_ShotgunShell_Buckshot",
			"FST_ShotgunShell_Slug",
			"FST_ShotgunShell_Stun",
			"FST_ShotgunShell_Ion"
		};
		units[]={};
	};
};
class CfgAmmo
{
	class BulletBase;
	class FST_BlasterBolt_Base: BulletBase
	{
		visibleFire = 5;
		audibleFire = 20;
		visibleFireTime = 2;
		dangerRadiusBulletClose = 4;
		dangerRadiusHit = -1;
		suppressionRadiusBulletClose = 2;
		suppressionRadiusHit = 4;
		hit = 1;
		indirectHit = 0;
		indirectHitRange = 0;
		model = "FST\FST_Weapons\FST_Magazines\Blasters\Data\BlasterBolt_Blue.p3d";
		caliber = 1;
		ACE_caliber = 1;
		FST_AmmoType = 1;
		coefGravity = 0.01;
		cartridge = "";
		cost = 1;
		timeToLive = 10;
		deflecting = 0;
		ExplosionEffects = "FST_ImpactBlasterBolt";
		craterEffects = "";
		explosive = 0.1;
		tracerStartTime = 0;
		tracerEndTime = 10;
		airFriction = -0.0003;
		muzzleEffect = "";
		waterEffectOffset = 0.8;
		effectFly = "FST_FX_Bullet_Teal";
		aiAmmoUsageFlags = "64 + 128 + 256";
		soundHitBody1[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-01.ogg",3,1,200};
		soundHitBody2[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-02.ogg",3,1,200};
		soundHitBody3[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-03.ogg",3,1,200};
		soundHitBody4[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-04.ogg",3,1,200};
		soundHitBody5[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-05.ogg",3,1,200};
		soundHitBody6[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-06.ogg",3,1.5,200};
		soundHitBody7[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-07.ogg",3,1.5,200};
		soundHitBody8[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-08.ogg",3,1.5,200};
		soundHitBody9[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-03.ogg",3,1.5,200};
		soundHitBody10[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Body-02.ogg",3,1.5,200};
		hitMan[] = {"soundHitBody1",0.1,"soundHitBody2",0.1,"soundHitBody3",0.1,"soundHitBody4",0.1,"soundHitBody5",0.1,"soundHitBody6",0.1,"soundHitBody7",0.1,"soundHitBody8",0.1,"soundHitBody9",0.1,"soundHitBody10",0.1};
		soundDefault1[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-01.ogg",2,1,165};
		soundDefault2[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-02.ogg",2,1,165};
		soundDefault3[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-03.ogg",2,1,165};
		soundDefault4[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-04.ogg",2,1,165};
		soundDefault5[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-05.ogg",2,1,165};
		soundDefault6[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-06.ogg",2,1,165};
		soundDefault7[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-07.ogg",2,1,165};
		soundDefault8[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-08.ogg",2,1,165};
		soundDefault9[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-09.ogg",2,1,165};
		soundDefault10[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-10.ogg",2,1,165};
		soundDefault11[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-11.ogg",2,1,165};
		soundDefault12[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-12.ogg",2,1,165};
		soundDefault13[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-13.ogg",2,1,165};
		soundDefault14[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-14.ogg",2,1,165};
		soundDefault15[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-15.ogg",2,1,165};
		soundDefault16[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-16.ogg",2,1,165};
		soundDefault17[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-17.ogg",2,1,165};
		soundDefault18[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-18.ogg",2,1,165};
		soundDefault19[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-19.ogg",2,1,165};
		soundDefault20[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-20.ogg",2,1,165};
		soundDefault21[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-21.ogg",2,1,165};
		soundDefault22[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-01.ogg",2,1,165};
		soundDefault23[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-02.ogg",2,1,165};
		soundDefault24[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-03.ogg",2,1,165};
		soundDefault25[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-04.ogg",2,1,165};
		soundDefault26[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-05.ogg",2,1,165};
		soundDefault27[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-06.ogg",2,1,165};
		soundDefault28[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-07.ogg",2,1,165};
		soundDefault29[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-08.ogg",2,1,165};
		soundDefault30[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-09.ogg",2,1,165};
		soundDefault31[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-10.ogg",2,1,165};
		soundDefault32[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-11.ogg",2,1,165};
		soundDefault33[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-12.ogg",2,1,165};
		soundDefault34[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-13.ogg",2,1,165};
		soundDefault35[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-14.ogg",2,1,165};
		soundDefault36[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-15.ogg",2,1,165};
		soundDefault37[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-16.ogg",2,1,165};
		soundDefault38[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Tree-01.ogg",2,1,165};
		soundDefault39[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Tree-02.ogg",2,1,165};
		hitDefault[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitFoliage[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitPlastic[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitRubber[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitTyre[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitWood[] = {"soundDefault38",0.027,"soundDefault39",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		hitBuilding[] = {"soundDefault1",0.027,"soundDefault2",0.027,"soundDefault3",0.027,"soundDefault4",0.027,"soundDefault5",0.027,"soundDefault6",0.027,"soundDefault7",0.027,"soundDefault8",0.027,"soundDefault9",0.027,"soundDefault10",0.027,"soundDefault11",0.027,"soundDefault12",0.027,"soundDefault13",0.027,"soundDefault14",0.027,"soundDefault15",0.027,"soundDefault16",0.027,"soundDefault17",0.027,"soundDefault18",0.027,"soundDefault19",0.027,"soundDefault20",0.027,"soundDefault21",0.027,"soundDefault22",0.027,"soundDefault23",0.027,"soundDefault24",0.027,"soundDefault25",0.027,"soundDefault26",0.027,"soundDefault37",0.027,"soundDefault27",0.027,"soundDefault28",0.027,"soundDefault29",0.027,"soundDefault30",0.027,"soundDefault31",0.027,"soundDefault32",0.027,"soundDefault33",0.027,"soundDefault34",0.027,"soundDefault35",0.027,"soundDefault36",0.027};
		soundHit1[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-01.ogg",2,1,165};
		soundHit2[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-02.ogg",2,1,165};
		soundHit3[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-03.ogg",2,1,165};
		soundHit4[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-04.ogg",2,1,165};
		soundHit5[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-05.ogg",2,1,165};
		soundHit6[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-06.ogg",2,1,165};
		soundHit7[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-01.ogg",2,1,165};
		soundHit8[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-02.ogg",2,1,165};
		soundHit9[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-03.ogg",2,1,165};
		soundHit10[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-04.ogg",2,1,165};
		soundHit11[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_Dirt-05.ogg",2,1,165};
		hitGround[] = {"soundHit1",0.0909,"soundHit2",0.0909,"soundHit3",0.0909,"soundHit4",0.0909,"soundHit5",0.0909,"soundHit6",0.0909,"soundHit7",0.0909,"soundHit8",0.0909,"soundHit9",0.0909,"soundHit10",0.0909,"soundHit11",0.0909};
		hitGroundHard[] = {"soundHit1",0.0909,"soundHit2",0.0909,"soundHit3",0.0909,"soundHit4",0.0909,"soundHit5",0.0909,"soundHit6",0.0909,"soundHit7",0.0909,"soundHit8",0.0909,"soundHit9",0.0909,"soundHit10",0.0909,"soundHit11",0.0909};
		hitGroundSoft[] = {"soundHit1",0.0909,"soundHit2",0.0909,"soundHit3",0.0909,"soundHit4",0.0909,"soundHit5",0.0909,"soundHit6",0.0909,"soundHit7",0.0909,"soundHit8",0.0909,"soundHit9",0.0909,"soundHit10",0.0909,"soundHit11",0.0909};
		hitConcrete[] = {"soundHit1",0.0909,"soundHit2",0.0909,"soundHit3",0.0909,"soundHit4",0.0909,"soundHit5",0.0909,"soundHit6",0.0909,"soundHit7",0.0909,"soundHit8",0.0909,"soundHit9",0.0909,"soundHit10",0.0909,"soundHit11",0.0909};
		soundMetal1[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-01.ogg",2,1,165};
		soundMetal2[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-02.ogg",2,1,165};
		soundMetal3[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-03.ogg",2,1,165};
		soundMetal4[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-04.ogg",2,1,165};
		soundMetal5[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-05.ogg",2,1,165};
		soundMetal6[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-06.ogg",2,1,165};
		soundMetal7[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-07.ogg",2,1,165};
		soundMetal8[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-08.ogg",2,1,165};
		soundMetal9[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-09.ogg",2,1,165};
		soundMetal10[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-01.ogg",2,1,165};
		soundMetal11[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-02.ogg",2,1,165};
		soundMetal12[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-03.ogg",2,1,165};
		soundMetal13[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-04.ogg",2,1,165};
		soundMetal14[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-20.ogg",2,1,165};
		soundMetal15[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact-21.ogg",2,1,165};
		hitMetal[] = {"soundMetal1",0.0666,"soundMetal2",0.0666,"soundMetal3",0.0666,"soundMetal4",0.0666,"soundMetal5",0.0666,"soundMetal6",0.0666,"soundMetal7",0.0666,"soundMetal8",0.0666,"soundMetal9",0.0666,"soundMetal10",0.0666,"soundMetal11",0.0666,"soundMetal12",0.0666,"soundMetal13",0.0666,"soundMetal14",0.0666,"soundMetal15",0.0666};
		hitIron[] = {"soundMetal1",0.0666,"soundMetal2",0.0666,"soundMetal3",0.0666,"soundMetal4",0.0666,"soundMetal5",0.0666,"soundMetal6",0.0666,"soundMetal7",0.0666,"soundMetal8",0.0666,"soundMetal9",0.0666,"soundMetal10",0.0666,"soundMetal11",0.0666,"soundMetal12",0.0666,"soundMetal13",0.0666,"soundMetal14",0.0666,"soundMetal15",0.0666};
		hitMetalInt[] = {"soundMetal1",0.0666,"soundMetal2",0.0666,"soundMetal3",0.0666,"soundMetal4",0.0666,"soundMetal5",0.0666,"soundMetal6",0.0666,"soundMetal7",0.0666,"soundMetal8",0.0666,"soundMetal9",0.0666,"soundMetal10",0.0666,"soundMetal11",0.0666,"soundMetal12",0.0666,"soundMetal13",0.0666,"soundMetal14",0.0666,"soundMetal15",0.0666};
		soundMetalPlate1[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-01.ogg",2,1,165};
		soundMetalPlate2[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-02.ogg",2,1,165};
		soundMetalPlate3[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-03.ogg",2,1,165};
		soundMetalPlate4[] = {"\FST\FST_Weapons\FST_Sounds\Weapons\Blaster_Impact_SheetMetal-04.ogg",2,1,165};
		hitMetalPlate[] = {"soundMetalPlate1",0.25,"soundMetalPlate2",0.25,"soundMetalPlate3",0.25,"soundMetalPlate4",0.25};
		hitArmor[] = {"soundMetal1",0.0666,"soundMetal2",0.0666,"soundMetal3",0.0666,"soundMetal4",0.0666,"soundMetal5",0.0666,"soundMetal6",0.0666,"soundMetal7",0.0666,"soundMetal8",0.0666,"soundMetal9",0.0666,"soundMetal10",0.0666,"soundMetal11",0.0666,"soundMetal12",0.0666,"soundMetal13",0.0666,"soundMetal14",0.0666,"soundMetal15",0.0666};
		hitArmorInt[] = {"soundMetal1",0.0666,"soundMetal2",0.0666,"soundMetal3",0.0666,"soundMetal4",0.0666,"soundMetal5",0.0666,"soundMetal6",0.0666,"soundMetal7",0.0666,"soundMetal8",0.0666,"soundMetal9",0.0666,"soundMetal10",0.0666,"soundMetal11",0.0666,"soundMetal12",0.0666,"soundMetal13",0.0666,"soundMetal14",0.0666,"soundMetal15",0.0666};
		soundFly[] = {"",0.251189,0.7};
		soundSetSonicCrack[] = {"FST_BlasterBolt_FlyBy_Soundset"};
		class HitEffects
		{
			Hit_Foliage_green = "FST_ImpactBlasterBolt";
			Hit_Foliage_Dead = "FST_ImpactBlasterBolt";
			Hit_Foliage_Green_big = "FST_ImpactBlasterBolt";
			Hit_Foliage_Palm = "FST_ImpactBlasterBolt";
			Hit_Foliage_Pine = "FST_ImpactBlasterBolt";
			hitFoliage = "FST_ImpactBlasterBolt";
			hitGlass = "FST_ImpactBlasterBolt";
			hitGlassArmored = "FST_ImpactBlasterBolt";
			hitWood = "FST_ImpactBlasterBolt";
			hitMetal = "FST_ImpactBlasterBolt";
			hitMetalPlate = "FST_ImpactBlasterBolt";
			hitBuilding = "FST_ImpactBlasterBolt";
			hitPlastic = "FST_ImpactBlasterBolt";
			hitRubber = "FST_ImpactBlasterBolt";
			hitTyre = "FST_ImpactBlasterBolt";
			hitConcrete = "FST_ImpactBlasterBolt";
			hitMan = "FST_ImpactBlasterBolt";
			hitGroundSoft = "FST_ImpactBlasterBolt";
			hitGroundRed = "FST_ImpactBlasterBolt";
			hitGroundHard = "FST_ImpactBlasterBolt";
			hitWater = "FST_ImpactBlasterBolt";
			hitVirtual = "FST_ImpactBlasterBolt";
			default_mat = "FST_ImpactBlasterBolt";
		};
	};
	class FST_BlasterBolt_VeryLowPowerBlue: FST_BlasterBolt_Base
	{
		hit = 5;
	};
	class FST_BlasterBolt_LowPowerBlue: FST_BlasterBolt_Base
	{
		hit = 11;
	};
	class FST_BlasterBolt_MediumPowerBlue: FST_BlasterBolt_Base
	{
		hit = 17;
	};
	class FST_BlasterBolt_HighPowerBlue: FST_BlasterBolt_Base
	{
		hit = 28;
	};
	class FST_BlasterBolt_VeryHighPowerBlue: FST_BlasterBolt_Base
	{
		hit = 40;
		caliber = 2;
		ACE_caliber = 2;
	};
	class FST_BlasterBolt_MaximumPowerBlue: FST_BlasterBolt_Base
	{
		hit = 100;
		caliber = 3;
		ACE_caliber = 3;
	};
	class FST_BlasterBolt_StunBlue: FST_BlasterBolt_Base
	{
		hit = 0.1;
		indirectHit = 0;
		indirectHitRange = 0;
		FST_AmmoType = 2;
		model = "FST\FST_Weapons\FST_Magazines\Blasters\Data\BlasterBoltStun_Blue.p3d";
		// Stun Duration for this is set in the FST_Weapon_fnc_onHitStun sqf file.
	};
	class FST_BlasterBolt_IonBlue: FST_BlasterBolt_Base
	{
		hit = 17;
		indirectHit = 0;
		indirectHitRange = 0;
		FST_AmmoType = 7;
	};
	class FST_ShotgunShell_Buckshot: FST_BlasterBolt_Base
	{
		hit = 20;
		caliber = 1.5;
		ACE_caliber = 1.5;
		simulation = "shotSpread";
		timetolive = 1.25;
		submunitionAmmo[] = {"FST_BlasterBolt_MediumPowerBlue",0.6,"FST_BlasterBolt_LowPowerBlue",0.3,"FST_BlasterBolt_VeryLowPowerBlue",0.1};
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionConeType[] = {"poissondisc", 15 }; 
		triggerTime = 0.1;
		deleteParentWhenTriggered = true;
	};
	class FST_ShotgunShell_Slug: FST_BlasterBolt_Base
	{
		hit = 30;
		caliber = 2;
		ACE_caliber = 2;
		timeToLive = 3;
	};
	class FST_ShotgunShell_Ion: FST_BlasterBolt_Base
	{
		hit = 18;
		caliber = 1;
		ACE_caliber = 1;
		simulation = "shotSpread";
		timetolive = 1.5;
		submunitionAmmo[] = {"FST_BlasterBolt_MediumPowerBlue",0.6,"FST_BlasterBolt_LowPowerBlue",0.3,"FST_BlasterBolt_VeryLowPowerBlue",0.1};
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionConeType[] = {"poissondisc", 15 }; 
		triggerTime = 0.1;
		deleteParentWhenTriggered = true;
		FST_AmmoType = 7;
	};
	class FST_ShotgunShell_Stun: FST_BlasterBolt_Base
	{
		hit = 0.1;
		caliber = 1;
		ACE_caliber = 1;
		simulation = "shotSpread";
		timetolive = 1.5;
		submunitionAmmo[] = {"FST_BlasterBolt_StunBlue",1};
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionConeType[] = {"poissondisc", 10 }; 
		triggerTime = 0.1;
		deleteParentWhenTriggered = false;
		FST_AmmoType = 2;
	};
};
class CfgMagazines
{	
	class Default;
	class CA_Magazine: Default{};
	class FST_ChargePack_Base: CA_Magazine
	{
		author = "Maldova";
		scope = 1;
		displayName = "[WPS] Charge Pack";
		picture = "\FST\FST_Weapons\FST_Magazines\Blasters\UI\DC15SeriesMagazineIcon.paa";
		ammo = "FST_BlasterBolt_HighPowerBlue";
		count = 50;
		tracersEvery = 1;
		lastRoundsTracer = 50;
		mass = 2;
		initSpeed = 320;
		descriptionShort = "Standard Charge Pack for the DC Platform of Weapons.";
	};
	class FST_ChargePack_DC15_Low: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] Low Charge Pack";
		ammo = "FST_BlasterBolt_LowPowerBlue";
		descriptionShort = "Low Power Charge Pack for the DC Platform of Weapons.";
	};
	class FST_ChargePack_DC15_Medium: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] Medium Charge Pack";
		ammo = "FST_BlasterBolt_MediumPowerBlue";
		descriptionShort = "Medium Power Charge Pack for the DC Platform of Weapons.";
	};
	class FST_ChargePack_DC15_High: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] High Charge Pack";
		ammo = "FST_BlasterBolt_HeavyPowerBlue";
		descriptionShort = "High Charge Pack for the DC Platform of Weapons.";
	};
	class FST_ChargePack_DC15H_Low:FST_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] DC15H Low Charge Pack (200)";
		picture = "\FST\FST_Weapons\FST_Magazines\Blasters\UI\DC15HMagazineIcon.paa";
		ammo = "FST_BlasterBolt_VeryLowPowerBlue";
		descriptionShort = "Low-Power Charge Pack for the DC-15H.";
		count = 200;
		lastRoundsTracer = 200;
	};
	class FST_ChargePack_DC15H_Medium:FST_ChargePack_Base
	{
		scope = 2;
		displayName = "[WPS] DC15H Medium Charge Pack (100)";
		picture = "\FST\FST_Weapons\FST_Magazines\Blasters\UI\DC15HMagazineIcon.paa";
		ammo = "FST_BlasterBolt_MediumPowerBlue";
		descriptionShort = "Medium-Power Charge Pack for the DC-15H.";
		count = 100;
		lastRoundsTracer = 100;
	};
	class FST_ChargePack_DC17_Low: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC-17 Charge Pack (Low)";
		ammo = "FST_BlasterBolt_LowPowerBlue";
		count = 50;
		lastRoundsTracer = 50;
		initSpeed = 300;
		descriptionShort = "Low-Power Charge Pack for the DC-17.";
	};
	class FST_ChargePack_DC17_High: FST_ChargePack_DC17_Low
	{
		scope = 2;
		displayName = "DC-17 Charge Pack (High)";
		ammo = "FST_BlasterBolt_HighPowerBlue";
		count = 20;
		lastRoundsTracer = 20;
		initSpeed = 350;
		descriptionShort = "High-Power Charge Pack for the DC-17.";
	};
	class FST_ChargePack_DC17_StunBlue: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC-17 Stun Pack";
		ammo = "FST_BlasterBolt_StunBlue";
		count = 10;
		lastRoundsTracer = 10;
		initspeed = 150;
		descriptionShort = "Low Power Charge Pack for the DC-17.  Stuns for 20 seconds.";
		// Stun Duration for this is set in the FST_Weapon_fnc_onHitStun sqf file.
	};
	class FST_ShotPack_DLT18_Buckshot: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC Series Buckshot";
		ammo = "FST_ShotgunShell_Buckshot";
		count = 15;
		lastRoundsTracer = 15;
		initSpeed = 400;
		descriptionShort = "Buckshot-Shotgun shells for use by the GAR.";
	};
	class FST_ShotPack_DLT18_Slug: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC Series slug-shot";
		ammo = "FST_ShotgunShell_Slug";
		count = 20;
		lastRoundsTracer = 20;
		initSpeed = 400;
		descriptionShort = "Slug-Shotgun shells for use by the GAR.";
	};
	class FST_ShotPack_DLT18_Stun: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC Series Stun-shot";
		ammo = "FST_ShotgunShell_Stun";
		count = 10;
		lastRoundsTracer = 10;
		initSpeed = 400;
		descriptionShort = "Stun-Shotgun shells for use by the GAR.";
	};
	class FST_ShotPack_DLT18_Ion: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC Series Ion-shot";
		ammo = "FST_ShotgunShell_Ion";
		count = 15;
		lastRoundsTracer = 15;
		initSpeed = 300;
		descriptionShort = "Ion-Shotgun shells for use by the GAR.";
	};
	class FST_ShotPack_DLT18_Incendiary: FST_ChargePack_Base
	{
		scope = 2;
		displayName = "DC Series Incendiary-shot";
		ammo = "FST_BTX42_FireShot";
		count = 15;
		lastRoundsTracer = 15;
		initSpeed = 200;
		descriptionShort = "Incendiary-Shotgun shells for use by the GAR.";
	};
};
class CfgMagazineWells
{
	class FST_DX11Magwell
	{
		DX11Magazines[] = 
		{
			"FST_ChargePack_DX11_Standard",
			"FST_ChargePack_DX11_Ion",
			"FST_ChargePack_DC15_High"
		};
	};
	class FST_DC15XMagwell
	{
		DC15XMagazines[] = 
		{
			"FST_ChargePack_DX11_Standard",
			"FST_ChargePack_DX11_Ion",
			"FST_ChargePack_DC15_High",
			"FST_ChargePack_DC15_Medium"
		};
	};
	class FST_DC15AMagwell
	{
		DC15AMagazines[] = 
		{
			"FST_ChargePack_DC15_Medium",
			"FST_ChargePack_DC15_High"
		};
	};
	class FST_DC15SMagwell
	{
		DC15SMagazines[] = 
		{
			"FST_ChargePack_DC15_Low",
			"FST_ChargePack_DC15_Medium"
		};
	};
	class FST_DC15CMagwell
	{
		DC15CMagazines[] = 
		{
			"FST_ChargePack_DC15_Low",
			"FST_ChargePack_DC15_Medium"
		};
	};
	class FST_DC15HMagwell
	{
		DC15HMagazines[] = 
		{
			"FST_ChargePack_DC15H_Low",
			"FST_ChargePack_DC15H_Medium"
		};
	};
	class FST_DC17Magwell
	{
		DC17Magazines[] = 
		{
			"FST_ChargePack_DC17_Low",
			"FST_ChargePack_DC17_High"
		};
	};
	class FST_DC17StunMagwell
	{
		DC17StunMagazines[] = 
		{
			"FST_ChargePack_DC17_StunBlue"
		};
	};
	class FST_DLT18Magwell
	{
		DLT18Magazines[] = 
		{
			"FST_ShotPack_DLT18_Buckshot",
			"FST_ShotPack_DLT18_Slug",
			"FST_ShotPack_DLT18_Stun",
			"FST_ShotPack_DLT18_Incendiary",
			"FST_ShotPack_DLT18_Ion"
		};
	};
	class FST_Valken38XMagwell
	{
		Valken38XMagazines[] = 
		{
			"FST_ChargePack_DX11_Ion",
			"FST_ChargePack_DC15_High"
		};
	};
};
class cfgRecoils
{
	class Default;
	class FST_Recoil_Default: Default
	{
		kickBack[] = {0.025,0.06};
		muzzleInner[] = {0,0,0.1,0.1};
		muzzleOuter[] = {0.3,1,0.3,0.2};
		permanent = 0.1;
		temporary = 0.01;
	};
	class FST_Recoil_Light: FST_Recoil_Default
	{
		kickBack[] = {0.01,0.02};
		muzzleOuter[] = {0.1,0.4,0.2,0.2};
		temporary = 0.005;
	};
	class FST_Recoil_Medium: FST_Recoil_Default
	{
		kickBack[] = {0.04,0.07};
		muzzleOuter[] = {0.5,1.5,0.5,0.4};
		temporary = 0.02;
	};
	class FST_Recoil_Heavy: FST_Recoil_Default
	{
		kickBack[] = {0.1,0.12};
		muzzleOuter[] = {1.4,3.5,0.8,0.8};
		temporary = 0.08;
	};
	class FST_Recoil_DC15A: FST_Recoil_Default
	{
		muzzleOuter[] = {0.3,0.8,0.4,0.3};
		kickBack[] = {0.03,0.06};
		temporary = 0.01;
	};
	class FST_Recoil_DC15S: FST_Recoil_Default
	{
		kickBack[] = {0.01,0.02};
		muzzleOuter[] = {0.1,0.55,0.2,0.3};
		permanent = 0.08;
		temporary = 0.005;
	};
	class FST_Recoil_DC15L: FST_Recoil_Default
	{
		muzzleOuter[] = {0.3,0.8,0.4,0.2};
		kickBack[] = {0.02,0.04};
		temporary = 0.01;
	};
	class FST_Recoil_DC15C: FST_Recoil_Default
	{
		muzzleOuter[] = {0.5,1,0.6,0.4};
		kickBack[] = {0.04,0.05};
		temporary = 0.01;
	};
	class FST_Recoil_Z6: FST_Recoil_Default
	{
		muzzleOuter[] = {0.4,1.3,0.7,0.25};
		kickBack[] = {0.015,0.05};
		temporary = 0.005;
	};
	class FST_Recoil_DLT18: FST_Recoil_Default
	{
		kickBack[] = {0.05,0.09};
		permanent = 1;
	};
	class FST_Recoil_DX11: FST_Recoil_Default
	{
		kickBack[] = {0.03,0.07};
		temporary = 0.04;
	};
};
