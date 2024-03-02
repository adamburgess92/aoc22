#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "parser.h"
#include "coord.h"


// class rope {
// public:
//     rope(): head_coords(0, 0), tail_coords(0, 0) {}
//     coord head_coords;
//     coord tail_coords;
//     void move_head(const char& m)
//     {
//         // Move head
//         switch(m) {
//             case 'R':
//                 ++head_coords.x;
//                 break;
//             case 'L':
//                 --head_coords.x;
//                 break;
//             case 'U':
//                 ++head_coords.y;
//                 break;
//             case 'D':
//                 --head_coords.y;
//                 break;
//         }
//     }
//     void follow_tail()
//     {
//         int x_dist = head_coords.x - tail_coords.x;
//         int y_dist = head_coords.y - tail_coords.y;
//         // Move horizontally
//         if (x_dist>1 && y_dist==0){
//             ++tail_coords.x;
//         } else if (x_dist<1 && y_dist==0){
//             --tail_coords.x;
//         }
//         // Move vertically
//         if (y_dist>1 && x_dist==0){
//             ++tail_coords.y;
//         } else if (y_dist<1 && x_dist==0){
//             --tail_coords.y;
//         }
//         // Move diagonally 
//         if (x_dist>0 && y_dist>1 || x_dist>0 && y_dist>1){ // Up-right
//             ++tail_coords.x;
//             ++tail_coords.y;
//         } else if (x_dist<1 && y_dist>0 || x_dist<0 && y_dist>1){ // Up-left
//             --tail_coords.x;
//             ++tail_coords.y;
//         } else if (x_dist<0 && y_dist<1 || x_dist<0 && y_dist<1){ // Down-left
//             --tail_coords.x;
//             --tail_coords.y;
//         } else if (x_dist>0 && y_dist<1 || x_dist>0 && y_dist<1){ // Down-right
//             ++tail_coords.x;
//             --tail_coords.y;
//         }
//     }
//     void move_rope(const char m)
//     {
//         move_head(m);
//         follow_tail();
//     }
// };

int main() 
{
    // std::vector<std::string> data = parse_data("test_data.txt");
    // for (int i=0; i!=data.size(); ++i){
    //     std::cout << data[i] << std::endl;
    // }
    // part 1

    // coord pairs (x, y)

    // turn steps into vector {R, R, R, L, U, D, D, D, ...}
    // r = rope(); // Initial state head overlapping tail
    // rope.move_rope(R)
    // v_tail_visited.push_back(rope.tail_coord)
    // count unique
    return 0;

}
