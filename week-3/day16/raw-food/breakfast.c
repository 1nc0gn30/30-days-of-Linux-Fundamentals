#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    // Clear screen and header
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 16 - Breakfast: Introduction to Auditing\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Breakfast...\n" RESET_COLOR);
    getchar();
    
    // Breakfast Lessons
    Lesson lessons[] = {
        {
            "Auditd and Linux Audit Framework",
            "Understanding the basics of Linux auditing and tracking events.",
            "sudo systemctl start auditd",
            "This lesson introduces auditd—the Linux auditing daemon—and explains how it monitors system events and user activities.",
            {"https://linux.die.net/man/8/auditd", "https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/security_guide/sec-auditing", NULL, NULL, NULL}
        },
        {
            "System Logs and Log Management",
            "Overview of system log files and effective log management.",
            "cat /var/log/syslog",
            "Learn how to view and interpret system logs to monitor system health and diagnose issues.",
            {"https://www.digitalocean.com/community/tutorials/how-to-read-log-files", NULL, NULL, NULL, NULL}
        },
        {
            "Analyzing Logs with logwatch",
            "Using logwatch to parse logs and identify unusual activity.",
            "logwatch --detail high",
            "Logwatch compiles comprehensive reports from your logs, helping you spot anomalies and security events.",
            {"https://sourceforge.net/projects/logwatch/", NULL, NULL, NULL, NULL}
        },
        {
            "Understanding Audit Rules",
            "Configure audit rules to monitor specific system events.",
            "auditctl -a always,exit -F arch=b64 -S open",
            "Setting audit rules allows you to track file accesses and system calls, reinforcing your security posture.",
            {"https://www.tecmint.com/auditctl-command-examples/", NULL, NULL, NULL, NULL}
        },
        {
            "Configuring Auditd for File Integrity",
            "Monitor critical file changes with auditd.",
            "auditctl -w /etc/passwd -p wa",
            "File integrity monitoring helps detect unauthorized modifications, protecting key system files.",
            {"https://www.cyberciti.biz/faq/linux-auditd-monitoring-file-changes/", NULL, NULL, NULL, NULL}
        },
        {
            "Monitoring User Activity with Auditd",
            "Track logins and commands executed by users.",
            "ausearch -ua username",
            "This lesson shows how to use auditd to review user activities, which can help uncover insider threats.",
            {"https://www.thegeekdiary.com/using-auditd-to-track-user-activity-in-linux/", NULL, NULL, NULL, NULL}
        },
        {
            "Centralized Logging Solutions",
            "Aggregate logs from multiple systems using syslog-ng or rsyslog.",
            "sudo service rsyslog restart",
            "Centralized logging simplifies the management and analysis of logs across many systems.",
            {"https://www.rsyslog.com/", NULL, NULL, NULL, NULL}
        },
        {
            "Parsing Logs with grep and awk",
            "Filter log files to find specific patterns or errors.",
            "grep 'error' /var/log/syslog",
            "Using grep and awk helps quickly pinpoint issues or suspicious patterns in large log files.",
            {"https://www.gnu.org/software/grep/", NULL, NULL, NULL, NULL}
        },
        {
            "Securing Log Files",
            "Ensure log files have proper permissions to prevent tampering.",
            "chmod 600 /var/log/auth.log",
            "Restricting access to log files protects audit data from unauthorized changes or deletion.",
            {"https://www.cyberciti.biz/faq/linux-secure-log-files/", NULL, NULL, NULL, NULL}
        },
        {
            "Advanced Log Management Techniques",
            "Automate log rotation and archival to keep logs organized.",
            "sudo logrotate /etc/logrotate.conf",
            "Advanced log management techniques help manage disk space and ensure historical logs are preserved.",
            {"https://www.logrotate.org/", NULL, NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }
    
    // Breakfast Questions
    Question questions[] = {
        {
            "Which command starts the audit daemon?",
            {"sudo systemctl start auditd", "sudo service auditd stop", "auditctl -s", "systemctl status auditd"},
            "sudo systemctl start auditd"
        },
        {
            "What file is typically used to view system logs?",
            {"/var/log/syslog", "/etc/auditd.conf", "/var/audit/log", "/usr/logs/system"},
            "/var/log/syslog"
        },
        {
            "Which tool generates comprehensive log reports?",
            {"logwatch", "grep", "awk", "sed"},
            "logwatch"
        },
        {
            "What command adds a watch on /etc/passwd for changes?",
            {"auditctl -w /etc/passwd -p wa", "ausearch -w /etc/passwd", "auditd /etc/passwd", "chmod 600 /etc/passwd"},
            "auditctl -w /etc/passwd -p wa"
        },
        {
            "Which command searches audit logs for a specific user?",
            {"ausearch -ua username", "auditctl -ua username", "grep username /var/log/audit.log", "cat /etc/audit/users"},
            "ausearch -ua username"
        },
        {
            "What service is restarted to apply centralized logging changes?",
            {"rsyslog", "auditd", "logwatch", "syslog-ng"},
            "rsyslog"
        },
        {
            "Which command filters logs for the keyword 'error'?",
            {"grep 'error' /var/log/syslog", "awk '/error/' /var/log/syslog", "logwatch --error", "sed -n '/error/p' /var/log/syslog"},
            "grep 'error' /var/log/syslog"
        },
        {
            "What permission is recommended for securing log files?",
            {"600", "644", "777", "400"},
            "600"
        },
        {
            "Which utility automates log rotation?",
            {"logrotate", "cron", "rsyslog", "systemd"},
            "logrotate"
        },
        {
            "What is the primary purpose of auditctl?",
            {"To configure audit rules", "To analyze logs", "To rotate logs", "To monitor user sessions"},
            "To configure audit rules"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your auditing knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
