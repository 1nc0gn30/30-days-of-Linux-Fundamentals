# Day 16 · Dinner — Security Auditing, Auditd, Logwatch & Vulnerability Scanning

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 3 (Security & Workflows)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 3 → Day 16 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/16` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-16 && cd /tmp/linux-dojo-day-16` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

Welcome to **Day 16 (Dinner Session)** of the **ZothOS × 1nc0gn30 30 Days of Linux Fundamentals** curriculum! This guide pairs directly with both the native C TUI (`./control-panel`) and the Web Mission Terminal (`astro-ui`).

## 1. Set Up Lynis

**Overview:** Install and conduct a local security audit using Lynis.

**Command Example:**
```bash
sudo lynis audit system --quick
```

**Deep Dive:** This lab task demonstrates a quick Lynis audit to identify system vulnerabilities and assess security posture.

**References:**
- [https://cisofy.com/lynis/](https://cisofy.com/lynis/)

## 2. Vulnerability Scanning with Nessus

**Overview:** Perform an initial vulnerability scan using Nessus.

**Command Example:**
```bash
sudo nessus -q
```

**Deep Dive:** Run Nessus in quiet mode to quickly assess potential vulnerabilities on your system.

**References:**
- [https://www.tenable.com/products/nessus](https://www.tenable.com/products/nessus)

## 3. Practical OpenVAS Setup

**Overview:** Install and run OpenVAS for a comprehensive vulnerability scan.

**Command Example:**
```bash
sudo openvas-start
```

**Deep Dive:** Set up OpenVAS to conduct an in-depth vulnerability assessment and generate actionable reports.

**References:**
- [https://www.openvas.org/](https://www.openvas.org/)

## 4. Hands-on Firewall Security Testing

**Overview:** Evaluate your firewall configuration with practical tests.

**Command Example:**
```bash
sudo iptables -L
```

**Deep Dive:** Reviewing your firewall rules in real-time helps verify that your network defenses are properly configured.

**References:**
- [https://www.digitalocean.com/community/tutorials/iptables-essentials](https://www.digitalocean.com/community/tutorials/iptables-essentials)

## 5. Penetration Testing Basics

**Overview:** Introduction to penetration testing methodologies and tools.

**Command Example:**
```bash
nmap -A target_ip
```

**Deep Dive:** This lesson introduces aggressive network scanning to identify open ports and potential vulnerabilities.

**References:**
- [https://nmap.org/book/](https://nmap.org/book/)

## 6. Secure Configuration Baselines

**Overview:** Evaluate system configurations against security benchmarks.

**Command Example:**
```bash
sudo oscap xccdf eval --profile standard /usr/share/xml/scap/ssg/content/ssg-ubuntu1604-ds.xml
```

**Deep Dive:** Assess your system’s configuration against industry security baselines to spot misconfigurations.

**References:**
- [https://www.open-scap.org/](https://www.open-scap.org/)

## 7. Conducting a Risk Assessment

**Overview:** Perform a comprehensive risk assessment to identify potential threats.

**Command Example:**
```bash
echo 'Risk Assessment Report'
```

**Deep Dive:** Risk assessments help prioritize security risks by evaluating their potential impact and likelihood.

**References:**
- [https://www.nist.gov/](https://www.nist.gov/)

## 8. Incident Response Drills

**Overview:** Simulate incident response scenarios to prepare for security breaches.

**Command Example:**
```bash
echo 'Simulate incident response'
```

**Deep Dive:** Regular drills ensure that your team is ready to respond efficiently when a real security incident occurs.

**References:**
- [https://www.sans.org/incident-response/](https://www.sans.org/incident-response/)

## 9. Real-time Security Monitoring

**Overview:** Monitor system logs in real-time to detect ongoing threats.

**Command Example:**
```bash
sudo tail -f /var/log/syslog
```

**Deep Dive:** Real-time log monitoring allows for immediate detection and response to suspicious activities.

**References:**
- [https://www.loggly.com/ultimate-guide/real-time-log-monitoring/](https://www.loggly.com/ultimate-guide/real-time-log-monitoring/)

## 10. Post-assessment Reporting and Mitigation Strategies

**Overview:** Compile assessment results and plan remediation actions.

**Command Example:**
```bash
cat report.txt
```

**Deep Dive:** Effective post-assessment reporting provides the foundation for implementing targeted mitigation strategies.

**References:**
- [https://www.sans.org/white-papers/389/](https://www.sans.org/white-papers/389/)

---

## Self-Check Quiz & Verification

**1. Which command quickly starts a Lynis audit?**
- A) `sudo lynis audit system --quick`
- B) `sudo lynis quick`
- C) `lynis --fast`
- D) `lynis audit -q`
- **Correct Answer:** `sudo lynis audit system --quick`

**2. Which command is used for vulnerability scanning with Nessus in quiet mode?**
- A) `sudo nessus -q`
- B) `nessus --quiet`
- C) `sudo nessus scan`
- D) `nessus -silent`
- **Correct Answer:** `sudo nessus -q`

**3. Which command initiates OpenVAS?**
- A) `sudo openvas-start`
- B) `openvas --run`
- C) `sudo openvas scan`
- D) `openvas -s`
- **Correct Answer:** `sudo openvas-start`

**4. What command lists current firewall rules?**
- A) `sudo iptables -L`
- B) `iptables --list`
- C) `firewall-cmd --list-all`
- D) `sudo firewall list`
- **Correct Answer:** `sudo iptables -L`

**5. Which command uses an aggressive scan for penetration testing?**
- A) `nmap -A target_ip`
- B) `nmap -aggressive target_ip`
- C) `nmap --attack target_ip`
- D) `nmap -sS target_ip`
- **Correct Answer:** `nmap -A target_ip`

**6. Which tool evaluates secure configuration baselines?**
- A) `oscap`
- B) `lynis`
- C) `nessus`
- D) `openvas`
- **Correct Answer:** `oscap`

**7. What does a risk assessment primarily involve?**
- A) `Evaluating potential security threats`
- B) `Installing patches`
- C) `Configuring firewalls`
- D) `Updating antivirus software`
- **Correct Answer:** `Evaluating potential security threats`

**8. Which command monitors logs in real-time?**
- A) `sudo tail -f /var/log/syslog`
- B) `watch /var/log/syslog`
- C) `cat /var/log/syslog`
- D) `logwatch --realtime`
- **Correct Answer:** `sudo tail -f /var/log/syslog`

**9. Why are incident response drills important?**
- A) `They prepare teams for actual security incidents`
- B) `They reduce system performance`
- C) `They replace audits`
- D) `They are only for training`
- **Correct Answer:** `They prepare teams for actual security incidents`

**10. What is the final goal of post-assessment reporting?**
- A) `To implement mitigation strategies`
- B) `To document vulnerabilities`
- C) `To schedule the next scan`
- D) `To archive log files`
- **Correct Answer:** `To implement mitigation strategies`
