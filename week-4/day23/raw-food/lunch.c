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
    printf(BOLD_COLOR CYAN_COLOR "Day 23 - Lunch: Useful Bash Scripts\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Automating Log Cleanup",
            "Delete outdated logs using find command for disk space management.",
            "find /var/log -type f -name '*.log' -mtime +7 -exec rm {} \\;",
            "This command finds and removes log files older than 7 days, reducing clutter and freeing up space.",
            {"https://linux.die.net/man/1/find", NULL, NULL, NULL, NULL}
        },
        {
            "Disk Usage Monitoring Script",
            "Monitor disk space usage and alert if a threshold is exceeded.",
            "USAGE=$(df / | awk 'NR==2 {print $5}' | sed 's/%//'); if [ $USAGE -gt 85 ]; then echo \"Disk Alert\" | mail -s \"Disk Usage\" root; fi",
            "This script checks if root partition disk usage exceeds 85% and sends an alert email to admin.",
            {"https://linuxize.com/post/how-to-check-disk-usage-in-linux/", NULL, NULL, NULL, NULL}
        },
        {
            "Command-Line Options with getopts",
            "Parse script options using getopts for flexible CLI tools.",
            "while getopts \"u:p:\" opt; do case $opt in u) user=$OPTARG ;; p) path=$OPTARG ;; *) echo 'Invalid';; esac; done",
            "This allows passing arguments to scripts like ./script.sh -u user -p /path for dynamic input.",
            {"https://wiki.bash-hackers.org/howto/getopts_tutorial", NULL, NULL, NULL, NULL}
        },
        {
            "Script Debugging Techniques",
            "Use bash flags to catch and fix bugs in shell scripts.",
            "bash -x script.sh && set -e && set -u",
            "The -x flag traces command execution, -e exits on error, and -u treats unset variables as errors.",
            {"https://linuxize.com/post/how-to-debug-bash-scripts/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What command deletes log files older than 7 days?",
            {"rm -rf /var/log/*.log", "find /var/log -name '*.log'", "find /var/log -type f -name '*.log' -mtime +7 -exec rm {} \\;", "delete /var/log/old.log"},
            "find /var/log -type f -name '*.log' -mtime +7 -exec rm {} \\;"
        },
        {
            "What does the getopts command help with?",
            {"Managing file permissions", "Handling script input arguments", "Debugging errors", "Formatting output"},
            "Handling script input arguments"
        },
        {
            "Which bash flag enables command tracing?",
            {"-u", "-e", "-x", "-d"},
            "-x"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Quick check – reinforce your scripting knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. Now go script something powerful!\n" RESET_COLOR);
    return 0;
}
