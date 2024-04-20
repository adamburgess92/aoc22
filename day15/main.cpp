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
    // for (int i=0; i!=data.size(); ++i){
    //     std::cout << data[i] << std::endl;
    // }
    apply_foo(data);

    return 0;
}
