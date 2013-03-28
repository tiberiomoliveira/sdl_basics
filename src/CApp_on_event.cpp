#include "CApp.h"

void CApp::on_event(SDL_Event* event) {
  CEvent::on_event(event);
}

void CApp::on_exit() {
  running = false;
}
