# Day 12 Lunch: Linux Kernel Basics

Welcome to Day 12 Lunch! In this session, we'll delve deeper into the Linux kernel. We will cover more advanced aspects of kernel modules, kernel parameters, and kernel versioning. By the end of this lesson, you should have a solid understanding of these concepts and how to apply them practically.

## Lesson Overview

### 1. **Understanding Kernel Modules**

**Description:**  
Kernel modules are pieces of code that can be loaded into the kernel as needed. They help extend the kernel's functionality without requiring a system reboot. Modules can include device drivers, file systems, or system calls.

**Detailed **Steps:****
1. **View Loaded Modules:**
   - **Command:** `lsmod`
   - **Description:** Lists all currently loaded kernel modules.
2. **Load a Module:**
   - **Command:** `sudo modprobe <module_name>`
   - **Description:** Dynamically loads the specified module into the kernel.
3. **Unload a Module:**
   - **Command:** `sudo modprobe -r <module_name>`
   - **Description:** Unloads the specified module from the kernel.
4. **Check Module Information:**
   - **Command:** `modinfo <module_name>`
   - **Description:** Displays detailed information about a module.

**Example Commands:**
```bash
lsmod
sudo modprobe usb_storage
sudo modprobe -r usb_storage
modinfo usb_storage
```

2. Building and Installing Kernel Modules
**Description:**
Creating custom kernel modules involves writing code in C, compiling it, and loading it into the kernel. This allows you to add functionality tailored to specific needs.

**Steps:**

Write a Kernel Module:
File: hello.c
Example Code:
```c
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    printk(KERN_INFO "Hello, Kernel World!\n");
    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Goodbye, Kernel World!\n");
}

MODULE_LICENSE("GPL");

```
Compile the Module:
**Command:** 
```bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
```
**Description:** Uses the kernel build system to compile the module.
Load the Module:
**Command:** 
```bash
sudo insmod hello.ko
```
**Description:** Inserts the compiled module into the kernel.
Remove the Module:
**Command:** sudo rmmod hello
**Description:** Removes the module from the kernel.
**Example Commands:**

```bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
sudo insmod hello.ko
sudo rmmod hello
```

3. Kernel Parameters and Sysctl
**Description:**
Kernel parameters control various aspects of the kernel's operation. These parameters can be adjusted at boot time or dynamically using the sysctl command.

Common Parameters:

fs.file-max: Maximum number of file descriptors.
kernel.pid_max: Maximum number of process IDs.
vm.swappiness: Tendency to swap memory.
**Commands:**

View Parameters:
**Command:** 
```bash
sysctl -a
```
Set a Parameter:
**Command:** 
```bash
sudo sysctl -w <parameter>=<value>
```
Make Changes Persistent:
Edit: /etc/sysctl.conf
Apply Changes: sudo sysctl -p
**Example Commands:**

```bash
sysctl -a
sudo sysctl -w vm.swappiness=10
sudo nano /etc/sysctl.conf
sudo sysctl -p
```

4. Tuning Kernel Parameters for Performance
**Description:**
Optimizing kernel parameters can improve system performance. This involves adjusting settings related to memory management, process limits, and more.

Examples:

Change Maximum Open File Descriptors:
**Command:** 
```bash
sudo sysctl -w fs.file-max=100000
```
Change Maximum User Processes:
**Command:** 
```bash
sudo sysctl -w kernel.pid_max=65536
```
Adjust Swappiness:
**Command:** 
```bash
sudo sysctl -w vm.swappiness=10
```
**Example Commands:**

```bash
sudo sysctl -w fs.file-max=100000
sudo sysctl -w kernel.pid_max=65536
sudo sysctl -w vm.swappiness=10
```

5. Kernel Versioning and Upgrades
**Description:**
Kernel versioning helps track changes and updates. Upgrading the kernel may be necessary for new features or hardware support.

**Steps:**

Check Current Kernel Version:
**Command:** uname -r
Upgrade Kernel:
**Command:** 
```bash
sudo apt-get install linux-image-<new_version>
```
Update Bootloader:
**Command:** 
```bash
sudo update-grub
```
**Example Commands:**

