# Day 27 · Lunch — Troubleshooting Methodology: Boot Recovery, Locks & Forensics

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
> **Core Commands**: `journalctl -xb`, `dmesg`, `fsck`, `lsof`, `fuser`, `strace`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 27 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/27` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-27 && cd /tmp/linux-dojo-day-27` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🥗 Day 27 - Lunch: Working with Docker Images and Containers

### 🎯 Objective

Learn Docker image basics, run containers, and manage their lifecycle.

### 📦 Docker Images

* Images are the blueprints of containers.
* Use `docker pull` to download images from Docker Hub.

#### Example:

```bash
docker pull nginx
```

### 🚀 Running Containers

* Containers are instances of images.

```bash
docker run -d -p 8080:80 nginx
```

* `-d` runs it in background, `-p` maps ports.

### 🔧 Managing Containers

* List containers:

```bash
docker ps -a
```

* Stop a container:

```bash
docker stop <container_id>
```

* Remove a container:

```bash
docker rm <container_id>
```

### ✅ Review Questions

1. How do you list all Docker containers?
2. What’s the difference between an image and a container?
3. Which flag runs a container in detached mode?

---
