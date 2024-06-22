#include <iostream>
#include <queue>
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
        // std::cout << size_all_files << std::endl;
        // std::cout << "Directory " << dir->name << " has size " << size_all_files << std::endl;
        return size_all_files;
    }
    int traverse(Directory* dir){
        int size_files_in_current_dir = calculate_directory_size(dir);
        int size_files_in_subdirectories = 0;
        for (const auto& d : dir->subdirectories) {
            size_files_in_subdirectories += traverse(d);
        }
        size_files_in_current_dir += size_files_in_subdirectories;
        if (size_files_in_current_dir<=100000){
            std::cout << "Including directory: " << dir->name << " with size " << size_files_in_current_dir << std::endl;
            pt_1_size+=size_files_in_current_dir;
        }
        return size_files_in_current_dir;
    }

    // void traverse(Directory* dir){
    //     int size_files_in_current_dir = calculate_directory_size(dir);
    //     // pt_1_size+=size_files_in_current_dir;
    //     if (size_files_in_current_dir<=100000){
    //         std::cout << "Including directory: " << dir->name << " with size " << size_files_in_current_dir << std::endl;
    //         pt_1_size+=size_files_in_current_dir;
    //     }
    //     for (const auto& d : dir->subdirectories) {
    //         traverse(d);
    //     }
    // }
};

int main()
{
    // Load data
    std::vector<std::string> data = parse_data("test_data.txt");
    // Skip first line and instantiate FileSystem with root directory:
    FileSystem fs = FileSystem("/");
    std::vector<std::string> term_output(data.begin()+1, data.end());
    fs.process_terminal_output(term_output);
    // Go back to root: 
    fs.current_directory = fs.root;
    fs.traverse(fs.current_directory);
    std::cout << fs.pt_1_size << std::endl;


    // 39065894 <- too high
    // 1969677 <- too high
}



