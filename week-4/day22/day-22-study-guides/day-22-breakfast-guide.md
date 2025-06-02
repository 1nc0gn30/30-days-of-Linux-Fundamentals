## 🥣 Day 22 Breakfast: System Performance Metrics

### 🧠 Objective

Understand and interpret key system metrics using CLI-based performance monitoring tools.

---

### 🖥️ CPU, Memory, and I/O Metrics

* `vmstat` (virtual memory statistics):

```bash
vmstat 1 5
```

Shows:

* procs: running and blocked processes

* memory: free, buffer, cache

* swap: in/out

* io: disk read/write

* system: interrupts, context switches

* `top`: live process and load average view

* `iotop`: real-time I/O usage by process (requires root)

---

### 📊 Using `htop` for Monitoring

* Easier navigation compared to `top`
* Tree view of processes
* Color-coded bars for CPU, memory, swap usage

**Start with:**

```bash
htop
```

* Press `F6` to sort by metrics (CPU, MEM, TIME+)
* Press `F9` to send signals (e.g., kill a process)

---

### 💽 Analyzing Disk I/O with `iostat`

Install via:

```bash
sudo apt install sysstat
```

Run:

```bash
iostat -xz 1 5
```

Key fields:

* `tps`: transfers per second
* `kB_read/s`, `kB_wrtn/s`: throughput
* `%util`: device utilization (watch for 100%)

---

## ✅ Summary:

By the end of breakfast, you should:

* Know which tools show real-time CPU and memory stats
* Read and interpret `vmstat`, `htop`, `iostat`
* Spot bottlenecks in process, memory, or I/O usage
