# Day 19 - Dinner: Practical Performance Tuning

## 🧪 Lab Task 1: Monitor System Load

1. Open `htop` in one terminal.
2. In another, run:
   ```bash
   yes > /dev/null &
   ```
   multiple times to simulate CPU stress.
3. Use `vmstat 1` to monitor system reaction.

---

## 🔥 Lab Task 2: Tune Services for Performance

1. Identify active services:
   ```bash
   systemctl list-units --type=service
   ```
2. Disable and stop unnecessary ones:
   ```bash
   sudo systemctl disable bluetooth
   sudo systemctl stop bluetooth
   ```

3. Validate with `top` or `htop`.

---

## 💡 Lab Task 3: Disk I/O Analysis and Optimization

1. Monitor:
   ```bash
   iostat -xz 2
   ```
2. Simulate write load:
   ```bash
   dd if=/dev/zero of=testfile bs=1M count=1000
   ```
3. Adjust disk buffer settings:
   ```bash
   sudo sysctl vm.dirty_ratio=10
   sudo sysctl vm.dirty_background_ratio=5
   ```

This controls how much dirty data can sit in RAM before being flushed to disk.

---

## ✅ Summary

- You’ve stress-tested and analyzed system performance.
- You identified bottlenecks and tuned system behaviors using kernel and systemd controls.
- Ready to move on to deeper tuning or logging next.