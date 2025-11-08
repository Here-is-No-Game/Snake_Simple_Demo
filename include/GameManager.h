#pragma once
#include "Map.hpp"
#include "Vec2.h"
#include "snake.hpp"
/**
 *  初始化游戏管理器。
 *
 *  w 地图宽度。
 *
 *  h 地图高度。
 *
 *  l 贪吃蛇的初始长度。
 */
struct GameManager {
  Map GameMap;
  snake Papy;
  GameManager(int w, int h, int l) : GameMap(w, h), Papy(l, &GameMap) {}
};
extern GameManager gm;