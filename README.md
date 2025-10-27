# 2D Adventure Game - MiniLibX Project
![image](https://github.com/user-attachments/assets/5b97c548-2081-4d5e-ac6a-6c84c28b8947)
## 🕹️ About the Project
This is a **2D adventure game** built using **MiniLibX**, a lightweight graphics library for X11. The game follows a simple yet engaging gameplay where the player must navigate through a maze, collect coins, and reach the exit while avoiding obstacles.

The project is developed as part of a coding challenge to learn event-driven programming, image rendering, and handling user input using **C and MiniLibX**.

## 📜 Game Rules
- The player controls a character that can move **up, down, left, and right**.
- The goal is to **collect all the coins** (`C`) before reaching the exit (`E`).
- Walls (`1`) block the player's movement.
- The game **ends in success** when all coins are collected and the player reaches the exit.
- If there are uncollected coins, the exit **remains locked**.
- The map is read from a `.ber` file and must be **rectangular**.

## 🎮 Controls
| Key        | Action         |
|------------|---------------|
| `W` / `↑` | Move Up       |
| `S` / `↓` | Move Down     |
| `A` / `←` | Move Left     |
| `D` / `→` | Move Right    |
| `ESC`      | Quit the game |

## 🏗️ Installation and Compilation
### Prerequisites
Ensure you have the following installed on your system:
- **gcc** (GNU Compiler Collection)
- **make**
- **MiniLibX** (included in the project or installed separately)
- **X11 libraries** (for Linux users)

### Compiling the Game
To compile the game, run:
```sh
make
```
This will generate an executable named `so_long`.

### Running the Game
To start the game, use:
```sh
./so_long maps/map1.ber
```
Replace `map1.ber` with the desired level file.

## 🗺️ Map File Format (`.ber`)
Each level is stored in a **`.ber`** file and must follow these rules:
- The map must be **rectangular**.
- It must contain **at least one** player (`P`), exit (`E`), and collectible (`C`).
- Walls (`1`) surround the entire map.
- Open paths (`0`) represent walkable areas.

**Example of a valid `.ber` file:**
```
111111
1P0C01
100001
1C0E01
111111
```
## 🔴 YouTube Video
Here are walkthrough and demo videos explaining the project structure, algorithm, and runtime behavior.

▶️ **Project Overview:**
[https://www.youtube.com/watch?v=rY4tZnFEBo8](https://www.youtube.com/watch?v=rY4tZnFEBo8)
---
**Enjoy the game 🎮🔥**

