#include <iostream>
#include <string>
#include <vector>
// #include "hand.h"
#include "parser.h"

int get_final_score(std::vector<Hand>& v)
{
    int score = 0;
    for (int i=0; i!=v.size(); ++i){
        int game_score = v[i].calculate_score();
        score += game_score;
    }
    return score;
}

int main()
{
    std::vector<Hand> d = parse_data("test_data.txt");
    int final_score = get_final_score(d);
    std::cout << final_score << std::endl;
}

