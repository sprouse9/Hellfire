# Hellfire (2D Bullet Demo)

**Hellfire** is a lightweight 2D shooter demo built using **SFML (Simple and Fast Multimedia Library)**. It features real-time sprite animation, bullet management, and player movement tied to the mouse cursor—all wrapped in a simple game loop architecture.

---

## 🎮 Features

- 🚀 **Player spaceship** with frame-based rotation animation from a sprite sheet
- 🔫 **Bullet system** with:
  - Object pooling (fixed-size array of `Bullet`)
  - Time-based shooting rate control
  - Screen edge deactivation
- 🖱️ Mouse-controlled player positioning
- 🧱 Collision-friendly design (bounding boxes available)
- 💡 Uses `sf::Text` to render bullets visually as `"=="`
- 📏 Adjustable game resolution to 70% of screen size
- ⌚ Frame-timed logic with `sf::Clock` and `sf::Time`

---

## 📦 Project Structure

```
Hellfire/
├── main.cpp
├── Player.hpp / .cpp        # Player class with animation & movement
├── Bullet.hpp / .cpp        # Bullet class for individual bullet state
├── BulletManager.hpp / .cpp # Handles bullet spawning and updating
├── ResourcePath.hpp         # Helper to load assets (esp. for macOS)
├── Assets/
│   ├── Hellfire-Player-SpriteSheet.png
│   └── sansation.ttf
```

---

## 🧠 Key Components

### `Player`

- Loads an 8-frame spaceship sprite sheet
- Updates sprite animation every 50ms
- Moves player to the mouse location each frame

### `BulletManager`

- Shoots bullets on key press (`A`)
- Prevents rapid-fire using time gating
- Advances bullets rightward until they exit the screen

### `main.cpp`

- Sets up SFML window and view
- Listens for `Keyboard` and `Mouse` input
- Draws player and bullets per frame

---

## 🛠️ Build Instructions

### 📋 Prerequisites

- C++11 or later
- SFML (Graphics, System, and Window modules)

### 🧪 Compile Example (Linux/macOS)

```bash
g++ -std=c++11 main.cpp Player.cpp BulletManager.cpp -lsfml-graphics -lsfml-window -lsfml-system -o hellfire
./hellfire
```

Make sure to place your assets (sprites, fonts) in the proper path expected by `resourcePath()`.

---

## ✏️ Notes

- The project uses a basic custom `resourcePath()` to support Xcode/macOS bundles.
- Bullet rendering uses large bold text (`==`) for a fun arcade vibe.
- Optimized for learning purposes, not a full-fledged engine.

---

## 📄 License

No restrictions.

---

> “All you need is a bold ship and a faster bullet.”  
