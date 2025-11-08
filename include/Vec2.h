#pragma once
#include "Config.h"
struct Vec2 {
  int x, y;
  Vec2(int x = 0, int y = 0) : x(x), y(y) {}

  Vec2 operator+(const Vec2 &other) const { return {x + other.x, y + other.y}; }

  Vec2 &operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  [[nodiscard]] bool InBounds() const {
    return (x >= 0 && x < Config::MAP_WIDTH && y >= 0 && y < Config::MAP_HEIGHT);
  }

  bool operator==(const Vec2 &other) const {
    return x == other.x && y == other.y;
  }
};