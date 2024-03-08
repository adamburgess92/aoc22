#include "Parser.h"
#include "Crawler.h"

int main() 
{
    std::vector<std::vector<char>> grid = parse_data("data.txt");
    Crawler c = Crawler(grid);
    c.set_start_end_loc();
    // Part 1
    // int n = c.traverse(c.start_point, c.end_point);
    // std::cout << n << std::endl;
    // Part 2:
    c.find_a_points();
    int shortest = c.get_shortest_a_path();
    std::cout << shortest << std::endl;
}