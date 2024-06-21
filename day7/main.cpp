#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "parser.h"


// Part 1: Find all of the directories with a total size of at most 100000.
// What is the sum of the total sizes of those directories?

struct File {
    std::string filename;
    int filesize;
    // Constructor: 
    File(std::string filename, int filesize) : filename(filename), filesize(filesize) {}
};

struct Node {
    std::string dir;
    Node* parent;
    std::vector<Node*> children;
    std::vector<File> files;
    // Constructor: 
    Node(std::string val) : dir(val) {};
};

// class Filesystem {
// public: 
//     Node root_node;
//     Node current_dir;
//     Filesystem() {}
    
// };

bool is_ls(std::string s_in){
    return s_in.substr(0, 4) == "$ ls";
}

bool is_cd(std::string s_in){
    return s_in.substr(0, 4) == "$ cd";
}

// std::vector<std::string> process_input(const std::vector<std::string> in){
void process_input(const std::vector<std::string> in){
    int i = 1;
    std::string next_entry = in[i];
    if (is_cd(next_entry)) {
        std::cout << next_entry << std::endl;
        return;
        // return next_entry;
    }
    if (is_ls(next_entry)){
        // Keep going until hit another command: 
        std::vector<std::string> x;
        while (!is_ls(in[i+1]) & !is_cd(in[i+1])){
            ++i;
            next_entry = in[i];
            x.push_back(next_entry);
        }
        for (const std::string& j : x) {
            std::cout << j << std::endl;
        }
    }
}

void process_ls(const std::vector<std::string>& s_ls, Node* current_node){
    for (const std::string& s : s_ls){
        // While not another command...
        if ((!is_ls(s)) & (!is_cd(s))){
            // If it's a directory
            if (s.substr(0, 3) == "dir") {
                std::string dir_name = s.substr(s.find(" "), s.length());
                Node* newdir = new Node(dir_name);
                current_node->children.push_back(newdir);
            }
            // If it's a file...
            else {
                int filesize = std::stoi(s.substr(0, s.find(" ")));
                std::string filename = s.substr(s.find(" "), s.length());
                File newfile(filename, filesize);
                current_node->files.push_back(newfile);
            }
        }
    }
}

void perform_action(std::string s_in){
    if (is_ls(s_in)){
        //
    }
    if (is_cd(s_in)){
        //
    }
    // Otherwise don't worry, just move on:
    else {
        return;
    }
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

    // // Test Node struct
    // Node* root = new Node("/");

    // Node* child1 = new Node("foo");
    // Node* child2 = new Node("bar");
    // Node* child3 = new Node("baz");

    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // child2->children.push_back(child3);

    // // Process commands: 
    // for (const std::string& s : data){
    //     perform_action(s);

    // }
    process_input(data);
    
    return 0;
}
