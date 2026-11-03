# Day 27 · Dinner — Troubleshooting Methodology: Boot Recovery, Locks & Forensics

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 27 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/27` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-27 && cd /tmp/linux-dojo-day-27` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍽️ Day 27 - Dinner: Practical Docker Labs

### 🎯 Objective

Apply your Docker knowledge by running and managing containers and images.

### 🔨 Lab Task 1: Run Your First Container

```bash
docker run hello-world
```

This checks if Docker is installed properly.

### 🏗️ Lab Task 2: Build a Custom Image

1. Create a file named `Dockerfile`:

```Dockerfile
FROM alpine
CMD ["echo", "Hello from custom Docker image!"]
```

2. Build the image:

```bash
docker build -t myimage .
```

### 🧹 Lab Task 3: Manage Containers

* View containers:

```bash
docker ps -a
```

* Clean up:

```bash
docker stop $(docker ps -aq)
docker rm $(docker ps -aq)
docker image prune -a
```

### ✅ Review Questions

1. What does `docker build` do?
2. Why is it helpful to prune images?
3. What’s the purpose of the Dockerfile?

---

You're now equipped to build and manage Docker containers effectively!
