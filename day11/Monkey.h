#include <string>
#include <vector>
#include "Item.h"


class Monkey {
public:
    Monkey(int n, std::vector<int> starting_items, std::string op, std::string test, int if_true, int if_false);
    std::vector<Item> items;
    int test_int;
    void update_item_worry_level(Item& item);
    void throw_item(Item item, std::vector<Monkey>& monkey_list);
    int n_items_inspected = 0;
};