# Day 21 · Dinner — User & Group Administration, Sudoers & PAM Security

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `useradd`, `usermod`, `userdel`, `groupadd`, `passwd`, `chage`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // DEFENSE-IN-DEPTH & STREAM PIPELINE ARCHITECTURE        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║  [ INBOUND PACKET ] ──► [ Netfilter: iptables / nftables ]                   ║
║                                │ (ACCEPT)                                    ║
║                                ▼                                             ║
║                         [ Hardened SSHD + Fail2Ban ]                         ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ DAC: chmod/chown ] ──► [ MAC: SELinux / AppArmor ] ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ Auditd & Log Pipelines: grep | awk | sed ]         ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 21 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/21` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-21 && cd /tmp/linux-dojo-day-21` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍽 Day 21 Dinner: Full-System Hardening Simulation

## 🧠 Objective
Perform a complete system hardening simulation using everything covered in Week 3. This is your capstone challenge for user setup, firewalling, backups, and auditing.

---

## 🧑‍💻 Step 1: Secure Admin User Creation

### Tasks:
- Prompt for new username
- Create user with login shell and home directory
- Add user to sudo group
- Lock down their home with `chmod 700`

### What You Learn:
- Secure onboarding for new admins
- Enforcing privacy and privilege access

---

## 🔐 Step 2: File Permission Hardening

### Tasks:
- Apply `chmod 700` recursively to all `/home/*` directories
- Ensure no public access to user homes

### What You Learn:
- Access control enforcement
- Real use of restrictive permission modes

---

## 🛡️ Step 3: Firewall Rule Configuration

### Tasks:
- Flush all existing iptables rules
- Set default INPUT policy to DROP
- Allow only SSH on port 22
- Simulate saving persistent rules

### What You Learn:
- Building a minimal-attack-surface firewall from scratch

---

## 💾 Step 4: Backup and Automation

### Tasks:
- Simulate creating a `.tar.gz` backup of `/etc`
- Add cron job to back up `/home` daily
- Emphasize redundancy and disaster readiness

### What You Learn:
- Hands-off backup automation
- Security through planned recovery

---

## 🔍 Step 5: Simulated Vulnerability Scan

### Tasks:
- Generate a system report with all hardening steps
- Output saved to `/tmp/system_hardening_report.log`
- Confirm each security layer via report feedback

### What You Learn:
- Documenting security status
- Performing baseline assessments

---

## 📋 Final Summary Output

### Includes:
- Confirmation of user, permission, firewall, and backup setup
- Reinforces awareness of completed safeguards

---

## ✅ Review After Running `day-21-dinner`:

- Was the user created securely?
- Are only required ports open?
- Is every home directory locked down?
- Can you restore from backup if needed?
- Does the log report reflect all tasks correctly?

---

## 💡 Pro Tip
Use this script to train others, test VM images, or as a checklist for production hardening.
