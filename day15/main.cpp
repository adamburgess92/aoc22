#include <iostream>
#include <sstream> 
#include <regex>
#include "Parser.h"

class Sensor {
    int X; 
    int Y; 
};

class Beacon {
    int X;
    int Y; 
};

std::vector<int> foo(const std::string& s) 
{ 
    std::vector<int> ints;
    std::regex pattern(R"((-?\d+))");
    std::sregex_iterator it(s.begin(), s.end(), pattern);
    std::sregex_iterator end;

    while (it != end) {
        std::smatch match = *it;
        std::cout << "Integer found: " << match.str(1) << std::endl;
        ints.push_back(std::stoi(match[1]));
        ++it;
    }
    std::cout << std::endl;
    return ints;
}

std::vector<std::vector<int>> apply_foo(const std::vector<std::string>& v_in)
{
    std::vector<std::vector<int>> v_out;
    for (int i=0; i!=v_in.size(); ++i){
        std::vector<int> r = foo(v_in[i]);
        v_out.push_back(r);
    }
    return v_out;
}

int main () 
{
    std::vector<std::string> data = load_data("test_data.txt");
    auto v = apply_foo(data);

    // idx 6 == (8,7) from the example
    int s_x = v[6][0];
    int s_y = v[6][1];
    int b_x = v[6][2];
    int b_y = v[6][3];

    int dist = abs(b_y-s_y) + abs(b_x-s_x);
    std::cout << dist << std::endl;
    

    return 0;
}





/* 
In row 2,000,000, how many positions cannot contain a beacon?
Don't draw the grid, it'll take forever...
This is probably a math problem 
Maybe start by finding boundaries? Even that is a lot...

From sensor S, if dist is d, what are the start/end coordinates at line L? <- this is probably the way

*/