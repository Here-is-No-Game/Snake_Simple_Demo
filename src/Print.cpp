#include "Print.hpp"

SDL_Color GetColor(int id) {
  auto it = Config::COLOR_MAP.find(id);
  return (it != Config::COLOR_MAP.end()) ? it->second
                                         : SDL_Color{255, 255, 255, 255};
}

void SetColor(int id) {
  SDL_SetRenderDrawColor(gRenderer, GetColor(id).r, GetColor(id).g,
                         GetColor(id).b, GetColor(id).a);
}

void PrintLine() {
  SetColor(3);

  for (int i = 0; i <= Config::MAP_WIDTH; i += 1) {
    for (int j = i * Config::CELL_SIZE; j <= i * Config::CELL_SIZE + 2; j++) {
      SDL_RenderLine(gRenderer, j, 0, j, Config::MAP_HEIGHT*Config::CELL_SIZE);
    }
  }
  for (int i = 0; i <= Config::MAP_HEIGHT; i += 1) {
    for (int j = i * Config::CELL_SIZE; j <= i * Config::CELL_SIZE + 2; j++) {
      SDL_RenderLine(gRenderer, 0, j, Config::MAP_WIDTH*Config::CELL_SIZE, j);
    }
  }
}

void PrintSquare(int _x, int _y, int ColorID) {
  SDL_FRect body;
  body.x = _x * Config::CELL_SIZE;
  body.y = _y * Config::CELL_SIZE;
  body.w = Config::CELL_SIZE;
  body.h = Config::CELL_SIZE;
  SetColor(ColorID);
  SDL_RenderFillRect(gRenderer, &body);
}

void PrintMap() {
  for (int i = 0; i < Config::MAP_HEIGHT; i++) {
    for (int j = 0; j < Config::MAP_WIDTH; j++) {
      PrintSquare(j, i, gm.GameMap.GetColorID(j, i));
    }
  }
}
