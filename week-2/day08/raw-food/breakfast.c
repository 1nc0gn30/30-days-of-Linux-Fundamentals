#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

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
} Question;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("%s\n", question->question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to Day 08 Breakfast!\n");
    printf("In this session, we'll explore shell scripting basics and package compilation.\n");
    printf("We'll learn how to write shell scripts and compile packages from source code.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Shell Scripting Basics",
            "Shell scripting is a powerful tool that allows you to automate tasks in Unix-based systems by writing a sequence of commands in a file. "
            "This can be used to streamline workflows, manage system configurations, or perform repetitive tasks efficiently.\n"
            "Shell scripts typically start with a 'shebang' (`#!/bin/bash`), which tells the system which interpreter to use for executing the script.\n"
            "Common use cases include backup scripts, batch processing, and environment setup.",
            "Examples:\n"
            "  #!/bin/bash\n"
            "  echo \"Hello, World!\"\n"
            "  # Save this script as hello.sh, make it executable with chmod +x hello.sh, and run it with ./hello.sh\n"
            "For more details, check out resources like 'The Linux Command Line' by William Shotts or the online Bash Guide at https://www.gnu.org/software/bash/manual/bash.html."
        },
        {
            "Package Compilation",
            "Compiling software from source code gives you the ability to customize software installations, optimize performance, and apply patches.\n"
            "This is particularly useful when the desired package is not available in your distribution’s package manager or when you need a specific version.\n"
            "The process usually involves downloading the source code, extracting it, configuring the build environment, compiling the source, and finally installing the binaries.",
            "Examples:\n"
            "  wget http://example.com/package.tar.gz\n"
            "  tar -xvf package.tar.gz\n"
            "  ./configure\n"
            "  make\n"
            "  sudo make install\n"
            "A deeper dive into this topic can be found in resources like 'Linux From Scratch' or the 'GNU Autotools' documentation at https://www.gnu.org/software/autoconf/manual/autoconf.html."
        },
        {
            "Variables in Shell Scripts",
            "Variables are used to store data that can be used and manipulated throughout your script. They are essential for making scripts dynamic and adaptable.\n"
            "In shell scripting, variables are created without a data type and can hold strings, numbers, or even the output of a command.\n"
            "Understanding how to use variables effectively allows you to create more powerful and flexible scripts.",
            "Examples:\n"
            "  my_variable=\"Hello, World!\"\n"
            "  echo $my_variable\n"
            "  # Variables can also be assigned dynamically, for example: my_date=$(date)\n"
            "For a comprehensive guide on shell variables, refer to the Bash Scripting Tutorial at https://linuxconfig.org/bash-scripting-tutorial."
        },
        {
            "Control Structures in Shell Scripts",
            "Control structures like `if-else` statements and loops (`for`, `while`) are fundamental to writing scripts that can make decisions and repeat tasks.\n"
            "These structures enable conditional execution of commands and iterating over data sets, which is critical in automating complex workflows.\n"
            "Mastering these control structures will allow you to write scripts that can handle a wide range of scenarios automatically.",
            "Examples:\n"
            "  if [ $my_variable = \"Hello, World!\" ]; then\n"
            "    echo \"Match found!\"\n"
            "  else\n"
            "    echo \"No match.\"\n"
            "  fi\n"
            "  for i in 1 2 3; do echo $i; done\n"
            "For more detailed information, you can consult the Advanced Bash-Scripting Guide at https://tldp.org/LDP/abs/html/."
        },
        {
            "Functions in Shell Scripts",
            "Functions in shell scripts are blocks of reusable code that can be invoked multiple times within the script. They help in organizing and structuring scripts, making them more readable and maintainable.\n"
            "Functions are particularly useful when you have a set of commands that need to be executed multiple times with different parameters.",
            "Examples:\n"
            "  my_function() {\n"
            "    echo \"Hello, World!\"\n"
            "  }\n"
            "  my_function\n"
            "  # Functions can also accept parameters, e.g., my_function() { echo \"Hello, $1\"; }.\n"
            "Learn more about functions in Bash by exploring the Bash Reference Manual at https://www.gnu.org/software/bash/manual/bash.html#Shell-Functions."
        },
        {
            "Package Configuration Options",
            "When compiling software from source, `./configure` scripts are used to tailor the build process to your specific environment. These scripts check for dependencies, set paths, and customize features.\n"
            "Using configuration options, you can specify installation directories, enable or disable features, and apply patches. This level of control is invaluable when creating optimized or specialized builds.",
            "Examples:\n"
            "  ./configure --prefix=/usr/local\n"
            "  ./configure --enable-debug\n"
            "  # You can also use options like --disable-feature or --with-custom-option to further customize your build.\n"
            "The GNU Autoconf documentation (https://www.gnu.org/software/autoconf/manual/autoconf.html) is an excellent resource for understanding these options in detail."
        }
    };

    // Questions
Question questions[] = {
    {
        "1. What is the purpose of the `#!/bin/bash` line in a shell script?\n"
        "Hint: Explain the role of the `shebang` line in specifying the shell interpreter.\n"
        "Format: The shebang line specifies the shell interpreter as [interpreter].",
        "#!/bin/bash specifies the shell interpreter as /bin/bash"
    },
    {
        "2. What command is used to extract a tarball?\n"
        "Hint: Mention the specific flags used to extract files from a `.tar.gz` archive.\n"
        "Format: The command to extract a tarball is `tar` with the flags [flags].",
        "tar -xvf"
    },
    {
        "3. What is the purpose of the `export` command in shell scripting?\n"
        "Hint: Describe how `export` affects environment variables.\n"
        "Format: The `export` command is used to variable av******* to sub*********.",
        "The `export` command is used to make a variable available to subprocesses"
    },
    {
        "4. How do you write an if-else statement in a shell script?\n"
        "Hint: Outline the basic syntax for an `if-else` statement in bash.\n"
        "Format: The syntax is `** condition; **** action; **** alternative; fi`.",
        "if condition; then action; else alternative; fi"
    },
    {
        "5. What is the difference between `./configure` and `./configure --prefix=/usr/local`?\n"
        "Hint: Explain how the `--prefix` option affects the installation path.\n"
        "Format: The `The latter sets the installation p****x to /usr/local",
        "The latter sets the installation prefix to /usr/local"
    },
    {
        "6. How do you define a function in a shell script? Use my_function as function name and commands as name for commands.\n"
        "Hint: Describe the syntax for defining a function in bash.\n"
        "Format: A function is defined using the syntax `[function_name]() { [commands]; }`.",
        "my_function() { commands; }"
    }
};

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    return 0;
}
