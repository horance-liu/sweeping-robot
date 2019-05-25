#ifndef H2FD131AD_760E_43F5_B7F3_20DA59F6B30B
#define H2FD131AD_760E_43F5_B7F3_20DA59F6B30B

#include <functional>
#include <ostream>

struct Point;
struct ActionDescribing;

using Output = std::function<void(const Point&, const ActionDescribing&)>;

Output to_text(std::ostream& os);
Output to_json(std::ostream& os);

#endif
