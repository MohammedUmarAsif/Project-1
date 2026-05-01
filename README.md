# Midnight Prototype (C++ Beginner Car Game)

A super-short **pure C++** beginner project you can compile into an `.exe` and run immediately.
It is intentionally engine-independent for now (console renderer only) so you learn architecture first.

## What this teaches
- clean class-based game structure (`Game` class)
- game loop fundamentals
- input/update/render separation
- simple spawning + collision systems
- score/combo loop for replayability

## Play loop
You drive in 3 lanes (`A`) and dodge traffic (`X`).
- `a` = left
- `d` = right
- `s` = stay
- `q` = quit
- `r` = restart after crash

## Build
```bash
cmake -S . -B build
cmake --build build --config Release
```

## Run
- Linux/macOS: `./build/midnight_prototype`
- Windows: `build\\Release\\midnight_prototype.exe` (or in build root depending generator)

## Zip package (Windows)
After building release:
```powershell
Compress-Archive -Path build\\Release\\* -DestinationPath midnight_prototype_win.zip -Force
```

## Long-term roadmap to a Midnight Club spiritual successor
1. Replace console renderer with SDL2/raylib/UE custom module.
2. Keep gameplay systems (`input/update/scoring`) separate from renderer.
3. Add data-driven configs (JSON) for physics tuning.
4. Add checkpoints, AI rivals, and drift scoring.
