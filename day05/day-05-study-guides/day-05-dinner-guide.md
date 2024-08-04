## Day 5 Dinner: Advanced Processes and System Monitoring

Welcome to Day 5 Dinner! Tonight, we'll build upon the concepts covered in breakfast and lunch, and dive even deeper into advanced process management and system monitoring. This session will review the topics covered earlier and introduce new techniques and tools to further enhance your understanding.
Dinner Agenda:

    Review of Breakfast and Lunch Topics
    Advanced Process Control
    In-Depth System Monitoring Techniques
    Hands-On Advanced Challenges

Detailed Overview and Advanced Topics
1. Review of Breakfast and Lunch Topics

Breakfast Review:

    Process Management: Covered ps, top, htop, and pstree for viewing and managing processes. Focused on real-time monitoring and process filtering.

Lunch Review:

    System Resource Monitoring: Examined sar for historical data and atop for real-time metrics. Also, discussed output customization with grep, awk, and sed.

2. Advanced Process Control

Advanced kill and pkill:

    Process Signals: Learn more about different signals you can send with kill. For example, SIGSTOP to pause a process and SIGCONT to resume it.
    Using pkill with Patterns: You can use regular expressions with pkill to match process names more flexibly.

Examples:

bash

kill -STOP 1234           # Pause process with PID 1234
kill -CONT 1234           # Resume process with PID 1234
pkill -f 'java.*'         # Kill all processes matching 'java.*' pattern
pkill -9 -f 'pattern'    # Force kill processes matching 'pattern'

Process Priorities with nice and renice:

    nice: Launch processes with adjusted priority.
    renice: Change the priority of already running processes.

Examples:

bash

nice -n 10 command        # Run 'command' with a nice value of 10
renice -n -5 -p 1234      # Change priority of process with PID 1234 to -5

3. In-Depth System Monitoring Techniques

Advanced sar Usage:

    Custom Reports: Generate specific reports for CPU, memory, and network usage using sar.
    Combining Metrics: Use sar to combine multiple metrics into a single report.

Examples:

bash

sar -u 1 3                # Report CPU usage every 1 second for 3 times
sar -r 1 3                # Report memory usage every 1 second for 3 times
sar -n DEV 1 3            # Report network statistics every 1 second for 3 times

Enhanced atop Features:

    Historical Data Analysis: Analyze data collected by atop for historical performance insights.
    Using atop Filters: Apply filters to focus on specific types of resources.

Examples:

bash

atop -r /var/log/atop/atop.log   # Read from atop log file
atop -b -n 10                    # Display real-time stats for 10 seconds

Customizing dstat:

    Combining Metrics: Use dstat to show combined metrics such as CPU, memory, disk I/O, and network.

Examples:

bash

dstat -cdngyt                  # Display CPU, disk, network, and system stats with timestamps
dstat --top-cpu                # Show the top processes by CPU usage

4. Hands-On Advanced Challenges

Challenge 1: Advanced Process Control

    Task: Use htop to identify and renice the top 3 processes consuming the most CPU. Save the output to a file.
    Command:

bash

htop
# In `htop`, sort by CPU usage, renice the top 3 processes, and save output using a screen capture or `htop` command options

Challenge 2: Comprehensive sar Report

    Task: Collect CPU, memory, and network usage data using sar and generate a report combining these metrics.
    Commands:

bash

sar -u 1 3 > cpu_usage.txt
sar -r 1 3 > mem_usage.txt
sar -n DEV 1 3 > net_usage.txt
cat cpu_usage.txt mem_usage.txt net_usage.txt

Challenge 3: Analyzing atop Logs

    Task: Review atop logs for CPU and memory usage spikes and identify any anomalies.
    Commands:

bash

atop -r /var/log/atop/atop.log
