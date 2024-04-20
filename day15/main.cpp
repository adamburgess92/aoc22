#include <iostream>
#include <sstream> 
#include <regex>
#include "Parser.h"


std::vector<int> find_ints(const std::string& s) 
{ 
    std::vector<int> ints;
    std::regex pattern(R"((-?\d+))");
    std::sregex_iterator it(s.begin(), s.end(), pattern);
    std::sregex_iterator end;

    while (it != end) {
        std::smatch match = *it;
        // std::cout << "Integer found: " << match.str(1) << std::endl;
        ints.push_back(std::stoi(match[1]));
        ++it;
    }
    // std::cout << std::endl;
    return ints;
}

std::vector<std::vector<int>> apply_find_ints(const std::vector<std::string>& v_in)
{
    std::vector<std::vector<int>> v_out;
    for (int i=0; i!=v_in.size(); ++i){
        std::vector<int> r = find_ints(v_in[i]);
        v_out.push_back(r);
    }
    return v_out;
}

std::vector<int> find_intersect(int s_x, int s_y, int b_x, int b_y, int line)
{
    int m_dist = abs(b_y-s_y) + abs(b_x-s_x);
    int y_dist = abs(line - s_y);
    int x_dist = abs(m_dist - y_dist);
    int x_a = s_x - x_dist;
    int x_b = s_x + x_dist;
    std::vector<int> v_out;
    v_out.push_back(x_a);
    v_out.push_back(x_b);
    return v_out;
}

std::vector<std::vector<int>> find_all_intersect(const std::vector<std::vector<int>>& v_in, int line)
{
    std::vector<std::vector<int>> v_out;
    for (int i=0; i!=v_in.size(); ++i){
        auto inter = find_intersect(v_in[i][0], v_in[i][1], v_in[i][2], v_in[i][3], line);
        // std::cout << inter[0] << std::endl;
        // std::cout << inter[1] << std::endl;
        v_out.push_back(inter);
    }
    return v_out;
}


int main () 
{
    std::vector<std::string> data = load_data("test_data.txt");
    auto v = apply_find_ints(data);

    // // idx 6 == (8,7) from the example
    // int s_x = v[6][0];
    // int s_y = v[6][1];
    // int b_x = v[6][2];
    // int b_y = v[6][3];
    // find_intersect(s_x, s_y, b_x, b_y, 10);
    auto intersections = find_all_intersect(v, 10); 
    
    return 0;
}





/* 
In row 2,000,000, how many positions cannot contain a beacon?
Don't draw the grid, it'll take forever...
This is probably a math problem 
Maybe start by finding boundaries? Even that is a lot...

From sensor S, if dist is d, what are the start/end coordinates at line L? <- this is probably the way



*/