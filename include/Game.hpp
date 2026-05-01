#pragma once

#include <random>
#include <string>
#include <vector>

class Game {
public:
    void Run();

private:
    struct Obstacle {
        int lane = 1;
        int row = 0;
        bool passed = false;
    };

    void Reset();
    void SpawnObstacle();
    void Update(char input);
    void Render() const;

    int playerLane_ = 1;
    int score_ = 0;
    int combo_ = 1;
    int tick_ = 0;
    bool crashed_ = false;
    std::vector<Obstacle> obstacles_;
    std::mt19937 rng_{42};
};
