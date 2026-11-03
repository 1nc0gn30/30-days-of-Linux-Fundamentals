# Day 14 · Lunch — Week 2 Review: Kernel Modules, Sysctl & Network Bonding

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 2 (System Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 2 → Day 14 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/14` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-14 && cd /tmp/linux-dojo-day-14` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 14 (Lunch Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Shell Scripting Techniques (Advanced)

This lesson builds on your previous scripting knowledge, diving into advanced concepts that can significantly enhance your scripts. We explore process control using commands like `wait`, `trap`, and `disown` to manage background jobs and signals effectively. Understanding file descriptors is key for redirecting output and errors to different destinations using `>&`, `2>&1`, and other redirection operators. Signal handling allows your scripts to respond to system signals, ensuring proper cleanup or action when they receive signals like `SIGINT` or `SIGTERM`.

Examples include creating scripts that monitor and control long-running processes, handling errors gracefully, and ensuring your scripts are robust even in unexpected situations. Practicing with signals and redirection will make your scripts more reliable and flexible in real-world scenarios.

## 2. Kernel Management

Interacting with the Linux kernel is a critical skill for system administrators. This lesson covers how to manage kernel modules dynamically using `modprobe` and `rmmod`, allowing you to add or remove functionality without rebooting the system. Understanding how to view and modify kernel parameters at runtime using `sysctl` is also crucial. For example, you might need to adjust network settings or change security parameters on the fly to meet specific requirements.

We also cover managing kernel versions, including how to identify your current kernel version with `uname -r` and the steps required to upgrade or downgrade your kernel. The lesson provides examples of compiling custom kernels and configuring `GRUB` to boot into different kernel versions, ensuring you're prepared for advanced system customization.

## 3. Network Configuration (Advanced)

This lesson takes your network configuration skills to the next level by focusing on complex IP configurations, static routes, and VLAN management. Configuring static routes using the `ip route add` command allows you to control the path packets take through a network, which is essential in multi-homed systems or when managing traffic across different networks. VLAN management using tools like `vconfig` enables segmentation of network traffic for better security and performance.

Practical exercises include setting up and testing static routes, configuring VLANs on network interfaces, and understanding how these configurations affect network traffic and security. This knowledge is critical for managing large or complex network environments where precise control over routing and segmentation is required.

## 4. System Security Enhancements

System security is paramount, and this lesson introduces additional measures to harden your Linux environment. We explore SELinux and AppArmor, two mandatory access control (MAC) systems that enforce security policies at the kernel level. You'll learn how to manage SELinux policies using `semanage` and `setsebool`, and how to troubleshoot security issues with `audit2why`. Similarly, AppArmor's profiles can be adjusted using `aa-complain` and `aa-enforce`, helping you control application behavior.

We also cover hardening SSH by disabling root login, changing the default SSH port, and configuring key-based authentication. Finally, setting up automatic security updates with `unattended-upgrades` ensures your system stays secure without manual intervention. These enhancements are essential for reducing the attack surface and protecting your systems from unauthorized access.

---

## Self-Check Quiz & Verification

**1. What is the command to display currently loaded kernel modules?**
- A) `A. lsmod`
- B) `B. modinfo`
- C) `C. modprobe`
- D) `D. rmmod`
- **Correct Answer:** `lsmod`

**2. Which command would you use to set a kernel parameter at runtime?**
- A) `A. sysctl`
- B) `B. modprobe`
- C) `C. top`
- D) `D. uname`
- **Correct Answer:** `sysctl`

**3. How do you add a static route in Linux?**
- A) `A. ip route add`
- B) `B. ifconfig`
- C) `C. netstat -r`
- D) `D. route -n`
- **Correct Answer:** `ip route add`

**4. What is the command to manage SELinux policies?**
- A) `A. semanage`
- B) `B. chcon`
- C) `C. setenforce`
- D) `D. sestatus`
- **Correct Answer:** `semanage`

**5. Which command hardens SSH by disabling root login?**
- A) `A. PermitRootLogin no in /etc/ssh/sshd_config`
- B) `B. sudo ufw disable`
- C) `C. sudo systemctl disable sshd`
- D) `D. sudo iptables -A INPUT -p tcp --dport 22 -j DROP`
- **Correct Answer:** `PermitRootLogin no in /etc/ssh/sshd_config`

**6. How do you change the default SSH port?**
- A) `A. Edit /etc/ssh/sshd_config and change the Port directive`
- B) `B. Use iptables to block port 22`
- C) `C. Disable SSH and enable Telnet`
- D) `D. Set SSH_PORT environment variable`
- **Correct Answer:** `Edit /etc/ssh/sshd_config and change the Port directive`

**7. Which command is used to compile a new kernel?**
- A) `A. make`
- B) `B. gcc`
- C) `C. ld`
- D) `D. nm`
- **Correct Answer:** `make`

**8. What tool is used to manage VLANs on Linux?**
- A) `A. vconfig`
- B) `B. ifconfig`
- C) `C. iptables`
- D) `D. brctl`
- **Correct Answer:** `vconfig`

**9. How do you view and modify network routes?**
- A) `A. ip route show`
- B) `B. lsmod`
- C) `C. netstat -r`
- D) `D. traceroute`
- **Correct Answer:** `ip route show`
