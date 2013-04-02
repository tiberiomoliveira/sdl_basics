#include "CApp.h"

bool CApp::on_init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((surf_display = SDL_SetVideoMode(SCREEN_WIDTH,
                                       SCREEN_HEIGHT,
                                       32,
                                       SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

  if ((surf_test = CSurface::on_load("./sprites/yoshi.bmp")) == NULL)
    return false;
  CSurface::transparent(surf_test, 255, 0, 255);

  anim_yoshi.max_frames = 8;

  if (!entity_1.on_load("./sprites/yoshi.bmp", SPRITE_SIZE, SPRITE_SIZE, 8))
    return false;

  if (!entity_2.on_load("./sprites/yoshi.bmp", SPRITE_SIZE, SPRITE_SIZE, 8))
    return false;

  entity_1.x = 100;
  entity_2.x = 200;

  CEntity::entity_list.push_back(&entity_1);
  CEntity::entity_list.push_back(&entity_2);

  return true;
}

