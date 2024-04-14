#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"
#include <sstream>

class Point {
public: 
    int X;
    int Y;
};

std::vector<std::string> split(std::string s, std::string delimiter) {
    int pos_start = 0;
    int pos_end = delimiter.length();
    int delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    for (int i=0; i!=res.size(); ++i){
        std::cout << res[i] << std::endl;
    }
    return res;
}


int main() 
{
    std::vector<std::string> d = parse_data("test_data.txt");
    for (int i=0; i!=d.size(); ++i){
        std::cout << d[i] << '\n';
    }

    // Iterate through lines of data, collecting lists of Points: 
    std::string delim = " -> ";
    // std::vector<Point> ls_pnt = create_ls_pnt(d, delim);
    split(d[0], delim);


    



    return 0;
}
