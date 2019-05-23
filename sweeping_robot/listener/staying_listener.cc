#include "sweeping_robot/listener/staying_listener.h"

#include <iostream>

StayingListener::StayingListener(int limit, Output* out)
  : limit(limit), action(out) {
}

inline bool StayingListener::overflow(const Point& to) {
  return cache[to] == limit;
}

void StayingListener::onChanged(const Point& to) {
  cache[to] += 1;
  std::cout << "before overflow" << std::endl;
  for (auto& iter : cache) {
    std::cout << iter.first << "->" << iter.second << std::endl;
  }

  if (overflow(to)) {
    action.report(to);
    cache.erase(to);
    std::cout << "after overflow" << std::endl;
    for (auto& iter : cache) {
      std::cout << iter.first << "->" << iter.second << std::endl;
    }
  }
}
