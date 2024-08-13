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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 14 Lunch!\n" RESET_COLOR);
    printf("In this session, we will continue reviewing key topics covered in Week 2.\n");
    printf("We will dive deeper into shell scripting, kernel management, network configuration, and system administration best practices.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
    {
        "Shell Scripting Techniques (Advanced)",
        "This lesson builds on your previous scripting knowledge, diving into advanced concepts that can significantly enhance your scripts. We explore process control using commands like `wait`, `trap`, and `disown` to manage background jobs and signals effectively. Understanding file descriptors is key for redirecting output and errors to different destinations using `>&`, `2>&1`, and other redirection operators. Signal handling allows your scripts to respond to system signals, ensuring proper cleanup or action when they receive signals like `SIGINT` or `SIGTERM`.\n\n"
        "Examples include creating scripts that monitor and control long-running processes, handling errors gracefully, and ensuring your scripts are robust even in unexpected situations. Practicing with signals and redirection will make your scripts more reliable and flexible in real-world scenarios."
    },
    {
        "Kernel Management",
        "Interacting with the Linux kernel is a critical skill for system administrators. This lesson covers how to manage kernel modules dynamically using `modprobe` and `rmmod`, allowing you to add or remove functionality without rebooting the system. Understanding how to view and modify kernel parameters at runtime using `sysctl` is also crucial. For example, you might need to adjust network settings or change security parameters on the fly to meet specific requirements.\n\n"
        "We also cover managing kernel versions, including how to identify your current kernel version with `uname -r` and the steps required to upgrade or downgrade your kernel. The lesson provides examples of compiling custom kernels and configuring `GRUB` to boot into different kernel versions, ensuring you're prepared for advanced system customization."
    },
    {
        "Network Configuration (Advanced)",
        "This lesson takes your network configuration skills to the next level by focusing on complex IP configurations, static routes, and VLAN management. Configuring static routes using the `ip route add` command allows you to control the path packets take through a network, which is essential in multi-homed systems or when managing traffic across different networks. VLAN management using tools like `vconfig` enables segmentation of network traffic for better security and performance.\n\n"
        "Practical exercises include setting up and testing static routes, configuring VLANs on network interfaces, and understanding how these configurations affect network traffic and security. This knowledge is critical for managing large or complex network environments where precise control over routing and segmentation is required."
    },
    {
        "System Security Enhancements",
        "System security is paramount, and this lesson introduces additional measures to harden your Linux environment. We explore SELinux and AppArmor, two mandatory access control (MAC) systems that enforce security policies at the kernel level. You'll learn how to manage SELinux policies using `semanage` and `setsebool`, and how to troubleshoot security issues with `audit2why`. Similarly, AppArmor's profiles can be adjusted using `aa-complain` and `aa-enforce`, helping you control application behavior.\n\n"
        "We also cover hardening SSH by disabling root login, changing the default SSH port, and configuring key-based authentication. Finally, setting up automatic security updates with `unattended-upgrades` ensures your system stays secure without manual intervention. These enhancements are essential for reducing the attack surface and protecting your systems from unauthorized access."
    }
};


    // Questions
    Question questions[] = {
    {"What is the command to display currently loaded kernel modules?", {"A. lsmod", "B. modinfo", "C. modprobe", "D. rmmod"}, "lsmod"},
    {"Which command would you use to set a kernel parameter at runtime?", {"A. sysctl", "B. modprobe", "C. top", "D. uname"}, "sysctl"},
    {"How do you add a static route in Linux?", {"A. ip route add", "B. ifconfig", "C. netstat -r", "D. route -n"}, "ip route add"},
    {"What is the command to manage SELinux policies?", {"A. semanage", "B. chcon", "C. setenforce", "D. sestatus"}, "semanage"},
    {"Which command hardens SSH by disabling root login?", {"A. PermitRootLogin no in /etc/ssh/sshd_config", "B. sudo ufw disable", "C. sudo systemctl disable sshd", "D. sudo iptables -A INPUT -p tcp --dport 22 -j DROP"}, "PermitRootLogin no in /etc/ssh/sshd_config"},
    {"How do you change the default SSH port?", {"A. Edit /etc/ssh/sshd_config and change the Port directive", "B. Use iptables to block port 22", "C. Disable SSH and enable Telnet", "D. Set SSH_PORT environment variable"}, "Edit /etc/ssh/sshd_config and change the Port directive"},
    {"Which command is used to compile a new kernel?", {"A. make", "B. gcc", "C. ld", "D. nm"}, "make"},
    {"What tool is used to manage VLANs on Linux?", {"A. vconfig", "B. ifconfig", "C. iptables", "D. brctl"}, "vconfig"},
    {"How do you view and modify network routes?", {"A. ip route show", "B. lsmod", "C. netstat -r", "D. traceroute"}, "ip route show"}
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

