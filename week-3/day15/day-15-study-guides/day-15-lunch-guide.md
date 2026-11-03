# Day 15 · Lunch — Linux Security Hardening, Firewalls & Mandatory Access Control

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 15 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/15` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-15 && cd /tmp/linux-dojo-day-15` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 15 (Lunch Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Firewall Basics (iptables/nftables)

**Overview:** Introduction to firewall management and configuring simple rules.

**Command Example:**
```bash
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
```

**Deep Dive:** Firewalls control network traffic by allowing or blocking specific connections based on predefined rules. The `iptables` command is used for packet filtering in Linux, while `nftables` is its modern successor.

To list firewall rules, use `sudo iptables -L`. To allow SSH traffic, use `sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT`. To drop all incoming traffic except for essential services, use `sudo iptables -P INPUT DROP`.

For persistent rules, install `iptables-persistent` and save the configuration using `sudo netfilter-persistent save`.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands](https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands)
- [https://wiki.archlinux.org/title/nftables](https://wiki.archlinux.org/title/nftables)
- [https://www.cyberciti.biz/faq/linux-iptables-how-to-block-an-ip-address/](https://www.cyberciti.biz/faq/linux-iptables-how-to-block-an-ip-address/)

## 2. SSH Hardening

**Overview:** Best practices for hardening SSH, including key-based authentication, restricting users, and using fail2ban.

**Command Example:**
```bash
sudo nano /etc/ssh/sshd_config
```

**Deep Dive:** To secure SSH, disable root login (`PermitRootLogin no`), enforce key-based authentication (`PasswordAuthentication no`), and allow only specific users (`AllowUsers user1 user2`).

Using `fail2ban` helps mitigate brute-force attacks. Install it using `sudo apt install fail2ban`, then configure `/etc/fail2ban/jail.local` to monitor failed login attempts and ban offending IPs.

For additional security, change the default SSH port (`Port 2222`) and use TCP Wrappers (`/etc/hosts.allow` and `/etc/hosts.deny`).

**References:**
- [https://www.ssh.com/academy/ssh/hardening](https://www.ssh.com/academy/ssh/hardening)
- [https://linuxhandbook.com/secure-ssh-server/](https://linuxhandbook.com/secure-ssh-server/)
- [https://www.fail2ban.org/wiki/index.php/Main_Page](https://www.fail2ban.org/wiki/index.php/Main_Page)

---

## Self-Check Quiz & Verification

**1. Which command is used to list iptables rules?**
- A) `iptables -L`
- B) `iptables --show`
- C) `firewall-cmd --list`
- D) `nft show ruleset`
- **Correct Answer:** `iptables -L`

**2. How do you disable root SSH login?**
- A) `PermitRootLogin no`
- B) `RootAccess off`
- C) `DisableRoot true`
- D) `SSHRootDeny yes`
- **Correct Answer:** `PermitRootLogin no`

**3. What tool helps prevent brute-force SSH attacks?**
- A) `fail2ban`
- B) `iptables`
- C) `nftables`
- D) `ufw`
- **Correct Answer:** `fail2ban`
