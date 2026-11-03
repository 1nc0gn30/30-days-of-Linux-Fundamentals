# Day 16 · Breakfast — Security Auditing, Auditd, Logwatch & Vulnerability Scanning

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `auditd`, `auditctl`, `ausearch`, `logwatch`, `lynis`, `nmap -A`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 16 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/16` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-16 && cd /tmp/linux-dojo-day-16` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 16 (Breakfast Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Auditd and Linux Audit Framework

**Overview:** Understanding the basics of Linux auditing and tracking events.

**Command Example:**
```bash
sudo systemctl start auditd
```

**Deep Dive:** This lesson introduces auditd—the Linux auditing daemon—and explains how it monitors system events and user activities.

**References:**
- [https://linux.die.net/man/8/auditd](https://linux.die.net/man/8/auditd)
- [https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/security_guide/sec-auditing](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/security_guide/sec-auditing)

## 2. System Logs and Log Management

**Overview:** Overview of system log files and effective log management.

**Command Example:**
```bash
cat /var/log/syslog
```

**Deep Dive:** Learn how to view and interpret system logs to monitor system health and diagnose issues.

**References:**
- [https://www.digitalocean.com/community/tutorials/how-to-read-log-files](https://www.digitalocean.com/community/tutorials/how-to-read-log-files)

## 3. Analyzing Logs with logwatch

**Overview:** Using logwatch to parse logs and identify unusual activity.

**Command Example:**
```bash
logwatch --detail high
```

**Deep Dive:** Logwatch compiles comprehensive reports from your logs, helping you spot anomalies and security events.

**References:**
- [https://sourceforge.net/projects/logwatch/](https://sourceforge.net/projects/logwatch/)

## 4. Understanding Audit Rules

**Overview:** Configure audit rules to monitor specific system events.

**Command Example:**
```bash
auditctl -a always,exit -F arch=b64 -S open
```

**Deep Dive:** Setting audit rules allows you to track file accesses and system calls, reinforcing your security posture.

**References:**
- [https://www.tecmint.com/auditctl-command-examples/](https://www.tecmint.com/auditctl-command-examples/)

## 5. Configuring Auditd for File Integrity

**Overview:** Monitor critical file changes with auditd.

**Command Example:**
```bash
auditctl -w /etc/passwd -p wa
```

**Deep Dive:** File integrity monitoring helps detect unauthorized modifications, protecting key system files.

**References:**
- [https://www.cyberciti.biz/faq/linux-auditd-monitoring-file-changes/](https://www.cyberciti.biz/faq/linux-auditd-monitoring-file-changes/)

## 6. Monitoring User Activity with Auditd

**Overview:** Track logins and commands executed by users.

**Command Example:**
```bash
ausearch -ua username
```

**Deep Dive:** This lesson shows how to use auditd to review user activities, which can help uncover insider threats.

**References:**
- [https://www.thegeekdiary.com/using-auditd-to-track-user-activity-in-linux/](https://www.thegeekdiary.com/using-auditd-to-track-user-activity-in-linux/)

## 7. Centralized Logging Solutions

**Overview:** Aggregate logs from multiple systems using syslog-ng or rsyslog.

**Command Example:**
```bash
sudo service rsyslog restart
```

**Deep Dive:** Centralized logging simplifies the management and analysis of logs across many systems.

**References:**
- [https://www.rsyslog.com/](https://www.rsyslog.com/)

## 8. Parsing Logs with grep and awk

**Overview:** Filter log files to find specific patterns or errors.

**Command Example:**
```bash
grep 'error' /var/log/syslog
```

**Deep Dive:** Using grep and awk helps quickly pinpoint issues or suspicious patterns in large log files.

**References:**
- [https://www.gnu.org/software/grep/](https://www.gnu.org/software/grep/)

## 9. Securing Log Files

**Overview:** Ensure log files have proper permissions to prevent tampering.

**Command Example:**
```bash
chmod 600 /var/log/auth.log
```

**Deep Dive:** Restricting access to log files protects audit data from unauthorized changes or deletion.

**References:**
- [https://www.cyberciti.biz/faq/linux-secure-log-files/](https://www.cyberciti.biz/faq/linux-secure-log-files/)

## 10. Advanced Log Management Techniques

**Overview:** Automate log rotation and archival to keep logs organized.

**Command Example:**
```bash
sudo logrotate /etc/logrotate.conf
```

**Deep Dive:** Advanced log management techniques help manage disk space and ensure historical logs are preserved.

**References:**
- [https://www.logrotate.org/](https://www.logrotate.org/)

---

## Self-Check Quiz & Verification

**1. Which command starts the audit daemon?**
- A) `sudo systemctl start auditd`
- B) `sudo service auditd stop`
- C) `auditctl -s`
- D) `systemctl status auditd`
- **Correct Answer:** `sudo systemctl start auditd`

**2. What file is typically used to view system logs?**
- A) `/var/log/syslog`
- B) `/etc/auditd.conf`
- C) `/var/audit/log`
- D) `/usr/logs/system`
- **Correct Answer:** `/var/log/syslog`

**3. Which tool generates comprehensive log reports?**
- A) `logwatch`
- B) `grep`
- C) `awk`
- D) `sed`
- **Correct Answer:** `logwatch`

**4. What command adds a watch on /etc/passwd for changes?**
- A) `auditctl -w /etc/passwd -p wa`
- B) `ausearch -w /etc/passwd`
- C) `auditd /etc/passwd`
- D) `chmod 600 /etc/passwd`
- **Correct Answer:** `auditctl -w /etc/passwd -p wa`

**5. Which command searches audit logs for a specific user?**
- A) `ausearch -ua username`
- B) `auditctl -ua username`
- C) `grep username /var/log/audit.log`
- D) `cat /etc/audit/users`
- **Correct Answer:** `ausearch -ua username`

**6. What service is restarted to apply centralized logging changes?**
- A) `rsyslog`
- B) `auditd`
- C) `logwatch`
- D) `syslog-ng`
- **Correct Answer:** `rsyslog`

**7. Which command filters logs for the keyword 'error'?**
- A) `grep 'error' /var/log/syslog`
- B) `awk '/error/' /var/log/syslog`
- C) `logwatch --error`
- D) `sed -n '/error/p' /var/log/syslog`
- **Correct Answer:** `grep 'error' /var/log/syslog`

**8. What permission is recommended for securing log files?**
- A) `600`
- B) `644`
- C) `777`
- D) `400`
- **Correct Answer:** `600`

**9. Which utility automates log rotation?**
- A) `logrotate`
- B) `cron`
- C) `rsyslog`
- D) `systemd`
- **Correct Answer:** `logrotate`

**10. What is the primary purpose of auditctl?**
- A) `To configure audit rules`
- B) `To analyze logs`
- C) `To rotate logs`
- D) `To monitor user sessions`
- **Correct Answer:** `To configure audit rules`
