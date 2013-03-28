#ifndef _CAPP_H_
#define _CAPP_H_

#include "CSurface.h"
#include "CEvent.h"

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

class CApp : public CEvent{
  public:
    CApp();
    int on_execute();
    void reset();
    void set_cell(int id, int type);

  public:
    bool on_init();
    void on_event(SDL_Event* event);
    void on_lbutton_down(int m_x, int m_y);
    void on_exit();
    void on_loop();
    void on_render();
    void on_cleanup();

  private:
    bool         running;
    SDL_Surface* surf_display;
    SDL_Surface* surf_grid;
    SDL_Surface* surf_x;
    SDL_Surface* surf_o;
    int          grid[9];
    enum {
      GRID_TYPE_NONE = 0,
      GRID_TYPE_X,
      GRID_TYPE_O
    };
    int current_player;
};

#endif
