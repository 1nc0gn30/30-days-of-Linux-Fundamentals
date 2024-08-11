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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 11 Breakfast!\n" RESET_COLOR);
    printf("In this session, we will explore Advanced Network Configuration.\n");
    printf("We will gain a comprehensive understanding of advanced network configuration concepts.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

   Lesson lessons[] = {
    {
        "IP Addressing and Subnetting",
        "Learn the basics of IP addressing, including private and public IP addresses. Understand subnetting, how to calculate subnet masks, and the role of subnets in network segmentation.\n"
        "Commands:\n"
        "To display your current IP address: `ip addr show` or `ifconfig`\n"
        "To calculate subnet masks and ranges, use the `ipcalc` tool:\n"
        "Example: `ipcalc 192.168.1.1/24`\n"
        "This will provide details about the network and broadcast addresses, as well as the range of usable IP addresses.\n"
        "To visualize network configuration: `nmcli dev show`"
    },
    {
        "VLANs (Virtual Local Area Networks)",
        "Explore VLAN concepts, how they are used to segment network traffic, and how to configure VLANs on Linux systems using `vconfig` or `ip` commands.\n"
        "Commands:\n"
        "To create a VLAN on Linux:\n"
        "`sudo ip link add link eth0 name eth0.10 type vlan id 10`\n"
        "To assign an IP address to the VLAN interface:\n"
        "`sudo ip addr add 192.168.10.1/24 dev eth0.10`\n"
        "To bring the VLAN interface up:\n"
        "`sudo ip link set dev eth0.10 up`\n"
        "Example: Create VLAN 10 for the Sales department and VLAN 20 for the HR department."
    },
    {
        "Routing Protocols",
        "Understand various routing protocols and how to manage routing tables on Linux.\n"
        "Commands:\n"
        "To view the routing table:\n"
        "`ip route show`\n"
        "To add a route:\n"
        "`sudo ip route add 10.0.0.0/24 via 192.168.1.1`\n"
        "To remove a route:\n"
        "`sudo ip route del 10.0.0.0/24`\n"
        "For dynamic routing, install and configure `Quagga` or `FRRouting` packages for OSPF or BGP.\n"
        "Example: Use `vtysh` to configure OSPF with `router ospf` and `network 192.168.1.0/24 area 0`."
    },
    {
        "NAT (Network Address Translation)",
        "Study NAT and how to configure it on Linux using `iptables`.\n"
        "Commands:\n"
        "To set up NAT with iptables:\n"
        "`sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE`\n"
        "To view NAT translations:\n"
        "`sudo iptables -t nat -L -n -v`\n"
        "Example: Configure NAT to allow multiple devices on a local network to share a single public IP address."
    },
    {
        "DHCP (Dynamic Host Configuration Protocol)",
        "Learn about DHCP and its role in automatically assigning IP addresses. Configure a DHCP server using `isc-dhcp-server` on Linux.\n"
        "Commands:\n"
        "To install the DHCP server:\n"
        "`sudo apt-get install isc-dhcp-server`\n"
        "To configure DHCP server:\n"
        "Edit `/etc/dhcp/dhcpd.conf` to define the IP address pool:\n"
        "Example:\n"
        "`subnet 192.168.1.0 netmask 255.255.255.0 {\n"
        "  range 192.168.1.100 192.168.1.200;\n"
        "  option routers 192.168.1.1;\n"
        "}`\n"
        "To view DHCP leases:\n"
        "`cat /var/lib/dhcp/dhclient.leases`"
    },
    {
        "Network Security Measures",
        "Discover network security measures like firewalls and intrusion detection systems on Linux.\n"
        "Commands:\n"
        "To configure a basic firewall rule using `iptables`:\n"
        "`sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT`\n"
        "`sudo iptables -A INPUT -j DROP`\n"
        "To view firewall rules:\n"
        "`sudo iptables -L`\n"
        "For IDS/IPS, consider tools like `Snort` or `Suricata`.\n"
        "Example: Use `snort` to monitor and analyze network traffic for suspicious activity."
    },
    {
        "Network Monitoring and Management",
        "Explore tools for monitoring network performance and managing devices.\n"
        "Commands:\n"
        "To monitor network interfaces:\n"
        "`sudo iftop` or `nload`\n"
        "To check network statistics:\n"
        "`netstat -i`\n"
        "To use SNMP:\n"
        "Install `snmpd` and configure `/etc/snmp/snmpd.conf`.\n"
        "To check SNMP configuration:\n"
        "`snmpwalk -v2c -c public localhost`\n"
        "Example: Use SNMP to collect and analyze performance data from network devices."
    },
    {
        "QoS (Quality of Service)",
        "Learn about QoS configurations to prioritize network traffic on Linux.\n"
        "Commands:\n"
        "To configure QoS using `tc` (Traffic Control):\n"
        "`sudo tc qdisc add dev eth0 root handle 1: htb default 30`\n"
        "`sudo tc class add dev eth0 parent 1: classid 1:1 htb rate 1mbit`\n"
        "`sudo tc filter add dev eth0 protocol ip prio 1 handle 1 fw flowid 1:1`\n"
        "To view QoS settings:\n"
        "`sudo tc qdisc show`\n"
        "Example: Configure QoS to prioritize VoIP traffic over regular data traffic."
    },
    {
        "Wireless Networking Concepts",
        "Understand wireless networking standards and manage wireless interfaces on Linux.\n"
        "Commands:\n"
        "To view wireless interfaces and their configuration:\n"
        "`iwconfig`\n"
        "To connect to a wireless network:\n"
        "`nmcli dev wifi connect SSID password YOUR_PASSWORD`\n"
        "To manage wireless interfaces:\n"
        "`sudo iw dev wlan0 scan`\n"
        "Example: Use `iwconfig` to troubleshoot wireless connectivity issues and `nmcli` to manage wireless connections."
    },
    {
        "Network Troubleshooting Techniques",
        "Practice network troubleshooting using various Linux tools.\n"
        "Commands:\n"
        "To test connectivity:\n"
        "`ping <destination_ip>`\n"
        "To trace the route:\n"
        "`traceroute <destination_ip>`\n"
        "To capture network traffic:\n"
        "`sudo tcpdump -i eth0`\n"
        "To analyze captured traffic:\n"
        "`sudo tcpdump -r <file>`\n"
        "Example: Use `ping` to check connectivity, `traceroute` to identify the route, and `tcpdump` to capture and analyze traffic."
    }
};

    Question questions[] = {
    {"What command is used to display the current IP address on Linux?", "ip addr show"},
    {"How can you create a VLAN on a Linux system?", "sudo ip link add link eth0 name eth0.10 type vlan id 10"},
    {"Which command shows the routing table on a Linux system?", "ip route show"},
    {"What command sets up NAT with iptables on Linux?", "sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE"},
    {"Which command installs the DHCP server on Ubuntu?", "sudo apt-get install isc-dhcp-server"},
    {"What is the purpose of configuring firewall rules with iptables?", "To control network traffic and enhance security"},
    {"Which tool is used to monitor network interfaces and performance?", "iftop"},
    {"What does QoS stand for in network management?", "Quality of Service"},
    {"Which command is used to view and manage wireless interfaces on Linux?", "iwconfig"},
    {"What command can be used to capture network traffic for analysis?", "sudo tcpdump -i eth0"}
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
