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
| 01 | [Task Manager & Scheduler](#-01---task-manager--scheduler) | Console task management with priorities & deadlines | ⭐⭐⭐ | OOP, Vectors, File I/O |
| 02 | [Banking System - ATM Simulator](#-02---banking-system--atm-simulator) | Full ATM simulator with authentication & transactions | ⭐⭐⭐⭐ | OOP, Map, Pointers, File I/O |

---

## 🗂️ 01 - Task Manager & Scheduler
> **Status:** ✅ Complete | **Lines of Code:** ~250

A fully functional console-based task management system for organizing daily tasks with priorities, deadlines, and persistent storage.

### Features
- ✅ Add tasks with title, description, priority (H/M/L) and deadline
- 📋 View all tasks or filter by priority
- ✓ Mark tasks as complete
- 🗑️ Delete tasks
- 📊 Statistics dashboard (total, completed, pending)
- 💾 Auto-save/load from file (data persists between sessions)

### Tech Stack
- **Data Structures:** Vector
- **Key Concepts:** OOP (Task & TaskManager classes), File I/O with fstream, Menu-driven interface, Input validation

### What I Learned
- Designing classes with proper encapsulation
- Managing dynamic data with STL vectors
- Implementing file persistence with custom delimiters
- Building user-friendly console applications

### Usage
```bash
g++ task_manager.cpp -o task_manager
./task_manager
````

```
1. Add Task
2. View All Tasks
3. View By Priority
4. Mark Task Complete
5. Delete Task
6. Statistics
7. Exit
```

### Repo Link

[View on GitHub](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular)

---

## 🏦 02 - Banking System / ATM Simulator

> **Status:** ✅ Complete | **Lines of Code:** ~400

A console-based banking application that simulates real-world ATM operations with account management, secure transactions, and persistent data storage.

### Features

* 🔐 Secure PIN-based authentication
* 🏦 Create Savings or Current accounts
* 💵 Deposit and withdraw money
* 💸 Transfer money between accounts
* 📊 Full transaction history tracking
* 👤 Detailed account information
* 🗑️ Delete account with PIN + confirmation
* 💾 Auto-save/load all accounts from file

### Tech Stack

* **Data Structures:** Map, Vector
* **Key Concepts:** OOP (BankAccount & BankingSystem classes), Pointers & references, STL map for account lookup, File I/O with custom parsing, PIN authentication, Multi-level menu system

### What I Learned

* Using `map<string, Object>` for efficient data lookup
* Working with pointers to pass objects by reference
* Building multi-level menu systems
* Implementing basic security (PIN verification, deletion confirmation)
* Parsing structured data from files

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

[View on GitHub](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular)

---

## 📈 Progress Tracker

| Concept                       | Learned Through          |
| ----------------------------- | ------------------------ |
| Classes & Objects             | Task Manager             |
| Encapsulation                 | Task Manager             |
| Vectors                       | Task Manager             |
| File I/O (fstream)            | Task Manager             |
| STL Map                       | Banking System           |
| Pointers & References         | Banking System           |
| Authentication Logic          | Banking System           |
| Multi-level Menus             | Banking System           |
| `<filesystem>` (C++17)        | 🔨 File Organizer (Next) |
| Recursive Directory Traversal | 🔨 File Organizer (Next) |
| Encryption Basics             | 📋 Password Manager      |
| Socket Programming            | 📋 Port Scanner          |
| Multithreading                | 📋 Resource Monitor      |

---

## 🗺️ Roadmap

### ✅ Phase 1 - Foundations (Done)

* [x] Task Manager & Scheduler
* [x] Banking System - ATM Simulator

### 🔨 Phase 2 - Intermediate (In Progress)

* [ ] File Organizer (`<filesystem>`, recursive traversal)
* [ ] Password Manager (encryption, hashing)
* [ ] Resource Monitor (system calls, threading)

### 📋 Phase 3 - Advanced (Planned)

* [ ] Terminal Text Editor (raw input, buffer management)
* [ ] Expression Calculator (tokenizer, stack evaluation)
* [ ] Port Scanner (socket programming, threading)

### 🎮 Phase 4 - Games (Planned)

* [ ] Console Snake Game
* [ ] Minesweeper
* [ ] Maze Generator & Solver
* [ ] Chess Engine

---

## 🔗 Related Repos

* [📋 cpp-project-ideas](https://github.com/Coddiction-101/cpp_projects/tree/main/cpp-project-ideas) - Full project ideas bank with overviews, concepts, and build tracker

---

## 📄 License

All projects are open source and available for educational purposes.

---

*Built project by project, concept by concept. Updated as new projects are completed.*
