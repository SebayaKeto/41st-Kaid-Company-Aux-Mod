
params ["_target", "_player"];

if !(missionNamespace getVariable ["FST_ATMInitialized", false]) then {missionNamespace setVariable ["FST_ATMInitialized", true, true]; missionNamespace setVariable ["FST_CollectedDeposit", 0, true];};

private _count = 0;
private _random = 0;
private _chiparray = [0, 5, 1, 3, 2, 1, 3, 0.5];
private _gemarray = [0, 10, 1 , 1, 2, 0.05];

while {"JLTS_credits_10" in items _player} do 
{
    _player removeItem "JLTS_credits_10";
    _count = _count + 10;
};

while {"JLTS_credits_100" in items _player} do 
{
    _player removeItem "JLTS_credits_100";
    _count = _count + 100;
};

while {"JLTS_credits_1000" in items _player} do 
{
    _player removeItem "JLTS_credits_1000";
    _count = _count + 1000;
};
while {"JLTS_credits_50" in items _player} do 
{
    _player removeItem "JLTS_credits_50";
    _count = _count + 50;
};

while {"JLTS_credits_500" in items _player} do 
{
    _player removeItem "JLTS_credits_500";
    _count = _count + 500;
};

while {"JLTS_credits_5000" in items _player} do 
{
    _player removeItem "JLTS_credits_5000";
    _count = _count + 5000;
};

while {"FST_CreditChip" in items _player} do 
{
    _player removeItem "FST_CreditChip";
    _random = selectRandomWeighted _chiparray;
    if (_random == 0) then {_count = _count + ((1 + floor (random 22)) * 10);};
    if (_random == 1) then {_count = _count + ((1 + floor (random 77)) * 10);};
    if (_random == 2) then {_count = _count + ((1 + floor (random 123)) * 10);};
    if (_random == 3) then {_count = _count + ((20 + floor (random 600)) * 10);};
};

while {"FST_CreditCase_Low" in items _player} do 
{
    _player removeItem "FST_CreditCase_Low";
    _count = _count + ((450 + floor (random 100)) * 10);
};

while {"FST_CreditCase_Med" in items _player} do 
{
    _player removeItem "FST_CreditCase_Med";
    _count = _count + ((930 + floor (random 150)) * 10);
};

while {"FST_CreditCase_High" in items _player} do 
{
    _player removeItem "FST_CreditCase_High";
    _count = _count + ((2410 + floor (random 130)) * 10);
};

while {"FST_CreditCase_Rare" in items _player} do 
{
    _player removeItem "FST_CreditCase_Rare";
    _count = _count + ((4850 + floor (random 300)) * 10);
};

while {"FST_CreditCase_Chip" in items _player} do 
{
    _player removeItem "FST_CreditCase_Chip";
    _count = _count + ((200 + floor (random 1000)) * 10);
};

while {"FST_Camtono_Corusca" in items _player} do 
{
    _player removeItem "FST_Camtono_Corusca";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((900 + floor (random 500)) * 10);};
    if (_random == 1) then {_count = _count + ((5000 + floor (random 10000)) * 10);};
    if (_random == 2) then {_count = _count + ((50000 + floor (random 55000)) * 10);};
};

while {"FST_Camtono_Rainbow" in items _player} do 
{
    _player removeItem "FST_Camtono_Rainbow";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((10000 + floor (random 15000)) * 10);};
    if (_random == 1) then {_count = _count + ((50000 + floor (random 25000)) * 10);};
    if (_random == 2) then {_count = _count + ((90000 + floor (random 55000)) * 10);};
};

while {"FST_Camtono_Vertex" in items _player} do 
{
    _player removeItem "FST_Camtono_Vertex";
    _count = _count + ((1200 + floor (random 2000)) * 10);
};

while {"FST_Camtono_Gemstones" in items _player} do 
{
    _player removeItem "FST_Camtono_Gemstones";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((10 + floor (random 200)) * 10);};
    if (_random == 1) then {_count = _count + ((250 + floor (random 500)) * 10);};
    if (_random == 2) then {_count = _count + ((1100 + floor (random 2500)) * 10);};
};

while {"FST_Camtono_Nova" in items _player} do 
{
    _player removeItem "FST_Camtono_Nova";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((500 + floor (random 780)) * 10);};
    if (_random == 1) then {_count = _count + ((2300 + floor (random 2300)) * 10);};
    if (_random == 2) then {_count = _count + ((3900 + floor (random 2500)) * 10);};
};

while {"FST_Camtono_Pearl" in items _player} do 
{
    _player removeItem "FST_Camtono_Pearl";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((2300 + floor (random 950)) * 10);};
    if (_random == 1) then {_count = _count + ((3700 + floor (random 2300)) * 10);};
    if (_random == 2) then {_count = _count + ((8000 + floor (random 4000)) * 10);};
};

while {"FST_Camtono_Kyber" in items _player} do 
{
    _player removeItem "FST_Camtono_Kyber";
    _random = selectRandomWeighted _gemarray;
    if (_random == 0) then {_count = _count + ((90 + floor (random 200)) * 10);};
    if (_random == 1) then {_count = _count + ((610 + floor (random 2700)) * 10);};
    if (_random == 2) then {_count = _count + ((2300 + floor (random 2300)) * 10);};
};

while {"FST_Camtono_Aurodium" in items _player} do 
{
    _player removeItem "FST_Camtono_Aurodium";
    _count = _count + ((2410 + floor (random 130)) * 10);
};

while {"FST_Camtono_Beskar" in items _player} do 
{
    _player removeItem "FST_Camtono_Beskar";
    _count = _count + ((2410 + floor (random 130)) * 10);
};

while {"FST_Camtono_Metal" in items _player} do 
{
    _player removeItem "FST_Camtono_Metal";
    _count = _count + ((2410 + floor (random 130)) * 10);
};

if ( _count != 0) then 
{
    ["FST_depositCredits", [_count]] call CBA_fnc_serverEvent;
};