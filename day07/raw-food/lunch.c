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

    printf("Welcome to Day 7 Lunch!\n");
    printf("In this session, we'll dive deeper into Package Management and Archiving/Compression.\n");
    printf("We'll explore advanced commands and scenarios to enhance your skills.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each command
    display_lesson(
        "Upgrading Packages (`apt-get dist-upgrade`)",
        "The `apt-get dist-upgrade` command not only upgrades packages but also handles dependencies intelligently. It can add or remove packages as necessary.",
        "Examples:\n  sudo apt-get dist-upgrade     # Upgrade packages, handling dependencies"
    );

    display_lesson(
        "Managing PPAs (`add-apt-repository`)",
        "The `add-apt-repository` command allows you to add Personal Package Archives (PPAs) to your system, enabling you to install software from third-party repositories.",
        "Examples:\n  sudo add-apt-repository ppa:repository_name     # Add a PPA\n  sudo apt-get update                             # Update package list\n  sudo apt-get install package_name               # Install package from PPA"
    );

    display_lesson(
        "Using `dpkg` for Package Management",
        "The `dpkg` command is a low-level package manager for Debian-based systems. It can be used to install, remove, and manage .deb packages.",
        "Examples:\n  sudo dpkg -i package.deb        # Install a .deb package\n  sudo dpkg -r package_name        # Remove an installed package\n  dpkg -l                          # List all installed packages"
    );

    display_lesson(
        "Creating and Extracting Archives with `tar`",
        "The `tar` command is versatile for creating and managing archive files. It supports various compression methods.",
        "Examples:\n  tar -cvf archive.tar file1 file2      # Create a tar archive\n  tar -czvf archive.tar.gz file1 file2   # Create a gzip-compressed tar archive\n  tar -xvf archive.tar                  # Extract a tar archive\n  tar -xzvf archive.tar.gz              # Extract a gzip-compressed tar archive"
    );

    display_lesson(
        "Using `zip` and `unzip`",
        "The `zip` and `unzip` commands are used for compressing and decompressing files in zip format, respectively.",
        "Examples:\n  zip archive.zip file1 file2         # Create a zip archive\n  unzip archive.zip                   # Extract a zip archive"
    );

    display_lesson(
        "Using `gzip` and `gunzip`",
        "The `gzip` command compresses files using the gzip algorithm, while `gunzip` decompresses them.",
        "Examples:\n  gzip file                          # Compress a file\n  gunzip file.gz                      # Decompress a file"
    );

    // Sample questions
    ask_question(
        "What command would you use to add a PPA to your system?",
        "sudo add-apt-repository ppa:repository_name"
    );

    ask_question(
        "How do you upgrade packages and handle dependencies using apt-get?",
        "sudo apt-get dist-upgrade"
    );

    ask_question(
        "Which command installs a .deb package using dpkg?",
        "sudo dpkg -i package.deb"
    );

    ask_question(
        "How do you create a gzip-compressed tar archive?",
        "tar -czvf archive.tar.gz file1 file2"
    );

    ask_question(
        "What command extracts files from a zip archive?",
        "unzip archive.zip"
    );

    return 0;
}

