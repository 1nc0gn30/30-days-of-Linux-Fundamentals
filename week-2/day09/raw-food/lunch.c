#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 100

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a question
typedef struct {
    const char *question;
    const char *correct_answer;
} Question;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf("Lesson on `%s`:\n", lesson->topic);
    printf("%s\n", lesson->description);
    printf("\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const Question *question) {
    char answer[MAX_ANSWER_LENGTH];
    printf("%s\n", question->question);
    printf("Instructions: Provide a detailed response based on your understanding. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, question->correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf("Welcome to Day 09 Lunch!\n");
    printf("In this session, we'll explore virtualization concepts, including virtual machines, hypervisors, and resource allocation.\n");
    printf("We'll also cover different virtualization tools and their uses.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Virtual Machines (VMs)",
            "Virtual Machines (VMs) are software-based emulations of physical computers. They run an operating system and applications just like a physical machine but are hosted on a physical server through a hypervisor.\n"
            "VMs provide isolation between different systems running on the same hardware and can be used for development, testing, and running multiple OS environments.",
            "Examples of VM tools:\n"
            "  1. VirtualBox\n"
            "  2. VMware Workstation\n"
            "  3. KVM (Kernel-based Virtual Machine)\n"
            "  4. Hyper-V"
        },
        {
            "Hypervisors",
            "Hypervisors are software or firmware that create and manage virtual machines by providing an abstraction layer between the hardware and the operating systems. There are two types of hypervisors:\n"
            "1. Type 1 (Bare-metal): Runs directly on the hardware (e.g., VMware ESXi, Microsoft Hyper-V).\n"
            "2. Type 2 (Hosted): Runs on top of a host operating system (e.g., VMware Workstation, Oracle VirtualBox).",
            "Examples of hypervisors:\n"
            "  1. VMware ESXi (Type 1)\n"
            "  2. Microsoft Hyper-V (Type 1)\n"
            "  3. VMware Workstation (Type 2)\n"
            "  4. Oracle VirtualBox (Type 2)"
        },
        {
            "Resource Allocation",
            "Resource allocation involves assigning physical resources (CPU, memory, storage) to virtual machines. Efficient allocation ensures optimal performance and avoids resource contention among VMs.\n"
            "Hypervisors often provide tools for monitoring and adjusting resource allocation to balance loads and ensure each VM gets the necessary resources.",
            "Examples of resource allocation tools:\n"
            "  1. VMware vSphere Client\n"
            "  2. Hyper-V Manager\n"
            "  3. Virt-Manager\n"
            "  4. Azure Resource Manager"
        },
        {
            "Performance Overhead",
            "Performance overhead refers to the additional resource consumption introduced by virtualization. It includes the extra CPU, memory, and storage used by the hypervisor to manage VMs and their operations.\n"
            "Understanding and managing performance overhead is crucial to ensure that VMs run efficiently and that the physical server is not overburdened.",
            "Examples of performance overhead management:\n"
            "  1. Monitoring VM performance with tools like `top` or `htop`\n"
            "  2. Adjusting VM resource settings based on usage\n"
            "  3. Analyzing hypervisor performance metrics"
        },
        {
            "Snapshots and Cloning",
            "Snapshots and cloning are features provided by virtualization tools to capture the state of a VM at a specific point in time or to create copies of VMs.\n"
            "Snapshots allow for quick rollbacks to previous states, while cloning enables the creation of identical VMs for scaling or testing purposes.",
            "Examples of snapshot and cloning tools:\n"
            "  1. VMware Snapshot\n"
            "  2. VirtualBox Clone\n"
            "  3. KVM Snapshot\n"
            "  4. Hyper-V Checkpoints"
        },
        {
            "Virtual Networking",
            "Virtual networking enables communication between VMs and external networks by creating virtual network interfaces and switches. It allows VMs to interact with each other and with the outside world while sharing the physical network resources.\n"
            "Configuring virtual networks involves setting up virtual switches, VLANs, and network adapters.",
            "Examples of virtual networking tools:\n"
            "  1. VMware vSwitch\n"
            "  2. VirtualBox Host-Only Network\n"
            "  3. Hyper-V Virtual Switch\n"
            "  4. KVM Virtual Network"
        },
        {
            "Storage Options",
            "Virtualization tools offer various storage options for VMs, including virtual disks and shared storage. Virtual disks are files stored on physical storage devices that represent the VM's hard drive, while shared storage allows multiple VMs to access the same storage resources.\n"
            "Choosing the right storage option is important for performance and reliability.",
            "Examples of storage options:\n"
            "  1. VMware VMDK\n"
            "  2. VirtualBox VDI\n"
            "  3. Hyper-V VHD\n"
            "  4. KVM QCOW2"
        },
        {
            "VM Migration",
            "VM migration involves moving a VM from one physical host to another without shutting it down. This process can be live (without interrupting the VM's operations) or cold (with downtime).\n"
            "Migration is used for load balancing, hardware maintenance, and disaster recovery.",
            "Examples of VM migration tools:\n"
            "  1. VMware vMotion\n"
            "  2. Hyper-V Live Migration\n"
            "  3. KVM Live Migration\n"
            "  4. VirtualBox Migration"
        },
        {
            "Security Considerations",
            "Security in virtualization involves protecting both the host and guest systems from vulnerabilities and attacks. This includes securing hypervisors, implementing access controls, and monitoring for potential threats.\n"
            "Ensuring that virtualization environments are secure is crucial for maintaining data integrity and system stability.",
            "Examples of security practices:\n"
            "  1. Hypervisor patch management\n"
            "  2. VM isolation and segmentation\n"
            "  3. Secure management interfaces\n"
            "  4. Regular security audits"
        },
        {
            "Backup and Recovery",
            "Backup and recovery in virtualization involve creating copies of VMs and their data to protect against data loss and system failures. Regular backups and well-defined recovery procedures are essential for disaster recovery planning.\n"
            "Backup solutions can include VM snapshots, full backups, and incremental backups.",
            "Examples of backup and recovery tools:\n"
            "  1. VMware Data Protection\n"
            "  2. Veeam Backup & Replication\n"
            "  3. Acronis Backup\n"
            "  4. Backup Exec"
        },
        {
            "Cloud Integration",
            "Cloud integration involves extending virtualization environments to cloud platforms, allowing for hybrid or multi-cloud deployments. This integration enables flexible resource scaling and enhanced disaster recovery options.\n"
            "Understanding cloud services and their interaction with on-premises virtualization is key for modern IT infrastructures.",
            "Examples of cloud integration tools:\n"
            "  1. VMware Cloud on AWS\n"
            "  2. Microsoft Azure Virtual Machines\n"
            "  3. Google Cloud Compute Engine\n"
            "  4. IBM Cloud Virtual Servers"
        }
    };

// Questions
Question questions[] = {
    {
        "1. What is a Virtual Machine (VM) and how does it differ from a physical machine?\n"
        "Hint: A Virtual Machine (VM) is a ********-based emulation of a ******** computer, running an operating system and ************, managed by a **********. Unlike a physical machine, multiple VMs can run on one ****** physical ******, sharing its resources.",
        "A Virtual Machine (VM) is a software-based emulation of a physical computer. It runs an operating system and applications, managed by a hypervisor. Unlike a physical machine, multiple VMs can run on one single physical server, sharing its resources."
    },
    {
        "2. What are the two types of hypervisors and their primary differences?\n"
        "Hint: Type 1 hypervisors run directly on ********, while Type 2 hypervisors run on top of a ****, with generally ****** overhead. Examples of Type 1 include VMware ESXi, and Type 2 include VMware Workstation.",
        "Type 1 hypervisors run directly on hardware, while Type 2 hypervisors run on top of a host, with generally higher overhead. Examples of Type 1 include VMware ESXi, and Type 2 include VMware Workstation."
    },
    {
        "3. How does resource allocation work in a virtualized environment?\n"
        "Hint: Hypervisors allocate ***, ******, and ******* to VMs, managing them to prevent ********* and ensure efficient use.",
        "Hypervisors allocate CPU, memory, and storage to VMs, managing to prevent contention and ensure efficient use."
    },
    {
        "4. What is performance overhead in virtualization, and why is it important?\n"
        "Hint: Performance overhead is the extra ***, ******, and ******* used by the **********, impacting VM efficiency.",
        "Performance overhead is the extra CPU, memory, and storage used by the hypervisor, impacting VM efficiency."
    },
    {
        "5. What are snapshots and cloning in virtualization, and how are they used?\n"
        "Hint: Snapshots capture the ***** of a VM at a point in ****, while cloning creates ****** of VMs for scaling or testing.",
        "Snapshots capture the state of a VM at a specific point in time, while cloning creates copies of VMs for scaling or testing."
    },
    {
        "6. Explain the concept of virtual networking and its components.\n"
        "Hint: Virtual networking uses ******* switches and ****** interfaces to connect VMs, with ***** for traffic segmentation and isolation.",
        "Virtual networking uses virtual switches and network interfaces to connect VMs, with VLANs for traffic segmentation and isolation."
    },
    {
        "7. What storage options are available for virtual machines, and how do they differ?\n"
        "Hint: Storage options include virtual ***, like VMDK, and *** storage, allowing multiple VMs to access the same ******** storage.",
        "Storage options include virtual disks (e.g., VMDK) and shared storage, allowing multiple VMs to access the same physical storage."
    },
    {
        "8. What is VM migration, and what are its types?\n"
        "Hint: VM migration involves moving a VM from one **** to another. **** migration occurs without downtime, while **** migration involves downtime.",
        "VM migration involves moving a VM from one host to another. Live migration occurs without downtime, while cold migration involves downtime."
    },
    {
        "9. What security considerations are important in a virtualized environment?\n"
        "Hint: Security includes protecting ***********, controlling ******, and isolating ***, with regular security audits.",
        "Security includes protecting hypervisors, controlling access, and isolating VMs, with regular security audits to maintain a secure environment."
    },
    {
        "10. How does cloud integration enhance virtualization environments?\n"
        "Hint: Cloud integration extends virtualization to cloud *********, enabling flexible ********, disaster recovery, and hybrid deployments.",
        "Cloud integration extends virtualization to cloud platforms, enabling flexible resource scaling, enhanced disaster recovery, and hybrid deployments."
    }
};



    // Display each lesson and ask related question
    for (int i = 0; i < 10; i++) {
        display_lesson(&lessons[i]);
        ask_question(&questions[i]);
    }

    printf("Thank you for participating in the Day 09 Lunch session!\n");

    return 0;
}
