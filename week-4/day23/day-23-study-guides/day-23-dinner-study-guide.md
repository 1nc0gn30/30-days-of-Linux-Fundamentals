# 🍽 Day 23 Dinner: Lab Session – Scripting Challenges

## 🧠 Objective

Apply advanced scripting skills to solve real-world problems: monitor disk space, automate backups, and debug broken scripts.

---

## 🖥️ Task 1: Disk Space Monitor + Email Alert

### 🛠️ Script Goal:

* Monitor disk usage and alert when usage > 85%

### 📄 Sample Logic:

```bash
#!/bin/bash
THRESHOLD=85
USAGE=$(df / | awk 'NR==2 {print $5}' | sed 's/%//')
if [ $USAGE -gt $THRESHOLD ]; then
  echo "Disk space on / is at $USAGE%" | mail -s "Disk Alert" admin@localhost
fi
```

---

## 🗂️ Task 2: Backup Automation Script

### 📋 Requirements:

* Daily backup of `/etc` to `/backups/etc-YYYYMMDD.tar.gz`
* Keep backups for 7 days max

### ⚙️ Sample:

```bash
#!/bin/bash
DATE=$(date +%F)
BACKUP_FILE="/backups/etc-$DATE.tar.gz"
tar -czf "$BACKUP_FILE" /etc
find /backups -name "etc-*.tar.gz" -mtime +7 -delete
```

---

## 🧪 Task 3: Debug a Broken Script

### 🔧 Approach:

* Use `bash -x script.sh` to trace
* Use `set -e` and `set -u` to catch logic and usage errors
* Check for unquoted variables and mistyped conditionals

### 👀 What to Look For:

* Missing variables
* Incorrect `if` or `[]` usage
* Unexpected command output

---

## ✅ Summary

By dinner, you should be able to:

* Monitor and alert on disk usage
* Automate and prune backups
* Troubleshoot scripting issues efficiently

Use `day-23-dinner` to walk through each lab interactively.
