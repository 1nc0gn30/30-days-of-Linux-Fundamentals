# Day 11 Lunch: Advanced Network Configuration

Welcome to Day 11 Lunch! Today, we continue our deep dive into **Advanced Network Configuration**. This session is packed with practical lessons on advanced IP configurations, network bonding, DHCP, managing network services, performance optimization, and troubleshooting. By the end of this session, you’ll have a strong grasp of these topics and be able to apply them confidently in real-world scenarios.

## Lessons

### Lesson 1: Advanced IP Configuration
**Topic:** Advanced IP Configuration  
**Description:**  
In this lesson, you'll explore advanced IP configuration tasks, including setting up IP aliases, configuring network bridges, and managing multiple IP addresses on a single interface.

**Commands:**
- To add an IP alias:
```bash
  sudo ip addr add 192.168.1.2/24 dev eth0
  ```
To set up a network bridge:
```bash
sudo ip link add name br0 type bridge
sudo ip link set dev br0 up
```
To add an interface to the bridge:
```bash
sudo ip link set dev eth0 master br0
```
**Example:** Use network bridges to combine multiple network interfaces into a single logical network.

**Instructions:**
Open a separate terminal and type the commands described above. Experiment with adding IP aliases and setting up network bridges. When ready, press Enter to continue.

### Lesson 2: Configuring Bonding Interfaces
**Topic:** Configuring Bonding Interfaces
**Description:**
Learn about network bonding, which allows combining multiple network interfaces into a single virtual interface for redundancy or increased bandwidth.

**Commands:**

To configure bonding on Linux:
Edit /etc/network/interfaces or create a bonding configuration file:
```bash
auto bond0
iface bond0 inet static
  address 192.168.1.10
  netmask 255.255.255.0
  bond-slaves eth0 eth1
  bond-mode 802.3ad
```
To bring up the bonded interface:
```bash
sudo ifup bond0
```
**Example:** Use bonding to improve network reliability and throughput.

**Instructions:**
Try setting up a bonding interface by following the commands above. Ensure you understand how to edit the network configuration file. When done, press Enter to proceed.

## Lesson 3: Advanced DHCP Configuration
**Topic:** Advanced DHCP Configuration
**Description:**
Dive into advanced DHCP configurations, including setting up DHCP relay agents and configuring DHCP options for various scenarios.

**Commands:**

To configure a DHCP relay agent:
```bash
sudo apt-get install isc-dhcp-relay
```
Edit /etc/default/isc-dhcp-relay to set the relay parameters.
To define custom DHCP options:
Edit /etc/dhcp/dhcpd.conf to include options like:
```bash
option domain-name-servers 8.8.8.8;
```
**Example:** Use DHCP relay agents to forward DHCP requests from clients in one subnet to a DHCP server in another subnet.

**Instructions:**
Follow the steps to set up a DHCP relay agent and configure custom DHCP options. Test these configurations in your environment. Press Enter when ready to continue.

### Lesson 4: Managing Network Services
**Topic:** Managing Network Services
**Description:**
Learn how to manage essential network services such as DNS and NTP on Linux.

**Commands:**

To configure DNS settings:
Edit /etc/resolv.conf to add nameserver entries:
```bash
nameserver 8.8.8.8
```
To install and configure NTP:
```bash
sudo apt-get install ntp
```
Edit /etc/ntp.conf to set NTP servers.
To check NTP synchronization:
```bash
ntpq -p
```
**Example:** Configure DNS and NTP services to ensure network name resolution and accurate time synchronization.

**Instructions:**
Configure DNS and NTP settings using the commands above. Verify the changes and test NTP synchronization. Press Enter to proceed to the next lesson.

### Lesson 5: Network Performance Optimization
**Topic:** Network Performance Optimization
**Description:**
Explore techniques for optimizing network performance, including adjusting network buffers and tuning kernel parameters.

**Commands:**

To adjust network buffer sizes:
```bash
sudo sysctl -w net.core.rmem_max=16777216
sudo sysctl -w net.core.wmem_max=16777216
```
To tune kernel parameters for network performance:
```bash
sudo sysctl -w net.ipv4.tcp_fin_timeout=30
```
**Example:** Optimize network performance by tuning kernel parameters to handle high throughput or latency-sensitive applications.

**Instructions:**
Experiment with adjusting network buffer sizes and tuning kernel parameters. Observe the effects of these changes. When ready, press Enter to continue.

### Lesson 6: Network Troubleshooting Tools
**Topic:** Network Troubleshooting Tools
**Description:**
Review advanced network troubleshooting tools and techniques for diagnosing complex network issues.

**Commands:**

To use traceroute with options:
```bash
traceroute -n <destination_ip>
```
To capture and analyze packets:
```bash
sudo wireshark
```
To perform network performance testing:
```bash
iperf3 -s  # Server
iperf3 -c <server_ip>  # Client
```
**Example:** Use wireshark to capture and analyze network traffic for detailed troubleshooting and performance testing.

**Instructions:**
Try using the tools above to troubleshoot network issues. Capture and analyze packets using wireshark and test network performance with iperf3. When finished, press Enter to proceed to the questions.

### Knowledge Check

**Now let's test your knowledge with some questions. Answer the following to the best of your ability.**

#### What command is used to add an IP alias on Linux?

Correct Answer: ip addr add

#### How do you set up a network bridge on Linux?

Correct Answer: ip link add name br0 type bridge

#### What is the purpose of network bonding?

Correct Answer: To combine multiple interfaces for redundancy or increased bandwidth

#### Which configuration file is used to set up bonding on Linux?

Correct Answer: /etc/network/interfaces

#### How do you configure a DHCP relay agent on Linux?

Correct Answer: Install and configure isc-dhcp-relay

#### Where do you define custom DHCP options?

Correct Answer: /etc/dhcp/dhcpd.conf

#### What command adjusts the maximum network buffer size?

Correct Answer: sysctl -w net.core.rmem_max

#### How do you check NTP synchronization?

Correct Answer: ntpq -p

#### Which tool is used for network performance testing?

Correct Answer: iperf3

#### What command shows the current network routing table?

Correct Answer: ip route show


## Conclusion
In this session, you have learned advanced techniques for configuring and managing Linux network interfaces. The lessons covered complex tasks such as IP configuration, bonding, DHCP, and more. These skills are crucial for optimizing and troubleshooting networks in a professional environment. Make sure to practice these commands and understand the underlying principles to solidify your knowledge. Continue exploring and experimenting with these tools to become proficient in network configuration and management on Linux.