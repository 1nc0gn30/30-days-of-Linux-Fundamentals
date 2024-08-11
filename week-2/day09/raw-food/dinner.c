#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

#define MAX_ANSWER_LENGTH 200

// ANSI color codes
#define RESET       "\x1B[0m"
#define GREEN       "\x1B[32m"
#define YELLOW      "\x1B[33m"
#define BLUE        "\x1B[34m"
#define MAGENTA     "\x1B[35m"

// Struct to represent a lesson
typedef struct {
    const char *topic;
    const char *description;
    const char *examples;
} Lesson;

// Struct to represent a multiple-choice question
typedef struct {
    const char *question;
    const char *options[4];
    char correct_answer;
} MCQuestion;

// Function to display a lesson and prompt user
void display_lesson(const Lesson *lesson) {
    printf(GREEN "Lesson on `%s`:\n" RESET, lesson->topic);
    printf("%s\n", lesson->description);
    printf("\n%s\n", lesson->examples);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user to press Enter
}

// Function to ask a multiple-choice question and check the answer
void ask_question(const MCQuestion *question) {
    char answer;
    printf(YELLOW "%s\n" RESET, question->question);
    for (int i = 0; i < 4; i++) {
        printf("  %c. %s\n", 'A' + i, question->options[i]);
    }
    printf("\nEnter your choice (A, B, C, or D): ");
    scanf(" %c", &answer);
    answer = toupper(answer); // Convert to uppercase for comparison

    if (answer == question->correct_answer) {
        printf(BLUE "Correct!\n\n" RESET);
    } else {
        printf(MAGENTA "Incorrect. The correct answer is: %c\n\n" RESET, question->correct_answer);
    }
}

