#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LESSON_COUNT 7

// Structure to hold lesson information
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

    printf("Welcome to the Advanced File and Directory Management Challenge - Dinner!\n");
    printf("In this challenge, you'll explore additional commands for managing files and directories.\n");
    printf("Follow the lessons to understand each command, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Array of lessons
    Lesson lessons[LESSON_COUNT] = {
        {
            "Creating Symbolic Links",
            "The `ln` command is used to create links between files. The `-s` option creates a symbolic link, which is a reference to another file.",
            "Examples:\n  ln -s /path/to/original file_link    # Create a symbolic link 'file_link' to '/path/to/original'\n  ln file1.txt file_link                # Create a hard link to 'file1.txt'"
        },
        {
            "Finding Files by Type",
            "The `find` command can be used to locate files by type. The `-type` option specifies the type of file to search for.",
            "Examples:\n  find . -type f                # Find all regular files in the current directory and subdirectories\n  find . -type d                # Find all directories in the current directory and subdirectories\n  find /path -type l            # Find all symbolic links in '/path'"
        },
        {
            "Archiving Files",
            "The `tar` command is used to create and manipulate archive files. It can bundle multiple files into one archive file and compress it.",
            "Examples:\n  tar -cvf archive.tar file1.txt file2.txt   # Create a new archive 'archive.tar' with 'file1.txt' and 'file2.txt'\n  tar -xvf archive.tar                        # Extract files from 'archive.tar'\n  tar -czvf archive.tar.gz file1.txt          # Create a compressed archive 'archive.tar.gz'"
        },
        {
            "Searching for Files",
            "The `find` command can also be used to search for files based on various criteria, such as name, size, or modification time.",
            "Examples:\n  find . -name '*.txt'            # Find all files with a '.txt' extension\n  find . -size +1M                # Find all files larger than 1 MB\n  find . -mtime -7                # Find all files modified in the last 7 days"
        },
        {
            "Checking File Integrity",
            "The `md5sum` command calculates and verifies MD5 checksums. It's useful for checking file integrity and detecting corruption.",
            "Examples:\n  md5sum file.txt                 # Display the MD5 checksum of 'file.txt'\n  md5sum -c checksum.md5          # Check files against the checksums listed in 'checksum.md5'"
        },
        {
            "Scheduling Tasks",
            "The `cron` system allows scheduling tasks to run automatically at specified intervals. You edit cron jobs using the `crontab` command.",
            "Examples:\n  crontab -e                      # Edit the current user's cron jobs\n  crontab -l                      # List the current user's cron jobs\n  # Example cron job: '0 5 * * * /path/to/script.sh' runs 'script.sh' daily at 5 AM"
        },
        {
            "Monitoring System Performance",
            "The `top` command provides a real-time view of system processes and resource usage. It displays CPU and memory usage statistics.",
            "Examples:\n  top                             # Display real-time system statistics\n  top -u username                  # Show processes for a specific user\n  top -d 10                        # Refresh display every 10 seconds"
        }
    };

    // Display all lessons
    for (int i = 0; i < LESSON_COUNT; i++) {
        display_lesson(&lessons[i]);
    }

    // Quiz questions
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    ask_question("1. What command creates a symbolic link to a file?", "ln -s");
    ask_question("2. What command finds files by type?", "find");
    ask_question("3. What command creates and manipulates archive files?", "tar");
    ask_question("4. What command searches for files based on various criteria?", "find");
    ask_question("5. What command checks file integrity using MD5 checksums?", "md5sum");
    ask_question("6. What command schedules tasks to run automatically?", "crontab");
    ask_question("7. What command monitors system performance in real-time?", "top");

    printf("Challenge complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}
