# Day 18 - Dinner: Disaster Recovery Planning

## 🍽️ Lab 1: Create Local Backups

```bash
tar -czvf etc_backup.tar.gz /etc
rsync -av /home/user/ /mnt/backup/
```

## 🍽️ Lab 2: Automate with Cron

```bash
nano ~/scripts/daily_backup.sh
crontab -e
# Add:
0 1 * * * /home/user/scripts/daily_backup.sh
chmod +x ~/scripts/daily_backup.sh
```

## 🍽️ Lab 3: Test Restoration

```bash
mkdir /tmp/etc_restore
tar -xzvf etc_backup.tar.gz -C /tmp/etc_restore
diff -r /etc /tmp/etc_restore
```

## ✅ Summary

- Created, automated, and restored backups locally and remotely.