# Day 07 · Breakfast — Week 1 Capstone: Shell & Filesystem Mastery Lab

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `find`, `xargs`, `tar`, `chmod`, `chown`, `grep`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 07 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/7` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-07 && cd /tmp/linux-dojo-day-07` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Package Management

### Installing Packages

Package managers help you install, update, and remove software packages.

#### Examples:
- **Debian-based systems:**
  ```sh
  sudo apt-get install package_name

    RHEL-based systems:

    sh

sudo yum install package_name

Using DNF:

sh

sudo dnf install package_name

Arch-based systems:

sh

    sudo pacman -S package_name

Removing Packages

You can remove installed software packages using package managers.
Examples:

    Debian-based systems:

    sh

sudo apt-get remove package_name

RHEL-based systems:

sh

sudo yum remove package_name

Using DNF:

sh

sudo dnf remove package_name

Arch-based systems:

sh

    sudo pacman -R package_name

Updating Packages

Keep your software up to date using package managers.
Examples:

    Debian-based systems:

    sh

sudo apt-get update        # Update package list
sudo apt-get upgrade       # Upgrade all packages

RHEL-based systems:

sh

sudo yum update            # Update all packages

Using DNF:

sh

sudo dnf update            # Update all packages

Arch-based systems:

sh

    sudo pacman -Syu           # Synchronize and update all packages

Archiving and Compression
Creating Archives

The tar command is used to create and manage archive files.
Examples:

    Create a tar archive:

    sh

tar -cvf archive.tar file1 file2

Create a gzip-compressed tar archive:

sh

tar -czvf archive.tar.gz file1 file2

Create a bzip2-compressed tar archive:

sh

    tar -cjvf archive.tar.bz2 file1 file2

Extracting Archives

You can extract files from an archive using the tar command.
Examples:

    Extract a tar archive:

    sh

tar -xvf archive.tar

Extract a gzip-compressed tar archive:

sh

tar -xzvf archive.tar.gz

Extract a bzip2-compressed tar archive:

sh

    tar -xjvf archive.tar.bz2

Compressing Files

Various tools are available for file compression.
Examples:

    Compress a file using gzip:

    sh

gzip file

Compress a file using bzip2:

sh

bzip2 file

Compress a file using xz:

sh

xz file

Decompress a gzip file:

sh

gzip -d file.gz

Decompress a bzip2 file:

sh

bzip2 -d file.bz2

Decompress an xz file:

sh

    xz -d file.xz

Quiz Questions

    What command would you use to install a package on a Debian-based system?
        Answer: sudo apt-get install package_name

    Which command will create a gzip-compressed tar archive?
        Answer: tar -czvf archive.tar.gz file1 file2

    How do you remove a package on an RHEL-based system?
        Answer: sudo yum remove package_name

    What is the command to update the package list on a Debian-based system?
        Answer: sudo apt-get update

    How do you extract a bzip2-compressed tar archive?
        Answer: tar -xjvf archive.tar.bz2

Study these commands and examples to understand the basics of package management and archiving/compression. Practice using them in your terminal to gain hands-on experience.
