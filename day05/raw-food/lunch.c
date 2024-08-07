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

    printf("Welcome to the Advanced Processes and System Monitoring Lunch Challenge!\n");
    printf("In this challenge, you will dive deeper into advanced process management and system monitoring techniques.\n");
    printf("Follow the lessons to understand each command in detail, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each command
    display_lesson(
        "Advanced Process Management (`htop`, `pstree`)",
        "The `htop` and `pstree` commands provide advanced ways to view and manage processes. `htop` offers an interactive, color-coded display, while `pstree` shows process hierarchies.",
        "Examples:\n  htop                 # Launch interactive process viewer\n  htop -u username      # Filter processes by a specific user\n  pstree                # Display process tree\n  pstree -p             # Show process IDs in the tree"
    );

    display_lesson(
        "Detailed Resource Monitoring (`sar`, `atop`)",
        "The `sar` command collects and reports system activity, while `atop` provides real-time and historical performance data.",
        "Examples:\n  sar -u 5 3            # Report CPU usage every 5 seconds for 3 iterations\n  sar -r               # Display memory usage statistics\n  atop                 # Start `atop` for detailed performance monitoring\n  atop -r               # Read from `atop` logs for historical data"
    );

    display_lesson(
        "Customizing Output (`grep`, `awk`, `sed`)",
        "Use `grep`, `awk`, and `sed` to filter, format, and manipulate command output for analysis.",
        "Examples:\n  top -b -n 1 | grep 'PID'     # Filter `top` output for lines containing 'PID'\n  ps aux | awk '{print $1, $11}' # Display user and command from `ps` output\n  vmstat 5 | grep 'procs'       # Filter `vmstat` output for lines containing 'procs'"
    );

    display_lesson(
        "Analyzing Logs (`logwatch`, `syslog`)",
        "The `logwatch` command summarizes and analyzes system logs, while `syslog` provides standardized logging of system messages.",
        "Examples:\n  logwatch --detail high --service all    # Generate a detailed log report for all services\n  tail -f /var/log/syslog                  # Continuously monitor syslog for new messages\n  logwatch --range 'yesterday'             # Report on logs from the previous day"
    );

    display_lesson(
        "System Performance (`perf`, `dstat`)",
        "The `perf` and `dstat` tools help with performance analysis and monitoring, offering real-time and detailed system performance metrics.",
        "Examples:\n  perf top               # Real-time performance monitoring and profiling\n  dstat -cdngy            # Display CPU, disk, network, and system statistics\n  perf record -e cpu-clock -a sleep 10 # Record performance data for 10 seconds\n  dstat --vm --io         # Show VM and I/O statistics"
    );

    // Example questions
    ask_question(
        "What command can you use to display a real-time, interactive view of processes with color-coded output?",
        "htop"
    );

    ask_question(
        "How can you filter `sar` to report CPU usage every 10 seconds for 5 iterations?",
        "sar -u 10 5"
    );

    ask_question(
        "Which command shows the system's process hierarchy with process IDs?",
        "pstree -p"
    );

    printf("Congratulations on completing Day 5 Lunch! You've deepened your understanding of advanced process management and system monitoring.\n");
    printf("Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}
