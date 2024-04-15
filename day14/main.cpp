#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include <sstream>

class Point {
public: 
    Point() {};
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

void apply_split(std::string s)
{
    // Output vector: 
    std::vector<Point> points; 
    std::string delimiter1 = " -> ";
    std::vector<std::string> s1 = split(s, delimiter1);
    // Iterate through s1, split by comma and create Points
    std::string delimiter2 = ",";
    std::vector<std::string> h;
    int x; 
    int y; 
    for (int i=0; i!=s.size(); ++i){
        h = split(s1[i], delimiter2);
        x = std::stoi(h[0]);
        y = std::stoi(h[1]);
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        // Create Point: 
        Point p;
        p.X = x; 
        p.Y = y;
        points.push_back(p);
    }
}


int main() 
{
    std::vector<std::string> d = parse_data("test_data.txt");
    for (int i=0; i!=d.size(); ++i){
        std::cout << d[i] << '\n';
    }

    apply_split(d[0]);




    // // Iterate through lines of data, collecting lists of Points: 
    // std::string delim1 = " -> ";
    // std::vector<std::string> res = split(d[0], delim1);

    // for (int i=0; i!=res.size(); ++i){
    //     std::cout << res[i] << std::endl;
    // }
    return 0;
}
