# Day 18 · Lunch — Text Processing Pipelines: Grep, Sed, Awk & Regex

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 18 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/18` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-18 && cd /tmp/linux-dojo-day-18` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍱 Lesson 1: Automating with Cron

```bash
crontab -e
# Example:
0 2 * * * tar -czf /backup/home_backup.tar.gz /home/user
```

## 🍱 Lesson 2: Snapshots with Btrfs

```bash
sudo btrfs subvolume snapshot /data /snapshots/data_$(date +%F)
```

## 🍱 Lesson 3: Remote Backups via SSH + rsync

```bash
rsync -avz /home/user/ user@remote:/backup/user/
```

## 📚 Resources

- https://crontab.guru/
- https://wiki.archlinux.org/title/Rsync
- https://btrfs.readthedocs.io/en/latest/btrfs-snapshot.html
