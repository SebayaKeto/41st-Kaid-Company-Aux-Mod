_plyer = _this select 1;
_LO = ((_this select 3) select 0) select 0;

comment "Add containers";
_plyer addBackpack "FST_Backpack_Jumppack_EOD";

comment "Add items to containers";
_plyer addItemToUniform "ACE_Fortify";
_plyer addItemToBackpack "ToolKit";
for "_i" from 1 to 4 do {_plyer addItemToUniform "FST_grenade_Penetrator_mag";};

