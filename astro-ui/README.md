# Astro UI — 30 Days of Linux Fundamentals (ZothOS × 1nc0gn30 Edition)

This directory contains the interactive **ZothOS × 1nc0gn30** Web Workstation (`astro-ui`) for **30 Days of Linux Fundamentals**.

## Quick Start

```bash
cd astro-ui
npm install
npm run dev
# Build production static bundle:
npm run build
npm run preview
```

## Features

- **30 Interactive Day Mission Terminals (`/day/1` – `/day/30`)**: Drill commands across Breakfast, Lunch, and Dinner sessions with live XP, streak tracking, Command Intel cards, and full Markdown study guides.
- **90 Digestible Study Guides**: Every meal across all 30 days includes a 60-Second Mental Model, ASCII architecture diagram, TUI vs. GUI workflow table, and safe `/tmp/linux-dojo-day-XX` sandbox instructions.
- **Interactive Visual Linux Labs (`/`)**:
  - Live `chmod` Octal & Symbolic Permission Calculator (`755`, `644`, `600`, `750`)
  - Interactive Linux Filesystem Hierarchy (`/`, `/etc`, `/var`, `/proc`, `/home`, `/bin`, `/dev`, `/tmp`) Explorer
  - Interactive Standard Streams & Pipeline (`|`, `grep`, `awk`, `sort`, `uniq`) Simulator
  - 60fps Unicode `U+2800` Braille & Ordered Bayer Dither Linux Kernel Canvas

## Netlify Settings

- **Base directory**: `astro-ui`
- **Build command**: `npm run build`
- **Publish directory**: `dist`
