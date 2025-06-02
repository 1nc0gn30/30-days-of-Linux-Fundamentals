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
    printf(BOLD_COLOR CYAN_COLOR "Day 25 - Dinner: Cron Job Automation Lab\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Schedule Backups",
            "Use cron to schedule daily backups of the /etc directory.",
            "0 2 * * * tar -czf /backups/etc-$(date +\"%F\").tar.gz /etc",
            "This cron job runs daily at 2 AM and creates a compressed backup of /etc in the /backups folder.",
            {"https://crontab.guru", "https://linux.die.net/man/5/crontab", NULL, NULL, NULL}
        },
        {
            "Automate Log Cleanup",
            "Schedule regular log cleanup to save disk space.",
            "0 3 * * 0 find /var/log -name '*.log' -mtime +7 -exec rm {} \\\\;",
            "This weekly job removes .log files older than 7 days every Sunday at 3 AM.",
            {"https://www.thegeekdiary.com/cron-job-examples-in-linux/", NULL, NULL, NULL, NULL}
        },
        {
            "Troubleshooting Cron Jobs",
            "Learn to debug cron job failures using logs and basic testing methods.",
            "cat /var/log/syslog | grep CRON",
            "Most cron job errors are due to incorrect paths or missing environment variables. Check logs for messages.",
            {"https://opensource.com/article/19/9/debug-cron-jobs", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "At what time does \"0 3 * * 0\" schedule a job to run?",
            {"3 AM every Sunday", "Midnight daily", "3 PM daily", "3 AM every day"},
            "3 AM every Sunday"
        },
        {
            "Which directory is commonly checked for cron logs?",
            {"/var/log/cron.log", "/var/log/cron", "/var/log/syslog", "/etc/cron.d/log"},
            "/var/log/syslog"
        },
        {
            "Why might a cron job fail silently?",
            {"Permissions issue", "Missing PATH", "Invalid syntax", "All of the above"},
            "All of the above"
        },
        {
            "Which operator runs commands found by 'find'?",
            {"--exec", "-run", "-do", "-exec"},
            "-exec"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nDinner Quiz – Test Your Cron Automation Skills:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nDinner complete. You've automated tasks like a pro!\n" RESET_COLOR);
    return 0;
}
