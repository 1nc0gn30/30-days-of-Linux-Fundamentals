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

    printf("Welcome to Day 08 Lunch Session!\n");
    printf("In this session, we'll dive deeper into Linux fundamentals, exploring file permissions, editing scripts, and user management.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "File Permissions and Ownership",
            "Understanding file permissions and ownership is crucial for managing security and access in a Linux system. Permissions dictate who can read, write, or execute a file.\n"
            "Each file has an owner and a group, and permissions can be set separately for the owner, the group, and others.\n"
            "Common commands include `chmod` to change permissions and `chown` to change ownership.",
            "Examples:\n"
            "  chmod 755 myscript.sh\n"
            "  chown user:group myfile.txt\n"
            "For more details, refer to the official documentation at https://man7.org/linux/man-pages/man1/chmod.1.html."
        },
        {
            "Editing Shell Scripts",
            "Editing and updating shell scripts is a routine task in system administration. Knowing how to use text editors like `vi`, `nano`, or `emacs` is essential.\n"
            "Basic operations include opening a file, editing content, saving changes, and executing scripts.",
            "Examples:\n"
            "  vi myscript.sh\n"
            "  nano myscript.sh\n"
            "For a complete guide, you can refer to the `vi` editor tutorial at https://www.washington.edu/computing/unix/vi.html."
        },
        {
            "User and Group Management",
            "Managing users and groups is a key aspect of system administration. This involves adding, deleting, and modifying users, as well as assigning them to groups.\n"
            "Commands like `useradd`, `usermod`, and `groupadd` are fundamental tools for these tasks.",
            "Examples:\n"
            "  useradd newuser\n"
            "  passwd newuser\n"
            "  usermod -aG groupname username\n"
            "  groupadd newgroup\n"
            "For further reading, check out the Linux User Management Guide at https://www.tecmint.com/manage-users-and-groups-in-linux/"
        }
    };

    // Questions
    Question questions[] = {
        {
            "1. What command is used to change file permissions?\n"
            "Hint: Use the format `command [options] filename`.\n"
            "Format: The command is `***** [permissions] [filename]`.",
            "chmod [permissions] [filename]"
        },
        {
            "2. How do you change the ownership of a file?\n"
            "Hint: Mention the command used to change both the user and group ownership.\n"
            "Format: The command is `***** [user]:[group] [filename]`.",
            "chown [user]:[group] [filename]"
        },
        {
            "3. How can you edit a script using the vi editor?\n"
            "Hint: Explain how to open a file in `vi` and the basic command to enter insert mode.\n"
            "Format: You use the command `** [filename]`, then press `*` to enter insert mode.",
            "vi [filename], then press 'i' to enter insert mode"
        },
        {
            "4. What command adds a new user to the system?\n"
            "Hint: Provide the command that is followed by the username.\n"
            "Format: The command is `******** [username]`.",
            "useradd [username]"
        },
        {
            "5. How do you add a user to a group?\n"
            "Hint: Use the command that modifies a user to include group membership.\n"
            "Format: The command is `***** -** [groupname] [username]`.",
            "usermod -aG [groupname] [username]"
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    return 0;
}
