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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 15 Lunch: Securing Network Configurations!\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {"Firewall Basics (iptables/nftables)", "Introduction to firewall management and configuring simple rules.", "sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT",
         "Firewalls control network traffic by allowing or blocking specific connections based on predefined rules. The `iptables` command is used for packet filtering in Linux, while `nftables` is its modern successor.\n\nTo list firewall rules, use `sudo iptables -L`. To allow SSH traffic, use `sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT`. To drop all incoming traffic except for essential services, use `sudo iptables -P INPUT DROP`.\n\nFor persistent rules, install `iptables-persistent` and save the configuration using `sudo netfilter-persistent save`.",
         {"https://www.digitalocean.com/community/tutorials/iptables-essentials-common-firewall-rules-and-commands", "https://wiki.archlinux.org/title/nftables", "https://www.cyberciti.biz/faq/linux-iptables-how-to-block-an-ip-address/", NULL, NULL}},
        {"SSH Hardening", "Best practices for hardening SSH, including key-based authentication, restricting users, and using fail2ban.", "sudo nano /etc/ssh/sshd_config",
         "To secure SSH, disable root login (`PermitRootLogin no`), enforce key-based authentication (`PasswordAuthentication no`), and allow only specific users (`AllowUsers user1 user2`).\n\nUsing `fail2ban` helps mitigate brute-force attacks. Install it using `sudo apt install fail2ban`, then configure `/etc/fail2ban/jail.local` to monitor failed login attempts and ban offending IPs.\n\nFor additional security, change the default SSH port (`Port 2222`) and use TCP Wrappers (`/etc/hosts.allow` and `/etc/hosts.deny`).",
         {"https://www.ssh.com/academy/ssh/hardening", "https://linuxhandbook.com/secure-ssh-server/", "https://www.fail2ban.org/wiki/index.php/Main_Page", NULL, NULL}},
    };

    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Quiz
    Question questions[] = {
        {"Which command is used to list iptables rules?", {"iptables -L", "iptables --show", "firewall-cmd --list", "nft show ruleset"}, "iptables -L"},
        {"How do you disable root SSH login?", {"PermitRootLogin no", "RootAccess off", "DisableRoot true", "SSHRootDeny yes"}, "PermitRootLogin no"},
        {"What tool helps prevent brute-force SSH attacks?", {"fail2ban", "iptables", "nftables", "ufw"}, "fail2ban"}
    };

    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}
