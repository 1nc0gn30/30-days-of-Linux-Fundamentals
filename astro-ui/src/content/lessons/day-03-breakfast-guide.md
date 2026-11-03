# Day 03 · Breakfast — Advanced File Manipulation & Scavenger Pipelines

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `touch`, `cp -r`, `mv`, `cd -`, `find`, `grep`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // LINUX FILESYSTEM & SHELL EXECUTION ARCHITECTURE       ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║   [ USER TERMINAL / TUI ]  ──( stdin 0 )──►  [ BASH / ZSH SHELL PARSER ]     ║
║                                                       │                      ║
║                                              ( glibc / syscalls )            ║
║                                                       ▼                      ║
║   [ VFS / INODE TABLE ]    ◄───────────────  [ LINUX KERNEL RING 0 ]         ║
║     ├── /bin  (Core Binaries)                  ├── Process Scheduler         ║
║     ├── /etc  (System Configs)                 ├── Memory Manager            ║
║     ├── /home (Operator Workspaces)            └── Netfilter / I/O           ║
║     └── /var  (Logs & Runtime State)                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 03 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/3` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-03 && cd /tmp/linux-dojo-day-03` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to Day 3 Breakfast! Today, we will deepen our understanding of advanced file and directory management techniques. This guide will cover creating, copying, moving, and renaming files, as well as navigating directories with advanced options and commands.

## Creating Files with Advanced Techniques

### Commands
- **`touch`**: Create a new empty file or update the timestamp of an existing file.
```bash
  touch file1.txt
```
    echo: Create a file with initial content. The > operator will overwrite the file if it already exists.

```bash

echo 'Initial content' > file2.txt

```

cat: Create a file with multiline content using a here document.

```bash

    cat > file3.txt <<EOF

```
    This is a new file.
    EOF

Examples

    Create a new empty file:

```bash

touch myfile.txt

```

Create a file with initial content:

```bash

echo 'Hello World' > hello.txt

```

Create a file with multiline content:

```bash

    cat > multiline.txt <<EOF

```
    Line 1
    Line 2
    Line 3
    EOF

Copying Files and Directories
Commands

    cp: Copy files or directories.

```bash

cp file1.txt backup/

```

cp -r: Recursively copy directories.

```bash

cp -r source/ destination/

```

cp -a: Archive mode: Copy files and preserve attributes (like symlinks).

```bash

cp -a source/ destination/

```

cp -u: Copy only if the source file is newer than the destination file.

```bash

cp -u file1.txt backup/

```

cp -i: Prompt before overwriting files.

```bash

    cp -i file1.txt backup/

```

Examples

    Copy a file to a directory:

```bash

cp document.txt /backup/

```

Recursively copy a directory:

```bash

cp -r mydir/ mybackup/

```

Copy a directory preserving attributes:

```bash

cp -a mydir/ mybackup/

```

Copy only newer files:

```bash

    cp -u newfile.txt /backup/

```

Moving and Renaming Files
Commands

    mv: Move or rename files and directories.

```bash

mv file1.txt /path/to/destination/

```

mv -i: Prompt before overwriting files.

```bash

mv -i file1.txt backup/

```

mv -u: Move only if the source file is newer than the destination file.

```bash

    mv -u file1.txt backup/

```

Examples

    Move a file to a different directory:

```bash

mv report.txt /archives/

```

Rename a file:

```bash

    mv oldname.txt newname.txt

```

Advanced Directory Navigation
Commands

    cd: Change directories.

```bash

cd /path/to/directory

```

cd ..: Move up one directory level.

```bash

cd ..

```

cd -: Switch to the previous directory.

```bash

cd -

```

cd ~: Change to the home directory.

```bash

cd ~

```

cd /: Change to the root directory.

```bash

cd /

```

cd -P: Resolve symbolic links to physical directories.

```bash

    cd -P /path/to/symlink

```

Examples

    Navigate to a specific directory:

```bash

cd /home/user/documents

```

Move up one level:

```bash

cd ..

```

Return to the previous directory:

```bash

cd -

```

Navigate to the home directory:

```bash

    cd ~

```

### Quiz Questions

- What command can create a new file with initial content?
        echo 'Initial content' > file.txt

- How do you recursively copy a directory and its contents?
        cp -r source/ destination/

- What command is used to move a file to a different directory?
        mv file.txt /path/to/destination/

- How can you rename a file in the current directory?
        mv oldname.txt newname.txt

- How can you switch to the previous directory you were in?
        cd -

#### Summary

- In this breakfast session, we have covered advanced file and directory management techniques, including creating files with different methods, copying files and directories with various options, moving and renaming files, and navigating directories with advanced commands. Practice these commands to enhance your skills and become proficient in managing files and directories in Linux.
