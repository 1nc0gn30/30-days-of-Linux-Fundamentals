# 🍲 Day 23 Lunch: Building Useful Scripts

## 🧠 Objective

Learn how to write useful Bash scripts for automation and system management, handle CLI options with `getopts`, and debug with common shell flags.

---

## 🛠️ Section 1: Automating Common Tasks

### 🔥 Example: Log Cleanup

```bash
#!/bin/bash
find /var/log -type f -name "*.log" -mtime +7 -exec rm {} \;
echo "Old logs removed."
```

### 💾 Example: Disk Monitor

```bash
#!/bin/bash
usage=$(df -h / | awk 'NR==2 {print $5}' | sed 's/%//')
if [ $usage -gt 80 ]; then
  echo "Disk space critical: $usage% used."
fi
```

---

## 🎛 Section 2: Using getopts

### 🧰 Example: Script Options

```bash
#!/bin/bash
while getopts ":u:p:" opt; do
  case $opt in
    u) user=$OPTARG ;;
    p) path=$OPTARG ;;
    *) echo "Invalid option" ; exit 1 ;;
  esac
done

echo "User: $user"
echo "Path: $path"
```

* This allows for custom flags like `-u neal -p /home/neal`

---

## 🪛 Section 3: Debugging Scripts

### 🔍 Debug Line-by-Line

```bash
bash -x script.sh
```

### ❌ Exit on First Error

```bash
set -e
```

* Good for scripts that need to stop if a command fails

### 🔄 Show All Commands

```bash
set -x
```

* Like `bash -x`, but works inline

---

## ✅ Summary

After lunch, you should know how to:

* Automate cleanup and monitoring with Bash
* Parse CLI flags using `getopts`
* Debug issues with `bash -x`, `set -e`, and `set -x`

Run the `day-23-lunch` program to interactively try each topic.
