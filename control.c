/*
 * ╔══════════════════════════════════════════════════════════════════════════╗
 * ║  ZOTHOS × 1NC0GN30 // 30 DAYS OF LINUX FUNDAMENTALS — DOJO TUI v3.4     ║
 * ║  Interactive Curriculum Navigator, ANSI Markdown Reader, Visual Atlas,  ║
 * ║  Command Cheat-Sheet, Flashcard Arena & Safe Terminal Sandbox           ║
 * ╚══════════════════════════════════════════════════════════════════════════╝
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <errno.h>

#define MAX_PATH_LENGTH 512
#define TOTAL_DAYS 30
#define PROGRESS_FILE ".dojo-progress"

/* ZothOS × 1nc0gn30 TrueColor / ANSI Escape Palette */
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define GOLD        "\033[38;2;245;184;46m"
#define EMERALD     "\033[38;2;57;211;83m"
#define CYAN        "\033[38;2;88;166;255m"
#define CORAL       "\033[38;2;255;123;114m"
#define PURPLE      "\033[38;2;210;168;255m"
#define SLATE       "\033[38;2;139;148;158m"
#define WHITE       "\033[38;2;240;246;252m"
#define BG_PANEL    "\033[48;2;13;17;23m"

typedef struct {
    int day;
    int week;
    const char *title;
    const char *phase;
    const char *commands;
} DayMeta;

static const DayMeta CURRICULUM[TOTAL_DAYS] = {
    { 1, 1, "Core Shell Navigation & File Operations",            "Foundations",          "ls, cd, pwd, touch, mkdir, cp, mv, rm, cat, chmod, grep, find"},
    { 2, 1, "Ownership, Process Control & Disk/Network Telemetry","Foundations",          "chown, chattr, ps, top, kill, tar, df, du, fdisk, netstat, ping"},
    { 3, 1, "Advanced File Manipulation & Scavenger Pipelines",   "Foundations",          "touch, cp -r, mv, cd -, find, grep, sed, awk, locate"},
    { 4, 1, "File Viewing, Stream Editing & Text Editors",        "Foundations",          "cat, less, more, head, tail, nano, vim, grep, sed, awk"},
    { 5, 1, "Permissions Architecture, Users & Process Signals",  "Foundations",          "chmod, chown, chgrp, umask, useradd, passwd, ps, top, kill"},
    { 6, 1, "Disk Partitioning, Archiving & Compression",         "Foundations",          "df -h, du -sh, fdisk, mount, umount, tar -czvf, gzip, zip"},
    { 7, 1, "Week 1 Capstone: Shell & Filesystem Mastery Lab",    "Foundations",          "find, xargs, tar, chmod, chown, grep, awk, sed, crontab"},
    { 8, 2, "Bash Scripting: Variables, Conditionals & Functions","System Ops",           "bash, chmod +x, echo, read, if/else, for, while, functions"},
    { 9, 2, "Process Lifecycle, Signals, Priorities & Jobs",      "System Ops",           "ps aux, top, htop, nice, renice, kill, pkill, bg, fg, nohup"},
    {10, 2, "Package Management, Repositories & Updates",         "System Ops",           "apt, dpkg, dnf, rpm, snap, flatpak, systemctl"},
    {11, 2, "Networking Stack: Interfaces, Routing, DNS & SSH",   "System Ops",           "ip addr, ip route, ss -tulpen, ping, dig, ssh, scp"},
    {12, 2, "Storage Engineering: Filesystems, Mounts & fstab",   "System Ops",           "lsblk, blkid, mkfs.ext4, mount, umount, /etc/fstab, fsck"},
    {13, 2, "System Logging, Journald & Scheduled Automation",    "System Ops",           "journalctl, /var/log/syslog, tail -f, logrotate, crontab -e"},
    {14, 2, "Week 2 Review: Kernel Modules, Sysctl & Bonding",    "System Ops",           "modprobe, lsmod, rmmod, sysctl, uname -r, fsck, ip route, rsync"},
    {15, 3, "Linux Security Hardening, Firewalls & MAC",          "Security & Workflows", "chmod 750, iptables, nftables, sshd_config, fail2ban, sestatus"},
    {16, 3, "Security Auditing, Auditd, Logwatch & Scanning",     "Security & Workflows", "auditd, auditctl, ausearch, logwatch, lynis, nmap -A, oscap"},
    {17, 3, "Network Hardening, NAT, Wireshark & Snort IDS",      "Security & Workflows", "systemctl disable, ss -tulwn, nmap, iptables -t nat, snort"},
    {18, 3, "Text Processing Pipelines: Grep, Sed, Awk & Regex",  "Security & Workflows", "grep -E, sed -i, awk, cut, sort, uniq -c, tr, wc -l, tee"},
    {19, 3, "Advanced Bash Automation, Exit Codes & Traps",       "Security & Workflows", "set -euo pipefail, trap, $?, $@, getopts, cron, rsync"},
    {20, 3, "Shell Environment Customization, Aliases & Dotfiles","Security & Workflows", "export, env, alias, ~/.bashrc, ~/.profile, source, PATH, PS1"},
    {21, 3, "User & Group Administration, Sudoers & PAM",         "Security & Workflows", "useradd, usermod, groupadd, passwd, chage, visudo, id, who"},
    {22, 4, "Systemd Services, Unit Files, Targets & Boot",       "Advanced Ops",         "systemctl, journalctl -u, systemd-analyze, hostnamectl"},
    {23, 4, "Parameterized CLI Scripts, Getopts & Tooling",       "Advanced Ops",         "getopts, shift, bash -x, printf, curl, jq"},
    {24, 4, "Performance Telemetry: CPU, Memory, Disk I/O & Load","Advanced Ops",         "vmstat, iostat, mpstat, sar, free -h, lsof, strace, uptime"},
    {25, 4, "Backup Architecture, Rsync Mirrors & Recovery",      "Advanced Ops",         "rsync -avz, tar -czvf, sha256sum, crontab, dd, scp"},
    {26, 4, "Container Primitives: Namespaces, Cgroups & Podman", "Advanced Ops",         "unshare, lsns, systemd-cgls, docker, podman, chroot"},
    {27, 4, "Troubleshooting: Boot Recovery, Locks & Forensics",  "Advanced Ops",         "journalctl -xb, dmesg, fsck, lsof, fuser, strace, ss"},
    {28, 4, "Production Server Hardening & Zero-Trust Baseline",  "Advanced Ops",         "ufw, iptables, ssh-keygen, sshd_config, fail2ban, sysctl"},
    {29, 5, "Capstone Sprint I: Multi-Tier Linux Deployment",     "Capstone Sprint",      "systemctl, ufw, rsync, crontab, journalctl, ss -tulpen"},
    {30, 5, "Capstone Sprint II: Incident Triage & Certification","Capstone Sprint",      "lynis, nmap, auditctl, iptables, tar, sha256sum, lsof"}
};