int main() {
    // Clear screen (for Unix-based systems)
    printf("\033[H\033[J");

    printf(GREEN "Welcome to Day 09 Dinner!! Containers Lesson!\n" RESET);
    printf("In this session, we'll explore container technology, focusing on Docker, container orchestration, and related concepts.\n");
    printf("We'll also cover practical commands and answer some questions to solidify your understanding.\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    // Lessons
    Lesson lessons[] = {
        {
            "Containerization vs. Virtualization",
            "Containerization involves packaging software and its dependencies into a container that can run on any system with the appropriate container runtime. Unlike traditional virtualization, which requires a full OS for each virtual machine, containers share the host OS kernel but run isolated user spaces.\n"
            "Key benefits of containers include reduced overhead and faster startup times compared to virtual machines.",
            "Examples of containerization benefits:\n"
            "  1. Lightweight deployment\n"
            "  2. Fast scaling\n"
            "  3. Consistent environments across development and production"
        },
        {
            "Docker Overview",
            "Docker is a popular containerization platform that allows developers to automate the deployment of applications within lightweight, portable containers. Docker simplifies the process of building, distributing, and running containers.\n"
            "Docker provides a command-line interface and a graphical user interface (Docker Desktop) for managing containers and images.",
            "Basic Docker commands:\n"
            "  1. docker build -t <image_name> .\n"
            "  2. docker run -d <image_name>\n"
            "  3. docker ps\n"
            "  4. docker stop <container_id>"
        },
        {
            "Container Orchestration",
            "Container orchestration involves managing the deployment, scaling, and operation of containerized applications. Orchestration tools automate these tasks and ensure that containers run reliably across clusters of machines.\n"
            "Popular orchestration tools include Kubernetes, Docker Swarm, and Apache Mesos.",
            "Examples of orchestration tools:\n"
            "  1. Kubernetes\n"
            "  2. Docker Swarm\n"
            "  3. Apache Mesos\n"
            "  4. Amazon ECS"
        },
        {
            "Images and Registries",
            "Container images are the building blocks of containers. They contain the application code, libraries, and dependencies needed to run an application. Images are stored in container registries, which can be public or private.\n"
            "Common registries include Docker Hub and Amazon ECR.",
            "Examples of image and registry commands:\n"
            "  1. docker pull <image_name>\n"
            "  2. docker push <image_name>\n"
            "  3. docker images\n"
            "  4. docker rmi <image_id>"
        },
        {
            "Creating a Dockerfile",
            "A Dockerfile is a text file that contains instructions for building a Docker image. It defines the base image, copies files, and specifies commands to run during the image build process.\n"
            "Dockerfiles help automate the creation of consistent container images.",
            "Example Dockerfile content:\n"
            "  FROM ubuntu:20.04\n"
            "  COPY . /app\n"
            "  RUN make /app\n"
            "  CMD ['python', '/app/app.py']"
        },
        {
            "Networking in Docker",
            "Docker provides several networking options for containers to communicate with each other and with external systems. Docker networks can be configured to support various use cases, including isolated networks and multi-host networking.\n"
            "Common network types include bridge, host, and overlay networks.",
            "Examples of Docker network commands:\n"
            "  1. docker network create <network_name>\n"
            "  2. docker network ls\n"
            "  3. docker network inspect <network_name>\n"
            "  4. docker run --network <network_name> <image_name>"
        },
        {
            "Volumes and Data Management",
            "Docker volumes are used to persist and manage data created by containers. Volumes allow data to be shared between containers and to persist beyond the lifecycle of a container.\n"
            "Volumes are managed by Docker and can be used to store configuration files, logs, and application data.",
            "Examples of volume commands:\n"
            "  1. docker volume create <volume_name>\n"
            "  2. docker volume ls\n"
            "  3. docker volume inspect <volume_name>\n"
            "  4. docker run -v <volume_name>:<container_path> <image_name>"
        },
        {
            "Security Best Practices",
            "Security in containerized environments involves ensuring that containers are isolated, securing the Docker daemon, and minimizing the attack surface. Best practices include using minimal base images, regularly updating images, and scanning for vulnerabilities.\n"
            "Maintaining security also involves proper management of container permissions and secrets.",
            "Examples of security practices:\n"
            "  1. Use official or well-maintained base images\n"
            "  2. Regularly scan images for vulnerabilities\n"
            "  3. Limit container privileges\n"
            "  4. Use secrets management tools"
        },
        {
            "Docker Compose",
            "Docker Compose is a tool for defining and running multi-container Docker applications. With Compose, you can use a YAML file to configure your application's services, networks, and volumes, and then start everything with a single command.\n"
            "Compose simplifies the management of complex applications by providing a unified configuration file and deployment process.",
            "Example `docker-compose.yml` file:\n"
            "  version: '3'\n"
            "  services:\n"
            "    web:\n"
            "      image: nginx\n"
            "      ports:\n"
            "        - '8080:80'\n"
            "    db:\n"
            "      image: postgres\n"
            "      environment:\n"
            "        POSTGRES_PASSWORD: example"
        },
        {
            "Troubleshooting Containers",
            "Troubleshooting container issues involves examining logs, checking container status, and analyzing performance metrics. Common tools and commands for troubleshooting include `docker logs`, `docker inspect`, and `docker stats`.\n"
            "Effective troubleshooting helps identify and resolve issues quickly to maintain application availability.",
            "Examples of troubleshooting commands:\n"
            "  1. docker logs <container_id>\n"
            "  2. docker inspect <container_id>\n"
            "  3. docker stats <container_id>\n"
            "  4. docker exec -it <container_id> /bin/sh"
        }
    };

    // Questions
    MCQuestion questions[] = {
        {
            "1. What is containerization and how does it differ from traditional virtualization?",
            {"Containerization", "Virtualization", "Hypervisor", "Machine Learning"},
            'B'
        },
        {
            "2. What is Docker and what role does it play in containerization?",
            {"Platform", "Service", "Network", "Library"},
            'A'
        },
        {
            "3. What is the difference between Docker Swarm and Kubernetes?",
            {"Clustering and Orchestration", "Networking", "Storage", "Security"},
            'A'
        },
        {
                        "4. What are container images and how are they used?",
            {"Blueprint for containers", "Executable files", "Operating systems", "Library dependencies"},
            'A'
        },
        {
            "5. What command is used to pull an image from a Docker registry?",
            {"docker pulls", "docker run", "docker pull", "docker push"},
            'C'
        },
        {
            "6. What is the purpose of a Dockerfile?",
            {"To edit Docker videos", "To configure network settings", "To build Docker images", "To monitor container performance"},
            'C'
        },
        {
            "7. Which Docker network type provides isolation between containers?",
            {"Bridge", "Host", "Overlay", "None"},
            'A'
        },
        {
            "8. How can you persist data in Docker containers?",
            {"Using images", "Using environment variables", "Using Docker commands", "Using volumes"},
            'D'
        },
        {
            "9. What is Docker Compose used for?",
            {"Managing multi-container applications", "Creating Docker images", "Building Docker networks", "Storing container data"},
            'A'
        },
        {
            "10. Which command can be used to check the status of a running container?",
            {"docker psx", "docker ps", "docker info", "docker inspect"},
            'B'
        }
    };

    // Display lessons
    for (int i = 0; i < sizeof(lessons) / sizeof(lessons[0]); i++) {
        display_lesson(&lessons[i]);
    }

    // Ask questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        ask_question(&questions[i]);
    }

    printf(GREEN "Thank you for participating in the Containers Lesson!\n" RESET);
    printf("Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter before exiting

    return 0;
}

