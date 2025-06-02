#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_RESOURCES 5

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

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
    printf(YELLOW_COLOR "Example Command:\n" RESET_COLOR GREEN_COLOR " %s\n" RESET_COLOR, lesson->command_example);
    printf(YELLOW_COLOR "Detailed Explanation:\n" RESET_COLOR "%s\n", lesson->detailed_explanation);
    printf(YELLOW_COLOR "Resources:\n" RESET_COLOR);
    for (int i = 0; i < MAX_RESOURCES && lesson->resources[i] != NULL; i++) {
        printf("- %s\n", lesson->resources[i]);
    }
    printf(YELLOW_COLOR "Press Enter to continue...\n" RESET_COLOR);
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
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') user_answer[0] -= 32;
    int index = user_answer[0] - 'A';
    if (index >= 0 && index < 4 && strcmp(question->choices[index], question->correct_answer) == 0) {
        printf(GREEN_COLOR "Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %s\n" RESET_COLOR, question->correct_answer);
    }
    printf("\n");
}

int main() {
    printf("\033[H\033[J");
    printf(BOLD_COLOR CYAN_COLOR "Day 18 - Lunch: Automating Backups\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Lunch...\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Automating Backups with Cron",
            "Schedule recurring backup tasks using cron jobs.",
            "crontab -e",
            "Cron lets users schedule scripts to run at specific times. For example, to back up `/home/user` every day at 2am, you might add:\n0 2 * * * tar -czf /backup/home_backup.tar.gz /home/user",
            {"https://opensource.com/article/19/9/intro-cron", "https://crontab.guru/", NULL}
        },
        {
            "Creating Snapshots with Btrfs",
            "Use Btrfs to take snapshots of your filesystem.",
            "sudo btrfs subvolume snapshot /data /snapshots/data_$(date +%F)",
            "Btrfs supports instant, space-efficient snapshots. Snapshots are read-only or writable versions of the data at a given point in time, useful for recovery.",
            {"https://btrfs.readthedocs.io/en/latest/btrfs-snapshot.html", NULL}
        },
        {
            "Remote Backups with rsync + SSH",
            "Securely transfer backups to a remote server using rsync over SSH.",
            "rsync -avz /home/user/ user@remote:/backup/user/",
            "`rsync -avz` combines archive mode, verbose output, and compression. When used with SSH, it securely syncs files to remote storage.",
            {"https://wiki.archlinux.org/title/Rsync", "https://www.redhat.com/sysadmin/rsync-backup", NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which tool allows scheduling backup tasks periodically?",
            {"rsync", "cron", "btrfs", "tar"},
            "cron"
        },
        {
            "What is the purpose of `btrfs subvolume snapshot`?",
            {"Deletes a volume", "Creates a backup file", "Creates a point-in-time snapshot", "Formats a disk"},
            "Creates a point-in-time snapshot"
        },
        {
            "Which command syncs data securely over SSH?",
            {"rsync -av /data /remote", "scp /data user@remote:/backup", "rsync -avz /data user@remote:/backup", "tar -czf - | ssh user@remote"},
            "rsync -avz /data user@remote:/backup"
        }
    };

    printf(BOLD_COLOR "Let’s reinforce your knowledge with a quick quiz:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    return 0;
}
