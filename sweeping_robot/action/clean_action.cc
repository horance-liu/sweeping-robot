#include "sweeping_robot/action/clean_action.h"
#include "sweeping_robot/core/point.h"
#include "sweeping_robot/out/output.h"

CleanAction::CleanAction(Output* out) : out(out) {
}

CleanAction::~CleanAction() {
  delete out;
}

void CleanAction::clean(const Point& to) {
  out->write(to, *this);
}

std::string CleanAction::text(const Point& to) const {
  return std::string("Execute cleaning at ") + to.str() + "\n";
}

std::string CleanAction::desc() const {
  return "clean";
}
