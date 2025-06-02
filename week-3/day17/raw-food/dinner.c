#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

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
    const char *command_example;
    const char *detailed_explanation;
    const char *resources[MAX_RESOURCES];
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
    printf(YELLOW_COLOR "Example Command:\n" RESET_COLOR);
    printf(GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Detailed Explanation:\n" RESET_COLOR);
    printf("%s\n", lesson->detailed_explanation);
    
    printf(YELLOW_COLOR "Additional Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && lesson->resources[i] != NULL; i++) {
        printf("- %s\n", lesson->resources[i]);
    }
    printf(YELLOW_COLOR "Press Enter to continue...\n" RESET_COLOR);
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
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') {
        user_answer[0] -= 32;
    }
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
    // Clear screen and header
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 17 - Dinner: Lab Sessions for Network Security\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Dinner...\n" RESET_COLOR);
    getchar();
    
    // Dinner Lessons (10 lessons)
    Lesson lessons[] = {
        {
            "Advanced iptables NAT Configuration Lab",
            "Configure iptables with NAT to manage outgoing traffic.",
            "sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE",
            "In this lab, you set up NAT so that internal IP addresses are masked behind a public IP.",
            {"https://www.cyberciti.biz/faq/iptables-nat/", NULL, NULL, NULL, NULL}
        },
        {
            "Port Forwarding Lab",
            "Implement port forwarding to direct external traffic to an internal server.",
            "sudo iptables -t nat -A PREROUTING -p tcp --dport 2222 -j DNAT --to-destination 192.168.1.10:22",
            "This lab demonstrates how to redirect traffic from one port on the firewall to a different port on an internal host.",
            {"https://www.digitalocean.com/community/tutorials/iptables-port-forwarding", NULL, NULL, NULL, NULL}
        },
        {
            "Rate Limiting with iptables",
            "Set up rate limiting to mitigate brute-force attacks.",
            "sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT",
            "Rate limiting helps protect services such as SSH by restricting the number of connection attempts.",
            {"https://www.cyberciti.biz/faq/iptables-rate-limit/", NULL, NULL, NULL, NULL}
        },
        {
            "Live Traffic Capture with Wireshark",
            "Capture network packets in real time for analysis.",
            "wireshark",
            "This lab task involves launching Wireshark to capture live traffic, enabling you to analyze network patterns and potential issues.",
            {"https://www.wireshark.org/docs/wsug_html_chunked/", NULL, NULL, NULL, NULL}
        },
        {
            "Analyzing Packet Captures",
            "Use Wireshark filters to analyze captured network data.",
            "ip.addr==192.168.1.2",
            "Learn how to apply display filters in Wireshark to isolate specific traffic and troubleshoot network issues.",
            {"https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html", NULL, NULL, NULL, NULL}
        },
        {
            "Snort IDS Installation Lab",
            "Install Snort on your system and run a basic configuration test.",
            "sudo snort -A console -c /etc/snort/snort.conf -i eth0",
            "This lab guides you through installing Snort and performing an initial test to ensure that it can detect suspicious traffic.",
            {"https://www.snort.org/documents", NULL, NULL, NULL, NULL}
        },
        {
            "Creating Custom Snort Rules",
            "Develop and implement custom rules in Snort.",
            "alert tcp any any -> any 80 (msg:\"Custom HTTP Alert\"; sid:100001;)",
            "In this exercise, you will create your own Snort rule to detect specific traffic patterns relevant to your network.",
            {"https://www.snort.org/faq", NULL, NULL, NULL, NULL}
        },
        {
            "Testing Snort Alerts",
            "Generate traffic to trigger Snort alerts and verify rule functionality.",
            "curl http://yourserver",
            "This lab tests your custom Snort rules by generating HTTP requests that should trigger alerts.",
            {"https://www.snort.org/faq", NULL, NULL, NULL, NULL}
        },
        {
            "Integrating iptables and IDS Logs",
            "Combine firewall and IDS logs for a comprehensive security audit.",
            "cat /var/log/syslog",
            "By correlating logs from iptables and Snort, you can better understand the threat landscape and refine your security policies.",
            {"https://www.sans.org/white-papers/389/", NULL, NULL, NULL, NULL}
        },
        {
            "Final Network Security Audit Lab",
            "Conduct a final audit combining all lab tasks to evaluate network security.",
            "echo 'Audit complete'",
            "This lab session brings together NAT, port forwarding, rate limiting, packet analysis, and IDS configuration for a final network security review.",
            {"https://www.sans.org/white-papers/advanced-network-security/", NULL, NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }
    
    // Dinner Questions (10 questions)
    Question questions[] = {
        {
            "Which iptables table is used for NAT configuration?",
            {"nat", "filter", "mangle", "raw"},
            "nat"
        },
        {
            "What is the purpose of the DNAT target in iptables?",
            {"Redirect traffic to another destination", "Log packets", "Block traffic", "Perform source NAT"},
            "Redirect traffic to another destination"
        },
        {
            "Which command is used to implement rate limiting in iptables?",
            {"sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT", "sudo iptables -F", "sudo iptables -X", "sudo iptables -L"},
            "sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT"
        },
        {
            "Which tool is used for live network traffic capture?",
            {"Wireshark", "Nmap", "tcpdump", "Snort"},
            "Wireshark"
        },
        {
            "What filter in Wireshark would display traffic from a specific IP?",
            {"ip.addr==192.168.1.2", "tcp.port==80", "udp.port==53", "icmp.type==8"},
            "ip.addr==192.168.1.2"
        },
        {
            "Which command starts Snort in console mode?",
            {"sudo snort -A console -c /etc/snort/snort.conf -i eth0", "snort -v", "sudo snort -d", "snort --start"},
            "sudo snort -A console -c /etc/snort/snort.conf -i eth0"
        },
        {
            "What is the purpose of creating custom Snort rules?",
            {"To detect specific network traffic patterns", "To block all traffic", "To improve Wireshark captures", "To disable firewall logging"},
            "To detect specific network traffic patterns"
        },
        {
            "Which lab task involves generating traffic to test IDS rules?",
            {"Testing Snort Alerts", "Rate Limiting Lab", "Port Forwarding Lab", "NAT Configuration Lab"},
            "Testing Snort Alerts"
        },
        {
            "Why integrate logs from iptables and IDS?",
            {"To achieve a comprehensive view of network security", "To reduce log file sizes", "To disable network services", "To bypass firewall rules"},
            "To achieve a comprehensive view of network security"
        },
        {
            "What is the final goal of the network security audit lab?",
            {"To review all lab configurations and ensure optimal security", "To restart all services", "To disable IDS", "To update Wireshark"},
            "To review all lab configurations and ensure optimal security"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your network security lab knowledge:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
