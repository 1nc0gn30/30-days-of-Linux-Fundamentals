#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 200

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

    printf("Welcome to the Containers Lesson!\n");
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
Question questions[] = {
    {
        "1. What is containerization and how does it differ from traditional virtualization?\n"
        "Hint: Containerization involves packaging software and its dependencies into a single unit called a *********, which can run on any system with the appropriate *******. Unlike traditional virtualization, containers share the host OS ****** and are more *********** with faster startup times and lower overhead compared to virtual machines.",
        "Containerization involves packaging software and its dependencies into a single unit called a container, which can run on any system with the appropriate runtime. Unlike traditional virtualization, containers share the host OS kernel and are more lightweight, with faster startup times and lower overhead compared to virtual machines."
    },
    {
        "2. What is Docker and what role does it play in containerization?\n"
        "Hint: Docker is a **************** platform that automates the deployment of applications within **********. It provides tools for building, running, and managing containers, making it easier to develop, ship, and deploy applications consistently across different ************.",
        "Docker is a containerization platform that automates the deployment of applications within containers. It provides tools for building, running, and managing containers, making it easier to develop, ship, and deploy applications consistently across different environments."
    },
    {
        "3. What is the difference between Docker Swarm and Kubernetes?\n"
        "Hint: Docker Swarm is Docker's native ********** and ************* tool, known for its ********** and ease of use. Kubernetes, on the other hand, is a more complex and *******-**** orchestration system that provides advanced capabilities for managing containerized applications at *****, including automated deployments, scaling, and management.",
        "Docker Swarm is Docker's native clustering and orchestration tool, known for its simplicity and ease of use. Kubernetes, on the other hand, is a more complex and feature-rich orchestration system that provides advanced capabilities for managing containerized applications at scale, including automated deployments, scaling, and management."
    },
    {
        "4. What are container images and how are they used?\n"
        "Hint: Container ****** are the blueprint for creating **********, containing the application code, *********, and dependencies needed to run an application. Images are used to instantiate containers and can be stored in ********* registries for distribution and sharing.",
        "Container images are the blueprint for creating containers. They contain the application code, libraries, and dependencies needed to run an application. Images are used to instantiate containers and can be stored in container registries for distribution and sharing."
    },
    {
        "5. How do you build a Docker image using a Dockerfile?\n"
        "Hint: A Dockerfile is a ****** containing instructions for building a Docker *****. It specifies the **** image, copies files, and defines commands to execute. The `docker *****` command is used to create an image from a Dockerfile, resulting in a portable and reproducible container image.",
        "A Dockerfile is a script containing instructions for building a Docker image. It specifies the base image, copies files, and defines commands to execute. The `docker build` command is used to create an image from a Dockerfile, resulting in a portable and reproducible container image."
    },
    {
        "6. What are Docker volumes and how do they differ from container storage?\n"
        "Hint: Docker ******* are used to persist and manage **** created by containers. They allow data to be shared between containers and to persist beyond the lifecycle of a container. Unlike container storage, which is *********, volumes are managed independently and can be reused across different containers.",
        "Docker volumes are used to persist and manage data created by containers. They allow data to be shared between containers and to persist beyond the lifecycle of a container. Unlike container storage, which is ephemeral and tied to the container's lifecycle, volumes are managed independently and can be reused across different containers."
    },
    {
        "7. What is container orchestration and why is it important?\n"
        "Hint: Container ************* involves automating the deployment, scaling, and management of containerized applications. It is important because it simplifies the management of complex applications running across multiple containers and ***** ensuring reliable and efficient operation at *****.",
        "Container orchestration involves automating the deployment, scaling, and management of containerized applications. It is important because it simplifies the management of complex applications running across multiple containers and hosts, ensuring reliable and efficient operation at scale."
    },
    {
        "8. How do you use Docker Compose to manage multi-container applications?\n"
        "Hint: Docker Compose uses a **** file to define and configure multi-container applications. By specifying services, networks, and volumes in the file, Compose allows for easy management and orchestration of complex applications with multiple interconnected containers. The `docker-compose **` command starts all services defined in the configuration file.",
        "Docker Compose uses a YAML file to define and configure multi-container applications. By specifying services, networks, and volumes in the file, Compose allows for easy management and orchestration of complex applications with multiple interconnected containers. The `docker-compose up` command starts all services defined in the configuration file."
    },
    {
        "9. What are some common security practices for containerized environments?\n"
        "Hint: Common security practices include using minimal base *****, regularly scanning for ***************, implementing proper access ********, and isolating containers to prevent unauthorized access. It's also important to secure the Docker ****** and manage secrets carefully.",
        "Common security practices include using minimal base images, regularly scanning for vulnerabilities, implementing proper access controls, and isolating containers to prevent unauthorized access. It's also important to secure the Docker daemon and manage secrets carefully."
    },
    {
        "10. How does Docker integrate with cloud platforms?\n"
        "Hint: Docker integrates with cloud platforms to enhance deployment flexibility and scalability. Cloud providers often offer managed container services that support Docker, allowing for seamless ***, automated ***, and improved resource management in cloud environments. This integration helps optimize the performance and availability of containerized applications.",
        "Docker integrates with cloud platforms to enhance deployment flexibility and scalability. Cloud providers often offer managed container services that support Docker, allowing for seamless scaling, automated updates, and improved resource management in cloud environments. This integration helps optimize the performance and availability of containerized applications."
    }
};

    // Display each lesson and ask related question
    for (int i = 0; i < 10; i++) {
        display_lesson(&lessons[i]);
        ask_question(&questions[i]);
    }

    printf("Thank you for participating in the Containers lesson!\n");

    return 0;
}
