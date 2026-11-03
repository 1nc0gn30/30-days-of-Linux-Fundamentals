# Day 23 · Lunch — Parameterized CLI Scripts, Getopts & Production Tooling

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
> **Core Commands**: `getopts`, `shift`, `bash -x`, `shellcheck`, `printf`, `jq`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 23 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/23` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-23 && cd /tmp/linux-dojo-day-23` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍲 Day 23 Lunch: Building Useful Scripts

## 🧠 Objective

Learn how to write useful Bash scripts for automation and system management, handle CLI options with `getopts`, and debug with common shell flags.

---

## 🛠️ Section 1: Automating Common Tasks

### 🔥 Example: Log Cleanup

```bash
#!/bin/bash
find /var/log -type f -name "*.log" -mtime +7 -exec rm {} \;
echo "Old logs removed."
```

### 💾 Example: Disk Monitor

```bash
#!/bin/bash
usage=$(df -h / | awk 'NR==2 {print $5}' | sed 's/%//')
if [ $usage -gt 80 ]; then
  echo "Disk space critical: $usage% used."
fi
```

---

## 🎛 Section 2: Using getopts

### 🧰 Example: Script Options

```bash
#!/bin/bash
while getopts ":u:p:" opt; do
  case $opt in
    u) user=$OPTARG ;;
    p) path=$OPTARG ;;
    *) echo "Invalid option" ; exit 1 ;;
  esac
done

echo "User: $user"
echo "Path: $path"
```

* This allows for custom flags like `-u zoth -p ~`

---

## 🪛 Section 3: Debugging Scripts

### 🔍 Debug Line-by-Line

```bash
bash -x script.sh
```

### ❌ Exit on First Error

```bash
set -e
```

* Good for scripts that need to stop if a command fails

### 🔄 Show All Commands

```bash
set -x
```

* Like `bash -x`, but works inline

---

## ✅ Summary

After lunch, you should know how to:

* Automate cleanup and monitoring with Bash
* Parse CLI flags using `getopts`
* Debug issues with `bash -x`, `set -e`, and `set -x`

Run the `day-23-lunch` program to interactively try each topic.
