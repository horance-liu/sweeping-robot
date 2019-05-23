#ifndef HDCAC8AA5_CAAD_4976_9847_078EF430D113
#define HDCAC8AA5_CAAD_4976_9847_078EF430D113

#include "cub/base/keywords.h"
#include <string>

struct Point;

DEF_INTERFACE(ActionDescribing) {
  ABSTRACT(std::string text(const Point&) const);
  ABSTRACT(std::string desc() const);
};


#endif
