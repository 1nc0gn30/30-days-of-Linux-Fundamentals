# Day 18 - Breakfast: Introduction to Backup Strategies

## 🥐 Lesson 1: Understanding Backup Types

- **Full Backup**: Captures all files every time. Takes longest but easiest to restore.
- **Incremental Backup**: Only backs up files changed since the last *incremental* backup. Fastest and smallest in size.
- **Differential Backup**: Backs up all changes since the last *full* backup. Larger than incremental, but faster to restore.

## 🥐 Lesson 2: Using `tar` for Backup

```bash
tar -czvf backup.tar.gz /home/user/
```

- `-c`: Create a new archive  
- `-z`: Compress using gzip  
- `-v`: Verbose output  
- `-f`: Specify filename  

Use `tar` to compress and archive files for full backups or one-time archives.

## 🥐 Lesson 3: Using `rsync` for Incremental Backups

```bash
rsync -av --delete /home/user/ /mnt/backup/
```

- `-a`: Archive mode (preserves permissions, symbolic links, etc.)  
- `-v`: Verbose output  
- `--delete`: Ensures that deletions in source are reflected in destination  

`rsync` is ideal for incremental backups due to its efficiency and ability to sync only changed files.

## 📚 Additional Resources

- https://linuxize.com/post/how-to-create-and-extract-archives-using-the-tar-command-in-linux/
- https://rsync.samba.org/