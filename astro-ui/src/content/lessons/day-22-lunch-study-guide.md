# Day 22 · Lunch — Systemd Services, Unit Files, Targets & Boot Architecture

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 22 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/22` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-22 && cd /tmp/linux-dojo-day-22` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍲 Day 22 Lunch: Performance Optimization

## 🧠 Objective

Learn techniques to reduce system resource usage by identifying heavy processes, managing background services, and understanding swap/cache behavior.

---

## 🔧 Optimize CPU Usage

* Use `ps` to sort processes by CPU usage:

```bash
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head
```

* Consider using `nice`, `renice`, or `kill` for high-CPU processes.
* Long-term issues might need profiling or workload redistribution.

---

## 🧠 Optimize Memory Usage

* Use `free -h` to check RAM/swap usage.
* High usage doesn’t always mean bad — focus on low available + high swap.
* Consider restarting memory-leaky apps or checking logs.

```bash
free -h
```

---

## ⚙️ Manage Background Services (systemd)

* View running services:

```bash
systemctl list-units --type=service --state=running
```

* Disable unused services to free memory/CPU:

```bash
sudo systemctl disable bluetooth.service
```

* Use `systemctl mask` to prevent startup at all costs.

---

## 💾 Swap & Cache Management

* View swap and cache usage:

```bash
grep -Ei 'swap|cached' /proc/meminfo
```

* Check current swappiness value:

```bash
sysctl vm.swappiness
```

* To lower swap aggressiveness:

```bash
sudo sysctl -w vm.swappiness=10
```

---

## 🧪 Run This Lesson in `day-22-lunch`

Interactively explore:

* CPU optimization
* Memory inspection
* Background service tuning
* Swap/cache understanding

---

## ✅ Summary

After this session, you should be able to:

* Spot and reduce high CPU/memory usage
* Disable or mask background bloat
* Tune swap behavior to match system needs
