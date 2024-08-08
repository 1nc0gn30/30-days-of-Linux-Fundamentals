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
    printf("Welcome to Day 6 Lunch!\n");
    printf("In this session, we'll go deeper into Networking Basics.\n");
    printf("We'll explore advanced networking commands and concepts.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter
}

int main() {
    display_intro();

    // Lessons
    Lesson lessons[] = {
        {
            "Inspecting Network Interfaces (`ip`)",
            "The `ip` command is used to show/manipulate routing, devices, policy routing, and tunnels.",
            "Examples:\n  ip addr show           # Display all network interfaces\n  ip link set eth0 up    # Bring up the 'eth0' interface\n  ip route show          # Display the routing table\n  ip addr add 192.168.1.100/24 dev eth0 # Add an IP address to 'eth0'"
        },
        {
            "Diagnosing Network Issues (`mtr`)",
            "The `mtr` command combines the functionality of `traceroute` and `ping` in a single network diagnostic tool.",
            "Examples:\n  mtr google.com         # Run mtr against Google\n  mtr -r google.com      # Generate a report after completion\n  mtr -c 100 google.com  # Limit to 100 cycles"
        },
        {
            "Monitoring Network Traffic (`tcpdump`)",
            "The `tcpdump` command allows you to capture and analyze network packets in real-time.",
            "Examples:\n  tcpdump -i eth0        # Capture traffic on 'eth0'\n  tcpdump port 80        # Capture traffic on port 80 (HTTP)\n  tcpdump -w capture.pcap # Save captured packets to a file"
        },
        {
            "Checking Port Status (`nmap`)",
            "The `nmap` command is used for network discovery and security auditing.",
            "Examples:\n  nmap -sP 192.168.1.0/24 # Ping scan a network range\n  nmap -p 80 google.com  # Scan port 80 on Google\n  nmap -A google.com     # Perform a comprehensive scan on Google"
        },
        {
            "Testing Network Connectivity (`curl`)",
            "The `curl` command transfers data from or to a server, using one of the supported protocols (HTTP, HTTPS, FTP, etc.).",
            "Examples:\n  curl http://example.com # Fetch a web page\n  curl -I http://example.com # Fetch HTTP headers\n  curl -d \"name=John\" -X POST http://example.com # Send a POST request"
        }
    };

        // Questions
    Question questions[] = {
        {"What command would you use to display all network interfaces using the `ip` tool?", "ip addr show"},
        {"Which command combines `traceroute` and `ping` functionalities?", "mtr"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Congratulations on completing Day 6 Lunch!\n");
    printf("You have learned advanced networking commands and concepts.\n");
    printf("Feel free to revisit the lessons and examples as needed. Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}