#include <iostream>
#include <vector>
#include <string>
#include "parser.h"

// bool is_visible(int x_col, int y_row)
// {

// }

int count_larger(int current_tree, std::vector<int>& v)
{
    int sum = 0;
    for (int i=0; i!=v.size(); ++i){
        if (v[i]>=current_tree){
            ++sum;
        }
    }
    return sum;
}


void count_visible(std::vector<std::vector<int> >& v) 
{
    // Count outer
    int outer_sum = 0;
    // Count outer
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            if (i==0 || i==v.size()-1 || j==0 || j==v[0].size()-1){
                ++outer_sum;
            }
        }
    }

    // Count inner: 
    int inner_sum = 0;
    for (int i=1; i!=v.size()-1; ++i){
        for (int j=1; j!=v[0].size()-1; ++j){
            std::cout << "row: " << i << std::endl;
            std::cout << "col: " << j << std::endl; 
            // Left
            std::vector<int> left(v[i].begin(), v[i].begin()+j);
            // Right
            std::vector<int> right(v[i].begin()+j+1, v[i].end());
            // Above
            std::vector<int> above;
            if (i>0){
                for (int k=0; k<i; ++k){
                    above.push_back(v[k][j]);
                }
            }
            // Below
            std::vector<int> below;
            if (i<v.size()-1){
                for (int l=i+1; l<v.size(); ++l){
                    below.push_back(v[l][j]);
                }
            } 

            // // Debug: 
            // std::cout << "Below" << std::endl;
            // for (int b=0; b<below.size(); ++b){
            //     std::cout << below[b] << std::endl;
            // }

            // If any of the below == 0, then the tree is visible from the outside
            std::cout << "Current tree height: " << v[i][j] << std::endl;
            int n_left = count_larger(v[i][j], left);
            int n_right = count_larger(v[i][j], right);
            int n_above = count_larger(v[i][j], above);
            int n_below = count_larger(v[i][j], below);

            if (n_left==0 || n_right==0 || n_above==0 || n_below==0){
                ++inner_sum;
                std::cout << "Visible - Inner" << std::endl;
            } else {
                std::cout << "Invisible" << std::endl;
            }
            left.clear();
            right.clear();
            above.clear();
            below.clear();
        }
    }
    std::cout << "Outer: " << outer_sum << std::endl;
    std::cout << "Inner: " << inner_sum << std::endl;
    int total = outer_sum + inner_sum;
    std::cout << "Total: " << total << std::endl;

}

int main()
{
    std::vector<std::vector<int> > data = parse_data("data.txt");
    count_visible(data);
}
