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
    printf(BOLD_COLOR CYAN_COLOR "Day 25 - Lunch: Advanced Cron Usage\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Cron Timing Syntax",
            "Learn how to write custom cron schedules using the 5-field format.",
            "* * * * * /path/to/command",
            "Each asterisk represents a time field: minute, hour, day of month, month, and day of week. Use ranges, lists, and step values for advanced timing.",
            {"https://crontab.guru/", "https://www.baeldung.com/linux/cron-expressions", NULL, NULL, NULL}
        },
        {
            "Environment Variables in Cron",
            "Understand how to work with environment variables in cron jobs.",
            "PATH=/usr/bin:/bin\n* * * * * my_script.sh",
            "Cron jobs run with a minimal environment. Define required variables at the top of the crontab or inside the script for reliability.",
            {"https://www.thegeekdiary.com/setting-environment-variables-in-cron-job/", NULL, NULL, NULL, NULL}
        },
        {
            "Cron Logs and Troubleshooting",
            "Explore how to troubleshoot and debug cron jobs by viewing logs.",
            "grep CRON /var/log/syslog",
            "Check system logs to confirm whether cron executed your job. Use 'mail' output or redirect output to log files for debugging.",
            {"https://www.cyberciti.biz/faq/cron-job-errors-debugging/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which of the following is the correct cron format for every 15 minutes?",
            {"*/15 * * * *", "15 * * * *", "0 15 * * *", "* * */15 * *"},
            "*/15 * * * *"
        },
        {
            "What does the PATH variable affect in cron jobs?",
            {"Time of execution", "User privileges", "Available commands", "Logging format"},
            "Available commands"
        },
        {
            "Where can you check logs for cron job execution?",
            {"/etc/cron.d", "/var/log/syslog", "/home/user/cron.log", "/usr/local/bin"},
            "/var/log/syslog"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Lunch Quiz – Deepen Your Cron Knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. Ready for some real-world cron lab tasks!\n" RESET_COLOR);
    return 0;
}
