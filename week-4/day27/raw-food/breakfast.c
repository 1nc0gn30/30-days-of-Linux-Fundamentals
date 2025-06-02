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
    printf(BOLD_COLOR CYAN_COLOR "Day 27 - Breakfast: What is Docker?\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Understanding Containers",
            "Learn what containers are and how Docker uses them to isolate environments.",
            "docker run hello-world",
            "Containers package applications and their dependencies into a standardized unit, making them portable and consistent across environments.",
            {"https://docs.docker.com/get-started/", NULL, NULL, NULL, NULL}
        },
        {
            "Installing Docker",
            "Step-by-step instructions to install Docker on Linux.",
            "sudo apt install docker.io",
            "On most Linux distros, Docker can be installed via the package manager. You may need to enable the Docker service and add your user to the docker group.",
            {"https://docs.docker.com/engine/install/", NULL, NULL, NULL, NULL}
        },
        {
            "Docker vs Virtual Machines",
            "Differences between Docker containers and virtual machines.",
            "",
            "VMs emulate entire operating systems, while containers share the host kernel and are more lightweight, efficient, and faster to start.",
            {"https://www.docker.com/resources/what-container/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What is the purpose of a Docker container?",
            {"Run virtual machines", "Emulate hardware", "Package and run applications", "Monitor system logs"},
            "Package and run applications"
        },
        {
            "How do you install Docker on Ubuntu?",
            {"apt install docker", "yum install docker", "sudo apt install docker.io", "brew install docker"},
            "sudo apt install docker.io"
        },
        {
            "What does the 'docker run hello-world' command do?",
            {"Installs Docker", "Builds a container", "Tests Docker installation", "Opens Docker GUI"},
            "Tests Docker installation"
        },
        {
            "What is one major difference between containers and virtual machines?",
            {"Containers run on Windows only", "VMs are more lightweight", "Containers are slower", "Containers share the host OS kernel"},
            "Containers share the host OS kernel"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nMorning Quiz – Docker Basics:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You now understand Docker basics.\n" RESET_COLOR);
    return 0;
}
