#ifndef HC06FD787_5D01_4F44_8FF2_9569D9E81CC7
#define HC06FD787_5D01_4F44_8FF2_9569D9E81CC7

#include "sweeping_robot/action/action_describing.h"
#include "sweeping_robot/out/output.h"
#include <memory>

struct Point;

struct CleanAction : private ActionDescribing {
  CleanAction(Output* out);
  void clean(const Point&);

private:
  OVERRIDE(std::string text(const Point&) const);
  OVERRIDE(const char* desc() const);

private:
  std::unique_ptr<Output> out;
};


#endif
