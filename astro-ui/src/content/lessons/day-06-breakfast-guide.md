# Day 06 · Breakfast — Disk Partitioning, Archiving & Compression

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 1 (Foundations)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `df -h`, `du -sh`, `fdisk`, `mount`, `umount`, `tar -czvf`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 1 → Day 06 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/6` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-06 && cd /tmp/linux-dojo-day-06` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Overview

In this session, we'll dive into Networking Basics. We'll explore essential networking commands and concepts.

## Lessons

### Viewing Network Configuration (`ifconfig`)

The `ifconfig` command displays or configures network interfaces.

**Examples:**
- `ifconfig` : Display all active interfaces
- `ifconfig eth0` : Show configuration of 'eth0' interface
- `ifconfig eth0 up` : Activate the 'eth0' interface
- `ifconfig eth0 down` : Deactivate the 'eth0' interface

### Pinging a Host (`ping`)

The `ping` command sends ICMP ECHO_REQUEST packets to network hosts.

**Examples:**
- `ping google.com` : Ping Google to check connectivity
- `ping -c 4 google.com` : Send 4 ping requests to Google
- `ping -i 0.5 google.com` : Set interval to 0.5 seconds between requests

### Traceroute to a Host (`traceroute`)

The `traceroute` command shows the path packets take to reach a network host.

**Examples:**
- `traceroute google.com` : Trace route to Google
- `traceroute -n google.com` : Trace route without resolving hostnames

### Displaying Network Statistics (`netstat`)

The `netstat` command displays network connections, routing tables, and interface statistics.

**Examples:**
- `netstat` : Show all active connections
- `netstat -r` : Display routing table
- `netstat -i` : Show network interfaces

### Testing Port Connectivity (`nc` or `netcat`)

The `nc` command is a versatile networking tool for reading from and writing to network connections.

**Examples:**
- `nc -zv google.com 80` : Check if port 80 is open on Google
- `nc -l 1234` : Listen on port 1234 for incoming connections
- `nc google.com 80` : Connect to port 80 on Google

## Quiz Questions

1. **Question:** What command would you use to view the configuration of all active network interfaces?
   - **Answer:** `ifconfig`

2. **Question:** Which command would you use to send 4 ICMP ECHO_REQUEST packets to google.com?
   - **Answer:** `ping -c 4 google.com`
