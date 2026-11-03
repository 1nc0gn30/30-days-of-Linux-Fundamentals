# Day 24 · Lunch — Performance Telemetry: CPU, Memory, Disk I/O & Load

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 24 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/24` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-24 && cd /tmp/linux-dojo-day-24` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍽️ Day 24 Lunch: Writing Playbooks

**Objective**: Learn how to create and execute Ansible playbooks to automate system tasks across multiple machines.

---

### 🖋️ Creating Your First Ansible Playbook

An **Ansible playbook** is a YAML file containing a list of actions (tasks) for Ansible to perform on managed nodes.

#### 📚 Example: Installing Nginx

```yaml
- name: Install Nginx on webservers
  hosts: webservers
  become: yes
  tasks:
    - name: Ensure Nginx is installed
      apt:
        name: nginx
        state: present
```

Save this file as `install_nginx.yml` and run it using:

```bash
ansible-playbook -i hosts install_nginx.yml
```

---

### 🛠️ Managing Multiple Servers

To manage multiple servers:

1. Define groups in your inventory file:

```ini
[webservers]
192.168.1.10
192.168.1.11

[dbservers]
192.168.1.20
```

2. Target specific groups in playbooks using the `hosts` key.

This makes it easy to roll out updates or changes across a fleet of machines.

---

### 🔹 Common Modules in Ansible

Modules are the building blocks of tasks in playbooks. Here are some commonly used ones:

| Module    | Purpose                                 | Example                                         |
| --------- | --------------------------------------- | ----------------------------------------------- |
| `apt`     | Manage packages on Debian-based systems | `apt: name=nginx state=present`                 |
| `yum`     | Manage packages on RedHat-based systems | `yum: name=httpd state=present`                 |
| `copy`    | Copy files to remote hosts              | `copy: src=/file.txt dest=/tmp/file.txt`        |
| `service` | Manage services                         | `service: name=nginx state=started enabled=yes` |
| `command` | Run shell commands (no variables)       | `command: /usr/bin/uptime`                      |
| `shell`   | Run shell commands (with vars, pipes)   | `shell: echo $HOME`                             |

---

### 🤔 Practice Task

Create a playbook to:

* Update the package cache
* Install htop
* Ensure the htop service is running (if applicable)

```yaml
- name: Install and run htop
  hosts: all
  become: yes
  tasks:
    - name: Update apt cache
      apt:
        update_cache: yes

    - name: Install htop
      apt:
        name: htop
        state: present

    - name: Run htop (verify presence)
      command: which htop
```

---

### 📚 Review Questions

1. What is a playbook and how is it structured?
2. How do you target specific groups of machines in your inventory?
3. What is the difference between the `command` and `shell` modules?
4. How would you install a package across multiple hosts?

---

### 📖 Recommended Reading

* [Ansible Playbooks - Official Docs](https://docs.ansible.com/ansible/latest/user_guide/playbooks.html)
* [Module Index](https://docs.ansible.com/ansible/latest/collections/index_module.html)
* [Best Practices](https://docs.ansible.com/ansible/latest/user_guide/playbooks_best_practices.html)

---

### ✅ Done?

Create your own playbook that installs multiple packages and configures a service, like setting up a basic web stack (nginx + ufw + fail2ban).

Next up: **Dinner - Practical Ansible Labs**
