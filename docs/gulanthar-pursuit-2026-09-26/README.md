# Gulanthar population and pursuit update — 26 September 2026

Prepared candidate; not published or deployed. Gameplay validation remains pending.

## Behavior

- Remove the eight-Gulanthar population cap from the shared admission path used by Zeus and managed spawns. Legacy FST_HC_GulantharLimit values no longer affect admission. The independent AT-RT population limit and existing owner-performance brake remain.
- Charge acquired enemies at full speed within 600 m by default, up from the old 100 m default. The new server-synchronized CBA setting, Gulanthar charge distance (Necroplague - Stalker), also applies to missions with the old agro value saved. Effective charge distance is the larger of this setting and the legacy agro setting.
- Keep the existing search/hunt settings (defaults 1,500/1,400 m). Beyond charge range, pursue the target at normal speed rather than slowly wandering around a random position near it. Existing user-waypoint priority outside charge range remains.
- Within charge range, order movement to the target's actual position rather than the generic helper's randomized 2 m offset. Refresh every 0.5 seconds inside 50 m and every second farther away. Check close-range behavior every 0.25 seconds; the wider enemy scan remains every two seconds.
- A failed psychic-attack attempt immediately falls through to the normal melee/eating decision instead of wasting the first attack opportunity. Actual hit range, damage, wind-up, cooldown, health, and successful psychic attack behavior are preserved.

## Packages and verification

Replace both FST_HCSpawn.pbo and JMSEF_animals.pbo together in a separate test copy of the Aux. Keep the existing FST_BURNS_Gulanthar.pbo. Do not load the test copy alongside the live Aux. New archives have not been release-signed; existing signatures do not cover them.

Four changed SQF files pass SQFLint error checks. Only two script entries changed in each archive; all 158 other entries, their original headers, compiled configs, models, and textures are unchanged. verification.json records package hashes and entry preservation. Source and matching tracked PBOs are updated in PUBLISHED MODPACK. The installed Workshop mod and current upload staging folder are untouched.

## Gameplay checks before release

Use an isolated test mission with matching Aux, dependencies, server, HCs, and clients:

1. Place at least 12 Gulanthars with healthy owner telemetry and verify all remain, including when the legacy cap variable is 8 or 1. Check all three variants. Separately confirm the AT-RT cap still rejects an over-limit request.
2. With legacy agro set to 100 and charge distance at 600, place a hostile target at 500 m. Verify mode 2/full-speed approach and a completed melee attack. At 800 m, verify direct normal-speed approach until charge range. Repeat with a moving target and slopes.
3. Set psychic chance to zero in the test mission and place a target just inside melee reach. Verify the first eligible opportunity starts melee instead of being consumed by a failed psychic roll. Repeat after psychic cooldown expires, and with psychic chance one/eligible lone target.
4. Verify ownership transfer does not duplicate controllers and the kill switch still pauses/resumes them. Measure server/HC frame time with larger packs; removal of a population cap is not proof of unlimited capacity.

These engine checks have not run during the live operation. The B1 non-Linger pod casualty investigation is separate and is not fixed by these packages.
