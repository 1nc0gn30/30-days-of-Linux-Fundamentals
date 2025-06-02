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
    printf("DATE=$(date +%%F)\n");
    printf("BACKUP_FILE=\"/backups/etc-$DATE.tar.gz\"\n");
    printf("tar -czf \"$BACKUP_FILE\" /etc\n");
    printf("find /backups -name \"etc-*.tar.gz\" -mtime +7 -delete\n");
    printf("Creates a backup and deletes old backups.\n");
}

void debug_script_example() {
    printf("\n🧠 Task 3: Debugging a Script\n");
    printf("-------------------------------------\n");
    printf("Use these debugging techniques:\n");
    printf("- bash -x script.sh\n");
    printf("- set -e to exit on error\n");
    printf("- set -u to error on unset vars\n");
    printf("- Check for quotes, if conditions, unexpected behavior\n");
}

void log_cleanup_script() {
    printf("\n🧹 Automating Log Cleanup\n");
    printf("---------------------------\n");
    printf("Script:\nfind /var/log -type f -name '*.log' -mtime +7 -exec rm {} \\;\\n");
    printf("Effectively removes logs older than 7 days.\n");
}

void disk_monitor_script() {
    printf("\n💾 Disk Space Monitor\n");
    printf("---------------------------\n");
    printf("Script:\nusage=$(df -h / | awk 'NR==2 {print $5}' | sed 's/%%//')\nif [ $usage -gt 80 ]; then echo \"Warning: $usage%% used.\"; fi\n");
    printf("Alerts user if root partition exceeds 80%%.\n");
}

void getopts_example() {
    printf("\n🎛️ Handling Options with getopts\n");
    printf("---------------------------\n");
    printf("Script snippet:\nwhile getopts \"u:p:\" opt; do\n case $opt in\n  u) user=$OPTARG ;;\n  p) path=$OPTARG ;;\n  *) echo 'Invalid option' ;;\n esac\ndone\n");
    printf("Use: ./script.sh -u neal -p /home\n");
}

void debug_script() {
    printf("\n🔧 Debugging Shell Scripts\n");
    printf("---------------------------\n");
    printf("Commands:\nbash -x script.sh   # Trace execution\nset -e               # Exit on error\nset -x               # Show commands inline\n");
}

void show_lunch_menu() {
    printf("\n====================================\n");
    printf(" Day 23: Lunch - Useful Bash Scripts\n");
    printf("====================================\n");
    printf("1. Automate Log Cleanup\n");
    printf("2. Monitor Disk Usage\n");
    printf("3. getopts Example\n");
    printf("4. Debugging Techniques\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        show_lunch_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_cleanup_script();
                break;
            case 2:
                disk_monitor_script();
                break;
            case 3:
                getopts_example();
                break;
            case 4:
                debug_script();
                break;
            case 5:
                printf("Exiting... Try automating your own task!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
