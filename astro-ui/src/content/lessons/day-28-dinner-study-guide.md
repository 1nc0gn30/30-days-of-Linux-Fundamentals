## 🍽️ Day 28 Dinner: Lab Session - Docker Compose

### 🎯 Objective

Apply your Docker Compose knowledge in practical scenarios by setting up and managing multi-container environments.

---

### 🧪 Lab Task 1: Set Up a Multi-Container Application

Use Docker Compose to run a web application with a database.

#### 📝 Sample `docker-compose.yml`

```yaml
version: '3.8'
services:
  web:
    image: nginx
    ports:
      - "8080:80"
  db:
    image: postgres
    environment:
      POSTGRES_USER: admin
      POSTGRES_PASSWORD: secret
```

Start with:

```bash
docker-compose up
```

Tear it down with:

```bash
docker-compose down
```

---

### 🧪 Lab Task 2: Manage Docker Networks

Create a custom Docker network and attach services to it.

#### 🔧 Command

```bash
docker network create my_custom_network
docker network ls
docker network inspect my_custom_network
```

Update `docker-compose.yml`:

```yaml
networks:
  default:
    external:
      name: my_custom_network
```

---

### 🧪 Lab Task 3: Persistent Data with Volumes

Create volumes to persist data between container restarts.

#### 📁 Sample Addition to Compose

```yaml
services:
  db:
    image: postgres
    volumes:
      - db_data:/var/lib/postgresql/data

volumes:
  db_data:
```

Check volumes:

```bash
docker volume ls
docker volume inspect db_data
```

---

### 🧠 Review Questions

1. What is the benefit of using Docker volumes?
2. How do you inspect a Docker network?
3. Why would you define external networks in Compose?
4. What happens when you run `docker-compose down -v`?

---

### 📚 Recommended Resources

* [Volumes in Docker](https://docs.docker.com/storage/volumes/)
* [Docker Networks Guide](https://docs.docker.com/network/)
* [Compose Networking Docs](https://docs.docker.com/compose/networking/)
* [Docker Compose CLI](https://docs.docker.com/compose/reference/overview/)

---

### ✅ Challenge

Create a Docker Compose setup with:

* An Nginx reverse proxy
* A Node.js app
* A PostgreSQL database

Use networks and volumes for full isolation and persistence.
