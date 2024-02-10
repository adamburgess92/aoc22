#include <iostream>
#include <string>
#include "hand.h"

Hand::Hand(char opp, char you)
    :opp(opp), you(you) 
{
}
void Hand::convert_input(char& s)
{
    switch(s){
        case 'A':
            s = 'R';
            break;
        case 'B':
            s = 'P';
            break;
        case 'C':
            s = 'S';
            break;
        case 'X':
            s = 'R';
            break;
        case 'Y':
            s = 'P';
            break;
        case 'Z':
            s = 'S';
            break;
    }
}
int Hand::calculate_score()
{
    int score = 0;

    std::cout << "Pre conversion: " << opp << std::endl;
    std::cout << "Pre conversion: " << you << std::endl;
    convert_input(opp);
    convert_input(you);
    std::cout << "Post conversion: " << opp << std::endl;
    std::cout << "Post conversion: " << you << std::endl;

    if (you=='R'){
        std::cout << "You have Rock" << std::endl;
        score += 1;
        if (opp=='S'){
            score += 6;
        }
    } else if (you=='P'){
        std::cout << "You have paper" << std::endl;
        score += 2;
        if (opp=='R'){
            score += 6;
        }
    } else if (you=='S'){
        std::cout << "You have scissors" << std::endl;
        score += 3;
        if (opp=='P'){
            score += 6;
        }
    }
    return score;    
}

