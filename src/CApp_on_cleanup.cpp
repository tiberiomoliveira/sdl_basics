#include "CApp.h"

void CApp::on_cleanup() {
  SDL_FreeSurface(surf_display);
  SDL_FreeSurface(surf_grid);
  SDL_FreeSurface(surf_x);
  SDL_FreeSurface(surf_o);
  SDL_Quit();
}
