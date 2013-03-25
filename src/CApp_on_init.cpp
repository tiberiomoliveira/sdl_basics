#include "CApp.h"

bool CApp::on_init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((surf_display = SDL_SetVideoMode(SCREEN_WIDTH,
                                       SCREEN_HEIGHT,
                                       32,
                                       SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

  if ((surf_test = CSurface::on_load("sprites/image.bmp")) == NULL)
    return false;

  return true;
}

