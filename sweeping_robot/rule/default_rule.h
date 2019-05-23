#ifndef H233E8DEF_65D8_4723_A19E_2A1C78B0B6C2
#define H233E8DEF_65D8_4723_A19E_2A1C78B0B6C2

#include "sweeping_robot/rule/rule.h"
#include <vector>

struct Listener;

struct DefaultRule : Rule {
  DefaultRule(std::vector<Listener*>);
  ~DefaultRule();

private:
  OVERRIDE(const Position& apply(const Position& to) const);

private:
  std::vector<Listener*> listeners;
};

#endif
