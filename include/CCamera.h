#ifndef CCAMERA_H_
#define CCAMERA_H_

#include <SDL/SDL.h>

#include "Define.h"

enum {
  TARGET_MODE_NORMAL = 0,
  TARGET_MODE_CENTER
};

class CCamera {
  public:
    CCamera();

    void on_move(int move_x, int move_y);
    int  get_x();
    int  get_y();
    void set_pos(int x, int y);
    void set_target(int *x, int *y);

    static CCamera camera_control;
    int target_mode;

  private:
    int x_;
    int y_;
    int *target_x;
    int *target_y;
};

#endif
