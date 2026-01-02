#include "snake.hpp"
#include "GameManager.h"
#include "Map.hpp"
#include "Vec2.h"
#include <SDL3/SDL.h>
#include <queue>
#include <unordered_map>

snake::snake(int lenth, Map *m) {
  M = m;
  direction = {1, 0};
  for (int x = 1; x <= lenth; x++) {
    Vec2 NewBody(x, 1);
    Body.push(NewBody);
    M->CreateBody(x, 1);
  }
  Map::SpawnFruit();
}
snake::~snake() = default;

Vec2 snake::InputTrans(const SDL_Event &input) {
  if (input.type != SDL_EVENT_KEY_DOWN)
    return {0, 0};
  static const std::unordered_map<SDL_Keycode, Vec2> dirMap = {
      {SDLK_W, {0, -1}},
      {SDLK_S, {0, 1}},
      {SDLK_A, {-1, 0}},
      {SDLK_D, {1, 0}},
  };
  auto it = dirMap.find(input.key.key);
  return (it != dirMap.end()) ? it->second : Vec2{0, 0};
}

void snake::SelfCut(Vec2 pos) {
  auto bodycp = Body;
  std::vector<Vec2> temp;
  while (!bodycp.empty()) {
    temp.push_back(bodycp.front());
    bodycp.pop();
  }
  int index = 0;
  do {
    M->ClearLocation(temp[index].x, temp[index].y);
    ++index;
  } while (temp[index] != pos);
  ++index;
  std::queue<Vec2> newBody;
  for (int i = index; i < temp.size(); ++i) {
    newBody.push(temp[i]);
  }
  Body = newBody;
  Body.push(pos);
  M->CreateHead(pos.x, pos.y);
}

void snake::move(SDL_Event input) {
  Vec2 NextPos;
  auto head = Body.back();
  NextPos = head + InputTrans(input);
  // TODO BAN Over Bound
  if (!NextPos.InBounds()) {
    return;
  }
  // TODO BAN Backward
  if (InputTrans(input) + direction == (Vec2){0, 0}) {
    return;
  }

  direction = InputTrans(input);

  if (M->Check(NextPos) == 1) {
    gm.GameMap.CreateBody(Body.back().x, Body.back().y);
    if (gm.Papy.Body.front() == NextPos) {
      gm.GameMap.ClearLocation(Body.front().x, Body.front().y);
      gm.GameMap.CreateHead(NextPos.x, NextPos.y);

      Body.push(NextPos);
      Body.pop();
      return;
    }
    SelfCut(NextPos);
  }
  if (M->Check(NextPos) == 0) {
    gm.GameMap.ClearLocation(Body.front().x, Body.front().y);
    gm.GameMap.CreateBody(Body.back().x, Body.back().y);
    gm.GameMap.CreateHead(NextPos.x, NextPos.y);

    Body.push(NextPos);
    Body.pop();
  }
  // TODO GET FRUIT
  if (M->Check(NextPos) == 2) {
    gm.GameMap.CreateBody(Body.back().x, Body.back().y);
    gm.GameMap.CreateHead(NextPos.x, NextPos.y);

    Body.push(NextPos);
    Map::SpawnFruit();
  }
}