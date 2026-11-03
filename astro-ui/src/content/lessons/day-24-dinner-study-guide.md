# Day 24 · Dinner — Performance Telemetry: CPU, Memory, Disk I/O & Load

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 24 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/24` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-24 && cd /tmp/linux-dojo-day-24` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍽️ Day 24 Dinner: Practical Ansible Labs

## 🎯 Objective

Reinforce your understanding of Ansible by completing hands-on lab exercises: writing playbooks, automating tasks, and debugging them effectively.

---

## 🧪 Lab Task 1: Write Your First Playbook

### ✨ Goal

Create a simple playbook that performs a basic task, such as installing a package or creating a file.

### 🛠️ Example

```yaml
- name: Create a file on localhost
  hosts: localhost
  connection: local
  tasks:
    - name: Create hello.txt file
      copy:
        dest: /tmp/hello.txt
        content: "Hello from Ansible!"
```

### ▶️ Run It:

```bash
ansible-playbook playbook.yml
```

---

## 🧪 Lab Task 2: Automate Software Installation

### ✨ Goal

Install and configure Nginx on multiple remote servers using Ansible.

### 🛠️ Example

```yaml
- name: Install and start nginx
  hosts: webservers
  become: yes
  tasks:
    - name: Ensure Nginx is installed
      apt:
        name: nginx
        state: present

    - name: Ensure Nginx is running
      service:
        name: nginx
        state: started
        enabled: true
```

### ▶️ Run It:

```bash
ansible-playbook -i hosts install-nginx.yml
```

---

## 🧪 Lab Task 3: Playbook Debugging

### ✨ Goal

Learn to identify and fix errors in a failing playbook.

### 🛠️ Tools & Tips

* Add `-v` or `-vvv` for verbose error output
* Use the `debug` module to print variables
* Common issues:

  * Indentation errors in YAML
  * Wrong module arguments
  * Incorrect hostnames or SSH keys

### 🔍 Debug Example

```yaml
- name: Debug example
  hosts: localhost
  connection: local
  tasks:
    - name: Print debug message
      debug:
        msg: "This variable is {{ some_var }}"
```

Run it:

```bash
ansible-playbook debug-test.yml -e some_var=42
```

---

## 🧠 Review Questions

1. What does the `become` directive do in Ansible?
2. How can you make a playbook idempotent?
3. What’s the purpose of `--check` and `--diff` flags?
4. How can you limit execution to one host?

---

## 📚 Additional Resources

* [Ansible Labs from Red Hat](https://www.redhat.com/en/topics/automation/ansible-labs)
* [Ansible Debug Module Docs](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/debug_module.html)
* [YAML Syntax Guide](https://yaml.org/spec/1.2/spec.html)

✅ **Next Step:** Create your own playbook to manage something on your local or remote systems. Try different modules like `file`, `lineinfile`, or `cron`!
