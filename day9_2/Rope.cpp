#include "Coord.h"
#include "Rope.h"

Rope::Rope(): head_coords(0, 0), tail_coords(0, 0) {}
void Rope::move_head(const char& m)
{
    // Move head
    switch(m) {
        case 'R':
            ++head_coords.x;
            break;
        case 'L':
            --head_coords.x;
            break;
        case 'U':
            ++head_coords.y;
            break;
        case 'D':
            --head_coords.y;
            break;
    }
}
void Rope::follow_tail()
{
    int x_dist = head_coords.x - tail_coords.x;
    int y_dist = head_coords.y - tail_coords.y;
    // Move horizontally
    if (x_dist>1 && y_dist==0){
        ++tail_coords.x;
    } else if (x_dist<1 && y_dist==0){
        --tail_coords.x;
    }
    // Move vertically
    if (y_dist>1 && x_dist==0){
        ++tail_coords.y;
    } else if (y_dist<1 && x_dist==0){
        --tail_coords.y;
    }
    // Move diagonally 
    if (x_dist>0 && y_dist>1 || x_dist>0 && y_dist>1){ // Up-right
        ++tail_coords.x;
        ++tail_coords.y;
    } else if (x_dist<1 && y_dist>0 || x_dist<0 && y_dist>1){ // Up-left
        --tail_coords.x;
        ++tail_coords.y;
    } else if (x_dist<0 && y_dist<1 || x_dist<0 && y_dist<1){ // Down-left
        --tail_coords.x;
        --tail_coords.y;
    } else if (x_dist>0 && y_dist<1 || x_dist>0 && y_dist<1){ // Down-right
        ++tail_coords.x;
        --tail_coords.y;
    }
}
void Rope::move_rope(const char m)
{
    move_head(m);
    follow_tail();
}

