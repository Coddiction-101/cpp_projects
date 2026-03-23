# 🧠 RecallX — Cognitive Memory Training Engine
**Category:** Tools & Utilities / Games | **Difficulty:** ⭐⭐⭐⭐ | **Status:** 📋 Planned

---

## 📌 Overview
RecallX is a console-based cognitive training game built entirely in C++. It presents the player with sequences — numbers, words, or mixed patterns — and challenges them to recall those sequences under progressively harder conditions.

No external libraries. No GUI. Just pure logic, clean C++, and a genuinely useful tool for training working memory, focus, and mental flexibility.

This is not a typical "build a linked list" project. RecallX demonstrates real product thinking — it has levels, scoring, multiple game modes, difficulty scaling, and persistent progress tracking.

---

## ✨ Features

### Core Game Modes
- 🔢 **Number Recall** — Memorize and repeat number sequences
- 📝 **Word Recall** — Memorize and repeat word sequences
- 🔀 **Mixed Recall** — Numbers and words combined
- ↩️ **Reverse Recall** — Repeat the sequence backwards
- ➕ **Math Recall** — Recall sequence + solve a math problem simultaneously
- 🎯 **Distraction Recall** — A distractor task shown mid-sequence to break focus

### Progression System
- 10 difficulty levels (1 → 10)
- Sequence length grows with level
- Time pressure increases at higher levels
- New modes unlock as levels are cleared

### Scoring System
- Points for correct recall
- Bonus points for speed
- Streak multiplier for consecutive correct answers
- Penalty for wrong answers
- High score saved to file (persists between sessions)

### Session Summary
- Accuracy percentage
- Average response time
- Longest streak
- Level reached
- Personal best comparison

---

## 🛠️ Tech Stack

| Technology | Purpose |
|---|---|
| C++ (C++17) | Core language |
| STL (`vector`, `string`, `map`) | Data structures |
| `<chrono>` | Timer and response time tracking |
| `<random>` | Sequence generation |
| `<fstream>` | Score persistence |
| `<thread>` / `<chrono>` | Countdown timers |
| ANSI escape codes | Color output, visual feedback |

---

## 🗂️ File Structure

### Beginner (Single Folder)
```
RecallX/
│
├── main.cpp              # Entry point, game loop
├── game.cpp              # Core game logic
├── game.h                # Game class declaration
├── sequence.cpp          # Sequence generation & validation
├── sequence.h            # Sequence class declaration
├── scores.cpp            # Score tracking & file I/O
├── scores.h              # Score class declaration
├── utils.cpp             # Helper functions (timers, display)
├── utils.h               # Utility declarations
├── scores.txt            # Auto-generated high score storage
└── README.md
```

### Scalable Modular Structure
```
RecallX/
│
├── src/
│   ├── main.cpp
│   ├── game/
│   │   ├── Game.cpp
│   │   ├── Game.h
│   │   ├── Level.cpp
│   │   └── Level.h
│   ├── sequence/
│   │   ├── Sequence.cpp
│   │   ├── Sequence.h
│   │   ├── NumberSequence.cpp
│   │   ├── WordSequence.cpp
│   │   └── MixedSequence.cpp
│   ├── modes/
│   │   ├── NormalMode.cpp
│   │   ├── ReverseMode.cpp
│   │   ├── MathMode.cpp
│   │   └── DistractionMode.cpp
│   ├── scoring/
│   │   ├── ScoreManager.cpp
│   │   └── ScoreManager.h
│   └── utils/
│       ├── Timer.cpp
│       ├── Timer.h
│       ├── Display.cpp
│       └── Display.h
│
├── data/
│   └── scores.txt
│
├── words/
│   └── wordlist.txt      # Word bank for word recall mode
│
└── README.md
```

---

## 🎮 Game Flow

```
Launch RecallX
      │
      ▼
  Main Menu
  1. Play
  2. Select Mode
  3. High Scores
  4. How to Play
  5. Exit
      │
      ▼
  Select Mode → Normal / Reverse / Math / Distraction / Mixed
      │
      ▼
  Level starts
  → Sequence displayed for N seconds
  → Screen clears
  → Player inputs recall
  → Validated → Score calculated
      │
   Correct?
   ├── Yes → Streak++, next round (harder sequence)
   └── No  → Life lost, feedback shown
      │
  Lives = 0?
  ├── Yes → Session summary shown → Save score
  └── No  → Continue
```

---

## 🏗️ Development Plan

### ✅ Phase 1 — Foundation (Start Here)
> Goal: Get the core loop working. A playable game with one mode.

- [ ] Project setup — folder structure, compile test
- [ ] `Sequence` class — generate random number sequences
- [ ] Display sequence on screen for N seconds, then clear
- [ ] Read player input and compare to original sequence
- [ ] Basic correct/wrong feedback with ANSI colors
- [ ] Loop for multiple rounds
- [ ] Difficulty scaling — sequence length grows each round

**Milestone:** A working number recall game, single mode, no scoring yet.

---

### 🔨 Phase 2 — Game System (Core Features)
> Goal: Add scoring, lives, levels, and session tracking.

- [ ] `ScoreManager` class — points, streak multiplier, lives
- [ ] Level system — 10 levels with different sequence lengths and time limits
- [ ] `<chrono>` timer — measure response time, award speed bonus
- [ ] Session summary screen — accuracy, streaks, time, score
- [ ] Save/load high scores with `fstream`
- [ ] High score screen
- [ ] ANSI color UI — green for correct, red for wrong, yellow for timer

**Milestone:** A complete, scoreable game with persistence.

---

### 📋 Phase 3 — Game Modes (Depth)
> Goal: Add all recall modes to make it feel like a full product.

