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
        int m_dist = abs(b_y-s_y) + abs(b_x-s_x);
        int y_dist = abs(line - s_y); 
        if (y_dist > m_dist){
            // std::cout << "Signal at " << s_x << ", " << s_y << " does not reach row " << line << std::endl;
            continue;
        }
        int x_dist = abs(y_dist-m_dist);
        int x_a = s_x - x_dist;
        int x_b = s_x + x_dist;
        // std::cout << "Signal at " << s_x << ", " << s_y << " meets line at " << x_a << ", " << x_b << std::endl;
        std::vector<int> v_pair {x_a, x_b};
        v_out.push_back(v_pair);
    }
    return v_out;
}

int find_start(const std::vector<std::vector<int>>& v_intersections)
{
    int min_x = 0; // Bad practice, but we can see from the data that min_x < 0
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

int num_possible_beacon(int start, int stop, std::vector<std::vector<int>> signals_beacons, std::vector<std::vector<int>> intersections, int line)
{
    // Create vector of existing non-distress beacons/sensors on line: 
    std::vector<int> existing_signal_beacon;
    for (const auto& row : signals_beacons)
    {
        if (row[1]==line) { // If Y coord of sensor==line
            existing_signal_beacon.push_back(row[0]); // Add X coord to vector
        }
        if (row[3]==line) { // If Y coord of beacon==line
            existing_signal_beacon.push_back(row[2]); // Add X coord to vector
        }
    }
    int n=0;
    for (int i=start; i<=stop; ++i){
        // Check that there is no non distress beacon at this point: 
        bool non_distress_beacon = false;
        for (const int& x : existing_signal_beacon){
            if (i==x){
                non_distress_beacon = true;
                break;
            }
        }
        if (non_distress_beacon){ // Can't be a possible distress beacon location, so move on.
            ++n;
            continue; 
        }
        // Otherwise, check that i is between intersection points:
        for (const std::vector<int>& row : intersections){
            int x_a = row[0];
            int x_b = row[1];
            if (i>=x_a && i<=x_b) {
                ++n;
                break;
            }
        }
    }
    return n;
}

bool sort_by_first(const std::vector<int>& a,  const std::vector<int>& b){
    return a[0] < b[0];
};

void part2(int start, int stop, const std::vector<std::vector<int>>& signals_beacons)
{
    // Iterate through row:
    for (int y=start; y<=stop; ++y){ // Row
        // Find and sort intersections with this row: 
        auto intersections = find_intersections(signals_beacons, y);
        std::sort(intersections.begin(), intersections.end(), sort_by_first);
        // Iterate over cols, skipping ahead where possible
        int x = start;
        while (x<=stop){
            bool s = false;
            for (std::vector<int>& ix : intersections){
                int x_a = ix[0];
                int x_b = ix[1];
                if (x>=x_a && x<=x_b){
                    s = true;
                    x = x_b+1;
                    break;
                }
            }
            if (!s) {
                std::cout << "x: " << x << ", y: " << y << std::endl;
                return;
            }
        }
        if (y%1000==0){
            std::cout << y << "/4000000" << std::endl;
        }
    }
}

int main ()
{
    std::vector<std::string> data = load_data("data.txt");
    // int line = 2000000;
    int line = 10;
    std::vector<std::vector<int>> signals_beacons = apply_find_ints(data);
    std::vector<std::vector<int>> intersections = find_intersections(signals_beacons, line);
    int start = find_start(intersections);
    int stop = find_stop(intersections);
    // Part 1:
    int res = num_possible_beacon(start, stop, signals_beacons, intersections, line);
    std::cout << res << std::endl;
    part2(0, 4000000, signals_beacons);
    return 0;
}
