#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include "Register.h"

Register::Register(): cycle(1), X(1) {};
void Register::build_queue(const std::string&s)
{
    // Update Queued instructions - these are the values AFTER cycle completes
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
    for (int i=1; i!=queued_instructions.size(); ++i){
        X += queued_instructions[i-1];
        if (std::find(k_cycles.begin(), k_cycles.end(), i) != k_cycles.end()){
            std::cout << X*i << std::endl;
            sum = sum + i*X;
        }
    }
    std::cout << sum << std::endl;
}

void Register::render_crt()
{
    int max_width = 40;
    // Think of it in 1d first, render it in 2d.
    int X = 1; // Should be 1?
    int crt_col = 0;
    // std::vector<char> p_vec;
    std::string p_vec;
    for (int i=1; i!=queued_instructions.size(); ++i){
        // std::cout << "crt_col: " << crt_col << std::endl;
        // std::cout << X << std::endl;
        int X_lower = X-1;
        int X_upper = X+1;
        // std::cout << "i (crt pos): " << crt_col << std::endl;
        // std::cout << "X_lower: " << X_lower << std::endl;
        // std::cout << "X_upper : " << X_upper << std::endl;
        if (crt_col>=X_lower && crt_col<=X_upper){
            // std::cout << '#' << std::endl;
            p_vec.push_back('#');
        } else {
            // std::cout << '.' << std::endl;
            p_vec.push_back('.');
        }
        X += queued_instructions[i]; // Sprite centre
        ++crt_col;
        if (crt_col==max_width){
            // Reset crt_col
            crt_col = 0;
            // // Debug
            // Print line:
            std::cout << p_vec << std::endl;
            // Reset p_vec
            p_vec.clear();
        }
    }
}
