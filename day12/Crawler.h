#include <iostream>
#include <algorithm>
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
    std::queue<Point> queue;
    std::queue<Point> visited;
    bool stop_hit = false;
    bool check_stop(Point p);
    void set_start_end_loc();
    std::vector<Point> get_valid_neighbours(Point p);
    int traverse(Point start_point, Point end_point);
    void clear_queue();
    void print_queue(std::queue<Point> q);
    bool is_already_in_queue(Point p, std::queue<Point> q);
    // For part 2:
    std::vector<Point> a_points;
    void find_a_points();
    int get_shortest_a_path();
    void clear_queue(std::queue<Point>& q);
};