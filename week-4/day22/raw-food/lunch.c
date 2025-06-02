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
    printf(BOLD_COLOR CYAN_COLOR "Day 22 - Lunch: Performance Optimization\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Optimizing CPU Usage",
            "Identify and reduce CPU-heavy processes.",
            "ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head",
            "Use the 'ps' command to list running processes sorted by CPU usage. Consider renicing or terminating heavy consumers.",
            {"https://www.tecmint.com/find-linux-processes-by-cpu-mem-usage/", NULL, NULL, NULL, NULL}
        },
        {
            "Optimizing Memory Usage",
            "Check memory usage and address high memory consumption.",
            "free -h",
            "The 'free' command shows current RAM and swap usage. Monitor for memory leaks and use tools like top or htop to identify offenders.",
            {"https://www.linuxtechi.com/check-memory-usage-linux/", NULL, NULL, NULL, NULL}
        },
        {
            "Managing Services with systemd",
            "Disable services you don't use to save resources.",
            "systemctl list-units --type=service --state=running",
            "Systemd helps manage startup and background services. Disabling unused ones like 'bluetooth' or 'cups' improves performance.",
            {"https://wiki.archlinux.org/title/Systemd", NULL, NULL, NULL, NULL}
        },
        {
            "Swapping and Cache Management",
            "Understand swap behavior and tweak swappiness.",
            "cat /proc/meminfo | grep -E 'swap|cached'; sysctl vm.swappiness",
            "Swappiness defines how aggressively the kernel uses swap. Lower values prefer RAM over swap, which can improve responsiveness.",
            {"https://linuxhint.com/linux_swap_memory_management/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which command helps identify top CPU-consuming processes?",
            {"free -h", "ps -eo ... --sort=-%cpu", "top -m cpu", "kill -9"},
            "ps -eo ... --sort=-%cpu"
        },
        {
            "What does the 'free' command display?",
            {"CPU temperature", "Active services", "Memory usage", "Filesystem size"},
            "Memory usage"
        },
        {
            "Which command disables a service using systemd?",
            {"systemctl stop", "systemctl disable", "service remove", "kill -9"},
            "systemctl disable"
        },
        {
            "What does swappiness control?",
            {"CPU frequency", "Disk read rate", "Swap memory usage behavior", "I/O scheduler"},
            "Swap memory usage behavior"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Ready to optimize? Quiz time!\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. Your system runs leaner and faster now.\n" RESET_COLOR);
    return 0;
}
