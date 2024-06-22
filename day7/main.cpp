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
    File(std::string name, int size) : name(name), size(size) {};
};

struct Directory {
    std::string name;
    std::vector<Directory*> subdirectories;
    std::vector<File*> files;
    // Constructor: 
    Directory(std::string s) : name(s) {};
};

class FileSystem {
public:
    Directory* root;
    Directory* current_directory;
    Directory* parent_directory;
    // Constructor: 
    FileSystem(std::string rootdir) {
        root = new Directory(rootdir);
        current_directory = root;
        parent_directory = nullptr;
    }
    // Change directory: 
    void change_directory(std::string cd_string){
        if (cd_string=="$ cd .."){
            current_directory = parent_directory;
            return;
        }
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
            add_directory(dir_name);
        }
        // Change directory: 
        parent_directory = current_directory;
    }
    void add_file(std::string s_file){
        int filesize = std::stoi(s_file.substr(0, s_file.find(" ")));
        std::string filename = s_file.substr(s_file.find(" ")+1, s_file.length());
        File* newfile = new File(filename, filesize);
        current_directory->files.push_back(newfile);
    }
    void add_directory(std::string s_directory){
        std::string directory_name = s_directory.substr(s_directory.find(" ")+1, s_directory.length());
        Directory* newdir = new Directory(directory_name);
        current_directory->subdirectories.push_back(newdir);
    }
};

int main()
{
    // std::vector<std::string> data = parse_data("test_data.txt");
    
    FileSystem fs = FileSystem("/");
    std::cout << fs.current_directory->name << std::endl;
    // $ ls - do nothing:
    // dir a
    fs.add_directory("dir a");
    // 14848514 b.txt
    fs.add_file("14848514 b.txt");
    



    /*
    // 8504156 c.dat
    current_directory = add_file("8504156 c.dat", current_directory);
    // dir d
    current_directory = add_directory("dir d", current_directory);
    // $ cd a
    change_directory("$ cd a", current_directory);
    change_directory("$ cd ..", current_directory);
    */


}
