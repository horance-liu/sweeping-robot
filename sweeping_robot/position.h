#ifndef H722C49C6_D285_4885_88D1_97A11D669EE1
#define H722C49C6_D285_4885_88D1_97A11D669EE1

#include "sweeping_robot/direction.h"
#include "sweeping_robot/point.h"

struct Position {
  Position(int x, int y, const Direction& d);
  Position(const Point& point, const Direction& d);

  Position turn(bool left) const;
  Position move(int step) const;

  DECL_EQUALS(Position);

private:
  Point point;
  Direction direction;
};

#endif
