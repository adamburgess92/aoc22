#include <iostream>
#include "Crawler.h"

Crawler::Crawler(std::vector<std::vector<char>> input_grid)
    : grid(input_grid), n_rows(input_grid.size()+1), n_cols(input_grid[0].size()+1) {};


void Crawler::set_start_end_loc()
{
    for(int r=0; r!=grid.size(); ++r){
        for (int c=0; c!=grid[0].size(); ++c){
            char h = grid[r][c];
            if (h=='S'){
                Point s_point(r, c);
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
    std::vector<Point> directions;
    Point point_up(p.row-1, p.col);
    Point point_down(p.row+1, p.col);
    Point point_left(p.row, p.col-1);
    Point point_right(p.row, p.col+1);
    directions.push_back(point_up);
    directions.push_back(point_down);
    directions.push_back(point_left);
    directions.push_back(point_right);
    std::vector<Point> options;
    // Evaluate whether movement possible:
    for (int i=0; i!=directions.size(); ++i){
        // Check boundaries
        if (directions[i].row<0 || directions[i].row > n_rows || directions[i].col<0 || directions[i].col > n_rows){
            continue;
        } else if (grid[directions[i].row][directions[i].col] <= grid[p.row][p.col]+1){
                options.push_back(directions[i]);
        }
    }
    return options;
}

bool Crawler::check_stop(Point p)
{
    if (p==end_point){
        return true;
    } 
    return false;
}

void Crawler::traverse()
{
    Point current_point = start_point;

    queue.push(start_point);
    current_point = start_point;
    while(!queue.empty()){
        std::cout << "Now at point " << current_point.row << ", " << current_point.col << std::endl;
        if (check_stop(current_point)){
            std::cout << "Reached E after " << n_visited << " steps" << std::endl;
        }
        visited.push(current_point);
        std::vector<Point> move_options = get_valid_neighbours(current_point);
        for (int i=0; i!=move_options.size(); ++i){
            queue.push(move_options[i]);
        }
        move_options.clear();
        ++ n_visited;
        current_point = queue.front();
    }
}



