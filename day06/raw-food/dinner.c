#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a lesson and prompt user
void display_lesson(const char *topic, const char *description, const char *examples) {
    printf("\033[H\033[J"); // Clear screen
    printf("Lesson on `%s`:\n", topic);
    printf("%s\n", description);
    printf("Examples:\n%s\n", examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a question and check the answer
void ask_question(const char *question, const char *correct_answer) {
    char answer[100];
    printf("\033[H\033[J"); // Clear screen
    printf("Question: %s\n", question);
    printf("Instructions: Open a separate terminal and type the command described. Press Enter to continue after you’ve tried it.\n");
    printf("When you are ready, press Enter to proceed...\n");
    getchar(); // Wait for user to press Enter

    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, correct_answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", correct_answer);
    }
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to display the course introduction
void display_intro() {
    printf("\033[H\033[J"); // Clear screen
    printf("Welcome to Day 6 Dinner!\n");
    printf("In this session, we'll review everything from today and explore additional advanced networking commands.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter
}

int main() {
    display_intro();

    // Review lessons and examples from breakfast and lunch
    display_lesson(
        "Inspecting Network Interfaces (`ip`)",
        "The `ip` command is used to show/manipulate routing, devices, policy routing, and tunnels.",
        "Examples:\n  ip addr show           # Display all network interfaces\n  ip link set eth0 up    # Bring up the 'eth0' interface\n  ip route show          # Display the routing table\n  ip addr add 192.168.1.100/24 dev eth0 # Add an IP address to 'eth0'"
    );

    display_lesson(
        "Diagnosing Network Issues (`mtr`)",
        "The `mtr` command combines the functionality of `traceroute` and `ping` in a single network diagnostic tool.",
        "Examples:\n  mtr google.com         # Run mtr against Google\n  mtr -r google.com      # Generate a report after completion\n  mtr -c 100 google.com  # Limit to 100 cycles"
    );

    display_lesson(
        "Monitoring Network Traffic (`tcpdump`)",
        "The `tcpdump` command allows you to capture and analyze network packets in real-time.",
        "Examples:\n  tcpdump -i eth0        # Capture traffic on 'eth0'\n  tcpdump port 80        # Capture traffic on port 80 (HTTP)\n  tcpdump -w capture.pcap # Save captured packets to a file"
    );

    display_lesson(
        "Checking Port Status (`nmap`)",
        "The `nmap` command is used for network discovery and security auditing.",
        "Examples:\n  nmap -sP 192.168.1.0/24 # Ping scan a network range\n  nmap -p 80 google.com  # Scan port 80 on Google\n  nmap -A google.com     # Perform a comprehensive scan on Google"
    );

    display_lesson(
        "Testing Network Connectivity (`curl`)",
        "The `curl` command transfers data from or to a server, using one of the supported protocols (HTTP, HTTPS, FTP, etc.).",
        "Examples:\n  curl http://example.com # Fetch a web page\n  curl -I http://example.com # Fetch HTTP headers\n  curl -d \"name=John\" -X POST http://example.com # Send a POST request"
    );

    // Additional advanced commands
    display_lesson(
        "Analyzing Network Performance (`iperf`)",
        "`iperf` is a network testing tool that can create TCP and UDP data streams and measure the throughput of a network.",
        "Examples:\n  iperf -s               # Run `iperf` in server mode\n  iperf -c <server_ip>   # Run `iperf` in client mode to test against a server"
    );

    display_lesson(
        "Network Interface Configuration (`ifconfig`)",
        "The `ifconfig` command is used to configure kernel-resident network interfaces.",
        "Examples:\n  ifconfig eth0          # Display the configuration of 'eth0'\n  ifconfig eth0 up       # Bring up the 'eth0' interface\n  ifconfig eth0 192.168.1.100/24 # Assign IP address to 'eth0'"
    );

    display_lesson(
        "Advanced Network Diagnostics (`netstat`)",
        "The `netstat` command displays various network-related information such as network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.",
        "Examples:\n  netstat -a             # Display all active connections\n  netstat -r             # Display the routing table\n  netstat -i             # Display network interfaces"
    );

    display_lesson(
        "Managing Firewall Rules (`iptables`)",
        "`iptables` is a command-line firewall utility that uses policy chains to allow or block traffic.",
        "Examples:\n  iptables -L            # List all rules\n  iptables -A INPUT -p tcp --dport 22 -j ACCEPT # Allow SSH traffic\n  iptables -A INPUT -p tcp --dport 80 -j DROP  # Block HTTP traffic"
    );

    // Review questions
    ask_question(
        "What command would you use to capture traffic on the 'eth0' interface?",
        "tcpdump -i eth0"
    );

    ask_question(
        "Which command would you use to test network throughput?",
        "iperf"
    );

    return 0;
}

