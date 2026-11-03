# Day 14 · Dinner — Week 2 Review: Kernel Modules, Sysctl & Network Bonding

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 2 (System Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 2 → Day 14 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/14` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-14 && cd /tmp/linux-dojo-day-14` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 14 (Dinner Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Kernel Modules Management

This lesson revisits the critical concepts of managing kernel modules, which are essential for extending the functionality of the Linux kernel. You'll learn how to load modules using `modprobe` and `insmod`, unload them with `rmmod`, and query loaded modules with `lsmod`. Understanding kernel parameters is crucial as they dictate the behavior of the kernel. You'll explore how to view and modify these parameters on the fly using `sysctl`, and learn the impact of these changes on system performance and security.

Real-world scenarios include enabling specific hardware support by loading necessary modules and troubleshooting kernel issues by examining and adjusting kernel parameters. This knowledge ensures you're equipped to manage and troubleshoot the core of the Linux operating system effectively.

## 2. Advanced Network Configurations

In this lesson, we dive deep into advanced network configurations, essential for optimizing and troubleshooting complex network environments. You will review IP addressing schemes, including subnetting and CIDR notation, and learn how to set up static IPs using the `ip` comman. We also cover static routing, where you'll configure routes manually to direct network traffic efficiently, using commands like `ip route add`.

Troubleshooting network issues is a critical skill, and you'll get hands-on experience with tools such as `ping`, `traceroute`, and `netstat`. By the end of this lesson, you should be able to diagnose and resolve network issues, configure advanced network settings, and optimize network performance in a Linux environment.

## 3. Shell Scripting Mastery

This lesson serves as the final review of advanced shell scripting techniques, where we consolidate all you've learned about creating powerful and efficient scripts. You'll delve into using loops (`for`, `while`, `until`) to automate repetitive tasks and conditional statements (`if`, `case`) to make your scripts more dynamiFunctions, which allow you to modularize your scripts, will also be a focus, enabling you to write more maintainable and reusable code.

Practical examples include writing scripts to automate system administration tasks, such as backups, user management, and log rotation. By mastering these techniques, you'll be able to create robust scripts that can handle complex tasks with ease, making you a more efficient and effective system administrator.

## 4. System Security and Hardening

This lesson reinforces the best practices for securing a Linux system, focusing on user management, file permissions, and implementing security policies. You'll learn how to manage users and groups effectively, ensuring that only authorized personnel have access to sensitive files and directories. File permissions, managed using the `chmod`, `chown`, and `chgrp` commands, are fundamental to Linux security, and you'll gain a deep understanding of how to apply them correctly.

In addition, the lesson covers advanced security policies using tools like SELinux and AppArmor. You'll explore how to configure and enforce security policies that restrict the actions of processes, enhancing your system's security posture. Practical exercises will guide you through hardening your system against common threats, ensuring that your Linux environment is as secure as possible.

---

## Self-Check Quiz & Verification

**1. How do you load a kernel module in Linux?**
- A) `insmod`
- B) `modprobe`
- C) `lsmod`
- D) `rmmod`
- **Correct Answer:** `modprobe`

**2. Which tool is used to trace the path packets take to a destination?**
- A) `traceroute`
- B) `ping`
- C) `netstat`
- D) `ifconfig`
- **Correct Answer:** `traceroute`

**3. Which command is used to create a loop in a shell script?**
- A) `for`
- B) `while`
- C) `until`
- D) `All of the above`
- **Correct Answer:** `All of the above`

**4. How do you check the status of SELinux?**
- A) `sestatus`
- B) `semanage`
- C) `getenforce`
- D) `. setenforce`
- **Correct Answer:** `sestatus`

**5. Which command is used to configure static routes?**
- A) `ip route add`
- B) `route -n`
- C) `ifconfig`
- D) `arp`
- **Correct Answer:** `ip route add`

**6. What is the primary function of `chmod`?**
- A) `Change file permissions`
- B) `Change file ownership`
- C) `Compress files`
- D) `Display file contents`
- **Correct Answer:** `Change file permissions`

**7. Which command can be used to unload a kernel module?**
- A) `rmmod`
- B) `modprobe`
- C) `lsmod`
- D) `. dmesg`
- **Correct Answer:** `rmmod`

**8. What command would you use to view the routing table in Linux?**
- A) `ip route show`
- B) `netstat -r`
- C) `route -n`
- D) `traceroute`
- **Correct Answer:** `ip route show`

**9. Which SELinux mode restricts access based on security policies?**
- A) `Enforcing`
- B) `Permissive`
- C) `Disabled`
- D) `Monitoring`
- **Correct Answer:** `Enforcing`

**10. How do you make a shell script executable?**
- A) `chmod +x scriptname`
- B) `chown scriptname`
- C) `cp scriptname`
- D) `ls -l scriptname`
- **Correct Answer:** `chmod +x scriptname`
