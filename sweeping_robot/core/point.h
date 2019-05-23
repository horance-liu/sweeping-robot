#ifndef H65A54D80_942C_4AB0_846B_A0568EA5200D
#define H65A54D80_942C_4AB0_846B_A0568EA5200D

#include "cub/base/comparator.h"
#include <stddef.h>
#include <functional>
#include <string>

struct Point {
  Point(int x, int y);

  size_t hash() const noexcept;
  std::string str() const;

  int getX() const;
  int getY() const;

  Point move(int xoffset, int yoffset) const;

  DECL_EQUALS(Point);

private:
  int x, y;
};

#include <ostream>

std::ostream& operator<<(std::ostream& out, const Point& p) {
  return out << p.str();
}

namespace std {
template<>
struct hash<Point> {
  size_t operator()(const Point& p) const noexcept {
    return p.hash();
  }
};
} // end namespace std

#endif
