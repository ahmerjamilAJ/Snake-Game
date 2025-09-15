# 🐍 Snake Game

A simple, fast, terminal-based Snake game you can compile and run locally.  
Built with modern C++ and a light cross-platform input/console shim so it works on macOS, Linux, and Windows.

---

## ✨ Features

- Classic Snake gameplay (grow by eating food, avoid walls and your tail)
- Pause / Resume functionality
- Score tracking & optional high-score file
- Adjustable speed
- Clean terminal rendering (no external GUI libs)

---

## 🎮 Controls

| Key | Action           |
|-----|------------------|
| `↑` | Move up          |
| `↓` | Move down        |
| `←` | Move left        |
| `→` | Move right       |
-------------------------

*(If your terminal sends different arrow sequences, WASD is often supported as a fallback.)*

---

## 📦 Requirements

- **C++17** compatible compiler (g++ / clang / MSVC)
- A terminal / console

---

## 🛠️ Build & Run


```bash
g++ -std=c++17 main.cpp -o snake
./snake
