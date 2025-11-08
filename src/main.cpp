#include "Config.h"
#include "RenderSystem.hpp"
#include "GameManager.h"
#include "Map.hpp"
#include "Vec2.h"
#include "snake.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>


GameManager gm(Config::MAP_WIDTH, Config::MAP_HEIGHT, Config::SNAKE_INIT_LENTH);

int main(int argc, char* argv[]) {


  SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
  SDL_Window *gWindow = SDL_CreateWindow(
      "Snake", Config::MAP_WIDTH * Config::CELL_SIZE,
      Config::MAP_HEIGHT * Config::CELL_SIZE, SDL_WINDOW_RESIZABLE);
  
  // if (!gWindow) {
  //   SDL_Log("窗口创建失败: %s", SDL_GetError());
  //   SDL_Quit();
  //   return -1;
  // }


  gRenderer = SDL_CreateRenderer(gWindow, "opengles2");
 
  // if (!gRenderer) {
  //   SDL_Log("渲染器创建失败: %s", SDL_GetError());
  //   SDL_DestroyWindow(gWindow);
  //   SDL_Quit();
  //   return -1;
  // }

  bool running = true;

  while (running) {
    // SDL_Event event;

    // while (SDL_PollEvent(&event)) {

    //   if (event.type == SDL_EVENT_QUIT) {
    //     running = false;
    //   }
    // }
    Flush();
    

    SDL_Event input;
    
    while (SDL_PollEvent(&input)) {
      switch (input.type) {
      case SDL_EVENT_KEY_DOWN:
        gm.Papy.move(input);
        if (input.key.key == SDLK_ESCAPE)
          running = false;
        break;
      case SDL_EVENT_QUIT:
        running = false;
        break;
      }
    }

    
    SDL_Delay(25);
  }

  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();

  return 0;
}
