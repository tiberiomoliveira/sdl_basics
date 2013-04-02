#include "CApp.h"

void CApp::on_loop() {
  anim_yoshi.on_animate();

  for (size_t i = 0; i < CEntity::entity_list.size(); ++i) {
    if (!CEntity::entity_list[i]) continue;

    CEntity::entity_list[i]->on_loop();
  }
}

