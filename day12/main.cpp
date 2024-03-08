#include "Parser.h"
#include "Crawler.h"

int main() 
{
    std::vector<std::vector<char>> grid = parse_data("test_data.txt");
    Crawler c = Crawler(grid);
    c.set_start_end_loc();
    c.traverse();

}