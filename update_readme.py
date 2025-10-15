import os
import re

# ===== SETTINGS =====
ROOT_README = "README.md"
ALLOWED_EXTENSIONS = {".cpp"}
IGNORED_FOLDERS = {".git", ".github", "__pycache__", ".vscode"}
MARKER_START = "<!-- FOLDER_STRUCTURE_START -->"
MARKER_END = "<!-- FOLDER_STRUCTURE_END -->"
REPO_URL = "https://github.com/OmChannawar/Cpp-Practice/blob/main"
# ====================

def generate_tree(start_path="."):
    tree = ""
    for root, dirs, files in os.walk(start_path):
        dirs[:] = [d for d in dirs if d not in IGNORED_FOLDERS]
        level = root.replace(start_path, "").count(os.sep)
        indent = "│   " * level
        folder_name = os.path.basename(root) or "Cpp-Practice"
        tree += f"{indent}├── {folder_name}\n"

        for f in sorted(files):
            ext = os.path.splitext(f)[1]
            if ext in ALLOWED_EXTENSIONS:
                rel_path = os.path.join(root, f).replace("\\", "/")
                file_url = f"{REPO_URL}/{rel_path}"
                tree += f"{indent}│   ├── [`{f}`]({file_url})\n"

    # Add README link
    tree += "└── [`README.md`](./README.md)\n"
    return "```\n" + tree + "```\n"

def update_readme():
    if not os.path.exists(ROOT_README):
        print("❌ README.md not found.")
        return

    with open(ROOT_README, "r", encoding="utf-8") as f:
        content = f.read()

    new_tree = generate_tree(".")

    if MARKER_START in content and MARKER_END in content:
        new_content = re.sub(
            f"{MARKER_START}.*?{MARKER_END}",
            f"{MARKER_START}\n{new_tree}{MARKER_END}",
            content,
            flags=re.DOTALL,
        )
    else:
        print("⚠️ Markers not found! Please add them around the folder structure section.")
        return

    with open(ROOT_README, "w", encoding="utf-8") as f:
        f.write(new_content)

    print("✅ Folder structure updated successfully!")

if __name__ == "__main__":
    update_readme()
# This script updates the README.md file with the current folder structure.