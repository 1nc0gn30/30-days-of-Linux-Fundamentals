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

    printf("Your answer (A, B, C, D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = '\0';

    if (strlen(user_answer) >= 1) {
        char c = toupper(user_answer[0]);
        if (c >= 'A' && c <= 'D') {
            int idx = c - 'A';
            if (strcmp(question->choices[idx], question->correct_answer) == 0) {
                printf(GREEN_COLOR "\u2705 Correct! \"%s\" is the right answer.\n" RESET_COLOR, question->correct_answer);
            } else {
                printf(RED_COLOR "\u274C Incorrect.\n" RESET_COLOR);
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
    printf(BOLD_COLOR CYAN_COLOR "Day 29 - Breakfast: System Hardening Techniques\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Removing Unnecessary Services",
            "Identify and disable services that are not needed to reduce attack surface.",
            "systemctl list-unit-files --type=service\nsystemctl disable bluetooth",
            "Unneeded services can introduce vulnerabilities. Disable unused ones using 'systemctl disable'.",
            {"https://www.cyberciti.biz/faq/linux-check-enabled-services/", NULL}
        },
        {
            "Configuring Firewall Rules",
            "Review and apply firewall rules using UFW or iptables.",
            "ufw default deny incoming\nufw allow 22\nufw enable",
            "Firewalls help restrict network access. Always deny by default and explicitly allow required ports.",
            {"https://help.ubuntu.com/community/UFW", NULL}
        },
        {
            "SSH Security Best Practices",
            "Harden SSH access by disabling root login and using key-based auth.",
            "nano /etc/ssh/sshd_config\nPermitRootLogin no\nPasswordAuthentication no",
            "Changing default SSH configs helps reduce brute-force attack risks.",
            {"https://www.ssh.com/academy/ssh/security-best-practices", NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Why should unnecessary services be disabled?",
            {"To save power", "To reduce system noise", "To reduce vulnerabilities", "To save storage"},
            "To reduce vulnerabilities"
        },
        {
            "What firewall command restricts SSH to a specific IP?",
            {"iptables --ssh 22", "ufw allow 22", "ufw allow from 192.168.1.10 to any port 22", "firewall-cmd --ssh"},
            "ufw allow from 192.168.1.10 to any port 22"
        },
        {
            "What setting disables SSH password login?",
            {"PasswordAuth off", "SSHPassword disable", "PasswordAuthentication no", "UsePassword no"},
            "PasswordAuthentication no"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Morning Quiz – Test Your System Hardening Basics:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You're ready to audit and secure your system like a pro.\n" RESET_COLOR);
    return 0;
}
