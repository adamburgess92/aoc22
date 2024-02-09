#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "parser.h"

std::vector<std::string> input_to_vector(std::string filename) {
    // Open the file for reading
    std::ifstream inputFile("test_data1.txt");

    // Define a vector to store lines from the file
    std::vector<std::string> lines;

    // Read and store the file contents line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Store each line in the vector
        lines.push_back(line);
    }
    inputFile.close();

    // // Print the contents of the vector
    // for (const auto& line : lines) {
    //     std::cout << line << std::endl;
    // }
    return lines;
}