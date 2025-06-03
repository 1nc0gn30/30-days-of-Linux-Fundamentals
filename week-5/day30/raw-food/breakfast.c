// === Day 30 - Breakfast: System Optimization & Automation Recap ===
// Mode: Interactive C Training

#include <stdio.h>
#include <string.h>

// Score tracker
int score = 0;

void pause() {
    printf("\n(Press Enter to continue...)\n");
    getchar();
}

// ============================
// SECTION: Automation Tools
// ============================
void automation_section() {
    printf("\n--- Automation Tools Review ---\n");
    printf("1. Ansible: Uses YAML to configure multiple systems simultaneously via SSH.\n");
    printf("2. Puppet: Manages system state with manifests and a central server.\n");
    printf("3. Cron: Runs scheduled tasks using time-based rules from crontab.\n");

    pause();

    printf("\nQuiz: Which tool uses 'playbooks' in YAML format?\n");
    printf("A. Puppet\nB. Cron\nC. Ansible\n> ");
    char answer;
    scanf(" %c", &answer);
    getchar(); // Consume newline

    if (answer == 'C' || answer == 'c') {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Nope! The answer is Ansible.\n");
    }
}

// ============================
// SECTION: Performance Tuning
// ============================
void performance_section() {
    printf("\n--- Performance Tuning Recap ---\n");
    printf("Key Tools:\n");
    printf("- top, htop: Monitor CPU and memory usage.\n");
    printf("- vmstat: View system performance statistics.\n");
    printf("- iotop, iostat: Analyze disk I/O.\n");

    pause();

    printf("\nQuiz: Which command shows real-time CPU & RAM usage in an interactive way?\n");
    printf("A. vmstat\nB. htop\nC. iostat\n> ");
    char answer;
    scanf(" %c", &answer);
    getchar();

    if (answer == 'B' || answer == 'b') {
        printf("✅ That's right!\n");
        score++;
    } else {
        printf("❌ Incorrect. The answer is htop.\n");
    }
}

// ============================
// SECTION: System Hardening
// ============================
void hardening_section() {
    printf("\n--- System Hardening Concepts ---\n");
    printf("- Disable root SSH login.\n");
    printf("- Use key-based SSH authentication.\n");
    printf("- Enable and configure firewalls (iptables, ufw).\n");
    printf("- Remove unused packages and services.\n");

    pause();

    printf("\nQuiz: Which of these increases SSH security?\n");
    printf("A. Allow root login\nB. Use password auth\nC. Use key-based auth\n> ");
    char answer;
    scanf(" %c", &answer);
    getchar();

    if (answer == 'C' || answer == 'c') {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Nope. It's key-based authentication.\n");
    }
}

// ============================
// MAIN
// ============================
int main() {
    printf("=== Day 30 - Breakfast Recap ===\n");
    automation_section();
    performance_section();
    hardening_section();

    printf("\n🎯 Final Score: %d/3\n", score);
    printf("Thanks for reviewing Week 4 concepts. Ready for lunch next?\n");

    return 0;
}
