# Test operation — 24 September

Use **DAARA 0.4 Counterattack** with this matching Aux candidate. This is a local rehearsal package, not a Workshop release or a live-server deployment. Check `QUALIFICATION.md` for final results and limits before launching.

## Prepared on this box

The complete candidate Aux is:

`C:\Users\Administrator\Documents\Codex\2026-09-23\extract-the-handoff-and-read-start\outputs\testing\server\@TonightCandidate`

Its launcher name is **41st Kaid Aux - TEST OP 24 Sep**. It contains the earlier B1, AT, garrison, BX, Gulanthar and N99 candidate fixes, plus the new optional AAT section task, revised attack-range goal and Saber handling addon. Accuracy and weapon damage are preserved. The unsuccessful hill-recovery prototype is excluded.

## Launch preparation

1. Verify the ZIP's adjacent SHA-256 file, then verify `SHA256SUMS.txt` after extraction. `New-TestCopy.ps1` verifies the package automatically before making a copy.
2. In a separate rehearsal profile, load the prepared candidate Aux and the usual dependencies. Every HC and player needs the same candidate. Load **one** Aux copy. These rehearsal replacements are not release-signed; use the existing rehearsal signature policy.
3. Select `DAARA-0.4/MPMissions/DaaraUmbara_040_Counterattack.m_36vwm796742s99.pbo`. The mission contains the small fog adjustment. Do not launch any qualification fixture as the actual operation.
4. Start a fresh operation. Follow `TEST_OP_CARD.md` for the in-game panel, objective capture and prioritized exercises. Use the new server RPT if starting the adviser; do not resume the ended 8766 session.

For another machine, `New-TestCopy.ps1 -SourceAux <existing Aux folder> -Destination <new test folder>` builds and verifies a separate full mod from the existing assets plus this package. It refuses mismatched baseline files or an existing destination. `-VerifyOnly` checks inputs without copying. Unchanged assets total about 5.8 GB and are not duplicated in this portable ZIP.

Main and Training are not restarted or reconfigured by these files. The independent Training profile uses game port **2328** and query port **2329**; keep it separate.

## AAT controls

Ordinary AAT attack tasks prefer an approach about **150 m** from a known target, with **100–200 m** as the intended firing band. Defend/hold/retreat orders are not converted into advances.

For coordinated movement, select **2–3 nearby AI AAT crew groups**, one tank per group, then use **BURNS → Task AAT Section Assault (Test)** and click ahead. It advances in column and deploys spaced line positions on clear, gentle ground. It does not recruit unselected tanks or enable DAARA armor autonomy. Four-tank sections were inconsistent and are rejected in this build.

Reset, replacement tasks and native Zeus waypoints take priority. The section releases coordination if it cannot form; tanks retain their individual Assault intent. There is no teleport, velocity boost or global reverse lock.

## Rollback and remaining work

The Saber handling addon increases engine torque by 20%, improves turning assistance and strengthens reverse gearing across the 16 41st Saber variants. Standard and Super Sabers retain **60 km/h**; Recon retains **120 km/h**, as requested. Player reverse speed and handling feel need confirmation during the rehearsal; see `SABER_HANDLING.md`.

Keep the prior Aux and mission as a matched rollback pair. The frozen September 23 candidate ZIP is unchanged. Switching profiles/copies is sufficient; this package overwrites no live server.

Read `REMAINING_WORK.md`: Preacher's invisible-player root cause, AAT hill rollback and intermittent N99 owner-transfer movement are still open. The selected checks finished **198/199 passed**, with that N99 failure retained. Human-client observation remains necessary for Saber reverse handling, balance, BX visual timing, the objective picker and the fog change.
