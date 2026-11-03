# Day 20 · Dinner — Shell Environment Customization, Aliases & Dotfiles

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `export`, `env`, `alias`, `~/.bashrc`, `~/.profile`, `source`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 20 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/20` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-20 && cd /tmp/linux-dojo-day-20` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🧪 Lab 1: Automate System Monitoring

1. Create `monitor_disk.sh`:
```bash
THRESHOLD=80
USAGE=$(df / | grep / | awk '{print $5}' | sed 's/%//g')
if [ "$USAGE" -gt "$THRESHOLD" ]; then
  echo "Disk space high: $USAGE%" | mail -s "Disk Alert" root
fi
```
2. Add to crontab for automatic checks.

---

## 💾 Lab 2: Backup Automation Script

1. Create `backup_logs.sh`:
```bash
BACKUP_DIR="/backup/$(date +%F)"
mkdir -p "$BACKUP_DIR"
cp -r /var/log "$BACKUP_DIR"
find /backup -type d -mtime +7 -exec rm -rf {} +
```
2. Automate daily with cron.

---

## 🐛 Lab 3: Script Debugging

1. Create buggy script:
```bash
#!/bin/bash
for i in 1 2 3
  echo "Number $i"
```
2. Debug:
```bash
bash -x broken_script.sh
```
3. Fix: add `do` after `for` line
4. Use `set -e` to stop on error, and `set -x` to trace

---

## ✅ Summary

- Created monitoring and backup automation
- Debugged and hardened scripts with real-world usage
