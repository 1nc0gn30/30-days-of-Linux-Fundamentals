# Day 20 - Dinner: Scripting Challenge Labs

## 🧪 Lab 1: Automate System Monitoring

1. Create `monitor_disk.sh`:
```bash
THRESHOLD=80
USAGE=$(df / | grep / | awk '{print $5}' | sed 's/%//g')
if [ "$USAGE" -gt "$THRESHOLD" ]; then
  echo "Disk space high: $USAGE%" | mail -s "Disk Alert" root
fi
```
2. Add to crontab for automatic checks.

---

## 💾 Lab 2: Backup Automation Script

1. Create `backup_logs.sh`:
```bash
BACKUP_DIR="/backup/$(date +%F)"
mkdir -p "$BACKUP_DIR"
cp -r /var/log "$BACKUP_DIR"
find /backup -type d -mtime +7 -exec rm -rf {} +
```
2. Automate daily with cron.

---

## 🐛 Lab 3: Script Debugging

1. Create buggy script:
```bash
#!/bin/bash
for i in 1 2 3
  echo "Number $i"
```
2. Debug:
```bash
bash -x broken_script.sh
```
3. Fix: add `do` after `for` line
4. Use `set -e` to stop on error, and `set -x` to trace

---

## ✅ Summary

- Created monitoring and backup automation
- Debugged and hardened scripts with real-world usage