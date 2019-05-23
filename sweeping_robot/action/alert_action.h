#ifndef H56BAFF9A_0D46_4618_A6F3_54CA1074A7FD
#define H56BAFF9A_0D46_4618_A6F3_54CA1074A7FD

#include "sweeping_robot/action/action_describing.h"

struct Output;
struct Point;

struct AlertAction : private ActionDescribing {
  AlertAction(Output* out);
  ~AlertAction();

  void report(const Point&);

private:
  OVERRIDE(std::string text(const Point&) const);
  OVERRIDE(std::string desc() const);

private:
  Output* out;
};


#endif
