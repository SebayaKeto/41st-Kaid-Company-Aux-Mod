// Radiation Monitor side panel resources
class RscText;
class RscPicture;
class RscProgress;
class RscIGUIText;
class RscIGUIValue;

class RscCustomInfoBUZZ_Radiation_MonitorLeft {
    idd = 31501;
    onLoad = "_this call BUZZ_Radiation_fnc_monitorOnLoad";
    // Panel layout
    class controls {
        class Background: RscText {
            idc = 1000;
            x = "0";
            y = "0";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_H', (10 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class Title: RscIGUIText {
            idc = 1001;
            x = "0";
            y = "0";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "RADIATION";
        };
        // Dark disc behind the direction ring
        class RingDisc: RscPicture {
            idc = 2100;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_disc_ca.paa";
            colorText[] = {0, 0, 0, 0.35};
        };
        class ViewCone: RscPicture {
            idc = 2101;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_cone_ca.paa";
            colorText[] = {0, 0.85, 1, 0.5};
        };
        class ConeEdge: RscPicture {
            idc = 2102;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_coneEdge_ca.paa";
            colorText[] = {0, 0.85, 1, 1};
        };
        class Dot0: RscPicture {
            idc = 2000;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot1: RscPicture {
            idc = 2001;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot2: RscPicture {
            idc = 2002;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot3: RscPicture {
            idc = 2003;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot4: RscPicture {
            idc = 2004;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot5: RscPicture {
            idc = 2005;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot6: RscPicture {
            idc = 2006;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot7: RscPicture {
            idc = 2007;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot8: RscPicture {
            idc = 2008;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot9: RscPicture {
            idc = 2009;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot10: RscPicture {
            idc = 2010;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot11: RscPicture {
            idc = 2011;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot12: RscPicture {
            idc = 2012;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot13: RscPicture {
            idc = 2013;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot14: RscPicture {
            idc = 2014;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot15: RscPicture {
            idc = 2015;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot16: RscPicture {
            idc = 2016;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot17: RscPicture {
            idc = 2017;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot18: RscPicture {
            idc = 2018;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot19: RscPicture {
            idc = 2019;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot20: RscPicture {
            idc = 2020;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot21: RscPicture {
            idc = 2021;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot22: RscPicture {
            idc = 2022;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot23: RscPicture {
            idc = 2023;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot24: RscPicture {
            idc = 2024;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot25: RscPicture {
            idc = 2025;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot26: RscPicture {
            idc = 2026;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot27: RscPicture {
            idc = 2027;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot28: RscPicture {
            idc = 2028;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot29: RscPicture {
            idc = 2029;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot30: RscPicture {
            idc = 2030;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot31: RscPicture {
            idc = 2031;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot32: RscPicture {
            idc = 2032;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot33: RscPicture {
            idc = 2033;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot34: RscPicture {
            idc = 2034;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot35: RscPicture {
            idc = 2035;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot36: RscPicture {
            idc = 2036;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot37: RscPicture {
            idc = 2037;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot38: RscPicture {
            idc = 2038;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot39: RscPicture {
            idc = 2039;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot40: RscPicture {
            idc = 2040;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot41: RscPicture {
            idc = 2041;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot42: RscPicture {
            idc = 2042;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot43: RscPicture {
            idc = 2043;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot44: RscPicture {
            idc = 2044;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot45: RscPicture {
            idc = 2045;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot46: RscPicture {
            idc = 2046;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot47: RscPicture {
            idc = 2047;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot48: RscPicture {
            idc = 2048;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot49: RscPicture {
            idc = 2049;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot50: RscPicture {
            idc = 2050;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot51: RscPicture {
            idc = 2051;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot52: RscPicture {
            idc = 2052;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot53: RscPicture {
            idc = 2053;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot54: RscPicture {
            idc = 2054;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot55: RscPicture {
            idc = 2055;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot56: RscPicture {
            idc = 2056;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot57: RscPicture {
            idc = 2057;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot58: RscPicture {
            idc = 2058;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot59: RscPicture {
            idc = 2059;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot60: RscPicture {
            idc = 2060;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot61: RscPicture {
            idc = 2061;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot62: RscPicture {
            idc = 2062;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot63: RscPicture {
            idc = 2063;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot64: RscPicture {
            idc = 2064;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class FieldLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "6.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "FIELD";
        };
        class FieldValue: RscIGUIValue {
            idc = 1002;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "6.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class DoseLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "7.0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "DOSE";
        };
        class DoseValue: RscIGUIValue {
            idc = 1004;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "7.0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class DoseBar: RscProgress {
            idc = 1005;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "7.85 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            colorFrame[] = {1, 1, 1, 0.5};
            colorBar[] = {1, 1, 1, 0.9};
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class SuitLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "8.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "SUIT";
        };
        class SuitValue: RscIGUIValue {
            idc = 1006;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "8.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class IodineLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "9.15 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "IODINE";
        };
        class IodineValue: RscIGUIValue {
            idc = 1007;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "9.15 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
    };
};

class RscCustomInfoBUZZ_Radiation_MonitorRight {
    idd = 31502;
    onLoad = "_this call BUZZ_Radiation_fnc_monitorOnLoad";
    // Panel layout
    class controls {
        class Background: RscText {
            idc = 1000;
            x = "0";
            y = "0";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_H', (10 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class Title: RscIGUIText {
            idc = 1001;
            x = "0";
            y = "0";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "RADIATION";
        };
        // Dark disc behind the direction ring
        class RingDisc: RscPicture {
            idc = 2100;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_disc_ca.paa";
            colorText[] = {0, 0, 0, 0.35};
        };
        class ViewCone: RscPicture {
            idc = 2101;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_cone_ca.paa";
            colorText[] = {0, 0.85, 1, 0.5};
        };
        class ConeEdge: RscPicture {
            idc = 2102;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\BUZZ_Radiation\data\BUZZ_Radiation_coneEdge_ca.paa";
            colorText[] = {0, 0.85, 1, 1};
        };
        class Dot0: RscPicture {
            idc = 2000;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot1: RscPicture {
            idc = 2001;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot2: RscPicture {
            idc = 2002;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot3: RscPicture {
            idc = 2003;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot4: RscPicture {
            idc = 2004;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot5: RscPicture {
            idc = 2005;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot6: RscPicture {
            idc = 2006;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot7: RscPicture {
            idc = 2007;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot8: RscPicture {
            idc = 2008;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot9: RscPicture {
            idc = 2009;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot10: RscPicture {
            idc = 2010;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot11: RscPicture {
            idc = 2011;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot12: RscPicture {
            idc = 2012;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot13: RscPicture {
            idc = 2013;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot14: RscPicture {
            idc = 2014;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot15: RscPicture {
            idc = 2015;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot16: RscPicture {
            idc = 2016;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot17: RscPicture {
            idc = 2017;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot18: RscPicture {
            idc = 2018;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot19: RscPicture {
            idc = 2019;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot20: RscPicture {
            idc = 2020;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot21: RscPicture {
            idc = 2021;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot22: RscPicture {
            idc = 2022;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot23: RscPicture {
            idc = 2023;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot24: RscPicture {
            idc = 2024;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot25: RscPicture {
            idc = 2025;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot26: RscPicture {
            idc = 2026;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot27: RscPicture {
            idc = 2027;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot28: RscPicture {
            idc = 2028;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot29: RscPicture {
            idc = 2029;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot30: RscPicture {
            idc = 2030;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot31: RscPicture {
            idc = 2031;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot32: RscPicture {
            idc = 2032;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot33: RscPicture {
            idc = 2033;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot34: RscPicture {
            idc = 2034;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot35: RscPicture {
            idc = 2035;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot36: RscPicture {
            idc = 2036;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot37: RscPicture {
            idc = 2037;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot38: RscPicture {
            idc = 2038;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot39: RscPicture {
            idc = 2039;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot40: RscPicture {
            idc = 2040;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot41: RscPicture {
            idc = 2041;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot42: RscPicture {
            idc = 2042;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot43: RscPicture {
            idc = 2043;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot44: RscPicture {
            idc = 2044;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot45: RscPicture {
            idc = 2045;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot46: RscPicture {
            idc = 2046;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot47: RscPicture {
            idc = 2047;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot48: RscPicture {
            idc = 2048;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot49: RscPicture {
            idc = 2049;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot50: RscPicture {
            idc = 2050;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot51: RscPicture {
            idc = 2051;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot52: RscPicture {
            idc = 2052;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot53: RscPicture {
            idc = 2053;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot54: RscPicture {
            idc = 2054;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot55: RscPicture {
            idc = 2055;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot56: RscPicture {
            idc = 2056;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot57: RscPicture {
            idc = 2057;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot58: RscPicture {
            idc = 2058;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot59: RscPicture {
            idc = 2059;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot60: RscPicture {
            idc = 2060;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot61: RscPicture {
            idc = 2061;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot62: RscPicture {
            idc = 2062;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot63: RscPicture {
            idc = 2063;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class Dot64: RscPicture {
            idc = 2064;
            x = "0";
            y = "0";
            w = "0";
            h = "0";
            text = "\A3\ui_f\data\map\markers\military\dot_ca.paa";
            colorText[] = {1, 1, 1, 0.15};
        };
        class FieldLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "6.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "FIELD";
        };
        class FieldValue: RscIGUIValue {
            idc = 1002;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "6.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class DoseLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "7.0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "DOSE";
        };
        class DoseValue: RscIGUIValue {
            idc = 1004;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "7.0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class DoseBar: RscProgress {
            idc = 1005;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "7.85 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "(profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            colorFrame[] = {1, 1, 1, 0.5};
            colorBar[] = {1, 1, 1, 0.9};
            colorBackground[] = {0, 0, 0, 0.3};
        };
        class SuitLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "8.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "SUIT";
        };
        class SuitValue: RscIGUIValue {
            idc = 1006;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "8.35 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
        class IodineLabel: RscIGUIText {
            idc = -1;
            x = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            y = "9.15 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "IODINE";
        };
        class IodineValue: RscIGUIValue {
            idc = 1007;
            x = "0.3 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))])";
            y = "9.15 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "0.7 * (profileNamespace getVariable ['IGUI_GRID_CUSTOMINFORIGHT_W', (10 * (((safezoneW / safezoneH) min 1.2) / 40))]) - 0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            text = "";
        };
    };
};
