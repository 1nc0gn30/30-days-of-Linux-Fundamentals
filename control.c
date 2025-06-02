#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>     // For access() and X_OK
#include <sys/stat.h>   // For mkdir()
#include <errno.h>      // For errno

#define MAX_PATH_LENGTH 256
#define MAX_ENTRIES 100

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to print a styled header
void printHeader(const char *title) {
    printf(CYAN BOLD "\n%s\n" RESET, title);
    printf(CYAN "--------------------------------------\n" RESET);
}

// Function to list and choose directories
void listAndChooseDirectory(const char *parentDir, char *chosenDir) {
    struct dirent *entry;
    DIR *dp = opendir(parentDir);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printHeader("Available Directories");
    int index = 1;
    char dirs[MAX_ENTRIES][MAX_PATH_LENGTH];

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 &&
            entry->d_type == DT_DIR && strcmp(entry->d_name, ".git") != 0) {
            printf(GREEN "%d. %s\n" RESET, index, entry->d_name);
            snprintf(dirs[index - 1], MAX_PATH_LENGTH, "%s/%s", parentDir, entry->d_name);
            index++;
        }
    }
    closedir(dp);

    if (index == 1) {
        printf(RED "No directories found in %s\n" RESET, parentDir);
        return;
    }

    int choice;
    printf(CYAN "Enter the number of the directory to choose (1-%d): " RESET, index - 1);
    if (scanf("%d", &choice) != 1 || choice < 1 || choice >= index) {
        printf(RED "Invalid choice.\n" RESET);
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    snprintf(chosenDir, MAX_PATH_LENGTH, "%s", dirs[choice - 1]);
}

// Function to list and execute files
void listAndExecuteFiles(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printHeader("Available Files");
    int index = 1;
    char filePath[MAX_PATH_LENGTH];
    char files[MAX_ENTRIES][MAX_PATH_LENGTH];

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 &&
            entry->d_type == DT_REG) {
            printf(GREEN "%d. %s\n" RESET, index, entry->d_name);
            snprintf(files[index - 1], MAX_PATH_LENGTH, "%s/%s", directory, entry->d_name);
            index++;
        }
    }
    closedir(dp);

    if (index == 1) {
        printf(RED "No executable files found.\n" RESET);
        return;
    }

    int choice;
    printf(CYAN "Enter the number of the file to execute (1-%d): " RESET, index - 1);
    if (scanf("%d", &choice) != 1 || choice < 1 || choice >= index) {
        printf(RED "Invalid choice.\n" RESET);
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    snprintf(filePath, MAX_PATH_LENGTH, "%s", files[choice - 1]);

    if (access(filePath, X_OK) == 0) {
        printf(GREEN "Executing %s...\n" RESET, filePath);
        int result = system(filePath);
        if (result == -1) perror("system");
    } else {
        printf(RED "File not executable or not found: %s\n" RESET, filePath);
    }
}

// Ensure food folder exists
void ensureDirectoryExists(const char *dirPath) {
    struct stat st = {0};
    if (stat(dirPath, &st) == -1) {
        if (mkdir(dirPath, 0700) == 0) {
            printf(GREEN "Created missing directory: %s\n" RESET, dirPath);
        } else {
            printf(RED "Failed to create directory: %s. Error: %s\n" RESET, dirPath, strerror(errno));
        }
    }
}

int main() {
    char weekDir[MAX_PATH_LENGTH];
    char dayDir[MAX_PATH_LENGTH];
    char foodDir[MAX_PATH_LENGTH];
    char dayPrefix[16];
    int day = 0;
    int running = 1;

    while (running) {
        printHeader("Main Menu");
        printf(GREEN "1. Select Week\n2. Exit\n" RESET);
        printf(CYAN "Enter your choice: " RESET);

        int menuChoice;
        if (scanf("%d", &menuChoice) != 1) {
            printf(RED "Invalid input.\n" RESET);
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (menuChoice) {
            case 1:
                printHeader("Select Week");
                listAndChooseDirectory(".", weekDir);
                printf(GREEN "Chosen week directory: %s\n" RESET, weekDir);

                printHeader("Select Day");
                listAndChooseDirectory(weekDir, dayDir);
                printf(GREEN "Chosen day directory: %s\n" RESET, dayDir);

                const char *basename = strrchr(dayDir, '/');
                if (basename != NULL) {
                    basename++;
                    if (sscanf(basename, "day%d", &day) == 1 && day > 0 && day <= 30) {
                        snprintf(dayPrefix, sizeof(dayPrefix), "day-%02d", day);
                    } else {
                        printf(RED "Invalid day format in directory name: %s\n" RESET, basename);
                        continue;
                    }
                } else {
                    printf(RED "Unexpected path format.\n" RESET);
                    continue;
                }

                snprintf(foodDir, MAX_PATH_LENGTH, "%s/%s-food", dayDir, dayPrefix);
                printf(GREEN "Food directory path: %s\n" RESET, foodDir);

                ensureDirectoryExists(foodDir);
                printHeader("Execute File");
                listAndExecuteFiles(foodDir);
                break;

            case 2:
                printHeader("Exiting...");
                running = 0;
                break;

            default:
                printf(RED "Invalid choice. Try again.\n" RESET);
                break;
        }
    }

    return 0;
}
