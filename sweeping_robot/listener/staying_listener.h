#ifndef HDDFD9772_2BD6_44B7_808E_EC5F40519BF5
#define HDDFD9772_2BD6_44B7_808E_EC5F40519BF5

#include "sweeping_robot/core/point.h"
#include "sweeping_robot/listener/listener.h"
#include "sweeping_robot/action/alert_action.h"
#include <unordered_map>

struct StayingListener : Listener {
  StayingListener(int limit, Output* out);

private:
  OVERRIDE(void onChanged(const Point&));

private:
  bool overflow(const Point& to);

private:
  int limit;
  AlertAction action;
  std::unordered_map<Point, int> cache;
};

#endif
