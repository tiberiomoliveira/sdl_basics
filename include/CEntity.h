#ifndef _CENTITY_H_
#define _CENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"

class CEntity {
  public:
    CEntity();
    virtual ~CEntity();

    virtual bool on_load(std::string file,
                         int width,
                         int height,
                         int max_frames);
    virtual void on_loop();
    virtual void on_render(SDL_Surface* surf_display);
    virtual void on_cleanup();

    static std::vector<CEntity*> entity_list;
    float                        x;
    float                        y;
    int                          width;
    int                          height;
    int                          anim_state;

  protected:
    CAnimation   anim_control;
    SDL_Surface* surf_entity;
};

#endif
