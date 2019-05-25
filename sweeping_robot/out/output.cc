#include "sweeping_robot/out/output.h"
#include "sweeping_robot/core/point.h"
#include "sweeping_robot/listener/action_describing.h"
#include "cub/string/str_printf.h"

Output to_text(std::ostream& os) {
  return [&os](auto& to, auto& action) {
    os << action.text(to);
  };
}

Output to_json(std::ostream& os) {
  return [&os](auto& to, auto& action) {
    os << cub::stringprintf(
R"({
    "action": "%s",
    "position": {
        "x": %d,
        "y": %d
    }
})", action.desc(), to.getX(), to.getY());
  };
}
