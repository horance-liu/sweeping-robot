#include "sweeping_robot/sweeping_robot.h"
#include "cut/cut.hpp"

using namespace cum;

FIXTURE(SweepingRobotTest) {
  SweepingRobot robot;

  TEST("at beginning, the robot is at (0, 0, N)") {
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }

  TEST("left: (0, 0, N) -> (0, 0, W)") {
    robot.exec(left());
    ASSERT_EQ(Position(0, 0, Direction::W), robot.position());
  }

  TEST("left(2 times): (0, 0, N) -> (0, 0, S)") {
    robot.exec(left());
    robot.exec(left());
    ASSERT_EQ(Position(0, 0, Direction::S), robot.position());
  }

  TEST("left(3 times): (0, 0, N) -> (0, 0, E)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    ASSERT_EQ(Position(0, 0, Direction::E), robot.position());
  }

  TEST("left(4 times): (0, 0, N) -> (0, 0, N)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }

  TEST("right: (0, 0, N) -> (0, 0, E)") {
    robot.exec(right());
    ASSERT_EQ(Position(0, 0, Direction::E), robot.position());
  }

  TEST("right(2 times): (0, 0, N) -> (0, 0, S)") {
    robot.exec(right());
    robot.exec(right());
    ASSERT_EQ(Position(0, 0, Direction::S), robot.position());
  }

  TEST("right(3 times): (0, 0, N) -> (0, 0, W)") {
    robot.exec(right());
    robot.exec(right());
    robot.exec(right());
    ASSERT_EQ(Position(0, 0, Direction::W), robot.position());
  }

  TEST("right(4 times): (0, 0, N) -> (0, 0, N)") {
    robot.exec(right());
    robot.exec(right());
    robot.exec(right());
    robot.exec(right());
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }

  TEST("forward: (0, 0, N) -> (0, 1, N)") {
    robot.exec(forward());
    ASSERT_EQ(Position(0, 1, Direction::N), robot.position());
  }

  TEST("left, forward: (0, 0, N) -> (-1, 0, W)") {
    robot.exec(left());
    robot.exec(forward());
    ASSERT_EQ(Position(-1, 0, Direction::W), robot.position());
  }

  TEST("left(2 times), forward: (0, 0, N) -> (0, -1, S)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(forward());
    ASSERT_EQ(Position(0, -1, Direction::S), robot.position());
  }

  TEST("left(3 times), forward: (0, 0, N) -> (1, 0, E)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(forward());
    ASSERT_EQ(Position(1, 0, Direction::E), robot.position());
  }

  TEST("left(4 times), forward: (0, 0, N) -> (0, 1, N)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(forward());
    ASSERT_EQ(Position(0, 1, Direction::N), robot.position());
  }

  TEST("backward: (0, 0, N) -> (0, -1, N)") {
    robot.exec(backward());
    ASSERT_EQ(Position(0, -1, Direction::N), robot.position());
  }

  TEST("left, backward: (0, 0, N) -> (1, 0, W)") {
    robot.exec(left());
    robot.exec(backward());
    ASSERT_EQ(Position(1, 0, Direction::W), robot.position());
  }

  TEST("left(2 times), backward: (0, 0, N) -> (0, 1, S)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(backward());
    ASSERT_EQ(Position(0, 1, Direction::S), robot.position());
  }

  TEST("left(3 times), backward: (0, 0, N) -> (-1, 0, E)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(backward());
    ASSERT_EQ(Position(-1, 0, Direction::E), robot.position());
  }

  TEST("left(3 times), backward: (0, 0, N) -> (0, -1, N)") {
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(left());
    robot.exec(backward());
    ASSERT_EQ(Position(0, -1, Direction::N), robot.position());
  }

  TEST("round: (0, 0, N) -> (0, 0, S)") {
    robot.exec(round());
    ASSERT_EQ(Position(0, 0, Direction::S), robot.position());
  }

  TEST("forward(10): (0, 0, N) -> (0, 10, N)") {
    robot.exec(forward(10));
    ASSERT_EQ(Position(0, 10, Direction::N), robot.position());
  }

  TEST("forward(11): out of bound") {
    robot.exec(forward(11));
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }

  TEST("backward(10): (0, 0, N) -> (0, -10, N)") {
    robot.exec(backward(10));
    ASSERT_EQ(Position(0, -10, Direction::N), robot.position());
  }

  TEST("backward(11): out of bound") {
    robot.exec(backward(11));
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }

  TEST("sequential(left, forward, round): (0, 0, N) -> (-1, 0, E)") {
    robot.exec(sequential({left(), forward(), round()}));
    ASSERT_EQ(Position(-1, 0, Direction::E), robot.position());
  }

  TEST("repeat(forward(2), 2): (0, 0, N) -> (0, 4, N)") {
    robot.exec(repeat(forward(2), 2));
    ASSERT_EQ(Position(0, 4, Direction::N), robot.position());
  }

  TEST("repeat(left(), 11): out of bound") {
    robot.exec(repeat(left(), 11));
    ASSERT_EQ(Position(0, 0, Direction::N), robot.position());
  }
};
