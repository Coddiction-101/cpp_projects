# 📝 Terminal Text Editor
**Category:** Tools & Utilities | **Difficulty:** ⭐⭐⭐⭐⭐ | **Status:** ✅ v1.0 Complete

---

## 📌 Overview
A fully functional terminal text editor built from scratch in C++. Edit text files directly in the console with real-time keyboard input, cursor control, and file saving - all without any external libraries.

This project demonstrates low-level terminal control, buffer management using STL vectors, and building complex interactive software from scratch.

---

## ✨ Features

### Version 1.0 (Current) ✅
- ✅ Real-time character input (no Enter required)
- ✅ Arrow key navigation (↑ ↓ ← →)
- ✅ Multi-line text editing
- ✅ Enter for new lines
- ✅ Backspace to delete characters
- ✅ Save file with Ctrl+S
- ✅ Quit with Ctrl+Q
- ✅ Status bar showing filename and shortcuts
- ✅ ANSI escape codes for cursor control

### Version 2.0 (Planned) 📋
- [ ] Open existing files (command-line argument)
- [ ] Line numbers display
- [ ] Search functionality (Ctrl+F)
- [ ] Visual "Saved!" confirmation message
- [ ] Multiple file tabs
- [ ] Copy/paste support
- [ ] Undo/redo functionality
- [ ] Basic syntax highlighting

---

## 🧠 Concepts Used

| Concept | Status |
|---------|--------|
| OOP (Classes & Objects) | ✅ Used |
| STL Vectors for buffer | ✅ Used |
| File I/O with fstream | ✅ Used |
| Raw terminal input (`_kbhit()`, `_getch()`) | ✅ Learned & Used |
| ANSI escape codes for cursor | ✅ Learned & Used |
| Buffer management with vector<string> | ✅ Learned & Used |

---

## 🚀 Usage

### Compile
```bash
g++ text_editor.cpp -o text_editor
```

### Run
```bash
./text_editor        # Linux/Mac
text_editor.exe      # Windows
```

### Keyboard Shortcuts
| Key | Action |
|-----|--------|
| Type | Insert characters at cursor |
| ↑ ↓ ← → | Move cursor |
| Enter | New line |
| Backspace | Delete character |
| Ctrl+S | Save file |
| Ctrl+Q | Quit editor |

### Output
- Creates/saves to `untitled.txt` in the current directory

---

## 🛠️ Technical Details

### Architecture
```
TextEditor Class
├── vector<string> lines     ← Text buffer (each string = one line)
├── int cursorRow            ← Current cursor position (row)
├── int cursorCol            ← Current cursor position (column)
├── string filename          ← File to save to
│
├── display()                ← Render all lines + status bar
├── insertChar()             ← Insert character at cursor
├── deleteChar()             ← Backspace functionality
├── newLine()                ← Split line at cursor
├── moveUp/Down/Left/Right() ← Cursor navigation
└── save()                   ← Write buffer to file
```

### Key Technologies
- **Raw Input:** `_kbhit()` detects keypresses, `_getch()` reads them without waiting for Enter
- **ANSI Codes:** `\033[row;colH` moves cursor, `\033[2J` clears screen
- **Buffer:** `vector<string>` stores all lines, insert/erase operations modify text
- **Arrow Keys:** Detected as two-byte sequences (224 prefix + direction code)

---

## 📖 What I Learned

### Before This Project
- Basic C++ syntax, OOP, file I/O
- Standard console input with `cin`

### After This Project
- How text editors work internally
- Terminal control without libraries
- Real-time input capture (no Enter key)
- ANSI escape sequences for cursor manipulation
- Efficient text buffer management
- Building complex interactive console applications

---

## 🐛 Known Limitations (v1.0)

- Cannot open existing files (creates new file only)
- No visual feedback after save
- No line numbers
- No search functionality
- Limited to terminal size (no scrolling)
- No syntax highlighting

*These will be addressed in v2.0*

---

## 🔮 Future Enhancements (v2.0+)

### High Priority
- Open existing files via command-line argument
- Line numbers on the left margin
- Ctrl+F search with highlighting
- "File saved!" status message

### Medium Priority
- Vertical scrolling for large files
- Multiple file tabs
- Ctrl+Z undo / Ctrl+Y redo

### Low Priority
- Syntax highlighting for C++/Python/etc
- Copy/paste (Ctrl+C, Ctrl+V)
- Find & replace
- Auto-indentation

---

## 📊 Project Stats

| Metric | Value |
|--------|-------|
| Lines of Code | ~200 |
| Development Time | 1 day |
| Concepts Learned | 3 new (raw input, ANSI codes, buffer mgmt) |
| Version | 1.0 |

---

## 🔗 Related Projects
- [Task Manager](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular) - First C++ project (OOP, vectors, file I/O)
- [Banking System](https://github.com/Coddiction-101/cpp_projects/tree/main/BankingSimulation) - Second project (maps, pointers, authentication)

---

[← Back to cpp-projects](https://github.com/Coddiction-101/cpp_projects/tree/main)
