## 🍽️ Day 29 Lunch: Security Audits and Tools

### 🌟 Objective

Learn how to audit your Linux system using industry-standard tools and practices, identify potential issues, and patch vulnerabilities effectively.

---

### 🔎 Using Lynis for System Audits

Lynis is a powerful auditing tool for Unix-based systems.

**Install Lynis:**

```bash
sudo apt update
sudo apt install lynis -y
```

**Run an audit:**

```bash
sudo lynis audit system
```

**Check the report:**

* Found at `/var/log/lynis.log`
* Suggestions and warnings help guide hardening efforts

---

### 🔍 Reviewing Logs for Suspicious Activity

Key logs to examine:

```bash
/var/log/auth.log      # Authentication logs
/var/log/syslog        # System messages
/var/log/kern.log      # Kernel events
```

**Search for anomalies:**

```bash
grep 'Failed password' /var/log/auth.log
grep 'error' /var/log/syslog
```

**Use journalctl for persistent logs:**

```bash
journalctl -xe
```

---

### 🚧 Patching and Updates

Keep your system secure with regular updates.

**Debian/Ubuntu:**

```bash
sudo apt update && sudo apt upgrade -y
```

**RHEL/CentOS:**

```bash
sudo yum update -y
```

**List upgradable packages:**

```bash
apt list --upgradable
```

**Enable automatic updates:**

```bash
sudo apt install unattended-upgrades
sudo dpkg-reconfigure --priority=low unattended-upgrades
```

---

### 🧠 Review Questions

1. What command installs Lynis?
2. Where can you find Lynis audit results?
3. Which log file shows SSH login attempts?
4. How can you automate security updates on Debian systems?

---

### 📓 Recommended Reading

* [Lynis Documentation](https://cisofy.com/documentation/lynis/)
* [Linux Log File Reference](https://help.ubuntu.com/community/LinuxLogFiles)
* [Unattended Upgrades Guide](https://wiki.debian.org/UnattendedUpgrades)

---

### ✅ Practice Task

* Install Lynis and run a system audit
* Review `/var/log/auth.log` for failed login attempts
* Enable automatic security updates

Confirm Lynis scan results:

```bash
sudo cat /var/log/lynis-report.dat | grep warning
```
