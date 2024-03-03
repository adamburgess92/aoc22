#include <iostream>
#include "Monkey.h"

Monkey::Monkey() {};

void Monkey::inspect_and_throw(int idx, std::vector<Monkey>& monkey_list)
{
    if (op_type=="+"){
        if (op_ints.size()==1){
            items[idx].worry_level = op_ints[0]+items[idx].worry_level;
        } else {
            items[idx].worry_level = items[idx].worry_level + items[idx].worry_level;
        }
    } else if (op_type=="*"){
        if (op_ints.size()==1){
            items[idx].worry_level = op_ints[0]*items[idx].worry_level;
        } else {
            items[idx].worry_level = items[idx].worry_level*items[idx].worry_level;
        }
    }
    ++n_items_inspected;
    //Divide by 3 once done inspecting: 
    items[idx].worry_level = std::floor(items[idx].worry_level/3);
    // Decide where to throw:
    bool t_result = (items[idx].worry_level%test_divisor==0);
    // Throw:
    if (t_result){
        std::cout << "Item with worry level " << items[idx].worry_level << " throw to monkey " << if_true << std::endl;
        monkey_list[if_true].items.push_back(items[idx]);
    } else {
        std::cout << "Item with worry level " << items[idx].worry_level << " throw to monkey " << if_false << std::endl;
        monkey_list[if_false].items.push_back(items[idx]);
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
    // Check for operation type: * or +
    std::regex pattern("[+*]");
    std::smatch match;
    std::regex_search(s, match, pattern);
    op_type = match.str()[0];

    std::vector<int> result;
    std::istringstream iss(s);
    while (!isdigit(iss.peek()) && iss.peek() != EOF ) {
        iss.ignore();
    }
    // Extract ints
    int num;
    while (iss >> num) {
        result.push_back(num);
        // Skip non-digit characters
        while (!isdigit(iss.peek()) && iss.peek() != EOF) {
            iss.ignore();
        }
    }
    op_ints = result;
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