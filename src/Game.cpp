#include "Game.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

namespace {
constexpr int kLanes = 3;
constexpr int kRows = 14;
}

void Game::Run() {
    Reset();

    while (true) {
        Render();
        if (crashed_) {
            std::cout << "\nCrash! Press r to restart or q to quit: ";
            char c;
            std::cin >> c;
            if (c == 'q') break;
            if (c == 'r') Reset();
            continue;
        }

        std::cout << "\nMove [a:left d:right s:stay q:quit]: ";
        char input = 's';
        std::cin >> input;
        if (input == 'q') break;
        Update(input);
    }
}

void Game::Reset() {
    playerLane_ = 1;
    score_ = 0;
    combo_ = 1;
    tick_ = 0;
    crashed_ = false;
    obstacles_.clear();
}

void Game::SpawnObstacle() {
    std::uniform_int_distribution<int> laneDist(0, kLanes - 1);
    obstacles_.push_back({laneDist(rng_), 0, false});
}

void Game::Update(char input) {
    // Input processing: keep this isolated so adding controller support later is easy.
    if (input == 'a') playerLane_ = std::max(0, playerLane_ - 1);
    if (input == 'd') playerLane_ = std::min(kLanes - 1, playerLane_ + 1);

    if (tick_ % 2 == 0) SpawnObstacle();

    for (auto& o : obstacles_) {
        o.row += 1;
        if (o.row == kRows - 1 && o.lane == playerLane_) {
            crashed_ = true;
        }
        if (o.row >= kRows - 1 && o.lane != playerLane_ && !o.passed) {
            o.passed = true;
            combo_ = std::min(9, combo_ + 1);
            score_ += 10 * combo_;
        }
    }

    if (tick_ % 4 == 0) combo_ = std::max(1, combo_ - 1);

    obstacles_.erase(
        std::remove_if(obstacles_.begin(), obstacles_.end(), [](const Obstacle& o) { return o.row >= kRows; }),
        obstacles_.end());

    ++tick_;
}

void Game::Render() const {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif

    std::cout << "=== MIDNIGHT PROTOTYPE (Console Edition) ===\n";
    std::cout << "Score: " << score_ << "   Combo: x" << combo_ << "\n\n";

    std::vector<std::string> grid(kRows, "|   |   |   |");

    for (const auto& o : obstacles_) {
        if (o.row >= 0 && o.row < kRows) {
            int col = 2 + o.lane * 4;
            grid[o.row][col] = 'X';
        }
    }

    int playerCol = 2 + playerLane_ * 4;
    grid[kRows - 1][playerCol] = 'A';

    for (const auto& row : grid) {
        std::cout << row << '\n';
    }
}
