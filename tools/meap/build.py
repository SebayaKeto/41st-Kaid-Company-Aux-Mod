"""Rebuild Core and Daidalos; keep four upstream asset/dependency PBOs unchanged."""
from pathlib import Path
import argparse
import hashlib
import json
import os
import subprocess
import tempfile

from pbo_tools import pack, read, index

repo = Path(__file__).resolve().parents[2]
parser = argparse.ArgumentParser()
parser.add_argument('--cfgconvert', required=True, type=Path)
args = parser.parse_args()
for name, prefix in [('MEAP_Core', r'MEAP\MEAP_Core'), ('MEAP_Architect_Core', r'MEAP\MEAP_Architect\MEAP_Architect_Core')]:
    source = repo / 'PUBLISHED MODPACK' / name
    destination = source.with_suffix('.pbo')
    with tempfile.TemporaryDirectory() as temporary:
        config = Path(temporary) / 'config.bin'
        result = subprocess.run([str(args.cfgconvert), '-bin', '-dst', str(config), str(source / 'config.cpp')], capture_output=True, text=True)
        if result.returncode or 'error' in (result.stdout + result.stderr).lower() or not config.is_file():
            raise RuntimeError(result.stdout + result.stderr)
        built = Path(temporary) / destination.name
        pack(source, built, prefix)
        for entry in index(built)[0].values():
            assert read(built, entry['name']) == (source / entry['name'].replace('\\', '/')).read_bytes()
        pending = destination.with_suffix('.pbo.new')
        pending.write_bytes(built.read_bytes())
        os.replace(pending, destination)
    print(json.dumps({'file': destination.name, 'sha256': hashlib.sha256(destination.read_bytes()).hexdigest(), 'configCompile': 'passed', 'packedSourceReadback': 'passed'}))
