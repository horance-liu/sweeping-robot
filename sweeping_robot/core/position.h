#ifndef H722C49C6_D285_4885_88D1_97A11D669EE1
#define H722C49C6_D285_4885_88D1_97A11D669EE1

#include "sweeping_robot/core/direction.h"
#include "sweeping_robot/core/point.h"

struct Position {
  Position(int x, int y, const Direction& d);
  Position(const Point& point, const Direction& d);

  Position turn(bool left) const;
  Position move(bool forward) const;

  const Point& getPoint() const;

  DECL_EQUALS(Position);

private:
  Point point;
  Direction direction;
};

#endif
