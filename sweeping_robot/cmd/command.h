#ifndef HC37C3D94_43F1_4677_BD56_34CB78EFEC75
#define HC37C3D94_43F1_4677_BD56_34CB78EFEC75

#include <vector>
#include <functional>

struct Rule;
struct Position;

using Command = std::function<Position(const Position&, Rule&)>;

Command left();
Command right();
Command round();

Command forward();
Command backward();

Command forward(int n);
Command backward(int n);

Command repeat(Command, int n);
Command sequential(std::vector<Command> cmds);

#endif
