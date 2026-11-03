# Day 22 · Dinner — Systemd Services, Unit Files, Targets & Boot Architecture

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `systemctl`, `journalctl -u`, `systemd-analyze`, `hostnamectl`, `timedatectl`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 22 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/22` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-22 && cd /tmp/linux-dojo-day-22` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍽 Day 22 Dinner: Practical Performance Tuning

## 🧠 Objective

Consolidate your understanding of performance monitoring by practicing real-world system tuning techniques using live tools and configuration adjustments.

---

## 📈 Task 1: Monitor System Load

### Tools:

* `vmstat 1 5` – view CPU scheduling, memory, swap, I/O, and context switches
* `htop` – interactive live process viewer

### What to Watch:

* High `wa` (I/O wait) time in `vmstat`
* CPU and MEM bars in `htop`
* Load average vs number of cores

---

## ⚙️ Task 2: Tune systemd Services

### Steps:

* List enabled services:

```bash
systemctl list-unit-files --type=service | grep enabled
```

* Disable unnecessary ones:

```bash
sudo systemctl disable NAME.service
```

* For critical tweaks, use `systemctl mask`

### Why:

* Reduces memory and boot time
* Improves idle efficiency on desktops and servers

---

## 💾 Task 3: Analyze & Optimize Disk I/O

### Tools:

* `iostat -xz 1 3` (requires `sysstat` package)

### What to Look For:

* `%util` nearing 100% = device is saturated
* High `await` and `svctm` = slow response times

### Actions:

* Migrate logs/temp dirs to faster storage
* Consider using `noop` or `deadline` I/O scheduler
* Balance load across disks with RAID or LVM striping

---

## 🧪 Run This Lab in `day-22-dinner`

* Interactive simulation of load monitoring, service tuning, and disk I/O analysis.
* Reinforces habits for keeping systems healthy under stress.

---

## ✅ Summary

After this lab, you should be able to:

* Read real-time performance indicators
* Disable or optimize services
* Analyze I/O patterns and take corrective action
