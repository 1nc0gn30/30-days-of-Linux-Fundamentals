#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

typedef struct {
    const char *topic;
    const char *description;
    const char *command_example;
    const char *detailed_explanation;
    const char *resources[MAX_RESOURCES];
} Lesson;

typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson: %s\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Example:\n" RESET_COLOR GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR "%s\n", lesson->detailed_explanation);
    printf(YELLOW_COLOR "Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && lesson->resources[i] != NULL; i++) {
        printf("- %s\n", lesson->resources[i]);
    }
    printf(YELLOW_COLOR "\nPress Enter to continue...\n" RESET_COLOR);
    getchar();
    printf("\n");
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];

    printf(BOLD_COLOR GREEN_COLOR "Quiz: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }

    printf("Your answer (A, B, C, D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = '\0';

    if (strlen(user_answer) >= 1) {
        char c = toupper(user_answer[0]);
        if (c >= 'A' && c <= 'D') {
            int idx = c - 'A';
            if (strcmp(question->choices[idx], question->correct_answer) == 0) {
                printf(GREEN_COLOR "\u2705 Correct! \"%s\" is the right answer.\n" RESET_COLOR, question->correct_answer);
            } else {
                printf(RED_COLOR "\u274C Incorrect.\n" RESET_COLOR);
                printf(YELLOW_COLOR "Explanation:\n" RESET_COLOR);
                printf("- Correct Answer: %s\n", question->correct_answer);
            }
        } else {
            printf(RED_COLOR "Invalid choice. Please enter A, B, C, or D.\n" RESET_COLOR);
        }
    } else {
        printf(RED_COLOR "No input received.\n" RESET_COLOR);
    }

    printf("\n");
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 24 - Lunch: Writing Playbooks in Ansible\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Creating a Playbook",
            "Learn to define and structure a basic Ansible playbook using YAML.",
            "- name: Install Nginx\n  hosts: webservers\n  become: yes\n  tasks:\n    - name: Install Nginx\n      apt:\n        name: nginx\n        state: present",
            "Playbooks are YAML files that define automation tasks. Each play targets a group of hosts and contains tasks that use modules.",
            {"https://docs.ansible.com/ansible/latest/user_guide/playbooks_intro.html", NULL, NULL, NULL, NULL}
        },
        {
            "Managing Multiple Servers",
            "Use one playbook to automate changes across multiple hosts.",
            "[webservers]\n192.168.1.10\n192.168.1.11",
            "Ansible uses an inventory to define host groups. You can run a playbook against any group or specific host by editing the hosts field.",
            {"https://docs.ansible.com/ansible/latest/user_guide/intro_inventory.html", NULL, NULL, NULL, NULL}
        },
        {
            "Common Ansible Modules",
            "Understand key modules like apt, copy, service, and file.",
            "ansible all -i hosts -m apt -a \"name=curl state=present\" -b",
            "Modules are the core of Ansible functionality. They handle tasks like installing packages, copying files, and managing services.",
            {"https://docs.ansible.com/ansible/latest/collections/ansible/builtin/index.html", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What format are Ansible playbooks written in?",
            {"JSON", "YAML", "INI", "XML"},
            "YAML"
        },
        {
            "Which Ansible module installs software packages?",
            {"copy", "file", "service", "apt"},
            "apt"
        },
        {
            "What does the 'hosts' field specify in a playbook?",
            {"The machine to install Ansible", "The task priority", "The target systems", "The Ansible version"},
            "The target systems"
        },
        {
            "How do you run a playbook?",
            {"ansible-playbook play.yml", "ansible-run play.yml", "ansible exec play.yml", "playbook-run play.yml"},
            "ansible-playbook play.yml"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nLunch Quiz – Test Your Playbook Knowledge:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. You can now build and execute your own Ansible playbooks!\n" RESET_COLOR);
    return 0;
}
