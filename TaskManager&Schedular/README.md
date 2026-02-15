# Task Manager & Scheduler

A command-line task management system built in C++ for organizing daily tasks with priorities, deadlines, and persistent storage.

## Features
- ✅ Add tasks with title, description, priority (H/M/L), and deadline
- 📋 View all tasks or filter by priority
- ✓ Mark tasks as complete
- 🗑️ Delete tasks
- 📊 View statistics (total, completed, pending)
- 💾 Auto-save/load tasks from file (data persists between sessions)

## Tech Stack
- **Language:** C++ (STL)
- **Data Structures:** Vector, File I/O
- **Concepts:** OOP (Classes), File Handling, Menu-driven Interface

## Getting Started

### Prerequisites
- C++ compiler (g++, MinGW, or any C++11 compatible compiler)
- Terminal/Command Prompt

### Installation & Usage

1. **Clone or download the project**
   ```bash
   git clone <your-repo-url>
   cd task-manager
   ```

2. **Compile the program**
   ```bash
   g++ task_manager.cpp -o task_manager
   ```

3. **Run the program**
   ```bash
   ./task_manager       # Linux/Mac
   task_manager.exe     # Windows
   ```

### How to Use

**Main Menu:**
```
1. Add Task          - Create a new task
2. View All Tasks    - Display all your tasks
3. View by Priority  - Filter tasks by priority (H/M/L)
4. Mark Complete     - Mark a task as done
5. Delete Task       - Remove a task permanently
6. Statistics        - View task summary
7. Exit              - Save and quit
```

**Adding a Task:**
1. Select option `1`
2. Enter task title (e.g., "Complete C++ project")
3. Enter description (e.g., "Finish task manager implementation")
4. Enter priority: `H` (High), `M` (Medium), or `L` (Low)
5. Enter deadline in format: `DD/MM/YYYY` (e.g., 20/02/2026)

**Viewing Tasks:**
- Option `2` shows all tasks with their details
- Option `3` filters by priority (enter H, M, or L)

**Managing Tasks:**
- Option `4` marks tasks as complete (tasks remain in list)
- Option `5` permanently deletes tasks
- Option `6` shows statistics: total, completed, and pending tasks

**Data Persistence:**
- All tasks are automatically saved to `tasks.txt`
- Tasks are loaded automatically when you restart the program
- No manual save needed!

## Learning Outcomes
- Object-oriented design (Task & TaskManager classes)
- STL vector operations and dynamic arrays
- File persistence using fstream
- User input validation and handling
- Clean console UI design
- Switch-case menu systems

## Future Enhancements

### Planned Features (v2.0)
- [ ] **Edit Task** - Modify existing task details
- [ ] **Search Functionality** - Find tasks by keyword in title/description
- [ ] **Sort by Deadline** - Display tasks ordered by due date
- [ ] **Color-coded Priorities** - Visual distinction for H/M/L priorities
- [ ] **Task Categories/Tags** - Organize tasks (Work, Personal, Urgent, etc.)
- [ ] **Due Date Alerts** - Highlight tasks due today/tomorrow
- [ ] **Recurring Tasks** - Support for daily/weekly repeating tasks

### Advanced Features (v3.0)
- [ ] **Time Tracking** - Log time spent on each task
- [ ] **Export to CSV/JSON** - Data portability
- [ ] **Task Dependencies** - Link related tasks
- [ ] **Subtasks** - Break large tasks into smaller steps
- [ ] **Archive Completed Tasks** - Keep history without clutter
- [ ] **Multi-user Support** - Individual user profiles
- [ ] **Task Notes/Comments** - Add additional context
- [ ] **Undo/Redo** - Recover from accidental deletions

### UI Improvements
- [ ] Better text formatting and alignment
- [ ] Progress bars for task completion percentage
- [ ] Calendar view of tasks
- [ ] Dark/Light theme support

## Contributing
Feel free to fork this project and submit pull requests for any enhancements!

## Project Structure
```
task-manager/
│
├── task_manager.cpp    # Main source code
├── tasks.txt           # Auto-generated task storage
└── README.md           # This file
```

---
## Screenshots

### Add Task Screen
![Add Task Screenshot](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/addTask.png)

### Dashboard Screen
![Dashboard Screenshot](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/dashboard.png)

### Statistics Screen
![Statistics Screenshot](https://github.com/Coddiction-101/cpp_projects/blob/main/TaskManager%26Schedular/snapshots/statistics.png)

---

## Version History
- **v1.0** (Feb 2026) - Initial release with core features

## License
This project is open source and available for educational purposes.

---

**Built as a learning project to master C++ fundamentals, OOP, and data structures.**
