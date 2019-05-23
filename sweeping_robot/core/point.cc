#include "sweeping_robot/core/point.h"

Point::Point(int x, int y) : x(x), y(y) {
}

size_t Point::hash() const noexcept {
  return 7 * x + y;
}

std::string Point::str() const {
  return std::string("(")  +
         std::to_string(x) + ", " +
         std::to_string(y) + ")";
}

int Point::getX() const {
  return x;
}

int Point::getY() const {
  return y;
}

Point Point::move(int xOffset, int yOffset) const {
  return {x + xOffset, y + yOffset};
}

DEF_EQUALS(Point) {
  return FIELD_EQ(x) && FIELD_EQ(y);
}
