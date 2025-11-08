#pragma once
#include "Config.h"
#include "GameManager.h"
#include "Map.hpp"
#include "Vec2.h"
#include "snake.hpp"
#include <RenderSystem.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <stdexcept>

void SetColor();
SDL_Color GetColor();
void PrintLine();
void PrintSquare();
void PrintMap();