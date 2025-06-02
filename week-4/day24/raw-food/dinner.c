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
                printf(GREEN_COLOR "✅ Correct! \"%s\" is the right answer.\n" RESET_COLOR, question->correct_answer);
            } else {
                printf(RED_COLOR "❌ Incorrect.\n" RESET_COLOR);
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
    printf(BOLD_COLOR CYAN_COLOR "Day 24 - Dinner: Practical Ansible Labs\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Write Your First Playbook",
            "Create and run a basic playbook to perform simple tasks.",
            "ansible-playbook playbook.yml",
            "This teaches the structure of a playbook including tasks, hosts, and modules like copy or command.",
            {"https://docs.ansible.com/ansible/latest/user_guide/playbooks_intro.html", NULL, NULL, NULL, NULL}
        },
        {
            "Automate Software Installation",
            "Install Nginx on multiple machines using Ansible.",
            "ansible-playbook -i hosts install-nginx.yml",
            "Helps automate common sysadmin tasks across multiple machines. Focuses on the apt and service modules.",
            {"https://docs.ansible.com/ansible/latest/collections/ansible/builtin/apt_module.html", NULL, NULL, NULL, NULL}
        },
        {
            "Playbook Debugging",
            "Learn how to identify and fix issues in playbooks.",
            "ansible-playbook debug.yml -e some_var=42",
            "Covers using the debug module, verbose flags, and reading error messages.",
            {"https://docs.ansible.com/ansible/latest/collections/ansible/builtin/debug_module.html", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which Ansible module helps print variable values?",
            {"copy", "service", "debug", "shell"},
            "debug"
        },
        {
            "How do you run a playbook on a specific inventory file?",
            {"ansible-playbook playbook.yml", "ansible -i playbook.yml", "ansible-playbook -i hosts playbook.yml", "ansible hosts playbook.yml"},
            "ansible-playbook -i hosts playbook.yml"
        },
        {
            "What does 'become: yes' do in a playbook?",
            {"Disables SSH", "Escalates privileges", "Creates a user", "Launches GUI"},
            "Escalates privileges"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Evening Quiz – Test Your Ansible Skills:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nDinner complete. You’ve now practiced real-world Ansible use cases!\n" RESET_COLOR);
    return 0;
}
