class CfgPatches
{
	class FST_JMSLLTE_vehair_N1fighter
	{
		requiredAddons[]=
		{
			"A3_Air_F_Exp"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_JMSLLTE_N1fighter_jinata_F"
		};
		weapons[]={};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class CfgVehicles
{
	class Plane;
	class Plane_Base_F: Plane
	{
		class HitPoints;
	};
	class VTOL_Base_F: Plane_Base_F
	{
		class AnimationSources;
		class EventHandlers;
		class NewTurret;
		class CargoTurret;
		class Components;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
	};
	class FST_JMSLLTE_N1fighter_base_F: VTOL_Base_F
	{
		author="JMax";
		_generalMacro="FST_JMSLLTE_N1fighter_base_F";
		scope=0;
		side=0;
		scopeCurator=0;
		displayName="TIEf";
		model="\JMSLLTE_veh_air_m\N1\n1.p3d";
		icon="\JMSLLTE_veh_air\N1\data\ico_N1.paa";
		picture="\JMSLLTE_veh_air\N1\data\pic_N1.paa";
		vehicleClass="Air";
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Air_Vehicle";
		destrType="DestructWreck";
		HeadAimDown=-12;
		driverAction="JMSLLTE_pilot_n1";
		getInAction="GetInHigh";
		getOutAction="GetOutHigh";
		driverCompartments="Compartment1";
		driverCanEject=0;
		driverLeftHandAnimName="";
		driverRightHandAnimName="Stick_control_1";
		driverLeftLegAnimName="Pedals_1_left_2";
		driverRightLegAnimName="Pedals_1_right_2";
		memoryPointTaskMarker="TaskMarker_1_pos";
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		memoryPointCM[]=
		{
			"Flare_launcher_1_pos",
			"Flare_launcher_2_pos"
		};
		memoryPointCMDir[]=
		{
			"Flare_launcher_1_dir",
			"Flare_launcher_2_dir"
		};
		extCameraPosition[]={0,1,-25};
		transportSoldier=0;
		accuracy=0.5;
		armor=100;
		armorStructural=4;
		explosionShielding=1;
		epeImpulseDamageCoef=70;
		ejectSpeed[]={0,-2,0};
		damageResistance=0.0099999998;
		laserScanner=1;
		showAllTargets=4;
		showCrewAim=0;
		radarTargetSize=1.4;
		visualTargetSize=1.2;
		irTargetSize=1.4;
		lockDetectionSystem="8 + 4";
		incomingMissileDetectionSystem="8 + 16";
		maximumLoad=3000;
		supplyRadius=5;
		getInRadius=3;
		selectionRotorStill="Rotors_static";
		selectionRotorMove="Rotors_blur";
		cabinOpening=0;
		gearRetracting=1;
		driveOnComponent[]=
		{
			"skids"
		};
		memoryPointLRocket="r1";
		memoryPointRRocket="r2";
		memoryPointLMissile="r1";
		memoryPointRMissile="r2";
		memoryPointGun[]=
		{
			"usti_hlavneL",
			"usti_hlavneR"
		};
		gunBeg[]=
		{
			"usti_hlavneL",
			"usti_hlavneR"
		};
		gunEnd[]=
		{
			"konec_hlavneL",
			"konec_hlavneR"
		};
		weapons[]={};
		magazines[]={};
		maxSpeed=570;
		landingAoa="10*3.1415/180";
		landingSpeed=0;
		stallSpeed=210;
		stallWarningTreshold=0.2;
		wheelSteeringSensitivity=0.69999999;
		airBrake=1;
		flaps=1;
		flapsFrictionCoef=0;
		angleOfIndicence="1*3.1415/180";
		envelope[]={0,0.01,0.2,2.5,3.5,4,4.5,4.5,4.5,4.2,3.8,3.2,2.5,1};
		altNoForce=11000;
		altFullForce=9000;
		throttleToThrustLogFactor=2;
		thrustCoef[]={1.42,1.17,1.15,1.14,1.13,1.12,1.1,1.0700001,0.99000001,0.2,0,0,0};
		aileronSensitivity=0.7;
		aileronCoef[]={0.6, 0.7, 0.9, 1, 1, 0.7, 0.5};
		elevatorSensitivity=0.90999997;
		elevatorCoef[]={0.2,0.38999999,0.50999999,0.60000002,0.68000001,0.75,0.80000001,0.85000002,0.89999998,0.74000001,0.30000001};
		rudderInfluence=0.866;
		rudderCoef[]={0.2,0.5,1,1.5,1.8,2.0999999,2.4000001,2.5,2.5999999,2.7,2.7,0.80000001,0.40000001};
		aileronControlsSensitivityCoef=1.2;
		elevatorControlsSensitivityCoef=4;
		rudderControlsSensitivityCoef=2;
		draconicForceXCoef=3;
		draconicForceYCoef=1;
		draconicForceZCoef=1;
		draconicTorqueXCoef[]={3,2.5,2.3,2.0,1.7,1.6,1.6,1.7,1.8,1.9,2.0};
		draconicTorqueYCoef[]={0.5,1,2,2.3,3,2.5999999,2.4000001,2.2,2,1.9,1.8};
		vtol=4;
		VTOLYawInfluence=6;
		VTOLPitchInfluence=2;
		VTOLRollInfluence=8;
		maxOmega=2000;
		class MarkerLights
		{
			class CollisionLightRed1
			{
				color[]={0.80000001,0,0};
				ambient[]={0.079999998,0,0};
				intensity=75;
				name="pos_collision_light_red_1";
				drawLight=1;
				drawLightSize=0.25;
				drawLightCenterSize=0.050000001;
				activeLight=0;
				blinking=0;
				dayLight=0;
				useFlare=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=25;
					quadratic=50;
					hardLimitStart=0.75;
					hardLimitEnd=1;
				};
			};
			class CollisionLightRed2: CollisionLightRed1
			{
				name="pos_collision_light_red_2";
			};
			class CollisionLightGreen1: CollisionLightRed1
			{
				color[]={0,0.80000001,0};
				ambient[]={0,0.079999998,0};
				name="pos_collision_light_green_1";
			};
			class CollisionLightGreen2: CollisionLightGreen1
			{
				name="pos_collision_light_green_2";
			};
			class CollisionLightWhite1: CollisionLightRed1
			{
				color[]={1,1,1};
				ambient[]={0.1,0.1,0.1};
				name="pos_collision_light_white_1";
				blinking=1;
				blinkingStartsOn=1;
				blinkingPattern[]={0.1,0.89999998};
				blinkingPatternGuarantee=1;
				drawLightSize=0.34999999;
				drawLightCenterSize=0.050000001;
			};
		};
		class MFD
		{
			class AirplaneHUD
			{
				topLeft="HUD_top_left";
				topRight="HUD_top_right";
				bottomLeft="HUD_bottom_left";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0.15000001,0.15000001,1,1};
				helmetMountedDisplay=1;
				helmetPosition[]={-0.037500001,0.037500001,0.1};
				helmetRight[]={0.075000003,0,0};
				helmetDown[]={0,-0.075000003,0};
				font="LucidaConsoleB";
				class Bones
				{
					class HUDCenter
					{
						type="fixed";
						pos[]={0.5,0.5};
					};
					class HorizonBankSource
					{
						type="rotational";
						source="HorizonBank";
						center[]={0.5,0.5};
						min=-6.2831001;
						max=6.2831001;
						minAngle=-360;
						maxAngle=360;
					};
					class HorizonDiveSource
					{
						source="horizonDive";
						type="linear";
						min=-1;
						max=1;
						minPos[]={0.5,2.5};
						maxPos[]={0.5,-1.5};
					};
					class VelocityVector
					{
						type="vector";
						source="velocityToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class ForwardVector
					{
						type="vector";
						source="forward";
						pos0[]={0,0};
						pos10[]={0.234,0.23};
					};
					class GunnerAim
					{
						type="vector";
						source="turret";
						pos0[]={0,-0.5};
						pos10[]={0.0068000001,-0.012};
						projection=0;
					};
					class WeaponAim
					{
						type="vector";
						source="weaponToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class TargetingPodTarget
					{
						source="pilotcameratoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class SliderDiveSource
					{
						type="linear";
						source="horizonDive";
						min="RAD(-10)";
						max="RAD(10)";
						minPos[]={0.105,0.38};
						maxPos[]={0.105,0.54000002};
					};
					class SliderDiveSource30: SliderDiveSource
					{
						min="RAD(10)";
						max="RAD(30)";
						minPos[]={0,-0.039999999};
						maxPos[]=
						{
							0,
							"0)"
						};
					};
					class SliderDiveSource90: SliderDiveSource30
					{
						min="RAD(30)";
						max="RAD(90)";
						minPos[]={0,-0.039999999};
					};
					class SliderDiveSource30m: SliderDiveSource
					{
						min="RAD(-30)";
						max="RAD(-10)";
						minPos[]={0,0};
						maxPos[]={0,0.039999999};
					};
					class SliderDiveSource90m: SliderDiveSource30m
					{
						min="RAD(-90)";
						max="RAD(-30)";
						maxPos[]={0,0.039999999};
					};
					class SliderAltitudeSource
					{
						type="linear";
						source="altitudeAGL";
						sourceOffset=-3;
						min=0;
						max=1000;
						minPos[]={0.88499999,0.2};
						maxPos[]={0.88499999,0.375};
					};
					class GForceSource
					{
						type="linear";
						source="gmeter";
						sourceScale=0.15000001;
						min=-1;
						max=3;
						minPos[]={0.105,0.69999999};
						maxPos[]={0.105,0.86000001};
					};
					class SliderVSpeedSource
					{
						type="linear";
						source="vspeed";
						min=-15;
						max=15;
						minPos[]={0.79500002,0.60000002};
						maxPos[]={0.79500002,0.83999997};
					};
					class ImpactPoint
					{
						type="vector";
						source="ImpactPointToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class WPPoint
					{
						type="vector";
						source="WPPointToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class rtdRPM1
					{
						type="linear";
						source="rpm";
						min=0.1;
						max=1;
						minPos[]={0,-0.075000003};
						maxPos[]={0,0};
					};
					class rtdRPM2: rtdRPM1
					{
						source="rpm";
					};
					class Limit0109
					{
						type="limit";
						limits[]={0.1,0.1,0.89999998,0.89999998};
					};
					class Target
					{
						source="targettoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class ThrustVectoringRotation
					{
						type="rotational";
						source="vtolvectoring";
						sourceScale=100;
						center[]={0.059999999,0.145};
						min=0;
						max=100;
						minAngle=0;
						maxAngle=-90;
						aspectRatio=0.98290598;
					};
					class MissileFlightTimeRot1
					{
						type="rotational";
						source="MissileFlightTime";
						sourceScale=0.46000001;
						center[]={0,0};
						min=0;
						max=0.5;
						minAngle=0;
						maxAngle=18;
						aspectRatio=0.98290598;
					};
					class MissileFlightTimeRot2: MissileFlightTimeRot1
					{
						maxAngle=36;
						max=1;
					};
					class MissileFlightTimeRot3: MissileFlightTimeRot1
					{
						maxAngle=54;
						max=1.5;
					};
					class MissileFlightTimeRot4: MissileFlightTimeRot1
					{
						maxAngle=72;
						max=2;
					};
					class MissileFlightTimeRot5: MissileFlightTimeRot1
					{
						maxAngle=90;
						max=2.5;
					};
					class MissileFlightTimeRot6: MissileFlightTimeRot1
					{
						maxAngle=108;
						max=3;
					};
					class MissileFlightTimeRot7: MissileFlightTimeRot1
					{
						maxAngle=126;
						max=3.5;
					};
					class MissileFlightTimeRot8: MissileFlightTimeRot1
					{
						maxAngle=144;
						max=4;
					};
					class MissileFlightTimeRot9: MissileFlightTimeRot1
					{
						maxAngle=162;
						max=4.5;
					};
					class MissileFlightTimeRot10: MissileFlightTimeRot1
					{
						maxAngle=180;
						max=5;
					};
					class MissileFlightTimeRot11: MissileFlightTimeRot1
					{
						maxAngle=198;
						max=5.5;
					};
					class MissileFlightTimeRot12: MissileFlightTimeRot1
					{
						maxAngle=216;
						max=6;
					};
					class MissileFlightTimeRot13: MissileFlightTimeRot1
					{
						maxAngle=234;
						max=6.5;
					};
					class MissileFlightTimeRot14: MissileFlightTimeRot1
					{
						maxAngle=252;
						max=7;
					};
					class MissileFlightTimeRot15: MissileFlightTimeRot1
					{
						maxAngle=270;
						max=7.5;
					};
					class MissileFlightTimeRot16: MissileFlightTimeRot1
					{
						maxAngle=288;
						max=8;
					};
					class MissileFlightTimeRot17: MissileFlightTimeRot1
					{
						maxAngle=306;
						max=8.5;
					};
					class MissileFlightTimeRot18: MissileFlightTimeRot1
					{
						maxAngle=324;
						max=9;
					};
					class MissileFlightTimeRot19: MissileFlightTimeRot1
					{
						maxAngle=342;
						max=9.5;
					};
					class MissileFlightTimeRot20: MissileFlightTimeRot1
					{
						maxAngle=360;
						max=10;
					};
					class HorizonBankRotFull
					{
						type="rotational";
						source="horizonBank";
						center[]={0,0};
						min=-3.1415999;
						max=3.1415999;
						minAngle=-180;
						maxAngle=180;
						aspectRatio=1;
					};
					class Airport1
					{
						type="vector";
						source="airportCorner1toview";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class Airport2: Airport1
					{
						source="airportCorner2toview";
					};
					class Airport3: Airport1
					{
						source="airportCorner3toview";
					};
					class Airport4: Airport1
					{
						source="airportCorner4toview";
					};
					class ILS_H
					{
						type="ils";
						pos0[]={0.5,0.5};
						pos3[]={0.57020003,0.5};
					};
					class ILS_W: ILS_H
					{
						pos3[]={0.5,0.56900001};
					};
				};
				class Draw
				{
					alpha=1;
					color[]={0.15000001,0.15000001,1,1};
					condition="(1 - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37))*on";
					class VelocityLine
					{
						type="line";
						width=2;
						points[]=
						{
							
							{
								"HUDCenter",
								1
							},
							
							{
								"VelocityVector",
								1
							},
							{},
							
							{
								"VelocityVector",
								{0,-0.0049145301},
								1
							},
							
							{
								"VelocityVector",
								{0.0024999999,-0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0.0043299999,-0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{0.0049999999,0},
								1
							},
							
							{
								"VelocityVector",
								{0.0043299999,0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{0.0024999999,0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0,0.0049145301},
								1
							},
							
							{
								"VelocityVector",
								{-0.0024999999,0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{-0.0043299999,0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{-0.0049999999,0},
								1
							},
							
							{
								"VelocityVector",
								{-0.0043299999,-0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{-0.0024999999,-0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0,-0.0049145301},
								1
							},
							{}
						};
					};
					class Static
					{
						type="line";
						width=3;
						points[]=
						{
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,0.0099999998},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0,0},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,-0.0099999998},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,0.0099999998},
								1
							},
							{},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.088,0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.088,-0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,-0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,0.015},
								1
							},
							{},
							
							{
								{0.1,0.30000001},
								1
							},
							
							{
								{0.1,0.62},
								1
							},
							{},
							
							{
								{0.1,0.30000001},
								1
							},
							
							{
								{0.079999998,0.30000001},
								1
							},
							{},
							
							{
								{0.1,0.34},
								1
							},
							
							{
								{0.079999998,0.34},
								1
							},
							{},
							
							{
								{0.1,0.38},
								1
							},
							
							{
								{0.079999998,0.38},
								1
							},
							{},
							
							{
								{0.1,0.46000001},
								1
							},
							
							{
								{0.079999998,0.46000001},
								1
							},
							{},
							
							{
								{0.1,0.54000002},
								1
							},
							
							{
								{0.079999998,0.54000002},
								1
							},
							{},
							
							{
								{0.1,0.57999998},
								1
							},
							
							{
								{0.079999998,0.57999998},
								1
							},
							{},
							
							{
								{0.1,0.62},
								1
							},
							
							{
								{0.079999998,0.62},
								1
							},
							{},
							
							{
								"GForceSource",
								{0.015,0.0099999998},
								1
							},
							
							{
								"GForceSource",
								{0,0},
								1
							},
							
							{
								"GForceSource",
								{0.015,-0.0099999998},
								1
							},
							
							{
								"GForceSource",
								{0.015,0.0099999998},
								1
							},
							{},
							
							{
								{0.1,0.68800002},
								1
							},
							
							{
								{0.1,0.81999999},
								1
							},
							{},
							
							{
								{0.1,0.69999999},
								1
							},
							
							{
								{0.079999998,0.69999999},
								1
							},
							{},
							
							{
								{0.1,0.74000001},
								1
							},
							
							{
								{0.079999998,0.74000001},
								1
							},
							{},
							
							{
								{0.1,0.77999997},
								1
							},
							
							{
								{0.079999998,0.77999997},
								1
							},
							{},
							
							{
								{0.1,0.81999999},
								1
							},
							
							{
								{0.079999998,0.81999999},
								1
							},
							{},
							
							{
								{0.40000001,0.86000001},
								1
							},
							
							{
								{0.40000001,0.94},
								1
							},
							
							{
								{0.60000002,0.94},
								1
							},
							
							{
								{0.60000002,0.86000001},
								1
							},
							
							{
								{0.40000001,0.86000001},
								1
							},
							{},
							
							{
								{0.40000001,0.89200002},
								1
							},
							
							{
								{0.40799999,0.89200002},
								1
							},
							{},
							
							{
								{0.60000002,0.89200002},
								1
							},
							
							{
								{0.59200001,0.89200002},
								1
							},
							{},
							
							{
								{0.5,0.86000001},
								1
							},
							
							{
								{0.5,0.86799997},
								1
							},
							{},
							
							{
								{0.5,0.94},
								1
							},
							
							{
								{0.5,0.93199998},
								1
							},
							{},
							
							{
								{0.46000001,0.07},
								1
							},
							
							{
								{0.54000002,0.07},
								1
							},
							
							{
								{0.54000002,0.035},
								1
							},
							
							{
								{0.46000001,0.035},
								1
							},
							
							{
								{0.46000001,0.07},
								1
							},
							{},
							
							{
								{0.15000001,0.115},
								1
							},
							
							{
								{0.85000002,0.115},
								1
							},
							{},
							
							{
								{0,0.95999998},
								1
							},
							
							{
								{1.1,0.95999998},
								1
							},
							{},
							
							{
								{0.47999999,0.5},
								1
							},
							
							{
								{0.49000001,0.5},
								1
							},
							{},
							
							{
								{0.50999999,0.5},
								1
							},
							
							{
								{0.51999998,0.5},
								1
							},
							{},
							
							{
								{0.5,0.49000001},
								1
							},
							
							{
								{0.5,0.47999999},
								1
							},
							{},
							
							{
								{0.5,0.50999999},
								1
							},
							
							{
								{0.5,0.51999998},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{-0.02,0},
								1
							},
							
							{
								"WeaponAim",
								1,
								{-0.0099999998,0},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0.0099999998,0},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0.02,0},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0,-0.0099999998},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0,-0.02},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0,0.0099999998},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0,0.02},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.16500001,7.0890902e-009},
								1
							},
							
							{
								"HUDCenter",
								{-0.22,9.45212e-009},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.16500001,-1.9339701e-009},
								1
							},
							
							{
								"HUDCenter",
								{0.22,-2.57863e-009},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.082500003,0.140452},
								1
							},
							
							{
								"HUDCenter",
								{-0.096249998,0.16385999},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.082500003,0.140452},
								1
							},
							
