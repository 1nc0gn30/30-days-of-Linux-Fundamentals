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
    printf(BOLD_COLOR CYAN_COLOR "Day 23 - Breakfast: Bash Scripting Refresher\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Variables and Echo",
            "Learn how to declare and use variables in Bash scripts.",
            "name=Neal\necho \"Welcome, $name!\"",
            "Variables in Bash are assigned without spaces (e.g., name=Neal). Access them with the $ prefix. Echo is used to print to the terminal.",
            {"https://www.gnu.org/software/bash/manual/", NULL, NULL, NULL, NULL}
        },
        {
            "Loops",
            "Explore Bash for and while loops for automation.",
            "for i in {1..5}; do echo $i; done",
            "Loops are essential for repetitive tasks. For loops iterate over a sequence, while loops run based on conditions.",
            {"https://ryanstutorials.net/bash-scripting-tutorial/bash-loops.php", NULL, NULL, NULL, NULL}
        },
        {
            "Conditionals",
            "Use 'if' statements for decision-making in scripts.",
            "if [ $num -gt 5 ]; then echo \"Greater\"; else echo \"Smaller\"; fi",
            "Conditionals check values using test brackets []. Use operators like -gt (greater than), -eq (equals), etc.",
            {"https://linuxize.com/post/bash-if-else-statement/", NULL, NULL, NULL, NULL}
        },
        {
            "Input and Output",
            "Capture user input and write to files.",
            "read -p \"Enter name: \" name\necho \"Welcome $name\" >> greetings.txt",
            "Use 'read' to get input. '>>' appends to files, '>' overwrites. Always sanitize input if using in scripts.",
            {"https://opensource.com/article/19/9/getting-started-bash-scripting", NULL, NULL, NULL, NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "What is the correct way to declare a variable in Bash?",
            {"name = Neal", "name Neal", "name=Neal", "let name=Neal"},
            "name=Neal"
        },
        {
            "What symbol is used to access a variable in Bash?",
            {"&", "@", "$", "#"},
            "$"
        },
        {
            "What does the 'read' command do in Bash?",
            {"Writes to a file", "Reads user input", "Displays system info", "Pauses script"},
            "Reads user input"
        },
        {
            "Which loop executes a block while a condition is true?",
            {"for", "if", "switch", "while"},
            "while"
        }
    };

    printf(BOLD_COLOR GREEN_COLOR "Morning Quiz – Test Your Bash Basics:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    printf(BOLD_COLOR CYAN_COLOR "\nBreakfast complete. You're ready to tackle more advanced scripting now.\n" RESET_COLOR);
    return 0;
}
