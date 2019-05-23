#ifndef H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B
#define H7E0F9253_B9EB_4F35_85E0_A2BF6B7DB27B

#include "cub/base/keywords.h"

struct Point;

DEF_INTERFACE(Listener) {
  ABSTRACT(void onChanged(const Point&));
};

#endif
