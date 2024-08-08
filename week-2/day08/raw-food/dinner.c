#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a question
typedef struct {
    const char *question;
    const char *correct_answer;
} Question;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("%s\n", question->question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to Day 08 Dinner!\n");
    printf("In this session, we'll dive deeper into shell scripting, regular expressions, and text processing tools.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Advanced Shell Scripting",
            "Building on the basics, we'll explore more complex shell scripting techniques like handling command-line arguments, error handling, and script debugging.\n"
            "You'll learn to write more sophisticated scripts that can take inputs from users, process them, and return outputs based on conditions.",
            "Examples:\n"
            "  #!/bin/bash\n"
            "  if [ $# -eq 0 ]; then\n"
            "    echo \"No arguments provided\"\n"
            "    exit 1\n"
            "  fi\n"
            "  echo \"You provided $# arguments: $@\"\n"
            "  # Save this script as args.sh, make it executable with chmod +x args.sh, and run it with ./args.sh arg1 arg2\n"
            "For more details, check out the Advanced Bash-Scripting Guide at https://tldp.org/LDP/abs/html/."
        },
        {
            "Working with Regular Expressions",
            "Regular expressions (regex) are patterns used to match character combinations in strings. They are powerful tools for searching, replacing, and validating text.\n"
            "You'll learn to create and use regex patterns in shell scripts and with command-line tools like `grep`, `sed`, and `awk`.",
            "Examples:\n"
            "  # Searching for lines that start with 'error' in a log file:\n"
            "  grep '^error' /var/log/syslog\n"
            "  # Replacing 'foo' with 'bar' in a file:\n"
            "  sed 's/foo/bar/g' input.txt > output.txt\n"
            "  # Extracting the second field from a CSV file:\n"
            "  awk -F ',' '{print $2}' data.csv\n"
            "For a comprehensive guide to regular expressions, refer to https://www.regular-expressions.info/."
        },
        {
            "Using `grep` for Text Searching",
            "The `grep` command is used to search text using patterns. It supports regular expressions and can be combined with other commands for powerful text processing.\n"
            "You'll learn how to use `grep` to find specific patterns in files, filter outputs, and even search recursively through directories.",
            "Examples:\n"
            "  grep 'pattern' file.txt\n"
            "  grep -r 'error' /var/log\n"
            "  grep -i 'error' file.txt # Case-insensitive search\n"
            "To learn more, explore the `grep` man page: `man grep`."
        },
        {
            "Using `sed` for Stream Editing",
            "`sed` is a stream editor that allows you to perform basic text transformations on an input stream (a file or input from a pipeline).\n"
            "You'll learn to use `sed` for text replacement, deletion, insertion, and more.",
            "Examples:\n"
            "  sed 's/old/new/g' file.txt\n"
            "  sed '/pattern/d' file.txt\n"
            "  sed '2i\
            This is a new line' file.txt\n"
            "For more examples and usage, see the `sed` documentation at https://www.gnu.org/software/sed/manual/sed.html."
        },
        {
            "Using `awk` for Pattern Scanning and Processing",
            "`awk` is a versatile programming language for working on files and streams that allows for pattern scanning and processing.\n"
            "You'll learn to use `awk` for extracting specific fields from structured text, performing calculations, and generating reports.",
            "Examples:\n"
            "  awk '{print $1}' file.txt  # Print the first field of each line\n"
            "  awk -F ':' '{print $1, $3}' /etc/passwd  # Print the username and UID from /etc/passwd\n"
            "  awk '$3 > 1000' file.txt  # Print lines where the third field is greater than 1000\n"
            "For detailed usage, refer to the GNU Awk User's Guide at https://www.gnu.org/software/gawk/manual/gawk.html."
        }
    };

    // Questions
    Question questions[] = {
        {
            "1. What is the purpose of the `$#` and `$@` variables in shell scripting?\n"
            "Hint: Explain how these special variables are used when handling command-line arguments.\n"
            "Format: `$#` gives the number of arguments, `$@` represents [what].",
            "$@ represents all the arguments passed to the script"
        },
        {
            "2. How would you write a regex pattern to match lines that contain a word starting with 'test'?\n"
            "Hint: Use a word boundary `\\b` to ensure it matches a whole word.\n"
            "Format: The pattern is `\\b[what].*\\b`.",
            "\\btest.*\\b"
        },
        {
            "3. How do you perform a case-insensitive search using `grep`?\n"
            "Hint: Mention the flag that makes the search case-insensitive.\n"
            "Format: The flag is `-[flag]`.",
            "-i"
        },
        {
            "4. How do you delete all lines containing 'error' in a file using `sed`?\n"
            "Hint: Describe the `sed` command that performs this action.\n"
            "Format: The command is `sed ['pattern' delete command] file.txt`.",
            "sed '/error/d' file.txt"
        },
        {
            "5. How would you extract the third field from a CSV file using `awk`?\n"
            "Hint: Use the `-F` option to specify the field separator and print the third field.\n"
            "Format: The command is `awk ['separator' 'print command'] file.csv`.",
            "awk -F ',' '{print $3}' file.csv"
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    return 0;
}
