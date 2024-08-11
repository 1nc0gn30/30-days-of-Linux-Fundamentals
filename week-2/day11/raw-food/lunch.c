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
    printf("Your answer: ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0;

    if (strcmp(user_answer, question->correct_answer) == 0) {
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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 11 Lunch!\n" RESET_COLOR);
    printf("In this session, we will continue exploring Advanced Network Configuration.\n");
    printf("We will delve deeper into network configuration concepts and practices.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
    {
        "Advanced IP Configuration",
        "Explore advanced IP configuration tasks including setting up IP aliases, configuring network bridges, and managing multiple IP addresses on a single interface.\n"
        "Commands:\n"
        "To add an IP alias:\n"
        "`sudo ip addr add 192.168.1.2/24 dev eth0`\n"
        "To set up a network bridge:\n"
        "`sudo ip link add name br0 type bridge`\n"
        "`sudo ip link set dev br0 up`\n"
        "To add an interface to the bridge:\n"
        "`sudo ip link set dev eth0 master br0`\n"
        "Example: Use network bridges to combine multiple network interfaces into a single logical network."
    },
    {
        "Configuring Bonding Interfaces",
        "Learn about network bonding, which allows combining multiple network interfaces into a single virtual interface for redundancy or increased bandwidth.\n"
        "Commands:\n"
        "To configure bonding on Linux:\n"
        "Edit `/etc/network/interfaces` or create a bonding configuration file:\n"
        "`auto bond0\n"
        "iface bond0 inet static\n"
        "  address 192.168.1.10\n"
        "  netmask 255.255.255.0\n"
        "  bond-slaves eth0 eth1\n"
        "  bond-mode 802.3ad`\n"
        "To bring up the bonded interface:\n"
        "`sudo ifup bond0`\n"
        "Example: Use bonding to improve network reliability and throughput."
    },
    {
        "Advanced DHCP Configuration",
        "Deep dive into advanced DHCP configurations including setting up DHCP relay agents and configuring DHCP options for different scenarios.\n"
        "Commands:\n"
        "To configure a DHCP relay agent:\n"
        "`sudo apt-get install isc-dhcp-relay`\n"
        "Edit `/etc/default/isc-dhcp-relay` to set the relay parameters.\n"
        "To define custom DHCP options:\n"
        "Edit `/etc/dhcp/dhcpd.conf` to include options like `option domain-name-servers 8.8.8.8;`\n"
        "Example: Use DHCP relay agents to forward DHCP requests from clients in one subnet to a DHCP server in another subnet."
    },
    {
        "Managing Network Services",
        "Learn how to manage network services such as DNS and NTP on Linux.\n"
        "Commands:\n"
        "To configure DNS settings:\n"
        "Edit `/etc/resolv.conf` to add nameserver entries:\n"
        "`nameserver 8.8.8.8`\n"
        "To install and configure NTP:\n"
        "`sudo apt-get install ntp`\n"
        "Edit `/etc/ntp.conf` to set NTP servers.\n"
        "To check NTP synchronization:\n"
        "`ntpq -p`\n"
        "Example: Configure DNS and NTP services to ensure network name resolution and accurate time synchronization."
    },
    {
        "Network Performance Optimization",
        "Explore techniques for optimizing network performance including adjusting network buffers and tuning kernel parameters.\n"
        "Commands:\n"
        "To adjust network buffer sizes:\n"
        "`sudo sysctl -w net.core.rmem_max=16777216`\n"
        "`sudo sysctl -w net.core.wmem_max=16777216`\n"
        "To tune kernel parameters for network performance:\n"
        "`sudo sysctl -w net.ipv4.tcp_fin_timeout=30`\n"
        "Example: Optimize network performance by tuning kernel parameters to handle high throughput or latency-sensitive applications."
    },
    {
        "Network Troubleshooting Tools",
        "Review advanced network troubleshooting tools and techniques for diagnosing complex network issues.\n"
        "Commands:\n"
        "To use `traceroute` with options:\n"
        "`traceroute -n <destination_ip>`\n"
        "To capture and analyze packets:\n"
        "`sudo wireshark`\n"
        "To perform network performance testing:\n"
        "`iperf3 -s` (server) and `iperf3 -c <server_ip>` (client)\n"
        "Example: Use `wireshark` to capture and analyze network traffic for detailed troubleshooting and performance testing."
    }
};

    Question questions[] = {
        {"What command is used to add an IP alias on Linux?", "ip addr add"},
        {"How do you set up a network bridge on Linux?", "ip link add name br0 type bridge"},
        {"What is the purpose of network bonding?", "To combine multiple interfaces for redundancy or increased bandwidth"},
        {"Which configuration file is used to set up bonding on Linux?", "/etc/network/interfaces"},
        {"How do you configure a DHCP relay agent on Linux?", "Install and configure isc-dhcp-relay"},
        {"Where do you define custom DHCP options?", "/etc/dhcp/dhcpd.conf"},
        {"What command adjusts the maximum network buffer size?", "sysctl -w net.core.rmem_max"},
        {"How do you check NTP synchronization?", "ntpq -p"},
        {"Which tool is used for network performance testing?", "iperf3"},
        {"What command shows the current network routing table?", "ip route show"}
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
