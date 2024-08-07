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

    printf("Welcome to the Advanced Processes and System Monitoring Dinner Challenge!\n");
    printf("In this challenge, you will review Day 5 Breakfast and Lunch topics and explore additional advanced concepts.\n");
    printf("Follow the lessons to understand each command in detail, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lesson and examples for each command
    display_lesson(
        "Advanced Process Control with `kill`, `pkill`, `nice`, and `renice`",
        "Learn to manage processes with advanced techniques, including sending different signals, using patterns with `pkill`, and adjusting process priorities with `nice` and `renice`.",
        "Examples:\n  kill -STOP 1234           # Pause process with PID 1234\n  kill -CONT 1234           # Resume process with PID 1234\n  pkill -f 'java.*'         # Kill all processes matching 'java.*' pattern\n  nice -n 10 command        # Run 'command' with a nice value of 10\n  renice -n -5 -p 1234      # Change priority of process with PID 1234 to -5"
    );

    display_lesson(
        "In-Depth System Monitoring with `sar`, `atop`, and `dstat`",
        "Explore advanced usage of system monitoring tools such as `sar`, `atop`, and `dstat`. Learn how to generate and analyze detailed system performance reports and logs.",
        "Examples:\n  sar -u 1 3                # Report CPU usage every 1 second for 3 times\n  sar -r 1 3                # Report memory usage every 1 second for 3 times\n  sar -n DEV 1 3            # Report network statistics every 1 second for 3 times\n  atop -r /var/log/atop/atop.log # Read from atop log file\n  dstat -cdngyt              # Display combined metrics for CPU, disk, network, and system"
    );

    display_lesson(
        "Customizing Output with `grep`, `awk`, and `sed`",
        "Enhance your ability to analyze command output using `grep`, `awk`, and `sed`. These tools are essential for filtering, formatting, and manipulating text data.",
        "Examples:\n  top -b -n 1 | grep 'PID'    # Filter `top` output for 'PID'\n  ps aux | awk '{print $1, $11}' # Display user and command from `ps`\n  vmstat 5 | grep 'procs'      # Filter `vmstat` output for 'procs'"
    );

    display_lesson(
        "Analyzing Logs with `logwatch` and `syslog`",
        "Use `logwatch` and `syslog` for comprehensive log analysis and system message monitoring. Generate detailed reports and keep track of system activities effectively.",
        "Examples:\n  logwatch --detail high --service all    # Detailed log report for all services\n  tail -f /var/log/syslog                  # Monitor syslog continuously\n  logwatch --range 'yesterday'             # Report on previous day's logs"
    );

    display_lesson(
        "System Performance with `perf` and `dstat`",
        "Utilize `perf` and `dstat` for monitoring and analyzing system performance. These tools provide real-time and historical performance data to help with optimization and troubleshooting.",
        "Examples:\n  perf top               # Real-time performance monitoring\n  dstat -cdngy            # Display CPU, disk, network, and system stats\n  perf record -e cpu-clock -a sleep 10 # Record performance data for 10 seconds\n  dstat --vm --io         # Show VM and I/O statistics"
    );

    // Example questions
    ask_question(
        "How can you customize `htop` to sort by CPU usage?",
        "In `htop`, you can sort processes by CPU usage by clicking on the CPU column header or pressing F6 and selecting CPU."
    );

    ask_question(
        "What command would you use to pause and then resume a process with PID 1234?",
        "To pause a process with PID 1234, use `kill -STOP 1234`. To resume it, use `kill -CONT 1234`."
    );

    ask_question(
        "How can you generate a detailed report for all services using `logwatch`?",
        "Use the command `logwatch --detail high --service all` to generate a detailed report for all services."
    );

    ask_question(
        "How do you use `sar` to report network statistics every 1 second for 3 times?",
        "Run `sar -n DEV 1 3` to report network statistics every 1 second for 3 times."
    );

    ask_question(
        "What is the command to view performance metrics from a log file created by `atop`?",
        "Use `atop -r /var/log/atop/atop.log` to view performance metrics from an `atop` log file."
    );

    printf("Congratulations on completing the Advanced Processes and System Monitoring Dinner Challenge!\n");
    printf("You have reviewed and expanded your knowledge on managing processes and system monitoring.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}
