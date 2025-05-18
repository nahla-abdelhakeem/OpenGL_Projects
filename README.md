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

## 📦 Requirements

- OpenGL
- GLUT

---

## 🚀 How to Run
```bash
g++ harry_potter_game.cpp -lGL -lGLU -lglut -o harry_potter_game
./harry_potter_game
