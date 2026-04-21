# Day 11: Advanced Network Configuration - Breakfast Session

In this session, we will dive into Advanced Network Configuration, covering crucial concepts and commands that will enhance your understanding of network management on Linux systems.

## Lessons

### 1. IP Addressing and Subnetting
**Topic:** IP Addressing and Subnetting  
**Description:**  
- Learn the basics of IP addressing, including private and public IP addresses.
- Understand subnetting, how to calculate subnet masks, and the role of subnets in network segmentation.

**Commands:**  
- Display current IP address: `ip addr show` or `ifconfig`
- Calculate subnet masks and ranges: `ipcalc 192.168.1.1/24`
- Visualize network configuration: `nmcli dev show`

---

### 2. VLANs (Virtual Local Area Networks)
**Topic:** VLANs (Virtual Local Area Networks)  
**Description:**  
- Explore VLAN concepts, how they are used to segment network traffic, and how to configure VLANs on Linux systems.

**Commands:**  
- Create a VLAN: `sudo ip link add link eth0 name eth0.10 type vlan id 10`
- Assign an IP address to the VLAN interface: `sudo ip addr add 192.168.10.1/24 dev eth0.10`
- Bring the VLAN interface up: `sudo ip link set dev eth0.10 up`

---

### 3. Routing Protocols
**Topic:** Routing Protocols  
**Description:**  
- Understand various routing protocols and how to manage routing tables on Linux.

**Commands:**  
- View the routing table: `ip route show`
- Add a route: `sudo ip route add 10.0.0.0/24 via 192.168.1.1`
- Remove a route: `sudo ip route del 10.0.0.0/24`

---

### 4. NAT (Network Address Translation)
**Topic:** NAT (Network Address Translation)  
**Description:**  
- Study NAT and how to configure it on Linux using `iptables`.

**Commands:**  
- Set up NAT: `sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE`
- View NAT translations: `sudo iptables -t nat -L -n -v`

---

### 5. DHCP (Dynamic Host Configuration Protocol)
**Topic:** DHCP (Dynamic Host Configuration Protocol)  
**Description:**  
- Learn about DHCP and its role in automatically assigning IP addresses.

**Commands:**  
- Install DHCP server: `sudo apt-get install isc-dhcp-server`
- Configure DHCP server: Edit `/etc/dhcp/dhcpd.conf`

---

### 6. Network Security Measures
**Topic:** Network Security Measures  
**Description:**  
- Discover network security measures like firewalls and intrusion detection systems on Linux.

**Commands:**  
- Configure a firewall rule: `sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT`
- View firewall rules: `sudo iptables -L`

---

### 7. Network Monitoring and Management
**Topic:** Network Monitoring and Management  
**Description:**  
- Explore tools for monitoring network performance and managing devices.

**Commands:**  
- Monitor network interfaces: `sudo iftop` or `nload`
- Check network statistics: `netstat -i`

---

### 8. QoS (Quality of Service)
**Topic:** QoS (Quality of Service)  
**Description:**  
- Learn about QoS configurations to prioritize network traffic on Linux.

**Commands:**  
- Configure QoS: `sudo tc qdisc add dev eth0 root handle 1: htb default 30`
- View QoS settings: `sudo tc qdisc show`

---

### 9. Wireless Networking Concepts
**Topic:** Wireless Networking Concepts  
**Description:**  
- Understand wireless networking standards and manage wireless interfaces on Linux.

**Commands:**  
- View wireless interfaces: `iwconfig`
- Connect to a wireless network: `nmcli dev wifi connect SSID password YOUR_PASSWORD`

---

### 10. Network Troubleshooting Techniques
**Topic:** Network Troubleshooting Techniques  
**Description:**  
- Practice network troubleshooting using various Linux tools.

**Commands:**  
- Test connectivity: `ping <destination_ip>`
- Trace the route: `traceroute <destination_ip>`

---

## Questions

1. **What command is used to display the current IP address on Linux?**  
   - **Correct Answer:** `ip addr show`

2. **How can you create a VLAN on a Linux system?**  
   - **Correct Answer:** `sudo ip link add link eth0 name eth0.10 type vlan id 10`

3. **Which command shows the routing table on a Linux system?**  
   - **Correct Answer:** `ip route show`

4. **What command sets up NAT with iptables on Linux?**  
   - **Correct Answer:** `sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE`

5. **Which command installs the DHCP server on Ubuntu?**  
   - **Correct Answer:** `sudo apt-get install isc-dhcp-server`

6. **What is the purpose of configuring firewall rules with iptables?**  
   - **Correct Answer:** `To control network traffic and enhance security`

7. **Which tool is used to monitor network interfaces and performance?**  
   - **Correct Answer:** `iftop`

8. **What does QoS stand for in network management?**  
   - **Correct Answer:** `Quality of Service`

9. **Which command is used to view and manage wireless interfaces on Linux?**  
   - **Correct Answer:** `iwconfig`

10. **What command can be used to capture network traffic for analysis?**  
    - **Correct Answer:** `sudo tcpdump -i eth0`

## Conclusion
In this breakfast session of Day 11, we've covered essential aspects of advanced network configuration on Linux. You learned about IP addressing, VLANs, routing protocols, NAT, DHCP, and other key topics that are fundamental to managing and securing networks effectively. By practicing these commands and understanding their underlying concepts, you'll be well-prepared to handle complex network setups and troubleshoot issues efficiently. Continue experimenting with these commands in your terminal to reinforce your knowledge and build confidence in your network administration skills.