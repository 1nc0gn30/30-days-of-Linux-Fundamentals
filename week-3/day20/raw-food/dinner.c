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

#define MAX_INPUT 100

typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void pause_continue() {
    printf(YELLOW_COLOR "\n[Press Enter to continue...]\n" RESET_COLOR);
    getchar();
}

void display_lab(const char *title, const char *objective, const char *wisdom, const char *steps[], int step_count) {
    printf(BOLD_COLOR BLUE_COLOR "\n[Lab: %s]\n" RESET_COLOR, title);
    printf(CYAN_COLOR "Objective: %s\n" RESET_COLOR, objective);
    printf(YELLOW_COLOR "Wisdom:\n" RESET_COLOR "%s\n", wisdom);
    printf(YELLOW_COLOR "Steps:\n" RESET_COLOR);
    for (int i = 0; i < step_count; i++) {
        printf("- %s\n", steps[i]);
    }
    pause_continue();
}

void display_question(const Question *q) {
    char input[MAX_INPUT];
    printf(BOLD_COLOR GREEN_COLOR "Quiz: %s\n" RESET_COLOR, q->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q->choices[i]);
    }

    printf("Your answer: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) >= 1) {
        char c = toupper(input[0]);
        if (c >= 'A' && c <= 'D') {
            int idx = c - 'A';
            if (strcmp(q->choices[idx], q->correct_answer) == 0) {
                printf(GREEN_COLOR "✅ Correct! \"%s\" is the right answer.\n" RESET_COLOR, q->correct_answer);
            } else {
                printf(RED_COLOR "❌ Incorrect.\n" RESET_COLOR);
                printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR "- The correct answer is: %s\n", q->correct_answer);
            }
        } else {
            printf(RED_COLOR "Invalid input. Use A-D or a-d.\n" RESET_COLOR);
        }
    }
    pause_continue();
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 20 - Dinner: Scripting Challenge Labs\n" RESET_COLOR);
    printf(YELLOW_COLOR "Let’s build real scripts that solve real admin tasks...\n" RESET_COLOR);
    pause_continue();

    const char *lab1_steps[] = {
        "Create a new script: nano monitor_disk.sh",
        "Inside the script:",
        "  THRESHOLD=80",
        "  USAGE=$(df / | grep / | awk '{print $5}' | sed 's/%//g')",
        "  if [ \"$USAGE\" -gt \"$THRESHOLD\" ]; then echo \"Disk space high: $USAGE%\" | mail -s \"Disk Alert\" root; fi",
        "Make the script executable: chmod +x monitor_disk.sh",
        "Test manually, then add to crontab if needed."
    };
    const char *lab1_wisdom = "Proactive monitoring can prevent outages before they impact users. "
                              "A 5-minute script can save hours of downtime.";

    display_lab("Automate System Monitoring", "Send alert email if disk usage exceeds threshold.", lab1_wisdom, lab1_steps, 7);

    const char *lab2_steps[] = {
        "Create: nano backup_logs.sh",
        "Inside the script:",
        "  BACKUP_DIR=\"/backup/$(date +%F)\"",
        "  mkdir -p \"$BACKUP_DIR\"",
        "  cp -r /var/log \"$BACKUP_DIR\"",
        "  find /backup -type d -mtime +7 -exec rm -rf {} +",
        "Make executable: chmod +x backup_logs.sh",
        "Schedule via cron: crontab -e"
    };
    const char *lab2_wisdom = "Automation isn't about laziness—it's about reliability. Backups should never depend on memory.";

    display_lab("Backup Automation Script", "Backup /var/log and delete backups older than 7 days.", lab2_wisdom, lab2_steps, 8);

    const char *lab3_steps[] = {
        "Create a script with bugs: nano broken_script.sh",
        "Example content with error:",
        "  #!/bin/bash",
        "  for i in 1 2 3",
        "    echo \"Number $i\"",
        "Make executable: chmod +x broken_script.sh",
        "Run with debug mode: bash -x broken_script.sh",
        "Fix: add 'do' after the for loop line",
        "Use `set -e` to stop on error and `set -x` to trace."
    };
    const char *lab3_wisdom = "Debugging isn't fixing bugs—it's understanding why your assumptions failed.";

    display_lab("Advanced Script Debugging", "Identify and fix bugs using bash debugging tools.", lab3_wisdom, lab3_steps, 9);

    Question questions[] = {
        {
            "Which tool can help trace the exact flow of a bash script?",
            {"cron", "awk", "set -x", "bashrc"},
            "set -x"
        },
        {
            "Which command creates a new directory?",
            {"mkdir", "touch", "nano", "cp"},
            "mkdir"
        },
        {
            "What does `set -e` do in a bash script?",
            {"Enable verbose output", "Exit on any error", "Execute script silently", "Loop infinitely"},
            "Exit on any error"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nMini Quiz - Test Your Admin Script Skills:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR GREEN_COLOR "\n✅ Dinner Complete!\n" RESET_COLOR);
    printf(CYAN_COLOR "You're now able to write, schedule, and debug serious admin-level shell scripts.\n" RESET_COLOR);
    pause_continue();

    return 0;
}