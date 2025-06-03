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
    printf(BOLD_COLOR CYAN_COLOR "Day 28 - Dinner: Lab Session - Docker Compose\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Set Up a Multi-Container Application",
            "Use Docker Compose to run a web app with a database backend.",
            "docker-compose up",
            "This command will start all services defined in your docker-compose.yml file. Useful for local testing and integration.",
            {"https://docs.docker.com/compose/gettingstarted/", NULL, NULL, NULL, NULL}
        },
        {
            "Manage Docker Networks",
            "Create and inspect networks to connect containers securely.",
            "docker network create my_network",
            "Docker networks allow inter-container communication. Use 'docker network ls' to view, and 'docker network inspect' to get details.",
            {"https://docs.docker.com/network/bridge/", NULL, NULL, NULL, NULL}
        },
        {
            "Persistent Data with Volumes",
            "Use volumes to persist container data across restarts.",
            "volumes:\n  db_data:\nservices:\n  db:\n    volumes:\n      - db_data:/var/lib/postgresql/data",
            "Volumes help persist important data like databases. Defined in the 'volumes' section of your compose file.",
            {"https://docs.docker.com/storage/volumes/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What is the purpose of using volumes in Docker Compose?",
            {"To monitor memory", "To persist data", "To expose ports", "To restart containers"},
            "To persist data"
        },
        {
            "What command creates a custom network in Docker?",
            {"docker build", "docker-compose net", "docker network create", "docker net up"},
            "docker network create"
        },
        {
            "Which file defines multiple services in Docker Compose?",
            {"Dockerfile", "services.json", "compose.yml", "docker-compose.yml"},
            "docker-compose.yml"
        },
        {
            "How do containers communicate securely in Compose?",
            {"By using volumes", "Via exposed ports", "Through Docker networks", "Through environment variables"},
            "Through Docker networks"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nDinner Quiz – Practicing Docker Compose:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nDinner complete. You've containerized and composed with confidence.\n" RESET_COLOR);
    return 0;
}
