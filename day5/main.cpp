#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <stack>

#include "parser.h"

int get_num_move(const std::string& s)
{
    std::regex pattern("move\\s+(\\d+)");
    std::smatch match;
    std::regex_search(s, match, pattern);
    return std::stoi(match[1]);
}

int get_from(std::string& s)
{
    std::regex pattern("from\\s+(\\d+)");
    std::smatch match;
    std::regex_search(s, match, pattern);
    return std::stoi(match[1]);
}

int get_to(std::string& s)
{
    std::regex pattern("to\\s+(\\d+)");
    std::smatch match;
    std::regex_search(s, match, pattern);
    return std::stoi(match[1]);
}

std::unordered_map<std::string, int> move_instructions(std::string& s)
{
    std::unordered_map<std::string, int> m;
    m["num_move"] = get_num_move(s);
    m["from"] = get_from(s);
    m["to"] = get_to(s);
    return m;
}

void perform_movement(std::unordered_map<int, std::stack<char>>& crates, std::unordered_map<std::string, int>& moves)
{
    // Pick crates up
    std::vector<char> crates_to_move;
    for (int i=0; i<=moves["num_move"]; ++i){
        char top = crates[moves["from"]].top();
        crates_to_move.push_back(top);
        crates[moves["from"]].pop();
    }
    // Put crates down...
    for (int j=crates_to_move.size(); j>=0; --j){
        crates[moves["to"]].push(crates_to_move[j]);
    }
}

int main() {
    // Too lazy to build parser for weird data...
    // std::unordered_map<int, std::vector<char>> m;
    // m[1] = {'N', 'Z'};
    // m[2] = {'M', 'C', 'D'};
    // m[3] = {'P'};

    std::unordered_map<int, std::stack<char>> m;
    m[1].push('N');
    m[1].push('Z');

    m[2].push('M');
    m[2].push('C');
    m[2].push('D');

    m[3].push('P');

    // Load moves:
    std::vector<std::string> d = parse_data("test_moves.txt");

    for (int i=0; i<=d.size(); ++i){
        std::unordered_map<std::string, int> moves = move_instructions(d[i]);
        perform_movement(m, moves);
    }


}

