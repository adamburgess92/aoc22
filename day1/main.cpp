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

int main() 
{
    std::vector<std::string> v = input_to_vector("test_data1.txt");
    
    replace_blanks(v);
    
    for (int i=0; i!=v.size(); ++i){
        std::cout << v[i] << std::endl;
    }
    return 0;
}