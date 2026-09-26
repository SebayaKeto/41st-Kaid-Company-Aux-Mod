"""Remove redundant root config.cpp from a PBO while preserving all other bytes.

Use only when config.bin is the intended runtime config. Refuses to overwrite
input/output and validates the archive checksum, config signature and every
retained entry. PBOs and model assets must stay outside the Git repository.
"""
import argparse
import hashlib
import io
import json
from pathlib import Path
import struct


def cstring(stream):
    result = bytearray()
    while True:
        char = stream.read(1)
        if not char:
            raise ValueError("Truncated PBO header")
        if char == b"\0":
            return result.decode("latin1")
        result.extend(char)


def parse(data):
    stream = io.BytesIO(data)
    prefixes, entries, names = [], [], set()
    while True:
        start = stream.tell()
        name = cstring(stream)
        raw = stream.read(20)
        if len(raw) != 20:
            raise ValueError("Truncated entry header")
        header = struct.unpack("<5I", raw)
        if not name and header[0] == 0x56657273:
            while cstring(stream):
                cstring(stream)
            prefixes.append(data[start:stream.tell()])
            continue
        if not name:
            terminal = data[start:stream.tell()]
            break
        key = name.replace("\\", "/").lower()
        if key in names:
            raise ValueError("Duplicate entry: " + key)
        names.add(key)
        entries.append({"name": name, "key": key, "header": header,
                        "raw_header": data[start:stream.tell()]})
    offset = stream.tell()
    for entry in entries:
        end = offset + entry["header"][4]
        entry["data"] = data[offset:end]
        if len(entry["data"]) != entry["header"][4]:
            raise ValueError("Truncated payload")
        offset = end
    if data[offset:] != b"\0" + hashlib.sha1(data[:offset]).digest():
        raise ValueError("Invalid PBO checksum or trailing data")
    return prefixes, entries, terminal


def repair(source, destination, report):
    if destination.exists() or source.resolve() == destination.resolve():
        raise ValueError("Use a new output path; inputs are never overwritten")
    original = source.read_bytes()
    prefixes, entries, terminal = parse(original)
    by_name = {entry["key"]: entry for entry in entries}
    if "config.cpp" not in by_name or "config.bin" not in by_name:
        raise ValueError("Expected both root config.cpp and config.bin")
    binary = by_name["config.bin"]
    if binary["header"][0] != 0 or not binary["data"].startswith(b"\0raP"):
        raise ValueError("Expected an uncompressed, compiled config.bin")
    retained = [entry for entry in entries if entry["key"] != "config.cpp"]
    body = b"".join(prefixes + [e["raw_header"] for e in retained] +
                    [terminal] + [e["data"] for e in retained])
    fixed = body + b"\0" + hashlib.sha1(body).digest()
    new_prefixes, new_entries, new_terminal = parse(fixed)
    assert prefixes == new_prefixes and terminal == new_terminal
    assert len(new_entries) == len(entries) - 1
    for before, after in zip(retained, new_entries):
        assert before["raw_header"] == after["raw_header"]
        assert before["data"] == after["data"]
    evidence = {
        "input_sha256": hashlib.sha256(original).hexdigest(),
        "output_sha256": hashlib.sha256(fixed).hexdigest(),
        "input_bytes": len(original), "output_bytes": len(fixed),
        "removed_entries": ["config.cpp"],
        "retained_entries": len(retained),
        "all_retained_entry_headers_and_payloads_identical": True,
        "archive_properties_identical": True,
        "config_bin_sha256": hashlib.sha256(binary["data"]).hexdigest(),
        "model_entries": [{"path": e["name"],
                           "sha256": hashlib.sha256(e["data"]).hexdigest()}
                          for e in retained if e["key"].endswith(".p3d")],
    }
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes(fixed)
    report.write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf8")
    print(json.dumps(evidence, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("destination", type=Path)
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    repair(args.source, args.destination, args.report)