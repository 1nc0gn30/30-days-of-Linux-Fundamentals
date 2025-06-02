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
    printf(YELLOW_COLOR "\n[Press Enter to continue...]\n" RESET_COLOR);
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
                printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR "- The correct answer is: %s\n", question->correct_answer);
            }
        } else {
            printf(RED_COLOR "Invalid input. Use A-D or a-d.\n" RESET_COLOR);
        }
    } else {
        printf(RED_COLOR "No input received.\n" RESET_COLOR);
    }

    printf("\n");
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 20 - Lunch: Building Useful Scripts\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Automating Tasks with Scripts",
            "Write reusable scripts to automate logs cleanup and disk checks.",
            "find /var/log -name \"*.log\" -mtime +7 -delete",
            "System maintenance often involves repetitive tasks like cleaning old logs or checking disk usage. "
            "Instead of doing this manually, we script it.\n"
            "This one-liner removes .log files older than 7 days. Wrap it in a script and add to cron for hands-off sysadmin magic.",
            {"https://opensource.com/article/19/9/cron-linux", NULL, NULL, NULL, NULL}
        },
        {
            "Using getopts for Options",
            "Parse flags (-h, -v, -d) inside scripts using getopts.",
            "while getopts \"hvf:\" opt; do case $opt in h) echo Help ;; v) echo Verbose ;; f) echo \"File: $OPTARG\" ;; esac; done",
            "`getopts` lets scripts handle CLI options just like pro tools do.\n"
            "Use it to make your scripts user-friendly, interactive, and predictable. Combine it with functions for modularity.",
            {"https://wiki.bash-hackers.org/howto/getopts_tutorial", NULL, NULL, NULL, NULL}
        },
        {
            "Debugging Shell Scripts",
            "Enable verbose and fail-fast modes for bug tracing.",
            "bash -x script.sh or set -x and set -e inside the script",
            "`set -x` prints commands before execution—like tracing steps in a maze.\n"
            "`set -e` causes your script to bail out on any failure—essential when your script is part of something critical.",
            {"https://linuxize.com/post/how-to-debug-bash-scripts/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which command removes logs older than 7 days?",
            {"rm *.log", "find /var/log -type f -mtime +7 -delete", "logrotate", "del -o 7"},
            "find /var/log -type f -mtime +7 -delete"
        },
        {
            "Which tool is best for parsing -h -v -f flags in shell?",
            {"shift", "case", "getopts", "grep"},
            "getopts"
        },
        {
            "What does `set -x` do?",
            {"Enable comments", "Enable debug mode", "Exit on error", "Print environment vars"},
            "Enable debug mode"
        },
        {
            "What does `set -e` ensure?",
            {"Stops script on error", "Echoes each line", "Exits script after loop", "Ignores return values"},
            "Stops script on error"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Quiz Time:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. You now build smarter, safer shell tools.\n" RESET_COLOR);
    return 0;
}
