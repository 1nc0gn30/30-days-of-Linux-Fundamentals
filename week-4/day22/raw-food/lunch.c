#include <stdio.h>
#include <stdlib.h>

void optimize_cpu() {
    printf("\n🔧 Optimizing CPU Usage:\n");
    printf("- Check which processes consume the most CPU.\n");
    printf("- Consider renicing or killing high-CPU processes.\n");
    system("ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head");
}

void optimize_memory() {
    printf("\n🧠 Optimizing Memory Usage:\n");
    printf("- Identify memory-heavy apps.\n");
    printf("- Consider restarting memory leaks or upgrading RAM.\n");
    system("free -h");
}

void manage_services() {
    printf("\n⚙️ Managing systemd services:\n");
    printf("- Disable unnecessary services to reduce resource usage.\n");
    printf("- Example: sudo systemctl disable bluetooth\n");
    system("systemctl list-units --type=service --state=running");
}

void swap_cache_info() {
    printf("\n💾 Swap and Cache Info:\n");
    printf("- Use swappiness to control swap aggressiveness.\n");
    printf("- View swap activity and cache usage.\n");
    system("cat /proc/meminfo | grep -E 'swap|cached'");
    system("sysctl vm.swappiness");
}

int main() {
    int choice;

    while (1) {
        printf("\n========================================\n");
        printf(" Day 22 Lunch: Performance Optimization\n");
        printf("========================================\n");
        printf("1. Optimize CPU Usage\n");
        printf("2. Optimize Memory Usage\n");
        printf("3. Manage Services (systemd)\n");
        printf("4. View Swap and Cache Settings\n");
        printf("5. Exit\n");
        printf("Select an option: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                optimize_cpu();
                break;
            case 2:
                optimize_memory();
                break;
            case 3:
                manage_services();
                break;
            case 4:
                swap_cache_info();
                break;
            case 5:
                printf("Exiting optimization guide.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
