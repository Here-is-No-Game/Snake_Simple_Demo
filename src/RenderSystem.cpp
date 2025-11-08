#include "RenderSystem.hpp"
#include "Print.hpp"

SDL_Window *gWindow =nullptr;
SDL_Renderer* gRenderer = nullptr;
void Flush() {
  SDL_RenderClear(gRenderer);
  PrintMap();
  PrintLine();
  SDL_RenderPresent(gRenderer);
}