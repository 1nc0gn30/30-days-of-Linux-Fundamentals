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
    printf(BOLD_COLOR CYAN_COLOR "Day 17 - Lunch: Advanced Network Security\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Lunch...\n" RESET_COLOR);
    getchar();
    
    // Lunch Lessons (10 lessons)
    Lesson lessons[] = {
        {
            "Firewall Deep Dive",
            "Explore advanced iptables rules including NAT and port forwarding.",
            "sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE",
            "This lesson covers advanced firewall configuration techniques such as setting up NAT and port forwarding using iptables.",
            {"https://www.digitalocean.com/community/tutorials/iptables-essentials", NULL, NULL, NULL, NULL}
        },
        {
            "Configuring NAT with iptables",
            "Learn to configure Network Address Translation for internal network security.",
            "sudo iptables -t nat -A PREROUTING -p tcp --dport 80 -j DNAT --to-destination 192.168.1.2:80",
            "NAT allows you to map external ports to internal hosts, thereby securing your network while providing access to necessary services.",
            {"https://www.cyberciti.biz/faq/iptables-nat/", NULL, NULL, NULL, NULL}
        },
        {
            "Port Forwarding Configuration",
            "Set up iptables rules for port forwarding to internal services.",
            "sudo iptables -t nat -A PREROUTING -p tcp --dport 2222 -j DNAT --to-destination 192.168.1.10:22",
            "Port forwarding redirects traffic from one port to another, useful for exposing internal services securely.",
            {"https://www.digitalocean.com/community/tutorials/iptables-port-forwarding", NULL, NULL, NULL, NULL}
        },
        {
            "Understanding iptables Chains",
            "Dive into the INPUT, OUTPUT, and FORWARD chains to secure network traffic.",
            "sudo iptables -L -v",
            "Understanding how iptables chains work is critical to creating a secure and robust firewall configuration.",
            {"https://wiki.archlinux.org/title/iptables", NULL, NULL, NULL, NULL}
        },
        {
            "Iptables Logging and Debugging",
            "Learn to log firewall activity to troubleshoot and secure your network.",
            "sudo iptables -A INPUT -j LOG --log-prefix 'IPTables-Dropped: '",
            "Logging with iptables helps you keep track of dropped packets and diagnose potential security issues.",
            {"https://www.cyberciti.biz/faq/linux-iptables-logging/", NULL, NULL, NULL, NULL}
        },
        {
            "Monitoring Traffic with Wireshark",
            "Introduction to capturing and analyzing network packets using Wireshark.",
            "wireshark",
            "Wireshark is a powerful tool that lets you capture live network traffic and analyze protocols to identify potential threats.",
            {"https://www.wireshark.org/docs/wsug_html_chunked/", NULL, NULL, NULL, NULL}
        },
        {
            "Wireshark Filters and Analysis",
            "Learn to apply display filters in Wireshark for targeted traffic analysis.",
            "ip.addr==192.168.1.2",
            "Filters allow you to focus on specific traffic, making it easier to detect anomalies and intrusions.",
            {"https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html", NULL, NULL, NULL, NULL}
        },
        {
            "Introduction to Snort IDS",
            "Overview of Snort as an intrusion detection system.",
            "sudo snort -A console -c /etc/snort/snort.conf -i eth0",
            "Snort inspects network traffic and uses predefined rules to detect malicious activities in real time.",
            {"https://www.snort.org/documents", NULL, NULL, NULL, NULL}
        },
        {
            "Snort Rule Basics",
            "Learn the fundamentals of creating and modifying Snort rules.",
            "alert tcp any any -> any 80 (msg:\"HTTP Traffic\"; sid:1000001;)",
            "Understanding Snort rules is essential for tuning your IDS to detect specific threats relevant to your network.",
            {"https://www.snort.org/faq", NULL, NULL, NULL, NULL}
        },
        {
            "Integrating Network Security Tools",
            "Combine firewall, packet analysis, and IDS tools to achieve layered network security.",
            "echo 'Integration complete'",
            "Layering multiple network security tools creates a robust defense by covering multiple attack vectors.",
            {"https://www.sans.org/white-papers/advanced-network-security/", NULL, NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }
    
    // Lunch Questions (10 questions)
    Question questions[] = {
        {
            "Which iptables table is used for NAT configuration?",
            {"nat", "filter", "mangle", "raw"},
            "nat"
        },
        {
            "What is the purpose of the MASQUERADE target in iptables?",
            {"To perform source NAT", "To block traffic", "To log packets", "To forward ports"},
            "To perform source NAT"
        },
        {
            "Which command is used to list iptables chains?",
            {"sudo iptables -L -v", "sudo iptables -F", "sudo iptables -S", "sudo iptables -X"},
            "sudo iptables -L -v"
        },
        {
            "Which tool is primarily used for network packet analysis?",
            {"Wireshark", "Nmap", "tcpdump", "Snort"},
            "Wireshark"
        },
        {
            "What display filter in Wireshark would show traffic from a specific IP?",
            {"ip.addr==192.168.1.2", "tcp.port==80", "udp.port==53", "icmp.type==8"},
            "ip.addr==192.168.1.2"
        },
        {
            "Which command starts Snort in console mode?",
            {"sudo snort -A console -c /etc/snort/snort.conf -i eth0", "snort -v", "sudo snort -d", "snort --start"},
            "sudo snort -A console -c /etc/snort/snort.conf -i eth0"
        },
        {
            "What is the primary function of Snort?",
            {"Intrusion Detection", "Firewall management", "Log rotation", "Packet filtering"},
            "Intrusion Detection"
        },
        {
            "Which iptables option is used to forward traffic to another destination?",
            {"DNAT", "SNAT", "MASQUERADE", "LOG"},
            "DNAT"
        },
        {
            "Why is logging with iptables useful?",
            {"It helps diagnose dropped packets", "It increases throughput", "It automatically blocks attacks", "It encrypts traffic"},
            "It helps diagnose dropped packets"
        },
        {
            "What is a key advantage of integrating multiple network security tools?",
            {"Layered defense", "Simpler configuration", "Fewer logs", "Increased open ports"},
            "Layered defense"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your advanced network security knowledge:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
