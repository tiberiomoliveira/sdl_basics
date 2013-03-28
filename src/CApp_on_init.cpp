#include "CApp.h"

bool CApp::on_init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((surf_display = SDL_SetVideoMode(SCREEN_WIDTH,
                                       SCREEN_HEIGHT,
                                       32,
                                       SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

  if ((surf_grid = CSurface::on_load("./sprites/grid.bmp")) == NULL)
    return false;

  if ((surf_x = CSurface::on_load("./sprites/x.bmp")) == NULL)
    return false;

  if ((surf_o = CSurface::on_load("./sprites/o.bmp")) == NULL)
    return false;

  CSurface::transparent(surf_x, 255, 0, 255);
  CSurface::transparent(surf_o, 255, 0, 255);

  reset();

  return true;
}

