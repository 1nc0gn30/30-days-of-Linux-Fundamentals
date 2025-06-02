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
    printf(BOLD_COLOR CYAN_COLOR "Day 27 - Lunch: Working with Docker Images and Containers\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Docker Images",
            "Learn how to find and pull images from Docker Hub.",
            "docker pull ubuntu",
            "Docker images are pre-packaged environments. Use \"docker pull\" to download from Docker Hub.",
            {"https://hub.docker.com", "https://docs.docker.com/engine/reference/commandline/pull/", NULL, NULL, NULL}
        },
        {
            "Running Containers",
            "Create and run containers from images.",
            "docker run -it ubuntu bash",
            "The \"docker run\" command starts a new container. Use \"-it\" for interactive shell sessions.",
            {"https://docs.docker.com/get-started/", NULL, NULL, NULL, NULL}
        },
        {
            "Managing Containers",
            "Basic commands to stop, start, and remove containers.",
            "docker ps -a\ndocker stop <container_id>\ndocker rm <container_id>",
            "\"docker ps -a\" lists all containers. Use \"docker stop\" and \"docker rm\" to manage container lifecycle.",
            {"https://docs.docker.com/engine/reference/commandline/ps/", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which command pulls a Docker image from Docker Hub?",
            {"docker run", "docker build", "docker pull", "docker image"},
            "docker pull"
        },
        {
            "What does the '-it' flag do in docker run?",
            {"Installs packages", "Interactive terminal", "Increases timeout", "Ignores errors"},
            "Interactive terminal"
        },
        {
            "Which command removes a Docker container?",
            {"docker stop", "docker rm", "docker kill", "docker exit"},
            "docker rm"
        },
        {
            "How do you list all containers including stopped ones?",
            {"docker list", "docker ps", "docker ps -a", "docker images"},
            "docker ps -a"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "\nLunch Quiz – Docker Containers and Management:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nLunch complete. You're getting comfortable with Docker operations!\n" RESET_COLOR);
    return 0;
}
