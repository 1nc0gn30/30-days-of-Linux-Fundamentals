# Day 04 · Lunch — File Viewing, Stream Editing & Text Editors

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 04 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/4` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-04 && cd /tmp/linux-dojo-day-04` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Lesson Overview
<p><strong>Topic:</strong> Kernel Parameters and Versioning</p>
<p><strong>Description:</strong> In this lesson, we explore how to manage kernel parameters and understand kernel versioning in Linux. You'll learn to view, set, and persist kernel parameters, as well as how to determine the current kernel version and its significance.</p>

## Practical Commands
- **View current kernel version:**
``` bash
  uname -r
```
List all kernel parameters:
``` bash
Copy code
sysctl -a
```
Set a kernel parameter:
``` bash
Copy code
sysctl -w <parameter>=<value>
```
Persist kernel parameter changes:
``` bash
Copy code
echo "<parameter>=<value>" >> /etc/sysctl.conf
``` 
### Practice Question
#### Question: Which command is used to display the current kernel version?
- A) sysctl -a
- B) uname -r
- C) sysctl -w
- D) lsmod
#### Answer: B) uname -r
<p><em>Practice these commands in a terminal to solidify your understanding.</em></p>
