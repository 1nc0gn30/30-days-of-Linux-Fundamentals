# Day 5 Breakfast Study Guide: Processes and System Monitoring

Welcome to Day 5 Breakfast! Today we will delve into processes and system monitoring, covering essential commands and their advanced usages.

## Viewing Processes (`ps`)

- **Description**: The `ps` command shows information about active processes. This includes their process ID (PID), status, and other details.
- **Basic Usage**:
  - `ps` - Lists processes running in the current shell.
  - `ps aux` - Displays detailed information about all processes.
  - `ps -ef` - Shows all processes in full format.
- **Advanced Usage**:
  - `ps -e -o pid,comm` - Displays only the process ID and command name.
  - `ps --sort=-%mem` - Sort processes by memory usage in descending order.

## Monitoring Processes (`top`)

- **Description**: The `top` command provides a dynamic, real-time view of system processes and resource usage.
- **Basic Usage**:
  - `top` - Displays a real-time list of processes and system resource usage.
  - `top -u username` - Shows processes for a specific user.
- **Advanced Usage**:
  - `top -d 5` - Updates the display every 5 seconds.
  - `top -b -n 1` - Runs `top` in batch mode for a single update, useful for logging.
  - `top -p pid` - Monitor specific process IDs.

## Killing Processes (`kill`, `killall`, `pkill`)

- **Description**: These commands are used to send signals to processes, typically to terminate them.
- **Basic Usage**:
  - `kill PID` - Sends the default TERM signal to the process with ID PID.
  - `kill -9 PID` - Forcefully kills the process using the KILL signal.
  - `killall process_name` - Terminates all processes with the name `process_name`.
- **Advanced Usage**:
  - `pkill -f pattern` - Kills processes whose command line matches the `pattern`.
  - `kill -s SIGTERM PID` - Sends a specific signal to the process.

## System Resource Monitoring (`vmstat`, `iostat`, `free`)

- **Description**: Commands that provide information about system resources like memory, CPU, and I/O statistics.
- **Basic Usage**:
  - `vmstat` - Reports virtual memory statistics.
  - `iostat` - Displays I/O statistics for devices.
  - `free` - Shows memory usage.
- **Advanced Usage**:
  - `vmstat 5` - Updates the report every 5 seconds.
  - `iostat -x 5` - Shows extended I/O statistics every 5 seconds.
  - `free -h` - Displays memory usage in human-readable format.

## Viewing System Logs (`dmesg`, `journalctl`)

- **Description**: System logs provide insights into system events, errors, and messages.
- **Basic Usage**:
  - `dmesg` - Displays kernel ring buffer messages.
  - `journalctl` - Shows systemd journal logs.
- **Advanced Usage**:
  - `dmesg | less` - View `dmesg` output page by page.
  - `journalctl -p err` - Show logs with error priority.
  - `journalctl --since "2024-07-30 10:00:00"` - Logs since a specific date and time.
  - `journalctl -u service_name` - Logs for a specific service.

## Practice Questions

1. **What command would you use to display a real-time list of processes and their system resource usage?**
   - Answer: `top`

2. **Which command will show you the memory usage in a human-readable format?**
   - Answer: `free -h`

Review these commands and their options thoroughly. Understanding these will give you a strong foundation in process management and system monitoring. Happy learning!
