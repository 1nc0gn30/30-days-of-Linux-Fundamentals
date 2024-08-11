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
    printf(BOLD_COLOR CYAN_COLOR "Welcome to Day 10 Breakfast!\n" RESET_COLOR);
    printf("In this session, we will explore Remote Access and Management.\n");
    printf("We will gain a comprehensive understanding of how to securely access and manage remote systems.\n");
    printf(YELLOW_COLOR "Press Enter to start...\n" RESET_COLOR);
    getchar();

    // Lessons
    Lesson lessons[] = {
        {
            "Introduction to SSH (Secure Shell)",
            "Overview of SSH: SSH is a protocol used to securely connect to remote systems over an unsecured network. It encrypts the connection, ensuring that data transmitted between the client and server is secure.\n"
            "Basic Usage:\n To connect to a remote server: ssh user@hostname\n Here, user is the username on the remote machine, and hostname is the IP address or domain name of the remote server."
        },
        {
            "Generating SSH Keys",
            "Commands:\n To generate a new SSH key pair: ssh-keygen -t rsa -b 4096 -C your_email@example.com\n This command creates a new RSA key pair with a 4096-bit key length and associates it with the provided email address.\n"
            "Understanding Public and Private Keys:\n The public key (id_rsa.pub) can be shared with remote servers. The private key (id_rsa) should be kept secure and private. The server uses the public key to encrypt data, which can only be decrypted by the corresponding private key."
        },
        {
            "Copying SSH Keys",
            "Commands:\n To copy your public key to a remote server: ssh-copy-id user@hostname\n This command appends your public key to the ~/.ssh/authorized_keys file on the remote server, allowing you to log in without a password.\n"
            "Automating Key Setup:\n By adding your public key to the authorized_keys file, you automate the authentication process for future logins, improving security and convenience."
        },
        {
            "SSH Configurations",
            "Config File Location:\n The SSH configuration file is located at ~/.ssh/config. It allows you to define settings for different hosts.\n"
            "Setting Up Aliases and Options:\n Example configuration:\n Host myserver\n   HostName hostname.example.com\n   User myuser\n   Port 2222\n This configuration allows you to use ssh myserver to connect to hostname.example.com as myuser on port 2222."
        },
        {
            "Using SCP (Secure Copy)",
            "Commands:\n To copy a file from your local machine to a remote server: scp local_file user@hostname:/remote/directory/\n To copy a file from the remote server to your local machine: scp user@hostname:/remote/file /local/directory/\n"
            "Copying Files Between Hosts:\n SCP can also be used to copy files directly between two remote hosts by specifying the source and destination in the format user@source_host:/path/to/file user@destination_host:/path/to/file."
        },
        {
            "Understanding SFTP (SSH File Transfer Protocol)",
            "Commands:\n To start an SFTP session: sftp user@hostname\n Within the SFTP session, you can use commands like ls, cd, get, and put to navigate and transfer files.\n"
            "Navigating and Managing Files:\n ls lists files, cd changes directories, get downloads files from the server, and put uploads files to the server."
        },
        {
            "Remote Command Execution",
            "Commands:\n To execute a command on a remote server: ssh user@hostname 'command'\n Example: ssh user@hostname 'df -h'\n This command will run df -h on the remote server, showing disk usage."
        },
        {
            "Managing Remote Sessions with tmux",
            "Basic Usage:\n Start a new tmux session: tmux\n Attach to an existing session: tmux attach\n Detach from a session: Ctrl+b d\n"
            "Session Management:\n tmux allows you to create, detach, and switch between multiple terminal sessions within a single SSH session."
        },
        {
            "Using rsync for Remote Syncing",
            "Commands:\n To synchronize a directory from your local machine to a remote server: rsync -avz /local/directory/ user@hostname:/remote/directory/\n The -a flag is for archive mode, -v is for verbose output, and -z compresses file data during transfer.\n"
            "Efficient File Synchronization:\n rsync only transfers the differences between source and destination, which makes it efficient for syncing large directories."
        },
        {
            "Introduction to Remote Desktop Tools",
            "Tools:\n VNC and xrdp are popular tools for remote desktop access.\n"
            "Basic Setup and Commands:\n For VNC, you typically install a VNC server on the remote machine and use a VNC client to connect.\n For xrdp, you install xrdp on the remote machine and connect using an RDP client like Remote Desktop Connection on Windows."
        }
    };

    // Questions
    Question questions[] = {
        {"How do you initiate an SSH connection to a remote server?", "ssh user@hostname"},
        {"What is the purpose of the ssh-keygen command?", "To generate a new SSH key pair"},
        {"How can you copy your SSH public key to a remote server?", "ssh-copy-id user@hostname"},
        {"What is the purpose of the ~/.ssh/config file in SSH configuration?", "It stores SSH configuration settings such as host aliases and connection options"},
        {"How do you copy a file from your local machine to a remote server using SCP?", "scp local_file user@hostname:/remote/directory/"},
        {"What commands are used to start an SFTP session?", "sftp user@hostname"},
        {"How can you execute a command on a remote server without logging into the SSH session?", "ssh user@hostname 'command'"},
        {"What are the basic commands for managing tmux sessions?", "tmux, tmux attach, Ctrl+b d"},
        {"How does rsync differ from scp in terms of file synchronization?", "rsync only transfers differences between source and destination"},
        {"What are the key differences between VNC and xrdp for remote desktop access?", "VNC uses the VNC protocol, xrdp uses the RDP protocol"},
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
