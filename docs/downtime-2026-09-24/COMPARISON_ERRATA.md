# Correction to September 23 AAT comparison labels

September 24 inspection found `Attempt to override final function` messages that the earlier result summarizer did not classify as test failures. Arma protected the registered functions, so assigning replacement function bodies from the mission did not change the running behavior.

- **Run31:** the sections labeled baseline and candidate ran the loaded candidate functions. They are repeated observations of that loaded build, not a valid baseline-versus-candidate comparison. Its Gulanthar movement/animation observations remain observations of the loaded candidate; they do not prove a comparative improvement.
- **Run40:** the proposed no-stop steering replacement was rejected. Its measurements are observations of the loaded candidate; the claim that they measured the alternative steering implementation is withdrawn. The experimental change was never promoted into the candidate.
- **Run42:** the new four-variant comparison had the same problem and was stopped. Function-based variant comparisons are invalid. This run is retained as failed test setup, not passing qualification.

The candidate PBOs and sealed September 23 ZIP have not been changed. This correction invalidates comparison interpretations, not the fact that vehicles moved/fired or the separate infantry, BX, N99 and fog checks. No broad AAT improvement or completed terrain fix should be inferred from these runs.

The replacement test mod, `@AATLab`, registers separate functions in its own PBO and logs the function variant actually reached for every group. It is test-only. The released candidate and live mod files remain separate. Further comparisons must prove their variant was executed and reject protected-function override warnings.
