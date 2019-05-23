#include "sweeping_robot/cmd/command.h"
#include "sweeping_robot/core/position.h"
#include "sweeping_robot/listener/listener.h"
#include "cub/algo/range.h"

namespace {
Command turn(bool left) {
  return [left](auto& from, auto& listener) {
    auto to = from.turn(left);
    listener.onChanged(to.getPoint());
    return to;
  };
}
}  // namespace

Command left() {
  return turn(true);
}

Command right() {
  return turn(false);
}

namespace {
Command move(bool forward) {
  return [forward](auto& from, auto& listener) {
    auto to = from.move(forward);
    listener.onChanged(to.getPoint());
    return to;
  };
}
}  // namespace

Command forward() {
  return move(true);
}

Command backward() {
  return move(false);
}

Command forward(int n) {
  return repeat(forward(), n);
}

Command backward(int n) {
  return repeat(backward(), n);
}

Command round() {
  return repeat(right(), 2);
}

namespace {
#define ASSERT_BETWEEN(num, min, max)       \
  do {                                      \
    if (num < min || num > max) return nop; \
  } while (0)

auto nop = [](const Position& from, Listener&) {
  return from;
};

constexpr auto MIN_REPEATED_NUM = 1;
constexpr auto MAX_REPEATED_NUM = 10;
}  // namespace

Command repeat(Command cmd, int n) {
  ASSERT_BETWEEN(n, MIN_REPEATED_NUM, MAX_REPEATED_NUM);
  return sequential(std::vector<Command>(n, cmd));
}

Command sequential(std::vector<Command> cmds) {
  return [cmds = std::move(cmds)](auto& from, auto& listener) {
    return cub::reduce(cmds, from, [&listener](auto& pos, auto& cmd) {
      pos = cmd(pos, listener);
    });
  };
}
