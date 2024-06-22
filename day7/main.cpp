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
    std::vector<Directory*> subdirectories;
    std::vector<File> files;
    // Constructor: 
    Directory(std::string s) : name(s) {};
};

Directory* add_file(std::string s_file, Directory* current_directory){
    int filesize = std::stoi(s_file.substr(0, s_file.find(" ")));
    std::string filename = s_file.substr(s_file.find(" ")+1, s_file.length());
    File newfile(filename, filesize);
    current_directory->files.push_back(newfile);
    return current_directory;
}

Directory* add_directory(std::string s_directory, Directory* current_directory){
    std::string directory_name = s_directory.substr(s_directory.find(" ")+1, s_directory.length());
    Directory* newdir = new Directory(directory_name);
    current_directory->subdirectories.push_back(newdir);
    // Return pointer to current directory
    return current_directory;
}

void change_directory(std::string cd_string, Directory* current_directory){
    // Directory name: 
    std::string dir_name = cd_string.substr(cd_string.find("cd")+3, cd_string.length());
    // Check if directory already exists:
    bool dir_exists = false;
    for (const auto& subdir : current_directory->subdirectories){
        if (dir_name == subdir->name) {
            std::cout << "Directory already exists" << std::endl;
            dir_exists = true;
            break;
        }
    }
    // If it doesn't exist, create new directory
    if (!dir_exists) {
        std::cout << "Creating new directory" << std::endl;
        current_directory = add_directory(dir_name, current_directory);
    }
    // Change directory: 


}

int main()
{
    // std::vector<std::string> data = parse_data("test_data.txt");
    // process_terminal_output(data);
    // return 0;

    // Directory* current_directory;
    // Skip first line, crete root directory:
    Directory* current_directory = new Directory("/");
    // $ ls - do nothing:
    // dir a
    current_directory = add_directory("dir a", current_directory);
    // 14848514 b.txt
    current_directory = add_file("14848514 b.txt", current_directory);
    // 8504156 c.dat
    current_directory = add_file("8504156 c.dat", current_directory);
    // dir d
    current_directory = add_directory("dir d", current_directory);
    // $ cd a
    change_directory("$ cd a", current_directory);
    change_directory("$ cd ..", current_directory);


}