static int completed_days[TOTAL_DAYS + 1] = {0};
static int dojo_xp = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void waitEnter(const char *prompt) {
    printf("\n" GOLD "▸ %s" RESET, prompt ? prompt : "Press Enter to return...");
    fflush(stdout);
    int c = getchar();
    if (c != '\n' && c != EOF) {
        clearInputBuffer();
    }
}

void loadProgress(void) {
    memset(completed_days, 0, sizeof(completed_days));
    dojo_xp = 0;
    FILE *fp = fopen(PROGRESS_FILE, "r");
    if (!fp) return;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int d, val;
        if (sscanf(line, "day_%d=%d", &d, &val) == 2 && d >= 1 && d <= TOTAL_DAYS) {
            completed_days[d] = val ? 1 : 0;
        } else if (sscanf(line, "xp=%d", &val) == 1) {
            dojo_xp = val;
        }
    }
    fclose(fp);
}

void saveProgress(void) {
    FILE *fp = fopen(PROGRESS_FILE, "w");
    if (!fp) return;
    fprintf(fp, "xp=%d\n", dojo_xp);
    for (int d = 1; d <= TOTAL_DAYS; d++) {
        if (completed_days[d]) {
            fprintf(fp, "day_%d=1\n", d);
        }
    }
    fclose(fp);
}

int countCompleted(void) {
    int count = 0;
    for (int d = 1; d <= TOTAL_DAYS; d++) {
        if (completed_days[d]) count++;
    }
    return count;
}

void printBanner(void) {
    struct utsname uts;
    char cwd[256] = ".";
    uname(&uts);
    if (!getcwd(cwd, sizeof(cwd))) strcpy(cwd, ".");

    int done = countCompleted();
    int pct = (done * 100) / TOTAL_DAYS;
    int filled = (done * 20) / TOTAL_DAYS;

    printf("\033[H\033[J");
    printf(GOLD BOLD "╔══════════════════════════════════════════════════════════════════════════════╗\n" RESET);
    printf(GOLD BOLD "║" RESET " ⣿ " GOLD BOLD "ZOTHOS × 1NC0GN30" RESET " // " WHITE BOLD "30 DAYS OF LINUX FUNDAMENTALS — DOJO TUI v3.4" RESET "       " GOLD BOLD "║\n" RESET);
    printf(GOLD BOLD "║" RESET " ⠿ " SLATE "Sovereign Terminal & Web Training Deck • 5 Weeks • 30 Days • 90 Missions" RESET "   " GOLD BOLD "║\n" RESET);
    printf(GOLD BOLD "╠══════════════════════════════════════════════════════════════════════════════╣\n" RESET);
    printf(GOLD BOLD "║" RESET " " CYAN "KERNEL:" RESET " %-22.22s " CYAN "ARCH:" RESET " %-8.8s " EMERALD "XP:" RESET " %-6d " GOLD "STREAK:" RESET " %2d/30 Days " GOLD BOLD "║\n" RESET,
           uts.release, uts.machine, dojo_xp, done);
    printf(GOLD BOLD "║" RESET " " CYAN "PROGRESS:" RESET " [");
    for (int i = 0; i < 20; i++) {
        if (i < filled) printf(EMERALD "█" RESET);
        else printf(SLATE "░" RESET);
    }
    printf("] " BOLD "%3d%%" RESET "  " SLATE "GUI: cd astro-ui && npm run dev" RESET "     " GOLD BOLD "║\n" RESET, pct);
    printf(GOLD BOLD "╚══════════════════════════════════════════════════════════════════════════════╝\n" RESET);
}

