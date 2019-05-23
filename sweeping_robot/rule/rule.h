#ifndef HAFEC11A9_9353_4B6E_91F0_4BB5A1D1CDEA
#define HAFEC11A9_9353_4B6E_91F0_4BB5A1D1CDEA

#include "cub/base/keywords.h"

struct Position;

DEF_INTERFACE(Rule) {
  ABSTRACT(const Position& apply(const Position& to));
  static Rule& nil();
};

#endif
