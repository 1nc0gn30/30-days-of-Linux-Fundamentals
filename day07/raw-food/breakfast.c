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

    printf("Welcome to Day 7 Breakfast!\n");
    printf("In this session, we'll explore Package Management and Archiving/Compression.\n");
    printf("We'll cover commands to manage software packages and work with file archives.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each command

    // Package Management
    display_lesson(
        "Installing Packages (`apt-get`, `yum`)",
        "Package managers help you install, update, and remove software packages.",
        "Examples:\n  sudo apt-get install package_name      # Install a package on Debian-based systems\n  sudo yum install package_name          # Install a package on RHEL-based systems\n  sudo dnf install package_name          # Install a package using DNF\n  sudo pacman -S package_name            # Install a package on Arch-based systems"
    );

    display_lesson(
        "Removing Packages (`apt-get`, `yum`)",
        "You can remove installed software packages using package managers.",
        "Examples:\n  sudo apt-get remove package_name       # Remove a package on Debian-based systems\n  sudo yum remove package_name           # Remove a package on RHEL-based systems\n  sudo dnf remove package_name           # Remove a package using DNF\n  sudo pacman -R package_name            # Remove a package on Arch-based systems"
    );

    display_lesson(
        "Updating Packages (`apt-get`, `yum`)",
        "Keep your software up to date using package managers.",
        "Examples:\n  sudo apt-get update                    # Update package list on Debian-based systems\n  sudo apt-get upgrade                   # Upgrade all packages on Debian-based systems\n  sudo yum update                        # Update all packages on RHEL-based systems\n  sudo dnf update                        # Update all packages using DNF\n  sudo pacman -Syu                       # Synchronize and update all packages on Arch-based systems"
    );

    // Archiving and Compression
    display_lesson(
        "Creating Archives (`tar`)",
        "The `tar` command is used to create and manage archive files.",
        "Examples:\n  tar -cvf archive.tar file1 file2       # Create a tar archive\n  tar -czvf archive.tar.gz file1 file2    # Create a gzip-compressed tar archive\n  tar -cjvf archive.tar.bz2 file1 file2   # Create a bzip2-compressed tar archive"
    );

    display_lesson(
        "Extracting Archives (`tar`)",
        "You can extract files from an archive using the `tar` command.",
        "Examples:\n  tar -xvf archive.tar                   # Extract a tar archive\n  tar -xzvf archive.tar.gz                # Extract a gzip-compressed tar archive\n  tar -xjvf archive.tar.bz2               # Extract a bzip2-compressed tar archive"
    );

    display_lesson(
        "Compressing Files (`gzip`, `bzip2`, `xz`)",
        "Various tools are available for file compression.",
        "Examples:\n  gzip file                             # Compress a file using gzip\n  bzip2 file                            # Compress a file using bzip2\n  xz file                               # Compress a file using xz\n  gzip -d file.gz                       # Decompress a gzip file\n  bzip2 -d file.bz2                     # Decompress a bzip2 file\n  xz -d file.xz                         # Decompress an xz file"
    );

    // Sample questions
    ask_question(
        "What command would you use to install a package on a Debian-based system?",
        "sudo apt-get install package_name"
    );

    ask_question(
        "Which command will create a gzip-compressed tar archive?",
        "tar -czvf archive.tar.gz file1 file2"
    );

    return 0;
}

