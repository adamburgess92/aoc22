#include "Parser.h"
#include "Crawler.h"

int main() 
{
    std::vector<std::vector<char>> grid = parse_data("test_data.txt");
    Crawler c = Crawler(grid);
    c.set_start_end_loc();
    std::cout << c.start_point.row << ", " << c.start_point.col << std::endl;
    std::cout << c.end_point.row << ", " << c.end_point.col << std::endl;
    c.traverse();
}