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
    int i=0;
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
            std::string r = remainder.substr(close_bracket_index+1, remainder.size());
            std::cout << s << std::endl;
            string_to_vec(s+r);
        } else if (isdigit(ch)){
            ss.putback(ch);
            ss >> number;
            std::cout << number << std::endl;
        }
    }
}


int main() 
{

    std::string test_string = "[4,4,[4,4]]";
    string_to_vec(test_string);





}