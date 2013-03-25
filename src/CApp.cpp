#include "CApp.h"

CApp::CApp ()
: running(true) {
  surf_display = NULL;
  surf_test    = NULL;
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

int
main(int argc, char* argv[]) {
  CApp the_app;

  return the_app.on_execute();
}
