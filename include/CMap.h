#ifndef _CMAP_H
#define _CMAP_H

#include <SDL/SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap {
public:
  CMap();

  bool on_load(std::string filename);
  void on_render(SDL_Surface* surf_display, int map_x, int map_y);

  SDL_Surface* surf_tileset;

private:
  std::vector<CTile> tile_list;
};

#endif
