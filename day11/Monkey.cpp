#include "Monkey.h"

Monkey::Monkey() {};

Monkey::Monkey(int n, std::vector<Item> starting_items) : n(n), items(starting_items) {};

void Monkey::inspect_item(int idx)
{
    curr_item_worry_level = items[idx].worry_level;
    curr_item_worry_level = curr_item_worry_level*7;
    items[idx].worry_level = curr_item_worry_level;
    ++n_items_inspected;
}

void Monkey::div_three(int idx)
{
    // Decrease worry level
    curr_item_worry_level = std::floor(curr_item_worry_level/3);
    items[idx].worry_level = curr_item_worry_level;
}

void Monkey::throw_item(int idx, Monkey& to_monkey)
{
    // Throw item to another monkey
    to_monkey.items.push_back(items[idx]);
    // Remove item from this monkey:
    items.erase(items.begin()+idx);
}

void Monkey::decide_and_throw(int idx, Monkey& if_true, Monkey& if_false)
{
    bool t_result = (curr_item_worry_level%11==0);
    if (t_result){
        throw_item(0, if_true);
    } else {
        throw_item(0, if_false);
    }
}

// Parsing things:
void Monkey::load_n(const std::string& s)
{
    std::stringstream ss(s);

}

void Monkey::load_items(const std::string& s)
{}

void Monkey::load_operation(const std::string& s)
{}

void Monkey::load_test(const std::string& s)
{}

void Monkey::load_true(const std::string& s)
{}

void Monkey::load_false(const std::string& s)
{}