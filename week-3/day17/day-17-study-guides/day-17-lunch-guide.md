# Day 17 · Lunch — Network Hardening, NAT/Port Forwarding, Wireshark & Snort IDS

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 17 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/17` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-17 && cd /tmp/linux-dojo-day-17` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 17 (Lunch Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Firewall Deep Dive

**Overview:** Explore advanced iptables rules including NAT and port forwarding.

**Command Example:**
```bash
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

**Deep Dive:** This lesson covers advanced firewall configuration techniques such as setting up NAT and port forwarding using iptables.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-essentials](https://www.digitalocean.com/community/tutorials/iptables-essentials)

## 2. Configuring NAT with iptables

**Overview:** Learn to configure Network Address Translation for internal network security.

**Command Example:**
```bash
sudo iptables -t nat -A PREROUTING -p tcp --dport 80 -j DNAT --to-destination 192.168.1.2:80
```

**Deep Dive:** NAT allows you to map external ports to internal hosts, thereby securing your network while providing access to necessary services.

**References:**
- [https://www.cyberciti.biz/faq/iptables-nat/](https://www.cyberciti.biz/faq/iptables-nat/)

## 3. Port Forwarding Configuration

**Overview:** Set up iptables rules for port forwarding to internal services.

**Command Example:**
```bash
sudo iptables -t nat -A PREROUTING -p tcp --dport 2222 -j DNAT --to-destination 192.168.1.10:22
```

**Deep Dive:** Port forwarding redirects traffic from one port to another, useful for exposing internal services securely.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-port-forwarding](https://www.digitalocean.com/community/tutorials/iptables-port-forwarding)

## 4. Understanding iptables Chains

**Overview:** Dive into the INPUT, OUTPUT, and FORWARD chains to secure network traffic.

**Command Example:**
```bash
sudo iptables -L -v
```

**Deep Dive:** Understanding how iptables chains work is critical to creating a secure and robust firewall configuration.

**References:**
- [https://wiki.archlinux.org/title/iptables](https://wiki.archlinux.org/title/iptables)

## 5. Iptables Logging and Debugging

**Overview:** Learn to log firewall activity to troubleshoot and secure your network.

**Command Example:**
```bash
sudo iptables -A INPUT -j LOG --log-prefix 'IPTables-Dropped: '
```

**Deep Dive:** Logging with iptables helps you keep track of dropped packets and diagnose potential security issues.

**References:**
- [https://www.cyberciti.biz/faq/linux-iptables-logging/](https://www.cyberciti.biz/faq/linux-iptables-logging/)

## 6. Monitoring Traffic with Wireshark

**Overview:** Introduction to capturing and analyzing network packets using Wireshark.

**Command Example:**
```bash
wireshark
```

**Deep Dive:** Wireshark is a powerful tool that lets you capture live network traffic and analyze protocols to identify potential threats.

**References:**
- [https://www.wireshark.org/docs/wsug_html_chunked/](https://www.wireshark.org/docs/wsug_html_chunked/)

## 7. Wireshark Filters and Analysis

**Overview:** Learn to apply display filters in Wireshark for targeted traffic analysis.

**Command Example:**
```bash
ip.addr==192.168.1.2
```

**Deep Dive:** Filters allow you to focus on specific traffic, making it easier to detect anomalies and intrusions.

**References:**
- [https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html](https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html)

## 8. Introduction to Snort IDS

**Overview:** Overview of Snort as an intrusion detection system.

**Command Example:**
```bash
sudo snort -A console -c /etc/snort/snort.conf -i eth0
```

**Deep Dive:** Snort inspects network traffic and uses predefined rules to detect malicious activities in real time.

**References:**
- [https://www.snort.org/documents](https://www.snort.org/documents)

## 9. Snort Rule Basics

**Overview:** Learn the fundamentals of creating and modifying Snort rules.

**Command Example:**
```bash
alert tcp any any -> any 80 (msg:"HTTP Traffic"; sid:1000001;)
```

**Deep Dive:** Understanding Snort rules is essential for tuning your IDS to detect specific threats relevant to your network.

**References:**
- [https://www.snort.org/faq](https://www.snort.org/faq)

## 10. Integrating Network Security Tools

**Overview:** Combine firewall, packet analysis, and IDS tools to achieve layered network security.

**Command Example:**
```bash
echo 'Integration complete'
```

**Deep Dive:** Layering multiple network security tools creates a robust defense by covering multiple attack vectors.

**References:**
- [https://www.sans.org/white-papers/advanced-network-security/](https://www.sans.org/white-papers/advanced-network-security/)

---

## Self-Check Quiz & Verification

**1. Which iptables table is used for NAT configuration?**
- A) `nat`
- B) `filter`
- C) `mangle`
- D) `raw`
- **Correct Answer:** `nat`

**2. What is the purpose of the MASQUERADE target in iptables?**
- A) `To perform source NAT`
- B) `To block traffic`
- C) `To log packets`
- D) `To forward ports`
- **Correct Answer:** `To perform source NAT`

**3. Which command is used to list iptables chains?**
- A) `sudo iptables -L -v`
- B) `sudo iptables -F`
- C) `sudo iptables -S`
- D) `sudo iptables -X`
- **Correct Answer:** `sudo iptables -L -v`

**4. Which tool is primarily used for network packet analysis?**
- A) `Wireshark`
- B) `Nmap`
- C) `tcpdump`
- D) `Snort`
- **Correct Answer:** `Wireshark`

**5. What display filter in Wireshark would show traffic from a specific IP?**
- A) `ip.addr==192.168.1.2`
- B) `tcp.port==80`
- C) `udp.port==53`
- D) `icmp.type==8`
- **Correct Answer:** `ip.addr==192.168.1.2`

**6. Which command starts Snort in console mode?**
- A) `sudo snort -A console -c /etc/snort/snort.conf -i eth0`
- B) `snort -v`
- C) `sudo snort -d`
- D) `snort --start`
- **Correct Answer:** `sudo snort -A console -c /etc/snort/snort.conf -i eth0`

**7. What is the primary function of Snort?**
- A) `Intrusion Detection`
- B) `Firewall management`
- C) `Log rotation`
- D) `Packet filtering`
- **Correct Answer:** `Intrusion Detection`

**8. Which iptables option is used to forward traffic to another destination?**
- A) `DNAT`
- B) `SNAT`
- C) `MASQUERADE`
- D) `LOG`
- **Correct Answer:** `DNAT`

**9. Why is logging with iptables useful?**
- A) `It helps diagnose dropped packets`
- B) `It increases throughput`
- C) `It automatically blocks attacks`
- D) `It encrypts traffic`
- **Correct Answer:** `It helps diagnose dropped packets`

**10. What is a key advantage of integrating multiple network security tools?**
- A) `Layered defense`
- B) `Simpler configuration`
- C) `Fewer logs`
- D) `Increased open ports`
- **Correct Answer:** `Layered defense`
