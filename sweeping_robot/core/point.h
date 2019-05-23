#ifndef H65A54D80_942C_4AB0_846B_A0568EA5200D
#define H65A54D80_942C_4AB0_846B_A0568EA5200D

#include "cub/base/comparator.h"

struct Point {
  Point(int x, int y);

  Point move(int xoffset, int yoffset) const;

  DECL_EQUALS(Point);

private:
  int x, y;
};

#endif
