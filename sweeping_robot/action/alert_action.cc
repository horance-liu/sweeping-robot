#include "sweeping_robot/action/alert_action.h"
#include "sweeping_robot/core/point.h"

AlertAction::AlertAction(Output* out) : out(out) {
}

void AlertAction::report(const Point& to) {
  out->write(to, *this);
}

std::string AlertAction::text(const Point& to) const {
  return std::string("Alert for passing ") + to.str() + " repeatly\n";
}

const char* AlertAction::desc() const {
  return "alert";
}
