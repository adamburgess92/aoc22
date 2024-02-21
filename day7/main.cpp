#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "parser.h"

// Part 1: Find all of the directories with a total size of at most 100000.
// What is the sum of the total sizes of those directories?

template<typename T>
class TreeNode
{
public:
    // Constructor
    TreeNode() {}
    TreeNode(const T& value): Value(value) {}

    T Value;
    std::list<TreeNode<T> > Children;

    // Every "Children" needs to be appended with ".."
};


int main()
{
    std::vector<std::string> data = parse_data("test_data.txt");
    for (int i=0; i!=data.size(); ++i){
        std::cout << data[i][0] << std::endl;
        if (d[i][0]=='$ cd') {
            TreeNode(d[i][1])
        }
    }

}
