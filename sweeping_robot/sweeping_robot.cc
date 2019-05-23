#include "sweeping_robot/sweeping_robot.h"

SweepingRobot::SweepingRobot(Rule& rule)
  : rule(rule), pos(0, 0, Direction::N) {
}

void SweepingRobot::exec(const Command& cmd) {
  pos = cmd(pos, rule);
}

const Position& SweepingRobot::position() const {
  return pos;
}
