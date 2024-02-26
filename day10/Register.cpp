#include <iostream>
#include <sstream>
#include "Register.h"

Register::Register(): cycle(1), X(1) {};
void Register::build_queue(const std::string&s)
{
    // Update Queued instructions
    std::string cmd_type = s.substr(0,4);
    if (cmd_type=="noop"){
        queued_instructions.emplace(cycle, 0);
        cycle += 1;
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
        queued_instructions.emplace(cycle, 0);
        queued_instructions.emplace(cycle+1, op);
        cycle += 2;
    }
}
void Register::execute_queue()
{
    for (int i=1; i!=queued_instructions.size()+1; ++i){
        std::cout << "cycle: " << i << std::endl;
        X += queued_instructions[i];
        std::cout << "X: " << X << std::endl;
    }
}
