#include <fstream>
#include <sstream>

#include "CArea.h"

CArea CArea::area_control;

CArea::CArea() {
  area_size = 0;
}

bool
CArea::on_load(std::string filename) {
  map_list.clear();

  std::ifstream fs(filename.c_str());

  if (! fs.is_open())
    return false;

  std::string tileset_file;
  getline(fs, tileset_file);

  if ((surf_tileset = CSurface::on_load(tileset_file)) == NULL) {
    fs.close();
    return false;
  }

  std::string str_line;
  getline(fs, str_line);
  std::stringstream ssline(str_line);

  ssline >> area_size;

  for (int x = 0; x < area_size; ++x) {
    str_line.clear();
    ssline.str(std::string());
    ssline.clear();
    getline(fs, str_line);
    ssline << str_line;
    for (int y = 0; y < area_size; ++y) {
      std::string map_file;
      ssline >> map_file;

      CMap temp_map;
      if (temp_map.on_load(map_file) == false) {
        fs.close();

        return false;
      }

      temp_map.surf_tileset = surf_tileset;
      map_list.push_back(temp_map);
    }
  }
  fs.close();

  return true;
}

void
CArea::on_render(SDL_Surface *surf_display, int cam_x, int cam_y) {
  int map_width  = MAP_WIDTH  * TILE_SIZE;
  int map_height = MAP_HEIGHT * TILE_SIZE;
  int first_id   = (-cam_x / map_width) + area_size * (-cam_y / map_height);

  for (int i = 0; i < 4; ++i) {
    unsigned id = first_id + ((i / 2) * area_size) + (i % 2);

    if (id < 0 || id >= map_list.size()) continue;

    int x = ((id % 2) * map_width) + cam_x;
    int y = ((id / 2) * map_height) + cam_y;

    map_list[id].on_render(surf_display, x, y);
  }
}

void
CArea::on_cleanup() {
  if (surf_tileset)
    SDL_FreeSurface(surf_tileset);

  map_list.clear();
}
