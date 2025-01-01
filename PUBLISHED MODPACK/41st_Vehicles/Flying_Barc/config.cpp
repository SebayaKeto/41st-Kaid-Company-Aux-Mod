class CfgPatches
{
	class FST_BARC
	{
		author="Ghostly";
		requiredaddons[]=
		{};
		requiredversion=1;
		units[]=
		{
			"FST_BARC",
			"FST_BARC_Heil",
		};
		weapons[]={};
	};
};
class Extended_init_EventHandlers
{
	class FST_BARC_Heil
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
		};
	};
};	
class CfgVehicles
{
	class Helicopter;
	class Helicopter_Base_F: Helicopter
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class CargoTurret;
		class ACE_selfActions;
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class Viewoptics;
		class ViewPilot;
		class RotorLibHelicopterProperties;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitHRotor;
			class HitVRotor;
			class HitAvionics;
		};
	};
	class 3as_laat_Base: Helicopter_Base_H
	{
	};
	class FST_LAAT: 3as_laat_Base
	{
	};
	class ls_barc_base;
	class FST_BARC: ls_barc_base
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		side=1;
		displayName="[41st] BARC";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Pilot_P1";
		author="Ghostly";
		hiddenSelections[]=
		{
			"body",
			"weapons",
			"dashboard"
		};
        hiddenSelectionsTextures[]=
        {
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_body.paa",
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_weapons.paa",
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_Dash.paa"
        };
		weapons[]=
		{
			"ls_speeder_AP"
		};
		magazines[]=
		{
			"ls_50Rnd_speederHE_belt",
			"ls_50Rnd_speederHE_belt",
			"ls_50Rnd_speederHE_belt"
		};
		canFloat=1;
		acceleration=10;
		brakeDistance=1;
        maxSpeed=300;    ////// CHANGE It goes up to 200kmh max not 300 
        waterLeakiness=2.5;
        waterPPInVehicle=0;
        waterAngularDampingCoef=0.5;
        waterResistanceCoef=0.0049999999;
        waterSpeedFactor=1;
        waterSpeedCoef=3;
        armor=300;
        accelAidForceCoef=30;
        accelAidForceSpd=20;
        waterLinearDampingCoefY=10;
        fuelCapacity=50;
        idleRpm=1000;
        redRpm=7000;
        enginePower=600; 
        minOmega=50; ////// CHANGE less to have it rev a bit more instead of jumping too fast
        maxOmega=800; ////// CHANGE less to have it go up in more gears instead of immediatly flying to max speed
        peakTorque=2500; ////// CHANGE less to have it go up in more gears instead of immediatly flying to max speed
		normalSpeedForwardCoef=0.5;
		slowSpeedForwardCoef=0.25;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				2.45,
				"D2",
				0.7,
				"D3",
				0.7,
			};
			AmphibiousRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				2.45,
				"D2",
				0.7,
				"D3",
				0.7,
			};
			TransmissionRatios[]=
			{
				"High",
				3.45
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		class Wheels
		{
			class LF
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				width=0.2;
				mass=4000;
				MOI=5.3000002;
				dampingRate=0.5;
				maxBrakeTorque=3000;
				maxHandBrakeTorque=1500;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.1;
				mMaxDroop=0.050000001;
				sprungMass=272.5;
				springStrength=27250;
				springDamperRate=6725;
				longitudinalStiffnessPerUnitGravity=100000;
				latStiffX=25;
				latStiffY=18000;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class LR: LF
			{
				boneName="wheel_1_2_damper";
				steering=0;
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
				maxHandBrakeTorque=3000;
			};
			class RF: LF
			{
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				steering=1;
			};
			class RR: RF
			{
				boneName="wheel_2_2_damper";
				steering=0;
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
				maxHandBrakeTorque=3000;
			};
		};
		class UserActions
		{
			class Flip
			{
				displayNameDefault="Press SPACEBAR to Flip Warthog";
				displayName="Press SPACEBAR to Flip Warthog";
				position="";
				radius=6;
				onlyForPlayer=1;
				condition="(alive this) AND !(canmove this)";
				statement="this setposATL [getPosATL this select 0, getPosATL this select 1, (getPosATL this select 2) + 4]; this setVectorUp surfaceNormal getposATL this;";
			};
		};
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
		class TransportMagazines{};
		class TransportItems{};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
	class FST_BARC_Heil: FST_LAAT
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		side=1;
		displayName="[41st] BARC [Experimental/FLY]";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Pilot_P1";
		model="\ls_vehicles_ground\barc\ls_ground_barc";
		Icon="\ls_vehicles_ground\_ui\icons\barc_icon.paa";
		editorpreview="\ls_vehicles_ground\_ui\editorPreviews\image_barc.jpg";
		author="Ghostly";
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
		fuelCapacity=8000;
		maxSpeed=200;
		fuelConsumptionRate=0.2;
        ls_impulsor_fuelDrain_1=9.9999997e-005;
        ls_impulsor_fuelDrain_2=9.9999997e-005;
        ls_impulsor_boostSpeed_1=50;
        ls_impulsor_boostSpeed_2=200;
        ls_hasImpulse=1;
		transportSoldier=0;
		class Turrets: Turrets
		{
			delete Copilot;
			delete LeftDoorgun;
			delete RightDoorGun;
		};
		class HitPoints: HitPoints
		{
			class HitFuel: HitFuel
			{
				visual="";
				radius=0.1;
				explosionShielding=2;
			};
			class HitHull: HitHull
			{
				armor=999;
				visual="zbytek";
				depends="Total";
				radius=0.0099999998;
			};
			class HitEngine: HitEngine
			{
				visual="";
				radius=0.2;
				explosionShielding=2;
			};
			class HitAvionics: HitAvionics
			{
				armor=1;
				visual="";
				radius=0.5;
				explosionShielding=2;
			};
			class HitHRotor: HitHRotor
			{
				visual="Rotor_1_static";
				armor=300000;
				radius=0.0099999998;
				explosionShielding=2.5;
			};
			class HitVRotor: HitVRotor
			{
				visual="Rotor_2_static";
				armor=200000;
				radius=0.0;
				explosionShielding=6;
			};
		};
		driveOnComponent[]=
		{
			"Wheel_1",
			"Wheel_2",
			"Wheel_3"
		};
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=2;
				initPhase=0;
			};
			class Door_1
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Door_2
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Door_3
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Door_4
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Door_5
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		hiddenSelections[]=
		{
			"body",
			"weapons",
			"dashboard"
		};
        hiddenSelectionsTextures[]=
        {
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_body.paa",
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_weapons.paa",
            "\41st_Vehicles\Flying_Barc\Data\FST_BARC_Dash.paa"
        };
		weapons[]=
		{
			"ls_speeder_AP"
		};
		magazines[]=
		{
			"ls_50Rnd_speederHE_belt",
			"ls_50Rnd_speederHE_belt",
			"ls_50Rnd_speederHE_belt"
		};
		memoryPointGun[]=
		{
			"gun_driver_l",
			"gun_driver_r"
		};
		driverAction="ls_driver_barc";
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		attenuationEffectType="CarAttenuation";
		cost=20000;
		altFullForce=14;
		altNoForce=20;
		selectionHRotorMove="Rotor_1_blur";
		selectionHRotorStill="Rotor_1_static";
		selectionVRotorMove="Rotor_2_blur";
		selectionVRotorStill="Rotor_2_static";
		threat[]={0.1,0.1,0.1};
		maxMainRotorDive=7;
		minMainRotorDive=-7;
		neutralMainRotorDive=0;
		gearRetracting=1;
		mainRotorSpeed=-1;
		backRotorSpeed=1;
		startDuration=5;
		liftForceCoef=1.2;
		cyclicAsideForceCoef=0.60000002;
		cyclicForwardForceCoef=0.69999999;
		bodyFrictionCoef=0.69999999;
		backRotorForceCoef=1.2;
		radarTargetSize=0.69999999;
		visualTargetSize=0.80000001;
		irTargetSize=0.80000001;
		lockDetectionSystem="8 + 4";
		incomingMissileDetectionSystem="8 + 16";
		airBrake=70;
		airBrakeFrictionCoef=60;
		class TransportMagazines{};
		class TransportItems{};
		class TransportWeapons{};
		class TransportBackpacks{};
	};
};