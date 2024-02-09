#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.h"

int main() 
{
    std::vector<std::string> v = input_to_vector("data.txt");
    
    // Debug: 
    // for (int i; i!= v.size(); ++i){
    //     std::cout << i << std::endl;
    // }

    return 0;
}