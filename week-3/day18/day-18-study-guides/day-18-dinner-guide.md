# Day 18 · Dinner — Text Processing Pipelines: Grep, Sed, Awk & Regex

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `grep -E`, `sed -i`, `awk`, `cut`, `sort`, `uniq -c`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 18 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/18` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-18 && cd /tmp/linux-dojo-day-18` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍽️ Lab 1: Create Local Backups

```bash
tar -czvf etc_backup.tar.gz /etc
rsync -av /home/user/ /mnt/backup/
```

## 🍽️ Lab 2: Automate with Cron

```bash
nano ~/scripts/daily_backup.sh
crontab -e
# Add:
0 1 * * * /home/user/scripts/daily_backup.sh
chmod +x ~/scripts/daily_backup.sh
```

## 🍽️ Lab 3: Test Restoration

```bash
mkdir /tmp/etc_restore
tar -xzvf etc_backup.tar.gz -C /tmp/etc_restore
diff -r /etc /tmp/etc_restore
```

## ✅ Summary

- Created, automated, and restored backups locally and remotely.
