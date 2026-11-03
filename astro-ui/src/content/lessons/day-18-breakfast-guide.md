# Day 18 · Breakfast — Text Processing Pipelines: Grep, Sed, Awk & Regex

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 18 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/18` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-18 && cd /tmp/linux-dojo-day-18` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🥐 Lesson 1: Understanding Backup Types

- **Full Backup**: Captures all files every time. Takes longest but easiest to restore.
- **Incremental Backup**: Only backs up files changed since the last *incremental* backup. Fastest and smallest in size.
- **Differential Backup**: Backs up all changes since the last *full* backup. Larger than incremental, but faster to restore.

## 🥐 Lesson 2: Using `tar` for Backup

```bash
tar -czvf backup.tar.gz /home/user/
```

- `-c`: Create a new archive  
- `-z`: Compress using gzip  
- `-v`: Verbose output  
- `-f`: Specify filename  

Use `tar` to compress and archive files for full backups or one-time archives.

## 🥐 Lesson 3: Using `rsync` for Incremental Backups

```bash
rsync -av --delete /home/user/ /mnt/backup/
```

- `-a`: Archive mode (preserves permissions, symbolic links, etc.)  
- `-v`: Verbose output  
- `--delete`: Ensures that deletions in source are reflected in destination  

`rsync` is ideal for incremental backups due to its efficiency and ability to sync only changed files.

## 📚 Additional Resources

- https://linuxize.com/post/how-to-create-and-extract-archives-using-the-tar-command-in-linux/
- https://rsync.samba.org/
