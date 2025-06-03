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
    printf(BOLD_COLOR CYAN_COLOR "Day 28 - Lunch: Docker Compose\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "What is Docker Compose?",
            "Learn how Docker Compose simplifies multi-container applications.",
            "docker-compose --version",
            "Docker Compose is a tool for defining and running multi-container Docker applications. It uses a YAML file to configure the application's services.",
            {"https://docs.docker.com/compose/", NULL, NULL, NULL, NULL}
        },
        {
            "Creating a docker-compose.yml File",
            "Write a YAML configuration file to define services, volumes, and networks.",
            "version: '3'\nservices:\n  web:\n    image: nginx\n  db:\n    image: postgres",
            "The docker-compose.yml file defines services and how they should run. You can include volumes, ports, networks, and environment variables.",
            {"https://docs.docker.com/compose/compose-file/", NULL, NULL, NULL, NULL}
        },
        {
            "Running Multi-Container Applications",
            "Use Docker Compose to start and stop all defined services.",
            "docker-compose up -d",
            "This command starts all the services in detached mode. Use 'docker-compose down' to stop and remove containers, networks, and volumes.",
            {"https://docs.docker.com/compose/reference/up/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What is Docker Compose primarily used for?",
            {"Running a single container", "Managing Docker Hub", "Defining and running multi-container applications", "Monitoring containers"},
            "Defining and running multi-container applications"
        },
        {
            "Which file defines services for Docker Compose?",
            {"Dockerfile", "docker-compose.yml", "compose.config", "containers.yml"},
            "docker-compose.yml"
        },
        {
            "What command starts services in detached mode?",
            {"docker-compose run", "docker-compose build", "docker-compose up -d", "docker-compose deploy"},
            "docker-compose up -d"
        },
        {
            "What does 'docker-compose down' do?",
            {"Starts containers", "Removes all services and volumes", "Upgrades Docker", "Monitors memory usage"},
            "Removes all services and volumes"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nLunch Quiz – Mastering Docker Compose:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. You're now orchestrating Docker services like a pro!\n" RESET_COLOR);
    return 0;
}
