# Day 19 · Lunch — Advanced Bash Automation, Exit Codes & Trap Handlers

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 19 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/19` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-19 && cd /tmp/linux-dojo-day-19` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## ⚙️ Optimizing System Resources

- Adjust CPU priority with `nice` and `renice`:
  - `nice -n 10 command` (lower priority)
  - `renice +10 <PID>` (lower an existing process)
- Monitor memory with:
  - `free -h`
  - `vmstat`
- Kill zombie or idle processes:
  - `kill -9 <PID>`

---

## 🔧 Managing Services with systemd

- View active services:
  ```bash
  systemctl list-units --type=service
  ```
- Disable unused services:
  ```bash
  sudo systemctl disable bluetooth
  sudo systemctl stop bluetooth
  ```

Reducing unnecessary services lowers boot time, CPU usage, and memory consumption.

---

## 💾 Swapping and Cache Management

- Show swap:
  ```bash
  swapon -s
  ```
- Adjust swap tendency:
  ```bash
  sudo sysctl vm.swappiness=10
  ```
- Make it permanent:
  ```bash
  echo "vm.swappiness=10" | sudo tee -a /etc/sysctl.conf
  ```

Lower swappiness means Linux prefers RAM and delays swapping.

---

## 📚 Resources

- https://wiki.archlinux.org/title/Swap
- https://www.freedesktop.org/software/systemd/man/systemctl.html
- https://linux.die.net/man/1/nice
