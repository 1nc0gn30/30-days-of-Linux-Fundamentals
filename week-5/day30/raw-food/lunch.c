/*
Day 30 Lunch: Capstone Project Overview - Interactive C Training
Focus: Overview, Requirements, Planning, and Collaboration
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

int score = 0;

void pause() {
    printf("\n(Press Enter to continue...)\n");
    getchar();
}

void show_overview() {
    printf(BOLD CYAN "\n=== Capstone Project Overview ===\n" RESET);
    printf("\nYour capstone project is a culmination of all you've learned:");
    printf("\n - System automation (Ansible, Puppet)");
    printf("\n - Container deployment (Docker)");
    printf("\n - System hardening & auditing");
    printf("\n - Task scheduling (cron)");
    printf("\n - Documentation & teamwork\n");
    pause();
}

void show_requirements() {
    printf(BOLD YELLOW "\nProject Requirements:\n" RESET);
    printf("- Secure a Linux-based system with proper firewall and SSH settings.\n");
    printf("- Automate setup with at least one configuration management tool.\n");
    printf("- Deploy at least one Docker container.\n");
    printf("- Schedule automated backups or maintenance tasks with cron.\n");
    printf("- Use Lynis to audit and correct critical issues.\n");
    pause();
}

void planning_tips() {
    printf(BOLD GREEN "\nPlanning Tips:\n" RESET);
    printf("- Begin with a checklist of required tasks.\n");
    printf("- Break the project into phases: Setup, Automation, Security, Deployment.\n");
    printf("- Define clear goals and expected outcomes.\n");
    pause();
}

void collaboration_tips() {
    printf(BOLD GREEN "\nCollaboration Guidelines:\n" RESET);
    printf("- Use Git and GitHub to track changes and share your work.\n");
    printf("- Assign roles if working in teams (networking, automation, documentation).\n");
    printf("- Communicate regularly, and review each other's code.\n");
    pause();
}

void recap_quiz() {
    char answer;

    printf(BOLD CYAN "\nQuiz: Which tool helps you run multiple containers together easily?\n" RESET);
    printf("A. Lynis\nB. cron\nC. Docker Compose\nD. SSH\n> ");
    scanf(" %c", &answer);
    getchar();

    if (tolower(answer) == 'c') {
        printf(GREEN "Correct! Docker Compose is used to run multi-container apps.\n" RESET);
        score++;
    } else {
        printf(RED "Incorrect. The correct answer is Docker Compose.\n" RESET);
    }

    printf(BOLD CYAN "\nQuiz: Why should you use Git during the project?\n" RESET);
    printf("A. To store backups\nB. To monitor containers\nC. For version control and collaboration\nD. To schedule tasks\n> ");
    scanf(" %c", &answer);
    getchar();

    if (tolower(answer) == 'c') {
        printf(GREEN "Correct! Git enables collaboration and change tracking.\n" RESET);
        score++;
    } else {
        printf(RED "Incorrect. Git is essential for version control.\n" RESET);
    }
}

int main() {
    printf(BOLD CYAN "\n=== Day 30: Capstone Project Lunch Session ===\n" RESET);

    show_overview();
    show_requirements();
    planning_tips();
    collaboration_tips();
    recap_quiz();

    printf(BOLD GREEN "\nFinal Score: %d/2\n" RESET, score);
    printf("Keep this project as a portfolio piece and share it on GitHub!\n");

    return 0;
}
