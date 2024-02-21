#include <iostream>
#include <vector>
#include <string>
#include "parser.h"

// bool is_visible(int x_col, int y_row)
// {

// }

void count_visible(std::vector<std::vector<int> >& v) 
{
    /*
    v looks like 
    [[..., ..., ...],
    [..., ..., ...]]
    */
    int sum = 0;
    // Count outer
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            if (i==0 || i==v.size()-1 || j==0 || j==v[0].size()-1){
                ++sum;
            }
        }
    }
    std::cout << "Outer: " << sum << std::endl;

    // Count inner: 
    std::vector<int> above; 
    std::vector<int> below; 
    std::vector<int> right; 
    for (int i=1; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            
            std::vector<int> left(v[i].begin(), v[i].begin()+j);
            std::vector<int> right(v[i].begin(), v[i].begin()-j);
            // above = v[i][j];
            // below = v[i][j];
            // right = v[i][j];
        }
    }

}

int main()
{
    std::vector<std::vector<int> > data = parse_data("test_data.txt");
    count_visible(data);


}
