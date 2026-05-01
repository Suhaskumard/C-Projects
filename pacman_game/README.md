# Pacman Game

A simple console-based Pacman clone written in C.

## How to Play

- **W** — Move Up
- **A** — Move Left
- **S** — Move Down
- **D** — Move Right
- **X** — Exit Game

## Objective

- Collect the food dots (`.`) to earn points
- Avoid the Ghost (`G`)
- Achieve the highest score possible

## Game Symbols

| Symbol | Meaning |
|--------|---------|
| `C` | Pacman (You) |
| `G` | Ghost (Enemy) |
| `.` | Food (Collect for +10 points) |
| `#` | Wall/Border |

## Building

### Windows (MinGW)
```bash
gcc pacman.c -o pacman.exe
.\pacman.exe
```

### Windows (Visual Studio)
```cmd
cl pacman.c
pacman.exe
```

## Controls

The game uses arrow-key style input (WASD). Press the key and the direction will change on the next frame.

## Features

- Random food generation
- Ghost AI with smart (70%) and random (30%) movement
- Score tracking
- Clean terminal output with screen clearing