# Day 15 · Breakfast — Linux Security Hardening, Firewalls & Mandatory Access Control

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `chmod 750`, `chown`, `iptables`, `nftables`, `sshd_config`, `fail2ban`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 15 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/15` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-15 && cd /tmp/linux-dojo-day-15` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 15 (Breakfast Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Linux Security Basics

**Overview:** Understanding the fundamental security mechanisms of Linux.

**Command Example:**
```bash
man security
```

**Deep Dive:** Linux security is enforced through user roles, permissions, and mandatory access controls. It ensures integrity, confidentiality, and availability of system resources. Tools like `auditd` allow monitoring of security events, and SELinux or AppArmor add additional layers of access control.

**References:**
- [https://linuxsecurity.com](https://linuxsecurity.com)
- [https://www.cyberciti.biz](https://www.cyberciti.biz)
- [https://www.linuxfoundation.org](https://www.linuxfoundation.org)
- [https://access.redhat.com](https://access.redhat.com)
- [https://www.nsa.gov/cybersecurity/](https://www.nsa.gov/cybersecurity/)

## 2. File Permissions & Ownership

**Overview:** Managing file permissions effectively to limit unauthorized access.

**Command Example:**
```bash
chmod 750 filename
```

**Deep Dive:** Linux files are protected using permission bits (rwx for owner, group, and others). The `chmod` command is used to modify access rights, `chown` changes ownership, and `umask` sets default permissions.

**References:**
- [https://linuxize.com/post/linux-file-permissions](https://linuxize.com/post/linux-file-permissions)
- [https://www.cyberciti.biz/tips/understanding-linux-file-permissions.html](https://www.cyberciti.biz/tips/understanding-linux-file-permissions.html)

## 3. Firewall Basics (iptables/nftables)

**Overview:** Setting up firewalls to manage inbound and outbound traffic.

**Command Example:**
```bash
sudo iptables -L
```

**Deep Dive:** Firewalls restrict access by filtering packets based on rules. `iptables` provides manual rule configuration, while `nftables` is a modern alternative with better performance and flexibility.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands](https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands)
- [https://wiki.archlinux.org/title/iptables](https://wiki.archlinux.org/title/iptables)

## 4. SSH Hardening

**Overview:** Techniques to improve SSH security and prevent unauthorized access.

**Command Example:**
```bash
sudo nano /etc/ssh/sshd_config
```

**Deep Dive:** To secure SSH, disable password-based login in favor of key authentication, restrict root login, change the default port, and use `fail2ban` to block repeated failed login attempts.

**References:**
- [https://www.ssh.com/academy/ssh/hardening](https://www.ssh.com/academy/ssh/hardening)
- [https://linuxhandbook.com/secure-ssh-server/](https://linuxhandbook.com/secure-ssh-server/)

---

## Self-Check Quiz & Verification

**1. Which command modifies file permissions?**
- A) `chmod`
- B) `chown`
- C) `ls`
- D) `rm`
- **Correct Answer:** `chmod`

**2. How do you change file ownership?**
- A) `chown`
- B) `chmod`
- C) `passwd`
- D) `touch`
- **Correct Answer:** `chown`

**3. What is the purpose of a firewall?**
- A) `Block unauthorized access`
- B) `Monitor disk usage`
- C) `Change file permissions`
- D) `Optimize memory usage`
- **Correct Answer:** `Block unauthorized access`
