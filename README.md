# 🎮 Mastermind Console Game in C++

A compact C++ implementation of the classic Mastermind game, designed for terminal play. The player must guess a secret 4-digit code (each digit from 1–6), receiving hints after each attempt:

- `O` → Correct digit in the correct position  
- `#` → Correct digit but in the wrong position

The game continues until all digits and positions are correctly guessed. Ideal for practicing arrays, loops, input handling, and logic-building in C++.

## 🛠 How to Run
1. Make sure you have a C++ compiler installed.
2. Clone or download this repo.
3. Compile the file:
   ```bash
   g++ -o mastermind mastermind.cpp
