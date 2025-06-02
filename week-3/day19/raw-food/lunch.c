#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

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
    printf(YELLOW_COLOR "Command Example:\n" RESET_COLOR GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Detailed Explanation:\n" RESET_COLOR "%s\n", lesson->detailed_explanation);
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
    printf("Your answer (A-D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') user_answer[0] -= 32;
    int idx = user_answer[0] - 'A';
    if (idx >= 0 && idx < 4 && strcmp(question->choices[idx], question->correct_answer) == 0) {
        printf(GREEN_COLOR "✅ Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "❌ Incorrect. Correct answer: %s\n" RESET_COLOR, question->correct_answer);
    }
    printf("\n");
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 19 - Lunch: Performance Optimization\n" RESET_COLOR);
    printf(YELLOW_COLOR "Time to sharpen your system’s performance like a blade.\n\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Optimizing System Resources",
            "Identify bottlenecks and tune CPU, memory, and disk usage.",
            "sudo nice -n 10 ./heavy_task",
            "`nice` and `renice` can lower or raise process priority to balance CPU time.\n"
            "Use `free -h` and `vmstat` to check memory usage and swap behavior.",
            {"https://man7.org/linux/man-pages/man1/nice.1.html", "https://linux.die.net/man/1/renice", NULL, NULL, NULL}
        },
        {
            "Managing Services with systemd",
            "Stop unneeded services to reduce resource load.",
            "sudo systemctl disable bluetooth",
            "Running fewer services reduces RAM, CPU, and I/O usage.\n"
            "`systemctl list-units --type=service` shows what's active.\n"
            "Disable or mask unnecessary services at boot to free up system power.",
            {"https://www.freedesktop.org/software/systemd/man/systemctl.html", "https://wiki.archlinux.org/title/Systemd", NULL, NULL, NULL}
        },
        {
            "Swapping and Cache Management",
            "Understand and control swap behavior and disk cache flushing.",
            "swapon -s; echo 10 > /proc/sys/vm/swappiness",
            "`swappiness` (0–100) determines how aggressively Linux uses swap.\n"
            "Use `sysctl vm.swappiness=10` for temporary change, or edit `/etc/sysctl.conf` for permanent.",
            {"https://wiki.archlinux.org/title/Swap", "https://linuxhint.com/linux_swappiness_value/", NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What does the `nice` command control?",
            {"Disk priority", "Memory priority", "Process scheduling priority", "Network priority"},
            "Process scheduling priority"
        },
        {
            "Which command shows swap space usage?",
            {"swapstat", "free -m", "swapon -s", "top"},
            "swapon -s"
        },
        {
            "How can you reduce the use of swap space?",
            {"Set swappiness to 80", "Use more swap partitions", "Set swappiness to 10", "Delete /swapfile"},
            "Set swappiness to 10"
        },
        {
            "Which systemd command disables a service at boot?",
            {"systemctl disable", "systemctl stop", "systemctl kill", "systemctl suspend"},
            "systemctl disable"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Quiz Time!\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. Your system is leaner and smarter.\n" RESET_COLOR);
    return 0;
}

