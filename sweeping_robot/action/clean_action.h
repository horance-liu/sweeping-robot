#ifndef HC06FD787_5D01_4F44_8FF2_9569D9E81CC7
#define HC06FD787_5D01_4F44_8FF2_9569D9E81CC7

#include "sweeping_robot/action/action_describing.h"

struct Output;
struct Point;

struct CleanAction : private ActionDescribing {
  CleanAction(Output* out);
  ~CleanAction();

  void clean(const Point&);

private:
  OVERRIDE(std::string text(const Point&) const);
  OVERRIDE(std::string desc() const);

private:
  Output* out;
};


#endif
