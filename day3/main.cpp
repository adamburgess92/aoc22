#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "parser.h"

std::vector<std::vector<std::string>> split_compartments(std::vector<std::string>& v)
{
    std::vector<std::vector<std::string>> v_out;

    for (int i=0; i!=v.size(); ++i){
        int l = v[i].size();
        std::string first_compartment = v[i].substr(0, l/2);
        std::string second_compartment = v[i].substr(l/2, l);
        std::vector<std::string> split_compartments = {first_compartment, second_compartment};
        v_out.push_back(split_compartments);
    }
    return v_out;
}

std::vector<char> get_common_item(std::vector<std::vector<std::string>>& v)
{
    std::vector<char> v_out;
    // Loop through:
    for (int i=0; i!=v.size(); ++i){
        std::string comp1 = v[i][0]; // Compartment 1
        std::string comp2 = v[i][1]; // Compartment 2
        // std::cout << comp1 << " " << comp2 << std::endl;

        for (int j=0; j!=comp1.size(); ++j){
            bool match = false;
            for (int k=0; k!=comp2.size(); ++k){
                if (comp1[j] == comp2[k]) {
                    v_out.push_back(comp1[j]);
                    // std::cout << comp1[j] << std::endl;
                    match = true;
                    break;
                }
            }
            if (match) {
                break;
            }
        }
    }
    return v_out;
}

std::unordered_map<char, int> generate_map()
{
    // Declare map - lower
    std::unordered_map<char, int> m;
    // Lower case
    for (char l='a'; l<='z'; ++l){
        int i = l - 'a' +1;
        m[l] = i;
    }
    // Declare map - upper
    std::unordered_map<char, int> n;
    // Upper case:
    for (char u='A'; u<='Z'; ++u){
        int j = u - 'A' + 26 + 1;
        n[u] = j;
    }
    // Combine maps
    m.insert(n.begin(), n.end());
    return m;
}

std::vector<int> char_to_int(std::vector<char> v)
{
    std::vector<int> v_out;
    // Generate map
    std::unordered_map<char, int> m = generate_map();
    for (int i=0; i!=v.size(); ++i){
        v_out.push_back(m[v[i]]);
    }
    return v_out;
}

int sum_scores(std::vector<int>& v)
{
    int sum  = 0;
    for (int i=0; i!=v.size(); ++i){
        sum += v[i];
    }
    return sum;
}

// std::vector<std::vector<std::string>> create_triplets(std::vector<std::string>& v)
// {
//     std::vector<std::vector<std::string>> v_out;
//    // v_out should have length 1/3 of v
// }


std::vector<std::vector<std::string>> triplets(std::vector<std::string>& v)
{
    std::vector<std::vector<std::string>> v_out;
    std::vector<std::string> subvec;
    int trip = 0;
    for (int i=0; i!=v.size(); ++i){
        // std::cout << "i: " << i << std::endl;
        // std::cout << "trip: " << trip << std::endl;
        ++trip;
        // Push to subvectors
        subvec.push_back(v[i]);
        if (trip%3==0){
            // Reset triplet counter:
            trip=0;
            // Push subvectors to v_out
            v_out.push_back(subvec);
            // Reset subvectors
            subvec.clear();
        }
    }
    return v_out; // should have size() 1/3x v
}

std::vector<std::vector<char>> get_common_from_triplet(std::vector<std::vector<std::string>>& v)
// std::vector<char> get_common_from_triplet(std::vector<std::vector<std::string>>& v)
{
    // Need to find common distinct common elements between v[i][0] and v[i][1] -> vector[string]
    // Once we have that, traverse that vector against v[i][2] -> char
    // [[..., ..., ...], [..., ..., ...]]
    // std::vector<char> v_out;
    std::vector<std::vector<char>> v_out;
    std::vector<char> first_matches;


    for (int i=0; i!=v.size(); ++i){
        std::string comp1 = v[i][0]; // Compartment 1
        std::string comp2 = v[i][1]; // Compartment 2
        std::string comp3 = v[i][2]; // Compartment 3

        for (int j=0; j!=comp1.size(); ++j) {
            for (int k=0; k!=comp2.size(); ++k) {
                if (comp1[j]==comp2[k]) {
                    first_matches.push_back(comp1[j]);
                }

            }
        }
        // Now we have the first matches only keep unique values:
        std::sort(first_matches.begin(), first_matches.end());
        std::vector<char>::iterator it = std::unique(first_matches.begin(), first_matches.end());
        first_matches.resize(std::distance(first_matches.begin(), it));
        v_out.push_back(first_matches);
        first_matches.clear();
    }
    return v_out;
}




int main()
{
    // // Part 1:
    // std::vector<std::string> d = parse_data("data.txt");
    // std::vector<std::vector<std::string>> split = split_compartments(d);
    // std::vector<char> common = get_common_item(split);
    // std::vector<int> scores = char_to_int(common);
    // int final_score = sum_scores(scores);
    // std::cout << final_score << std::endl;

    // Part 2:
    std::vector<std::string> d = parse_data("test_data.txt");
    std::vector<std::vector<std::string>> trips = triplets(d);
    std::vector<std::vector<char>> c = get_common_from_triplet(trips);

    // std::vector<std::string> first_element = trips[1];
    // for (int i=0; i!=first_element.size(); ++i){
    //     std::cout << first_element[i] << std::endl;
    // }

    std::vector<char> first_element = c[1];
    for (int i=0; i!=first_element.size(); ++i){
        std::cout << first_element[i] << std::endl;
    }


}