void printSectionHeader(const char *subtitle) {
    printf("\n" GOLD "┌──────────────────────────────────────────────────────────────────────────────┐\n" RESET);
    printf(GOLD "│" RESET " " CYAN BOLD "◈ %s" RESET "\n", subtitle);
    printf(GOLD "└──────────────────────────────────────────────────────────────────────────────┘\n" RESET);
}

/* Built-in ANSI Markdown Study Guide Viewer */
void renderMarkdownFile(const char *filepath, const char *title) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        printf(CORAL "  [!] Study guide not found at: %s\n" RESET, filepath);
        waitEnter(NULL);
        return;
    }

    printBanner();
    printSectionHeader(title);
    printf(SLATE "  Source: %s\n\n" RESET, filepath);

    char line[1024];
    int in_code = 0;
    int line_count = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = 0;

        if (strncmp(line, "<!--", 4) == 0) continue;

        if (strncmp(line, "```", 3) == 0) {
            in_code = !in_code;
            if (in_code) {
                printf(SLATE "  ┌──[ code / diagram ]────────────────────────────────────────────────────\n" RESET);
            } else {
                printf(SLATE "  └────────────────────────────────────────────────────────────────────────\n" RESET);
            }
            continue;
        }

        if (in_code) {
            printf("  " SLATE "│ " EMERALD "%s\n" RESET, line);
        } else if (strncmp(line, "# ", 2) == 0) {
            printf("\n  " GOLD BOLD "══ %s ══" RESET "\n", line + 2);
        } else if (strncmp(line, "## ", 3) == 0) {
            printf("\n  " CYAN BOLD "▸ %s" RESET "\n", line + 3);
        } else if (strncmp(line, "### ", 4) == 0) {
            printf("\n  " PURPLE BOLD "• %s" RESET "\n", line + 4);
        } else if (strncmp(line, "> ", 2) == 0) {
            printf("  " GOLD "┃ " WHITE "%s\n" RESET, line + 2);
        } else if (strncmp(line, "| ", 2) == 0) {
            printf("  " CYAN "%s\n" RESET, line);
        } else if (strncmp(line, "- ", 2) == 0 || strncmp(line, "* ", 2) == 0) {
            printf("  " EMERALD "  • " WHITE "%s\n" RESET, line + 2);
        } else if (strcmp(line, "---") == 0) {
            printf("  " SLATE "─────────────────────────────────────────────────────────────────────────\n" RESET);
        } else {
            printf("  %s\n", line);
        }

        line_count++;
        if (line_count > 0 && line_count % 36 == 0) {
            printf(GOLD "\n  -- More (Enter = continue, q + Enter = quit reader) -- " RESET);
            fflush(stdout);
            int c = getchar();
            if (c == 'q' || c == 'Q') {
                clearInputBuffer();
                break;
            }
            if (c != '\n' && c != EOF) clearInputBuffer();
        }
    }

    fclose(fp);
    dojo_xp += 5;
    saveProgress();
    waitEnter("Study guide complete (+5 XP). Press Enter to return...");
}

void openGuideForDayMeal(int day, const char *meal) {
    int week = (day - 1) / 7 + 1;
    char p1[MAX_PATH_LENGTH], p2[MAX_PATH_LENGTH], p3[MAX_PATH_LENGTH];
    snprintf(p1, sizeof(p1), "week-%d/day%02d/day-%02d-study-guides/day-%02d-%s-guide.md", week, day, day, day, meal);
    snprintf(p2, sizeof(p2), "week-%d/day%02d/day-%02d-study-guides/day-%02d-%s-study-guide.md", week, day, day, day, meal);
    snprintf(p3, sizeof(p3), "astro-ui/src/content/lessons/day-%02d-%s-guide.md", day, meal);

    char title[128];
    snprintf(title, sizeof(title), "Day %02d (%s) — %s", day, meal, CURRICULUM[day - 1].title);

    if (access(p1, R_OK) == 0) {
        renderMarkdownFile(p1, title);
    } else if (access(p2, R_OK) == 0) {
        renderMarkdownFile(p2, title);
    } else if (access(p3, R_OK) == 0) {
        renderMarkdownFile(p3, title);
    } else {
        printf(CORAL "  [!] Guide file not found for Day %02d (%s)\n" RESET, day, meal);
        waitEnter(NULL);
    }
}

