# September 24 deployment

This supplements the sealed `../tonight-2026-09-24` test package with the latest GitHub armor assets and Umbaran infantry. Use Workshop item **3048946639** for the complete matching player mod. The full release manifest identifies every file; this ZIP is a build supplement, not a standalone mod.

The ZIP contains the five small replacement addons, the seven changed Armor source assets, the DAARA 0.4 mission and adviser. Rebuild the Armor PBO by overlaying these seven assets on the supplied Pod Fix Armor candidate; retain all other packed entries. The validated full build retained 1,849 unchanged Armor entries byte-for-byte. Source is committed alongside this package. The full 2 GB Armor PBO is distributed through Workshop.

Main uses a separate local `Kaid Aux 24 Sep` mod and DAARA 0.4 Counterattack, with four HCs. Training 2328/2329 keeps its old profile and Aux. Its files were verified unchanged. The Main copy and new staging copy were checked against RELEASE_MANIFEST.json.

Players must finish the Workshop update and restart Arma before joining. Start a fresh operation. In-game, open **Ctrl+Shift+F8**, enable infantry autonomy, then confirm step-off when ready. Capture objectives through the map picker and wait for **Mission confirmed: secured**. The separate adviser uses a fresh session on **8770**, automatic review initially off; the ended 8766 session is obsolete.

For coordinated AATs, select **2–3 separate AI AAT crew groups** and use **BURNS → Task AAT Section Assault (Test)**. Ordinary attack tasks aim for 100–200 m, with 150 m preferred. DAARA does not autonomously direct tanks. Standard/Super Sabers remain capped at 60 km/h, Recon at its existing 120; handling changes apply across all 16 variants. B1 accuracy is preserved following debrief feedback.

Known limits: AAT hill rollback, intermittent N99 movement after HC transfer, and Preacher's invisible-player root cause remain open. Player Saber reverse handling and visual/balance checks require tonight's human test. Prior behavioral qualification passed 198/199 checks, retaining the N99 failure, plus 99 adviser checks. See the sealed package's test card and remaining-work notes.
