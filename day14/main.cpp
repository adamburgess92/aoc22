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
}

int main() 
{
    // Load data
    std::vector<std::string> d = parse_data("test_data.txt");
    // Convert to vectors vector of Points
    for (int i=0; i!=d.size(); ++i){
        std::vector<Point> d_point = apply_split(d[i]);
    }
    // Now we have [[Point(1, 2), Point(3, 4)], [Point(5, 6), ...], ...]

    // Test point: 
    Point pa; 
    pa.X = 525;
    pa.Y = 117;
    Point pb; 
    pb.X = 525;
    pb.Y = 114;
    
    fill_space(pa, pb);


    

    return 0;
}
