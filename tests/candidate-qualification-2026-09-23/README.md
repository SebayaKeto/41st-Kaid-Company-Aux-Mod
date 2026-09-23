# Candidate qualification, September 23

See READINESS.md for disposition and limitations. These are dedicated-server
fixtures, not evidence of human client participation.

Incoming source was staged in the preceding local commit. The final change
repairs Gulanthar movement inheritance. The AAT feedback experiment remains
mission-only and is NOT included in any candidate addon PBO.

Historical suites and failed fixtures are retained so the findings can be
audited. CandidateQualification.VR corresponds to the original incoming build,
including its subsequently invalidated VR slope fixture. CandidateCreatures.Altis
is the repaired Gulanthar suite. CandidateCombat.VR is the focused combat suite.
CandidatePodsClean.Altis isolates pod fault/concurrency tests on dry high ground.
CandidateSafeArmor.VR tests the conservative CBA setting and requires four HCs.

Package a mission directory with pbo_tools.pack(source, destination), without
an addon prefix, and keep its world suffix. Do not change mod files during a run.
Use the same candidate/dependency preset on every process. The test-only
CfgRemoteExec policy is for loopback fixtures and is not a deployment preset.

Raw logs and process records stay in the task outputs/testing/runs directory;
runtime-results.json records their SHA-256 and preserves failed assertions.
No scripts here authorize deployment, Workshop publishing or stopping unrelated
server sessions. Mission profile paths are disposable and separate from live.
