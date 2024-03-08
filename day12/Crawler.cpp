#include "Crawler.h"

void Crawler::print_queue(std::queue<Point> q)
{
  while (!q.empty())
  {
    std::cout << q.front().row << ", " << q.front().col << " dist: " << q.front().dist << std::endl;
    q.pop();
  }
}


Crawler::Crawler(std::vector<std::vector<char>> input_grid): 
    grid(input_grid), 
    n_rows(input_grid.size()), 
    n_cols(input_grid[0].size())
{};


void Crawler::set_start_end_loc()
{
    for(int r=0; r!=grid.size(); ++r){
        for (int c=0; c!=grid[0].size(); ++c){
            char h = grid[r][c];
            if (h=='S'){
                Point s_point(r, c);
                s_point.add_dist(0);
                start_point = s_point;
                // Replace S with a
                grid[r][c] = 'a';
            }
            if (h=='E'){
                Point e_point(r, c);
                end_point = e_point;
                // Replace E with a z
                grid[r][c] = 'z';
            }
        }
    }
};

std::vector<Point> Crawler::get_valid_neighbours(Point p)
{
    // Create vector of optional new directions
    std::vector<Point> directions;
    Point point_up(p.row-1, p.col);
    Point point_down(p.row+1, p.col);
    Point point_left(p.row, p.col-1);
    Point point_right(p.row, p.col+1);
    // Record increasing distance from starting cell
    point_up.dist = p.dist+1;
    point_down.dist = p.dist+1;
    point_left.dist = p.dist+1;
    point_right.dist = p.dist+1;

    directions.push_back(point_up);
    directions.push_back(point_down);
    directions.push_back(point_left);
    directions.push_back(point_right);
    std::vector<Point> options;
    // Evaluate whether movement possible:
    for (int i=0; i!=directions.size(); ++i){
        // Check boundaries
        if (directions[i].row<0 || directions[i].row>n_rows-1 || directions[i].col<0 || directions[i].col > n_cols-1){
            continue;
        } else if (grid[directions[i].row][directions[i].col] <= grid[p.row][p.col]+1 && !is_already_in_queue(directions[i], visited)){
            options.push_back(directions[i]);
        }
    }
    return options;
}

bool Crawler::check_stop(Point p)
{
    if (p==end_point){
        stop_hit = true;
        return true;
    } 
    return false;
}

bool Crawler::is_already_in_queue(Point p, std::queue<Point> q)
{
    while (!q.empty()){
        if (q.front()==p){
            return true;
        }
        q.pop();
    }
    return false;
}

void Crawler::clear_queue(std::queue<Point>& q)
{
    while (!q.empty()){
        q.pop();
    }
}

int Crawler::traverse(Point start_point, Point end_point)
{
    // Reset things: 
    n_visited = 0;
    clear_queue(queue);
    clear_queue(visited);

    Point current_point = start_point;
    queue.push(current_point);
    while(!queue.empty()){
        // Mark current point as visited: 
        visited.push(current_point);
        // std::cout << "at point " << current_point.row << ", " << current_point.col << std::endl;
        if (check_stop(current_point)){
            return visited.back().dist;
        }
        std::vector<Point> move_options = get_valid_neighbours(current_point);
        for (int i=0; i!=move_options.size(); ++i){
            if (is_already_in_queue(move_options[i], queue)){
                continue;
            } else {
                queue.push(move_options[i]);
            }
        }
        move_options.clear();
        ++ n_visited;
        queue.pop();
        current_point = queue.front();
    }
}

void Crawler::find_a_points()
{
    for (int row=0; row!=grid.size(); ++row){
        for (int col=0; col!=grid[0].size(); ++col){
            if (grid[row][col]=='a'){
                a_points.push_back(Point(row, col));
            }
        }
    }
}

int Crawler::get_shortest_a_path()
{
    std::vector<int> distances;
    for (int i=0; i!=a_points.size(); ++i){
        distances.push_back(traverse(a_points[i], end_point));
    }
    int smallest = distances[0];
    for (int i=0; i!=distances.size(); ++i){
        if (distances[i]<smallest && distances[i]>0 && distances[i]<400){ // Bit dodgy but whatever.
            smallest = distances[i];
        }
    }
    return smallest;
}