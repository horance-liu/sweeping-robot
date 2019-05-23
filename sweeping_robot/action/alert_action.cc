#include "sweeping_robot/action/alert_action.h"
#include "sweeping_robot/core/point.h"
#include "sweeping_robot/out/output.h"

AlertAction::AlertAction(Output* out) : out(out) {
}

AlertAction::~AlertAction() {
  delete out;
}

void AlertAction::report(const Point& to) {
  out->write(to, *this);
}

std::string AlertAction::text(const Point& to) const {
  return std::string("Alert for passing ") + to.str() + " repeatly\n";
}

std::string AlertAction::desc() const {
  return "alert";
}
