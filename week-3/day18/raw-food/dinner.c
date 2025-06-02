#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

void pause_continue() {
    printf(YELLOW_COLOR "\nPress Enter to continue...\n" RESET_COLOR);
    getchar();
}

void lab_intro(const char *title, const char *objective, const char *task_summary) {
    printf(BOLD_COLOR BLUE_COLOR "\n[Lab: %s]\n" RESET_COLOR, title);
    printf(CYAN_COLOR "Objective: %s\n" RESET_COLOR, objective);
    printf(YELLOW_COLOR "Task Summary:\n" RESET_COLOR "%s\n", task_summary);
    pause_continue();
}

void lab_tip(const char *tip) {
    printf(GREEN_COLOR "💡 Tip: %s\n" RESET_COLOR, tip);
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 18 - Dinner: Disaster Recovery Planning\n" RESET_COLOR);
    printf(YELLOW_COLOR "Let’s begin the lab tasks...\n" RESET_COLOR);
    pause_continue();

    // Lab 1: Create Local Backups
    lab_intro(
        "Create Local Backups",
        "Use `tar` and `rsync` to perform local backups of important directories.",
        "1. Create a compressed backup of /etc using tar.\n"
        "2. Use rsync to mirror /home/user to /mnt/backup."
    );
    lab_tip("tar -czvf etc_backup.tar.gz /etc");
    lab_tip("rsync -av /home/user/ /mnt/backup/");

    // Lab 2: Automate with Cron
    lab_intro(
        "Automate Backups with Cron",
        "Set up cron jobs to run backup scripts automatically on a schedule.",
        "1. Create a shell script named `daily_backup.sh` that uses tar and rsync.\n"
        "2. Add a cron job to run the script every day at 1AM."
    );
    lab_tip("crontab -e → 0 1 * * * /home/user/scripts/daily_backup.sh");
    lab_tip("Make sure the script has executable permissions: chmod +x daily_backup.sh");

    // Lab 3: Test Restoration
    lab_intro(
        "Testing Restoration",
        "Ensure you can successfully restore data from your backups.",
        "1. Extract the tar archive of /etc to /tmp/etc_restore.\n"
        "2. Compare restored files with the originals.\n"
        "3. Try copying a file from the rsync backup back to /home/user."
    );
    lab_tip("mkdir /tmp/etc_restore && tar -xzvf etc_backup.tar.gz -C /tmp/etc_restore");
    lab_tip("diff -r /etc /tmp/etc_restore or use meld for visual comparison");

    printf(BOLD_COLOR GREEN_COLOR "\n🎯 Disaster Recovery Dinner Completed!\n" RESET_COLOR);
    printf(CYAN_COLOR "You now have hands-on experience creating, automating, and restoring backups.\n" RESET_COLOR);
    pause_continue();

    return 0;
}
