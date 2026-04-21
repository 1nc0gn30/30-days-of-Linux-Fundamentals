# Day 19 - Breakfast: System Performance Metrics

## 🧠 CPU, Memory, and I/O Metrics with vmstat, top, and iotop

- **vmstat 1**: Reports memory, swap, I/O, system processes, and CPU every second.
- **top**: Real-time process view, sorted by CPU usage by default.
- **iotop**: Displays disk I/O usage per process.

Use these tools to:
- Spot CPU hogs.
- Identify memory starvation.
- Detect I/O-heavy processes stalling your disk throughput.

---

## 🔍 Using htop for Monitoring

- Run: `htop`
- Colorful, interactive version of `top`.
- Features:
  - Mouse support.
  - Easy sorting.
  - Kill processes visually.
  - Toggle display columns (F2).

---

## 📀 Analyzing Disk I/O with iostat

- Install via: `sudo apt install sysstat`
- Run: `iostat -xz 1`
- Parameters:
  - `-x`: extended stats.
  - `-z`: suppress zero-only devices.
  - `1`: refresh every second.

Monitors:
- Disk utilization
- Read/write throughput
- Average request size and queue times

---

## 📚 Resources

- https://man7.org/linux/man-pages/man1/top.1.html
- https://linux.die.net/man/1/iotop
- https://htop.dev/