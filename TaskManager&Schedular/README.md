# 📋 Task Manager & Scheduler
**Category:** Tools & Utilities | **Status:** ✅ v2.0 Complete

---

## 📌 Overview
A fully functional command-line task management system built in C++ for organizing daily tasks with priorities, deadlines, and persistent storage. Features a color-coded terminal UI using ANSI escape codes — no external libraries required.

---

## ✨ Features

### Version 1.0 ✅
- ✅ Add tasks with title, description, priority (H/M/L), and deadline
- ✅ View all tasks or filter by priority
- ✅ Mark tasks as complete
- ✅ Delete tasks
- ✅ Statistics dashboard (total, completed, pending)
- ✅ Auto-save/load from file (data persists between sessions)

### Version 2.0 ✅
- ✅ Color-coded priorities — High (red), Medium (yellow), Low (green)
- ✅ Edit task — modify any field, press Enter to keep current value
- ✅ Search by keyword — case-insensitive, searches title + description
- ✅ Sort by deadline — chronological sort, saves new order
- ✅ Due date alerts — overdue and due-today highlighted on every view
- ✅ Startup alert banner — warns you instantly on launch
- ✅ Delete confirmation — prompts before permanently removing a task
- ✅ Priority input validation — only accepts H, M, or L
- ✅ Deadline format validation — enforces DD/MM/YYYY with range checks
- ✅ Fixed `cin.ignore()` consistency across all input methods
- ✅ Fixed signed/unsigned comparison warnings

---

## ⌨️ Menu Options

| # | Option | Description |
|---|--------|-------------|
| 1 | Add Task | Create a new task with title, description, priority, deadline |
| 2 | View All Tasks | Display all tasks with full details |
| 3 | View by Priority | Filter tasks by H / M / L |
| 4 | Edit Task | Modify any field of an existing task |
| 5 | Mark Complete | Mark a task as done |
| 6 | Delete Task | Permanently remove a task (with confirmation) |
| 7 | Search Tasks | Find tasks by keyword in title or description |
| 8 | Sort by Deadline | Reorder all tasks chronologically |
| 9 | Due Date Alerts | View all overdue and due-today tasks |
| 10 | Statistics | Summary by status and priority |
| 0 | Exit | Save and quit |

---

## 🚀 Usage

### Compile
```bash
g++ -std=c++17 task_manager.cpp -o task_manager
```

### Run
```bash
task_manager.exe     # Windows
./task_manager       # Linux/Mac
```

### Adding a Task
1. Select option `1`
2. Enter title, description
3. Enter priority: `H` (High), `M` (Medium), or `L` (Low) — validated
4. Enter deadline: `DD/MM/YYYY` (e.g. `25/12/2026`) — validated

### Data Persistence
All tasks auto-save to `tasks.txt` after every change. Tasks load automatically on startup. No manual save needed.

---

## 🛠️ Technical Details

### Architecture
```
Task Class
├── string title, description, priority, deadline
├── bool completed
├── display()         ← Full colored output with deadline alert
├── displayCompact()  ← One-line summary for lists
└── setters           ← Used by edit feature

TaskManager Class
├── vector<Task> tasks
├── addTask()         ← Validated input, saves after add
├── viewAllTasks()    ← Full display of all tasks
├── viewByPriority()  ← Filtered view
├── editTask()        ← Field-by-field edit, Enter to skip
├── markComplete()    ← Sets completed flag, saves
├── deleteTask()      ← Confirmation prompt, saves
├── searchTasks()     ← Case-insensitive keyword search
├── sortByDeadline()  ← Chronological sort via lambda
├── showAlerts()      ← Overdue + due-today breakdown
├── showStats()       ← Full statistics with color
├── saveToFile()      ← Pipe-delimited persistence
└── loadFromFile()    ← Robust line-by-line parsing
```

### Key Technologies

| Technology | What it does |
|---|---|
| ANSI escape codes | Color-coded output (RED, YELLOW, GREEN, DIM, BOLD) |
| `std::sort` + lambda | Chronological deadline sorting |
| `string::find` | Case-insensitive keyword search |
| `__DATE__` macro | Compile-time "today" for deadline status checks |
| `istringstream` | Robust pipe-delimited file parsing |
| Input validation loops | Priority and deadline format enforcement |

### Deadline Status Logic
Each task's deadline is compared against today's date (parsed from `__DATE__` at compile time):
- **Overdue** → shown in red with `!! OVERDUE`
- **Due today** → shown in yellow with `(Due today)`
- **Future** → shown normally

---

## 🧠 Concepts Used

| Concept | Introduced In |
|---------|--------------|
| OOP (Classes & Objects) | v1.0 |
| STL Vectors | v1.0 |
| File I/O with fstream | v1.0 |
| Switch-case menu system | v1.0 |
| ANSI escape codes for color | v2.0 |
| `std::sort` with lambda comparator | v2.0 |
| String search (`string::find`) | v2.0 |
| Input validation loops | v2.0 |
| Date parsing and comparison | v2.0 |

---

## 📖 What I Learned

### Before This Project
- Basic C++ syntax, OOP, file I/O, vectors

### After This Project
- ANSI terminal colors without any external library
- Sorting custom objects with lambda comparators
- Robust file parsing with `istringstream`
- Input validation patterns that loop until correct
- Date logic without `<ctime>` complexity

---

## 📊 Project Stats

| Metric | Value |
|--------|-------|
| Lines of Code | ~450 |
| Versions | 2 (v1.0 → v2.0) |
| External Libraries | None |
| New Concepts in v2.0 | 5 |

---

## 🔮 Future Enhancements (v3.0+)

### High Priority
- [ ] Task categories / tags (Work, Personal, Urgent)
- [ ] Recurring tasks (daily / weekly)
- [ ] Progress bar for completion percentage

### Medium Priority
- [ ] Archive completed tasks (keep history without clutter)
- [ ] Export to CSV
- [ ] Subtasks — break large tasks into steps

### Low Priority
- [ ] Time tracking — log time spent per task
- [ ] Task dependencies — link related tasks
- [ ] Calendar view

---

## 🖼️ Screenshots

### Add Task Screen
![Add Task](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/addTask.png)

### Dashboard Screen
![Dashboard](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/dashboard.png)

### Statistics Screen
![Statistics](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/statistics.png)

---

## 🔗 Related Projects
- [Banking System](https://github.com/Coddiction-101/cpp_projects/tree/main/BankingSimulation) — maps, pointers, authentication
- [Terminal Text Editor](https://github.com/Coddiction-101/cpp_projects/tree/main/TerminalTextEditor) — raw input, ANSI, undo/redo

---

## 📅 Version History
- **v2.0** (Mar 2026) — Colors, edit, search, sort, due date alerts, bug fixes
- **v1.0** (Feb 2026) — Initial release with core features

---

[← Back to cpp-projects](https://github.com/Coddiction-101/cpp_projects/tree/main)
