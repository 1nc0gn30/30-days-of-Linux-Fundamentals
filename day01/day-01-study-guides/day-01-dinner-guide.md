# Day 1 Dinner Challenge Study Guide

## 1. Creating Symbolic Links

**Command:** `ln`  
**Description:**  
The `ln` command creates links between files. A symbolic link (symlink) is a reference to another file, allowing you to access the target file from different locations.

**Examples:**
- `ln -s /path/to/original file_link`  
  Creates a symbolic link named 'file_link' that points to '/path/to/original'.

- `ln file1.txt file_link`  
  Creates a hard link to 'file1.txt' named 'file_link'. Hard links share the same inode and are indistinguishable from the original file.

## 2. Finding Files by Type

**Command:** `find`  
**Description:**  
The `find` command searches for files and directories in a directory hierarchy based on specified criteria. The `-type` option helps filter results by file type.

**Examples:**
- `find . -type f`  
  Finds all regular files in the current directory and subdirectories.

- `find . -type d`  
  Finds all directories in the current directory and subdirectories.

- `find /path -type l`  
  Finds all symbolic links in the specified path.

## 3. Archiving Files

**Command:** `tar`  
**Description:**  
The `tar` command is used to create and manipulate archive files. Archives bundle multiple files into one file, which can be compressed or uncompressed.

**Examples:**
- `tar -cvf archive.tar file1.txt file2.txt`  
  Creates an archive named 'archive.tar' containing 'file1.txt' and 'file2.txt'.

- `tar -xvf archive.tar`  
  Extracts files from 'archive.tar'.

- `tar -czvf archive.tar.gz file1.txt`  
  Creates a compressed archive named 'archive.tar.gz' from 'file1.txt'.

## 4. Searching for Files

**Command:** `find`  
**Description:**  
The `find` command can also search for files based on various attributes such as name, size, or modification time.

**Examples:**
- `find . -name '*.txt'`  
  Finds all files with a '.txt' extension in the current directory and subdirectories.

- `find . -size +1M`  
  Finds all files larger than 1 MB.

- `find . -mtime -7`  
  Finds all files modified in the last 7 days.

## 5. Checking File Integrity

**Command:** `md5sum`  
**Description:**  
The `md5sum` command calculates and verifies MD5 checksums. This is used to ensure file integrity by comparing checksums to detect corruption.

**Examples:**
- `md5sum file.txt`  
  Displays the MD5 checksum of 'file.txt'.

- `md5sum -c checksum.md5`  
  Checks files against the checksums listed in 'checksum.md5'.

## 6. Scheduling Tasks

**Command:** `crontab`  
**Description:**  
The `crontab` command is used to schedule tasks (cron jobs) that run automatically at specified intervals. You can set up jobs to run daily, weekly, or at other regular times.

**Examples:**
- `crontab -e`  
  Opens the crontab file for editing. You can add or modify scheduled tasks.

- `crontab -l`  
  Lists the current user's cron jobs.

- Example cron job entry: `0 5 * * * /path/to/script.sh`  
  This entry runs the script located at `/path/to/script.sh` every day at 5 AM.

## 7. Monitoring System Performance

**Command:** `top`  
**Description:**  
The `top` command provides a real-time view of system processes and resource usage. It shows CPU and memory usage statistics, along with a list of running processes.

**Examples:**
- `top`  
  Displays real-time system statistics including CPU, memory usage, and a list of active processes.

- `top -u username`  
  Filters the display to show only processes running under the specified user.

- `top -d 10`  
  Sets the display to refresh every 10 seconds.

---

**Challenge Summary:**
In this Dinner challenge, you learned about several new commands for managing files and directories, creating symbolic links, archiving files, checking file integrity, and scheduling tasks. Each command has been explained with practical examples to help you understand how to use them effectively.

---

**Next Steps:**
- Practice using these commands in your terminal to become familiar with their options and output.
- Explore additional options and combinations of these commands to enhance your file and system management skills.

Happy learning and experimenting with Linux commands!

