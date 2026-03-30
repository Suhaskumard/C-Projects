Advanced Rock–Paper–Scissors Game (C)

An advanced console-based game written in C, implementing the Rock–Paper–Scissors–Lizard–Spock (RPSLS) ruleset with intelligent AI behavior, timed gameplay, and persistent player statistics.

This project is designed to demonstrate core C programming concepts, game logic, and basic AI decision-making in a single-file implementation.

 🎮 Project Overview

This game allows a player to compete against the computer in an extended version of Rock–Paper–Scissors. The computer adapts its moves based on the player’s behavior, and the game tracks performance over time.

Key goals of this project:

* Practice structured programming in C
* Implement game logic using matrices and conditions
* Demonstrate file handling and persistent data storage
* Build a non-trivial console application suitable for college submissions or GitHub portfolios

 ✨ Features

* **Rock–Paper–Scissors–Lizard–Spock** gameplay
* Player vs Computer mode
* Difficulty levels:
* Easy – random computer moves
* Medium – partially adaptive AI
* Hard – predictive AI based on player history


* Best-of-3 and Best-of-5 match modes
* Timed player input (reaction-based gameplay)
* Win streak tracking
* Persistent player statistics using file handling
* Colored console output for better user experience

> **Note on Portability:** Colored console output and timed inputs often rely on OS-specific features (like ANSI escape codes for Linux/macOS or `<windows.h>` for Windows).

 🧠 Concepts Used

This project demonstrates the following C programming concepts:

* Structures (`struct`)
* Arrays and 2D matrices
* Conditional statements and loops
* Functions and modular design
* Random number generation
* File handling (`fopen`, `fprintf`, `fscanf`)
* Time-based input handling
* Basic AI logic
  
 📁 Project Structure

advanced-rps-game-c/
- rps_game.c       # Main source file (single-file project)
- score.txt        # Auto-generated file to store player statistics
- README.md        # Project documentation



Note: `score.txt` is created automatically when the game is run for the first time.

⚙️ How to Compile & Run

Make sure you have a C compiler installed (GCC recommended).

Linux / macOS / Git Bash (Windows)
gcc rps_game.c -o rps
./rps


Windows (Command Prompt / PowerShell)
gcc rps_game.c -o rps.exe
rps.exe

 🎯 How to Play

1. Run the program.
2. Choose **Play Game** from the menu.
3. Select your match type (Best-of-3 or Best-of-5).
4. Select your difficulty level.
5. Enter your move when prompted:
`1` – Rock
 `2` – Paper
 `3` – Scissors
 `4` – Lizard
 `5` – Spock

6. **Respond within 5 seconds**, or the round is forfeited!
7. View your overall stats from the main menu at any time.

#📊 Statistics & Persistence

* Player wins, losses, and draws are saved to `score.txt`.
* Move usage and win streaks are tracked across sessions.
* Statistics are automatically loaded when the game starts.

 🚀 Future Enhancements

Possible improvements for future iterations:

* Multiplayer mode (local or network-based)
* ASCII animations
* Sound effects
* Tournament mode
* Graphical version using SDL or Raylib

 🎓 Academic & Portfolio Use

This project is highly suitable for:

* C programming assignments
* Mini projects
* GitHub portfolios
* Viva / technical interviews

 📜 License
This project is for educational purposes and is open for learning and modification.

