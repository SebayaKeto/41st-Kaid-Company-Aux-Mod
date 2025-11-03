////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.45
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 24 11:48:44 2024 : 'file' last modified on Wed Apr 17 19:43:44 2024
////////////////////////////////////////////////////////////////////
#include "mec_base_defines.hpp"
#define _ARMA_
class CfgFunctions
{
    class FST_MEC_func
    {
        tag = MEC_TAG; 
        class FST_MEC_Core_func
        {
            file = MEC_FUNCTION_PATH;
            class electricitysystem
            {
                file = "FST\FST_MEC\FST_MEC_Core\functions\electricitysystem\fn_mec_powerinitialize.sqf";
                class checkChargeState {};
                class initializeChargeState {};
            };
        };
    };
};
