#include "\nsm_Main\_include\macros.hpp"
//First we get the last backppack
saved_backpack=ace_player getVariable['NSM_jumppack_backpack_class',''];

//Then we get current backpack
current_backpack=backpack ace_player;

//if backpacks are same, dont do anything
if(saved_backpack isEqualTo current_backpack) exitwith {};

//if different, update classname and set energy to 0. Also set last recharge time to false so that rehcarge can handle and selected jump reset.
//ace_player setVariable ["NSM_jumppack_backpack_class",current_backpack,true];
//ace_player setVariable ["NSM_jumppack_energy",0,true];
ace_player setVariable["NSM_jumppack_last_call_time",false,true];
//(unitBackpack ace_player) setVariable["NSM_jumppack_selected_jump",0,true];