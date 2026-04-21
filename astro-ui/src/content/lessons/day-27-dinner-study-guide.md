## 🍽️ Day 27 - Dinner: Practical Docker Labs

### 🎯 Objective

Apply your Docker knowledge by running and managing containers and images.

### 🔨 Lab Task 1: Run Your First Container

```bash
docker run hello-world
```

This checks if Docker is installed properly.

### 🏗️ Lab Task 2: Build a Custom Image

1. Create a file named `Dockerfile`:

```Dockerfile
FROM alpine
CMD ["echo", "Hello from custom Docker image!"]
```

2. Build the image:

```bash
docker build -t myimage .
```

### 🧹 Lab Task 3: Manage Containers

* View containers:

```bash
docker ps -a
```

* Clean up:

```bash
docker stop $(docker ps -aq)
docker rm $(docker ps -aq)
docker image prune -a
```

### ✅ Review Questions

1. What does `docker build` do?
2. Why is it helpful to prune images?
3. What’s the purpose of the Dockerfile?

---

You're now equipped to build and manage Docker containers effectively!
