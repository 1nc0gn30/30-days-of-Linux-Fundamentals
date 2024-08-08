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

    printf("Welcome to Day 4 Dinner: Comprehensive Review and Advanced Topics!\n");
    printf("We will review the concepts from breakfast and lunch, and dive deeper into each topic.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Advanced Editing with `vim` - Review",
            "Review of `vim` editor commands and additional advanced features.",
            "Examples:\n  :e filename          # Open a new file for editing\n  :set nonumber        # Hide line numbers\n  :set wrap            # Wrap long lines\n  :!ls                # Run 'ls' command within `vim`\n  :diffsplit file2.txt  # Compare current file with 'file2.txt' using a side-by-side diff view\n  :syntax on           # Enable syntax highlighting\n  :tabnew              # Open a new tab in `vim`\n  :tabnext             # Switch to the next tab\n  :bdelete             # Close a buffer"
        },
        {
            "Advanced Editing with `nano` - Review",
            "Review of `nano` editor commands and additional features.",
            "Examples:\n  ^T                    # Invoke the spell checker (if available)\n  ^G                    # Display help\n  ^C                    # Display cursor position\n  ^R                    # Insert a file into the current file (Ctrl+R)\n  ^W, ^R                # Search and replace (Ctrl+W, Ctrl+R)\n  ^K, ^U                # Cut and paste multiple lines\n  ^J                    # Justify (wrap) text\n  ^X, ^A                # Exit and confirm changes (Ctrl+X, Ctrl+A)"
        },
        {
            "Understanding File Permissions - Review",
            "In-depth review of file permissions and their numerical representation.",
            "Examples:\n  chmod 700 file.txt    # Permissions: rwx------ (full access for owner)\n  chmod 666 file.txt    # Permissions: rw-rw-rw- (read/write for all users)\n  chmod 400 file.txt    # Permissions: r-------- (read-only for owner)\n  chmod u+s file.txt    # Setuid bit: executable will run with the file owner’s permissions\n  chmod g+s directory/  # Setgid bit: new files in the directory inherit the group ownership"
        },
                {
            "Permission Values and Calculation - Review",
            "Detailed breakdown of numeric permission values and how to calculate them.",
            "Examples:\n  750 = rwxr-x--- (owner has read/write/execute, group has read/execute, others have no permissions)\n  775 = rwxrwxr-x (owner/group have read/write/execute, others have read/execute)\n  600 = rw------- (owner has read/write, group/others have no permissions)\n  444 = r--r--r-- (read-only for everyone)\n  111 = --x--x--x (execute only for everyone)"
        },
        {
            "Advanced File Manipulation - Review",
            "Explore advanced techniques for file manipulation and editing.",
            "Examples:\n  cp -u source.txt destination/  # Copy only if source.txt is newer than destination/\n  mv -i oldname.txt newname.txt  # Prompt before overwriting 'newname.txt'\n  nano -B file.txt               # Backup file before editing with `nano`\n  vim -d file1.txt file2.txt     # Compare differences between file1.txt and file2.txt using `vim` diff mode\n  find /path -type f -exec chmod 644 {} + # Find all files in /path and set permissions to 644"
        }
    };

    // Questions
    Question questions[] = {
        {"How do you open a new file for editing in `vim`?", ":e filename"},
        {"In `nano`, what command is used to insert another file into the current file?", "^R"},
        {"What do the permissions '700' represent?", "rwx------"},
        {"How would you set permissions to 'read-only for everyone'?", "chmod 444 file.txt"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Day 4 Dinner is complete! Press Enter to end...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}