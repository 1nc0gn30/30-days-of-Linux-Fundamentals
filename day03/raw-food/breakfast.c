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

    printf("Welcome to Day 3 Breakfast: Advanced File and Directory Management!\n");
    printf("It’s great to see you made it through the first two days. Today, we will deepen your knowledge in creating, copying, moving, and renaming files, as well as navigating directories with advanced commands and techniques.\n");
    printf("Follow the lessons and examples to enhance your skills, and then test your knowledge with some questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each topic
    display_lesson(
        "Creating Files with Advanced Techniques",
        "The `touch` command is often used to create new files or update timestamps, but there are additional techniques for creating files. For instance, using `cat` or `echo` for quick file creation.",
        "Examples:\n  touch file1.txt            # Create a new empty file named 'file1.txt'\n  echo 'Initial content' > file2.txt # Create 'file2.txt' with initial content\n  cat > file3.txt <<EOF\nThis is a new file.\nEOF\n  # Create 'file3.txt' with multiline content\n"
    );

    display_lesson(
        "Copying Files and Directories",
        "The `cp` command copies files and directories. Advanced options allow for interactive copying, preserving attributes, and handling symbolic links.",
        "Examples:\n  cp file1.txt backup/            # Copy 'file1.txt' to 'backup' directory\n  cp -r source/ destination/      # Recursively copy 'source' directory to 'destination'\n  cp -a source/ destination/      # Archive mode: Copy files and preserve attributes (like symlinks)\n  cp -u file1.txt backup/         # Copy only if 'file1.txt' is newer than the existing file in 'backup/'\n  cp -i file1.txt backup/         # Prompt before overwriting files in 'backup/'"
    );

    display_lesson(
        "Moving and Renaming Files",
        "The `mv` command is used for moving or renaming files and directories. Learn to use options for interactive mode, and handling overwrite situations.",
        "Examples:\n  mv file1.txt /path/to/destination/   # Move 'file1.txt' to the specified directory\n  mv oldname.txt newname.txt           # Rename 'oldname.txt' to 'newname.txt'\n  mv -i file1.txt backup/              # Prompt before overwriting files in 'backup/'\n  mv -u file1.txt destination/         # Move only if 'file1.txt' is newer than the existing file in 'destination/'"
    );

    display_lesson(
        "Advanced Directory Navigation",
        "The `cd` command changes directories, but advanced usage includes navigating with shortcuts, handling symbolic links, and tracking your path.",
        "Examples:\n  cd /path/to/directory       # Change to the specified directory\n  cd ..                       # Move up one directory\n  cd -                        # Switch to the previous directory\n  cd ~                        # Change to the home directory\n  cd /                        # Change to the root directory\n  cd -P /path/to/symlink      # Resolve symbolic links to physical directories"
    );

    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    ask_question("1. What command can create a new file with initial content?", "echo 'Initial content' > file.txt");
    ask_question("2. How do you recursively copy a directory and its contents?", "cp -r source/ destination/");
    ask_question("3. What command is used to move a file to a different directory?", "mv file.txt /path/to/destination/");
    ask_question("4. How can you rename a file in the current directory?", "mv oldname.txt newname.txt");
    ask_question("5. How can you switch to the previous directory you were in?", "cd -");

    printf("Breakfast complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}

