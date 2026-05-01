# Midnight Prototype (C++ Beginner Car Game)

You were right to ask for a runnable `.exe`.
This repo now includes a **Windows build pipeline** so you can download a packaged `.zip` that contains `midnight_prototype.exe`.

## Fastest way to get the EXE zip (no coding needed)
1. Push this repo to GitHub.
2. Open **Actions** tab.
3. Run workflow: **Build Windows EXE**.
4. After it finishes, download artifact: `midnight_prototype_win`.
5. Extract `midnight_prototype_win.zip` and run `midnight_prototype.exe`.

## Local Windows build (if you want to build yourself)
Double-click:
- `build_windows.bat`

It will:
- compile Release build
- create `midnight_prototype_win.zip`

## Controls
- `a` = left
- `d` = right
- `s` = stay
- `q` = quit
- `r` = restart after crash

## Architecture learning goals
- class-based game structure (`Game`)
- input/update/render separation
- spawn/collision/score/combo systems
- easy next-step path to later graphics engines

## Current scope
This is intentionally a pure C++ console prototype so you can learn architecture first.
Next upgrade: replace renderer with SDL2/raylib while preserving gameplay systems.
