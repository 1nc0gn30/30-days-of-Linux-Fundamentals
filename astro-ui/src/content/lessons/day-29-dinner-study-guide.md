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
