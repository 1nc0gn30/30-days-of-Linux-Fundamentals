# Day 02 Lunch Study Guide

Welcome to Day 2's lunch study guide! This guide covers file compression and archiving, disk management, and network utilities. Use this guide to review and reinforce your understanding of the commands introduced in the Day 2 lunch challenge.

## File Compression and Archiving

### `tar`
The `tar` command is used to create and extract archives. It can also compress files using various compression algorithms.

**Examples:**
```sh
tar -cvf archive.tar file1.txt file2.txt         # Create an archive named 'archive.tar' with 'file1.txt' and 'file2.txt'
tar -xvf archive.tar                              # Extract the contents of 'archive.tar'
tar -czvf archive.tar.gz file1.txt file2.txt      # Create a compressed archive with gzip
tar -xzvf archive.tar.gz                         # Extract a compressed archive with gzip
tar -cf archive.tar -C /path/to/directory/ .       # Create an archive of all files in '/path/to/directory/'
tar -tf archive.tar                              # List the contents of 'archive.tar'

Description:

    -c creates a new archive.
    -x extracts an archive.
    -v displays verbose output (shows the progress).
    -f specifies the filename of the archive.
    -z compresses the archive using gzip.
    -j uses bzip2 compression (not used in these examples but is an option).
    -C changes to the directory before adding files to the archive.
    -t lists the contents of the archive.

Disk Usage and Management
df

The df command reports disk space usage.

Examples:

sh

df -h                         # Show disk space usage in human-readable format
df -T                         # Show the file system type along with disk usage

Description:

    -h displays sizes in human-readable format (e.g., GB, MB).
    -T shows the file system type.

fdisk

The fdisk command is used for disk partitioning.

Examples:

sh

sudo fdisk -l                 # List all disk partitions and their sizes
sudo fdisk /dev/sda           # Open the fdisk utility for disk '/dev/sda'

Description:

    -l lists all partitions.
    /dev/sda is an example of a disk device; replace with your actual device name.

du

The du command provides disk usage information.

Examples:

sh

du -sh directory/             # Show the total disk usage of 'directory/' in a human-readable format
du -a                         # Show disk usage of all files and directories recursively
du -ch | grep total            # Show disk usage and find the total size
du -sh --max-depth=1          # Show disk usage of directories within 'directory/' up to 1 level deep

Description:

    -s summarizes the total usage.
    -h displays sizes in human-readable format.
    --max-depth limits the depth of directory recursion.

Network Utilities
netstat

The netstat command displays network connections, routing tables, and network interface statistics.

Examples:

sh

netstat -tuln                 # Show all listening TCP and UDP ports
netstat -r                    # Show the routing table

Description:

    -t shows TCP connections.
    -u shows UDP connections.
    -l shows only listening sockets.
    -n displays addresses and port numbers numerically.

ping

The ping command tests connectivity to a network host.

Examples:

sh

ping google.com               # Test connectivity to 'google.com'
ping -c 4 google.com          # Ping 'google.com' 4 times

Description:

    -c specifies the number of packets to send.

traceroute

The traceroute command shows the route packets take to a network host.

Examples:

sh

traceroute google.com         # Trace the route to 'google.com'
traceroute -n google.com      # Trace the route without resolving hostnames

Description:

    -n displays numerical addresses instead of resolving hostnames.

Summary

    File Compression and Archiving: tar helps in creating and extracting compressed archives.
    Disk Usage and Management: df and du provide disk usage information, while fdisk is used for partition management.
    Network Utilities: netstat, ping, and traceroute are used to monitor network connections and troubleshoot network issues.

Review these commands and practice using them in your terminal to reinforce your understanding. Good luck with your studies!
