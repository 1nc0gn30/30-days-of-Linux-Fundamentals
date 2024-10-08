#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// Struct for lessons
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct for questions
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

// Main function
int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to the File and Directory Management Challenge - Breakfast!\n");
    printf("In this challenge, you'll learn about file attributes, process management, and permissions.\n");
    printf("Follow the lessons to understand each command, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Array of lessons
    Lesson lessons[] = {
        {"Changing File Ownership",
         "The `chown` command changes the ownership of a file or directory. It can change both the user and group ownership.",
         "Examples:\n  chown user:group file.txt           # Change owner to 'user' and group to 'group'\n  chown user file.txt                  # Change owner to 'user', group remains unchanged\n  chown :group file.txt                # Change group to 'group', owner remains unchanged"},

        {"Changing File Attributes",
         "The `chattr` command changes file attributes on a Linux file system. It can set attributes like immutability or append-only.",
         "Examples:\n  chattr +i file.txt                   # Set the immutable attribute on 'file.txt', preventing modifications\n  chattr -i file.txt                   # Remove the immutable attribute from 'file.txt'\n  lsattr file.txt                      # List the attributes of 'file.txt'"},

        {"Displaying Running Processes",
         "The `ps` command displays information about active processes. It provides a snapshot of current processes.",
         "Examples:\n  ps                                # Display processes running in the current shell\n  ps aux                            # Display detailed information about all processes\n  ps -ef                            # Show processes in full format including user and command"},

        {"Monitoring System Activity",
         "The `top` command provides a dynamic, real-time view of system processes. It shows CPU and memory usage, along with process details.",
         "Examples:\n  top                                # Start the top command to view real-time system activity\n  top -u username                     # Show processes for a specific user\n  top -d 10                           # Refresh the display every 10 seconds"},

        {"Viewing and Controlling Processes",
         "The `kill` command sends signals to processes. It can terminate or control processes by their PID (Process ID).",
         "Examples:\n  kill PID                            # Send the default TERM signal to the process with ID 'PID'\n  kill -9 PID                         # Forcefully terminate the process with 'PID' using the KILL signal\n  pkill process_name                  # Send signals to all processes with the name 'process_name'"}
    };

    // Array of questions
    Question questions[] = {
        {"1. What command changes the ownership of a file?", "chown"},
        {"2. What command changes file attributes like immutability?", "chattr"},
        {"3. What command displays information about active processes?", "ps"},
        {"4. What command provides a real-time view of system activity?", "top"},
        {"5. What command sends signals to processes to control them?", "kill"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Quiz questions
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Challenge complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}
