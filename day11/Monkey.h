#include <string>
#include <vector>
#include "Item.h"


class Monkey {
public:
    Monkey(int n, std::vector<Item> starting_items);
    int n;
    std::vector<Item> items;
    // void update_item_worry_level(Item& item);
    void throw_item(Item item, Monkey& to_monkey);
    int n_items_inspected = 0;

};