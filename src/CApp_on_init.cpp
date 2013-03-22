#include "CApp.h"

bool CApp::on_init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  surf_display = SDL_SetVideoMode(SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (surf_display == NULL)
    return false;

  return true;
}

