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
    printf(BOLD_COLOR CYAN_COLOR "Day 22 - Breakfast: System Performance Metrics\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "CPU, Memory, and I/O Metrics",
            "Use vmstat to monitor CPU, memory, and process statistics.",
            "vmstat 1 3",
            "The 'vmstat' tool provides valuable real-time insight into CPU load, memory usage, swapping, and I/O performance in short intervals.",
            {"https://linux.die.net/man/8/vmstat", NULL, NULL, NULL, NULL}
        },
        {
            "Using htop for Monitoring",
            "Visualize process tree and sort by memory/CPU usage interactively.",
            "htop",
            "htop gives a real-time, colorized view of system processes, load average, and system uptime. It allows intuitive navigation and process control.",
            {"https://htop.dev", NULL, NULL, NULL, NULL}
        },
        {
            "Analyzing Disk I/O",
            "Monitor disk activity across devices using iostat.",
            "iostat -xz 1 3",
            "The 'iostat' tool shows device utilization and I/O statistics. Use it to identify bottlenecks and assess read/write throughput.",
            {"https://linux.die.net/man/1/iostat", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which tool shows CPU and memory metrics in real time?",
            {"df", "vmstat", "lsblk", "uptime"},
            "vmstat"
        },
        {
            "Which monitoring tool is interactive and colorful?",
            {"top", "iostat", "htop", "free"},
            "htop"
        },
        {
            "What does iostat primarily monitor?",
            {"Network packets", "User login sessions", "Disk I/O", "CPU temperature"},
            "Disk I/O"
        },
        {
            "What is required to use iostat on many Linux systems?",
            {"Installing sysstat", "Compiling the kernel", "Rebooting to enable", "Modifying .bashrc"},
            "Installing sysstat"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Time to test your performance monitoring knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You now understand performance metrics monitoring.\n" RESET_COLOR);
    return 0;
}