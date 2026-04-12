# 🐍 Snake Game (C Language - Terminal Based)

## 📌 Overview
This project is a **feature-rich Snake Game implemented in C**, designed to run in the terminal.  
It goes beyond a basic implementation by incorporating **real-time gameplay, dynamic difficulty scaling, file-based high score tracking, and interactive controls**.

The project demonstrates strong understanding of **C programming, game logic, data structures, and system-level interaction**.


## 🎯 Objectives
- Develop a real-time terminal-based game in C 
- Implement dynamic snake movement and growth logic
- Introduce increasing difficulty levels
- Store and retrieve persistent high scores using file handling
- Provide an interactive and responsive user experience


## 🧠 Features

### 🎮 Gameplay
- Real-time snake movement using keyboard input
- Snake grows after eating food
- Collision detection (self-collision)
- Continuous gameplay loop with smooth updates 

### ⚡ Difficulty System
- Speed increases as score grows
- Progressive challenge for players

### 💾 High Score System
- File-based storage (`highscore.txt`)
- Automatically loads previous high score
- Updates on new record

### ⏸️ Game Controls
- Pause and Resume functionality
- Exit option during gameplay

### 🔄 Wall Behavior
- Snake wraps around screen edges (no hard walls)

### 🧩 Data Structures
- Snake body implemented using arrays
- Dynamic tail movement logic


## 🛠️ Technologies Used
- **Programming Language:** C  
- **Core Concepts:**
  - Arrays & Pointers
  - Game Loop Design
  - File Handling
  - Real-time Input Handling (`conio.h`)
  - System Calls (`windows.h`)
  - Control Structures


## 📁 Project Structure

snake-game-c/
- main.c
- highscore.txt    (auto-generated)
- README.md

> The `highscore.txt` file is created automatically after the first run.


## ▶️ How to Compile and Run

### 1️⃣ Compile

gcc main.c -o snake


### 2️⃣ Run

./snake


## 🎮 Controls

W → Move Up  
S → Move Down  
A → Move Left  
D → Move Right  
P → Pause Game  
R → Resume Game  
X → Exit Game  


## 📈 Sample Output

- ASCII-based game board
- Moving snake with growing tail
- Real-time score display
- High score tracking
- Pause and resume messages


## 🧪 Test Coverage

- Snake movement accuracy
- Collision detection (self)
- Food spawning logic
- Score increment validation
- High score persistence
- Input handling robustness


## 🎓 Academic Relevance

This project demonstrates:
- Strong understanding of **real-time systems in C**
- Practical use of **data structures in games**
- Implementation of **file handling for persistence**
- Experience with **interactive console applications**

✔ Suitable for:
- C Programming Projects
- Mini / Major Academic Projects
- Game Development Basics
- GitHub Portfolio Enhancement


## 🔮 Future Enhancements

- Colored UI using ANSI escape codes
- Obstacle-based gameplay
- Multiple difficulty modes
- AI-based auto-play snake
- Cross-platform support using `ncurses`
- Sound effects integration


## 📜 License

This project is intended for **academic and learning purposes only**.

