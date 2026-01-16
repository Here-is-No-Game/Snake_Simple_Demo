#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
namespace Config {
constexpr int MAP_WIDTH = 15;
constexpr int MAP_HEIGHT = 15;
constexpr int SNAKE_INIT_LENTH = 5;
constexpr int CELL_SIZE = 75; // 单位格边长像素
const std::unordered_map<int, SDL_Color> COLOR_MAP = {
    {0, SDL_Color{20, 20, 20, 255}},    // Spare
    {1, SDL_Color{255, 0, 222, 255}}, // Body
    {2, SDL_Color{255,190, 0, 255}},   // Fruit
    {3, SDL_Color{240, 240, 240, 255}}, // line
    {4, SDL_Color{0,240, 255, 255}}  // Head
};
} // namespace Config