#include "Parser.h"

std::vector<std::string> parse_data(const std::string&filename)
{
    std::ifstream inputFile(filename);
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(inputFile, line)){
        lines.push_back(line);
    }
    inputFile.close();
    return lines;
}