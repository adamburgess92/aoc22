#include <string>
#include <unordered_map>

class Register {
public:
    Register();
    int cycle;
    int X;
    std::unordered_map<int, int> queued_instructions;
    void process_command(const std::string& s);
};
