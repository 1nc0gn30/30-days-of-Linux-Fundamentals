# Day 10: Linux Fundamentals - Dinner Session

Welcome to the Day 10 Dinner session of Linux Fundamentals! In this session, we will delve into **Remote Access** and **System Recovery Techniques**. Make sure you have a terminal open as you'll be practicing various commands.

---

## Lessons

### 1. **Secure Remote Access with SSH**
   - **Description:** SSH (Secure Shell) is the most common tool for remote administration of Linux systems.
   - **Command Example:**
     ```bash
     ssh user@remote_host
     ```
   - **Instruction:** Open a terminal and connect to a remote server using the command above. Replace `user` with your username and `remote_host` with the server's address.

### 2. **File Transfer with SCP**
   - **Description:** SCP (Secure Copy) allows you to securely copy files between hosts.
   - **Command Example:**
     ```bash
     scp file.txt user@remote_host:/remote/directory
     ```
   - **Instruction:** Use SCP to copy a file to a remote server. Replace `file.txt` with your file name, `user` with your username, and `/remote/directory` with the destination directory.

### 3. **Disk Usage Monitoring with SSH**
   - **Description:** You can remotely check disk usage on a server using SSH.
   - **Command Example:**
     ```bash
     ssh user@remote_host 'df -h'
     ```
   - **Instruction:** Check the disk usage on your remote server using the command above.

### 4. **Mounting Remote Directories with SSHFS**
   - **Description:** SSHFS allows you to mount a remote directory over SSH.
   - **Command Example:**
     ```bash
     sshfs user@remote_host:/remote/data /mnt/local_mount
     ```
   - **Instruction:** Mount a remote directory to your local filesystem. Replace `/remote/data` with the directory on the remote server and `/mnt/local_mount` with your local mount point.

### 5. **Booting into Single-User Mode**
   - **Description:** Single-user mode is useful for system recovery and maintenance.
   - **Command Example:**
     ```bash
     Append 'single' to the kernel line in GRUB during boot.
     ```
   - **Instruction:** Reboot your system and enter single-user mode by editing the GRUB boot parameters.

### 6. **Resetting the Root Password**
   - **Description:** If you've forgotten the root password, it can be reset in single-user mode.
   - **Command Example:**
     ```bash
     passwd
     ```
   - **Instruction:** After booting into single-user mode, reset the root password using the command above.

### 7. **Recovering Deleted Files with extundelete**
   - **Description:** extundelete can be used to recover deleted files on ext3/ext4 filesystems.
   - **Command Example:**
     ```bash
     extundelete /dev/sdX --restore-file /path/to/file
     ```
   - **Instruction:** Attempt to recover a deleted file by replacing `/dev/sdX` with your disk and `/path/to/file` with the file path.

### 8. **Changing the Root Directory with chroot**
   - **Description:** `chroot` changes the root directory for the current running process.
   - **Command Example:**
     ```bash
     chroot /mnt
     ```
   - **Instruction:** Use `chroot` to change the root directory to `/mnt` for system repair.

### 9. **Reinstalling GRUB from a Live CD**
   - **Description:** Reinstalling GRUB is necessary when the bootloader is damaged.
   - **Command Example:**
     ```bash
     grub-install --root-directory=/mnt /dev/sdX
     ```
   - **Instruction:** Boot from a Live CD and reinstall GRUB on your disk by replacing `/dev/sdX` with your disk.

### 10. **Creating a Backup Image with dd**
   - **Description:** `dd` is a powerful tool to create disk images for backups.
   - **Command Example:**
     ```bash
     dd if=/dev/sda of=/path/to/backup.img
     ```
   - **Instruction:** Create a backup image of your disk using the `dd` command. Replace `/dev/sda` with your disk and `/path/to/backup.img` with the desired output path.

---

## Questions

1. **What command would you use to securely connect to a remote server as user 'john'?**
   ```bash
   ssh john@remote_host
How do you copy a file named 'report.txt' to a remote server at '/home/user/' using SCP?

```bash
scp report.txt user@remote_host:/home/user/
```
What is the command to display disk usage on a remote server using SSH?

```bash
ssh user@remote_host 'df -h'
```
How can you mount a remote directory '/data' to '/mnt/remote_data' using SSHFS?

```bash
sshfs user@remote_host:/data /mnt/remote_data
```
Which boot parameter would you add to GRUB to boot into single-user mode?

```bash
single
```
What command is used to reset the root password after booting into single-user mode?

```bash
passwd
```
How would you recover a deleted file '/home/user/document.txt' using extundelete?

```bash
extundelete /dev/sdX --restore-file /home/user/document.txt
```
Which command changes the root directory to '/mnt' for system repair?

```bash
chroot /mnt
```
How do you reinstall GRUB to the first disk after booting from a live CD?

```bash
grub-install --root-directory=/mnt /dev/sdX
```
What dd command would you use to create a backup image of a disk '/dev/sda'?
```bash
dd if=/dev/sda of=/path/to/backup.img
```

## Conclusion

Well done on completing the Day 10 Dinner session of Linux Fundamentals! You’ve successfully learned critical skills in **Remote Access** and **System Recovery Techniques**, which are essential for maintaining and troubleshooting Linux systems. 

By mastering these commands, you’re equipped to securely manage remote servers, recover from system failures, and ensure your Linux environments remain robust and reliable. Keep practicing these techniques, and you'll be well-prepared to handle real-world scenarios with confidence.

Remember, consistency is key—so keep up the great work, and continue pushing your Linux skills to the next level!

Happy learning!

