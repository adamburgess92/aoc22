#include "Parser.h"

std::vector<std::vector<char>> parse_data(const std::string& filename)
{
    std::ifstream inputFile(filename);
    std::string line;
    std::vector<char> lines;
    std::vector<std::vector<char>> v_out;

    while (std::getline(inputFile, line)){
        for (int i=0; i!=line.size(); ++i){
            lines.push_back(line[i]);
        }
        v_out.push_back(lines);
        lines.clear();
    }
    inputFile.close();
    return v_out;
}
