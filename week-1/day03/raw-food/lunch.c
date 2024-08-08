#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function to clear the screen (Unix-based systems)
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to wait for the user to press Enter
void wait_for_enter() {
    printf("Press Enter to continue...\n");
    getchar();
}

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("Examples:\n%s\n", lesson->examples);
    wait_for_enter();
}

// Struct to represent a question
typedef struct {
    const char *question;
    const char *correct_answer;
} Question;

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[BUFFER_SIZE];

    printf("%s\n", question->question);
    printf("Instructions: Open a separate terminal and type the command described. ");
    wait_for_enter();
    printf("When you are ready, press Enter to proceed...\n");
    wait_for_enter();

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

// Function to display welcome message and start the session
void start_session() {
    clear_screen();
    printf("Welcome to Day 3 Lunch!\n");
    printf("In this session, we'll delve into advanced file and directory management, as well as file viewing and editing.\n");
    printf("Follow the lessons and complete the tasks to test your skills.\n");
    wait_for_enter();
}

// Function to handle lessons and questions
void handle_lessons_and_questions() {
    Lesson lessons[] = {
        {
            "Create, Copy, Move, and Rename Files",
            "This section covers advanced file management tasks including creating, copying, moving, and renaming files.",
            "Examples:\n  touch file1.txt           # Create an empty file\n  echo 'Hello World' > file2.txt  # Create a file with content\n  cp file1.txt /backup/     # Copy file to a directory\n  mv file1.txt /path/        # Move file to a new location\n  mv oldname.txt newname.txt # Rename a file"
        },
        {
            "Directory Navigation and Manipulation",
            "This section focuses on navigating through directories and manipulating them.",
            "Examples:\n  cd /path/to/directory       # Change to a specified directory\n  cd ..                       # Move up one directory\n  mkdir -p parent/child       # Create nested directories\n  rmdir emptydir/             # Remove an empty directory\n  rm -r nonemptydir/          # Remove a non-empty directory"
        },
        {
            "File Management Scavenger Hunt",
            "This scavenger hunt will test your ability to find, manage, and handle files based on specific criteria.",
            "Examples:\n  find /path -name '*.log'   # Find all .log files in a directory\n  grep 'pattern' file.txt    # Search for a pattern in a file\n  mv file.txt /path/          # Move a file to a directory\n  cp -i file.txt /path/       # Copy a file with interactive prompt\n  rm -i file.txt              # Remove a file with interactive prompt"
        }
    };

    Question questions[] = {
        {"Create a file named `testfile.txt` with content 'Test Content'.", "echo 'Test Content' > testfile.txt"},
        {"Copy `testfile.txt` to a directory named `backup/`.", "cp testfile.txt backup/"},
        {"Rename `testfile.txt` to `renamedfile.txt` and move it to `backup/`.", "mv testfile.txt backup/renamedfile.txt"},
        {"Recursively copy the `backup/` directory to `archive/`.", "cp -r backup/ archive/"},
        {"Navigate to the `/etc` directory.", "cd /etc"},
        {"Create a directory structure `/data/archive/2024`.", "mkdir -p /data/archive/2024"},
        {"Change the permissions of `/data` to `755`.", "chmod 755 /data"},
        {"Display the size of the `/home/user` directory", "du -dh /home/user"},
                {"Remove the `/data/archive/2024` directory and all its contents.", "rm -r /data/archive/2024"},
        {"Find all `.log` files in `/var/log`.", "find /var/log -name '*.log'"},
        {"Search for the pattern 'Error' in `/var/log/syslog`.", "grep 'Error' /var/log/syslog"},
        {"Move a file named `report.txt` from `/home/user/` to `/archive/`.", "mv /home/user/report.txt /archive/"},
        {"Create a backup of `report.txt` in `/backup/` without overwriting existing files.", "cp -u /home/user/report.txt /backup/"},
        {"Remove `report.txt` from `/archive/` interactively.", "rm -i /archive/report.txt"}
    };

    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
        for (int j = 0; j < sizeof(questions) / sizeof(questions[0]); j++) {
            if (i == 0 && j >= 0 && j <= 3) {
                ask_question(&questions[j]);
            } else if (i == 1 && j >= 4 && j <= 8) {
                ask_question(&questions[j]);
            } else if (i == 2 && j >= 9 && j <= 11) {
                ask_question(&questions[j]);
            }
        }
    }
}

int main() {
    start_session();
    handle_lessons_and_questions();
    printf("Well done! You've completed Day 3 Lunch. Keep practicing to become proficient in Linux file and directory management.\n");
    return 0;
}