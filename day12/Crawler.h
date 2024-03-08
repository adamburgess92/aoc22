#include <queue>
#include <vector>
#include "Point.h"

class Crawler{
public: 
    Crawler(std::vector<std::vector<char>> input_grid);
    std::vector<std::vector<char>> grid;
    int n_rows;
    int n_cols;
    int n_visited = 0;
    Point start_point;
    Point end_point;
    std::queue<Point> visited;
    std::queue<Point> queue;
    bool stop_hit = false;
    bool check_stop(Point p);
    void set_start_end_loc();
    std::vector<Point> get_valid_neighbours(Point p);
    void traverse();
    void print_queue(std::queue<Point> q);
    bool is_already_in_queue(Point p, std::queue<Point> q);


};