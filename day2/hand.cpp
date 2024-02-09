#include <string>
#include "hand.h"

Hand::Hand(char opp, char you)
    :opp(opp), you(you)
{
}
char Hand::convert_input(const char s)
{
    char c = s[0];
    switch(c){
        case 'A':
            return 'R';
        case 'B':
            return 'P';
        case 'C':
            return 'S';
        case ''

    }
}
int Hand::calculate_score()
{
    // R, P, S
    if (opp=="")
    
}

