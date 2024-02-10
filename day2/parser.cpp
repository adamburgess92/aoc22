#include <iostream>
#include <vector>
#include <fstream>
#include "hand.h"

std::vector<Hand> parse_data(const std::string& filename)
{
    std::ifstream input_file(filename);
    std::vector<Hand> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        // std::cout << line << std::endl;
        // split line:
        char opp = line.front();
        char you = line.back();

        // std::cout << you << std::endl;

        Hand h(opp, you);
        lines.push_back(h);
    }
    input_file.close();
    return lines;
}
