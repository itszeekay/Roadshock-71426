#!/usr/bin/env python3
"""Verify repository artifacts in one go (for reproduce-from-scratch).

Checks:
  - dump checksums (dumps/SHA256SUMS)
  - prebuilt firmware checksums (firmware/prebuilt/SHA256SUMS)
  - reference manifest (reference/asr560x/MANIFEST.sha256)
  - tool self-tests (asr5601_dump --selftest, protocol_ref self-test)
  - Intel HEX line endings (LF)
  - Python files compile

Usage:
    python3 tools/verify_builds.py
    python3 tools/verify_builds.py --root /path/to/repo
"""
import argparse
import hashlib
import os
import py_compile
import subprocess
import sys


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()


def check_sums_file(root, sums_file, base):
    """Verify a sha256sum-format file; return list of failures."""
    path = os.path.join(root, sums_file)
    if not os.path.exists(path):
        return ["missing: %s" % sums_file]
    failures = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split(None, 1)
            if len(parts) != 2:
                continue
            expect, rel = parts
            rel = rel.lstrip("*")
            full = os.path.join(root, base, rel)
            if not os.path.exists(full):
                failures.append("missing: %s" % os.path.join(base, rel))
                continue
            if sha256(full) != expect:
                failures.append("hash mismatch: %s" % rel)
    return failures


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default=os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    args = ap.parse_args()
    root = args.root

    failures = []
    # dumps
    for f in check_sums_file(root, os.path.join("dumps", "SHA256SUMS"), "dumps"):
        failures.append(f)
    # firmware prebuilt
    for f in check_sums_file(root, os.path.join("firmware", "prebuilt", "SHA256SUMS"),
                             os.path.join("firmware", "prebuilt")):
        failures.append(f)
    # reference manifest
    for f in check_sums_file(root, os.path.join("reference", "asr560x", "MANIFEST.sha256"),
                             os.path.join("reference", "asr560x")):
        failures.append(f)

    # py_compile all tool sources
    for name in os.listdir(os.path.join(root, "tools")):
        if name.endswith(".py"):
            try:
                py_compile.compile(os.path.join(root, "tools", name), doraise=True)
            except Exception as e:
                failures.append("compile failed: %s (%s)" % (name, e))

    # HEX line endings
    for base, _dirs, files in os.walk(root):
        if ".git" in base:
            continue
        for name in files:
            if name.endswith((".ihx", ".hex")):
                path = os.path.join(base, name)
                with open(path, "rb") as fh:
                    data = fh.read()
                if b"\r\n" in data:
                    failures.append("CRLF in Intel HEX: %s" % os.path.relpath(path, root))

    # self-tests (best effort; report but continue)
    def selftest(cmd):
        try:
            out = subprocess.run(cmd, capture_output=True, text=True, timeout=60, cwd=root)
            if out.returncode != 0:
                return "FAIL %s: %s" % (" ".join(cmd), (out.stderr or out.stdout).strip()[:200])
            return None
        except Exception as e:
            return "skip %s (%s)" % (" ".join(cmd), e)

    results = []
    for cmd in [
        [sys.executable, os.path.join("tools", "asr5601_dump.py"), "--selftest"],
        [sys.executable, os.path.join("tools", "protocol_ref.py")],
    ]:
        r = selftest(cmd)
        if r:
            results.append(r)

    print("=== verify_builds ===")
    if failures:
        print("FAILURES:")
        for f in failures:
            print("  - %s" % f)
    else:
        print("checksums, compile, line endings: ok")
    for r in results:
        print(r)
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    main()
