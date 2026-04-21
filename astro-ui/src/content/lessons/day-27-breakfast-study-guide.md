## 🥣 Day 27 - Breakfast: What is Docker?

### 🎯 Objective

Understand containerization fundamentals, install Docker, and compare containers vs VMs.

### 📘 Understanding Containers

* Containers are lightweight, portable units for software that package code and dependencies.
* Docker allows developers to easily deploy apps across systems.
* Key advantages: fast boot, isolated environments, scalable.

### 🐳 Installing Docker

#### On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install docker.io -y
sudo systemctl enable --now docker
```

#### Verify Installation:

```bash
docker --version
docker run hello-world
```

### 🧠 Docker vs Virtual Machines

| Feature        | Docker (Containers) | Virtual Machines |
| -------------- | ------------------- | ---------------- |
| Boot Time      | Seconds             | Minutes          |
| Resource Usage | Low                 | High             |
| Isolation      | Process-level       | Full OS-level    |
| Portability    | High                | Moderate         |

### ✅ Review Questions

1. What makes Docker containers faster than VMs?
2. How do containers ensure app portability?
3. Which command tests Docker installation?

---

## 🥗 Day 27 - Lunch: Working with Docker Images and Containers

### 🎯 Objective

Learn Docker image basics, run containers, and manage their lifecycle.

### 📦 Docker Images

* Images are the blueprints of containers.
* Use `docker pull` to download images from Docker Hub.

#### Example:

```bash
docker pull nginx
```

### 🚀 Running Containers

* Containers are instances of images.

```bash
docker run -d -p 8080:80 nginx
```

* `-d` runs it in background, `-p` maps ports.

### 🔧 Managing Containers

* List containers:

```bash
docker ps -a
```

* Stop a container:

```bash
docker stop <container_id>
```

* Remove a container:

```bash
docker rm <container_id>
```

### ✅ Review Questions

1. How do you list all Docker containers?
2. What’s the difference between an image and a container?
3. Which flag runs a container in detached mode?

---