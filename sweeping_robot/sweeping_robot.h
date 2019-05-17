#ifndef H632C2FEA_66F0_4B68_B047_121B6CE1482E
#define H632C2FEA_66F0_4B68_B047_121B6CE1482E

#include "sweeping_robot/command.h"
#include "sweeping_robot/position.h"

struct SweepingRobot {
  SweepingRobot();

  void exec(const Command&);
  const Position& position() const;

private:
  Position pos;
};

#endif
