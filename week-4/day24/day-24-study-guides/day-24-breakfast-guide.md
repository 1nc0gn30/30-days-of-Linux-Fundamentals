# Day 24 · Breakfast — Performance Telemetry: CPU, Memory, Disk I/O & Load

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `vmstat`, `iostat`, `mpstat`, `sar`, `free -h`, `lsof`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 24 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/24` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-24 && cd /tmp/linux-dojo-day-24` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🥣 Day 24 Breakfast: Introduction to Ansible

> **Objective:** Understand what Ansible is, how it helps in system automation, and how to set it up on your Linux system.

---

## 📘 What is Ansible?

Ansible is a **powerful open-source automation tool** used for:

- 🔧 Configuration management
- 🚀 Application deployment
- 🤖 Task automation across multiple machines

Unlike other tools, **Ansible is agentless**, meaning it uses **SSH** to communicate with remote machines — no need to install anything on the client nodes.

### ✅ Key Benefits

- Easy to learn (YAML-based playbooks)
- No agents required
- Scales easily across environments
- Widely used in DevOps and sysadmin workflows

---

## 💾 Installing Ansible

### 🐧 On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install ansible -y
```

### 🐍 Using pip (Python):

```bash
pip install ansible
```

### ✅ Verify Installation

```bash
ansible --version
```

You should see something like:

```bash
ansible [core 2.15.2]
```

---

## 🧠 Core Concepts of Ansible

### 📜 Playbooks

- Written in **YAML**
- Define a set of tasks to run on one or more machines
- Each play targets a group of hosts

```yaml
- name: Install Apache
  hosts: webservers
  become: yes
  tasks:
    - name: Install Apache2
      apt:
        name: apache2
        state: present
```

### 📂 Inventory

An inventory is a list of machines managed by Ansible.

#### Example `hosts` file:

```
[webservers]
192.168.1.10
192.168.1.11

[dbservers]
192.168.1.20
```

Run a ping test:

```bash
ansible all -i hosts -m ping
```

### 🧹 Modules

Ansible modules are reusable, standalone scripts that Ansible runs.

#### Common modules:

- `ping` – test connectivity
- `apt` / `yum` – manage packages
- `copy` – copy files to nodes
- `service` – control system services
- `command` – run commands

#### Example:

```bash
ansible webservers -m apt -a "name=nginx state=present" -b
```

---

## 🧠 Review Questions

1. What makes Ansible "agentless"?
2. What language are playbooks written in?
3. What does the `-m` flag do in an Ansible command?
4. What's the difference between `command` and `shell` modules?

---

## 📚 Recommended Reading

- [Official Ansible Docs](https://docs.ansible.com/)
- [Introduction to YAML](https://yaml.org/start.html)
- [Ansible for Beginners – Red Hat Guide](https://www.redhat.com/en/topics/automation/what-is-ansible)

---

## ✅ Practice Task

Create a simple inventory file and ping your own machine:

```bash
echo "[local]
127.0.0.1 ansible_connection=local" > hosts
ansible all -i hosts -m ping
