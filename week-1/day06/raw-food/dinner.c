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
    printf("\033[H\033[J"); // Clear screen
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("Examples:\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("\033[H\033[J"); // Clear screen
    printf("Question: %s\n", question->question);
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
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to display the course introduction
void display_intro() {
    printf("\033[H\033[J"); // Clear screen
    printf("Welcome to Day 6 Dinner!\n");
    printf("In this session, we'll review everything from today and explore additional advanced networking commands.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter
}

int main() {
    display_intro();

    // Lessons
    Lesson lessons[] = {
    {
        "Network Security (`ssh`)",
        "The `ssh` command is used to securely connect to a remote server or device.",
        "Examples:\n  ssh user@remote_server           # Connect to a remote server as a specific user\n  ssh -p 2222 user@remote_server   # Connect to a remote server on a non-standard port\n  ssh -X user@remote_server       # Enable X11 forwarding for graphical applications"
    },
    {
        "Network Troubleshooting (`ping`, `traceroute`)",
        "The `ping` and `traceroute` commands are used to troubleshoot network connectivity issues.",
        "Examples:\n  ping google.com                 # Test connectivity to a specific host\n  traceroute google.com           # Trace the route to a specific host\n  ping -c 5 google.com           # Send 5 ICMP echo requests to a specific host"
    },
    {
        "Network Configuration (`ifconfig`, `ip`)",
        "The `ifconfig` and `ip` commands are used to configure network interfaces.",
        "Examples:\n  ifconfig eth0 up               # Bring up the 'eth0' interface\n  ip addr add 192.168.1.100/24 dev eth0 # Assign an IP address to the 'eth0' interface\n  ifconfig eth0 down             # Bring down the 'eth0' interface"
    },
    {
        "Network Monitoring (`top`, `htop`)",
        "The `top` and `htop` commands are used to monitor system resources and network activity.",
        "Examples:\n  top                           # Display system resource usage\n  htop                          # Display system resource usage with a graphical interface\n  top -b -n 1                  # Display system resource usage in batch mode"
    }
};

    // Questions
    Question questions[] = {
        {"What command would you use to capture traffic on the 'eth0' interface?", "tcpdump -i eth0"},
        {"Which command would you use to test network throughput?", "iperf"},
        {"What command would you use to securely connect to a remote server as a specific user?", "ssh user@remote_server"},
        {"Which command would you use to trace the route to a specific host?", "traceroute"},
        {"How would you bring up the 'eth0' interface using the `ifconfig` command?", "ifconfig eth0 up"},
        {"What command would you use to display system resource usage with a graphical interface?", "htop"}
};
    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Congratulations on completing Day 6 Dinner!\n");
    printf("You have reviewed and learned additional advanced networking commands.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}