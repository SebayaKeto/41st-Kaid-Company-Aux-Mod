_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeBackpack _plyer;

comment "Add binoculars";
_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack_LR";

for "_i" from 1 to 10 do {_plyer addItemToBackpack "IDA_Grenade_Smoke_mag";};
for "_i" from 1 to 5 do {_plyer addItemToBackpack "IDA_Grenade_Smoke_Blue_mag";};
for "_i" from 1 to 5 do {_plyer addItemToBackpack "IDA_Grenade_Smoke_Green_mag";};
for "_i" from 1 to 5 do {_plyer addItemToBackpack "IDA_Grenade_Smoke_Red_mag";};
for "_i" from 1 to 5 do {_plyer addItemToBackpack "IDA_Grenade_Smoke_Purple_mag";};

_plyer addMagazine "Laserbatteries";
_plyer addWeapon "FST_Electrobinoculars";

_plyer addItemToUniform "ACE_MapTools";

_plyer addItemToBackpack "ItemAndroid";