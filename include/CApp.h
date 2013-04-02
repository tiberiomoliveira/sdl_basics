#ifndef _CAPP_H_
#define _CAPP_H_

#include "CEntity.h"
#include "CEvent.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE   64

class CApp : public CEvent{
  public:
    CApp();

    int  on_execute();
    bool on_init();
    void on_event(SDL_Event* event);
    void on_exit();
    void on_loop();
    void on_render();
    void on_cleanup();

  private:
    bool         running;
    SDL_Surface* surf_display;
    SDL_Surface* surf_test;
    CAnimation   anim_yoshi;
    CEntity      entity_1;
    CEntity      entity_2;
};

#endif
