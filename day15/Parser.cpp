#include "Parser.h"

std::vector<std::string> load_data(const std::string& filename)
{
    std::ifstream inputFile(filename);
    std::string line;
    std::vector<std::string> v_out;
    while (std::getline(inputFile, line)){
        v_out.push_back(line);
    }
    inputFile.close();
    return v_out;
}