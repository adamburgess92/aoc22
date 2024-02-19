#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> parse_data(const std::string& filename)
{
    std::ifstream input_file(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }
    input_file.close();
    return lines;
}
