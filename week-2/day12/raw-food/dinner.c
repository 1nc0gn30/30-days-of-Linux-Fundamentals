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
    const char *options[4];
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
        printf("%d. %s\n", i + 1, question->options[i]);
    }
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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 12 Dinner!\n" RESET_COLOR);
    printf("In this session, we will explore advanced Linux Kernel topics.\n");
    printf("Topics include kernel debugging, security, patching, and more.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "Introduction to Kernel Debugging",
            "Kernel debugging is essential for diagnosing and fixing issues within the Linux kernel.\n"
            "Key Tools:\n"
            "1. kgdb: A debugger for the Linux kernel.\n"
            "   - To start debugging: `gdb vmlinux`.\n"
            "   - Connect to the kernel: `target remote /dev/ttyS0`.\n"
            "2. kdump: A crash dumping mechanism.\n"
            "   - To configure: Edit /etc/default/grub and add `crashkernel=128M`.\n"
            "   - To test: `echo c > /proc/sysrq-trigger`.\n"
            "3. ftrace: A tracing utility for debugging kernel performance issues.\n"
            "   - To start tracing: `echo function > /sys/kernel/debug/tracing/current_tracer`.\n"
            "   - To view trace output: `cat /sys/kernel/debug/tracing/trace`."
        },
        {
            "Using kgdb for Kernel Debugging",
            "kgdb allows you to debug a running kernel using gdb.\n"
            "Setup Steps:\n"
            "1. Compile the kernel with debugging symbols enabled by adding `CONFIG_KGDB=y` to your kernel configuration.\n"
            "2. Use a serial or network connection to connect your debugger to the kernel.\n"
            "3. Launch gdb: `gdb vmlinux`.\n"
            "4. Connect gdb to kgdb: `target remote /dev/ttyS0`.\n"
            "5. Set breakpoints and inspect the kernel state as needed."
        },
        {
            "Understanding Kernel Crash Dumps with kdump",
            "kdump captures the contents of the kernel's memory after a crash, allowing for post-mortem analysis.\n"
            "Configuration Steps:\n"
            "1. Install kexec-tools: `sudo apt-get install kexec-tools`.\n"
            "2. Configure the crashkernel parameter in GRUB by editing /etc/default/grub and adding `crashkernel=128M`.\n"
            "3. Update GRUB: `sudo update-grub`.\n"
            "4. Test kdump by triggering a crash: `echo c > /proc/sysrq-trigger`."
        },
        {
            "Using ftrace for Kernel Tracing",
            "ftrace is a powerful tracing framework for analyzing kernel performance and behavior.\n"
            "Commands:\n"
            "1. Enable function tracing: `echo function > /sys/kernel/debug/tracing/current_tracer`.\n"
            "2. View trace output: `cat /sys/kernel/debug/tracing/trace`.\n"
            "3. Stop tracing: `echo > /sys/kernel/debug/tracing/trace`.\n"
            "4. Set up tracepoints: `echo 'tracepoint_name' > /sys/kernel/debug/tracing/set_ftrace_filter`."
        },
        {
            "Kernel Security Enhancements",
            "The Linux kernel includes several security features to protect the system from vulnerabilities.\n"
            "Security Features:\n"
            "1. SELinux: Enforces security policies at the kernel level.\n"
            "   - Check status: `sestatus`.\n"
            "   - Modify settings: Edit /etc/selinux/config.\n"
            "2. AppArmor: Similar to SELinux but with different implementations.\n"
            "   - Check status: `sudo aa-status`.\n"
            "3. seccomp: Restricts the system calls a process can make.\n"
            "   - Set up filters: Use `prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT)` in your code."
        },
        {
            "Configuring SELinux",
            "SELinux (Security-Enhanced Linux) is a security module that provides mandatory access control (MAC) to enforce security policies.\n"
            "Commands:\n"
            "1. Check SELinux status: `sestatus`.\n"
            "2. Enable or disable SELinux: Edit /etc/selinux/config and set SELINUX=enforcing or SELINUX=permissive.\n"
            "3. Troubleshoot issues: Use `ausearch -m avc` to search for access vector cache messages and `semanage` to manage policies."
        },
        {
            "Applying Kernel Patches",
            "Kernel patches are updates that fix bugs, close security vulnerabilities, or add features.\n"
            "Steps to Apply a Patch:\n"
            "1. Download the patch from kernel.org or another trusted source.\n"
            "2. Apply the patch: `patch -p1 < patch_file`.\n"
            "3. Rebuild the kernel: `make -j $(nproc)`.\n"
            "4. Install the new kernel: `sudo make modules_install && sudo make install`.\n"
            "5. Update the bootloader: `sudo update-grub`."
        },
        {
            "Kernel Live Patching",
            "Live patching allows you to apply kernel patches without rebooting the system.\n"
            "Tools:\n"
            "1. kpatch: A utility for live kernel patching.\n"
            "   - Install kpatch: `sudo yum install kpatch`.\n"
            "   - Apply a patch: `kpatch load patch_file`.\n"
            "2. kGraft: Another live patching solution.\n"
            "3. Canonical's livepatch service: Provides live kernel updates for Ubuntu.\n"
            "   - Enable: `sudo apt-get install ubuntu-livepatch`."
        },
        {
            "Understanding Kernel Locking Mechanisms",
            "Kernel locking mechanisms are used to prevent race conditions and ensure data consistency within the kernel.\n"
            "Types of Locks:\n"
            "1. Spinlocks: Busy-wait locks used in interrupt contexts.\n"
            "   - Acquire: `spin_lock(&lock)`.\n"
            "   - Release: `spin_unlock(&lock)`.\n"
            "2. Mutexes: Sleep-based locks used in process contexts.\n"
            "   - Acquire: `mutex_lock(&mutex)`.\n"
            "   - Release: `mutex_unlock(&mutex)`.\n"
            "3. Read-write locks: Allow multiple readers or a single writer.\n"
            "   - Acquire read lock: `read_lock(&rwlock)`.\n"
            "   - Release read lock: `read_unlock(&rwlock)`.\n"
            "   - Acquire write lock: `write_lock(&rwlock)`.\n"
            "   - Release write lock: `write_unlock(&rwlock)`."
        },
        {
            "Managing Kernel Threads",
            "Kernel threads perform background tasks within the kernel and can be managed through various commands.\n"
            "Commands:\n"
            "1. View kernel threads: `ps -eLf`.\n"
            "2. Create a kernel thread: Use the `kthread_create` function in kernel code.\n"
            "   - Example: `struct task_struct *task = kthread_create(function, data, 'name');`\n"
            "3. Start a kernel thread: `wake_up_process(task)`.\n"
            "4. Stop a kernel thread: Use the `kthread_stop` function in kernel code.\n"
            "   - Example: `kthread_stop(task);`."
        }
    };

    // Questions
    Question questions[] = {
        {
            "Which tool is used for debugging the Linux kernel?",
            {"kgdb", "gdb", "strace", "lsof"},
            "kgdb"
        },
        {
            "What is the purpose of kdump?",
            {"To capture the contents of the kernel's memory after a crash", "To monitor CPU usage", "To manage kernel modules", "To apply live kernel patches"},
            "To capture the contents of the kernel's memory after a crash"
        },
        {
            "How do you enable function tracing with ftrace?",
            {"echo function > /sys/kernel/debug/tracing/current_tracer", "echo 'trace' > /sys/kernel/debug/tracing/trace", "echo start > /sys/kernel/debug/tracing/start_tracing", "echo enable > /sys/kernel/debug/tracing/enable"},
            "echo function > /sys/kernel/debug/tracing/current_tracer"
        },
        {
            "Which command checks the status of SELinux?",
            {"sestatus", "getenforce", "aa-status", "semanage status"},
            "sestatus"
        },
        {
            "How do you apply a kernel patch?",
            {"patch -p1 < patch_file", "make -j $(nproc)", "update-grub", "apt-get upgrade linux-image"},
            "patch -p1 < patch_file"
        },
        {
            "What is live kernel patching?",
            {"Applying kernel patches without rebooting the system", "Patching the kernel during boot", "Installing security updates", "Updating kernel modules"},
            "Applying kernel patches without rebooting the system"
        },
        {
            "What is a spinlock?",
            {"A busy-wait lock used in interrupt contexts", "A sleep-based lock used in process contexts", "A lock for read-write operations", "A type of kernel thread"},
            "A busy-wait lock used in interrupt contexts"
        },
        {
            "How do you view kernel threads?",
            {"ps -eLf", "top", "vmstat", "dmesg"},
            "ps -eLf"
        },
        {
            "What is the purpose of SELinux?",
            {"To enforce mandatory access control (MAC) security policies", "To manage kernel modules", "To monitor network traffic", "To handle system calls"},
            "To enforce mandatory access control (MAC) security policies"
        },
        {
            "Which utility is used for live kernel patching on Linux?",
            {"kpatch", "patch", "kexec", "kdump"},
            "kpatch"
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
