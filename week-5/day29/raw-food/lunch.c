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
    printf(BOLD_COLOR CYAN_COLOR "Day 29 - Lunch: Security Audits and Tools\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Using Lynis for System Audits",
            "Run Lynis to analyze your system's security posture.",
            "lynis audit system",
            "Lynis provides detailed reports on security settings and potential vulnerabilities. Use it regularly.",
            {"https://cisofy.com/documentation/lynis/", NULL}
        },
        {
            "Reviewing Logs for Suspicious Activity",
            "Learn how to identify red flags in logs like auth.log and syslog.",
            "grep 'Failed password' /var/log/auth.log",
            "Regularly checking logs helps detect brute-force attempts, privilege escalation, or unusual behavior.",
            {"https://www.thegeekdiary.com/understanding-var-log-messages-file-format-on-linux/", NULL}
        },
        {
            "Patching and Updates",
            "Ensure your packages are current and security patches applied.",
            "sudo apt update && sudo apt upgrade -y",
            "Outdated packages may contain known vulnerabilities. Always stay up to date.",
            {"https://wiki.debian.org/Security", NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What does the 'lynis audit system' command do?",
            {"Launches a firewall", "Installs updates", "Audits system for security", "Starts system logging"},
            "Audits system for security"
        },
        {
            "Which log file shows SSH login attempts?",
            {"/var/log/syslog", "/var/log/apt/history.log", "/var/log/auth.log", "/var/log/kern.log"},
            "/var/log/auth.log"
        },
        {
            "Why is it important to patch systems regularly?",
            {"To save disk space", "To add new users", "To fix bugs and vulnerabilities", "To increase CPU speed"},
            "To fix bugs and vulnerabilities"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Lunch Quiz – Test Your Security Audit Knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. Time to prepare for practical hardening in the evening!\n" RESET_COLOR);
    return 0;
}
