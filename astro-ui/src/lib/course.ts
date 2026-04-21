export const TOTAL_DAYS = 30;

export const COURSE_WEEKS = [
  { id: 1, title: 'Week 1: Linux Foundations', summary: 'Shell basics, navigation, file operations, and confidence with core terminal workflows.', startDay: 1, endDay: 7 },
  { id: 2, title: 'Week 2: Operating the System', summary: 'Permissions, process control, package management, and system-level awareness.', startDay: 8, endDay: 14 },
  { id: 3, title: 'Week 3: Real Workflow Mastery', summary: 'Pipelines, text processing, automation habits, and troubleshooting under pressure.', startDay: 15, endDay: 21 },
  { id: 4, title: 'Week 4: Advanced Linux Ops', summary: 'Networking, services, maintenance tasks, and production-style command usage.', startDay: 22, endDay: 28 },
  { id: 5, title: 'Week 5: Final Mission Sprint', summary: 'Capstone review, performance checks, and practical readiness to use Linux daily.', startDay: 29, endDay: 30 },
] as const;

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
