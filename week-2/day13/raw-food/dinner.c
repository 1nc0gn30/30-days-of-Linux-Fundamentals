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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 13 Dinner!\n" RESET_COLOR);
    printf("In this session, we will delve into System Monitoring and Performance Tuning.\n");
    printf("We'll explore various tools and techniques to monitor system performance and optimize system resources.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "Introduction to System Monitoring",
            "System monitoring is crucial for understanding how your system is performing and identifying potential issues.\n"
            "Key Areas:\n"
            "- **CPU Usage:** Monitor how much CPU is being used by processes.\n"
            "- **Memory Usage:** Track the amount of RAM being used and available.\n"
            "- **Disk Usage:** Check how much disk space is being used and how much is available.\n"
            "- **Network Usage:** Observe the amount of data being sent and received over the network."
        },
        {
            "Using `top` for Real-Time Monitoring",
            "`top` is a powerful tool for monitoring system performance in real-time.\n"
            "Commands:\n"
            "- To launch `top`: `top`\n"
            "  ```bash\n"
            "  top\n"
            "  ```\n"
            "- To sort by CPU usage: Press `Shift + P`\n"
            "- To sort by memory usage: Press `Shift + M`\n"
            "- To exit `top`: Press `q`\n"
            "The `top` command provides a dynamic view of the system's resource usage and can help identify processes consuming excessive resources."
        },
        {
            "Monitoring System Performance with `vmstat`",
            "`vmstat` reports virtual memory statistics and provides insight into system performance.\n"
            "Commands:\n"
            "- To display system statistics: `vmstat`\n"
            "  ```bash\n"
            "  vmstat\n"
            "  ```\n"
            "- To report statistics every 5 seconds: `vmstat 5`\n"
            "  ```bash\n"
            "  vmstat 5\n"
            "  ```\n"
            "- Key Metrics:\n"
            "  - **procs:** Information on processes, including run queues.\n"
            "  - **memory:** Memory usage, including free, used, and buffer/cache.\n"
            "  - **swap:** Swap space usage.\n"
            "  - **io:** I/O activity, including read and write operations.\n"
            "  - **system:** System activity, including interrupts and context switches.\n"
            "  - **cpu:** CPU usage breakdown."
        },
        {
            "Analyzing Disk Usage with `iostat`",
            "`iostat` provides statistics on CPU and I/O usage for devices and partitions.\n"
            "Commands:\n"
            "- To display I/O statistics: `iostat`\n"
            "  ```bash\n"
            "  iostat\n"
            "  ```\n"
            "- To report statistics every 5 seconds: `iostat 5`\n"
            "  ```bash\n"
            "  iostat 5\n"
            "  ```\n"
            "- Key Metrics:\n"
            "  - **%user:** CPU time spent in user space.\n"
            "  - **%system:** CPU time spent in kernel space.\n"
            "  - **%iowait:** CPU time waiting for I/O operations.\n"
            "  - **tps:** Transactions per second (I/O operations).\n"
            "  - **kB_read/s:** Kilobytes read per second.\n"
            "  - **kB_wrtn/s:** Kilobytes written per second."
        },
        {
            "Network Monitoring with `netstat`",
            "`netstat` displays network connections, routing tables, and interface statistics.\n"
            "Commands:\n"
            "- To display network connections: `netstat`\n"
            "  ```bash\n"
            "  netstat\n"
            "  ```\n"
            "- To display network interfaces: `netstat -i`\n"
            "  ```bash\n"
            "  netstat -i\n"
            "  ```\n"
            "- To display listening ports: `netstat -l`\n"
            "  ```bash\n"
            "  netstat -l\n"
            "  ```\n"
            "- To display routing table: `netstat -r`\n"
            "  ```bash\n"
            "  netstat -r\n"
            "  ```\n"
            "- Key Metrics:\n"
            "  - **Proto:** Protocol (TCP/UDP).\n"
            "  - **Recv-Q:** Receive queue size.\n"
            "  - **Send-Q:** Send queue size.\n"
            "  - **Local Address:** Local IP address and port.\n"
            "  - **Foreign Address:** Remote IP address and port.\n"
            "  - **State:** Connection state (e.g., ESTABLISHED, LISTEN)."
        },
        {
            "Using `sar` for Historical Data",
            "`sar` collects, reports, and saves system activity information.\n"
            "Commands:\n"
            "- To display CPU usage: `sar -u`\n"
            "  ```bash\n"
            "  sar -u\n"
            "  ```\n"
            "- To display memory usage: `sar -r`\n"
            "  ```bash\n"
            "  sar -r\n"
            "  ```\n"
            "- To display network activity: `sar -n DEV`\n"
            "  ```bash\n"
            "  sar -n DEV\n"
            "  ```\n"
            "- To display I/O statistics: `sar -b`\n"
            "  ```bash\n"
            "  sar -b\n"
            "  ```\n"
            "- To collect data every 10 seconds for 1 minute: `sar -u 10 6`\n"
            "  ```bash\n"
            "  sar -u 10 6\n"
            "  ```\n"
            "Key Metrics:\n"
            "  - **%usr:** CPU time spent in user space.\n"
            "  - **%sys:** CPU time spent in kernel space.\n"
            "  - **%idle:** CPU idle time.\n"
            "  - **kbmemfree:** Free memory (kilobytes).\n"
            "  - **kbswpfree:** Free swap space (kilobytes).\n"
            "  - **rxpck/s:** Packets received per second.\n"
            "  - **txpck/s:** Packets transmitted per second."
        },
        {
            "Performance Tuning Tips",
            "Performance tuning involves optimizing system parameters to improve efficiency.\n"
            "Tips:\n"
            "- **CPU Tuning:** Adjust CPU scheduling policies and prioritize processes.\n"
            "- **Memory Tuning:** Configure swap space, adjust cache sizes, and manage memory limits.\n"
            "- **Disk Tuning:** Optimize file systems, use appropriate RAID levels, and defragment disks if necessary.\n"
            "- **Network Tuning:** Adjust network interface settings, optimize network stack parameters, and manage network bandwidth.\n"
            "- **Regular Maintenance:** Keep your system updated, monitor logs for issues, and perform regular backups."
        }
    };

    // Questions
    Question questions[] = {
        {"Which command is used to monitor real-time CPU and memory usage?", {"A. top", "B. vmstat", "C. iostat", "D. sar"}, "top"},
        {"What does `vmstat` provide information on?", {"A. Disk I/O", "B. Network Traffic", "C. Memory Usage", "D. Process Information"}, "Memory Usage"},
        {"What command is used to analyze disk I/O?", {"A. netstat", "B. sar", "C. iostat", "D. top"}, "iostat"},
        {"Which tool provides historical performance data?", {"A. top", "B. vmstat", "C. netstat", "D. sar"}, "sar"},
        {"How can you check the amount of data received over the network?", {"A. netstat -i", "B. sar -n DEV", "C. iostat", "D. vmstat"}, "sar -n DEV"},
        {"What is a key metric reported by `iostat`?", {"A. %usr", "B. %idle", "C. kB_read/s", "D. %sys"}, "kB_read/s"}
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

