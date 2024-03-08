class Point {
public:
    Point();
    Point(int row, int col);
    int row;
    int col;
    int dist; // Optional - dist traversed to get to point from start point
    void add_dist(int d);
    bool operator==(const Point& other) const;
};