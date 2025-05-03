_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeBackpack _plyer;

comment "Add weapons";
_plyer addWeapon "FST_T15";
_plyer addPrimaryWeaponItem "FST_thermal_coil_LP_Blue";
_plyer addPrimaryWeaponItem "FST_thermal_coil_T15_Blue";
_plyer addPrimaryWeaponItem "FST_Optic_MRCO_T15";
_plyer addPrimaryWeaponItem "3as_bipod_vk38x_f";
_plyer addPrimaryWeaponItem "IDA_stun_cell";
_plyer addPrimaryWeaponItem "acc_flashlight";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";

comment "Add containers";
_plyer addBackpack "FST_Clone_backpack";

comment "Add items to containers";
for "_i" from 1 to 2 do {_plyer addItemToUniform "IDA_BattleStim";};
for "_i" from 1 to 20 do {_plyer addItemToUniform "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "ACE_splint";};
for "_i" from 1 to 5 do {_plyer addItemToUniform "ACE_tourniquet";};
_plyer addItemToUniform "ACE_EntrenchingTool";
_plyer addItemToUniform "WBK_HeadLampItem";
_plyer addItemToUniform "ACE_Flashlight_XL50";
_plyer addItemToUniform "ACE_IR_Strobe_Item";

for "_i" from 1 to 4 do {_plyer addItemToVest "FST_thermal_coil_LP_Blue";};
for "_i" from 1 to 3 do {_plyer addItemToVest "FST_grenade_Detonator_mag";};
for "_i" from 1 to 3 do {_plyer addItemToVest "IDA_grenade_Smoke_mag";};
_plyer addItemToVest "IDA_grenade_Smoke_Blue_mag";
_plyer addItemToVest "ls_mag_glowrod_hiGreen";

for "_i" from 1 to 2 do {_plyer addItemToBackpack "FST_thermal_coil_LP_Blue";};
for "_i" from 1 to 4 do {_plyer addItemToBackpack "FST_thermal_coil_T15_Blue";};
_plyer addItemToBackpack "ACE_Tripod";

for "_i" from 1 to 2 do {_plyer addItemToUniform "ACE_CableTie";};
_plyer addItemToVest "IDA_grenade_Smoke_Purple_mag";