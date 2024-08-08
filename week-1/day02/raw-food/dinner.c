#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for lessons
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("Examples:\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const char *question, const char *correct_answer) {
    char answer[100];
    printf("%s\n", question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to the Comprehensive Review and Advanced Concepts Dinner Challenge!\n");
    printf("In this challenge, you will review and expand on the commands learned in Day 1 and Day 2.\n");
    printf("Follow the lessons to understand each command in detail, then answer the questions at the end.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Define lessons
    Lesson lessons[] = {
        {"Listing Directory Contents (`ls`)",
         "The `ls` command lists directory contents. It shows the files and directories in the specified directory. It's a fundamental command for navigating and managing files.",
         "Examples:\n  ls                  # List files in the current directory\n  ls -l               # List files with detailed information, including permissions and size\n  ls -a               # List all files, including hidden files (those starting with a dot)\n  ls -lh              # List files with human-readable file sizes\n  ls -R               # Recursively list all subdirectories\n  ls --color=auto    # List files with color-coded output for different file types"},

        {"Changing Directories (`cd`)",
         "The `cd` command changes the current working directory. It's used to navigate through the filesystem. Understanding how to navigate efficiently is crucial for effective file management.",
         "Examples:\n  cd /home/user        # Change to the specified directory\n  cd ..                # Move up one directory\n  cd ~                 # Change to the home directory\n  cd -                 # Switch to the previous directory\n  cd /var/log          # Change to a specific directory\n  cd /                # Change to the root directory"},

        {"Creating and Updating Files (`touch`)",
         "The `touch` command creates a new empty file or updates the timestamp of an existing file. It’s useful for quickly creating files and modifying their timestamps.",
         "Examples:\n  touch newfile.txt           # Create a new file named 'newfile.txt'\n  touch existingfile.txt      # Update the timestamp of 'existingfile.txt'\n  touch file1.txt file2.txt   # Create or update multiple files\n  touch -c non_existing_file.txt  # Create a new file only if it does not already exist\n  touch -t 202407292030.00 file.txt # Set the timestamp of 'file.txt' to July 29, 2024, 20:30:00"},

        {"Removing Files (`rm`)",
         "The `rm` command removes (deletes) files or directories. This operation is irreversible, so use it with caution. It's essential to understand the different options to avoid accidental data loss.",
         "Examples:\n  rm file.txt               # Remove the file named 'file.txt'\n  rm -i file.txt            # Prompt for confirmation before deleting the file\n  rm -r directory/         # Remove a directory and its contents recursively\n  rm -f file.txt            # Force delete the file, ignoring nonexistent files and without prompting\n  rm -rf directory/         # Force delete a directory and its contents without prompting"},

        {"Printing Working Directory (`pwd`)",
         "The `pwd` command prints the current working directory. It shows the full path to the directory you are currently in, helping you keep track of your location in the filesystem.",
         "Examples:\n  pwd                      # Print the full path of the current directory\n  pwd -L                   # Print the logical path (resolves symbolic links)\n  pwd -P                   # Print the physical path (without resolving symbolic links)"},

        {"Creating Directories (`mkdir`)",
         "The `mkdir` command creates a new directory. It's useful for organizing files into separate folders. Understanding how to create nested directories and set permissions is important for managing filesystem hierarchy.",
         "Examples:\n  mkdir new_directory        # Create a new directory named 'new_directory'\n  mkdir -p parent/child      # Create parent and child directories; the `-p` flag creates parent directories if they do not exist\n  mkdir -m 755 new_dir       # Create a directory with specific permissions (rwxr-xr-x)"},

        {"Copying Files (`cp`)",
         "The `cp` command copies files or directories from one location to another. It supports various options to handle different copying needs, such as recursive copying and interactive prompts.",
         "Examples:\n  cp file1.txt file2.txt     # Copy 'file1.txt' to 'file2.txt'\n  cp -r dir1/ dir2/          # Recursively copy directory 'dir1' to 'dir2'\n  cp -i file1.txt backup/    # Prompt before overwriting the file in 'backup/'\n  cp -u file1.txt destination/  # Copy only if 'file1.txt' is newer than the existing file in 'destination/'\n  cp -a source/ destination/  # Archive mode: Copy files and preserve attributes"},

        {"Moving and Renaming Files (`mv`)",
         "The `mv` command moves or renames files and directories. It’s used for relocating files or changing their names. It also handles overwriting scenarios based on provided options.",
         "Examples:\n  mv file1.txt /path/to/destination/     # Move 'file1.txt' to the specified directory\n  mv oldname.txt newname.txt             # Rename 'oldname.txt' to 'newname.txt'\n  mv -i file1.txt backup/                # Prompt before overwriting files in 'backup/'\n  mv -u file1.txt destination/           # Move only if 'file1.txt' is newer than the existing file in 'destination/'"},

        {"Viewing File Contents (`cat`)",
         "The `cat` command displays the contents of a file and can concatenate multiple files into one. It's useful for viewing short files and combining files.",
         "Examples:\n  cat file.txt                # Display the contents of 'file.txt'\n  cat file1.txt file2.txt     # Concatenate 'file1.txt' and 'file2.txt' and display the result\n  cat file.txt > newfile.txt  # Redirect the contents of 'file.txt' to 'newfile.txt'\n  cat file.txt | less         # View the contents of 'file.txt' page by page"},

        {"Changing File Permissions (`chmod`)",
         "The `chmod` command changes the permissions of files and directories. Understanding how to use symbolic and octal modes to set permissions is crucial for managing access control.",
         "Examples:\n  chmod 755 script.sh           # Set permissions to rwxr-xr-x for 'script.sh'\n  chmod u+x script.sh            # Add execute permission for the user on 'script.sh'\n  chmod go-rwx file.txt          # Remove all permissions for group and others on 'file.txt'\n  chmod 644 file.txt             # Set permissions to rw-r--r--"},

        {"Displaying Disk Usage (`du`)",
         "The `du` command shows the disk usage of files and directories. It helps in identifying large files or directories that consume disk space.",
         "Examples:\n  du -sh directory/             # Show the total disk usage of 'directory/' in a human-readable format\n  du -a                         # Show disk usage of all files and directories recursively\n  du -ch | grep total            # Show disk usage and find the total size\n  du -sh --max-depth=1          # Show disk usage of directories within 'directory/' up to 1 level deep"},

        {"Network Utilities (`netstat`, `ping`, `traceroute`)",
         "Network utilities provide tools for network diagnostics and monitoring. They help in troubleshooting network issues, monitoring network performance, and understanding network configurations.",
         "Examples:\n  netstat -tuln                 # List all listening ports and their associated services\n  ping google.com               # Send ICMP echo requests to 'google.com' and measure round-trip time\n  traceroute google.com         # Trace the path packets take to reach 'google.com'"},

        {"Searching for Files (`find`, `grep`)",
         "The `find` and `grep` commands search for files and content within files, respectively. They are powerful tools for locating files and patterns in large datasets.",
         "Examples:\n  find /path/to/search -name '*.txt'    # Find all '.txt' files in the specified path\n  find /path/to/search -type f -exec ls -lh {} \\;    # Find all files and list their details\n  grep 'pattern' file.txt                # Search for 'pattern' within 'file.txt'\n  grep -r 'pattern' /path/to/search      # Recursively search for 'pattern' in the specified path"},

        {"Downloading Files (`wget`, `curl`)",
         "The `wget` and `curl` commands download files from the internet. They support various protocols and provide options for resuming downloads, handling authentication, and more.",
         "Examples:\n  wget https://example.com/file.txt      # Download 'file.txt' from 'example.com'\n  wget -c https://example.com/file.txt   # Resume a previously interrupted download\n  curl -O https://example.com/file.txt   # Download 'file.txt' from 'example.com' and save it with the same name\n  curl -u user:password https://example.com/file.txt    # Download 'file.txt' with basic authentication"}
    };

    // Iterate through lessons and display them
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Define questions and answers
    struct {
        const char *question;
        const char *correct_answer;
    } questions[] = {
        {"What command lists the contents of a directory?", "ls"},
        {"How do you change to the home directory?", "cd ~"},
        {"What command is used to create a new file?", "touch"},
        {"How do you remove a file named 'file.txt'?", "rm file.txt"},
        {"What command prints the current working directory?", "pwd"},
        {"How do you create a directory named 'new_folder'?", "mkdir new_folder"},
        {"What command copies 'file1.txt' to 'file2.txt'?", "cp file1.txt file2.txt"},
        {"How do you move a file named 'file.txt' to '/path/to/destination/'?", "mv file.txt /path/to/destination/"},
        {"What command displays the contents of 'file.txt'?", "cat file.txt"},
        {"How do you change the permissions of 'script.sh' to rwxr-xr-x?", "chmod 755 script.sh"},
        {"What command shows the disk usage of 'directory/'?", "du -sh directory/"},
        {"What command lists all listening ports?", "netstat -tuln"},
        {"How do you find all '.txt' files in the specified path?", "find /path/to/search -name '*.txt'"},
        {"What command downloads 'file.txt' from 'example.com'?", "wget https://example.com/file.txt"}
    };

    // Iterate through questions and ask them
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(questions[i].question, questions[i].correct_answer);
    }

    printf("Congratulations! You have completed the Comprehensive Review and Advanced Concepts Dinner Challenge.\n");
    printf("Press Enter to finish...\n");
    getchar(); // Wait for user to press Enter

    return 0;
}
