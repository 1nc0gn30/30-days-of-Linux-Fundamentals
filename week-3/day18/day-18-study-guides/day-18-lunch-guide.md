# Day 18 - Lunch: Automating Backups

## 🍱 Lesson 1: Automating with Cron

```bash
crontab -e
# Example:
0 2 * * * tar -czf /backup/home_backup.tar.gz /home/user
```

## 🍱 Lesson 2: Snapshots with Btrfs

```bash
sudo btrfs subvolume snapshot /data /snapshots/data_$(date +%F)
```

## 🍱 Lesson 3: Remote Backups via SSH + rsync

```bash
rsync -avz /home/user/ user@remote:/backup/user/
```

## 📚 Resources

- https://crontab.guru/
- https://wiki.archlinux.org/title/Rsync
- https://btrfs.readthedocs.io/en/latest/btrfs-snapshot.html