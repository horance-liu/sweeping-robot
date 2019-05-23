#include "sweeping_robot/listener/staying_listener.h"

StayingListener::StayingListener(int limit, Output* out)
  : limit(limit), action(out) {
}

inline bool StayingListener::overflow(const Point& to) {
  return cache[to] == limit;
}

void StayingListener::onChanged(const Point& to) {
  cache[to] += 1;
  if (overflow(to)) {
    action.report(to);
    cache.erase(to);
  }
}
