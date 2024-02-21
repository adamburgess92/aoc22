#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include "parser.h"

class Device {
public:
    Device(std::string s_in) : input_string(s_in), counter(0), target(13) {next();};
    std::vector<char> current_four;
    std::string input_string;
    int counter;
    int target;
    void next()
    {
        // Get 4 characters from input string from counter to counter+4, increment counter
        std::vector<char> v_out;
        std::string fourstring = input_string.substr(counter, 14);
        for (int i=0; i!=fourstring.size(); ++i){
            v_out.push_back(fourstring[i]);
        }
        current_four = v_out;
        counter += 1;
        target += 1;
    }
    bool contains_dupes(){
        // Check std::vector<char> for duplicates:
        bool bool_out = false; // No dupes by default
        std::sort(current_four.begin(), current_four.end());
        for (int i=1; i<current_four.size(); ++i){
            if (current_four[i] == current_four[i-1]){
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::string> data = parse_data("data.txt");
    std::string t = data[0];

    // // Test cases
    // std::string t1 = "bvwbjplbgvbhsrlpgdmjqwftvncz";
    // std::string t2 = "nppdvjthqldpwncqszvftbrmjlhg";
    // std::string t3 = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
    // std::string t4 = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";

    Device d(t);
    for (int i=0; i!=d.input_string.size(); ++i){
        if (d.contains_dupes()){
            d.next();
        } else {
            std::cout << d.target << std::endl;
            break;
        }
    }
    // 1531 is the answer
}

