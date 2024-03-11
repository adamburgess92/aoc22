#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Parser.h"

void basic_stringstream(const std::string& str_in)
{
    std::stringstream ss(str_in);
    std::vector<int> numbers;
    int num;
    char ch;
    while (ss >> ch){
        if (isdigit(ch)){
            ss.putback(ch);
            ss >> num;
            numbers.push_back(num);
        }
    }
    for (int i=0; i!=numbers.size(); ++i){
        std::cout << numbers[i] << std::endl;
    }
}

// Given a string starting with an opening bracket, returns index of closing bracket: 
int locate_closing_bracket(std::string& str_in)
{
    std::stringstream ss_open(str_in);
    // count number of '[' 
    char ch_open;
    int n_open=0;
    int n_close=0;
    while (ss_open >> ch_open){
        if (ch_open=='['){
            ++n_open;
        }
        if (ch_open==']'){
            ++n_close;
        }
        if (n_open>0 && n_close>0 && n_open==n_close){
            break;
        }
    }
    // Find index of nth closing bracket:
    std::stringstream ss_close(str_in);
    char ch_close;
    int i = 0;
    int count_hit = 0;
    while (ss_close >> ch_close){
        if (ch_close==']'){
            ++count_hit;
        }
        if (count_hit==n_open){
            break;
        }
        ++i;
    }
    return i;
}

void string_to_vec(std::string str_in)
{
    std::stringstream ss(str_in);
    std::vector<int> numbers;
    int number;
    char ch;
    while (ss >> ch){
        if (ch=='['){
            std::string remainder;
            ss.putback(ch);
            ss >> remainder;
            int close_bracket_index = locate_closing_bracket(remainder);
            std::string s = remainder.substr(1, close_bracket_index-1);
            std::cout << s << std::endl;
            string_to_vec(s);
        } else if (isdigit(ch)){
            ss.putback(ch);
            ss >> number;
            std::cout << number << std::endl;
        }
    }
}


int main() 
{
    // std::vector<std::vector<std::string>> d = parse_data("test_data.txt");
    // std::cout << d[0][0] << std::endl;
    // std::cout << d[0][1] << std::endl;
    // std::cout << d[1][0] << std::endl;
    // std::cout << d[1][1] << std::endl;

    // std::string test_string = "[[8,7,6]]";
    // std::string test_string = "[1,[2,[3,[4,[5,6,7]]]],8,9]";
    // std::string test_string = "[[[[[[[40]]]]]]]";
    // std::string test_string = "[[4,4],4,4]";
    std::string test_string = "[4,4,[4,4]]";
    // std::string test_string = "[[1],[2,3,4]]";
    // std::string test_string = "[[],[],[[[0],8],[],[4,4,9],8],[[8,1,6]]]";


    string_to_vec(test_string);





}