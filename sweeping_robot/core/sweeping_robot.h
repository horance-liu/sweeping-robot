#ifndef H632C2FEA_66F0_4B68_B047_121B6CE1482E
#define H632C2FEA_66F0_4B68_B047_121B6CE1482E

#include "sweeping_robot/cmd/command.h"
#include "sweeping_robot/core/position.h"
#include "sweeping_robot/rule/rule.h"

struct SweepingRobot {
  SweepingRobot(const Rule& = Rule::nil());

  void exec(const Command&);
  const Position& position() const;

private:
  const Rule& rule;
  Position pos;
};

#endif
