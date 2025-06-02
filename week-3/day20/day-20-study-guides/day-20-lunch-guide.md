# Day 20 - Lunch: Building Useful Scripts

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