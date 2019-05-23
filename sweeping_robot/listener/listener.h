#ifndef H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B
#define H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B

#include "cub/base/keywords.h"
#include "sweeping_robot/out/output.h"
#include <unordered_set>

DEF_INTERFACE(Listener) {
  ABSTRACT(void onChanged(const Point&));
};

using Points = std::unordered_set<Point>;

Listener* path(Points points, Output out);
Listener* stay(int limit, Output out);

#endif
