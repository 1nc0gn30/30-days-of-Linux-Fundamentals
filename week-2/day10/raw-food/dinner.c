#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

typedef struct {
    const char *topic;
    const char  *description;
} Lesson;

typedef struct {
    const char *question; 
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    char answer[MAX_ANSWER_LENGTH];
    printf("\033[H\033[J");  // Clear the screen
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you've tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    fgets(answer, sizeof(answer), stdin);  // Wait for Enter
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];
    printf("Question: %s\n", question->question);
    printf("Your answer: ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    if (strcmp(user_answer, question->correct_answer) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n", question->correct_answer);
    }
    printf("\nPress Enter to continue...");
    getchar();  // Wait for Enter
}

int main() {
    printf("\033[H\033[J");  // Clear the screen
    
    printf("Welcome to Day 10: Linux Fundamentals!\n");
    printf("In this session, we will explore Package Management and System Monitoring.\n");
    printf("Press Enter to start...\n");
    getchar();  // Wait for Enter

    Lesson lessons[] = {
        {
            "Introduction to Package Management",
            "Package management is a critical part of maintaining a Linux system. "
            "Package managers like APT, YUM, and DNF allow you to install, update, "
            "and remove software packages easily.\n\n"
            "For example, to install a package with APT:\n\n"
            "sudo apt-get install package_name\n"
            "To remove a package:\n\n"
            "sudo apt-get remove package_name\n"
        },
        {
            "Using APT for Package Management",
            "APT (Advanced Package Tool) is the default package manager for Debian-based distributions like Ubuntu.\n\n"
            "To update the package list:\n\n"
            "sudo apt-get update\n\n"
            "To upgrade installed packages to their latest versions:\n\n"
            "sudo apt-get upgrade\n"
        },
        {
            "Managing Repositories",
            "Software repositories are locations from which packages can be retrieved and installed. "
            "In Debian-based systems, repository information is stored in /etc/apt/sources.list.\n\n"
            "To add a new repository, you can edit the sources.list file or add a new file under /etc/apt/sources.list.d/.\n\n"
            "Example of adding a repository:\n\n"
            "sudo add-apt-repository ppa:repository_name\n"
        },
        {
            "Checking Disk Usage with `df`",
            "The `df` command reports file system disk space usage.\n\n"
            "For example, to display disk usage in human-readable format:\n\n"
            "df -h\n"
        },
        {
            "Monitoring Processes with `top`",
            "The `top` command provides a dynamic, real-time view of the running system, including "
            "CPU usage, memory usage, and processes.\n\n"
            "To sort processes by CPU usage, you can use the 'P' key while top is running.\n"
        },
        {
            "Using `ps` to View Processes",
            "`ps` is used to view the currently running processes on the system.\n\n"
            "For example, to view all processes running on the system:\n\n"
            "ps -e\n\n"
            "To filter processes by a specific user:\n\n"
            "ps -u username\n"
        },
        {
            "Monitoring System Load with `uptime`",
            "The `uptime` command tells you how long the system has been running and the system load averages.\n\n"
            "For example, to view the uptime:\n\n"
            "uptime\n\n"
            "The load averages indicate the average system load over the last 1, 5, and 15 minutes.\n"
        }
    };

    Question questions[] = {
        {"Which command is used to update the package list in APT?", "sudo apt-get update"},
        {"What is the command to view all processes running on the system?", "ps -e"},
        {"How do you display disk usage in a human-readable format?", "df -h"},
        {"What command would you use to install a package named 'nginx'?", "sudo apt-get install nginx"},
        {"How do you add a new PPA repository?", "sudo add-apt-repository ppa:repository_name"},
        {"Which command provides a dynamic, real-time view of the system's processes?", "top"},
        {"How do you view the system's uptime and load averages?", "uptime"}
    };

    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    printf("\033[H\033[J");  // Clear the screen
    printf("Now let's test your knowledge with some questions:\n");
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    printf("Thank you for participating in Day 10 of Linux Fundamentals!\n");
    printf("Press Enter to exit...\n");
    getchar();  // Wait for Enter

    return 0;
}
