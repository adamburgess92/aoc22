#include <iostream>
#include <sstream>
#include "Register.h"

Register::Register(): cycle(0), X(1) {};
void Register::process_command(const std::string&s)
{
    std::cout << "Cycle: " << cycle << std::endl;
    std::cout << "Start X: " << X << std::endl;

    // Command is going to look something like "addx 15", "noop"
    std::string cmd_type = s.substr(0,4);

    if (cmd_type=="addx"){
        // Get the int:
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        int op = std::stoi(tokens[1]);

        // Append to queued instructions:
        // std::cout << "Adding to queue: " << op << std::endl;
        int k = cycle+2;
        queued_instructions.emplace(k, op);

        // Perform any queued operations
        // If current cycle is in queued instructions,

        // for (const auto& pair : queued_instructions) {
        //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        //
    }
    auto it = queued_instructions.find(cycle);
    if (it != queued_instructions.end()) {
        X += queued_instructions[cycle];
    }

    std::cout << "End X: " << X << std::endl;
    // If cmd_type is noop, nothing happens

    ++cycle;
}