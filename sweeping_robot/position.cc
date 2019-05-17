#include "sweeping_robot/position.h"

Position::Position(int x, int y, const Direction& d)
  : Position(Point(x, y), d) {
}

Position::Position(const Point& point, const Direction& d)
  : point(point), direction(d) {
}

Position Position::turn(bool left) const {
  return {point, direction.turn(left)};
}

Position Position::move(int steps) const {
  return {direction.move(point, steps), direction};
}

DEF_EQUALS(Position) {
  return FIELD_EQ(point) && FIELD_EQ(direction);
}
