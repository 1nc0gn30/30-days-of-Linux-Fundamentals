# Day 21 · Lunch — User & Group Administration, Sudoers & PAM Security

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 21 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/21` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-21 && cd /tmp/linux-dojo-day-21` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍲 Day 21 Lunch: Hands-On Practice Labs

## 🧠 Objective
Apply the concepts from the morning session through real-world Linux sysadmin simulations:
- Secure user creation
- Firewall rule management
- IDS analysis
- Backup restoration

---

## 🔐 Lab 1: User Permissions Simulation

### Goal:
Create a minimal-privilege user with locked-down home access and sudo rights.

### Commands:
```bash
sudo useradd -m -s /bin/bash secure_user
sudo passwd secure_user
sudo usermod -aG sudo secure_user
sudo chmod 700 /home/secure_user

What You Learn:

    Principle of Least Privilege

    Sudo access with tight home permissions

🛡️ Lab 2: Firewall Rule Simulation
Goal:

Simulate configuring iptables for a locked-down but SSH-accessible server.
Commands:

sudo iptables -F
sudo iptables -P INPUT DROP
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
sudo iptables-save > /etc/iptables.rules

What You Learn:

    Stateful firewall management

    Whitelisting only essential ports

🕵️ Lab 3: IDS Monitoring (Snort & Wireshark)
Goal:

Understand how to inspect traffic and simulate detection of suspicious packets.
Simulated Commands:

sudo snort -A console -i eth0 -c /etc/snort/snort.conf
sudo wireshark &

Wireshark Filters to Try:

    tcp.port == 22

    http

    dns

What You Learn:

    Real-time network monitoring and packet inspection

    Practical use of IDS in a secure network

💾 Lab 4: Backup Restoration Practice
Goal:

Simulate restoring a backup archive and verifying its integrity.
Commands:

sudo tar -xzvf /backups/home_backup.tar.gz -C /
sha256sum -c checksums.txt
sudo systemctl restart sshd

What You Learn:

    Disaster recovery techniques

    File integrity checking

    Service restoration

By the end of lunch, you should be able to:

    Add and secure new users

    Write and apply basic firewall rules

    Analyze traffic using IDS tools

    Restore from and validate backup archives
