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
    const char *commands;
} Lesson;

// Question structure
typedef struct {
    const char *question;
    const char *options[4];
    const char *correct_answer;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    if (lesson->commands) {
        printf(BOLD_COLOR YELLOW_COLOR "Try these commands in a separate terminal:\n" RESET_COLOR);
        printf(BOLD_COLOR GREEN_COLOR "%s\n" RESET_COLOR, lesson->commands);
    }
    printf(YELLOW_COLOR "Instructions: After trying out the commands, press Enter to continue.\n" RESET_COLOR);
    getchar();
    printf("\n");
}

void display_question(const Question *question) {
    printf(BOLD_COLOR GREEN_COLOR "Question: %s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, question->options[i]);
    }

    char user_answer[MAX_ANSWER_LENGTH];
    printf("Your answer (1-4): ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    int answer_index = atoi(user_answer) - 1;

    if (answer_index >= 0 && answer_index < 4 && strcmp(question->options[answer_index], question->correct_answer) == 0) {
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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 12 Lunch!\n" RESET_COLOR);
    printf("In this session, we will dive deeper into Linux Kernel Basics.\n");
    printf("We will cover kernel modules, kernel parameters, and kernel versioning.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "Understanding Kernel Modules",
            "Kernel modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system. For example, drivers for hardware components are often implemented as modules, allowing them to be loaded when the hardware is present and unloaded when not needed.\n\n"
            "Detailed steps:\n"
            "1. To view loaded modules, use `lsmod`.\n"
            "2. To load a module, use `sudo modprobe module_name`. This command dynamically loads a module into the running kernel.\n"
            "3. To unload a module, use `sudo modprobe -r module_name`.\n"
            "4. Check if a module supports a particular device with `modinfo module_name`.",
            "lsmod\nsudo modprobe module_name\nsudo modprobe -r module_name\nmodinfo module_name"
        },
        {
            "Building and Installing Kernel Modules",
            "Kernel modules can be custom-built to add specific features to the kernel. This involves writing a module in C, compiling it, and then loading it into the kernel.\n\n"
            "Steps:\n"
            "1. Write a simple kernel module in C.\n"
            "2. Compile the module using the kernel's build system: `make -C /lib/modules/$(uname -r)/build M=$(pwd) modules`.\n"
            "3. Load the module with `sudo insmod module_name.ko`.\n"
            "4. Remove the module with `sudo rmmod module_name`.",
            "make -C /lib/modules/$(uname -r)/build M=$(pwd) modules\nsudo insmod module_name.ko\nsudo rmmod module_name"
        },
        {
            "Kernel Parameters and Sysctl",
            "Kernel parameters control the operation of the kernel at runtime. They can be set at boot time or modified on the fly using the sysctl command. This is useful for tuning system performance and behavior without needing to reboot.\n\n"
            "Common parameters include:\n"
            "- `fs.file-max`: The maximum number of open file descriptors.\n"
            "- `kernel.pid_max`: The maximum number of process IDs.\n"
            "- `vm.swappiness`: Controls the tendency of the kernel to swap out process memory.\n"
            "To make changes persistent, modify `/etc/sysctl.conf` and then run `sudo sysctl -p`.",
            "sysctl -a\nsudo sysctl -w parameter=value\nsudo sysctl -p"
        },
        {
            "Tuning Kernel Parameters for Performance",
            "Certain kernel parameters can be tuned for better system performance based on your workload. This includes adjusting memory usage, process management, and network settings.\n\n"
            "Examples:\n"
            "1. To change the maximum number of open file descriptors: `sudo sysctl -w fs.file-max=100000`.\n"
            "2. To change the maximum number of user processes: `sudo sysctl -w kernel.pid_max=65536`.\n"
            "3. To adjust the swappiness value, which influences how aggressively the kernel swaps memory: `sudo sysctl -w vm.swappiness=10`.",
            "sudo sysctl -w fs.file-max=100000\nsudo sysctl -w kernel.pid_max=65536\nsudo sysctl -w vm.swappiness=10"
        },
        {
            "Kernel Versioning and Upgrades",
            "The Linux kernel follows a strict versioning system to track changes and updates. Each version is represented by a major, minor, and patch number (e.g., 5.10.16).\n\n"
            "Steps to manage kernel versions:\n"
            "1. Check the current kernel version with `uname -r`.\n"
            "2. Upgrade the kernel on a Debian-based system using `sudo apt-get install linux-image-new_version`.\n"
            "3. Manage multiple kernel versions by editing the GRUB configuration: `sudo update-grub`.",
            "uname -r\nsudo apt-get install linux-image-new_version\nsudo update-grub"
        },
        {
            "Using the dmesg Command",
            "The `dmesg` command is used to view the kernel's ring buffer, which contains messages related to hardware and system events. These messages are crucial for debugging hardware issues or tracking system events after boot.\n\n"
            "Commands to explore:\n"
            "1. View the entire kernel message buffer: `dmesg`.\n"
            "2. Filter messages for specific keywords: `dmesg | grep keyword`.\n"
            "3. Clear the message buffer: `sudo dmesg -C`.",
            "dmesg\ndmesg | grep keyword\nsudo dmesg -C"
        },
        {
            "Configuring the GRUB Bootloader",
            "GRUB (Grand Unified Bootloader) is responsible for loading the Linux kernel at boot time. You can configure GRUB to control which kernel version is booted by default, pass boot parameters to the kernel, and more.\n\n"
            "Steps:\n"
            "1. Update GRUB after installing a new kernel: `sudo update-grub`.\n"
            "2. Set the default kernel version in `/etc/default/grub` by editing the `GRUB_DEFAULT` parameter.\n"
            "3. Apply changes by running `sudo update-grub`.",
            "sudo update-grub\nsudo nano /etc/default/grub\nsudo update-grub"
        },
        {
            "Understanding Kernel Oops and Panics",
            "A kernel oops is an error that the kernel encounters but can recover from, while a kernel panic is a more severe error that causes the system to halt. Understanding these errors is crucial for system stability.\n\n"
            "Logs and troubleshooting:\n"
            "1. View kernel oops and panic logs in `/var/log/syslog` or `/var/log/kern.log`.\n"
            "2. Force a kernel panic for testing: `echo c > /proc/sysrq-trigger` (use with caution).\n"
            "3. Enable kernel crash dumps using `kdump` for detailed debugging information.",
            "dmesg\ncat /var/log/kern.log\necho c > /proc/sysrq-trigger"
        },
        {
            "Monitoring Kernel Activity",
            "Monitoring kernel activity helps in understanding the system's performance and detecting any issues. Various tools are available for monitoring different aspects of the kernel.\n\n"
            "Tools to use:\n"
                        "1. Monitor CPU activity: `top` or `htop`.\n"
            "2. Monitor disk activity: `iostat`.\n"
            "3. Monitor network activity: `iftop` or `nload`.\n"
            "4. For detailed process monitoring: `ps aux`.",
            "top\nhtop\niostat\niftop\nnload\nps aux"
        },
        {
            "Custom Kernel Compilation",
            "Compiling a custom kernel allows you to tailor the kernel to your specific hardware and software needs. This is an advanced topic and requires a good understanding of kernel configuration and compilation.\n\n"
            "Steps to compile a custom kernel:\n"
            "1. Download the kernel source code from `kernel.org`.\n"
            "2. Extract the source code and navigate to the directory: `tar -xvf linux-x.y.z.tar.xz && cd linux-x.y.z`.\n"
            "3. Configure the kernel using `make menuconfig` to select features and options.\n"
            "4. Compile the kernel using `make -j $(nproc)`.\n"
            "5. Install the new kernel: `sudo make modules_install && sudo make install`.\n"
            "6. Update the bootloader configuration: `sudo update-grub`.",
            "wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.x.y.tar.xz\ntar -xvf linux-5.x.y.tar.xz\ncd linux-5.x.y\nmake menuconfig\nmake -j $(nproc)\nsudo make modules_install\nsudo make install\nsudo update-grub"
        }
    };

    // Questions
    Question questions[] = {
        {
            "What command lists the currently loaded kernel modules?",
            {"lsmod", "modinfo module_name", "sudo modprobe module_name", "dmesg"},
            "lsmod"
        },
        {
            "How do you compile a kernel module?",
            {"make -C /lib/modules/$(uname -r)/build M=$(pwd) modules", "sudo make modules", "gcc -o module module.c", "make clean"},
            "make -C /lib/modules/$(uname -r)/build M=$(pwd) modules"
        },
        {
            "Which command modifies a kernel parameter on the fly?",
            {"sysctl -a", "sudo sysctl -w parameter=value", "echo parameter=value > /proc/sys/parameter", "cat /proc/sys/parameter"},
            "sudo sysctl -w parameter=value"
        },
        {
            "How can you check the current kernel version?",
            {"uname -r", "ls /boot", "cat /proc/version", "dmesg | grep 'Linux version'"},
            "uname -r"
        },
        {
            "What does the dmesg command do?",
            {"It prints the kernel's ring buffer messages", "It lists all kernel modules", "It shows kernel parameters", "It updates the GRUB configuration"},
            "It prints the kernel's ring buffer messages"
        },
        {
            "How do you update the GRUB configuration?",
            {"sudo update-grub", "sudo grub-mkconfig", "sudo grub-install", "sudo grub-update"},
            "sudo update-grub"
        },
        {
            "Where are kernel oops logs usually found?",
            {"/var/log/syslog or /var/log/kern.log", "/var/log/messages", "/var/log/kernel.log", "/var/log/oops.log"},
            "/var/log/syslog or /var/log/kern.log"
        },
        {
            "Which command monitors CPU activity?",
            {"top or htop", "iostat", "iftop", "vmstat"},
            "top or htop"
        },
        {
            "Where can you download the Linux kernel source code?",
            {"kernel.org", "sourceforge.net", "github.com", "linux.org"},
            "kernel.org"
        },
        {
            "What is a kernel module?",
            {"A piece of code that can be loaded and unloaded into the kernel on demand", "A configuration file for the kernel", "A hardware component of the kernel", "A special type of kernel parameter"},
            "A piece of code that can be loaded and unloaded into the kernel on demand"
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Display questions
    printf(BOLD_COLOR "Now let's test your knowledge with some multiple-choice questions:\n" RESET_COLOR);
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        display_question(&questions[i]);
    }

    return 0;
}

