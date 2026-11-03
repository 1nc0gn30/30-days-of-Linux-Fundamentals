# Day 28 · Dinner — Production Server Hardening & Zero-Trust Baseline Lab

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 28 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/28` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-28 && cd /tmp/linux-dojo-day-28` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍽️ Day 28 Dinner: Lab Session - Docker Compose

### 🎯 Objective

Apply your Docker Compose knowledge in practical scenarios by setting up and managing multi-container environments.

---

### 🧪 Lab Task 1: Set Up a Multi-Container Application

Use Docker Compose to run a web application with a database.

#### 📝 Sample `docker-compose.yml`

```yaml
version: '3.8'
services:
  web:
    image: nginx
    ports:
      - "8080:80"
  db:
    image: postgres
    environment:
      POSTGRES_USER: admin
      POSTGRES_PASSWORD: secret
```

Start with:

```bash
docker-compose up
```

Tear it down with:

```bash
docker-compose down
```

---

### 🧪 Lab Task 2: Manage Docker Networks

Create a custom Docker network and attach services to it.

#### 🔧 Command

```bash
docker network create my_custom_network
docker network ls
docker network inspect my_custom_network
```

Update `docker-compose.yml`:

```yaml
networks:
  default:
    external:
      name: my_custom_network
```

---

### 🧪 Lab Task 3: Persistent Data with Volumes

Create volumes to persist data between container restarts.

#### 📁 Sample Addition to Compose

```yaml
services:
  db:
    image: postgres
    volumes:
      - db_data:/var/lib/postgresql/data

volumes:
  db_data:
```

Check volumes:

```bash
docker volume ls
docker volume inspect db_data
```

---

### 🧠 Review Questions

1. What is the benefit of using Docker volumes?
2. How do you inspect a Docker network?
3. Why would you define external networks in Compose?
4. What happens when you run `docker-compose down -v`?

---

### 📚 Recommended Resources

* [Volumes in Docker](https://docs.docker.com/storage/volumes/)
* [Docker Networks Guide](https://docs.docker.com/network/)
* [Compose Networking Docs](https://docs.docker.com/compose/networking/)
* [Docker Compose CLI](https://docs.docker.com/compose/reference/overview/)

---

### ✅ Challenge

Create a Docker Compose setup with:

* An Nginx reverse proxy
* A Node.js app
* A PostgreSQL database

Use networks and volumes for full isolation and persistence.
