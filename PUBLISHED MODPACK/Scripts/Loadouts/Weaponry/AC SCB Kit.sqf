_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeBackpack _plyer;

comment "Add weapons";
_plyer addWeapon "FST_DP23";
_plyer addPrimaryWeaponItem "FST_Attachment_Optic_Holo_DC15";
_plyer addPrimaryWeaponItem "FST_blaster_scatter_cell_DP23_Blue";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";
_plyer addHeadgear "FST_Crewman_Helmet";

comment "Add containers";
_plyer addBackpack "FST_Backpack_Antenna";
_plyer addVest "FST_CloneVestSuspenders";

comment "Add items to containers";
for "_i" from 1 to 2 do {_plyer addItemToUniform "IDA_BattleStim";};
for "_i" from 1 to 20 do {_plyer addItemToUniform "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "ACE_splint";};
for "_i" from 1 to 5 do {_plyer addItemToUniform "ACE_tourniquet";};
for "_i" from 1 to 2 do {_plyer addItemToUniform "ACE_CableTie";};
for "_i" from 1 to 3 do {_plyer addItemToUniform "FST_grenade_Detonator_mag";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "IDA_grenade_Smoke_mag";};
_plyer addItemToUniform "ACE_EntrenchingTool";
_plyer addItemToUniform "IDA_grenade_Smoke_Blue_mag";
_plyer addItemToUniform "IDA_grenade_Smoke_Purple_mag";
_plyer addItemToUniform "WBK_HeadLampItem_Double";
_plyer addItemToUniform "ACE_Flashlight_XL50";
_plyer addItemToUniform "ACE_IR_Strobe_Item";
_plyer addItemToUniform "ItemAndroid";

for "_i" from 1 to 8 do {_plyer addItemToVest "FST_blaster_scatter_cell_DP23_Blue";};
for "_i" from 1 to 8 do {_plyer addItemToVest "FST_thermal_slug_mag_Blue";};
_plyer addItemToVest "ToolKit";
_plyer addItemToVest "ls_mag_glowrod_hiGreen";