							{
								"HUDCenter",
								{0.096249998,0.16385999},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.142894,0.081089802},
								1
							},
							
							{
								"HUDCenter",
								{-0.16671,0.094604701},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.142894,0.081089698},
								1
							},
							
							{
								"HUDCenter",
								{0.16671,0.094604701},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.116673,0.114678},
								1
							},
							
							{
								"HUDCenter",
								{-0.155564,0.152904},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.116673,0.114678},
								1
							},
							
							{
								"HUDCenter",
								{0.155563,0.152904},
								1
							},
							{},
							
							{
								{0.033333302,0.14866699},
								1
							},
							
							{
								{0.054000001,0.162},
								1
							},
							
							{
								{0.13500001,0.162},
								1
							},
							
							{
								{0.13500001,0.14866699},
								1
							},
							
							{
								{0.126333,0.139667},
								1
							},
							
							{
								{0.118,0.139667},
								1
							},
							
							{
								{0.093333296,0.129333},
								1
							},
							
							{
								{0.033333302,0.129333},
								1
							},
							
							{
								{0.015666701,0.111},
								1
							},
							
							{
								{0.0086666699,0.115333},
								1
							},
							
							{
								{0.0116667,0.13600001},
								1
							},
							{}
						};
					};
					class Gunner
					{
						type="line";
						width=4;
						points[]=
						{
							
							{
								"GunnerAim",
								{0.48500001,0.89200002},
								1
							},
							
							{
								"GunnerAim",
								{0.48500001,0.90799999},
								1
							},
							
							{
								"GunnerAim",
								{0.51499999,0.90799999},
								1
							},
							
							{
								"GunnerAim",
								{0.51499999,0.89200002},
								1
							},
							
							{
								"GunnerAim",
								{0.48500001,0.89200002},
								1
							}
						};
					};
					class DiveNumber
					{
						type="text";
						source="horizondive";
						sourceScale=57.29578;
						sourceOffset=0;
						align="left";
						scale=1;
						pos[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.085000001,
								"0.00-0.011"
							},
							1
						};
						right[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.12,
								"0.00-0.011"
							},
							1
						};
						down[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.085000001,
								"0.03-0.011"
							},
							1
						};
					};
					class VSpeedGroup
					{
						condition="on";
						class VSpeedNumber
						{
							type="text";
							source="vspeed";
							sourceScale=1;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.82+0.07",
									0.72799999
								},
								1
							};
							right[]=
							{
								
								{
									"0.86+0.07",
									0.72799999
								},
								1
							};
							down[]=
							{
								
								{
									"0.82+0.07",
									0.76300001
								},
								1
							};
						};
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.84899998,0.75999999},
									1
								},
								
								{
									{0.92900002,0.75999999},
									1
								},
								
								{
									{0.92900002,0.72500002},
									1
								},
								
								{
									{0.84899998,0.72500002},
									1
								},
								
								{
									{0.84899998,0.75999999},
									1
								},
								{}
							};
						};
					};
					class VSpeedGroupUp
					{
						condition="vspeed";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.86900002,0.71499997},
									1
								},
								
								{
									{0.90899998,0.71499997},
									1
								},
								
								{
									{0.889,0.69499999},
									1
								},
								
								{
									{0.86900002,0.71499997},
									1
								},
								{}
							};
						};
					};
					class VSpeedGroupDown
					{
						condition="-vspeed";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.86900002,0.76999998},
									1
								},
								
								{
									{0.90899998,0.76999998},
									1
								},
								
								{
									{0.889,0.79000002},
									1
								},
								
								{
									{0.86900002,0.76999998},
									1
								},
								{}
							};
						};
					};
					class AltGroup
					{
						condition="1000 - altitudeAGL";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"SliderAltitudeSource",
									{0.024,0.0099999998},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.0089999996,0},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.024,-0.0099999998},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.024,0.0099999998},
									1
								},
								{},
								
								{
									"SliderAltitudeSource",
									{0.035,0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.093000002,0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.093000002,-0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.035,-0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.035,0.015},
									1
								},
								{},
								
								{
									{0.889,0.2},
									1
								},
								
								{
									{0.889,0.375},
									1
								},
								{},
								
								{
									{0.87900001,0.2},
									1
								},
								
								{
									{0.89899999,0.2},
									1
								},
								{},
								
								{
									{0.87900001,0.375},
									1
								},
								
								{
									{0.89899999,0.375},
									1
								},
								{}
							};
						};
						class AltNumber
						{
							type="text";
							source="altitudeAGL";
							sourceScale=1;
							sourceOffset=-3;
							align="left";
							scale=1;
							pos[]=
							{
								"SliderAltitudeSource",
								
								{
									0.085000001,
									"0.00-0.011"
								},
								1
							};
							right[]=
							{
								"SliderAltitudeSource",
								
								{
									0.11,
									"0.00-0.011"
								},
								1
							};
							down[]=
							{
								"SliderAltitudeSource",
								
								{
									0.085000001,
									"0.03-0.011"
								},
								1
							};
						};
						class AltStatic50
						{
							type="text";
							source="static";
							text="1000";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.88499999,0.171},
								1
							};
							right[]=
							{
								{0.92500001,0.171},
								1
							};
							down[]=
							{
								{0.88499999,0.20100001},
								1
							};
						};
					};
					class SpeedNumber
					{
						type="text";
						source="speed";
						sourceScale=3.5999999;
						sourceLength=3;
						align="left";
						scale=1;
						pos[]=
						{
							{0.13,0.22},
							1
						};
						down[]=
						{
							{0.13,0.25999999},
							1
						};
						right[]=
						{
							{0.2,0.22},
							1
						};
					};
					class Angle_90
					{
						type="text";
						source="static";
						text="90";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.285},
							1
						};
						right[]=
						{
							{0.11,0.285},
							1
						};
						down[]=
						{
							{0.07,0.315},
							1
						};
					};
					class Angle_30
					{
						type="text";
						source="static";
						text="30";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.32499999},
							1
						};
						right[]=
						{
							{0.11,0.32499999},
							1
						};
						down[]=
						{
							{0.07,0.35499999},
							1
						};
					};
					class Angle_10
					{
						type="text";
						source="static";
						text="10";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.36500001},
							1
						};
						right[]=
						{
							{0.11,0.36500001},
							1
						};
						down[]=
						{
							{0.07,0.39500001},
							1
						};
					};
					class Angle_0
					{
						type="text";
						source="static";
						text="0";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.44499999},
							1
						};
						right[]=
						{
							{0.11,0.44499999},
							1
						};
						down[]=
						{
							{0.07,0.47499999},
							1
						};
					};
					class Angle_10m
					{
						type="text";
						source="static";
						text="-10";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.52499998},
							1
						};
						right[]=
						{
							{0.11,0.52499998},
							1
						};
						down[]=
						{
							{0.07,0.55500001},
							1
						};
					};
					class Angle_30m
					{
						type="text";
						source="static";
						text="-30";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.565},
							1
						};
						right[]=
						{
							{0.11,0.565},
							1
						};
						down[]=
						{
							{0.07,0.59500003},
							1
						};
					};
					class Angle_90m
					{
						type="text";
						source="static";
						text="-90";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.60500002},
							1
						};
						right[]=
						{
							{0.11,0.60500002},
							1
						};
						down[]=
						{
							{0.07,0.63499999},
							1
						};
					};
					class GMeterStatic3
					{
						type="text";
						source="static";
						text="3";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.68300003},
							1
						};
						right[]=
						{
							{0.11,0.68300003},
							1
						};
						down[]=
						{
							{0.07,0.713},
							1
						};
					};
					class GMeterStatic2
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.72299999},
							1
						};
						right[]=
						{
							{0.11,0.72299999},
							1
						};
						down[]=
						{
							{0.07,0.75300002},
							1
						};
					};
					class GMeterStatic1
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.76300001},
							1
						};
						right[]=
						{
							{0.11,0.76300001},
							1
						};
						down[]=
						{
							{0.07,0.79299998},
							1
						};
					};
					class GMeterStatic0
					{
						type="text";
						source="static";
						text="0";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.80299997},
							1
						};
						right[]=
						{
							{0.11,0.80299997},
							1
						};
						down[]=
						{
							{0.07,0.833},
							1
						};
					};
					class CollectiveNumber
					{
						type="text";
						source="throttle";
						sourceScale=100;
						align="left";
						scale=1;
						pos[]=
						{
							{0.889,0.46000001},
							1
						};
						right[]=
						{
							{0.93900001,0.46000001},
							1
						};
						down[]=
						{
							{0.889,0.495},
							1
						};
					};
					class CollectiveText
					{
						type="text";
						source="static";
						text="%";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.89899999,0.46000001},
							1
						};
						right[]=
						{
							{0.949,0.46000001},
							1
						};
						down[]=
						{
							{0.89899999,0.495},
							1
						};
					};
					class ThrustVectoring
					{
						condition="1+vtolvectoring";
						class VectorigNumber
						{
							type="text";
							source="vtolvectoring";
							sourceScale=90;
							align="left";
							scale=1;
							pos[]=
							{
								{0.102,0.14},
								1
							};
							right[]=
							{
								{0.127,0.14},
								1
							};
							down[]=
							{
								{0.102,0.155},
								1
							};
						};
						class VectoringArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,-0.0060000001},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.044,0},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,0.0060000001},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,-0.0060000001},
									1
								},
								{},
								
								{
									"ThrustVectoringRotation",
									{-0.044,0},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.0040000002,0},
									1
								},
								{}
							};
						};
					};
					class ThrustVectoringAuto
					{
						condition="-vtolvectoring";
						class VectorigNumber
						{
							type="text";
							source="static";
							sourceScale=1;
							text="AUTO";
							align="left";
							scale=1;
							pos[]=
							{
								{0.103,0.14},
								1
							};
							right[]=
							{
								{0.123,0.14},
								1
							};
							down[]=
							{
								{0.103,0.155},
								1
							};
						};
					};
					class EngineRPM
					{
						type="line";
						width=3;
						points[]=
						{
							
							{
								{0.88999999,0.5},
								1
							},
							
							{
								{0.88999999,0.66000003},
								1
							},
							{},
							
							{
								{0.92000002,0.5},
								1
							},
							
							{
								{0.86000001,0.5},
								1
							},
							{},
							
							{
								{0.92000002,0.66000003},
								1
							},
							
							{
								{0.86000001,0.66000003},
								1
							},
							{},
							
							{
								{0.91000003,0.54000002},
								1
							},
							
							{
								{0.87,0.54000002},
								1
							},
							{},
							
							{
								{0.91000003,0.57999998},
								1
							},
							
							{
								{0.87,0.57999998},
								1
							},
							{},
							
							{
								{0.91000003,0.62},
								1
							},
							
							{
								{0.87,0.62},
								1
							},
							{}
						};
					};
					class EngineRPMLines
					{
						type="line";
						width=5;
						points[]=
						{
							
							{
								
								{
									"0.90+0.01",
									0.66000003
								},
								1
							},
							
							{
								"rtdrpm1",
								
								{
									"0.90+0.01",
									0.66000003
								},
								1
							},
							{},
							
							{
								
								{
									"0.86+0.01",
									0.66000003
								},
								1
							},
							
							{
								"rtdrpm2",
								
								{
									"0.86+0.01",
									0.66000003
								},
								1
							},
							{},
							{}
						};
					};
					class RPM60Text
					{
						type="text";
						source="static";
						text="60";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.64499998},
							1
						};
						right[]=
						{
							{0.95499998,0.64499998},
							1
						};
						down[]=
						{
							{0.92500001,0.67000002},
							1
						};
					};
					class RPM80Text
					{
						type="text";
						source="static";
						text="80";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.60500002},
							1
						};
						right[]=
						{
							{0.95499998,0.60500002},
							1
						};
						down[]=
						{
							{0.92500001,0.63},
							1
						};
					};
					class RPM100Text
					{
						type="text";
						source="static";
						text="100";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.565},
							1
						};
						right[]=
						{
							{0.95499998,0.565},
							1
						};
						down[]=
						{
							{0.92500001,0.58999997},
							1
						};
					};
					class RPM120Text
					{
						type="text";
						source="static";
						text="120";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.52499998},
							1
						};
						right[]=
						{
							{0.95499998,0.52499998},
							1
						};
						down[]=
						{
							{0.92500001,0.55000001},
							1
						};
					};
					class HeadingNumber
					{
						type="text";
						source="heading";
						sourceScale=1;
						align="center";
						scale=1;
						pos[]=
						{
							
							{
								"0.80-0.302",
								"0.082-0.043"
							},
							1
						};
						right[]=
						{
							
							{
								"0.84-0.302",
								"0.082-0.043"
							},
							1
						};
						down[]=
						{
							
							{
								"0.80-0.302",
								"0.117-0.043"
							},
							1
						};
					};
					class HeadingRotationArrow
					{
						condition="5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
						class HeadingArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.51999998,0.079999998},
									1
								},
								
								{
									{0.5,0.11},
									1
								},
								
								{
									{0.47999999,0.079999998},
									1
								},
								
								{
									{0.51999998,0.079999998},
									1
								},
								{}
							};
						};
					};
					class HeadingRotation
					{
						condition="abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
						class HeadingHeadNumber
						{
							type="text";
							source="cameraDir";
							sourceScale=1;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.80-0.302",
									"0.082+0.001"
								},
								1
							};
							right[]=
							{
								
								{
									"0.83-0.302",
									"0.082+0.001"
								},
								1
							};
							down[]=
							{
								
								{
									"0.80-0.302",
									"0.113+0.001"
								},
								1
							};
						};
						class HeadingArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.47799999,0.075000003},
									1
								},
								
								{
									{0.52200001,0.075000003},
									1
								},
								
								{
									{0.55199999,0.094999999},
									1
								},
								
								{
									{0.52200001,0.115},
									1
								},
								
								{
									{0.47799999,0.115},
									1
								},
								
								{
									{0.44800001,0.094999999},
									1
								},
								
								{
									{0.47799999,0.075000003},
									1
								},
								{}
							};
						};
					};
					class HeadingScale
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=0.1;
						sourceoffset=0;
						width=3;
						NeverEatSeaWeed=1;
						top=0.15000001;
						center=0.5;
						bottom=0.85000002;
						lineXleft=0.114;
						lineYright=0.12;
						lineXleftMajor=0.114;
						lineYrightMajor=0.13;
						majorLineEach=2;
						numberEach=6;
						step=0.5;
						stepSize=0.034482799;
						align="center";
						scale=1;
						pos[]={0.15000001,0.13};
						right[]={0.20999999,0.13};
						down[]={0.15000001,0.17};
					};
					class HorizonBanking
					{
						type="line";
						width=3;
						clipTL[]={0,0.1};
						clipBR[]={1,0.89999998};
						points[]=
						{
							
							{
								"HorizonBankSource",
								{0.16,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.1,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.085000001,-0.015},
								1
							},
							
							{
								"HorizonBankSource",
								{0.07,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.050000001,0},
								1
							},
							{},
							
							{
								"HorizonBankSource",
								{-0.16,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.1,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.085000001,-0.015},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.07,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.050000001,0},
								1
							},
							{}
						};
					};
					class CoordXNumber
					{
						type="text";
						source="coordinateX";
						sourceScale=0.0099999998;
						sourceLength=3;
						sourceOffset=-0.5;
						align="right";
						scale=1;
						pos[]=
						{
							{0.80900002,0.96100003},
							1
						};
						right[]=
						{
							{0.85900003,0.96100003},
							1
						};
						down[]=
						{
							{0.80900002,0.99599999},
							1
						};
					};
					class CoordYNumber: CoordXNumber
					{
						source="coordinateY";
						pos[]=
						{
							{0.89899999,0.96100003},
							1
						};
						right[]=
						{
							{0.949,0.96100003},
							1
						};
						down[]=
						{
							{0.89899999,0.99599999},
							1
						};
					};
					class Time: CoordXNumber
					{
						source="time";
						text="%X";
						align="left";
						pos[]=
						{
							{0.60500002,0.96100003},
							1
						};
						right[]=
						{
							{0.65499997,0.96100003},
							1
						};
						down[]=
						{
							{0.60500002,0.99599999},
							1
						};
					};
					class CurrentWeapon
					{
						type="text";
						source="weapon";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.97899997,0.889},
							1
						};
						right[]=
						{
							{1.029,0.889},
							1
						};
						down[]=
						{
							{0.97899997,0.92400002},
							1
						};
					};
					class CurrentAmmo: CurrentWeapon
					{
						source="ammo";
						align="left";
						pos[]=
						{
							{0.97899997,0.921},
							1
						};
						right[]=
						{
							{1.029,0.921},
							1
						};
						down[]=
						{
							{0.97899997,0.95599997},
							1
						};
					};
					class CoordXText
					{
						type="text";
						source="static";
						text="GRID:";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.65499997,0.96100003},
							1
						};
						right[]=
						{
							{0.70499998,0.96100003},
							1
						};
						down[]=
						{
							{0.65499997,0.99599999},
							1
						};
					};
					class CoordYText
					{
						type="text";
						source="static";
						text="";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.875,0.96100003},
							1
						};
						right[]=
						{
							{0.92500001,0.96100003},
							1
						};
						down[]=
						{
							{0.875,0.99599999},
							1
						};
					};
					class LightsGroup
					{
						condition="lights";
						class LightsText
						{
							type="text";
							source="static";
							text="LIGHT";
							align="left";
							scale=1;
							pos[]=
							{
								{0.149,0.96100003},
								1
							};
							right[]=
							{
								{0.199,0.96100003},
								1
							};
							down[]=
							{
								{0.149,0.99599999},
								1
							};
						};
					};
					class CollisionLights
					{
						condition="collisionlights";
						class CollisionLightsText
						{
							type="text";
							source="static";
							text="COLL";
							align="left";
							scale=1;
							pos[]=
							{
								{0.30899999,0.96100003},
								1
							};
							right[]=
							{
								{0.359,0.96100003},
								1
							};
							down[]=
							{
								{0.30899999,0.99599999},
								1
							};
						};
					};
					class TargetingPodGroup
					{
						condition="1-pilotcameralock";
						class TargetingPodDir
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"TargetingPodTarget",
									{-0.0070710699,0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									{-0.0212132,0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									{0.0070710699,0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									{0.0212132,0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									{0.0070710699,-0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									{0.0212132,-0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									{-0.0070710699,-0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									{-0.0212132,-0.020850601},
									1
								},
								{}
							};
						};
					};
					class TargetingPodGroupOn
					{
						condition="pilotcameralock";
						class TargetingPodDir
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{-0.0070710699,0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{-0.0212132,0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{0.0070710699,0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{0.0212132,0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{0.0070710699,-0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{0.0212132,-0.020850601},
									1
								},
								{},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{-0.0070710699,-0.0069501898},
									1
								},
								
								{
									"TargetingPodTarget",
									1,
									"Limit0109",
									1,
									{-0.0212132,-0.020850601},
									1
								},
								{}
							};
						};
					};
					class WeaponsLocking
					{
						condition="missilelocking";
						blinkingPattern[]={0.2,0.2};
						blinkingStartsOn=1;
						class Text
						{
							type="text";
							source="static";
							text="LOCKING";
							align="center";
							scale=1;
							pos[]=
							{
								{0.215,0.87970102},
								1
							};
							right[]=
							{
								{0.27500001,0.87970102},
								1
							};
							down[]=
							{
								{0.215,0.928846},
								1
							};
						};
					};
					class TargetInfo
					{
						condition="missilelocked";
						class TargetLockedText
						{
							type="text";
							source="static";
							text="TARGET ACQUIRED";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.19499999,0.85900003},
								1
							};
							right[]=
							{
								{0.235,0.85900003},
								1
							};
							down[]=
							{
								{0.19499999,0.88999999},
								1
							};
						};
						class TimeOfFlightText
						{
							type="text";
							source="static";
							text="TOF:";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.127+0.13",
									0.889
								},
								1
							};
							right[]=
							{
								{0.30199999,0.889},
								1
							};
							down[]=
							{
								
								{
									"0.127+0.13",
									0.92400002
								},
								1
							};
						};
						class DistanceText
						{
							type="text";
							source="static";
							text="DISTANCE:";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.125+0.13",
									0.921
								},
								1
							};
							right[]=
							{
								{0.30000001,0.921},
								1
							};
							down[]=
							{
								
								{
									"0.125+0.13",
									0.95599997
								},
								1
							};
						};
						class TOF_source: CurrentWeapon
						{
							source="missileflighttime";
							align="right";
							pos[]=
							{
								{0.26899999,0.889},
								1
							};
							right[]=
							{
								{0.31900001,0.889},
								1
							};
							down[]=
							{
								{0.26899999,0.92400002},
								1
							};
						};
						class TargetDistance: CurrentWeapon
						{
							source="targetDist";
							sourceLength=0;
							sourcePrecision=1;
							sourceScale=0.001;
							align="right";
							pos[]=
							{
								{0.26899999,0.921},
								1
							};
							right[]=
							{
								{0.31900001,0.921},
								1
							};
							down[]=
							{
								{0.26899999,0.95599997},
								1
							};
						};
					};
					class IncomingMissile
					{
						condition="incomingmissile";
						blinkingPattern[]={0.30000001,0.30000001};
						blinkingStartsOn=1;
						class Text
						{
							type="text";
							source="static";
							text="!INCOMING MISSILE!";
							align="center";
							scale=1;
							pos[]=
							{
								{0.48500001,0.21623901},
								1
							};
							right[]=
							{
								{0.54500002,0.21623901},
								1
							};
							down[]=
							{
								{0.48500001,0.265385},
								1
							};
						};
					};
					class GearGroup
					{
						type="group";
						condition="ils";
						class GearText
						{
							type="text";
							source="static";
							text="GEAR";
							align="center";
							scale=1;
							pos[]=
							{
								{0.5,0.82564098},
								1
							};
							right[]=
							{
								{0.54000002,0.82564098},
								1
							};
							down[]=
							{
								{0.5,0.85512799},
								1
							};
						};
					};
					class ILS
					{
						condition="ils";
						class Glideslope
						{
							clipTL[]={0,0};
							clipBR[]={1,1};
							class ILS
							{
								type="line";
								points[]=
								{
									
									{
										"ILS_W",
										{-0.23999999,0},
										1
									},
									
									{
										"ILS_W",
										{0.23999999,0},
										1
									},
									{},
									
									{
										"ILS_W",
										{-0.23999999,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{-0.23999999,0.0235897},
										1
									},
									{},
									
									{
										"ILS_W",
										{-0.12,-0.0176923},
										1
									},
									
									{
										"ILS_W",
										{-0.12,0.0176923},
										1
									},
									{},
									
									{
										"ILS_W",
										{0,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{0,0.0235897},
										1
									},
									{},
									
									{
										"ILS_W",
										{0.12,-0.0176923},
										1
									},
									
									{
										"ILS_W",
										{0.12,0.0176923},
										1
									},
									{},
									
									{
										"ILS_W",
										{0.23999999,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{0.23999999,0.0235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{0,-0.235897},
										1
									},
									
									{
										"ILS_H",
										{0,0.235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,-0.235897},
										1
									},
									
									{
										"ILS_H",
										{0.024,-0.235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.017999999,-0.117949},
										1
									},
									
									{
										"ILS_H",
										{0.017999999,-0.117949},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,0},
										1
									},
									
									{
										"ILS_H",
										{0.024,0},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.017999999,0.117949},
										1
									},
									
									{
										"ILS_H",
										{0.017999999,0.117949},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,0.235897},
										1
									},
									
									{
										"ILS_H",
										{0.024,0.235897},
										1
									}
								};
							};
							class airport
							{
								type="line";
								points[]=
								{
									
									{
										"airport1",
										1
									},
									
									{
										"airport2",
										1
									},
									
									{
										"airport4",
										1
									},
									
									{
										"airport3",
										1
									},
									
									{
										"airport1",
										1
									}
								};
							};
						};
					};
					class MGun
					{
						condition="-2+(mgun+rocket)*ImpactDistance";
						class Cross
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0393162},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0.02,-0.024},
									1
								},
								
								{
									"ImpactPoint",
									{0.025,-0.030999999},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0,-0.0020000001},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0020000001},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{-0.0020000001,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.0020000001,0},
									1
								},
								{}
							};
						};
						class Circle
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0344017},
									1
								},
								
								{
									"MissileFlightTimeRot1",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot2",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot3",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot4",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot5",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot6",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot7",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot8",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot9",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot10",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot11",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot12",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot13",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot14",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot15",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot16",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot17",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot18",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot19",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot20",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								}
							};
						};
						class Circle_Min_Range
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								}
							};
						};
						class Distance
						{
							type="text";
							source="ImpactDistance";
							sourceScale=0.001;
							sourcePrecision=1;
							max=15;
							align="center";
							scale=1;
							pos[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.079999998},
								1
							};
							right[]=
							{
								"ImpactPoint",
								{0.045000002,-0.079999998},
								1
							};
							down[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.039999999},
								1
							};
						};
					};
					class BombCrosshairGroup
					{
						type="group";
						condition="bomb";
						class BombCrosshair
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0982906},
									1
								},
								
								{
									"ImpactPoint",
									{0.01736,-0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0.034200002,-0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{0.050000001,-0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{0.064280003,-0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{0.0766,-0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{0.086599998,-0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{0.093970001,-0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{0.098480001,-0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{0.1,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.098480001,0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{0.093970001,0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{0.086599998,0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{0.0766,0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{0.064280003,0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{0.050000001,0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{0.034200002,0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{0.01736,0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0982906},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01736,0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{-0.034200002,0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{-0.050000001,0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{-0.064280003,0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0766,0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{-0.086599998,0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{-0.093970001,0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{-0.098480001,0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{-0.1,0},
									1
								},
								
								{
									"ImpactPoint",
									{-0.098480001,-0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{-0.093970001,-0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{-0.086599998,-0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0766,-0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{-0.064280003,-0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{-0.050000001,-0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{-0.034200002,-0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01736,-0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0982906},
									1
								},
								{},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,-0.0196581},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0.014,-0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									
									{
										"+ 0.02",
										0
									},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0.014,0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,0.0196581},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{-0.014,0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									
									{
										"- 0.02",
										0
									},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{-0.014,-0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,-0.0196581},
									1
								},
								{},
								
								{
									"VelocityVector",
									0.001,
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,0},
									1
								},
								
								{
									"VelocityVector",
									1,
									"Limit0109",
									1,
									{0,0},
									1
								}
							};
						};
						class Distance
						{
							type="text";
							source="ImpactDistance";
							sourceScale=0.001;
							sourcePrecision=1;
							max=15;
							align="center";
							scale=1;
							pos[]=
							{
								"ImpactPoint",
								{-0.0020000001,0.11},
								1
							};
							right[]=
							{
								"ImpactPoint",
								{0.045000002,0.11},
								1
							};
							down[]=
							{
								"ImpactPoint",
								{-0.0020000001,0.15000001},
								1
							};
						};
					};
					class WP
					{
						condition="wpvalid";
						class WPdist
						{
							type="text";
							source="wpdist";
							sourceScale=0.001;
							sourcePrecision=1;
							align="left";
							scale=1;
							pos[]=
							{
								{0.935,0.79713702},
								1
							};
							right[]=
							{
								{0.97500002,0.79713702},
								1
							};
							down[]=
							{
								{0.935,0.83448702},
								1
							};
						};
						class WPstatic
						{
							type="text";
							source="static";
							text=">";
							align="center";
							scale=2;
							pos[]=
							{
								{0.94999999,0.79713702},
								1
							};
							right[]=
							{
								{0.97000003,0.79713702},
								1
							};
							down[]=
							{
								{0.94999999,0.83448702},
								1
							};
						};
						class WPIndex
						{
							type="text";
							source="wpIndex";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.95999998,0.79713702},
								1
							};
							right[]=
							{
								{1,0.79713702},
								1
							};
							down[]=
							{
								{0.95999998,0.83448702},
								1
							};
						};
						class WP
						{
							width=1;
							type="line";
							points[]=
							{
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										0.015,
										-0.035
									},
									1
								},
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										0,
										0
									},
									1
								},
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										-0.015,
										-0.035
									},
									1
								}
							};
						};
					};
					class RadarBoxes
					{
						type="radartoview";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
						width=2;
						points[]=
						{
							
							{
								{-0.0020000001,-0.0019658101},
								1
							},
							
							{
								{0.0020000001,-0.0019658101},
								1
							},
							
							{
								{0.0020000001,0.0019658101},
								1
							},
							
							{
								{-0.0020000001,0.0019658101},
								1
							},
							
							{
								{-0.0020000001,-0.0019658101},
								1
							}
						};
					};
					class TargetDiamond
					{
						class shape
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.02,0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.02,-0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,-0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,0.0196581},
									1
								}
							};
						};
					};
					class TargetLocked
					{
						condition="missilelocked";
						class shape
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0294872},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.029999999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0294872},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.029999999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0294872},
									1
								}
							};
						};
					};
				};
			};
			class HMD_CMPilot: AirplaneHUD
			{
				turret[]={-1};
				class Draw
				{
					alpha=1;
					color[]={0.25,0.25,1};
					condition="on - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37)";
					class CMName
					{
						type="text";
						source="cmweapon";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.86900002,0.84899998},
							1
						};
						right[]=
						{
							{0.91900003,0.84899998},
							1
						};
						down[]=
						{
							{0.86900002,0.884},
							1
						};
					};
					class CMCount
					{
						type="text";
						source="cmammo";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.97899997,0.84899998},
							1
						};
						right[]=
						{
							{1.029,0.84899998},
							1
						};
						down[]=
						{
							{0.97899997,0.884},
							1
						};
					};
				};
			};
		};
		waterLeakiness=100;
		waterResistanceCoef=0.029999999;
		class RenderTargets
		{
			class Gunner01_pip
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="Cannon_pip_pos";
					pointDirection="Cannon_pip_dir";
					renderVisionMode=2;
					renderQuality=2;
					fov=0.40000001;
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"JMSLLTE_veh_air\N1\data\n1.rvmat",
				"JMSLLTE_veh_air\N1\data\n1_damage.rvmat",
				"JMSLLTE_veh_air\N1\data\n1_damage.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\JMSLLTE_veh_air\N1\data\n1_base_co.paa",
			"\JMSLLTE_veh_air\Xwing\data\droid_dark_co.paa"
		};
		class TextureSources
		{
			class Tex_N1_Base
			{
				displayName="Base grey";
				author="JMax";
				factions[]=
				{
					"JMSLLTE_empire_fact",
					"JMSLLTE_empireRemnant_fact",
					"JMSLLTE_scumFact",
					"JMSLLTE_NRearlyFact",
					"JMSLLTE_NRFact",
					"JMSLLTE_sawpartisans",
					"JMSLLTE_civilian_fact",
					"JMSLLTE_Jinata_fact"
				};
				textures[]=
				{
					"\JMSLLTE_veh_air\N1\data\n1_base_co.paa",
					"\JMSLLTE_veh_air\Xwing\data\droid_dark_co.paa"
				};
			};
			class Tex_N1_Naboo
			{
				displayName="Naboo Royal Forces";
				author="JMax";
				factions[]=
				{
					"JMSLLTE_empire_fact",
					"JMSLLTE_empireRemnant_fact",
					"JMSLLTE_scumFact",
					"JMSLLTE_NRearlyFact",
					"JMSLLTE_NRFact",
					"JMSLLTE_sawpartisans",
					"JMSLLTE_civilian_fact",
					"JMSLLTE_Jinata_fact"
				};
				textures[]=
				{
					"\JMSLLTE_veh_air\N1\data\n1_naboo_co.paa",
					"\JMSLLTE_veh_air\Xwing\data\droid_red_co.paa"
				};
			};
			class Tex_N1_Jinata
			{
				displayName="Jinata Security";
				author="JMax";
				factions[]=
				{
					"JMSLLTE_empire_fact",
					"JMSLLTE_empireRemnant_fact",
					"JMSLLTE_scumFact",
					"JMSLLTE_NRearlyFact",
					"JMSLLTE_NRFact",
					"JMSLLTE_sawpartisans",
					"JMSLLTE_civilian_fact",
					"JMSLLTE_Jinata_fact"
				};
				textures[]=
				{
					"\JMSLLTE_veh_air\N1\data\n1_Jinata_co.paa",
					"\JMSLLTE_veh_air\Xwing\data\droid_blue2_co.paa"
				};
			};
		};
		textureList[]=
		{
			"Tex_N1_Base",
			1,
			"Tex_N1_Naboo",
			1,
			"Tex_N1_Jinata",
			1
		};
		attenuationEffectType="HeliAttenuation";
		soundGetIn[]=
		{
			"A3\Sounds_F\air\Plane_Fighter_03\buzzard_getin",
			"db0",
			1,
			40
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\air\Plane_Fighter_03\getout",
			"db0",
			1,
			40
		};
		soundDammage[]=
		{
			"",
			"db-5",
			1
		};
		soundEngineOnInt[]=
		{
			"JMSLLTE_veh_air_s\N1_sounds\engine_on.ogg",
			"db-0",
			1
		};
		soundEngineOnExt[]=
		{
			"JMSLLTE_veh_air_s\N1_sounds\engine_on.ogg",
			"db5",
			1,
			500
		};
		soundEngineOffInt[]=
		{
			"JMSLLTE_veh_air_s\N1_sounds\engine_off.ogg",
			"db-0",
			1
		};
		soundEngineOffExt[]=
		{
			"JMSLLTE_veh_air_s\N1_sounds\engine_off.ogg",
			"db5",
			1,
			500
		};
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			"db-20",
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			"db-20",
			1.5
		};
		soundGearUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_up",
			"db-2",
			1,
			150
		};
		soundGearDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_down",
			"db-2",
			1,
			150
		};
		soundFlapsUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Up",
			"db-4",
			1,
			100
		};
		soundFlapsDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Down",
			"db-4",
			1,
			100
		};
		class scrubLandInt
		{
			sound[]=
			{
				"A3\Sounds_F\vehicles\air\noises\wheelsInt",
				"db0",
				1,
				100
			};
			frequency=1;
			volume="(scrubLand factor[0.01, 0.20])";
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\N1_sounds\engine.ogg",
					"db8",
					1,
					2100
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\N1_sounds\engine.ogg",
					"db8",
					1.2,
					2300
				};
				frequency="1";
				volume="camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\Awing_sounds\forsage.ogg",
					"db5",
					0.99000001,
					2500
				};
				frequency="1";
				volume="engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[]={3.1400001,3.9200001,2,0.5};
			};
			class WindNoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					"db-5",
					1,
					150
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\N1_sounds\interior.ogg",
					"db0",
					1
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\N1_sounds\interior.ogg",
					"db0",
					1.2
				};
				frequency="1";
				volume="(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageIn
			{
				sound[]=
				{
					"JMSLLTE_veh_air_s\Awing_sounds\forsage_int.ogg",
					"db0",
					1
				};
				frequency="1";
				volume="(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					"db-6",
					1
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="(1-camPos)*(speed factor[1, 150])";
			};
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=3;
				explosionShielding=1;
				name="HitHull";
				passThrough=0.5;
				visual="Hit_Hull";
				radius=0.30000001;
				minimalHit=0.02;
				depends="Total";
				material=-1;
			};
			class HitLAileron: HitHull
			{
				armor=2.5;
				explosionShielding=3;
				name="HitLAileron";
				passThrough=0.1;
				visual="Hit_AileronL";
				radius=0.44999999;
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitRAileron: HitHull
			{
				armor=2.5;
				explosionShielding=3;
				name="HitRAileron";
				passThrough=0.1;
				visual="Hit_AileronR";
				radius=0.44999999;
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitLCRudder: HitLAileron
			{
			};
			class HitRRudder: HitRAileron
			{
			};
			class HitLCElevator: HitLAileron
			{
			};
			class HitRElevator: HitRAileron
			{
			};
			class HitEngine: HitHull
			{
				armor=3.25;
				explosionShielding=0.5;
				name="HitEngine";
				passThrough=0.1;
				visual="Hit_Engine";
				radius=0.2;
				minimalHit=0.0099999998;
				depends="HitHull*0.33";
				class DestructionEffects
				{
					class JMSLLTE_Engine_Smoke
					{
						simulation="particles";
						type="BarelDestructionSmoke";
						position="engine_smoke";
						intensity=0.80000001;
						interval=1;
						lifeTime=60;
					};
				};
			};
			class HitEngine2: HitHull
			{
				armor=3.25;
				explosionShielding=0.5;
				name="HitEngine2";
				passThrough=0.1;
				visual="Hit_Engine2";
				radius=0.2;
				minimalHit=0.0099999998;
				depends="HitHull*0.33";
				class DestructionEffects
				{
					class JMSLLTE_Engine2_Smoke
					{
						simulation="particles";
						type="BarelDestructionSmoke";
						position="engine2_smoke";
						intensity=0.80000001;
						interval=1;
						lifeTime=60;
					};
				};
			};
			class HitAvionics: HitHull
			{
				armor=2;
				explosionShielding=1;
				name="HitAvionics";
				passThrough=0.2;
				visual="Hit_Avionics";
				radius=0.2;
				depends="0";
			};
			class HitFuel: HitHull
			{
				armor=2.75;
				explosionShielding=0.5;
				name="HitFuel";
				passThrough=0.5;
				visual="Hit_Fuel";
				radius=0.2;
				minimalHit=0.0099999998;
				depends="0";
				class DestructionEffects
				{
					class JMSLLTE_Fuel_Smoke
					{
						simulation="particles";
						type="ObjectDestructionSmokeFuelS";
						position="engine_smoke";
						intensity=0.80000001;
						interval=1;
						lifeTime=60;
					};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class BurnersHidedeMeopal
			{
				source="user";
				animPeriod=3;
				initPhase=1;
			};
			class HitLAileron
			{
				source="Hit";
				hitpoint="HitLAileron";
				raw=1;
			};
			class HitRAileron
			{
				source="Hit";
				hitpoint="HitRAileron";
				raw=1;
			};
			class HitAvionics
			{
				source="Hit";
				hitpoint="HitAvionics";
				raw=1;
			};
			class HitEngine
			{
				source="Hit";
				hitpoint="HitEngine";
				raw=1;
			};
			class HitEngine2
			{
				source="Hit";
				hitpoint="HitEngine2";
				raw=1;
			};
			class HideWeapons
			{
				source="user";
				animPeriod=1e-006;
				initPhase=0;
			};
		};
		lightOnGear=0;
		class Reflectors
		{
			class Light_1
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=50;
				size=1;
				innerAngle=5;
				outerAngle=65;
				coneFadeCoef=10;
				position="Light_1_pos";
				direction="Light_1_dir";
				hitpoint="Light_1_hit";
				selection="Light_1_hide";
				useFlare=1;
				flareSize=10;
				flareMaxDistance=250;
				dayLight=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
		};
		dustEffect="VTOLDust";
		waterEffect="VTOLWater";
		class WingVortices
		{
			class BodyLeft
			{
				effectName="WingVortices";
				position="body_vapour_L_S";
			};
			class WingTipLeft
			{
				effectName="WingVortices";
				position="body_vapour_L_E";
			};
			class WingTipRight
			{
				effectName="WingVortices";
				position="body_vapour_R_E";
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="Exhaust1";
				direction="Exhaust1_dir";
				effect="ExhaustsEffectHeliComHP";
				engineIndex=0;
			};
			class Exhaust2
			{
				position="Exhaust2";
				direction="Exhaust2_dir";
				effect="ExhaustsEffectHeliComHP";
				engineIndex=1;
			};
		};
		reportOwnPosition=1;
		reportRemoteTargets=1;
		receiveRemoteTargets=1;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=500;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=26;
						angleRangeVertical=26;
						maxTrackableSpeed=75;
						animDirection="Cannon_rot";
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=500;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=26;
						angleRangeVertical=26;
						maxTrackableSpeed=75;
						animDirection="Cannon_rot";
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=4000;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=120;
						angleRangeVertical=80;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						aimDown=40;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
					};
					class NVSensorComponent: SensorTemplateNV
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,16000,8000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,16000,8000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture="\JMSLLTE_veh_air\N1\data\ico_N1.paa";
				class pylons
				{
					class pylons1
					{
						maxweight=500;
						hardpoints[]=
						{
							"JMSLLTE_N1_CANNON_PYLON"
						};
						attachment="PylonRack_JMSLLTE_1000Rnd_N1_N1_mag";
						priority=3;
						UIposition[]={0.2,0.30000001};
						turret[]={};
					};
					class pylons2: pylons1
					{
						UIposition[]={0.40000001,0.30000001};
						mirroredMissilePos=1;
					};
					class pylons3
					{
						maxweight=500;
						hardpoints[]=
						{
							"JMSLLTE_MG7A_10RND_PROTON_PYLON"
						};
						attachment="PylonRack_JMSLLTE_10Rnd_MG7_proton_missiles";
						priority=1;
						UIposition[]={0.30000001,0.2};
						turret[]={};
					};
				};
				class Presets
				{
					class Empty
					{
						displayName="$STR_empty";
						attachment[]={};
					};
					class N1
					{
						displayName="N1/MG7-A";
						attachment[]=
						{
							"PylonRack_JMSLLTE_1000Rnd_N1_N1_mag",
							"PylonRack_JMSLLTE_1000Rnd_N1_N1_mag",
							"PylonRack_JMSLLTE_10Rnd_MG7_proton_missiles"
						};
					};
				};
			};
		};
		memoryPointDriverOptics="PilotCamera_pos";
		unitInfoType="RscOptics_CAS_Pilot";
		driverWeaponsInfoType="RscOptics_CAS_01_TGP";
		class pilotCamera
		{
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName="WFOV";
					initAngleX=0;
					minAngleX=0;
					maxAngleX=0;
					initAngleY=0;
					minAngleY=0;
					maxAngleY=0;
					initFov="(30 / 120)";
					minFov="(30 / 120)";
					maxFov="(30 / 120)";
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
				class Medium: Wide
				{
					opticsDisplayName="MFOV";
					initFov="(6 / 120)";
					minFov="(6 / 120)";
					maxFov="(6 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName="NFOV";
					initFov="(2 / 120)";
					minFov="(2 / 120)";
					maxFov="(2 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
			minTurn=-30;
			maxTurn=160;
			initTurn=0;
			minElev=-5;
			maxElev=90;
			initElev=5;
			maxXRotSpeed=1;
			maxYRotSpeed=1;
			maxMouseXRotSpeed=0.5;
			maxMouseYRotSpeed=0.5;
			pilotOpticsShowCursor=1;
			controllable=1;
		};
		class TransportBackpacks
		{
		};
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name="FirstAidKit";
				count=2;
			};
			class _xx_Toolkit
			{
				name="Toolkit";
				count=1;
			};
			class _xx_Medikit
			{
				name="Medikit";
				count=1;
			};
		};
		class EventHandlers: EventHandlers
		{
			init="if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
		};
		class UserActions
		{
			class ThrusterEngage
			{
				displayName="[Engage thrusters]";
				displayNameDefault="[Engage thrusters]";
				textToolTip="[Engage thrusters]";
				position="pilotview";
				radius=20;
				priority=21;
				onlyForPlayer=1;
				condition="(!(this getvariable [""ThrustersStatus"",false]) AND (player == driver this) AND (alive this) AND (speed this >10) )";
				statement="this execVM ""\JMSLLTE_veh_air\init\fn_ThrusterEngage.sqf""";
			};
			class ThrusterDisngage: ThrusterEngage
			{
				displayName="[Disengage thrusters]";
				displayNameDefault="[Disengage thrusters]";
				textToolTip="[Disengage thrusters]";
				priority=999;
				condition="((this getvariable [""ThrustersStatus"",false]) AND (player == driver this) AND (alive this))";
				statement="this execVM ""\JMSLLTE_veh_air\init\fn_ThrusterDisengage.sqf""";
			};
			class AirbrakeEngage
			{
				displayName="[Airbrake engage]";
				displayNameDefault="";
				position="pilotview";
				radius=20;
				priority=20;
				hideonuse=1;
				onlyForPlayer=1;
				condition="Alive this && isEngineOn this && speed this > 50";
				statement="this execVM ""\JMSLLTE_veh_air\init\fn_AirbrakeEngage.sqf""";
			};
		};
	};
	class FST_JMSLLTE_N1fighter_jinata_F: FST_JMSLLTE_N1fighter_base_F
	{
		author="JMax";
		class SimpleObject
		{
			eden=0;
			animate[]=
			{
				
				{
					"damage_hide",
					0
				},
				
				{
					"glass_1",
					0
				},
				
				{
					"glass_2",
					0
				},
				
				{
					"glass_3",
					0
				},
				
				{
					"glass_4",
					0
				},
				
				{
					"glass_5",
					0
				},
				
				{
					"glass_6",
					0
				},
				
				{
					"glass_7",
					0
				},
				
				{
					"glass_8",
					0
				},
				
				{
					"glass_9",
					0
				},
				
				{
					"glass_10",
					0
				},
				
				{
					"glass_11",
					0
				},
				
				{
					"glass_12",
					0
				},
				
				{
					"glass_13",
					0
				},
				
				{
					"glass_14",
					0
				},
				
				{
					"glass_15",
					0
				},
				
				{
					"glass_16",
					0
				},
				
				{
					"glass_17",
					0
				},
				
				{
					"glass_18",
					0
				},
				
				{
					"glass_19",
					0
				},
				
				{
					"glass_20",
					0
				},
				
				{
					"cannon_barrel_hide",
					0
				},
				
				{
					"rotor_1_blur_hide",
					0
				},
				
				{
					"rotor_1_static_hide",
					0
				},
				
				{
					"rotor_2_blur_hide",
					0
				},
				
				{
					"rotor_2_static_hide",
					0
				},
				
				{
					"engine_1_1_rot",
					1
				},
				
				{
					"engine_1_2_rot",
					1
				},
				
				{
					"engine_2_1_rot",
					1
				},
				
				{
					"engine_2_2_rot",
					1
				},
				
				{
					"stator_1_rudder_rot",
					0
				},
				
				{
					"stator_1_elevator_rot",
					0
				},
				
				{
					"rotor_1_rot",
					0
				},
				
				{
					"stator_2_rudder_rot",
					0
				},
				
				{
					"stator_2_elevator_rot",
					0
				},
				
				{
					"rotor_2_rot",
					0
				},
				
				{
					"gear_1_rot",
					0
				},
				
				{
					"gear_2_move",
					0
				},
				
				{
					"gear_3_move",
					0
				},
				
				{
					"gear_1_hatch_1_rot",
					0
				},
				
				{
					"gear_1_hatch_2_rot",
					0
				},
				
				{
					"gear_1_hatch_3_rot",
					0
				},
				
				{
					"gear_2_hatch_1_rot",
					0
				},
				
				{
					"gear_2_hatch_2_rot",
					0
				},
				
				{
					"gear_3_hatch_1_rot",
					0
				},
				
				{
					"gear_3_hatch_2_rot",
					0
				},
				
				{
					"wheel_1_rot",
					0
				},
				
				{
					"wheel_2_rot",
					0
				},
				
				{
					"wheel_3_rot",
					0
				},
				
				{
					"gear_1_damper_move",
					0.52999997
				},
				
				{
					"gear_1_damper_rotate",
					0.52999997
				},
				
				{
					"gear_1_link_1_rotate",
					0.52999997
				},
				
				{
					"gear_1_link_2_rotate",
					0.52999997
				},
				
				{
					"gear_2_damper_move",
					0.98000002
				},
				
				{
					"gear_3_damper_move",
					0.95999998
				},
				
				{
					"door_1_rot",
					0
				},
				
				{
					"cargoseats_hide",
					0
				},
				
				{
					"display_off_hide",
					0
				},
				
				{
					"positionlights_hide",
					0
				},
				
				{
					"cannon_turret_rot",
					0
				},
				
				{
					"cannon_rot",
					0.090000004
				},
				
				{
					"cannon_muzzleflash_hide",
					0
				},
				
				{
					"cannon_barrel_move",
					1
				},
				
				{
					"rotor_1_hide",
					0
				},
				
				{
					"rotor_1_unhide",
					0
				},
				
				{
					"rotor_2_hide",
					0
				},
				
				{
					"rotor_2_unhide",
					0
				},
				
				{
					"avionics_damage",
					0
				},
				
				{
					"stick_control_1_pitch_rot",
					0
				},
				
				{
					"stick_control_2_pitch_rot",
					0
				},
				
				{
					"stick_control_1_roll_rot",
					0
				},
				
				{
					"stick_control_2_roll_rot",
					0
				},
				
				{
					"pedals_1_left_1_move",
					0
				},
				
				{
					"pedals_1_right_1_move",
					0
				},
				
				{
					"pedals_1_left_2_rot",
					0
				},
				
				{
					"pedals_1_right_2_rot",
					0
				},
				
				{
					"pedals_2_left_1_move",
					0
				},
				
				{
					"pedals_2_right_1_move",
					0
				},
				
				{
					"pedals_2_left_2_rot",
					0
				},
				
				{
					"pedals_2_right_2_rot",
					0
				},
				
				{
					"display_1_alt_ladder_rot",
					8.1599998
				},
				
				{
					"display_1_alt_1_rot",
					8.1599998
				},
				
				{
					"display_1_alt_10_rot",
					8.1599998
				},
				
				{
					"display_1_alt_100_rot",
					8.1599998
				},
				
				{
					"display_1_alt_1000_rot",
					8.1599998
				},
				
				{
					"display_1_compass_rot",
					0
				},
				
				{
					"display_1_fuel_move",
					1
				},
				
				{
					"display_1_gear_down_move",
					0
				},
				
				{
					"display_1_gear_up_move",
					0
				},
				
				{
					"display_1_horizon_bank_rot",
					0
				},
				
				{
					"display_1_horizon_move",
					0
				},
				
				{
					"display_1_hydraulics_1_rot",
					0
				},
				
				{
					"display_1_hydraulics_2_rot",
					0
				},
				
				{
					"display_1_oil_1_rot",
					1
				},
				
				{
					"display_1_oil_2_rot",
					1
				},
				
				{
					"display_1_oil_3_rot",
					1
				},
				
				{
					"display_1_oil_4_rot",
					1
				},
				
				{
					"display_1_oil_5_rot",
					1
				},
				
				{
					"display_1_oil_6_rot",
					1
				},
				
				{
					"display_1_pitch_rot",
					0
				},
				
				{
					"display_1_roll_rot",
					0
				},
				
				{
					"display_1_yaw_rot",
					0
				},
				
				{
					"display_1_rpm_1_rot",
					0
				},
				
				{
					"display_1_rpm_2_rot",
					0
				},
				
				{
					"display_1_speed_ladder_rot",
					0
				},
				
				{
					"display_1_speed_1_rot",
					0
				},
				
				{
					"display_1_speed_10_rot",
					0
				},
				
				{
					"display_1_speed_100_rot",
					0
				},
				
				{
					"display_1_vert_speed_rot",
					0
				},
				
				{
					"display_1_voltage_1_rot",
					0
				},
				
				{
					"display_1_voltage_2_rot",
					0
				},
				
				{
					"display_1_vtol_1_rot",
					1
				},
				
				{
					"display_1_vtol_2_rot",
					1
				},
				
				{
					"display_2_alt_ladder_rot",
					8.1599998
				},
				
				{
					"display_2_alt_1_rot",
					8.1599998
				},
				
				{
					"display_2_alt_10_rot",
					8.1599998
				},
				
				{
					"display_2_alt_100_rot",
					8.1599998
				},
				
				{
					"display_2_alt_1000_rot",
					8.1599998
				},
				
				{
					"display_2_compass_rot",
					0
				},
				
				{
					"display_2_fuel_move",
					1
				},
				
				{
					"display_2_horizon_bank_rot",
					0
				},
				
				{
					"display_2_horizon_move",
					0
				},
				
				{
					"display_2_oil_1_rot",
					1
				},
				
				{
					"display_2_oil_2_rot",
					1
				},
				
				{
					"display_2_speed_ladder_rot",
					0
				},
				
				{
					"display_2_speed_1_rot",
					0
				},
				
				{
					"display_2_speed_10_rot",
					0
				},
				
				{
					"display_2_speed_100_rot",
					0
				},
				
				{
					"display_2_vert_speed_rot",
					0
				},
				
				{
					"display_2_vtol_1_rot",
					1
				},
				
				{
					"display_2_vtol_2_rot",
					1
				},
				
				{
					"display_at_1_hide",
					1
				},
				
				{
					"display_at_2_hide",
					1
				},
				
				{
					"display_at_3_hide",
					1
				},
				
				{
					"display_at_4_hide",
					1
				},
				
				{
					"display_at_5_hide",
					1
				},
				
				{
					"display_at_6_hide",
					1
				},
				
				{
					"display_at_7_hide",
					1
				},
				
				{
					"display_at_8_hide",
					1
				},
				
				{
					"display_mg_ammo_1_hide",
					1
				},
				
				{
					"display_mg_ammo_2_hide",
					1
				},
				
				{
					"display_mg_ammo_3_hide",
					1
				},
				
				{
					"display_mg_ammo_4_hide",
					1
				},
				
				{
					"display_mg_ammo_5_hide",
					1
				},
				
				{
					"display_mg_ammo_6_hide",
					1
				},
				
				{
					"display_mg_ammo_7_hide",
					1
				},
				
				{
					"display_mg_ammo_8_hide",
					1
				},
				
				{
					"display_mg_ammo_9_hide",
					1
				},
				
				{
					"display_mg_ammo_10_hide",
					1
				},
				
				{
					"display_rocketspod_1_empty_hide",
					1
				},
				
				{
					"display_rocketspod_2_empty_hide",
					1
				},
				
				{
					"rocketb19_hide",
					1
				},
				
				{
					"rocketa19_hide",
					1
				},
				
				{
					"rocketb18_hide",
					1
				},
				
				{
					"rocketa18_hide",
					1
				},
				
				{
					"rocketb17_hide",
					1
				},
				
				{
					"rocketa17_hide",
					1
				},
				
				{
					"rocketb16_hide",
					1
				},
				
				{
					"rocketa16_hide",
					1
				},
				
				{
					"rocketb15_hide",
					1
				},
				
				{
					"rocketa15_hide",
					1
				},
				
				{
					"rocketb14_hide",
					1
				},
				
				{
					"rocketa14_hide",
					1
				},
				
				{
					"rocketb13_hide",
					1
				},
				
				{
					"rocketa13_hide",
					1
				},
				
				{
					"rocketb12_hide",
					1
				},
				
				{
					"rocketa12_hide",
					1
				},
				
				{
					"rocketb11_hide",
					1
				},
				
				{
					"rocketa11_hide",
					1
				},
				
				{
					"rocketb10_hide",
					1
				},
				
				{
					"rocketa10_hide",
					1
				},
				
				{
					"rocketb9_hide",
					1
				},
				
				{
					"rocketa9_hide",
					1
				},
				
				{
					"rocketb8_hide",
					1
				},
				
				{
					"rocketa8_hide",
					1
				},
				
				{
					"rocketb6_hide",
					1
				},
				
				{
					"rocketa6_hide",
					1
				},
				
				{
					"rocketb5_hide",
					1
				},
				
				{
					"rocketa5_hide",
					1
				},
				
				{
					"rocketb4_hide",
					1
				},
				
				{
					"rocketa4_hide",
					1
				},
				
				{
					"rocketb3_hide",
					1
				},
				
				{
					"rocketa3_hide",
					1
				},
				
				{
					"rocketb2_hide",
					1
				},
				
				{
					"rocketa2_hide",
					1
				},
				
				{
					"rocketb7_hide",
					1
				},
				
				{
					"rocketa7_hide",
					1
				},
				
				{
					"rocketb1_hide",
					1
				},
				
				{
					"rocketa1_hide",
					1
				}
			};
			hide[]=
			{
				"clan",
				"zasleh",
				"cannon_muzzleflash",
				"light_1_hide",
				"light_2_hide",
				"light_3_hide",
				"zadni svetlo",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=3.2279999;
			verticalOffsetWorld=-0.034000002;
		};
		_generalMacro="FST_JMSLLTE_N1fighter_jinata_F";
		scope=2;
		scopeCurator=2;
		displayName="[41st] Tukata N-1 starfighter";
		side=0;
		faction="FST_Tukata_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_JMSLLTE_JinTrooper_armor_F";
		typicalCargo[]=
		{
			"FST_JMSLLTE_JinTrooper_armor_F"
		};
		textureList[]=
		{
			"Tex_N1_Jinata",
			1
		};
		weapons[]=
		{
			"FST_ARC_Light_Canon",
			"ls_weapon_CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"FST_ARC_1000Rnd_Heavy_shells",
			"FST_ARC_1000Rnd_Heavy_shells",
			"FST_ARC_1000Rnd_Heavy_shells",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"Laserbatteries",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile"
		};
	};
};
