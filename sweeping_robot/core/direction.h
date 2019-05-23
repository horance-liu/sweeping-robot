#ifndef H9811B75A_15B3_4DF0_91B7_483C42F74473
#define H9811B75A_15B3_4DF0_91B7_483C42F74473

#include "cub/base/comparator.h"

struct Point;

struct Direction {
  const Direction& turn(bool left) const;
  Point move(const Point& from, bool forward) const;

  static Direction E;
  static Direction S;
  static Direction W;
  static Direction N;

  DECL_EQUALS(Direction);

private:
  Direction(int order, int xOffset, int yOffset);

private:
  int order;
  int xOffset;
  int yOffset;
};

#endif
