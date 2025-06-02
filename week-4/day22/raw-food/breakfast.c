#include <stdio.h>
#include <stdlib.h>

void run_vmstat() {
    printf("\n[vmstat] Real-time Virtual Memory Statistics:\n");
    system("vmstat 1 3");
}

void run_top() {
    printf("\n[top] Process and System Load View:\n");
    printf("Launching top for 5 seconds... Press 'q' to quit manually.\n\n");
    system("top -n 1");
}

void run_htop() {
    printf("\n[htop] (If installed) Interactive System Monitor:\n");
    printf("Tip: Use arrows to navigate, F6 to sort, F9 to kill processes.\n\n");
    system("htop");
}

void run_iostat() {
    printf("\n[iostat] Disk I/O Statistics:\n");
    printf("\nEnsure sysstat is installed. Example: sudo apt install sysstat\n\n");
    system("iostat -xz 1 3");
}

int main() {
    int choice;

    while (1) {
        printf("\n========================================\n");
        printf(" Day 22 Breakfast: Performance Metrics\n");
        printf("========================================\n");
        printf("1. Check Virtual Memory (vmstat)\n");
        printf("2. View Processes and Load (top)\n");
        printf("3. Interactive Monitor (htop)\n");
        printf("4. Disk I/O Stats (iostat)\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                run_vmstat();
                break;
            case 2:
                run_top();
                break;
            case 3:
                run_htop();
                break;
            case 4:
                run_iostat();
                break;
            case 5:
                printf("Exiting performance metrics viewer.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
