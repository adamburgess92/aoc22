#include <iostream>
#include "Monkey.h"

Monkey::Monkey() {};

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

void Monkey::decide_and_throw(int idx, std::vector<Monkey>& monkey_list)
{
    bool t_result = (curr_item_worry_level%11==0);
    if (t_result){
        throw_item(idx, monkey_list[if_true]);
    } else {
        throw_item(idx, monkey_list[if_false]);
    }
}

// Parsing things:
void Monkey::load_n(int i)
{
    n = i;
}

void Monkey::load_items(const std::string& s)
{
    std::vector<Item> result;
    std::istringstream iss(s);
    while (!isdigit(iss.peek()) && iss.peek() != EOF) {
        iss.ignore();
    }
    // Extract ints
    int num;
    while (iss >> num) {
        result.push_back(Item(num));
        // Skip non-digit characters
        while (!isdigit(iss.peek()) && iss.peek() != EOF) {
            iss.ignore();
        }
    }
    items = result;
}


void Monkey::load_operation(const std::string& s)
{
}

void Monkey::load_test(const std::string& s)
{
    int result;
    std::istringstream iss(s);
    while (!isdigit(iss.peek()) && iss.peek() != EOF) {
        iss.ignore();
    }
    // Extract int
    int num;
    while (iss >> num) {
        result = num;
        break;
    }
    test_divisor = result;
}

void Monkey::load_true(const std::string& s)
{
    int result;
    std::istringstream iss(s);
    while (!isdigit(iss.peek()) && iss.peek() != EOF) {
        iss.ignore();
    }
    // Extract int
    int num;
    while (iss >> num) {
        result = num;
        break;
    }
    if_true = result;
}

void Monkey::load_false(const std::string& s)
{
    int result;
    std::istringstream iss(s);
    while (!isdigit(iss.peek()) && iss.peek() != EOF) {
        iss.ignore();
    }
    // Extract int
    int num;
    while (iss >> num) {
        result = num;
        break;
    }
    if_false = result;
}