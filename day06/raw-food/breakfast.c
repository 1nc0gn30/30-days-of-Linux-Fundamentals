#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a lesson and prompt user
void display_lesson(const char *topic, const char *description, const char *examples) {
    printf("\033[H\033[J"); // Clear screen
    printf("Lesson on `%s`:\n", topic);
    printf("%s\n", description);
    printf("Examples:\n%s\n", examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const char *question, const char *correct_answer) {
    char answer[100];
    printf("\033[H\033[J"); // Clear screen
    printf("Question: %s\n", question);
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

    // Lesson and examples for each command
    display_lesson(
        "Viewing Network Configuration (`ifconfig`)",
        "The `ifconfig` command displays or configures network interfaces.",
        "Examples:\n  ifconfig              # Display all active interfaces\n  ifconfig eth0         # Show configuration of 'eth0' interface\n  ifconfig eth0 up      # Activate the 'eth0' interface\n  ifconfig eth0 down    # Deactivate the 'eth0' interface"
    );

    display_lesson(
        "Pinging a Host (`ping`)",
        "The `ping` command sends ICMP ECHO_REQUEST packets to network hosts.",
        "Examples:\n  ping google.com       # Ping Google to check connectivity\n  ping -c 4 google.com  # Send 4 ping requests to Google\n  ping -i 0.5 google.com # Set interval to 0.5 seconds between requests"
    );

    display_lesson(
        "Traceroute to a Host (`traceroute`)",
        "The `traceroute` command shows the path packets take to reach a network host.",
        "Examples:\n  traceroute google.com # Trace route to Google\n  traceroute -n google.com # Trace route without resolving hostnames"
    );

    display_lesson(
        "Displaying Network Statistics (`netstat`)",
        "The `netstat` command displays network connections, routing tables, and interface statistics.",
        "Examples:\n  netstat               # Show all active connections\n  netstat -r            # Display routing table\n  netstat -i            # Show network interfaces"
    );

    display_lesson(
        "Testing Port Connectivity (`nc` or `netcat`)",
        "The `nc` command is a versatile networking tool for reading from and writing to network connections.",
        "Examples:\n  nc -zv google.com 80  # Check if port 80 is open on Google\n  nc -l 1234            # Listen on port 1234 for incoming connections\n  nc google.com 80      # Connect to port 80 on Google"
    );

    // Sample questions
    ask_question(
        "What command would you use to view the configuration of all active network interfaces?",
        "ifconfig"
    );

    ask_question(
        "Which command would you use to send 4 ICMP ECHO_REQUEST packets to google.com?",
        "ping -c 4 google.com"
    );

    return 0;
}

