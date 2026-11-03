# Day 30 · Dinner — Capstone Sprint II: Incident Triage, Security Audit & Certification

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 5 (Capstone Sprint)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 5 → Day 30 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/30` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-30 && cd /tmp/linux-dojo-day-30` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Table of Contents

1. Lab Task 1: Execute the Capstone Project
2. Lab Task 2: Troubleshooting and Testing
3. Lab Task 3: Documentation and Presentation

---

## Lab Task 1: Execute the Capstone Project

### Objective:

Put all skills learned over the past 30 days into practice by executing a complete capstone project that incorporates Linux fundamentals, automation, security, and system management.

### Key Activities:

* Set up a secure Linux server.
* Automate tasks using shell scripts or tools like Ansible or Puppet.
* Utilize Docker to containerize applications if applicable.
* Harden the system with firewall rules, SSH best practices, and user management.
* Configure backups and system monitoring.

### Tips:

* Refer to your study guides for relevant command syntax and best practices.
* Break down the project into phases: setup, configuration, hardening, testing.

---

## Lab Task 2: Troubleshooting and Testing

### Objective:

Ensure the system is robust, reliable, and secure.

### Checklist:

* Use `ping`, `curl`, and `nmap` to verify network services are running and accessible.
* Confirm firewall rules are applied correctly with `iptables` or `ufw`.
* Test user access levels and file permissions.
* Run a Lynis audit and resolve any high-risk warnings.
* Use tools like `htop`, `vmstat`, and `iostat` to monitor performance.

### Common Issues:

* Misconfigured cron jobs or playbooks.
* Incorrect user/group permissions.
* Unreachable containers or services.
* Ineffective firewall rules or open ports.

---

## Lab Task 3: Documentation and Presentation

### Objective:

Provide clear, professional documentation and prepare a brief presentation.

### Deliverables:

* A README file with:

  * Project overview
  * Tools used
  * Setup instructions
  * Security measures implemented
  * Troubleshooting notes

* Screenshots or terminal output of major tasks completed.

* Optional: Record a short video walk-through of your system.

### Presentation Tips:

* Explain your problem-solving process.
* Highlight key decisions and tools chosen.
* Be ready to answer questions on any part of your project.

---

**Congratulations!** You've reached the final challenge. Executing this capstone project demonstrates your grasp of essential Linux system administration and DevOps fundamentals.
