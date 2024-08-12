# Day 12 Dinner: Linux Kernel Basics Study Guide

## Overview

In this study guide, we'll explore advanced topics in Linux Kernel Basics, including kernel debugging, security enhancements, patching, and live patching. This guide covers key concepts, commands, and practical applications related to these topics.

## Lesson Topics

### 1. Introduction to Kernel Debugging

Kernel debugging is crucial for diagnosing and fixing kernel issues. Key tools include:

- **kgdb**: A debugger for the Linux kernel.
  - **Start debugging**: `gdb vmlinux`
  - **Connect to the kernel**: `target remote /dev/ttyS0`
- **kdump**: A crash dumping mechanism.
  - **Configure**: Edit `/etc/default/grub` and add `crashkernel=128M`
  - **Test**: `echo c > /proc/sysrq-trigger`
- **ftrace**: A tracing utility for debugging kernel performance.
  - **Start tracing**: `echo function > /sys/kernel/debug/tracing/current_tracer`
  - **View trace output**: `cat /sys/kernel/debug/tracing/trace`

### 2. Using kgdb for Kernel Debugging

**kgdb** allows you to debug a running kernel using gdb:

1. **Compile kernel with debugging symbols**: Add `CONFIG_KGDB=y` to your kernel configuration.
2. **Connect debugger**: Use a serial or network connection.
3. **Launch gdb**: `gdb vmlinux`
4. **Connect to kgdb**: `target remote /dev/ttyS0`
5. **Set breakpoints and inspect kernel state**.

### 3. Understanding Kernel Crash Dumps with kdump

**kdump** captures kernel memory contents after a crash:

1. **Install kexec-tools**: `sudo apt-get install kexec-tools`
2. **Configure crashkernel**: Edit `/etc/default/grub` and add `crashkernel=128M`
3. **Update GRUB**: `sudo update-grub`
4. **Test kdump**: Trigger a crash with `echo c > /proc/sysrq-trigger`.

### 4. Using ftrace for Kernel Tracing

**ftrace** helps analyze kernel performance:

1. **Enable function tracing**: `echo function > /sys/kernel/debug/tracing/current_tracer`
2. **View trace output**: `cat /sys/kernel/debug/tracing/trace`
3. **Stop tracing**: `echo > /sys/kernel/debug/tracing/trace`
4. **Set up tracepoints**: `echo 'tracepoint_name' > /sys/kernel/debug/tracing/set_ftrace_filter`

### 5. Kernel Security Enhancements

Kernel security features include:

- **SELinux**: Enforces security policies.
  - **Check status**: `sestatus`
  - **Modify settings**: Edit `/etc/selinux/config`
- **AppArmor**: Similar to SELinux.
  - **Check status**: `sudo aa-status`
- **seccomp**: Restricts system calls.
  - **Set up filters**: Use `prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT)`

### 6. Configuring SELinux

**SELinux** provides mandatory access control (MAC):

1. **Check status**: `sestatus`
2. **Enable/disable SELinux**: Edit `/etc/selinux/config` and set `SELINUX=enforcing` or `SELINUX=permissive`.
3. **Troubleshoot issues**: Use `ausearch -m avc` and `semanage` for policy management.

### 7. Applying Kernel Patches

Kernel patches fix bugs and add features:

1. **Download patch**: Obtain from kernel.org or a trusted source.
2. **Apply patch**: `patch -p1 < patch_file`
3. **Rebuild kernel**: `make -j $(nproc)`
4. **Install new kernel**: `sudo make modules_install && sudo make install`
5. **Update bootloader**: `sudo update-grub`

### 8. Kernel Live Patching

**Live patching** applies patches without rebooting:

- **kpatch**: Install and apply patches.
  - **Install**: `sudo yum install kpatch`
  - **Apply patch**: `kpatch load patch_file`
- **kGraft**: Another live patching solution.
- **Canonical livepatch service**: For Ubuntu.
  - **Enable**: `sudo apt-get install ubuntu-livepatch`

### 9. Understanding Kernel Locking Mechanisms

Kernel locking prevents race conditions:

- **Spinlocks**: Busy-wait locks for interrupt contexts.
  - **Acquire**: `spin_lock(&lock)`
  - **Release**: `spin_unlock(&lock)`
- **Mutexes**: Sleep-based locks for process contexts.
  - **Acquire**: `mutex_lock(&mutex)`
  - **Release**: `mutex_unlock(&mutex)`
- **Read-write locks**: Allow multiple readers or a single writer.
  - **Acquire read lock**: `read_lock(&rwlock)`
  - **Release read lock**: `read_unlock(&rwlock)`
  - **Acquire write lock**: `write_lock(&rwlock)`
  - **Release write lock**: `write_unlock(&rwlock)`

### 10. Managing Kernel Threads

**Kernel threads** perform background tasks:

1. **View kernel threads**: `ps -eLf`
2. **Create kernel thread**: Use `kthread_create` in kernel code.
   - **Example**: `struct task_struct *task = kthread_create(function, data, 'name');`
3. **Start kernel thread**: `wake_up_process(task)`
4. **Stop kernel thread**: Use `kthread_stop` in kernel code.
   - **Example**: `kthread_stop(task);`

## Questions and Answers

### Breakfast Questions

1. **Which command is used to view all loaded kernel modules?**
   - `lsmod`

2. **How do you dynamically load a kernel module?**
   - `sudo modprobe <module_name>`

3. **Which file contains information about kernel modules?**
   - `/lib/modules/$(uname -r)/modules.dep`

4. **How do you unload a kernel module?**
   - `sudo modprobe -r <module_name>`

5. **Which command displays detailed information about a module?**
   - `modinfo <module_name>`

### Lunch Questions

1. **What command shows the current kernel version?**
   - `uname -r`

2. **Which command updates the GRUB bootloader?**
   - `sudo update-grub`

3. **How do you check kernel parameters?**
   - `sysctl -a`

4. **Which file do you edit to make kernel parameter changes persistent?**
   - `/etc/sysctl.conf`

5. **What command is used to apply changes from `/etc/sysctl.conf`?**
   - `sudo sysctl -p`

### Dinner Questions

1. **Which tool is used for debugging the Linux kernel?**
   - **Answer**: `kgdb`

2. **What is the purpose of kdump?**
   - **Answer**: To capture the contents of the kernel's memory after a crash

3. **How do you enable function tracing with ftrace?**
   - **Answer**: `echo function > /sys/kernel/debug/tracing/current_tracer`

4. **Which command checks the status of SELinux?**
   - **Answer**: `sestatus`

5. **How do you apply a kernel patch?**
   - **Answer**: `patch -p1 < patch_file`

6. **What is live kernel patching?**
   - **Answer**: Applying kernel patches without rebooting the system

7. **What is a spinlock?**
   - **Answer**: A busy-wait lock used in interrupt contexts

8. **How do you view kernel threads?**
   - **Answer**: `ps -eLf`

9. **What is the purpose of SELinux?**
   - **Answer**: To enforce mandatory access control (MAC) security policies

10. **Which utility is used for live kernel patching on Linux?**
    - **Answer**: `kpatch`

## Conclusion

In Day 12 Dinner, we covered essential aspects of Linux Kernel Basics, including debugging, security, patching, and live patching. Understanding these concepts is crucial for effective kernel management and troubleshooting. Review the lessons and test your knowledge with the provided questions to solidify your understanding.
