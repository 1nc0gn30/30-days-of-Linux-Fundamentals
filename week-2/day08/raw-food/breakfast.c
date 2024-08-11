#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>  // For randomizing question order

// ANSI color codes for better user experience
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"
#define COLOR_MAGENTA "\033[35m"

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a question
typedef struct {
    const char *question;
    const char *correct_answer;
    const char *hint;
} Question;

// Function to clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    clear_screen();
    printf(COLOR_CYAN "Lesson on `%s`:\n" COLOR_RESET, lesson->topic);
    printf(COLOR_MAGENTA "%s\n" COLOR_RESET, lesson->description);
    printf(COLOR_YELLOW "\n%s\n" COLOR_RESET, lesson->examples);
    printf(COLOR_GREEN "Press Enter to continue...\n" COLOR_RESET);
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question, int question_number) {
    char user_answer[100];
    int attempts = 0;

    while (attempts < 2) {
        clear_screen();
        printf(COLOR_CYAN "Question %d: %s\n" COLOR_RESET, question_number, question->question);
        printf(COLOR_YELLOW "Hint: %s\n" COLOR_RESET, question->hint);
        printf(COLOR_GREEN "Please type answer out in full and do not include the option letter.\nIf the answer is... A) Apple ...then you would type the answer as Apple. \nWhen you are ready, press Enter to proceed...\n" COLOR_RESET);
        getchar(); // Wait for user to press Enter

        printf("Your answer: ");
        fgets(user_answer, sizeof(user_answer), stdin);
        user_answer[strcspn(user_answer, "\n")] = 0;  // Remove trailing newline

        if (strcmp(user_answer, question->correct_answer) == 0) {
            printf(COLOR_GREEN "Correct! Well done!\n\n" COLOR_RESET);
            sleep(2);  // Pause before moving to the next question
            break;
        } else {
            attempts++;
            if (attempts < 2) {
                printf(COLOR_RED "Incorrect. Try again...\n\n" COLOR_RESET);
                sleep(2);  // Pause before retrying
            } else {
                printf(COLOR_RED "Incorrect again. The correct answer is: %s\n\n" COLOR_RESET, question->correct_answer);
                sleep(2);  // Pause before moving to the next question
            }
        }
    }
}

int main() {
    clear_screen();

    printf(COLOR_CYAN "Welcome to Day 08 Breakfast!\n" COLOR_RESET);
    printf("In this session, we'll explore shell scripting basics and package compilation.\n");
    printf(COLOR_YELLOW "We'll learn how to write shell scripts and compile packages from source code.\n" COLOR_RESET);
    printf(COLOR_GREEN "Press Enter to start...\n" COLOR_RESET);
    getchar(); // Wait for user to press Enter

   // Lessons
Lesson lessons[] = {
    {
        "Shell Scripting Basics",
        "Shell scripting allows you to automate repetitive tasks in your Linux environment. By writing scripts, you can perform a series of commands without manually typing them one by one. Scripts can include commands, loops, conditional statements, and functions to handle complex operations.",
        "Example: \n"
        "#!/bin/bash\n"
        "echo 'Hello, World!'\n"
        "This script prints 'Hello, World!' to the terminal."
    },
    {
        "Package Compilation",
        "Compiling a package from source code involves converting the human-readable code into machine code that your computer can execute. This is useful when you need the latest version of software or when it's not available in your package manager.",
        "Example: \n"
        "1. Download the source code (e.g., via `wget` or `git clone`).\n"
        "2. Extract the archive: `tar -xvf source-code.tar.gz`\n"
        "3. Navigate to the directory: `cd source-code`\n"
        "4. Configure the package: `./configure`\n"
        "5. Compile the code: `make`\n"
        "6. Install the package: `sudo make install`"
    },
    {
        "Variables in Shell Scripts",
        "Variables in shell scripts are used to store data that your script can use later. Variables can hold numbers, strings, or the output of commands. You can assign values to variables and then reference them using the `$` symbol.",
        "Example: \n"
        "name='Neal'\n"
        "echo \"Hello, $name\"\n"
        "This script prints 'Hello, Neal' using the variable `name`."
    },
    {
        "Control Structures",
        "Control structures like `if-else` statements and loops (`for`, `while`) allow your scripts to make decisions and repeat tasks. This makes your scripts more powerful by enabling conditional execution and iteration.",
        "Example: \n"
        "if [ \"$name\" = \"Neal\" ]; then\n"
        "  echo \"Hello, Neal\"\n"
        "else\n"
        "  echo \"Hello, Stranger\"\n"
        "fi\n"
        "This script greets Neal if the `name` variable is set to 'Neal'; otherwise, it greets a stranger."
    },
    {
        "Functions",
        "Functions in shell scripts are blocks of code that you can define once and reuse multiple times throughout your script. Functions help to organize code and avoid repetition, making scripts easier to read and maintain.",
        "Example: \n"
        "greet() {\n"
        "  echo \"Hello, $1\"\n"
        "}\n"
        "greet 'Neal'\n"
        "This script defines a function `greet` and then calls it with the argument 'Neal'."
    },
    {
        "Package Configuration",
        "The configuration step in package compilation is where you customize how the package will be built. The `./configure` script checks for dependencies and allows you to set various options, such as installation directories or enabling/disabling features.",
        "Example: \n"
        "./configure --prefix=/usr/local --enable-feature\n"
        "This configures the package to install in `/usr/local` and enables a specific feature during the build."
    }
};

   // Questions
Question questions[] = {
    {"What is the purpose of the shebang (`#!`) in the first line of a shell script?\nA) Specifies the file type\nB) Specifies the interpreter\nC) Starts a comment\nD) Defines a function", 
    "Specifies the interpreter", 
    "It tells the system which interpreter to use for executing the script."},

    {"List the sequence of commands to compile a package from source code after downloading the archive.\nA) tar -xvf, cd, ./configure, make, sudo make install\nB) make, cd, tar -xvf, sudo make install, ./configure\nC) ./configure, tar -xvf, make, sudo make install, cd\nD) sudo make install, make, cd, tar -xvf, ./configure", 
    "tar -xvf, cd, ./configure, make, sudo make install", 
    "Think of the steps from extraction to installation."},

    {"How do you store and access data, such as a user's name, within a shell script?\nA) Function\nB) Variable\nC) Loop\nD) Alias", 
    "Variable", 
    "It's a placeholder for dynamic values in the script."},

    {"What control structure would you use to execute different commands based on conditions?\nA) for loop\nB) while loop\nC) if-else\nD) case", 
    "if-else", 
    "It allows your script to make decisions."},

    {"What feature in a shell script lets you organize code into reusable blocks?\nA) Function\nB) Variable\nC) Loop\nD) Alias", 
    "Function", 
    "It allows you to define and call blocks of code."},

    {"Which command customizes the build process of a package, allowing you to set options before compiling?\nA) make\nB) configure\nC) sudo make install\nD) tar -xvf", 
    "configure", 
    "This command is run before `make` and checks for dependencies."}
};


    // Randomize question order
    srand(time(NULL));
    for (int i = sizeof(questions) / sizeof(questions[0]) - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // Run through lessons and questions
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i], i + 1); // Pass question number
    }

    printf(COLOR_CYAN "Congratulations! You've completed Day 08 Breakfast.\n" COLOR_RESET);
    printf("Remember to keep practicing and exploring the topics we covered today.\n");
    printf(COLOR_GREEN "Press Enter to exit." COLOR_RESET);
    getchar(); // Wait for user to press Enter before exiting

    return 0;
}
