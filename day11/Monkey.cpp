#include "Monkey.h"
#include "Item.h"



void Monkey::update_item_worry_level(Item& item)
{
    int worry_level; // Do the operation
    item.worry_level = worry_level;
}

void Monkey::throw_item(Item item, std::vector<Monkey>& monkey_list)
{
    // Figre out who to throw Item to:
    if (item.worry_level%test_int==0){
        int to = 1;
    } else {
        int to = 3;
    }
    int to = 3;
    monkey_list[to].items.push_back(item);


    // Remove from vector


}