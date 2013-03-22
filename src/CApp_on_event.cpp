#include "CApp.h"

void CApp::on_event(SDL_Event* event) {
  if (event->type == SDL_QUIT)
    running = false;
}
