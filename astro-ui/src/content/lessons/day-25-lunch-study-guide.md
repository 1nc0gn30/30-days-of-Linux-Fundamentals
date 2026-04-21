# 🕐 Day 25 Lunch: Advanced Cron Usage

## 🎯 Objective

Dive deeper into how cron works behind the scenes. Learn about timing syntax, using environment variables, and debugging cron jobs with logs.

---

## ⏰ Cron Timing Syntax

Cron uses a specific 5-field format to schedule jobs:

```
* * * * * command_to_run
| | | | |
| | | | +----- Day of the week (0 - 7) (Sunday = 0 or 7)
| | | +------- Month (1 - 12)
| | +--------- Day of month (1 - 31)
| +----------- Hour (0 - 23)
+------------- Minute (0 - 59)
```

### 🔍 Examples

* `0 0 * * *` – every day at midnight
* `*/15 * * * *` – every 15 minutes
* `0 9 * * 1-5` – every weekday at 9 AM

> Test expressions using [crontab.guru](https://crontab.guru/)

---

## 🌍 Environment Variables in Cron

Cron runs in a limited environment, so it's best to define any variables or paths needed:

### 📄 Example

```bash
PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
MAILTO="your@email.com"
SHELL=/bin/bash

0 2 * * * /home/neal/scripts/backup.sh
```

---

## 🧾 Cron Logs and Troubleshooting

### 🔧 View Logs

* Debian/Ubuntu: `/var/log/syslog`

```bash
grep CRON /var/log/syslog
```

* RedHat/CentOS: `/var/log/cron`

### ⚠️ Common Pitfalls

* Commands fail silently → redirect output:

```bash
0 1 * * * /path/to/script.sh > /tmp/cron.log 2>&1
```

* Script lacks execute permissions:

```bash
chmod +x /path/to/script.sh
```

* Missing full paths to commands inside script:

```bash
#!/bin/bash
/usr/bin/tar -czf backup.tar.gz /etc
```

---

## 🧠 Review Questions

1. What does `*/10` mean in the minute field of a cron expression?
2. Where can you check cron job execution logs on Ubuntu?
3. What variable should you set if you want cron job output sent via email?
4. Why should full paths to binaries be used in cron scripts?

---

## 📚 Additional Resources

* [Crontab Guru](https://crontab.guru/)
* [Linux CronHowto](https://help.ubuntu.com/community/CronHowto)
* `man 5 crontab` – Manual for crontab syntax

✅ **Next Step:** Try modifying your existing cron jobs to include logging, or test a custom schedule with a non-critical script.
