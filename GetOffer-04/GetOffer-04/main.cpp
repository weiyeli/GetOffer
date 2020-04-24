//
//  main.cpp
//  GetOffer-04
//
//  Created by liweiye on 2020/4/24.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size();
        int coulums = matrix[1].size();

        // 从右上角开始
        for (int i = 0; i < rows;) {
            for (int j = coulums - 1; j >= 0;) {
                if (target == matrix[i][j]) {
                    return true;
                } else if (target > matrix[i][j]) {
                    i++;
                    if (i == rows) return false;
                } else {
                    j--;
                    if (j < 0) return false;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
//    vector<vector<int>> inputVector = {
//        {1,   4,  7, 11, 15},
//        {2,   5,  8, 12, 19},
//        {3,   6,  9, 16, 22},
//        {10, 13, 14, 17, 24},
//        {18, 21, 23, 26, 30}};
    vector<vector<int>> emptyVector = {{-5}};
    bool res = solution.findNumberIn2DArray(emptyVector, -2);
    cout << res << endl;
}
