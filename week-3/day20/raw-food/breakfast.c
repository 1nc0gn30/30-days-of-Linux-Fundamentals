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

    printf("Your answer (A, a, A., a., etc): ");
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
    printf(BOLD_COLOR CYAN_COLOR "Day 20 - Breakfast: Shell Scripting Refresher\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Review Variables and Loops",
            "How to declare variables and use loops in shell scripts.",
            "for i in {1..5}; do echo \"Number: $i\"; done",
            "Shell scripting allows lightweight automation. Loops let you repeat logic over ranges, arrays, or command outputs.\n"
            "Variables are declared like `name=Neal` without spaces, and accessed as `$name`.",
            {"https://tldp.org/LDP/Bash-Beginners-Guide/html/", NULL, NULL, NULL, NULL}
        },
        {
            "Conditionals in Scripts",
            "Using `if`, `else`, and `[ ]` for logic decisions.",
            "if [ \"$USER\" = \"root\" ]; then echo \"Admin\"; else echo \"User\"; fi",
            "Conditionals control script logic. Always quote variables inside `[ ]` and use `=` or `-eq` depending on type.",
            {"https://linuxize.com/post/bash-if-else-statement/", NULL, NULL, NULL, NULL}
        },
        {
            "Handling Input/Output",
            "Prompt for user input and redirect output to a file.",
            "read -p \"Enter your name: \" name; echo \"Hello $name\" >> greetings.txt",
            "`read` captures input. Use `>` for overwriting output and `>>` for appending. Always validate user input in production scripts.",
            {"https://opensource.com/article/19/9/getting-started-bash-scripting", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which of the following correctly declares a variable in bash?",
            {"var = 5", "var =5", "var=5", "let var=5"},
            "var=5"
        },
        {
            "Which command appends output to a file?",
            {"echo hello > file.txt", "echo hello >> file.txt", "echo hello | file.txt", "cat > file.txt"},
            "echo hello >> file.txt"
        },
        {
            "How do you read input from a user in a script?",
            {"input name", "read -p \"Name: \" name", "get name", "echo $USER"},
            "read -p \"Name: \" name"
        },
        {
            "What does this do: `if [ \"$USER\" = \"root\" ]; then`?",
            {"Checks if the user is root", "Starts a loop", "Compares integers", "Launches root shell"},
            "Checks if the user is root"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Time to quiz your shell skills:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You're now warmed up for advanced scripting.\n" RESET_COLOR);
    return 0;
}