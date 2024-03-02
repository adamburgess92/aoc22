class Item{
public:
    Item(int worry_level): worry_level(worry_level) {}
    int worry_level;
    // Overload == operator to allow for removal
    bool operator==(const Item& other) const {
        return worry_level == other.worry_level;
    }
};