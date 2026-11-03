# Day 26 · Lunch — Container Primitives: Namespaces, Cgroups, Docker & Podman

> **ZothOS × 1nc0gn30 Linux Dojo** · **Phase**: `Week 4 (Advanced Ops)` · **Session**: `Lunch (Midday Operational Workflows & Flag Mastery)`  
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
| **1. Native TUI (`./control-panel`)** | Run `./control-panel` from repo root → Select **Week 4 → Day 26 → Lunch** to drill interactive C lessons & quizzes. |
| **2. Web Workstation (`astro-ui`)** | Open `/day/26` → Select **Lunch** tab → Type each target command in the live Mission Terminal to earn XP & streak mastery. |
| **3. Safe Local Sandbox** | Run `mkdir -p /tmp/linux-dojo-day-26 && cd /tmp/linux-dojo-day-26` to test every flag below without touching production files. |

---
<!-- ZOTH-1NC0GN30-DIGESTIBLE-BLUEPRINT -->

# 🥗 Day 26 Lunch: Writing Puppet Manifests

## 🎯 Objective

Learn how to write Puppet manifests, understand Puppet's built-in resources, and apply configurations to specific nodes.

---

## 📘 What is a Manifest?

A **manifest** is a file written in Puppet's DSL (Domain Specific Language) that defines how resources should be managed.

* File extension: `.pp`
* Can contain one or more **resources** and **classes**

### 🧠 Example Manifest

```puppet
file { '/tmp/example.txt':
  ensure  => 'present',
  content => 'Managed by Puppet!\n',
}
```

This manifest ensures a file `/tmp/example.txt` exists with the specified content.

---

## 🧱 Puppet Resources

Resources describe the desired state of a part of the system, such as packages, files, or services.

### 📦 Common Resource Types

#### 🗃️ File

```puppet
file { '/etc/motd':
  ensure  => 'file',
  content => 'Welcome to the server!',
}
```

#### 📦 Package

```puppet
package { 'nginx':
  ensure => 'installed',
}
```

#### 🔧 Service

```puppet
service { 'nginx':
  ensure => 'running',
  enable => true,
}
```

Resources can be chained together:

```puppet
package { 'nginx': ensure => installed; }
-> service { 'nginx': ensure => running; }
```

---

## 🧩 Node Classification

Node classification lets you apply specific configuration to a group of systems or hostnames.

### 🧠 Example:

```puppet
node 'webserver1.example.com' {
  include nginx
}
```

Or using groups:

```puppet
node default {
  include base
}
```

---

## 🧠 Review Questions

1. What is a Puppet manifest?
2. How do you ensure a package is installed in Puppet?
3. How do you manage a service's state in Puppet?
4. What is node classification used for?

---

## 📚 Additional Resources

* [Puppet Official Documentation](https://puppet.com/docs/puppet/latest/)
* [Learn Puppet - Puppet Academy](https://learn.puppet.com/)
* [Puppet Resource Reference](https://puppet.com/docs/puppet/latest/type.html)

✅ **Next Step:** Write a manifest that manages a file, installs a package, and ensures a service is running.
