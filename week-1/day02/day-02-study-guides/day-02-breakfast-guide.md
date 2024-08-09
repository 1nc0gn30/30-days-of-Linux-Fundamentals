# Day 02 Breakfast Study Guide

Welcome to Day 2's breakfast study guide! This guide covers new commands related to file and directory attributes, process management, and permissions. Use this guide to review and reinforce your understanding of the commands introduced in the Day 2 breakfast challenge.

## Changing File Ownership

### `chown`
The `chown` command is used to change the ownership of files and directories. You can specify a new owner and optionally a new group.

**Examples:**
```sh
chown user:group file.txt           # Change the owner to 'user' and the group to 'group'
chown user file.txt                  # Change only the owner to 'user'; the group remains unchanged
chown :group file.txt                # Change only the group to 'group'; the owner remains unchanged

Description:

    user:group specifies the new owner and group.
    If only user is provided, the group remains unchanged.
    If only :group is provided, the owner remains unchanged.

Changing File Attributes
chattr

The chattr command changes file attributes on a Linux file system. Attributes can control file behaviors such as immutability or append-only status.

Examples:

sh

chattr +i file.txt                   # Set the immutable attribute, making 'file.txt' unchangeable
chattr -i file.txt                   # Remove the immutable attribute, allowing changes
lsattr file.txt                      # List attributes of 'file.txt'

Description:

    +i makes the file immutable, meaning it cannot be modified or deleted.
    -i removes the immutable attribute.
    lsattr lists the attributes of files in the directory.

Displaying Running Processes
ps

The ps command displays information about active processes. It provides a snapshot of current processes, including their PID and resource usage.

Examples:

sh

ps                                # Show processes running in the current shell
ps aux                            # Show detailed information about all processes
ps -ef                            # Show processes in full format including user and command

Description:

    ps alone shows processes in the current shell.
    ps aux provides a detailed list of all processes.
    ps -ef shows full-format listing including additional details.

Monitoring System Activity
top

The top command provides a dynamic, real-time view of system processes. It updates periodically to show current CPU and memory usage.

Examples:

sh

top                                # Start the top command to view real-time system activity
top -u username                     # Filter processes to show those belonging to a specific user
top -d 10                           # Refresh display every 10 seconds

Description:

    top provides a real-time overview of system performance.
    -u filters processes by user.
    -d sets the refresh interval for updates.

Viewing and Controlling Processes
kill

The kill command sends signals to processes to control their execution. Signals can terminate processes or change their state.

Examples:

sh

kill PID                            # Send the default TERM signal to process with ID 'PID'
kill -9 PID                         # Forcefully terminate the process with 'PID' using the KILL signal
pkill process_name                  # Send signals to all processes matching 'process_name'

Description:

    kill PID sends the TERM signal, which allows processes to clean up before exiting.
    kill -9 PID sends the KILL signal, which immediately terminates the process without cleanup.
    pkill allows sending signals to processes by name.

Summary

Use this study guide to review the commands learned during the Day 2 breakfast session. Practice these commands in your terminal to gain proficiency in managing file attributes, processes, and permissions.
