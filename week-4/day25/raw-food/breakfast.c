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
    printf(BOLD_COLOR CYAN_COLOR "Day 25 - Breakfast: Introduction to Cron\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "What is Cron?",
            "Cron is a time-based job scheduler in Unix-like systems. It automates recurring tasks.",
            "cron, crontab, /etc/crontab",
            "Cron helps automate tasks like backups, cleanup, and notifications using a scheduling daemon.",
            {"https://opensource.com/article/19/9/intro-cron", NULL, NULL, NULL, NULL}
        },
        {
            "Setting Up Cron Jobs",
            "Use crontab to create, view, or edit cron jobs for automation.",
            "crontab -e\n* * * * * echo 'Hello' >> /tmp/hello.txt",
            "The syntax includes: minute, hour, day of month, month, and day of week.\nUse `crontab -l` to list current jobs.",
            {"https://crontab.guru/", NULL, NULL, NULL, NULL}
        },
        {
            "Common Cron Use Cases",
            "Examples of routine automation with cron.",
            "0 2 * * * /home/user/backup.sh",
            "This job runs every day at 2 AM and calls a script for backups. Cron is ideal for such periodic maintenance tasks.",
            {"https://linuxize.com/post/scheduling-cron-jobs-with-crontab/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What does cron use to determine when to run jobs?",
            {"System uptime", "System load", "A schedule expression", "Kernel interrupts"},
            "A schedule expression"
        },
        {
            "Which command lets you edit your current user's cron jobs?",
            {"cron -e", "crontab -e", "cronjob --edit", "editcron"},
            "crontab -e"
        },
        {
            "Where are system-wide cron jobs typically stored?",
            {"/etc/cron.d", "/home/cron", "/var/crontab", "/etc/systemcron"},
            "/etc/cron.d"
        },
        {
            "What happens if you forget to specify output redirection in a cron job?",
            {"It fails silently", "Sends mail to the user", "Writes to syslog", "Asks for confirmation"},
            "Sends mail to the user"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nMorning Quiz – Test Your Cron Basics:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You're ready to schedule like a pro!\n" RESET_COLOR);
    return 0;
}
