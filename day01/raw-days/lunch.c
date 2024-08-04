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

    printf("Welcome to the File and Directory Management Challenge - Lunch Game!\n");
    printf("In this challenge, you will learn about additional file and directory management commands.\n");
    printf("Follow the lessons to understand each command, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each task
    display_lesson(
        "Viewing File Contents",
        "The `cat` command displays the contents of a file. It can also be used to concatenate multiple files into one.",
        "Examples:\n  cat file.txt                # Display the contents of 'file.txt'\n  cat file1.txt file2.txt     # Concatenate 'file1.txt' and 'file2.txt' and display the result\n  cat file.txt > newfile.txt  # Redirect the contents of 'file.txt' to 'newfile.txt'"
    );

    display_lesson(
        "Copying Files",
        "The `cp` command copies files or directories. You can use various options to control the behavior of the copy operation.",
        "Examples:\n  cp file.txt backup/           # Copy 'file.txt' to the 'backup' directory\n  cp -r dir1/ dir2/             # Recursively copy 'dir1' directory to 'dir2'\n  cp -i file.txt backup/        # Prompt before overwriting files in the 'backup' directory"
    );

    display_lesson(
        "Changing File Permissions",
        "The `chmod` command changes the permissions of a file or directory. You can use symbolic or octal modes to specify permissions.",
        "Examples:\n  chmod 755 script.sh           # Set permissions to rwxr-xr-x for 'script.sh'\n  chmod u+x script.sh            # Add execute permission for the user on 'script.sh'\n  chmod go-rwx file.txt          # Remove all permissions for group and others on 'file.txt'"
    );

    display_lesson(
        "Displaying Disk Usage",
        "The `du` command shows the disk usage of files and directories. You can use various options to customize the output.",
        "Examples:\n  du -sh directory/             # Show the total disk usage of 'directory/' in a human-readable format\n  du -a                        # Show disk usage of all files and directories recursively\n  du -ch | grep total           # Show disk usage and find the total size"
    );

    display_lesson(
        "Viewing File Differences",
        "The `diff` command compares files line by line and shows the differences between them. It is useful for finding changes between versions of files.",
        "Examples:\n  diff file1.txt file2.txt       # Compare 'file1.txt' and 'file2.txt' and show differences\n  diff -u file1.txt file2.txt    # Show differences in a unified format (more readable)"
    );

    display_lesson(
        "Finding Files by Name",
        "The `locate` command searches for files and directories by name using a prebuilt index. This is faster than `find` but requires updating the database.",
        "Examples:\n  locate filename.txt            # Search for 'filename.txt' in the indexed database\n  locate -i pattern              # Perform a case-insensitive search for 'pattern'"
    );

    display_lesson(
        "Searching Within Files",
        "The `grep` command searches for text patterns within files. It is useful for finding specific content in large files or multiple files.",
        "Examples:\n  grep 'pattern' file.txt        # Search for 'pattern' in 'file.txt'\n  grep -r 'pattern' directory/   # Recursively search for 'pattern' in files within 'directory/'\n  grep -i 'pattern' file.txt     # Perform a case-insensitive search"
    );

    // Quiz questions
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    ask_question("1. What command displays the contents of a file?", "cat");
    ask_question("2. What command copies files or directories?", "cp");
    ask_question("3. What command changes file permissions?", "chmod");
    ask_question("4. What command shows disk usage?", "du");
    ask_question("5. What command compares two files and shows differences?", "diff");
    ask_question("6. What command searches for files by name using an index?", "locate");
    ask_question("7. What command searches for text patterns within files?", "grep");

    printf("Challenge complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}

