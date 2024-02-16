#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "parser.h"

std::vector<std::string> split_string(std::string& s, char delimiter)
{
    std::stringstream ss(s);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

// std::unordered_map build_map(std::string& s)
std::unordered_map<std::string, int> build_map(std::string& s)
{
    // Split s on ',' delimiter
    std::vector<std::string> a = split_string(s, ',');
    std::string elf1 = a[0];
    std::string elf2 = a[1];
    // Split on '-' delimiter:
    std::vector<std::string> elf1_r = split_string(elf1, '-');
    std::vector<std::string> elf2_r = split_string(elf2, '-');

    std::string elf1_start = elf1_r[0];
    std::string elf1_end = elf1_r[1];
    std::string elf2_start = elf2_r[0];
    std::string elf2_end = elf2_r[1];

    std::cout << elf1_start << std::endl;
    std::cout << elf1_end << std::endl;
    std::cout << elf2_start << std::endl;
    std::cout << elf2_end << std::endl;

    std::unordered_map<std::string, int> sections;
    sections["elf1_start"] = std::stoi(elf1_start);
    sections["elf1_end"] = std::stoi(elf1_end);
    sections["elf2_start"] = std::stoi(elf2_start);
    sections["elf2_end"] = std::stoi(elf2_end);
    return sections;
}

//In how many assignment pairs does one range fully contain the other?
int main()
{
    std::vector<std::string> d = parse_data("test_data.txt");
    std::string s = d[0];
    build_map(s);
    // std::cout << res[1] << std::endl;


}

