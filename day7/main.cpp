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
    void change_directory(std::string s_cd){
        Directory* tmp_current; 
        Directory* tmp_parent;
        std::string dir_name = s_cd.substr(s_cd.find("cd")+3, s_cd.length());
        for (int i=0; i<=current_directory->subdirectories.size(); ++i){
            if (dir_name==current_directory->subdirectories[i]->name){
                current_directory = current_directory->subdirectories[i];
                // parent_directory = tmp_current->name;
                break;
            }
        }
    }
    void up_level(){
        // Store temps: 
        // Directory* tmp_current; 
        // Directory* tmp_parent;
        std::cout << "Parent directory: " << current_directory->name << std::endl;
    }

};

int main()
{
    // Load data
    std::vector<std::string> data = parse_data("test_data.txt");
    // Skip first line and instantiate FileSystem with root directory:
    FileSystem fs = FileSystem("/");
    // $ ls - do nothing:
    // dir a
    fs.add_directory("dir a");
    // 14848514 b.txt
    fs.add_file("14848514 b.txt");
    // 8504156 c.dat
    fs.add_file("8504156 c.dat");
    // dir d
    fs.add_directory("dir d");
    // $ cd a
    // fs.change_directory("$ cd a");
    // $ cd ..
    std::cout << "current directory: " << fs.current_directory->name << std::endl;
    // std::cout << "parent directory: " << fs.parent_directory->name << std::endl;
    fs.change_directory("$ cd a");
    std::cout << "current directory: " << fs.current_directory->name << std::endl;
    
    
    // fs.current_directory = fs.current_directory->subdirectories[0];
    // std::cout << "moved, current directory: " << fs.current_directory->name << std::endl;
    // fs.up_level();
    // std::cout << "after uplevel, current directory: " << fs.current_directory->name << std::endl;

}



/*    void change_directory(std::string cd_string){
        // store temps 
        Directory* tmp_parent = parent_directory;
        Directory* tmp_current = current_directory;
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
            std::cout << "Directory " << dir_name << " does not exist - creating it" << std::endl;
            add_directory(dir_name);
        }
        // // Change directory: 
        // current_directory = current_directory->subdirectories
    }
    void up_level(){
        // store temps 
        Directory* tmp_parent = parent_directory;
        Directory* tmp_current = current_directory;
        current_directory = tmp_current;
        parent_directory = 
    }*/