```bash
uname -r
sudo apt-get install linux-image-5.15.0-58-generic
sudo update-grub
```
6. Using the dmesg Command
**Description:**
The dmesg command displays the kernel's ring buffer, containing messages about hardware and system events. This is useful for debugging.

**Commands:**

View All Messages:
**Command:** 
```bash
dmesg
```
Filter Messages:
**Command:** 
```bash
dmesg | grep <keyword>
```
Clear Message Buffer:
**Command:** 
```bash
sudo dmesg -C
```
**Example Commands:**

```bash
dmesg
dmesg | grep usb
sudo dmesg -C
```

7. Configuring the GRUB Bootloader
**Description:**
GRUB is the bootloader responsible for loading the kernel. Configuration involves setting default kernel versions and passing parameters.

**Steps:**

Update GRUB:
**Command:** 
```bash
sudo update-grub
```
Edit GRUB Configuration:
File: /etc/default/grub
Example Edit: GRUB_DEFAULT="1>2"
Apply Changes:
**Command:** 
```bash
sudo update-grub
```

**Example Commands:**

```bash
sudo update-grub
sudo nano /etc/default/grub
sudo update-grub
```

8. Understanding Kernel Oops and Panics
**Description:**
Kernel oops and panics indicate errors in the kernel. An oops is recoverable, while a panic halts the system. Understanding these is essential for system stability.

Logs and Troubleshooting:

View Logs:
**Command:** 
```bash
cat /var/log/kern.log
```
Force a Kernel Panic:
**Command:** 
```bash
echo c > /proc/sysrq-trigger (Use with caution)
```
Enable Crash Dumps:
**Command:** 
```bash
sudo apt-get install kdump-tools
```
**Example Commands:**

```bash
cat /var/log/kern.log
echo c > /proc/sysrq-trigger
sudo apt-get install kdump-tools
```

9. Monitoring Kernel Activity
**Description:**
Monitoring kernel activity is crucial for system performance and troubleshooting. Various tools help track different aspects of kernel performance.

Tools:

Monitor CPU Activity:
**Commands:** 
```bash
top, htop
```
Monitor Disk Activity:
**Command:** 
```bash
iostat
```
Monitor Network Activity:
**Commands:** 
```bash
iftop
```
```bash
nload
```
Detailed Process Monitoring:
**Command:** 
```bash
ps aux
```
**Example Commands:**

```bash
top
htop
iostat
iftop
nload
ps aux
```

10. Custom Kernel Compilation
**Description:**
Compiling a custom kernel allows tailoring the kernel to specific hardware and needs. This advanced process requires careful configuration.

**Steps:**

Download Kernel Source:
**Command:** 
```bash
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.x.y.tar.xz
```
Extract and Configure:
**Commands:**
```bash
tar -xvf linux-5.x.y.tar.xz
cd linux-5.x.y
make menuconfig
```
Compile and Install:
**Commands:**
```bash
make -j $(nproc)
sudo make modules_install
sudo make install
```
Update Bootloader:
**Command:** 
```bash
sudo update-grub
```
**Example Commands:**

```bash
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.x.y.tar.xz
tar -xvf linux-5.x.y.tar.xz
cd linux-5.x.y
make menuconfig
make -j $(nproc)
sudo make modules_install
sudo make install
sudo update-grub
```
### Practice Commands

- View current kernel modules and load/unload a module.
- Compile a basic kernel module and test it.
- Adjust kernel parameters and verify changes.
- Upgrade the kernel and check the version.
- Use dmesg to view and filter kernel messages.
- Update GRUB and configure default kernel options.
- Check kernel logs for oops and panic messages.
- Monitor system activity with various tools.
- Compile and install a custom kernel.

#### Conclusion

In this lesson, we explored kernel modules, parameters, and versioning. Understanding these aspects is crucial for system performance and customization. Practice these commands and concepts to become proficient in managing and optimizing the Linux kernel.