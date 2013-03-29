#ifndef _CANIMATION_H_
#define _CANIMATION_H_

#include <SDL/SDL.h>

class CAnimation {
  public:
    CAnimation();
    void on_animation();

    void set_frame_rate(int rate);
    void set_current_frame(int frame);
    int  get_current_frame();

    int  max_frames;
    bool oscillate;

  private:
    int  current_frame;
    int  frame_inc;
    int  frame_rate; // milliseconds
    long old_time;
};

#endif
