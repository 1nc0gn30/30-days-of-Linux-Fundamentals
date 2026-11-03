# Day 19 · Dinner — Advanced Bash Automation, Exit Codes & Trap Handlers

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 19 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/19` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-19 && cd /tmp/linux-dojo-day-19` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🧪 Lab Task 1: Monitor System Load

1. Open `htop` in one terminal.
2. In another, run:
   ```bash
   yes > /dev/null &
   ```
   multiple times to simulate CPU stress.
3. Use `vmstat 1` to monitor system reaction.

---

## 🔥 Lab Task 2: Tune Services for Performance

1. Identify active services:
   ```bash
   systemctl list-units --type=service
   ```
2. Disable and stop unnecessary ones:
   ```bash
   sudo systemctl disable bluetooth
   sudo systemctl stop bluetooth
   ```

3. Validate with `top` or `htop`.

---

## 💡 Lab Task 3: Disk I/O Analysis and Optimization

1. Monitor:
   ```bash
   iostat -xz 2
   ```
2. Simulate write load:
   ```bash
   dd if=/dev/zero of=testfile bs=1M count=1000
   ```
3. Adjust disk buffer settings:
   ```bash
   sudo sysctl vm.dirty_ratio=10
   sudo sysctl vm.dirty_background_ratio=5
   ```

This controls how much dirty data can sit in RAM before being flushed to disk.

---

## ✅ Summary

- You’ve stress-tested and analyzed system performance.
- You identified bottlenecks and tuned system behaviors using kernel and systemd controls.
- Ready to move on to deeper tuning or logging next.
