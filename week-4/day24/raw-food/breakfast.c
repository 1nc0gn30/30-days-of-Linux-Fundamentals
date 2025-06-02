#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define CYAN_COLOR "\033[36m"
#define BOLD_COLOR "\033[1m"

void show_title() {
    printf(BOLD_COLOR CYAN_COLOR "\nDay 24 - Breakfast: Introduction to Ansible\n" RESET_COLOR);
    printf("--------------------------------------------\n\n");
}

void explain_ansible() {
    printf(BOLD_COLOR GREEN_COLOR "\nWhat is Ansible?\n" RESET_COLOR);
    printf("Ansible is an open-source automation tool used for configuration management,\n");
    printf("application deployment, and task automation.\n\n");
    printf("Key Features:\n");
    printf("- Agentless (uses SSH to communicate)\n");
    printf("- Uses YAML-based playbooks\n");
    printf("- Easy to learn and scales well\n");
    printf("- Widely used in DevOps workflows\n");
}

void installation_steps() {
    printf(BOLD_COLOR GREEN_COLOR "\nInstalling Ansible:\n" RESET_COLOR);
    printf("On Debian/Ubuntu:\n");
    printf("  sudo apt update\n  sudo apt install ansible -y\n\n");
    printf("With pip (Python):\n");
    printf("  pip install ansible\n\n");
    printf("Verify Installation:\n");
    printf("  ansible --version\n");
}

void explain_playbooks() {
    printf(BOLD_COLOR GREEN_COLOR "\nCore Concept: Playbooks\n" RESET_COLOR);
    printf("- Written in YAML\n- Define tasks to run on managed nodes\n- Can target groups of machines\n\nExample:\n");
    printf("- name: Install Apache\n  hosts: webservers\n  become: yes\n  tasks:\n    - name: Install apache2\n      apt:\n        name: apache2\n        state: present\n");
}

void explain_inventory() {
    printf(BOLD_COLOR GREEN_COLOR "\nCore Concept: Inventory\n" RESET_COLOR);
    printf("An inventory is a file that lists managed hosts.\n\nExample:\n");
    printf("[webservers]\n192.168.1.10\n192.168.1.11\n\n[dbservers]\n192.168.1.20\n\n");
    printf("Ping test:\n  ansible all -i hosts -m ping\n");
}

void explain_modules() {
    printf(BOLD_COLOR GREEN_COLOR "\nCore Concept: Modules\n" RESET_COLOR);
    printf("Modules are units of work Ansible ships and runs.\n\nCommon Modules:\n");
    printf("- ping     => test connectivity\n");
    printf("- apt/yum  => manage packages\n");
    printf("- copy     => copy files\n");
    printf("- service  => start/stop services\n");
    printf("- command  => run shell commands\n\n");
    printf("Example:\n");
    printf("  ansible webservers -m apt -a \"name=nginx state=present\" -b\n");
}

void review_questions() {
    printf(BOLD_COLOR YELLOW_COLOR "\nReview Questions:\n" RESET_COLOR);
    printf("1. What makes Ansible \"agentless\"?\n");
    printf("2. What language are Ansible playbooks written in?\n");
    printf("3. What is the -m flag used for in Ansible?\n");
    printf("4. How is an inventory file structured?\n");
}

int main() {
    show_title();
    explain_ansible();
    installation_steps();
    explain_playbooks();
    explain_inventory();
    explain_modules();
    review_questions();
    printf(GREEN_COLOR "\nBreakfast complete. Ready to write your first playbook!\n" RESET_COLOR);
    return 0;
}
