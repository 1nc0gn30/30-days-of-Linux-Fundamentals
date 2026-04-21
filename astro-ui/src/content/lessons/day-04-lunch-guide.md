# Day 14 Lunch: Kernel Parameters and Versioning

## Lesson Overview
<p><strong>Topic:</strong> Kernel Parameters and Versioning</p>
<p><strong>Description:</strong> In this lesson, we explore how to manage kernel parameters and understand kernel versioning in Linux. You'll learn to view, set, and persist kernel parameters, as well as how to determine the current kernel version and its significance.</p>

## Practical Commands
- **View current kernel version:**
``` bash
  uname -r
```
List all kernel parameters:
``` bash
Copy code
sysctl -a
```
Set a kernel parameter:
``` bash
Copy code
sysctl -w <parameter>=<value>
```
Persist kernel parameter changes:
``` bash
Copy code
echo "<parameter>=<value>" >> /etc/sysctl.conf
``` 
### Practice Question
#### Question: Which command is used to display the current kernel version?
- A) sysctl -a
- B) uname -r
- C) sysctl -w
- D) lsmod
#### Answer: B) uname -r
<p><em>Practice these commands in a terminal to solidify your understanding.</em></p>