void runMealBinary(int day, const char *meal) {
    int week = (day - 1) / 7 + 1;
    char binPath[MAX_PATH_LENGTH];
    snprintf(binPath, sizeof(binPath), "./week-%d/day%02d/day-%02d-food/%s-day-%02d", week, day, day, meal, day);

    if (access(binPath, X_OK) == 0) {
        printf(EMERALD BOLD "\n  [▸] Launching %s interactive drill...\n\n" RESET, binPath);
        int rc = system(binPath);
        if (rc == -1) perror("system");
        dojo_xp += 15;
        saveProgress();
        waitEnter("Interactive drill finished (+15 XP). Press Enter to return to Day Menu...");
    } else {
        printf(CORAL "\n  [!] Binary not found or not executable: %s\n" RESET, binPath);
        waitEnter(NULL);
    }
}

void launchSandbox(int day) {
    char sandboxDir[128];
    snprintf(sandboxDir, sizeof(sandboxDir), "/tmp/linux-dojo-day-%02d", day);
    mkdir(sandboxDir, 0755);

    char readmePath[256];
    snprintf(readmePath, sizeof(readmePath), "%s/MISSION_NOTES.txt", sandboxDir);
    FILE *fp = fopen(readmePath, "w");
    if (fp) {
        fprintf(fp, "=== ZOTHOS x 1NC0GN30 LINUX DOJO SANDBOX (DAY %02d) ===\n", day);
        fprintf(fp, "Topic: %s\n", CURRICULUM[day - 1].title);
        fprintf(fp, "Target Commands: %s\n", CURRICULUM[day - 1].commands);
        fprintf(fp, "Practice freely in this directory. Type 'exit' to return to control-panel.\n");
        fclose(fp);
    }

    printf("\n" GOLD BOLD "╔══════════════════════════════════════════════════════════════════════════════╗\n" RESET);
    printf(GOLD BOLD "║" RESET " " EMERALD BOLD "🧪 SANDBOX SHELL ACTIVE:" RESET " %-51s " GOLD BOLD "║\n" RESET, sandboxDir);
    printf(GOLD BOLD "║" RESET " " WHITE "Target Commands:" RESET " %-59.59s " GOLD BOLD "║\n" RESET, CURRICULUM[day - 1].commands);
    printf(GOLD BOLD "║" RESET " " CYAN "Type 'exit' or press Ctrl+D at any time to return to the Dojo TUI." RESET "          " GOLD BOLD "║\n" RESET);
    printf(GOLD BOLD "╚══════════════════════════════════════════════════════════════════════════════╝\n\n" RESET);

    char cmd[512];
    snprintf(cmd, sizeof(cmd),
             "cd %s && PS1='\\[\\033[1;33m\\]1nc0gn30×zoth[day-%02d]\\[\\033[0m\\]:\\[\\033[1;36m\\]\\w\\[\\033[0m\\]$ ' bash --norc -i",
             sandboxDir, day);
    int rc = system(cmd);
    if (rc == -1) perror("system");
    dojo_xp += 10;
    saveProgress();
}

