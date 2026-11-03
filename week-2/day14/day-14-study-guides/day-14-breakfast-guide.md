# Day 14 · Breakfast — Week 2 Review: Kernel Modules, Sysctl & Network Bonding

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 2 (System Ops)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `modprobe`, `lsmod`, `rmmod`, `sysctl`, `uname -r`, `fsck`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // PROCESS, KERNEL & NETWORK OPERATIONS PIPELINE          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║  ┌─────────────────┐    fork() / execve()    ┌────────────────────────────┐  ║
║  │  PID 1: systemd │ ──────────────────────► │  Active Daemons & Tasks    │  ║
║  └────────┬────────┘                         │  • nice / renice [-20..19] │  ║
║           │                                  │  • SIGTERM(15) / SIGKILL(9)│  ║
║           ▼                                  └─────────────┬──────────────┘  ║
║  ┌─────────────────┐    /proc & sysctl       ┌─────────────▼──────────────┐  ║
║  │ Kernel Modules  │ ◄─────────────────────► │ Network & Storage Stack    │  ║
║  │ lsmod / modprobe│                         │ ip route • ss • /etc/fstab │  ║
║  └─────────────────┘                         └────────────────────────────┘  ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 2 → Day 14 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/14` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-14 && cd /tmp/linux-dojo-day-14` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 14 (Breakfast Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Advanced Shell Scripting

In this module, we explored advanced techniques in shell scripting to enhance automation. We delved into the use of loops (`for`, `while`, `until`) for automating repetitive tasks, which is crucial in systems administration. Functions were introduced to modularize scripts, making them more organized and easier to maintain. For example, defining a function to check disk space can be reused across multiple scripts.

We also covered regular expressions, which are powerful for text processing and extracting data from logs. Understanding and using tools like `sed`, `awk`, and `grep` within scripts enables complex data manipulation. For instance, using `grep` with regular expressions to filter log entries or `awk` to format output data. Error handling with conditional statements (`if`, `else`, `elif`) and debugging techniques (`set -x`, `trap`) were also emphasized to ensure scripts run reliably in different environments.

## 2. Linux Filesystem Management

This lesson focused on the crucial aspects of managing Linux filesystems. We covered mounting and unmounting filesystems, understanding how the `mount` command works, and the significance of the `/etc/fstab` file for persistent mounts. Users practiced checking filesystem integrity using the `fsck` command, which is essential for diagnosing and repairing filesystem issues.

We also explored different filesystem types like ext4, XFS, and Btrfs, discussing their use cases and performance implications. Understanding the Linux Filesystem Hierarchy Standard (FHS) helped in navigating and managing the directory structure. Examples included creating and resizing partitions using `fdisk` and `parted`, managing disk quotas to allocate disk space efficiently, and optimizing filesystem performance using `tune2fs` and other tools.

## 3. Linux Kernel Basics

The Linux kernel is the core component of the operating system, and understanding its operations is key for any system administrator. We covered how to manage kernel modules using `modprobe` to load and unload modules dynamically. This is useful for adding hardware support or network drivers without rebooting the system. For instance, loading a new network driver can be done using `modprobe <module_name>`.

We also discussed modifying kernel parameters using the `sysctl` command, which allows runtime configuration of the kernel without the need to edit system files directly. Understanding kernel versioning through `uname -r` was crucial for knowing which kernel version is in use, especially when applying patches or updates. Additionally, the lesson covered the role of `initramfs` in the boot process and how to compile custom kernels, providing flexibility for specialized tasks or hardware support.

## 4. Advanced Network Configuration

This lesson delved into the complexities of network configuration on Linux systems. We explored both static and dynamic IP configurations, learning how to configure network interfaces manually through `/etc/network/interfaces` or using `nmcli` for NetworkManager-controlled systems. Configuring DHCP servers and clients was also covered, with examples of setting up a DHCP server using `isc-dhcp-server`.

We discussed network interface bonding, which is a technique to combine multiple network interfaces to increase bandwidth or provide redundancy. The `ifenslave` tool was introduced for this purpose, with examples of configuring active-backup and load-balancing modes. Additionally, we covered network performance optimization techniques, such as adjusting TCP window sizes with `sysctl` settings, and introduced advanced troubleshooting tools like `tcpdump` for packet analysis and `netstat` for monitoring network connections.

## 5. System Administration Best Practices

Effective system administration requires adhering to best practices, and this lesson provided a comprehensive overview. We started with system monitoring tools like `top`, `htop`, and `vmstat`, emphasizing the importance of regular monitoring to detect and resolve performance issues. Practical exercises included using these tools to monitor CPU, memory, and I/O performance in real-time.

Backup and recovery strategies were also discussed, with hands-on practice using `rsync` for incremental backups, `tar` for archiving files, and `dd` for creating disk images. Security best practices were emphasized, including regular updates, user management, and the use of firewalls like `ufw` or `iptables`. The lesson also highlighted the importance of documentation, scripting for automation, and ongoing education to stay current with evolving technologies and threats.

---

## Self-Check Quiz & Verification

**1. What command is used to check filesystem integrity?**
- A) `fsck`
- B) `top`
- C) `uname`
- D) `tar`
- **Correct Answer:** `fsck`

**2. Which tool is used to load kernel modules?**
- A) `modprobe`
- B) `lsmod`
- C) `top`
- D) `htop`
- **Correct Answer:** `modprobe`

**3. How do you bond network interfaces?**
- A) `ifenslave`
- B) `top`
- C) `uname`
- D) `vmstat`
- **Correct Answer:** `ifenslave`

**4. Which command is used to monitor system performance?**
- A) `top`
- B) `tar`
- C) `cp`
- D) `chmod`
- **Correct Answer:** `top`

**5. Which command creates a backup using rsync?**
- A) `rsync -avz /source/ /destination/`
- B) `cp /source/ /destination/`
- C) `tar -cvf /source/ /destination/`
- D) `dd if=/source/ of=/destination/`
- **Correct Answer:** `rsync -avz /source/ /destination/`

**6. What is the purpose of the /etc/fstab file?**
- A) `To define filesystems to be mounted at boot`
- B) `To list all installed packages`
- C) `To configure network interfaces`
- D) `To manage user accounts`
- **Correct Answer:** `To define filesystems to be mounted at boot`

**7. Which command is used to create a partition on a disk?**
- A) `fdisk`
- B) `fsck`
- C) `dd`
- D) `tar`
- **Correct Answer:** `fdisk`

**8. What command displays kernel version information?**
- A) `uname -r`
- B) `top`
- C) `modprobe`
- D) `lsmod`
- **Correct Answer:** `uname -r`

**9. How do you apply a runtime kernel parameter?**
- A) `sysctl -w <parameter>=<value>`
- B) `echo <parameter> > /proc/sys/<parameter>`
- C) `modprobe <module>`
- D) `update-grub`
- **Correct Answer:** `sysctl -w <parameter>=<value>`
