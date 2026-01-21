import os
import shutil

SOURCE_DIR = r"C:\Program Files\Epic Games\UE_5.7\Engine\Shaders\Private"
DEST_DIR = "Private"
TARGET = "// CelLit"

os.makedirs(DEST_DIR, exist_ok=True)

for root, _, files in os.walk(SOURCE_DIR):
    for name in files:
        src_path = os.path.join(root, name)
        try:
            with open(src_path, "r", encoding="utf-8", errors="ignore") as f:
                if TARGET in f.read():
                    # Preserve subfolder structure under DEST_DIR
                    rel_path = os.path.relpath(src_path, SOURCE_DIR)
                    dst_path = os.path.join(DEST_DIR, rel_path)
                    os.makedirs(os.path.dirname(dst_path), exist_ok=True)
                    shutil.copy2(src_path, dst_path)
        except OSError:
            # Skip files that can't be read
            pass
