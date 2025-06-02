#include <stdio.h>

int main() {
    int answer;

    printf("=============================================\n");
    printf(" Day 21: Week 3 Recap - Security Deep Dive\n");
    printf("=============================================\n\n");

    // User Management & Permissions
    printf("🔐 USER MANAGEMENT & PERMISSIONS\n");
    printf("---------------------------------------------\n");
    printf("• Create users:         useradd <username>\n");
    printf("• Modify users:         usermod -aG <group> <username>\n");
    printf("• Set passwords:        passwd <username>\n");
    printf("• File ownership:       chown <user>:<group> <file>\n");
    printf("• File permissions:     chmod 755 <file>\n");
    printf("• View permissions:     ls -l <file>\n");
    printf("• Add user to sudoers:  usermod -aG sudo <username>\n\n");

    // Firewall Configuration
    printf("🛡️ FIREWALL CONFIGURATION\n");
    printf("---------------------------------------------\n");
    printf("• iptables - legacy firewall manager\n");
    printf("• nftables - modern replacement (faster, simpler)\n");
    printf("• Basic examples:\n");
    printf("   - sudo iptables -L\n");
    printf("   - sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT\n");
    printf("   - sudo iptables -P INPUT DROP\n\n");

    // IDS
    printf("🕵️ INTRUSION DETECTION SYSTEMS\n");
    printf("---------------------------------------------\n");
    printf("• Snort: Real-time network monitoring and packet logging\n");
    printf("• Wireshark: GUI packet analyzer for protocol inspection\n\n");

    // SELinux & AppArmor
    printf("🔐 SELinux / AppArmor\n");
    printf("---------------------------------------------\n");
    printf("• SELinux: Mandatory Access Control with policy enforcement\n");
    printf("• AppArmor: Profile-based access control system\n");
    printf("• Commands:\n");
    printf("   - sestatus\n");
    printf("   - sudo setenforce 0 (temporary permissive mode)\n");
    printf("   - sudo aa-status\n\n");

    // QUIZ SECTION
    printf("📝 MULTIPLE CHOICE QUIZ\n");
    printf("---------------------------------------------\n");

    printf("Q1: What command changes file permissions in Linux?\n");
    printf("1. chperm\n2. chown\n3. chmod\n4. setperm\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 3) printf("✅ Correct!\n\n");
    else printf("❌ Incorrect. The correct answer is 3. chmod\n\n");

    printf("Q2: Which tool is used for real-time packet inspection?\n");
    printf("1. Snort\n2. Lynis\n3. iptables\n4. netstat\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 1) printf("✅ Correct!\n\n");
    else printf("❌ Incorrect. The correct answer is 1. Snort\n\n");

    printf("Q3: How do you temporarily set SELinux to permissive mode?\n");
    printf("1. sudo selinux off\n2. sudo setenforce 0\n3. set-permissive on\n4. disable-selinux\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);
    if (answer == 2) printf("✅ Correct!\n\n");
    else printf("❌ Incorrect. The correct answer is 2. sudo setenforce 0\n\n");

    printf("🎉 Quiz Complete! Great job reviewing Week 3.\n");

    return 0;
}
