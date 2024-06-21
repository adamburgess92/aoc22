#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "parser.h"


// Part 1: Find all of the directories with a total size of at most 100000.
// What is the sum of the total sizes of those directories?

struct Node {
    std::string dir;
    std::vector<Node*> children;
    // Constructor: 
    Node(std::string val) : dir(val) {};
};

class Filesystem {
public: 
    Node current_dir;
    
}

int main()
{
    std::vector<std::string> data = parse_data("test_data.txt");
    // Print data
    // for (const std::string& s : data) {
    //     std::cout << s << std::endl;
    // }
    /*
    A row can begin with either
    - $ -> a command
    - dir -> a directory
    - 23409234 -> file size 
    */

   // Test Node struct
   Node* root = new Node("/");

   Node* child1 = new Node("foo");
   Node* child2 = new Node("bar");
   Node* child3 = new Node("baz");

   root->children.push_back(child1);
   root->children.push_back(child2);
   child2->children.push_back(child3);


   
    
}
