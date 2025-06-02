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

void display_lab(const char *title, const char *objective, const char *steps[], int step_count) {
    printf(BOLD_COLOR BLUE_COLOR "\n[Lab: %s]\n" RESET_COLOR, title);
    printf(CYAN_COLOR "Objective: %s\n" RESET_COLOR, objective);
    printf(YELLOW_COLOR "Steps:\n" RESET_COLOR);
    for (int i = 0; i < step_count; i++) {
        printf("- %s\n", steps[i]);
    }
    pause_continue();
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 19 - Dinner: Practical Performance Tuning\n" RESET_COLOR);
    printf(YELLOW_COLOR "Now it’s time to put your performance insights into action.\n" RESET_COLOR);
    pause_continue();

    // Lab 1: Monitor System Load
    const char *lab1_steps[] = {
        "Open terminal 1: Run `htop` to watch CPU and memory usage in real time.",
        "Open terminal 2: Run `vmstat 1` to observe system metrics per second.",
        "Stress the system: Run `yes > /dev/null &` multiple times to simulate load.",
        "Watch how CPU and memory respond under stress."
    };
    display_lab("Monitor System Load", "Use real-time tools to monitor CPU, memory, and I/O under simulated stress.", lab1_steps, 4);

    // Lab 2: Tune Services for Performance
    const char *lab2_steps[] = {
        "List active services: `systemctl list-units --type=service`",
        "Identify unneeded ones (e.g., `bluetooth`, `cups`, `avahi-daemon`).",
        "Disable one: `sudo systemctl disable bluetooth`",
        "Optionally, stop running ones with: `sudo systemctl stop bluetooth`",
        "Review changes with `top` or `htop` to check load impact."
    };
    display_lab("Tune Services for Performance", "Disable unused services to free resources and speed up system boot.", lab2_steps, 5);

    // Lab 3: Disk I/O Analysis and Optimization
    const char *lab3_steps[] = {
        "Run `iostat -xz 2` to monitor per-disk I/O every 2 seconds.",
        "Write a file: `dd if=/dev/zero of=testfile bs=1M count=1000`",
        "Check performance again with `iostat` or `iotop`.",
        "Tune `vm.dirty_ratio` and `vm.dirty_background_ratio` for I/O responsiveness:",
        "    `sudo sysctl vm.dirty_ratio=10`",
        "    `sudo sysctl vm.dirty_background_ratio=5`"
    };
    display_lab("Disk I/O Analysis and Optimization", "Practice evaluating and tuning disk write performance and kernel buffers.", lab3_steps, 6);

    printf(BOLD_COLOR GREEN_COLOR "\n🎯 Dinner Complete!\n" RESET_COLOR);
    printf(CYAN_COLOR "You’ve now tested your system under stress and tuned it to breathe better.\n" RESET_COLOR);
    pause_continue();

    return 0;
}
