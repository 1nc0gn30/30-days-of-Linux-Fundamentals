# Day 19 · Breakfast — Advanced Bash Automation, Exit Codes & Trap Handlers

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `set -euo pipefail`, `trap`, `$?`, `$@`, `getopts`, `cron`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // DEFENSE-IN-DEPTH & STREAM PIPELINE ARCHITECTURE        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║  [ INBOUND PACKET ] ──► [ Netfilter: iptables / nftables ]                   ║
║                                │ (ACCEPT)                                    ║
║                                ▼                                             ║
║                         [ Hardened SSHD + Fail2Ban ]                         ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ DAC: chmod/chown ] ──► [ MAC: SELinux / AppArmor ] ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ Auditd & Log Pipelines: grep | awk | sed ]         ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 19 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/19` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-19 && cd /tmp/linux-dojo-day-19` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🧠 CPU, Memory, and I/O Metrics with vmstat, top, and iotop

- **vmstat 1**: Reports memory, swap, I/O, system processes, and CPU every second.
- **top**: Real-time process view, sorted by CPU usage by default.
- **iotop**: Displays disk I/O usage per process.

Use these tools to:
- Spot CPU hogs.
- Identify memory starvation.
- Detect I/O-heavy processes stalling your disk throughput.

---

## 🔍 Using htop for Monitoring

- Run: `htop`
- Colorful, interactive version of `top`.
- Features:
  - Mouse support.
  - Easy sorting.
  - Kill processes visually.
  - Toggle display columns (F2).

---

## 📀 Analyzing Disk I/O with iostat

- Install via: `sudo apt install sysstat`
- Run: `iostat -xz 1`
- Parameters:
  - `-x`: extended stats.
  - `-z`: suppress zero-only devices.
  - `1`: refresh every second.

Monitors:
- Disk utilization
- Read/write throughput
- Average request size and queue times

---

## 📚 Resources

- https://man7.org/linux/man-pages/man1/top.1.html
- https://linux.die.net/man/1/iotop
- https://htop.dev/
