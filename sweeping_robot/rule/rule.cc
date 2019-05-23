#include "sweeping_robot/rule/rule.h"

namespace {
struct NilRule : Rule {
  OVERRIDE(const Position& apply(const Position& to)) {
    return to;
  }
};
} // end namespace

Rule& Rule::nil() {
  static NilRule inst;
  return inst;
}
