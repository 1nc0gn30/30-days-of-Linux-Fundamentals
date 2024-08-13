#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

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
    printf(YELLOW_COLOR "Instructions: Open a separate terminal and type the command describe. Press Enter to continue after you've tried it.\n" RESET_COLOR);
    printf("When you are ready, press Enter to proceed...\n");
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

    // Convert the answer to uppercase for comparison
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') {
        user_answer[0] -= 32; // Convert to uppercase
    }

    // Convert answer to index
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

    // Introduction
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 14 Dinner!\n" RESET_COLOR);
    printf("This session will wrap up Week 2 with a review of key topics and some final questions.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
    {
        "Kernel Modules Management",
        "This lesson revisits the critical concepts of managing kernel modules, which are essential for extending the functionality of the Linux kernel. You'll learn how to load modules using `modprobe` and `insmod`, unload them with `rmmod`, and query loaded modules with `lsmod`. Understanding kernel parameters is crucial as they dictate the behavior of the kernel. You'll explore how to view and modify these parameters on the fly using `sysctl`, and learn the impact of these changes on system performance and security.\n\n"
        "Real-world scenarios include enabling specific hardware support by loading necessary modules and troubleshooting kernel issues by examining and adjusting kernel parameters. This knowledge ensures you're equipped to manage and troubleshoot the core of the Linux operating system effectively."
    },
    {
        "Advanced Network Configurations",
        "In this lesson, we dive deep into advanced network configurations, essential for optimizing and troubleshooting complex network environments. You will review IP addressing schemes, including subnetting and CIDR notation, and learn how to set up static IPs using the `ip` comman. We also cover static routing, where you'll configure routes manually to direct network traffic efficiently, using commands like `ip route add`.\n\n"
        "Troubleshooting network issues is a critical skill, and you'll get hands-on experience with tools such as `ping`, `traceroute`, and `netstat`. By the end of this lesson, you should be able to diagnose and resolve network issues, configure advanced network settings, and optimize network performance in a Linux environment."
    },
    {
        "Shell Scripting Mastery",
        "This lesson serves as the final review of advanced shell scripting techniques, where we consolidate all you've learned about creating powerful and efficient scripts. You'll delve into using loops (`for`, `while`, `until`) to automate repetitive tasks and conditional statements (`if`, `case`) to make your scripts more dynamiFunctions, which allow you to modularize your scripts, will also be a focus, enabling you to write more maintainable and reusable code.\n\n"
        "Practical examples include writing scripts to automate system administration tasks, such as backups, user management, and log rotation. By mastering these techniques, you'll be able to create robust scripts that can handle complex tasks with ease, making you a more efficient and effective system administrator."
    },
    {
        "System Security and Hardening",
        "This lesson reinforces the best practices for securing a Linux system, focusing on user management, file permissions, and implementing security policies. You'll learn how to manage users and groups effectively, ensuring that only authorized personnel have access to sensitive files and directories. File permissions, managed using the `chmod`, `chown`, and `chgrp` commands, are fundamental to Linux security, and you'll gain a deep understanding of how to apply them correctly.\n\n"
        "In addition, the lesson covers advanced security policies using tools like SELinux and AppArmor. You'll explore how to configure and enforce security policies that restrict the actions of processes, enhancing your system's security posture. Practical exercises will guide you through hardening your system against common threats, ensuring that your Linux environment is as secure as possible."
    }
};


    // Questions
    Question questions[] = {
    {"How do you load a kernel module in Linux?", {"insmod", "modprobe", "lsmod", "rmmod"}, "modprobe"},
    {"Which tool is used to trace the path packets take to a destination?", {"traceroute", "ping", "netstat", "ifconfig"}, "traceroute"},
    {"Which command is used to create a loop in a shell script?", {"for", "while", "until", "All of the above"}, "All of the above"},
    {"How do you check the status of SELinux?", {"sestatus", "semanage", "getenforce", ". setenforce"}, "sestatus"},
    {"Which command is used to configure static routes?", {"ip route add", "route -n", "ifconfig", "arp"}, "ip route add"},
    {"What is the primary function of `chmod`?", {"Change file permissions", "Change file ownership", "Compress files", "Display file contents"}, "Change file permissions"},
    {"Which command can be used to unload a kernel module?", {"rmmod", "modprobe", "lsmod", ". dmesg"}, "rmmod"},
    {"What command would you use to view the routing table in Linux?", {"ip route show", "netstat -r", "route -n", "traceroute"}, "ip route show"},
    {"Which SELinux mode restricts access based on security policies?", {"Enforcing", "Permissive", "Disabled", "Monitoring"}, "Enforcing"},
    {"How do you make a shell script executable?", {"chmod +x scriptname", "chown scriptname", "cp scriptname", "ls -l scriptname"}, "chmod +x scriptname"}
};


    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Display questions
    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}

