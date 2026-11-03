# Day 25 · Breakfast — Backup Architecture, Rsync Mirrors, Cron & Disaster Recovery

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `rsync -avz`, `tar -czvf`, `sha256sum`, `crontab`, `dd`, `scp`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // PRODUCTION TELEMETRY, SYSTEMD & RECOVERY MATRIX        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐  ║
║   │ CPU & SCHED  │   │ MEMORY / VM  │   │ DISK & VFS   │   │ NET SOCKETS  │  ║
║   │ top / mpstat │   │ free / vmstat│   │ iostat / df  │   │ ss -tulpen   │  ║
║   └──────┬───────┘   └──────┬───────┘   └──────┬───────┘   └──────┬───────┘  ║
║          └──────────────────┴─────────┬────────┴──────────────────┘          ║
║                                       ▼                                      ║
║                  [ Automated Remediation: systemd + cron + rsync ]           ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 25 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/25` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-25 && cd /tmp/linux-dojo-day-25` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍞 Day 25: Cron Jobs and Task Scheduling

## 🌿 Breakfast: Introduction to Cron

### 🔢 Objective

Understand what cron is, how it works, and how to set up basic scheduled jobs for automation on a Linux system.

---

### 🔧 What is Cron?

Cron is a time-based job scheduler in Unix-like operating systems. It allows you to automate repetitive tasks like backups, system updates, or script executions.

**Key features:**

* Automates tasks without manual intervention
* Runs in the background
* Uses `crontab` to manage job schedules

---

### ✅ Setting Up Cron Jobs

#### View your crontab:

```bash
crontab -l
```

#### Edit your crontab:

```bash
crontab -e
```

#### Example cron job (runs a script every day at 2 AM):

```bash
0 2 * * * /home/user/backup.sh
```

---

### 📅 Cron Time Fields (Five-Part Format)

```
* * * * *
| | | | |
| | | | +----- Day of the week (0 - 7) [0 and 7 are Sunday]
| | | +------- Month (1 - 12)
| | +--------- Day of the month (1 - 31)
| +----------- Hour (0 - 23)
+------------- Minute (0 - 59)
```

---

### 🧰 Common Cron Use Cases

* Schedule backups
* Rotate and delete old logs
* Sync data between systems
* Send reminders or alerts via email

---

### 🤔 Review Questions

1. What does `crontab -e` do?
2. How would you schedule a job to run every Monday at midnight?
3. What's the difference between `crontab -l` and `crontab -r`?

---

### 📖 Resources

* [Crontab.guru](https://crontab.guru) – Cron expression helper
* [Linux Man Page: crontab(5)](https://man7.org/linux/man-pages/man5/crontab.5.html)
* [Linuxize - Cron Jobs](https://linuxize.com/post/scheduling-cron-jobs-with-crontab/)
