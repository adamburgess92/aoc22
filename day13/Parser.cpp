#include "Parser.h"

   std::vector<std::vector<std::string>> parse_data(const std::string& filename)
{
    std::ifstream inputFile(filename);
    std::string line;
    std::vector<std::string> pair_lines;
    std::vector<std::vector<std::string>> v_out;
    int l_count = 1;
    while(std::getline(inputFile, line)){
        if (l_count%3==0){
            v_out.push_back(pair_lines);
            pair_lines.clear();
        } else {
            pair_lines.push_back(line);
        }
        ++l_count;
    }
    inputFile.close();
    return v_out;
}