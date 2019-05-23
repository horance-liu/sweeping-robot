#include "sweeping_robot/listener/listener.h"
#include "sweeping_robot/listener/action_describing.h"
#include "sweeping_robot/core/point.h"
#include <unordered_map>

namespace {
struct NilListener : Listener {
  OVERRIDE(void onChanged(const Point& to)) {
  }
};
} // end namespace

Listener* nil() {
  return new NilListener;
}

namespace {
struct ListenerList : Listener {
  ListenerList(Listeners listeners)
    : listeners(std::move(listeners)) {
  }

  ~ListenerList() {
    for (auto listener : listeners) {
      delete listener;
    }
  }

private:
  OVERRIDE(void onChanged(const Point& to)) {
    for (auto listener : listeners) {
      listener->onChanged(to);
    }
  }

private:
  Listeners listeners;
};
} // end namespace

Listener* all(Listeners listeners) {
  return new ListenerList(std::move(listeners));
}

namespace {
struct Action : protected ActionDescribing {
  Action(Output out) : out(std::move(out)) {
  }

  void process(const Point& to) const {
    out(to, *this);
  }

private:
  Output out;
};

struct AlertAction : Action {
  using Action::Action;

private:
  OVERRIDE(std::string text(const Point& to) const) {
    return std::string("Alert for passing ") + to.str() + " repeatly\n";
  }

  OVERRIDE(const char* desc() const) {
    return "alert";
  }
};

struct StayListener : Listener {
  StayListener(int limit, Output out)
    : limit(limit), action(std::move(out)) {
  }

  void onChanged(const Point& to) {
    cache[to] += 1;
    if (overflow(to)) {
      action.process(to);
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
  return new StayListener(limit, std::move(out));
}

namespace {
struct CleanAction : Action {
  using Action::Action;

private:
  OVERRIDE(std::string text(const Point& to) const) {
    return std::string("Execute cleaning at ") + to.str() + "\n";
  }

  OVERRIDE(const char* desc() const) {
    return "clean";
  }
};

struct PathListener : Listener {
  PathListener(Points points, Output out)
    : points(std::move(points)), action(std::move(out)) {
  }

private:
  OVERRIDE(void onChanged(const Point& to)) {
    auto iter = std::find(points.cbegin(), points.cend(), to);
    if (iter != points.cend()) {
      action.process(to);
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
