# Day 17 · Dinner — Network Hardening, NAT/Port Forwarding, Wireshark & Snort IDS

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 17 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/17` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-17 && cd /tmp/linux-dojo-day-17` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 17 (Dinner Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Advanced iptables NAT Configuration Lab

**Overview:** Configure iptables with NAT to manage outgoing traffic.

**Command Example:**
```bash
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

**Deep Dive:** In this lab, you set up NAT so that internal IP addresses are masked behind a public IP.

**References:**
- [https://www.cyberciti.biz/faq/iptables-nat/](https://www.cyberciti.biz/faq/iptables-nat/)

## 2. Port Forwarding Lab

**Overview:** Implement port forwarding to direct external traffic to an internal server.

**Command Example:**
```bash
sudo iptables -t nat -A PREROUTING -p tcp --dport 2222 -j DNAT --to-destination 192.168.1.10:22
```

**Deep Dive:** This lab demonstrates how to redirect traffic from one port on the firewall to a different port on an internal host.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-port-forwarding](https://www.digitalocean.com/community/tutorials/iptables-port-forwarding)

## 3. Rate Limiting with iptables

**Overview:** Set up rate limiting to mitigate brute-force attacks.

**Command Example:**
```bash
sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT
```

**Deep Dive:** Rate limiting helps protect services such as SSH by restricting the number of connection attempts.

**References:**
- [https://www.cyberciti.biz/faq/iptables-rate-limit/](https://www.cyberciti.biz/faq/iptables-rate-limit/)

## 4. Live Traffic Capture with Wireshark

**Overview:** Capture network packets in real time for analysis.

**Command Example:**
```bash
wireshark
```

**Deep Dive:** This lab task involves launching Wireshark to capture live traffic, enabling you to analyze network patterns and potential issues.

**References:**
- [https://www.wireshark.org/docs/wsug_html_chunked/](https://www.wireshark.org/docs/wsug_html_chunked/)

## 5. Analyzing Packet Captures

**Overview:** Use Wireshark filters to analyze captured network data.

**Command Example:**
```bash
ip.addr==192.168.1.2
```

**Deep Dive:** Learn how to apply display filters in Wireshark to isolate specific traffic and troubleshoot network issues.

**References:**
- [https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html](https://www.wireshark.org/docs/wsug_html_chunked/ChWorkBuildDisplayFilterSection.html)

## 6. Snort IDS Installation Lab

**Overview:** Install Snort on your system and run a basic configuration test.

**Command Example:**
```bash
sudo snort -A console -c /etc/snort/snort.conf -i eth0
```

**Deep Dive:** This lab guides you through installing Snort and performing an initial test to ensure that it can detect suspicious traffic.

**References:**
- [https://www.snort.org/documents](https://www.snort.org/documents)

## 7. Creating Custom Snort Rules

**Overview:** Develop and implement custom rules in Snort.

**Command Example:**
```bash
alert tcp any any -> any 80 (msg:"Custom HTTP Alert"; sid:100001;)
```

**Deep Dive:** In this exercise, you will create your own Snort rule to detect specific traffic patterns relevant to your network.

**References:**
- [https://www.snort.org/faq](https://www.snort.org/faq)

## 8. Testing Snort Alerts

**Overview:** Generate traffic to trigger Snort alerts and verify rule functionality.

**Command Example:**
```bash
curl http://yourserver
```

**Deep Dive:** This lab tests your custom Snort rules by generating HTTP requests that should trigger alerts.

**References:**
- [https://www.snort.org/faq](https://www.snort.org/faq)

## 9. Integrating iptables and IDS Logs

**Overview:** Combine firewall and IDS logs for a comprehensive security audit.

**Command Example:**
```bash
cat /var/log/syslog
```

**Deep Dive:** By correlating logs from iptables and Snort, you can better understand the threat landscape and refine your security policies.

**References:**
- [https://www.sans.org/white-papers/389/](https://www.sans.org/white-papers/389/)

## 10. Final Network Security Audit Lab

**Overview:** Conduct a final audit combining all lab tasks to evaluate network security.

**Command Example:**
```bash
echo 'Audit complete'
```

**Deep Dive:** This lab session brings together NAT, port forwarding, rate limiting, packet analysis, and IDS configuration for a final network security review.

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

**2. What is the purpose of the DNAT target in iptables?**
- A) `Redirect traffic to another destination`
- B) `Log packets`
- C) `Block traffic`
- D) `Perform source NAT`
- **Correct Answer:** `Redirect traffic to another destination`

**3. Which command is used to implement rate limiting in iptables?**
- A) `sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT`
- B) `sudo iptables -F`
- C) `sudo iptables -X`
- D) `sudo iptables -L`
- **Correct Answer:** `sudo iptables -A INPUT -p tcp --dport 22 -m limit --limit 10/minute -j ACCEPT`

**4. Which tool is used for live network traffic capture?**
- A) `Wireshark`
- B) `Nmap`
- C) `tcpdump`
- D) `Snort`
- **Correct Answer:** `Wireshark`

**5. What filter in Wireshark would display traffic from a specific IP?**
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

**7. What is the purpose of creating custom Snort rules?**
- A) `To detect specific network traffic patterns`
- B) `To block all traffic`
- C) `To improve Wireshark captures`
- D) `To disable firewall logging`
- **Correct Answer:** `To detect specific network traffic patterns`

**8. Which lab task involves generating traffic to test IDS rules?**
- A) `Testing Snort Alerts`
- B) `Rate Limiting Lab`
- C) `Port Forwarding Lab`
- D) `NAT Configuration Lab`
- **Correct Answer:** `Testing Snort Alerts`

**9. Why integrate logs from iptables and IDS?**
- A) `To achieve a comprehensive view of network security`
- B) `To reduce log file sizes`
- C) `To disable network services`
- D) `To bypass firewall rules`
- **Correct Answer:** `To achieve a comprehensive view of network security`

**10. What is the final goal of the network security audit lab?**
- A) `To review all lab configurations and ensure optimal security`
- B) `To restart all services`
- C) `To disable IDS`
- D) `To update Wireshark`
- **Correct Answer:** `To review all lab configurations and ensure optimal security`
