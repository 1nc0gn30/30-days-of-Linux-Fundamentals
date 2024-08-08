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

    printf("Welcome to the Comprehensive Review and Advanced Concepts Dinner Challenge!\n");
    printf("In this challenge, you will review and expand on the commands learned in Day 3 breakfast and lunch.\n");
    printf("Follow the lessons to understand each command in detail, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Creating Files (`touch`, `cat`, `echo`)",
            "The `touch` command creates or updates files. The `cat` command displays and concatenates file contents. The `echo` command creates files with content.",
            "Examples:\n  touch newfile.txt                          # Create an empty file\n  cat file1.txt file2.txt > combined.txt    # Combine content of two files into a new file\n  echo \"Hello, World!\" > hello.txt          # Create a file with content"
        },
        {
            "Copying Files (`cp`, `rsync`)",
            "The `cp` command copies files or directories. The `rsync` command synchronizes files and directories between locations.",
            "Examples:\n  cp file.txt backup/                       # Copy file to backup directory\n  cp -r dir1/ dir2/                        # Recursively copy directory\n  rsync -avz source/ destination/          # Sync files with verbose output\n  rsync --delete source/ destination/     # Sync files and delete those no longer in source"
        },
        {
            "Moving and Renaming Files (`mv`, `rename`)",
            "The `mv` command moves or renames files and directories. The `rename` command allows renaming multiple files using patterns.",
            "Examples:\n  mv oldfile.txt newfile.txt               # Rename a file\n  mv file.txt /path/to/destination/        # Move file to another directory\n  rename 's/.txt/.bak/' *.txt              # Rename all .txt files to .bak"
        },
        {
            "Navigating Directories (`cd`, `pwd`, `find`)",
            "The `cd` command changes directories. The `pwd` command prints the current directory. The `find` command searches for files and directories.",
            "Examples:\n  cd /home/user                          # Change to a specific directory\n  pwd                                    # Print the current directory path\n  find /path/to/search -name \"*.txt\"     # Find .txt files under a path\n  find . -type f -exec ls -lh {} \\;     # List details of all files found"
        },
        {
            "Advanced File Operations (`ln`, `stat`, `file`)",
            "The `ln` command creates hard and symbolic links. The `stat` command displays file status. The `file` command determines file type.",
            "Examples:\n  ln -s /path/to/original /path/to/link   # Create a symbolic link\n  stat file.txt                           # Display file status\n  file file.txt                           # Determine the file type"
        },
        {
            "Combining Commands (`xargs`, `tee`, `awk`)",
            "The `xargs` command builds and executes command lines from standard input. The `tee` command writes to files and standard output. The `awk` command processes text.",
            "Examples:\n  find . -name \"*.log\" | xargs rm       # Find and delete all .log files\n  echo \"Hello, World!\" | tee hello.txt  # Write to file and output to terminal\n  awk '{print $1}' file.txt             # Print the first field of each line"
        }
    };

    // Questions
    Question questions[] = {
        {"1. What command creates an empty file?", "touch"},
        {"2. How do you recursively copy a directory?", "cp -r"},
        {"3. What command renames multiple files using a pattern?", "rename"},
        {"4. How do you find all .txt files under a directory?", "find /path/to/search -name \"*.txt\""},
        {"5. What command creates a symbolic link?", "ln -s"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Challenge complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}