void dayDashboard(int day) {
    if (day < 1 || day > TOTAL_DAYS) return;
    int inDay = 1;
    while (inDay) {
        const DayMeta *m = &CURRICULUM[day - 1];
        printBanner();
        printf("\n" GOLD BOLD "  ╔══ DAY %02d / 30 (WEEK %d · %s) ═══════════════════════════════════════╗\n" RESET,
               m->day, m->week, m->phase);
        printf("  " GOLD "║" RESET " " WHITE BOLD "%-74s" RESET " " GOLD "║\n" RESET, m->title);
        printf("  " GOLD "║" RESET " " CYAN "Core Commands:" RESET " %-59.59s " GOLD "║\n" RESET, m->commands);
        printf("  " GOLD "║" RESET " " SLATE "Status:" RESET " %s                                                       " GOLD "║\n" RESET,
               completed_days[day] ? (EMERALD BOLD "[✓ COMPLETED]" RESET) : (GOLD "[○ IN PROGRESS]" RESET));
        printf(GOLD BOLD "  ╚════════════════════════════════════════════════════════════════════════════╝\n" RESET);

        printf("\n  " CYAN BOLD "INTERACTIVE C DRILLS (TUI QUIZZES)" RESET "\n");
        printf("    " GOLD "[1]" RESET " 🍳 Run " BOLD "Breakfast" RESET " Interactive Drill   " SLATE "(./week-%d/day%02d/day-%02d-food/breakfast-day-%02d)\n" RESET, m->week, day, day, day);
        printf("    " GOLD "[2]" RESET " 🥪 Run " BOLD "Lunch" RESET " Interactive Drill       " SLATE "(./week-%d/day%02d/day-%02d-food/lunch-day-%02d)\n" RESET, m->week, day, day, day);
        printf("    " GOLD "[3]" RESET " 🍽️ Run " BOLD "Dinner" RESET " Interactive Drill      " SLATE "(./week-%d/day%02d/day-%02d-food/dinner-day-%02d)\n" RESET, m->week, day, day, day);

        printf("\n  " EMERALD BOLD "DIGESTIBLE STUDY GUIDES & VISUAL DIAGRAMS (TERMINAL READER)" RESET "\n");
        printf("    " EMERALD "[4]" RESET " 📖 Read " BOLD "Breakfast Study Guide" RESET "        " SLATE "(Mental Model + Examples + Flags)\n" RESET);
        printf("    " EMERALD "[5]" RESET " 📖 Read " BOLD "Lunch Study Guide" RESET "            " SLATE "(Operational Workflows + Quiz)\n" RESET);
        printf("    " EMERALD "[6]" RESET " 📖 Read " BOLD "Dinner Study Guide" RESET "           " SLATE "(Hardening & Hands-On Lab)\n" RESET);

        printf("\n  " PURPLE BOLD "HANDS-ON LAB & PROGRESS" RESET "\n");
        printf("    " PURPLE "[7]" RESET " 🧪 Launch Safe Practice Shell in " CYAN "/tmp/linux-dojo-day-%02d" RESET "\n", day);
        printf("    " PURPLE "[8]" RESET " ✓  Toggle Day %02d Completion Status\n", day);
        printf("    " SLATE "[9]" RESET " ←  Next / Previous Day  (" GOLD "n" RESET " = Day %02d, " GOLD "p" RESET " = Day %02d)\n",
               day < 30 ? day + 1 : 1, day > 1 ? day - 1 : 30);
        printf("    " CORAL "[0]" RESET " ←  Back to Main Menu\n");

        printf("\n" GOLD "  Select action [0-8, n/p]: " RESET);
        char buf[32];
        if (!fgets(buf, sizeof(buf), stdin)) break;
        buf[strcspn(buf, "\r\n")] = 0;

        if (strcmp(buf, "0") == 0 || strcmp(buf, "q") == 0) {
            inDay = 0;
        } else if (strcmp(buf, "1") == 0) {
            runMealBinary(day, "breakfast");
        } else if (strcmp(buf, "2") == 0) {
            runMealBinary(day, "lunch");
        } else if (strcmp(buf, "3") == 0) {
            runMealBinary(day, "dinner");
        } else if (strcmp(buf, "4") == 0) {
            openGuideForDayMeal(day, "breakfast");
        } else if (strcmp(buf, "5") == 0) {
            openGuideForDayMeal(day, "lunch");
        } else if (strcmp(buf, "6") == 0) {
            openGuideForDayMeal(day, "dinner");
        } else if (strcmp(buf, "7") == 0) {
            launchSandbox(day);
        } else if (strcmp(buf, "8") == 0) {
            completed_days[day] = !completed_days[day];
            if (completed_days[day]) dojo_xp += 25;
            saveProgress();
        } else if (strcmp(buf, "n") == 0 || strcmp(buf, "N") == 0 || strcmp(buf, "9") == 0) {
            day = (day < TOTAL_DAYS) ? day + 1 : 1;
        } else if (strcmp(buf, "p") == 0 || strcmp(buf, "P") == 0) {
            day = (day > 1) ? day - 1 : TOTAL_DAYS;
        }
    }
}

void showCheatSheet(int interactive) {
    if (interactive) printBanner();
    printSectionHeader("ZOTHOS × 1NC0GN30 // MASTER LINUX COMMAND CHEAT-SHEET");

    printf(GOLD BOLD "\n  [01] FILESYSTEM & NAVIGATION\n" RESET);
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "pwd -P", "Print physical working directory (resolves symlinks)");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "ls -lah --color=auto", "List all files (including hidden) with human sizes & perms");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "cd -  /  cd ~", "Toggle previous directory / Jump to home directory");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "mkdir -p app/{src,logs}", "Create nested directory trees in a single command");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "cp -a src/ backup/", "Archive copy preserving permissions, owners & timestamps");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "find . -type f -name '*.sh'", "Recursively locate files matching glob or mtime/size");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "ln -s /opt/tool /usr/bin/t", "Create symbolic (soft) link pointing to target path");

    printf(GOLD BOLD "\n  [02] PERMISSIONS, OWNERSHIP & IDENTITY\n" RESET);
    printf("  " CYAN "%-26s" RESET " │ %s\n", "chmod 755 script.sh", "rwxr-xr-x (Owner: rwx=7, Group: r-x=5, Others: r-x=5)");
    printf("  " CYAN "%-26s" RESET " │ %s\n", "chmod 600 ~/.ssh/id_ed25519", "rw------- (Lock private keys strictly to owner)");
    printf("  " CYAN "%-26s" RESET " │ %s\n", "chown -R zoth:ops /srv/app", "Recursively assign user 'zoth' and group 'ops'");
    printf("  " CYAN "%-26s" RESET " │ %s\n", "sudo visudo", "Safely edit /etc/sudoers with syntax verification");
    printf("  " CYAN "%-26s" RESET " │ %s\n", "id && groups", "Inspect effective UID, GID, and supplementary groups");

    printf(GOLD BOLD "\n  [03] TEXT STREAMS, PIPES & REGEX\n" RESET);
    printf("  " PURPLE "%-26s" RESET " │ %s\n", "grep -RIn 'ERROR' /var/log", "Recursive, case-sensitive search with line numbers");
    printf("  " PURPLE "%-26s" RESET " │ %s\n", "sed -i 's/http:/https:/g' f", "In-place stream regex replacement across file");
    printf("  " PURPLE "%-26s" RESET " │ %s\n", "awk -F: '{print $1,$7}' /etc/passwd", "Extract username ($1) and login shell ($7)");
    printf("  " PURPLE "%-26s" RESET " │ %s\n", "sort access.log | uniq -c | sort -nr", "Count and rank most frequent lines in a stream");
    printf("  " PURPLE "%-26s" RESET " │ %s\n", "cmd 2>&1 | tee build.log", "Merge stderr into stdout and stream to both screen & file");

    printf(GOLD BOLD "\n  [04] PROCESSES, SYSTEMD & TELEMETRY\n" RESET);
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "ps aux --sort=-%mem | head", "Show top memory-consuming processes on the host");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "kill -15 <PID> / kill -9", "Send graceful SIGTERM (15) or immediate SIGKILL (9)");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "systemctl status nginx", "Inspect daemon state, cgroup PID tree & recent logs");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "journalctl -u ssh -f", "Follow real-time systemd journal logs for a unit");
    printf("  " EMERALD "%-26s" RESET " │ %s\n", "df -h  &&  du -sh * | sort -h", "Check mounted filesystem capacity & largest directories");

    printf(GOLD BOLD "\n  [05] NETWORKING, FIREWALLS & AUDITING\n" RESET);
    printf("  " CORAL "%-26s" RESET " │ %s\n", "ss -tulpen", "List all listening TCP/UDP sockets with PID & user");
    printf("  " CORAL "%-26s" RESET " │ %s\n", "ip -br addr  &&  ip route", "Compact network interface IPs & kernel routing table");
    printf("  " CORAL "%-26s" RESET " │ %s\n", "iptables -L -v -n", "Inspect active Netfilter packet rules & byte counters");
    printf("  " CORAL "%-26s" RESET " │ %s\n", "rsync -avzP src/ host:/dst/", "Delta-transfer archive with compression & progress bar");
    printf("  " CORAL "%-26s" RESET " │ %s\n", "sha256sum -c SHA256SUMS", "Verify cryptographic integrity of ISOs and backups");

    if (interactive) {
        waitEnter(NULL);
    }
}

