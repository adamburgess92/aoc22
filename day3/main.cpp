#include <vector>
#include <iostream>
#include <unordered_map>
#include "parser.h"

std::vector<std::vector<std::string> > split_compartments(std::vector<std::string>& v)
{
    std::vector<std::vector<std::string> > v_out;
    
    for (int i=0; i!=v.size(); ++i){
        int l = v[i].size();
        std::string first_compartment = v[i].substr(0, l/2);
        std::string second_compartment = v[i].substr(l/2, l);
        std::vector<std::string> split_compartments = {first_compartment, second_compartment};
        v_out.push_back(split_compartments);
    }
    return v_out;
}

std::vector<char> get_common_item(std::vector<std::vector<std::string> >& v) 
{
    std::vector<char> v_out;
    // Loop through: 
    for (int i=0; i!=v.size(); ++i){
        std::string comp1 = v[i][0]; // Compartment 1
        std::string comp2 = v[i][1]; // Compartment 2
        // std::cout << comp1 << " " << comp2 << std::endl;

        for (int j=0; j!=comp1.size(); ++j){
            bool match = false;
            for (int k=0; k!=comp2.size(); ++k){
                if (comp1[j] == comp2[k]) {
                    v_out.push_back(comp1[j]);
                    // std::cout << comp1[j] << std::endl;
                    match = true;
                    break;
                }
            }
            if (match) {
                break;
            }
        }
    }
    return v_out;
}



std::vector<int> char_to_int(std::vector<char> v)
{
    std::unordered_map<char, int> char_map;

    for (char c='a'; c<='z'; ++c){
        std::cout << c << std::endl;
        char_map[c] = l;
        ++l;
    }
    std::vector<int> v_out;
    for (int i:v){
        v_out.push_back(char_map[v[i]]);
    }
    return v_out;
}

int main() 
{

    // Scratch: 
    std::vector<std::string> d = parse_data("test_data.txt");
    std::vector<std::vector<std::string>> split = split_compartments(d);
    std::vector<char> common = get_common_item(split);
    std::vector<int> int_rep = char_to_int(common);



    for (int i=0; i!=int_rep.size(); ++i){
        std::cout << int_rep[i] << std::endl;
    }

}