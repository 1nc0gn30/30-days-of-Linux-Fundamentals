# Day 14 Breakfast: Kernel Modules Management

## Lesson Overview
<p><strong>Topic:</strong> Kernel Modules Management</p>
<p><strong>Description:</strong> In this lesson, we focus on managing kernel modules in Linux. Kernel modules are pieces of code that can be loaded and unloaded into the kernel upon demand, providing flexibility and efficiency. You'll learn how to load, unload, and query these modules, as well as modify kernel parameters.</p>

## Practical Commands
- **Load a module:** 
  ```bash
  modprobe <module_name>
```
Unload a module:
``` bash
Copy code
rmmod <module_name>
```
View loaded modules:
``` bash
Copy code
lsmod
```
Modify kernel parameters:
``` bash
Copy code
sysctl -w <parameter>=<value>
```
### Practice Question
#### Question: What command is used to load a kernel module?
- A) insmod
- B) modprobe
- C) lsmod
- D) rmmod
#### Answer: B) modprobe
<p><em>Make sure to practice these commands in a terminal to reinforce your understanding.</em></p>
