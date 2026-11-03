# Day 15 · Dinner — Linux Security Hardening, Firewalls & Mandatory Access Control

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `chmod 750`, `chown`, `iptables`, `nftables`, `sshd_config`, `fail2ban`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // DEFENSE-IN-DEPTH & STREAM PIPELINE ARCHITECTURE        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║  [ INBOUND PACKET ] ──► [ Netfilter: iptables / nftables ]                   ║
║                                │ (ACCEPT)                                    ║
║                                ▼                                             ║
║                         [ Hardened SSHD + Fail2Ban ]                         ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ DAC: chmod/chown ] ──► [ MAC: SELinux / AppArmor ] ║
║                                │                                             ║
║                                ▼                                             ║
║                         [ Auditd & Log Pipelines: grep | awk | sed ]         ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 15 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/15` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-15 && cd /tmp/linux-dojo-day-15` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 15 (Dinner Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Configuring a Basic Firewall

**Overview:** Set up and test basic iptables or nftables rules to manage incoming/outgoing traffic.

**Command Example:**
```bash
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```

**Deep Dive:** This lesson covers the basics of firewall configuration. Learn how to allow specific traffic (e.g., HTTP on port 80) while blocking unwanted connections. Both iptables and nftables can be used to control network traffic.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-essentials](https://www.digitalocean.com/community/tutorials/iptables-essentials)
- [https://wiki.archlinux.org/title/nftables](https://wiki.archlinux.org/title/nftables)

## 2. Advanced Firewall Techniques

**Overview:** Implement advanced rules including logging and port forwarding to enhance firewall capabilities.

**Command Example:**
```bash
sudo iptables -A INPUT -p tcp --dport 443 -j LOG --log-prefix 'HTTPS: '
```

**Deep Dive:** This lesson explains how to set up advanced firewall rules. Logging can help you monitor traffic and troubleshoot issues while port forwarding directs traffic from one port to another.

**References:**
- [https://www.cyberciti.biz/faq/iptables-logging-guide/](https://www.cyberciti.biz/faq/iptables-logging-guide/)
- [https://www.digitalocean.com/community/tutorials/iptables-port-forwarding](https://www.digitalocean.com/community/tutorials/iptables-port-forwarding)

## 3. Implementing User Permissions

**Overview:** Learn how to enforce least privilege by managing user permissions effectively.

**Command Example:**
```bash
sudo usermod -aG sudo username
```

**Deep Dive:** In this lesson, you will learn how to assign users to groups, limiting their access rights and enforcing the principle of least privilege, which is vital for system security.

**References:**
- [https://www.cyberciti.biz/tips/linux-unix-bsd-users-and-groups.html](https://www.cyberciti.biz/tips/linux-unix-bsd-users-and-groups.html)

## 4. Configuring Sudoers

**Overview:** Configure the sudoers file to specify which users can run specific commands with elevated privileges.

**Command Example:**
```bash
sudo visudo
```

**Deep Dive:** This lesson discusses the configuration of the sudoers file. Proper configuration ensures that only authorized users can execute critical commands, thereby minimizing security risks.

**References:**
- [https://www.sudo.ws/man/1.8.13/sudoers.man.html](https://www.sudo.ws/man/1.8.13/sudoers.man.html)

## 5. SELinux Fundamentals

**Overview:** Understand SELinux policies and modes to enforce application-level security.

**Command Example:**
```bash
sestatus
```

**Deep Dive:** This lesson provides an introduction to SELinux. You will learn about its different modes (enforcing, permissive, disabled) and how to interpret the status output to secure your applications.

**References:**
- [https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/)

## 6. AppArmor Basics

**Overview:** An overview of AppArmor for managing application-specific security policies.

**Command Example:**
```bash
sudo aa-status
```

**Deep Dive:** Learn how AppArmor profiles restrict application behavior. This lesson covers profile enforcement, troubleshooting, and best practices for maintaining a secure system.

**References:**
- [https://www.digitalocean.com/community/tutorials/how-to-use-apparmor-to-restrict-programs-on-ubuntu-16-04](https://www.digitalocean.com/community/tutorials/how-to-use-apparmor-to-restrict-programs-on-ubuntu-16-04)

## 7. Fail2Ban Configuration

**Overview:** Prevent brute-force attacks by configuring Fail2Ban to monitor and ban suspicious IP addresses.

**Command Example:**
```bash
sudo systemctl start fail2ban
```

**Deep Dive:** This lesson walks through setting up Fail2Ban. By monitoring log files for repeated failed login attempts, Fail2Ban automatically bans offending IP addresses.

**References:**
- [https://www.fail2ban.org/wiki/index.php/Main_Page](https://www.fail2ban.org/wiki/index.php/Main_Page)
- [https://www.digitalocean.com/community/tutorials/how-to-protect-ssh-with-fail2ban](https://www.digitalocean.com/community/tutorials/how-to-protect-ssh-with-fail2ban)

## 8. Intrusion Detection with Snort

**Overview:** Set up Snort to monitor network traffic and detect potential intrusions.

**Command Example:**
```bash
sudo snort -A console -q -c /etc/snort/snort.conf -i eth0
```

**Deep Dive:** This lesson introduces Snort, a powerful intrusion detection system. You will learn how to install and configure Snort to alert you to suspicious network activities.

**References:**
- [https://www.snort.org/documents](https://www.snort.org/documents)

## 9. VPN Setup and Security

**Overview:** Configure a VPN to secure remote connections and protect data in transit.

**Command Example:**
```bash
sudo openvpn --config client.ovpn
```

**Deep Dive:** In this lesson, you'll learn how to set up a VPN using OpenVPN. VPNs encrypt data traffic and provide a secure tunnel for remote access.

**References:**
- [https://openvpn.net/community-resources/how-to/](https://openvpn.net/community-resources/how-to/)

## 10. Log Analysis and Security Auditing

**Overview:** Use log analysis tools to audit system security and detect anomalies.

**Command Example:**
```bash
sudo logwatch --detail high
```

**Deep Dive:** This lesson covers the basics of security auditing through log analysis. Tools like Logwatch help administrators monitor system logs and identify potential security threats.

**References:**
- [https://www.logwatch.net/](https://www.logwatch.net/)
- [https://www.digitalocean.com/community/tutorials/how-to-analyze-log-files-on-ubuntu-20-04](https://www.digitalocean.com/community/tutorials/how-to-analyze-log-files-on-ubuntu-20-04)

---

## Self-Check Quiz & Verification

**1. Which command is used to add a basic firewall rule using iptables?**
- A) `iptables -A INPUT -p tcp --dport 80 -j ACCEPT`
- B) `iptables --add`
- C) `firewall-cmd --zone=public --add-port=80/tcp`
- D) `nft add rule ip filter input tcp dport 80 accept`
- **Correct Answer:** `iptables -A INPUT -p tcp --dport 80 -j ACCEPT`

**2. What is the purpose of logging in firewall rules?**
- A) `To drop packets`
- B) `To record network traffic events`
- C) `To forward traffic`
- D) `To encrypt data`
- **Correct Answer:** `To record network traffic events`

**3. Which command is used to modify user permissions by adding a user to the sudo group?**
- A) `sudo adduser username sudo`
- B) `sudo usermod -aG sudo username`
- C) `chmod +x username`
- D) `usermod --sudo username`
- **Correct Answer:** `sudo usermod -aG sudo username`

**4. What is the main purpose of configuring the sudoers file?**
- A) `To allow root login`
- B) `To define which users can run specific commands with elevated privileges`
- C) `To create new user accounts`
- D) `To disable all system logging`
- **Correct Answer:** `To define which users can run specific commands with elevated privileges`

