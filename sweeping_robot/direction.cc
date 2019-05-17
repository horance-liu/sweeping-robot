#include "sweeping_robot/direction.h"
#include "sweeping_robot/point.h"

Point Direction::move(const Point& from, int steps) const {
  return from.move(steps * xOffset, steps * yOffset);
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

DEF_DIRECTION(E, 0,  1,  0)
DEF_DIRECTION(S, 1,  0, -1)
DEF_DIRECTION(W, 2, -1,  0)
DEF_DIRECTION(N, 3,  0,  1)

DEF_EQUALS(Direction) {
  return FIELD_EQ(order) && FIELD_EQ(xOffset) && FIELD_EQ(yOffset);
}
