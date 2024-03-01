#include <iostream>
#include "Parser.h"
#include <vector>
#include "Monkey.h"


// Op should be a function (if possible)
// test should be a function (if possible)


std::vector<Monkey> set_initial_state()
{
    std::vector<Monkey> monkey_list;
    monkey_list.push_back(Monkey(0, std::vector<Item>{Item(79), Item(98)}));
    monkey_list.push_back(Monkey(1, std::vector<Item>{Item(79), Item(98)}));
    monkey_list.push_back(Monkey(2, std::vector<Item>{Item(79), Item(98)}));
    monkey_list.push_back(Monkey(3, std::vector<Item>{Item(79), Item(98)}));
    monkey_list.push_back(Monkey(4, std::vector<Item>{Item(79), Item(98)}));

    return monkey_list;
}



// void perform_monkey_business(std::vector<Monkey>& monkey_list)
// {
//     for (int m=0; m!=monkey_list.size(); ++m){
//         auto monkey = monkey_list[m];
//         for (int i=0; i!=monkey.items.size(); ++i){
//             monkey.update_item_worry_level(monkey.items[i]);
//             monkey.throw_item(monkey.items[i]);

//         }
//     }
// }



int main()
{
    // std::vector<std::string> d = parse_data("data.txt");
    // // One round
    // perform_monkey_business(monkey_list); // Do this 20 times.

    std::vector<Monkey> monkey_list = set_initial_state();

    Monkey monkey1 = Monkey(1, std::vector<Item>{Item(1), Item(2)});
    Monkey monkey2 = Monkey(2, std::vector<Item>{Item(3), Item(4)});
    monkey1.throw_item(Item(1), monkey2);
    std::cout << "monkey 2" << std::endl;
    for (int i = 0; i!=monkey2.items.size(); ++i){
      std::cout << monkey2.items[i].worry_level << std::endl;
    }
    std::cout << "monkey 1" << std::endl;
    for (int i = 0; i!=monkey1.items.size(); ++i){
      std::cout << monkey1.items[i].worry_level << std::endl;
    }



}


/*
Monkey 0:
  Monkey inspects an item with a worry level of 79.
    Worry level is multiplied by 19 to 1501.
    Monkey gets bored with item. Worry level is divided by 3 to 500.
    Current worry level is not divisible by 23.
    Item with worry level 500 is thrown to monkey 3.
  Monkey inspects an item with a worry level of 98.
    Worry level is multiplied by 19 to 1862.
    Monkey gets bored with item. Worry level is divided by 3 to 620.
    Current worry level is not divisible by 23.
    Item with worry level 620 is thrown to monkey 3.
Monkey 1:
  Monkey inspects an item with a worry level of 54.
    Worry level increases by 6 to 60.
    Monkey gets bored with item. Worry level is divided by 3 to 20.
    Current worry level is not divisible by 19.
    Item with worry level 20 is thrown to monkey 0.
  Monkey inspects an item with a worry level of 65.
    Worry level increases by 6 to 71.
    Monkey gets bored with item. Worry level is divided by 3 to 23.
    Current worry level is not divisible by 19.
    Item with worry level 23 is thrown to monkey 0.
  Monkey inspects an item with a worry level of 75.
    Worry level increases by 6 to 81.
    Monkey gets bored with item. Worry level is divided by 3 to 27.
    Current worry level is not divisible by 19.
    Item with worry level 27 is thrown to monkey 0.
  Monkey inspects an item with a worry level of 74.
    Worry level increases by 6 to 80.
    Monkey gets bored with item. Worry level is divided by 3 to 26.
    Current worry level is not divisible by 19.
    Item with worry level 26 is thrown to monkey 0.
Monkey 2:
  Monkey inspects an item with a worry level of 79.
    Worry level is multiplied by itself to 6241.
    Monkey gets bored with item. Worry level is divided by 3 to 2080.
    Current worry level is divisible by 13.
    Item with worry level 2080 is thrown to monkey 1.
  Monkey inspects an item with a worry level of 60.
    Worry level is multiplied by itself to 3600.
    Monkey gets bored with item. Worry level is divided by 3 to 1200.
    Current worry level is not divisible by 13.
    Item with worry level 1200 is thrown to monkey 3.
  Monkey inspects an item with a worry level of 97.
    Worry level is multiplied by itself to 9409.
    Monkey gets bored with item. Worry level is divided by 3 to 3136.
    Current worry level is not divisible by 13.
    Item with worry level 3136 is thrown to monkey 3.
Monkey 3:
  Monkey inspects an item with a worry level of 74.
    Worry level increases by 3 to 77.
    Monkey gets bored with item. Worry level is divided by 3 to 25.
    Current worry level is not divisible by 17.
    Item with worry level 25 is thrown to monkey 1.
  Monkey inspects an item with a worry level of 500.
    Worry level increases by 3 to 503.
    Monkey gets bored with item. Worry level is divided by 3 to 167.
    Current worry level is not divisible by 17.
    Item with worry level 167 is thrown to monkey 1.
  Monkey inspects an item with a worry level of 620.
    Worry level increases by 3 to 623.
    Monkey gets bored with item. Worry level is divided by 3 to 207.
    Current worry level is not divisible by 17.
    Item with worry level 207 is thrown to monkey 1.
  Monkey inspects an item with a worry level of 1200.
    Worry level increases by 3 to 1203.
    Monkey gets bored with item. Worry level is divided by 3 to 401.
    Current worry level is not divisible by 17.
    Item with worry level 401 is thrown to monkey 1.
  Monkey inspects an item with a worry level of 3136.
    Worry level increases by 3 to 3139.
    Monkey gets bored with item. Worry level is divided by 3 to 1046.
    Current worry level is not divisible by 17.
    Item with worry level 1046 is thrown to monkey 1.

*/


/*
After 1 round:

Monkey 0: 20, 23, 27, 26
Monkey 1: 2080, 25, 167, 207, 401, 1046
Monkey 2:
Monkey 3:
*/
