#include <queue>
#include <vector>
#include "Point.h"

class Crawler{
public: 
    Crawler(std::vector<std::vector<char>> input_grid);
    std::vector<std::vector<char>> grid;
    int n_rows;
    int n_cols;
    int n_visited;
    Point start_point;
    Point end_point;
    std::queue<Point> visited;
    std::queue<Point> queue;
    bool check_stop(Point p);
    void set_start_end_loc();
    std::vector<Point> get_valid_neighbours(Point p);
    void traverse();

};