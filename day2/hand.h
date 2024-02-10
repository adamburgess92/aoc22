#include <string>

class Hand {
public:
    Hand(char opp, char you);
    void convert_input(char& s);
    int calculate_score();
private:
    char opp;
    char you;
};

    // Rock, Paper, Scissors

    // A beats Z
    // B beats X
    // C beats Y

    // R beats S
    // S beats P
    // P beats R

    // R P 