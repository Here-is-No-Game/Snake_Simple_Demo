#pragma once
#include "Vec2.h"
#include <vector>
/** 
 *@ 0: Spare
 *@ 1: Body
 *@ 2: Fruit
*/
class Map {
private:
  const int x, y;
  std::vector<std::vector<int>> GameMap_;

public:
  Map(int _x, int _y);
  ~Map();
  void CreateBody(int _x, int _y);
  void CreateHead(int _x, int _y);
  void CreateFruit(int _x, int _y) ;
  void ClearLocation(int _x, int _y);
  void static SpawnFruit();
  int Check(Vec2 pos);
  int GetColorID(int _x, int _y);
  
};