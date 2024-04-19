#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include <sstream>
#include <algorithm>

class Point {
public:
    int X;
    int Y;
    char T; // Type
};

class Sand {
public:
    int X;
    int Y;
    bool at_rest;
    bool reached_abyss;
    Sand() {X=500; Y=0; at_rest=false; reached_abyss=false;} // Default constructor places new unit of sand at 500,0
    void move(std::vector<std::vector<char>> landscape)
    {
        char below = landscape[Y+1][X];
        char left = landscape[Y+1][X-1];
        char right = landscape[Y+1][X+1];
        if (below=='.'){
            ++Y;
        } else if (left=='.'){
            ++Y;
            --X;
        } else if (right=='.'){
            ++Y;
            ++X;
        } else {
            at_rest = true;
        }
        if (Y == 699) {
            reached_abyss=true;
        }
    };

};

class Grid {
public:
    std::vector<std::vector<char>> landscape;
    void add_sand_to_landscape(int x, int y)
    {
        landscape[y][x] = 'o';
    }
    void print_landscape(int x_min, int x_max, int y_min, int y_max)
    {
        // Print the grid (optional)
        for (int y=y_min; y!=y_max; ++y) {
            for (int x=x_min; x!=x_max; ++x) {
                std::cout << landscape[y][x] << "";
            }
            std::cout << std::endl; // Terminate the line after each row
        }
    }
};

std::vector<std::string> split(std::string s, std::string delimiter)
{
    std::string token;
    std::vector<std::string> tokens;
    int pos_start = 0;
    int pos_end = delimiter.length();
    int delim_end = delimiter.length();

    while((pos_end = s.find(delimiter, pos_start)) != std::string::npos){
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_end;
        tokens.push_back(token);
    }
    tokens.push_back(s.substr(pos_start));
    return tokens;
}

std::vector<Point> apply_split(std::string s)
{
    // Output vector:
    std::vector<Point> points;
    std::string delimiter1 = " -> ";
    std::vector<std::string> s1 = split(s, delimiter1);
    std::string delimiter2 = ",";
    for (int i=0; i!=s1.size(); ++i){
        std::vector<std::string> s2 = split(s1[i], delimiter2);
        int x = std::stoi(s2[0]);
        int y = std::stoi(s2[1]);
        Point p;
        p.X = x;
        p.Y = y;
        p.T = '#';
        points.push_back(p);
    }
    return points;
}

std::vector<Point> fill_space(Point point_a, Point point_b)
{
    // Fill space between two points
    std::vector<Point> new_points;
    int min_x = std::min(point_a.X, point_b.X);
    int max_x = std::max(point_a.X, point_b.X);
    int min_y = std::min(point_a.Y, point_b.Y);
    int max_y = std::max(point_a.Y, point_b.Y);

    for (int i=min_x; i!=max_x+1; ++i){
        for (int j=min_y; j!=max_y+1; ++j){
            Point new_point;
            new_point.X = i;
            new_point.Y = j;
            new_point.T = '#';
            new_points.push_back(new_point);
        }
    }
    return new_points;
}

std::vector<Point> fill_space_vec(std::vector<Point>& v_points_in)
{
    // Apply fill_space to vector of points
    std::vector<Point> v_points_out;
    for (int i=1; i!=v_points_in.size(); ++i){
        Point point_a = v_points_in[i-1];
        Point point_b = v_points_in[i];
        std::vector<Point> new_points = fill_space(point_a, point_b);
        for (int j=0; j!=new_points.size(); ++j){
            v_points_out.push_back(new_points[j]);
        }
        new_points.clear();
    }
    return v_points_out;
}

std::vector<Point> flatten_vector(std::vector<std::vector<Point>>& v_in)
{
    std::vector<Point> flattened_vec;
    for (int i=0; i!=v_in.size(); ++i){
        std::vector<Point> sub_vec = v_in[i];
        for (int j=0; j!=sub_vec.size(); ++j){
            flattened_vec.push_back(sub_vec[j]);
        }
    }
    return flattened_vec;
}

std::vector<std::vector<char>> build_landscape(int x_min, int x_max, int y_min, int y_max, std::vector<Point>& rocks)
{
    std::vector<Point> all_points;
    for (int i=x_min; i!=x_max; ++i){
        for (int j=y_min; j!=y_max; ++j){
            Point current_point;
            current_point.X = i;
            current_point.Y = j;
            current_point.T = '.';
            // Check if this point appears in rocks:
            for (const Point& r : rocks){
                if (current_point.X==r.X && current_point.Y==r.Y){
                    current_point.T = '#';
                }
            }
            all_points.push_back(current_point);
        }
    }
    // Contruct the grid:
    std::vector<std::vector<char>> grid(y_max, std::vector<char>(x_max));
    // Populate the grid with the symbols from the points
    for (const Point& p : all_points) {
        grid[p.Y][p.X] = p.T;
    }
    return grid;
}

int main()
{
    // Load data
    std::vector<std::string> d = parse_data("test_data.txt");
    // Convert to vectors of vectors of Points
    std::vector<std::vector<Point>> d_points;
    for (int i=0; i!=d.size(); ++i){
        d_points.push_back(apply_split(d[i]));
    }
    // Now we have [[Point(1, 2), Point(3, 4)], [Point(5, 6), ...], ...]
    // Fill spaces:
    std::vector<std::vector<Point>> d_points_filled;
    for (int i=0; i!=d_points.size(); ++i){
        d_points_filled.push_back(fill_space_vec(d_points[i]));
    }
    // Now we have vectors of vectors of Points, representing the whole grid. Flatten it:
    std::vector<Point> rocks = flatten_vector(d_points_filled);
    // Build starting landscape
    // std::vector<std::vector<char>> landscape = build_landscape(494, 504, 0, 10, rocks);
    std::vector<std::vector<char>> landscape = build_landscape(0, 700, 0, 300, rocks);
    Grid g;
    g.landscape = landscape;

    int n_units = 0;
    for (int i=0; i!=2000; ++i){
        // Make new sand and drop it
        Sand s = Sand();
        ++n_units;
        while (!s.at_rest && !s.reached_abyss) {
            s.move(g.landscape);
        }
        std::cout << "Settled at " << s.X << ", " << s.Y <<  std::endl;
        // Update landscape:
        g.add_sand_to_landscape(s.X, s.Y);
        // g.print_landscape(493, 504, 0, 10);
        std::cout << "n units: " << n_units << std::endl;
    }

    return 0;
}

