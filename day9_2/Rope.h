#include "Coord.h"

class Rope {
public:
    Coord head_coords;
    Coord tail_coords;
    Rope(): head_coords(0, 0), tail_coords(0, 0) {}
    void move_head(const char& m);
    void follow_tail();
    void move_rope(const char m);
};