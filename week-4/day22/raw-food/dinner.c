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
    printf(BOLD_COLOR CYAN_COLOR "Day 22 - Dinner: Practical Performance Tuning\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Monitoring System Load",
            "Use vmstat and htop to observe system load and bottlenecks in real time.",
            "vmstat 1 5 && htop",
            "vmstat samples virtual memory statistics and can highlight CPU wait time or blocked processes. htop provides a colorful, interactive view of CPU, memory, and process states.",
            {"https://linux.die.net/man/8/vmstat", "https://htop.dev", NULL, NULL, NULL}
        },
        {
            "Tuning systemd Services",
            "List enabled services and disable unneeded ones to free up resources.",
            "systemctl list-unit-files --type=service | grep enabled",
            "Too many background services slow down boot and consume CPU/memory. Disabling Bluetooth, printing, or unused daemons helps streamline system load.",
            {"https://wiki.archlinux.org/title/Systemd/Services", NULL, NULL, NULL, NULL}
        },
        {
            "Disk I/O Analysis",
            "Identify I/O bottlenecks using iostat and tune storage configurations.",
            "iostat -xz 1 3",
            "The iostat utility reports CPU stats and I/O per device. High \"%util\" indicates a busy disk. Optimizations may include SSD upgrades, changing the I/O scheduler, or load balancing.",
            {"https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/performance_tuning_guide/io-schedulers", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What does vmstat help you monitor?",
            {"Network traffic", "Service ports", "Memory and process activity", "Open files"},
            "Memory and process activity"
        },
        {
            "Which tool provides an interactive real-time view of system performance?",
            {"iostat", "htop", "df", "uptime"},
            "htop"
        },
        {
            "How do you disable a background service using systemd?",
            {"service stop", "systemctl stop", "systemctl disable", "kill -9"},
            "systemctl disable"
        },
        {
            "What metric in iostat shows high disk utilization?",
            {"%idle", "%cpu", "%util", "%load"},
            "%util"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Evening assessment – test your tuning knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nDinner complete. Your system tuning toolkit is sharper than ever.\n" RESET_COLOR);
    return 0;
}
