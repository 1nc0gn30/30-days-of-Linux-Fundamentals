# 🍽 Day 22 Dinner: Practical Performance Tuning

## 🧠 Objective

Consolidate your understanding of performance monitoring by practicing real-world system tuning techniques using live tools and configuration adjustments.

---

## 📈 Task 1: Monitor System Load

### Tools:

* `vmstat 1 5` – view CPU scheduling, memory, swap, I/O, and context switches
* `htop` – interactive live process viewer

### What to Watch:

* High `wa` (I/O wait) time in `vmstat`
* CPU and MEM bars in `htop`
* Load average vs number of cores

---

## ⚙️ Task 2: Tune systemd Services

### Steps:

* List enabled services:

```bash
systemctl list-unit-files --type=service | grep enabled
```

* Disable unnecessary ones:

```bash
sudo systemctl disable NAME.service
```

* For critical tweaks, use `systemctl mask`

### Why:

* Reduces memory and boot time
* Improves idle efficiency on desktops and servers

---

## 💾 Task 3: Analyze & Optimize Disk I/O

### Tools:

* `iostat -xz 1 3` (requires `sysstat` package)

### What to Look For:

* `%util` nearing 100% = device is saturated
* High `await` and `svctm` = slow response times

### Actions:

* Migrate logs/temp dirs to faster storage
* Consider using `noop` or `deadline` I/O scheduler
* Balance load across disks with RAID or LVM striping

---

## 🧪 Run This Lab in `day-22-dinner`

* Interactive simulation of load monitoring, service tuning, and disk I/O analysis.
* Reinforces habits for keeping systems healthy under stress.

---

## ✅ Summary

After this lab, you should be able to:

* Read real-time performance indicators
* Disable or optimize services
* Analyze I/O patterns and take corrective action
