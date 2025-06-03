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
    printf(BOLD_COLOR CYAN_COLOR "Day 28 - Breakfast: Docker Networking and Storage\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Docker Networking Basics",
            "Understand how Docker containers communicate over virtual networks.",
            "docker network ls",
            "Docker networks allow containers to discover and communicate with each other. Use bridge, host, or overlay networks depending on your architecture.",
            {"https://docs.docker.com/network/", NULL, NULL, NULL, NULL}
        },
        {
            "Volumes and Persistent Storage",
            "Use Docker volumes to keep data even after containers are removed.",
            "docker volume create mydata",
            "Volumes store persistent or shared data for containers. Useful for database storage, configuration files, etc.",
            {"https://docs.docker.com/storage/volumes/", NULL, NULL, NULL, NULL}
        },
        {
            "Linking Containers",
            "Allow containers to reference each other by name.",
            "docker run --name db -d postgres\ndocker run --name web --link db:db -d myapp",
            "The --link flag allows temporary container-to-container name resolution and communication. Better to use user-defined networks for modern setups.",
            {"https://docs.docker.com/network/links/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What command lists available Docker networks?",
            {"docker networks", "docker network list", "docker network ls", "docker net show"},
            "docker network ls"
        },
        {
            "What is the purpose of Docker volumes?",
            {"To add RAM", "To store persistent data", "To scale containers", "To backup Docker images"},
            "To store persistent data"
        },
        {
            "Which flag is used to link two containers?",
            {"--network", "--connect", "--link", "--bind"},
            "--link"
        },
        {
            "Which network type is the Docker default?",
            {"host", "overlay", "bridge", "none"},
            "bridge"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nBreakfast Quiz – Docker Networking and Storage:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You're networking containers like a champ!\n" RESET_COLOR);
    return 0;
}
