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
    Directory* parent_directory;
    std::vector<Directory*> subdirectories;
    std::vector<File*> files;
    // Constructor: 
    Directory(std::string s) : name(s) {};
};

class FileSystem {
public:
    Directory* root;
    Directory* current_directory;
    // Constructor: 
    FileSystem(std::string rootdir) {
        root = new Directory(rootdir);
        root->parent_directory = nullptr;
        current_directory = root;
    }
    void add_file(std::string s_file){
        std::cout << "Adding file" << std::endl;
        int filesize = std::stoi(s_file.substr(0, s_file.find(" ")));
        std::string filename = s_file.substr(s_file.find(" ")+1, s_file.length());
        File* newfile = new File(filename, filesize);
        current_directory->files.push_back(newfile);
    }
    void add_directory(std::string s_directory){
        std::cout << "Adding directory" << std::endl;
        std::string directory_name = s_directory.substr(s_directory.find(" ")+1, s_directory.length());
        Directory* newdir = new Directory(directory_name);
        current_directory->subdirectories.push_back(newdir);
    }
    void change_directory(std::string s_cd){
        std::cout << "Changing directory" << std::endl;
        Directory* tmp_current = current_directory; 
        std::string dir_name = s_cd.substr(s_cd.find("cd")+3, s_cd.length());
        for (int i=0; i<=current_directory->subdirectories.size(); ++i){
            if (dir_name==current_directory->subdirectories[i]->name){
                current_directory = current_directory->subdirectories[i];
                current_directory->parent_directory = tmp_current;
                break;
            }
        }
    }
    void up_level(){
        std::cout << "Moving up level" << std::endl;
        current_directory = current_directory->parent_directory;
    }
    void process_terminal_output(std::vector<std::string> commands){
        for (const std::string& c : commands){ 
            std::cout << "Command: " << c << std::endl;
            if (c=="$ cd ..") {
                up_level();
            }
            else if (c.substr(0, 4)=="$ cd") {
                change_directory(c);
            } 
            else if (c.substr(0, 3)=="dir") {
                add_directory(c);
            }
            else if (c.substr(0, 4)=="$ ls") {
                continue;
            }
            else {
                add_file(c);
            }
        }
    }

};

int main()
{
    // Load data
    std::vector<std::string> data = parse_data("test_data.txt");
    // Skip first line and instantiate FileSystem with root directory:
    FileSystem fs = FileSystem("/");
    std::vector<std::string> term_output(data.begin()+1, data.end());
    fs.process_terminal_output(term_output);

    
    
    // Testing things:
    /*
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
    fs.change_directory("$ cd d");
    std::cout << "current directory: " << fs.current_directory->name << std::endl;
    fs.add_directory("dir e");
    fs.change_directory("$ cd e");
    std::cout << "current directory: " << fs.current_directory->name << std::endl;
    fs.up_level();
    std::cout << "current directory: " << fs.current_directory->name << std::endl;
    */
}



