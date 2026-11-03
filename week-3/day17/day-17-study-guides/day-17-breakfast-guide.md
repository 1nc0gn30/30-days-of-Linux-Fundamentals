# Day 17 · Breakfast — Network Hardening, NAT/Port Forwarding, Wireshark & Snort IDS

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
> **Core Commands**: `systemctl disable`, `ss -tulwn`, `nmap`, `iptables -t nat`, `wireshark`, `snort`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 17 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/17` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-17 && cd /tmp/linux-dojo-day-17` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 17 (Breakfast Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Disabling Unnecessary Network Services

**Overview:** Identify non-critical services and disable them to minimize the potential attack surface.

**Command Example:**
```bash
sudo systemctl disable bluetooth
```

**Deep Dive:** Many Linux systems ship with services that are not required for a given deployment. This lesson teaches you how to review active services and disable those that are not needed. Disabling unused services (such as Bluetooth on a server) reduces resource usage and limits exposure to exploits.

**References:**
- [https://www.cyberciti.biz/tips/disable-unneeded-services-linux.html](https://www.cyberciti.biz/tips/disable-unneeded-services-linux.html)
- [https://www.tecmint.com/stop-disable-unwanted-services-in-linux/](https://www.tecmint.com/stop-disable-unwanted-services-in-linux/)
- [https://www.digitalocean.com/community/tutorials/how-to-manage-systemd-services](https://www.digitalocean.com/community/tutorials/how-to-manage-systemd-services)

## 2. Identifying Active Services

**Overview:** Learn to list all active network services to pinpoint potential vulnerabilities.

**Command Example:**
```bash
sudo netstat -tulpn
```

**Deep Dive:** Using tools like netstat or the newer 'ss' command, you can display active listening ports along with the associated service names and process IDs. This helps in identifying which services are running and if any unknown or unneeded service is active.

**References:**
- [https://linux.die.net/man/8/netstat](https://linux.die.net/man/8/netstat)
- [https://man7.org/linux/man-pages/man8/ss.8.html](https://man7.org/linux/man-pages/man8/ss.8.html)

## 3. Using systemctl to Manage Services

**Overview:** Master the usage of systemctl to manage, start, and stop services efficiently.

**Command Example:**
```bash
sudo systemctl stop avahi-daemon
```

**Deep Dive:** The systemctl command provides a unified interface to control system services under systemd. This lesson covers how to stop and disable services, ensuring that only essential services are allowed to run on your system.

**References:**
- [https://www.freedesktop.org/software/systemd/man/systemctl.html](https://www.freedesktop.org/software/systemd/man/systemctl.html)
- [https://www.digitalocean.com/community/tutorials/understanding-systemd-units-and-unit-files](https://www.digitalocean.com/community/tutorials/understanding-systemd-units-and-unit-files)

## 4. Configuring TCP Wrappers

**Overview:** Implement basic network access control with TCP wrappers using hosts.allow.

**Command Example:**
```bash
sudo nano /etc/hosts.allow
```

**Deep Dive:** TCP wrappers offer a simple but effective method to restrict access to network services. By specifying which hosts are permitted in /etc/hosts.allow, you can filter incoming connections before they reach the service level.

**References:**
- [https://www.tldp.org/HOWTO/TCP-Wrappers-HOWTO/](https://www.tldp.org/HOWTO/TCP-Wrappers-HOWTO/)
- [https://www.cyberciti.biz/faq/tcp-wrappers-howto/](https://www.cyberciti.biz/faq/tcp-wrappers-howto/)

## 5. Understanding /etc/hosts.deny

**Overview:** Block unwanted hosts by properly configuring /etc/hosts.deny.

**Command Example:**
```bash
sudo nano /etc/hosts.deny
```

**Deep Dive:** Complementing hosts.allow, the /etc/hosts.deny file lets you explicitly block access from specific IP addresses or hostnames. This two-tier approach to access control enhances your network security posture.

**References:**
- [https://linux.die.net/man/5/hosts.deny](https://linux.die.net/man/5/hosts.deny)
- [https://www.cyberciti.biz/tips/howto-use-hosts-allow-and-hosts-deny.html](https://www.cyberciti.biz/tips/howto-use-hosts-allow-and-hosts-deny.html)

## 6. Port Scanning with nmap

**Overview:** Use nmap for comprehensive scanning of open ports and services running on target systems.

**Command Example:**
```bash
nmap -sV target_ip
```

**Deep Dive:** Nmap is one of the most powerful tools for network discovery. In this lesson, you learn how to run a version scan (-sV) to not only detect open ports but also determine the services and versions running on those ports.

**References:**
- [https://nmap.org/book/man.html](https://nmap.org/book/man.html)
- [https://nmap.org/book/inst-windows.html](https://nmap.org/book/inst-windows.html)

## 7. Interpreting nmap Output

**Overview:** Analyze detailed nmap scan results to understand the network's exposed services.

**Command Example:**
```bash
nmap -A target_ip
```

**Deep Dive:** The aggressive scan (-A) in nmap combines OS detection, version scanning, script scanning, and traceroute. This lesson explains how to interpret the output, which is critical for identifying vulnerable services and planning hardening measures.

**References:**
- [https://nmap.org/book/toc.html](https://nmap.org/book/toc.html)
- [https://nmap.org/book/man-osdetect.html](https://nmap.org/book/man-osdetect.html)

## 8. Reviewing Open Ports with ss

**Overview:** Verify open ports using the ss command, a modern replacement for netstat.

**Command Example:**
```bash
ss -tulwn
```

**Deep Dive:** The 'ss' command provides a fast and detailed view of open TCP and UDP ports along with associated process details. This tool is useful for confirming the results from other port-scanning methods.

**References:**
- [https://man7.org/linux/man-pages/man8/ss.8.html](https://man7.org/linux/man-pages/man8/ss.8.html)
- [https://www.tecmint.com/ss-command-examples-in-linux/](https://www.tecmint.com/ss-command-examples-in-linux/)

## 9. Best Practices for Network Hardening

**Overview:** Discuss a variety of best practices for securing network services and minimizing exposure.

**Command Example:**
```bash
echo 'Implement best practices'
```

**Deep Dive:** This lesson aggregates multiple techniques such as disabling unneeded services, tightening access controls, and routinely reviewing open ports. Adopting these practices will significantly lower the risk of unauthorized access or exploitation.

**References:**
- [https://www.sans.org/security-resources/policies/general/pdf/network-security-policy](https://www.sans.org/security-resources/policies/general/pdf/network-security-policy)
- [https://www.cisa.gov/publication/securing-network-infrastructure](https://www.cisa.gov/publication/securing-network-infrastructure)

## 10. Securing Remote Access

**Overview:** Limit and secure remote access protocols to reduce potential attack vectors.

**Command Example:**
```bash
sudo systemctl disable telnet
```

**Deep Dive:** Many legacy protocols like Telnet transmit data in plaintext, making them prime targets for interception. This lesson emphasizes disabling such insecure services and opting for more secure alternatives like SSH with proper configurations.

**References:**
- [https://www.cyberciti.biz/tips/secure-remote-access.html](https://www.cyberciti.biz/tips/secure-remote-access.html)
- [https://www.ssh.com/academy/ssh](https://www.ssh.com/academy/ssh)

---

## Self-Check Quiz & Verification

**1. Which command disables an unnecessary service using systemctl?**
- A) `sudo systemctl disable bluetooth`
- B) `sudo systemctl enable ssh`
- C) `sudo systemctl status netstat`
- D) `sudo systemctl start avahi-daemon`
- **Correct Answer:** `sudo systemctl disable bluetooth`

**2. What tool can be used to view active network services along with their associated ports?**
- A) `netstat`
- B) `tcpdump`
- C) `curl`
- D) `ifconfig`
- **Correct Answer:** `netstat`

**3. Which file is used to allow specific hosts in TCP wrappers?**
- A) `/etc/hosts.allow`
- B) `/etc/hosts.deny`
- C) `/etc/services`
- D) `/etc/network/interfaces`
- **Correct Answer:** `/etc/hosts.allow`

**4. Which file is used to block unwanted hosts in TCP wrappers?**
- A) `/etc/hosts.deny`
- B) `/etc/hosts.allow`
- C) `/etc/passwd`
- D) `/etc/shadow`
- **Correct Answer:** `/etc/hosts.deny`

**5. What is the primary purpose of using nmap in network hardening?**
- A) `Port scanning and service enumeration`
- B) `Encrypting data`
- C) `Disabling services`
- D) `Managing user accounts`
- **Correct Answer:** `Port scanning and service enumeration`

**6. Which nmap option is used to perform an aggressive scan combining OS detection and service versioning?**
- A) `-A`
- B) `-sV`
- C) `-O`
- D) `-Pn`
- **Correct Answer:** `-A`

**7. Which command displays listening ports using ss, a modern alternative to netstat?**
- A) `ss -tulwn`
- B) `ss -a`
- C) `netstat -r`
- D) `ifconfig -a`
- **Correct Answer:** `ss -tulwn`

**8. What is one key benefit of disabling non-essential network services?**
- A) `Reduce attack surface`
- B) `Increase power consumption`
- C) `Enhance UI performance`
- D) `Improve file storage`
- **Correct Answer:** `Reduce attack surface`

**9. Which command is used to stop a service immediately using systemctl?**
- A) `sudo systemctl stop avahi-daemon`
- B) `sudo systemctl list`
- C) `sudo systemctl start avahi-daemon`
- D) `sudo systemctl restart bluetooth`
- **Correct Answer:** `sudo systemctl stop avahi-daemon`

**10. What is the overall goal of implementing network hardening practices?**
- A) `Minimize vulnerabilities`
- B) `Maximize open ports`
- C) `Increase service availability`
- D) `Streamline user access`
- **Correct Answer:** `Minimize vulnerabilities`
