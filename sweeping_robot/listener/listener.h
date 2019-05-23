#ifndef H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B
#define H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B

#include "cub/base/keywords.h"
#include "sweeping_robot/out/output.h"

#include <vector>
#include <unordered_set>

DEF_INTERFACE(Listener) {
  ABSTRACT(void onChanged(const Point&));
};

using Listeners = std::vector<Listener*>;
using Points = std::unordered_set<Point>;

Listener* nil();
Listener* all(Listeners);

Listener* path(Points, Output);
Listener* stay(int limit, Output);

#endif
