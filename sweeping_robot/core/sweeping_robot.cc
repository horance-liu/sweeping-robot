#include "sweeping_robot/core/sweeping_robot.h"

SweepingRobot::SweepingRobot(Listener* listener)
  : listener(listener), pos(0, 0, Direction::N) {
}

void SweepingRobot::exec(const Command& cmd) {
  pos = cmd(pos, *listener);
}

const Position& SweepingRobot::position() const {
  return pos;
}
