# FST Sabre Armor Extension

Native Arma 3 extension for the Sabre APC armor HUD. The extension evaluates normalized damage values and returns a bounded, versioned assessment. It does not create UI controls; the Sabre SQF HUD remains responsible for presentation.

## Protocol

SQF invokes the extension as follows:

```sqf
"FST_SabreArmorExtension" callExtension ["assess-v1", [0, 0, 0, 0, 0]]
```

Arguments are five numeric damage values in the inclusive range `0` to `1`, ordered as front armor, left armor, right armor, rear armor, and total vehicle damage. Let `callExtension` serialize these numbers; applying `str` first produces quoted strings that the native parser rejects.

The successful response format is:

```text
v1|frontIntegrity|leftIntegrity|rightIntegrity|rearIntegrity|hullIntegrity|condition|criticalAlert
```

Each integrity value is an integer from `0` to `100`. `condition` is `NOMINAL`, `DEGRADED`, or `CRITICAL`; `criticalAlert` is `0` or `1`. Invalid requests return an `ERROR|...` response and a nonzero extension result code. The SQF consumer rejects malformed replies, disables the extension for the current HUD session, and continues with a local assessment.

## Build

Build this project with Visual Studio 2022 Build Tools or Visual Studio 2022 with the **Desktop development with C++** workload installed:

```powershell
cmake -S . -B build -A x64
cmake --build build --config Release
```

This creates `build\Release\FST_SabreArmorExtension.dll`. Arma 3 is 64-bit, so do not build a 32-bit DLL.

## Deploy

Copy the 64-bit build to the mod root as `FST_SabreArmorExtension_x64.dll`, alongside the `Addons` directory. Keep the SQF extension name `FST_SabreArmorExtension`: Arma's 64-bit loader adds the `_x64.dll` suffix. Do not pack the DLL inside a PBO. Every client that should use the enhanced armor assessment needs the DLL. Clients without it retain the local SQF assessment after one rejected response. See the [Bohemia extension naming documentation](https://community.bistudio.com/wiki/Extensions).

## Extension Boundaries

`callExtension` is synchronous. The HUD calls this extension at most twice per second, while the UI still refreshes locally every 0.1 seconds. Keep future extension work deterministic and short-lived; do not perform blocking network operations from `RVExtensionArgs`.
