#include <iostream>
#include "Parser.h"
#include <vector>
#include "Monkey.h"

void monkey_business(std::vector<Monkey>& monkeys, int n)
    {
        for (int r=0; r!=n; ++r){
            for (int m=0; m!=monkeys.size(); ++m){ // Monkeys 
                for (int i=0; i!=monkeys[m].items.size(); ++i){
                    std::cout << "monkey: " << m << std::endl;
                    monkeys[m].inspect_and_throw(i, monkeys);
                }
                monkeys[m].items.clear();
            }
        }
    }

int main()
{
    std::vector<std::vector<std::string>> d = parse_data("test_data.txt");

    // Load data into vector
    std::vector<Monkey> monkeys;
    for (int i=0; i!=d.size(); ++i){
        Monkey m = Monkey();
        m.load_n(i);
        m.load_items(d[i][1]);
        m.load_operation(d[i][2]);
        m.load_test(d[i][3]);
        m.load_true(d[i][4]);
        m.load_false(d[i][5]);
        monkeys.push_back(m);
    }

    monkey_business(monkeys, 20);
    std::cout << "Monkey 0 has" << std::endl;
    for (int i=0; i!=monkeys[0].items.size(); ++i){
        std::cout << monkeys[0].items[i].worry_level << std::endl;
    }
    std::cout << "Monkey 1 has" << std::endl;
    for (int i=0; i!=monkeys[1].items.size(); ++i){
        std::cout << monkeys[1].items[i].worry_level << std::endl;
    }
    std::cout << "Monkey 2 has" << std::endl;
    for (int i=0; i!=monkeys[2].items.size(); ++i){
        std::cout << monkeys[2].items[i].worry_level << std::endl;
    }
    std::cout << "Monkey 3 has" << std::endl;
    for (int i=0; i!=monkeys[3].items.size(); ++i){
        std::cout << monkeys[3].items[i].worry_level << std::endl;
    }

    for (int m=0; m!=monkeys.size(); ++m){
        std::cout << "Monkey " << monkeys[m].n << " inspected items " << monkeys[m].n_items_inspected << " times" << std::endl;
    }
}

