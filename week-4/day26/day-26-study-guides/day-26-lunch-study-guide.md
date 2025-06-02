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
