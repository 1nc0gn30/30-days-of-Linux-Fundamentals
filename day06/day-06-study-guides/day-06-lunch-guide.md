# Day 6 Lunch: Advanced Networking Basics

## Overview

In this session, we'll dive deeper into Networking Basics. We'll explore advanced networking commands and concepts.

## Lessons

### Inspecting Network Interfaces (`ip`)

The `ip` command is used to show/manipulate routing, devices, policy routing, and tunnels.

**Examples:**
- `ip addr show` : Display all network interfaces
- `ip link set eth0 up` : Bring up the 'eth0' interface
- `ip route show` : Display the routing table
- `ip addr add 192.168.1.100/24 dev eth0` : Add an IP address to 'eth0'

### Diagnosing Network Issues (`mtr`)

The `mtr` command combines the functionality of `traceroute` and `ping` in a single network diagnostic tool.

**Examples:**
- `mtr google.com` : Run mtr against Google
- `mtr -r google.com` : Generate a report after completion
- `mtr -c 100 google.com` : Limit to 100 cycles

### Monitoring Network Traffic (`tcpdump`)

The `tcpdump` command allows you to capture and analyze network packets in real-time.

**Examples:**
- `tcpdump -i eth0` : Capture traffic on 'eth0'
- `tcpdump port 80` : Capture traffic on port 80 (HTTP)
- `tcpdump -w capture.pcap` : Save captured packets to a file

### Checking Port Status (`nmap`)

The `nmap` command is used for network discovery and security auditing.

**Examples:**
- `nmap -sP 192.168.1.0/24` : Ping scan a network range
- `nmap -p 80 google.com` : Scan port 80 on Google
- `nmap -A google.com` : Perform a comprehensive scan on Google

### Testing Network Connectivity (`curl`)

The `curl` command transfers data from or to a server, using one of the supported protocols (HTTP, HTTPS, FTP, etc.).

**Examples:**
- `curl http://example.com` : Fetch a web page
- `curl -I http://example.com` : Fetch HTTP headers
- `curl -d "name=John" -X POST http://example.com` : Send a POST request

## Quiz Questions

1. **Question:** What command would you use to display all network interfaces using the `ip` tool?
   - **Answer:** `ip addr show`

2. **Question:** Which command combines `traceroute` and `ping` functionalities?
   - **Answer:** `mtr`


