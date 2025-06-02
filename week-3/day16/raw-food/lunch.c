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
    printf(BOLD_COLOR CYAN_COLOR "Day 16 - Lunch: Vulnerability Assessment Tools\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Lunch...\n" RESET_COLOR);
    getchar();
    
    // Lunch Lessons
    Lesson lessons[] = {
        {
            "Using Lynis for Auditing",
            "Conduct a comprehensive security audit using Lynis.",
            "sudo lynis audit system",
            "Lynis is an open-source auditing tool that assesses system security and compliance.",
            {"https://cisofy.com/lynis/", NULL, NULL, NULL, NULL}
        },
        {
            "Nessus for Vulnerability Scanning",
            "Learn the basics of vulnerability scanning with Nessus.",
            "nessus -q",
            "Nessus is a powerful vulnerability scanner that identifies security holes and misconfigurations.",
            {"https://www.tenable.com/products/nessus", NULL, NULL, NULL, NULL}
        },
        {
            "OpenVAS Overview",
            "Introduction to OpenVAS as an open-source vulnerability scanner.",
            "openvas-start",
            "OpenVAS offers a robust framework for scanning and managing vulnerabilities across your network.",
            {"https://www.openvas.org/", NULL, NULL, NULL, NULL}
        },
        {
            "Introduction to Vulnerability Assessment",
            "Understand the fundamentals of identifying security weaknesses.",
            "sudo apt install lynis",
            "Regular vulnerability assessments help in proactively identifying and mitigating risks.",
            {"https://www.sans.org/white-papers/374/", NULL, NULL, NULL, NULL}
        },
        {
            "Configuring Vulnerability Scanners",
            "Set up tools like Nessus for optimal vulnerability scanning.",
            "sudo nessuscli update",
            "Proper configuration ensures accurate and efficient detection of security vulnerabilities.",
            {"https://www.tenable.com/products/nessus/nessus-configuration", NULL, NULL, NULL, NULL}
        },
        {
            "Interpreting Vulnerability Scan Reports",
            "Learn how to read and act on scan reports.",
            "cat /var/nessus/report.html",
            "Understanding scan reports is key to identifying and remediating security issues.",
            {"https://www.tenable.com/blog/how-to-read-nessus-reports", NULL, NULL, NULL, NULL}
        },
        {
            "Best Practices for Vulnerability Management",
            "Overview of effective strategies for managing vulnerabilities.",
            "echo 'Review reports regularly'",
            "Implementing best practices helps prioritize fixes and maintain overall system security.",
            {"https://www.cisa.gov/vulnerability-management", NULL, NULL, NULL, NULL}
        },
        {
            "Manual Vulnerability Checks",
            "Perform manual vulnerability checks with tools like nmap.",
            "nmap -sV target_ip",
            "Manual checks can complement automated scans by providing deeper insight into system vulnerabilities.",
            {"https://nmap.org/book/", NULL, NULL, NULL, NULL}
        },
        {
            "Automating Vulnerability Assessments",
            "Schedule regular scans to continuously monitor for vulnerabilities.",
            "crontab -e",
            "Automation reduces manual effort and ensures that vulnerability assessments are performed routinely.",
            {"https://www.cyberciti.biz/tips/automate-tasks-with-cron-jobs-in-linux.html", NULL, NULL, NULL, NULL}
        },
        {
            "Prioritizing Vulnerability Remediation",
            "Assess and prioritize vulnerabilities based on risk levels.",
            "echo 'Set remediation priorities'",
            "This lesson stresses the importance of addressing the most critical vulnerabilities first.",
            {"https://www.us-cert.gov/vulnerability", NULL, NULL, NULL, NULL}
        }
    };
    int numLessons = sizeof(lessons) / sizeof(lessons[0]);
    for (int i = 0; i < numLessons; i++) {
        display_lesson(&lessons[i]);
    }
    
    // Lunch Questions
    Question questions[] = {
        {
            "Which command initiates a system audit using Lynis?",
            {"sudo lynis audit system", "lynis --scan", "sudo lynis check", "lynis audit -q"},
            "sudo lynis audit system"
        },
        {
            "Which tool is known for its vulnerability scanning capabilities with a graphical interface?",
            {"Nessus", "Lynis", "OpenVAS", "Snort"},
            "Nessus"
        },
        {
            "Which open-source tool is used for vulnerability scanning?",
            {"OpenVAS", "Nessus", "Lynis", "Wireshark"},
            "OpenVAS"
        },
        {
            "What is the primary purpose of vulnerability assessments?",
            {"To identify security weaknesses", "To update software", "To monitor network traffic", "To backup data"},
            "To identify security weaknesses"
        },
        {
            "Which command updates Nessus plugins?",
            {"sudo nessuscli update", "nessus --update", "sudo apt update nessus", "nessus-update"},
            "sudo nessuscli update"
        },
        {
            "Which tool is used for manual vulnerability checks?",
            {"nmap -sV target_ip", "lynis audit", "openvas-start", "grep vulnerabilities"},
            "nmap -sV target_ip"
        },
        {
            "What is a key benefit of automating vulnerability assessments?",
            {"Regular scheduled scans", "Manual report generation", "Increased false positives", "Reduced network performance"},
            "Regular scheduled scans"
        },
        {
            "Which command displays a vulnerability scan report?",
            {"cat /var/nessus/report.html", "open /var/report", "nessus --report", "view report.txt"},
            "cat /var/nessus/report.html"
        },
        {
            "What is crucial for effective vulnerability management?",
            {"Prioritizing remediation", "Immediate shutdown", "Ignoring low risks", "Disabling scanning"},
            "Prioritizing remediation"
        },
        {
            "Which tool is renowned for comprehensive system auditing?",
            {"Lynis", "OpenVAS", "Nessus", "Snort"},
            "Lynis"
        }
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    printf(BOLD_COLOR "Now, let's test your vulnerability assessment knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < numQuestions; i++) {
        display_question(&questions[i]);
    }
    
    return 0;
}
