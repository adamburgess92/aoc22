#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include "Item.h"

class Monkey {
public:
    Monkey();
    // Monkey(int n, std::vector<Item> starting_items);

    int n;
    std::vector<Item> items;
    int if_true;
    int if_false;
    int n_items_inspected = 0;
    int curr_item_worry_level;
    void inspect_item(int idx);
    void update_item_worry_level(int idx);
    void div_three(int idx);
    void throw_item(int idx, Monkey& to_monkey);
    void decide_and_throw(int idx, std::vector<Monkey>& monkey_list);

    int test_divisor;
    void load_n(int i);
    void load_items(const std::string& s);
    void perform_operation();
    void load_operation(const std::string& s);
    bool perform_test();
    void load_test(const std::string& s);
    void load_true(const std::string& s);
    void load_false(const std::string& s);


};