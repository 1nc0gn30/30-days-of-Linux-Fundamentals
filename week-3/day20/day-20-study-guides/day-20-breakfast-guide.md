# Day 20 · Breakfast — Shell Environment Customization, Aliases & Dotfiles

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 20 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/20` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-20 && cd /tmp/linux-dojo-day-20` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

## 📌 Review Variables and Loops

```bash
for i in {1..5}; do echo "Number: $i"; done
```

- Declare variables without spaces: `name=zoth`
- Access them with `$name`
- Loops: for, while, until
- Useful for batch automation and command sequences

---

## 📌 Conditionals in Scripts

```bash
if [ "$USER" = "root" ]; then echo "Admin"; else echo "User"; fi
```

- Use `[` or `[[` for conditions
- Operators: `=`, `!=`, `-lt`, `-eq`, `-f`, `-d`
- Always quote variables inside conditionals

---

## 📌 Handling Input and Output

```bash
read -p "Enter your name: " name
echo "Hello $name" >> greetings.txt
```

- `read`: Get user input
- `>` overwrites files; `>>` appends
- `tee` can write to file and print to screen

---

## 📚 Resources

- https://linuxize.com/post/bash-if-else-statement/
- https://opensource.com/article/19/9/getting-started-bash-scripting
