_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeBackpack _plyer;

comment "Add weapons";
_plyer addWeapon "FST_DC15L_F";
_plyer addPrimaryWeaponItem "FST_blaster_battery_DC15L_Blue";
_plyer addPrimaryWeaponItem "FST_Optic_DC15L";
_plyer addPrimaryWeaponItem "FST_Bipod_DC15L_f";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack";

comment "Add items to containers";
for "_i" from 1 to 2 do {_plyer addItemToUniform "IDA_BattleStim";};
for "_i" from 1 to 20 do {_plyer addItemToUniform "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "ACE_splint";};
for "_i" from 1 to 5 do {_plyer addItemToUniform "ACE_tourniquet";};
_plyer addItemToUniform "ACE_EntrenchingTool";
_plyer addItemToUniform "WBK_HeadLampItem";
_plyer addItemToUniform "ACE_Flashlight_XL50";
_plyer addItemToUniform "ACE_IR_Strobe_Item";

for "_i" from 1 to 8 do {_plyer addItemToVest "FST_blaster_battery_DC15L_Blue";};
for "_i" from 1 to 3 do {_plyer addItemToVest "FST_grenade_Detonator_mag";};
for "_i" from 1 to 3 do {_plyer addItemToVest "IDA_grenade_Smoke_mag";};
_plyer addItemToVest "IDA_grenade_Smoke_Blue_mag";
_plyer addItemToVest "ls_mag_glowrod_hiGreen";

for "_i" from 1 to 6 do {_plyer addItemToBackpack "FST_blaster_battery_DC15L_Blue";};
_plyer addItemToBackpack "ACE_Tripod";

for "_i" from 1 to 2 do {_plyer addItemToUniform "ACE_CableTie";};
_plyer addItemToVest "IDA_grenade_Smoke_Purple_mag";