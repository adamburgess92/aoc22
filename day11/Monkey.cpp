#include "Monkey.h"

Monkey::Monkey(int n, std::vector<Item> starting_items) : n(n), items(starting_items) {};

// void Monkey::update_item_worry_level(Item& item)
// {
//     int worry_level; // Do the operation
//     item.worry_level = worry_level;
// }

void Monkey::throw_item(Item item, Monkey& to_monkey)
{
    // Throw item to another monkey
    to_monkey.items.push_back(item);
    // Remove item from this monkey:
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}