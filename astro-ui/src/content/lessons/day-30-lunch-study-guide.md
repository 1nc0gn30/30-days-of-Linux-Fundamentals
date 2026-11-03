# Day 30 · Lunch — Capstone Sprint II: Incident Triage, Security Audit & Certification

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 5 (Capstone Sprint)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 5 → Day 30 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/30` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-30 && cd /tmp/linux-dojo-day-30` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## Lunch Study Guide: Capstone Project Overview

### Project Requirements

**Objective:**

* Apply all skills and tools learned throughout the 30-day course to complete a comprehensive Linux-based capstone project.
* The project should simulate a real-world environment and demonstrate competence in system setup, automation, and security.

**Requirements Checklist:**

* Deploy a virtual or physical Linux machine (preferably a VM for safe testing).
* Secure the system (disable unnecessary services, configure firewall, harden SSH).
* Automate tasks with scripts, cron, or configuration management tools.
* Use Docker or Ansible/Puppet for service deployment.
* Ensure logging and monitoring is active (systemd, journald, custom scripts, Lynis).
* Include backup and recovery solutions.

### Planning the Project

**Steps to Plan:**

1. **Define Scope:** Choose whether to simulate a web server setup, a secure DevOps pipeline, or a workstation hardening project.
2. **List Components:** Identify what needs to be installed/configured (e.g., Nginx, Docker, Ansible, cron jobs).
3. **Draft a Timeline:** Allocate time for installation, configuration, testing, and documentation.
4. **Choose Tools:** Select tools like Docker, Ansible, or bash scripting based on what best demonstrates your skills.
5. **Set Milestones:** Break the project into stages: initial setup, automation, hardening, testing, documentation.

### Team Collaboration (If Applicable)

**Best Practices:**

* Use GitHub or GitLab for version control and collaboration.
* Assign roles: e.g., security lead, automation engineer, documentation lead.
* Communicate clearly using comments and markdown README files.
* Use tools like `tmux`, `ssh`, or `VS Code Live Share` for real-time pairing (optional).

### Capstone Tips

* Focus on clarity, completeness, and functionality.
* Don't try to use every tool—use the ones that show your understanding and capability.
* Document each step: what you did, why you did it, and the outcome.
* Include screenshots or logs as evidence of system behavior.

### Review Questions

* What tools did you choose and why?
* How did you ensure system security?
* What automation tasks were included?
* How would you improve your setup if given more time?
