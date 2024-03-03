#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <regex>
#include "Item.h"

class Monkey {
public:
    Monkey();
    // Monkey(int n, std::vector<Item> starting_items);

    int n;
    std::vector<Item> items;
    std::string op_type;
    std::vector<int> op_ints;
    int test_divisor;
    int if_true;
    int if_false;
    int n_items_inspected = 0;
    int curr_item_worry_level;
    void inspect_and_throw(int idx, std::vector<Monkey>& monkey_list);
    void load_n(int i);
    void load_items(const std::string& s);
    void load_operation(const std::string& s);
    void load_test(const std::string& s);
    void load_true(const std::string& s);
    void load_false(const std::string& s);
    
    bool perform_test();


};