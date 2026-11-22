# P26z8 (18 Nov 2026): Suddra build 2 on P26z7

Published 22:52 EST (03:52Z 19 Nov) on Miran's go typed in the Mapmaking Omnibus chat ("Go P26z8", verified in that session's transcript; Miran confirmed in the Aux chat). ManifestID 5504948947415350007, time_updated 1795060334, 99 files / 8,393,286,297 B (-46,031 B vs P26z7).
Base = P26z7 (6426817668243429582). Rollback staged = Downloads/Steam-aux-ROLLBACK-to-P26z6-from-P26z8 (P26z6 8190672032863050125; --check passed 03:52Z). Built by `D:/AuxUpdater/aatcrew/make_p26z8.py`.

- CHANGED fst_suddra.pbo -> 7aecefdd (283,048,138): Suddra build 2 restores 3 protected site pads that build 1 flooded at two op 1-2 sites; 14 layer/wrp files differ, config.bin byte-identical.
- CHANGED fst_suddra_reed.pbo -> 2528a44d and fst_sud_rpine.pbo -> e0563c07: content byte-identical to build 1 (entry timestamps only).
- Ember Caldera build 8 (711e5584) unchanged.

Checks: stage_terrain (only the known Stratis re-open, identical to live), `--check` passed 03:51Z. NOT run: engine boot of the payload (Suddra lane S3 headless boots ran from pinned output_b2).
Open P0 at publish: Miran's "visual filter on every map" after the P26z7 update; P26z7/P26z6 contents measured clean; Arma updated 2.22.154191 -> .154202 the same day; vanilla no-mods fine; tests A/B open.
