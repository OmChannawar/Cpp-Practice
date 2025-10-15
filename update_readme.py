import os
import re

# ===== SETTINGS =====
ROOT_README = "README.md"
ALLOWED_EXTENSIONS = {".cpp"}
IGNORED_FOLDERS = {".git", ".github", "__pycache__", ".vscode"}
MARKER_START = "<!-- FOLDER_STRUCTURE_START -->"
MARKER_END = "<!-- FOLDER_STRUCTURE_END -->"
# The REPO_URL is for the 'main' branch content viewer, which is correct.
REPO_URL = "https://github.com/OmChannawar/Cpp-Practice/blob/main"
# ====================

def generate_tree(start_path="."):
    tree = ""
    for root, dirs, files in os.walk(start_path):
        # Filter out ignored folders
        dirs[:] = [d for d in dirs if d not in IGNORED_FOLDERS]
        
        rel_root = os.path.relpath(root, start_path).replace("\\", "/")
        is_root = (rel_root == ".")
        
        # Calculate the depth level for indentation lines
        level = rel_root.count('/') if not is_root else 0
        indent_lines = "│   " * level

        # 1. Folder Line Construction
        if not is_root:
            folder_name = os.path.basename(root)
            # Add the folder line with the correct prefix
            tree += f"{indent_lines}├── {folder_name}\n"

        # 2. File Line Construction
        
        # Calculate the final prefix for the files inside the current folder
        file_indent_prefix = indent_lines + ("│   " if not is_root else "")
        
        file_list = sorted(f for f in files if os.path.splitext(f)[1] in ALLOWED_EXTENSIONS)
        
        # Simple structure: Prefix + Connector + Link
        for i, f in enumerate(file_list):
            full_rel_path = os.path.join(root, f).replace("\\", "/")
            
            # CRITICAL FIX: Clean up the leading "./" from the file path for a cleaner URL
            if full_rel_path.startswith("./"):
                 full_rel_path = full_rel_path[2:]
                 
            file_url = f"{REPO_URL}/{full_rel_path}"
            
            connector = "├──"

            tree += f"{file_indent_prefix}{connector} [`{f}`]({file_url})\n"
            
    # Add README link as the last entry, using └──
    tree += "└── [`README.md`](./README.md)\n"
    
    # === FINAL AND MOST ROBUST FIX ===
    # Use HTML <pre> tags to guarantee whitespace and line breaks are preserved (fixing formatting)
    # Since this is not a fenced code block, internal Markdown links will be clickable.
    return "<pre>\n" + tree + "</pre>\n"

def update_readme():
    if not os.path.exists(ROOT_README):
        print("❌ README.md not found.")
        return

    try:
        with open(ROOT_README, "r", encoding="utf-8") as f:
            content = f.read()
    except Exception as e:
        print(f"❌ Error reading {ROOT_README}: {e}")
        return

    new_tree = generate_tree(".")
    
    # The new tree now correctly includes the wrapping <pre>\n ... \n</pre>
    replacement = f"{MARKER_START}\n{new_tree}{MARKER_END}"

    if MARKER_START in content and MARKER_END in content:
        # This regex ensures we replace *everything* between the two markers, including any old backticks or <pre> tags.
        new_content = re.sub(
            f"{MARKER_START}.*?{MARKER_END}",
            replacement,
            content,
            flags=re.DOTALL,
        )
    else:
        print("⚠️ Markers not found! Please add them around the folder structure section.")
        return

    try:
        with open(ROOT_README, "w", encoding="utf-8") as f:
            f.write(new_content)
        print("✅ Folder structure updated successfully!")
    except Exception as e:
        print(f"❌ Error writing to {ROOT_README}: {e}")

if __name__ == "__main__":
    update_readme()
# This script updates the README.md file with the current folder structure.