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
    printf(BOLD_COLOR CYAN_COLOR "Day 26 - Lunch: Writing Puppet Manifests\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Creating a Manifest",
            "Write a simple Puppet manifest to automate a system task.",
            "file { '/tmp/welcome.txt':\n  ensure  => present,\n  content => 'Hello from Puppet!',\n}",
            "Puppet manifests are written in .pp files and describe the desired state of resources on a system.",
            {"https://puppet.com/docs/puppet/latest/lang_write_resources.html", NULL, NULL, NULL, NULL}
        },
        {
            "Puppet Resources",
            "Understand common resources used in Puppet, such as file, package, and service.",
            "package { 'nginx':\n  ensure => installed,\n}",
            "Resources are building blocks in Puppet. Common resources include package, service, and file.",
            {"https://puppet.com/docs/puppet/latest/lang_resources.html", NULL, NULL, NULL, NULL}
        },
        {
            "Node Classification",
            "Learn how to apply specific configurations to nodes using Puppet.",
            "node 'webserver' { include nginx }",
            "Node definitions let you assign configurations to specific systems based on hostname or patterns.",
            {"https://puppet.com/docs/puppet/latest/lang_node_definitions.html", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What file extension is used for Puppet manifests?",
            {".yaml", ".conf", ".pp", ".json"},
            ".pp"
        },
        {
            "What is a resource in Puppet?",
            {"A file path", "A managed element like a package", "A class variable", "An agent config"},
            "A managed element like a package"
        },
        {
            "What is the purpose of node classification?",
            {"To reboot nodes", "To group servers for updates", "To assign specific configurations", "To limit memory usage"},
            "To assign specific configurations"
        },
        {
            "Which of the following is a valid Puppet resource type?",
            {"script", "user", "deploy", "binary"},
            "user"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nLunch Quiz – Writing Manifests:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. You can now write basic Puppet code!\n" RESET_COLOR);
    return 0;
}
