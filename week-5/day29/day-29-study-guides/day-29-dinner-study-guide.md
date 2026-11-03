# Day 29 · Dinner — Capstone Sprint I: Multi-Tier Linux Infrastructure Deployment

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 5 (Capstone Sprint)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `systemctl`, `nginx/caddy`, `ufw`, `rsync`, `crontab`, `journalctl`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 5 → Day 29 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/29` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-29 && cd /tmp/linux-dojo-day-29` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🍽️ Day 29 Dinner: Lab Session - Hardening Practice

### 🌟 Objective

Apply everything you've learned by actively hardening a Linux system using real-world tasks.

---

### 🔧 Lab Task 1: Secure a Linux System

#### ✅ Checklist:

* [ ] Disable unneeded services (`cups`, `bluetooth`, etc.)
* [ ] Remove unused user accounts
* [ ] Change default SSH port
* [ ] Disable root login via SSH
* [ ] Enforce strong password policies (`/etc/login.defs`)

**Command Reference:**

```bash
sudo systemctl disable cups
sudo userdel olduser
sudo nano /etc/ssh/sshd_config  # change port, disable root login
```

Restart SSH:

```bash
sudo systemctl restart ssh
```

---

### 🔎 Lab Task 2: Audit with Lynis

Run a full Lynis system audit:

```bash
sudo lynis audit system
```

Review the results:

* [ ] Review `hardening_index`
* [ ] Read suggestions at the bottom
* [ ] Address critical warnings

View report:

```bash
cat /var/log/lynis.log
```

Fix suggestions such as:

* Missing AppArmor/SELinux
* Insecure SSH settings
* Weak file permissions

---

### 🛡️ Lab Task 3: Finalize Firewall and SSH Settings

1. **Firewall:**

```bash
sudo ufw default deny incoming
sudo ufw allow 22
sudo ufw allow 80
sudo ufw enable
```

2. **SSH Rules:**

```bash
sudo nano /etc/ssh/sshd_config
# Set:
PermitRootLogin no
PasswordAuthentication no
AllowUsers youruser
```

Restart services:

```bash
sudo systemctl restart ssh
sudo ufw status
```

---

### 🧐 Review Questions

1. What does `sudo lynis audit system` do?
2. Where do you find Lynis recommendations?
3. How do you block all but specific ports with UFW?
4. What config file controls SSH settings?

---

### 📓 Additional Resources

* [Lynis Documentation](https://cisofy.com/documentation/lynis/)
* [SSH Hardening Tips](https://infosec.mozilla.org/guidelines/openssh.html)
* [Ubuntu Hardening Guide](https://wiki.ubuntu.com/Security/Features)

---

### ✅ Final Task

* Harden a VM or test box using the checklist
* Run `lynis` before and after to compare hardening index
* Export your final `lynis.log` for documentation
