#include "Coord.h"

class Rope {
public:
    Coord head_coords;
    Coord tail_coords;
    Rope();
    void move_head(const char& m);
    void follow_tail();
    void move_rope(const char m);
};