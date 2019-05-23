#include "sweeping_robot/rule/default_rule.h"
#include "sweeping_robot/listener/listener.h"
#include "sweeping_robot/core/position.h"

DefaultRule::DefaultRule(std::vector<Listener*> listeners)
  : listeners(std::move(listeners)) {
}

DefaultRule::~DefaultRule() {
  for (auto listener : listeners) {
    delete listener;
  }
}

const Position& DefaultRule::apply(const Position& to) const {
  for (auto listener : listeners) {
    listener->onChanged(to.getPoint());
  }
  return to;
}
