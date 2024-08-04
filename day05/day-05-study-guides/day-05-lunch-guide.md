# Day 5 Lunch Study Guide: Advanced Processes and System Monitoring

Welcome to Day 5 Lunch! Today, we will dive deeper into advanced process management and system monitoring techniques. We'll cover enhanced commands, filtering and customizing output, and analyzing system logs.

## Advanced Process Management (`htop`, `pstree`)

- **Description**: `htop` and `pstree` offer more detailed and interactive ways to view processes and their hierarchies.
- **Basic Usage**:
  - `htop` - Launch an interactive, color-coded process viewer. You can navigate using arrow keys and manage processes interactively.
  - `pstree` - Display processes in a tree-like format, showing parent-child relationships.
- **Advanced Usage**:
  - `htop -u username` - Filter `htop` to show processes for a specific user.
  - `pstree -p` - Include process IDs in the tree view.
  - `htop -d 10` - Set `htop` to update every 10 seconds.

## Detailed Resource Monitoring (`sar`, `atop`)

- **Description**: `sar` collects and reports system activity, while `atop` provides detailed historical performance data.
- **Basic Usage**:
  - `sar -u 5 3` - Report CPU usage every 5 seconds for 3 iterations.
  - `sar -r` - Display memory usage statistics.
  - `atop` - Start `atop` for real-time and historical performance monitoring.
- **Advanced Usage**:
  - `atop -r` - Read from `atop` logs for historical analysis.
  - `sar -q` - Report queue length and system load.

## Customizing Output (`grep`, `awk`, `sed`)

- **Description**: Use `grep`, `awk`, and `sed` to filter, format, and manipulate command output for analysis.
- **Basic Usage**:
  - `grep 'pattern'` - Search for lines matching 'pattern' in command output.
  - `awk '{print $1, $2}'` - Format output by extracting specific columns.
  - `sed 's/old/new/'` - Replace occurrences of 'old' with 'new' in output.
- **Advanced Usage**:
  - `top -b -n 1 | grep 'PID'` - Filter `top` output to show only lines containing 'PID'.
  - `ps aux | awk '{print $1, $11}'` - Display user and command name from `ps` output.
  - `vmstat 5 | grep 'procs'` - Filter `vmstat` output to show only lines containing 'procs'.

## Analyzing Logs (`logwatch`, `syslog`)

- **Description**: `logwatch` summarizes system logs, and `syslog` provides a standardized way to log system messages.
- **Basic Usage**:
  - `logwatch --detail high --service all` - Generate a detailed log report for all services.
  - `tail -f /var/log/syslog` - Continuously monitor the syslog file for new messages.
- **Advanced Usage**:
  - `logwatch --range 'yesterday'` - Report on logs from the previous day.
  - `tail -f /var/log/messages` - Monitor general system messages.

## System Performance (`perf`, `dstat`)

- **Description**: `perf` and `dstat` are tools for performance analysis and monitoring.
- **Basic Usage**:
  - `perf top` - Real-time performance monitoring and profiling.
  - `dstat -cdngy` - Display CPU, disk, network, and system statistics.
- **Advanced Usage**:
  - `perf record -e cpu-clock -a sleep 10` - Record performance data for 10 seconds.
  - `dstat --vm --io` - Show VM and I/O statistics.

## Key Takeaways

- **`htop`**: An interactive tool for viewing processes, allowing real-time management and filtering.
- **`pstree`**: Visualizes processes and their hierarchy, helping understand parent-child relationships.
- **`sar`**: Collects and reports detailed system activity, useful for performance analysis over time.
- **`atop`**: Provides comprehensive monitoring of system resources, including historical data.
- **`grep`, `awk`, `sed`**: Essential tools for filtering, formatting, and manipulating command output for deeper analysis.
- **`logwatch`**: Summarizes and analyzes system logs, helping in quick reviews of system activities.
- **`syslog`**: A standard for logging system messages, crucial for monitoring and troubleshooting.
- **`perf`**: Performance profiling tool that helps analyze and optimize system performance.
- **`dstat`**: Provides versatile resource monitoring, offering real-time insights into system performance.

By mastering these commands and techniques, you'll gain a comprehensive understanding of process management and system monitoring, enabling you to effectively analyze and troubleshoot system performance issues.

Happy learning and exploring!

