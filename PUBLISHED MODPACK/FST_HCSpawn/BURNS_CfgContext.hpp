// Original BURNS interface; grouped so every command fits normal screens.
class ZEN_context_menu_actions {
    class BURNS {
        displayName = "BURNS";
        condition = "(_groups isNotEqualTo []) || (_objects isNotEqualTo [])";
        priority = 6;
        class orders {
            displayName = "Orders";
            class rush {
                displayName = "Task Rush";
                statement = "['rush',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class hunt {
                displayName = "Task Hunt";
                statement = "['hunt',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class creep {
                displayName = "Task Creep";
                statement = "['creep',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class assault {
                displayName = "Task Assault";
                statement = "['assault',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class retreat {
                displayName = "Task Retreat";
                statement = "['retreat',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class patrol {
                displayName = "Task Patrol";
                statement = "['patrol',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
        };
        class buildings {
            displayName = "Building Tasks";
            class cqb {
                displayName = "Task CQB";
                statement = "['cqb',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class garrison {
                displayName = "Task Garrison";
                statement = "['garrison',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class camp {
                displayName = "Task Camp";
                statement = "['camp',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class defend {
                displayName = "Task Defend";
                statement = "['defend',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
        };
        class artillery {
            displayName = "Artillery";
            class artillery_register {
                displayName = "Register Artillery";
                statement = "['artillery_register',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class artillery_remove {
                displayName = "Unregister Artillery";
                statement = "['artillery_remove',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class artillery_fire {
                displayName = "Artillery Fire Mission";
                statement = "['artillery_fire',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
        };
        class ai {
            displayName = "AI Settings";
            class configure {
                displayName = "Configure Group AI";
                statement = "['configure',_groups,_objects,_position] call FST_HCSpawn_fnc_burnsDialog";
            };
            class enable_unit {
                displayName = "Enable Unit AI";
                statement = "['enable_unit',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class disable_unit {
                displayName = "Disable Unit AI";
                statement = "['disable_unit',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class enable_group {
                displayName = "Enable Group AI";
                statement = "['enable_group',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class disable_group {
                displayName = "Disable Group AI";
                statement = "['disable_group',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class set_radio {
                displayName = "Set Radio";
                statement = "['set_radio',_groups,_objects,_position] call FST_HCSpawn_fnc_burnsDialog";
            };
            class radio_on {
                displayName = "Enable Radio";
                statement = "['radio_on',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class radio_off {
                displayName = "Disable Radio";
                statement = "['radio_off',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class reinforce_on {
                displayName = "Enable Reinforcement";
                statement = "['reinforce_on',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
            class reinforce_off {
                displayName = "Disable Reinforcement";
                statement = "['reinforce_off',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
            };
        };
        class target {
            displayName = "Set Task Target";
            statement = "['target',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
        };
        class reset {
            displayName = "Task Reset";
            statement = "['reset',_groups,_objects,_position,true] call FST_HCSpawn_fnc_burnsDialog";
        };
    };
};
