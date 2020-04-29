//
//  main.cpp
//  GetOffer-57
//
//  Created by liweiye on 2020/4/27.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findContinuousSequence(int target) {
        if (target <= 2) return res;
        int i = 1, j = 2;
        while (i < j && j <= target) {
            if (continuousSum(i, j) < target) {
                j++;
            } else {
                if (continuousSum(i, j) == target) {
                    res.emplace_back(getContinuousSequence(i, j));
                }
                i++;
            }
        }
        return res;
    }


private:
    int continuousSum(int start, int end) {
        return (end - start + 1) * (start + end) / 2;
    }

    vector<int> getContinuousSequence(int start, int end) {
        vector<int> res;
        for (int i = start; i <= end; i++) {
            res.emplace_back(i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> vec = s.findContinuousSequence(15);
    for (auto sequence: vec) {
        for (auto i: sequence) {
            cout << i << " ";
        }
        cout << endl;
    }
}