- [ ] **Reverse Recall** — player must type sequence backwards
- [ ] **Word Recall** — load wordlist.txt, display words instead of numbers
- [ ] **Mixed Recall** — alternate numbers and words in same sequence
- [ ] **Math Recall** — show sequence + simple math problem, solve both
- [ ] **Distraction Recall** — show a distractor (odd/even question) mid-display
- [ ] Mode selection menu
- [ ] Per-mode high scores

**Milestone:** 5 distinct game modes all working.

---

### 🚀 Phase 4 — Polish & Advanced (Portfolio Ready)
> Goal: Make it stand out as a portfolio project.

- [ ] Player profiles — multiple users, separate scores
- [ ] Training report — track performance over multiple sessions
- [ ] Adaptive difficulty — auto-adjusts based on accuracy
- [ ] Timed challenge mode — beat the clock across 10 rounds
- [ ] `<thread>` countdown timer — live ticking timer displayed while playing
- [ ] Config file — customizable sequence length, time limits, word bank
- [ ] Clean, minimal UI with ANSI box-drawing characters

**Milestone:** Portfolio-level project, documented and GitHub-ready.

---

## 🧠 Core Logic Design

### Sequence Generation
```
vector<string> generateSequence(int length, Mode mode) {
    - For NUMBER mode: random integers 0–99
    - For WORD mode:   random words from wordlist.txt
    - For MIXED mode:  alternate number and word at each index
    - Seed with chrono for true randomness each run
}
```

### Display & Clear
```
displaySequence(sequence, int durationSeconds) {
    - Print each element with spacing
    - Sleep for durationSeconds using <chrono>
    - Clear screen (system("cls") or ANSI \033[2J)
}
```

### Validation
```
bool validateRecall(vector<string> original, vector<string> input, Mode mode) {
    - NORMAL:  compare index by index
    - REVERSE: compare input[i] with original[n-1-i]
    - MIXED:   same as normal but type-aware matching
    - Return accuracy percentage, not just pass/fail
}
```

### Scoring Formula
```
basePoints    = correctElements * 10
speedBonus    = max(0, (timeLimit - responseTime) * 2)
streakBonus   = streak * 5
totalScore    = (basePoints + speedBonus) * streakMultiplier
streakMultiplier = 1.0 + (streak * 0.1)   // caps at 2.0x
```

### Level Scaling
| Level | Sequence Length | Time to Memorize | Mode Unlocked |
|---|---|---|---|
| 1–2 | 3–4 elements | 5 seconds | Normal only |
| 3–4 | 5–6 elements | 5 seconds | Reverse unlocked |
| 5–6 | 6–7 elements | 4 seconds | Word + Mixed unlocked |
| 7–8 | 8–9 elements | 4 seconds | Math Recall unlocked |
| 9–10 | 10–12 elements | 3 seconds | Distraction unlocked |

---

## 💡 Standout Features (Bonus Ideas)

| Feature | Why It Stands Out |
|---|---|
| Adaptive difficulty | Auto-adjusts to your accuracy — feels like real cognitive training |
| Training report | Session history tracked across days — shows real improvement |
| Distraction mode | Genuinely hard — tests real-world focus, not just memory |
| Player profiles | Multiple users on one machine — shows multi-user design thinking |
| Wordlist from file | Demonstrates file-based config, easy to extend |
| Live countdown timer | Uses `<thread>` — introduces multithreading naturally |

---

## 🌐 Web Version Conversion Path

When you're ready to take RecallX beyond C++:

| Layer | Technology |
|---|---|
| Frontend UI | React + Tailwind CSS |
| Game logic port | TypeScript (mirrors C++ class structure exactly) |
| Backend / scores | Node.js + Express |
| Database | SQLite or Firebase |
| Deployment | Vercel (frontend) + Railway (backend) |

The C++ class structure (Sequence, ScoreManager, Level, Mode) maps 1:1 to TypeScript classes — making the web port straightforward once the C++ version is solid.

---

## 💼 Why This Project Is Valuable

| Signal | What Recruiters See |
|---|---|
| Multiple game modes | Product thinking — you designed a system, not just a script |
| Scoring + persistence | File I/O, data design, real-world state management |
| Timer with `<chrono>` | Beyond basic C++ — time-aware programming |
| Level scaling | Algorithm design — dynamic difficulty |
| Modular structure | Professional code organization, easy to extend |
| Cognitive training angle | Unique domain — stands out from banking/task manager clones |

---

## 🧠 Concepts You Will Learn

| Concept | Phase |
|---|---|
| OOP (classes, inheritance) | Phase 1 |
| STL vectors, strings | Phase 1 |
| `<random>` for seeded generation | Phase 1 |
| ANSI terminal colors | Phase 1 |
| `<chrono>` timers | Phase 2 |
| File I/O with fstream | Phase 2 |
| Scoring algorithms | Phase 2 |
| Polymorphism (mode classes) | Phase 3 |
| File-based word banks | Phase 3 |
| `<thread>` basics | Phase 4 |
| Adaptive algorithms | Phase 4 |

---

## 📊 Project Stats (Estimated)

| Metric | Value |
|---|---|
| Lines of Code | ~600–800 |
| Development Phases | 4 |
| Game Modes | 5 |
| New Concepts | 6+ |
| External Libraries | None |

---

## 🔗 Related Projects
- [Task Manager](https://github.com/Coddiction-101/cpp_projects/tree/main/TaskManager%26Schedular) — OOP, vectors, file I/O
- [Terminal Text Editor](https://github.com/Coddiction-101/cpp_projects/tree/main/cpp-project-ideas/Tools-and-Utilities/Terminal-Text-Editor) — raw input, ANSI, timers

---

[← Back to cpp-projects](https://github.com/Coddiction-101/cpp_projects/tree/main)
