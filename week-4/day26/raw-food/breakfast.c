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
    printf(BOLD_COLOR CYAN_COLOR "Day 26 - Breakfast: Introduction to Puppet\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "What is Puppet?",
            "Overview of Puppet and its role in configuration management.",
            "puppet --version",
            "Puppet is a configuration management tool that automates the provisioning and management of infrastructure. It uses manifests to define desired system states.",
            {"https://puppet.com/docs/puppet/latest/", NULL, NULL, NULL, NULL}
        },
        {
            "Installing Puppet",
            "Guide on how to install Puppet on your system.",
            "sudo apt install puppet -y",
            "Install the Puppet agent using the package manager on Debian/Ubuntu. Ensure the Puppet server is reachable and agent is configured properly.",
            {"https://puppet.com/docs/puppet/latest/installing_and_upgrading.html", NULL, NULL, NULL, NULL}
        },
        {
            "Basic Concepts",
            "Learn about manifests, modules, and how Puppet manages system state.",
            "cat site.pp",
            "Puppet manifests define system configurations. Modules group related manifests and files. Puppet ensures system state matches the defined configuration.",
            {"https://puppet.com/docs/puppet/latest/lang_resources.html", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What is Puppet used for?",
            {"Software development", "Database querying", "Configuration management", "System monitoring"},
            "Configuration management"
        },
        {
            "Which command installs Puppet on Ubuntu?",
            {"apt install puppet", "install-puppet", "puppet-install", "setup puppet"},
            "apt install puppet"
        },
        {
            "What is a Puppet manifest?",
            {"A config file for cron", "A YAML file for Ansible", "A file defining system state", "A kernel module"},
            "A file defining system state"
        },
        {
            "What is the file extension for Puppet manifests?",
            {".yaml", ".pp", ".cfg", ".conf"},
            ".pp"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nMorning Quiz – Puppet Basics:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. Puppet foundations installed!\n" RESET_COLOR);
    return 0;
}
