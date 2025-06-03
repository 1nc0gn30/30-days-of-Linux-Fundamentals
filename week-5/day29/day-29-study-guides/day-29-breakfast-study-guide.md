## 🍳 Day 29 Breakfast: System Hardening Techniques

### 🌟 Objective

Learn essential hardening techniques to reduce system vulnerabilities and improve security posture.

---

### 🔌 Removing Unnecessary Services

Unneeded services can introduce vulnerabilities. Disable anything not in use:

```bash
systemctl list-unit-files --type=service
systemctl disable <service-name>
```

**Examples to disable:**

* `cups` (printing)
* `avahi-daemon` (zeroconf)
* `bluetooth` (if unused)

**Tip:** Use `netstat -tulnp` or `ss -tuln` to see what’s listening on ports.

---

### 🛡️ Configuring Firewall Rules

Use UFW or iptables to limit access:

```bash
# Allow SSH only from trusted IP
ufw allow from 192.168.1.10 to any port 22

# Deny all incoming by default
ufw default deny incoming

# Enable firewall
ufw enable
```

**Best practices:**

* Allow only required ports (e.g., 22, 80, 443)
* Deny by default, allow explicitly

---

### 🔐 SSH Security Best Practices

1. **Disable root login:**

```bash
nano /etc/ssh/sshd_config
# Change to:
PermitRootLogin no
```

2. **Change default SSH port:**

```bash
Port 2222
```

3. **Use key-based auth only:**

```bash
PasswordAuthentication no
```

4. **Limit SSH users:**

```bash
AllowUsers yourusername
```

Restart the SSH service after changes:

```bash
systemctl restart ssh
```

---

### 🧠 Review Questions

1. Why should unnecessary services be disabled?
2. What firewall command restricts SSH to a specific IP?
3. What setting disables SSH password login?
4. How can you verify which services are active?

---

### 📓 Recommended Reading

* [UFW Essentials](https://help.ubuntu.com/community/UFW)
* [OpenSSH Hardening Guide](https://www.ssh.com/academy/ssh/security-best-practices)
* [System Hardening Guide by CIS](https://www.cisecurity.org/cis-benchmarks)

---

### ✅ Practice Task

* Disable an unused service on your system
* Configure UFW to allow only web and SSH traffic
* Apply at least 2 SSH hardening rules

Verify with:

```bash
sudo ufw status
sudo systemctl status ssh
```
