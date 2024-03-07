class Point {
public:
    Point();
    Point(int row, int col);
    int row;
    int col;
    bool operator==(const Point& other) const;
};