#ifndef HC37C3D94_43F1_4677_BD56_34CB78EFEC75
#define HC37C3D94_43F1_4677_BD56_34CB78EFEC75

#include <vector>
#include <functional>

struct Position;

using Command = std::function<Position(const Position&)>;

Command left();
Command right();

Command forward(int n = 1);
Command backward(int n = 1);
Command round();

Command repeat(Command, int n);
Command sequential(std::vector<Command> cmds);

#endif
