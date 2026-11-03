# Day 26 · Breakfast — Container Primitives: Namespaces, Cgroups, Docker & Podman

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Breakfast (Morning Foundation & Core Command Syntax)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 26 → Breakfast** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/26` → Select **Breakfast** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-26 && cd /tmp/linux-dojo-day-26` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🍽️ Day 26 Breakfast: Introduction to Puppet

## 🎯 Objective

Understand what Puppet is, how it helps automate configuration management, and get it set up on your Linux system.

---

## 🤖 What is Puppet?

Puppet is a configuration management tool used to automate the setup, management, and maintenance of system configurations across many machines.

### 📌 Puppet is used for:

* ✅ Enforcing system state (e.g., ensure a package is always installed)
* 🔄 Idempotent changes (applying the same config multiple times has no additional effect)
* 🔐 Infrastructure as Code (IaC) principles

Unlike Ansible, Puppet operates using a **master-agent** architecture (although standalone use is possible).

---

## 💾 Installing Puppet

### 🐧 On Debian/Ubuntu (Agent Only)

```bash
wget https://apt.puppetlabs.com/puppet-release-focal.deb
sudo dpkg -i puppet-release-focal.deb
sudo apt update
sudo apt install puppet-agent -y
```

### 🧠 Master Setup

Master nodes are typically set up in larger environments and require:

* A Puppet Server
* SSL Certificate generation
* Facter and PuppetDB (for advanced setups)

---

## 🧠 Puppet Basic Concepts

### 📜 Manifests

Puppet manifests are files with the `.pp` extension written in Puppet DSL (Domain Specific Language).

```puppet
file { '/tmp/example.txt':
  ensure  => 'present',
  content => 'Hello from Puppet!',
}
```

### 📦 Modules

Modules are self-contained bundles of manifests, files, and templates. You use them to organize reusable configurations.

```bash
puppet module generate yourname-sample
```

### 📂 Resources

Resources are the basic building blocks in Puppet used to describe system entities like files, services, and packages.

```puppet
package { 'nginx':
  ensure => installed,
}
```

---

## 🔁 Puppet Workflow

1. **Write a manifest** describing desired state
2. **Apply the manifest** with `puppet apply`
3. **Puppet evaluates and enforces** the system configuration

```bash
puppet apply my_manifest.pp
```

---

## 🧠 Review Questions

1. What is the difference between Puppet and Ansible in terms of architecture?
2. What is a manifest in Puppet?
3. How does Puppet ensure idempotency?
4. What is the role of a module in Puppet?

---

## 📚 Recommended Reading

* [Puppet Official Docs](https://puppet.com/docs/)
* [Learn Puppet Manifest Basics](https://puppet.com/docs/puppet/latest/lang_write_functions.html)
* [DigitalOcean Puppet Install Guide](https://www.digitalocean.com/community/tutorial_series/puppet-configuration-management)

✅ **Next Step**: Practice writing your first Puppet manifest to control a file or package.
