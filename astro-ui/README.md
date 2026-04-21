# Astro UI (30 Days of Linux Fundamentals)

This folder contains the Astro frontend for the Linux fundamentals project.

## Commands

```bash
npm install
npm run dev
npm run build
npm run preview
```

## Git Notes

Do not commit generated files from local runs. The repository `.gitignore` is configured to ignore:

- `node_modules/`
- `.astro/`
- `dist/`
- `.vite/`
- `.netlify/`
- `.vercel/`
- `coverage/`

If these files were previously committed, remove them from Git tracking (without deleting local copies):

```bash
git rm -r --cached node_modules .astro
```
