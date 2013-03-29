#include "CApp.h"

CApp::CApp ()
: running(true),
  current_player(0) {
  surf_display = NULL;
  surf_grid = NULL;
  surf_x = NULL;
  surf_o = NULL;
}

int
CApp::on_execute() {
  if (!on_init())
    return -1;

  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event))
      on_event(&event);

    on_loop();
    on_render();
  }

  on_cleanup();

  return 0;
}

void
CApp::reset() {
  for (int i = 0; i < 9; ++i)
    grid[i] = GRID_TYPE_NONE;
}

void
CApp::set_cell(int id, int type) {
  if (id < 0 || id >= 9) return;
  if (type < 0 || type > GRID_TYPE_O) return;

  grid[id] = type;
}

int
main(int argc, char* argv[]) {
  CApp the_app;

  return the_app.on_execute();
}
