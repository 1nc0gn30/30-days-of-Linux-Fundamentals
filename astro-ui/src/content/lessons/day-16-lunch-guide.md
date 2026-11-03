# Day 16 · Lunch — Security Auditing, Auditd, Logwatch & Vulnerability Scanning

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
> **Core Commands**: `auditd`, `auditctl`, `ausearch`, `logwatch`, `lynis`, `nmap -A`

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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 16 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/16` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-16 && cd /tmp/linux-dojo-day-16` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 16 (Lunch Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Using Lynis for Auditing

**Overview:** Conduct a comprehensive security audit using Lynis.

**Command Example:**
```bash
sudo lynis audit system
```

**Deep Dive:** Lynis is an open-source auditing tool that assesses system security and compliance.

**References:**
- [https://cisofy.com/lynis/](https://cisofy.com/lynis/)

## 2. Nessus for Vulnerability Scanning

**Overview:** Learn the basics of vulnerability scanning with Nessus.

**Command Example:**
```bash
nessus -q
```

**Deep Dive:** Nessus is a powerful vulnerability scanner that identifies security holes and misconfigurations.

**References:**
- [https://www.tenable.com/products/nessus](https://www.tenable.com/products/nessus)

## 3. OpenVAS Overview

**Overview:** Introduction to OpenVAS as an open-source vulnerability scanner.

**Command Example:**
```bash
openvas-start
```

**Deep Dive:** OpenVAS offers a robust framework for scanning and managing vulnerabilities across your network.

**References:**
- [https://www.openvas.org/](https://www.openvas.org/)

## 4. Introduction to Vulnerability Assessment

**Overview:** Understand the fundamentals of identifying security weaknesses.

**Command Example:**
```bash
sudo apt install lynis
```

**Deep Dive:** Regular vulnerability assessments help in proactively identifying and mitigating risks.

**References:**
- [https://www.sans.org/white-papers/374/](https://www.sans.org/white-papers/374/)

## 5. Configuring Vulnerability Scanners

**Overview:** Set up tools like Nessus for optimal vulnerability scanning.

**Command Example:**
```bash
sudo nessuscli update
```

**Deep Dive:** Proper configuration ensures accurate and efficient detection of security vulnerabilities.

**References:**
- [https://www.tenable.com/products/nessus/nessus-configuration](https://www.tenable.com/products/nessus/nessus-configuration)

## 6. Interpreting Vulnerability Scan Reports

**Overview:** Learn how to read and act on scan reports.

**Command Example:**
```bash
cat /var/nessus/report.html
```

**Deep Dive:** Understanding scan reports is key to identifying and remediating security issues.

**References:**
- [https://www.tenable.com/blog/how-to-read-nessus-reports](https://www.tenable.com/blog/how-to-read-nessus-reports)

## 7. Best Practices for Vulnerability Management

**Overview:** Overview of effective strategies for managing vulnerabilities.

**Command Example:**
```bash
echo 'Review reports regularly'
```

**Deep Dive:** Implementing best practices helps prioritize fixes and maintain overall system security.

**References:**
- [https://www.cisa.gov/vulnerability-management](https://www.cisa.gov/vulnerability-management)

## 8. Manual Vulnerability Checks

**Overview:** Perform manual vulnerability checks with tools like nmap.

**Command Example:**
```bash
nmap -sV target_ip
```

**Deep Dive:** Manual checks can complement automated scans by providing deeper insight into system vulnerabilities.

**References:**
- [https://nmap.org/book/](https://nmap.org/book/)

## 9. Automating Vulnerability Assessments

**Overview:** Schedule regular scans to continuously monitor for vulnerabilities.

**Command Example:**
```bash
crontab -e
```

**Deep Dive:** Automation reduces manual effort and ensures that vulnerability assessments are performed routinely.

**References:**
- [https://www.cyberciti.biz/tips/automate-tasks-with-cron-jobs-in-linux.html](https://www.cyberciti.biz/tips/automate-tasks-with-cron-jobs-in-linux.html)

## 10. Prioritizing Vulnerability Remediation

**Overview:** Assess and prioritize vulnerabilities based on risk levels.

**Command Example:**
```bash
echo 'Set remediation priorities'
```

**Deep Dive:** This lesson stresses the importance of addressing the most critical vulnerabilities first.

**References:**
- [https://www.us-cert.gov/vulnerability](https://www.us-cert.gov/vulnerability)

---

## Self-Check Quiz & Verification

**1. Which command initiates a system audit using Lynis?**
- A) `sudo lynis audit system`
- B) `lynis --scan`
- C) `sudo lynis check`
- D) `lynis audit -q`
- **Correct Answer:** `sudo lynis audit system`

**2. Which tool is known for its vulnerability scanning capabilities with a graphical interface?**
- A) `Nessus`
- B) `Lynis`
- C) `OpenVAS`
- D) `Snort`
- **Correct Answer:** `Nessus`

**3. Which open-source tool is used for vulnerability scanning?**
- A) `OpenVAS`
- B) `Nessus`
- C) `Lynis`
- D) `Wireshark`
- **Correct Answer:** `OpenVAS`

**4. What is the primary purpose of vulnerability assessments?**
- A) `To identify security weaknesses`
- B) `To update software`
- C) `To monitor network traffic`
- D) `To backup data`
- **Correct Answer:** `To identify security weaknesses`

**5. Which command updates Nessus plugins?**
- A) `sudo nessuscli update`
- B) `nessus --update`
- C) `sudo apt update nessus`
- D) `nessus-update`
- **Correct Answer:** `sudo nessuscli update`

**6. Which tool is used for manual vulnerability checks?**
- A) `nmap -sV target_ip`
- B) `lynis audit`
- C) `openvas-start`
- D) `grep vulnerabilities`
- **Correct Answer:** `nmap -sV target_ip`

**7. What is a key benefit of automating vulnerability assessments?**
- A) `Regular scheduled scans`
- B) `Manual report generation`
- C) `Increased false positives`
- D) `Reduced network performance`
- **Correct Answer:** `Regular scheduled scans`

**8. Which command displays a vulnerability scan report?**
- A) `cat /var/nessus/report.html`
- B) `open /var/report`
- C) `nessus --report`
- D) `view report.txt`
- **Correct Answer:** `cat /var/nessus/report.html`

**9. What is crucial for effective vulnerability management?**
- A) `Prioritizing remediation`
- B) `Immediate shutdown`
- C) `Ignoring low risks`
- D) `Disabling scanning`
- **Correct Answer:** `Prioritizing remediation`

**10. Which tool is renowned for comprehensive system auditing?**
- A) `Lynis`
- B) `OpenVAS`
- C) `Nessus`
- D) `Snort`
- **Correct Answer:** `Lynis`
