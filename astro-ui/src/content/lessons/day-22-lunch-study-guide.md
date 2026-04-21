# 🍲 Day 22 Lunch: Performance Optimization

## 🧠 Objective

Learn techniques to reduce system resource usage by identifying heavy processes, managing background services, and understanding swap/cache behavior.

---

## 🔧 Optimize CPU Usage

* Use `ps` to sort processes by CPU usage:

```bash
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head
```

* Consider using `nice`, `renice`, or `kill` for high-CPU processes.
* Long-term issues might need profiling or workload redistribution.

---

## 🧠 Optimize Memory Usage

* Use `free -h` to check RAM/swap usage.
* High usage doesn’t always mean bad — focus on low available + high swap.
* Consider restarting memory-leaky apps or checking logs.

```bash
free -h
```

---

## ⚙️ Manage Background Services (systemd)

* View running services:

```bash
systemctl list-units --type=service --state=running
```

* Disable unused services to free memory/CPU:

```bash
sudo systemctl disable bluetooth.service
```

* Use `systemctl mask` to prevent startup at all costs.

---

## 💾 Swap & Cache Management

* View swap and cache usage:

```bash
grep -Ei 'swap|cached' /proc/meminfo
```

* Check current swappiness value:

```bash
sysctl vm.swappiness
```

* To lower swap aggressiveness:

```bash
sudo sysctl -w vm.swappiness=10
```

---

## 🧪 Run This Lesson in `day-22-lunch`

Interactively explore:

* CPU optimization
* Memory inspection
* Background service tuning
* Swap/cache understanding

---

## ✅ Summary

After this session, you should be able to:

* Spot and reduce high CPU/memory usage
* Disable or mask background bloat
* Tune swap behavior to match system needs