void showVisualAtlas(int interactive) {
    if (interactive) printBanner();
    printSectionHeader("ZOTHOS × 1NC0GN30 // VISUAL LINUX ARCHITECTURE ATLAS");

    printf(GOLD BOLD "\n  1. THE LINUX FILESYSTEM HIERARCHY STANDARD (FHS)\n" RESET);
    printf(CYAN
           "  ┌─────────────────────────── [ / ] ROOT DIRECTORY ───────────────────────────┐\n"
           "  ├── /bin -> /usr/bin   Essential user command binaries (ls, cp, bash, cat)\n"
           "  ├── /sbin -> /usr/sbin System administration binaries (iptables, fsck, mount)\n"
           "  ├── /etc               Host-specific system configuration (passwd, fstab, ssh/)\n"
           "  ├── /home              User workspaces & dotfiles (/home/zoth/.bashrc)\n"
           "  ├── /var               Variable runtime data, spools & logs (/var/log/syslog)\n"
           "  ├── /proc              Virtual kernel & process telemetry (/proc/cpuinfo, /proc/PID)\n"
           "  ├── /dev               Device nodes (/dev/nvme0n1, /dev/null, /dev/urandom)\n"
           "  └── /tmp               Volatile scratch space (cleared on reboot)\n"
           "  └────────────────────────────────────────────────────────────────────────────┘\n" RESET);

    printf(GOLD BOLD "\n  2. CHMOD OCTAL & SYMBOLIC PERMISSION MATRIX\n" RESET);
    printf(EMERALD
           "  ┌────────────────────────────────────────────────────────────────────────────┐\n"
           "  │   FILE TYPE     OWNER (u)         GROUP (g)         OTHERS (o)             │\n"
           "  │      [-]        [ r  w  x ]       [ r  -  x ]       [ r  -  - ]            │\n"
           "  │     file         4 + 2 + 1 = 7     4 + 0 + 1 = 5     4 + 0 + 0 = 4         │\n"
           "  │                                                                            │\n"
           "  │   • 755 (-rwxr-xr-x) : Standard executable script / public directory       │\n"
           "  │   • 750 (-rwxr-x---) : Team-restricted binary / private workspace          │\n"
           "  │   • 644 (-rw-r--r--) : Standard config file or markdown document           │\n"
           "  │   • 600 (-rw-------) : Private SSH keys (~/.ssh/id_ed25519) & secrets      │\n"
           "  └────────────────────────────────────────────────────────────────────────────┘\n" RESET);

    printf(GOLD BOLD "\n  3. STANDARD STREAMS & PIPE PLUMBING\n" RESET);
    printf(PURPLE
           "  ┌────────────────────────────────────────────────────────────────────────────┐\n"
           "  │                        ┌──────────────────────┐                            │\n"
           "  │   stdin (FD 0) ──────► │   LINUX PROCESS      │ ──────► stdout (FD 1)      │\n"
           "  │   (< input.txt)        │   (grep / awk / sed) │         (> out.txt)        │\n"
           "  │                        └──────────┬───────────┘                            │\n"
           "  │                                   └───────────────────► stderr (FD 2)      │\n"
           "  │                                                         (2> err.log)       │\n"
           "  │   • Pipe (A | B)  : Connects stdout of Process A directly to stdin of B    │\n"
           "  │   • 2>&1          : Redirects stderr (2) into stdout (1) stream            │\n"
           "  └────────────────────────────────────────────────────────────────────────────┘\n" RESET);

    if (interactive) {
        waitEnter(NULL);
    }
}

