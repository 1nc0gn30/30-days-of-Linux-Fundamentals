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
    printf(BOLD_COLOR CYAN_COLOR "Day 19 - Breakfast: System Performance Metrics\n" RESET_COLOR);
    printf(YELLOW_COLOR "Let's explore the soul of your Linux system through performance monitoring...\n\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "CPU, Memory, and I/O Metrics with vmstat, top, and iotop",
            "Understand how to monitor the heartbeat of your system.",
            "vmstat 1, top, iotop",
            "`vmstat` provides insights on processes, memory, paging, block I/O, and CPU usage.\n"
            "`top` gives a dynamic real-time view of running tasks and system load.\n"
            "`iotop` shows real-time disk I/O per process—great for finding I/O bottlenecks.",
            {"https://man7.org/linux/man-pages/man8/vmstat.8.html", "https://man7.org/linux/man-pages/man1/top.1.html", "https://linux.die.net/man/1/iotop", NULL, NULL}
        },
        {
            "Using htop for Monitoring",
            "A colorful and interactive alternative to top.",
            "htop",
            "`htop` not only shows CPU, memory, and swap usage but allows you to kill processes with a keystroke, sort columns, and more.\n"
            "It provides an intuitive UI for process management and system analysis.",
            {"https://htop.dev/", "https://www.digitalocean.com/community/tutorials/how-to-use-htop", NULL, NULL, NULL}
        },
        {
            "Analyzing Disk I/O with iostat",
            "Measure your system’s disk read/write speeds and identify I/O bottlenecks.",
            "iostat -xz 1",
            "`iostat` from the sysstat package shows CPU stats and per-device I/O performance.\n"
            "Flags:\n  -x: extended stats\n  -z: suppress zeroes\n  1: refresh interval in seconds.",
            {"https://linux.die.net/man/1/iostat", "https://www.thegeekdiary.com/understanding-iostat-command-output-in-linux/", NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which command gives a snapshot of memory, CPU, and I/O in real time?",
            {"df", "vmstat", "du", "uptime"},
            "vmstat"
        },
        {
            "What is a major advantage of using `htop` over `top`?",
            {"Saves output to a file", "Provides a GUI", "Colorized interface & easier navigation", "Uses less CPU"},
            "Colorized interface & easier navigation"
        },
        {
            "Which command shows disk I/O usage per process?",
            {"iotop", "free", "ps", "du"},
            "iotop"
        },
        {
            "What does the `iostat -xz 1` command do?",
            {"Shows CPU usage only", "Shows per-device disk stats with refresh every second", "Kills high I/O processes", "Formats the disk"},
            "Shows per-device disk stats with refresh every second"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Quiz Time!\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nWell done. You've tapped into your system's pulse.\n" RESET_COLOR);
    return 0;
}

