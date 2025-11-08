#include "Map.hpp"
#include "GameManager.h"
#include "Vec2.h"
#include <random>
#include <vector>
Map::Map(int _x, int _y) : x(_x), y(_y) {
  std::vector<int> row(_x, 0);   // 一行 _x 列
  for (int i = 0; i < _y; i++) { // 共 _y 行
    GameMap_.push_back(row);
  }
}
Map::~Map() = default;

void Map::CreateBody(int _x, int _y) { GameMap_[_y][_x] = 1; }
void Map::CreateFruit(int _x, int _y) { GameMap_[_y][_x] = 2; }
void Map::ClearLocation(int _x, int _y) { GameMap_[_y][_x] = 0; }
void Map::CreateHead(int _x, int _y) { GameMap_[_y][_x] = 4; }
int Map::Check(Vec2 pos) { return GameMap_[pos.y][pos.x]; }

int Map::GetColorID(int _x, int _y) {
  Vec2 a(_x, _y);
  if (a.InBounds()) {
    return GameMap_[_y][_x];
  }
  return 0;
}

void Map::SpawnFruit() {
  std::vector<Vec2> EmptyCells;
  for (int y = 0; y < Config::MAP_HEIGHT; ++y) {
    for (int x = 0; x < Config::MAP_WIDTH; ++x) {
      if (gm.GameMap.GameMap_[y][x] == 0)
        EmptyCells.emplace_back(x, y);
    }
  }
  static std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<> dist(0, EmptyCells.size() - 1);
  auto pos = EmptyCells[dist(gen)];
  gm.GameMap.GameMap_[pos.y][pos.x] = 2;
}