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
// Part 2:
void Hand::convert_input_2(char& s)
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
            s = 'L';
            break;
        case 'Y':
            s = 'D';
            break;
        case 'Z':
            s = 'W';
            break;
    }
}
int Hand::calculate_score_2()
{
    int score = 0;
    convert_input_2(opp);
    convert_input_2(you);
    // Logic:
    if (you=='W'){
        score += 6;
        // you hand needs to beat opp hand
        if (opp=='R'){ // you must be paper
            score += 2;
        } else if (opp=='P'){ // you must be scissors
            score += 3;
        } else if (opp='S'){ // you must be rock
            score += 1;
        }
    } else if (you=='D'){
        score += 3;
        // you hand needs to match opp hand
        if (opp=='R'){ // you must be rock
            score += 1;
        } else if (opp=='P'){ // you must be paper
            score += 2;
        } else if (opp='S'){ // you must be scissors
            score += 3;
        }
        
    } else if (you=='L'){
        score += 0;
        // you hand needs to lose to opp hand
        if (opp=='R'){ // you must be scissors
            score += 3;
        } else if (opp=='P'){ // you must be rock
            score += 1;
        } else if (opp='S'){ // you must be paper
            score += 2;
        }
    }
    return score;
}

