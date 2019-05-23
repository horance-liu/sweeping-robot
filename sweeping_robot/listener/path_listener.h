#ifndef H113D8729_C944_4AF7_8BD8_6EA9FED21EC1
#define H113D8729_C944_4AF7_8BD8_6EA9FED21EC1

#include "sweeping_robot/core/point.h"
#include "sweeping_robot/listener/listener.h"
#include "sweeping_robot/action/clean_action.h"
#include <unordered_set>

struct PathListener : Listener {
  using Points = std::unordered_set<Point>;
  PathListener(Points points, Output* out);

private:
  OVERRIDE(void onChanged(const Point&));

private:
  CleanAction action;
  Points points;
};

#endif
