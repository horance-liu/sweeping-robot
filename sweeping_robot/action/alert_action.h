#ifndef H56BAFF9A_0D46_4618_A6F3_54CA1074A7FD
#define H56BAFF9A_0D46_4618_A6F3_54CA1074A7FD

#include "sweeping_robot/action/action_describing.h"
#include "sweeping_robot/out/output.h"
#include <memory>

struct Point;

struct AlertAction : private ActionDescribing {
  AlertAction(Output* out);
  void report(const Point&);

private:
  OVERRIDE(std::string text(const Point&) const);
  OVERRIDE(const char* desc() const);

private:
  std::unique_ptr<Output> out;
};


#endif
