# Day 01 Breakfast Study Guide

Welcome to the Breakfast challenge for Day 1! This guide will help you understand and practice the essential Linux commands covered in the challenge.

## Lesson on `ls`

**Description:**  
The `ls` command lists directory contents. It shows the files and directories in the specified directory.

**Examples:**
- `ls`  
  Lists files and directories in the current directory.

- `ls -l`  
  Lists files with detailed information, including permissions, owner, group, size, and modification date.

- `ls -a`  
  Lists all files, including hidden files (those starting with a dot).

- `ls -lh`  
  Lists files with human-readable file sizes (e.g., KB, MB).

- `ls -R`  
  Recursively lists all subdirectories and their contents.

**Usage Tip:**  
Use `ls` with various options to get detailed insights about files and directories. Combining options can provide more comprehensive information about the directory contents.

---

## Lesson on `cd`

**Description:**  
The `cd` command changes the current working directory. It's used to navigate through directories.

**Examples:**
- `cd /home/user`  
  Changes to the specified directory.

- `cd ..`  
  Moves up one directory level.

- `cd ~`  
  Changes to the home directory of the current user.

- `cd -`  
  Switches to the previous directory.

- `cd /var/log`  
  Changes to a specific directory (e.g., system logs).

**Usage Tip:**  
Use `cd` to navigate between directories efficiently. The `~` symbol is a shortcut to your home directory, making it easier to return to the starting point.

---

## Lesson on `touch`

**Description:**  
The `touch` command creates a new empty file or updates the timestamp of an existing file. It is commonly used to create a new file quickly.

**Examples:**
- `touch newfile.txt`  
  Creates a new file named `newfile.txt`.

- `touch existingfile.txt`  
  Updates the timestamp of `existingfile.txt`.

- `touch file1.txt file2.txt`  
  Creates or updates multiple files at once.

- `touch -c non_existing_file.txt`  
  Creates the file only if it does not already exist. The `-c` flag prevents the creation of a new file if it doesn't exist.

**Usage Tip:**  
`touch` is useful for creating files quickly without editing them. It’s also handy for updating timestamps, which can be important for file management.

---

## Lesson on `rm`

**Description:**  
The `rm` command removes (deletes) files or directories. Be cautious as this operation is irreversible and does not move files to a trash or recycle bin.

**Examples:**
- `rm file.txt`  
  Removes the file named `file.txt`.

- `rm -i file.txt`  
  Prompts for confirmation before deleting the file.

- `rm -r directory/`  
  Removes a directory and its contents recursively.

- `rm -f file.txt`  
  Force deletes the file, ignoring nonexistent files and without prompting.

**Usage Tip:**  
Use `rm` with caution. The `-i` option helps prevent accidental deletion by asking for confirmation. Always double-check before using `rm -r` to avoid deleting important directories.

---

## Lesson on `pwd`

**Description:**  
The `pwd` command prints the current working directory. It shows the full path to the directory you are currently in, which helps in navigating and managing files.

**Examples:**
- `pwd`  
  Prints the full path of the current directory.

- `pwd -L`  
  Prints the logical path (resolves symbolic links).

- `pwd -P`  
  Prints the physical path (without resolving symbolic links).

**Usage Tip:**  
Use `pwd` to confirm your current location in the filesystem. This is especially useful when working in deeply nested directories or when scripting.

---

## Lesson on `mkdir`

**Description:**  
The `mkdir` command creates a new directory. It is useful for organizing files into separate folders.

**Examples:**
- `mkdir new_directory`  
  Creates a new directory named `new_directory`.

- `mkdir -p parent/child`  
  Creates parent and child directories; the `-p` flag creates parent directories if they do not exist.

- `mkdir -m 755 new_dir`  
  Creates a directory with specific permissions (`755` in this case, which means read/write/execute for the owner, and read/execute for others).

**Usage Tip:**  
Use `mkdir` to create new directories for better organization. The `-p` flag helps in creating nested directories in a single command.

---

## Lesson on `cp`

**Description:**  
The `cp` command copies files or directories from one location to another. It can also be used to copy files and directories recursively.

**Examples:**
- `cp file1.txt file2.txt`  
  Copies `file1.txt` to `file2.txt`.

- `cp -r dir1/ dir2/`  
  Recursively copies directory `dir1` to `dir2`.

- `cp -i file1.txt backup/`  
  Prompts before overwriting the file in `backup/`.

- `cp -u file1.txt destination/`  
  Copies only if `file1.txt` is newer than the existing file in `destination/`.

**Usage Tip:**  
Use `cp` to duplicate files and directories. The `-i` option helps avoid overwriting files unintentionally, and the `-u` option ensures that only newer files are copied.

---

## Lesson on `mv`

**Description:**  
The `mv` command moves or renames files and directories. It can be used to move files from one location to another or to rename files and directories.

**Examples:**
- `mv file1.txt /path/to/destination/`  
  Moves `file1.txt` to the specified directory.

- `mv oldname.txt newname.txt`  
  Renames `oldname.txt` to `newname.txt`.

- `mv -i file1.txt backup/`  
  Prompts before overwriting files in `backup/`.

- `mv -u file1.txt destination/`  
  Moves only if `file1.txt` is newer than the existing file in `destination/`.

**Usage Tip:**  
Use `mv` to relocate or rename files and directories. The `-i` option helps avoid accidental overwrites, and `-u` ensures that only updated files are moved.

---

## Practice and Quiz

After reviewing each command, practice using them in your terminal. Test your knowledge with the following questions:

1. What command lists all files and directories in the current directory?
2. What command changes the current directory?
3. What command creates a new empty file?
4. What command removes a file?
5. What command prints the current working directory?
6. What command creates a new directory?
7. What command copies files or directories from one location to another?
8. What command moves or renames files and directories?

Happy learning and experimenting with Linux commands!

