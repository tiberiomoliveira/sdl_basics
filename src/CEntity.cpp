#include "CEntity.h"

std::vector<CEntity*> CEntity::entity_list;

CEntity::CEntity()
: x(0.0f),
  y(0.0f),
  width(0),
  height(0),
  anim_state(0) {
  surf_entity = NULL;
}

CEntity::~CEntity() {}

bool
CEntity::on_load(std::string file,
                 int width,
                 int height,
                 int max_frames) {
  if ((surf_entity = CSurface::on_load(file)) == NULL)
    return false;

  CSurface::transparent(surf_entity, 255, 0, 255);

  this->width  = width;
  this->height = height;
  anim_control.max_frames = max_frames;

  return true;
}

void
CEntity::on_loop() {
  anim_control.on_animate();
}

void
CEntity::on_render(SDL_Surface* surf_display) {
  if (surf_entity == NULL || surf_display == NULL) return;

  CSurface::on_draw(surf_entity,
                    surf_display,
                    anim_state * width,
                    anim_control.get_current_frame() * height,
                    width, height,
                    x, y);
}

void
CEntity::on_cleanup() {
  if (surf_entity)
    SDL_FreeSurface(surf_entity);

  surf_entity = NULL;
}

