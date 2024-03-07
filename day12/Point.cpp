#include "Point.h"

Point::Point() {};
Point::Point(int row, int col): row(row), col(col) {};
bool Point::operator==(const Point& other) const 
{
    return (row==other.row && col==other.col);
}