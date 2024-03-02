#include "Parser.h"

std::vector<std::vector<std::string>> parse_data(const std::string&filename)
{
    std::ifstream inputFile(filename);
    std::vector<std::vector<std::string>> v_out;
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(inputFile, line)){
        if (line.empty()){
            v_out.push_back(lines);
            lines.clear();
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();
    return v_out;
}