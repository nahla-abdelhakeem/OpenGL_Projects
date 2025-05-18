# Harry Potter Game 🧙‍♂️✨

A simple 2D game built using **C++** and **OpenGL (GLUT)**. The player controls **Harry Potter** flying on a broomstick, aiming to reach the finish line while avoiding golden snitches.

---

## 🕹️ Gameplay

- Harry automatically **moves to the right**.
- The player controls **vertical movement** using the **arrow keys**.
- If Harry **reaches the end** ➝ `"Well Done!"` 🎉
- If Harry **hits a golden snitch** ➝ `"Game Over!"` ❌

---

## 🎨 Graphics

- Characters (Harry and golden snitches) are drawn in **pixel-art style**.
- The background features a **simple animated sky effect**.

---

## ⚙️ Technical Details

- Developed in **C++** using **OpenGL (GLUT)**.
- Core components include:
  - **Window management** with GLUT.
  - **Animation loop** for continuous movement.
  - **Collision detection** between Harry and snitches.
  - **Keyboard input handling**.
  - **2D graphics rendering**.

---

# Pac-Man Game 👻🍒

A simple **Pac-Man** game developed using **OpenGL (GLUT)** with **C++**. The player controls Pac-Man to collect all the dots while avoiding collisions with walls.

---

## 🎮 Main Features

- 🟡 Pac-Man is drawn as a **circle with an open mouth**.
- 🟠 Dots are placed in the scene and are **removed when collected**.
- 🧱 **Walls** act as obstacles — collision with them ends the game.
- 🔼🔽◀️▶️ Use **arrow keys** to control movement direction.
- ⏱️ Movement is updated **continuously using a timer**.
- ❗ Includes **collision detection** with both dots and walls.
- 🏆 **Win Screen** appears when all dots are collected.
- ☠️ **Lose Screen** appears if you collide with a wall.

---

## ⚙️ Technologies Used

- **C++**
- **OpenGL + GLUT**
- Drawing done using `glBegin`, `glVertex`, and 2D coordinate logic.
- `glutTimerFunc` is used for frame/movement updates.

---

## 🏁 Win and Lose Conditions

- ✅ **Win:** All dots are collected.
- ❌ **Lose:** Collision with a wall.

---

## 📦 Requirements

- OpenGL
- GLUT

---

## 🚀 How to Run
```bash
g++ pacman_game.cpp -lGL -lGLU -lglut -o pacman_game
./pacman_game


## 🚀 How to Run
```bash
g++ harry_potter_game.cpp -lGL -lGLU -lglut -o harry_potter_game
./harry_potter_game
