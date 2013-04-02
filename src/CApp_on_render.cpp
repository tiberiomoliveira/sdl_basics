#include "CApp.h"

void CApp::on_render() {
  CSurface::on_draw(surf_test, surf_display,
                    0, anim_yoshi.get_current_frame() * SPRITE_SIZE,
                    SPRITE_SIZE, SPRITE_SIZE,
                    SCREEN_WIDTH / 2 - SPRITE_SIZE / 2,
                    SCREEN_HEIGHT / 2 - SPRITE_SIZE / 2);

  for (size_t i = 0; i < CEntity::entity_list.size(); ++i) {
    if (!CEntity::entity_list[i]) continue;

    CEntity::entity_list[i]->on_render(surf_display);
  }

  SDL_Flip(surf_display);
}
