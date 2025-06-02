#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

typedef struct {
    const char *topic;
    const char *description;
    const char *command_example;
    const char *detailed_explanation;
    const char *resources[MAX_RESOURCES];
} Lesson;

typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson: %s\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Example:\n" RESET_COLOR GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR "%s\n", lesson->detailed_explanation);
    printf(YELLOW_COLOR "Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && lesson->resources[i] != NULL; i++) {
        printf("- %s\n", lesson->resources[i]);
    }
    printf(YELLOW_COLOR "\nPress Enter to continue...\n" RESET_COLOR);
    getchar();
    printf("\n");
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];

    printf(BOLD_COLOR GREEN_COLOR "Quiz: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }

    printf("Your answer (A, a, A., a., etc): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = '\0';

    if (strlen(user_answer) >= 1) {
        char c = toupper(user_answer[0]);
        if (c >= 'A' && c <= 'D') {
            int idx = c - 'A';
            if (strcmp(question->choices[idx], question->correct_answer) == 0) {
                printf(GREEN_COLOR "✅ Correct! \"%s\" is the right answer.\n" RESET_COLOR, question->correct_answer);
            } else {
                printf(RED_COLOR "❌ Incorrect.\n" RESET_COLOR);
                printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR);
                printf("- Correct Answer: %s\n", question->correct_answer);
            }
        } else {
            printf(RED_COLOR "Invalid choice. Please enter A, B, C, or D.\n" RESET_COLOR);
        }
    } else {
        printf(RED_COLOR "No input received.\n" RESET_COLOR);
    }

    printf("\n");
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 21 - Dinner: Lab Challenge - Comprehensive Review\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "End-to-End System Setup",
            "Secure a Linux system from scratch, harden it, and configure recovery procedures.",
            "sudo apt update && sudo apt install ufw fail2ban rsync",
            "Start from a base install, update software, harden SSH, configure firewall rules with UFW, install IDS tools, and enable automatic backups.",
            {"https://wiki.debian.org/Hardening", "https://linuxsecurity.expert/tutorials/", NULL, NULL, NULL}
        },
        {
            "Practical Security Assessment",
            "Conduct a vulnerability scan and apply patches.",
            "sudo lynis audit system",
            "Use tools like Lynis or OpenVAS to scan for system weaknesses. Analyze the report, and patch issues like weak passwords, insecure permissions, or missing updates.",
            {"https://cisofy.com/lynis/", "https://www.openvas.org/", NULL, NULL, NULL}
        },
        {
            "Network Configuration and Testing",
            "Set up secure interfaces, validate DNS, and test connectivity and firewall.",
            "ip a && ping -c 4 8.8.8.8",
            "Configure static IPs or DHCP as needed. Test DNS with dig or ping. Use nmap or netstat to verify port security and open services.",
            {"https://wiki.archlinux.org/title/Network_configuration", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which tool is commonly used to perform a security audit on Linux?",
            {"netstat", "ufw", "lynis", "top"},
            "lynis"
        },
        {
            "Which of the following is a valid way to set up automatic backups?",
            {"rsync + cron job", "ping + ssh", "iptables + curl", "dig + systemctl"},
            "rsync + cron job"
        },
        {
            "What does 'ip a' show you?",
            {"Port status", "Disk usage", "Network interfaces", "CPU usage"},
            "Network interfaces"
        },
        {
            "Why use a tool like fail2ban?",
            {"Monitor system uptime", "Block brute force attacks", "Check memory usage", "Disable services"},
            "Block brute force attacks"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Test your applied security knowledge below:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nDinner complete. Your system is now audit-ready.\n" RESET_COLOR);
    return 0;
}
