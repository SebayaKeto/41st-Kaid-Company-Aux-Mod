_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeBackpack _plyer;

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack";

for "_i" from 1 to 3 do {_plyer addItemToBackpack "FST_RPS6_rocket";};
_plyer addItemToBackpack "FST_RPS6_rocket_HE";