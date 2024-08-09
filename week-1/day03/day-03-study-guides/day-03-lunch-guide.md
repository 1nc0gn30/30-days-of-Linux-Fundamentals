# Day 03 Lunch Study Guide: Advanced File and Directory Management

Welcome to Day 3 Lunch! Today, we will dive deeper into file and directory management with a focus on creating, copying, moving, renaming files, and navigating directories. We'll also cover some advanced tasks to help solidify your skills.

## Topics Covered

### Create, Copy, Move, and Rename Files

- **Creating Files**
  - `touch filename.txt`  
    Creates an empty file named `filename.txt`. If the file already exists, it updates its timestamp.

  - `echo 'content' > filename.txt`  
    Creates a file named `filename.txt` with the specified content. If the file already exists, it overwrites its content.

- **Copying Files**
  - `cp source.txt destination.txt`  
    Copies the file `source.txt` to `destination.txt`. If `destination.txt` already exists, it will be overwritten.

  - `cp -r source_dir/ destination_dir/`  
    Recursively copies the directory `source_dir` and its contents to `destination_dir`.

- **Moving and Renaming Files**
  - `mv oldname.txt newname.txt`  
    Renames `oldname.txt` to `newname.txt`. If the target file exists, it will be overwritten.

  - `mv file.txt /path/to/destination/`  
    Moves `file.txt` to the specified directory `/path/to/destination/`. It can also rename the file if a new name is provided.

- **Additional Commands**
  - `cp -i source.txt destination.txt`  
    Copies `source.txt` to `destination.txt` with an interactive prompt to confirm overwriting.

  - `mv -i oldname.txt newname.txt`  
    Renames or moves `oldname.txt` to `newname.txt` with an interactive prompt to confirm overwriting.

### Directory Navigation and Manipulation

- **Navigating Directories**
  - `cd /path/to/directory`  
    Changes the current directory to `/path/to/directory`.

  - `cd ..`  
    Moves up one directory level.

  - `cd ~`  
    Changes to the home directory of the current user.

- **Creating and Removing Directories**
  - `mkdir directory_name`  
    Creates a new directory named `directory_name`.

  - `mkdir -p parent/child`  
    Creates nested directories `parent` and `child`. The `-p` flag ensures that parent directories are created if they do not exist.

  - `rmdir directory_name`  
    Removes an empty directory named `directory_name`.

  - `rm -r directory_name`  
    Recursively removes a directory and its contents.

- **Additional Commands**
  - `cd -`  
    Switches to the previous directory.

  - `ls -R`  
    Lists all files and directories recursively.

### File Management Scavenger Hunt

- **Finding Files**
  - `find /path -name '*.txt'`  
    Finds all files with the `.txt` extension in the specified path.

  - `find /path -type f -size +1M`  
    Finds all files larger than 1 MB in the specified path.

- **Searching File Content**
  - `grep 'pattern' filename.txt`  
    Searches for the specified `pattern` in `filename.txt`.

  - `grep -r 'pattern' /path/to/dir/`  
    Recursively searches for `pattern` in all files within `/path/to/dir/`.

- **Managing Files**
  - `mv file1.txt /backup/`  
    Moves `file1.txt` to the `/backup/` directory.

  - `cp -u file1.txt /backup/`  
    Copies `file1.txt` to `/backup/` only if `file1.txt` is newer than the existing file in `/backup/`.

  - `rm -i file1.txt`  
    Removes `file1.txt` with an interactive prompt to confirm deletion.

## Practice Questions

1. **Create a file named `testfile.txt` with content 'Test Content'.**
   - Command: `echo 'Test Content' > testfile.txt`

2. **Copy `testfile.txt` to a directory named `backup/`.**
   - Command: `cp testfile.txt backup/`

3. **Rename `testfile.txt` to `renamedfile.txt` and move it to `backup/`.**
   - Command: `mv testfile.txt backup/renamedfile.txt`

4. **Recursively copy the `backup/` directory to `archive/`.**
   - Command: `cp -r backup/ archive/`

5. **Navigate to the `/etc` directory.**
   - Command: `cd /etc`

6. **Create a directory structure `/data/archive/2024`.**
   - Command: `mkdir -p /data/archive/2024`

7. **Change the permissions of `/data` to `755`.**
   - Command: `chmod 755 /data`

8. **Display the size of the `/home/user` directory.**
   - Command: `du -sh /home/user`

9. **Remove the `/data/archive/2024` directory and all its contents.**
   - Command: `rm -r /data/archive/2024`

10. **Find all `.log` files in `/var/log`.**
    - Command: `find /var/log -name '*.log'`

11. **Search for the pattern 'Error' in `/var/log/syslog`.**
    - Command: `grep 'Error' /var/log/syslog`

12. **Move a file named `report.txt` from `/home/user/` to `/archive/`.**
    - Command: `mv /home/user/report.txt /archive/`

13. **Create a backup of `report.txt` in `/backup/` without overwriting existing files.**
    - Command: `cp -u /home/user/report.txt /backup/`

14. **Remove `report.txt` from `/archive/` interactively.**
    - Command: `rm -i /archive/report.txt`

---

Great job on completing Day 3 Lunch! You've explored advanced file and directory management techniques, and tackled a variety of real-world scenarios. Keep practicing to master these commands and enhance your Linux skills.
