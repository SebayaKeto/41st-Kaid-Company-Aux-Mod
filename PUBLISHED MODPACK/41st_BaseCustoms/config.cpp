class CfgPatches
{
	class 41st_BaseCustom
	{
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			
			"FST_BaseCustomBlue",
			"FST_BaseCustomRed",
			"FST_BaseCustomGreen",
			"FST_BaseCustomCiv",

		};
	};
	author="Tooka";
};
class CfgFactionClasses
{
    class FST_CustomsGroup
    {
        displayName="41st Elite Corps Customs";
		priority=1;
		side=3;
		icon=""; 
    };
};
class CfgEditorSubcategories
{
	class FST_BaseSub
	{
		displayName = "Base Custom Unit"; 
	};
};
class CfgVehicles
{
    class C_man_1;
    class lsd_gar_bodyGlove_base;
    class FST_BaseCustomBlue: lsd_gar_bodyGlove_base
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=1;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Friendly Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
        class EventHandlers
        {
            init = "_this spawn { params ['_unit']; sleep 2; if (!isServer) exitWith {}; if (is3DEN || is3DENPreview) exitWith {}; private _defaultUniform = 'FST_Uniform_Bodyglove'; if (uniform _unit == _defaultUniform) then { deleteVehicle _unit; };};";
        };
    };
    class FST_BaseCustomRed: lsd_gar_bodyGlove_base
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=0;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Enemy Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
        class EventHandlers
        {
            init = "_this spawn { params ['_unit']; sleep 2; if (!isServer) exitWith {}; if (is3DEN || is3DENPreview) exitWith {}; private _defaultUniform = 'FST_Uniform_Bodyglove'; if (uniform _unit == _defaultUniform) then { deleteVehicle _unit; };};";
        };
    };
    class FST_BaseCustomGreen: lsd_gar_bodyGlove_base
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        side=2;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Independant Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
        class EventHandlers
        {
            init = "_this spawn { params ['_unit']; sleep 2; if (!isServer) exitWith {}; if (is3DEN || is3DENPreview) exitWith {}; private _defaultUniform = 'FST_Uniform_Bodyglove'; if (uniform _unit == _defaultUniform) then { deleteVehicle _unit; };};";
        };
    };
    class FST_BaseCustomCiv: C_man_1
    {
        author="Tooka";
        scope=2;
        scopeCurator=0;
        uniformClass="FST_Uniform_Bodyglove";
        faction="FST_CustomsGroup";
		editorSubcategory="FST_BaseSub";
        displayName="Custom Civilian Unit";
        Backpack="";
        weapons[]=
        {
            "Throw",
			"Put"
        };
		identityTypes[]={};
        Items[]={};
		respawnItems[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
		magazines[]={};
		respawnMagazines[]={};
        class EventHandlers
        {
            init = "_this spawn { params ['_unit']; sleep 2; if (!isServer) exitWith {}; if (is3DEN || is3DENPreview) exitWith {}; private _defaultUniform = 'FST_Uniform_Bodyglove'; if (uniform _unit == _defaultUniform) then { deleteVehicle _unit; };};";
        };
    };
};
