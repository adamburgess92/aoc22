#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "parser.h"

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
    int pt_1_size = 0;
    int used_space;
    int unused_space;
    std::map<std::string, int> filsize_map;
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
    int calculate_directory_size(Directory* dir){
        int size_all_files = 0;
        for (const auto& f : dir->files) {
            size_all_files += f->size;
        }
        return size_all_files;
    }
    int traverse_pt1(Directory* dir){
        int size_files_in_current_dir = calculate_directory_size(dir);
        int size_files_in_subdirectories = 0;
        for (const auto& d : dir->subdirectories) {
            size_files_in_subdirectories += traverse_pt1(d);
        }
        size_files_in_current_dir += size_files_in_subdirectories;
        if (size_files_in_current_dir<=100000){
            std::cout << "Including directory: " << dir->name << " with size " << size_files_in_current_dir << std::endl;
            pt_1_size+=size_files_in_current_dir;
        }
        return size_files_in_current_dir;
    }
    void get_sum_all_files(Directory* dir){
        int size_files_in_current_dir = calculate_directory_size(dir);
        used_space += size_files_in_current_dir;
        std::cout << "Dir " << dir->name << " has size " << size_files_in_current_dir << std::endl;
        // Recursively move to subdirectories
        for (const auto& d : dir->subdirectories) {
            get_sum_all_files(d);
        }
    }
    int get_used_space(){
        used_space = 0;
        get_sum_all_files(root);
        std::cout << "Used space: " << used_space << std::endl;
        return used_space;
    }
    int get_unused_space(){
        int used_space = get_used_space();
        unused_space = 70000000 - used_space;
        std::cout << "Unused space = " << unused_space << std::endl;
        return unused_space;
    }
    int traverse_pt2(Directory* dir){
        int size_files_in_current_dir = calculate_directory_size(dir);
        int size_files_in_subdirectories = 0;
        for (const auto& d : dir->subdirectories) {
            size_files_in_subdirectories += traverse_pt2(d);
        }
        size_files_in_current_dir += size_files_in_subdirectories;
        std::cout << "Directory: " << dir->name << " has size " << size_files_in_current_dir << std::endl;
        // Add to map:
        filsize_map[dir->name] = size_files_in_current_dir;
        return size_files_in_current_dir;
    }
    void solve_pt2(){
        int used_space = get_used_space();
        int unused_space = get_unused_space();
        int total_space = 70000000;
        int need_space = 30000000;
        int need_delete = need_space - unused_space;
        int smallest = total_space;
        for (const auto& pair : filsize_map){
            if (pair.second >= need_delete) {
                std::cout << pair.first << ": " << pair.second << std::endl;
                if (pair.second < smallest){
                    smallest = pair.second;
                }
            }
        }
        std::cout << "Smallest directory that could be deleted has size: " << smallest << std::endl;
    }
};

int main()
{
    // Load data
    std::vector<std::string> data = parse_data("data.txt");
    // Skip first line and instantiate FileSystem with root directory:
    FileSystem fs = FileSystem("/");
    std::vector<std::string> term_output(data.begin()+1, data.end());
    fs.process_terminal_output(term_output);
    // Part 1: Go back to root: 
    fs.current_directory = fs.root;
    // fs.traverse_pt1(fs.current_directory);
    std::cout << "Part 1 result: " << fs.pt_1_size << std::endl;
    // Part 2:
    fs.current_directory = fs.root;
    fs.traverse_pt2(fs.current_directory);
    fs.solve_pt2();
    return 0;
}