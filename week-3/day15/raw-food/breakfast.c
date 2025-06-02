#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

// Lesson structure
typedef struct {
    const char *topic;
    const char *description;
    const char *command_example;
    const char *detailed_explanation;
    const char *resources[MAX_RESOURCES];
} Lesson;

// Question structure
typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Example Command:\n" RESET_COLOR);
    printf(GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Detailed Explanation:\n" RESET_COLOR);
    printf("%s\n", lesson->detailed_explanation);
    
    printf(YELLOW_COLOR "Additional Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && lesson->resources[i] != NULL; i++) {
        printf("- %s\n", lesson->resources[i]);
    }
    printf(YELLOW_COLOR "Press Enter to continue...\n" RESET_COLOR);
    getchar();
    printf("\n");
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];
    printf(BOLD_COLOR GREEN_COLOR "Question: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }
    printf("Your answer (A, B, C, or D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') {
        user_answer[0] -= 32;
    }

    int answer_index = -1;
    if (user_answer[0] >= 'A' && user_answer[0] <= 'D') {
        answer_index = user_answer[0] - 'A';
    }

    if (answer_index >= 0 && answer_index < 4 && strcmp(question->choices[answer_index], question->correct_answer) == 0) {
        printf(GREEN_COLOR "Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %s\n" RESET_COLOR, question->correct_answer);
    }
    printf("\n");
}

int main() {
    printf("\033[H\033[J"); // Clear screen
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 15 Breakfast: Security Essentials!\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {"Linux Security Basics", "Understanding the fundamental security mechanisms of Linux.", "man security",
         "Linux security is enforced through user roles, permissions, and mandatory access controls. It ensures integrity, confidentiality, and availability of system resources. Tools like `auditd` allow monitoring of security events, and SELinux or AppArmor add additional layers of access control.",
         {"https://linuxsecurity.com", "https://www.cyberciti.biz", "https://www.linuxfoundation.org", "https://access.redhat.com", "https://www.nsa.gov/cybersecurity/"}},
        {"File Permissions & Ownership", "Managing file permissions effectively to limit unauthorized access.", "chmod 750 filename",
         "Linux files are protected using permission bits (rwx for owner, group, and others). The `chmod` command is used to modify access rights, `chown` changes ownership, and `umask` sets default permissions.",
         {"https://linuxize.com/post/linux-file-permissions", "https://www.cyberciti.biz/tips/understanding-linux-file-permissions.html", NULL, NULL, NULL}},
        {"Firewall Basics (iptables/nftables)", "Setting up firewalls to manage inbound and outbound traffic.", "sudo iptables -L",
         "Firewalls restrict access by filtering packets based on rules. `iptables` provides manual rule configuration, while `nftables` is a modern alternative with better performance and flexibility.",
         {"https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands", "https://wiki.archlinux.org/title/iptables", NULL, NULL, NULL}},
        {"SSH Hardening", "Techniques to improve SSH security and prevent unauthorized access.", "sudo nano /etc/ssh/sshd_config",
         "To secure SSH, disable password-based login in favor of key authentication, restrict root login, change the default port, and use `fail2ban` to block repeated failed login attempts.",
         {"https://www.ssh.com/academy/ssh/hardening", "https://linuxhandbook.com/secure-ssh-server/", NULL, NULL, NULL}}
    };

    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Questions
    Question questions[] = {
        {"Which command modifies file permissions?", {"chmod", "chown", "ls", "rm"}, "chmod"},
        {"How do you change file ownership?", {"chown", "chmod", "passwd", "touch"}, "chown"},
        {"What is the purpose of a firewall?", {"Block unauthorized access", "Monitor disk usage", "Change file permissions", "Optimize memory usage"}, "Block unauthorized access"}
    };

    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}
