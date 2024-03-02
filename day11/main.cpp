#include <iostream>
#include "Parser.h"
#include <vector>
#include "Monkey.h"

int main()
{
    std::vector<std::vector<std::string>> d = parse_data("test_data.txt");
    // std::cout << d[0][0] << std::endl;
    // std::cout << d[0][1] << std::endl;
    // std::cout << d[0][2] << std::endl;
    // std::cout << d[0][3] << std::endl;
    // std::cout << d[0][4] << std::endl;
    // std::cout << d[0][5] << std::endl;

    // Load data into vector
    std::vector<Monkey> monkeys;
    for (int i=0; i!=d.size(); ++i){
        Monkey m = Monkey();
        m.load_n(i);
        m.load_items(d[i][1]);
        // m.load_operation(d[i][2]);
        m.load_test(d[i][3]);
        m.load_true(d[i][4]);
        m.load_false(d[i][5]);
        monkeys.push_back(m);
    }
    std::vector<Item> vi = monkeys[1].items;
    for (int i=0; i!=vi.size(); ++i){
        std::cout << vi[i].worry_level << std::endl;
    }
    std::cout << "Test divisor: " << monkeys[1].test_divisor << std::endl;
    std::cout << "If true throw to : " << monkeys[1].if_true << std::endl;
    std::cout << "If false throw to : " << monkeys[1].if_false << std::endl;

}

