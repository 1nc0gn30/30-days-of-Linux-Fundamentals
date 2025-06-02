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
    printf(BOLD_COLOR CYAN_COLOR "Day 21 - Breakfast: Week 3 Security Recap\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "User Management & Permissions",
            "Create, modify, and manage users securely.",
            "sudo useradd -m neal && sudo passwd neal",
            "Manage users with useradd/usermod, assign groups, and protect home directories using chmod/chown.",
            {"https://linuxize.com/post/how-to-create-users-in-linux-using-the-useradd-command/", NULL, NULL, NULL, NULL}
        },
        {
            "Firewall Configuration",
            "Set strict inbound traffic rules.",
            "sudo iptables -P INPUT DROP",
            "Configure iptables/nftables to only allow required ports, e.g., SSH, HTTP. Test with nmap or netcat.",
            {"https://wiki.archlinux.org/title/Iptables", NULL, NULL, NULL, NULL}
        },
        {
            "Intrusion Detection Systems",
            "Snort and Wireshark usage overview.",
            "sudo snort -A console -i eth0 -c /etc/snort/snort.conf",
            "Snort detects network anomalies, Wireshark visually inspects packets. Learn to filter and analyze traffic.",
            {"https://docs.snort.org/", NULL, NULL, NULL, NULL}
        },
        {
            "SELinux/AppArmor Basics",
            "Control app behavior with mandatory access.",
            "sudo aa-status OR sudo getenforce",
            "Security modules enforce policies that restrict how apps interact with system components.",
            {"https://wiki.ubuntu.com/AppArmor", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What command modifies file permissions?",
            {"chmod", "chown", "usermod", "passwd"},
            "chmod"
        },
        {
            "Which command enforces inbound packet restrictions?",
            {"iptables", "chgrp", "ifconfig", "ss"},
            "iptables"
        },
        {
            "Which tool helps analyze packet traffic visually?",
            {"Snort", "Wireshark", "Fail2Ban", "auditd"},
            "Wireshark"
        },
        {
            "What does SELinux do?",
            {"Controls disk I/O", "Logs authentication", "Enforces access controls", "Disables root access"},
            "Enforces access controls"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Time to reinforce what you learned:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. Your security fundamentals are solid.\n" RESET_COLOR);
    return 0;
}
