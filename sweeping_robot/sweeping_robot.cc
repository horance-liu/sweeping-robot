#include "sweeping_robot/sweeping_robot.h"

SweepingRobot::SweepingRobot() : pos(0, 0, Direction::N) {
}

void SweepingRobot::exec(const Command& cmd) {
  pos = cmd(pos);
}

const Position& SweepingRobot::position() const {
  return pos;
}
