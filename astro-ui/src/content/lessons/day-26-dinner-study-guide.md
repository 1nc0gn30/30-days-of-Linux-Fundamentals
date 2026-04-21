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
