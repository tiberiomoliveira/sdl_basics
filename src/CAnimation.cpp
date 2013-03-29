#include "CAnimation.h"

CAnimation::CAnimation()
: max_frames(0),
  oscillate(false),
  current_frame(0),
  frame_inc(1),
  frame_rate(100),
  old_time(0) {}

void
CAnimation::on_animation() {
  if (old_time + frame_rate > SDL_GetTicks())
    return;

  old_time = SDL_GetTicks();
  current_frame += frame_inc;

  if (oscillate) {
    if (frame_inc > 0) {
      if (current_frame >= max_frames)
        frame_inc = -frame_inc;
    }
    else {
      if (current_frame <= 0)
        frame_inc = -frame_inc;
    }
  }
  else {
    if (current_frame >= max_frames)
      current_frame = 0;
  }
}

void
CAnimation::set_frame_rate(int rate) { frame_rate = rate; }

void
CAnimation::set_current_frame(int frame) {
  if (frame < 0 || frame >= max_frames) return;

  current_frame = frame;
}

int
CAnimation::get_current_frame() { return current_frame; }
