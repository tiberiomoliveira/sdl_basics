#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <string>
#include <SDL/SDL.h>

class CSurface {
  public:
    CSurface();

    static SDL_Surface* on_load(std::string filename);
    static bool         on_draw(SDL_Surface* surf_src,
                                SDL_Surface* surf_dst,
                                int x, int y);
    static bool         on_draw(SDL_Surface* surf_src,
                                SDL_Surface* surf_dst,
                                int x1, int y1,
                                int w,  int h,
                                int x2, int y2);
    static bool         transparent(SDL_Surface* surf_dst,
                                    int r, int g, int b);
};

#endif
