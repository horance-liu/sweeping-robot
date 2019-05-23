#include "sweeping_robot/core/position.h"

Position::Position(int x, int y, const Direction& d)
  : Position(Point(x, y), d) {
}

Position::Position(const Point& point, const Direction& d)
  : point(point), direction(d) {
}

Position Position::turn(bool left) const {
  return {point, direction.turn(left)};
}

Position Position::move(bool forward) const {
  return {direction.move(point, forward), direction};
}

const Point& Position::getPoint() const {
  return point;
}

DEF_EQUALS(Position) {
  return FIELD_EQ(point) && FIELD_EQ(direction);
}
