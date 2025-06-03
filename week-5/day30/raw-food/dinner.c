/*
Day 30 Dinner: Capstone Project Execution - Interactive C Training
Focus: Execution, Testing, and Documentation
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

void show_instructions() {
    printf(BOLD CYAN "\n=== Capstone Project Execution Instructions ===\n" RESET);
    printf("\nYour objective is to put all the concepts from the past 30 days into a final project.\n");
    printf("This project should showcase your ability to:");
    printf("\n - Automate systems using tools like Ansible or Puppet");
    printf("\n - Deploy containerized services with Docker");
    printf("\n - Apply security hardening techniques\n\n");

    printf(BOLD YELLOW "Capstone Requirements:\n" RESET);
    printf("1. Harden a base Linux system (disable unused services, secure SSH, configure firewall).\n");
    printf("2. Use Ansible or Puppet to automate configuration across multiple nodes.\n");
    printf("3. Deploy at least one Dockerized service (e.g., Nginx, Node.js, or PostgreSQL).\n");
    printf("4. Create a cron job for backups or maintenance.\n");
    printf("5. Run a Lynis audit and address the major issues.\n\n");

    printf(BOLD GREEN "\nProject Submission Instructions:\n" RESET);
    printf("- Upload your finished project to a GitHub repository.\n");
    printf("- Include a README.md that explains what your project does and how to run it.\n");
    printf("- Share the link with your instructor or community group.\n");
    printf("- You may include screenshots or short videos showing the system in action.\n\n");
}

int main() {
    printf(BOLD CYAN "\n=== Day 30: Capstone Project Dinner Instructions ===\n" RESET);
    show_instructions();
    printf(GREEN "\nYou're now ready to bring it all together. Good luck, and don't forget to share your final masterpiece!\n" RESET);
    return 0;
}
