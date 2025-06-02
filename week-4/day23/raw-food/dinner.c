#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monitor_disk_space() {
    printf("\n🧠 Task 1: Disk Usage Alert Simulation\n");
    printf("-------------------------------------\n");
    printf("THRESHOLD=85\n");
    printf("USAGE=$(df / | awk 'NR==2 {print $5}' | sed 's/%%//')\n");
    printf("if [ $USAGE -gt $THRESHOLD ]; then\n  echo \"Disk space at $USAGE%%!\" | mail -s \"Disk Alert\" admin@localhost\nfi\n");
}

void automate_backup() {
    printf("\n🧠 Task 2: Backup Automation Example\n");
    printf("-------------------------------------\n");
    printf("DATE=$(date +%%F)\nBACKUP_FILE=\"/backups/etc-$DATE.tar.gz\"\ntar -czf \"$BACKUP_FILE\" /etc\nfind /backups -name \"etc-*.tar.gz\" -mtime +7 -delete\n");
    printf("Creates a backup and deletes old backups.\n");
}

void debug_script_example() {
    printf("\n🧠 Task 3: Debugging a Script\n");
    printf("-------------------------------------\n");
    printf("Use these debugging techniques:\n");
    printf("- bash -x script.sh\n- set -e to exit on error\n- set -u to error on unset vars\n- Check for quotes, if conditions, unexpected behavior\n");
}

void show_dinner_menu() {
    printf("\n==========================================\n");
    printf(" Day 23: Dinner - Script Lab Challenges\n");
    printf("==========================================\n");
    printf("1. Disk Monitor + Email Alert\n");
    printf("2. Automated Backup Script\n");
    printf("3. Script Debugging Practice\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        show_dinner_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                monitor_disk_space();
                break;
            case 2:
                automate_backup();
                break;
            case 3:
                debug_script_example();
                break;
            case 4:
                printf("Good work! You're mastering Linux scripting.\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
