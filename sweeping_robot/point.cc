#include "sweeping_robot/point.h"

Point::Point(int x, int y) : x(x), y(y) {
}

Point Point::move(int xOffset, int yOffset) const {
  return {x + xOffset, y + yOffset};
}

DEF_EQUALS(Point) {
  return FIELD_EQ(x) && FIELD_EQ(y);
}
