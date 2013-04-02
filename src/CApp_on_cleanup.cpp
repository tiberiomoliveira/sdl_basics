#include "CApp.h"

void CApp::on_cleanup() {
  SDL_FreeSurface(surf_display);
  SDL_FreeSurface(surf_test);

  for (size_t i = 0; i < CEntity::entity_list.size(); ++i) {
    if (!CEntity::entity_list[i]) continue;

    CEntity::entity_list[i]->on_cleanup();
  }
  CEntity::entity_list.clear();

  SDL_Quit();
}
