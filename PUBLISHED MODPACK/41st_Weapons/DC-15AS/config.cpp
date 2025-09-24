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
			"FST_DC15A_Wood",
			"FST_DC15A_ugl",
			"FST_DC15S",
			"FST_DC15S_UGL",
			"FST_DC15C_F",
			"FST_DC15LE",
			"FST_Mercenary_DC15S_UGL_Wood"
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
class CfgWeapons
{
	class JLTS_stun_muzzle;
	class UGL_F;
	class WeaponSlotsInfo;
	class Rifle_Base_F;
	class IDA_DC15A;
	class FST_DC15A: IDA_DC15A
	{
		author="Gold";
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=0;
		JLTS_friedItem="FST_DC15A_fried";
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
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
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
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class IDA_DC15A_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=100;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"3AS_optic_holo_DC15S",
					"FST_Attachment_Optic_Holo_DC15",
				//	"3AS_Optic_Red_DC15A"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"FST_Knife",
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
	};
	class FST_DC15A_Wood: FST_DC15A
	{
		author="Gold";
		displayName="[41st] DC-15A Rifle (Wood)";
		model="\MRC\JLTS\weapons\DC15A\DC15A.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"illum"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\DC15A\data\DC15A_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"
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
			"EGLM",
			"Stun"
		};
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
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
			discreteDistanceInitIndex=1;
			magazines[]=
			{
				"FST_HE_LauncherGrenade",
				"FST_HE_LauncherGrenade_Delayed_5",
				//"FST_TDHE_LauncherGrenade",
				"FST_Smoke_LauncherGrenade",
				"FST_SmokeRed_LauncherGrenade",
				"FST_SmokeGreen_LauncherGrenade",
				"FST_SmokeBlue_LauncherGrenade",
				"FST_SmokePurple_LauncherGrenade",
				"FST_Droid_Popper_Launcher",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_40mm_Flare_ir",
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
			class Stun: JLTS_stun_muzzle{};
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
					"3AS_optic_holo_DC15S",
					"FST_Attachment_Optic_Holo_DC15"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"FST_Knife",
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
	};
	class FST_DC15LE: IDA_DC15A
	{
		author="Gold";
		baseWeapon="FST_DC15LE";
		displayName="[41st] DC-15LE Designated Marksman Rifle";
		descriptionShort="Long range, slow rate of fire.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15LE\Model\IDA_DC15LE.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"Indecisive_Armoury_Anims\Republic\DC15A.rtm"
		};
		reloadAction="GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg",
			5,
			1,
			100
		};
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
			"Single"
		};
		muzzles[]=
		{
			"this"
		};
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
        /*      linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
                compatibleItems[]=
                {
					"3AS_Optic_Red_DC15A",
                    "FST_Optic_LEScope_DC15LE"
                };*/
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
		class LinkedItems
		{
			class LinkedItemsMuzzleSlot
			{
				slot="MuzzleSlot";
				item="3AS_Muzzle_LE_DC15A";
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
	class IDA_DC15S;
	class FST_DC15S: IDA_DC15S
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=0;
		JLTS_friedItem="FST_DC15S_fried";
		JLTS_repairTime=5;
		IDA_plasmabolt=1;
		IDA_heatpershot=1;
		IDA_maxheat=1;		
		IDA_cooldownTime=15;
		JLTS_canHaveShield=1;
		JLTS_shieldedWeapon="IDA_DC15S_shield";
		author="Gold";
		baseWeapon="FST_DC15S";
		displayName="[41st] DC-15S carbine";
		descriptionShort="Close range, fast rate of fire.";
		picture="\MRC\JLTS\weapons\DC15S\data\ui\DC15S_ui_ca.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\Model\IDA_DC15S.p3d";
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
			reloadTime=0.1;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class IDA_DC15S_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
			//		"3AS_optic_holo_DC15S",
					"FST_Attachment_Optic_Holo_DC15"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
			//		"FST_Knife",
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
	};
	class FST_DC15S_UGL: FST_DC15S
	{
		baseWeapon="FST_DC15S_UGL";
		recoil="FST_recoil_dc15s";
		displayName="[41st] DC-15S Carbine w/ UGL";
		scope=2;
		picture="\MRC\JLTS\weapons\DC15S\data\ui\DC15S_ui_ca.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\Model\IDA_DC15S_UGL.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_beta\Rifles\MK20\Data\Anim\mk20G.rtm"
		};
		muzzles[]=
		{
			"This",
			"Stun",
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
				"FST_HE_LauncherGrenade_Delayed_5",
				"FST_Smoke_LauncherGrenade",
				"FST_SmokeRed_LauncherGrenade",
				"FST_SmokeGreen_LauncherGrenade",
				"FST_SmokeBlue_LauncherGrenade",
				"FST_SmokePurple_LauncherGrenade",
				"FST_Droid_Popper_Launcher",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_40mm_Flare_ir",
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
			class Stun: JLTS_stun_muzzle{};
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
				compatibleItems[]=
				{
					"FST_Attachment_Optic_Holo_DC15"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
				//	"FST_Knife",
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
	};
	class FST_Mercenary_DC15S_UGL_Wood: FST_DC15S_UGL
	{
		displayName="[41st] Mercenary DC-15S Carbine w/ UGL";
		baseWeapon= "FST_Mercenary_DC15S_UGL_Wood";
		recoil="FST_recoil_dc15s";
		picture="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\DC15S_UGL_ui.paa";
		model="DBA_Republic\Addons\DBA_Weapons\DBA_DC15C\DC15SGL.p3d";
		scope=2;
		scopeArsenal=2;
		hiddenSelections[]={};
		hiddenSelectionsTextures[]={};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_beta\Rifles\MK20\Data\Anim\mk20G.rtm"
		};
		muzzles[]=
		{
			"This",
			"EGLM_DC15S_WOOD"
		};
		modes[]=
		{
			"FullAuto",
			"Single",
		};
		class EGLM_DC15S_WOOD: UGL_F
		{
			displayName="[41st] DC15S-GL";
			descriptionShort="GL for the DC15S Wood Platform";
			useModelOptics=0;
			useExternalOptic=0;
			magazines[]=
			{
				"IDA_HE_LauncherGrenade",
				"FST_HE_LauncherGrenade",
				"FST_HE_LauncherGrenade_Delayed_5",
				"IDA_Smoke_LauncherGrenade",
				"IDA_SmokeRed_LauncherGrenade",
				"IDA_SmokeGreen_LauncherGrenade",
				"IDA_SmokeBlue_LauncherGrenade",
				"IDA_SmokePurple_LauncherGrenade",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_40mm_Flare_ir",
				"ACE_HuntIR_M203",
				"FST_thermal_slug_mag_Blue",
				"FST_thermal_slug_mag_Green",
				"FST_thermal_slug_mag_Red",
				"FST_thermal_slug_mag_Yellow"
			};
			cameraDir="OP_look";
			discreteDistance[]={50,100,150,200};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
			magazineWell[]={};
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
				access=1;
				compatibleItems[]=
				{
				//	"optic_MRCO",
					"DBA_MRCO_A",
					"DBA_MRCO_B"
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
	class FST_DC15C_Base_F: Rifle_Base_F
	{
		author="Daara";
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
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
					"3AS_optic_reflex_DC15C",
					"FST_Attachment_Optic_Holo_DC15"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
		//			"FST_Knife",
				};
			};
            class PointerSlot: PointerSlot
            {
                compatibleItems[]=
                {
                    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White"
                };
            };
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
		descriptionShort="DC-15C Carbine";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3as\3AS_Weapons\Republic\DC15C\Data\Anim\New_DC15C_Handanim.rtm"
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
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=0;
		JLTS_friedItem="FST_DC15C_fried";
		displayName="[41st] DC-15C Carbine";
		model="\3AS\3AS_Weapons\Republic\DC15C\3AS_DC15C_F.p3d";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=100;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class IDA_DC15A_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=100;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
				//	"3AS_optic_reflex_DC15C",
					"FST_Attachment_Optic_Holo_DC15"
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
                    "FST_Attachment_Module_Light_Beam_White"
                };
            };
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
	class FST_DC15A_fried: FST_DC15A
	{
		baseWeapon="FST_DC15A_fried";
		displayname = "[41st] DC-15A (Fried)";
		scope = 1;
		magazines[]={};
		JLTS_isFried=1;
	};
	class FST_DC15S_fried: FST_DC15S
	{
		baseWeapon="FST_DC15S_fried";
		displayname = "[41st] DC-15S (Fried)";
		scope = 1;
		magazines[]={};
		JLTS_isFried=1;
	};
	class FST_DC15C_fried: FST_DC15C_F
	{
		baseWeapon="FST_DC15C_fried";
		displayname = "[41st] DC-15C (Fried)";
		scope = 1;
		magazines[]={};
		JLTS_isFried=1;
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
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class FST_Attachment_Optic_Holo_DC15: ItemCore
	{
		author="Vengence";
		scope=2;
		displayName="[41st] Holo Optic";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="JLTS_EA_Scopes\SEA_Scope_One_blue.p3d";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=6;
			modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
			optics=2;
			class OpticsModes
			{
				class Iron
				{
					opticsID=1;
					useModelOptics=0;
					opticsPPEffects[]=
					{
						"",
						""
					};
					opticsZoomMin=0.25;
					opticsZoomMax=1.25;
					opticsZoomInit=0.75;
					discreteDistance[]={60};
					discreteDistanceInitIndex=0;
					distanceZoomMin=200;
					distanceZoomMax=200;
					memoryPointCamera="opticView"; //eye
					visionMode[]={};
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
				};
				class AlternateScope
				{
					opticsID=2;
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsRadialBlur1",
						"OpticsBlur1"
					};
					opticsZoomMin=0.25;
					opticsZoomMax=1.25;
					opticsZoomInit=0.75;
					discreteDistance[]={60};
					discreteDistanceInitIndex=0;
					distanceZoomMin=200;
					distanceZoomMax=200;
					memoryPointCamera="opticView"; //eye
					visionMode[]={};
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					cameraDir="";
				};
			};
		};
	};
};
