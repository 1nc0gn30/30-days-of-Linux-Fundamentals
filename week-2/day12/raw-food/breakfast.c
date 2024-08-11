#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100
#define MAX_CHOICES 4

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
    const char *choices[MAX_CHOICES];
    int correct_index;
} Question;

void display_lesson(const Lesson *lesson) {
    printf(BOLD_COLOR BLUE_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf(CYAN_COLOR "%s\n" RESET_COLOR, lesson->description);
    printf(YELLOW_COLOR "Instructions: Open a separate terminal and try out the concepts described. Press Enter to continue after you've tried it.\n" RESET_COLOR);
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); 
    printf("\n");
}

void display_question(const Question *question) {
    char user_input[2];
    int user_choice;

    printf(BOLD_COLOR GREEN_COLOR "Question: %s\n" RESET_COLOR, question->question);
    
    // Display multiple choices
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%d) %s\n", i + 1, question->choices[i]);
    }

    // Get user's answer
    printf("Your choice (1-%d): ", MAX_CHOICES);
    fgets(user_input, sizeof(user_input), stdin);
    user_choice = atoi(user_input) - 1;

    // Check if the answer is correct
    if (user_choice == question->correct_index) {
        printf(GREEN_COLOR "Correct!\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %s\n" RESET_COLOR, question->choices[question->correct_index]);
    }
    printf("\n");
}

