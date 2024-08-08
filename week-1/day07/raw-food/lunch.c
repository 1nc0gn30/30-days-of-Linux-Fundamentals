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

    printf("Welcome to Day 7 Lunch!\n");
    printf("In this session, we'll dive deeper into Package Management and Archiving/Compression.\n");
    printf("We'll explore advanced commands and scenarios to enhance your skills.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Upgrading Packages (`apt-get dist-upgrade`)",
            "The `apt-get dist-upgrade` command not only upgrades packages but also handles dependencies intelligently. It can add or remove packages as necessary.",
            "Examples:\n  sudo apt-get dist-upgrade     # Upgrade packages, handling dependencies"
        },
        {
            "Managing PPAs (`add-apt-repository`)",
            "The `add-apt-repository` command allows you to add Personal Package Archives (PPAs) to your system, enabling you to install software from third-party repositories.",
            "Examples:\n  sudo add-apt-repository ppa:repository_name     # Add a PPA\n  sudo apt-get update                             # Update package list\n  sudo apt-get install package_name               # Install package from PPA"
        },
        {
            "Using `dpkg` for Package Management",
            "The `dpkg` command is a low-level package manager for Debian-based systems. It can be used to install, remove, and manage .deb packages.",
            "Examples:\n  sudo dpkg -i package.deb        # Install a .deb package\n  sudo dpkg -r package_name        # Remove an installed package\n  dpkg -l                          # List all installed packages"
        },
        {
            "Creating and Extracting Archives with `tar`",
            "The `tar` command is versatile for creating and managing archive files. It supports various compression methods.",
            "Examples:\n  tar -cvf archive.tar file1 file2      # Create a tar archive\n  tar -czvf archive.tar.gz file1 file2   # Create a gzip-compressed tar archive\n  tar -xvf archive.tar                  # Extract a tar archive\n  tar -xzvf archive.tar.gz              # Extract a gzip-compressed tar archive"
        },
        {
            "Using `zip` and `unzip`",
            "The `zip` and `unzip` commands are used for compressing and decompressing files in zip format, respectively.",
            "Examples:\n  zip archive.zip file1 file2         # Create a zip archive\n  unzip archive.zip                   # Extract a zip archive"
        },
        {
            "Using `gzip` and `gunzip`",
            "The `gzip` command compresses files using the gzip algorithm, while `gunzip` decompresses them.",
            "Examples:\n  gzip file                          # Compress a file\n  gunzip file.gz                      # Decompress a file"
        }
    };

    // Questions
    Question questions[] = {
        {"What command would you use to add a PPA to your system?", "sudo add-apt-repository ppa:repository_name"},
                {"How do you upgrade packages and handle dependencies using apt-get?", "sudo apt-get dist-upgrade"},
        {"Which command installs a .deb package using dpkg?", "sudo dpkg -i package.deb"},
        {"How do you create a gzip-compressed tar archive?", "tar -czvf archive.tar.gz file1 file2"},
        {"What command extracts files from a zip archive?", "unzip archive.zip"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Congratulations on completing Day 7 Lunch!\n");
    printf("You have learned about advanced Package Management and Archiving/Compression techniques.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}