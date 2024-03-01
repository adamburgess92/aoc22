class Item{
public:
    Item(int worry_level): worry_level(worry_level) {}
    int worry_level;
    bool operator==(const Item& other) const {
        return worry_level == other.worry_level;
    }
};