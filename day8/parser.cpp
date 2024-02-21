#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<int> > parse_data(const std::string& filename)
{
    std::ifstream input_file(filename);
    std::vector<std::vector<int> > lines;
    std::string line;
    while (std::getline(input_file, line)) {
        std::vector<int> curr_vec;
        for (int i=0; i!=line.size(); ++i){
            curr_vec.push_back(std::stoi(line.substr(i, 1)));
        }
        lines.push_back(curr_vec);
    }
    input_file.close();
    return lines;
}
