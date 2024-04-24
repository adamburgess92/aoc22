#include <algorithm>
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

std::vector<std::vector<int>> find_intersections(const std::vector<std::vector<int>>& v_in, int line)
{
    // v_in is [[s_x, s_y, b_x, b_y],[s_x, s_y, b_x, b_y], ...]
    // line is the line at which to check for intersections
    std::vector<std::vector<int>> v_out;
    for (const std::vector<int>& row : v_in){
        int s_x = row[0];
        int s_y = row[1];
        int b_x = row[2];
        int b_y = row[3];
        int m_dist = abs(b_y-s_y) + abs(b_x-s_x); // This is correct
        int y_dist = abs(line - s_y); 
        if (y_dist > m_dist){
            std::cout << "Signal at " << s_x << ", " << s_y << " does not reach row " << line << std::endl;
            continue;
        }
        int x_dist = abs(y_dist-m_dist);
        int x_a = s_x - x_dist;
        int x_b = s_x + x_dist;
        std::cout << "Signal at " << s_x << ", " << s_y << " meets line at " << x_a << ", " << x_b << std::endl;
        std::vector<int> v_pair {x_a, x_b};
        v_out.push_back(v_pair);
    }
    return v_out;
}


int find_start(const std::vector<std::vector<int>>& v_intersections)
{
    int min_x = 0;
    for (int i=0; i<v_intersections.size(); ++i){
        int a = v_intersections[i][0];
        if (a<min_x){
            min_x = a;
        }
    }
    return min_x;
}

int find_stop(const std::vector<std::vector<int>>& v_intersections)
{
    int max_x = 0;
    for (int i=0; i<v_intersections.size(); ++i){
        int b = v_intersections[i][1];
        if (b>max_x){
            max_x = b;
        }
    }
    return max_x;
}

void no_possible_beacon(int start, int stop, std::vector<std::vector<int>> intersections)
{
    int n=0;
    for (int i=start; i<=stop; ++i){
        for (int j=0; j!=intersections.size(); ++j){
            int x_a = intersections[j][0];
            int x_b = intersections[j][1];
            bool in=false;
            if (i>=x_a && i<=x_b) {
                in = true;
                ++n;
                break;
            }
        }
    }
    std::cout << "res: " << n << std::endl;
    std::cout << "res-1: " << n-1 << std::endl; // Because row contains a beacon already
}

int main ()
{
    std::vector<std::string> data = load_data("data.txt");
    // std::cout << data[0] << std::endl;
    std::vector<std::vector<int>> v = apply_find_ints(data);
    std::vector<std::vector<int>> intersections = find_intersections(v, 2000000);
    int start = find_start(intersections);
    int stop = find_stop(intersections);
    no_possible_beacon(start, stop, intersections);
    return 0;
}

// 6582242 is not the answer
// 6582243 is not the answer - too high
// 6345457-1 is not the answer - too high
// Weirdly - when x_max increases by 1, result is increasing by one. 
// This is not happening when x_min is decreased



/*
Just need to remove Beacons in row 10
*/