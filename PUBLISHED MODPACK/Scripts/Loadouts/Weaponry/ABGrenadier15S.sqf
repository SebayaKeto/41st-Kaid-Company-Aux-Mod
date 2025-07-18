_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeBackpack _plyer;

comment "Add weapons";
_plyer addWeapon "FST_DC15S_UGL";
_plyer addPrimaryWeaponItem "FST_blaster_cell_Blue";
_plyer addPrimaryWeaponItem "FST_HE_LauncherGrenade";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack_GRN";

comment "Add items to containers";
for "_i" from 1 to 2 do {_plyer addItemToUniform "IDA_BattleStim";};
for "_i" from 1 to 20 do {_plyer addItemToUniform "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "ACE_splint";};
for "_i" from 1 to 5 do {_plyer addItemToUniform "ACE_tourniquet";};
_plyer addItemToUniform "ACE_EntrenchingTool";
_plyer addItemToUniform "WBK_HeadLampItem_Double";
_plyer addItemToUniform "ACE_Flashlight_XL50";
_plyer addItemToUniform "FST_SmokeBlue_LauncherGrenade";
_plyer addItemToUniform "FST_SmokeGreen_LauncherGrenade";
_plyer addItemToUniform "FST_SmokeRed_LauncherGrenade";
_plyer addItemToUniform "ACE_IR_Strobe_Item";

for "_i" from 1 to 12 do {_plyer addItemToVest "FST_blaster_cell_Blue";};
for "_i" from 1 to 3 do {_plyer addItemToVest "FST_grenade_Detonator_mag";};
for "_i" from 1 to 3 do {_plyer addItemToVest "IDA_grenade_Smoke_mag";};
_plyer addItemToVest "IDA_grenade_Smoke_Blue_mag";
_plyer addItemToVest "ls_mag_glowrod_hiGreen";
_plyer addItemToUniform "ACE_HuntIR_monitor";

for "_i" from 1 to 12 do {_plyer addItemToBackpack "FST_HE_LauncherGrenade";};
for "_i" from 1 to 4 do {_plyer addItemToBackpack "ACE_40mm_Flare_white";};
for "_i" from 1 to 2 do {_plyer addItemToBackpack "ACE_HuntIR_M203";};
for "_i" from 1 to 6 do {_plyer addItemToBackpack "FST_Smoke_LauncherGrenade";};

for "_i" from 1 to 2 do {_plyer addItemToUniform "ACE_CableTie";};