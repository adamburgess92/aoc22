#include <iostream>
#include <sstream>
#include <algorithm>
#include "Register.h"

Register::Register(): cycle(0), X(1) {};
void Register::build_queue(const std::string&s)
{
    // Update Queued instructions
    std::string cmd_type = s.substr(0,4);
    if (cmd_type=="noop"){
        cycle += 1;
        queued_instructions.emplace(cycle, 0);
    }
    if (cmd_type=="addx"){
        // Get the int:
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        int op = std::stoi(tokens[1]);
        cycle += 2;
        queued_instructions.emplace(cycle, 0);
        queued_instructions.emplace(cycle+1, op);
    }
}
void Register::print_queue()
{
    for (int i=1; i!=queued_instructions.size()+1; ++i){
        std::cout << "cycle: " << i << std::endl;
        X += queued_instructions[i];
        std::cout << "X: " << X << std::endl;
    }
}
void Register::print_res()
{
    int sum = 0;
    std::vector k_cycles = {20, 60, 100, 140, 180, 220};
    for (int i=1; i!=queued_instructions.size()+1; ++i){
        X += queued_instructions[i];
        if (std::find(k_cycles.begin(), k_cycles.end(), i) != k_cycles.end()){
            std::cout << X*i << std::endl;
            sum = sum + i*X;
        }
    }
    std::cout << sum << std::endl;
}
