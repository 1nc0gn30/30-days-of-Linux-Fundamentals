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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 11 Dinner!\n" RESET_COLOR);
    printf("In this session, we will focus on more advanced topics in network configuration.\n");
    printf("We'll cover high-level concepts and practices to solidify your understanding.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    Lesson lessons[] = {
    {
        "Advanced Network Configuration with IPsec",
        "Explore IPsec for securing IP communications by authenticating and encrypting each IP packet. Learn how to configure IPsec on Linux for secure communications.\n"
        "Commands:\n"
        "To install IPsec tools:\n"
        "`sudo apt-get install strongswan`\n"
        "To configure IPsec, edit `/etc/ipsec.conf`:\n"
        "Example configuration:\n"
        "`conn myvpn\n"
        "  authby=psk\n"
        "  keyexchange=ikev2\n"
        "  left=%any\n"
        "  leftsubnet=0.0.0.0/0\n"
        "  right=%any\n"
        "  rightdns=8.8.8.8\n"
        "  rightsourceip=10.0.0.0/24`\n"
        "Restart the IPsec service:\n"
        "`sudo systemctl restart strongswan`\n"
        "Example: Use IPsec to establish a secure VPN connection."
    },
    {
        "Load Balancing Techniques",
        "Learn about load balancing to distribute network traffic across multiple servers or resources to improve performance and reliability.\n"
        "Commands:\n"
        "To configure load balancing with `nginx`:\n"
        "Edit `/etc/nginx/nginx.conf` to include:\n"
        "`http {\n"
        "  upstream backend {\n"
        "    server 192.168.1.2;\n"
        "    server 192.168.1.3;\n"
        "  }\n"
        "  server {\n"
        "    location / {\n"
        "      proxy_pass http://backend;\n"
        "    }\n"
        "  }\n"
        "}`\n"
        "Restart nginx:\n"
        "`sudo systemctl restart nginx`\n"
        "Example: Use nginx to balance traffic between multiple web servers."
    },
    {
        "High Availability Configuration",
        "Explore high availability solutions to ensure that critical services remain available even in the event of hardware or software failures.\n"
        "Commands:\n"
        "To configure high availability with `keepalived`:\n"
        "Install `keepalived`:\n"
        "`sudo apt-get install keepalived`\n"
        "Edit `/etc/keepalived/keepalived.conf`:\n"
        "Example configuration:\n"
        "`vrrp_instance VI_1 {\n"
        "  state MASTER\n"
        "  interface eth0\n"
        "  virtual_router_id 51\n"
        "  priority 101\n"
        "  advert_int 1\n"
        "  authentication {\n"
        "    auth_type PASS\n"
        "    auth_pass mypassword\n"
        "  }\n"
        "  virtual_ipaddress {\n"
        "    192.168.1.100\n"
        "  }\n"
        "}`\n"
        "Restart keepalived:\n"
        "`sudo systemctl restart keepalived`\n"
        "Example: Use keepalived to provide a virtual IP address that can failover between multiple servers."
    },
    {
        "Network Performance Analysis",
        "Deep dive into tools and techniques for analyzing network performance and identifying bottlenecks.\n"
        "Commands:\n"
        "To use `nload` for network traffic monitoring:\n"
        "`sudo nload`\n"
        "To perform a detailed network analysis with `iperf`:\n"
        "`iperf3 -s` (server)\n"
        "`iperf3 -c <server_ip>` (client)\n"
        "To analyze network latency and packet loss:\n"
        "`ping -c 100 <destination_ip>`\n"
        "Example: Use `iperf` to test throughput and `ping` to check latency and packet loss."
    },
    {
        "Security Best Practices for Network Configuration",
        "Review security best practices for network configuration, including securing network services and implementing access controls.\n"
        "Commands:\n"
        "To secure SSH access with key-based authentication:\n"
        "Generate a key pair:\n"
        "`ssh-keygen`\n"
        "Copy the public key to the server:\n"
        "`ssh-copy-id user@server`\n"
        "Disable password authentication in `/etc/ssh/sshd_config`:\n"
        "`PasswordAuthentication no`\n"
        "Restart SSH service:\n"
        "`sudo systemctl restart ssh`\n"
        "Example: Secure SSH access to prevent unauthorized logins."
    },
    {
        "Network Service Troubleshooting",
        "Explore troubleshooting techniques for network services to diagnose and resolve issues effectively.\n"
        "Commands:\n"
        "To check service status with `systemctl`:\n"
        "`sudo systemctl status <service>`\n"
        "To view service logs with `journalctl`:\n"
        "`sudo journalctl -u <service>`\n"
        "To check network service connectivity:\n"
        "`telnet <hostname> <port>`\n"
        "Example: Use `systemctl` to check service status and `telnet` to test connectivity to a specific port."
    }
};

    Question questions[] = {
        {"What command is used to install IPsec tools on Linux?", "sudo apt-get install strongswan"},
        {"How do you configure IPsec for a VPN on Linux?", "Edit /etc/ipsec.conf"},
        {"What is the purpose of load balancing?", "To distribute network traffic across multiple servers"},
        {"Which tool can be used for load balancing on Linux?", "nginx"},
        {"How do you configure high availability with keepalived?", "Edit /etc/keepalived/keepalived.conf"},
        {"What command shows network traffic in real-time?", "nload"},
        {"How do you secure SSH access with key-based authentication?", "Generate a key pair and copy the public key"},
        {"What is a common tool for analyzing network throughput?", "iperf3"},
        {"Which command helps to check the status of a service?", "systemctl status"},
        {"How can you test network service connectivity to a specific port?", "telnet"}
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
