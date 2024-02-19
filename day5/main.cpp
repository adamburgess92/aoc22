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

void perform_movement(std::unordered_map<int, std::stack<char>>& crates, std::unordered_map<std::string, int> moves)
{
    for (int i=1; i<=moves["num_move"]; ++i){
        char top = crates[moves["from"]].top();
        crates[moves["from"]].pop();
        crates[moves["to"]].push(top);
    }
}

int main() {
    // Too lazy to build parser for weird data...
    std::unordered_map<int, std::stack<char>> m;
    m[1].push('Z');
    m[1].push('N');

    m[2].push('M');
    m[2].push('C');
    m[2].push('D');

    m[3].push('P');

    // Load moves:
    std::vector<std::string> d = parse_data("test_moves.txt");
    std::unordered_map<std::string, int> instructions;
    for (int i=0; i!=d.size(); ++i){
        std::cout << d[i] << std::endl;
        instructions = move_instructions(d[i]);
        perform_movement(m, instructions);
    }
    while (!m[1].empty()) {
        std::cout << m[1].top() << std::endl;
        m[1].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[2].empty()) {
        std::cout << m[2].top() << std::endl;
        m[2].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[3].empty()) {
        std::cout << m[3].top() << std::endl;
        m[3].pop();
    }
}

