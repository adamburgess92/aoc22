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
    std::string name;
    int size;
    // Constructor: 
    File(std::string name, int size) : name(name), size(size) {}
};

struct Directory {
    std::string name;
    Directory* parent;
    std::vector<Directory*> subdirectories;
    std::vector<File> files;
    // Constructor: 
    Directory(std::string s) : name(s) {};
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

bool is_uplevel(std::string s_in){
    return s_in == "$ cd ..";
}

void process_ls_output(const std::vector<std::string>& s_ls, Directory* current_directory){
    for (const std::string& s : s_ls){
        // If it's a directory...
        if (s.substr(0, 3) == "dir") {
            std::string dir_name = s.substr(s.find(" "), s.length());
            Directory* newdir = new Directory(dir_name);
            current_directory->subdirectories.push_back(newdir);
        }
        // If it's a file...
        else {
            int filesize = std::stoi(s.substr(0, s.find(" ")));
            std::string filename = s.substr(s.find(" "), s.length());
            File newfile(filename, filesize);
            current_directory->files.push_back(newfile);
        }
    }
}

void process_cd_output(const std::string& s_cd, Directory* current_node){
    // Dp we even need this?
}

void process_terminal_output(const std::vector<std::string> in){
    int i = 1; // Skip first line - we always start at root
    Directory* current_dir = new Directory("/");
    while (i<=in.size()) {
        std::string next_entry = in[i];
        std::cout << "Next entry: " << next_entry << std::endl;
        std::cout << "Current directory: " << current_dir->name << std::endl;
        if (is_uplevel(next_entry)) {
            std::cout << "Moving up a level" << std::endl;
            current_dir = current_dir->parent;
            ++i;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }
        if (is_cd(next_entry)) {
            // return next_entry;
            std::cout << "Changing directory" << std::endl;
            ++i;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }
        if (is_ls(next_entry)){
            std::cout << "Listing directory contents" << std::endl;
            // Keep going until hit another command: 
            std::vector<std::string> ls_output;
            while (!is_ls(in[i+1]) & !is_cd(in[i+1])){
                ++i;
                next_entry = in[i];
                ls_output.push_back(next_entry);
            }
            // 
            for (const std::string& j : ls_output) {
                std::cout << j << std::endl;
            }
            process_ls_output(ls_output, current_dir);
            ++i;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }
    }
}

int main()
{
    std::vector<std::string> data = parse_data("test_data.txt");
    process_terminal_output(data);
    return 0;
}
