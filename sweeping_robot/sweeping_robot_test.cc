#include "sweeping_robot/sweeping_robot.h"
#include "cut/cut.hpp"

using namespace cum;

FIXTURE(NoActionTest) {
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

#include "sweeping_robot/rule/default_rule.h"
#include "sweeping_robot/listener/staying_listener.h"
#include "sweeping_robot/out/text_output.h"

using namespace std::string_literals;

FIXTURE(TextAlertTest) {
  std::stringstream ss;

  DefaultRule rule{{
    new StayingListener(5, new TextOutput(ss)),
    //new PathListener({{0, 1}, {0, 2}}, new JsonOutput(ss))
  }};

  SweepingRobot robot{rule};

  TEST("robot turns left 5 times, then reports alert") {
    robot.exec(repeat(left(), 5));
    ASSERT_THAT(ss.str(), eq("Alert for passing (0, 0) repeatly\n"s));
  }

  TEST("robot alert only once") {
    robot.exec(repeat(left(), 6));
    ASSERT_THAT(ss.str(), eq("Alert for passing (0, 0) repeatly\n"s));
  }

  TEST("report one alert per one overflow") {
    std::string expected =
        "Alert for passing (0, 0) repeatly\n"
        "Alert for passing (0, 0) repeatly\n";

    robot.exec(repeat(left(), 10));
    ASSERT_THAT(ss.str(), eq(expected));
  }
};

#include "sweeping_robot/out/json_output.h"

FIXTURE(JsonAlertTest) {
  std::stringstream ss;

  DefaultRule rule{{
    new StayingListener(5, new JsonOutput(ss)),
  }};

  SweepingRobot robot{rule};

  TEST("robot turns left 5 times, then reports alert") {
    std::string expected =
R"({
    "action": "alert",
    "position": {
        "x": 0,
        "y": 0
    }
})";

    robot.exec(repeat(left(), 5));
    ASSERT_THAT(ss.str(), eq(expected));
  }
};

#include "sweeping_robot/listener/path_listener.h"
#include "sweeping_robot/out/text_output.h"

FIXTURE(TextCleanTest) {
  std::stringstream ss;

  DefaultRule rule{{
    new PathListener({{0, 1}, {0, 3}}, new TextOutput(ss))
  }};

  SweepingRobot robot{rule};

  TEST("robot pass points set, then execute clean action") {
    robot.exec(forward());
    ASSERT_THAT(ss.str(), eq("Execute cleaning at (0, 1)\n"s));
  }

  TEST("robot pass points set, then execute clean action") {
    std::string expected =
        "Execute cleaning at (0, 1)\n"
        "Execute cleaning at (0, 3)\n";

    robot.exec(forward(3));
    ASSERT_THAT(ss.str(), eq(expected));
  }

  TEST("robot clean point only once") {
    robot.exec(sequential({forward(), backward()}));
    ASSERT_THAT(ss.str(), eq("Execute cleaning at (0, 1)\n"s));
  }
};

FIXTURE(MultiActionTest) {
  std::stringstream s1;
  std::stringstream s2;

  DefaultRule rule{{
    new StayingListener(5, new JsonOutput(s1)),
    new PathListener({{-1, 0}, {0, 3}}, new TextOutput(s2))
  }};

  SweepingRobot robot{rule};

  TEST("robot pass points set, then execute clean action") {
    robot.exec(sequential({repeat(left(), 5), forward()}));

    std::string s1Expected =
R"({
    "action": "alert",
    "position": {
        "x": 0,
        "y": 0
    }
})";

    ASSERT_THAT(s1.str(), eq(s1Expected));
    ASSERT_THAT(s2.str(), eq("Execute cleaning at (-1, 0)\n"s));
  }
};

