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

# Stitch Game 🎮

A simple 2D game built using **OpenGL** and **GLUT**, where the player controls the character **Stitch** to collect hearts and avoid knives.

---

## 🧩 Features

### 👾 Character Rendering
- Stitch is drawn using pixel data and a color palette.
- Each pixel is rendered using OpenGL `quads` mapped from pixel values.

### ❤️ Object Shapes
- **Hearts**: Increase the player's score.
- **Knives**: End the game if touched.

### 🎮 Controls
- Use **Left** and **Right Arrow Keys** to move Stitch within the screen boundaries.

### 🧠 Collision Detection
- Touching a **heart** ➝ Score increases.
- Touching a **knife** ➝ Game Over.
- Collect **3 hearts** ➝ You win!

### 🖼️ Graphics & Background
- Background built with **gradient-colored quads** to simulate sky and ground.

---

## 🔁 Game Loop
- Uses **timers** and **GLUT callbacks** to:
  - Continuously update object positions.
  - Handle keyboard input.
  - Detect collisions.
  - Render the updated scene.

---

## 🛠️ How It Works
1. Initializes a GLUT window and sets up an orthographic projection using `glOrtho`.
2. Continuously runs the game loop:
   - Reads keyboard inputs.
   - Moves hearts and knives downward.
   - Detects collisions.
   - Updates score or shows game over.

---

## 🏁 Game End Conditions
- 🎉 **"Well Done!!!"** if the player collects 3 hearts.
- 💀 **"GAME OVER!!!"** if Stitch touches a knife.

---


## 📦 Requirements
- OpenGL
- GLUT

---


