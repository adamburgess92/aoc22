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

int max_calories(std::vector<std::string>& v)
{
    int largest = 0;
    int sum = 0;
    for (int i=0; i!=v.size(); ++i){
        if (v[i]=="x"){
            if (sum>largest){
                largest = sum;
            }
            sum = 0;
        } else {
            sum += std::stoi(v[i]);
        }
    }
    return largest;
}

int main() 
{
    std::vector<std::string> v = input_to_vector("data.txt");
    replace_blanks(v);
    int res = max_calories(v);
    std::cout << res << std::endl;

    return 0;
}