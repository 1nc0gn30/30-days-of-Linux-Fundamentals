#include <stdio.h>
#include <stdlib.h>

void monitor_system_load() {
    printf("\n📈 Monitoring System Load:\n");
    printf("- Launching vmstat and htop for load observation...\n\n");
    system("vmstat 1 5");
    printf("\n[htop] Press 'q' to exit.\n\n");
    system("htop");
}

void tune_services() {
    printf("\n⚙️ Tuning Services for Performance:\n");
    printf("- Listing all enabled services. Disable non-essentials.\n\n");
    system("systemctl list-unit-files --type=service | grep enabled");
    printf("\nExample to disable: sudo systemctl disable bluetooth.service\n");
}

void analyze_disk_io() {
    printf("\n💾 Disk I/O Analysis and Tuning:\n");
    printf("- Running iostat for block device usage.\n\n");
    system("iostat -xz 1 3");
    printf("\nIf \"%util\" is consistently near 100%%, consider: \
 - Upgrading disk\n - Using faster I/O schedulers\n - Load balancing across devices\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n============================================\n");
        printf(" Day 22 Dinner: Practical Performance Tuning\n");
        printf("============================================\n");
        printf("1. Monitor System Load (vmstat + htop)\n");
        printf("2. Tune systemd Services\n");
        printf("3. Analyze and Optimize Disk I/O\n");
        printf("4. Exit\n");
        printf("Choose a task: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                monitor_system_load();
                break;
            case 2:
                tune_services();
                break;
            case 3:
                analyze_disk_io();
                break;
            case 4:
                printf("Exiting Day 22 tuning session.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
