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

    // Convert the answer to uppercase for comparison
    if (user_answer[0] >= 'a' && user_answer[0] <= 'd') {
        user_answer[0] -= 32; // Convert to uppercase
    }

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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 14 breakfast!\n" RESET_COLOR);
    printf("In this session, we will review key topics covered in Week 2.\n");
    printf("We will revisit advanced shell scripting, filesystem management, kernel basics, and more.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
    {
        "Advanced Shell Scripting",
        "In this module, we explored advanced techniques in shell scripting to enhance automation. We delved into the use of loops (`for`, `while`, `until`) for automating repetitive tasks, which is crucial in systems administration. Functions were introduced to modularize scripts, making them more organized and easier to maintain. For example, defining a function to check disk space can be reused across multiple scripts.\n\n"
        "We also covered regular expressions, which are powerful for text processing and extracting data from logs. Understanding and using tools like `sed`, `awk`, and `grep` within scripts enables complex data manipulation. For instance, using `grep` with regular expressions to filter log entries or `awk` to format output data. Error handling with conditional statements (`if`, `else`, `elif`) and debugging techniques (`set -x`, `trap`) were also emphasized to ensure scripts run reliably in different environments."
    },
    {
        "Linux Filesystem Management",
        "This lesson focused on the crucial aspects of managing Linux filesystems. We covered mounting and unmounting filesystems, understanding how the `mount` command works, and the significance of the `/etc/fstab` file for persistent mounts. Users practiced checking filesystem integrity using the `fsck` command, which is essential for diagnosing and repairing filesystem issues.\n\n"
        "We also explored different filesystem types like ext4, XFS, and Btrfs, discussing their use cases and performance implications. Understanding the Linux Filesystem Hierarchy Standard (FHS) helped in navigating and managing the directory structure. Examples included creating and resizing partitions using `fdisk` and `parted`, managing disk quotas to allocate disk space efficiently, and optimizing filesystem performance using `tune2fs` and other tools."
    },
    {
        "Linux Kernel Basics",
        "The Linux kernel is the core component of the operating system, and understanding its operations is key for any system administrator. We covered how to manage kernel modules using `modprobe` to load and unload modules dynamically. This is useful for adding hardware support or network drivers without rebooting the system. For instance, loading a new network driver can be done using `modprobe <module_name>`.\n\n"
        "We also discussed modifying kernel parameters using the `sysctl` command, which allows runtime configuration of the kernel without the need to edit system files directly. Understanding kernel versioning through `uname -r` was crucial for knowing which kernel version is in use, especially when applying patches or updates. Additionally, the lesson covered the role of `initramfs` in the boot process and how to compile custom kernels, providing flexibility for specialized tasks or hardware support."
    },
    {
        "Advanced Network Configuration",
        "This lesson delved into the complexities of network configuration on Linux systems. We explored both static and dynamic IP configurations, learning how to configure network interfaces manually through `/etc/network/interfaces` or using `nmcli` for NetworkManager-controlled systems. Configuring DHCP servers and clients was also covered, with examples of setting up a DHCP server using `isc-dhcp-server`.\n\n"
        "We discussed network interface bonding, which is a technique to combine multiple network interfaces to increase bandwidth or provide redundancy. The `ifenslave` tool was introduced for this purpose, with examples of configuring active-backup and load-balancing modes. Additionally, we covered network performance optimization techniques, such as adjusting TCP window sizes with `sysctl` settings, and introduced advanced troubleshooting tools like `tcpdump` for packet analysis and `netstat` for monitoring network connections."
    },
    {
        "System Administration Best Practices",
        "Effective system administration requires adhering to best practices, and this lesson provided a comprehensive overview. We started with system monitoring tools like `top`, `htop`, and `vmstat`, emphasizing the importance of regular monitoring to detect and resolve performance issues. Practical exercises included using these tools to monitor CPU, memory, and I/O performance in real-time.\n\n"
        "Backup and recovery strategies were also discussed, with hands-on practice using `rsync` for incremental backups, `tar` for archiving files, and `dd` for creating disk images. Security best practices were emphasized, including regular updates, user management, and the use of firewalls like `ufw` or `iptables`. The lesson also highlighted the importance of documentation, scripting for automation, and ongoing education to stay current with evolving technologies and threats."
    }
};

    // Questions
    Question questions[] = {
    {"What command is used to check filesystem integrity?", {"fsck", "top", "uname", "tar"}, "fsck"},
    {"Which tool is used to load kernel modules?", {"modprobe", "lsmod", "top", "htop"}, "modprobe"},
    {"How do you bond network interfaces?", {"ifenslave", "top", "uname", "vmstat"}, "ifenslave"},
    {"Which command is used to monitor system performance?", {"top", "tar", "cp", "chmod"}, "top"},
    {"Which command creates a backup using rsync?", {"rsync -avz /source/ /destination/", "cp /source/ /destination/", "tar -cvf /source/ /destination/", "dd if=/source/ of=/destination/"}, "rsync -avz /source/ /destination/"},
    {"What is the purpose of the /etc/fstab file?", {"To define filesystems to be mounted at boot", "To list all installed packages", "To configure network interfaces", "To manage user accounts"}, "To define filesystems to be mounted at boot"},
    {"Which command is used to create a partition on a disk?", {"fdisk", "fsck", "dd", "tar"}, "fdisk"},
    {"What command displays kernel version information?", {"uname -r", "top", "modprobe", "lsmod"}, "uname -r"},
    {"How do you apply a runtime kernel parameter?", {"sysctl -w <parameter>=<value>", "echo <parameter> > /proc/sys/<parameter>", "modprobe <module>", "update-grub"}, "sysctl -w <parameter>=<value>"}
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

