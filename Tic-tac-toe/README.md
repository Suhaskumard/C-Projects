
# 🎮 Tic-Tac-Toe Minimax AI (C Language)

## 📌 Overview
This project is an **advanced Tic-Tac-Toe game implemented in C** featuring an **unbeatable AI powered by the Minimax algorithm**.  
The system goes beyond a basic game by including **tournament mode**, **file-based leaderboard**, and a **colored console UI**, while also outlining a scalable path toward a **window-based GUI**.

The project demonstrates strong fundamentals in **C programming, recursion, algorithms, and system design**.


## 🎯 Objectives
- Implement an unbeatable AI using the Minimax algorithm
- Simulate real-world game flow using tournament logic
- Persist game results using file handling
- Provide a clean and interactive console-based UI
- Demonstrate AI and algorithmic thinking in C


## 🧠 Features

### 🤖 Artificial Intelligence
- Unbeatable **Minimax AI**
- Recursive game-tree evaluation
- Depth-based scoring for optimal decisions
- AI always wins or forces a draw

### 🏆 Tournament Mode
- Play best-of-N rounds
- Automatic score tracking
- Final winner announcement

### 💾 Leaderboard (SAVE)
- File-based leaderboard (`leaderboard.txt`)
- Stores wins, losses, and draws
- Persistent across program executions

### 🎨 Console UI
- Colored symbols using ANSI escape codes
  - **X** (Human) → Red  
  - **O** (AI) → Blue
- Clean board layout
- User-friendly prompts

### 🪟 GUI Extension (Planned)
- GUI architecture designed for SDL2 / WinAPI
- Separation of game logic and UI
- Suitable for future window-based implementation



## 🛠️ Technologies Used
- **Programming Language:** C  
- **Core Concepts:**
  - Recursion
  - Minimax Algorithm
  - Game Tree Evaluation
  - File Handling
  - Arrays & Control Structures
  - ANSI Console Styling


## 📁 Project Structure

tic-tac-toe-minimax-c/
- ttt_pro_minimax.c
- leaderboard.txt      (auto-generated)
- README.md


> The `leaderboard.txt` file is created automatically after the first tournament.



## ▶️ How to Compile and Run

### 1️⃣ Compile

gcc ttt_pro_minimax.c -o ttt


### 2️⃣ Run

./ttt

## 🎮 How to Play

1. Enter the number of tournament rounds
2. Play as **X**
3. Choose positions using numbers **1–9**
4. The AI (**O**) responds using Minimax logic
5. Final tournament results are displayed and saved


## 📈 Sample Output

* Colored Tic-Tac-Toe board
* Per-round win/draw result
* Tournament summary
* Persistent leaderboard entry


## 🧪 Test Coverage

* AI always selects optimal moves
* Draw and win detection
* Tournament score accuracy
* File persistence verification
* Invalid input handling


## 🎓 Academic Relevance

This project demonstrates:
* Advanced use of **recursion and algorithms**
* Practical implementation of **AI concepts**
* Strong understanding of **C programming fundamentals**
* System-level thinking and modular design

✔ Suitable for:
* CSE Mini / Major Projects
* Data Structures & Algorithms coursework
* AI fundamentals demonstration
* GitHub portfolio & resume projects


## 🔮 Future Enhancements

* Alpha-Beta Pruning for Minimax optimization
* Full GUI using SDL2
* Online multiplayer support
* NxN board generalization
* Timestamped leaderboard entries


## 📜 License

This project is intended for **academic and learning purposes only**.

---

## 🧑‍🏫 Evaluation Note

> *“This project demonstrates strong algorithmic thinking and AI fundamentals implemented in a low-level language.”*

