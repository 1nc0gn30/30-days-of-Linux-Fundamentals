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
    printf("Welcome to Day 6 Breakfast!\n");
    printf("In this session, we'll dive into Networking Basics.\n");
    printf("We'll explore essential networking commands and concepts.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter
}

int main() {
    display_intro();

    // Lessons
    Lesson lessons[] = {
        {
            "Viewing Network Configuration (`ifconfig`)",
            "The `ifconfig` command displays or configures network interfaces.",
            "Examples:\n  ifconfig              # Display all active interfaces\n  ifconfig eth0         # Show configuration of 'eth0' interface\n  ifconfig eth0 up      # Activate the 'eth0' interface\n  ifconfig eth0 down    # Deactivate the 'eth0' interface"
        },
        {
            "Pinging a Host (`ping`)",
            "The `ping` command sends ICMP ECHO_REQUEST packets to network hosts.",
            "Examples:\n  ping google.com       # Ping Google to check connectivity\n  ping -c 4 google.com  # Send 4 ping requests to Google\n  ping -i 0.5 google.com # Set interval to 0.5 seconds between requests"
        },
        {
            "Traceroute to a Host (`traceroute`)",
            "The `traceroute` command shows the path packets take to reach a network host.",
            "Examples:\n  traceroute google.com # Trace route to Google\n  traceroute -n google.com # Trace route without resolving hostnames"
        },
        {
            "Displaying Network Statistics (`netstat`)",
            "The `netstat` command displays network connections, routing tables, and interface statistics.",
            "Examples:\n  netstat               # Show all active connections\n  netstat -r            # Display routing table\n  netstat -i            # Show network interfaces"
        },
        {
            "Testing Port Connectivity (`nc` or `netcat`)",
            "The `nc` command is a versatile networking tool for reading from and writing to network connections.",
            "Examples:\n  nc -zv google.com 80  # Check if port 80 is open on Google\n  nc -l 1234            # Listen on port 1234 for incoming connections\n  nc google.com 80      # Connect to port 80 on Google"
        }
    };

    // Questions
    Question questions[] = {
        {"What command would you use to view the configuration of all active network interfaces?", "ifconfig"},
        {"Which command would you use to send 4 ICMP ECHO_REQUEST packets to google.com?", "ping -c 4 google.com"}
    };

       // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Congratulations on completing Day 6 Breakfast!\n");
    printf("You have learned essential networking commands and concepts.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}