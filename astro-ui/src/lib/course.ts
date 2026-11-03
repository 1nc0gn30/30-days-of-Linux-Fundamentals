export const TOTAL_DAYS = 30;

export interface DayMeta {
  day: number;
  weekId: number;
  title: string;
  phase: string;
  summary: string;
  commands: string[];
}

export const COURSE_WEEKS = [
  {
    id: 1,
    title: 'Week 1: Linux Foundations & File Mastery',
    summary: 'Shell navigation, FHS directory architecture, file manipulation, octal permissions (chmod/chown), streams, and archives.',
    startDay: 1,
    endDay: 7,
    accent: '#F5B82E',
  },
  {
    id: 2,
    title: 'Week 2: System Operations, Kernel & Networking',
    summary: 'Bash scripting fundamentals, process lifecycle & signals, package managers, iproute2 networking, storage mounts, and kernel modules.',
    startDay: 8,
    endDay: 14,
    accent: '#39D353',
  },
  {
    id: 3,
    title: 'Week 3: Security Hardening, Auditing & Text Pipelines',
    summary: 'Firewalls (iptables/nftables), SSH hardening, auditd & Lynis scanning, Wireshark/Snort IDS, grep/sed/awk pipelines, and sudoers/PAM.',
    startDay: 15,
    endDay: 21,
    accent: '#58A6FF',
  },
  {
    id: 4,
    title: 'Week 4: Production Engineering, Telemetry & Containers',
    summary: 'Systemd unit orchestration, parameterized CLI tools, CPU/RAM/I/O performance telemetry, rsync backups, namespaces/cgroups, and forensics.',
    startDay: 22,
    endDay: 28,
    accent: '#D2A8FF',
  },
  {
    id: 5,
    title: 'Week 5: Sovereign Operator Capstone Sprint',
    summary: 'Full-stack multi-tier Linux infrastructure deployment, live incident triage, security auditing, and final operator verification.',
    startDay: 29,
    endDay: 30,
    accent: '#FF7B72',
  },
] as const;

