#include <iostream>
#include "Parser.h"
#include "Register.h"

// X starts at 1
// addx takes 2x cycles to complete
// noop takes 1 cycle to complete

int main()
{
    std::vector<std::string> d = parse_data("test_data.txt");
    Register r = Register();
    for (int i=0; i<d.size(); ++i){
        r.build_queue(d[i]);

    }
    // for (const auto& pair : r.queued_instructions) {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }
    r.print_queue();
    // r.print_res();

}