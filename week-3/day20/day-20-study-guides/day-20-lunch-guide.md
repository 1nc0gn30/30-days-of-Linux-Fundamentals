# Day 20 · Lunch — Shell Environment Customization, Aliases & Dotfiles

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
> **Core Commands**: `export`, `env`, `alias`, `~/.bashrc`, `~/.profile`, `source`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // DEFENSE-IN-DEPTH & STREAM PIPELINE ARCHITECTURE        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║  [ INBOUND PACKET ] ──► [ Netfilter: iptables / nftables ]                   ║
║                                │ (ACCEPT)                                    ║
║                                ▼                                             ║
║                         [ Hardened SSHD + Fail2Ban ]                         ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ DAC: chmod/chown ] ──► [ MAC: SELinux / AppArmor ] ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ Auditd & Log Pipelines: grep | awk | sed ]         ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 20 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/20` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-20 && cd /tmp/linux-dojo-day-20` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 🛠 Automating Tasks with Shell Scripts

```bash
find /var/log -name "*.log" -mtime +7 -delete
```

- Clean logs older than 7 days
- Run in crontab for scheduled automation

---

## 🧩 Using getopts for Command-Line Options

```bash
while getopts "hvf:" opt; do
  case $opt in
    h) echo "Help";;
    v) echo "Verbose mode";;
    f) echo "File: $OPTARG";;
  esac
done
```

- `getopts` handles CLI options like `-h`, `-v`, `-f filename`
- `$OPTARG` gives the argument value passed with options

---

## 🐞 Debugging Shell Scripts

```bash
bash -x script.sh
set -e  # exits on any error
set -x  # shows each command as it executes
```

- Use for tracing logic errors
- Combine with `echo` statements and input logs

---

## 📚 Resources

- https://linuxize.com/post/how-to-debug-bash-scripts/
- https://wiki.bash-hackers.org/howto/getopts_tutorial
