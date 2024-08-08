# Day 6 Dinner: Advanced Networking Review and Further Exploration

## Overview

In this session, we'll review everything from today and explore additional advanced networking commands.

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

## Additional Advanced Commands

### Analyzing Network Performance (`iperf`)

`iperf` is a network testing tool that can create TCP and UDP data streams and measure the throughput of a network.

**Examples:**
- `iperf -s` : Run `iperf` in server mode
- `iperf -c <server_ip>` : Run `iperf` in client mode to test against a server

### Network Interface Configuration (`ifconfig`)

The `ifconfig` command is used to configure kernel-resident network interfaces.

**Examples:**
- `ifconfig eth0` : Display the configuration of 'eth0'
- `ifconfig eth0 up` : Bring up the 'eth0' interface
- `ifconfig eth0 192.168.1.100/24` : Assign IP address to 'eth0'

### Advanced Network Diagnostics (`netstat`)

The `netstat` command displays various network-related information such as network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.

**Examples:**
- `netstat -a` : Display all active connections
- `netstat -r` : Display the routing table
- `netstat -i` : Display network interfaces

### Managing Firewall Rules (`iptables`)

`iptables` is a command-line firewall utility that uses policy chains to allow or block traffic.

**Examples:**
- `iptables -L` : List all rules
- `iptables -A INPUT -p tcp --dport 22 -j ACCEPT` : Allow SSH traffic
- `iptables -A INPUT -p tcp --dport 80 -j DROP` : Block HTTP traffic

## Review Questions

1. **What command would you use to capture traffic on the 'eth0' interface?**
   - Correct Answer: `tcpdump -i eth0`

2. **Which command would you use to test network throughput?**
   - Correct Answer: `iperf`

3. **How would you add an IP address to the 'eth0' interface using the `ip` command?**
   - Correct Answer: `ip addr add 192.168.1.100/24 dev eth0`

4. **What `nmap` command would you use to perform a comprehensive scan on Google?**
   - Correct Answer: `nmap -A google.com`

5. **How can you display all active network connections using `netstat`?**
   - Correct Answer: `netstat -a`

## Conclusion

Today, we covered essential networking commands and advanced tools that are critical for network diagnostics and management. Make sure to practice these commands in a controlled environment to understand their impact fully.

Good luck, and keep networking!

