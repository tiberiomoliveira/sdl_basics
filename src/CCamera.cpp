#include "CCamera.h"

CCamera CCamera::camera_control;

CCamera::CCamera() {
  x_ = y_ = 0;

  target_x = target_y = 0;

  target_mode = TARGET_MODE_NORMAL;
}

void
CCamera::on_move(int move_x, int move_y) {
  x_ += move_x;
  y_ += move_y;
}

int
CCamera::get_x() {
  if (target_x != NULL) {
    if (target_mode == TARGET_MODE_CENTER)
      return *target_x - SCREEN_WIDTH / 2;

    return *target_x;
  }

  return x_;
}

int
CCamera::get_y() {
  if (target_y != NULL) {
    if (target_mode == TARGET_MODE_CENTER)
      return *target_y - SCREEN_HEIGHT / 2;

    return *target_y;
  }

  return y_;
}

void
CCamera::set_pos(int x, int y) {
  x_ = x;
  y_ = y;
}

void
CCamera::set_target(int *x, int *y) {
  target_x = x;
  target_y = y;
}
