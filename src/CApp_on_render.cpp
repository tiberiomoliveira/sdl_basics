#include "CApp.h"

void CApp::on_render() {
  CSurface::on_draw(surf_grid, surf_display, 0, 0);

  for (int i = 0; i < 9; ++i) {
    int x = (i % 3) * (SCREEN_WIDTH / 3);
    int y = (i / 3) * (SCREEN_HEIGHT / 3);

    if (grid[i] == GRID_TYPE_X)
      CSurface::on_draw(surf_x, surf_display, x, y);
    else
      if (grid[i] == GRID_TYPE_O)
        CSurface::on_draw(surf_o, surf_display, x, y);

  }

  SDL_Flip(surf_display);
}
