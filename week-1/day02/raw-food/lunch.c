#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for lessons
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Define struct for questions
typedef struct {
    const char *question;
    const char *correct_answer;
} Question;

// Function prototypes
void clear_screen();
void display_lesson(const Lesson *lesson);
void ask_question(const Question *question);

// Function to clear the screen (for Unix-based systems)
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("Examples:\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[100];
    printf("%s\n", question->question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0; // Remove the newline character

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

int main() {
    // Clear screen
    clear_screen();

    printf("Welcome to the File and Directory Management Challenge - Lunch!\n");
    printf("In this challenge, you'll learn about file compression, disk management, and network utilities.\n");
    printf("Follow the lessons to understand each command, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons array
    Lesson lessons[] = {
        {
            "File Compression and Archiving",
            "The `tar` command is used to create and extract archives. It can also compress files using various compression algorithms.",
            "Examples:\n  tar -cvf archive.tar file1.txt file2.txt         # Create an archive named 'archive.tar' with 'file1.txt' and 'file2.txt'\n  tar -xvf archive.tar                              # Extract the contents of 'archive.tar'\n  tar -czvf archive.tar.gz file1.txt file2.txt      # Create a compressed archive with gzip\n  tar -xzvf archive.tar.gz                         # Extract a compressed archive with gzip\n  tar -cf archive.tar -C /path/to/directory/ .       # Create an archive of all files in '/path/to/directory/'\n  tar -tf archive.tar                              # List the contents of 'archive.tar'"
        },
        {
            "Disk Usage and Management",
            "The `df` command reports disk space usage, and `fdisk` is used for disk partitioning. The `du` command provides disk usage information of directories and files.",
            "Examples:\n  df -h                         # Show disk space usage in human-readable format\n  df -T                         # Show the file system type along with disk usage\n  sudo fdisk -l                 # List all disk partitions and their sizes\n  sudo fdisk /dev/sda           # Open the fdisk utility for disk '/dev/sda'\n  du -sh directory/             # Show the total disk usage of 'directory/' in a human-readable format\n  du -a                         # Show disk usage of all files and directories recursively\n  du -ch | grep total            # Show disk usage and find the total size\n  du -sh --max-depth=1          # Show disk usage of directories within 'directory/' up to 1 level deep"
        },
        {
            "Network Utilities",
            "The `netstat` command displays network connections, routing tables, and network interface statistics. The `ping` command tests connectivity to a network host. The `traceroute` command shows the route packets take to a network host.",
            "Examples:\n  netstat -tuln                 # Show all listening TCP and UDP ports\n  netstat -r                    # Show the routing table\n  ping google.com               # Test connectivity to 'google.com'\n  ping -c 4 google.com          # Ping 'google.com' 4 times\n  traceroute google.com         # Trace the route to 'google.com'\n  traceroute -n google.com      # Trace the route without resolving hostnames"
        }
    };

    // Iterate through lessons and display them
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Quiz questions array
    Question questions[] = {
        {"1. What command creates and extracts archives and can also compress files?", "tar"},
        {"2. What command shows disk space usage in a human-readable format?", "df"},
        {"3. What command lists all disk partitions and their sizes?", "fdisk"},
        {"4. What command displays network connections and statistics?", "netstat"},
        {"5. What command tests connectivity to a network host?", "ping"},
        {"6. What command shows the route packets take to a network host?", "traceroute"}
    };

    // Quiz introduction
    printf("Now, test your knowledge with the following questions.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Iterate through questions and ask them
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf("Challenge complete! Review the commands and practice using them in your terminal.\n");
    return 0;
}
