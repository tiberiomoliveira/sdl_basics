#include "CApp.h"

void CApp::on_render() {
  CSurface::on_draw(surf_test, surf_display, 0, 0);
  CSurface::on_draw(surf_test, surf_display, 0, 0, 50, 50, 100, 100);

  SDL_Flip(surf_display);
}
