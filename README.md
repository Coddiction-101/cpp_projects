# 🚀 C++ Projects

A collection of real-world C++ projects built from scratch, progressively increasing in complexity. Each project is fully functional, documented, and covers key C++ concepts including OOP, STL, File I/O, and Data Structures.

## 👨‍💻 About
This repo documents my C++ learning journey through hands-on project building. Every project here was built step by step, starting from zero C++ knowledge.

- **Language:** C++ (C++11 / C++17)
- **Compiler:** g++ (MinGW on Windows)
- **Approach:** Concept first → Build → Document

---

## 📁 Projects

### 🛠️ Tools & Utilities

| # | Project | Description | Difficulty | Concepts |
|---|---|---|---|---|
| 01 | [Task Manager & Scheduler](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular) | Console task management with priorities, deadlines & color UI | ⭐⭐⭐ | OOP, Vectors, File I/O, ANSI colors |
| 02 | [Banking System - ATM Simulator](https://github.com/Coddiction-101/cpp_projects/tree/main/BankingSimulation) | Full ATM simulator with authentication & transactions | ⭐⭐⭐⭐ | OOP, Map, Pointers, File I/O |
| 03 | [Terminal Text Editor](https://github.com/Coddiction-101/cpp_projects/tree/main/cpp-project-ideas/Tools-and-Utilities/Terminal-Text-Editor) | Fully functional terminal editor with search, undo/redo & scrollbar | ⭐⭐⭐⭐⭐ | Raw input, Win32 API, ANSI codes, Snapshots |

---

## 🗂️ 01 - Task Manager & Scheduler
> **Status:** ✅ Complete v2.0 | **Lines of Code:** ~450

A fully functional console-based task management system for organizing daily tasks with color-coded priorities, deadlines, alerts, and persistent storage.

### Features
- ✅ Add tasks with title, description, priority (H/M/L) and deadline
- 📋 View all tasks or filter by priority
- ✏️ Edit any task field (press Enter to keep current value)
- 🔍 Search tasks by keyword (title + description)
- 📅 Sort tasks by deadline (chronological)
- ⚠️ Due date alerts — overdue and due-today highlighted automatically
- ✓ Mark tasks as complete
- 🗑️ Delete tasks (with confirmation)
- 📊 Statistics dashboard (total, completed, pending, by priority)
- 💾 Auto-save/load from file (data persists between sessions)

### Tech Stack
- **Data Structures:** Vector
- **Key Concepts:** OOP (Task & TaskManager classes), ANSI escape codes for color, File I/O with fstream, Lambda sort comparator, Input validation loops, Date parsing

### What I Learned
- ANSI terminal colors without any external library
- Sorting custom objects with `std::sort` and lambda comparators
- Robust file parsing with `istringstream`
- Input validation patterns that loop until correct input is given
- Date logic and deadline status comparison

### Usage
```bash
g++ -std=c++17 task_manager.cpp -o task_manager
task_manager.exe
```

```
1. Add Task          6. Delete Task
2. View All Tasks    7. Search Tasks
3. View by Priority  8. Sort by Deadline
4. Edit Task         9. Due Date Alerts
5. Mark Complete    10. Statistics
                     0. Exit
```

### Repo Link
[View on GitHub](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular)

---

## 🏦 02 - Banking System / ATM Simulator
> **Status:** ✅ Complete v1.0 | **Lines of Code:** ~400

A console-based banking application that simulates real-world ATM operations with account management, secure transactions, and persistent data storage.

### Features
- 🔐 Secure PIN-based authentication
- 🏦 Create Savings or Current accounts
- 💵 Deposit and withdraw money
- 💸 Transfer money between accounts
- 📊 Full transaction history tracking
- 👤 Detailed account information
- 🗑️ Delete account with PIN + confirmation
- 💾 Auto-save/load all accounts from file

### Tech Stack
- **Data Structures:** Map, Vector
- **Key Concepts:** OOP (BankAccount & BankingSystem classes), Pointers & references, STL map for account lookup, File I/O with custom parsing, PIN authentication, Multi-level menu system

### What I Learned
- Using `map<string, Object>` for efficient data lookup
- Working with pointers to pass objects by reference
- Building multi-level menu systems
- Implementing basic security (PIN verification, deletion confirmation)
- Parsing structured data from files

### Usage
```bash
g++ banking_system.cpp -o banking_system
./banking_system
```

```
1. Create New Account
2. Login to Account
3. Delete Account
4. Exit
```

### Repo Link
[View on GitHub](https://github.com/Coddiction-101/cpp_projects/tree/main/BankingSimulation)

---

## 📝 03 - Terminal Text Editor
> **Status:** ✅ Complete v2.1 | **Lines of Code:** ~450

A fully functional terminal text editor built from scratch — no external libraries. Edit, search, undo, and save real files directly in the console.

### Features
- ⌨️ Real-time character input (no Enter required)
- 🔼 Arrow key navigation + viewport scrolling
- 🔍 Ctrl+F search with live match highlighting
- 🔁 Ctrl+N find next match (with wraparound)
- ↩️ Undo / Redo — Ctrl+Z / Ctrl+Y (50-level snapshot history)
- 📋 Copy line (Ctrl+C) / Paste line (Ctrl+V)
- 📄 Auto-indentation — Enter inherits current line's indent
- 💾 Open existing files via command-line argument
- 🔢 Dynamic line numbers (scales to 100+ lines)
- 📊 Scroll indicator — Ln / Col / % in status bar
- ✱ Modified flag + quit guard for unsaved changes

### Tech Stack
- **Data Structures:** Vector of strings (line buffer), Struct stacks (undo/redo)
- **Key Concepts:** Raw terminal input (`_kbhit`, `_getch`), Win32 API cursor control, ANSI escape codes, Snapshot-based undo/redo, Viewport scrolling with offset clamping

### What I Learned
- How text editors manage buffers internally
- Real-time input capture without Enter key
- Terminal control via Win32 API
- Viewport scrolling with offset clamping
- Snapshot-based undo/redo using structs + stacks
- ANSI escape sequences for highlighting and color

### Usage
```bash
g++ -std=c++17 text_editor.cpp -o text_editor
text_editor.exe              # new file
text_editor.exe myfile.txt   # open existing file
```

```
Ctrl+S  Save       Ctrl+F  Find       Ctrl+N  Next match
Ctrl+C  Copy line  Ctrl+V  Paste      Ctrl+Z  Undo
Ctrl+Y  Redo       Ctrl+Q  Quit       Tab     Indent
```

### Repo Link
[View on GitHub](https://github.com/Coddiction-101/cpp_projects/tree/main/cpp-project-ideas/Tools-and-Utilities/Terminal-Text-Editor)

---

## 📈 Progress Tracker

| Concept | Learned Through |
|---|---|
| Classes & Objects | Task Manager |
| Encapsulation | Task Manager |
| Vectors | Task Manager |
| File I/O (fstream) | Task Manager |
| ANSI escape codes | Task Manager v2.0 |
| Lambda comparators | Task Manager v2.0 |
| Date parsing & validation | Task Manager v2.0 |
| STL Map | Banking System |
| Pointers & References | Banking System |
| Authentication Logic | Banking System |
| Multi-level Menus | Banking System |
| Raw terminal input (`_kbhit`, `_getch`) | Terminal Text Editor |
| Win32 API cursor control | Terminal Text Editor |
| Snapshot-based undo/redo | Terminal Text Editor |
| Viewport scrolling | Terminal Text Editor |
| `<filesystem>` (C++17) | 🔨 File Organizer (Next) |
| Recursive Directory Traversal | 🔨 File Organizer (Next) |
| Encryption Basics | 📋 Password Manager |
| Socket Programming | 📋 Port Scanner |
| Multithreading | 📋 Resource Monitor |

---

## 🗺️ Roadmap

### ✅ Phase 1 - Foundations (Done)
- [x] Task Manager & Scheduler
- [x] Banking System - ATM Simulator

### 🔨 Phase 2 - Intermediate (In Progress)
- [ ] File Organizer (`<filesystem>`, recursive traversal)
- [ ] Password Manager (encryption, hashing)
- [ ] Resource Monitor (system calls, threading)

### ✅ Phase 3 - Advanced (Done)
- [x] Terminal Text Editor (raw input, buffer management, undo/redo)
- [ ] Expression Calculator (tokenizer, stack evaluation)
- [ ] Port Scanner (socket programming, threading)

### 🎮 Phase 4 - Games (Planned)
- [ ] Console Snake Game
- [ ] Minesweeper
- [ ] Maze Generator & Solver
- [ ] Chess Engine

---

## 🔗 Related Repos
- [📋 cpp-project-ideas](https://github.com/Coddiction-101/cpp_projects/tree/main/cpp-project-ideas) - Full project ideas bank with overviews, concepts, and build tracker

---

## 📄 License
All projects are open source and available for educational purposes.

---

*Built project by project, concept by concept. Updated as new projects are completed.*
