#include <string>

class Hand {
public:
    Hand(std::string opp, std::string you);
    char convert_input(const char);
    int calculate_score();
private:
    char opp;
    char you;
};