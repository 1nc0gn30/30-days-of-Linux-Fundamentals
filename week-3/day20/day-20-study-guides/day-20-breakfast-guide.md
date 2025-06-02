# Day 20 - Breakfast: Shell Scripting Refresher

## 📌 Review Variables and Loops

```bash
for i in {1..5}; do echo "Number: $i"; done
```

- Declare variables without spaces: `name=Neal`
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