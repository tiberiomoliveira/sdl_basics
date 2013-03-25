#include "CSurface.h"

CSurface::CSurface() {}

SDL_Surface*
CSurface::on_load(std::string filename) {
  SDL_Surface* surf_temp   = NULL;
  SDL_Surface* surf_return = NULL;

  if ((surf_temp = SDL_LoadBMP(filename.c_str())) == NULL)
    return NULL;

  surf_return = SDL_DisplayFormat(surf_temp);
  SDL_FreeSurface(surf_temp);

  return surf_return;
}

bool
CSurface::on_draw(SDL_Surface* surf_src,
                  SDL_Surface* surf_dst,
                  int x, int y) {
  if (surf_src == NULL || surf_dst == NULL)
    return false;

  SDL_Rect rect_dst;

  rect_dst.x = x;
  rect_dst.y = y;

  if (SDL_BlitSurface(surf_src, NULL, surf_dst, &rect_dst) == -1)
    return false;

  return true;
}

bool
CSurface::on_draw(SDL_Surface* surf_src,
                  SDL_Surface* surf_dst,
                  int x1, int y1,
                  int w,  int h,
                  int x2, int y2) {
  if (surf_src == NULL || surf_dst == NULL)
    return false;

  SDL_Rect rect_src;
  rect_src.x = x1;
  rect_src.y = y1;
  rect_src.w = w;
  rect_src.h = h;

  SDL_Rect rect_dst;
  rect_dst.x = x2;
  rect_dst.y = y2;

  if ((SDL_BlitSurface(surf_src, &rect_src, surf_dst, &rect_dst)) == -1)
    return false;

  return true;
}
