#include <iostream>
#include "Parser.h"
#include "Register.h"

// X starts at 1
// addx takes 2x cycles to complete
// noop takes 1 cycle to complete

int main()
{
    std::vector<std::string> d = parse_data("tiny_data.txt");
    Register r = Register();
    for (int i=0; i<d.size(); ++i){
        r.process_command(d[i]);

    }
}