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
    printf(BOLD_COLOR CYAN_COLOR "Day 18 - Breakfast: Introduction to Backup Strategies\n" RESET_COLOR);
    printf(YELLOW_COLOR "Press Enter to begin Breakfast...\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
        {
            "Understanding Backup Types",
            "Differentiate between full, incremental, and differential backups.",
            "N/A (Conceptual)",
            "A full backup copies all data. An incremental backup only copies data that changed since the last backup. A differential backup copies all changes since the last full backup.",
            {"https://www.ibm.com/docs/en/tsm/7.1.0?topic=SSGSG7_7.1.0/com.ibm.itsm.client.doc/t_bac_concept.html", NULL}
        },
        {
            "Using tar for Backup",
            "Use tar to archive directories and files into compressed backups.",
            "tar -czvf backup.tar.gz /home/user/",
            "`tar` creates compressed archives. The `-c` creates a new archive, `-z` uses gzip compression, `-v` enables verbose mode, and `-f` specifies the archive file name.",
            {"https://linuxize.com/post/how-to-create-and-extract-archives-using-the-tar-command-in-linux/", NULL}
        },
        {
            "Using rsync for Incremental Backups",
            "Sync files and directories efficiently using rsync.",
            "rsync -av --delete /home/user/ /mnt/backup/",
            "`rsync` compares files and only copies changed ones. The `-a` preserves file permissions and timestamps, `-v` shows output, and `--delete` removes deleted files from destination.",
            {"https://rsync.samba.org/", "https://linux.die.net/man/1/rsync", NULL}
        }
    };

    for (int i = 0; i < sizeof(lessons)/sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    Question questions[] = {
        {
            "Which backup type saves all data every time it runs?",
            {"Incremental backup", "Differential backup", "Full backup", "Snapshot"},
            "Full backup"
        },
        {
            "Which command creates a gzip-compressed tar archive?",
            {"tar -czvf archive.tar.gz /path", "zip -r archive.zip /path", "gzip -d archive", "tar -tvf archive"},
            "tar -czvf archive.tar.gz /path"
        },
        {
            "Which rsync flag ensures that deletions are mirrored in the backup?",
            {"--copy-links", "--compress", "--delete", "--update"},
            "--delete"
        }
    };

    printf(BOLD_COLOR "Let's review what you've learned:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions)/sizeof(Question); i++) {
        display_question(&questions[i]);
    }

    return 0;
}
