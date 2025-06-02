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

#define MAX_RESOURCES 5

typedef struct {
    const char *title;
    const char *description;
    const char *command;
    const char *explanation;
    const char *resources[MAX_RESOURCES];
} Challenge;

void display_challenge(const Challenge *c) {
    printf(BOLD_COLOR CYAN_COLOR "\nChallenge: %s\n" RESET_COLOR, c->title);
    printf(YELLOW_COLOR "%s\n" RESET_COLOR, c->description);
    printf(GREEN_COLOR "\nCommand Example:\n%s\n" RESET_COLOR, c->command);
    printf(BLUE_COLOR "\nExplanation:\n%s\n" RESET_COLOR, c->explanation);
    printf(YELLOW_COLOR "\nHelpful Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && c->resources[i] != NULL; i++) {
        printf("- %s\n", c->resources[i]);
    }
    printf("\nPress Enter to continue...\n");
    getchar(); getchar();
}

int main() {
    Challenge challenges[] = {
        {
            "Disk Monitor + Email Alert",
            "Simulate a disk usage check and send an alert if usage exceeds threshold.",
            "THRESHOLD=85\nUSAGE=$(df / | awk 'NR==2 {print $5}' | sed 's/%//')\nif [ $USAGE -gt $THRESHOLD ]; then\n  echo \"Disk space at $USAGE%!\" | mail -s \"Disk Alert\" admin@localhost\nfi",
            "This script helps you automate monitoring of disk space and alerts the system administrator if a critical threshold is exceeded.",
            {"https://linuxize.com/post/how-to-check-disk-usage-in-linux/", NULL}
        },
        {
            "Automated Backup Script",
            "Create scheduled backups and remove backups older than 7 days.",
            "DATE=$(date +%F)\nBACKUP_FILE=\"/backups/etc-$DATE.tar.gz\"\ntar -czf \"$BACKUP_FILE\" /etc\nfind /backups -name \"etc-*.tar.gz\" -mtime +7 -delete",
            "The script backs up /etc into a timestamped tarball and cleans up backups older than 7 days.",
            {"https://www.tecmint.com/backup-linux-files-using-tar/", NULL}
        },
        {
            "Script Debugging Techniques",
            "Learn how to identify and fix common Bash script issues.",
            "bash -x script.sh\nset -e\nset -u",
            "Use 'bash -x' to trace command execution, 'set -e' to stop on errors, and 'set -u' to catch unset variables.",
            {"https://linuxize.com/post/how-to-debug-bash-scripts/", NULL}
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Day 23 - Dinner: Script Lab Challenges\n" RESET_COLOR);

    for (int i = 0; i < sizeof(challenges)/sizeof(Challenge); i++) {
        display_challenge(&challenges[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "All challenges complete. Take a break or script more magic!\n" RESET_COLOR);
    return 0;
}