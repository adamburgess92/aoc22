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
    convert_input(opp);
    convert_input(you);
    // Logic:
    if (you=='R'){
        score += 1;
        if (opp=='S'){
            score += 6;
        } else if (opp=='R'){
            score += 3;
        }
    } else if (you=='P'){
        score += 2;
        if (opp=='R'){
            score += 6;
        } else if (opp=='P'){
            score += 3;
        }
    } else if (you=='S'){
        score += 3;
        if (opp=='P'){
            score += 6;
        } else if (opp=='S'){
            score += 3;
        }
    }
    return score;
}

