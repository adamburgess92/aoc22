#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> parse_data(const std::string& filename)
{
    std::ifstream input_file(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        // std::vector<std::string> curr_vec;
        for (int i=0; i!=line.size(); ++i){
            lines.push_back(line);
        }
    }
    input_file.close();
    return lines;
}
