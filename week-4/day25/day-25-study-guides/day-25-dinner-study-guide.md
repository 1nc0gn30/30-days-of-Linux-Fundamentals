# 🍽️ Day 25 Dinner: Cron Job Automation Labs

## 🎯 Objective

Practice writing and troubleshooting cron jobs to automate Linux system tasks efficiently.

---

## 🧪 Lab Task 1: Schedule Backups

### ✨ Goal

Set up a cron job to create a daily backup of the `/etc` directory.

### 🔧 Sample Script

```bash
#!/bin/bash
DATE=$(date +"%F")
BACKUP_FILE="/backups/etc-$DATE.tar.gz"
tar -czf "$BACKUP_FILE" /etc
```

### ⏰ Cron Entry

To schedule this at 2:00 AM daily:

```cron
0 2 * * * /usr/local/bin/backup.sh
```

> Make sure `backup.sh` is executable: `chmod +x /usr/local/bin/backup.sh`

---

## 🧪 Lab Task 2: Automate Log Cleanup

### ✨ Goal

Clear out log files older than 7 days every Sunday at 3:00 AM.

### 🔧 Cron Entry

```cron
0 3 * * 0 find /var/log -type f -name '*.log' -mtime +7 -exec rm {} \;
```

> Always test your `find` command before putting it in cron.

---

## 🧪 Lab Task 3: Troubleshoot a Failing Cron Job

### ✨ Goal

Debug a script that is not running as expected via cron.

### 🔧 Tips for Debugging

* Use full paths to all binaries (e.g., `/bin/echo` instead of `echo`)
* Redirect stdout and stderr:

  ```cron
  * * * * * /path/to/script.sh > /tmp/output.log 2>&1
  ```
* Check user-specific logs:

  ```bash
  grep CRON /var/log/syslog  # Debian/Ubuntu
  journalctl -u cron         # systemd systems
  ```

---

## 🧠 Review Questions

1. What does `0 2 * * *` mean in a cron expression?
2. How do you ensure a script runs properly when executed by cron?
3. Why is it important to use full paths in cron jobs?
4. How can you log output from a cron job for debugging?

---

## 📚 Resources

* [crontab.guru](https://crontab.guru) — Cron schedule editor and reference
* [GNU Cron Manual](https://man7.org/linux/man-pages/man5/crontab.5.html)
* [An Introduction to Cron](https://www.digitalocean.com/community/tutorials/how-to-use-cron-to-automate-tasks-on-a-vps)

---

✅ **Next Step:** Apply what you've learned by automating something on your own system, like syncing files, pruning logs, or restarting a service!
