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
    printf(BOLD_COLOR CYAN_COLOR "Day 16 - Dinner: Practical Security Assessments\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Dinner...\n" RESET_COLOR);
    getchar();
    
    // Dinner Lessons
    Lesson lessons[] = {
        {
            "Set Up Lynis",
            "Install and conduct a local security audit using Lynis.",
            "sudo lynis audit system --quick",
            "This lab task demonstrates a quick Lynis audit to identify system vulnerabilities and assess security posture.",
            {"https://cisofy.com/lynis/", NULL, NULL, NULL, NULL}
        },
        {
            "Vulnerability Scanning with Nessus",
            "Perform an initial vulnerability scan using Nessus.",
            "sudo nessus -q",
            "Run Nessus in quiet mode to quickly assess potential vulnerabilities on your system.",
            {"https://www.tenable.com/products/nessus", NULL, NULL, NULL, NULL}
        },
        {
            "Practical OpenVAS Setup",
            "Install and run OpenVAS for a comprehensive vulnerability scan.",
            "sudo openvas-start",
            "Set up OpenVAS to conduct an in-depth vulnerability assessment and generate actionable reports.",
            {"https://www.openvas.org/", NULL, NULL, NULL, NULL}
        },
        {
            "Hands-on Firewall Security Testing",
            "Evaluate your firewall configuration with practical tests.",
            "sudo iptables -L",
            "Reviewing your firewall rules in real-time helps verify that your network defenses are properly configured.",
            {"https://www.digitalocean.com/community/tutorials/iptables-essentials", NULL, NULL, NULL, NULL}
        },
        {
            "Penetration Testing Basics",
            "Introduction to penetration testing methodologies and tools.",
            "nmap -A target_ip",
            "This lesson introduces aggressive network scanning to identify open ports and potential vulnerabilities.",
            {"https://nmap.org/book/", NULL, NULL, NULL, NULL}
        },
        {
            "Secure Configuration Baselines",
            "Evaluate system configurations against security benchmarks.",
            "sudo oscap xccdf eval --profile standard /usr/share/xml/scap/ssg/content/ssg-ubuntu1604-ds.xml",
            "Assess your system’s configuration against industry security baselines to spot misconfigurations.",
            {"https://www.open-scap.org/", NULL, NULL, NULL, NULL}
        },
        {
            "Conducting a Risk Assessment",
            "Perform a comprehensive risk assessment to identify potential threats.",
            "echo 'Risk Assessment Report'",
            "Risk assessments help prioritize security risks by evaluating their potential impact and likelihood.",
            {"https://www.nist.gov/", NULL, NULL, NULL, NULL}
        },
        {
            "Incident Response Drills",
            "Simulate incident response scenarios to prepare for security breaches.",
            "echo 'Simulate incident response'",
            "Regular drills ensure that your team is ready to respond efficiently when a real security incident occurs.",
            {"https://www.sans.org/incident-response/", NULL, NULL, NULL, NULL}
        },
        {
            "Real-time Security Monitoring",
            "Monitor system logs in real-time to detect ongoing threats.",
            "sudo tail -f /var/log/syslog",
            "Real-time log monitoring allows for immediate detection and response to suspicious activities.",
            {"https://www.loggly.com/ultimate-guide/real-time-log-monitoring/", NULL, NULL, NULL, NULL}
        },
        {
            "Post-assessment Reporting and Mitigation Strategies",
            "Compile assessment results and plan remediation actions.",
            "cat report.txt",
            "Effective post-assessment reporting provides the foundation for implementing targeted mitigation strategies.",
            {"https://www.sans.org/white-papers/389/", NULL, NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }
    
    // Dinner Questions
    Question questions[] = {
        {
            "Which command quickly starts a Lynis audit?",
            {"sudo lynis audit system --quick", "sudo lynis quick", "lynis --fast", "lynis audit -q"},
            "sudo lynis audit system --quick"
        },
        {
            "Which command is used for vulnerability scanning with Nessus in quiet mode?",
            {"sudo nessus -q", "nessus --quiet", "sudo nessus scan", "nessus -silent"},
            "sudo nessus -q"
        },
        {
            "Which command initiates OpenVAS?",
            {"sudo openvas-start", "openvas --run", "sudo openvas scan", "openvas -s"},
            "sudo openvas-start"
        },
        {
            "What command lists current firewall rules?",
            {"sudo iptables -L", "iptables --list", "firewall-cmd --list-all", "sudo firewall list"},
            "sudo iptables -L"
        },
        {
            "Which command uses an aggressive scan for penetration testing?",
            {"nmap -A target_ip", "nmap -aggressive target_ip", "nmap --attack target_ip", "nmap -sS target_ip"},
            "nmap -A target_ip"
        },
        {
            "Which tool evaluates secure configuration baselines?",
            {"oscap", "lynis", "nessus", "openvas"},
            "oscap"
        },
        {
            "What does a risk assessment primarily involve?",
            {"Evaluating potential security threats", "Installing patches", "Configuring firewalls", "Updating antivirus software"},
            "Evaluating potential security threats"
        },
        {
            "Which command monitors logs in real-time?",
            {"sudo tail -f /var/log/syslog", "watch /var/log/syslog", "cat /var/log/syslog", "logwatch --realtime"},
            "sudo tail -f /var/log/syslog"
        },
        {
            "Why are incident response drills important?",
            {"They prepare teams for actual security incidents", "They reduce system performance", "They replace audits", "They are only for training"},
            "They prepare teams for actual security incidents"
        },
        {
            "What is the final goal of post-assessment reporting?",
            {"To implement mitigation strategies", "To document vulnerabilities", "To schedule the next scan", "To archive log files"},
            "To implement mitigation strategies"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your practical security assessment knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