void runFlashcardArena(void) {
    struct {
        const char *prompt;
        const char *answer;
        const char *hint;
    } cards[] = {
        {"List all listening TCP/UDP ports with process IDs using modern iproute2:", "ss", "Starts with 'ss' (e.g., ss -tulpen)"},
        {"Print the current working directory path:", "pwd", "3 letters: Print Working Directory"},
        {"Change file permissions to rwxr-xr-x (octal number only or full chmod):", "chmod 755", "chmod followed by 3 octal digits (7=rwx, 5=r-x)"},
        {"Search recursively for 'error' inside logs:", "grep", "Global Regular Expression Print"},
        {"View real-time systemd logs for a service unit:", "journalctl", "Systemd journal query tool"},
        {"Check mounted disk space in human-readable format:", "df -h", "Disk Free with -h flag"},
        {"Load a Linux kernel module dynamically:", "modprobe", "Module probe utility"},
        {"Synchronize directories over SSH with archive & compression:", "rsync", "Remote sync utility"}
    };
    int total = sizeof(cards) / sizeof(cards[0]);
    int score = 0;

    printBanner();
    printSectionHeader("RAPID-FIRE LINUX FLASHCARD ARENA (8 CHALLENGES)");
    printf(SLATE "  Type the base command or exact command requested. Type 'q' to exit early.\n\n" RESET);

    for (int i = 0; i < total; i++) {
        printf(GOLD BOLD "  [%d/%d] " WHITE "%s\n" RESET, i + 1, total, cards[i].prompt);
        printf(CYAN "  dojo$ " RESET);
        char ans[128];
        if (!fgets(ans, sizeof(ans), stdin)) break;
        ans[strcspn(ans, "\r\n")] = 0;
        if (strcmp(ans, "q") == 0) break;

        if (strstr(ans, cards[i].answer) != NULL ||
            (strcmp(cards[i].answer, "chmod 755") == 0 && strcmp(ans, "755") == 0)) {
            printf(EMERALD BOLD "  ✓ Correct! (+10 XP)\n\n" RESET);
            score++;
            dojo_xp += 10;
        } else {
            printf(CORAL "  ✗ Hint: %s  |  Expected: `%s`\n\n" RESET, cards[i].hint, cards[i].answer);
        }
    }

    saveProgress();
    printf(GOLD BOLD "  Arena Complete! Score: %d/%d  |  Total Dojo XP: %d\n" RESET, score, total, dojo_xp);
    waitEnter(NULL);
}

void browseCurriculumMenu(void) {
    int browsing = 1;
    while (browsing) {
        printBanner();
        printSectionHeader("30-DAY LINUX CURRICULUM MATRIX (WEEKS 1–5)");

        for (int w = 1; w <= 5; w++) {
            int start = (w - 1) * 7 + 1;
            int end = (w * 7 <= TOTAL_DAYS) ? w * 7 : TOTAL_DAYS;
            printf("\n  " GOLD BOLD "▸ WEEK %d (DAYS %02d–%02d) — %s\n" RESET,
                   w, start, end, CURRICULUM[start - 1].phase);
            for (int d = start; d <= end; d++) {
                const char *badge = completed_days[d] ? (EMERALD "✓" RESET) : (SLATE "○" RESET);
                printf("    [%s] " CYAN BOLD "Day %02d" RESET " │ %-48.48s " SLATE "(%-.22s...)\n" RESET,
                       badge, d, CURRICULUM[d - 1].title, CURRICULUM[d - 1].commands);
            }
        }

        printf("\n" GOLD "  Enter Day number [1-30] to open (or 0 to return): " RESET);
        char buf[32];
        if (!fgets(buf, sizeof(buf), stdin)) break;
        int d = atoi(buf);
        if (d == 0) {
            browsing = 0;
        } else if (d >= 1 && d <= TOTAL_DAYS) {
            dayDashboard(d);
        }
    }
}

void printCliHelp(const char *prog) {
    printf(GOLD BOLD "ZothOS × 1nc0gn30 — 30 Days of Linux Fundamentals TUI v3.4\n" RESET);
    printf("Usage: %s [OPTION]\n\n", prog);
    printf("Options:\n");
    printf("  (no args)         Launch interactive Sovereign Linux Dojo TUI\n");
    printf("  --day <1-30>      Jump directly into Day <N> Mission Dashboard\n");
    printf("  --cheatsheet      Print Master Linux Command Cheat-Sheet to stdout\n");
    printf("  --atlas           Print Visual Linux Architecture Atlas (FHS, chmod, pipes)\n");
    printf("  --status          Show 30-day completion status & XP telemetry\n");
    printf("  -h, --help        Display this help message\n");
}

