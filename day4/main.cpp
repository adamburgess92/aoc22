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

    std::unordered_map<std::string, int> sections;
    sections["elf1_start"] = std::stoi(elf1_start);
    sections["elf1_end"] = std::stoi(elf1_end);
    sections["elf2_start"] = std::stoi(elf2_start);
    sections["elf2_end"] = std::stoi(elf2_end);
    return sections;
}

std::vector<std::unordered_map<std::string, int>> convert_data_to_maps(std::vector<std::string>& v)
{
    std::vector<std::unordered_map<std::string, int>> v_out;
    for (int i=0; i!=v.size(); ++i){
        v_out.push_back(build_map(v[i]));
    }
    return v_out;
}

int check_duplicated(std::unordered_map<std::string, int>& m)
{
    int score = 0;
    // Check if elf 1's work is a subset of elf 2's work
    if ((m["elf1_start"]>=m["elf2_start"]) && (m["elf1_end"]<=m["elf2_end"])){
        score += 1;
    }
    if ((m["elf2_start"]>=m["elf1_start"]) && (m["elf2_end"]<=m["elf1_end"])){
        score += 1;
    }
    return score;
}

int sum_all_duplicated(std::vector<std::unordered_map<std::string, int>>& d)
{
    int score = 0;
    for (int i=0; i!=d.size(); ++i){
        if (check_duplicated(d[i])==1){
            score+=1;
        }
    }
    return score;
}

//In how many assignment pairs does one range fully contain the other?
int main()
{
    std::vector<std::string> d = parse_data("test_data.txt");
    std::vector<std::unordered_map<std::string, int>> m = convert_data_to_maps(d);
    int res = sum_all_duplicated(m);
    std::cout << res << std::endl;

}

