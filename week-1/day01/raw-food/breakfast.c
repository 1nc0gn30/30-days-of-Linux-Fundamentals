#include <stdio.h>
#include <string.h>

// Structure to hold lesson information
struct Lesson {
    const char *command;
    const char *description;
    const char *examples;
};

// Function to display a lesson about a command
void display_lesson(const struct Lesson lesson) {
    printf("Lesson on `%s`:\n", lesson.command);
    printf("%s\n", lesson.description);
    printf("\n%s\n", lesson.examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and provide instructions
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
    printf("Welcome to the Linux Commands Quiz - Breakfast Challenge!\n");
    printf("In this interactive lesson, you will learn about basic Linux commands.\n");
    printf("Follow the lessons and examples to understand the commands, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Array of lessons
    struct Lesson lessons[] = {
        {
            "ls",
            "The `ls` command lists directory contents. It shows the files and directories in the specified directory.",
            "Examples:\n  ls                  # List files in the current directory\n  ls -l               # List files with detailed information, including permissions and size\n  ls -a               # List all files, including hidden files (those starting with a dot)\n  ls -lh              # List files with human-readable file sizes\n  ls -R               # Recursively list all subdirectories"
        },
        {
            "cd",
            "The `cd` command changes the current working directory. It's used to navigate through directories.",
            "Examples:\n  cd /home/user        # Change to the specified directory\n  cd ..                # Move up one directory\n  cd ~                 # Change to the home directory\n  cd -                 # Switch to the previous directory\n  cd /var/log          # Change to a specific directory"
        },
        {
            "touch",
            "The `touch` command creates a new empty file or updates the timestamp of an existing file. It's commonly used to create a new file quickly.",
            "Examples:\n  touch newfile.txt           # Create a new file named 'newfile.txt'\n  touch existingfile.txt      # Update the timestamp of 'existingfile.txt'\n  touch file1.txt file2.txt   # Create or update multiple files\n  touch -c non_existing_file.txt  # Create a new file only if it does not already exist"
        },
        {
            "rm",
            "The `rm` command removes (deletes) files or directories. Be cautious as this operation is irreversible and does not move files to a trash or recycle bin.",
            "Examples:\n  rm file.txt               # Remove the file named 'file.txt'\n  rm -i file.txt            # Prompt for confirmation before deleting the file\n  rm -r directory/         # Remove a directory and its contents recursively\n  rm -f file.txt            # Force delete the file, ignoring nonexistent files and without prompting"
        },
        {
            "pwd",
            "The `pwd` command prints the current working directory. It shows the full path to the directory you are currently in, which helps in navigating and managing files.",
            "Examples:\n  pwd                      # Print the full path of the current directory\n  pwd -L                   # Print the logical path (resolves symbolic links)\n  pwd -P                   # Print the physical path (without resolving symbolic links)"
        },
        {
            "mkdir",
            "The `mkdir` command creates a new directory. It is useful for organizing files into separate folders.",
            "Examples:\n  mkdir new_directory        # Create a new directory named 'new_directory'\n  mkdir -p parent/child      # Create parent and child directories; the `-p` flag creates parent directories if they do not exist\n  mkdir -m 755 new_dir       # Create a directory with specific permissions"
        },
        {
            "cp",
            "The `cp` command copies files or directories from one location to another. It can also be used to copy files and directories recursively.",
            "Examples:\n  cp file1.txt file2.txt     # Copy 'file1.txt' to 'file2.txt'\n  cp -r dir1/ dir2/          # Recursively copy directory 'dir1' to 'dir2'\n  cp -i file1.txt backup/    # Prompt before overwriting the file in 'backup/'\n  cp -u file1.txt destination/  # Copy only if 'file1.txt' is newer than the existing file in 'destination/'"
        },
        {
            "mv",
            "The `mv` command moves or renames files and directories. It can be used to move files from one location to another or to rename files and directories.",
            "Examples:\n  mv file1.txt /path/to/destination/     # Move 'file1.txt' to the specified directory\n  mv oldname.txt newname.txt             # Rename 'oldname.txt' to 'newname.txt'\n  mv -i file1.txt backup/                # Prompt before overwriting files in 'backup/'\n  mv -u file1.txt destination/           # Move only if 'file1.txt' is newer than the existing file in 'destination/'"
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(lessons[i]);
    }

    // Quiz questions
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Array of questions and answers
    struct {
        const char *question;
        const char *correct_answer;
    } questions[] = {
        {"1. What command lists all files and directories in the current directory?", "ls"},
        {"2. What command changes the current directory?", "cd"},
        {"3. What command creates a new file?", "touch"},
        {"4. What command removes a file?", "rm"},
        {"5. What command shows the current working directory?", "pwd"},
        {"6. What command creates a new directory?", "mkdir"},
        {"7. What command copies files or directories?", "cp"},
        {"8. What command moves or renames files or directories?", "mv"}
    };

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(questions[i].question, questions[i].correct_answer);
    }

    printf("Quiz complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}
