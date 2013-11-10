#ifndef _CAREA_H
#define _CAREA_H

#include "CMap.h"

class CArea {
public:
  CArea();
  bool on_load(std::string filename);
  void on_render(SDL_Surface *surf_display, int cam_x, int cam_y);
  void on_cleanup();

  static CArea      area_control;
  std::vector<CMap> map_list;
private:
  int          area_size;
  SDL_Surface *surf_tileset;
};

#endif
