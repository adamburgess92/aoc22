#include <vector>
#include <iostream>
#include "parser.h"

std::vector<std::vector<std::string>> split_compartments(std::vector<std::string>& v)
{
    std::vector<std::vector<std::string>> v_out;
    
    for (int i=0; i!=v.size(); ++i){
        int l = v[i].size();
        std::string first_compartment = v[i].substr(0, l/2);
        std::string second_compartment = v[i].substr(l/2, l);
        std::vector<std::string> split_compartments = {first_compartment, second_compartment};
        v_out.push_back(split_compartments);
    }
    return v_out;
}

std::vector<char> get_common_item(std::vector<std::vector<std::string>>& v) 
{
    std::vector<char> v_out;
    // Length of each 'subvector'
    for (int i=0; i!=v.size(); ++i){
        for (int j=0; j!=v[i].size(); ++j){
            for(int k=0; k!=v[i][j].size(); ++k){
                if (v[i][0][j]==v[i][1][k]){
                    v_out.push_back(v[i][0][j]);
                }
            }
        }
    }
    return v_out;
}

// int get_priority(const char& c)
// int sum_priorties


int main() {

    // for (int i=0; i!=d.size(); ++i){
    //     std::cout << d[i] << std::endl;
    //     std::cout << d[i].size() << std::endl;
    // }


    // Scratch: 
    std::vector<std::string> d = parse_data("test_data.txt");
    std::vector<std::vector<std::string>> split = split_compartments(d);
    std::vector<char> common = get_common_item(split);

    for (int i=0; i!=common.size(); ++i){
        std::cout << common[i] << std::endl;
    }

}