### Day 30: Capstone Project and Week 4 Review

---

## **Breakfast: Week 4 Recap - Study Guide**

### Objectives:

* Summarize major concepts from Week 4
* Reinforce understanding of automation tools and performance optimization
* Reflect on system hardening and review best practices

### Topics Covered:

#### 1. **Review of Key Concepts:**

* **System Performance Monitoring:**

  * Tools: `htop`, `vmstat`, `iostat`, `top`, `iotop`
  * Metrics: CPU usage, memory load, I/O statistics
* **Shell Scripting Techniques:**

  * Variables, conditionals, loops, and functions
  * Input/output redirection, script debugging (`bash -x`, `set -e`)

#### 2. **Automation Tools Summary:**

* **Ansible:**

  * Uses YAML playbooks
  * Agentless architecture
  * Ideal for configuration management and batch server deployment
* **Puppet:**

  * Declarative manifests
  * Client-server model
  * Best for infrastructure as code in enterprise environments
* **Cron:**

  * Scheduling scripts and jobs with `crontab`
  * Common syntax: `* * * * * /path/to/script.sh`

#### 3. **Performance and Hardening Review:**

* **Systemd Optimization:**

  * Disable unused services with `systemctl disable`
* **Firewall Configuration:**

  * Using `ufw` or `iptables` to limit exposed ports
* **SSH Best Practices:**

  * Disable root login, change default port, use key-based auth

### Review Questions:

1. What tools help monitor CPU and memory in real-time?
2. Name 3 improvements you can make to harden an SSH server.
3. What's the purpose of a Puppet manifest?

---

Let me know if you'd like Lunch and Dinner split the same way next!
