#include "sweeping_robot/listener/path_listener.h"

PathListener::PathListener(std::vector<Point> points, Output* out)
  : action(out), points(std::move(points)) {
}

void PathListener::onChanged(const Point& to) {
  auto iter = std::find(points.cbegin(), points.cend(), to);
  if (iter != points.cend()) {
    action.clean(to);
    points.erase(iter);
  }
}
