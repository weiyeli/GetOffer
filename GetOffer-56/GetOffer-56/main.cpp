//
//  main.cpp
//  GetOffer-56
//
//  Created by liweiye on 2020/5/31.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 位运算
 1. LeetCode 56
 2. LeetCode 136
 3. LeetCode 137
 4. LeetCode 645
 */


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2, 0);
        int ans = 0;
        for (auto num: nums) {
            ans ^= num;
        }
        int k = ans & (-ans);
        for (auto num: nums) {
            if (num & k) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {2, 2, 4, 6};
    vector<int> res = s.singleNumbers(v);
    cout << res[0] << res[1] << endl;
}