int main(int argc, char *argv[]) {
    loadProgress();

    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            printCliHelp(argv[0]);
            return 0;
        }
        if (strcmp(argv[1], "--cheatsheet") == 0) {
            showCheatSheet(0);
            return 0;
        }
        if (strcmp(argv[1], "--atlas") == 0) {
            showVisualAtlas(0);
            return 0;
        }
        if (strcmp(argv[1], "--status") == 0) {
            printBanner();
            printf("\n  Completed Days: %d / %d  |  Dojo XP: %d\n\n", countCompleted(), TOTAL_DAYS, dojo_xp);
            return 0;
        }
        if (strcmp(argv[1], "--day") == 0 && argc > 2) {
            int d = atoi(argv[2]);
            if (d >= 1 && d <= TOTAL_DAYS) {
                dayDashboard(d);
                return 0;
            }
        }
    }

    int running = 1;
    while (running) {
        printBanner();
        printf("\n  " GOLD BOLD "MAIN COMMAND DECK" RESET " — Select a training mode or type " CYAN "d<1-30>" RESET " (e.g. " CYAN "d1" RESET "):\n\n");
        printf("    " GOLD BOLD "[1]" RESET " 🗺️  " WHITE BOLD "30-Day Curriculum Navigator" RESET "     " SLATE "(Browse Weeks 1–5, C Drills, Guides & Sandboxes)\n" RESET);
        printf("    " GOLD BOLD "[2]" RESET " ⚡  " WHITE BOLD "Direct Day Jump (Day 01–30)" RESET "     " SLATE "(Jump straight to any day's Breakfast/Lunch/Dinner)\n" RESET);
        printf("    " GOLD BOLD "[3]" RESET " 📋  " WHITE BOLD "Master Linux Cheat-Sheet" RESET "        " SLATE "(Flags & syntax for Files, Perms, Pipes, Net & Sec)\n" RESET);
        printf("    " GOLD BOLD "[4]" RESET " 🏛️  " WHITE BOLD "Visual Architecture Atlas" RESET "       " SLATE "(ASCII diagrams: FHS Tree, Chmod Matrix & Streams)\n" RESET);
        printf("    " GOLD BOLD "[5]" RESET " 🎯  " WHITE BOLD "Rapid-Fire Flashcard Arena" RESET "      " SLATE "(Test command recall & build Dojo XP)\n" RESET);
        printf("    " GOLD BOLD "[6]" RESET " 🌐  " WHITE BOLD "Web GUI Workstation Info" RESET "        " SLATE "(Launch Astro Web Mission Terminal on localhost:4321)\n" RESET);
        printf("    " CORAL BOLD "[0]" RESET " 🚪  " WHITE "Exit Dojo TUI\n" RESET);

        printf("\n" GOLD "  1nc0gn30×zoth-dojo> " RESET);
        char input[64];
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\r\n")] = 0;

        if (strcmp(input, "0") == 0 || strcmp(input, "q") == 0 || strcmp(input, "exit") == 0) {
            printf(EMERALD BOLD "\n  Keep building in the terminal. Exiting ZothOS × 1nc0gn30 Linux Dojo.\n\n" RESET);
            running = 0;
        } else if ( (input[0] == 'd' || input[0] == 'D') && atoi(input + 1) >= 1 && atoi(input + 1) <= 30 ) {
            dayDashboard(atoi(input + 1));
        } else if (strcmp(input, "1") == 0) {
            browseCurriculumMenu();
        } else if (strcmp(input, "2") == 0) {
            printf(CYAN "  Enter Day number (1–30): " RESET);
            char dbuf[32];
            if (fgets(dbuf, sizeof(dbuf), stdin)) {
                int d = atoi(dbuf);
                if (d >= 1 && d <= TOTAL_DAYS) dayDashboard(d);
            }
        } else if (strcmp(input, "3") == 0) {
            showCheatSheet(1);
        } else if (strcmp(input, "4") == 0) {
            showVisualAtlas(1);
        } else if (strcmp(input, "5") == 0) {
            runFlashcardArena();
        } else if (strcmp(input, "6") == 0) {
            printBanner();
            printSectionHeader("WEB GUI WORKSTATION (ASTRO MISSION TERMINAL)");
            printf("  The companion Web GUI provides an interactive browser terminal, XP & Streak\n");
            printf("  tracking, live Chmod Octal Calculator, FHS Explorer, and all 90 Study Guides.\n\n");
            printf("  " EMERALD BOLD "To launch the Web GUI locally:" RESET "\n");
            printf("    " CYAN "$ cd astro-ui && npm install && npm run dev\n" RESET);
            printf("    " SLATE "Then open http://localhost:4321 in your browser.\n" RESET);
            waitEnter(NULL);
        }
    }

    return 0;
}
