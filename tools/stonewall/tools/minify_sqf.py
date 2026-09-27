"""Strip comments/indentation from an SQF file so it can be pasted into the debug console
(the console compiles without the preprocessor, so comments would be syntax errors)."""
import sys
from pathlib import Path


def strip_comments(src: str) -> str:
    out, i, n = [], 0, len(src)
    while i < n:
        c = src[i]
        if c in "\"'":
            j = i + 1
            while j < n:
                if src[j] == c:
                    if j + 1 < n and src[j + 1] == c:
                        j += 2
                        continue
                    break
                j += 1
            out.append(src[i:j + 1])
            i = j + 1
        elif src.startswith("//", i):
            while i < n and src[i] != "\n":
                i += 1
        elif src.startswith("/*", i):
            e = src.find("*/", i + 2)
            if e < 0:
                raise SystemExit("unterminated block comment")
            i = e + 2
        else:
            out.append(c)
            i += 1
    return "".join(out)


def minify(src: str) -> str:
    lines = [ln.strip() for ln in strip_comments(src).splitlines()]
    return "\n".join(ln for ln in lines if ln) + "\n"


def parts(text: str, limit: int = 900):
    """Split into debug-console pastes: each appends to a server string; the last one compiles and runs it."""
    lines, chunks, cur = text.splitlines(keepends=True), [], ""
    for ln in lines:
        if len(cur) + len(ln) > limit and cur:
            chunks.append(cur)
            cur = ""
        cur += ln
    chunks.append(cur)
    out = []
    for i, c in enumerate(chunks):
        lit = '"' + c.replace('"', '""') + '"'
        # the buffer lives in localNamespace on the server: a client's publicVariable cannot swap it between pastes
        prev = '""' if i == 0 else '(localNamespace getVariable ["stonewall_code", ""])'
        body = f'localNamespace setVariable ["stonewall_code", {prev} + {lit}];'
        if i == len(chunks) - 1:
            body += '\ncall compile (localNamespace getVariable ["stonewall_code", ""]);'
            body += '\nlocalNamespace setVariable ["stonewall_code", nil];'
        out.append(body + "\n")
    return out


if __name__ == "__main__":
    s, d = Path(sys.argv[1]), Path(sys.argv[2])
    text = minify(s.read_text(encoding="utf-8"))
    if any(ln.startswith("#") for ln in text.splitlines()):
        raise SystemExit("preprocessor directive left in output")
    d.write_text(text, encoding="utf-8", newline="\n")
    print(f"{s.name}: {len(s.read_text(encoding='utf-8'))} -> {len(text)} chars -> {d}")
    pdir = d.parent / (d.stem.replace(".min", "") + "_parts")
    pdir.mkdir(exist_ok=True)
    ps = parts(text)
    for i, p in enumerate(ps, 1):
        (pdir / f"part{i}_of_{len(ps)}.sqf").write_text(p, encoding="utf-8", newline="\n")
    print(f"fallback: {len(ps)} console pastes (<= {max(len(p) for p in ps)} chars each) -> {pdir}")
