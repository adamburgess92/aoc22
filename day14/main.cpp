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
            new_points.push_back(new_point);
        }
    }
    for (int i=0; i!=new_points.size(); ++i){
        std::cout << new_points[i].X << "," << new_points[i].Y << std::endl;
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
    // Fill space: 
    std::vector<std::vector<Point>> d_points_filled;
    for (int i=0; i!=d_points.size(); ++i){
        d_points_filled.push_back(fill_space_vec(d_points[i]));
    }
    return 0;
}
