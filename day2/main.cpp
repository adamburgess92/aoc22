#include <iostream>
#include <string>
#include <vector>
// #include "hand.h"
#include "parser.h"

int main()
{
    std::vector<Hand> d = parse_data("test_data.txt");
    
    for (int i=0; i!=d.size(); ++i){
        int game_score = d[i].calculate_score();
        std::cout << game_score << std::endl;
    }
    
}

