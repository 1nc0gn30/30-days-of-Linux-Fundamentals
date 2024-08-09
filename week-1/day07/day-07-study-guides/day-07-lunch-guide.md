# Day 07 Lunch Study Guide

## Package Management

### Upgrading Packages

The `apt-get dist-upgrade` command not only upgrades packages but also handles dependencies intelligently. It can add or remove packages as necessary.

#### Examples:
```sh
sudo apt-get dist-upgrade     # Upgrade packages, handling dependencies

Managing PPAs

The add-apt-repository command allows you to add Personal Package Archives (PPAs) to your system, enabling you to install software from third-party repositories.
Examples:

sh

sudo add-apt-repository ppa:repository_name     # Add a PPA
sudo apt-get update                             # Update package list
sudo apt-get install package_name               # Install package from PPA

Using dpkg for Package Management

The dpkg command is a low-level package manager for Debian-based systems. It can be used to install, remove, and manage .deb packages.
Examples:

sh

sudo dpkg -i package.deb        # Install a .deb package
sudo dpkg -r package_name        # Remove an installed package
dpkg -l                          # List all installed packages

Archiving and Compression
Creating and Extracting Archives with tar

The tar command is versatile for creating and managing archive files. It supports various compression methods.
Examples:

sh

tar -cvf archive.tar file1 file2      # Create a tar archive
tar -czvf archive.tar.gz file1 file2  # Create a gzip-compressed tar archive
tar -xvf archive.tar                  # Extract a tar archive
tar -xzvf archive.tar.gz              # Extract a gzip-compressed tar archive

Using zip and unzip

The zip and unzip commands are used for compressing and decompressing files in zip format, respectively.
Examples:

sh

zip archive.zip file1 file2         # Create a zip archive
unzip archive.zip                   # Extract a zip archive

Using gzip and gunzip

The gzip command compresses files using the gzip algorithm, while gunzip decompresses them.
Examples:

sh

gzip file                          # Compress a file
gunzip file.gz                      # Decompress a file

Quiz Questions

    What command would you use to add a PPA to your system?
        Answer: sudo add-apt-repository ppa:repository_name

    How do you upgrade packages and handle dependencies using apt-get?
        Answer: sudo apt-get dist-upgrade

    Which command installs a .deb package using dpkg?
        Answer: sudo dpkg -i package.deb

    How do you create a gzip-compressed tar archive?
        Answer: tar -czvf archive.tar.gz file1 file2

    What command extracts files from a zip archive?
        Answer: unzip archive.zip

Study these commands and examples to understand more advanced concepts in package management and archiving/compression. Practice using them in your terminal to gain hands-on experience.
