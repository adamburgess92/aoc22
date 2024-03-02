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
    // m[1].push('Z');
    // m[1].push('N');

    // m[2].push('M');
    // m[2].push('C');
    // m[2].push('D');

    // m[3].push('P');

    m[1].push('H');
    m[1].push('T');
    m[1].push('Z');
    m[1].push('D');

    m[2].push('Q');
    m[2].push('R');
    m[2].push('W');
    m[2].push('T');
    m[2].push('G');
    m[2].push('C');
    m[2].push('S');

    m[3].push('P');
    m[3].push('B');
    m[3].push('F');
    m[3].push('Q');
    m[3].push('N');
    m[3].push('R');
    m[3].push('C');
    m[3].push('H');

    m[4].push('L');
    m[4].push('C');
    m[4].push('N');
    m[4].push('F');
    m[4].push('H');
    m[4].push('Z');

    m[5].push('G');
    m[5].push('L');
    m[5].push('F');
    m[5].push('Q');
    m[5].push('S');

    m[6].push('V');
    m[6].push('P');
    m[6].push('W');
    m[6].push('Z');
    m[6].push('B');
    m[6].push('R');
    m[6].push('C');
    m[6].push('S');

    m[7].push('Z');
    m[7].push('F');
    m[7].push('J');

    m[8].push('D');
    m[8].push('L');
    m[8].push('V');
    m[8].push('Z');
    m[8].push('R');
    m[8].push('H');
    m[8].push('Q');

    m[9].push('B');
    m[9].push('H');
    m[9].push('G');
    m[9].push('N');
    m[9].push('F');
    m[9].push('Z');
    m[9].push('L');
    m[9].push('D');


    // Load moves:
    // std::vector<std::string> d = parse_data("test_moves.txt");
    std::vector<std::string> d = parse_data("moves.txt");

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
    std::cout << "~~~~~" << std::endl;
    while (!m[4].empty()) {
        std::cout << m[4].top() << std::endl;
        m[4].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[5].empty()) {
        std::cout << m[5].top() << std::endl;
        m[5].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[6].empty()) {
        std::cout << m[6].top() << std::endl;
        m[6].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[7].empty()) {
        std::cout << m[7].top() << std::endl;
        m[7].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[8].empty()) {
        std::cout << m[8].top() << std::endl;
        m[8].pop();
    }
    std::cout << "~~~~~" << std::endl;
    while (!m[9].empty()) {
        std::cout << m[9].top() << std::endl;
        m[9].pop();
    }
}

