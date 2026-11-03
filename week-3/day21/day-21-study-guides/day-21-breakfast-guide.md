# Day 21 · Breakfast — User & Group Administration, Sudoers & PAM Security

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 21 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/21` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-21 && cd /tmp/linux-dojo-day-21` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🥣 Day 21 Breakfast: Week 3 Recap

## 🧠 Objective
Reinforce foundational security practices from Week 3 by reviewing:
- User and group permissions
- Firewall hardening
- IDS fundamentals
- Backup & recovery strategies

---

## 🔐 Section 1: Security Best Practices

### Key Concepts:
- Use `chmod`, `chown`, and `groups` to enforce least privilege
- Disable unused users:  
  `sudo passwd -l <username>`
- Grant sudo access securely:  
  `sudo usermod -aG sudo <username>`

### Practice:
```bash
sudo useradd -m secure_user
sudo passwd secure_user
sudo usermod -aG sudo secure_user
sudo chmod 700 /home/secure_user

🛡️ Section 2: Advanced Network Hardening
Key Commands:

sudo iptables -F
sudo iptables -P INPUT DROP
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
sudo iptables-save > /etc/iptables.rules

SSH Hardening Tips:

    Disable root login: PermitRootLogin no

    Use key auth only: PasswordAuthentication no

    Set idle timeout: ClientAliveInterval, ClientAliveCountMax

💾 Section 3: Backups & Disaster Recovery
Practice:

# Backup /etc
tar -czvf /backups/etc_backup.tar.gz /etc

# Automate backups
echo "0 2 * * * tar -czf /backups/home_$(date +\%F).tar.gz /home" | sudo tee /etc/cron.d/home_backup

# Verify file integrity
sha256sum -c backup_checksums.txt

✅ Quiz Topics (In breakfast-day-21)

    chmod syntax and modes

    IDS use cases (Snort, Wireshark)

    SELinux command basics

✅ Summary

By the end of this section, you should:

    Know how to create and secure users

    Understand baseline firewall configuration

    Be able to perform and verify a backup

    Recognize core IDS tools and their purpose
