# Day 12 Breakfast: Linux Kernel Basics

Welcome to Day 12 Breakfast! Today, we'll explore the fundamentals of the Linux kernel. Understanding the kernel is crucial for mastering Linux system administration and development. In this session, we'll cover kernel modules, kernel parameters, and kernel versioning.

## Lesson Overview

### 1. **Introduction to the Linux Kernel**

**Description:** 
The Linux kernel is the core component of a Linux operating system, managing hardware, system resources, and providing essential services. It acts as an intermediary between the hardware and user applications.

**Key Concepts:**
- **Kernel Architecture:** Monolithic kernel with modules.
- **Responsibilities:** Hardware abstraction, process management, memory management, device drivers, and system calls.

**Commands:**
- **Check the kernel version:**
```bash
  unKernel Modules
```
**Description:**
Kernel modules are pieces of code that can be loaded into the kernel as needed. They extend the functionality of the kernel without requiring a reboot.

**Key Concepts:**

Module Loading: Dynamically add functionalities such as device drivers.
**Commands:**
List loaded modules:
```bash
lsmod
```
Load a module:
```bash
sudo modprobe <module_name>
```
Remove a module:
```bash
sudo rmmod <module_name>
```
**Example:** Load the usb_storage module to enable USB storage support.

3. Kernel Parameters
**Description:**
Kernel parameters are settings that control various aspects of the kernel's behavior. They can be configured at boot time or during runtime.

**Key Concepts:**

Boot Parameters: Passed to the kernel during system startup.
Runtime Parameters: Modified using sysctl.
**Commands:**

View current parameters:
```bash
sysctl -a
```
Set a parameter:
```bash
sudo sysctl -w <parameter>=<value>
```
Persistent changes: Edit /etc/sysctl.conf and apply changes:
```bash
sudo sysctl -p
```
**Example:** Adjust vm.swappiness to control how aggressively the kernel swaps memory pages.

4. Kernel Versioning
**Description:**
Kernel versioning helps in identifying the version of the kernel running on your system, which is important for compatibility and troubleshooting.

**Key Concepts:**

Version Format: major.minor.patch
**Commands:**
Check kernel version:
```bash
uname -r
```
Check detailed kernel information:
```bash
uname -a
```
**Example:** Verify kernel version compatibility with hardware drivers or software requirements.

### Practice Commands
Check your current kernel version.
List all loaded kernel modules.
Load and then remove a dummy module (e.g., dummy).
View and set a kernel parameter, such as net.ipv4.ip_forward.
Edit /etc/sysctl.conf to make a persistent change to a kernel parameter.
Conclusion

**In this Breakfast session, you've learned about the core components of the Linux kernel, how to work with kernel modules, configure kernel parameters, and understand kernel versioning. These fundamentals are essential for effective Linux system administration and development.**

- Feel free to experiment with the commands and configurations provided to deepen your understanding of the Linux kernel. Prepare for the next lesson as we continue to build on these concepts.