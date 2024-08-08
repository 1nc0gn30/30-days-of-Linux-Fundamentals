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

    printf("Welcome to Day 4 Breakfast: File Viewing and Editing!\n");
    printf("In this session, we will explore commands related to viewing and editing files.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Viewing File Contents (`cat`)",
            "The `cat` command is used to display the contents of a file. It can also be used to concatenate multiple files into one and redirect output to new files.",
            "Examples:\n  cat file.txt                # Display the contents of 'file.txt'\n  cat file1.txt file2.txt     # Concatenate 'file1.txt' and 'file2.txt' and display the result\n  cat file.txt > newfile.txt  # Redirect the contents of 'file.txt' to 'newfile.txt'\n  cat file.txt | less         # View the contents of 'file.txt' page by page"
        },
        {
            "Viewing File Contents with `more` and `less`",
            "The `more` and `less` commands are used for viewing file contents one page at a time. They are useful for large files that don't fit on one screen.",
            "Examples:\n  more file.txt               # View 'file.txt' one page at a time\n  less file.txt               # View 'file.txt' with navigation capabilities\n  less +G file.txt            # Start viewing at the end of the file"
        },
        {
            "Basic Text Editing with `nano`",
            "The `nano` editor is a simple, user-friendly text editor for editing files. It’s good for quick edits and learning basic text editing commands.",
            "Examples:\n  nano file.txt               # Open 'file.txt' for editing\n  nano +5 file.txt            # Open 'file.txt' and jump to line 5\n  nano -c file.txt            # Show line numbers while editing"
        },
        {
            "Basic Text Editing with `vim`",
            "The `vim` editor is a powerful text editor with a steeper learning curve. It offers advanced features for text manipulation and editing.",
            "Examples:\n  vim file.txt                # Open 'file.txt' in vim\n  vim +5 file.txt             # Open 'file.txt' and jump to line 5\n  :wq                         # Save changes and exit vim\n  :q!                         # Quit vim without saving changes"
        },
        {
            "Searching within Files (`grep`)",
            "The `grep` command searches for text patterns within files. It's useful for finding specific content in large files or multiple files.",
            "Examples:\n  grep 'pattern' file.txt      # Search for 'pattern' in 'file.txt'\n  grep -r 'pattern' directory/ # Recursively search for 'pattern' in 'directory/'\n  grep -i 'pattern' file.txt   # Perform a case-insensitive search"
        },
        {
            "Editing Files with `sed`",
            "The `sed` command is a stream editor that can perform basic text transformations on an input stream (a file or input from a pipeline).",
            "Examples:\n  sed 's/old/new/' file.txt    # Replace 'old' with 'new' in 'file.txt'\n  sed -i 's/old/new/' file.txt  # Edit 'file.txt' in-place to replace 'old' with 'new'\n  sed -n '1,5p' file.txt       # Print lines 1 through 5 of 'file.txt'"
        }
    };

    // Questions
    Question questions[] = {
        {"What command would you use to view the contents of a file one page at a time?", "more"},
        {"Which text editor is known for its advanced features but has a steeper learning curve?", "vim"},
        {"How do you perform a case-insensitive search for a pattern in a file using `grep`?", "grep -i 'pattern' file.txt"},
        {"What command can you use to replace 'old' with 'new' in a file using `sed`?", "sed 's/old/new/' file.txt"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Day 4 Breakfast is complete! Press Enter to end...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}