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

// Struct to represent a question with multiple choices
typedef struct {
    const char *question;
    const char *choices[4];
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

// Function to ask a multiple-choice question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("%s\n", question->question);
    
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcasecmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to Day 09 Breakfast!\n");
    printf("In this session, we'll explore system performance tuning techniques.\n");
    printf("We'll learn about optimizing system settings to improve performance, including CPU scheduling, memory management, and more.\n");
    printf("Press Enter to start...\n");
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "System Performance Tuning",
            "System performance tuning involves optimizing the system settings to improve performance. "
            "Key areas to focus on include CPU scheduling, memory management, disk I/O optimization, and network performance.\n"
            "Effective tuning can help in achieving better responsiveness, efficiency, and overall system stability. "
            "Performance tuning is critical for environments where consistent performance is a priority, such as servers, databases, or high-performance computing clusters.",
            "Examples of tuning commands:\n"
            "  1. View CPU usage: top or htop\n"
            "  2. Adjust swappiness: sysctl vm.swappiness=10\n"
            "  3. Monitor disk I/O: iostat\n"
            "  4. Network tuning: ethtool, sysctl net.ipv4.tcp_congestion_control\n"
            "For more detailed information, consult resources like the Linux Performance Tuning Guide at https://www.redhat.com/en/resources/linux-performance-tuning-guide."
        },
        {
            "CPU Scheduling",
            "CPU scheduling is the process by which the operating system determines which tasks (processes) should be executed by the CPU. "
            "It involves prioritizing tasks to ensure efficient CPU utilization and responsiveness.\n"
            "Different scheduling algorithms (such as FIFO, Round Robin, and Completely Fair Scheduler) are used to manage processes based on their priority and required resources. "
            "Understanding these algorithms can help system administrators in selecting the right scheduling policy for specific workloads, leading to optimized system performance and balanced CPU load.",
            "Examples of tuning commands:\n"
            "  1. Check CPU scheduling policy: chrt -p [PID]\n"
            "  2. Change scheduling policy: chrt -f -p [PRI] [PID]\n"
            "  3. View process priority: ps -eo pid,ni,comm\n"
            "For more insights, review the Linux Kernel Documentation on Scheduling at https://www.kernel.org/doc/html/latest/scheduler/index.html."
        },
        {
            "Memory Management",
            "Memory management involves optimizing the use of system memory to improve performance and avoid issues like swapping and fragmentation.\n"
            "Techniques include adjusting the swappiness parameter, monitoring memory usage, and configuring swap space effectively. "
            "Proper memory management helps in preventing memory bottlenecks, reducing the likelihood of system slowdowns, and ensuring that critical applications have enough memory resources to function efficiently.",
            "Examples of tuning commands:\n"
            "  1. View memory usage: free -h\n"
            "  2. Adjust swappiness: sysctl vm.swappiness=10\n"
            "  3. Check swap usage: swapon --show\n"
            "For a deeper understanding, refer to the Linux Memory Management documentation at https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html."
        },
        {
            "Disk I/O Optimization",
            "Disk I/O optimization focuses on improving the performance of disk operations, such as read and write speeds. "
            "This involves monitoring disk performance, optimizing file systems, and adjusting parameters related to I/O operations.\n"
            "Effective disk I/O optimization ensures faster data access, reduced latency in read/write operations, and extended disk lifespan, especially in environments with heavy disk usage, such as database servers or data processing applications.",
            "Examples of tuning commands:\n"
            "  1. Monitor disk I/O: iostat -x\n"
            "  2. Check file system performance: tune2fs -l [device]\n"
            "  3. Adjust I/O scheduler: echo 'deadline' > /sys/block/[device]/queue/scheduler\n"
            "For additional resources, explore the Disk I/O Tuning Guide at https://www.redhat.com/en/resources/disk-io-tuning-guide."
        },
        {
            "Network Performance",
            "Network performance tuning aims to optimize network throughput and reduce latency. This includes configuring network interfaces, adjusting TCP settings, and monitoring network traffic.\n"
            "Network tuning is crucial in environments where data transfer speed and reliability are critical, such as web servers, cloud services, and distributed applications. "
            "Proper tuning can lead to improved network reliability, faster data transfer rates, and reduced packet loss.",
            "Examples of tuning commands:\n"
            "  1. Check network interfaces: ifconfig or ip a\n"
            "  2. Adjust TCP congestion control: sysctl net.ipv4.tcp_congestion_control=reno\n"
            "  3. Monitor network traffic: iftop or nload\n"
            "For more detailed guidance, check the Network Performance Tuning documentation at https://www.redhat.com/en/resources/network-performance-tuning-guide."
        }
    };

    // Questions with multiple-choice options
    Question questions[] = {
        {
            "1. What is the purpose of adjusting the `vm.swappiness` parameter?",
            {"Increase CPU usage", "Reduce disk usage", "Control memory swapping", "Optimize network speed"},
            "C"
        },
        {
            "2. How can you view real-time CPU usage on a Unix-based system?",
            {"top", "free", "df", "iostat"},
            "A"
        },
        {
            "3. What command can be used to monitor disk I/O performance?",
            {"top", "iostat", "free", "vmstat"},
            "B"
        },
        {
            "4. What is the effect of changing the network congestion control algorithm?",
            {"Adjusts CPU scheduling", "Modifies disk I/O priority", "Affects TCP transmission rate", "Controls memory allocation"},
            "C"
        },
        {
            "5. How do you check the current I/O scheduler for a disk device?",
            {"sysctl", "iostat", "chrt", "cat /sys/block/[device]/queue/scheduler"},
            "D"
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
