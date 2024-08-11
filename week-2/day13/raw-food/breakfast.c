#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

// Lesson structure
typedef struct {
    const char *topic;
    const char *description;
} Lesson;

// Question structure
typedef struct {
    const char *question;
    const char *choices[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Instructions: Open a separate terminal and type the command described. Press Enter to continue after you've tried it.\n" RESET_COLOR);
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); 
    printf("\n");
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];
    printf(BOLD_COLOR GREEN_COLOR "Question: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->choices[i]);
    }
    printf("Your answer (A, B, C, or D): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    // Convert answer to index
    int answer_index = -1;
    if (user_answer[0] >= 'A' && user_answer[0] <= 'D') {
        answer_index = user_answer[0] - 'A';
    }

    if (answer_index >= 0 && answer_index < 4 && strcmp(question->choices[answer_index], question->correct_answer) == 0) {
        printf(GREEN_COLOR "Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %s\n" RESET_COLOR, question->correct_answer);
    }
    printf("\n");
}

int main() {
    // Clear screen
    printf("\033[H\033[J");

    // Introduction
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 13 breakfast!\n" RESET_COLOR);
    printf("In this session, we will explore System Administration Best Practices.\n");
    printf("We will cover system monitoring, backup and recovery, and security practices.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "System Monitoring and Performance Tuning",
            "Monitoring and tuning system performance is crucial for maintaining system health.\n"
            "Commands:\n"
            "- `top`: Displays real-time system information and resource usage.\n"
            "  ```bash\n"
            "  top\n"
            "  ```\n"
            "- `htop`: An enhanced version of top with a user-friendly interface.\n"
            "  ```bash\n"
            "  htop\n"
            "  ```\n"
            "- `vmstat`: Reports virtual memory statistics.\n"
            "  ```bash\n"
            "  vmstat 5\n"
            "  ```\n"
            "- `iostat`: Reports CPU and I/O statistics.\n"
            "  ```bash\n"
            "  iostat -x 5\n"
            "  ```\n"
            "Use these commands to monitor and optimize system performance."
        },
        {
            "Backup and Recovery Strategies",
            "Backup and recovery are essential for data protection and system resilience.\n"
            "Commands:\n"
            "- `rsync`: Efficiently syncs files and directories.\n"
            "  ```bash\n"
            "  rsync -avz /source/ /destination/\n"
            "  ```\n"
            "- `tar`: Archives files into a single file.\n"
            "  ```bash\n"
            "  tar -cvzf backup.tar.gz /directory/\n"
            "  ```\n"
            "- `dd`: Creates disk images.\n"
            "  ```bash\n"
            "  sudo dd if=/dev/sda of=/path/to/backup.img bs=4M\n"
            "  ```\n"
            "- Automate backups using `cron` by adding a cron job to `/etc/crontab`.\n"
            "  ```bash\n"
            "  0 2 * * * /usr/bin/rsync -avz /source/ /destination/\n"
            "  ```\n"
            "Test your backup and recovery procedures to ensure data integrity."
        },
        {
            "Security Best Practices",
            "Implementing security best practices is crucial for protecting Linux systems.\n"
            "Commands:\n"
            "- `chmod`: Changes file permissions.\n"
            "  ```bash\n"
            "  chmod 700 /secure_file\n"
            "  ```\n"
            "- `chown`: Changes file ownership.\n"
            "  ```bash\n"
            "  chown user:group /file\n"
            "  ```\n"
            "- Configure firewall with `ufw`.\n"
            "  ```bash\n"
            "  sudo ufw enable\n"
            "  sudo ufw allow 22\n"
            "  ```\n"
            "Ensure to regularly review and update security configurations."
        }
    };

    // Questions
    Question questions[] = {
        {"Which command displays real-time system information and resource usage?", {"A. top", "B. htop", "C. vmstat", "D. iostat"}, "top"},
        {"Which tool creates disk images?", {"A. rsync", "B. tar", "C. dd", "D. cp"}, "dd"},
        {"How do you enable a firewall using ufw?", {"A. sudo ufw enable", "B. sudo firewall start", "C. sudo iptables -A", "D. sudo firewall-cmd --add-port"}, "sudo ufw enable"},
        {"What does the `chmod 700` command do?", {"A. Changes file permissions", "B. Changes file ownership", "C. Creates a backup", "D. Archives files"}, "Changes file permissions"},
        {"Which command is used to sync files and directories?", {"A. rsync", "B. tar", "C. dd", "D. cp"}, "rsync"},
        {"How do you schedule automated backups with cron?", {"A. Edit /etc/crontab", "B. Use the cron command", "C. Run crontab -e", "D. Edit /etc/cron.daily"}, "Edit /etc/crontab"}
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Display questions
    printf(BOLD_COLOR "Now let's test your knowledge with some questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}

