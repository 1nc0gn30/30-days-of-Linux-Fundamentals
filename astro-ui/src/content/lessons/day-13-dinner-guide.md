# Day 13 Dinner: System Monitoring and Performance Tuning

In this session, we will delve into System Monitoring and Performance Tuning. We'll explore various tools and techniques to monitor system performance and optimize system resources.

## Lessons

### 1. Introduction to System Monitoring

System monitoring is crucial for understanding how your system is performing and identifying potential issues. Key areas include:

- **CPU Usage:** Monitor how much CPU is being used by processes.
- **Memory Usage:** Track the amount of RAM being used and available.
- **Disk Usage:** Check how much disk space is being used and how much is available.
- **Network Usage:** Observe the amount of data being sent and received over the network.

### 2. Using `top` for Real-Time Monitoring

`top` is a powerful tool for monitoring system performance in real-time.

**Commands:**
- To launch `top`: 
  ```bash
  top
To sort by CPU usage: Press Shift + P
To sort by memory usage: Press Shift + M
To exit top: Press q
The top command provides a dynamic view of the system's resource usage and can help identify processes consuming excessive resources.

3. Monitoring System Performance with vmstat
vmstat reports virtual memory statistics and provides insight into system performance.

Commands:

To display system statistics:
bash
Copy code
vmstat
To report statistics every 5 seconds:
bash
Copy code
vmstat 5
Key Metrics:

procs: Information on processes, including run queues.
memory: Memory usage, including free, used, and buffer/cache.
swap: Swap space usage.
io: I/O activity, including read and write operations.
system: System activity, including interrupts and context switches.
cpu: CPU usage breakdown.
4. Analyzing Disk Usage with iostat
iostat provides statistics on CPU and I/O usage for devices and partitions.

Commands:

To display I/O statistics:
bash
Copy code
iostat
To report statistics every 5 seconds:
bash
Copy code
iostat 5
Key Metrics:

%user: CPU time spent in user space.
%system: CPU time spent in kernel space.
%iowait: CPU time waiting for I/O operations.
tps: Transactions per second (I/O operations).
kB_read/s: Kilobytes read per second.
kB_wrtn/s: Kilobytes written per second.
5. Network Monitoring with netstat
netstat displays network connections, routing tables, and interface statistics.

Commands:

To display network connections:
bash
Copy code
netstat
To display network interfaces:
bash
Copy code
netstat -i
To display listening ports:
bash
Copy code
netstat -l
To display routing table:
bash
Copy code
netstat -r
Key Metrics:

Proto: Protocol (TCP/UDP).
Recv-Q: Receive queue size.
Send-Q: Send queue size.
Local Address: Local IP address and port.
Foreign Address: Remote IP address and port.
State: Connection state (e.g., ESTABLISHED, LISTEN).
6. Using sar for Historical Data
sar collects, reports, and saves system activity information.

Commands:

To display CPU usage:
bash
Copy code
sar -u
To display memory usage:
bash
Copy code
sar -r
To display network activity:
bash
Copy code
sar -n DEV
To display I/O statistics:
bash
Copy code
sar -b
To collect data every 10 seconds for 1 minute:
bash
Copy code
sar -u 10 6
Key Metrics:

%usr: CPU time spent in user space.
%sys: CPU time spent in kernel space.
%idle: CPU idle time.
kbmemfree: Free memory (kilobytes).
kbswpfree: Free swap space (kilobytes).
rxpck/s: Packets received per second.
txpck/s: Packets transmitted per second.
7. Performance Tuning Tips
Performance tuning involves optimizing system parameters to improve efficiency.

Tips:

CPU Tuning: Adjust CPU scheduling policies and prioritize processes.
Memory Tuning: Configure swap space, adjust cache sizes, and manage memory limits.
Disk Tuning: Optimize file systems, use appropriate RAID levels, and defragment disks if necessary.
Network Tuning: Adjust network interface settings, optimize network stack parameters, and manage network bandwidth.
Regular Maintenance: Keep your system updated, monitor logs for issues, and perform regular backups.
Questions
Which command is used to monitor real-time CPU and memory usage?

A. top
B. vmstat
C. iostat
D. sar
Correct Answer: A. top

What does vmstat provide information on?

A. Disk I/O
B. Network Traffic
C. Memory Usage
D. Process Information
Correct Answer: C. Memory Usage

What command is used to analyze disk I/O?

A. netstat
B. sar
C. iostat
D. top
Correct Answer: C. iostat

Which tool provides historical performance data?

A. top
B. vmstat
C. netstat
D. sar
Correct Answer: D. sar

How can you check the amount of data received over the network?

A. netstat -i
B. sar -n DEV
C. iostat
D. vmstat
Correct Answer: B. sar -n DEV

What is a key metric reported by iostat?

A. %usr
B. %idle
C. kB_read/s
D. %sys
Correct Answer: C. kB_read/s