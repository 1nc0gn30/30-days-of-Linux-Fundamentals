#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

typedef struct {
    const char *topic;
    const char *description;
} Lesson;

typedef struct {
    const char *question; 
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf("\n\033[1mLesson: %s\033[0m\n", lesson->topic);
    printf("%s\n\n", lesson->description);
    printf("Instructions: Open a separate terminal and type the command described above.\n");
    printf("Press Enter to continue after you've tried it...");
    getchar();
    printf("\033[H\033[J"); // Clear the screen
}

void display_question(const Question *question) {
    char user_answer[MAX_ANSWER_LENGTH];
    
    printf("\033[1mQuestion:\033[0m %s\n", question->question);
    printf("Your answer: ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;  // Remove the newline character

    if (strcasecmp(user_answer, question->correct_answer) == 0) {
        printf("\033[1;32mCorrect!\033[0m\n\n");
    } else {
        printf("\033[1;31mIncorrect.\033[0m The correct answer is: \033[1m%s\033[0m\n\n", question->correct_answer);
    }
    printf("Press Enter to continue...");
    getchar();
    printf("\033[H\033[J"); // Clear the screen
}

int main () {
    printf("\033[H\033[J"); // Clear the screen
    
    printf("\033[1mWelcome to Day 10 Lunch!\033[0m\n");
    printf("In this session, we will explore \033[1mRemote Access and Management\033[0m, and \033[1mSystem Recovery and Rescue\033[0m.\n");
    printf("We will gain an understanding of important commands and techniques to manage and recover Linux systems.\n");
    printf("Press Enter to start...\n");
    getchar();

    Lesson lessons[] = {
        {
            "Remote Access with SSH",
            "Secure Shell (SSH) is a protocol for securely accessing and managing a remote server. "
            "The basic syntax to connect to a remote server is:\n\n"
            "ssh username@remote_host\n\n"
            "For example, to connect to a remote server with the IP address 192.168.1.10 "
            "as the user 'admin', use the command:\n\n"
            "ssh admin@192.168.1.10\n"
        },
        {
            "Copying Files with SCP",
            "The Secure Copy Protocol (SCP) allows you to securely transfer files between hosts over SSH.\n\n"
            "To copy a file from your local machine to a remote server:\n\n"
            "scp localfile.txt username@remote_host:/path/to/destination\n\n"
            "To copy a file from a remote server to your local machine:\n\n"
            "scp username@remote_host:/path/to/file localfile.txt\n"
        },
        {
            "Monitoring Remote Systems with SSH",
            "You can execute commands on a remote system over SSH to monitor or manage it.\n\n"
            "For example, to check the disk usage on a remote server:\n\n"
            "ssh username@remote_host 'df -h'\n\n"
            "Or to view the running processes:\n\n"
            "ssh username@remote_host 'top -b -n 1'\n"
        },
        {
            "Remote File System Mounting with SSHFS",
            "SSHFS (SSH File System) allows you to mount a remote filesystem locally using SSH.\n\n"
            "To mount a remote directory:\n\n"
            "sshfs username@remote_host:/remote/path /local/mountpoint\n\n"
            "To unmount the directory:\n\n"
            "fusermount -u /local/mountpoint\n"
        },
        {
            "Rescue Mode and Single-User Mode",
            "Rescue mode is a way to boot your system with minimal services to troubleshoot issues. "
            "Single-user mode is a similar mode used primarily for maintenance.\n\n"
            "To boot into single-user mode, you can edit the GRUB boot menu and add 'single' or 'rescue' "
            "to the boot parameters.\n"
        },
        {
            "Resetting the Root Password",
            "If you lose the root password, you can reset it by booting into single-user mode.\n\n"
            "Once in single-user mode, use the 'passwd' command to reset the root password:\n\n"
            "passwd\n\n"
            "Enter and confirm the new password when prompted.\n"
        },
        {
            "Recovering Deleted Files with extundelete",
            "extundelete is a utility that can recover deleted files from ext3/ext4 filesystems.\n\n"
            "To recover a deleted file, run:\n\n"
            "extundelete /dev/sdX --restore-file /path/to/deleted/file\n\n"
            "Replace /dev/sdX with the appropriate device identifier and specify the path to the file.\n"
        },
        {
            "Using `chroot` for System Repair",
            "The `chroot` command changes the apparent root directory for a process, useful in system recovery.\n\n"
            "For example, if you need to repair a system from a live CD:\n\n"
            "1. Mount the filesystem:\n"
            "   mount /dev/sdX1 /mnt\n\n"
            "2. Change root to the mounted system:\n"
            "   chroot /mnt\n\n"
            "Now you can run commands as if you were on the original system.\n"
        },
        {
            "Reinstalling GRUB Bootloader",
            "If the GRUB bootloader is corrupted, you can reinstall it using a live CD or rescue mode.\n\n"
            "1. Boot into a live environment.\n"
            "2. Mount the root filesystem:\n"
            "   mount /dev/sdX1 /mnt\n\n"
            "3. Reinstall GRUB:\n"
            "   grub-install --root-directory=/mnt /dev/sdX\n"
        },
        {
            "System Rescue with dd",
            "The dd command can be used for low-level copying and backup, useful in rescue scenarios.\n"
            "For example, to create a disk image:\n\n"
            "dd if=/dev/sdX of=/path/to/backup.img\n\n"
            "To restore the image:\n\n"
            "dd if=/path/to/backup.img of=/dev/sdX\n"
        }
    };

    Question questions[] = {
        {"What command would you use to securely connect to a remote server as user 'john'?", "ssh john@remote_host"},
        {"How do you copy a file named 'report.txt' to a remote server at '/home/user/' using SCP?", "scp report.txt user@remote_host:/home/user/"},
        {"What is the command to display disk usage on a remote server using SSH?", "ssh user@remote_host 'df -h'"},
        {"How can you mount a remote directory '/data' to '/mnt/remote_data' using SSHFS?", "sshfs user@remote_host:/data /mnt/remote_data"},
        {"Which boot parameter would you add to GRUB to boot into single-user mode?", "single"},
        {"What command is used to reset the root password after booting into single-user mode?", "passwd"},
        {"How would you recover a deleted file '/home/user/document.txt' using extundelete?", "extundelete /dev/sdX --restore-file /home/user/document.txt"},
        {"Which command changes the root directory to '/mnt' for system repair?", "chroot /mnt"},
        {"How do you reinstall GRUB to the first disk after booting from a live CD?", "grub-install --root-directory=/mnt /dev/sdX"},
        {"What `dd` command would you use to create a backup image of a disk '/dev/sda'?", "dd if=/dev/sda of=/path/to/backup.img"}
    };

    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    printf("\033[1mNow let's test your knowledge with some questions:\033[0m\n\n");
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    printf("Congratulations! You've completed the Day 10 Lunch session.\n");

    return 0;
}
