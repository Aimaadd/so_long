# So_Long

**So_Long** is a 2D game developed as part of the [42 School](https://www.42.fr/) curriculum. 
The project focuses on creating a simple graphical application using the **MiniLibX** graphical library. 
The goal is to help players navigate through a maze while collecting items and avoiding obstacles.

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Technologies Used](#technologies-used)
- [Acknowledgments](#acknowledgments)

---

## About the Project

This project is an introduction to graphical programming. The player must guide a character through a map, 
collect items, and reach the exit while adhering to specific constraints. The map is built using a `.ber` file format, 
and the game validates the structure before running.

**Key Goals:**
- Implement a fully functional game loop.
- Manage user inputs for character movements.
- Handle resource loading (textures, sprites).
- Detect and respond to win/loss conditions.

---

## Features

- Reads and validates map files in `.ber` format.
- Implements collision detection for walls and collectible items.
- Displays the game in a window using MiniLibX.
- Tracks player movements and displays a move counter.

---

## Installation

### Prerequisites
- **CC** or another C compiler.
- **Make** for building the project.
- MiniLibX library (included or installable).

### Clone the Repository
```bash
git clone https://github.com/Aimaadd/so_long.git
cd so_long
