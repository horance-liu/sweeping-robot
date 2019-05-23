#include "sweeping_robot/listener/listener.h"
#include "sweeping_robot/action/clean_action.h"
#include "sweeping_robot/action/alert_action.h"
#include "sweeping_robot/core/point.h"
#include <unordered_map>

namespace {
struct PathListener : Listener {
  PathListener(Points points, Output out)
    : points(std::move(points)), action(std::move(out)) {
  }

private:
  OVERRIDE(void onChanged(const Point& to)) {
    auto iter = std::find(points.cbegin(), points.cend(), to);
    if (iter != points.cend()) {
      action.clean(to);
      points.erase(iter);
    }
  }

private:
  Points points;
  CleanAction action;
};
} // end namespace

Listener* path(Points points, Output out) {
  return new PathListener(std::move(points), std::move(out));
}

namespace {
struct StayingListener : Listener {
  StayingListener(int limit, Output out)
    : limit(limit), action(std::move(out)) {
  }

  void onChanged(const Point& to) {
    cache[to] += 1;
    if (overflow(to)) {
      action.report(to);
      cache.erase(to);
    }
  }

private:
  bool overflow(const Point& to) {
    return cache[to] == limit;
  }

private:
  int limit;
  AlertAction action;
  std::unordered_map<Point, int> cache;
};
} // end namespace

Listener* stay(int limit, Output out) {
  return new StayingListener(limit, std::move(out));
}
