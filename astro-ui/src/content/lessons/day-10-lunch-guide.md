# Day 10 Lunch: Remote Access, Management, and System Recovery

Welcome to Day 10 Lunch! In this session, we will explore **Remote Access and Management** and **System Recovery and Rescue**. We'll cover essential commands and techniques for managing and recovering Linux systems.

## Lessons

### 1. Remote Access with SSH
**Secure Shell (SSH)** is a protocol for securely accessing and managing a remote server. The basic syntax to connect to a remote server is:

```bash
ssh username@remote_host
```
For example, to connect to a remote server with the IP address 192.168.1.10 as the user admin, use the command:

`````` bash
ssh admin@192.168.1.10
``````

### 2. Copying Files with SCP
Secure Copy Protocol (SCP) allows you to securely transfer files between hosts over SSH.

To copy a file from your local machine to a remote server:

`````` bash
scp localfile.txt username@remote_host:/path/to/destination
``````

To copy a file from a remote server to your local machine:

`````` bash
scp username@remote_host:/path/to/file localfile.txt
``````

### 3. Monitoring Remote Systems with SSH
You can execute commands on a remote system over SSH to monitor or manage it.

For example, to check the disk usage on a remote server:

`````` bash
ssh username@remote_host 'df -h'
``````

Or to view the running processes:

``` bash
ssh username@remote_host 'top -b -n 1'
```
### 4. Remote File System Mounting with SSHFS
SSHFS (SSH File System) allows you to mount a remote filesystem locally using SSH.

To mount a remote directory:

``` bash
sshfs username@remote_host:/remote/path /local/mountpoint
```
To unmount the directory:

``` bash
fusermount -u /local/mountpoint
```
### 5. Rescue Mode and Single-User Mode
Rescue mode is a way to boot your system with minimal services to troubleshoot issues. Single-user mode is a similar mode used primarily for maintenance.

To boot into single-user mode, you can edit the GRUB boot menu and add single or rescue to the boot parameters.

### 6. Resetting the Root Password
If you lose the root password, you can reset it by booting into single-user mode.

Once in single-user mode, use the passwd command to reset the root password:

``` bash
passwd
```
Enter and confirm the new password when prompted.

### 7. Recovering Deleted Files with extundelete
extundelete is a utility that can recover deleted files from ext3/ext4 filesystems.

To recover a deleted file, run:

``` bash
extundelete /dev/sdX --restore-file /path/to/deleted/file
```
Replace /dev/sdX with the appropriate device identifier and specify the path to the file.

### 8. Using chroot for System Repair
The chroot command changes the apparent root directory for a process, useful in system recovery.

For example, if you need to repair a system from a live CD:

Mount the filesystem:

``` bash
mount /dev/sdX1 /mnt
```
Change root to the mounted system:

``` bash
chroot /mnt
```
Now you can run commands as if you were on the original system.

### 9. Reinstalling GRUB Bootloader
If the GRUB bootloader is corrupted, you can reinstall it using a live CD or rescue mode.

Boot into a live environment.

Mount the root filesystem:

``` bash
mount /dev/sdX1 /mnt
```
Reinstall GRUB:

``` bash
grub-install --root-directory=/mnt /dev/sdX
```
### 10. System Rescue with dd
The dd command can be used for low-level copying and backup, useful in rescue scenarios.

For example, to create a disk image:

``` bash
dd if=/dev/sdX of=/path/to/backup.img
```
To restore the image:

``` bash
dd if=/path/to/backup.img of=/dev/sdX
```
## Questions and Answers

1. **What command would you use to securely connect to a remote server as user 'john'?**

```bash
   ssh john@remote_host
```
#### How do you copy a file named 'report.txt' to a remote server at '/home/user/' using SCP?

```bash

scp report.txt user@remote_host:/home/user/
```
#### What is the command to display disk usage on a remote server using SSH?

```bash

ssh user@remote_host 'df -h'
```
#### How can you mount a remote directory '/data' to '/mnt/remote_data' using SSHFS?

```bash

sshfs user@remote_host:/data /mnt/remote_data
```
#### Which boot parameter would you add to GRUB to boot into single-user mode?

```bash

single
```
#### What command is used to reset the root password after booting into single-user mode?

```bash

passwd
```
#### How would you recover a deleted file '/home/user/document.txt' using extundelete?

```bash

extundelete /dev/sdX --restore-file /home/user/document.txt
```
#### Which command changes the root directory to '/mnt' for system repair?

```bash

chroot /mnt
```
#### How do you reinstall GRUB to the first disk after booting from a live CD?

```bash

grub-install --root-directory=/mnt /dev/sdX
```
#### What dd command would you use to create a backup image of a disk '/dev/sda'?

```bash

dd if=/dev/sda of=/path/to/backup.img
```
#### Conclusion
Congratulations! You've completed the Day 10 Lunch session. You now have a solid understanding of remote access, system recovery, and rescue techniques in Linux. Keep practicing these commands and concepts to build a strong foundation in Linux system administration.