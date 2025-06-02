#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_user() {
    char username[50];
    printf("\n🔐 SECURE USER SETUP\n");
    printf("----------------------------\n");
    printf("[+] Enter a username to create: ");
    scanf("%s", username);

    char cmd[256];
    sprintf(cmd, "sudo useradd -m -s /bin/bash %s", username);
    printf("[~] Simulating: %s\n", cmd);
    printf("[~] Simulating: sudo passwd %s\n", username);
    printf("[+] User '%s' created with a home directory and login shell.\n", username);

    printf("[~] Adding '%s' to sudo group...\n", username);
    printf("Simulating: sudo usermod -aG sudo %s\n", username);
    printf("[+] User '%s' now has sudo privileges.\n", username);
}

void secure_home_dirs() {
    printf("\n🔒 HOME DIRECTORY PERMISSIONS\n");
    printf("----------------------------\n");
    printf("[~] Locking down all user home directories...\n");
    printf("Simulating: sudo chmod 700 /home/*\n");
    printf("[+] Home directories now only accessible by their respective users.\n");
}

void configure_firewall() {
    printf("\n🛡️ FIREWALL CONFIGURATION\n");
    printf("----------------------------\n");
    printf("[~] Resetting firewall rules...\n");
    printf("Simulating: sudo iptables -F\n");

    printf("[~] Setting default input policy to DROP...\n");
    printf("Simulating: sudo iptables -P INPUT DROP\n");

    printf("[~] Allowing inbound SSH on port 22...\n");
    printf("Simulating: sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT\n");

    printf("[~] Saving rules...\n");
    printf("Simulating: sudo iptables-save > /etc/iptables.rules\n");

    printf("[+] Firewall configured: all traffic blocked except SSH.\n");
}

void configure_backup() {
    printf("\n💾 BACKUP CONFIGURATION\n");
    printf("----------------------------\n");
    printf("[~] Simulating creation of full /etc backup...\n");
    printf("Simulating: sudo tar -czvf /backups/etc_backup.tar.gz /etc\n");

    printf("[~] Setting up daily cron job for backups...\n");
    printf("Simulating: echo \"0 2 * * * tar -czf /backups/home_backup_$(date +\\%%F).tar.gz /home\" > /etc/cron.d/daily_home_backup\n");

    printf("[+] Backups are now scheduled and secured.\n");
}

void run_security_scan() {
    printf("\n🔍 SECURITY SCAN & REPORTING\n");
    printf("----------------------------\n");
    FILE *log = fopen("/tmp/system_hardening_report.log", "w");
    if (!log) {
        printf("❌ Failed to write report log.\n");
        return;
    }

    fprintf(log, "===== SYSTEM HARDENING REPORT =====\n");
    fprintf(log, "✔ Secure user created and added to sudo group\n");
    fprintf(log, "✔ Home directories restricted to owner (chmod 700)\n");
    fprintf(log, "✔ iptables active, all ports blocked except SSH (port 22)\n");
    fprintf(log, "✔ Daily cron backup job configured for /home\n");
    fprintf(log, "✔ IDS tools installed (Snort, Wireshark)\n");
    fprintf(log, "✔ No open guest accounts or unsecured services detected\n");
    fprintf(log, "✔ System ready for baseline audit and compliance scan\n");
    fclose(log);

    printf("[+] Scan complete. Report saved to /tmp/system_hardening_report.log\n");
}

void display_summary() {
    printf("\n📋 FINAL SUMMARY\n");
    printf("----------------------------\n");
    printf("✔ Hardened user added securely\n");
    printf("✔ Permissions enforced across home directories\n");
    printf("✔ Firewall rules configured to whitelist SSH only\n");
    printf("✔ Scheduled backup automation in place\n");
    printf("✔ Vulnerability scan completed and report generated\n");
    printf("System is now in a secure, operational state ✅\n");
}

int main() {
    printf("\n===============================================\n");
    printf(" Day 21: Dinner - End-to-End Security Challenge\n");
    printf("===============================================\n");

    create_user();
    secure_home_dirs();
    configure_firewall();
    configure_backup();
    run_security_scan();
    display_summary();

    printf("\n🚀 Done. You've completed the full system hardening simulation.\n");
    return 0;
}
