_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

//comment "Remove existing items";
removeBackpack _plyer;

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack";

for "_i" from 1 to 12 do {_plyer addItemToBackpack "FST_blaster_cell_High_Blue";};
for "_i" from 1 to 18 do {_plyer addItemToBackpack "FST_blaster_cell_Blue";};
for "_i" from 1 to 4 do {_plyer addItemToBackpack "FST_blaster_cell_LE_Blue";};
for "_i" from 1 to 4 do {_plyer addItemToBackpack "FST_blaster_scatter_cell_DP23_Blue";};
for "_i" from 1 to 6 do {_plyer addItemToVest "FST_grenade_Detonator_mag";};
for "_i" from 1 to 8 do {_plyer addItemToVest "FST_HE_LauncherGrenade";};
