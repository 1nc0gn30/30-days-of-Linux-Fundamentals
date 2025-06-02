#include <stdio.h>
#include <stdlib.h>

void user_permissions_lab() {
    printf("\n🔐 LAB: User Permissions Deep Dive\n");
    printf("------------------------------------------------\n");
    printf("Scenario: You need to create a secure user with limited access.\n");

    printf("\n📌 Step 1: Create a new system user\n");
    printf("   Command: sudo useradd -m -s /bin/bash secure_user\n");
    printf("   🔍 Creates the user with a home directory and default shell\n");

    printf("\n📌 Step 2: Set the user's password\n");
    printf("   Command: sudo passwd secure_user\n");
    printf("   🔐 Enforces credential access for login\n");

    printf("\n📌 Step 3: Add user to sudo group for administrative tasks\n");
    printf("   Command: sudo usermod -aG sudo secure_user\n");
    printf("   🔒 Controls privilege escalation\n");

    printf("\n📌 Step 4: Lock down home directory permissions\n");
    printf("   Command: sudo chmod 700 /home/secure_user\n");
    printf("   🔏 Ensures only the user has read/write/execute access to their home\n");

    printf("\n✅ User setup complete. User 'secure_user' is now minimal-privilege by default.\n\n");
}

void firewall_lab() {
    printf("\n🛡️ LAB: Firewall Rule Configuration\n");
    printf("------------------------------------------------\n");
    printf("Scenario: Harden the system by limiting open ports using iptables.\n");

    printf("\n📌 Step 1: Flush old rules (clean slate)\n");
    printf("   Command: sudo iptables -F\n");

    printf("\n📌 Step 2: Set default inbound policy to DROP\n");
    printf("   Command: sudo iptables -P INPUT DROP\n");
    printf("   🔐 Prevents all traffic unless explicitly allowed\n");

    printf("\n📌 Step 3: Allow SSH (for remote access)\n");
    printf("   Command: sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT\n");
    printf("   📡 Allows essential secure access\n");

    printf("\n📌 Step 4: Save firewall rules\n");
    printf("   Command: sudo iptables-save > /etc/iptables.rules\n");
    printf("   💾 Stores rule set for persistence\n");

    printf("\n⚠️ NOTE: For production systems, use nftables or UFW for modern configs.\n");
    printf("✅ Firewall configuration simulation complete.\n\n");
}

void ids_lab() {
    printf("\n🕵️ LAB: IDS Tool Simulation (Snort & Wireshark)\n");
    printf("------------------------------------------------\n");
    printf("Scenario: Analyze network traffic for suspicious activity.\n");

    printf("\n📌 Step 1: Launch Snort in console mode (simulated)\n");
    printf("   Command: sudo snort -A console -i eth0 -c /etc/snort/snort.conf\n");
    printf("   🧠 Snort detects protocol anomalies, scans, exploits\n");

    printf("\n📌 Step 2: Open Wireshark and begin packet capture\n");
    printf("   Command: sudo wireshark &\n");
    printf("   🧪 GUI tool to analyze packets and real-time traffic\n");

    printf("\n📌 Step 3: Apply filters (e.g., tcp.port == 80, http)\n");
    printf("   🔍 Allows visual analysis of targeted protocol behavior\n");

    printf("\n✅ IDS tools prepared. You're now monitoring and defending the network.\n\n");
}

void backup_restore_lab() {
    printf("\n🧰 LAB: Backup Restoration Practice\n");
    printf("------------------------------------------------\n");
    printf("Scenario: Restore important data after a system failure.\n");

    printf("\n📌 Step 1: Locate the backup archive\n");
    printf("   Example: /backups/home_backup_2025-06-01.tar.gz\n");

    printf("\n📌 Step 2: Restore to the original location\n");
    printf("   Command: sudo tar -xzvf /backups/home_backup_2025-06-01.tar.gz -C /\n");

    printf("\n📌 Step 3: Verify file integrity\n");
    printf("   Command: sha256sum -c checksums.txt\n");

    printf("\n📌 Step 4: Restart services if config files were restored\n");
    printf("   Command: sudo systemctl restart sshd\n");

    printf("\n✅ Backup restoration simulated successfully.\n\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n=============================================\n");
        printf(" Day 21: Lunch - Hands-On Security Labs Menu\n");
        printf("=============================================\n");
        printf("1. Secure User Setup & Permissions\n");
        printf("2. Firewall Rule Configuration\n");
        printf("3. IDS Tools: Snort & Wireshark\n");
        printf("4. Backup Restoration Simulation\n");
        printf("5. Exit\n");
        printf("Select a lab to simulate: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                user_permissions_lab();
                break;
            case 2:
                firewall_lab();
                break;
            case 3:
                ids_lab();
                break;
            case 4:
                backup_restore_lab();
                break;
            case 5:
                printf("Exiting lab simulation. Onward to dinner challenge...\n");
                return 0;
            default:
                printf("❌ Invalid selection. Please choose a valid lab.\n");
        }
    }

    return 0;
}
