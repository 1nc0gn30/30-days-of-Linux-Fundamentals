#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

// ANSI color codes for terminal formatting
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

// Lesson structure holds key elements for each lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *command_example;
    const char *detailed_explanation;
    const char *resources[MAX_RESOURCES];
} Lesson;

// Question structure for interactive quiz items
typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

// Displays a lesson in a formatted manner with detailed explanations
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

// Displays a quiz question and checks user input against the correct answer
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
    // Clear screen and display the session header
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 17 - Breakfast: Network Hardening\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Breakfast...\n" RESET_COLOR);
    getchar();

    // Enhanced Breakfast Lessons with additional details and context (10 lessons)
    Lesson lessons[] = {
        {
            "Disabling Unnecessary Network Services",
            "Identify non-critical services and disable them to minimize the potential attack surface.",
            "sudo systemctl disable bluetooth",
            "Many Linux systems ship with services that are not required for a given deployment. This lesson teaches you how to review active services and disable those that are not needed. Disabling unused services (such as Bluetooth on a server) reduces resource usage and limits exposure to exploits.",
            {"https://www.cyberciti.biz/tips/disable-unneeded-services-linux.html", "https://www.tecmint.com/stop-disable-unwanted-services-in-linux/", "https://www.digitalocean.com/community/tutorials/how-to-manage-systemd-services", NULL, NULL}
        },
        {
            "Identifying Active Services",
            "Learn to list all active network services to pinpoint potential vulnerabilities.",
            "sudo netstat -tulpn",
            "Using tools like netstat or the newer 'ss' command, you can display active listening ports along with the associated service names and process IDs. This helps in identifying which services are running and if any unknown or unneeded service is active.",
            {"https://linux.die.net/man/8/netstat", "https://man7.org/linux/man-pages/man8/ss.8.html", NULL, NULL, NULL}
        },
        {
            "Using systemctl to Manage Services",
            "Master the usage of systemctl to manage, start, and stop services efficiently.",
            "sudo systemctl stop avahi-daemon",
            "The systemctl command provides a unified interface to control system services under systemd. This lesson covers how to stop and disable services, ensuring that only essential services are allowed to run on your system.",
            {"https://www.freedesktop.org/software/systemd/man/systemctl.html", "https://www.digitalocean.com/community/tutorials/understanding-systemd-units-and-unit-files", NULL, NULL, NULL}
        },
        {
            "Configuring TCP Wrappers",
            "Implement basic network access control with TCP wrappers using hosts.allow.",
            "sudo nano /etc/hosts.allow",
            "TCP wrappers offer a simple but effective method to restrict access to network services. By specifying which hosts are permitted in /etc/hosts.allow, you can filter incoming connections before they reach the service level.",
            {"https://www.tldp.org/HOWTO/TCP-Wrappers-HOWTO/", "https://www.cyberciti.biz/faq/tcp-wrappers-howto/", NULL, NULL, NULL}
        },
        {
            "Understanding /etc/hosts.deny",
            "Block unwanted hosts by properly configuring /etc/hosts.deny.",
            "sudo nano /etc/hosts.deny",
            "Complementing hosts.allow, the /etc/hosts.deny file lets you explicitly block access from specific IP addresses or hostnames. This two-tier approach to access control enhances your network security posture.",
            {"https://linux.die.net/man/5/hosts.deny", "https://www.cyberciti.biz/tips/howto-use-hosts-allow-and-hosts-deny.html", NULL, NULL, NULL}
        },
        {
            "Port Scanning with nmap",
            "Use nmap for comprehensive scanning of open ports and services running on target systems.",
            "nmap -sV target_ip",
            "Nmap is one of the most powerful tools for network discovery. In this lesson, you learn how to run a version scan (-sV) to not only detect open ports but also determine the services and versions running on those ports.",
            {"https://nmap.org/book/man.html", "https://nmap.org/book/inst-windows.html", NULL, NULL, NULL}
        },
        {
            "Interpreting nmap Output",
            "Analyze detailed nmap scan results to understand the network's exposed services.",
            "nmap -A target_ip",
            "The aggressive scan (-A) in nmap combines OS detection, version scanning, script scanning, and traceroute. This lesson explains how to interpret the output, which is critical for identifying vulnerable services and planning hardening measures.",
            {"https://nmap.org/book/toc.html", "https://nmap.org/book/man-osdetect.html", NULL, NULL, NULL}
        },
        {
            "Reviewing Open Ports with ss",
            "Verify open ports using the ss command, a modern replacement for netstat.",
            "ss -tulwn",
            "The 'ss' command provides a fast and detailed view of open TCP and UDP ports along with associated process details. This tool is useful for confirming the results from other port-scanning methods.",
            {"https://man7.org/linux/man-pages/man8/ss.8.html", "https://www.tecmint.com/ss-command-examples-in-linux/", NULL, NULL, NULL}
        },
        {
            "Best Practices for Network Hardening",
            "Discuss a variety of best practices for securing network services and minimizing exposure.",
            "echo 'Implement best practices'",
            "This lesson aggregates multiple techniques such as disabling unneeded services, tightening access controls, and routinely reviewing open ports. Adopting these practices will significantly lower the risk of unauthorized access or exploitation.",
            {"https://www.sans.org/security-resources/policies/general/pdf/network-security-policy", "https://www.cisa.gov/publication/securing-network-infrastructure", NULL, NULL, NULL}
        },
        {
            "Securing Remote Access",
            "Limit and secure remote access protocols to reduce potential attack vectors.",
            "sudo systemctl disable telnet",
            "Many legacy protocols like Telnet transmit data in plaintext, making them prime targets for interception. This lesson emphasizes disabling such insecure services and opting for more secure alternatives like SSH with proper configurations.",
            {"https://www.cyberciti.biz/tips/secure-remote-access.html", "https://www.ssh.com/academy/ssh", NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }

    // Enhanced Breakfast Questions with additional clarity (10 questions)
    Question questions[] = {
        {
            "Which command disables an unnecessary service using systemctl?",
            {"sudo systemctl disable bluetooth", "sudo systemctl enable ssh", "sudo systemctl status netstat", "sudo systemctl start avahi-daemon"},
            "sudo systemctl disable bluetooth"
        },
        {
            "What tool can be used to view active network services along with their associated ports?",
            {"netstat", "tcpdump", "curl", "ifconfig"},
            "netstat"
        },
        {
            "Which file is used to allow specific hosts in TCP wrappers?",
            {"/etc/hosts.allow", "/etc/hosts.deny", "/etc/services", "/etc/network/interfaces"},
            "/etc/hosts.allow"
        },
        {
            "Which file is used to block unwanted hosts in TCP wrappers?",
            {"/etc/hosts.deny", "/etc/hosts.allow", "/etc/passwd", "/etc/shadow"},
            "/etc/hosts.deny"
        },
        {
            "What is the primary purpose of using nmap in network hardening?",
            {"Port scanning and service enumeration", "Encrypting data", "Disabling services", "Managing user accounts"},
            "Port scanning and service enumeration"
        },
        {
            "Which nmap option is used to perform an aggressive scan combining OS detection and service versioning?",
            {"-A", "-sV", "-O", "-Pn"},
            "-A"
        },
        {
            "Which command displays listening ports using ss, a modern alternative to netstat?",
            {"ss -tulwn", "ss -a", "netstat -r", "ifconfig -a"},
            "ss -tulwn"
        },
        {
            "What is one key benefit of disabling non-essential network services?",
            {"Reduce attack surface", "Increase power consumption", "Enhance UI performance", "Improve file storage"},
            "Reduce attack surface"
        },
        {
            "Which command is used to stop a service immediately using systemctl?",
            {"sudo systemctl stop avahi-daemon", "sudo systemctl list", "sudo systemctl start avahi-daemon", "sudo systemctl restart bluetooth"},
            "sudo systemctl stop avahi-daemon"
        },
        {
            "What is the overall goal of implementing network hardening practices?",
            {"Minimize vulnerabilities", "Maximize open ports", "Increase service availability", "Streamline user access"},
            "Minimize vulnerabilities"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your detailed network hardening knowledge:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