**5. Which command checks the status of SELinux?**
- A) `sestatus`
- B) `selinux-status`
- C) `getenforce`
- D) `status selinux`
- **Correct Answer:** `sestatus`

**6. How can you check the status of AppArmor profiles?**
- A) `sudo aa-status`
- B) `apparmor-check`
- C) `sudo apparmor --status`
- D) `aa-check-status`
- **Correct Answer:** `sudo aa-status`

**7. Which tool is used to ban IPs after multiple failed login attempts?**
- A) `fail2ban`
- B) `iptables`
- C) `ufw`
- D) `nftables`
- **Correct Answer:** `fail2ban`

**8. What is Snort primarily used for?**
- A) `User authentication`
- B) `Network intrusion detection`
- C) `VPN configuration`
- D) `Log analysis`
- **Correct Answer:** `Network intrusion detection`

**9. Which command initiates an OpenVPN connection?**
- A) `sudo openvpn --config client.ovpn`
- B) `openvpn --start`
- C) `vpn-connect`
- D) `sudo vpnclient connect`
- **Correct Answer:** `sudo openvpn --config client.ovpn`

**10. Which tool is used for detailed log analysis to audit system security?**
- A) `logwatch`
- B) `fail2ban`
- C) `snort`
- D) `iptables`
- **Correct Answer:** `logwatch`
