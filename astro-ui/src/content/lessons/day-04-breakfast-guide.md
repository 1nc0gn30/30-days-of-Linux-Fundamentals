# Day 04 · Breakfast — File Viewing, Stream Editing & Text Editors

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `cat`, `less`, `more`, `head`, `tail`, `nano`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 04 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/4` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-04 && cd /tmp/linux-dojo-day-04` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Lesson Overview
<p><strong>Topic:</strong> Kernel Modules Management</p>
<p><strong>Description:</strong> In this lesson, we focus on managing kernel modules in Linux. Kernel modules are pieces of code that can be loaded and unloaded into the kernel upon demand, providing flexibility and efficiency. You'll learn how to load, unload, and query these modules, as well as modify kernel parameters.</p>

## Practical Commands
- **Load a module:** 
```bash
  modprobe <module_name>
```
Unload a module:
``` bash
rmmod <module_name>
```
View loaded modules:
``` bash
lsmod
```
Modify kernel parameters:
``` bash
sysctl -w <parameter>=<value>
```
### Practice Question
#### Question: What command is used to load a kernel module?
- A) insmod
- B) modprobe
- C) lsmod
- D) rmmod
#### Answer: B) modprobe
<p><em>Make sure to practice these commands in a terminal to reinforce your understanding.</em></p>
