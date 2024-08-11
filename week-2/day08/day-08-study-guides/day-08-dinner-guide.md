# Diy 08 Dinner Study Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Lessons](#lessons)
   - [Advanced Shell Scripting](#advanced-shell-scripting)
   - [Working with Regular Expressions](#working-with-regular-expressions)
   - [Using `grep` for Text Searching](#using-grep-for-text-searching)
   - [Using `sed` for Stream Editing](#using-sed-for-stream-editing)
   - [Using `awk` for Pattern Scanning and Processing](#using-awk-for-pattern-scanning-and-processing)
3. [Interactive Questions](#interactive-questions)
4. [Conclusion](#conclusion)
5. [Further Reading](#further-reading)

---

## Introduction
Welcome to Day 08 Dinner! In this session, we'll dive deeper into shell scripting, regular expressions, and text processing tools. You'll explore advanced shell scripting techniques, regular expressions for text manipulation, and powerful command-line tools like `grep`, `sed`, and `awk`.

## Lessons

### Advanced Shell Scripting
**Topic:** Building on basic shell scripting  
**Description:**  
Explore more complex shell scripting techniques including handling command-line arguments, error handling, and script debugging. Learn to write scripts that process user inputs and return outputs based on conditions.

**Examples:**
```bash
#!/bin/bash
if [ $# -eq 0 ]; then
  echo "No arguments provided"
  exit 1
fi
echo "You provided $# arguments: $@"
```
# Save this script as args.sh, make it executable with chmod +x args.sh, and run it with ./args.sh arg1 arg2
For more details, check out the Advanced Bash-Scripting Guide.

Working with Regular Expressions
Topic: Using regex patterns for text manipulation
Description:
Regular expressions (regex) are used for matching patterns in strings. Learn to create and use regex patterns in shell scripts and with command-line tools like grep, sed, and awk.

Examples:

```bash
# Searching for lines that start with 'error' in a log file:
grep '^error' /var/log/syslog
# Replacing 'foo' with 'bar' in a file:
sed 's/foo/bar/g' input.txt > output.txt
# Extracting the second field from a CSV file:
awk -F ',' '{print $2}' data.csv
```
For a comprehensive guide to regular expressions, refer to Regular Expressions Info.

Using grep for Text Searching
Topic: Searching text with patterns
Description:
The grep command searches text using patterns and supports regular expressions. Learn how to find specific patterns, filter outputs, and search recursively through directories.

Examples:

```bash
Copy code
grep 'pattern' file.txt
grep -r 'error' /var/log
grep -i 'error' file.txt # Case-insensitive search
```
To learn more, explore the grep man page: man grep.

Using sed for Stream Editing
Topic: Editing text streams
Description:
sed is a stream editor for performing text transformations. Learn to use sed for text replacement, deletion, and insertion.

Examples:

```bash
Copy code
sed 's/old/new/g' file.txt
sed '/pattern/d' file.txt
sed '2i\
This is a new line' file.txt
```
For more examples and usage, see the sed documentation.

Using awk for Pattern Scanning and Processing
Topic: Pattern scanning and processing with awk
Description:
awk is a versatile language for file and stream processing. Learn to extract specific fields, perform calculations, and generate reports.

Examples:

```bash
awk '{print $1}' file.txt  # Print the first field of each line
awk -F ':' '{print $1, $3}' /etc/passwd  # Print the username and UID from /etc/passwd
awk '$3 > 1000' file.txt  # Print lines where the third field is greater than 1000
```
***For detailed usage, refer to the GNU Awk User's Guide.***

### Interactive Questions
#### Test your knowledge with the following questions:

**What is the purpose of the `$# and $@` variables in shell scripting?**

$# gives the number of arguments, $@ represents all arguments passed to the script
$# gives the first argument, $@ represents all arguments passed to the script
$# gives the number of arguments, $@ represents the last argument passed to the script
$# gives the number of arguments, $@ represents the script name
How would you write a regex pattern to match lines that contain a word starting with 'test'?

\btest.*
test.*\b
\btest.*\b
\b.*test\b

**How do you perform a case-insensitive search using grep?**

-c
-i
-n
-v

**How do you delete all lines containing 'error' in a file using sed?**

sed 's/error//g' file.txt
sed 'error' file.txt
sed 'd/error' file.txt
sed '/error/d' file.txt

**How would you extract the third field from a CSV file using awk?**

awk -F ',' '{print $1}' file.csv
awk -F ',' '{print $2}' file.csv
awk -F ',' '{print $3}' file.csv
awk -F ',' '{print $4}' file.csv

## **Conclusion*

This guide provides an in-depth look into advanced shell scripting techniques, regular expressions, and essential text processing tools. Mastering these concepts will enhance your ability to automate tasks and manipulate text in a Linux environment effectively.

### Further Reading
For more information and further learning, explore the following resources:

- Advanced Shell Scripting

- Advanced Bash-Scripting Guide
- Regular Expressions

- Regular Expressions Info
- grep Command

- grep Man Page
- sed Command

- sed Documentation
- awk Command

- GNU Awk User's Guide