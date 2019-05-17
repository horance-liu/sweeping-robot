#include "sweeping_robot/command.h"
#include "sweeping_robot/position.h"
#include "cub/algo/range.h"

namespace {
#define ASSERT_BETWEEN(num, min, max) \
  do {                                \
    if (num < min || num > max)       \
      return nop;          \
  } while (0)

auto nop = [](const Position& from) {
  return from;
};
}  // namespace

Command left() {
  return [](auto& from) {
    return from.turn(true);
  };
}

Command right() {
  return [](auto& from) {
    return from.turn(false);
  };
}

namespace {
constexpr auto MIN_MOVE_NUM = 1;
constexpr auto MAX_MOVE_NUM = 10;

Command move(int sign, int n) {
  ASSERT_BETWEEN(n, MIN_MOVE_NUM, MAX_MOVE_NUM);
  return [sign, n](auto& from) {
    return from.move(sign * n);
  };
}
}  // namespace

Command forward(int n) {
  return move(1, n);
}

Command backward(int n) {
  return move(-1, n);
}

Command round() {
  return repeat(right(), 2);
}

constexpr auto MIN_REPEATED_NUM = 1;
constexpr auto MAX_REPEATED_NUM = 10;

Command repeat(Command cmd, int n) {
  ASSERT_BETWEEN(n, MIN_REPEATED_NUM, MAX_REPEATED_NUM);
  return sequential(std::vector<Command>(n, cmd));
}

Command sequential(std::vector<Command>&& cmds) {
  return [cmds = std::move(cmds)](auto& from) {
    return cub::reduce(cmds, from, [](auto& pos, auto& cmd) {
      pos = cmd(pos);
    });
  };
}
