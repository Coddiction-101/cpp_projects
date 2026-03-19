# 📝 Terminal Text Editor
**Category:** Tools & Utilities | **Difficulty:** ⭐⭐⭐⭐⭐ | **Status:** ✅ v2.1 Complete

---

## 📌 Overview
A fully functional terminal text editor built from scratch in C++. Edit text files directly in the console with real-time keyboard input, cursor control, search, undo/redo, and file persistence — all without any external libraries.

This project demonstrates low-level terminal control, buffer management using STL vectors, snapshot-based undo/redo, and building complex interactive software from scratch.

---

## ✨ Features

### Version 1.0 ✅
- ✅ Real-time character input (no Enter required)
- ✅ Arrow key navigation (↑ ↓ ← →)
- ✅ Multi-line text editing
- ✅ Enter for new lines
- ✅ Backspace to delete characters
- ✅ Save file with Ctrl+S
- ✅ Quit with Ctrl+Q
- ✅ Status bar showing filename and shortcuts
- ✅ Windows console cursor control via Win32 API

### Version 2.0 ✅
- ✅ Open existing files via command-line argument
- ✅ Line numbers (dynamic width, scales to 100+ lines)
- ✅ Search functionality (Ctrl+F) with match highlighting
- ✅ Visual "Saved!" confirmation message
- ✅ Modified flag (`*filename` when unsaved changes exist)
- ✅ Quit guard — prompts before discarding unsaved changes
- ✅ Dynamic status bar (no hardcoded row — adapts to terminal height)
- ✅ Fixed word count logic

### Version 2.1 ✅
- ✅ Scroll indicator — `Ln / Col / %` position in status bar
- ✅ Visual scrollbar on far right with proportional thumb block
- ✅ Auto-indentation — Enter inherits leading whitespace from current line
- ✅ Tab key support — inserts 4 spaces (soft tab)
- ✅ Copy line (Ctrl+C) and paste line below (Ctrl+V)
- ✅ Ctrl+N — find next search match with wraparound
- ✅ Undo (Ctrl+Z) / Redo (Ctrl+Y) — snapshot-based, 50-level history

---

## ⌨️ Keyboard Shortcuts

| Key | Action |
|-----|--------|
| Type | Insert characters at cursor |
| ↑ ↓ ← → | Move cursor |
| Enter | New line (with auto-indent) |
| Backspace | Delete character |
| Tab | Insert 4 spaces |
| Ctrl+S | Save file |
| Ctrl+F | Find / search |
| Ctrl+N | Find next match |
| Ctrl+C | Copy current line |
| Ctrl+V | Paste line below cursor |
| Ctrl+Z | Undo |
| Ctrl+Y | Redo |
| Ctrl+Q | Quit (prompts if unsaved) |

---

## 🚀 Usage

### Compile
```bash
g++ -std=c++17 text_editor.cpp -o text_editor
```

### Run
```bash
text_editor.exe              # New file (saved as untitled.txt)
text_editor.exe myfile.txt   # Open existing file or create named file
```

---

## 🛠️ Technical Details

### Architecture
```
TextEditor Class
├── vector<string> lines        ← Text buffer (each string = one line)
├── int cursorRow / cursorCol   ← Current cursor position
├── int scrollOffset            ← First visible line index
├── string filename             ← Active file name
├── bool modified               ← Unsaved changes flag
├── string clipboard            ← Line-based clipboard
├── vector<EditorState> undoStack / redoStack  ← Snapshot history
├── string searchTerm           ← Active search term
│
├── display()                   ← Full redraw: text + scrollbar + status bar
├── refreshCursor()             ← Lightweight: reposition cursor only
├── insertChar()                ← Insert character, push undo snapshot
├── deleteChar()                ← Backspace, merge lines if at col 0
├── newLine()                   ← Split line at cursor + auto-indent
├── insertTab()                 ← Insert 4 spaces (soft tab)
├── moveUp/Down/Left/Right()    ← Cursor navigation with line wrapping
├── updateScroll()              ← Keep cursor in visible window
├── startSearch()               ← Interactive Ctrl+F prompt in status bar
├── findNext()                  ← Search forward with wraparound
├── copyLine() / pasteLine()    ← Line clipboard operations
├── undo() / redo()             ← Snapshot restore from history stacks
└── save() / loadFile()         ← File I/O with fstream
```

### Key Technologies

| Technology | What it does |
|---|---|
| `_kbhit()` / `_getch()` | Real-time input — no Enter key needed |
| `SetConsoleCursorPosition()` | Moves cursor to exact row/col via Win32 API |
| `GetConsoleScreenBufferInfo()` | Reads terminal dimensions dynamically |
| `vector<string>` | Line buffer — each element is one line of text |
| `ANSI escape codes` | `\033[7m` for search highlight, `\033[32m` for green status |
| `EditorState` struct | Snapshot of lines + cursor for undo/redo |
| `vector<EditorState>` stacks | LIFO undo/redo history (capped at 50 states) |

### Undo/Redo Design
Snapshot-based: before every edit operation, the current state (all lines + cursor position) is pushed onto the undo stack. Undo pops from undo → pushes to redo. Redo pops from redo → pushes to undo. Any new edit clears the redo stack. Capped at 50 snapshots to limit memory use.

### Scrollbar Design
The scrollbar occupies the last column of the terminal. Thumb size is proportional to `visible_rows / total_lines`. Thumb position maps `scrollOffset` into the available track height. Rendered using ANSI inverse video (`\033[7m`) for the thumb and dim (`\033[2m`) for the track.

---

## 🧠 Concepts Used

| Concept | Introduced In |
|---------|--------------|
| OOP (Classes & Objects) | v1.0 |
| STL Vectors for buffer | v1.0 |
| File I/O with fstream | v1.0 |
| Raw terminal input (`_kbhit`, `_getch`) | v1.0 |
| Win32 API for cursor control | v1.0 |
| ANSI escape codes | v1.0 |
| Dynamic terminal dimensions | v2.0 |
| String search (`string::find`) | v2.0 |
| Viewport scrolling logic | v2.1 |
| Stack-based undo/redo (snapshots) | v2.1 |
| Soft tabs / auto-indentation | v2.1 |

---

## 📖 What I Learned

### Before This Project
- Basic C++ syntax, OOP, STL containers, file I/O

### After This Project
- How text editors manage buffers internally
- Real-time input capture without Enter key
- Terminal/console control via Win32 API
- Viewport scrolling with offset clamping
- Snapshot-based undo/redo using structs + stacks
- ANSI escape sequences for highlighting and color
- Building complex, stateful interactive console apps

---

## 📊 Project Stats

| Metric | Value |
|--------|-------|
| Lines of Code | ~450 |
| Versions | 3 (v1.0 → v2.0 → v2.1) |
| New Concepts Learned | 6+ |
| Undo History Depth | 50 snapshots |
| External Libraries | None |

---

## 🔮 Future Enhancements (v3.0+)

### High Priority
- Syntax highlighting for C++ / Python / JSON
- Find & replace (Ctrl+H)
- Select text with Shift + arrow keys

### Medium Priority
- Multiple file tabs
- Horizontal scrolling for long lines
- Jump to line number (Ctrl+G)

### Low Priority
- Mouse click to reposition cursor
- Line wrapping toggle
- Config file (custom tab width, theme)

---

## 🔗 Related Projects
- [Task Manager](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular) — OOP, vectors, file I/O
- [Banking System](https://github.com/Coddiction-101/cpp_projects/tree/main/BankingSimulation) — maps, pointers, authentication

---

[← Back to cpp-projects](https://github.com/Coddiction-101/cpp_projects/tree/main)
