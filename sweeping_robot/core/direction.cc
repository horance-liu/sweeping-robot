#include "sweeping_robot/core/direction.h"
#include "sweeping_robot/core/point.h"

Point Direction::move(const Point& from, bool forward) const {
  auto sign = forward ? 1 : -1;
  return from.move(sign * xOffset, sign * yOffset);
}

static Direction* directions[4] = {0};

const Direction& Direction::turn(bool left) const {
  auto numOfTurns = left ? 3 : 1;
  return *directions[(order + numOfTurns) % 4];
}

inline Direction::Direction(int order, int xOffset, int yOffset)
  : order(order), xOffset(xOffset), yOffset(yOffset) {
  directions[order] = this;
}

#define DEF_DIRECTION(name, order, xOffset, yOffset) \
  Direction Direction::name(order, xOffset, yOffset);

DEF_DIRECTION(E, 0, 1, 0)
DEF_DIRECTION(S, 1, 0, -1)
DEF_DIRECTION(W, 2, -1, 0)
DEF_DIRECTION(N, 3, 0, 1)

DEF_EQUALS(Direction) {
  return FIELD_EQ(order) && FIELD_EQ(xOffset) && FIELD_EQ(yOffset);
}