int main() {
    // Clear screen
    printf("\033[H\033[J");

    // Introduction
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 12 Breakfast!\n" RESET_COLOR);
    printf("In this session, we will explore the basics of the Linux Kernel.\n");
    printf("We will gain a comprehensive understanding of how the Linux Kernel functions.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "Introduction to the Linux Kernel",
            "The Linux kernel is the core component of the Linux operating system. It manages system resources, such as CPU, memory, and devices, and facilitates communication between hardware and software.\n"
            "Key responsibilities include:\n"
            "- Process management: Handles processes' creation, scheduling, and termination.\n"
            "- Memory management: Manages the allocation and deallocation of memory.\n"
            "- Device management: Interacts with hardware devices through device drivers.\n"
            "- File system management: Manages data storage, retrieval, and file system organization."
        },
        {
            "Kernel Architecture Overview",
            "The Linux kernel follows a monolithic architecture, where all essential functions are integrated into one large binary. This includes device drivers, file system management, network stack, and more.\n"
            "Advantages of this architecture:\n"
            "- Performance: Since all components run in the same address space, communication between them is faster.\n"
            "- Flexibility: Modular components like device drivers can be loaded and unloaded dynamically.\n"
            "Commands:\n"
            "- To view loaded kernel modules: `lsmod`\n"
            "- To load a kernel module: `sudo modprobe <module_name>`\n"
            "- To unload a kernel module: `sudo modprobe -r <module_name>`"
        },
        {
            "Kernel Space vs. User Space",
            "The operating system is divided into kernel space and user space. Kernel space is where the core kernel code runs, with full access to system resources, while user space is where applications run, with limited access.\n"
            "The separation ensures system stability and security. If a user space application crashes, it does not affect the kernel, but a crash in kernel space can bring down the entire system.\n"
            "Commands:\n"
            "- To view the current running processes: `ps aux`\n"
            "- To check kernel space activity: `dmesg`\n"
            "- To switch to a different user: `su <username>`"
        },
        {
            "Linux Kernel Modules",
            "Kernel modules are pieces of code that can be loaded and unloaded into the kernel dynamically, allowing the kernel to extend its capabilities without rebooting.\n"
            "For example, a device driver can be loaded as a module when the device is connected and unloaded when the device is removed.\n"
            "Commands:\n"
            "- To view information about a specific module: `modinfo <module_name>`\n"
            "- To load a module: `sudo modprobe <module_name>`\n"
            "- To remove a module: `sudo modprobe -r <module_name>`"
        },
        {
            "Understanding System Calls",
            "System calls are the primary interface between user space applications and the kernel. They allow applications to request services from the kernel, such as file operations, process control, and networking.\n"
            "Common system calls include:\n"
            "- `open`: Opens a file.\n"
            "- `read`: Reads data from a file.\n"
            "- `write`: Writes data to a file.\n"
            "- `close`: Closes a file.\n"
            "Commands:\n"
            "- To trace system calls made by a command: `strace <command>`\n"
            "- To list all available system calls: `man 2 syscall`"
        },
        {
            "Kernel Versioning",
            "The Linux kernel is continuously being updated with new features, improvements, and bug fixes. Each version is identified by a unique number, such as 5.10.16, where:\n"
            "- `5`: Major version\n"
            "- `10`: Minor version\n"
            "- `16`: Patch level\n"
            "Commands:\n"
            "- To check the current kernel version: `uname -r`\n"
            "- To view kernel release notes: Visit `https://kernel.org`"
        },
        {
            "Linux Kernel Development",
            "The Linux kernel is developed collaboratively by a large community of developers worldwide. Contributions are made in the form of patches, which are reviewed by maintainers before being accepted into the mainline kernel.\n"
            "Key components of kernel development:\n"
            "- `git`: Version control system used to manage kernel source code.\n"
            "- `patch`: Tool used to apply changes to the kernel source.\n"
            "- `make`: Tool used to compile the kernel.\n"
            "Commands:\n"
            "- To clone the Linux kernel source code: `git clone https://github.com/torvalds/linux.git`\n"
            "- To apply a patch: `patch -p1 < patch_file`\n"
            "- To compile the kernel: `make`"
        },
        {
            "Kernel Configuration and Compilation",
            "Before compiling the kernel, it must be configured to include the necessary features and support for hardware. This can be done using tools like `make menuconfig` or `make xconfig`.\n"
            "Steps:\n"
            "- Configure the kernel options: `make menuconfig`\n"
            "- Compile the kernel: `make`\n"
            "- Install the compiled kernel: `sudo make install`\n"
            "- Update the bootloader: `sudo update-grub`"
        },
        {
            "Kernel Boot Parameters",
            "Boot parameters are options passed to the Linux kernel at boot time to control its behavior. These parameters can enable or disable specific features, configure hardware settings, and more.\n"
            "Examples of boot parameters:\n"
            "- `quiet`: Suppresses most boot messages.\n"
            "- `nomodeset`: Disables kernel mode setting for graphics drivers.\n"
            "- `init=/bin/bash`: Boots directly into a bash shell instead of the usual init process.\n"
            "Commands:\n"
            "- To edit boot parameters: Press `e` at the GRUB menu and modify the `linux` line.\n"
            "- To apply changes permanently: Edit `/etc/default/grub` and run `sudo update-grub`."
        },
        {
            "Kernel Panic and Debugging",
            "A kernel panic is an action taken by the Linux kernel when it encounters a critical error from which it cannot recover. Understanding kernel panics and debugging them is crucial for system stability.\n"
            "Common causes of kernel panics:\n"
            "- Hardware failure: Memory corruption, disk errors, etc.\n"
            "- Software bugs: Kernel bugs, incompatible modules, etc.\n"
            "- Misconfiguration: Incorrect kernel parameters, faulty drivers, etc.\n"
            "Commands:\n"
            "- To view kernel panic logs: `dmesg` or check `/var/log/kern.log`\n"
            "- To force a kernel panic for testing: `echo c > /proc/sysrq-trigger`\n"
            "- To enable kernel crash dumps: `kdump` configuration is required."
        }
    };

    // Questions
    Question questions[] = {
        {
            "What is the primary function of the Linux kernel?",
            {"Managing system resources", "User interface management", "Web server management", "Database management"},
            0
        },
        {
            "Which architecture does the Linux kernel follow?",
            {"Microkernel", "Monolithic", "Hybrid", "Exokernel"},
            1
        },
        {
            "What is the difference between kernel space and user space?",
            {"Kernel space has restricted access", "User space has full access", "Kernel space has full access", "User space runs the kernel"},
            2
        },
        {
            "What are Linux kernel modules?",
            {"Kernel extensions", "System logs", "Application programs", "Memory segments"},
            0
        },
        {
            "How do user applications interact with the Linux kernel?",
            {"Through direct access", "Through system calls", "Through device drivers", "Through the command line"},
            1
        },
        {
            "What does the Linux kernel version number represent?",
            {"Major, minor, and patch levels", "Build date and time", "CPU architecture", "License type"},
            0
        },
        {
            "How is the Linux kernel developed?",
            {"By a single company", "By individual users", "By a large community of developers", "By proprietary organizations"},
            2
        },
        {
            "What is the purpose of 'make menuconfig' in kernel development?",
            {"To compile the kernel", "To update the system", "To configure kernel options", "To monitor kernel logs"},
            2
        },
        {
            "What are kernel boot parameters used for?",
            {"To control the bootloader", "To manage user sessions", "To control kernel behavior at boot time", "To install kernel updates"},
            2
        },
        {
            "What is a kernel panic?",
            {"A performance monitoring tool", "A safety measure for critical errors", "A memory management technique", "A process scheduling algorithm"},
            1
        }
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
