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
        case 'B':
            s = 'P';
        case 'C':
            s = 'S';
        case 'X':
            s = 'R';
        case 'Y':
            s = 'P';
        case 'Z':
            s = 'S';
    }
}
int Hand::calculate_score()
{
    int score = 0;
    convert_input(opp);
    convert_input(you);

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

