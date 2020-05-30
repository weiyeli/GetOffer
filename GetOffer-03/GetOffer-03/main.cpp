//
//  main.cpp
//  GetOffer-03
//
//  Created by liweiye on 2020/5/18.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 使用set
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> count;
        for (auto i: nums) {
            if (count.count(i) == 1) {
                return i;
            } else {
                count.insert(i);
            }
        }
        return 0;
    }
};

// 原地置换
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                nums[nums[i]] = nums[i];
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
