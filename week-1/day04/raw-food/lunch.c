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
    printf("Examples:\n%s\n", lesson->examples);
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

    printf("Welcome to Day 4 Lunch: Advanced File Editing and Understanding Permissions!\n");
    printf("Today, we will delve deeper into `vim` and `nano` editors and explore file permissions in detail.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Advanced Editing with `vim`",
            "The `vim` editor offers powerful features for editing text. Understanding these advanced functionalities can significantly enhance your productivity.",
            "Examples:\n  i                          # Enter insert mode\n  :w                          # Save changes\n  :q                          # Quit vim\n  :wq                         # Save and quit\n  :x                          # Save and quit (alternative to :wq)\n  /pattern                    # Search for 'pattern'\n  :%s/old/new/g               # Replace 'old' with 'new' globally in the file\n  :set number                 # Show line numbers\n  :!command                   # Execute an external command (e.g., :!ls to list files)"
        },
        {
            "Advanced Editing with `nano`",
            "The `nano` text editor is simpler but also supports several advanced editing features that can be useful for quick file modifications.",
            "Examples:\n  ^K                         # Cut a line (Ctrl+K)\n  ^U                         # Paste the cut line (Ctrl+U)\n  ^W                         # Search for text (Ctrl+W)\n  ^_                         # Go to a specific line number (Ctrl+_)\n  ^O                         # Save the file (Ctrl+O)\n  ^X                         # Exit the editor (Ctrl+X)\n  ^J                         # Justify (wrap) text (Ctrl+J)"
        },
        {
            "Understanding File Permissions",
            "File permissions in Linux are represented by three sets of permissions for the owner, group, and others. Each set has read (r), write (w), and execute (x) permissions.",
            "Examples:\n  rwxr-xr-x                  # Permissions breakdown\n  755                          # Numeric representation\n  chmod 755 file.txt          # Set permissions to rwxr-xr-x\n  chmod u+x file.txt          # Add execute permission for the user\n  chmod go-r file.txt         # Remove read permission for group and others\n  ls -l file.txt              # Show file permissions in long listing format"
        },
      
                    {
            "Permission Values and Calculation",
            "Permissions are represented numerically with a three-digit octal number. Each digit corresponds to the permissions for owner, group, and others respectively.",
            "Examples:\n  4 = r (read)\n  2 = w (write)\n  1 = x (execute)\n  7 = rwx (read, write, execute)\n  644 = rw-r--r-- (owner has read/write, group/others have read only)\n  755 = rwxr-xr-x (owner has read/write/execute, group/others have read/execute)"
        }
    };

    // Questions
    Question questions[] = {
        {"How do you replace 'old' with 'new' globally in `vim`?", ":%s/old/new/g"},
        {"In `nano`, what command is used to save the file?", "^O"},
        {"What does the permission value '755' represent?", "rwxr-xr-x"},
        {"How is the numeric permission value '644' broken down?", "rw-r--r--"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Day 4 Lunch is complete! Press Enter to end...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}