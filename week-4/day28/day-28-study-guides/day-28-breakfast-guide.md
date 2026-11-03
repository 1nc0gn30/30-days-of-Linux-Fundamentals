# Day 28 · Breakfast — Production Server Hardening & Zero-Trust Baseline Lab

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `ufw`, `iptables`, `ssh-keygen`, `sshd_config`, `fail2ban`, `auditctl`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 28 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/28` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-28 && cd /tmp/linux-dojo-day-28` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🐳 Day 28: Breakfast – Docker Networking and Storage

## 🧠 Objective

Learn how Docker manages networking and storage, and how containers communicate and persist data.

---

## 🌐 Docker Networking Basics

Docker uses **bridge networks** by default. Each container joins a virtual bridge allowing communication between containers and the host.

### 📌 Common Network Types

* `bridge`: Default for standalone containers
* `host`: Uses the host network stack
* `none`: Disables networking
* Custom: User-defined for fine control

### 🔧 Create a custom bridge network

```bash
docker network create my_network
```

Then run containers inside it:

```bash
docker run -d --name web --network my_network nginx
docker run -d --name db --network my_network postgres
```

### 🔪 Inspect network

```bash
docker network inspect my_network
```

---

## 📂 Volumes and Persistent Storage

By default, container data is lost after deletion. **Volumes** ensure your data survives restarts.

### 🔨 Create a volume

```bash
docker volume create db_data
```

### 📦 Use in a container

```bash
docker run -d -v db_data:/var/lib/postgresql/data postgres
```

Or inside Docker Compose:

```yaml
services:
  db:
    image: postgres
    volumes:
      - db_data:/var/lib/postgresql/data

volumes:
  db_data:
```

---

## 🔗 Linking Containers (Legacy)

Before custom networks, `--link` was used to link containers. It’s deprecated now. Use user-defined networks instead for DNS-based service discovery.

---

## 🧠 Review Questions

1. What’s the default Docker network for containers?
2. How do you persist database data across restarts?
3. What does `docker volume ls` do?
4. Why is `--link` deprecated?

---

## 📚 Further Reading

* [Docker Networking Overview](https://docs.docker.com/network/)
* [Docker Volumes](https://docs.docker.com/storage/volumes/)
* [Docker Compose Storage Best Practices](https://docs.docker.com/compose/compose-file/compose-file-v3/#volumes)
