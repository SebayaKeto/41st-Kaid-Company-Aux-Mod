class CfgPatches {
    class FST_BARC {
        author = "Ghostly, Adjusted by Ruby.";
        requiredVersion = 1;
        requiredAddons[]=
		{
			"A3_Soft_F",
			"A3_Data_F",
			"A3_UI_F",
			"A3_Anims_F",
			"A3_Anims_F_Config_Sdr"
		};
        units[] =
        {
			"FST_BARC",
			"FST_BARC_Dirty",
			"FST_BarcSideCar_Dirty"
        };
        weapons[] = {};
    };
};


class CfgVehicles
{
    class ls_vehicle_barc_base;
    class FST_BARC: ls_vehicle_barc_base
    {
        scope = 2;
        scopecurator=2;
        scopearsenal=2;
        tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
        side=1;
        displayName="[41st] BARC";
        
        faction="FST_Faction";
        editorSubcategory="FST_Ground_Vehicle";
        crew="FST_Pilot_P1";
        author="Ghostly, Adjusted by Ruby";
        model="ls\core\addons\vehicles_barc\ls_vehicle_barc.p3d";
        hiddenSelections[]=
        {
            "body",
            "weapons",
            "dashboard"
        };
        hiddenSelectionsTextures[]=
        {
            "\41st_Vehicles\Barc\Data\FST_BARC_body.paa",
            "\41st_Vehicles\Barc\Data\FST_BARC_weapons.paa",
            "\41st_Vehicles\Barc\Data\FST_BARC_Dash.paa"
        };
        weapons[]=
        {
            "ls_speeder_AP"
        };
        magazines[]=
        {  
            "ls_magazine_speederHE_belt",
            "ls_magazine_speederHE_belt",
            "ls_magazine_speederHE_belt"
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
    ace_cargo_hasCargo=1;
    ace_cargo_space=1000;
        class TransportMagazines{};
        class TransportItems{};
        class TransportWeapons{};
        class TransportBackpacks{};
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
    };
	class FST_BARC_Dirty: FST_BARC
    {
        scope = 2;
        scopecurator=2;
        scopearsenal=2;
        side=1;
        displayName="[41st] BARC (Dirty)";
        author="Gold";
        model="ls\core\addons\vehicles_barc\ls_vehicle_barc.p3d";
        hiddenSelections[]=
        {
            "body",
            "weapons",
            "dashboard"
        };
        hiddenSelectionsTextures[]=
        {
            "\41st_Vehicles\Barc\Data\FST_BARC_body_Dirty.paa",
            "\41st_Vehicles\Barc\Data\FST_BARC_weapons_Dirty.paa",
            "\41st_Vehicles\Barc\Data\FST_BARC_Dash_Dirty.paa"
        };
    };
	class 3AS_BarcSideCar;
	class FST_BarcSideCar_Dirty: 3AS_BarcSideCar
	{
		displayname="[41st] BARC Speeder Sidecar (Dirty)";
		scope = 2;
        scopecurator=2;
        scopearsenal=2;
        side=1;
		faction="FST_Faction";
        editorSubcategory="FST_Ground_Vehicle";
		hiddenSelections[]=
		{
			"camo",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\BARC\Data\FST_BARC_Sidecar_Body.paa",
			"41st_Vehicles\BARC\Data\FST_BARC_Sidecar_Gunner.paa"
		};
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
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
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
        class TransportMagazines{};
        class TransportItems{};
        class TransportWeapons{};
        class TransportBackpacks{};
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
	};
};   