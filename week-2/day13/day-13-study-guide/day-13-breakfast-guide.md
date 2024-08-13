# Day 13 Breakfast Study Guide: System Administration Best Practices

## Overview
In this session, we will explore key practices for effective system administration. We will cover:

1. **System Monitoring and Performance Tuning**
2. **Backup and Recovery Strategies**
3. **Security Best Practices**

## Lessons

### Lesson 1: System Monitoring and Performance Tuning

Monitoring and tuning system performance are crucial for maintaining system health. Here are some important commands and their usage:

- top: Displays real-time system information and resource usage.
```bash
  top
  ```
- htop: An enhanced version of top with a user-friendly interface.
```bash
htop
```
- vmstat: Reports virtual memory statistics.
```bash
vmstat 5
```
- iostat: Reports CPU and I/O statistics.
```bash
iostat -x 5
```
Use these commands to monitor and optimize system performance.

### Lesson 2: Backup and Recovery Strategies
Backup and recovery are essential for data protection and system resilience. Here are some tools and commands for backup and recovery:

- rsync: Efficiently syncs files and directories.
```bash
rsync -avz /source/ /destination/
```
- tar: Archives files into a single file.
```bash
tar -cvzf backup.tar.gz /directory/
```
- dd: Creates disk images.
```bash
sudo dd if=/dev/sda of=/path/to/backup.img bs=4M
```
Automate backups using cron by adding a cron job to /etc/crontab:

```bash
0 2 * * * /usr/bin/rsync -avz /source/ /destination/
```
Test your backup and recovery procedures to ensure data integrity.

### Lesson 3: Security Best Practices
Implementing security best practices is crucial for protecting Linux systems. Here are some important commands:

- chmod: Changes file permissions.
```bash
chmod 700 /secure_file
```
- chown: Changes file ownership.
```bash
chown user:group /file
```
- Configure firewall with ufw:
```bash
sudo ufw enable
sudo ufw allow 22
```
- Ensure to regularly review and update security configurations.

## Questions
### Which command displays real-time system information and resource usage?

A. top
B. htop
C. vmstat
D. iostat
**Correct Answer: A. top*

### Which tool creates disk images?

A. rsync
B. tar
C. dd
D. cp
**Correct Answer: C. dd*

### How do you enable a firewall using ufw?

A. sudo ufw enable
B. sudo firewall start
C. sudo iptables -A
D. sudo firewall-cmd --add-port
**Correct Answer: A. sudo ufw enable*

### What does the chmod 700 command do?

A. Changes file permissions
B. Changes file ownership
C. Creates a backup
D. Archives files
**Correct Answer: A. Changes file permissions*

### Which command is used to sync files and directories?

A. rsync
B. tar
C. dd
D. cp
**Correct Answer: A. rsync*

### How do you schedule automated backups with cron?

A. Edit /etc/crontab
B. Use the cron command
C. Run crontab -e
D. Edit /etc/cron.daily
**Correct Answer: A. Edit /etc/crontab*

#### Conclusion

In Day 13 Breakfast, we've covered essential system administration practices. From monitoring and performance tuning to backup strategies and security best practices, these lessons provide foundational knowledge for effective system management. Make sure to practice the commands and strategies discussed to ensure you are well-prepared for managing and securing Linux systems.

Good luck with your studies and practice!