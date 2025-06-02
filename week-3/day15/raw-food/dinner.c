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
    // Clear screen
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Dinner: Practical Security Tools\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons array (10 lessons)
    Lesson lessons[] = {
        {
            "Configuring a Basic Firewall",
            "Set up and test basic iptables or nftables rules to manage incoming/outgoing traffic.",
            "sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT",
            "This lesson covers the basics of firewall configuration. Learn how to allow specific traffic (e.g., HTTP on port 80) while blocking unwanted connections. Both iptables and nftables can be used to control network traffic.",
            {"https://www.digitalocean.com/community/tutorials/iptables-essentials", "https://wiki.archlinux.org/title/nftables", NULL, NULL, NULL}
        },
        {
            "Advanced Firewall Techniques",
            "Implement advanced rules including logging and port forwarding to enhance firewall capabilities.",
            "sudo iptables -A INPUT -p tcp --dport 443 -j LOG --log-prefix 'HTTPS: '",
            "This lesson explains how to set up advanced firewall rules. Logging can help you monitor traffic and troubleshoot issues while port forwarding directs traffic from one port to another.",
            {"https://www.cyberciti.biz/faq/iptables-logging-guide/", "https://www.digitalocean.com/community/tutorials/iptables-port-forwarding", NULL, NULL, NULL}
        },
        {
            "Implementing User Permissions",
            "Learn how to enforce least privilege by managing user permissions effectively.",
            "sudo usermod -aG sudo username",
            "In this lesson, you will learn how to assign users to groups, limiting their access rights and enforcing the principle of least privilege, which is vital for system security.",
            {"https://www.cyberciti.biz/tips/linux-unix-bsd-users-and-groups.html", NULL, NULL, NULL, NULL}
        },
        {
            "Configuring Sudoers",
            "Configure the sudoers file to specify which users can run specific commands with elevated privileges.",
            "sudo visudo",
            "This lesson discusses the configuration of the sudoers file. Proper configuration ensures that only authorized users can execute critical commands, thereby minimizing security risks.",
            {"https://www.sudo.ws/man/1.8.13/sudoers.man.html", NULL, NULL, NULL, NULL}
        },
        {
            "SELinux Fundamentals",
            "Understand SELinux policies and modes to enforce application-level security.",
            "sestatus",
            "This lesson provides an introduction to SELinux. You will learn about its different modes (enforcing, permissive, disabled) and how to interpret the status output to secure your applications.",
            {"https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/", NULL, NULL, NULL, NULL}
        },
        {
            "AppArmor Basics",
            "An overview of AppArmor for managing application-specific security policies.",
            "sudo aa-status",
            "Learn how AppArmor profiles restrict application behavior. This lesson covers profile enforcement, troubleshooting, and best practices for maintaining a secure system.",
            {"https://www.digitalocean.com/community/tutorials/how-to-use-apparmor-to-restrict-programs-on-ubuntu-16-04", NULL, NULL, NULL, NULL}
        },
        {
            "Fail2Ban Configuration",
            "Prevent brute-force attacks by configuring Fail2Ban to monitor and ban suspicious IP addresses.",
            "sudo systemctl start fail2ban",
            "This lesson walks through setting up Fail2Ban. By monitoring log files for repeated failed login attempts, Fail2Ban automatically bans offending IP addresses.",
            {"https://www.fail2ban.org/wiki/index.php/Main_Page", "https://www.digitalocean.com/community/tutorials/how-to-protect-ssh-with-fail2ban", NULL, NULL, NULL}
        },
        {
            "Intrusion Detection with Snort",
            "Set up Snort to monitor network traffic and detect potential intrusions.",
            "sudo snort -A console -q -c /etc/snort/snort.conf -i eth0",
            "This lesson introduces Snort, a powerful intrusion detection system. You will learn how to install and configure Snort to alert you to suspicious network activities.",
            {"https://www.snort.org/documents", NULL, NULL, NULL, NULL}
        },
        {
            "VPN Setup and Security",
            "Configure a VPN to secure remote connections and protect data in transit.",
            "sudo openvpn --config client.ovpn",
            "In this lesson, you'll learn how to set up a VPN using OpenVPN. VPNs encrypt data traffic and provide a secure tunnel for remote access.",
            {"https://openvpn.net/community-resources/how-to/", NULL, NULL, NULL, NULL}
        },
        {
            "Log Analysis and Security Auditing",
            "Use log analysis tools to audit system security and detect anomalies.",
            "sudo logwatch --detail high",
            "This lesson covers the basics of security auditing through log analysis. Tools like Logwatch help administrators monitor system logs and identify potential security threats.",
            {"https://www.logwatch.net/", "https://www.digitalocean.com/community/tutorials/how-to-analyze-log-files-on-ubuntu-20-04", NULL, NULL, NULL}
        }
    };

    // Display lessons
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }

    // Questions array (10 questions)
    Question questions[] = {
        {
            "Which command is used to add a basic firewall rule using iptables?",
            {"iptables -A INPUT -p tcp --dport 80 -j ACCEPT", "iptables --add", "firewall-cmd --zone=public --add-port=80/tcp", "nft add rule ip filter input tcp dport 80 accept"},
            "iptables -A INPUT -p tcp --dport 80 -j ACCEPT"
        },
        {
            "What is the purpose of logging in firewall rules?",
            {"To drop packets", "To record network traffic events", "To forward traffic", "To encrypt data"},
            "To record network traffic events"
        },
        {
            "Which command is used to modify user permissions by adding a user to the sudo group?",
            {"sudo adduser username sudo", "sudo usermod -aG sudo username", "chmod +x username", "usermod --sudo username"},
            "sudo usermod -aG sudo username"
        },
        {
            "What is the main purpose of configuring the sudoers file?",
            {"To allow root login", "To define which users can run specific commands with elevated privileges", "To create new user accounts", "To disable all system logging"},
            "To define which users can run specific commands with elevated privileges"
        },
        {
            "Which command checks the status of SELinux?",
            {"sestatus", "selinux-status", "getenforce", "status selinux"},
            "sestatus"
        },
        {
            "How can you check the status of AppArmor profiles?",
            {"sudo aa-status", "apparmor-check", "sudo apparmor --status", "aa-check-status"},
            "sudo aa-status"
        },
        {
            "Which tool is used to ban IPs after multiple failed login attempts?",
            {"fail2ban", "iptables", "ufw", "nftables"},
            "fail2ban"
        },
        {
            "What is Snort primarily used for?",
            {"User authentication", "Network intrusion detection", "VPN configuration", "Log analysis"},
            "Network intrusion detection"
        },
        {
            "Which command initiates an OpenVPN connection?",
            {"sudo openvpn --config client.ovpn", "openvpn --start", "vpn-connect", "sudo vpnclient connect"},
            "sudo openvpn --config client.ovpn"
        },
        {
            "Which tool is used for detailed log analysis to audit system security?",
            {"logwatch", "fail2ban", "snort", "iptables"},
            "logwatch"
        }
    };

    // Display questions
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }

    return 0;
}
