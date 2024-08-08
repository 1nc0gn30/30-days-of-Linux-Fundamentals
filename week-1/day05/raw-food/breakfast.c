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

    printf("Welcome to Day 5 Breakfast!\n");
    printf("In this session, we'll dive into processes and system monitoring.\n");
    printf("We'll explore commands to manage processes and monitor system resources.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Viewing Processes (`ps`)",
            "The `ps` command displays information about active processes. It helps you see which processes are running and their status.",
            "Examples:\n  ps                  # List processes running in the current shell\n  ps aux              # Display detailed information about all running processes\n  ps -ef              # Show all processes in full format\n  ps -e -o pid,comm   # Display only process ID and command name"
        },
        {
            "Monitoring Processes (`top`)",
            "The `top` command provides a dynamic, real-time view of system processes. It updates periodically and shows system resource usage.",
            "Examples:\n  top                  # Display a real-time list of processes and system resource usage\n  top -u username       # Show processes belonging to a specific user\n  top -d 5              # Update the display every 5 seconds\n  top -b -n 1           # Run `top` in batch mode for a single update"
        },
        {
            "Killing Processes (`kill`, `killall`, `pkill`)",
            "The `kill`, `killall`, and `pkill` commands are used to send signals to processes, usually to terminate them. They offer different ways to specify which processes to kill.",
            "Examples:\n  kill 1234             # Send the default TERM signal to process with PID 1234\n  kill -9 1234          # Forcefully kill the process with PID 1234 using the KILL signal\n  killall process_name  # Kill all processes with the name 'process_name'\n  pkill -f pattern      # Kill processes matching the 'pattern' in their command line"
        },
        {
            "System Resource Monitoring (`vmstat`, `iostat`, `free`)",
            "These commands provide information about system resources, including memory, CPU, and I/O statistics. They help you understand how system resources are being used.",
            "Examples:\n  vmstat                # Report virtual memory statistics\n  vmstat 5              # Update the report every 5 seconds\n  iostat                # Display I/O statistics for devices\n  iostat -x 5           # Display extended I/O statistics every 5 seconds\n  free                  # Show memory usage\n  free -h               # Display memory usage in human-readable format"
        },
                {
            "Viewing System Logs (`dmesg`, `journalctl`)",
            "System logs provide information about system events, errors, and messages. The `dmesg` and `journalctl` commands help you view these logs.",
            "Examples:\n  dmesg                 # Display kernel ring buffer messages\n  dmesg | less          # View dmesg output page by page\n  journalctl            # Show systemd journal logs\n  journalctl -p err     # Show logs with error priority\n  journalctl --since \"2024-07-30 10:00:00\"  # Show logs since a specific date and time"
        }
    };

    // Questions
    Question questions[] = {
        {"What command would you use to display a real-time list of processes and their system resource usage?", "top"},
        {"Which command will show you the memory usage in a human-readable format?", "free -h"}
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