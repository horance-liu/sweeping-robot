#include "sweeping_robot/rule/rule.h"

namespace {
struct NilRule : Rule {
  OVERRIDE(const Position& apply(const Position& to) const) {
    return to;
  }
};
} // end namespace

const Rule& Rule::nil() {
  static NilRule inst;
  return inst;
}
