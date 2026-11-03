# Day 26 · Dinner — Container Primitives: Namespaces, Cgroups, Docker & Podman

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Dinner (Evening Hardening, Pipelines & Verification Lab)`  
> **Core Commands**: `unshare`, `lsns`, `systemd-cgls`, `docker`, `podman`, `chroot`

### ⚡ 60-Second Mental Model (Student Digest)

```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  ZOTHOS × 1NC0GN30 // PRODUCTION TELEMETRY, SYSTEMD & RECOVERY MATRIX        ║
╠══════════════════════════════════════════════════════════════════════════════╣
║                                                                              ║
║   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐  ║
║   │ CPU & SCHED  │   │ MEMORY / VM  │   │ DISK & VFS   │   │ NET SOCKETS  │  ║
║   │ top / mpstat │   │ free / vmstat│   │ iostat / df  │   │ ss -tulpen   │  ║
║   └──────┬───────┘   └──────┬───────┘   └──────┬───────┘   └──────┬───────┘  ║
║          └──────────────────┴─────────┬────────┴──────────────────┘          ║
║                                       ▼                                      ║
║                  [ Automated Remediation: systemd + cron + rsync ]           ║
╚══════════════════════════════════════════════════════════════════════════════╝
```

| Learning Pillar | How to Practice This Session |
| :--- | :--- |
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 26 → Dinner** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/26` → Select **Dinner** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-26 && cd /tmp/linux-dojo-day-26` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍽️ Day 26 Dinner: Practical Puppet Labs

## 🎯 Objective

Reinforce your Puppet configuration knowledge by creating and running practical manifests to automate real-world system tasks.

---

## 🧪 Lab Task 1: Write Your First Manifest

### ✨ Goal

Create a simple Puppet manifest to manage a file or a basic service on your system.

### 🛠️ Example: Create a file

```puppet
file { '/tmp/puppet_hello.txt':
  ensure  => 'present',
  content => "Hello from Puppet!\n",
}
```

### ▶️ Apply It:

```bash
sudo puppet apply hello_file.pp
```

---

## 🧪 Lab Task 2: Automate Package Management

### ✨ Goal

Use Puppet to install and manage a package like `nginx`.

### 🛠️ Example: Install and enable Nginx

```puppet
package { 'nginx':
  ensure => installed,
}

service { 'nginx':
  ensure     => running,
  enable     => true,
  require    => Package['nginx'],
}
```

### ▶️ Apply It:

```bash
sudo puppet apply nginx_install.pp
```

---

## 🧪 Lab Task 3: Puppet Troubleshooting

### ✨ Goal

Debug and fix issues in a failing manifest.

### 🧰 Troubleshooting Techniques

* Check **syntax**: `puppet parser validate <filename.pp>`
* Use `--debug` or `--verbose` when applying
* Check logs: `/var/log/puppetlabs/puppet/puppet.log` (or use `journalctl` for services)
* Validate **resource relationships** (e.g. missing `require`)

### 🔍 Debugging Example

```puppet
file { '/tmp/test.txt':
  ensure  => present,
  content => "Testing file\n",
}

exec { 'print_file':
  command => '/bin/cat /tmp/test.txt',
  require => File['/tmp/test.txt'],
}
```

---

## 🧠 Review Questions

1. What command applies a Puppet manifest locally?
2. How do you ensure a package is installed in Puppet?
3. What keyword is used to define dependencies between resources?
4. Where do you look for Puppet logs?

---

## 📚 Additional Resources

* [Puppet Official Documentation](https://puppet.com/docs/)
* [Puppet Resource Types](https://puppet.com/docs/puppet/latest/type.html)
* [Learn Puppet Exercises](https://learn.puppet.com/)
* [Validate Puppet Manifests](https://puppet.com/docs/puppet/latest/lang_validation.html)

✅ **Next Step:** Try combining `file`, `package`, and `service` resources into a single manifest to manage an application’s full lifecycle!
