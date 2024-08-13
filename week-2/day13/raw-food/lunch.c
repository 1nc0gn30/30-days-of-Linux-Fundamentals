#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

// Lesson structure
typedef struct {
    const char *topic;
    const char *description;
} Lesson;

// Question structure
typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Instructions: Open a separate terminal and type the command described. Press Enter to continue after you've tried it.\n" RESET_COLOR);
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); 
    printf("\n");
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];
    printf(BOLD_COLOR GREEN_COLOR "Question: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }
    printf("Your answer (A, B, C, or D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    // Convert the answer to uppercase for comparison
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') {
        user_answer[0] -= 32; // Convert to uppercase
    }

    // Convert answer to index
    int answer_index = -1;
    if (user_answer[0] >= 'A' && user_answer[0] <= 'D') {
        answer_index = user_answer[0] - 'A';
    }

    if (answer_index >= 0 && answer_index < 4 && strcmp(question->choices[answer_index], question->correct_answer) == 0) {
        printf(GREEN_COLOR "Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %s\n" RESET_COLOR, question->correct_answer);
    }
    printf("\n");
}

int main() {
    // Clear screen
    printf("\033[H\033[J");

    // Introduction
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 13 Lunch!\n" RESET_COLOR);
    printf("In this session, we will focus on User and Group Management.\n");
    printf("We will cover creating, modifying, and deleting users and groups.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
Lesson lessons[] = {
    {
        "System Monitoring Tools Overview",
        "Effective system monitoring involves using various tools to keep track of system performance and health.\n"
        "Key Tools and Their Usage:\n"
        "- **top:** Provides a real-time, dynamic view of system processes, CPU, and memory usage.\n"
        "  ```bash\n"
        "  top\n"
        "  ```\n"
        "- **vmstat:** Reports information about virtual memory, processes, and system performance.\n"
        "  ```bash\n"
        "  vmstat\n"
        "  ```\n"
        "- **iostat:** Reports CPU and I/O statistics, helping you understand disk usage and performance.\n"
        "  ```bash\n"
        "  iostat\n"
        "  ```\n"
        "- **netstat:** Provides network-related statistics, including connections, routing tables, and interface statistics.\n"
        "  ```bash\n"
        "  netstat\n"
        "  ```\n"
        "- **sar:** Collects and reports system activity data, useful for historical performance analysis.\n"
        "  ```bash\n"
        "  sar\n"
        "  ```\n"
        "These tools are essential for identifying performance bottlenecks and ensuring optimal system operation."
    },
    {
        "Understanding CPU and Memory Usage",
        "Monitoring CPU and memory usage helps in identifying resource constraints and optimizing performance.\n"
        "Commands and Examples:\n"
        "- **`top` Command:\n"
        "  ```bash\n"
        "  top\n"
        "  ```\n"
        "  - Press `Shift + P` to sort by CPU usage.\n"
        "  - Press `Shift + M` to sort by memory usage.\n"
        "- **`vmstat` Command:\n"
        "  ```bash\n"
        "  vmstat\n"
        "  ```\n"
        "  - Displays columns like `procs`, `memory`, `swap`, `io`, `system`, and `cpu`.\n"
        "  - Use `vmstat 5` to update statistics every 5 seconds.\n"
        "- **`iostat` Command:\n"
        "  ```bash\n"
        "  iostat\n"
        "  ```\n"
        "  - Displays CPU usage and disk I/O statistics.\n"
        "  - Use `iostat 5` for 5-second intervals.\n"
        "Monitoring these metrics helps in diagnosing performance issues related to CPU and memory utilization."
    },
    {
        "Disk and Network Performance Monitoring",
        "Understanding disk and network performance is critical for maintaining system efficiency and diagnosing issues.\n"
        "Commands and Examples:\n"
        "- **`iostat` for Disk Performance:\n"
        "  ```bash\n"
        "  iostat -x\n"
        "  ```\n"
        "  - Provides extended statistics for disks.\n"
        "- **`netstat` for Network Statistics:\n"
        "  ```bash\n"
        "  netstat -i\n"
        "  ```\n"
        "  - Displays network interfaces and their statistics.\n"
        "  ```bash\n"
        "  netstat -s\n"
        "  ```\n"
        "  - Displays network statistics by protocol.\n"
        "Analyzing disk and network performance helps in managing I/O operations and network traffic efficiently."
    },
    {
        "Historical Data Collection and Analysis",
        "Collecting and analyzing historical data helps in identifying long-term trends and performance issues.\n"
        "Commands and Examples:\n"
        "- **`sar` Command:\n"
        "  ```bash\n"
        "  sar -u 1 3\n"
        "  ```\n"
        "  - Reports CPU usage every second for 3 intervals.\n"
        "  ```bash\n"
        "  sar -r 1 3\n"
        "  ```\n"
        "  - Reports memory usage every second for 3 intervals.\n"
        "- **`sar -n DEV` for Network Performance:\n"
        "  ```bash\n"
        "  sar -n DEV 1 3\n"
        "  ```\n"
        "  - Reports network device statistics every second for 3 intervals.\n"
        "Using `sar` effectively provides insights into historical performance, which is crucial for capacity planning and identifying trends."
    },
    {
        "Best Practices for Performance Tuning",
        "Implementing best practices for performance tuning ensures that the system operates efficiently and effectively.\n"
        "Tips and Recommendations:\n"
        "- **CPU Tuning:** Adjust scheduling priorities using `nice` and `renice` commands.\n"
        "  ```bash\n"
        "  nice -n 10 command\n"
        "  renice -n 10 -p PID\n"
        "  ```\n"
        "- **Memory Tuning:** Configure swap space and manage memory limits.\n"
        "  ```bash\n"
        "  swapon -s\n"
        "  free -h\n"
        "  ```\n"
        "- **Disk Tuning:** Optimize file systems and use tools like `fsck` for filesystem checks.\n"
        "  ```bash\n"
        "  fsck /dev/sdX\n"
        "  ```\n"
        "- **Network Tuning:** Adjust network settings and optimize TCP/IP stack parameters.\n"
        "  ```bash\n"
        "  sysctl -w net.ipv4.tcp_window_scaling=1\n"
        "  ```\n"
        "Regular maintenance and tuning based on best practices are vital for maintaining optimal system performance."
    }
};

// Questions
Question questions[] = {
    {"Which tool provides a real-time view of CPU and memory usage?", {"top", "vmstat", "iostat", "sar"}, "top"},
    {"What command can be used to monitor disk I/O statistics?", {"netstat", "sar", "iostat", "vmstat"}, "iostat"},
    {"How do you monitor network interface statistics?", {"netstat -s", "sar -n DEV", "iostat -x", "vmstat"}, "sar -n DEV"},
    {"Which command is used to report CPU usage in historical data?", {"top", "sar -u", "vmstat", "iostat"}, "sar -u"},
    {"What is the purpose of the `iostat` command?", {"Network statistics", "CPU and I/O statistics", "Disk usage", "Memory usage"}, "CPU and I/O statistics"},
    {"How can you collect system activity data for analysis?", {"top", "vmstat", "sar", "netstat"}, "sar"}
};


    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Display questions
    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}

