#pragma once
#include "Map.hpp"
#include "Vec2.h"
#include <SDL3/SDL.h>
#include <queue>
#include <unordered_map>

class snake {
private:
  std::queue<Vec2> Body;
  Map *M;
  Vec2 direction;

public:
  snake(int lenth, Map *m);
  ~snake();

  static Vec2 InputTrans(const SDL_Event &input);
  void SelfCut(Vec2 pos);
  void move(SDL_Event input);
};