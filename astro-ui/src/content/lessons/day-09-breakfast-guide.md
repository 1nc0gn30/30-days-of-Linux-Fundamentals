# Day 09 Breakfast: System Performance Tuning

## Overview
In this session, we'll explore system performance tuning techniques. We'll learn about optimizing system settings to improve performance, including CPU scheduling, memory management, disk I/O optimization, and network performance.

## Lesson 1: System Performance Tuning

### Description
System performance tuning involves optimizing system settings to enhance performance. Key areas to focus on include:

- **CPU Scheduling**: Prioritizing tasks to ensure efficient CPU utilization and responsiveness.
- **Memory Management**: Optimizing memory usage to avoid issues like swapping and fragmentation.
- **Disk I/O Optimization**: Improving disk operation performance (read/write speeds).
- **Network Performance**: Optimizing network throughput and reducing latency.

Effective tuning can help in achieving better responsiveness, efficiency, and overall system stability. This is especially critical in environments where consistent performance is a priority, such as servers, databases, or high-performance computing clusters.

### Examples of Tuning Commands
1. **View CPU usage**: `top` or `htop`
2. **Adjust swappiness**: `sysctl vm.swappiness=10`
3. **Monitor disk I/O**: `iostat`
4. **Network tuning**: `ethtool`, `sysctl net.ipv4.tcp_congestion_control`

For more detailed information, consult resources like the [Linux Performance Tuning Guide](https://www.redhat.com/en/resources/linux-performance-tuning-guide).

---

## Lesson 2: CPU Scheduling

### Description
CPU scheduling is the process by which the operating system determines which tasks (processes) should be executed by the CPU. This involves prioritizing tasks to ensure efficient CPU utilization and responsiveness.

Different scheduling algorithms (such as FIFO, Round Robin, and Completely Fair Scheduler) manage processes based on their priority and required resources. Understanding these algorithms helps in selecting the right scheduling policy for specific workloads, leading to optimized system performance and balanced CPU load.

### Examples of Tuning Commands
1. **Check CPU scheduling policy**: `chrt -p [PID]`
2. **Change scheduling policy**: `chrt -f -p [PRI] [PID]`
3. **View process priority**: `ps -eo pid,ni,comm`

For more insights, review the [Linux Kernel Documentation on Scheduling](https://www.kernel.org/doc/html/latest/scheduler/index.html).

---

## Lesson 3: Memory Management

### Description
Memory management involves optimizing the use of system memory to improve performance and avoid issues like swapping and fragmentation. Techniques include adjusting the swappiness parameter, monitoring memory usage, and configuring swap space effectively.

Proper memory management helps prevent memory bottlenecks, reduces the likelihood of system slowdowns, and ensures that critical applications have enough memory resources to function efficiently.

### Examples of Tuning Commands
1. **View memory usage**: `free -h`
2. **Adjust swappiness**: `sysctl vm.swappiness=10`
3. **Check swap usage**: `swapon --show`

For a deeper understanding, refer to the [Linux Memory Management documentation](https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html).

---

## Lesson 4: Disk I/O Optimization

### Description
Disk I/O optimization focuses on improving the performance of disk operations, such as read and write speeds. This involves monitoring disk performance, optimizing file systems, and adjusting parameters related to I/O operations.

Effective disk I/O optimization ensures faster data access, reduced latency in read/write operations, and extended disk lifespan, especially in environments with heavy disk usage, such as database servers or data processing applications.

### Examples of Tuning Commands
1. **Monitor disk I/O**: `iostat -x`
2. **Check file system performance**: `tune2fs -l [device]`
3. **Adjust I/O scheduler**: `echo 'deadline' > /sys/block/[device]/queue/scheduler`

For additional resources, explore the [Disk I/O Tuning Guide](https://www.redhat.com/en/resources/disk-io-tuning-guide).

---

## Lesson 5: Network Performance

### Description
Network performance tuning aims to optimize network throughput and reduce latency. This includes configuring network interfaces, adjusting TCP settings, and monitoring network traffic.

Network tuning is crucial in environments where data transfer speed and reliability are critical, such as web servers, cloud services, and distributed applications. Proper tuning can lead to improved network reliability, faster data transfer rates, and reduced packet loss.

### Examples of Tuning Commands
1. **Check network interfaces**: `ifconfig` or `ip a`
2. **Adjust TCP congestion control**: `sysctl net.ipv4.tcp_congestion_control=reno`
3. **Monitor network traffic**: `iftop` or `nload`

For more detailed guidance, check the [Network Performance Tuning documentation](https://www.redhat.com/en/resources/network-performance-tuning-guide).

---

## Multiple-Choice Questions

1. **What is the purpose of adjusting the `vm.swappiness` parameter?**
    - A. Increase CPU usage
    - B. Reduce disk usage
    - C. Control memory swapping
    - D. Optimize network speed
    - **Correct Answer:** C

2. **How can you view real-time CPU usage on a Unix-based system?**
    - A. `top`
    - B. `free`
    - C. `df`
    - D. `iostat`
    - **Correct Answer:** A

3. **What command can be used to monitor disk I/O performance?**
    - A. `top`
    - B. `iostat`
    - C. `free`
    - D. `vmstat`
    - **Correct Answer:** B

4. **What is the effect of changing the network congestion control algorithm?**
    - A. Adjusts CPU scheduling
    - B. Modifies disk I/O priority
    - C. Affects TCP transmission rate
    - D. Controls memory allocation
    - **Correct Answer:** C

5. **How do you check the current I/O scheduler for a disk device?**
    - A. `sysctl`
    - B. `iostat`
    - C. `chrt`
    - D. `cat /sys/block/[device]/queue/scheduler`
    - **Correct Answer:** D


## Happy coding!!