_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeAllWeapons _plyer;
removeBackpack _plyer;

comment "Add weapons";
_plyer addWeapon "FST_DC15A";
_plyer addPrimaryWeaponItem "FST_blaster_cell_High_Blue";

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";
_plyer addHeadgear "FST_Pilot_P1_Helmet";

comment "Add containers";
_plyer addBackpack "FST_Clone_LR_attachment";
// comment _plyer addVest "FST_vest_holster";

comment "Add items to containers";
for "_i" from 1 to 2 do {_plyer addItemToUniform "IDA_BattleStim";};
for "_i" from 1 to 20 do {_plyer addItemToUniform "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToUniform "ACE_splint";};
for "_i" from 1 to 5 do {_plyer addItemToUniform "ACE_tourniquet";};
for "_i" from 1 to 2 do {_plyer addItemToUniform "ACE_CableTie";};
_plyer addItemToUniform "ACE_EntrenchingTool";
_plyer addItemToUniform "WBK_HeadLampItem_Double";
_plyer addItemToUniform "ACE_Flashlight_XL50";
_plyer addItemToUniform "ACE_IR_Strobe_Item";
_plyer addItemToUniform "ItemcTab";
_plyer addItemToUniform "ToolKit";

for "_i" from 1 to 8 do {_plyer addItemToVest "FST_blaster_cell_High_Blue";};
for "_i" from 1 to 3 do {_plyer addItemToVest "FST_grenade_Detonator_mag";};
for "_i" from 1 to 3 do {_plyer addItemToVest "IDA_grenade_Smoke_mag";};
_plyer addItemToVest "IDA_grenade_Smoke_Blue_mag";
_plyer addItemToVest "ls_mag_glowrod_hiGreen";
_plyer addItemToVest "IDA_grenade_Smoke_Purple_mag";

_plyer addItemToBackpack "FST_Bacta_Tank";
_plyer addItemToBackpack "IDA_Cauterizer";
for "_i" from 1 to 80 do {_plyer addItemToBackpack "IDA_BactaBandage";};
for "_i" from 1 to 4 do {_plyer addItemToBackpack "ACE_PlasmaIV";};
for "_i" from 1 to 6 do {_plyer addItemToBackpack "ACE_PlasmaIV_500";};
for "_i" from 1 to 10 do {_plyer addItemToBackpack "IDA_BattleStim";};
for "_i" from 1 to 3 do {_plyer addItemToBackpack "ACE_Adenosine";};
for "_i" from 1 to 6 do {_plyer addItemToBackpack "ACE_Splint";};
for "_i" from 1 to 6 do {_plyer addItemToBackpack "ACE_tourniquet";};