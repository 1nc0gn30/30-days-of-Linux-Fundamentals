# Day 19 - Lunch: Performance Optimization

## ⚙️ Optimizing System Resources

- Adjust CPU priority with `nice` and `renice`:
  - `nice -n 10 command` (lower priority)
  - `renice +10 <PID>` (lower an existing process)
- Monitor memory with:
  - `free -h`
  - `vmstat`
- Kill zombie or idle processes:
  - `kill -9 <PID>`

---

## 🔧 Managing Services with systemd

- View active services:
  ```bash
  systemctl list-units --type=service
  ```
- Disable unused services:
  ```bash
  sudo systemctl disable bluetooth
  sudo systemctl stop bluetooth
  ```

Reducing unnecessary services lowers boot time, CPU usage, and memory consumption.

---

## 💾 Swapping and Cache Management

- Show swap:
  ```bash
  swapon -s
  ```
- Adjust swap tendency:
  ```bash
  sudo sysctl vm.swappiness=10
  ```
- Make it permanent:
  ```bash
  echo "vm.swappiness=10" | sudo tee -a /etc/sysctl.conf
  ```

Lower swappiness means Linux prefers RAM and delays swapping.

---

## 📚 Resources

- https://wiki.archlinux.org/title/Swap
- https://www.freedesktop.org/software/systemd/man/systemctl.html
- https://linux.die.net/man/1/nice