export const DAY_METADATA: DayMeta[] = [
  { day: 1, weekId: 1, title: 'Core Shell Navigation & File Operations', phase: 'Foundations', summary: 'Navigate the filesystem, create/copy/move files, inspect contents, and create symbolic links.', commands: ['ls -la', 'cd', 'pwd', 'touch', 'mkdir -p', 'cp', 'mv', 'rm', 'cat', 'chmod', 'grep', 'ln -s'] },
  { day: 2, weekId: 1, title: 'Ownership, Process Control & Disk/Network Telemetry', phase: 'Foundations', summary: 'Manage user/group ownership, inspect running processes, archive directories, and probe network reachability.', commands: ['chown', 'chattr', 'ps aux', 'top', 'kill', 'tar -czvf', 'df -h', 'du -sh', 'netstat', 'ping', 'traceroute'] },
  { day: 3, weekId: 1, title: 'Advanced File Manipulation & Scavenger Pipelines', phase: 'Foundations', summary: 'Combine directory traversal with recursive file searches, pattern matching, and stream transformations.', commands: ['touch', 'cp -r', 'mv', 'cd -', 'find', 'grep -R', 'sed', 'awk', 'locate'] },
  { day: 4, weekId: 1, title: 'File Viewing, Stream Editing & Text Editors', phase: 'Foundations', summary: 'Inspect logs with pagers, edit configs in nano and vim, and filter/transform text with grep, sed, and awk.', commands: ['cat', 'less', 'head -n 20', 'tail -f', 'nano', 'vim', 'grep', 'sed', 'awk'] },
  { day: 5, weekId: 1, title: 'Permissions Architecture, Users & Process Signals', phase: 'Foundations', summary: 'Master octal (755/644/600) and symbolic permissions, user creation, and process scheduling priorities.', commands: ['chmod 755', 'chown', 'umask', 'useradd', 'passwd', 'ps', 'top', 'kill -9', 'nice', 'renice'] },
  { day: 6, weekId: 1, title: 'Disk Partitioning, Archiving & Compression', phase: 'Foundations', summary: 'Analyze block storage usage, partition disks, mount filesystems, and compress archives with tar/gzip/zip.', commands: ['df -h', 'du -sh *', 'fdisk -l', 'mount', 'umount', 'tar -xzvf', 'gzip', 'gunzip', 'zip'] },
  { day: 7, weekId: 1, title: 'Week 1 Capstone: Shell & Filesystem Mastery Lab', phase: 'Foundations', summary: 'Synthesize Week 1 skills into multi-stage find/xargs pipelines, automated backups, and permission audits.', commands: ['find', 'xargs', 'tar -czvf', 'chmod', 'chown', 'grep', 'awk', 'sed', 'crontab -l'] },
  { day: 8, weekId: 2, title: 'Bash Scripting: Variables, Conditionals & Functions', phase: 'System Ops', summary: 'Write executable Bash scripts with variables, if/else branches, loops, and reusable functions.', commands: ['bash', 'chmod +x', 'echo', 'read', 'export', 'env', 'grep', 'sed'] },
  { day: 9, weekId: 2, title: 'Process Lifecycle, Signals, Priorities & Job Control', phase: 'System Ops', summary: 'Control foreground/background jobs, send POSIX signals (SIGTERM/SIGKILL), and tune CPU nice levels.', commands: ['ps aux', 'top', 'htop', 'nice', 'renice', 'kill -15', 'pkill', 'nohup', 'jobs'] },
  { day: 10, weekId: 2, title: 'Package Management, Repositories & System Updates', phase: 'System Ops', summary: 'Install, audit, and upgrade packages across Debian/Ubuntu (apt/dpkg) and Enterprise Linux (dnf/rpm).', commands: ['apt update', 'apt install', 'dpkg -l', 'dnf', 'systemctl', 'curl', 'wget'] },
  { day: 11, weekId: 2, title: 'Networking Stack: Interfaces, Routing, DNS & SSH', phase: 'System Ops', summary: 'Inspect network interfaces, kernel routing tables, active sockets, DNS resolution, and SSH tunnels.', commands: ['ip addr', 'ip route', 'ss -tulpen', 'ping', 'dig', 'nslookup', 'ssh', 'scp'] },
  { day: 12, weekId: 2, title: 'Storage Engineering: Filesystems, Mounts & fstab', phase: 'System Ops', summary: 'Format ext4/XFS partitions, configure persistent mounts in /etc/fstab, and verify filesystem integrity.', commands: ['lsblk', 'mount', 'umount', 'fsck', 'df -h', 'du -sh', 'fdisk'] },
  { day: 13, weekId: 2, title: 'System Logging, Journald & Scheduled Automation', phase: 'System Ops', summary: 'Query structured systemd journals, rotate /var/log files, and schedule recurring cron jobs.', commands: ['journalctl -xe', 'tail -f /var/log/syslog', 'crontab -e', 'systemctl', 'grep', 'awk'] },
  { day: 14, weekId: 2, title: 'Week 2 Review: Kernel Modules, Sysctl & Bonding', phase: 'System Ops', summary: 'Load/unload Linux kernel modules dynamically, tune runtime sysctl parameters, and configure network routes.', commands: ['modprobe', 'lsmod', 'rmmod', 'sysctl', 'uname -r', 'fsck', 'ip route', 'rsync -avz'] },
  { day: 15, weekId: 3, title: 'Linux Security Hardening, Firewalls & MAC', phase: 'Security & Workflows', summary: 'Harden file permissions, configure iptables/nftables packet filtering, lock down SSH, and inspect SELinux/AppArmor.', commands: ['chmod 750', 'chown', 'iptables -L', 'sshd_config', 'fail2ban', 'sestatus', 'sudo'] },
  { day: 16, weekId: 3, title: 'Security Auditing, Auditd, Logwatch & Scanning', phase: 'Security & Workflows', summary: 'Track syscall and file integrity events with auditd, parse logs with logwatch, and run Lynis/Nmap audits.', commands: ['systemctl start auditd', 'cat /var/log/syslog', 'logwatch', 'nmap -A', 'iptables -L', 'tail -f'] },
  { day: 17, weekId: 3, title: 'Network Hardening, NAT, Wireshark & Snort IDS', phase: 'Security & Workflows', summary: 'Disable unneeded services, enumerate open sockets with ss/nmap, configure iptables NAT, and run Snort IDS.', commands: ['systemctl disable', 'ss -tulwn', 'netstat -tulpn', 'nmap', 'iptables -L -v', 'snort', 'wireshark'] },
  { day: 18, weekId: 3, title: 'Text Processing Pipelines: Grep, Sed, Awk & Regex', phase: 'Security & Workflows', summary: 'Chain regex searches, stream editors, and column processors to extract actionable intelligence from logs.', commands: ['grep -E', 'sed', 'awk', 'cut', 'sort', 'uniq -c', 'tr', 'wc -l', 'tee'] },
  { day: 19, weekId: 3, title: 'Advanced Bash Automation, Exit Codes & Traps', phase: 'Security & Workflows', summary: 'Build resilient production scripts with strict error handling, signal traps, and automated logging.', commands: ['bash', 'chmod +x', 'crontab', 'rsync', 'tar', 'grep', 'find'] },
  { day: 20, weekId: 3, title: 'Shell Environment Customization, Aliases & Dotfiles', phase: 'Security & Workflows', summary: 'Configure persistent environment variables, PATH exports, productivity aliases, and custom prompts in ~/.bashrc.', commands: ['export', 'env', 'alias', 'source ~/.bashrc', 'echo', 'cat'] },
  { day: 21, weekId: 3, title: 'User & Group Administration, Sudoers & PAM Security', phase: 'Security & Workflows', summary: 'Provision operator accounts, enforce password aging policies, and manage least-privilege sudoers access.', commands: ['useradd -m', 'usermod -aG', 'userdel', 'groupadd', 'passwd', 'id', 'who', 'whoami'] },
  { day: 22, weekId: 4, title: 'Systemd Services, Unit Files, Targets & Boot', phase: 'Advanced Ops', summary: 'Author custom systemd service units, manage daemon lifecycles, and analyze boot performance.', commands: ['systemctl status', 'systemctl restart', 'journalctl -u', 'hostnamectl', 'uname -a'] },
  { day: 23, weekId: 4, title: 'Parameterized CLI Scripts, Getopts & Tooling', phase: 'Advanced Ops', summary: 'Parse CLI flags with getopts, validate inputs, and build modular command-line utilities.', commands: ['bash', 'chmod +x', 'echo', 'grep', 'awk', 'sed', 'curl'] },
  { day: 24, weekId: 4, title: 'Performance Telemetry: CPU, Memory, Disk I/O & Load', phase: 'Advanced Ops', summary: 'Diagnose CPU bottlenecks, memory pressure, swap thrashing, and disk I/O latency in real time.', commands: ['top', 'htop', 'free -h', 'vmstat 1 5', 'iostat -x', 'sar -u 1 3', 'df -h', 'lsof'] },
  { day: 25, weekId: 4, title: 'Backup Architecture, Rsync Mirrors & Recovery', phase: 'Advanced Ops', summary: 'Design automated incremental backups with rsync and tar, verify SHA-256 checksums, and test restores.', commands: ['tar -czvf', 'tar -xzvf', 'rsync', 'scp', 'sha256sum', 'crontab -e'] },
  { day: 26, weekId: 4, title: 'Container Primitives: Namespaces, Cgroups & Podman', phase: 'Advanced Ops', summary: 'Understand how Linux kernel namespaces and cgroups power rootless Podman and Docker containers.', commands: ['ps aux', 'systemctl', 'ip addr', 'mount', 'df -h', 'uname -r'] },
  { day: 27, weekId: 4, title: 'Troubleshooting: Boot Recovery, Locks & Forensics', phase: 'Advanced Ops', summary: 'Triage broken boot sequences, trace open file descriptors with lsof, and inspect kernel ring buffers.', commands: ['journalctl', 'fsck', 'lsof', 'ps aux', 'ss -tulpen', 'df -h', 'mount'] },
  { day: 28, weekId: 4, title: 'Production Server Hardening & Zero-Trust Baseline', phase: 'Advanced Ops', summary: 'Apply comprehensive defense-in-depth across SSH, netfilter firewalls, sysctl kernel flags, and audit logs.', commands: ['iptables', 'ssh', 'chmod 600', 'chown', 'systemctl', 'journalctl', 'sha256sum'] },
  { day: 29, weekId: 5, title: 'Capstone Sprint I: Multi-Tier Linux Deployment', phase: 'Capstone Sprint', summary: 'Deploy, network, and secure a production Linux service stack with automated systemd units and backups.', commands: ['systemctl', 'ss -tulpen', 'iptables', 'tar -czvf', 'crontab -e', 'journalctl'] },
  { day: 30, weekId: 5, title: 'Capstone Sprint II: Incident Triage & Certification', phase: 'Capstone Sprint', summary: 'Execute a full security & performance audit, remediate live findings, and complete the 30-Day Linux Dojo.', commands: ['ps aux', 'ss -tulpen', 'iptables -L', 'df -h', 'du -sh *', 'grep -R', 'sha256sum', 'journalctl'] },
];

export function getDayMeta(day: number): DayMeta {
  return (
    DAY_METADATA.find((d) => d.day === day) ?? {
      day,
      weekId: Math.ceil(day / 7),
      title: `Day ${day} Linux Mission`,
      phase: 'Linux Fundamentals',
      summary: 'Hands-on Linux command drills and guided study sessions.',
      commands: ['ls -la', 'pwd', 'cd', 'grep', 'chmod'],
    }
  );
}

export function getWeekForDay(day: number) {
  return COURSE_WEEKS.find((week) => day >= week.startDay && day <= week.endDay);
}

export function getPreviousDay(day: number) {
  if (day <= 1) return null;
  return day - 1;
}

export function getNextDay(day: number) {
  if (day >= TOTAL_DAYS) return null;
  return day + 1;
}
