#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include <sstream>

class Point {
public: 
    // Point() {};
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


int main() 
{
    std::vector<std::string> d = parse_data("test_data.txt");
    for (int i=0; i!=d.size(); ++i){
        std::cout << d[i] << '\n';
    }

    // Iterate through lines of data, collecting lists of Points: 
    std::string delim1 = " -> ";
    std::vector<std::string> res = split(d[0], delim1);

    for (int i=0; i!=res.size(); ++i){
        std::cout << res[i] << std::endl;
    }
    return 0;
}
