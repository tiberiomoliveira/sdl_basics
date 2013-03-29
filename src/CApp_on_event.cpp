#include "CApp.h"

void CApp::on_event(SDL_Event* event) {
  CEvent::on_event(event);
}

void
CApp::on_lbutton_down(int m_x, int m_y) {
  int id = m_x / (SCREEN_WIDTH / 3);
  id += 3 * (m_y / (SCREEN_HEIGHT / 3));

  if (grid[id] != GRID_TYPE_NONE)
    return;

  if (current_player == 0) {
    set_cell(id, GRID_TYPE_X);
    current_player = 1;
  }
  else {
    set_cell(id, GRID_TYPE_O);
    current_player = 0;
  }
}

void CApp::on_exit() {
  running = false;
}

