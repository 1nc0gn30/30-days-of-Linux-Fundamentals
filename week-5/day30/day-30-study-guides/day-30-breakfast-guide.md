# Day 30 · Breakfast — Capstone Sprint II: Incident Triage, Security Audit & Certification

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 5 (Capstone Sprint)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `lynis`, `nmap`, `auditctl`, `iptables`, `tar`, `sha256sum`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // SOVEREIGN LINUX OPERATOR CAPSTONE VERIFICATION         ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║   1. PROVISION & MOUNT    ──►  lsblk • mkfs • /etc/fstab • chmod 750         ║
║   2. SERVICE ORCHESTRATION ──► systemctl enable --now • journalctl -u        ║
║   3. NETWORK & FIREWALL    ──► ss -tulpen • iptables / ufw • sshd_config     ║
║   4. AUDIT & BACKUP        ──► lynis audit • rsync -avz • sha256sum -c       ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 5 → Day 30 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/30` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-30 && cd /tmp/linux-dojo-day-30` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

### Day 30: Capstone Project and Week 4 Review

---

## **Breakfast: Week 4 Recap - Study Guide**

### Objectives:

* Summarize major concepts from Week 4
* Reinforce understanding of automation tools and performance optimization
* Reflect on system hardening and review best practices

### Topics Covered:

#### 1. **Review of Key Concepts:**

* **System Performance Monitoring:**

  * Tools: `htop`, `vmstat`, `iostat`, `top`, `iotop`
  * Metrics: CPU usage, memory load, I/O statistics
* **Shell Scripting Techniques:**

  * Variables, conditionals, loops, and functions
  * Input/output redirection, script debugging (`bash -x`, `set -e`)

#### 2. **Automation Tools Summary:**

* **Ansible:**

  * Uses YAML playbooks
  * Agentless architecture
  * Ideal for configuration management and batch server deployment
* **Puppet:**

  * Declarative manifests
  * Client-server model
  * Best for infrastructure as code in enterprise environments
* **Cron:**

  * Scheduling scripts and jobs with `crontab`
  * Common syntax: `* * * * * /path/to/script.sh`

#### 3. **Performance and Hardening Review:**

* **Systemd Optimization:**

  * Disable unused services with `systemctl disable`
* **Firewall Configuration:**

  * Using `ufw` or `iptables` to limit exposed ports
* **SSH Best Practices:**

  * Disable root login, change default port, use key-based auth

### Review Questions:

1. What tools help monitor CPU and memory in real-time?
2. Name 3 improvements you can make to harden an SSH server.
3. What's the purpose of a Puppet manifest?

---

Let me know if you'd like Lunch and Dinner split the same way next!
