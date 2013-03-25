#include "CApp.h"

void CApp::on_cleanup() {
  SDL_FreeSurface(surf_display);
  SDL_FreeSurface(surf_test);
  SDL_Quit();
}
