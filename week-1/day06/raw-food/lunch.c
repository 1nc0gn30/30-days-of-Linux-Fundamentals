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
    const char *hint;
} Question;

// Function to display a lesson and prompt the user
void display_lesson(const Lesson *lesson) {
    printf("\033[H\033[J"); // Clear screen
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n\n", lesson->description);
    printf("Examples:\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
int ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    int attempts = 0;

    printf("\033[H\033[J"); // Clear screen
    printf("Question: %s\n", question->question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    while (attempts < 3) {
        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(answer, question->correct_answer) == 0) {
            printf("Correct!\n\n");
            return 1; // Return 1 for a correct answer
        } else {
            printf("Incorrect.\n");
            if (attempts < 2) {
                // Display hint if there are attempts remaining
                printf("Hint: %s\n", question->hint);
                printf("Try again...\n");
            }
        }
        attempts++;
    }

    // Optionally, you can indicate that the user has exhausted their attempts
    printf("You have used all your attempts.\n\n");

    return 0; // Return 0 if the answer was incorrect
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

// Function to display the final score
void display_score(int correct_answers, int total_questions) {
    printf("\033[H\033[J"); // Clear screen
    printf("Quiz Completed!\n");
    printf("You answered %d out of %d questions correctly.\n", correct_answers, total_questions);
    if (correct_answers == total_questions) {
        printf("Excellent work! You've mastered the advanced networking commands and concepts.\n");
    } else if (correct_answers > total_questions / 2) {
        printf("Good job! You have a solid understanding, but there's room for improvement.\n");
    } else {
        printf("Keep practicing! Review the lessons and try the quiz again.\n");
    }
    printf("Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter
}

int main() {
    display_intro();

    // Lessons
    Lesson lessons[] = {
        {
            "Inspecting Network Interfaces (`ip`)",
            "The `ip` command is used to show/manipulate routing, devices, policy routing, and tunnels.",
            "  ip addr show           # Display all network interfaces\n  ip link set eth0 up    # Bring up the 'eth0' interface\n  ip route show          # Display the routing table\n  ip addr add 192.168.1.100/24 dev eth0 # Add an IP address to 'eth0'"
        },
        {
            "Diagnosing Network Issues (`mtr`)",
            "The `mtr` command combines the functionality of `traceroute` and `ping` in a single network diagnostic tool.",
            "  mtr google.com         # Run mtr against Google\n  mtr -r google.com      # Generate a report after completion\n  mtr -c 100 google.com  # Limit to 100 cycles"
        },
        {
            "Monitoring Network Traffic (`tcpdump`)",
            "The `tcpdump` command allows you to capture and analyze network packets in real-time.",
            "  tcpdump -i eth0        # Capture traffic on 'eth0'\n  tcpdump port 80        # Capture traffic on port 80 (HTTP)\n  tcpdump -w capture.pcap # Save captured packets to a file"
        },
        {
            "Checking Port Status (`nmap`)",
            "The `nmap` command is used for network discovery and security auditing.",
            "  nmap -sP 192.168.1.0/24 # Ping scan a network range\n  nmap -p 80 google.com  # Scan port 80 on Google\n  nmap -A google.com     # Perform a comprehensive scan on Google"
        },
        {
            "Testing Network Connectivity (`curl`)",
            "The `curl` command transfers data from or to a server, using one of the supported protocols (HTTP, HTTPS, FTP, etc.).",
            "  curl http://example.com # Fetch a web page\n  curl -I http://example.com # Fetch HTTP headers\n  curl -d \"name=John\" -X POST http://example.com # Send a POST request"
        }
    };

    // Questions
    Question questions[] = {
        {
            "What command would you use to bring up the 'eth0' network interface?",
            "ip link set eth0 up",
            "Hint: The command involves setting the status of a network interface."
        },
        {
            "How would you display the routing table using the `ip` command?",
            "ip route show",
            "Hint: This command displays all routes in the routing table."
        },
        {
            "Which command would you use to add an IP address to the 'eth0' interface?",
            "ip addr add 192.168.1.100/24 dev eth0",
            "Hint: The command involves assigning a new IP address to a specific network interface. ** **** *** 192.168.1.100/24 *** ****"
        },
        {
            "How do you run `mtr` against Google and generate a report after completion?",
            "mtr -r google.com",
            "Hint: This command runs `mtr` in a mode that generates a report once it completes."
        },
        {
            "What `mtr` option limits the test to a specific number of cycles?",
            "mtr -c 100 google.com",
            "Hint: This option specifies the number of cycles `mtr` should perform. *** -* ******.com"
        },
        {
            "Which command captures network traffic on the 'eth0' interface?",
            "tcpdump -i eth0",
            "Hint: The command involves monitoring traffic on a specific network interface."
        },
        {
            "How would you capture only HTTP traffic on port 80?",
            "tcpdump port 80",
            "Hint: This command filters the captured traffic based on a specific port number. ******* port ** "
        },
        {
            "What is the command to save captured packets to a file using `tcpdump`?",
            "tcpdump -w capture.pcap",
            "Hint: ******* -* capture.pcap"
        },
        {
            "How do you perform a ping scan on a network range with `nmap`?",
            "nmap -sP 192.168.1.0/24",
            "Hint: **** -** 192.168.1.0/24"
        },
        {
            "Which command scans port 80 on Google's servers using `nmap`?",
            "nmap -p 80 google.com",
            "Hint: **** -* ** ******.com"
        },
        {
            "What command would you use to perform a comprehensive scan on Google's servers?",
            "nmap -A google.com",
            "Hint: **** -* ******.com"
        },
        {
            "How would you fetch a web page using `curl`?",
            "curl http://example.com",
            "Hint: **** http://example.com"
        },
        {
            "What `curl` option fetches HTTP headers only?",
            "curl -I http://example.com",
            "Hint: **** -* http://example.com"
        },
        {
            "Which `curl` option sends a POST request with data?",
            "curl -d \"name=John\" -X POST http://example.com",
            "Hint: **** -d \"name=John\" -X POST ****"
        }
    };

    int num_lessons = sizeof(lessons) / sizeof(lessons[0]);
    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int correct_answers = 0;

    // Display lessons
    for (int i = 0; i < num_lessons; i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < num_questions; i++) {
        if (ask_question(&questions[i])) {
            correct_answers++;
        }
    }

    // Display final score
    display_score(correct_answers, num_questions);

    return 0;
}
