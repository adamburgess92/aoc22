#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.h"

int main() 
{
    std::vector<std::string> v = input_to_vector("test_data1.txt");
    
    // Debug: 
    for (int i=0; i!= v.size(); ++i){
        std::cout << v[i] << std::endl;
        if (v[i]==" ") {
            std::cout << "newline" << std::endl;
        }
    }

    // Iterate through vector. When hit " "



    return 0;
}