#ifndef _CTILE_H
#define _CTILE_H

#include "Define.h"

enum {
  TILE_TYPE_NONE = 0,
  TILE_TYPE_NORMAL,
  TILE_TYPE_BLOCK
};

class CTile {
  public:
    CTile();

    int tile_id;
    int type_id;
};

#endif
