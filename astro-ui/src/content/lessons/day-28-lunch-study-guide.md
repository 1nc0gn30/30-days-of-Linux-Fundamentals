## 🍽️ Day 28 Lunch: Docker Compose

### 🎯 Objective

Understand how Docker Compose simplifies running multi-container applications and learn to use the `docker-compose.yml` file effectively.

---

### 📦 What is Docker Compose?

Docker Compose is a tool for defining and running multi-container Docker applications. With Compose, you use a YAML file to configure your application’s services, networks, and volumes.

---

### 🛠️ Why Use Docker Compose?

* 🔁 **Manage multiple containers** as a single service.
* 📜 **Centralized configuration** using YAML.
* 🚀 **Faster and repeatable deployments**.
* 🐳 Ideal for development and testing environments.

---

### 🧱 Creating a `docker-compose.yml` File

```yaml
db:
  image: postgres
  environment:
    POSTGRES_USER: admin
    POSTGRES_PASSWORD: secret

web:
  build: .
  ports:
    - "5000:5000"
  depends_on:
    - db
```

---

### 🔄 Running Multi-Container Applications

Run everything with:

```bash
docker-compose up
```

Tear it all down:

```bash
docker-compose down
```

Rebuild after changes:

```bash
docker-compose up --build
```

---

### 🧩 Common Compose Commands

| Command                  | Description      |
| ------------------------ | ---------------- |
| `docker-compose ps`      | List containers  |
| `docker-compose logs`    | Show logs        |
| `docker-compose stop`    | Stop services    |
| `docker-compose restart` | Restart services |

---

### 🧠 Review Questions

1. What does `depends_on` do in a Compose file?
2. How do you define environment variables for a container?
3. What’s the difference between `up` and `up --build`?
4. How do you expose a port in Compose?

---

### 📚 Recommended Reading

* [Docker Compose Docs](https://docs.docker.com/compose/)
* [Compose File Reference](https://docs.docker.com/compose/compose-file/)
* [DockerHub](https://hub.docker.com/)

---

### ✅ Practice Task

Create a `docker-compose.yml` file that runs a Node.js app and a MongoDB container.

```yaml
version: '3.8'
services:
  app:
    image: node:alpine
    working_dir: /app
    volumes:
      - .:/app
    ports:
      - "3000:3000"
    command: "npm start"
  mongo:
    image: mongo
    ports:
      - "27017:27017"
```

Run it with:

```bash
docker-compose up
```
