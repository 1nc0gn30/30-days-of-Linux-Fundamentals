# 🥣 Day 23 Breakfast: Shell Scripting Refresher

## 🧠 Objective

Refresh your knowledge of Bash scripting basics: variables, conditionals, loops, and basic input/output handling.

---

## 🔤 Section 1: Variables and Loops

### 💡 Variables

```bash
name="Neal"
echo "Welcome, $name!"
```

* Use `"$var"` to safely access values.

### 🔁 For Loop

```bash
for i in {1..5}; do
  echo "Count: $i"
done
```

### 🔁 While Loop

```bash
count=1
while [ $count -le 5 ]; do
  echo "Still counting: $count"
  ((count++))
done
```

---

## 🔀 Section 2: Conditionals

### ✅ If-Else Example

```bash
num=10
if [ $num -gt 5 ]; then
  echo "Greater than 5"
else
  echo "5 or less"
fi
```

### 🧪 Nested Conditions

```bash
if [ -f file.txt ]; then
  echo "File exists"
elif [ -d file.txt ]; then
  echo "It's a directory"
else
  echo "Does not exist"
fi
```

---

## 🧾 Section 3: Input and Output

### 🧍‍♂️ User Input

```bash
read -p "Enter your username: " username
echo "Hello, $username"
```

### 📁 Redirect Output

```bash
echo "Log Entry" >> log.txt
```

### 🧹 Clear File Content

```bash
> log.txt
```

---

## ✅ Summary

By the end of this refresher, you should be comfortable with:

* Declaring and using variables
* Looping with `for` and `while`
* Handling input/output
* Writing basic conditional logic

Use the `day-23-breakfast` simulation to practice live.
