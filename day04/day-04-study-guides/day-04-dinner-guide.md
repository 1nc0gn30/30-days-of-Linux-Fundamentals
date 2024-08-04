## Day 4 Dinner Study Guide
1. Advanced Editing with vim - Review

Commands:

    :e filename: Opens a new file for editing.
    :set nonumber: Hides line numbers.
    :set wrap: Enables text wrapping for long lines.
    :!ls: Executes the ls command within vim to list directory contents.
    :diffsplit file2.txt: Compares the current file with file2.txt side-by-side.
    :syntax on: Enables syntax highlighting.
    :tabnew: Opens a new tab in vim.
    :tabnext: Switches to the next tab.
    :bdelete: Closes the current buffer.

Description:

    vim is a powerful text editor with numerous features for advanced file editing and comparison. Mastering these commands will help you efficiently handle complex editing tasks and navigate multiple files.

Examples:

bash

# Open a new file named 'example.txt'
:e example.txt

# Hide line numbers and enable text wrapping
:set nonumber
:set wrap

# Run an external command within `vim`
:!ls

# Compare 'file1.txt' with 'file2.txt'
:diffsplit file2.txt

# Enable syntax highlighting
:syntax on

# Open a new tab
:tabnew

# Switch to the next tab
:tabnext

# Close the current buffer
:bdelete

2. Advanced Editing with nano - Review

Commands:

    ^T: Invokes the spell checker (if available).
    ^G: Displays help.
    ^C: Shows the cursor position.
    ^R: Inserts another file into the current file.
    ^W, ^R: Performs search and replace.
    ^K, ^U: Cuts and pastes multiple lines.
    ^J: Justifies (wraps) text.
    ^X, ^A: Exits and confirms changes.

Description:

    nano provides a user-friendly interface with various advanced features for text manipulation. These commands allow for efficient file editing and content management.

Examples:

bash

# Invoke the spell checker (Ctrl+T)
^T

# Display help (Ctrl+G)
^G

# Show cursor position (Ctrl+C)
^C

# Insert 'anotherfile.txt' into the current file (Ctrl+R)
^R

# Search and replace text (Ctrl+W, then Ctrl+R)
^W, ^R

# Cut and paste multiple lines (Ctrl+K, then Ctrl+U)
^K, ^U

# Justify text (Ctrl+J)
^J

# Exit and confirm changes (Ctrl+X, then Ctrl+A)
^X, ^A

3. Understanding File Permissions - Review

Permissions Breakdown:

    rwx------: Full access for the owner.
    rw-rw-rw-: Read/write permissions for everyone.
    r--------: Read-only for the owner.
    rwxr-x---: Owner has read/write/execute; group has read/execute; others have no permissions.
    rwxrwxr-x: Owner/group have read/write/execute; others have read/execute.

Description:

    File permissions control access to files and directories. The r (read), w (write), and x (execute) permissions are set for the owner, group, and others.

Examples:

bash

# Set permissions to full access for the owner
chmod 700 file.txt

# Set read/write permissions for everyone
chmod 666 file.txt

# Set read-only for the owner
chmod 400 file.txt

# Set permissions to rwxr-x--- (owner: rwx, group: r-x, others: ---)
chmod 750 file.txt

# Set permissions to rwxrwxr-x (owner/group: rwxrwx, others: r-x)
chmod 775 file.txt

4. Permission Values and Calculation - Review

Numeric Representation:

    750 = rwxr-x---: Owner has read/write/execute; group has read/execute; others have no permissions.
    775 = rwxrwxr-x: Owner/group have read/write/execute; others have read/execute.
    600 = rw-------: Owner has read/write; group/others have no permissions.
    444 = r--r--r--: Read-only for everyone.
    111 = --x--x--x: Execute-only for everyone.

Description:

    File permissions are represented in octal format, where each digit controls access levels for the owner, group, and others. Each permission level is represented by a combination of read (4), write (2), and execute (1) permissions.

Examples:

bash

# Set permissions to rwxr-x--- (750)
chmod 750 file.txt

# Set permissions to rwxrwxr-x (775)
chmod 775 file.txt

# Set permissions to rw------- (600)
chmod 600 file.txt

# Set permissions to r--r--r-- (444)
chmod 444 file.txt

# Set permissions to --x--x--x (111)
chmod 111 file.txt

5. Advanced File Manipulation - Review

Examples:

    cp -u source.txt destination/: Copies source.txt to destination/ only if source.txt is newer.
    mv -i oldname.txt newname.txt: Moves/renames oldname.txt to newname.txt and prompts before overwriting.
    nano -B file.txt: Edits file.txt with nano, creating a backup before editing.
    vim -d file1.txt file2.txt: Compares file1.txt and file2.txt using vim diff mode.
    find /path -type f -exec chmod 644 {} +: Finds all files in /path and sets permissions to 644.

Description:

    These commands demonstrate advanced techniques for file manipulation, including conditional copying, file comparison, and setting permissions for multiple files.

Examples:

bash

# Copy source.txt only if it is newer than the destination
cp -u source.txt destination/

# Move/rename oldname.txt to newname.txt, prompting before overwriting
mv -i oldname.txt newname.txt

# Edit file.txt with nano, creating a backup before editing
nano -B file.txt

# Compare file1.txt and file2.txt using vim diff mode
vim -d file1.txt file2.txt

# Find all files in /path and set permissions to 644
find /path -type f -exec chmod 644 {} +

Congratulations on completing Day 4 Dinner! You've reviewed and expanded upon key concepts from previous lessons and tackled advanced topics in file management, editing, and permissions. Keep practicing and experimenting to further solidify your skills!
