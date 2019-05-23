#include "sweeping_robot/action/clean_action.h"
#include "sweeping_robot/core/point.h"

CleanAction::CleanAction(Output* out) : out(out) {
}

void CleanAction::clean(const Point& to) {
  out->write(to, *this);
}

std::string CleanAction::text(const Point& to) const {
  return std::string("Execute cleaning at ") + to.str() + "\n";
}

const char* CleanAction::desc() const {
  return "clean";
}
