#include <string>
#include <unordered_map>
#include <vector>

class Register {
public:
    Register();
    int cycle;
    int X;
    std::vector<char> crt;
    std::unordered_map<int, int> queued_instructions;
    void build_queue(const std::string& s);
    void print_queue();
    void print_res();
    void render_crt();
};
