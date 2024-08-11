#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// ANSI escape codes for text color
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a question
typedef struct {
    const char *question;
    const char *options[4];
    const char *correct_answer;
} Question;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("%sLesson on `%s`:%s\n", CYAN, lesson->topic, RESET);
    printf("%s%s%s\n", YELLOW, lesson->description, RESET);
    printf("\n%s%s%s\n", GREEN, lesson->examples, RESET);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("%s%s%s\n", BLUE, question->question, RESET);

    // Display multiple choice options
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }

    printf("Your answer (1-4): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("%sCorrect!%s\n\n", GREEN, RESET);
    } else {
        printf("%sIncorrect.%s The correct answer is: %s\n\n", RED, RESET, question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("%sWelcome to Day 08 Dinner!%s\n", MAGENTA, RESET);
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
            "What is the purpose of the `$#` and `$@` variables in shell scripting?",
            {"$# gives the number of arguments, $@ represents all arguments passed to the script",
             "$# gives the first argument, $@ represents all arguments passed to the script",
             "$# gives the number of arguments, $@ represents the last argument passed to the script",
             "$# gives the number of arguments, $@ represents the script name"},
            "1"
        },
        {
            "How would you write a regex pattern to match lines that contain a word starting with 'test'?",
            {"\\btest.*",
             "test.*\\b",
             "\\btest.*\\b",
             "\\b.*test\\b"},
            "3"
        },
        {
            "How do you perform a case-insensitive search using `grep`?",
            {"-c",
             "-i",
             "-n",
             "-v"},
            "2"
        },
        {
            "How do you delete all lines containing 'error' in a file using `sed`?",
            {"sed 's/error//g' file.txt",
             "sed 'error' file.txt",
             "sed 'd/error' file.txt",
             "sed '/error/d' file.txt"},
            "4"
        },
        {
            "How would you extract the third field from a CSV file using `awk`?",
            {"awk -F ',' '{print $1}' file.csv",
             "awk -F ',' '{print $2}' file.csv",
             "awk -F ',' '{print $3}' file.csv",
             "awk -F ',' '{print $4}' file.csv"},
            "3"
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
