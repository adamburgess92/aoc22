#include <string>

class Hand {
public:
    Hand(char opp, char you);
    void convert_input(char& s);
    int calculate_score();
    // Part 2
    void convert_input_2(char& s);
    int calculate_score_2();
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