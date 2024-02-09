#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.h"

void replace_blanks(std::vector<std::string>& v)
{
    for (int i=0; i!=v.size(); ++i){
        if (v[i].empty()){
            v[i]="x";
        }
    }
}

std::vector<int> calories_by_elf(std::vector<std::string>& v)
{
    std::vector<int> v_out;
    int sum = 0;
    for (int i=0; i!=v.size(); ++i){
        if (v[i]=="x"){
            // Append sum to v_out
            v_out.push_back(sum);
            // reset cal_count
            sum = 0;
        } else {
            sum += std::stoi(v[i]);
        }
    }
    return v_out;
}

std::vector<int> get_top_three(std::vector<int>& v)
{
    std::vector<int> v_out(v.end()-3, v.end());
    return v_out;
}

int sum_top_three(std::vector<int>& v)
{
    int sum = 0;
    for (int i=0; i!=v.size(); ++i){
        sum += v[i];
    }
    return sum;
}

int main() 
{
    // Load data to vector
    // std::vector<std::string> v = input_to_vector("test_data.txt");
    std::vector<std::string> v = input_to_vector("data.txt");
    // Replace blanks with "x"
    replace_blanks(v);
    // Get a vector, calories by elf
    std::vector<int> cbe = calories_by_elf(v);
    // Sort vector of calories by elf:
    std::sort(cbe.begin(), cbe.end());
    // Get top three (last three values in vector)
    std::vector<int> top_three = get_top_three(cbe);
    // Sum top 3
    int res = sum_top_three(top_three);
    std::cout << res << std::endl;
    return 0;
}