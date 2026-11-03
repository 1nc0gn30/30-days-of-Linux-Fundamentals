# Day 07 · Dinner — Week 1 Capstone: Shell & Filesystem Mastery Lab

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 07 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/7` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-07 && cd /tmp/linux-dojo-day-07` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Package Management

### Advanced Package Management with `apt-get`

Beyond basic installation and removal, `apt-get` offers advanced options for package management, including cleaning up unnecessary packages and fixing broken dependencies.

#### Examples:
```sh
sudo apt-get autoremove               # Remove unnecessary packages
sudo apt-get clean                    # Clear out the local repository of retrieved package files
sudo apt-get -f install               # Fix broken dependencies

Using apt-cache for Package Information

The apt-cache command allows you to search for packages, display package information, and show package dependencies.
Examples:

sh

apt-cache search package_name         # Search for a package
apt-cache show package_name           # Display package information
apt-cache depends package_name        # Show package dependencies

Advanced dpkg Commands

The dpkg command has additional options for querying and managing packages, such as listing files installed by a package and checking package status.
Examples:

sh

dpkg -L package_name                  # List files installed by a package
dpkg -s package_name                  # Display package status
dpkg-reconfigure package_name         # Reconfigure an installed package

Archiving and Compression
Creating and Managing Archives with tar

In addition to basic archiving and extraction, tar supports advanced options for handling file attributes and excluding files from archives.
Examples:

sh

tar -cvpzf archive.tar.gz /path/to/dir  # Create a tarball while preserving file permissions
tar -cvzf archive.tar.gz --exclude='*.log' /path/to/dir  # Exclude log files from the archive
tar -tvf archive.tar.gz                 # List contents of a tarball

Using rsync for Efficient File Transfer

The rsync command is powerful for synchronizing files and directories between locations, preserving file attributes, and minimizing data transfer.
Examples:

sh

rsync -avz /source/dir /destination/dir  # Synchronize directories with verbose output and compression
rsync -avz --delete /source/dir /destination/dir  # Delete files in destination that are not in source
rsync -avz -e ssh /source/dir user@remote:/destination/dir  # Use SSH for remote synchronization

Quiz Questions

    What command removes unnecessary packages and dependencies?
        Answer: sudo apt-get autoremove

    How do you display the dependencies of a package using apt-cache?
        Answer: apt-cache depends package_name

    Which command lists files installed by a package using dpkg?
        Answer: dpkg -L package_name

    How do you create a tarball while preserving file permissions?
        Answer: tar -cvpzf archive.tar.gz /path/to/dir

    What command synchronizes directories using rsync with compression?
        Answer: rsync -avz /source/dir /destination/dir

Study these commands and examples to reinforce your understanding of advanced package management and archiving/compression techniques. Practice using them in your terminal to gain hands-on experience.
