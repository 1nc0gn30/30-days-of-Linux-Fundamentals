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

    printf("Welcome to Day 09 Breakfast!\n");
    printf("In this session, we'll explore system performance tuning techniques.\n");
    printf("We'll learn about optimizing system settings to improve performance, including CPU scheduling, memory management, and more.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "System Performance Tuning",
            "System performance tuning involves optimizing the system settings to improve performance. "
            "Key areas to focus on include CPU scheduling, memory management, disk I/O optimization, and network performance.\n"
            "Effective tuning can help in achieving better responsiveness, efficiency, and overall system stability.",
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
            "Understanding different scheduling algorithms helps in optimizing system performance and balancing workload.",
            "Examples of tuning commands:\n"
            "  1. Check CPU scheduling policy: chrt -p [PID]\n"
            "  2. Change scheduling policy: chrt -f -p [PRI] [PID]\n"
            "  3. View process priority: ps -eo pid,ni,comm\n"
            "For more insights, review the Linux Kernel Documentation on Scheduling at https://www.kernel.org/doc/html/latest/scheduler/index.html."
        },
        {
            "Memory Management",
            "Memory management involves optimizing the use of system memory to improve performance and avoid issues like swapping and fragmentation.\n"
            "Key techniques include adjusting the swappiness parameter, monitoring memory usage, and configuring swap space effectively.",
            "Examples of tuning commands:\n"
            "  1. View memory usage: free -h\n"
            "  2. Adjust swappiness: sysctl vm.swappiness=10\n"
            "  3. Check swap usage: swapon --show\n"
            "For a deeper understanding, refer to the Linux Memory Management documentation at https://www.kernel.org/doc/html/latest/admin-guide/mm/index.html."
        },
        {
            "Disk I/O Optimization",
            "Disk I/O optimization focuses on improving the performance of disk operations, such as read and write speeds. "
            "This involves monitoring disk performance, optimizing file systems, and adjusting parameters related to I/O operations.",
            "Examples of tuning commands:\n"
            "  1. Monitor disk I/O: iostat -x\n"
            "  2. Check file system performance: tune2fs -l [device]\n"
            "  3. Adjust I/O scheduler: echo 'deadline' > /sys/block/[device]/queue/scheduler\n"
            "For additional resources, explore the Disk I/O Tuning Guide at https://www.redhat.com/en/resources/disk-io-tuning-guide."
        },
        {
            "Network Performance",
            "Network performance tuning aims to optimize network throughput and reduce latency. This includes configuring network interfaces, adjusting TCP settings, and monitoring network traffic.\n"
            "Proper tuning can lead to improved network reliability and faster data transfer rates.",
            "Examples of tuning commands:\n"
            "  1. Check network interfaces: ifconfig or ip a\n"
            "  2. Adjust TCP congestion control: sysctl net.ipv4.tcp_congestion_control=reno\n"
            "  3. Monitor network traffic: iftop or nload\n"
            "For more detailed guidance, check the Network Performance Tuning documentation at https://www.redhat.com/en/resources/network-performance-tuning-guide."
        }
    };

    // Questions
    Question questions[] = {
        {
            "1. What is the purpose of adjusting the `vm.swappiness` parameter?\n"
            "Hint: Explain how changing swappiness affects memory usage and swapping behavior.\n"
            "Format: The `vm.swappiness` parameter controls the tendency of the kernel to move **** from RAM to swap space. A ***** value reduces swapping.",
            "The `vm.swappiness` parameter controls the tendency of the kernel to move data from RAM to swap space. A lower value reduces swapping."
        },
        {
            "2. How can you view real-time CPU usage on a Unix-based system?\n"
            "Hint: Mention commands that provide a dynamic view of CPU usage.\n"
            "Format: You can use `***` or `****` to view real-time CPU usage.",
            "You can use `top` or `htop` to view real-time CPU usage."
        },
        {
            "3. What command can be used to monitor disk I/O performance?\n"
            "Hint: Name the command that provides detailed statistics on disk I/O.\n"
            "Format: The command to monitor disk I/O is `******`.",
            "The command to monitor disk I/O is `iostat`."
        },
        {
            "4. What is the effect of changing the network congestion control algorithm?\n"
            "Hint: Describe how different algorithms impact network performance.\n"
            "Format: Changing the network congestion control algorithm affects the way *** adjusts its trans******* rate in response to network congestion.",
            "Changing the network congestion control algorithm affects the way TCP adjusts its transmission rate in response to network congestion."
        },
        {
            "5. How do you check the current I/O scheduler for a disk device?\n"
            "Hint: Mention the file where the I/O scheduler information is stored.\n"
            "Format: The current I/O scheduler for a disk device can be checked using `*** /sys/block/[device]/queue/scheduler`.",
            "The current I/O scheduler for a disk device can be checked using `cat /sys/block/[device]/queue/scheduler`."
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
