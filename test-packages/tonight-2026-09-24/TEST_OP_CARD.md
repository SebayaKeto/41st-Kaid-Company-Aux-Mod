# Tonight's rehearsal

Use **DAARA 0.4 Counterattack** with the matching candidate Aux on the server, every HC and every player. The local complete Aux folder is `outputs/testing/server/@TonightCandidate`. The portable package contains replacements and a checked-copy tool; it does not include the 5.8 GB of unchanged assets.

Start a fresh operation in shadow mode. Confirm everyone can see each other and the selected Aux is the same before step-off. Open the mission panel with **Ctrl+Shift+F8**. Enable infantry autonomy and confirm step-off when ready. Counterattacks remain limited to one B1 squad at a time, 75 seconds per attack and at least 120 seconds between starts. DAARA does not automatically command the AAT sections.

## AAT section exercise

1. Place three AI AATs, each with its own crew group, roughly 35 m apart in column on open, gentle ground. Keep all of them within 250 m. Two tanks are also supported; four are rejected.
2. Select their groups in Zeus, use **BURNS → Task AAT Section Assault (Test)**, and click a destination ahead. Ordinary Assault, Rush and Hunt also now approach a known contact toward the 100–200 m firing band, without requiring the section task.
3. Observe column travel, deployment into fixed slots about 30 m apart after detecting contact, and a coordinated firing front. Judge useful spacing and mutual support; the task does not synchronize shots or force a geometrically exact line.
4. Check that a new task, native Zeus waypoint or Reset takes priority. A blocked formation eventually releases coordination and continues individual Assault; regroup on a clearer approach. Steep hills and dense woodland are not the first test lane.
5. Repeat with a human-crewed Saber, then on an actual Umbara approach. Note the tank, task, location, slope and time if it reverses or stalls.

## Other priority checks

| Exercise | What to observe |
|---|---|
| Player Saber, Super Saber and Recon | Time a 90-degree stationary turn, reverse along a flat clear lane, then accelerate forwards. Standard/Super must retain 60 km/h and Recon 120. Check steering overshoot and braking; report sustained reverse speed. |
| Preacher with two affected clients | Both clients see body, weapon and gear. If not, run selected-player visibility diagnostics before a reset and retain all three client RPTs. Root cause is still unresolved. |
| FST garrison and defense | Prompt firing at exposed infantry while retaining useful positions. Accuracy is intentionally preserved. |
| B1 squads versus fireteams | More shooting, less circling; leader stays with the firing front. |
| B1 rifle/AT versus a player Saber | Rifle engagement and launcher use below 60 m, with clear line of sight. |
| BX Creep, Ambush, CQB | Prone creep; concealed ambush followed by ranged weapons; CQB closes for melee. Confirm visual animation timing. |
| N99 Assault and HC transfer | Destination accepted and measurable movement after a transfer or replacement order. Focused tests passed, but broader runs still reproduce intermittent hesitation; this remains an open issue. |
| DAARA capture | Choose the actual objective on the map, including duplicate names; wait for **Mission confirmed: secured**. |
| Fog | A small improvement only: the mission uses a 1.05 visibility tuning factor. Ask players before increasing it. |

Record the new server RPT, HC RPTs and timestamps. For the separate adviser, use this package's `DAARA-0.4/adviser/Start-Adviser.ps1` with the new server RPT, leave automatic review off initially, and omit ResumeState. Its default address is `http://127.0.0.1:8770/`; do not reuse the ended 8766 session.

Main and independent Training are not started or changed by this package. Never select Training's 2328/2329 profile for this rehearsal. To roll back, select the prior Aux copy and prior mission together.
