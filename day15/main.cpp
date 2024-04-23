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
    // Find points x_a and x_b where signal instersects with line
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
    // Generate [[x_a, x_b], [x_a, x_b], ...] for all signals
    std::vector<std::vector<int>> v_out;
    for (int i=0; i!=v_in.size(); ++i){
        auto inter = find_intersect(v_in[i][0], v_in[i][1], v_in[i][2], v_in[i][3], line);
        // std::cout << inter[0] << std::endl;
        // std::cout << inter[1] << std::endl;
        // std::cout << std::endl;
        v_out.push_back(inter);
    }
    return v_out;
}

int find_min_x(const std::vector<std::vector<int>>& v_in)
{
    int min=0;
    for (int i=0; i!=v_in.size(); ++i){
        int s_x = v_in[i][0];
        int s_y = v_in[i][1];
        int b_x = v_in[i][2];
        int b_y = v_in[i][3];
        int m_dist = abs(b_y-s_y) + abs(b_x-s_x);
        int x_min = s_x - m_dist;
        if (x_min < min){
            min = x_min;
        }
    }
    return min;
}

int find_max_x(const std::vector<std::vector<int>>& v_in)
{
    int max=0;
    for (int i=0; i!=v_in.size(); ++i){
        int s_x = v_in[i][0];
        int s_y = v_in[i][1];
        int b_x = v_in[i][2];
        int b_y = v_in[i][3];
        int m_dist = abs(b_y-s_y) + abs(b_x-s_x);
        int x_max = s_x + m_dist;
        if (x_max > max){
            max = x_max;
        }
    }
    return max;
}

void no_possible_beacon(int start, int stop, std::vector<std::vector<int>> intersections)
{
    int n=0;
    for (int i=start; i<stop+12; ++i){
        for (int j=0; j!=intersections.size(); ++j){
            int x_a = intersections[j][0];
            int x_b = intersections[j][1];
            bool in=false;
            if (i>=x_a && i<=x_b) {
                in = true;
                ++n;
                if (in && i>stop){
                    std::cout << "i: " << i << std::endl;
                    std::cout << "x_a: " << x_a << std::endl;
                    std::cout << "x_b: " << x_b << std::endl;
                    std::cout << "in: " << in << std::endl;
                    std::cout << "n: " << n << std::endl;
                    std::cout << std::endl;
                }
                break;
            }
        }
    }
    std::cout << "res: " << n << std::endl;
}

int main ()
{
    std::vector<std::string> data = load_data("data.txt");
    // std::cout << data[0] << std::endl;
    std::vector<std::vector<int>> v = apply_find_ints(data);
    auto intersections = find_all_intersect(v, 2000000);
    // auto intersections = find_all_intersect(v, 10);

    int x_min = find_min_x(v);
    int x_max = find_max_x(v);
    std::cout << "x_min: " << x_min << std::endl;
    std::cout << "x_max: " << x_max << std::endl;
    no_possible_beacon(x_min, x_max, intersections);

    // Test things:
    return 0;
}

// 6345457-1 is not the answer
// Weirdly - when x_max increases by 1, result is increasing by one. 
// This is not happening when x_min is decreased



/*
Just need to remove Beacons in row 10
*/