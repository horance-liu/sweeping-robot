#include "sweeping_robot/action/clean_action.h"
#include "sweeping_robot/core/point.h"

CleanAction::CleanAction(Output out) : out(std::move(out)) {
}

void CleanAction::clean(const Point& to) const {
  out(to, *this);
}

std::string CleanAction::text(const Point& to) const {
  return std::string("Execute cleaning at ") + to.str() + "\n";
}

const char* CleanAction::desc() const {
  return "clean";
}
