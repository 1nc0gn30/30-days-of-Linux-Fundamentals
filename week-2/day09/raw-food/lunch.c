#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

#define MAX_ANSWER_LENGTH 100

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[1;32m"
#define RED_COLOR "\033[1;31m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define CYAN_COLOR "\033[1;36m"
#define BOLD "\033[1m"

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a question
typedef struct {
    const char *question;
    const char *options[4];
    char correct_option;
} Question;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf(BOLD YELLOW_COLOR "Lesson on `%s`:\n" RESET_COLOR, lesson->topic);
    printf("%s\n", lesson->description);
    printf(CYAN_COLOR "\n%s\n" RESET_COLOR, lesson->examples);
    printf(BLUE_COLOR "Press Enter to continue...\n" RESET_COLOR);
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer;
    printf(BOLD YELLOW_COLOR "%s\n" RESET_COLOR, question->question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->options[i]);
    }

    printf(BOLD "Your answer: " RESET_COLOR);
    scanf(" %c", &answer);
    getchar(); // Consume newline

    answer = toupper(answer);

    if (answer == question->correct_option) {
        printf(GREEN_COLOR "Correct!\n\n" RESET_COLOR);
    } else {
        printf(RED_COLOR "Incorrect. The correct answer is: %c\n\n" RESET_COLOR, question->correct_option);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf(BOLD CYAN_COLOR "Welcome to Day 09 Lunch!\n" RESET_COLOR);
    printf("In this session, we'll dive into virtualization concepts, including virtual machines, hypervisors, and resource allocation.\n");
    printf("We will explore various virtualization tools and their practical applications.\n");
    printf(BLUE_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Virtual Machines (VMs)",
            "Virtual Machines (VMs) are software-based emulations of physical computers. They run an operating system and applications just like a physical machine but are hosted on a physical server through a hypervisor.\n"
            "VMs provide isolation between different systems running on the same hardware, making them ideal for testing, development, and running multiple OS environments concurrently. This isolation also enhances security, as VMs are separated from each other, preventing one compromised VM from affecting others.",
            "Examples of VM tools:\n"
            "  1. VirtualBox - Free and open-source software for creating VMs.\n"
            "  2. VMware Workstation - A popular commercial VM tool for professionals.\n"
            "  3. KVM (Kernel-based Virtual Machine) - A Linux-based VM that turns the Linux kernel into a hypervisor.\n"
            "  4. Hyper-V - Microsoft's VM platform, built into Windows."
        },
        {
            "Hypervisors",
            "Hypervisors are crucial for virtualization as they allow multiple VMs to run on a single physical machine by providing an abstraction layer between the hardware and the operating systems. There are two main types:\n"
            "1. Type 1 (Bare-metal): Runs directly on the physical hardware, offering better performance and security. Examples include VMware ESXi and Microsoft Hyper-V.\n"
            "2. Type 2 (Hosted): Runs on top of a host operating system, making them more flexible but with a slight performance overhead. Examples include VMware Workstation and Oracle VirtualBox.",
            "Examples of hypervisors:\n"
            "  1. VMware ESXi (Type 1) - A bare-metal hypervisor.\n"
            "  2. Microsoft Hyper-V (Type 1) - Integrated with Windows Server.\n"
            "  3. VMware Workstation (Type 2) - A hosted hypervisor ideal for desktop users.\n"
            "  4. Oracle VirtualBox (Type 2) - A versatile, open-source option."
        },
        {
            "Resource Allocation",
            "Resource allocation is a key aspect of virtualization, involving the assignment of physical resources like CPU, memory, and storage to VMs. Efficient allocation ensures that each VM performs optimally without causing resource contention. Hypervisors provide tools to monitor and adjust resource allocation dynamically, allowing administrators to balance the load and optimize performance across VMs.",
            "Examples of resource allocation tools:\n"
            "  1. VMware vSphere Client - Manages resource distribution in VMware environments.\n"
            "  2. Hyper-V Manager - A tool for managing Hyper-V environments.\n"
            "  3. Virt-Manager - An interface for managing KVM VMs.\n"
            "  4. Azure Resource Manager - Manages resources in Microsoft's cloud."
        },
        {
            "Performance Overhead",
            "Performance overhead refers to the additional resource consumption introduced by virtualization. This includes the extra CPU cycles, memory, and storage used by the hypervisor to manage VMs and their operations. Understanding and minimizing performance overhead is critical to ensure that VMs run efficiently, and that the underlying physical server is not overburdened, which could lead to slowdowns or instability.",
            "Examples of performance overhead management:\n"
            "  1. Monitoring VM performance with tools like `top`, `htop`, or VMware's performance monitoring tools.\n"
            "  2. Adjusting VM resource settings based on real-time usage data.\n"
            "  3. Regularly analyzing hypervisor performance metrics to identify bottlenecks."
        },
        {
            "Snapshots and Cloning",
            "Snapshots and cloning are powerful features provided by virtualization tools. Snapshots allow you to capture the state of a VM at a specific point in time, which is useful for quickly rolling back to a known good state. Cloning, on the other hand, creates an exact copy of a VM, which can be used for scaling applications or testing environments without affecting the original VM.",
            "Examples of snapshot and cloning tools:\n"
            "  1. VMware Snapshot - Capture and revert VM states with ease.\n"
            "  2. VirtualBox Clone - Duplicate VMs for testing or scaling.\n"
            "  3. KVM Snapshot - Capture VM states in KVM environments.\n"
            "  4. Hyper-V Checkpoints - Create and manage VM snapshots in Hyper-V."
        },
        {
            "Virtual Networking",
            "Virtual networking allows VMs to communicate with each other and with external networks. This is achieved by creating virtual network interfaces and switches that operate like physical ones. Virtual networking enables the isolation of network traffic, the creation of VLANs for traffic segmentation, and the configuration of virtual firewalls to control access between different network segments.",
            "Examples of virtual networking tools:\n"
            "  1. VMware vSwitch - A virtual switch for managing VM network traffic.\n"
            "  2. VirtualBox Host-Only Network - Isolates VMs from the external network while allowing communication between them.\n"
            "  3. Hyper-V Virtual Switch - Manages network connectivity for VMs in Hyper-V.\n"
            "  4. KVM Virtual Network - Manages virtual network interfaces and switches in KVM."
        },
        {
            "VM Migration",
            "VM migration is the process of moving a VM from one physical host to another. There are two types of migration:\n"
            "1. Live Migration: Moves a VM without any downtime, ensuring continuous operation.\n"
            "2. Cold Migration: Involves shutting down the VM before moving it, then restarting it on the new host. This is generally used when hardware maintenance is required or during disaster recovery scenarios.",
            "Examples of VM migration tools:\n"
            "  1. VMware vMotion - Enables live migration of VMs across hosts.\n"
            "  2. Hyper-V Live Migration - Allows VMs to be moved without downtime in Hyper-V.\n"
            "  3. KVM Live Migration - Facilitates the live migration of VMs in KVM environments.\n"
            "  4. VirtualBox Migration - Supports VM migration across different VirtualBox hosts."
        }
    };
    // Questions
    Question questions[] = {
        {
            "1. What is a Virtual Machine (VM) and how does it differ from a physical machine?",
            {
                "A VM is a physical computer running software applications.",
                "A VM is a software-based emulation of a physical computer.",
                "A VM is a type of cloud service.",
                "A VM is a network protocol."
            },
            'B'
        },
        {
            "2. What is the primary difference between Type 1 and Type 2 hypervisors?",
            {
                "Type 1 runs on a host OS, while Type 2 runs directly on hardware.",
                "Type 1 runs directly on hardware, while Type 2 runs on a host OS.",
                "Type 2 offers better performance than Type 1.",
                "Type 1 is for desktop use, while Type 2 is for servers."
            },
            'B'
        },
        {
            "3. How can performance overhead in virtualization be minimized?",
            {
                "By increasing the number of VMs running on the host.",
                "By using less resource-intensive applications within VMs.",
                "By regularly analyzing hypervisor performance metrics.",
                "By disabling VM snapshots."
            },
            'C'
        },
        {
            "4. What is a VM snapshot used for?",
            {
                "To create a backup of the physical server.",
                "To capture the current state of a VM at a specific point in time.",
                "To clone a VM for scaling purposes.",
                "To manage network traffic between VMs."
            },
            'B'
        },
        {
            "5. Which tool is used for live migration of VMs?",
            {
                "VMware Snapshot",
                "Hyper-V Manager",
                "VMware vMotion",
                "VirtualBox Clone"
            },
            'C'
        },
        {
            "6. What does virtual networking allow VMs to do?",
            {
                "Communicate with physical network interfaces only.",
                "Operate independently from each other.",
                "Communicate with each other and with external networks.",
                "D. Run network protocols on their own."
            },
            'C'
        },
        {
            "7. What is a key benefit of using virtual machines?",
            {
                "Increased hardware requirements.",
                "Better isolation and security between different systems.",
                "Reduced need for networking.",
                "D. Lower performance overhead."
            },
            'B'
        },
        {
            "8. What tool can manage resource allocation in VMware environments?",
            {
                "VMware Workstation",
                "VMware vSphere Client",
                "Hyper-V Manager",
                "Virt-Manager"
            },
            'B'
        },
        {
            "9. What does VM cloning allow you to do?",
            {
                "Create a backup of the VM's disk.",
                "Capture the VM's state for rollback.",
                "Create an exact copy of a VM.",
                "Adjust the VM's resource allocation."
            },
            'C'
        },
        {
            "10. How does Type 1 hypervisor differ from Type 2 in terms of performance?",
            {
                "Type 1 has higher performance due to running directly on hardware.",
                "Type 2 has higher performance due to running on a host OS.",
                "Both have the same performance.",
                "Type 1 and Type 2 have performance that depends on the number of VMs."
            },
            'A'
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(Lesson); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        ask_question(&questions[i]);
    }

    printf(BOLD CYAN_COLOR "Thank you for participating in Day 09 Lunch!\n" RESET_COLOR);
    printf("Please make sure to review the materials and reach out if you have any questions.\n");

    return 0;
}
