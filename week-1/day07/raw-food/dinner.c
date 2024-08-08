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

    printf("Welcome to Day 7 Dinner!\n");
    printf("In this session, we'll review and expand on Package Management and Archiving/Compression.\n");
    printf("We'll cover advanced scenarios and practice commands to solidify your understanding.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Advanced Package Management with `apt-get`",
            "Beyond basic installation and removal, `apt-get` offers advanced options for package management, including cleaning up unnecessary packages and fixing broken dependencies.",
            "Examples:\n  sudo apt-get autoremove               # Remove unnecessary packages\n  sudo apt-get clean                    # Clear out the local repository of retrieved package files\n  sudo apt-get -f install               # Fix broken dependencies"
        },
        {
            "Using `apt-cache` for Package Information",
            "The `apt-cache` command allows you to search for packages, display package information, and show package dependencies.",
            "Examples:\n  apt-cache search package_name         # Search for a package\n  apt-cache show package_name           # Display package information\n  apt-cache depends package_name        # Show package dependencies"
        },
        {
            "Advanced `dpkg` Commands",
            "The `dpkg` command has additional options for querying and managing packages, such as listing files installed by a package and checking package status.",
            "Examples:\n  dpkg -L package_name                  # List files installed by a package\n  dpkg -s package_name                  # Display package status\n  dpkg-reconfigure package_name         # Reconfigure an installed package"
        },
        {
            "Creating and Managing Archives with `tar`",
            "In addition to basic archiving and extraction, `tar` supports advanced options for handling file attributes and excluding files from archives.",
            "Examples:\n  tar -cvpzf archive.tar.gz /path/to/dir  # Create a tarball while preserving file permissions\n  tar -cvzf archive.tar.gz --exclude='*.log' /path/to/dir  # Exclude log files from the archive\n  tar -tvf archive.tar.gz                 # List contents of a tarball"
        },
        {
            "Using `rsync` for Efficient File Transfer",
            "The `rsync` command is powerful for synchronizing files and directories between locations, preserving file attributes, and minimizing data transfer.",
            "Examples:\n  rsync -avz /source/dir /destination/dir  # Synchronize directories with verbose output and compression\n  rsync -avz --delete /source/dir /destination/dir  # Delete files in destination that are not in source\n  rsync -avz -e ssh /source/dir user@remote:/destination/dir  # Use SSH for remote synchronization"
        }
    };

    // Questions
    Question questions[] = {
        {"What command removes unnecessary packages and dependencies?", "sudo apt-get autoremove"},
        {"How do you display the dependencies of a package using `apt-cache`?", "apt-cache depends package_name"},
                {"Which command lists files installed by a package using `dpkg`?", "dpkg -L package_name"},
        {"How do you create a tarball while preserving file permissions?", "tar -cvpzf archive.tar.gz /path/to/dir"},
        {"What command synchronizes directories using `rsync` with compression?", "rsync -avz /source/dir /destination/dir"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Congratulations! You've completed Day 7 Dinner.\n");
    printf("You should now have a solid understanding of advanced Package Management and Archiving/Compression techniques.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to finish...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}