#include <fstream>
#include <sstream>

#include "CMap.h"

CMap::CMap() {
  surf_tileset = NULL;
}

bool
CMap::on_load(std::string filename) {
  tile_list.clear();

  std::ifstream input_file(filename.c_str());

  if (!input_file.is_open())
    return false;

  for (int y = 0; y < MAP_HEIGHT; ++y) {
    std::string line;
    getline(input_file, line);
    std::stringstream sline(line);
    for (int x = 0; x < MAP_WIDTH; ++x) {
      CTile tmp_tile;

      std::string token;
      getline(sline, token, ' ');
      std::stringstream ss(token);
      ss >> tmp_tile.tile_id;
      ss.seekg(ss.tellg() + (long)1);
      ss >> tmp_tile.type_id;

      tile_list.push_back(tmp_tile);
    }
  }
  input_file.close();

  return true;
}

void
CMap::on_render(SDL_Surface* surf_display, int map_x, int map_y) {
  if (surf_tileset == NULL) return;

  int tileset_width  = surf_tileset->w / TILE_SIZE;
  //int tileset_height = surf_tileset->h / TILE_SIZE;
  int t_x;
  int t_y;
  int tileset_x;
  int tileset_y;

  for (int y = 0, id = 0; y < MAP_HEIGHT; ++y) {
    for (int x = 0; x < MAP_WIDTH; ++x, ++id) {
      if (tile_list[id].type_id == TILE_TYPE_NONE) continue;

      t_x = map_x + (x * TILE_SIZE);
      t_y = map_y + (y * TILE_SIZE);

      tileset_x = (tile_list[id].tile_id % tileset_width) * TILE_SIZE;
      tileset_y = (tile_list[id].tile_id / tileset_width) * TILE_SIZE;

      CSurface::on_draw(surf_tileset, surf_display,
                        tileset_x, tileset_y, TILE_SIZE, TILE_SIZE,
                        t_x, t_y);
    }
  }
}
