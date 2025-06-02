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