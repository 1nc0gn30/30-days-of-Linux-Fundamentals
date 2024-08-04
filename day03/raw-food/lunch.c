#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a lesson and prompt user
void display_lesson(const char *topic, const char *description, const char *examples) {
    printf("Lesson on `%s`:\n", topic);
    printf("%s\n", description);
    printf("Examples:\n%s\n", examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const char *question, const char *correct_answer) {
    char answer[100];
    printf("%s\n", question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to Day 3 Lunch!\n");
    printf("In this session, we'll delve into advanced file and directory management, as well as file viewing and editing.\n");
    printf("Follow the lessons and complete the tasks to test your skills.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each command
    display_lesson(
        "Create, Copy, Move, and Rename Files",
        "This section covers advanced file management tasks including creating, copying, moving, and renaming files.",
        "Examples:\n  touch file1.txt           # Create an empty file\n  echo 'Hello World' > file2.txt  # Create a file with content\n  cp file1.txt /backup/     # Copy file to a directory\n  mv file1.txt /path/        # Move file to a new location\n  mv oldname.txt newname.txt # Rename a file"
    );

    ask_question(
        "Create a file named `testfile.txt` with content 'Test Content'.",
        "echo 'Test Content' > testfile.txt"
    );

    ask_question(
        "Copy `testfile.txt` to a directory named `backup/`.",
        "cp testfile.txt backup/"
    );

    ask_question(
        "Rename `testfile.txt` to `renamedfile.txt` and move it to `backup/`.",
        "mv testfile.txt backup/renamedfile.txt"
    );

    ask_question(
        "Recursively copy the `backup/` directory to `archive/`.",
        "cp -r backup/ archive/"
    );

    display_lesson(
        "Directory Navigation and Manipulation",
        "This section focuses on navigating through directories and manipulating them.",
        "Examples:\n  cd /path/to/directory       # Change to a specified directory\n  cd ..                       # Move up one directory\n  mkdir -p parent/child       # Create nested directories\n  rmdir emptydir/             # Remove an empty directory\n  rm -r nonemptydir/          # Remove a non-empty directory"
    );

    ask_question(
        "Navigate to the `/etc` directory.",
        "cd /etc"
    );

    ask_question(
        "Create a directory structure `/data/archive/2024`.",
        "mkdir -p /data/archive/2024"
    );

    ask_question(
        "Change the permissions of `/data` to `755`.",
        "chmod 755 /data"
    );

    ask_question(
        "Display the size of the `/home/user` directory.",
        "du -sh /home/user"
    );

    ask_question(
        "Remove the `/data/archive/2024` directory and all its contents.",
        "rm -r /data/archive/2024"
    );

    display_lesson(
        "File Management Scavenger Hunt",
        "This scavenger hunt will test your ability to find, manage, and handle files based on specific criteria.",
        "Examples:\n  find /path -name '*.log'   # Find all .log files in a directory\n  grep 'pattern' file.txt    # Search for a pattern in a file\n  mv file.txt /path/          # Move a file to a directory\n  cp -i file.txt /path/       # Copy a file with interactive prompt\n  rm -i file.txt              # Remove a file with interactive prompt"
    );

    ask_question(
        "Find all `.log` files in `/var/log`.",
        "find /var/log -name '*.log'"
    );

    ask_question(
        "Search for the pattern 'Error' in `/var/log/syslog`.",
        "grep 'Error' /var/log/syslog"
    );

    ask_question(
        "Move a file named `report.txt` from `/home/user/` to `/archive/`.",
        "mv /home/user/report.txt /archive/"
    );

    ask_question(
        "Create a backup of `report.txt` in `/backup/` without overwriting existing files.",
        "cp -u /home/user/report.txt /backup/"
    );

    ask_question(
        "Remove `report.txt` from `/archive/` interactively.",
        "rm -i /archive/report.txt"
    );

    printf("Well done! You've completed Day 3 Lunch. Keep practicing to become proficient in Linux file and directory management.\n");
    return 0;
}

