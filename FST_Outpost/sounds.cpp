/**
 * @file: sounds.cpp
 * @author: Maldova
 * @brief: Defines the sounds for the FST Outpost assets.
 * This file is included by the main config.cpp.
 *
 */

class CfgSounds
{
	class FST_Door_Open_Sound
	{
		name = "FST_Door_Open_Sound";
		sound[] = {"\FST\FST_Core\Sounds\FST_OutpostEntrance_LightGate.ogg", 5, 1, 15};
		titles[] = {};
	};
	class FST_Door_Close_Sound
	{
		name = "FST_Door_Close_Sound";
		sound[] = {"\FST\FST_Core\Sounds\FST_OutpostEntrance_LightGate.ogg", 5, 1, 15};
		titles[] = {};
	};
};
class CfgAnimationSourceSounds
{
	class LightOutpostDoorsSound
	{
		class DoorMovement
		{
			loop=0;
			terminate=1;
			trigger="(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[]=
			{
				"a3\sounds_f\environment\structures\doors\gatedoors\gatesqueak_1",
				1,
				1,
				40
			};
			sound1[]=
			{
				"a3\sounds_f\environment\structures\doors\gatedoors\gatesqueak_2",
				1,
				1,
				40
			};
			sound[]=
			{
				"sound0",
				0.5,
				"sound1",
				0.5
			};
		};
		class OpenTheDoor
		{
			loop=0;
			terminate=0;
			trigger="direction * (phase factor[0.01,0.02])";
			sound0[]=
			{
				"a3\sounds_f\environment\structures\doors\gatedoors\gateknob",
				1,
				1,
				50
			};
			sound[]=
			{
				"sound0",
				1
			};
		};
		class SlamTheDoor
		{
			loop=0;
			terminate=0;
			trigger="(1 - direction) * (phase factor[0.1,0.09])";
			sound0[]=
			{
				"a3\sounds_f\environment\structures\doors\gatedoors\gateslam",
				1,
				1,
				50
			};
			sound[]=
			{
				"sound0",
				1
			};
		};
	};
};